// Plateau.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "JeuDeDames.h"
#include "Plateau.h"

// CONSTRUCTEURS ---------------------------------------------------------

Plateau::Plateau(void)
{
	for (int k = 0; k < 2; k++) {
		for (int l = 0; l < 2; l++)
		{
			tableauDeCases[2*k][2*l] = Case(BLANC, 2*k, 2*l);
			//(tableauDeCases[2*k][2*l]).setEtat(BLANC);
		}
	}
	for (int m = 0; m < 2; m++) {
		for (int n = 0; n < 2; n++)
		{
			tableauDeCases[2*m+1][2*n+1] = Case(BLANC, 2*m+1, 2*n+1);
			//(tableauDeCases[2*k+1][2*l+1]).setEtat(NOIR);
		}
	}
	for (int k = 0; k < 2; k++) {
		for (int l = 0; l < 2; l++)
		{
			tableauDeCases[2*k+1][2*l] = Case(NOIR, 2*k+1, 2*l);
			//(tableauDeCases[2*k][2*l]).setEtat(BLANC);
		}
	}
	for (int m = 0; m < 2; m++) {
		for (int n = 0; n < 2; n++)
		{
			tableauDeCases[2*m][2*n+1] = Case(NOIR, 2*m, 2*n+1);
			//(tableauDeCases[2*k+1][2*l+1]).setEtat(NOIR);
		}
	}
}

Plateau::~Plateau(void)
{
}

// ACCESSEURS ---------------------------------------------------------
int Plateau::getNbCases()
{
	return nbCases;
}

// UTILISATEUR ---------------------------------------------------------
void Plateau::dessinerPlateau(CDC* pDC)
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
		{
			tableauDeCases[i][j].dessinerCase(pDC);
		}
	}
}

Case Plateau::getCaseDuTableau(int ligne, int colonne)
{
	return tableauDeCases[ligne][colonne];
}

void Plateau::setTableauCases(Case unecase, int ligne, int colonne)
{
	tableauDeCases[ligne][colonne] = unecase;
}