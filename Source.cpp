#include <iostream>
using namespace std;
#include "LinkedList.h"

int main() {
	LinkedList<int> lista;
	LinkedList<int> lista2;

	lista += 10;
	lista += 20;
	lista += 30; 
	lista += 40;
	lista2 += 10;
	lista2 += 20;
	lista2 += 30;
	lista2 += 40;
	
	lista2.print();

	lista.print();

	cin.get();
	return 0;
}
