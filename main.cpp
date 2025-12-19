#include "management_system.h"

int main() {
    clearScreen();
    cout << "=== SMART UNIVERSITY MANAGEMENT SYSTEM ===\n\n" << endl;

    Student student("ALI", 12, "password123");
    // clearScreen();
    studentMenu(student);
    
    Teacher teacher("Asghar Hassan", 43, "qwerty123");
    // clearScreen();
    teacherMenu(teacher, student);
    
    Admin admin("Admin1", 12, "password9090");
    // clearScreen();
    adminMenu(admin, teacher,student);
    return 0;
}
