#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class match{

};

int main(){
	time_t now = time(0);
	char * dt = ctime(&now);
	cout << dt << endl;
}