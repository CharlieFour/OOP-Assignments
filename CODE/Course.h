#ifndef Course_H
#define Course_H

#include <string>


class Course
{
    private:
        std::string courseName;
    public:
        Course() = default;
        Course(std::string courseName) : courseName(courseName) {}
};

#endif // Course_H
