// WorldCupDoc.cpp : implementation of the CWorldCupDoc class
//

#include "Graphl1.h"
#include "stdafx.h"
#include "WorldCup.h"


#include "WorldCupDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorldCupDoc

IMPLEMENT_DYNCREATE(CWorldCupDoc, CDocument)

BEGIN_MESSAGE_MAP(CWorldCupDoc, CDocument)
	//{{AFX_MSG_MAP(CWorldCupDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorldCupDoc construction/destruction

CWorldCupDoc::CWorldCupDoc()
{
	Pos=-1;
	g = new Graphl(32);

}

CWorldCupDoc::~CWorldCupDoc()
{
}

BOOL CWorldCupDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWorldCupDoc serialization

void CWorldCupDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int i=Teams.GetSize();
		ar<<i;

		int x=0;
		while(x<Teams.GetSize()){
			ar<<Teams[x];
			x++;
		}
	}
	else
	{
		int i,j;
		ar>>i;
		for(j=0;j<i;j++){
			Team* m;//顺序必须与写入顺序相同  
			ar>>m;
			TeamAdd(m);
		}
	}
	g->Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CWorldCupDoc diagnostics

#ifdef _DEBUG
void CWorldCupDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWorldCupDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorldCupDoc commands

void CWorldCupDoc::Before()
{
	if(Teams.GetSize()>0){
		if((Pos-1)<0){	
			Pos=0;
		}
		else
			Pos=Pos-1;
	}
	else
		Pos=Pos;

}

void CWorldCupDoc::DeleteAll()
{
	int nCount=Teams.GetSize();
	int nPos;
	if(nCount){
	for(nPos=0; nPos<nCount; nPos++)
		delete Teams[nPos];
		Teams.RemoveAll();
	}
	Pos=-1;

}

void CWorldCupDoc::DeleteContents()
{
		DeleteAll();
}

void CWorldCupDoc::EditCurrentData(Team *t)
{
	((Team*)Teams[Pos])->SetTeamName(t->GetTeamName());
	((Team*)Teams[Pos])->SetRanking(t->GetRanking());
//	((Team*)Teams[Pos])->SetPlayersGoalTiming(t->GetPlayersGoalTiming());
//	((Team*)Teams[Pos])->SetPlayersGoalEvent(t->GetPlayersGoalEvent());
//	((Team*)Teams[Pos])->SetPlayersName(t->GetPlayersName());
}

Team* CWorldCupDoc::GetData(int n)
{
	return (Team*)Teams[n];
}

CString CWorldCupDoc::GetInfo()
{
	return info;
}

int CWorldCupDoc::GetPos()
{
	return Pos;
}

bool CWorldCupDoc::TeamAdd(Team *t)
{
	if(Teams.GetSize()==0){
		Teams.Add(t);
		Pos=0;
		return true;
		}
	else{
		int i=0;
		while(i<Teams.GetSize()){
			Team *te = GetData(i);


			if(te->GetTeamName()==t->GetTeamName()){
				if(te->GetRanking() == t->GetRanking())
					return true;
				else {
					((Team*)Teams[i])->SetRanking(t->GetRanking());
					return true;
				}
			}
			else if(te->GetRanking()==t->GetRanking()){
				if(te->GetTeamName() == t->GetTeamName())
					return true; 
				else {
					((Team*)Teams[i])->SetTeamName(t->GetTeamName());
					return true;
				}
			}





			i++;
		}
			Teams.Add(t);
			return true;
	}
}


bool CWorldCupDoc::TeamDelete(Team *t)
{
 if(Teams.GetSize()==0){
			return false;
		}

		if((((Team*)Teams[0])->GetRanking()==t->GetRanking())&&(((Team*)Teams[0])->GetTeamName()==t->GetTeamName())){//
			delete Teams[0];
			Teams.RemoveAt(0);
			Pos=0;//
			if(Teams.GetSize()==0)
				Pos=-1;
			return true;
		}

		int n=1;
		while(n<Teams.GetSize())
		{
			if((((Team*)Teams[n])->GetRanking()==t->GetRanking())&&(((Team*)Teams[n])->GetTeamName()==t->GetTeamName()))//
			{
				delete Teams[n];
				Teams.RemoveAt(n);
				Pos=0;//
				if(Teams.GetSize()==0)
					Pos=-1;
				return true;
			}
			n++;
		}
		return false;
}

void CWorldCupDoc::Next()
{
	if(Pos<(Teams.GetSize()-1)){
		Pos++;
	}
	else
		Pos=Pos;
}

BOOL CWorldCupDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return false;

	return true;
}

Team* CWorldCupDoc::ReturnCurrentData()
{
	if(Pos==-1)
		return NULL;
	else
		return (Team *)Teams[Pos];
}

void CWorldCupDoc::SetInfo(CString str)
{
	info=str;
}

void CWorldCupDoc::SetPos(int a)
{
	Pos=a;
}

int CWorldCupDoc::Size()
{
	return Teams.GetSize();
}


Team* CWorldCupDoc::GetTeam(CString t)
{	
	for(int i=0;i<Teams.GetSize();i++){
		if(((Team*)Teams[i])->GetTeamName() == t)
			return ((Team*)Teams[i]);
	}
	return NULL;
}
