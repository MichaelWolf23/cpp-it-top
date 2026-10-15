#include<iostream>
#include<string>
#include <windows.h>
#include <memory>


class BatteryReserver {
public:
	// explicit - создание конструктора
	explicit BatteryReserver(int value) : value_{ std::make_unique<int>(value) } {
		std::cout << "Reserve acquired\n";
	}

	~BatteryReserver() {
		std::cout << "Reserve released\n";
	}

	int value() const {
		return *value_;
	}

private:
	std::unique_ptr<int> value_;

};

// RAII - подход в C++ при котором время жизни ресурса связывает с временем жизни объекта - владельца.

// Ресурсом может быть не только память. Это также файл, сетевое соединение или другой объект,
// который нужно корректно освобождать после использования.

// В нашем примере ресурс - это число в динамической памяти, которым владеет unique_ptr.

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	BatteryReserver reserve{ 20 };

	std::cout << "Value: " << reserve.value() << "%\n";

	return 0;
}

