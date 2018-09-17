#if !defined(AFX_LOOKTEAM_H__43E8C562_A97D_4354_80AD_A28140B625A5__INCLUDED_)
#define AFX_LOOKTEAM_H__43E8C562_A97D_4354_80AD_A28140B625A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LookTeam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LookTeam dialog

class LookTeam : public CDialog
{
// Construction
public:
	LookTeam(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LookTeam)
	enum { IDD = IDD_LOOK_TEAM };
	CString	m_team;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LookTeam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LookTeam)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOOKTEAM_H__43E8C562_A97D_4354_80AD_A28140B625A5__INCLUDED_)
