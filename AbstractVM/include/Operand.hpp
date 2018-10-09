#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include <stdexcept>
#include <limits>
#include <cmath>
#include <sstream>

#include <IOperand.hpp>
#include <OperandFactory.hpp>
#include <VMException.hpp>

template <typename T>
class Operand: public IOperand {

    T                   m_value;
    eOperandType        m_type;
    std::string         m_str;

    Operand() = default;

    static const IOperand &    getMorePreciseOperand(const IOperand&, const IOperand&);

public:
    Operand(const Operand&) = default;
    Operand&    operator=(const Operand&) = default;
    ~Operand() override = default;

    Operand(eOperandType type, const std::string & value);

    int                 getPrecision() const override;
    eOperandType        getType() const override;

    const IOperand *    operator+(const IOperand & rhs) const override;
    const IOperand *    operator-(const IOperand & rhs) const override;
    const IOperand *    operator*(const IOperand & rhs) const override;
    const IOperand *    operator/(const IOperand & rhs) const override;
    const IOperand *    operator%(const IOperand & rhs) const override;

    const IOperand *    getAbs() const override;
    const IOperand *    getSquare() const override;
    const IOperand *    getSqrt() const override;
    const IOperand *    getLog() const override;
    const IOperand *    getLog10() const override;

    bool                operator==(const IOperand & rhs) const override;

    const std::string & toString() const override;

};

template<typename T>
Operand<T>::Operand(eOperandType type, const std::string & value) {

    try {

        long double tmp = std::stold(value);

        if (tmp < std::numeric_limits<T>::lowest() ||
            tmp > std::numeric_limits<T>::max())
            throw VMException("The operand is out of range of the type \'" + Operands::toString(type) + "\'");

        m_value = static_cast<T>(tmp);
    }
    catch (const std::invalid_argument&) {
        throw VMException("The operand is invalid");
    }
    catch (const std::out_of_range&) {
        throw;
    }

    m_type = type;

    std::stringstream   ss;
    ss << static_cast<long double>(m_value);
    m_str = ss.str();
}

template <typename T>
int                 Operand<T>::getPrecision() const {

    return static_cast<int>(m_type);
}

template <typename T>
eOperandType        Operand<T>::getType() const {

    return m_type;
}

template <typename T>
const IOperand*     Operand<T>::operator+(const IOperand & rhs) const {

    const IOperand *    result;

    try {

        long double     tmp = m_value + std::stold(rhs.toString());

        result = OperandFactory::getInstance().createOperand(
                getMorePreciseOperand(*this, rhs).getType(),
                std::to_string(tmp)
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template <typename T>
const IOperand* Operand<T>::operator-(const IOperand &rhs) const {

    const IOperand *    result;

    try {

        long double     tmp = m_value - std::stold(rhs.toString());

        result = OperandFactory::getInstance().createOperand(
                getMorePreciseOperand(*this, rhs).getType(),
                std::to_string(tmp)
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template <typename T>
const IOperand* Operand<T>::operator*(const IOperand &rhs) const {

    const IOperand *    result;

    try {

        long double     tmp = m_value * std::stold(rhs.toString());

        result = OperandFactory::getInstance().createOperand(
                getMorePreciseOperand(*this, rhs).getType(),
                std::to_string(tmp)
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template <typename T>
const IOperand* Operand<T>::operator/(const IOperand &rhs) const {

    const IOperand *    result;

    try {

        long double     tmp = std::stold(rhs.toString());

        if (tmp == 0)
            throw VMException("Dividing by zero");

        tmp = m_value / tmp;

        result = OperandFactory::getInstance().createOperand(
                getMorePreciseOperand(*this, rhs).getType(),
                std::to_string(tmp)
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template <typename T>
const IOperand* Operand<T>::operator%(const IOperand &rhs) const {

    const IOperand *    result;

    try {

        if (m_type == eOperandType::Float || m_type == eOperandType::Double ||
            rhs.getType() == eOperandType::Float || rhs.getType() == eOperandType::Double)
            throw VMException("The operand type is invalid");

        int32_t     tmp = std::stoi(rhs.toString());

        if (tmp == 0)
            throw VMException("Dividing by zero");

        tmp = static_cast<int32_t>(m_value) % tmp;

        result = OperandFactory::getInstance().createOperand(
                getMorePreciseOperand(*this, rhs).getType(),
                std::to_string(tmp)
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template<typename T>
const IOperand* Operand<T>::getAbs() const {

    const IOperand *    result;

    try {

        result = OperandFactory::getInstance().createOperand(
                m_type,
                std::to_string(std::abs(m_value))
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template<typename T>
const IOperand* Operand<T>::getSquare() const {

    const IOperand *    result;

    try {

        long double     tmp = m_value * m_value;

        result = OperandFactory::getInstance().createOperand(
                m_type,
                std::to_string(tmp)
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template<typename T>
const IOperand *Operand<T>::getSqrt() const {

    const IOperand *    result;

    try {

        result = OperandFactory::getInstance().createOperand(
                m_type,
                std::to_string(sqrt(m_value))
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template<typename T>
const IOperand *Operand<T>::getLog() const {

    const IOperand *    result;

    try {

        result = OperandFactory::getInstance().createOperand(
                m_type,
                std::to_string(log(m_value))
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template<typename T>
const IOperand *Operand<T>::getLog10() const {

    const IOperand *    result;

    try {

        result = OperandFactory::getInstance().createOperand(
                m_type,
                std::to_string(log10(m_value))
        );
    }
    catch (...) {
        throw;
    }

    return result;
}

template<typename T>
bool Operand<T>::operator==(const IOperand& rhs) const {

    return m_str == rhs.toString() && m_type == rhs.getType();
}

template <typename T>
const std::string & Operand<T>::toString() const {

    return m_str;
}

template<typename T>
const IOperand &Operand<T>::getMorePreciseOperand(const IOperand & operand1, const IOperand & operand2) {

    return std::max(operand1, operand2,
            [](const IOperand& operand1, const IOperand& operand2) {
                return operand1.getPrecision() < operand2.getPrecision();
            });
}

#endif //ABSTRACTVM_OPERAND_HPP
