#ifndef Admin_H
#define Admin_H

#include <string>
#include "Teacher.h"

class Admin {
private:
    std::string name;
    std::string password;
public:
    Admin(std::string name, std::string password);
    std::string getName();
    std::string getPassword();
    void setName(std::string name);
    void addTeacher(Teacher teacher);
    void removeTeacher(Teacher teacher);
};

#endif // Admin_H