#include<iostream>
using namespace std;

template<typename T>
class LIST {
	template<typename T>
	class celltype {
	public:
		celltype* next;
		celltype* prev;
		T element;

		celltype(T element = T(), celltype* next = nullptr, celltype* prev = nullptr) {
			this->element = element;
			this->next = next;
			this->prev = prev;
		}
	};
	int size;
	celltype<T>* head;
	celltype<T>* tail;

public:
	LIST();
	~LIST();

	int GetSize() { return size; }
	void AddHead(T element);
	void AddTail(T element);
	void MAKENULL();
	int END();
	int FIRST();
	void INSERT(T element, int index);
	void DELETE(int index);
	int LOCATE(T element);
	T& RETRIEVE(int index);
	void* NEXT(int index);
	void* PREVIOUS(int index);
	void PRINTLIST();
};

template<typename T>
LIST<T>::LIST() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
LIST<T>::~LIST() {
	MAKENULL();
}

template<typename T>
void LIST<T>::AddHead(T element) {
	celltype<T>* tmp = new celltype<T>(element, head);

	if (head != nullptr) {
		head->prev = tmp;
	}

	if (size == 0) {
		head = tail = tmp;
	}
	else {
		head = tmp;
	}
	size++;
}

template<typename T>
void LIST<T>::AddTail(T element) {
	celltype<T>* tmp = new celltype<T>(element, nullptr, tail);

	if (tail != nullptr) {
		tail->next = tmp;
	}

	if (size == 0) {
		head = tail = tmp;
	}
	else {
		tail = tmp;
	}
	size++;
}

template<typename T>
void LIST<T>::MAKENULL() {
	while (size) {
		celltype<T>* tmp = head;
		head = head->next;
		delete tmp;
		size--;
	}
}

template<typename T>
int LIST<T>::END() {
	int counter = 0;
	celltype<T>* current = this->head;
	while (current != nullptr) {
		current = current->next;
		counter++;
	}
	return counter;
}

template<typename T>
int LIST<T>::FIRST() {
	if (head != nullptr) {
		return 0;
	}
	else {
		return END();
	}
}

template<typename T>
void LIST<T>::INSERT(T element, int index) {
	if (index == 0) {
		AddHead(element);
	}
	else if (index == size) {
		AddTail(element);
	}
	else {
		celltype<T>* previous = head;
		celltype<T>* Next = tail;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}
		for (int i = size - 1; i > index + 1; i--) {
			Next = Next->prev;
		}
		previous->next = new celltype<T>(element, previous->next, Next->prev);
		size++;
	}
}

template<typename T>
void LIST<T>::DELETE(int index) {
	celltype<T>* toDelete = head;
	int i = 0;
	while (i < index) {
		toDelete = toDelete->next;
		i++;
	}

	celltype<T>* PrevToDelete = toDelete->prev;
	celltype<T>* NextToDelete = toDelete->next;

	if (index == 0) {
		head = NextToDelete;
	}
	else if (index == size - 1) {
		tail = PrevToDelete;
	}
	else {
		if (PrevToDelete != nullptr && size != 1)
			PrevToDelete->next = NextToDelete;
		if (NextToDelete != nullptr && size != 1)
			NextToDelete->prev = PrevToDelete;
	}
	delete toDelete;
	size--;
}

template<typename T>
int LIST<T>::LOCATE(T element) {
	int counter = 0;
	celltype<T>* current = this->head;
	while (current != nullptr) {
		if (current->element == element) {
			return counter;
		}
		current = current->next;
		counter++;
	}
	return END();
}

template<typename T>
T& LIST<T>::RETRIEVE(int index) {
	if (size - index < index) {
		int counter = 0;
		celltype<T>* current = this->head;
		while (current != nullptr) {
			if (counter == index) {
				return current->element;
			}
			current = current->next;
			counter++;
		}
	}
	else {
		int counter = size - 1;
		celltype<T>* current = this->tail;
		while (current != nullptr) {
			if (counter == index) {
				return current->element;
			}
			current = current->prev;
			counter--;
		}
	}
	
}

template<typename T>
void* LIST<T>::NEXT(int index) {
	bool tmp = false;
	int counter = 0;
	celltype<T>* current = this->head;
	while (current->next != nullptr) {
		if (counter == index) {
			tmp = true;
			return current->next;
		}
		current = current->next;
		counter++;
	}
	if (tmp == false) {
		return END();
	}
}

template<typename T>
void* LIST<T>::PREVIOUS(int index) {
	bool tmp = false;
	int counter = 0;
	celltype<T>* current = this->head;
	while (current->next != nullptr) {
		if (counter == index) {
			tmp = true;
			return current->prev;
		}
		current = current->next;
		counter++;
	}
	if (tmp == false) {
		return END();
	}
}

template<typename T>
void LIST<T>::PRINTLIST() {
	cout << "{ ";
	for (int i = 0; i < size; i++) {
		cout << RETRIEVE(i) << " ";
	}
	cout << "}" << endl;
}

int main() {
	LIST<int> L;
	L.AddTail(5);
	L.AddTail(4);
	L.AddTail(3);
	L.AddTail(2);
	L.AddTail(1);
	L.PRINTLIST();
	return 0;
}