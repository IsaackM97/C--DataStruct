/*
Isaack Morales 
z#23387999
Professor Mehrdad Nojoumian
Data Structures and Algorithm
due date: 11/30/17
due time: 11:59pm
Assignment 4
*/

#include <stdio.h>
#include<iostream>
#include<sstream>

using namespace std;

struct slinklist {

	int data;
	struct slinklist *next;
	

};

typedef struct slinklist node;
node *front = NULL;
node*rear = NULL;


node * getnode() {

	node* newnode; //declares newnode as a pointer

	newnode = (node*)malloc(sizeof(node)); //allocating memory the node
	cout << "Enter data" << endl;
	cin >> newnode->data;

	newnode->next = NULL;

	return newnode;  //returns a node

}

void create_List(int n) {

	//start is front

	node *newnode; //decalres newnode as a pointer 
	node *temp;   //declares temp as a pointer

	for (int i=0; i < n; i++) {
		newnode = getnode();  //newnode is assigned as a node being created

		if (front == NULL) { 
			front = newnode;  //front points to the node address
		}
		else {
			temp = front;   //temp is pointing to the same node as front and we use temp to go down the link list
			while (temp->next != NULL) {  //goes through the link list until temp->next is NULL

				temp = temp->next;  //this is the formula to go down the link list
			}
			temp->next = newnode; //temp->next is now pointing to an entirely new node in the list
			rear = temp;
		}

	}
}

//prompts user to ask which action they would like to perform
int menu() {
	int action;
	cout << "Select the action you would like to make: \n 1. Enqueue\n 2. Dequeue \n 3. Display \n 4.Quit\n" << endl;
	cin >> action;
	return action;
}


void Enqueue() {

	node *newnode,*temp;
	newnode = getnode();

	
	if (front == NULL) {
		front = newnode;
		rear = newnode;

	}
	else {
		temp = front;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		rear = temp->next;
	}
}

void Dequeue() {
	if (front == NULL) {

		cout << "The queue is empty, no deletion is necessary" << endl;	
		
	}
	else {
		node *temp = front;
		front = front->next;

		cout << "The element" << temp->data << "has been sucessfully deleted" << endl;
		free(temp);

	}
}

void Display() {

	if (front == NULL) {
		cout << "The queue is empty, nothing will be displayed" << endl;
	}
	else {
		node*temp = front;
		while (temp->next != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
}

int main() {
	int action;
	int n;
	cout << "Enter the number of nodes" << endl;
	cin >> n;

	create_List(n);

	do {
		action = menu();
		switch (action) {
		case 1:
			Enqueue(); //input
			break;
		case 2:
			Dequeue(); //delete
			break;
		case 3:
			Display(); //display
			break;
		case 4:
			exit(0);
		default:
			cout << "Invlaid action, try again" << endl;
			break;


		}
	} while (1);
		return 0;
}