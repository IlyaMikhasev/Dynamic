// Персональный шаблон
#include <iostream>
#include <cstdlib>
#include <ctime>
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
		for (int i = 0; i < length; i++)
			std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//заполнение массива
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
	//динамические переменные
	
	int* point=new int;//выделение участка динамической памяти размером в 4 байта с помощью оператора new
	*point = 10;
	std::cout << "point = " << point << '\n';
	std::cout << "*point = " << *point << '\n';
	delete point;//очищение области памяти на которую направлен указатель
	point = nullptr;
	if (point != nullptr)
		std::cout << "*point = " << *point << '\n';
	else
		std::cout << "Указатель нейтрален\n";
	point = new int;//выделение нового участка памяти 
	*point = 15;
	std::cout << "point = " << point << '\n';
	std::cout << "*point = " << *point << '\n';
	delete point;
	
	//динамические массивы
		
	std::cout << "Введите длину массива: \n";
	std::cin >> n;
	if (n < 0)
		std::cout << "Длинна неможет быть отрицательной!";
	else {
		int* mass = new int[n];//выделение динамическрой памяти для хранения массива
		std::cout << "Динамический массив:\n";
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			std::cout << mass[i] << ", ";
		}
		std::cout << "\b\b.\n";
		delete[] mass;
	}
	
	//задача 1. Увиличение массива
	
	std::cout << "Задача1\nВведите длину массива:\n";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	std::cout << "Изначальный массив:";
	fill_arr(arr1, size1, 0, 10);
	show_arr(arr1, size1);
	std::cout << "Введите количество новых элементов:\n";
	std::cin >> n;
	add_el(arr1, size1, n);
	std::cout << "Итоговый массив:";
	show_arr(arr1, size1+n);
	
	//Задача2 . Уиеньшение массива
	
	std::cout << "Введите длину массива:";
	int size2;
	std::cin >> size2;
	std::cout << "Начальный массив:";	
	int* arr2 = new int[size2];	
	fill_arr(arr2, size2, 1, 11);
	show_arr(arr2, size2);
	std::cout << "Введите количество элементов которые убрать:";
	std::cin >> n;
	substract_el(arr2, size2, n);
	std::cout << "Итоговый массив:";
	show_arr(arr2, size2 - n);
	
	//двумерный динамический массив
	//int* mx = new int[4][6];//не работает
	int** mx = new int*[4];
	for (int i = 0; i < 4; i++)
		mx[i] = new int[6];
	//очищение двумерного динамического массива
	//int delete[][]mx;//не работает
	for (int i = 0; i < 4; i++)
		delete[] mx[i];
	delete[] mx;
	return 0;
}
//уменьшение массива
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
//увилечение массива
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