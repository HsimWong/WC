// Edge.cpp: implementation of the Edge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Edge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Edge::Edge()
{
	from = -1;
	to = -1;
	weight1=0;
	weight2 = 0;
}

Edge::~Edge()
{

}

Edge::Edge(int f, int t, int w1, int w2)
{
	from = f;
	to = t;
	weight1 = w1;
	weight2 = w2;
}

Edge::Edge(const Edge & e)
{
  from = e.from;
  to = e.to;
  weight1 = e.weight1;
  weight2 = e.weight2;
}

IMPLEMENT_SERIAL(Edge,CObject,0);
void Edge::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( ))
        ar<<from<<to<<weight1<<weight2;
    else
        ar>>from>>to>>weight1>>weight2;
}

