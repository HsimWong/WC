// WorldCupView.h : interface of the CWorldCupView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORLDCUPVIEW_H__8CA181E0_DAA2_481F_8F26_34542B7F62A9__INCLUDED_)
#define AFX_WORLDCUPVIEW_H__8CA181E0_DAA2_481F_8F26_34542B7F62A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWorldCupView : public CView
{
protected: // create from serialization only
	CWorldCupView();
	DECLARE_DYNCREATE(CWorldCupView)

// Attributes
public:
	CWorldCupDoc* GetDocument();

// Operations
public:
	Team* tea;
	Team* t1;
	Team* t2;
	bool team;
	bool teaminformation;
	bool match;
	int weight1;
	int weight2;
	CString team1;
	CString team2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorldCupView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWorldCupView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWorldCupView)
	afx_msg void OnAddTeam();
	afx_msg void OnLookTeam();
	afx_msg void OnAddPlayer();
	afx_msg void OnLookTeamInformation();
	afx_msg void OnAddMatch();
	afx_msg void OnLookMatch();
	afx_msg void OnAddScore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WorldCupView.cpp
inline CWorldCupDoc* CWorldCupView::GetDocument()
   { return (CWorldCupDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORLDCUPVIEW_H__8CA181E0_DAA2_481F_8F26_34542B7F62A9__INCLUDED_)
