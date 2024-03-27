#ifndef Student_h
#define Student_h

#include <string>
#include <vector>
#include "Course.h"

class Student 
{
    private:
        struct StudentInfo 
        {
            std::string name;
            int semester;
            int id;
        };

        std::vector<StudentInfo> students;

    public:
        void registerStudent();
        void saveDataToFile(const std::string& filename);
};


#endif 

