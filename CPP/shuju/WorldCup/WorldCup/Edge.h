// Edge.h: interface for the Edge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDGE_H__295AE0AB_E570_465A_9B97_980DF193DAA6__INCLUDED_)
#define AFX_EDGE_H__295AE0AB_E570_465A_9B97_980DF193DAA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Edge : public CObject  
{
	DECLARE_SERIAL(Edge)
public:
	void Serialize(CArchive & ar);
	Edge(const  Edge& e);
	Edge(int f,int t,int w1,int w2);
	int from,to,weight1,weight2;
	Edge();
	virtual ~Edge();

};

#endif // !defined(AFX_EDGE_H__295AE0AB_E570_465A_9B97_980DF193DAA6__INCLUDED_)
