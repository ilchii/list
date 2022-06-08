#include<iostream>
using namespace std;

template<typename T>
class LIST {

	template<typename T>
	class celltype {
	public:
		celltype* next;
		T element;

		celltype(T element = T(), celltype* next = nullptr) {
			this->element = element;
			this->next = next;
		}
	};
	int size;
	celltype<T> *head;

public:
	LIST();
	~LIST();

	int GetSize() { return size; }
	void MAKENULL();
	int END();
	int FIRST();
	void INSERT(T element, int index);
	void DELETE(int index);
	int LOCATE(T element);
	T& RETRIEVE(int index);
	void* NEXT(int index);
	
};

template<typename T>
LIST<T>::LIST() {
	size = 0;
	head = nullptr;
}

template<typename T>
LIST<T>::~LIST() {
	MAKENULL();
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
		head = new celltype<T>(element, head);
		size++;
	}
	else {
		celltype<T>* previous = head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}
		previous->next = new celltype<T>(element, previous->next);
		size++;
	}
}

template<typename T>
void LIST<T>::DELETE(int index) {
	if (index == 0) {
		celltype<T>* tmp = head;
		head = head->next;
		delete tmp;
		size--;
	}
	else {
		celltype<T>* previous = head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}
		celltype<T>* tmp = previous->next;
		previous->next = tmp->next;
		delete tmp;
		size--;
	}
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

int main() {
	LIST<int> L;
	return 0;
}
