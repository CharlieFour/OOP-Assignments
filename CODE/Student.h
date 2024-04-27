#ifndef Student_h
#define Student_h

#include <string>
#include <vector>
#include "Person.h"

class Student : public Person
{
    private:
        std::string semester;
        /*struct StudentInfo 
        {
            std::string name;
            std::string semester;
            std::string id;

            StudentInfo() = default;
            StudentInfo(std::string name, std::string semester, std::string id) : name(name), semester(semester), id(id) {}
        };

        std::vector<StudentInfo> students;*/

    public:
        Student() = default;
        Student(const std::string semester);
        std::string getSemester();
        void setSemester(const std::string semester);
        /*void registerStudent();
        void saveStudentFile();
        void loadStudentFile();*/
};

#endif 