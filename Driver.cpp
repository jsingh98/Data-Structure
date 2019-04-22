// Single Linked Lists with basic functionalities
// Written by Jupraj Singh
// 4/9/2019

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;




int main() {
	
	LinkedList <double> a;
	a.add_node(2);
	a.add_node(3);
	a.add_node(4);
	a.add_node(5);
	a.add_node(6);
	a.add_node(7);
	a.add_node(8);
	a.add_node(9);
	a.add_node(10);
	a.add_node(11);
	a.add_node(12);
	a.add_node(13);
	a.add_node(14);
	a.addFirst(1);
	a.contains(5, a.gethead());
	a.remove(9);
	a.display(a.gethead()); 

	a.insert(3, 244);
	cout << endl;
	a.display(a.gethead()); 
	a.pop(); 
	cout << "SIZE IS: " << a.size() << endl;
	a.remove(3);
	a.display(a.gethead()); 
	cout << endl;
	
	a.set(1, 555); 
	cout << "DISPLAYING LINKED LIST A:" << endl;
	a.display(a.gethead());
	

	LinkedList <double> b;

	b.add_node(532);
	b.addFirst(56);
	cout << endl << endl << "Diplaying Linked list B:" << endl;
	b.display(b.gethead()); // 56 532
	cout << endl;

	a.merge(b);
	cout << "displaying linked list a after it merged with linked list b\n";
	a.display(a.gethead());
	
	return 0;
}