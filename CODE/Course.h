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
        /*Course() = default;
        Course(std::string name) : courseName(name) {}
        Course(std::string name, Teacher teacher, int credits) : courseName(name), courseTeacher(teacher), courseCredits(credits) {}
        std::string getName() const;
        std::string getTeacher();
        int getCredits();
        void setTeacher(Teacher teacher);
        void setCredits(int credits);*/
};

#endif // Course_H
