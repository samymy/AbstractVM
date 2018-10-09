#include <Operators.hpp>

const std::string&      Operators::toString(eOperatorType operator_type) {

    auto    it = std::find_if(operators.begin(), operators.end(),
                              [operator_type](const std::pair<std::string, eOperatorType> pair){
                                  return pair.second == operator_type;
                              }
    );

    return it->first;
}

Operators::eOperatorType Operators::toOperatorType(const std::string& operator_name) {

    return operators[operator_name];
}
