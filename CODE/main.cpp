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

void Student::setName(string Sname)
{
    Student* student = new Student ;
    for(int a = 0 ; a < 25 ; a++)
    {
        if(student.studentName[a] == 0)
        {
            student.studentName[a] = Sname;
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
            student.studentID[x] = 1000+a ; //1000+x 
            delete student;
            int a=25; //shdnt it be 1 so that 1000+1=1001 and then 1002, 1003..
            break;
        } 
    }
}


 void Student::setSemester(int semester, int studentID)
 {
    Student new student;
    int new ID = (1000-studentID);
    student.studentSemester[ID] = semester; 
    delete student, ID;
 }
 
 void Student::setPassword(string password)
 {
    Student new student;
    int new ID = (1000-studentID);
    student.studentSemester[ID] = semester; 
    delete student, ID;
 }


string Student:: getName(int studentID)
{
    Student new student;
    int new ID = (1000-studentID);
    return student.studentName[ID]; 
}

int Student::getStudentID()
{
    Student new student;
    int new ID = (1000-studentID);
    student.studentName[ID];  
    
}

string Student::getSemester(int studentID) 
{
    Student new student;
    int new ID = (1000-studentID);
    student.studentSemester[ID];  
    
}

string Student::getPassword(int studentID)
{
    Student new student;
    int new ID = (1000-studentID);
    student.studentPassword[ID];
}

void Teacher::setName(string Sname)
{
    Teacher new teacher ;
    for(int a = 0 ; a < 5 ; a++)
    {
        if(teacher.teacherName[a] == 0)
        {
            teacher.teacherName[a] = Sname;
            delete teacher;
            break;
        }
        else
        {
            cerr << "max limit reached (5)" << endl;
        }
    }


}

void Teacher::setID(string studentID)
{
Teacher new teacher;

    for(int x = 0 ; x < 5 ; x++)
    {
        if( teacher.teacherID[x] == 0 )
        {
           teacher.teacherID[x] = 100+x ;
            delete teacher;
            x=1;
            break;
        } 
    }
}


void Teacher:: setCourse(string course, int studentID)
{
   Teacher new teacher;
    int new ID = (10000-studentID);
    teacher.teacherCourse[ID];  
}

void Teacher:: setPassword(string password)
{
      Teacher new teacher;
    int new ID = (1000-studentID);
   teacher.teacherPassword[ID];
}


    string Teacher:: getName(int studentID)
    {
    Teacher new teacher;
    int new ID = (100-studentID);
    return teacher.teacherName[ID]; 
    }

    string Teacher:: getID()
    {
    Teacher new teacher;
    int new ID = (1000-studentID);
    Teacher.teacherName[ID];  
    }

    string Teacher:: getCourse(int studentID)
    {
    Teacher new teacher;
    int new ID = (100-studentID);
    teacher.teacherCourse[ID];  
    }

    string Teacher:: getPassword(int studentID)
    {
    Teacher new teacher;
    int new ID = (100-studentID);
   Teacher.teacherPassword[ID];
    } //comment





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