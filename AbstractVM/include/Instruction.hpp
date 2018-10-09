#ifndef ABSTRACTVM_INSTRUCTION_HPP
#define ABSTRACTVM_INSTRUCTION_HPP

#include <iostream>
#include <sstream>

#include <Operators.hpp>
#include <Operands.hpp>
#include <IOperand.hpp>

class Instruction {

    std::size_t		m_line_idx;
    eOperatorType	m_operator_type;
    eOperandType	m_operand_type;
    std::string		m_operand_value;

    const IOperand* m_operand = nullptr;

public:
    Instruction() = delete;
    Instruction(size_t, eOperatorType, eOperandType = eOperandType::Int8, const std::string& = "0");
    Instruction(const Instruction&) = default;
    Instruction&	operator=(const Instruction&) = default;
    ~Instruction() = default;

    size_t				getLineIdx() const;
    eOperatorType		getOperatorType() const;
    eOperandType		getOperandType() const;
    const std::string&	getOperandValue() const;

    void                createOperand();
    const IOperand*     getOperand() const;

};

#endif //ABSTRACTVM_INSTRUCTION_HPP
