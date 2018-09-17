#if !defined(AFX_LOOKMATCH_H__482E7245_C7E1_4F32_BA62_AD89341049DF__INCLUDED_)
#define AFX_LOOKMATCH_H__482E7245_C7E1_4F32_BA62_AD89341049DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LookMatch.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LookMatch dialog

class LookMatch : public CDialog
{
// Construction
public:
	LookMatch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LookMatch)
	enum { IDD = IDD_LOOK_MATCH };
	CString	m_team1;
	CString	m_team2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LookMatch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LookMatch)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOOKMATCH_H__482E7245_C7E1_4F32_BA62_AD89341049DF__INCLUDED_)
