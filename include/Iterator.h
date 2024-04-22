#pragma once
#include "Node.h"

template <typename T>
class Iterator {
	Node<T>* iter;
public:
	Iterator() {
		iter = nullptr;
	}
	Iterator(Node<T>* _iter) {
		iter = _iter;
	}
	Iterator(const Iterator& _iter) {
		iter = _iter.iter;
	}
	 Iterator& operator++() {
		iter = iter->next;
		return *this;
	}
	bool operator==(const Iterator<T>& it) {
		if (iter == it.iter) {
			return true;
		}
		else return false;
	}
	bool operator!=(const Iterator<T>& it) {
		if (iter != it.iter) {
			return true;
		}
		else return false;
	}
	T& operator*() {
		return iter->data;
	}
	friend class Polynomial;
	template <typename T>
	friend class TList;
};