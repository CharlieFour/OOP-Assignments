#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

#include "Admin.h"    
#include "Teacher.h"
#include "Course.h"

using namespace std;

int main()
{
}

//create file for student counter 

void Student::setName(string name)
{
    Student* student = new Student ;
    for(int a = 0 ; a < 25 ; a++)
    {
        if(student.studentName[a] == 0)
        {
            student.studentName[a] = name;
            delete student;
            break;
        }
        else
        {
            cerr << "max limit reached (25)" << endl;
        }
    }
    delete student;
}

void Student::setStudentID()
{
    Student new student;

    for(int x = 0 ; x < 25 ; x++)
    {
        if( student.studentID[x] == 0 )
        {
            student.studentID[x] = 1000+x ;
            delete student;
            x=25;
            break;
        } 
    }
}


 void Student::setSemester(int semester, int id)
 {
    Student new student;
    int new ID = (1000-id);
    student.studentSemester[ID] = semester; 
    delete student, ID;
 }
 
 void Student::setPassword(string password)
 {
    Student new student;
    int new ID = (1000-id);
    student.studentSemester[ID] = semester; 
    delete student, ID;
 }


string Student:: getName(int id)
{
    Student new student;
    int new ID = (1000-id);
    return student.studentName[ID]; 
}

int Student::getStudentID()
{
    Student new student;
    int new ID = (1000-id);
    student.studentName[ID];  
    
}

string Student::getSemester(int id) 
{
    Student new student;
    int new ID = (1000-id);
    student.studentSemester[ID];  
    
}

string Student::getPassword(int id)
{
    Student new student;
    int new ID = (1000-id);
    student.studentPassword[ID];
}

void Teacher::setName(string name)
{

}

void Teacher::setID(string id)
{

}

void Teacher:: setCourse(string course)
{

}

void Teacher:: setPassword(string password)
{

}








void startMenu()
{
     int a;
     cout << "welcome to Bahria's start menu!";
     cout << "what would you like to do today?" << endl;
     cout << "1.View class schedule" << endl;
     cout << "2.Manage teacher schedule" << endl;
     cout << "3.Manage student schedule" << endl;
     cout << "Enter your choice: ";
     cin >> a;

     switch(a)
     {
         case 1:
             cout << "class schedule:" << endl;

             break;
         case 2:
             cout << "teacher schedule:" << endl;
             break;
         case 3:
             cout << "student schedule:" << endl;
             break;
         default:
             cout << "invalid choice:" << endl;
             break;
     }
     return 0;
}

void Register()
{
    int choice;
    string name;

    cout << "Student Registeration" << endl;
    
    const int studentNumber = 5;

    string semester1[studentNumber]=0;
    string semester2[studentNumber]=0;
    string semester3[studentNumber]=0;
    string semester4[studentNumber]=0;
    string semester5[studentNumber]=0;

    
}

