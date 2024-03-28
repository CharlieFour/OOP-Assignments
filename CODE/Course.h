#ifndef Course_H
#define Course_H

#include <string>
#include "Teacher.h"

class Course
{
    private:
        std::string courseName;
        Teacher courseTeacher;
        int courseCredits;
    public:
        Course(std::string name, Teacher teacher, int credits);
        std::string getName();
        std::string getTeacher();
        int getCredits();
        void setTeacher(Teacher teacher);
        void setCredits(int credits);
};

#endif // Course_H
