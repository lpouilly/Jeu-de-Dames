#pragma once
#include "Case.h"
#include "Plateau.h"



class AlgoRegle
{
public:
	AlgoRegle(void);
	~AlgoRegle(void);
	Case deroulerAlgo (Case caseCliquee);
	void AlgoADeroulerJoueurBlanc(int nbCases);
	void AlgoADeroulerJoueurRouge(int nbCases);
	bool verificationCaseDuPlateau( int nbCases, int ligneVoulue, int colonneVoulue );
	Case getCaseMemoOcDroite ();
	Case getCaseMemoOcGauche ();
	int getCptMemoOc ();

private:
	Case caseCliquee; 
	Case caseMemo;
	Case caseMemoOcDroite;
	Case caseMemoOcGauche;
	int cptMemoOc;
	Case tableauDeCases[TAILLE][TAILLE];

};
