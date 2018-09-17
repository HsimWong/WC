#if !defined(AFX_ADDMATCH_H__B328B6DF_E6FC_49D2_BD34_B18B0528D7BD__INCLUDED_)
#define AFX_ADDMATCH_H__B328B6DF_E6FC_49D2_BD34_B18B0528D7BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddMatch.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddMatch dialog

class AddMatch : public CDialog
{
// Construction
public:
	AddMatch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddMatch)
	enum { IDD = IDD_ADD_MATCH };
	CString	m_team1;
	CString	m_team2;
	int		m_weight1;
	int		m_weight2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddMatch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddMatch)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDMATCH_H__B328B6DF_E6FC_49D2_BD34_B18B0528D7BD__INCLUDED_)
