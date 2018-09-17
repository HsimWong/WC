// LookMatch.cpp : implementation file
//

#include "stdafx.h"
#include "WorldCup.h"
#include "LookMatch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LookMatch dialog


LookMatch::LookMatch(CWnd* pParent /*=NULL*/)
	: CDialog(LookMatch::IDD, pParent)
{
	//{{AFX_DATA_INIT(LookMatch)
	m_team1 = _T("");
	m_team2 = _T("");
	//}}AFX_DATA_INIT
}


void LookMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LookMatch)
	DDX_Text(pDX, IDC_TEAM1, m_team1);
	DDX_Text(pDX, IDC_TEAM2, m_team2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LookMatch, CDialog)
	//{{AFX_MSG_MAP(LookMatch)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LookMatch message handlers
