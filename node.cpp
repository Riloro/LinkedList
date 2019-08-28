
#ifndef Node_h
#define Node_h

template <class T>
class Node
{
public:
	Node(T d);
	Node(T d, Node<T> *n);
	T getData();
	Node<T>* getNext(); //Regresa una direccion de memoria
	void setData(T d);
	void setNext(Node<T> *n);
private:
	T data;
	Node<T> *next;
};

template <typename T>
Node<T>::Node(T d)
{
	data = d;
	next = NULL;
}

template <typename T>
Node<T>::Node(T d, Node<T> *n)
{
	data = d;
	next = n;
}

template <typename T>
T Node<T>::getData()
{
	return data;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <typename T>
void Node<T>::setData(T d)
{
	data = d;
}

template <typename T>
void Node<T>::setNext(Node<T>* n)
{
	next = n;
}

#endif /* Node_h */
