// Elem.cpp: implementation of the Elem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Elem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Elem::Elem()
{

}

Elem::~Elem()
{

}
IMPLEMENT_SERIAL(Elem,CObject,0);

void Elem::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( ))
        ar<<vertex<<weight1<<weight2;
    else
        ar>>vertex>>weight1>>weight2;
}
