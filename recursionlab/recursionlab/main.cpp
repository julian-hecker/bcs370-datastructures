#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int power(int base, int exp) {
	if (exp == 0) {
		return 1;
	}
	return base * power(base, exp - 1);
}

int summation(int n) {
	if (n == 0) {
		return n;
	}
	return n + summation(n - 1);
}

int arrayAdd(int *a, int index) {
	if (index == 0) {
		return a[index];
	}
	return a[index] + arrayAdd(a, index - 1);
}

int mult(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}

	return a + mult(a, b - 1);
}

int main() {
	cout << factorial(4) << endl;

	cout << fibonacci(10) << endl;

	cout << power(8, 2) << endl;

	cout << summation(10) << endl;

	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << arrayAdd(arr, 10) << endl;

	cout << mult(5, 11) << endl;

	return 0;
}