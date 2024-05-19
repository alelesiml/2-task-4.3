#include "DataBase.h"
#include <iostream>

int main() 
{
    setlocale(LC_ALL, "ru");

    StudentDatabase database;

    int choice;
    do 
    {
        cout << "Меню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Сохранить данные в файл\n";
        cout << "3. Загрузить данные из файла\n";
        cout << "4. Вывести данные всех студентов\n";
        cout << "5. Посчитать средний балл по курсу\n";
        cout << "0. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            database.enter_student_from_keyboard();
            break;
        case 2:
            database.save_to_file("database.bin");
            break;
        case 3:
            database.get_from_file("database.bin");
            break;
        case 4:
            cout << endl;
            database.print();
            break;
        case 5:
            int course;
            cout << "Введите курс для определения среднего балла: ";
            cin >> course;
            database.calculate_score(course);
            break;
        case 0:
            cout << "Завершение работы.\n";
            break;
        default:
            cout << "Неправильный выбор. Завершение программы\n";
            break;
        }

        cout << endl;
    } while (choice != 0);
    
    return 0;
}

