#include <iostream>
#include <string>
#include <fstream>

class Address
{
private:
	std::string city;
	std::string street;
	int house_number;
	int apartment_number;

public:

	Address(std::string city, std::string street, int house_number, int apartment_number)	//это конструктор с параметрами
	{
		this->city = city;																	// инициализация
		this->street = street;																// инициализация
		this->house_number = house_number;													// инициализация
		this->apartment_number = apartment_number;											// инициализация
	}

	Address()																				//это конструктор без параметров
	{
		city = " ";
		street = " ";
		house_number = apartment_number = 0;
	}

	std::string get_output_address() // метод, который собирает строку для вывода в файл, метод будет возвращать значение типа std::string
	{
		return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
	}
};

int main() {

	setlocale(LC_ALL, "rus");

	std::ifstream fin("in.txt");                    // пытаемся открыть существующий файл
	std::string s;									// создали переменную string для хранения строки

	std::ofstream fout("out.txt");					// открыли файл на запись

	fin >> s;										// считали 1-е слово из файла и записали его в перем. s

	const int n = std::stoi(s);						// преобразовали значение типа std::string в число
	std::cout << n << std::endl;
	fout << n << std::endl;

	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;

	fin >> s1;
	fin >> s2;
	fin >> s3;
	int n1 = std::stoi(s3);
	fin >> s4;
	int n2 = std::stoi(s4);

	Address* address = new Address[n];

	for (int i = 0; i < n; i++)
	{
		address[i] = Address(s1, s2, n1, n2);
		std::cout << address[i].get_output_address();
		std::cout << std::endl;
	}
	
	fin.close();											 // закрываем файл "in.txt"
	fout.close();											 // закрываем файл "out.txt"
	delete[]address;
}





/*
Задача 1. Адреса
В этом задании вы будете читать адреса из файла и выводить их в другой файл в другом формате.

Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле. После числа N располагаются N блоков по 4 строки в каждом. Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt и вывести их в файл out.txt в другом формате и в обратном порядке. Не забудьте вывести количество адресов в начале.

Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.

Пример работы программы
in.txt
3
Москва
Строителей
34
12
Омск
Пушкина
2
13
Новосибирск
Мира
85
64
out.txt
3
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
Москва, Строителей, 34, 12
*/