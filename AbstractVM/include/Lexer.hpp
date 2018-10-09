#ifndef ABSTRACTVM_LEXER_HPP
#define ABSTRACTVM_LEXER_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <regex>

#include <Instruction.hpp>
#include <Operators.hpp>
#include <Operands.hpp>

class Lexer {

    const std::regex	m_unary_instruction { R"(\s*(pop|add|sub|mul|div|mod|abs|square|sqrt|log|log10|print|dump|exit)\s*(?:;.*)?)" };
    const std::regex	m_binary_int_instruction { R"(\s*(push|assert)\s+(int8|int16|int32)\s*\(\s*(-?[0-9]+)\s*\)\s*(?:;.*)?)" };
    const std::regex	m_binary_float_instruction { R"(\s*(push|assert)\s+(float|double)\s*\(\s*(-?[0-9]+.[0-9]+)\s*\)\s*(?:;.*)?)" };
    const std::regex	m_non_instruction { R"(\s*(?:;.*)?)" };

    std::vector<Instruction*>		m_instructions;

    void							tokenizeLine(std::size_t, const std::string&);

public:
    Lexer() = default;
    Lexer(const Lexer&) = default;
    Lexer&	operator=(const Lexer&) = default;
    ~Lexer();

    void								tokenize(int, char**);
    const std::vector<Instruction*>&	getInstructions() const;

};

#endif //ABSTRACTVM_LEXER_HPP
