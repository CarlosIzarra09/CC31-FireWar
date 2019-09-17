#ifndef __LIST_H__
#define __LIST_H__
using namespace std;
#include <functional>

using namespace std;

typedef unsigned int uint;

template<typename T>
class ListaSimple {
	struct	Node
	{
		T elem;
		Node * next;
		Node(T elem = 0, Node * next = nullptr) : elem(elem), next(next) {}
	};

	int Length;
	Node* First;

public:

	ListaSimple() :Length(0), First(nullptr) {}

	~ListaSimple() {
		while (First != nullptr)
		{
			Node *aux = First;
			First = First->next;
			delete aux;
		}
	}

	bool ISEMPTY()
	{
		return First == nullptr;
	}
	int size() {
		return Length;
	}
	void addFirst(T elem) {
		First = new Node(elem, First);
		++Length;
	}
	void insert(T elem, int pos) {
		if (pos == 0)
		{
			addFirst(elem);
		}
		else if (pos > 0 && pos <= Length) {
			Node *aux = First;
			for (int i = 1; i < pos; i++)
			{
				aux = aux->next;
			}
			aux->next = new Node(elem, aux->next);
			++Length;
		}
	}
	void append(T elem) {
		insert(elem, Length);

	}


	T getAt(int pos)
	{
		if (Length > 0 && pos < Length)
		{
			Node * aux = First;
			for (int i = 0; i < pos; i++) {
				aux = aux->next;
			}
			return aux->elem;
		}

	}

	void DeleteFirst()
	{
		if (Length > 0)
		{
			Node *aux = First;
			First = First->next;
			delete aux;
			--Length;
		}
	}

	void DeletePos(int pos)
	{
		if (pos == 0)
		{
			DeleteFirst();

		}
		else if (pos > 0 && pos < Length) {
			Node *aux = First;
			for (int i = 0; i < pos; i++)
			{
				aux = aux->next;
			}
			Node *aux2 = aux->next;

			aux->next = aux2->next;

			delete aux2;
			--Length;
		}
	}
	void deleteLast()
	{
		DeletePos(Length - 1);

	}
	void editPos(T elem, int pos)
	{
		if (Length > 0 && pos < Length)
		{
			Node * aux = First;
			for (int i = 0; i < pos; i++)
			{
				aux = aux->next;
			}

			aux->elem = elem;
		}
	}

};




#endif // __LIST_H__
