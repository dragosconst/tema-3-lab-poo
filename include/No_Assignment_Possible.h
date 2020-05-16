#ifndef NO_ASSIGNMENT_POSSIBLE_H
#define NO_ASSIGNMENT_POSSIBLE_H

#include <exception>


class No_Assignment_Possible : public std::exception
{
public:
    No_Assignment_Possible() noexcept {}
    No_Assignment_Possible(const No_Assignment_Possible&) noexcept = default;
    No_Assignment_Possible& operator=(const No_Assignment_Possible&) noexcept = default;
    virtual ~No_Assignment_Possible() noexcept = default;
    virtual const char* what() const noexcept{
        return "Nu este permis assignment pentru obiecte ce contin membrii constanti!";
    }
};

#endif // NO_ASSIGNMENT_POSSIBLE_H
