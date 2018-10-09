#include <OperandFactory.hpp>
#include <Operand.hpp>

OperandFactory::OperandFactory() {

    creators.push_back(&OperandFactory::createInt8);
    creators.push_back(&OperandFactory::createInt16);
    creators.push_back(&OperandFactory::createInt32);
    creators.push_back(&OperandFactory::createFloat);
    creators.push_back(&OperandFactory::createDouble);
}

const IOperand * OperandFactory::createOperand(eOperandType type, const std::string & value) const {

    return (this->*creators[static_cast<size_t>(type)])(value);
}

const IOperand * OperandFactory::createInt8(const std::string & value) const {

    const IOperand *    result;

    try {
        result = new Operand<int8_t>(eOperandType::Int8, value);
    }
    catch (...) {
        throw;
    }

    return result;
}

const IOperand * OperandFactory::createInt16(const std::string & value) const {

    const IOperand *    result;

    try {
        result = new Operand<int16_t>(eOperandType::Int16, value);
    }
    catch (...) {
        throw;
    }

    return result;
}

const IOperand * OperandFactory::createInt32(const std::string & value) const {

    const IOperand *    result;

    try {
        result = new Operand<int32_t>(eOperandType::Int32, value);
    }
    catch (...) {
        throw;
    }

    return result;
}

const IOperand * OperandFactory::createFloat(const std::string & value) const {

    const IOperand *    result;

    try {
        result = new Operand<float>(eOperandType::Float, value);
    }
    catch (...) {
        throw;
    }

    return result;
}

const IOperand * OperandFactory::createDouble(const std::string & value) const {

    const IOperand *    result;

    try {
        result = new Operand<double>(eOperandType::Double, value);
    }
    catch (...) {
        throw;
    }

    return result;
}

OperandFactory& OperandFactory::getInstance() {

    static OperandFactory   instance;

    return instance;
}
