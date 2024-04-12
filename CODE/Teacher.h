#ifndef Teacher_H
#define Teacher_H
#include <string>

#include "Person.h"
#include "Course.h"
class Teacher : public Person, public Course
{ 
    public:
        Teacher() = default;
        Teacher(const std::string id, const std::string name) : Person(id, name) {}
        Teacher(const std::string course, const std::string courseCredits) : Course(course, courseCredits) {}
        
        /*Teacher() = default;
        Teacher(std::string name) : teacherName(name) {}
        Teacher(std::string name, std::string id, std::string course) : teacherName(name), teacherID(id), teacherCourse(course) {}
        std::string getName() const;
        std::string getID();
        std::string getCourse();

        void setName(std::string name);
        void setID(std::string id);
        void setCourse(std::string course);*/
};

#endif 