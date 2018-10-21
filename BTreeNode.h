#ifndef TREENODE_H
#define TREENODE_H

#include<iostream>
using namespace std;

template <class T>
class BTreeNode
{
private:
	T info;
	BTreeNode<T> * left;
	BTreeNode<T> * right;

public:
	BTreeNode();
	~BTreeNode();
	
};

template <class T>
BTreeNode<T> :: BTreeNode(T info){
	this -> info = 
}


#endif