// Link.h: interface for the Link class.
//
//////////////////////////////////////////////////////////////////////
#include"Elem.h"


#if !defined(AFX_LINK_H__87B8D34B_2B33_4CCB_8321_E25F4EAF4B6B__INCLUDED_)
#define AFX_LINK_H__87B8D34B_2B33_4CCB_8321_E25F4EAF4B6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Link : public CObject  
{
	DECLARE_SERIAL(Link)
public:
	void Serialize(CArchive &ar);
	Link(Link * nextval = NULL);
	Link( Elem & elemval,Link * nextval = NULL);
	Elem element;//表目数据
	Link *next;//指向下一个链表元素的指针

	virtual ~Link();

};

#endif // !defined(AFX_LINK_H__87B8D34B_2B33_4CCB_8321_E25F4EAF4B6B__INCLUDED_)
