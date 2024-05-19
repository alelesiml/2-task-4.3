#include "DataBase.h"
#include <iostream>

StudentDatabase::StudentDatabase() 
{
    num_of_students = 0;
}

void StudentDatabase::enter_student_from_keyboard() 
{
    if (num_of_students >= MAX) 
    {
        cout << "База данных заполнена" << endl;
        return;
    }

    Student new_student;
    new_student.enter_from_keyboard();
    students[num_of_students] = new_student;
    num_of_students++;
}

void StudentDatabase::save_to_file(const string& filename)
{
    ofstream file(filename, ios::binary);
    if (file) 
    {
        file.write(reinterpret_cast<const char*>(&num_of_students), sizeof(num_of_students));
        for (int i = 0; i < num_of_students; i++)
        {
            students[i].save_to_file(file);
        }
        file.close();
        cout << "Данные сохранены в файл: " << filename << endl;
    }
    else 
    {
        cout << "Ошибка открытия файла: " << filename << endl;
    }
}

void StudentDatabase::get_from_file(const string& filename) 
{
    ifstream file(filename, ios::binary);
    if (file) 
    {
        file.read(reinterpret_cast<char*>(&num_of_students), sizeof(num_of_students));
        for (int i = 0; i < num_of_students; i++) 
        {
            students[i].get_from_file(file);
        }
        file.close();
        cout << "Данные сохранены в файл: " << filename << endl;
    }
    else 
    {
        cout << "Ошибка открытия файла: " << filename << endl;
    }
}

void StudentDatabase::print()
{
    for (int i = 0; i < num_of_students; i++) 
    {
        cout << "Студент " << i + 1 << ":" << endl;
        students[i].output();
        cout << endl;
    }
}

double StudentDatabase::calculate_score(int course)
{
    int q = 0;
    double score = 0;

    for (int i = 0; i < num_of_students; i++)
    {
        if (students[i].get_course() == course)
        {
            score += students[i].get_grade();
            q++;
        }
    }
    score = score / q;
    cout << "Средний балл: " << score << endl;
    return score;
}