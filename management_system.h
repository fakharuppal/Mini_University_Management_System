#include <iostream>
#include <fstream>
using namespace std;

//User Class
class User{
private:
    string password;
protected:
    string name;
    int id;
public:
    void getDetail();
    User(string, int);
    //Login and Logout functions
    void login();
    void logout();
    //password setter
    void passwordSet(string userPassword);
    ~User();
};

class Course{
protected:
    string courseName;
    int marks=0, credits;
public:
    Course();
    Course(string courseName, int credits);
    void getCourses();
    void setMarks(int marks);
    int getMarks(); 
    ~Course();
};

//Student CLass 
class Student: public User{
protected:
    Course course[5];
    int courseCount=0;
public:
    Student(string, int, string);
    //add grades
    void addcourse(string courseName, int credits);
    //getNAme
    string getName();
    //view Courses
    void getCourseDetail();
    //get course by index
    Course& getCourse(int index);
    ~Student();
};
//Teacher Class
class Teacher: public User{
public:
    Teacher(string, int, string);
    void viewStudentMarks(Student &s, int courseIndex);
    void addMarks(Student &s, int courseIndex,int marks);
    void teacherDetail();
    ~Teacher();
};
//Admin Class
class Admin: public User{
public:
    Admin(string, int, string);
    ~Admin();
};

//Management System Menu
void UserType();
void studentMenu(Student &student);
void teacherMenu(Teacher &teacher, Student &student);
void adminMenu(Admin &admin, Teacher &teacher, Student &student);
void clearScreen();
