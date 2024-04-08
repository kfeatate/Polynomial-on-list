#pragma once

template <typename T>
class Node {
public:
	T data;
	Node* next;
public:
	Node(const T& _data) {
		data = _data;
		next = nullptr;
	} 
	template <typename T>
	friend class Tlist;
	template <typename T>
	friend class Iterator;
	friend class Polynomial;
};