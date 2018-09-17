// Graphl1.cpp: implementation of the Graphl class.
//
//////////////////////////////////////////////////////////////////////
#include "Edge.h"
#include "Team.h"
#include "Llist.h"
#include "stdafx.h"
#include "WorldCup.h"
#include "Graphl1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Graphl::Graphl()
{
}

Graphl::~Graphl()
{
	delete []graList;
}

Graphl::Graphl(int numVert):Graph(numVert)
{
	graList = new Llist [numVert];
}


Edge Graphl::FirstEdge(int oneVertex)
{
	Edge myEdge;
	myEdge.from = oneVertex;//oneVertex作为始点
	Link *temp = graList[oneVertex].head;//temp指向边表第一个元素
	if(temp->next != NULL){
		myEdge.to = temp->next->element.vertex;
		myEdge.weight1 = temp->next->element.weight1;
		myEdge.weight2 = temp->next->element.weight2;
	}
	return myEdge;

}

int Graphl::VerticesNum()
{
	return numVertex;
}

Edge Graphl::NextEdge(Edge preEdge)
{
	Edge myEdge;
	myEdge.from = preEdge.from;
	Link *temp = graList[preEdge.from].head;//temp指向第一个元素
	while(temp->next != NULL && temp->next->element.vertex <= preEdge.to)
		temp = temp->next;
	if(temp->next != NULL){//下一条边存在
		myEdge.to = temp->next->element.vertex;
		myEdge.weight1 = temp->next->element.weight1;
		myEdge.weight2 = temp->next->element.weight2;
	}
	return myEdge;

}

void Graphl::setEdge(int from, int to, int weight1, int weight2)
{
	Link *temp = graList[from].head;//temp指向第一个元素
	while(temp->next != NULL && temp->next->element.vertex < to)
		temp = temp->next;
	if(temp->next == NULL){//（from，to）不存在且是最后一条边
		temp->next = new Link();
		temp->next->element.vertex=to;
		temp->next->element.weight1=weight1;
		temp->next->element.weight2=weight2;
		numEdge++;
		Indegree[to]++;
		return;
	}
	if(temp->next->element.vertex == to){//（from，to）存在
		temp->next->element.weight1 = weight1;
		temp->next->element.weight2 = weight2;
		return;
	}
	if(temp->next->element.vertex > to){//（from，to）不存在且后面还有边
		Link *other = temp->next;//临时存放指向后面链表元素的指针
		temp->next = new Link();
		temp->next->element.vertex=to;
		temp->next->element.weight1=weight1;
		temp->next->element.weight2=weight2;
		temp->next->next = other;
		numEdge++;
		Indegree[to]++;
		return;
	}

}

void Graphl::delEdge(int from, int to)
{
	Link *temp = graList[from].head;
	while(temp->next != NULL && temp->next->element.vertex < to)
		temp = temp->next;//temp指向被删除元素的前驱
		if(temp->next == NULL) return;
		if(temp->next->element.vertex > to) return;
		if(temp->next->element.vertex == to){
			Link *other =temp->next->next;
			delete temp->next;
			temp->next = other;
			numEdge++;
			Indegree[to]--;
			return;
		}

}

int Graphl::FromVertex(Edge e)
{
	return e.from;
}

int Graphl::ToVertex(Edge e)
{
	return e.to;
}

int Graphl::Weight1(Edge e)
{
	return e.weight1;
}

int Graphl::Weight2(Edge e)
{
	return e.weight2;
}

Graphl* Graphl::operator =(Graphl &t)
{
	graList = t.graList;
	return this;
}

Edge Graphl::GetEdge(int from, int to)
{
	Edge myEdge;
	myEdge.from = from;
	Link *temp = graList[from].head;//temp指向第一个元素
	while(temp->next != NULL && temp->next->element.vertex < to)
		temp = temp->next;
	if(temp->next != NULL){//下一条边存在
		myEdge.to = temp->next->element.vertex;
		myEdge.weight1 = temp->next->element.weight1;
		myEdge.weight2 = temp->next->element.weight2;
	}
	return myEdge;

}

IMPLEMENT_SERIAL(Graphl,CObject,1)
void Graphl::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  空函数
    if(ar.IsStoring( )){
		
		
	}
    else{
	
	} 
	graList->Serialize(ar);
}

