/*
Isaack Morales
Z#23387999
Data structures/ Algorithms
Professor Mehrdad Nojoumian
Due time: 11:59pm
Due date: 11/1/17
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void selectionsort(int a[], int n) {

	int temp;

	for (int i = 0; i < n - 1; i++) {

		int maxIndex = i;
		for (int j = i + 1; j < n; j++) {

			if (a[j] > a[maxIndex]) {
				maxIndex = j;
			}
		}

		temp = a[i];
		a[i] = a[maxIndex];
		a[maxIndex] = temp;
	}


}

int main() {

	int size = 0;
	int*a = 0;

	cout << "How many entries do you want to have?" << endl;
	cin >> size;

	a = new int[size];

	for (int i = 0; i < size; i++) {

		cout << "Enter value"<< endl;
		cin >> a[i];
	}

	cout << "Unsorted array: " ;
	for (int i = 0; i < size; i++) {

		cout << a[i] << " ";
	}

	selectionsort(a, size);

	cout << "sorted array: " ;

	for (int i = 0; i < size; i++) {

		cout << a[i] << " ";
	}
	return 0;
}