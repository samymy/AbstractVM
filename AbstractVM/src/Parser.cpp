#include <Parser.hpp>
#include <VMException.hpp>

bool Parser::containsExitInstruction(const std::vector<Instruction*>& instructions) {

    for (auto instruction : instructions)
        if (instruction->getOperatorType() == eOperatorType::EXIT)
            return true;

    return false;
}

bool Parser::isBinaryInstruction(const Instruction* instruction) {

    if (instruction->getOperatorType() == eOperatorType::PUSH ||
        instruction->getOperatorType() == eOperatorType::ASSERT)
        return true;

    return false;
}

void Parser::parse(const std::vector<Instruction*>& instructions) {

    bool    error = false;

    if (!containsExitInstruction(instructions))
        throw VMException("There is not the \'EXIT\' instruction");

    for (auto instruction : instructions) {

        if (isBinaryInstruction(instruction)) {
            try {
                instruction->createOperand();
            }
            catch (const VMException &exc) {
                error = true;
                std::cout << exc.what() << std::endl;
            }
        }
    }

    if (error)
        throw VMException("Fix the errors above and try again");
}
