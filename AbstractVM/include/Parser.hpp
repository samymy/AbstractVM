#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

#include <vector>
#include <Instruction.hpp>

class Parser {

    static bool containsExitInstruction(const std::vector<Instruction*>&);
    static bool isBinaryInstruction(const Instruction*);

public:
    static void parse(const std::vector<Instruction*>&);

};

#endif //ABSTRACTVM_PARSER_HPP
