#if !defined(AFX_ADDSCORE_H__5B77F650_F073_4727_9381_037689596935__INCLUDED_)
#define AFX_ADDSCORE_H__5B77F650_F073_4727_9381_037689596935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddScore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddScore dialog

class AddScore : public CDialog
{
// Construction
public:
	AddScore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddScore)
	enum { IDD = IDD_ADD_SCORE };
	CString	m_team;
	CString	m_timing;
	CString	m_player;
	CString	m_against;
	int		m_number;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddScore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddScore)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSCORE_H__5B77F650_F073_4727_9381_037689596935__INCLUDED_)
