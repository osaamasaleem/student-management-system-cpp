Student Record Management System
This C++ project implements a simple command-line based Student Record Management System. It facilitates the management of students, courses, and teachers, offering distinct functionalities based on the user's role (Administrator, Teacher, or Student).

Features
Administrator
Manage Students: Add new student records, modify existing student details, view a comprehensive list of all enrolled students, and delete student entries.
Manage Courses: Create new course entries, update existing course information, and remove courses from the system.
Manage Teachers: Add new teacher accounts, edit teacher contact and login details, and delete teacher records.
Generate Reports: Produce various reports including student report cards, attendance summaries, and a complete student list.
Teacher
Enter Grades: Input student grades for courses they are assigned to teach.
View Grades: Access and review student grades specifically for their assigned courses.
Mark Attendance: Record student attendance for the courses they teach.
Generate Reports: Create student report cards, attendance reports, and a general student list.
Authorization Note: Teachers are authorized to perform actions (like entering grades or marking attendance) only for courses where they are designated as the instructor. The system enforces this access control.
Student
View Grades: Check their own grades for all courses they are enrolled in. This information can also be exported to a text file.
View Courses: See a list of all courses they are currently enrolled in.
View Attendance: Review their attendance status for each enrolled course.
General Functionality
Role-Based Login System: Secure access for Administrators, Teachers, and Students through separate login interfaces.
Teacher Signup: Provides an option for new teachers to create their accounts within the system.
In-Memory Data Storage: All system data (students, teachers, courses) is stored in memory using arrays.
File Export: Allows students to save their grades and teachers to export various reports to .txt files.
Getting Started
Prerequisites
You'll need a C++ compiler (such as G++).

Compiling and Running
Save the code: Save the provided C++ source code as main.cpp (or any other .cpp filename of your choice).
Compile: Open your terminal or command prompt. Navigate to the directory where you saved main.cpp and compile the code:
Bash

g++ main.cpp -o student_system
Run: Execute the compiled program:
Bash

./student_system
Usage
Upon launching the application, you will be presented with a main menu. You can choose to log in as an Administrator, Teacher, Student, or opt to Sign Up if you are a new teacher.

Default Credentials:
Administrator:
Username: admin
Password: 123
Initial Teachers:
Huzaifa: huzaifa / huzaifa456 (Assigned to: OOP)
Ali: ali / ali456 (Assigned to: CA)
Zobia: roohma / roohma456 (Assigned to: AP)
Student (General Login):
Username: student
Password: 789
Note: For student-specific actions like viewing grades or attendance, you will be prompted to enter a specific Student ID (e.g., 11 for Ahmed).
Follow the on-screen instructions to navigate through the menus and utilize the system's features.

