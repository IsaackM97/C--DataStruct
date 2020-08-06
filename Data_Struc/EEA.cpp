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

void EEA(int a, int b) {

	
	int q; //quotient 
	int temp; //temporary varibale
	int temp1;
	int temp2;


	int s = 0;
	int old_s = 1;
	int t = 1;
	int old_t = 0;
	int r = b;
	int old_r = a;

	while (r != 0) {

		q = old_r / r;
		temp = r;
		r = old_r - q*r;
		old_r = temp;

		temp1 = s;
		s = old_s - q*s;
		old_s = temp1;

		temp2 = t;
		t = old_t - q*t;
		old_t = temp2;

		



	}

	cout << "GCD = " << old_r << endl;
}


int main() {

	int x, y;

	cout << "Enter x" << endl;
	cin >> x;

	cout << "Enter y" << endl;
	cin >> y;

	EEA(x, y);
}