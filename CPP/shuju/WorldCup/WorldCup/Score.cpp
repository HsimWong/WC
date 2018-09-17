// Score.cpp: implementation of the Score class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Score.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Score::Score()
{
	Timing = "";
	Against = "";
	next = NULL;
}

Score::~Score()
{

}

IMPLEMENT_SERIAL(Score,CObject,0);
void Score::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( ))
        ar<<Timing<<Event<<Against;
    else
        ar>>Timing>>Event>>Against;
	next->Serialize(ar);
}
