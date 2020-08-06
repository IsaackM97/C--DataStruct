/*
Isaack Morales
z#23387999
Assignment #3
Data Structures and Algorithms
Professor Mehrdad Nojoumian
Due time: 11:59pm
Due date:11/18/17
*/

#include<iostream>
#include <sstream>
using namespace std;

struct slinklist {

	int data;
	struct slinklist *next;

};

typedef struct slinklist node;
node * start = NULL;

node * getnode() {  //creating a node

	node* newnode;

	newnode = (node*)malloc(sizeof(node));

	cout << "Enter data: " << endl;
	cin >> (newnode->data);

	newnode->next = NULL;
	return newnode;


}

void create_list(int n)  //creating a list //n is the input number of nodes
{

	int i;
	node* newnode;  //sets newnode as a pointer
	node* temp;    //sets temp as a pointer

	for (i = 0; i < n; i++)
	{
		newnode = getnode();

		if (start == NULL) {
			start = newnode;  //sets the address value of newnode into start
		}
		else {
			temp = start;
			while (temp->next != NULL) {

				temp = temp->next;
			}
			temp->next = newnode;
		}
	}




}

int countnode(node * start) {   //This function counts the number of nodes

	node* temp = start;
	int counter = 0;
	while (temp != NULL) {

		temp = temp->next;
		counter++;

	}

	return counter;

}

void deletemid()  //deleting a node in the middle
{
	int counter = 1;   //count
	int position;     //position of the node
	int nodecounter;  //tells how many nodes there are

	node * temp;
	node *prev;

	if (start == NULL) {

		cout << "empty list";
		return;
	}
	else {

		cout << "Enter the postion of the node you want to delete" << endl;
		cin >> position;
		nodecounter = countnode(start);

		if (position > nodecounter) {
			cout << "The node does not exsist" << endl;
		}
	      if (position > 1 && position < nodecounter) {
			temp = start;
			prev = start;

			while (counter < position) {

				prev = temp;
				temp = temp->next;
				counter++;
			}
			prev->next = temp->next;
			free(temp);
			cout << "The node was deleted" << endl;
		}
	}

}


void insert_in_middle() {  //insert a node in the middle

	node * newnode, *temp, *prev;
	int counter=1;
	int position, nodecounter;
	

	newnode = getnode();

	cout << "Enter the postion " << endl;
	cin >> position;

	nodecounter = countnode(start);

	if (position > 1 && position < nodecounter) {

		temp = start;
		prev = start;

		while (counter < position) {
			prev = temp;
			temp = temp->next;
			counter++;
		}

		prev->next = newnode;
		newnode->next = temp;
	}
	else {
		cout << "Position " << position << " is not a middle position" << endl;
	}
}

void traversal() {
	node *temp;
	temp = start;

	cout << "The contents of the list from left to right" << endl;
	if (start == NULL) {

		cout << "empty list";
	}

	else {
		while (temp != NULL)
		{
			cout << " " << temp->data;
			temp = temp->next;

		}
	}
}


int main() {
	int n= 0;
	cout << "Enter the number of nodes" << endl;
	cin >> n;

	create_list(n);
	deletemid();
	insert_in_middle();
	

	traversal();

	return 0;




}