#include <Lexer.hpp>

#include <fstream>
#include <VMException.hpp>

Lexer::~Lexer() {

    for (auto instruction : m_instructions)
        delete instruction;
}

void	Lexer::tokenizeLine(std::size_t line_idx, const std::string& line) {

    std::string		operator_name, operand_name, operand_value;

    if (std::regex_match(line, m_unary_instruction)) {

        operator_name = std::regex_replace(line, m_unary_instruction,"$1");
        m_instructions.push_back(new Instruction(line_idx,
                                                 Operators::toOperatorType(operator_name)));
    }
    else if (std::regex_match(line, m_binary_int_instruction)) {

        operator_name = std::regex_replace(line, m_binary_int_instruction,"$1");
        operand_name = std::regex_replace(line, m_binary_int_instruction,"$2");
        operand_value = std::regex_replace(line, m_binary_int_instruction,"$3");
        m_instructions.push_back(new Instruction(line_idx,
                                                 Operators::toOperatorType(operator_name),
                                                 Operands::toOperandType(operand_name),
                                                 operand_value));
    }
    else if (std::regex_match(line, m_binary_float_instruction)) {

        operator_name = std::regex_replace(line, m_binary_float_instruction,"$1");
        operand_name = std::regex_replace(line, m_binary_float_instruction,"$2");
        operand_value = std::regex_replace(line, m_binary_float_instruction,"$3");
        m_instructions.push_back(new Instruction(line_idx,
                                                 Operators::toOperatorType(operator_name),
                                                 Operands::toOperandType(operand_name),
                                                 operand_value));
    }
    else if (std::regex_match(line, m_non_instruction)) {
        return;
    }
    else {
        std::stringstream	ss;

        ss << "Line " << line_idx << ": Error: The instruction is invalid";
        throw VMException(ss.str());
    }
}

void	Lexer::tokenize(int argc, char** argv) {

    std::string		line;
    std::size_t		line_idx = 0;
    bool            error = false;

    if (argc == 1) {

        std::vector<std::string>    lines;
        std::size_t                 istream_end_idx;

        while (true) {

            std::getline(std::cin, line);
            if (feof(stdin)) {
            	clearerr(stdin);
                std::cin.clear();
            }
            if ((istream_end_idx = line.find(";;")) != std::string::npos)
                line = line.substr(0, istream_end_idx);
            lines.push_back(line);
            if (istream_end_idx != std::string::npos)
                break;
        }

        for (auto& line : lines) {

            ++line_idx;
            try {
                tokenizeLine(line_idx, line);
            }
            catch (const VMException& exc) {
                error = true;
                std::cout << exc.what() << std::endl;
            }
        }
    }
    else if (argc == 2) {

        std::ifstream	file(argv[1]);

        if (!file)
            throw VMException("The error is occured while reading the file \'" + std::string(argv[1]) + "\'");

        while (std::getline(file, line)) {

            ++line_idx;

            try {
                tokenizeLine(line_idx, line);
            }
            catch (const VMException& exc) {
                error = true;
                std::cout << exc.what() << std::endl;
            }
        }
        file.close();
    }
    else {
        throw VMException("There is too many reading files");
    }

    if (error)
        throw VMException("Fix the errors above and try again");
}

const std::vector<Instruction*>&	Lexer::getInstructions() const {

    return m_instructions;
}
