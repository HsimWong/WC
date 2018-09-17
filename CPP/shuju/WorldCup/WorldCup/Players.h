// Players.h: interface for the Players class.
//
//////////////////////////////////////////////////////////////////////
#include"Score.h"

#if !defined(AFX_PLAYERS_H__B4484502_E51B_46F7_8EE1_28410C5FD46A__INCLUDED_)
#define AFX_PLAYERS_H__B4484502_E51B_46F7_8EE1_28410C5FD46A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Players : public CObject  
{
	DECLARE_SERIAL(Players)
public:
	Score* GetTiming(CString a);
	void SetAgainst(CString a);
	void SetTiming(CString t);
	CString Name;
	int Number;
	int Ranking;
	CString Team;
	CString Position;
//	CString Timing;
//	CString Event;
	int  s;
	Score *sc;
	void Serialize(CArchive & ar);
	Players();
	virtual ~Players();
	Players*  operator=(Players &p2);

};



#endif // !defined(AFX_PLAYERS_H__B4484502_E51B_46F7_8EE1_28410C5FD46A__INCLUDED_)
