//
//  LinkedList.h
//

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList(); // Se llama automaticamente
	void addFirst(T d); //prepend
	void addLast(T d); // append
	T deleteFirst();
	void deleteLast();
	void add(T d, int pos);
	void del(int pos);
	void reverse();
	void print();
	T get(int pos);
	bool set(T d, int pos);
	bool isEmpty();
	int getCount();

private:
	Node<T> *head;
	void borra();
	int count;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	count = 0;
}

template <typename T>
void LinkedList<T>::borra()
{
	Node<T>* aux = head;
	while (aux != NULL)
	{
		head = head->getNext();
		delete aux;
		aux = head;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	borra();
}

template <typename T>
void LinkedList<T>::addFirst(T d)
{
	head = new Node<T>(d, head);
	count++;
}

template <typename T>
void LinkedList<T>::addLast(T d)
{
	Node<T>* aux = head;
	if (head == NULL)
	{
		addFirst(d);
		return;
	}
	while (aux->getNext() != NULL)
	{
		aux = aux->getNext();
	}
	// Ya tenemos el ultimo en aux
	aux->setNext(new Node<T>(d));

	count++;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
	//return count == 0;
}

template <typename T>
int LinkedList<T>::getCount()
{
	return count;
}

template <typename T>
void LinkedList<T>::print()
{
	if (head == NULL)
		return;
	Node<T>* aux = head;
	while (aux != NULL)
	{
		cout << aux->getData() << " ";
		aux = aux->getNext();
	}
	cout << endl;
}

template <typename T>
T LinkedList<T>::deleteFirst() {
	if (this->isEmpty()) {
		return NULL;
	}

	T dataAux = head->getData();
	Node<T> *aux = head;
	head = head->getNext();
	delete aux;
	count--;
	return dataAux;
}

#endif /* LinkedList_h */