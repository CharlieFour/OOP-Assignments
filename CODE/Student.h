#ifndef Student_h
#define Student_h

#include <string>
#include <vector>

class Student 
{
    private:
        struct StudentInfo 
        {
            std::string name;
            std::string semester;
            int id;

            StudentInfo() = default;
            StudentInfo(std::string name, std::string semester, int id) : name(name), semester(semester), id(id) {}
        };

        std::vector<StudentInfo> students;

    public:
        void registerStudent();
        void saveStudentFile();
        void loadStudentFile();
};


#endif 