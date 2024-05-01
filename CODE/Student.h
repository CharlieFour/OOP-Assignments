#ifndef Student_h
#define Student_h

#include <string>
#include <vector>
#include "Person.h"

class Student : public Person
{
    private:
        std::string semester;
    public:
        Student() = default;
        Student(const std::string semester);
        std::string getSemester();
        void setSemester(const std::string semester);
};

#endif 