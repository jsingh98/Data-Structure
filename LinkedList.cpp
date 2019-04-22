#include "LinkedList.h"
#include <iostream>
using namespace std;




//default constructor which sets head and tail to null
LinkedList<double>::LinkedList() {
	head = NULL;
	tail = 0;
	length = 0;
}

// a recursive function that will delete all nodes in a linked list
// We need this function to call the destructor recursively because the destructor itself
// takes no parameters so we call to this function inside the destructor 
//function to make the destructors "recursive"
void LinkedList<double>::deleteList(Node<double>* tmp) {
	if (head == 0) { return; }
	// << "THIS DATA OF HEAD IS: " << head->data << endl;
	head = head->next;
	deleteList(head);
	delete head;
}


//DESTRUCTOR, DESTROYS EVERY NODE IN THE LINKED LIST, THIS IS DONE ITERATIVELY
//LinkedList::~LinkedList() {
//	tail = head;
//	length = 0;
//	while (tail != 0) {
//		head = head->next;
//		delete tail;
//		tail = head;
//	}
//}

// recursive destructor
//something to note, a destructor is automatically called when the instance goes out of scope
 LinkedList<double>::~LinkedList() {
	deleteList(head);
	length = 0;
}


 // add_node() function, ADD NODE TO THE END OF THE LIST
 bool LinkedList<double>::add_node(double d) {
	 Node<double> *tmp; // * is called indirect operator 

	 try
	 {
		 tmp = new Node<double>(d);
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
 bool LinkedList<double>::addFirst(double d) {
	 Node<double> *tmp;

	 try
	 {
		 tmp = new Node<double>(d);
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
 void LinkedList<double>::pop() {
	 Node<double>* tmp;
	 tmp = head->next;
	 delete head;
	 head = tmp;
	 cout << "REMOVED OLD HEAD, NEW HEAD'S DATA IS: " << head->data << endl;
	 length--;
 }

 //CONTAINS FUNCTION, RETURNS TRUE OR FLASE IF A NODE CONTAINS THE DATA, THIS IS DONE ITERATIVELY
 /*void LinkedList<double>::contains(double data) {
 Node<double>* tmp = head;
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
 }*/


 void LinkedList<double>::contains(double data, Node<double>* tmp) {
	 if (tmp->data == data) {
		 cout << "FOUND THE DATA " << data << endl;
		 return;
	 }
	 //cout << "DATA RIGHT NOW IS: " << tmp->data << endl;
	 contains(data, tmp->next);
 }


 //SIZE FUNCTION, RETURNS THE NUMBER OF NODES IN THE LIST
 double LinkedList<double>::size() {
	 return length;
 }

 //void LinkedList<double>::display() // to display all nodes in the list without using recursion, this is done iteratively
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
 Node<double>* LinkedList<double>::gethead() {
	 return head;
 }

 /* DISPLAY FUNCTION USING RECURSION
 THE BASE CASE IS IF THE HEAD IS NULL,
 WE PASS THE FUNCTION WITH THE NEXT NODE TO KEEP THE LINKED LIST GOING*/
 void LinkedList<double>::display(Node<double>* tmp) {
	 if (tmp == NULL) {
		 return;
	 }
	 cout << tmp->data << endl;
	 display(tmp->next);
 }


 /* reminder of how RECURSION WORKS
 you pass in a number, if the number is not 1 or 0,
 multiply current number by the function times the number -1*/
 int LinkedList<double>::factorial(int my_num) {
	 if (my_num == 1 || 0) {
		 return 1;
	 }
	 if (my_num < 0) {
		 return 0;
	 }
	 return my_num * factorial(my_num - 1);
 }


 // SET FUNCTION, UPDATE THE DATA FOR WHICHEVER INDEX THE USER INPUTS
 void LinkedList<double>::set(int index, double data) {

	 Node<double>* tmp = head;
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
 void LinkedList<double>::merge(LinkedList<double>& l) {

	 this->tail->next = l.head;
	 l.head = NULL;
	 this->length += l.length;
	 l.length = 0;
	 return;
 }

 // INSERT FUNCTION, ADD A NODE IN THE MIDDLE OF THE LINKED LIST
 void LinkedList<double>::insert(int index, double data) {
	 Node<double>* addme;
	 Node<double>* traverse = head;
	 int i = 0;
	 addme = new Node<double>(data);

	 while (traverse != NULL && i != index - 1) {
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
 void LinkedList<double>::remove(int index) {
	 Node<double>* next;
	 Node<double>* traverse = head;
	 Node<double>* prev;
	 int i = 0;
	 length -= 1;

	 while (traverse != NULL && i != index - 1) {
		 traverse = traverse->next;
		 i++;
	 }
	 if (traverse == 0) {
		 cout << " doesnt exist" << endl;
	 }
	 // i is == to index here
	 prev = traverse;
	 while (traverse != NULL && i != index) {
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