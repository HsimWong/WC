// Score.h: interface for the Score class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCORE_H__0EC8FACB_EDD0_4410_9BF2_15FB2BD50EC8__INCLUDED_)
#define AFX_SCORE_H__0EC8FACB_EDD0_4410_9BF2_15FB2BD50EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Score : public CObject  
{DECLARE_SERIAL(Score)
public:
	void Serialize(CArchive &ar);
	CString Timing;
	CString Event;
	CString Against;
	Score *next;
	Score();
	virtual ~Score();

};

#endif // !defined(AFX_SCORE_H__0EC8FACB_EDD0_4410_9BF2_15FB2BD50EC8__INCLUDED_)
