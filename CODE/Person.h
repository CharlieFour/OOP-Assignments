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
        Person(std::string id, std::string name) : id(id), name(name) {}
};

#endif