// JeuDeDamesView.cpp : implémentation de la classe CJeuDeDamesView
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include <string>
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL et permettent la partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "JeuDeDames.h"
#endif

#include "JeuDeDamesDoc.h"
#include "JeuDeDamesView.h"
#include "DlgMenu.h"
#include "Plateau.h"
#include "Clic.h"
#include "AlgoEtude.h"


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
	ON_WM_LBUTTONDOWN()
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

void CJeuDeDamesView::OnDraw(CDC* pDC)
{
	CJeuDeDamesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ajoutez ici le code de dessin pour les données natives
	
	Plateau* plateau = ((CJeuDeDamesApp *) AfxGetApp( ))->getPlateau();
	int taillePlateau = ((CJeuDeDamesApp *) AfxGetApp( ))->getTaillePlateau();

	plateau->dessinerPlateau(pDC, taillePlateau);

	int nbPionsBlanc = ((CJeuDeDamesApp *) AfxGetApp( ))->getNbPionsBlanc();
	int nbPionsRouge = ((CJeuDeDamesApp *) AfxGetApp( ))->getNbPionsRouge();

	CString chaineBlanc;
	chaineBlanc.Format(L"Blancs :     %d", nbPionsBlanc);
	CString chaineRouge;
	chaineRouge.Format(L"Rouges :    %d", nbPionsRouge);

	pDC->TextOutW(600, 80, L"- Pions restants -");
	pDC->TextOutW(615, 120, chaineBlanc);
	pDC->TextOutW(615, 150, chaineRouge);
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


void CJeuDeDamesView::OnLButtonDown(UINT nFlags, CPoint point)
{
	Clic* clic = new Clic;
	Case* caseCliquee = new Case;
	int ligne;
	int colonne;
	
	Plateau* plateau = ((CJeuDeDamesApp *)AfxGetApp( ))->getPlateau();

	ligne = clic->LigneDuClic(point);
	colonne = clic->ColonneDuClic(point);
	
	
	if((ligne!=-1)&&(colonne!=-1))
	{
		*caseCliquee = plateau->getCaseDuTableau(ligne,colonne);

		AlgoEtude* algoEtude = ((CJeuDeDamesApp *)AfxGetApp( ))->getAlgoEtude();
		algoEtude->appliquerAlgoEtude(*caseCliquee);

		CJeuDeDamesDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(NULL);
	}

	CView::OnLButtonDown(nFlags, point);
}
