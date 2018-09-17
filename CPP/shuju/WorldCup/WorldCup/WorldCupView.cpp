// WorldCupView.cpp : implementation of the CWorldCupView class
//

#include "stdafx.h"
#include "WorldCup.h"
#include"AddTeam.h"
#include"AddPlayer.h"
#include"LookTeam.h"
#include"LookMatch.h"
#include"AddMatch.h"
#include"AddScore.h"

#include "WorldCupDoc.h"
#include "WorldCupView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorldCupView

IMPLEMENT_DYNCREATE(CWorldCupView, CView)

BEGIN_MESSAGE_MAP(CWorldCupView, CView)
	//{{AFX_MSG_MAP(CWorldCupView)
	ON_COMMAND(ID_MENUTEAM, OnAddTeam)
	ON_COMMAND(ID_LOOK, OnLookTeam)
	ON_COMMAND(ID_MENUPLAYER, OnAddPlayer)
	ON_COMMAND(ID_MENUTEAMINFORMATION, OnLookTeamInformation)
	ON_COMMAND(ID_MENUMATCH, OnAddMatch)
	ON_COMMAND(ID_MENULOOKMATCH, OnLookMatch)
	ON_COMMAND(ID_MENUSCORE, OnAddScore)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorldCupView construction/destruction

int l = 1;

CWorldCupView::CWorldCupView()
{
	team = false;
	teaminformation = false;
	match = false;

}

CWorldCupView::~CWorldCupView()
{
}

BOOL CWorldCupView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWorldCupView drawing

void CWorldCupView::OnDraw(CDC* pDC)
{

	Team * te;
	CString  ran,num,w1,w2,number;
	CWorldCupDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

//	pDC->TextOut(20,20,shiyan);

	int n = pDoc->Size();
	int i=0,k=0,h1=60,h2=60,h3=60,h4=60,h5=60,h6=80;
	if(team){
		pDC->TextOut(20,20,"32强排行榜：");
		pDC->TextOut(20,40,"队伍：");
		pDC->TextOut(120,40,"排名：");
		while(i<n){
			te= pDoc->GetData(i);
			if(i<28){
				pDC->TextOut(20,h1,te->GetTeamName());
				ran.Format("%d",te->GetRanking());
				pDC->TextOut(120,h1,ran);
					h1+=20;
			}
			else {
					pDC->TextOut(220,40,"队伍：");
					pDC->TextOut(320,40,"排名：");
					pDC->TextOut(220,h2,te->GetTeamName());
					ran.Format("%d",te->GetRanking());
					pDC->TextOut(320,h2,ran);
						h2+=20;

			}
			i++;
		
		}
	}
	
	if(teaminformation){
		pDC->TextOut(70,20,tea->GetTeamName());
		pDC->TextOut(150,20,"队名单");
		pDC->TextOut(20,40,"号码");
		pDC->TextOut(120,40,"姓名");
		pDC->TextOut(220,40,"位置");
		while(tea->GetPlayersNumber(k) != 0){
			num.Format("%d",tea->GetPlayersNumber(k));
			pDC->TextOut(20,h3,num);
			pDC->TextOut(120,h4,tea->GetPlayersName(k));
			pDC->TextOut(220,h5,tea->GetPlayersPosition(k));
				k++;
				h3+=20;
				h4+=20;
				h5+=20;
		}
	}
	

	if(match){
		pDC->TextOut(70,20,"对阵信息");
		pDC->TextOut(20,40,team1);
		pDC->TextOut(120,40,team2);
		w1.Format("%d",weight1);
		w2.Format("%d",weight2);
		pDC->TextOut(20,60,w1);
		pDC->TextOut(120,60,w2);
		for(int i=0;i<23;i++){
			if(t1->p[i].GetTiming(t2->GetTeamName())->Against == team2){
				pDC->TextOut(20,h6,t1->GetTeamName() );
				pDC->TextOut(65,h6,"队" );
				number.Format("%d",(t1->GetPlayersNumber(i)));
				pDC->TextOut(80,h6,number);
				pDC->TextOut(95,h6,"号");
				pDC->TextOut(110,h6,t1->GetPlayersName(i) );
				pDC->TextOut(150,h6,":" );
				pDC->TextOut(160,h6,t1->GetPlayersGoalTiming(team2,i) );
				pDC->TextOut(220,h6,"进球;");
				h6+=20;
			}
		}
			for(int j=0;j<23;j++){
			if(t2->p[j].GetTiming(t1->GetTeamName())->Against == team1){
				pDC->TextOut(20,h6,t2->GetTeamName() );
				pDC->TextOut(65,h6,"队" );
				number.Format("%d",(t2->GetPlayersNumber(j)));
				pDC->TextOut(80,h6,number);
				pDC->TextOut(95,h6,"号");
				pDC->TextOut(110,h6,t2->GetPlayersName(j) );
				pDC->TextOut(150,h6,":" );
				pDC->TextOut(160,h6,t2->GetPlayersGoalTiming(team1,j) );
				pDC->TextOut(220,h6,"进球;");
				h6+=20;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWorldCupView printing

BOOL CWorldCupView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWorldCupView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWorldCupView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWorldCupView diagnostics

#ifdef _DEBUG
void CWorldCupView::AssertValid() const
{
	CView::AssertValid();
}

void CWorldCupView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorldCupDoc* CWorldCupView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorldCupDoc)));
	return (CWorldCupDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorldCupView message handlers

void CWorldCupView::OnAddTeam() 
{
	Invalidate( );//视窗重画
	AddTeam aboutDlg;
	bool i;

    CWorldCupDoc* pDoc = GetDocument();//***********************8
	
    if(aboutDlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		Team *t=new Team();
		t->SetTeamName(aboutDlg.m_teamname);
		t->SetRanking(aboutDlg.m_teamranking);
		t->SetVertex(aboutDlg.m_teamranking);
		i=pDoc->TeamAdd(t);
	}
	else
	{
	}
	if(i==true){
		AfxMessageBox("添加成功");	
	}
}

void CWorldCupView::OnLookTeam() 
{
	
	Invalidate( );//视窗重画
	team=true;
	teaminformation=false;
	match = false;
	Invalidate( );//视窗重画
}

void CWorldCupView::OnAddPlayer() 
{
	Invalidate( );//视窗重画
	AddPlayer aboutDlg;
	bool i;
	int n;

    CWorldCupDoc* pDoc = GetDocument();//***********************8
	
    if(aboutDlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		n=aboutDlg.m_number-1;
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersTeam(aboutDlg.m_team,n);
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersNumber(aboutDlg.m_number,n);
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersName(aboutDlg.m_name,n);
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersRanking(aboutDlg.m_ranking,n);
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersPosition(aboutDlg.m_position,n);
		i=true;
	}
	else
	{
	}
	if(i==true){
		AfxMessageBox("添加成功");	
	}
	
}









void CWorldCupView::OnLookTeamInformation() 
{
	Invalidate( );//视窗重画
	LookTeam aboutDlg;
	bool i;
	teaminformation=false;

    CWorldCupDoc* pDoc = GetDocument();//***********************8
	
    if(aboutDlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		tea = pDoc->GetTeam(aboutDlg.m_team);
		i=true;

	}
	else
	{
	}
	if(i==true){
		teaminformation=true;
		team=false;
		match = false;
		Invalidate( );//视窗重画
	}
}

void CWorldCupView::OnAddMatch() 
{
	
	Invalidate( );//视窗重画
	AddMatch aboutDlg;
	match = false;
	
	CWorldCupDoc* pDoc = GetDocument();//***********************8
	 if(aboutDlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		t1 = pDoc->GetTeam(aboutDlg.m_team1);
		t2 = pDoc->GetTeam(aboutDlg.m_team2);
		pDoc->g->setEdge(t1->vertex,t2->vertex,aboutDlg.m_weight1,aboutDlg.m_weight2);
		CString m;
		m.Format("%d",pDoc->g->FirstEdge(t1->vertex).weight1);
		CDC *pDC=GetDC();
		pDC->TextOut(0,0,m);

		match = true;
		teaminformation=false;
		team=false;

	}
	else
	{
	}

}

void CWorldCupView::OnLookMatch() 
{
	match = false;
	Invalidate( );//视窗重画
	LookMatch aboutDlg;
	CWorldCupDoc* pDoc = GetDocument();//***********************
		
	 if(aboutDlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		team1 = aboutDlg.m_team1;
		team2 = aboutDlg.m_team2;
		t1 = pDoc->GetTeam(aboutDlg.m_team1);
		t2 = pDoc->GetTeam(aboutDlg.m_team2);
		weight1 = pDoc->g->GetEdge(t1->vertex,t2->vertex).weight1;
		weight2 = pDoc->g->GetEdge(t1->vertex,t2->vertex).weight2;
	
		match = true;
		team = false;
		teaminformation = false;
	}
	else
	{
	}
	Invalidate( );//视窗重画
}

void CWorldCupView::OnAddScore() 
{
	Invalidate( );//视窗重画
	AddScore aboutDlg;
	bool i;
	int n;

    CWorldCupDoc* pDoc = GetDocument();//***********************8
	
    if(aboutDlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		n=aboutDlg.m_number-1;
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersGoalTiming(aboutDlg.m_timing,n);
		pDoc->GetTeam(aboutDlg.m_team)->SetPlayersGoalAgainst(aboutDlg.m_against,n);
		i=true;
	}
	else
	{
	}
	if(i==true){
		AfxMessageBox("添加成功");	
	}
	
}
