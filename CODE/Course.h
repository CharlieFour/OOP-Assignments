#ifndef Course_H
#define Course_H

#include <string>
#include "Teacher.h"
#include "Student.h"

class Course {
private:
    std::string courseName;
    Teacher courseTeacher;
    int courseCredits;
    std::vector<Student> enrolledStudents;
public:
    Course(std::string name, Teacher teacher, int credits);
    std::string getName();
    std::string getTeacher();
    int getCredits();
    void setTeacher(Teacher teacher);
    void setCredits(int credits);
    void addStudent(Student student);
    void removeStudent(Student student);
};

#endif // Course_H
