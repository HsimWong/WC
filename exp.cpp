#include "Stack.h"
#include<iostream>
#include "Match.h"
using namespace std;



int main(){
	Match * match = new Match(5);
	cout << match -> get_match_id();
}