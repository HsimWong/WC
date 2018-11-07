#include<iostream>
using namespace std;

template<class T>
void QuickSort(T Array[], int left, int right){
	if(right < left)return;
	int pivot = selectPivot(left, right);
	T temp = Array[left];
	Array[right] = 
}

template<class T>


template<class T>
void selectPivot(int left, int right ){
	return (left + right) / 2;
}



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}