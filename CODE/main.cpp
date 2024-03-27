#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>

#include "Admin.h"    
#include "Teacher.h"
#include "Course.h"
#include "Student.h"

using namespace std;

int maxStudents=25; //for login function
int maxTeachers=5;

int main()
{
}

//create file for student counter 

void Student::registerStudent() 
{
    StudentInfo newStudent;
    
    cout << "Enter student's name: ";
    getline(cin, newStudent.name);

    cout << "Enter student's semester: ";
    cin >> newStudent.semester;

   
    srand(time(nullptr)); 
    bool uniqueIDFound = false;
    while (!uniqueIDFound) 
    {
        newStudent.id = rand() % 9000 + 1000; 
        bool duplicate = false;
        for (const auto& student : students) 
        {
            if (student.id == newStudent.id) 
            {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) 
        {
            uniqueIDFound = true;
        }
    }

    students.push_back(newStudent);
}

void Student::saveDataToFile(const string& filename) 
{
    ofstream outFile(filename);
    if (!outFile) 
    {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    outFile << "Student ID" << setw(15) << "Name" << setw(20) << "Semester" << endl;
    for (const auto& student : students) 
    {
        outFile << student.id << setw(20) << student.name << setw(15) << student.semester << endl;
    }

    outFile.close();

}


// Teacher methods
Teacher::Teacher(string name, string id, string course) :
    teacherName(name), teacherID(id), teacherCourse(course) {}

string Teacher::getName() 
{ 
     return teacherName; 
}
string Teacher::getID() 
{ 
    return teacherID; 
}
string Teacher::getCourse() 
{ 
    return teacherCourse; 
}
void Teacher::setName(string name) 
{ 
    teacherName = name; 
}
void Teacher::setID(string id) 
{ 
    teacherID = id; 
}
void Teacher::setCourse(string course) 
{ 
    teacherCourse = course; 
}


void startMenu()
{
    
    int choice, a , x ;

    cout << "Welcome to Bahria University LMS" << endl;
    cout << "Do you want to:" << endl;
    cout << "1.login" << endl;
    cout << "2.Register" << endl;
    cin >> choice;

    do
    {
    if(choice==1)
    {
        login();
    }
    if(choice==2)
    {
        registerUser();
        login();
    }

     cout << "Do you want to (1)Start or (2)Quit?" << endl;
     cin >> x;

     if(x == 1)
     {
        cout << "You have accessed the Start Menu" << endl;
     }
     if(x == 2)
     {
        cout << "You chose to quit. Goodbye" << endl;
        exit(0);
     }

    }while(x < 1 || x < 3 );

     cout << "Do you want to view as:" << endl;
     cout << "1.Student" << endl;
     cout << "2.Teacher" << endl;
     cout << "3.Exit" << endl;
     cout << "Enter your choice: ";
     cin >> a;

     switch(a)
     {
        case 1:
            cout << "You're viewing as a STUDENT. Would you like to:" << endl;
            cout << "1. View timetable" << endl;
            cout << "2. View Section Timetable" << endl;
            cout << "3. View Room Timetable" << endl;
            cout << "4. View Course Information" << endl;
             break;

        case 2:
            cout << "You're viewing as a TEACHER. Would you like to:" << endl;
            cout << "2. View Section Timetable" << endl;
            cout << "3. View Room Timetable" << endl;
            break;

        case 3:     
            cout << "General Options:" << endl;
            cout << "1. Query Timetable" << endl;
         
        case 4:
            cout << "You have successfully exitted." << endl;
            exit(0);
     }

     return 0;
}



void registerUser()
{
    string Sname; 
    int numberOfStudents=0;
    int studentID[maxStudents]=0; //maxstudents defined at top
    string studentName[maxStudents]=0;;
    int studentID = 1000;
    int o;

    string Tname; 
    int numberOfTeachers=0;
    int teacherID[maxTeachers]=0; //maxTeachers defined at top
    string teacherName[maxTeachers]=0;;
    int teacherID = 100;

    cout << "do you want to register as a \n 1.Student or \n 2.Teacher " << endl;
    cin >> o;

    do {
    if(o==1)
    {
        cout << "Welcome. Enter your name: " << cout;
        cin >> Sname;
        if(numberOfStudents>=maxStudents)
        {
            cout << "Max limit has been reached." << endl;
        }
        else if(maxStudents<=numberOfStudents)
        {
            for(int a = 0 ; a < 25 ; a++)
            {
            
                if(studentName[a] == 0)
                {
                    studentName[a] = Sname;
                    studentID[a] = studentID+numberOfStudents;
                    cout << "Welcome " << studentName[a] << "Your ID is: " << studentID[a] << endl;
                    numberOfStudents++;
                    studentID++;
                    break;
                }
            }
        }
    }
    if(o == 2)
    {
         cout << "Welcome. Enter your name: " << cout;
        cin >> Tname;
        if(numberOfTeachers>=maxTeachers)
        {
            cout << "Max limit has been reached." << endl;
        }
        else if(maxTeachers<=numberOfTeachers)
        {
            for(int a = 0 ; a < 5 ; a++)
            {
            
                if(teacherName[a] == 0)
                {
                    teacherName[a] = Tname;
                    teacherID[a] = teacherID + numberOfTeachers;
                    cout << "Welcome " << teacherName[a] << "Your ID is: " << teacherID[a] << endl;
                    numberOfTeachers++;
                    teacherID++;
                    break;
                }
            }
        }
    }
    }while(o < 1 || o > 3);

}


void Login()
{
    int a, choice;
    cout << "Welcome to the login page." << endl;
    cin >> a;
    
     do {
        cout << "Do you want to log in as \n1.Student \n2.Teacher \n3.Admin" << endl;
        cin >> choice;

        if (choice < 1 || choice > 3) 
        {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    } while (choice < 1 || choice > 3);

    if(a == 1)
    {
        string username;
        cout << "Enter your username: " << endl;
        cin >> username;

        cout << "Enter your password: " << endl;

    }
   

}

//------------------------------------ :D ------------------------------------------

Admin::Admin(string Sname, string password) : Sname(Sname), password(password) {}
string Admin::getName()
{
    return Sname;
}
string Admin::getPassword()
{
    return password;
}
void Admin::setName(string Sname)
{
    this -> Sname = Sname;
}
void Admin::addTeacher(Teacher teacher)
{
    
}
void Admin::removeTeacher(Teacher teacher)
{  

}

Course::Course(string Sname, Teacher teacher, int credits) : courseName(Sname), courseTeacher(teacher), courseCredits(credits) {}
string Course::getName()
{
    return courseName;
}
string Course::getTeacher()
{
    return courseTeacher.getName();
}
int Course::getCredits()
{
    return courseCredits;
}
void Course::setTeacher(Teacher teacher)
{
    courseTeacher = teacher;
}
void Course::setCredits(int credits)
{
    courseCredits = credits;
}
void Course::addStudent(Student student)
{
    enrolledStudents.push_back(student);
}
void Course::removeStudent(Student student)
{
    // Implementation to remove student
}