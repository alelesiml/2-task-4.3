#pragma once

#include "Student.h"
#include <fstream>

const int MAX = 100;

class StudentDatabase 
{
    Student students[MAX];
    int num_of_students;

public:
    StudentDatabase();

    void enter_student_from_keyboard();
    void save_to_file(const string& filename);
    void get_from_file(const string& filename);
    void print();
    double calculate_score(int);
};