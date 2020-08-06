/*
Isaack Morales 
z#23387999
Data structures and Algorithms
Professor Mehrdad Nojoumian
Due date:11/18/17
Due time: 11:59pm
Double link list

*/


#include <iostream>
#include <sstream>
using namespace std;

struct dlinklist
{
	int data;
	struct dlinklist *left;
	struct dlinklist *right;
};

typedef struct dlinklist node;
node *start = NULL;


node *getnode()
{
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	cout << "Enter data" << endl;
	cin >> (newnode->data);

	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void createlist(int n)
{
	int i;
	node * newnode;
	node * temp;
	for (i = 0; i < n; i++)
	{
		newnode = getnode();
		if (start == NULL) //if linked list is empty
		{
			start = newnode;
		}
		else //linked list is not empty
		{
			temp = start;
			while (temp->right != NULL)
			{
				temp = temp->right; 
			}

			temp->right = newnode;
			newnode->left = temp;

		}
	}
}

void delete_at_end()
{
	node *temp;
	temp = start;

	if (start == NULL) {
		cout << "The list is empty" << endl;
		return;
	}

	else {

		while (temp->right != NULL) {
			temp = temp->right;

		}

		temp->left->right = NULL;

		free(temp);

		cout << " The node at the end is deleted " << endl;
	}



}

void insert_at_beg() {
	node *temp;
	node* newnode;
	newnode = getnode();

	if (start == NULL) {
		cout << "The list is empty" << endl;
		start = newnode;
	}
	else {
		newnode->right = start;
		start->left = newnode;
		start = newnode;
	}

	cout << "The node has been inserted at the beginning" << endl;
}

void traversal()
{
	node * temp;
	temp = start;

	

	if (start == NULL) {

		cout << "empty list";
	}
	else {
		cout << "The contents of the node from left to right" << endl;

		while (temp->right!= NULL) {
			cout << temp->data << endl;
			temp = temp->right;
		}
		cout << temp->data << endl;
	}

}

int main() {
	int n = 0;
	cout << "Enter the number of nodes" << endl;
	cin >> n;

	createlist(n);
	delete_at_end();
	insert_at_beg();

	traversal();
	return 0;


}