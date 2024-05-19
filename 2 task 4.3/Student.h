#pragma once

#include <string>
#include <fstream>

using namespace std;

class Student 
{
    string name;
    int age;
    int course;
    string gender;
    double grade;
    double average_grade;

public:
    Student();
    Student(const string&, int, int, const string&, double);
    Student(const Student&);
    Student(Student&&);
    ~Student();
    string get_name() const;
    int get_age() const;
    int get_course() const;
    string get_gender() const;
    int get_grade() const;
    double get_average_grade() const;
    void delete_student();
    void enter_from_keyboard();
    void save_to_file(ofstream& file);
    void get_from_file(ifstream& file);
    void output();
    void operator=(const Student&);
};