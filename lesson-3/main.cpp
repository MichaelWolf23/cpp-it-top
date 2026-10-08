#include <iostream>
#include <string>
//#include <cstdlib>     // Нужен для работы команды system
//#include "my_input.h"  // Подключаем наш созданный файл

void printTest(const int* test) {
    if (test != nullptr) {
        std::cout << "printTest: " << *test << "\n";
    }
}


int main() {
    int rover{ 80 };

    std::cout << "Value rover: " << rover << "\n";
    std::cout << "Address rover: " << &rover << "\n";

    // Указатель - это адрес нахождения значения переменной в памяти.
    // Для того чтобы узнать адрес перед названием переменной пишем "&"
    // Помимо прямого способа узнать местонахождение значения переменной мы также можем записывать адрес в отдельную переменную.

    int* sensor{ &rover }; // Указатель

    std::cout << "Address rover in var: " << sensor << "\n";
    std::cout << "Value sensor: " << *sensor << "\n"; // Разыменование - получение информации которое хранится по определенному адресу
    
    *sensor = 90;

    std::cout << "Address rover in var: " << sensor << "\n";
    std::cout << "Value sensor: " << *sensor << "\n";
    std::cout << "Value rover: " << rover << "\n";

    int scout{ 45 };
    sensor = &scout;

    std::cout << "Address scout in var: " << sensor << "\n";
    std::cout << "Value sensor: " << *sensor << "\n";
    std::cout << "Value scout: " << scout << "\n";

    sensor = nullptr; // Сброс указателя

    if (sensor != nullptr) {
        std::cout << *sensor;
    }

    int* test{ &scout }; // Указатель
    int& baterry{ rover }; // Ссылка
    
    // Используем ссылку если объект точно существует и нам точно нужно работать с ним
    // Используем указатель если объект может отсутствовать или нужно переключаться на другой объект

    printTest(test);
    printTest(&scout);

    std::cout << "=========================================" << "\n\n";

    
    // Куча - это когда система просит выделить память для временной переменной. Для этого мы используем оперетор new

    int* extra{ new int{25} };
    // int* - указатель
    // new int{25} - создай в куче число типа int и полохи туда 25

    std::cout << "Address: " << extra << "\n";
    std::cout << "Value: " << *extra << "\n";

    delete extra; // Удаление объекта (уничтожен)
    extra = nullptr;

    std::cout << "Address: " << extra << "\n";
    
    // new - создание кучи
    // Куча работает
    // delete
    // Присваеваем указателю nullptr

    int* values{ new int[5] };

    std::cout << "Address: " << values << "\n";
    std::cout << "Value: " << *values << "\n";

    delete[] values;
    values = nullptr;

    return 0;

}
