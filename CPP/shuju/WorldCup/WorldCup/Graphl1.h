// Graphl1.h: interface for the Graphl class.
//
//////////////////////////////////////////////////////////////////////
#include "Graph1.h"
#include "Llist.h"
#if !defined(AFX_GRAPHL1_H__6B309099_235E_4805_A99B_4C15EC69BDD1__INCLUDED_)
#define AFX_GRAPHL1_H__6B309099_235E_4805_A99B_4C15EC69BDD1__INCLUDED_

#include "Edge.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Graphl : public Graph  
{
	DECLARE_SERIAL(Graphl)
public:
	void Serialize(CArchive &ar);
	Llist  *graList;//保存所有边表的数组

	int Weight2(Edge e);
	int Weight1(Edge e);
	int ToVertex(Edge e);
	int FromVertex(Edge e);
	void delEdge(int from,int to);
	Edge GetEdge(int from,int to);
	void setEdge(int from,int to,int weight1,int weight2);
	Edge NextEdge(Edge preEdge);
	int VerticesNum();
	Edge FirstEdge(int oneVertex);
	Graphl(int numVert);
	Graphl* operator =(Graphl &t);
	
	Graphl();
	virtual ~Graphl();

};

#endif // !defined(AFX_GRAPHL1_H__6B309099_235E_4805_A99B_4C15EC69BDD1__INCLUDED_)
