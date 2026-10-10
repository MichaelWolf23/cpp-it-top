#include <iostream>
#include <memory>
#include <array>
#include <vector>

void printReserve(const std::unique_ptr<int>& test) {
	if (!test) {
		std::cout << "No resever\n";
	}
	else {
		std::cout << "Resever: " << test << "%\n";
		std::cout << "Address: " << *test << '\n';
	}
}

struct Device {
	std::string name;
	int battery;
};

void printDevice(const Device& device) {
	std::cout << "Name: " << device.name << '\n';
	std::cout << "Battery: " << device.battery << '\n';
}

void changeDevice(Device& device, int bonus) {
	device.battery += bonus;

}

bool isBatteryValid(const Device& device) {
	return device.battery >= 0 && device.battery <= 100;
}

int main() {

	int* reserve{ new int{25} };

	std::cout << reserve << '\n';
	std::cout << *reserve << '\n';

	delete reserve;
	reserve = nullptr;

	// unique_ptr - хозяин одного объекта (умный указатель)

	std::unique_ptr<int> test{
		std::make_unique<int>(25)
	};

	// std::unique_ptr<int> - умный указатель с типом данных int
	// test - имя указателя
	// std::make_unique<int>(25) - создаем объект int со значением 25 и передает его под упровление unique_ptr.

	std::cout << test << '\n';
	std::cout << *test << '\n';

	*test = 35;

	std::cout << test << '\n';
	std::cout << *test << '\n';

	std::unique_ptr<int> zero{};

	// std::cout << zero << '\n';
	// std::cout << *zero << '\n';

	if (!zero) {
		std::cout << "No value\n";
	}

	std::unique_ptr<int> first{
		std::make_unique<int>(25)
	};

	// ::unique_ptr<int> second{ first };
	// unique_ptr - нельзя копировать инфу

	std::unique_ptr<int> second{
		std::move(first) // std::move - смена хозяина
	};

	printReserve(((((((((((((((((((((((((((((((((((((((((second)))))))))))))))))))))))))))))))))))))))));
	std::cout << "Resever: " << *second << "%\n";

	second.reset(); // удаление объекта раньше 

	printReserve(second);

	int* raw{ second.get() };

	std::shared_ptr<int> test1{ // std::shared_ptr - позволяет задать несколько владельцов для значения
		std::make_unique<int>(40)
	};

	std::shared_ptr<int> test2{test1};

	std::cout << "================================\n\n";

	// std::string - строка
	// std::array - фиксированное кол-во элементов
	// std::vector - список

	int battery1{ 70 };
	int battery2{ 20 };
	int battery3{ 10 };

	std::string name{ "Scout" };

	std::cout << "Name: " << name << "\n";
	name += " One";
	std::cout << "Name: " << name << "\n";
	std::cout << "Name size: " << name.size() << "\n"; // size() - показывает длину строки
	std::cout << "Name 0: " << name.at(0) << "\n"; // at() - символ по индексу
	std::cout << "Name 1: " << name.at(1) << "\n";

	std::array<int, 3> batteries{ 70,40,90 };
	
	std::cout << "batteries size: " << batteries.size() << "\n";
	std::cout << "batteries 0: " << batteries.at(0) << "\n";
	std::cout << "batteries 1: " << batteries.at(1) << "\n";
	std::cout << "batteries 2: " << batteries.at(2) << "\n";

	batteries.at(0) = 90;
	std::cout << "batteries 0: " << batteries.at(0) << "\n";

	std::vector<int> reading;
	reading.push_back(10);
	reading.push_back(20);
	reading.push_back(30);
	reading.push_back(40);
	reading.push_back(50);

	std::cout << "vector reading size: " << reading.size() << "\n";
	std::cout << "vector reading 0: " << reading.at(0) << "\n";
	std::cout << "vector reading 1: " << reading.at(1) << "\n";
	std::cout << "vector reading 2: " << reading.at(2) << "\n";
	std::cout << "vector reading last: " << reading.at(reading.size() - 1) << "\n";

	for (int value : reading) {
		std::cout << "value: " << value << "\n";
	}

	for (int value : reading) {
		std::cout << value << ' ';
	}

	for (int& value : reading) {
		value += 10;
	}

	for (int value : reading) {
		std::cout << "value: " << value << '\n';
	}

	std::cout << "================================\n\n";

	std::string roverName{ "Rover" };
	int roverBattery{ 80 };

	std::string scoutName{ "Scout" };
	int scoutBattery{ 80 };

	// struct - это способ создать собственный тип данных, в котором объеденены несколько полей.

	Device rover{ "Rover", 80 };
	printDevice(rover);
	changeDevice(rover, 10);
	printDevice(rover);

	Device scout{ "Scout", 70 };
	printDevice(scout);

	std::cout << "Vector:\n";

	std::vector<Device> fleet{
		{ "Rover", 80 },
		{ "Scout", 110 }
	};
	//fleet.push_back({ "Rover", 80 });
	//fleet.push_back({ "Scout", 70 });

	for (const Device& device : fleet) {
		printDevice(device);
		if (isBatteryValid(device)) {
			std::cout << "Good!\n";
		}
		else {
			std::cout << "Not Good!\n";

		}
	}

	return 0;
}