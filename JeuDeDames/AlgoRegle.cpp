#include "StdAfx.h"
#include "Case.h"
#include "AlgoEtude.h"
#include "AlgoRegle.h"
#include "Plateau.h"
#include "JeuDeDames.h"

AlgoRegle::AlgoRegle(void)
{
	caseCliquee = Case (BLANC, 0, 0);
	caseMemoOcDroite = Case (BLANC, 0, 0);
	caseMemoOcGauche = Case (BLANC, 0, 0);
}

AlgoRegle::~AlgoRegle(void)
{
}

Case AlgoRegle::getCaseMemoOcDroite()
{
	return caseMemoOcDroite;
}

Case AlgoRegle::getCaseMemoOcGauche()
{
	return caseMemoOcGauche;
}

int AlgoRegle::getCptMemoOc()
{
	return cptMemoOc;
}


Case AlgoRegle::deroulerAlgo (Case caseClic)
{
	// On récupère la case cliquée
	caseCliquee = caseClic;

	// On récupère le tableau de cases
	Plateau* plateau = ((CJeuDeDamesApp *)AfxGetApp( ))->getPlateau();
	int nbCases = ((CJeuDeDamesApp *)AfxGetApp( ))->getTaillePlateau();

	for(int i = 0; i < nbCases; i++) {
		for(int j = 0; j < nbCases; j++)
		{
			tableauDeCases[i][j] = plateau->getCaseDuTableau(i,j);
		} 
	}

	// On récupère le joueur en cours
	int joueurEnCours = ((CJeuDeDamesApp *)AfxGetApp( ))->getJoueurEnCours();

	// On applique l'algo spécifique au joueur
	if (joueurEnCours == 1) AlgoADeroulerJoueurBlanc(nbCases);
	if (joueurEnCours == 2) AlgoADeroulerJoueurRouge(nbCases);

	// On met à jour le plateau
	for(int i = 0; i < nbCases; i++) {
		for(int j = 0; j < nbCases; j++)
		{
			plateau->setCaseDuTableau(i, j, tableauDeCases[i][j].getEtat());
		}
	}

	return caseMemo;
}


void AlgoRegle::AlgoADeroulerJoueurBlanc(int nbCases)
{
	cptMemoOc = 0;

	// On cherche les deux cases candidates au mouvement
	int ligneVoulue = caseCliquee.getLigne() - 1;

	int colonneVoulueGauche = caseCliquee.getColonne() - 1;
	int colonneVoulueDroite = caseCliquee.getColonne() + 1;

	// On étudie pour le candidat de droite
	// On vérifie qu'il soit dans le plateau
	if (verificationCaseDuPlateau(nbCases, ligneVoulue, colonneVoulueDroite) == true)
	{
		Case caseAVerif1 = tableauDeCases[ligneVoulue][colonneVoulueDroite];

		// CAS où la case est libre
		if (caseAVerif1.getEtat() == NOIR)
		{
			tableauDeCases[ligneVoulue][colonneVoulueDroite].setEtat(NOIR_SEL);
			caseMemo = caseCliquee;
		}

		// CAS où la case est occupée par un pion rouge
		if (caseAVerif1.getEtat() == NOIR_OC_ROUGE)
		{
			// On regarde si la case suivante est libre
			if (tableauDeCases[ligneVoulue - 1][colonneVoulueDroite + 1].getEtat() == NOIR)
			{
				tableauDeCases[ligneVoulue - 1][colonneVoulueDroite + 1].setEtat(NOIR_SEL);
				caseMemo = caseCliquee;
				caseMemoOcDroite = tableauDeCases[ligneVoulue][colonneVoulueDroite];
				cptMemoOc += 1; 
			}
		}
	}

	// On étudie pour le candidat de gauche
	// On vérifie qu'il soit dans le plateau
	if (verificationCaseDuPlateau(nbCases, ligneVoulue, colonneVoulueGauche) == true)
	{
		Case caseAVerif2 = tableauDeCases[ligneVoulue][colonneVoulueGauche];

		// CAS où la case est libre
		if (caseAVerif2.getEtat() == NOIR)
		{
			tableauDeCases[ligneVoulue][colonneVoulueGauche].setEtat(NOIR_SEL);
			caseMemo = caseCliquee;
		}

		// CAS où la case est occupée par un pion rouge
		if (caseAVerif2.getEtat() == NOIR_OC_ROUGE)
		{
			// On regarde si la case suivante est libre
			if (tableauDeCases[ligneVoulue - 1][colonneVoulueGauche - 1].getEtat() == NOIR)
			{
				tableauDeCases[ligneVoulue - 1][colonneVoulueGauche - 1].setEtat(NOIR_SEL);
				caseMemo = caseCliquee;
				caseMemoOcGauche = tableauDeCases[ligneVoulue][colonneVoulueGauche];
				cptMemoOc += 2;
			}
		}
	}
}


void AlgoRegle::AlgoADeroulerJoueurRouge(int nbCases)
{
	cptMemoOc = 0;

	// On cherche les deux cases candidates au mouvement
	int ligneVoulue = caseCliquee.getLigne() + 1;

	int colonneVoulueGauche = caseCliquee.getColonne() - 1;
	int colonneVoulueDroite = caseCliquee.getColonne() + 1;

	// On étudie pour le candidat de droite
	// On vérifie qu'il soit dans le plateau
	if (verificationCaseDuPlateau(nbCases, ligneVoulue, colonneVoulueDroite) == true)
	{
		Case caseAVerif1 = tableauDeCases[ligneVoulue][colonneVoulueDroite];

		// CAS où la case est libre
		if (caseAVerif1.getEtat() == NOIR)
		{
			tableauDeCases[ligneVoulue][colonneVoulueDroite].setEtat(NOIR_SEL);
			caseMemo = caseCliquee;
		}

		// CAS où la case est occupée par un pion blanc
		if (caseAVerif1.getEtat() == NOIR_OC_BLANC)
		{
			// On regarde si la case suivante est libre
			if (tableauDeCases[ligneVoulue + 1][colonneVoulueDroite + 1].getEtat() == NOIR)
			{
				tableauDeCases[ligneVoulue + 1][colonneVoulueDroite + 1].setEtat(NOIR_SEL);
				caseMemo = caseCliquee;
				caseMemoOcDroite = tableauDeCases[ligneVoulue][colonneVoulueDroite];
				cptMemoOc += 1;
			}
		}
	}

	// On étudie pour le candidat de gauche
	// On vérifie qu'il soit dans le plateau
	if (verificationCaseDuPlateau(nbCases,ligneVoulue,colonneVoulueGauche) == true)
	{
		Case caseAVerif2 = tableauDeCases[ligneVoulue][colonneVoulueGauche];

		// CAS où la case est libre
		if (caseAVerif2.getEtat() == NOIR)
		{
			tableauDeCases[ligneVoulue][colonneVoulueGauche].setEtat(NOIR_SEL);
			caseMemo = caseCliquee;
		}

		// CAS où la case est occupée par un pion blanc
		if (caseAVerif2.getEtat() == NOIR_OC_BLANC)
		{
			// On regarde si la case suivante est libre
			if (tableauDeCases[ligneVoulue + 1][colonneVoulueGauche - 1].getEtat() == NOIR)
			{
				tableauDeCases[ligneVoulue + 1][colonneVoulueGauche - 1].setEtat(NOIR_SEL);
				caseMemo = caseCliquee;
				caseMemoOcGauche = tableauDeCases[ligneVoulue][colonneVoulueGauche];
				cptMemoOc += 2;
			}
		}
	}
}

bool AlgoRegle::verificationCaseDuPlateau( int nbCases, int ligneVoulue, int colonneVoulue )
{
	if ((ligneVoulue >= 0) && (ligneVoulue < nbCases ) && (colonneVoulue >= 0) && (colonneVoulue < nbCases))
	{
		return true;
	}
	else
	{
		return false;
	}
}
