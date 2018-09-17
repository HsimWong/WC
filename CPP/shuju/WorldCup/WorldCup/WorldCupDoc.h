// WorldCupDoc.h : interface of the CWorldCupDoc class
//
/////////////////////////////////////////////////////////////////////////////



#if !defined(AFX_WORLDCUPDOC_H__2A676ADD_F3F7_4F11_B562_3D9700F49D86__INCLUDED_)
#define AFX_WORLDCUPDOC_H__2A676ADD_F3F7_4F11_B562_3D9700F49D86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Graphl1.h"
#include "Team.h"


class CWorldCupDoc : public CDocument
{
protected: // create from serialization only
	CWorldCupDoc();
	DECLARE_DYNCREATE(CWorldCupDoc)

// Attributes
public:
	CString info;
	CObArray Teams;
    int Pos;
	bool nCount;
	Graphl *g;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorldCupDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	Team* GetTeam(CString t);
	bool TeamDelete(Team *t);
	int Size();
	void SetPos(int a);
	void SetInfo(CString a);
	Team * ReturnCurrentData();
	BOOL OnOpenDocument(LPCTSTR lpszPathName);
	void Next();
	bool TeamAdd(Team * t);
	int GetPos();
	CString GetInfo();
	Team * GetData(int n);
	void EditCurrentData(Team *t);
	void DeleteContents();
	void DeleteAll();
	void Before();
	virtual ~CWorldCupDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWorldCupDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORLDCUPDOC_H__2A676ADD_F3F7_4F11_B562_3D9700F49D86__INCLUDED_)
