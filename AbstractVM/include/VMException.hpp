#ifndef ABSTRACTVM_VMEXCEPTION_HPP
#define ABSTRACTVM_VMEXCEPTION_HPP

#include <iostream>
#include <stdexcept>

class VMException: public std::exception {

    std::string     m_details;

    VMException() = default;

public:
    explicit VMException(const std::string&);

    VMException(const VMException&) = default;
    VMException&    operator=(const VMException&) = default;
    ~VMException() override = default;

    const char* what() const noexcept override;

};

#endif //ABSTRACTVM_VMEXCEPTION_HPP
