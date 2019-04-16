// Single Linked Lists with basic functionalities
// Written by Jupraj Singh
// 4/9/2019

#include <iostream>
#include <string>
using namespace std;


// Creating a Node Struct. The default for struct is public
template<class T>
struct Node
{
	T data;
	Node* next;
	Node(T data) {
		this->data = data;
	}
};

// Creating LinkedList with functionalities like addAtHead, addAtTail, delete, insert, merge, etc.
// Default access modifier is private in classes
template<class T>
class LinkedList {


private:
	Node<T>* head;
	Node<T>* tail;
	double length = 0;
public:
	//default constructor which sets head and tail to null
	LinkedList() {
		head = NULL;
		tail = 0;
		length = 0;
	}
	//DESTRUCTOR, DESTROYS EVERY NODE IN THE LINKED LIST
	~LinkedList() {
		tail = head;
		length = 0;
		while (tail != 0) {
			head = head->next;
			delete tail;
			tail = head;
		}
	}

	// a recursive function that will delete all nodes in a linked list
	// We need this function to call the destructor recursively because the destructor itself
	// takes no parameters so we call to this function inside the destructor function to make the destructors "recursive"
	//void deleteList(Node<T>* tmp) {
	//	if (head == 0) { return; }
	//	// << "THIS DATA OF HEAD IS: " << head->data << endl;
	//	head = head->next;
	//	deleteList(head);
	//	delete head;
	//}

	// recursive destructor
	// something to note, a destructor is automatically called 
	/*~LinkedList() {
		deleteList(head);
	}*/

	//~LinkedList() {
	//	Node<T>* tmp = head; //indirection
	//
	//	while (tail->next != 0) {
	//		tmp = tmp->next;
	//		delete head;
	//		head = tmp;
	//		cout << "destruct " << tmp->data << endl;
	//	}

	// add_node() function, ADD NODE TO THE END OF THE LIST
	bool add_node(T d) {
		Node<T> *tmp;

		try
		{
			tmp = new Node<T>(d);
		}
		catch (const bad_alloc)
		{
			return false;
		}
		tmp->next = NULL;
		if (head == NULL && tail == 0) {
			head = tmp;
			tail = tmp;
			length++;
		}
		else {
			tail->next = tmp;
			tail = tmp;
			length++;
		}
		return true;
	}
	// ADD FIRST FUNCTION ADDS A NODE TO THE BEGINNING OF THE LIST
	bool addFirst(T d) {
		Node<T> *tmp;

		try
		{
			tmp = new Node<T>(d);
		}
		catch (const bad_alloc)
		{
			cout << "BAD ALLOCATION";
			return false;
		}
		tmp->next = 0;
		if (head == NULL && tail == 0) {
			head = tmp;
			tail = tmp;
			length++;
			return true;
		}
		else {
			tmp->next = head;
			head = tmp;
			length++;
			return true;
		}
		//return true;
	}
	
	//POP FUNCTION, REMOVES FIRST NODE OF THE LIST
	void pop() {
		Node<T>* tmp;
		tmp = head->next;
		delete head;
		head = tmp;
		cout << "REMOVED OLD HEAD, NEW HEAD'S DATA IS: " << head->data << endl;
		length--;
	}

	//CONTAINS FUNCTION, RETURNS TRUE OR FLASE IF A NODE CONTAINS THE DATA
	void contains(T data) {
		Node<T>* tmp = head;
		while (tmp != NULL && tmp->data != data) {
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			cout << data << " DOESNT EXIST IN LINKED LIST " << endl << endl;
			return;
		}

		if (tmp->data = data) {
			cout << "CONGRATULATIONS, " << tmp->data << " IS IN THE LINKED LIST" << endl << endl;
			return;
		}

	}

	//SIZE FUNCTION, RETURNS THE NUMBER OF NODES IN THE LIST
	double size() {
		return length;
	}

	//void display() // to display all nodes in the list without using recursion, this is done iteratively
	//{
	//	cout << "Displaying Linked Lists:" << endl;
	//	Node<T> *tmp;
	//	tmp = head;
	//	while (tmp != NULL)
	//	{
	//		cout << tmp->data << endl;
	//		tmp = tmp->next;
	//	}
	//	cout << endl;
	//}



	// In oder to call display function recursively, get head function is necessery 
	Node<T>* gethead() {
		return head;
	}

	/* DISPLAY FUNCTION USING RECURSION
	THE BASE CASE IS IF THE HEAD IS NULL,
	WE PASS THE FUNCTION WITH THE NEXT NODE TO KEEP THE LINKED LIST GOING*/
	void display(Node<T>* tmp) {
	
		/*cout << head << endl;
		cout << tmp << endl;*/

		if (tmp == NULL) {
			return;
		}
		cout << tmp->data << endl;
		display(tmp->next);

	}

	/* reminder of how RECURSION WORKS
	you pass in a number, if the number is not 1 or 0,
	multiply current number by the function times the number -1*/
	int factorial(int my_num) {
		if (my_num == 1 || 0) {
			return 1;
		}
		if (my_num < 0) {
			return 0;
		}
		return my_num * factorial(my_num - 1);
	}
	// SET FUNCTION, UPDATE THE DATA FOR WHICHEVER INDEX THE USER INPUTS
	void set(int index, T data) {

		Node<T>* tmp = head;
		int i = 0;
		while (tmp != NULL && i != index) {
			tmp = tmp->next;
			i++;
		}
		if (tmp == NULL) {
			cout << data << " DOESNT EXIST" << endl;
		}
		// i is == to index here
		tmp->data = data;
	}

	// MERGE FUNCTION, WILL ADD ALL THE NODES FROM THE LINKED LIST YOU PUT IN AS A PARAMETER TO THE END OF *THIS LINKED LIST
	void merge(LinkedList<T>& l) {

		this->tail->next = l.head;
		l.head = NULL;
		l.length = 0;
		return;
	}

	// INSERT FUNCTION, ADD A NODE IN THE MIDDLE OF THE LINKED LIST
	void insert(int index, T data) {
		Node<T>* addme;
		Node<T>* traverse = head;
		int i = 0;
		addme = new Node<T>(data);

		while (traverse != NULL && i != index-1 ) {
				traverse = traverse->next;
				i++;
			}
			if (traverse == 0) {
				cout << data << " doesnt exist" << endl;
			}
			// i is == to index here
			addme->next = traverse->next;
			traverse->next = addme;
	}

	// REMOVE A NODE AT A GIVEN POSITION
	void remove(int index) {
		Node<T>* next;
		Node<T>* traverse = head;
		Node<T>* prev;
		int i = 0;

		while (traverse != NULL && i != index -1) {
			traverse = traverse->next;
			i++;
		}
		if (traverse == 0) {
			cout <<  " doesnt exist" << endl;
		}
		// i is == to index here
		prev = traverse;
		while (traverse != NULL && i != index ) {
			traverse = traverse->next;
			i++;
		}
		if (traverse == 0) {
			cout << " doesnt exist" << endl;
		}
		next = traverse->next;

		prev->next = next;
		delete traverse;

	}
};

int main() {
	
	LinkedList <double> a;

	a.add_node(3);
	a.add_node(4);
	a.add_node(5);
	a.addFirst(1);
	a.~LinkedList();
	a.addFirst(788);
	a.display(a.gethead());

	/*a.insert(1, 500);
	a.remove(3);
	a.set(0, 52);
	cout << a.factorial(19) << endl;*/
	//a.display(a.gethead());
	//a.~LinkedList();
	//cout << endl << endl;
	//cout << endl << endl;
	//a.addFirst(71);
	//a.display(a.gethead());

	//a.add_node(5);
	//a.display(a.gethead());

	//cout << "setting 2nd element to 21" << endl;
	//a.set(2, 21);
	//a.display();

	//cout << "the size of array before pop is: " << a.size() << endl;
	//a.pop();
	//cout << "the size of array after pop is: " << a.size() << endl;
	//a.display();

	//cout << "deleting entire list" << endl << endl;
	//a.~LinkedList();
	//

	//a.add_node(12);
	//a.add_node(56);
	//a.add_node(5);
	//a.add_node(6);
	//a.add_node(7000);
	//a.display();
	//cout << endl; 


	/*a.contains(135);
	a.contains(6);
	a.contains(134);
	a.contains(7000);

	LinkedList<double> b;
	b.add_node(2);
	b.addFirst(1);
	cout << "DISPLAYING LINKED LIST B:" << endl;
	b.display();
	cout << "SIZE OF LINKED LIST B: " <<  b.size()<< endl;
	a.merge(b);
	
	cout << "DISPLAYING LINKED LIST A AFTER IT MERGED WITH LINKED LIST B\n";
	a.display();


	cout << "SIZE OF LINKED LIST B AFTER IT GOT MERGED ONTO LINKED LIST A: " << b.size() << endl;
*/

	return 0;
}