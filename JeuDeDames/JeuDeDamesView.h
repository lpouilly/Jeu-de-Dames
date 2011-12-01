
// JeuDeDamesView.h : interface de la classe CJeuDeDamesView
//

#pragma once


class CJeuDeDamesView : public CView
{
protected: // création à partir de la sérialisation uniquement
	CJeuDeDamesView();
	DECLARE_DYNCREATE(CJeuDeDamesView)

// Attributs
public:
	CJeuDeDamesDoc* GetDocument() const;

// Opérations
public:
	void creerPlateau(CDC* pDC);

// Substitutions
public:
	virtual void OnDraw(CDC* pDC);  // substitué pour dessiner cette vue
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implémentation
public:
	virtual ~CJeuDeDamesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // version debug dans JeuDeDamesView.cpp
inline CJeuDeDamesDoc* CJeuDeDamesView::GetDocument() const
   { return reinterpret_cast<CJeuDeDamesDoc*>(m_pDocument); }
#endif

