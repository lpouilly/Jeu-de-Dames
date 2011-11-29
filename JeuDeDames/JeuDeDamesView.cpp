// JeuDeDamesView.cpp : implémentation de la classe CJeuDeDamesView
//

#include "stdafx.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL et permettent la partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "JeuDeDames.h"
#endif

#include "JeuDeDamesDoc.h"
#include "JeuDeDamesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJeuDeDamesView

IMPLEMENT_DYNCREATE(CJeuDeDamesView, CView)

BEGIN_MESSAGE_MAP(CJeuDeDamesView, CView)
	// Commandes d'impression standard
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// construction ou destruction de CJeuDeDamesView

CJeuDeDamesView::CJeuDeDamesView()
{
	// TODO: ajoutez ici du code de construction

}

CJeuDeDamesView::~CJeuDeDamesView()
{
}

BOOL CJeuDeDamesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// dessin de CJeuDeDamesView

void dessinerPlateau(CDC* pDC, int nb, int taille) 
{
	
	for (int j=1;j<=nb;j++)
	{
		for(int i=1;i<=nb;i++)
		{
			pDC->Rectangle(taille*i,taille*j,taille*(i+1),taille*(j+1)); 
		}
	}
}

void CJeuDeDamesView::OnDraw(CDC* pDC)
{
	int nbrCases = 4; // nombre de cases du plateau par coté 
	int tailleCases = 80; // taille des cases du plateau

	CJeuDeDamesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ajoutez ici le code de dessin pour les données natives
	dessinerPlateau(pDC, nbrCases, tailleCases);
}


// impression de CJeuDeDamesView

BOOL CJeuDeDamesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// préparation par défaut
	return DoPreparePrinting(pInfo);
}

void CJeuDeDamesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez une initialisation supplémentaire avant l'impression
}

void CJeuDeDamesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez un nettoyage après l'impression
}


// diagnostics pour CJeuDeDamesView

#ifdef _DEBUG
void CJeuDeDamesView::AssertValid() const
{
	CView::AssertValid();
}

void CJeuDeDamesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJeuDeDamesDoc* CJeuDeDamesView::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJeuDeDamesDoc)));
	return (CJeuDeDamesDoc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages pour CJeuDeDamesView
