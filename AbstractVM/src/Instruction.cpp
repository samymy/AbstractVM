#include <Instruction.hpp>
#include <VMException.hpp>
#include <OperandFactory.hpp>

Instruction::Instruction(size_t line_idx,
                         eOperatorType operator_type,
                         eOperandType operand_type,
                         const std::string& operand_value):
        m_line_idx(line_idx),
        m_operator_type(operator_type),
        m_operand_type(operand_type),
        m_operand_value(operand_value) {}

size_t Instruction::getLineIdx() const {

    return m_line_idx;
}

eOperatorType Instruction::getOperatorType() const {

    return m_operator_type;
}

eOperandType Instruction::getOperandType() const {

    return m_operand_type;
}

const std::string&  Instruction::getOperandValue() const {

    return m_operand_value;
}

void    Instruction::createOperand() {

    try {
        m_operand = OperandFactory::getInstance().createOperand(m_operand_type, m_operand_value);
    }
    catch (const VMException& exc) {
        std::stringstream   ss;

        ss << "Line " << m_line_idx << ": Error: " << exc.what();
        throw VMException(ss.str());
    }
}

const IOperand* Instruction::getOperand() const {

    return m_operand;
}
