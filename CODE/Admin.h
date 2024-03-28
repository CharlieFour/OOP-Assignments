#ifndef Admin_H
#define Admin_H

#include <string>

class Admin
{
    private:
        std::string name;
        std::string password;
    public:
        Admin(std::string name, std::string password);
        std::string getAdminName();
        std::string getAdminPassword();
        void setName(std::string name);
        void setPassword(std::string password);
};

#endif
