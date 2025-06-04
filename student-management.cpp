#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Teacher{
	public:
		string name;
		string contact;
		string username;
		string password;
};
class Course{
    public:
    string name;
    string instructor;
};
class Student {
    public:
    string name;
    int id;
    string address;
    string contact;
    string grade[5];
    bool present[5];

};
class StudentRecordSystem{
    private:  	
    static const int Max_Teachers = 10;	
    const int Max_Courses = 10;
    const int Max_Students = 20;
    string loggedInTeacher;
    Teacher teachers[Max_Teachers]={
	{"huzaifa","876543","huzaifa","huzaifa456"},
	{"ali","567890","ali","ali456"},
	{"zobia","456789","roohma","roohma456"}
	};
    Course courses[10]={
        {"OOP","huzaifa"},
        {"CA","ali"},
        {"AP","zobia"}
    };
    Student students[20]={
         {"Ahmed", 11, "Main", "7894", {"A"}, {false, false, false}},
        {"Junaid", 12, "Street", "5678", {"A"}, {false, false, false}},
        {"Saad", 13, "Rwp", "9012", {"B"}, {false, false, false}},
        {"Ammad", 14, "Lhr", "7894", {"A"}, {false, false, false}},
        {"abdullah", 15, "sadar", "3454", {"D"}, {false, false, false}},
        {"Rafay", 16, "Cantt", "2345", {"B"}, {false, false, false}},
        {"Ali", 17, "Main", "7678", {"A"}, {false, false, false}},
        {"Umar", 18, "Isb", "2134", {"A"}, {false, false, false}},
        {"Usman", 19, "Rwp", "6787", {"C"}, {false, false, false}},
        {"Taha", 20, "Main", "6788", {"C"}, {false, false, false}}  
	};   	
    int teacherCount=3;
    int courseCount=3;
    int studentCount=10; 
      bool isTeacherAuthorized(const string& courseName) {
        for (int i = 0; i < courseCount; ++i) {
            if (courses[i].name == courseName && courses[i].instructor == loggedInTeacher) {
                return true;
            }
        }
        return false;
    }
    public:
//line 46
     void addNewCourse();
    void addNewStudent();
    void enterGrades();
    void viewStudentGrades(bool isTeacher);    
    void markAttendance();
    void editStudentDetails();
    void editCourseDetails();
    void deleteStudent();
    void deleteCourse();
    void generateReport();
    void adminLogin();
    void teacherLogin();
    void studentLogin();
    void viewStudentCourses();
    void viewStudentAttendance();
    void displayMainMenu();
    void manageStudents();
    void adminMenu();
    void manageCourses();
    void teacherMenu();
    void studentMenu();
    void viewStudentList();
    void manageTeachers();
    void addNewTeacher();
    void editTeacherDetails();
    void deleteTeacher();
    void signupMenu();
    void teacherSignup();
    void reportCard();
	void attendanceReport(); 
	void studentListReport();
};
void StudentRecordSystem::addNewCourse() {
    if (courseCount >= Max_Courses) {
        cout << "Maximum Number of Courses Reached." << endl;
        return;
    }
    cout << "Enter Course Details" << endl;
    cout << "Enter Course Name: ";
    cin >> courses[courseCount].name;
    cout << "Enter Instructor's Name: ";
    cin >> courses[courseCount].instructor;
    cout << "Course Added Successfully." << endl;
    courseCount++;
}
void StudentRecordSystem::addNewStudent() {
    if (studentCount >= Max_Students) {
        cout << "Maximum Number of Students Reached." << endl;
        return;
    }
    cout << "Enter Student Details" << endl;
    cout << "Enter Name: ";
    cin >> students[studentCount].name;
    cout << "Enter ID: ";
    cin >> students[studentCount].id;
    cout << "Enter Address: ";
    cin >> students[studentCount].address;
    cout << "Enter Contact Number: ";
    cin >> students[studentCount].contact;
    cout << "Student Added Successfully." << endl;
    studentCount++;
}
void StudentRecordSystem::addNewTeacher(){
	if(teacherCount>= Max_Teachers){
		cout<< "Maximum Number of Teachers Reached." << endl;
		return;
	}
	cout<< "Enter Teacher Details" << endl;
	cout<< "Enter Name:	";
	cin>>teachers[teacherCount].name;
	cout<< "Enter Contact:	";
	cin>>teachers[teacherCount].contact;
	cout<<  "Enter Username: ";
	cin>>teachers[teacherCount].username;
	cout<< "Enter Password:	";
	cin>>teachers[teacherCount].password;
	teacherCount++;
	cout<<"Teacher Added Successfully"<<endl;
}
void StudentRecordSystem::editTeacherDetails() {
    string teacherName;
    cout << "Enter Teacher's name whose details you want to edit: ";
    cin >> teacherName;
    bool found = false;
    for (int i = 0; i < teacherCount; ++i) {
        if (teachers[i].name == teacherName) {
            found = true;
            cout << "Editing Teacher Details for name " << teacherName << ":" << endl;
            cout << "Enter new Name: ";
            cin >> teachers[i].name;
            cout << "Enter new Contact: ";
            cin >> teachers[i].contact;
            cout << "Enter new username: ";
            cin >> teachers[i].username;
            cout << "Enter new password: ";
            cin >> teachers[i].password;
            cout<<"\nTeacher Edited Successfully.\n";
        }
    }
    if (!found) {
        cout << "Teacher with name " << teacherName << " not found." << endl;
    }
}
void StudentRecordSystem::deleteTeacher() {
    string teacherName;
    cout << "Enter Teacher Name to delete: ";
    cin >> teacherName;
    for (int i = 0; i < teacherCount; ++i) {
        if (teachers[i].name == teacherName) {
            cout << "Details of teacher with name " << teacherName << ":" << endl;
            cout << "Name: " << teachers[i].name << endl;
            cout << "Contact: " << teachers[i].contact << endl;
            cout << "Username: " << teachers[i].username << endl;
            cout << "Password: " << teachers[i].password << endl;
            char confirm;
            cout << "Are you sure you want to delete this teacher? (Y/N): ";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                teachers[i] = teachers[teacherCount - 1];
                teacherCount--;
                cout << "Teacher with name " << teacherName << " deleted successfully." << endl;
            } else {
                cout << "Deletion cancelled." << endl;
            }
            return;
        }
    }
    cout << "Teacher with Name " << teacherName << " not found." << endl;
}
void StudentRecordSystem::manageTeachers() {
    while(true){
    cout << "\n******Manage Teachers******" << endl;
    cout << "1. Add New Teacher" << endl;
    cout << "2. Edit Teacher Details" << endl;
    cout << "3. Delete Teacher" << endl;
    cout << "4. Back " << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            addNewTeacher();
            break;
        case 2:
            editTeacherDetails();
            break;
        case 3:
        	deleteTeacher();
        	break;
        case 4:
            cout << "Returning " << endl;
            adminMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}
}
void StudentRecordSystem::enterGrades() {
    string courseName;
    cout << "Enter Course Name: ";
    cin >> courseName;
    if (!isTeacherAuthorized(courseName)) {
        cout << "You are not authorized to enter grades for this course." << endl;
        return;
    }
    // Find the course index
    int courseIndex = -1;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].name == courseName) {
            courseIndex = i;
            break;
        }
    }
    if (courseIndex == -1) {
        cout << "No course with this name found." << endl;
        return;
    }
    for (int i = 0; i < studentCount; ++i) {
        cout << "Enter Grades for student ID: " << students[i].id << " (Name: " << students[i].name << ") for Course: " << courseName << ": ";
        cin >> students[i].grade[courseIndex];
    }
    cout << "Grades updated successfully for course " << courseName << "." << endl;
}
void StudentRecordSystem::viewStudentGrades(bool isTeacher) {
    if (isTeacher) {
        cout << "******View All Student Grades******" << endl;
        for (int i = 0; i < studentCount; ++i) {
            cout << "Grades for " << students[i].name << " (ID: " << students[i].id << "):" << endl;
            for (int j = 0; j < courseCount; ++j) {
                if (isTeacherAuthorized(courses[j].name)) {
                    cout << courses[j].name << ": " << students[i].grade[j] << endl;
                }
            }
            cout << endl;
        }
    } else {
        cout << "******View Your Grades******" << endl;
        int studentID;
        cout << "Enter your Student ID: ";
        cin >> studentID;
        bool studentFound = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].id == studentID) {
                studentFound = true;
                cout << "Grades for " << students[i].name << " (ID: " << students[i].id << "):" << endl;
                for (int j = 0; j < courseCount; ++j) {
                    cout << courses[j].name << ": " << students[i].grade[j] << endl;
                }
                cout << "Do you want to print this to a file? (yes/no): ";
                string response;
                cin >> response;
                if (response == "yes") {
                    ofstream outFile("student_grades.txt");
                    if (outFile.is_open()) {
                        outFile << "******Grades for " << students[i].name << " (ID: " << students[i].id << ")******" << endl;
                        for (int j = 0; j < courseCount; ++j) {
                            outFile << courses[j].name << ": " << students[i].grade[j] << endl;
                        }
                        outFile.close();
                        cout << "Grades have been printed to 'student_grades.txt'." << endl;
                    } else {
                        cout << "Unable to open file for writing." << endl;
                    }
                }
                return;
            }
        }
        if (!studentFound) {
            cout << "Student with ID " << studentID << " not found." << endl;
        }
    }
}
void StudentRecordSystem::markAttendance() {
    string courseName;
    cout << "Enter course Name to mark attendance: ";
    cin >> courseName;
    if (!isTeacherAuthorized(courseName)) {
        cout << "You are not authorized to mark attendance for this course." << endl;
        return;
    }
    // Find the course index
    int courseIndex = -1;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].name == courseName) {
            courseIndex = i;
            break;
        }
    }
    if (courseIndex == -1) {
        cout << "No course with this name found." << endl;
        return;
    }
    for (int i = 0; i < studentCount; ++i) {
        cout << "Mark attendance for " << students[i].name << " (ID: " << students[i].id << "): ";
        char attendance;
        cout << "Present (P) or Absent (A)? ";
        cin >> attendance;
        if (attendance == 'P' || attendance == 'p') {
            students[i].present[courseIndex] = true;
        } else {
            students[i].present[courseIndex] = false;
        }
    }
    cout << "Attendance marked successfully for course " << courseName << "." << endl;
}
void StudentRecordSystem::editStudentDetails() {
    int studentID;
    cout << "Enter Student ID whose details you want to edit: ";
    cin >> studentID;
    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == studentID) {
            found = true;
            cout << "Editing Student Details for ID " << studentID << ":" << endl;
            cout << "Enter new Name: ";
            cin >> students[i].name;
            cout << "Enter new ID: ";
            cin >> students[i].id;
            cout << "Enter new Address: ";
            cin >> students[i].address;
            cout << "Enter new Contact: ";
            cin >> students[i].contact;
            cout<<"\nStudent Edited Successfully.\n";
        }
    }
    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}
void StudentRecordSystem::editCourseDetails() {
    string courseName;
    cout << "Enter Course Name whose details you want to edit: ";
    cin >> courseName;
    bool found = false;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].name == courseName) {
            found = true;
            cout << "Editing Course Details for Name " << courseName << ":" << endl;
            cout << "Enter new Course Name: ";
            cin >> courses[i].name;
            cout << "Enter new Instructor: ";
            cin >> courses[i].instructor;
        }
    }
    if (!found) {
        cout << "Course with Name " << courseName << " not found." << endl;
    }
}
void StudentRecordSystem::deleteStudent() {
    int studentID;
    cout << "Enter Student ID to delete: ";
    cin >> studentID;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == studentID) {
            cout << "Details of student with ID " << studentID << ":" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Contact Number: " << students[i].contact << endl;
            char confirm;
            cout << "Are you sure you want to delete this student? (Y/N): ";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                students[i] = students[studentCount - 1];
                studentCount--;
                cout << "Student with ID " << studentID << " deleted successfully." << endl;
            } else {
                cout << "Deletion cancelled." << endl;
            }
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found." << endl;
}
void StudentRecordSystem::deleteCourse() {
    string courseName;
    cout << "Enter Course Name to delete: ";
    cin >> courseName;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].name == courseName) {
            cout << "Details of Course with Name " << courseName << ":" << endl;
            cout << "Course Name: " << courses[i].name << endl;
            cout << "Instructor: " << courses[i].instructor << endl;
            char confirm;
            cout << "Are you sure you want to delete this course? (Y/N): ";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                courses[i] = courses[courseCount - 1];
                courseCount--;
                cout << "Course with Name " << courseName << " deleted successfully." << endl;
            } else {
                cout << "Deletion cancelled." << endl;
            }
            return;
        }
    }
    cout << "Course with Name " << courseName << " not found." << endl;
}
void StudentRecordSystem::viewStudentList() {
    cout<<"\n******View Student List******"<< endl;
    cout<< "Total Students: " << studentCount <<endl;
    cout<<"---------------------------------"<< endl;
    for (int i = 0; i < studentCount; ++i) {
        cout<<"Name: " << students[i].name <<endl;
        cout<<"ID: " << students[i].id <<endl;
        cout<<"Address: " << students[i].address<< endl;
        cout<<"Contact: " << students[i].contact <<endl;
        cout<<"---------------------------------" <<endl;
    }
}
void StudentRecordSystem::manageStudents() {
    while(true){
    cout<<"\n\n******Manage Students******"<<endl;
    cout<<"1. Add New Student"<<endl;
    cout<<"2. Edit Student Details"<<endl;
    cout<<"3. View Student List "<<endl;
    cout<<"4. Delete Student"<<endl;
    cout<<"5. Back "<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            addNewStudent();
            break;
        case 2:
            editStudentDetails();
            break;
        case 3:
            viewStudentList();
            break;
        case 4:
        	deleteStudent();
        	break;
        case 5:
            cout << "Returning " << endl;
            adminMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}
}
void StudentRecordSystem::manageCourses() {
    while(true){
    cout<<"\n******Manage Courses******" <<endl;
    cout<<"1. Add New Course"<<endl;
    cout<<"2. Edit Course Details"<<endl;
    cout<<"3. Delete Course"<<endl;
    cout<<"4. Back "<<endl;
    cout<<"Enter your choice:";
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:
            addNewCourse();
            break;
        case 2:
            editCourseDetails();
            break;
        case 3:
            deleteCourse();
            break;
        case 4:
            cout << "Returning " << endl;
            adminMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}
}
void StudentRecordSystem::adminMenu() {    
        cout<<"\n******Administrator Menu******"<<endl;
        cout<<"1.Manage Students" <<endl;
        cout<<"2.Manage Courses" <<endl;
        cout<<"3.Manage Teachers" <<endl;
        cout<<"4.Logout" << endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
                manageStudents();
                break;
            case 2:
                manageCourses();
                break;
            case 3:
            	manageTeachers();
            	break;
            case 4:
                cout << "Logged out Successfully\n" << endl;
				displayMainMenu();
            default:
                cout << "Invalid choice!" << endl;
displayMainMenu();        }
    }
void StudentRecordSystem::adminLogin() {
    cout << "\nAdministrator Login" << endl;
    string adminUsername = "admin";
    string adminPassword = "123";
    string username, password;
    int loginAttempts = 0;
    while(loginAttempts <3){	
	cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    if (username == adminUsername && password == adminPassword) {
        cout << "Logged in successfully." << endl;
        adminMenu();        
    } else {
        cout << "Invalid credentials. Please try again." << endl;
        loginAttempts++;        
    }
}
cout<<"Maximum Login Attempts Reached.Exiting...."<<endl;
exit(0);
}
void StudentRecordSystem::attendanceReport() {
    cout << "******View All Student Attendance******" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << "Attendance for " << students[i].name << " (ID: " << students[i].id << "):" << endl;
        for (int j = 0; j < courseCount; ++j) {
            cout << courses[j].name << ": ";
            if (students[i].present[j]) {
                cout << "P";
            } else {
                cout << "A";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Do you want to print this to a file? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes" || response == "Yes" || response == "y" || response == "Y") {
        ofstream outFile("student_report.txt");
        if (outFile.is_open()) {
            outFile << "******Attendance Report******" << endl;
            for (int i = 0; i < studentCount; ++i) {
                outFile << "Attendance for " << students[i].name << " (ID: " << students[i].id << "):" << endl;
                for (int j = 0; j < courseCount; ++j) {
                    outFile << courses[j].name << ": ";
                    if (students[i].present[j]) {
                        outFile << "P";
                    } else {
                        outFile << "A";
                    }
                    outFile << endl;
                }
                outFile << endl;
            }
            outFile.close();
            cout << "Attendance have been printed to 'student_report.txt'." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
}
void StudentRecordSystem::reportCard() {
    cout << "******View All Student Grades******" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << "Grades for " << students[i].name << " (ID: " << students[i].id << "):" << endl;
        for (int j = 0; j < courseCount; ++j) {
            cout << courses[j].name << ": " << students[i].grade[j] << endl;
        }
        cout << endl;
    }
    cout << "Do you want to print this to a file? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes" || response == "Yes" || response == "y" || response == "Y") {
        ofstream outFile("student_report.txt");
        if (outFile.is_open()) {
        	outFile<<"******Report Card******"<<endl;
            for (int i = 0; i < studentCount; ++i) {
                outFile << "Grades for " << students[i].name << " (ID: " << students[i].id << "):" << endl;
                for (int j = 0; j < courseCount; ++j) {
                    outFile << courses[j].name << ": " << students[i].grade[j] << endl;
                }
                outFile << endl;
            }
            outFile.close();
            cout << "Grades have been printed to 'student_report.txt'." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
}
void StudentRecordSystem::studentListReport(){
    cout << "\n******Student List Report******"<<endl;
    cout << "Total Students: " << studentCount <<endl;
    cout << "---------------------------------" <<endl;
    for (int i = 0; i < studentCount; ++i) {
        cout<<"Name: " << students[i].name <<endl;
        cout<<"ID: " << students[i].id <<endl;
        cout<<"Address: " << students[i].address <<endl;
        cout<<"Contact: " << students[i].contact <<endl;
        cout<<"---------------------------------" <<endl;
    }    
      cout << "Do you want to print this to a file? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes" || response == "Yes" || response == "y" || response == "Y") {
        ofstream outFile("student_report.txt");
        if (outFile.is_open()) {
        	outFile<<"******Student List Report******"<<endl;
            for (int i = 0; i < studentCount; ++i) {
        outFile<<"Name: " << students[i].name << endl;
        outFile<<"ID: " << students[i].id << endl;
        outFile<<"Address: " << students[i].address << endl;
        outFile<<"Contact: " << students[i].contact << endl;
        outFile<<"---------------------------------" << endl;
    }
                outFile << endl;
            }
            outFile.close();
            cout << "Student List have been printed to 'student_greport.txt'." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
    void StudentRecordSystem::generateReport(){
	cout<<"\nGenerate Report " <<endl;
	cout<<"1.Report Card"<<endl;
	cout<<"2.Attendance Report"<<endl;
	cout<<"3.Student List Report"<<endl;
	int choice;
	cout<<"Enter your Choice"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			reportCard();
			break;
		case 2:
			attendanceReport();
			break;
		case 3:
			studentListReport();
			break;
		default:
			cout<<"Invalid Choice!"<<endl;				
	}
}
void StudentRecordSystem::teacherMenu() {
    while(true){
        cout<<"\n******Teacher Menu******" <<endl;
        cout<<"1.Enter Grades"<<endl;
        cout<<"2.View Grades"<<endl;
        cout<<"3.Mark Attendance "<<endl;
        cout<<"4.Generate Report "<<endl;
		cout<<"5.Logout" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                enterGrades();
                break;
            case 2:
                viewStudentGrades(true);
                break;
            case 3:
            //attendance
            markAttendance();
            break;
            case 4:
            	generateReport();
            	break;
               case 5:
                cout << "Logging out..." << endl;
				 displayMainMenu();                 
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}
void StudentRecordSystem::teacherLogin() {
    cout<<"\nTeacher Login" << endl;
    string username, password;
    bool loggedIn = false; 
    int loginAttempts = 0;    
    while(loginAttempts<3){	
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;        
        for(int i = 0; i < teacherCount; i++) {
            string teacherUsername = teachers[i].username;
            string teacherPassword = teachers[i].password;
            if (username == teacherUsername && password == teacherPassword) {
                cout << "Logged in successfully. Welcome " <<teachers[i].name<< endl;
                loggedInTeacher = teachers[i].name;
                teacherMenu();
                loggedIn = true;
                break; 
            }
        }        
        if (!loggedIn) {
            cout << "Invalid credentials. Please try again." << endl;
            loginAttempts++; 
        }}
    cout<<"Maximum number of login attempts reached.Exiting...."<<endl;
    exit(0);
}
void StudentRecordSystem::teacherSignup(){
	if(teacherCount>= Max_Teachers){
		cout<< "Maximum Number of Teachers Reached." << endl;
		return;
	}
	cout<< "Enter Your Details" << endl;
	cout<< "Enter Name:	";
	cin>>teachers[teacherCount].name;
	cout<< "Enter Contact:	";
	cin>>teachers[teacherCount].contact;
	cout<<  "Enter desired Username: ";
	cin>>teachers[teacherCount].username;
	cout<< "Enter desired Password:	";
	cin>>teachers[teacherCount].password;
	teacherCount++;
	cout<<"You can use these credentials to login."<<endl;
}
void StudentRecordSystem::viewStudentCourses() {
    cout<<"\n******View Enrolled Courses******" <<endl;
    int studentID;
    cout<<"Enter your Student ID: ";
    cin>>studentID;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == studentID) {
            cout << "Courses Enrolled for " << students[i].name << ":" << endl;
            for (int j = 0; j < courseCount; ++j) {
                cout << courses[j].name << " - " << courses[j].instructor << endl;
            }
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found." << endl;
}
void StudentRecordSystem::viewStudentAttendance() {
    cout<<"\n******View Attendance******"<<endl;
    int studentID;
    cout<<"Enter your Student ID: ";
    cin>>studentID;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == studentID) {
            cout << "Attendance for " << students[i].name << ":" << endl;
            for (int j = 0; j < courseCount; ++j) {
                cout << courses[j].name << ": ";
                if (students[i].present[j]) {
                    cout << "Present" << endl;
                } else {
                    cout << "Absent" << endl;
                }
            }
            return;
        }
    }
    cout<<"Student with ID "<<studentID << " not found." <<endl;
}
void StudentRecordSystem::studentMenu() {
    while(true){
        cout<<"\n******Student Menu******" <<endl;
        cout<<"1. View Grades"<<endl;
        cout<<"2. View Courses"<<endl;
        cout<<"3. View Attendance "<< endl;
        cout<<"4. Logout"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
                viewStudentGrades(false);
                break;
            case 2:
                viewStudentCourses();
                break;
            case 3:
                viewStudentAttendance();
                break;
            case 4:
                cout << "Logging out..." << endl;
                displayMainMenu();
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}
void StudentRecordSystem::studentLogin() {
    cout<<"\nStudent Login"<<endl;
    string studentUsername = "student";
    string studentPassword = "789";
    string username, password;
    int loginAttempts = 0;
    while(loginAttempts<3){
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    if (username == studentUsername && password == studentPassword) {
        cout << "Logged in successfully." << endl;
        studentMenu();
    } else {
        cout << "Invalid credentials. Please try again." << endl;
        loginAttempts++;
    }
}
    cout<<"Maximum Number of login attempts reached.Exiting..."<<endl;
    exit(0);
}
void StudentRecordSystem::signupMenu() {
   while(true){ 
    cout<<"\n******Signup Menu******"<<endl;
    cout<<"1.Signup as Teacher"<<endl;
    cout<<"2.Back"<<endl;
    int choice;
    cout << "Enter Your Choice :";
    cin>>choice;
    switch(choice){
        case 1:
        teacherSignup();
        break;
        case 2:
        cout << "Returning...."<<endl;
        displayMainMenu();
        default:
        cout << "Invalid Chioce. \n";
    }
}
}
void StudentRecordSystem::displayMainMenu() {   
    cout<<"\n******Welcome to the Student Record System!******"<<endl;
    cout<<"1. Login as Administrator"<<endl;
    cout<<"2. Login as Teacher"<<endl;
    cout<<"3. Login as Student"<<endl;
    cout<<"4. To Signup "<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:
            adminLogin();
            break;
        case 2:
            teacherLogin();
            break;
        case 3:
            studentLogin();
            break;
        case 4 :
            signupMenu();
            break;
        case 5:
            cout << "Exiting..." << endl;
            exit(0);
            default:
            cout << "Invalid choice!" << endl;
    }
}
int main(){
  StudentRecordSystem srs;
    srs.displayMainMenu();
    return 0;
}