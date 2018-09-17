#if !defined(AFX_ADDTEAM_H__D7F11BEF_3895_4484_BE95_8E7352C1793F__INCLUDED_)
#define AFX_ADDTEAM_H__D7F11BEF_3895_4484_BE95_8E7352C1793F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddTeam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddTeam dialog

class AddTeam : public CDialog
{
// Construction
public:
	AddTeam(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddTeam)
	enum { IDD = IDD_ADD_TEAM };
	CString	m_teamname;
	int		m_teamranking;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddTeam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddTeam)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDTEAM_H__D7F11BEF_3895_4484_BE95_8E7352C1793F__INCLUDED_)
