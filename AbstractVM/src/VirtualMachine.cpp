#include <VirtualMachine.hpp>

VirtualMachine::VirtualMachine() {

    m_operators.push_back(&VirtualMachine::push);
    m_operators.push_back(&VirtualMachine::pop);
    m_operators.push_back(&VirtualMachine::add);
    m_operators.push_back(&VirtualMachine::sub);
    m_operators.push_back(&VirtualMachine::mul);
    m_operators.push_back(&VirtualMachine::div);
    m_operators.push_back(&VirtualMachine::mod);
    m_operators.push_back(&VirtualMachine::abs);
    m_operators.push_back(&VirtualMachine::square);
    m_operators.push_back(&VirtualMachine::sqrt);
    m_operators.push_back(&VirtualMachine::log);
    m_operators.push_back(&VirtualMachine::log10);
    m_operators.push_back(&VirtualMachine::assert);
    m_operators.push_back(&VirtualMachine::print);
    m_operators.push_back(&VirtualMachine::dump);
}

void    VirtualMachine::push(const IOperand* operand) {

    m_operands.push_back(std::shared_ptr<const IOperand>(operand));
}

void    VirtualMachine::pop(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    m_operands.pop_back();
}

void    VirtualMachine::add(const IOperand*) {

    if (m_operands.size() < 2)
        throw VMException("The stack don't have enough operands");

    auto    secondOperand = m_operands.back();
    m_operands.pop_back();

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = *firstOperand + *secondOperand;
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::sub(const IOperand*) {

    if (m_operands.size() < 2)
        throw VMException("The stack don't have enough operands");

    auto    secondOperand = m_operands.back();
    m_operands.pop_back();

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = *firstOperand - *secondOperand;
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::mul(const IOperand*) {

    if (m_operands.size() < 2)
        throw VMException("The stack don't have enough operands");

    auto    secondOperand = m_operands.back();
    m_operands.pop_back();

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = *firstOperand * *secondOperand;
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::div(const IOperand*) {

    if (m_operands.size() < 2)
        throw VMException("The stack don't have enough operands");

    auto    secondOperand = m_operands.back();
    m_operands.pop_back();

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = *firstOperand / *secondOperand;
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::mod(const IOperand*) {

    if (m_operands.size() < 2)
        throw VMException("The stack don't have enough operands");

    auto    secondOperand = m_operands.back();
    m_operands.pop_back();

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = *firstOperand % *secondOperand;
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::abs(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = firstOperand->getAbs();
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::square(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = firstOperand->getSquare();
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::sqrt(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = firstOperand->getSqrt();
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::log(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = firstOperand->getLog();
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::log10(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto    firstOperand = m_operands.back();
    m_operands.pop_back();

    try {

        auto    result = firstOperand->getLog10();
        push(result);
    }
    catch (...) {
        throw;
    }
}

void    VirtualMachine::assert(const IOperand* operand) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto&    lhs = m_operands.back();
    std::shared_ptr<const IOperand>     rhs(operand);

    if (!(*lhs == *rhs))
        throw VMException("Assertion failed");
}

void    VirtualMachine::print(const IOperand*) {

    if (m_operands.empty())
        throw VMException("The stack is empty");

    auto&   operand = m_operands.back();

    if (operand->getType() != eOperandType::Int8)
        throw VMException("The type of the operand is not \'int8\'");

    char    symbol = static_cast<char>(std::stoi(operand->toString()));

    if (isprint(symbol))
        std::cout << symbol << std::endl;
    else
        std::cout << "Non printable symbol" << std::endl;
}

void    VirtualMachine::dump(const IOperand*) {

    for (auto& operand : m_operands)
        std::cout << operand->toString() << std::endl;
}

void    VirtualMachine::execute(const std::vector<Instruction*>& instructions) {

    for (auto instruction : instructions) {

        if (instruction->getOperatorType() == eOperatorType::EXIT)
            break;

        try {
            (this->*m_operators[static_cast<int>(instruction->getOperatorType())])(instruction->getOperand());
        }
        catch (const VMException& exc) {

            std::stringstream   ss;

            ss << "Line " << instruction->getLineIdx() << ": Error: " << exc.what();
            throw VMException(ss.str());
        }
    }
}
