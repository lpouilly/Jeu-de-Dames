// Case.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "JeuDeDames.h"
#include "Case.h"


// CCase

//IMPLEMENT_DYNAMIC(CCase, CWnd)


// CONSTRUCTEURS ---------------------------------------------------------

Case::Case(void)
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


// ACCESSEURS ---------------------------------------------------------

int Case::getEtat()
{
	return etat;
}

void Case::setEtat(int monEtat)
{
	etat = monEtat;
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

	/*case NOIR_OC_BLANC:		image.Load(_T("blanc.png"));
							break;

	case NOIR_OC_ROUGE:		image.Load(_T("blanc.png"));
							break;

	case NOIR_SEL:			image.Load(_T("blanc.png"));
							break;

	case NOIR_OC_BLANC_SEL:	image.Load(_T("blanc.png"));
							break;

	case NOIR_OC_ROUGE_SEL:	image.Load(_T("blanc.png"));
							break;*/
	}
	
	image.Draw(*pDC, x, y, LARGEUR_CASE, LARGEUR_CASE);
	image.Detach();
}

int Case::getColonne() 
{
	return colonne;
}

int Case::getLigne() 
{
	return ligne;
}






