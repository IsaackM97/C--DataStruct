/*
Isaack Morales
z#23387999
Data Structure and Algoritm
Professor Mehrdad Nojoumian
Due time:11:59pm
Due date: 11/1/17
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector <int> BinaryK(int k) {

	vector <int> K; //vector k

	int temp = k;

	int i = 0;

	while (temp > 0) {
		K.push_back(temp % 2);
		temp = (temp - K[i] / 2);

		i++;

		return K;
	}
}


int Modular_expo(int a, vector <int> K, int n, int k){
	
	if (n == 1) {

		return 0;
	}

	int b = 1;

	if (k == 0) {

		return b;
	}

	int A = a;

	if (K[0] == 1) {
		b = a;

		for (int i = 0; i <= K.size(); i++) {

			A = A * A % n;
			if (K[i] == 1) {

				b = A * b % n;
			}
		}

		return b;
	}

}


int main() {

	vector <int>B;
	int a; 
	int n;  
	int k; 
	  
	
	cout << "Please enter the value for a" << endl;
	cin >> a;

	cout << "Please enter the value for n" << endl;
	cin >> n;
	
	cout << "Please enter the for k" << endl;
	cin >> k;

	  B = BinaryK(k);
		 
     Modular_expo(a, B, n, k);
		
		 
		 
	  
	  
	  return 0;
		
	
}





