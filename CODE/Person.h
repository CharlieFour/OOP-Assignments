#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person
{
    private:
        std::string id;
        std::string name;
    public:
        Person() = default;
        Person(std::string id) : id(id) {}
        Person(std::string name) : name(name) {}
        Person(std::string id, std::string name) : id(id), name(name) {}
        ~Person() = default;
        std::string getName() const ;
        std::string getId() const ;
        void setName(std::string name);
        void setId(std::string id);
};

#endif