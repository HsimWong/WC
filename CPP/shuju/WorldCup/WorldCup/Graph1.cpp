// Graph1.cpp: implementation of the Graph class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Graph1.h"

#define INFINITY 10000
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Graph::Graph()
{
	numVertex = 0;
	numEdge = 0;
	Indegree = new int[0];
	Mark = new int[0];
	
}

Graph::~Graph()
{
	delete[] Mark;
	delete[] Indegree;

}

Graph::Graph(int numVert)
{
	numVertex = numVert;
	numEdge = 0;
	Indegree = new int[numVertex];
	Mark = new int[numVertex];
	for(int i=0;i < numVertex;i++){
		Mark[i] = 0;
		Indegree[i] = 0;
	}

}

int Graph::VerticesNum()
{
	return numVertex;
}

bool Graph::IsEdge(Edge oneEdge)
{
	if(oneEdge.weight1>0 && oneEdge.weight2>0 && oneEdge.weight1<INFINITY && oneEdge.weight2<INFINITY && oneEdge.to>=0)
			return true;
		else
			return false;
}

IMPLEMENT_SERIAL(Graph,CObject,1)
void Graph::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( )){
		ar<<numEdge<<numVertex;
		  for(int i=0;i<numVertex;i++)
        {
             int p ;
			 p= Indegree[i];
			 ar<<p<<Mark[i];
        }
		
	}
    else{
		ar>>numEdge>>numVertex;
		  for(int i=0;i<numVertex;i++)
        {
             int p ;
			 p= Indegree[i];
			 ar>>p>>Mark[i];
        }
	} 
}
