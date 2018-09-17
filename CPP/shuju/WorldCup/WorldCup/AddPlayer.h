#if !defined(AFX_ADDPLAYER_H__EC250191_5AF8_4A14_AB18_8D5F3929F001__INCLUDED_)
#define AFX_ADDPLAYER_H__EC250191_5AF8_4A14_AB18_8D5F3929F001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddPlayer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddPlayer dialog

class AddPlayer : public CDialog
{
// Construction
public:
	AddPlayer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddPlayer)
	enum { IDD = IDD_ADD_PLAYER };
	CString	m_position;
	CString	m_name;
	int		m_number;
	int		m_ranking;
	CString	m_team;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddPlayer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddPlayer)
	afx_msg void OnAddPlayer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDPLAYER_H__EC250191_5AF8_4A14_AB18_8D5F3929F001__INCLUDED_)
