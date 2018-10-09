#include <Operands.hpp>

const std::string&      Operands::toString(eOperandType operand_type) {

    auto    it = std::find_if(operands.begin(), operands.end(),
                              [operand_type](const std::pair<std::string, eOperandType> pair){
                                  return pair.second == operand_type;
                              }
    );

    return it->first;
}

Operands::eOperandType   Operands::toOperandType(const std::string& operand_name) {

    return operands[operand_name];
}

