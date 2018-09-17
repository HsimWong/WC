// Team.h: interface for the Team class.
//
//////////////////////////////////////////////////////////////////////
#include "Players.h"
#if !defined(AFX_TEAM_H__76CF55A8_3D54_4F61_9257_C8C24167381B__INCLUDED_)
#define AFX_TEAM_H__76CF55A8_3D54_4F61_9257_C8C24167381B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Team : public CObject  
{
DECLARE_SERIAL(Team)

public:

	
	int vertex;
	int weight1,weight2;
	CString TeamName;
	Players  p[23];
	int Ranking;
	Team();
	~Team();
	int GetVertex();
	void SetVertex(int v);
	Team*  operator =(Team &t);
    void Serialize(CArchive & ar);
    void SetTeamName(CString sName)      {	TeamName=sName;	}
    void SetRanking(int ranking)   {	Ranking=ranking;	}
    void SetPlayersName(CString pName,int n)      {	p[n].Name=pName;	}
	void SetPlayersNumber(int pNumber,int n)      {	p[n].Number=pNumber;	}
	void SetPlayersRanking(int pRanking,int n)      {	p[n].Ranking=pRanking;	}
	void SetPlayersTeam(CString pTeam,int n)      {	p[n].Team=pTeam;	}
	void SetPlayersPosition(CString pPosition,int n)      {	p[n].Position=pPosition;	}
	void SetPlayersGoalTiming( CString timing,int n)      {	 p[n].SetTiming(timing);	}
	void SetPlayersGoalAgainst( CString against,int n)      {	p[n].SetAgainst(against);	}
    CString GetTeamName( )      {	return TeamName;	}
   // Players  GetPlayers( int n)	          {	return p[n];	}
    int GetRanking( )   {		return Ranking;	}
    CString GetPlayersName(int n)      {		return p[n].Name;	}
	int GetPlayersNumber( int n)      {		return p[n].Number;	}
	int GetPlayersRanking( int n)      {		return p[n].Ranking;	}
	CString GetPlayersTeam(int n)      {		return p[n].Team;	}
	CString GetPlayersPosition(int n)      {		return p[n].Position;	}
	CString GetPlayersGoalTiming( CString t,int n)      {		return p[n].GetTiming(t)->Timing;	}
//	CString GetPlayersGoalEvent( int n)      {	 /*	returnp[n].Event;*/	}

};

#endif // !defined(AFX_TEAM_H__76CF55A8_3D54_4F61_9257_C8C24167381B__INCLUDED_)
