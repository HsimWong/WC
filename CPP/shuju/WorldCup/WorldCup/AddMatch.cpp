// AddMatch.cpp : implementation file
//

#include "stdafx.h"
#include "WorldCup.h"
#include "AddMatch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddMatch dialog


AddMatch::AddMatch(CWnd* pParent /*=NULL*/)
	: CDialog(AddMatch::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddMatch)
	m_team1 = _T("");
	m_team2 = _T("");
	m_weight1 = 0;
	m_weight2 = 0;
	//}}AFX_DATA_INIT
}


void AddMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddMatch)
	DDX_Text(pDX, IDC_TEAM1, m_team1);
	DDX_Text(pDX, IDC_TEAM2, m_team2);
	DDX_Text(pDX, IDC_WEIGHT1, m_weight1);
	DDX_Text(pDX, IDC_WEIGHT2, m_weight2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddMatch, CDialog)
	//{{AFX_MSG_MAP(AddMatch)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddMatch message handlers
