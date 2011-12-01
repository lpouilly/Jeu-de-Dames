#pragma once
#include "Case.h"
#include "Plateau.h"



class AlgoRegle
{
public:
	AlgoRegle(void);
	~AlgoRegle(void);
	Case AlgoADerouler(Case caseCliquee);
	void AlgoADeroulerJoueurBlanc();
	void AlgoADeroulerJoueurRouge();
	bool verificationCaseDuPlateau( int nbCases, int ligneVoulue, int colonneVoulue );
	int verificationTypeCase(Case CaseAVerifier );

private:
	Case caseCliquee; 
	Case caseMemo;
	Case tableauDeCases[TAILLE][TAILLE];
	int nbCases;

};
