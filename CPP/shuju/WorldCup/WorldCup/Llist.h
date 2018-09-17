// Llist.h: interface for the Llist class.
//
//////////////////////////////////////////////////////////////////////
#include"Elem.h"
#include"Link.h"
#if !defined(AFX_LLIST_H__62F4E2C9_A7F7_4430_B137_809D73613987__INCLUDED_)
#define AFX_LLIST_H__62F4E2C9_A7F7_4430_B137_809D73613987__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Llist : public CObject  
{
	DECLARE_SERIAL(Llist)
public:
	void Serialize(CArchive &ar);
	Link *head;//Õ∑÷∏’Î
	Llist();
	virtual ~Llist();

};

#endif // !defined(AFX_LLIST_H__62F4E2C9_A7F7_4430_B137_809D73613987__INCLUDED_)
