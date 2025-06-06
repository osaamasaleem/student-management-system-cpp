# 🎓 Student Record Management System

A **C++ command-line application** designed to manage student records, courses, and teachers efficiently. It supports multiple roles: Administrator, Teacher, and Student — each with distinct functionalities and access rights.

---

## 📌 Features

### 👮‍♂️ Administrator
- Add, edit, delete, and list **students**, **teachers**, and **courses**
- Generate:
  - Student report cards
  - Attendance reports
  - Complete student lists

### 👨‍🏫 Teacher
- Add/view **grades** for assigned courses
- Mark/view **attendance** for assigned courses
- Generate:
  - Student report cards
  - Attendance records
  - General reports

> 🔒 Teachers are **restricted** to their assigned courses only

### 👨‍🎓 Student
- View:
  - Enrolled courses
  - Personal grades
  - Attendance records
- Export grades to a `.txt` file

---

## 📋 Usage Instructions

After launching the program, a main menu will appear.

You can:

- Log in as:
  - **Administrator**
  - **Teacher**
  - **Student**
- Or **Sign up** as a new teacher

---

## 🔐 Default Login Credentials

### 🛡️ Administrator
- **Username:** `admin`
- **Password:** `123`

### 👨‍🏫 Teachers

| Name    | Username | Password     | Assigned Course |
|---------|----------|--------------|-----------------|
| Huzaifa | huzaifa  | huzaifa456   | OOP             |
| Ali     | ali      | ali456       | CA              |
| Zobia   | roohma   | roohma456    | AP              |

### 👨‍🎓 Student
- **Username:** `student`
- **Password:** `789`

> ℹ️ For student actions (like viewing grades or attendance), enter the **Student ID** (e.g., `11` for Ahmed).

---

## ⚙️ How to Compile and Run

### 📦 Requirements
- C++ compiler (e.g., `g++`)

### 💻 Steps

1. Save the code to a file (e.g., `main.cpp`)
2. Compile & Run

