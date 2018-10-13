#ifndef STACK_H
#define STACK_H
#include<iostream>
#include "Link.h"
using namespace std;

template<class T>
class Stack{
private:
	int length;
	// Link<T> * head;
	Link<T> * Top;
public:
	Stack();
	void clear();
	Link<T> * push(T item);
	bool pop();
	Link<T> * top();
	bool isEmpty();
	// int get_length();
};

template <class T>
Stack<T>::Stack(){
	this -> length = 0;
	// this -> head = NULL;
	this -> Top = NULL;
}
template<class T>
Link<T> * Stack<T>::push(T item){
	if(this -> length == 0){
		this -> Top = NULL;
	}
	Link<T> * temp = new Link<T>(item, Top);
	length++;
	this -> Top = temp;
	temp -> ~Link();
	return this -> Top;
}

template<class T>
void Stack<T>:: clear(){
	Link<T> * temp;
	while((this -> length) != 0 ){
		pop();
	}

	// if((this -> length) == 0){
	// 	return true;
	// }
	// else{
	// 	cerr << "Stack has tried to clear but failed" << endl;
	// 	return false;
	// }
}

template<class T>
bool Stack<T>::pop(){
	Link<T> * temp;
	if((this -> length) != 0){
		temp = this -> Top;
		this -> Top = temp -> pre;
		temp -> ~Link();
		(this -> length)--; 
		return true;
	}
	else{
		
		cerr << "Pop failed" << endl;
		return false;
	}
}

template<class T>
Link<T> * Stack<T> :: top(){
	return this -> Top;
}

template<class T>
bool Stack<T>::isEmpty(){
	return (this -> length) == 0;
}




#endif