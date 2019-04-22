#pragma once


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

// Creating LinkedList with functionalities like addAtHead, addAtTail, 
//delete, insert, merge, etc.
// Default access modifier is private in classes
template<class T>
class LinkedList {


private:
	Node<T>* head;
	Node<T>* tail;
	double length = 0;
public:

	//default constructor which sets head and tail to null
	LinkedList<T>();


	// a recursive function that will delete all nodes in a linked list
	// We need this function to call the destructor recursively because the destructor itself
	// takes no parameters so we call to this function inside the destructor function to make the destructors "recursive"
	void deleteList(Node<T>* tmp);

	// recursive destructor
	//something to note, a destructor is automatically called 
	~LinkedList();


	// add_node() function, ADD NODE TO THE END OF THE LIST
	bool add_node(T d);

	// ADD FIRST FUNCTION ADDS A NODE TO THE BEGINNING OF THE LIST
	bool addFirst(T d);

	//POP FUNCTION, REMOVES FIRST NODE OF THE LIST
	void pop();

	void contains(double data, Node<T>* tmp);

	//SIZE FUNCTION, RETURNS THE NUMBER OF NODES IN THE LIST
	double size();


	// In oder to call display function recursively, get head function is necessery 
	Node<T>* gethead();


	/* DISPLAY FUNCTION USING RECURSION
	THE BASE CASE IS IF THE HEAD IS NULL,
	WE PASS THE FUNCTION WITH THE NEXT NODE TO KEEP THE LINKED LIST GOING*/
	void display(Node<T>* tmp);

	/* reminder of how RECURSION WORKS
	you pass in a number, if the number is not 1 or 0,
	multiply current number by the function times the number -1*/
	int factorial(int my_num);

	// SET FUNCTION, UPDATE THE DATA FOR WHICHEVER INDEX THE USER INPUTS
	void set(int index, T data);

	// MERGE FUNCTION, WILL ADD ALL THE NODES FROM THE LINKED LIST YOU PUT IN AS A PARAMETER TO THE END OF *THIS LINKED LIST
	void merge(LinkedList<T>& l);

	// INSERT FUNCTION, ADD A NODE IN THE MIDDLE OF THE LINKED LIST
	void insert(int index, T data);

	// REMOVE A NODE AT A GIVEN POSITION
	void remove(int index);

};






