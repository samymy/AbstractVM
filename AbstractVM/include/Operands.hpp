#ifndef ABSTRACTVM_OPERANDTYPE_HPP
#define ABSTRACTVM_OPERANDTYPE_HPP

#include <iostream>
#include <unordered_map>
#include <algorithm>

namespace Operands {

    enum class eOperandType {

        Int8,
        Int16,
        Int32,
        Float,
        Double
    };

    namespace {

        std::unordered_map<std::string, eOperandType>	operands = {

                { "int8",	eOperandType::Int8 },
                { "int16",	eOperandType::Int16 },
                { "int32",	eOperandType::Int32 },
                { "float",	eOperandType::Float },
                { "double",	eOperandType::Double }
        };
    }

    const std::string&  toString(eOperandType);

    eOperandType        toOperandType(const std::string&);
}

using eOperandType = Operands::eOperandType;

#endif //ABSTRACTVM_OPERANDTYPE_HPP
