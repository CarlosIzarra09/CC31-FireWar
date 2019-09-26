#ifndef __LIST_H__
#define __LIST_H__



template<typename T>
class ListaSimple {
	struct	Node
	{
		T* obj;
		Node  *next;
		Node(T* obj = nullptr, Node * next = nullptr) : obj(obj), next(next) {}
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
	int Tamano() {
		return Length;
	}
	void addFirst(T* obj) {
		First = new Node(obj, First);
		++Length;
	}
	void insert(T* obj, int pos) {
		if (pos == 0)
		{
			addFirst(obj);
		}
		else if (pos > 0 && pos <= Length) {
			Node *aux = First;
			for (int i = 1; i < pos; i++)
			{
				aux = aux->next;
			}
			aux->next = new Node(obj, aux->next);
			++Length;
		}
	}
	void addend(T* obj) {
		insert(obj, Length);

	}


	T* getAt(int pos)
	{
		if (Length > 0 && pos < Length)
		{
			Node * aux = First;
			for (int i = 0; i < pos; i++) {
				aux = aux->next;
			}
			return aux->obj;
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
		else if (pos > 0 && pos < Length-1) {
			Node *aux = First;
			for (int i = 0; i < pos-1; i++)
			{
				aux = aux->next;
			}
			Node *aux2 = aux->next;

			aux->next = aux2->next;

			delete aux2;
			--Length;
		}
		else if (pos == Length - 1)
		{
			deleteLast();
		}
	}
	void deleteLast()
	{
		Node*aux = First;
		for (int i = 0; i < Length-1; i++)
		{
			aux = aux->next;
		}
		Node*aux2 = aux->next;
		delete aux2;
		aux->next = nullptr;
		--Length;
	}
	void editPos(T* obj, int pos)
	{
		if (Length > 0 && pos < Length)
		{
			Node * aux = First;
			for (int i = 0; i < pos; i++)
			{
				aux = aux->next;
			}

			aux->obj = obj;
		}
	}

};




#endif // __LIST_H__
