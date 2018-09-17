// Link.cpp: implementation of the Link class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Link.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



Link::~Link()
{

}

Link::Link( Elem &elemval, Link *nextval)
{
	element.vertex = elemval.vertex;
	element.weight1 = elemval.weight1;
	element.weight2 = elemval.weight2;
	next = nextval;

}

Link::Link(Link *nextval)
{
	next = nextval;
}

IMPLEMENT_SERIAL(Link,CObject,0);
void Link::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( )){
	}  
    else{
	}
	next->Serialize(ar);
	element.Serialize(ar);
}
