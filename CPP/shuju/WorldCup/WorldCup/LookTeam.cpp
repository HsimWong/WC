// LookTeam.cpp : implementation file
//

#include "stdafx.h"
#include "WorldCup.h"
#include "LookTeam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LookTeam dialog


LookTeam::LookTeam(CWnd* pParent /*=NULL*/)
	: CDialog(LookTeam::IDD, pParent)
{
	//{{AFX_DATA_INIT(LookTeam)
	m_team = _T("");
	//}}AFX_DATA_INIT
}


void LookTeam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LookTeam)
	DDX_Text(pDX, IDC_LOOK_TEAM, m_team);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LookTeam, CDialog)
	//{{AFX_MSG_MAP(LookTeam)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LookTeam message handlers



