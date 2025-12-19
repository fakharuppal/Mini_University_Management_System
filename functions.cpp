#include "management_system.h"

//---------User class functions---------
//User Class Constructor
User::User(string userName, int userId) {
    cout<<"\033[31m-->\033[0m \033[32mUser Class Constructor calling\033[0m"<<endl;
    name = userName;
    id = userId;
}
void User::getDetail(){
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
}
//password setter
void User::passwordSet(string userPassword){
    password = userPassword;
}
//Login and Logout functions
void User::login(){
    cout << name << " logged in." << endl;
}
void User::logout(){
    cout << name << " logged out." << endl;
}
User::~User(){
    cout<<"\033[31m-->\033[0m \033[32mUser Class Destructor calling\033[32m"<<endl;
}

//---------End of User class functions---------

//---------Student Class-----------------------
Student::Student(string userName, int userId, string userPassword) : User(userName, userId) {
    passwordSet(userPassword);
    cout<<"\033[31m-->\033[0m \033[32mStudent Class Constructor calling\033[32m"<<endl;
}
//add grades
void Student::addcourse(string courseName, int credits){
    if(courseCount<5){
        course[courseCount]=Course(courseName, credits);
        courseCount++;
    }
    else{
        cout<<"Course limit reached!"<<endl;
    }
}
//getting Name
string Student::getName(){
        return name;
}
//view Courses
void Student::getCourseDetail(){
    for(int i=0;i<courseCount;i++){
        course[i].getCourses();
    }
}
//get course by index
Course& Student::getCourse(int index){
    return course[index];
}
Student::~Student(){
    cout<<"\033[31m-->\033[0m \033[32mStudent Class Destructor calling\033[0m"<<endl;
}

// -------Course Class Functions--------
Course::Course(){
        courseName="";
        credits=0;    
}
//Parameterized Constructor
Course::Course(string courseName, int credits){
        this->courseName=courseName;
        this->credits=credits;
        cout<<"\033[31m-->\033[0m \033[32mCourse Class Constructor calling\033[0m"<<endl;
}
//get Courses
void Course::getCourses(){
    cout << "Course: " << courseName << " Credits: " << credits <<" Marks: "<< marks<< endl;
}
//setting marks
void Course::setMarks(int marks){
    this->marks= marks;
}
//getting marks
int Course::getMarks(){
    return marks;
}
Course::~Course(){
    cout<<"\033[31m-->\033[0m \033[32mCourse Class Destructor calling\033[0m"<<endl;
}

//----------Teacher Class Functions---------
Teacher::Teacher(string userName, int userId, string userPassword) : User(userName, userId) {
    passwordSet(userPassword);
    cout<<"\033[31m-->\033[0m \033[32mTeacher Class Constructor calling\033[0m"<<endl;
}
void Teacher::viewStudentMarks(Student &s, int courseIndex){
    cout << "Student " << s.getName();
    s.getCourse(courseIndex).getCourses();
}
void Teacher::addMarks(Student &s, int courseIndex,int marks){
    s.getCourse(courseIndex).setMarks(marks);
}
void Teacher::teacherDetail(){
    getDetail();
}
Teacher::~Teacher(){
    cout<<"\033[31m-->\033[0m \033[32mTeacher Class Destructor calling\033[0m"<<endl;
}
//----------Admin Class Functions---------
Admin::Admin(string userName, int userId, string userPassword) : User(userName, userId) {
    passwordSet(userPassword);
    cout<<"\033[31m-->\033[0m \033[32mAdmin Class Constructor calling\033[0m"<<endl;
}
Admin::~Admin(){
    cout<<"\033[31m-->\033[0m \033[32mAdmin Class Destructor calling\033[0m"<<endl;
}

//---------Management System Menu---------

void studentMenu(Student &student){
    int menuChoice, credits;
    do{
        cout<<"\n\033[32m--- Student Menu ---\033[0m"<<endl;
        cout<<"\033[31m1. Register Course\033[0m"<<endl;
        cout<<"\033[31m2. View Grades\033[0m"<<endl;
        cout<<"\033[31m3. View Student Info\033[0m"<<endl;
        cout<<"\033[31m4. Exit\033[0m"<<endl;
        cout<<"\n\033[33mEnter your choice: \033[0m";
        cin>>menuChoice;
        string course;

        switch(menuChoice){
            case 1:
                cout<<"\033[35m---- Registering course:\033[0m \n"<<endl;
                cout<<"Course Name: ";
                cin>>course;
                cout<<"Course Credits";
                cin>>credits;
                student.addcourse(course, credits);
                break;
            case 2:
                cout<<"\n\033[35mViewing grades:\033[0m "<<endl;
                student.getCourseDetail();
                break;
            case 3:
                cout<<"\n\033[35mStudent Detail\033[0m"<<endl;
                student.getDetail();
                break;
            case 4:
                cout<<"\n\033[35mExiting student menu!! \033[0m"<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(menuChoice!=4);
}
void teacherMenu(Teacher &teacher, Student &student){
    int menuChoice,marks,courseNumber;
    do{
        cout<<"\n\033[32m--- Teacher Menu ---\033[0m"<<endl;
        cout<<"\033[31m1. Set Course Marks\033[0m"<<endl;
        cout<<"\033[31m2. View Student Grades\033[0m"<<endl;
        cout<<"\033[31m3. View Teacher Info\033[0m"<<endl;
        cout<<"\033[31m4. Exit\033[0m"<<endl;
        cout<<"\n\033[36mEnter your choice: \033[0m";
        cin>>menuChoice;
        string course;
        switch(menuChoice){
            case 1:
                cout<<"\n\033[35mSetting course marks: \033[0m"<<endl;
                student.getCourseDetail();
                cout<<"Which course to set marks for (0 or 1): ";
                cin>>courseNumber;
                cout<<"Marks to add: ";
                cin>>marks;
                teacher.addMarks(student, courseNumber, marks);
                break;
            case 2:
                cout<<"\n\033[35mViewing grades:\033[0m "<<endl;
                student.getCourseDetail();
                break;
            case 3:
                cout<<"\n\033[35mStudent Detail\033[0m"<<endl;
                teacher.getDetail();
                break;
            case 4:
                cout<<"\nExiting student menu"<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(menuChoice!=4);
}

void adminMenu(Admin &admin, Teacher &teacher, Student &student){
    int menuChoice;
    do{
        cout<<"\n\033[32m--- Admin Menu ---\033[0m"<<endl;
        cout<<"\033[31m1. View Teacher Info\033[0m"<<endl;
        cout<<"\033[31m2. View Student Info\033[0m"<<endl;
        cout<<"\033[31m3. View Admin Info\033[0m"<<endl;
        cout<<"\033[31m4. Exit\033[0m"<<endl;
        cout<<"\n\033[36mEnter your choice: \033[0m";
        cin>>menuChoice;
        string course;
        switch(menuChoice){
            case 1:
                cout<<"\n\033[35mViewing teacher info...\033[0m"<<endl;
                teacher.teacherDetail();
                break;
            case 2:
                cout<<"\n\033[35mViewing student info...\033[0m"<<endl;
                student.getDetail();
                student.getCourseDetail();
                break;
            case 3:
                cout<<"\n\033[35mAdmin Detail\033[0m"<<endl;
                admin.getDetail();
                break;
            case 4:
                cout<<"\nExiting admin menu"<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(menuChoice!=4);
    
}
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
//--------------=-------------------
