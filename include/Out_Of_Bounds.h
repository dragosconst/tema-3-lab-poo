#ifndef OUT_OF_BOUNDS_H
#define OUT_OF_BOUNDS_H

#include <exception>


class Out_Of_Bounds : public std::exception
{
public:
    Out_Of_Bounds() noexcept {}
    Out_Of_Bounds(const Out_Of_Bounds&) noexcept = default;
    Out_Of_Bounds& operator=(const Out_Of_Bounds&) noexcept = default;
    virtual ~Out_Of_Bounds() noexcept = default;
    virtual const char* what() const noexcept{
        return "Nu exista index-ul cerut in obiectul destinat gestiunii farmaciilor.";
    }
};

#endif // OUT_OF_BOUNDS_H
