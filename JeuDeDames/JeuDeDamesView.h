
// JeuDeDamesView.h : interface de la classe CJeuDeDamesView
//

#pragma once


class CJeuDeDamesView : public CView
{
protected: // cr�ation � partir de la s�rialisation uniquement
	CJeuDeDamesView();
	DECLARE_DYNCREATE(CJeuDeDamesView)

// Attributs
public:
	CJeuDeDamesDoc* GetDocument() const;

// Op�rations

// Substitutions
public:
	virtual void OnDraw(CDC* pDC);  // substitu� pour dessiner cette vue
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);


// Impl�mentation
public:
	virtual ~CJeuDeDamesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions g�n�r�es de la table des messages
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // version debug dans JeuDeDamesView.cpp
inline CJeuDeDamesDoc* CJeuDeDamesView::GetDocument() const
   { return reinterpret_cast<CJeuDeDamesDoc*>(m_pDocument); }
#endif

