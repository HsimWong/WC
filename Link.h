#ifndef LINK_H
#define LINK_H 
#include<iostream>
using namespace std;
template<class T>
class Link{
public:
	T data;
	Link<T> * next;
	Link<T> * pre;
	Link(T info, Link<T> * pre = NULL, Link<T> * nextValue = NULL){
		this -> data = info;
		this -> pre = pre;
		this -> next = nextValue;
	}
	
};



#endif		