#ifndef Teacher_H
#define Teacher_H
#include <string>

#include "Person.h"
#include "Course.h"
class Teacher : public Person, public Course
{ 
    public:
        Teacher() = default;
        Teacher(const std::string id, const std::string name, const std::string course) : Person(id, name), Course(course) {}
        ~Teacher()	= default;
};

#endif 