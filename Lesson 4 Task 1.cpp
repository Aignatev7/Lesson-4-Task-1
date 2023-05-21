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

	Address(std::string city, std::string street, int house_number, int apartment_number)	//��� ����������� � �����������
	{
		this->city = city;																	// �������������
		this->street = street;																// �������������
		this->house_number = house_number;													// �������������
		this->apartment_number = apartment_number;											// �������������
	}

	Address()																				//��� ����������� ��� ����������
	{
		city = " ";
		street = " ";
		house_number = apartment_number = 0;
	}

	std::string get_output_address() // �����, ������� �������� ������ ��� ������ � ����, ����� ����� ���������� �������� ���� std::string
	{
		return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
	}
};

int main() {

	setlocale(LC_ALL, "rus");

	std::ifstream fin("in.txt");                    // �������� ������� ������������ ����
	std::string s;									// ������� ���������� string ��� �������� ������

	std::ofstream fout("out.txt");					// ������� ���� �� ������

	fin >> s;										// ������� 1-� ����� �� ����� � �������� ��� � �����. s

	const int n = std::stoi(s);						// ������������� �������� ���� std::string � �����
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
	
	fin.close();											 // ��������� ���� "in.txt"
	fout.close();											 // ��������� ���� "out.txt"
	delete[]address;
}





/*
������ 1. ������
� ���� ������� �� ������ ������ ������ �� ����� � �������� �� � ������ ���� � ������ �������.

��� ��� ���� in.txt, � ������� ��������� N �������. ����� N ��� ������ � �����. ����� ����� N ������������� N ������ �� 4 ������ � ������. ������ ���� ������� �� ��������� �����: �������� ������, �������� �����, ����� ����, ����� ��������.

������ ��������� ����������� � ���, ����� ������� ������ �� ����� in.txt � ������� �� � ���� out.txt � ������ ������� � � �������� �������. �� �������� ������� ���������� ������� � ������.

������ ������ ������: <�������� ������>, <�������� �����>, <����� ����>, <����� ��������>.

������ ������ ���������
in.txt
3
������
����������
34
12
����
�������
2
13
�����������
����
85
64
out.txt
3
�����������, ����, 85, 64
����, �������, 2, 13
������, ����������, 34, 12
*/