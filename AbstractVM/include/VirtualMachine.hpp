#ifndef ABSTRACTVM_VIRTUALMACHINE_HPP
#define ABSTRACTVM_VIRTUALMACHINE_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>

#include <IOperand.hpp>
#include <Instruction.hpp>
#include <VMException.hpp>

class VirtualMachine {

    std::deque<std::shared_ptr<const IOperand>>     m_operands;

    using mem_fun_ptr = void (VirtualMachine::*) (const IOperand*);

    std::vector<mem_fun_ptr>        m_operators;

    void        push(const IOperand*);
    void        pop(const IOperand*);
    void        add(const IOperand*);
    void        sub(const IOperand*);
    void        mul(const IOperand*);
    void        div(const IOperand*);
    void        mod(const IOperand*);
    void        abs(const IOperand*);
    void        square(const IOperand*);
    void        sqrt(const IOperand*);
    void        log(const IOperand*);
    void        log10(const IOperand*);
    void        assert(const IOperand*);
    void        print(const IOperand*);
    void        dump(const IOperand*);

public:
    VirtualMachine();
    VirtualMachine(const VirtualMachine&) = delete;
    VirtualMachine&     operator=(const VirtualMachine&) = delete;
    VirtualMachine(const VirtualMachine&&) = delete;
    VirtualMachine&     operator=(const VirtualMachine&&) = delete;
    ~VirtualMachine() = default;

    void        execute(const std::vector<Instruction*>&);

};

#endif //ABSTRACTVM_VIRTUALMACHINE_HPP
