#pragma once
#include<iostream>
using namespace std;
template<class T>
class Stack{
	T* data;
	int maxSize;
	int topIndex;
public:
	Stack():topIndex(-1),data(nullptr),maxSize(0){}
	Stack(int maxSize):topIndex(-1),data(nullptr) {
		if (maxSize < 1)
			maxSize = 1;
		this->maxSize = maxSize;
			data = new T[maxSize];
	}
	Stack(const Stack& other) {
		maxSize = other.maxSize;
		topIndex = other.topIndex;
		data = nullptr;
		if (topIndex != -1)
			data = new T[topIndex + 1];
		for (int i = 0; i <= topIndex; i++)
			data[i] = other[i];
	}
	Stack& operator=(const Stack& other) {
		if (this != &other) {
			maxSize = other.maxSize;
			topIndex = other.topIndex;
			data = nullptr;
			if (topIndex != -1)
				data = new T[topIndex + 1];
			for (int i = 0; i <= topIndex; i++)
				data[i] = other[i];
		}
		return *this;
	}
	~Stack() {
		delete[]data;
	}

	bool Push(T&elem){
		if (maxSize == 0) {
			T *res = new T[topIndex+2];
			for (int i = 0; i <= topIndex; i++)
				res[i] = data[i];
				delete[]data;
			data = res;
		}
		if (!IsFull()){
			data[++topIndex] = elem;
			return true;
		}
		
		return false;
	}
	T Pop(){
		if (!IsEmpty()) 
			return data[topIndex--];
		
		return T();
	}
	T Peek(){
		if (!IsEmpty())
			return data[topIndex];

		return 0;
	}
	bool IsFull()const {
		return maxSize != 0 && topIndex == maxSize - 1;
	}
	bool IsEmpty() {
		return topIndex == -1;
	}
	int GetCount() const{
		return topIndex + 1;
	}
};

