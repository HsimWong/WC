// Elem.h: interface for the Elem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEM_H__34F5F4EC_68C2_4D1C_9B5B_8FDD01A1D7C3__INCLUDED_)
#define AFX_ELEM_H__34F5F4EC_68C2_4D1C_9B5B_8FDD01A1D7C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Elem : public CObject  
{ 
DECLARE_SERIAL(Elem)
public:
	void Serialize(CArchive & ar);
	int vertex;
	int weight1;
	int weight2;
	Elem();
	virtual ~Elem();

};

#endif // !defined(AFX_ELEM_H__34F5F4EC_68C2_4D1C_9B5B_8FDD01A1D7C3__INCLUDED_)
