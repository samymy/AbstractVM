#ifndef ABSTRACTVM_OPERATORTYPE_HPP
#define ABSTRACTVM_OPERATORTYPE_HPP

#include <iostream>
#include <unordered_map>
#include <algorithm>

namespace Operators {

    enum class eOperatorType {

        PUSH,
        POP,
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        ABS,
        SQUARE,
        SQRT,
        LOG,
        LOG10,
        ASSERT,
        PRINT,
        DUMP,
        EXIT
    };

    namespace {

        std::unordered_map<std::string, eOperatorType>	operators = {

                { "push",	eOperatorType::PUSH },
                { "pop",	eOperatorType::POP },
                { "add",	eOperatorType::ADD },
                { "sub",	eOperatorType::SUB },
                { "mul",	eOperatorType::MUL },
                { "div",	eOperatorType::DIV },
                { "mod",	eOperatorType::MOD },
                { "abs",	eOperatorType::ABS },
                { "square",	eOperatorType::SQUARE },
                { "sqrt",	eOperatorType::SQRT },
                { "log",	eOperatorType::LOG },
                { "log10",	eOperatorType::LOG10 },
                { "assert",	eOperatorType::ASSERT },
                { "print",	eOperatorType::PRINT },
                { "dump",	eOperatorType::DUMP },
                { "exit",	eOperatorType::EXIT }
        };
    }

    const std::string&  toString(eOperatorType);

    eOperatorType       toOperatorType(const std::string&);
}

using eOperatorType = Operators::eOperatorType;

#endif //ABSTRACTVM_OPERATORTYPE_HPP
