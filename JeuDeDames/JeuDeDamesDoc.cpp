
// JeuDeDamesDoc.cpp : implémentation de la classe CJeuDeDamesDoc
//

#include "stdafx.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL et permettent la partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "JeuDeDames.h"
#endif

#include "JeuDeDamesDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CJeuDeDamesDoc

IMPLEMENT_DYNCREATE(CJeuDeDamesDoc, CDocument)

BEGIN_MESSAGE_MAP(CJeuDeDamesDoc, CDocument)
END_MESSAGE_MAP()


// construction ou destruction de CJeuDeDamesDoc

CJeuDeDamesDoc::CJeuDeDamesDoc()
{
	// TODO: ajoutez ici le code d'une construction unique

}

CJeuDeDamesDoc::~CJeuDeDamesDoc()
{
}

BOOL CJeuDeDamesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ajoutez ici le code de réinitialisation
	// (les documents SDI réutiliseront ce document)


	return TRUE;
}




// sérialisation de CJeuDeDamesDoc

void CJeuDeDamesDoc::Serialize(CArchive& ar)
{
	Plateau* plateau = ((CJeuDeDamesApp*) AfxGetApp())->getPlateau();
	int nbCases = ((CJeuDeDamesApp *)AfxGetApp( ))->getTaillePlateau();
	
	if (ar.IsStoring())
	{
		// TODO: ajoutez ici le code de stockage
		for (int i = 0; i < nbCases; i++) {
			for (int j = 0; j < nbCases; j++) 
			{
				plateau->getCaseDuTableau(i, j).Serialize(ar);
			}
		}
	}
	else
	{
		// TODO: ajoutez ici le code de chargement
		for (int i = 0; i < nbCases; i++) {
			for (int j = 0; j < nbCases; j++) 
			{
				plateau->getCaseDuTableau(i, j).Serialize(ar);
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// Prise en charge des miniatures
void CJeuDeDamesDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modifier ce code pour dessiner les données du document
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support pour les gestionnaires de recherche
void CJeuDeDamesDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Définir le contenu de recherche à partir des données du document. 
	// Les parties du contenu doivent être séparées par ";"

	// Par exemple :  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CJeuDeDamesDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// diagnostics pour CJeuDeDamesDoc

#ifdef _DEBUG
void CJeuDeDamesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJeuDeDamesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// commandes pour CJeuDeDamesDoc


void CJeuDeDamesDoc::DeleteContents()
{
	// TODO: ajoutez ici votre code spécialisé et/ou l'appel de la classe de base
	//Plateau* plateau = ((CJeuDeDamesApp*) AfxGetApp())->getPlateau();
	//plateau->initialiserPlateau6x6();

	CDocument::DeleteContents();
}

void CJeuDeDamesDoc::OnRepaintAllViews()
{
	UpdateAllViews(NULL);
}