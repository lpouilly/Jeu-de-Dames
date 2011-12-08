// Case.cpp : fichier d'implémentation
//

#include <afxtempl.h>
#include "stdafx.h"
#include "JeuDeDames.h"
#include "Case.h"

IMPLEMENT_SERIAL(Case, CObject, 1)

// CONSTRUCTEURS / DESTRUCTEURS ----------------------------------------

Case::Case()
{
}

Case::Case(int monEtat, int maLigne, int maColonne)
{
	etat = monEtat;
	ligne = maLigne;
	colonne = maColonne;
}

Case::~Case(void)
{
}

Case::Case(const Case &rCase)
{
	CopyFrom(rCase);
}

const Case& Case::operator=(const Case& Src)
{
	CopyFrom(Src);
	return *this;
}

void Case::CopyFrom(const Case & Src )
{
	if(this == &Src) return;

	etat = Src.etat;
	ligne = Src.ligne;
	colonne = Src.colonne;
	//m_strVille  =Src.m_strVille;
}

// ACCESSEURS ---------------------------------------------------------

int Case::getEtat()
{
	return etat;
}

int Case::getLigne()
{
	return ligne;
}

int Case::getColonne()
{
	return colonne;
}

void Case::setEtat(int monEtat)
{
	etat = monEtat;
}

void Case::setLigne( int maLigne )
{
	ligne = maLigne;
}

void Case::setColonne( int maColonne )
{
	colonne = maColonne;
}

// UTILISATEUR ---------------------------------------------------------

void Case::dessinerCase(CDC* pDC)
{
	int x = 80 + 50 * colonne;
	int y = 80 + 50 * ligne;
	
	switch (etat)
	{
	case BLANC:				image.Load(L"../Images/blanc.png");
							break;

	case NOIR:				image.Load(L"../Images/noir.png");
							break;

	case NOIR_OC_BLANC:		image.Load(L"../Images/noir_oc_blanc.png");
							break;

	case NOIR_OC_ROUGE:		image.Load(L"../Images/noir_oc_rouge.png");
							break;

	case NOIR_SEL:			image.Load(L"../Images/noir_sel.png");
							break;

	case NOIR_OC_BLANC_SEL:	image.Load(L"../Images/noir_oc_blanc_sel.png");
							break;

	case NOIR_OC_ROUGE_SEL:	image.Load(L"../Images/noir_oc_rouge_sel.png");
							break;
	}
		
	image.Draw(*pDC, x, y, LARGEUR_CASE, LARGEUR_CASE);
	image.Detach();
}

void Case::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << ligne << colonne << etat;
	}
	else
	{
		ar >> ligne >> colonne >> etat;
	}
}



