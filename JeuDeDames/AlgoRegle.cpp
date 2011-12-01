#include "StdAfx.h"
#include "Case.h"
#include "AlgoEtude.h"
#include "AlgoRegle.h"
#include "Plateau.h"
#include "JeuDeDames.h"

AlgoRegle::AlgoRegle(void)
{
}

AlgoRegle::~AlgoRegle(void)
{
}

Case AlgoRegle::AlgoADerouler(Case caseCl)
{
	caseCliquee = caseCl;
	AlgoEtude* algoEtude = new AlgoEtude;
	Plateau* plateau = new Plateau;

	nbCases = plateau->getNbCases();
	int JoueurEnCours = ((CJeuDeDamesApp *)AfxGetApp( ))->getJoueurEnCours();

	for(int i=0;i<nbCases;i++)
	{
		for(int j=0;j<nbCases;j++)
		{
			tableauDeCases[i][j] = algoEtude->getCaseDuTableauTemp(i,j);
		}
	}

	if (JoueurEnCours == 1) AlgoADeroulerJoueurBlanc();
	if (JoueurEnCours == 2) AlgoADeroulerJoueurRouge();

	for(int k=nbCases;k<nbCases;k++)
	{
		for(int l=nbCases;l<nbCases;l++)
		{
			plateau->setTableauCases(tableauDeCases[k][l],k,l);
		}
	}	
	return caseMemo;
}

void AlgoRegle::AlgoADeroulerJoueurBlanc()
{
	Case* caseCliquee = new Case();
	int ligneVoulue = caseCliquee->getLigne() - 1;
	//Deux candidats sont crés !!!
	int colonneVoulueGauche = caseCliquee->getColonne() + 1;
	int colonneVoulueDroite = caseCliquee->getColonne() - 1;
	caseCliquee->setEtat(NOIR_OC_BLANC);

	// On étudie pour le candidat de droite
	if (verificationCaseDuPlateau(nbCases,ligneVoulue,colonneVoulueDroite) == true) //on regarde si la case candidate de droite est sur le plateau
	{
		Case caseAVerif1 = tableauDeCases[ligneVoulue][colonneVoulueDroite];
		if (verificationTypeCase(caseAVerif1) == NOIR) //on regarde si la case est libre
		{
			tableauDeCases[ligneVoulue][colonneVoulueDroite].setEtat(NOIR_SEL);
			caseMemo = *caseCliquee;
		}

		else
		{
			//il faudra gerer le cas ou on saute un pion
		}
	}

	// On étudie pour le candidat de gauche
	if (verificationCaseDuPlateau(nbCases,ligneVoulue,colonneVoulueGauche) == true)
	{
		Case caseAVerif2 = tableauDeCases[ligneVoulue][colonneVoulueGauche];
		if (verificationTypeCase(caseAVerif2) == NOIR)
		{
			tableauDeCases[ligneVoulue][colonneVoulueGauche].setEtat(NOIR_SEL);
			caseMemo = *caseCliquee;
		}

		else
		{
			//il faudra gerer le cas ou on saute un pion
		}
	}
}

void AlgoRegle::AlgoADeroulerJoueurRouge()
{
	int ligneVoulue = caseCliquee.getLigne() - 1;
	int colonneVoulueGauche = caseCliquee.getColonne() + 1;
	int colonneVoulueDroite = caseCliquee.getColonne() - 1;

	if (verificationCaseDuPlateau(nbCases,ligneVoulue,colonneVoulueDroite) == true) //on regarde si la case candidate de droite est sur le plateau
	{
		Case caseAVerif1 = tableauDeCases[ligneVoulue][colonneVoulueDroite];
		if (verificationTypeCase(caseAVerif1) == NOIR) //on regarde si la case est libre
		{
			tableauDeCases[TAILLE][TAILLE].setEtat(NOIR_SEL);
			caseMemo = caseCliquee;
		}

		else
		{
			//il faudra gerer le cas ou on saute un pion
		}
	}

	if (verificationCaseDuPlateau(nbCases,ligneVoulue,colonneVoulueGauche) == true)
	{
		Case caseAVerif2 = tableauDeCases[ligneVoulue][colonneVoulueGauche];
		if (verificationTypeCase(caseAVerif2) == NOIR)
		{
			tableauDeCases[nbCases][nbCases].setEtat(NOIR_SEL);
			caseMemo = caseCliquee;
		}

		else
		{
			//il faudra gerer le cas ou on saute un pion
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

int AlgoRegle::verificationTypeCase(Case CaseAVerifier)
{
	switch(CaseAVerifier.getEtat())
	{
		case NOIR: return NOIR;
		break;

		case NOIR_OC_BLANC : return NOIR_OC_BLANC;
		break;

		case NOIR_OC_ROUGE : return NOIR_OC_ROUGE;
		break;

		default: return -1;
		break;
	}
}
