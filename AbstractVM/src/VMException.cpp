#include <VMException.hpp>

VMException::VMException(const std::string& details): m_details(details) {}

const char*     VMException::what() const noexcept {

    return m_details.c_str();
}
