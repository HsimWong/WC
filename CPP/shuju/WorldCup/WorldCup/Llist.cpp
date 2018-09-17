// Llist.cpp: implementation of the Llist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Llist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Llist::Llist()
{
	head = new Link();
}

Llist::~Llist()
{

}

IMPLEMENT_SERIAL(Llist,CObject,0);
void Llist::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( )){
	}  
    else{
	}
	head->Serialize(ar);
}
