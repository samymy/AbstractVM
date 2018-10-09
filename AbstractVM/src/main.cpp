#include <VirtualMachine.hpp>
#include <Lexer.hpp>
#include <Parser.hpp>

int main(int argc, char** argv) {

    VirtualMachine  vm;
    Lexer           lexer;

    try {

        lexer.tokenize(argc, argv);
        Parser::parse(lexer.getInstructions());
        vm.execute(lexer.getInstructions());
    }
    catch (const VMException& exc) {

        std::cout << exc.what() << std::endl;
        return 1;
    }

    return 0;
}