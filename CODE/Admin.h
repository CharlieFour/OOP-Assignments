#ifndef Admin_H
#define Admin_H

#include <string>
#include "Person.h"

class Admin: public Person
{
    private:
        std::string password;
    public:
        Admin() = default;
        Admin(std::string name, std::string password) : Person(name) , password(password) {}
        ~Admin() = default;
        std::string getAdminName();
        std::string getAdminPassword();
        void setIdPass(std::string name, std::string password);
        bool checkIdPass(std::string name, std::string password);
        void saveAdminFile();
};

#endif
