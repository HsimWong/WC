// AddTeam.cpp : implementation file
//

#include "stdafx.h"
#include "WorldCup.h"
#include "AddTeam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddTeam dialog


AddTeam::AddTeam(CWnd* pParent /*=NULL*/)
	: CDialog(AddTeam::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddTeam)
	m_teamname = _T("");
	m_teamranking = 0;
	//}}AFX_DATA_INIT
}


void AddTeam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddTeam)
	DDX_Text(pDX, IDC_EDIT1, m_teamname);
	DDX_Text(pDX, IDC_EDIT2, m_teamranking);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddTeam, CDialog)
	//{{AFX_MSG_MAP(AddTeam)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddTeam message handlers
