#ifndef NEGATIVE_NUMBER_H
#define NEGATIVE_NUMBER_H

#include <exception>


class Negative_Number : public std::exception
{
public:
    Negative_Number() noexcept {}
    Negative_Number(const Negative_Number&) noexcept = default;
    Negative_Number& operator=(const Negative_Number&) noexcept = default;
    virtual ~Negative_Number() noexcept = default;
    virtual const char* what() const noexcept{
        return "Numere negative pot fi introduse doar pentru valoarea profitului lunar!";
    }
};

#endif // NEGATIVE_NUMBER_H
