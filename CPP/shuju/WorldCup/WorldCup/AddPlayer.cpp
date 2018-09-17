// AddPlayer.cpp : implementation file
//

#include "stdafx.h"
#include "WorldCup.h"
#include "AddPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddPlayer dialog


AddPlayer::AddPlayer(CWnd* pParent /*=NULL*/)
	: CDialog(AddPlayer::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddPlayer)
	m_position = _T("");
	m_name = _T("");
	m_number = 0;
	m_ranking = 0;
	m_team = _T("");
	//}}AFX_DATA_INIT
}


void AddPlayer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddPlayer)
	DDX_Text(pDX, IDC_POSITION, m_position);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_NUMBER, m_number);
	DDX_Text(pDX, IDC_RANKING, m_ranking);
	DDX_Text(pDX, IDC_TEAM, m_team);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddPlayer, CDialog)
	//{{AFX_MSG_MAP(AddPlayer)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddPlayer message handlers
