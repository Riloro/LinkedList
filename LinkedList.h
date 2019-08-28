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
	~LinkedList(); 
	void addFirst(T d); 
	void addLast (T d);
	void operator += (T d);
	T deleteFirst();
	T deleteLast();
	void deleteAll();
	bool add(T d, int pos);
	T del(int pos);
	void print();
	T get(int);
	void set(T, int);
	bool isEmpty();
	int getCount();
	bool change(int, int);
	void reverse();
	void shift(int);
	bool operator == ( LinkedList<T>);
	void operator += (LinkedList<T>const &) ;
	void operator = (LinkedList<T>);

private:
	Node<T> *head;
	void borra();
	int count;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	count = 0;
}

template <typename T>
void LinkedList<T>::borra()
{
	Node<T>* aux = head;
	while (head != nullptr)
	{
		head = head->getNext();
		delete aux;
		aux = head;
	}
	
}

template <typename T>
void LinkedList<T>::deleteAll()
{
	Node<T>* aux = head;
	while (head != nullptr)
	{
		head = head->getNext();
		delete aux;
		aux = head;
	}
	count = 0;

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
void LinkedList<T>:: addLast (T d)
{
	Node<T>* aux = head;
	if (head == nullptr)
	{
		addFirst(d);
		return;
	}
	while (aux->getNext() != nullptr)
	{
		aux = aux->getNext();
	}
	
	aux->setNext(new Node<T>(d));

	count++;
}

template <typename T>
void LinkedList<T>::operator+= (T d) {
	Node <T> *aux = head;
	while (aux->getNext() != nullptr)
	{
		aux = aux->getNext();
	}
	aux->setNext(new Node<T>(d));
	count ++;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return head == nullptr;
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
	if (head == nullptr)
		return;
	Node<T>* aux = head;
	while (aux != nullptr)
	{
		cout << aux->getData() << " ";
		aux = aux->getNext();
	}
	cout << endl;
}

template <typename T>
T LinkedList<T>::deleteFirst() {
	if (this->isEmpty()) {
		return nullptr;
	}

	T dataAux = head->getData();
	Node<T> *aux = head;
	head = head->getNext();
	delete aux;
	count--;
	return dataAux;
}

template<typename T>
T LinkedList<T>::deleteLast() {
	if (count <= 1) {
		return this->deleteFirst();
	}
	Node<T> *aux = head;
	while (aux->getNext()->getNext() != nullptr) {
		aux = aux->getNext();
	}
	Node<T> *aux2 = aux->getNext();
	T dataaux = aux2->getData();
	aux->setNext(nullptr);
	delete aux2;
	count--;
	return  dataaux;
}

template<typename T>
bool LinkedList<T>::add(T d, int pos) {
	if (pos < 0 || pos > count) {
		return false;
	}
	if (pos == 0){
		this->addFirst(d);
	}
	else if ( pos == count) {
		this->addLast(d);
	}
	else {
		Node<T> *aux = head;
		for (int i = 1; i < pos; i++) {
			aux = aux->getNext();
		}
		aux->setNext(new Node<T>(d, aux->getNext()));
		count++;
	}
	return true;
}

template <typename T>
T LinkedList<T>::del(int pos) {
	if (pos >= count) {
		return nullptr;
	}
	if (pos == 0) {
		return this->deleteFirst();
	}
	if (pos == count) {
		return this->deleteLast();
	}
	else {
		Node<T> *aux = head;
		for (int i = 1; i < pos; i++) {
			aux = aux->getNext();
		}
		Node<T> *aux2 = aux->getNext();
		T dataAux = aux2->getData();
		aux->setNext(aux2->getNext());
		delete aux2;
		count--;
		return dataAux;
	}
	
}
//Reverse
template<typename T>
void LinkedList<T>::reverse() {
	Node<T> *aux1 = head;
	Node<T> *aux2 = head->getNext();
	head->setNext(nullptr);
	
	while (aux2 != nullptr)
	{
		head = aux2;
		aux2 = aux2->getNext();
		head->setNext(aux1);
		aux1 = head;
	
	}
	
	
}

template<typename T>
void LinkedList<T>::shift(int num) {
	Node <T> *aux1;
	Node<T> *aux2;
	Node <T>*aux3;
	aux3 = head;
	aux2 = head;
	int size = 0;

	if (num < 0)
	{
		size = count - (-1 * num);
		for (int i = 0; i < size ; i++)
		{
			head = head->getNext();
		}
		for (int i = 0; i < size - 1; i++)
		{
			aux2 = aux2->getNext();
		}
		aux1 = head;
		while (aux1->getNext() != nullptr)
		{
			aux1 = aux1->getNext();
		}
		aux2->setNext(nullptr);
		aux1->setNext(aux3);
	}
	else {
		for (int i = 0; i < num; i++)
		{
			head = head->getNext();
		}
		for (int i = 0; i < num - 1; i++)
		{
			aux2 = aux2->getNext();
		}
		aux1 = head;
		while (aux1->getNext() != nullptr)
		{
			aux1 = aux1->getNext();
		}
		aux2->setNext(nullptr);
		aux1->setNext(aux3);


	}
}

template < typename T>
bool LinkedList<T>::change(int pos1, int pos2) {

	if (pos1 < 0 || pos1 >= count || pos2 < 0 || pos2 >= count) {
		return false;
	}
	if (pos1 == pos2)
	{
		return true;
	}
	T dataAux1, dataAux2;
	Node<T> *aux1 = head, *aux2 = head;
	for (int i = 1; i <= pos1; i++) {
		aux1 = aux1->getNext();
	}
	for (int i = 1; i <= pos2; i++) {
		aux2 = aux2->getNext();
	}
	dataAux1 = aux1->getData();
	dataAux2 = aux2->getData();
	aux1->setData(dataAux2);
	aux2->setData(dataAux1);
	return true;

}

template<typename T>
bool LinkedList<T>::operator == ( LinkedList<T> lista) {
	

	if (lista.getCount() != this->count)
	{
		return false;
	}
	Node<T> *aux = head;
	Node<T> *aux2 = lista.head;
	for (int i = 0; i < count ; i++)
	{	
		if (aux2->getData() != aux->getData())
		{
			return false;
		}
		aux = aux->getNext();
		aux2 = aux2->getNext();
	}
	return true;
}

template<class T>
void LinkedList<T> :: operator += (LinkedList<T> const &list)  {
	Node<T> *aux = list.head;
	/*Node<T> *aux = head;
	while (aux->getNext() != NULL)
	{
		aux = aux->getNext();
	}
	for (int i = 0; i < list.getCount(); i++)
	{
		aux->setNext(new Node <T>(list.get(i)));
	}*/
	for (int i = 0; i < list.getCount(); i++)
	{
		*this += aux->getData();
		aux = aux->getNext();
	}
}

template<typename T>
void LinkedList<T>::operator = (LinkedList<T> list) {
	this->deleteAll();
	Node<T> *aux = list.head;
	for (int i = 0; i < list.getCount(); i++)
	{
		this->addLast(aux->getData());
		aux = aux->getNext();
	}
	
}

template<typename T>
T LinkedList<T>::get(int pos) {
	if (pos < this->count) {
		Node<T> *aux = head;
		for (int i = 0; i < pos; i++)
		{
			aux = aux->getNext();
		}
		return aux->getData();
	}
	return 0;
}


template<typename T>
void LinkedList<T>::set(T data, int pos) {
	
	Node<T> *aux1 = head;

	for (int i = 0; i < pos; i++)
	{
		aux1 = aux1->getNext();
	}

	aux1->setData(data);
}


#endif