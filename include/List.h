#pragma once
#include "Node.h"
#include "Iterator.h"

template <typename T>
class TList {
	Node<T>* first;
<<<<<<< HEAD
	size_t sz;
=======
	size_t sz; 
>>>>>>> 968f3b0bcd639bb83f686024e62fa7e82a522a3a
public:
	TList() {
		sz = 0;
		first = nullptr;
	}
	TList(const TList& list) {
		sz = list.sz; 
		Node<T>* tmp = list.first;
		while (tmp) {
			push_back(tmp->data);
			tmp = tmp->next;
		}
	}
	~TList() {
	Node<T>* tmp = first;
	while (tmp) {
		Node<T>* _next = tmp->next;
		delete tmp;
		tmp = _next;
	}
	}
	Node<T>* GetFirst() {
		return first;
	}
	int GetSize() {
		return sz;
	}
	bool isEmpty();
	void push_back(const T& val);
	void insert(const T& val, int pos);
	T& search(int pos);
	void clear(int pos);
	TList<T>& operator=(const TList<T>& list);

	Iterator<T> begin() {
		return Iterator<T>(first);
	}
	Iterator<T> end() {
		return Iterator<T>(nullptr);
	}
	friend class Polynomial;
};

template <typename T>
bool TList<T>::isEmpty() {
	if (this->first == nullptr)
		return true;
	else return false;
}

template <typename T>
void TList<T>::push_back(const T& val) {
	if (first == nullptr) {
		first = new Node<T>(val);
	}
	else {
		Node<T>* tmp = first;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(val);
	}
	sz++;
}

template <typename T>
void TList<T>::insert(const T& val, int pos) {
	if (pos < 0 || pos > sz) {
		throw "wrong position!";
	}
	else {
		Node<T>* node = new Node<T>(val);
		auto current = first;
		for (int i = 0; i < pos-1; i++) {
			current = current->next;
		}
		auto current2 = current->next;
		current->next = node;
		node->next = current2;
		sz++;
	}
}

template <typename T>
T& TList<T>::search(int pos) {
	if (pos < 0 || pos > sz) {
		throw "wrong position!";
	}
	auto current = first;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}
	return current->data;
}

template <typename T>
void TList<T>::clear(int pos) {
	if (pos < 0 || pos > sz) {
		throw "wrong position!";
	}
	if (pos == 0) {
		auto tmp = first;
		first = first->next;
		delete[] tmp;
	}
	else {
		auto current = first;
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}
		auto current2 = current->next;
		current->next = current2->next;
		delete current2;
	}
    sz--;
}

template <typename T>
TList<T>& TList<T>::operator=(const TList<T>& list) {
	sz = list.sz;
	Node<T>* tmp = list.first;
	while (tmp) {
		push_back(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}
