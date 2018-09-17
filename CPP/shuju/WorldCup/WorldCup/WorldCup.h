// WorldCup.h : main header file for the WORLDCUP application
//

#if !defined(AFX_WORLDCUP_H__D6BD1024_A232_4CAB_94B1_1FF64E2CB126__INCLUDED_)
#define AFX_WORLDCUP_H__D6BD1024_A232_4CAB_94B1_1FF64E2CB126__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWorldCupApp:
// See WorldCup.cpp for the implementation of this class
//

class CWorldCupApp : public CWinApp
{
public:
	CWorldCupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorldCupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWorldCupApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORLDCUP_H__D6BD1024_A232_4CAB_94B1_1FF64E2CB126__INCLUDED_)
