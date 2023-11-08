#include<iostream>


int NUM;	// Глобальная переменная.
void num_inc() {
	NUM++;
}
const double PI = 3.14; // глобальная константа.
const int SIZE = 5; // глобальная константа.
int ARR[SIZE]; // глобальный массив.

void func() {
	static int a = 0; // статическая переменная, которая не удаляется при завершении работы программы. Создается один единственный раз.
	a++;
	std::cout << a << std::endl;
	if (a % 5 == 0)
		std::cout << "---\n";
}

int power(int num1, int num2 = 2) {
	int result = 1;
	for (int i = 1; i <= num2; i++)
		result *= num1;
	return result;
}

inline double absolut(double num) {
	return (num < 0.0 ? -num : num);
}

int max(int num1, int num2) {
	std::cout << "TWO INTs\n";
	return num1 > num2 ? num1 : num2;
}

double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}

char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}

int max(int num1, int num2, int num3) {
	std::cout << "TRHEE INTS";
	return num1 > max(num2, num3) ? num1 : max(num2, num3);
}

template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	int n;

	//Области видимости данных
	
	std::cout << NUM << std::endl;
	num_inc();
	std::cout << NUM << std::endl;

	std::cout << "PI = " << PI << std::endl;
	
	for(int i=0; i < 15; i++)
		func();
	
	// Параметры по умолчании (Передачи данных функции)
	
	std::cout << "5^3 = " << power(5, 3) << std::endl;
	std::cout << "7^2 = " << power(7) << std::endl;
	std::cout << "4^4 = " << power(4, 4) << std::endl;
	std::cout << "11^2 = " << power(11) << std::endl;
	
	// Встраиваемая функция
	
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << '|' << n << "| = " << absolut(n) << std::endl;
	
	// Перегруженная функция
	
	std::cout << max(5, 7) << std::endl;
	std::cout << max(1.3, 1.03) << std::endl;
	std::cout << max('k', 'K') << std::endl;
	std::cout << max(5, 7, 4) << std::endl;
	
	// Шаблонная функция
	const int size = 5;
	int arr[size]{ 10, 20, 30 , 40 , 50 };
	std::cout << "Массив:\n";
	print_arr(arr, size);





	return 0;
}