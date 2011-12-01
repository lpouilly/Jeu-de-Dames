#pragma once 

#include "Case.h"

#define TAILLE 200

class Plateau
{
private:
	int nbCases;
	Case tableauDeCases [TAILLE][TAILLE];

public:
	Plateau(void);
	~Plateau(void);

	// Accesseurs
	int getNbCases ();

	// Utilisateur
	Case getCaseDuTableau (int ligne, int colonne);
	void dessinerPlateau (CDC* pDC);
	void setTableauCases(Case unecase, int ligne, int colonne);
};


