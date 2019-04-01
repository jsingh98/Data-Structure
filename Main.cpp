#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* link;
};

class LinkedList {
private:
	Node* head;
	Node* current;
public:
	LinkedList() {
		head = NULL;
		current = NULL;
	}



	~LinkedList() {
		cout << "LIST DELETED" << endl;
		current = head;
		while (current != NULL) {
			head = head->link;
			delete current;
			current = head;
		}
	}

	void addNode(int n) {
		Node* temp = new Node();
		temp->data = n;
		//cout << temp->data << endl;
		if (head == NULL) {
			head = temp;
			current = temp;
		}
		else {
			current->link = temp;
			current = current->link;
		}

	}


	void display() {
		Node *tmp;
		tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->link;
		}


	}

	void addFirst(int t) {
		Node *temp = new Node;
		temp->data = t;
		temp->link = head;
		head = temp;
		
	}



};




int main() {
	LinkedList l;
	l.addNode(3);
	l.addNode(5);
	l.display();
	l.~LinkedList();
	l.addNode(4);
	l.addFirst(5);
	l.display();





	return 0;
}