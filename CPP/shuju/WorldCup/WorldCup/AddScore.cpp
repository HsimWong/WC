// AddScore.cpp : implementation file
//

#include "stdafx.h"
#include "WorldCup.h"
#include "AddScore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddScore dialog


AddScore::AddScore(CWnd* pParent /*=NULL*/)
	: CDialog(AddScore::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddScore)
	m_team = _T("");
	m_timing = _T("");
	m_player = _T("");
	m_against = _T("");
	m_number = 0;
	//}}AFX_DATA_INIT
}


void AddScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddScore)
	DDX_Text(pDX, IDC_TEAM, m_team);
	DDX_Text(pDX, IDC_TIMING, m_timing);
	DDX_Text(pDX, IDC_PLAYER, m_player);
	DDX_Text(pDX, IDC_AGAINST, m_against);
	DDX_Text(pDX, IDC_PLAYER2, m_number);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddScore, CDialog)
	//{{AFX_MSG_MAP(AddScore)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddScore message handlers
