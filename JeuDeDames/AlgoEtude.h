#pragma once
#include "Case.h"
#include "Plateau.h"

#define TAILLE 200

#pragma once
class AlgoEtude
{
public:
	AlgoEtude(void);
	~AlgoEtude(void);
	AlgoEtude(Case caseCliquee);
	Case getCaseDuTableauTemp (int ligne, int colonne);
	void setTableauCases(Case unecase, int ligne, int colonne);
private:
	int nbCases;
	Case caseMemo;
	Case tableauDeCases[TAILLE][TAILLE];

};
