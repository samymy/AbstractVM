#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP

#include <iostream>
#include <Operands.hpp>

class IOperand {

public:

    virtual int                 getPrecision() const = 0;
    virtual eOperandType        getType() const = 0;

    virtual const IOperand *    operator+(const IOperand & rhs) const = 0;
    virtual const IOperand *    operator-(const IOperand & rhs) const = 0;
    virtual const IOperand *    operator*(const IOperand & rhs) const = 0;
    virtual const IOperand *    operator/(const IOperand & rhs) const = 0;
    virtual const IOperand *    operator%(const IOperand & rhs) const = 0;

    virtual const IOperand *    getAbs() const = 0;
    virtual const IOperand *    getSquare() const = 0;
    virtual const IOperand *    getSqrt() const = 0;
    virtual const IOperand *    getLog() const = 0;
    virtual const IOperand *    getLog10() const = 0;

    virtual bool                operator==(const IOperand & rhs) const = 0;

    virtual const std::string & toString() const = 0;

    virtual ~IOperand() = default;

};

#endif //ABSTRACTVM_IOPERAND_HPP
