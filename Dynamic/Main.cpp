// ������������ ������
#include <iostream>
#include <cstdlib>
#include <ctime>
//����� �������
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
		for (int i = 0; i < length; i++)
			std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//���������� �������
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (begin - end);
}
template <typename T>
void add_el(T *&arr, const int length, int num);
template <typename T>
void substract_el(T*& arr, const int length, int num);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//������������ ����������
	/*
	int* point=new int;//��������� ������� ������������ ������ �������� � 4 ����� � ������� ��������� new
	*point = 10;
	std::cout << "point = " << point << '\n';
	std::cout << "*point = " << *point << '\n';
	delete point;//�������� ������� ������ �� ������� ��������� ���������
	point = nullptr;
	if (point != nullptr)
		std::cout << "*point = " << *point << '\n';
	else
		std::cout << "��������� ���������\n";
	point = new int;//��������� ������ ������� ������ 
	*point = 15;
	std::cout << "point = " << point << '\n';
	std::cout << "*point = " << *point << '\n';
	delete point;
	*/
	//������������ �������
	/*	
	std::cout << "������� ����� �������: \n";
	std::cin >> n;
	if (n < 0)
		std::cout << "������ ������� ���� �������������!";
	else {
		int* mass = new int[n];//��������� ������������� ������ ��� �������� �������
		std::cout << "������������ ������:\n";
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			std::cout << mass[i] << ", ";
		}
		std::cout << "\b\b.\n";
		delete[] mass;
	}
	*/
	//������ 1. ���������� �������
	/*
	std::cout << "������1\n������� ����� �������:\n";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	std::cout << "����������� ������:";
	fill_arr(arr1, size1, 0, 10);
	show_arr(arr1, size1);
	std::cout << "������� ���������� ����� ���������:\n";
	std::cin >> n;
	add_el(arr1, size1, n);
	std::cout << "�������� ������:";
	show_arr(arr1, size1+n);
	*/
	//������2 . ���������� �������
	/*
	std::cout << "������� ����� �������:";
	int size2;
	std::cin >> size2;
	std::cout << "��������� ������:";	
	int* arr2 = new int[size2];	
	fill_arr(arr2, size2, 1, 11);
	show_arr(arr2, size2);
	std::cout << "������� ���������� ��������� ������� ������:";
	std::cin >> n;
	substract_el(arr2, size2, n);
	std::cout << "�������� ������:";
	show_arr(arr2, size2 - n);
	*/
	//��������� ������������ ������
	//int* mx = new int[4][6];//�� ��������
	int** mx = new int*[4];
	for (int i = 0; i < 4; i++)
		mx[i] = new int[6];
	//�������� ���������� ������������� �������
	//int delete[][]mx;//�� ��������
	for (int i = 0; i < 4; i++)
		delete[] mx[i];
	delete[] mx;
	return 0;
}
//���������� �������
template <typename T>
void substract_el(T*& arr, const int length, int num) {
	if (num <= 0)
		return;
	if (num > length) {
		delete[] arr;
		arr = new int[0];
		return;
	}
	T* tmp = new T[length - num]{};
	for (int i = 0; i < length-num; i++)
		tmp[i] = arr[i];
	delete[]arr;
	arr = tmp;
}
//���������� �������
template <typename T>
void add_el(T *&arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[]arr;
	arr = tmp;
}