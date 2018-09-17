// Players.cpp: implementation of the Players class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Players.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Players::Players():Name(""),Number(0),Ranking(0),Team(""),Position(""),s(0)//Timing(""),Event(""),
{
	sc = new Score();
}

Players::~Players()
{

}

Players* Players:: operator =(Players &p2)
{
	 Name = p2.Name;
	 Number = p2.Number;
	 Position = p2.Position;
	 Ranking = p2.Ranking;
	 Team = p2.Team;
	// Timing = p2.Timing;
//	 Event = p2.Event;
	 s= p2.s;
	 sc = p2.sc;
	 return this;

 }
IMPLEMENT_SERIAL(Players,CObject,0);
void Players::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( ))
        ar<<Name<<Number<<Ranking<<Team<<Position<<s;//<<Timing<<Event
    else
        ar>>Name>>Number>>Ranking>>Team>>Position<<s;//<<Timing>>Event

//	sc->Serialize(ar);/////////////////////////////////////////////////////////////////////////////
}

void Players::SetTiming(CString t)
{
	Score *temp;
	temp = sc;
	while(temp->next != NULL && temp->next->Timing != "" )
		temp = temp->next;
	if(temp->next == NULL){
		temp->next = new Score();
		temp->next->Timing = t;
	}
	else temp->next->Timing = t;
}

void Players::SetAgainst(CString a)
{
	Score *temp = sc;
	while(temp->next != NULL && temp->next->Against != "" )
		temp = temp->next;
	if(temp->next == NULL){
		temp->next = new Score();
		temp->next->Against = a;
	}
	else temp->next->Against = a;

}

Score* Players::GetTiming(CString a)
{
	Score *temp = sc;
	while(temp->next != NULL && temp->Against != a )
		temp = temp->next;
	 return temp;
}
