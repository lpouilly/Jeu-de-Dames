#pragma once

#include "Case.h"

#define TAILLE 200

class Plateau
{
private:
	Case tableauDeCases [TAILLE][TAILLE];

public:
	Plateau(void);
	Plateau(int taillePlateau);
	~Plateau(void);

	// Accesseurs
	int getNbCases ();
	Case getCaseDuTableau (int i, int j);
	void setCaseDuTableau (int i, int j, int newEtat);

	// Utilisateur
	void dessinerPlateau (CDC* pDC, int taillePlateau);

	// Initialisations
	void initialiserPlateau4x4 ();
	void initialiserPlateau6x6 ();
	void initialiserPlateau8x8 ();
	void initialiserPlateau10x10 ();
};


