// Plateau.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "JeuDeDames.h"
#include "Plateau.h"

IMPLEMENT_SERIAL(Plateau, CObject, 1)

// CONSTRUCTEURS / DESTRUCTEUR -----------------------------------------
Plateau::Plateau(void)
{
	
}

Plateau::Plateau(int taille_plateau)
{
	switch (taille_plateau)
	{
	case 4:		initialiserPlateau4x4();
				break;
	case 6:		initialiserPlateau6x6();
				break;
	case 8:		initialiserPlateau8x8();
				break;
	case 10:	initialiserPlateau10x10();
				break;
	}
}

Plateau::~Plateau(void)
{
}

// ACCESSEURS ---------------------------------------------------------
Case Plateau::getCaseDuTableau(int i, int j)
{
	return tableauDeCases[i][j];
}

void Plateau::setCaseDuTableau (int i, int j, int newEtat)
{
	tableauDeCases[i][j].setEtat(newEtat);
}

// UTILISATEUR ---------------------------------------------------------
void Plateau::dessinerPlateau(CDC* pDC, int taillePlateau)
{
	for (int i = 0; i < taillePlateau; i++){
		for (int j = 0; j < taillePlateau; j++)
		{
			tableauDeCases[i][j].dessinerCase(pDC);
		}
	}
}

// INITIALISATION ------------------------------------------------------
void Plateau::initialiserPlateau4x4()
{
	// CASES BLANCHES
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
		{
			tableauDeCases[2*i][2*j] = Case(BLANC, 2*i, 2*j);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
		{
			tableauDeCases[2*i+1][2*j+1] = Case(BLANC, 2*i+1, 2*j+1);
		}
	}

	// CASES NOIRES
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
		{
			tableauDeCases[2*i+1][2*j] = Case(NOIR, 2*i+1, 2*j);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
		{
			tableauDeCases[2*i][2*j+1] = Case(NOIR, 2*i, 2*j+1);
		}
	}

	// CASES OCCUPEES BLANCHES
	tableauDeCases[0][1] = Case(NOIR_OC_ROUGE, 0, 1);
	tableauDeCases[0][3] = Case(NOIR_OC_ROUGE, 0, 3);

	// CASES OCCUPEES ROUGES
	tableauDeCases[3][0] = Case(NOIR_OC_BLANC, 3, 0);
	tableauDeCases[3][2] = Case(NOIR_OC_BLANC, 3, 2);
}

void Plateau::initialiserPlateau6x6 ()
{
	// CASES BLANCHES
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			tableauDeCases[2*i][2*j] = Case(BLANC, 2*i, 2*j);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			tableauDeCases[2*i+1][2*j+1] = Case(BLANC, 2*i+1, 2*j+1);
		}
	}

	// CASES NOIRES
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			tableauDeCases[2*i+1][2*j] = Case(NOIR, 2*i+1, 2*j);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			tableauDeCases[2*i][2*j+1] = Case(NOIR, 2*i, 2*j+1);
		}
	}

	// CASES OCCUPEES BLANCHES
	for (int j= 0; j < 3; j++) {
		tableauDeCases[0][2*j+1].setEtat(NOIR_OC_ROUGE);
	}
	for (int j= 0; j < 3; j++) {
		tableauDeCases[1][2*j].setEtat(NOIR_OC_ROUGE);
	}

	// CASES OCCUPEES ROUGES
	for (int j= 0; j < 3; j++) {
		tableauDeCases[4][2*j+1].setEtat(NOIR_OC_BLANC);
	}
	for (int j= 0; j < 3; j++) {
		tableauDeCases[5][2*j].setEtat(NOIR_OC_BLANC);
	}
}

void Plateau::initialiserPlateau8x8 ()
{
	
	// CASES BLANCHES
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			tableauDeCases[2*i][2*j] = Case(BLANC, 2*i, 2*j);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			tableauDeCases[2*i+1][2*j+1] = Case(BLANC, 2*i+1, 2*j+1);
		}
	}

	// CASES NOIRES
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			tableauDeCases[2*i+1][2*j] = Case(NOIR, 2*i+1, 2*j);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			tableauDeCases[2*i][2*j+1] = Case(NOIR, 2*i, 2*j+1);
		}
	}

	// CASES OCCUPEES BLANCHES
	for (int j= 0; j < 4; j++) {
		tableauDeCases[0][2*j+1].setEtat(NOIR_OC_ROUGE);
		tableauDeCases[2][2*j+1].setEtat(NOIR_OC_ROUGE);
	}
	for (int j= 0; j < 4; j++) {
		tableauDeCases[1][2*j].setEtat(NOIR_OC_ROUGE);
	}

	// CASES OCCUPEES ROUGES
	for (int j= 0; j < 4; j++) {
		tableauDeCases[5][2*j].setEtat(NOIR_OC_BLANC);
		tableauDeCases[7][2*j].setEtat(NOIR_OC_BLANC);
	}
	for (int j= 0; j < 4; j++) {
		tableauDeCases[6][2*j+1].setEtat(NOIR_OC_BLANC);
	}
	
}

void Plateau::initialiserPlateau10x10 ()
{
	// CASES BLANCHES
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			tableauDeCases[2*i][2*j] = Case(BLANC, 2*i, 2*j);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			tableauDeCases[2*i+1][2*j+1] = Case(BLANC, 2*i+1, 2*j+1);
		}
	}

	// CASES NOIRES
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			tableauDeCases[2*i+1][2*j] = Case(NOIR, 2*i+1, 2*j);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			tableauDeCases[2*i][2*j+1] = Case(NOIR, 2*i, 2*j+1);
		}
	}

	// CASES OCCUPEES BLANCHES
	for (int j= 0; j < 5; j++) {
		tableauDeCases[0][2*j+1].setEtat(NOIR_OC_ROUGE);
		tableauDeCases[2][2*j+1].setEtat(NOIR_OC_ROUGE);
	}
	for (int j= 0; j < 5; j++) {
		tableauDeCases[1][2*j].setEtat(NOIR_OC_ROUGE);
		tableauDeCases[3][2*j].setEtat(NOIR_OC_ROUGE);
	}

	// CASES OCCUPEES ROUGES
	for (int j= 0; j < 5; j++) {
		tableauDeCases[7][2*j].setEtat(NOIR_OC_BLANC);
		tableauDeCases[9][2*j].setEtat(NOIR_OC_BLANC);
	}
	for (int j= 0; j < 5; j++) {
		tableauDeCases[6][2*j+1].setEtat(NOIR_OC_BLANC);
		tableauDeCases[8][2*j+1].setEtat(NOIR_OC_BLANC);
	}
}

void Plateau::Serialize(CArchive& ar)
{    
	if (ar.IsStoring())
	{
		CJeuDeDamesApp* app = ((CJeuDeDamesApp* ) AfxGetApp());

		ar << app->getJoueurEnCours();
		ar << app->getNbPionsBlanc();
		ar << app->getNbPionsRouge();

		for(int i = 0; i < app->getTaillePlateau(); i++) {
			for(int j = 0; j < app->getTaillePlateau(); j++)
			{   		 
				ar << tableauDeCases[i][j].getEtat();
			}
		}
	}

	else
	{
		CJeuDeDamesApp* app = ((CJeuDeDamesApp* ) AfxGetApp());

		int joueur;
		ar >> joueur;
		app->setJoueurEnCours(joueur);

		int pionsBlanc;
		ar >> pionsBlanc;
		app->setNbPionsBlanc(pionsBlanc);

		int pionsRouge;
		ar >> pionsRouge;
		app->setNbPionsRouge(pionsRouge);

		int etat = 0;

		for(int i = 0; i < app->getTaillePlateau(); i++) {
			for(int j = 0; j < app->getTaillePlateau(); j++)
			{   			 
				ar >> etat;

				tableauDeCases[i][j] = Case (etat, i, j);   			 
			}
		}
	}
}