#include "Student.h"
#include <iostream>

Student::Student() 
{
    name = "";
    age = 0;
    course = 0;
    gender = "";
    grade = 0;
    average_grade = 0;
}
Student::Student(const string& name, int age, int course,const string& gender, double grade)
{
	this->name = name;
	this->age = age;
	this->course = course;
	this->gender = gender;
	this->grade = grade;
}

Student::Student(const Student& other_student)
{
	name = other_student.get_name();
	age = other_student.get_age();
	course = other_student.get_course();
	gender = other_student.get_gender();
	grade = other_student.get_grade();
}

Student::Student(Student&& other_student)
{
	name = other_student.get_name();
	age = other_student.get_age();
	course = other_student.get_course();
	gender = other_student.get_gender();
	grade = other_student.get_grade();
	other_student.delete_student();
}

Student::~Student() {}

string Student::get_name() const
{
    return name;
}

int Student::get_age() const
{
    return age;
}

int Student::get_course() const
{
    return course;
}

string Student::get_gender() const
{
    return gender;
}

int Student::get_grade() const
{
    return grade;
}

double Student::get_average_grade() const 
{
    return average_grade;
}

void Student::delete_student()
{
    name = "";
    age = 0;
    course = 0;
    gender = "";
    grade = 0;
}

void Student::enter_from_keyboard() 
{
    cout << "Введите ФИО: ";
    cin >> name;

    do
    {
        cout << "Введите возраст: ";
        cin >> age;
        if (age < 16)
        {
            cout << "Введен некорректный возраст" << endl;
            continue;
        }
    } while (age < 16);

    cout << "Введите курс: ";
    cin >> course;

    cout << "Введите гендер: ";
    cin >> gender;

    cout << "Введите успеваемость: ";
    cin >> grade;
}

void Student::save_to_file(ofstream& file)
{
    if (file.is_open())
    {
        file.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

void Student::get_from_file(ifstream& file) 
{
    if (file.is_open())
    {
        file.read(reinterpret_cast<char*>(this), sizeof(*this));
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

void Student::output()
{
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;
    cout << "Курс: " << course << endl;
    cout << "Гендер: " << gender << endl;
    cout << "Успеваемость: " << grade << endl;
}

void Student::operator=(const Student& other)
{
    name = other.get_name();
    age = other.get_age();
    course = other.get_course();
    gender = other.get_gender();
    grade = other.get_grade();
}