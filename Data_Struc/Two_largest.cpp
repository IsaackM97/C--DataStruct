/*
Isaack Morales 
z#23387999
Professor Mehrdad Nojoumian
Data Strucutres and Algoritm Analysis
Due time: 11:59pm
Due date: 11/1/17
*/

#include<iostream>
#include<math.h>
#include <vector>

using namespace std;

vector<double> vector_get(int n) {

	int i;
	double d;
	vector<double> v;

	for (i = 0; i < n; i++) {

		cout << "Enter value" << i + 1 << " : ";
		cin >> d;
		v.push_back(d);
	}
	return v;
}


void two_Largest(vector<double>A) {

	
	double large_1 = 0; //first largest number 
	double large_2 = 0;  //second largest number 
	int n= A.size();

	
	for (int i = 1; i < n; i++) {

		if (A[i] > large_1) {

			large_2 = large_1;
			large_1 = A[i];
		}

		else if (large_2 < A[i]) {

			large_2 = A[i];

		}

	}

	cout << "The largest is: " << large_1 << endl;
	cout << "The second largest is: " << large_2 << endl;
}

int main()
{
	vector <double>a;
	int n;

	

	cout << "Please enter number of elements" << endl;
	cin >> n;

	a = vector_get(n);

	two_Largest(a);


}
