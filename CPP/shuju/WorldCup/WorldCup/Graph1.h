// Graph1.h: interface for the Graph class.
//
//////////////////////////////////////////////////////////////////////
#include "Edge.h"
#if !defined(AFX_GRAPH1_H__C7951A7C_29E7_4B43_9B18_136E4BC5160B__INCLUDED_)
#define AFX_GRAPH1_H__C7951A7C_29E7_4B43_9B18_136E4BC5160B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Graph : public CObject  
{
	DECLARE_SERIAL(Graph)
public:
	void Serialize(CArchive &ar);
	bool IsEdge(Edge oneEdge);
	int VerticesNum();
	Graph(int numVert);
	int numVertex;
	int numEdge;
	int *Mark;//入度访问,访问过为1，未访问为0
	int *Indegree;//顶点入度

	Graph();
	virtual ~Graph();

};

#endif // !defined(AFX_GRAPH1_H__C7951A7C_29E7_4B43_9B18_136E4BC5160B__INCLUDED_)
