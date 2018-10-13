#include "Stack.h"
#include<iostream>
using namespace std;



int main(){
	Stack<int> * a = new Stack<int>();
	a -> push(5);
	a -> push(6);
	cout << (a -> top() -> data);
	a -> pop();
	cout << (a -> top() -> data);
}