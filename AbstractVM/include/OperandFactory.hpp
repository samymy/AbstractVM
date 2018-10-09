#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP

#include <vector>

#include <IOperand.hpp>

class OperandFactory {

    using mem_fun_ptr = const IOperand * (OperandFactory::*) (const std::string & value) const;

    std::vector<mem_fun_ptr>    creators;

    const IOperand *            createInt8(const std::string & value) const;
    const IOperand *            createInt16(const std::string & value) const;
    const IOperand *            createInt32(const std::string & value) const;
    const IOperand *            createFloat(const std::string & value) const;
    const IOperand *            createDouble(const std::string & value) const;

    OperandFactory();

public:
    OperandFactory(const OperandFactory&) = delete;
    OperandFactory& operator=(const OperandFactory&) = delete;
    OperandFactory(OperandFactory&&) = delete;
    OperandFactory& operator=(OperandFactory&&) = delete;

    ~OperandFactory() = default;

    const IOperand *            createOperand(eOperandType type, const std::string & value) const;

    static OperandFactory &     getInstance();

};

#endif //ABSTRACTVM_OPERANDFACTORY_HPP
