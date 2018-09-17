// Team.cpp: implementation of the Team class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldCup.h"
#include "Team.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Team::Team()
{
	TeamName="";
	Ranking=0;
}

Team::~Team()
{
}
IMPLEMENT_SERIAL(Team,CObject,1)
void Team::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);	//  ¿Õº¯Êý
    if(ar.IsStoring( )){
		int size=23;
		ar<<size;
		  for(int i=0;i<size;i++)
        {
             Players psn ;
			 psn= p[i];
             psn.Serialize(ar);
        }
		ar<<TeamName<<Ranking<<vertex<<weight1<<weight2;
	}
    else{
		int size=23;
		ar>>size;
		  for(int i=0;i<size;i++)
        {
             Players psn;
             psn.Serialize(ar);
			 p[i]=psn;
        }
		ar>>TeamName>>Ranking>>vertex>>weight1>>weight2;
	} 
}

Team* Team::operator =(Team &t)
{
	Ranking = t.Ranking;
	TeamName = t.TeamName;
	vertex = t.vertex;
	weight1 = t.weight1;
	weight2 = t.weight2;
	for(int i=0;i<23;i++)
		p[i] = t.p[i];
	return this;

}



void Team::SetVertex(int v)
{
   vertex = v;
}

int Team::GetVertex()
{
   return vertex;
}
