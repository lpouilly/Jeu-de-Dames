#include "StdAfx.h"
#include "Case.h"
#include "AlgoEtude.h"
#include "JeuDeDames.h"
#include "Plateau.h"
#include "JeuDeDames.h"


AlgoEtude::AlgoEtude(void)
{
	caseMemo = Case (BLANC, 0, 0);
}


AlgoEtude::~AlgoEtude(void)
{
}


void AlgoEtude::appliquerAlgoEtude (Case caseCliquee)
{
	// On r�cup�re le plateau, sa taille et le joueur en cours
	Plateau* plateau = ((CJeuDeDamesApp *)AfxGetApp( ))->getPlateau();
	int nbCases = ((CJeuDeDamesApp *)AfxGetApp( ))->getTaillePlateau();
	int joueurEnCours = ((CJeuDeDamesApp *)AfxGetApp( ))->getJoueurEnCours();
	AlgoRegle* algoRegle = ((CJeuDeDamesApp *)AfxGetApp( ))->getAlgoRegle();
	int nbPionsBlanc = ((CJeuDeDamesApp *)AfxGetApp( ))->getNbPionsBlanc();
	int nbPionsRouge = ((CJeuDeDamesApp *)AfxGetApp( ))->getNbPionsRouge();

	// CAS DU JOUEUR 1
	if (joueurEnCours == 1 )
	{
		// Il clique sur une case occup�e par un de ses pions
		if(caseCliquee.getEtat() == NOIR_OC_BLANC)
		{
			// On d�s�lectionne toutes les cases
			for(int i = 0; i < nbCases; i++) {
				for(int j = 0; j < nbCases; j++)
				{
					if (plateau->getCaseDuTableau(i, j).getEtat() == NOIR_SEL) plateau->setCaseDuTableau(i, j, NOIR);
				} 
			}

			caseMemo = algoRegle->deroulerAlgo(caseCliquee);	
		}

		// Il clique sur une case candidate au d�placement
		if(caseCliquee.getEtat() == NOIR_SEL)
		{
			int iMemo = caseMemo.getLigne();
			int jMemo = caseMemo.getColonne();

			int iClic = caseCliquee.getLigne();
			int jClic = caseCliquee.getColonne();

			// On d�place le pion
			plateau->setCaseDuTableau(iMemo, jMemo, NOIR);
			plateau->setCaseDuTableau(iClic, jClic, NOIR_OC_BLANC);

			// CAS o� on saute un pion
			if ((iMemo - iClic) == 2)
			{
				testCaseOc(caseCliquee, algoRegle, plateau);
				nbPionsRouge -= 1;
				((CJeuDeDamesApp *)AfxGetApp( ))->setNbPionsRouge(nbPionsRouge);
			}
			
			// On d�s�lectionne toutes les cases
			for(int i = 0; i < nbCases; i++) {
				for(int j = 0; j < nbCases; j++)
				{
					if (plateau->getCaseDuTableau(i, j).getEtat() == NOIR_SEL) plateau->setCaseDuTableau(i, j, NOIR);
				} 
			}

			// On change de joueur
			((CJeuDeDamesApp *)AfxGetApp( ))->setJoueurEnCours(2);
		}

	}

	// CAS DU JOUEUR 2
	if (joueurEnCours == 2 )
	{
		// Il clique sur une case occup�e par un de ses pions
		if(caseCliquee.getEtat() == NOIR_OC_ROUGE)
		{
			// On d�s�lectionne toutes les cases
			for(int i = 0; i < nbCases; i++) {
				for(int j = 0; j < nbCases; j++)
				{
					if (plateau->getCaseDuTableau(i, j).getEtat() == NOIR_SEL) plateau->setCaseDuTableau(i, j, NOIR);
				} 
			}

			caseMemo = algoRegle->deroulerAlgo(caseCliquee);
		}

		// Il clique sur une case candidate au d�placement
		if(caseCliquee.getEtat() == NOIR_SEL)
		{
			int iMemo = caseMemo.getLigne();
			int jMemo = caseMemo.getColonne();

			int iClic = caseCliquee.getLigne();
			int jClic = caseCliquee.getColonne();

			// On d�place le pion
			plateau->setCaseDuTableau(iMemo, jMemo, NOIR);
			plateau->setCaseDuTableau(iClic, jClic, NOIR_OC_ROUGE);

			// CAS o� on saute un pion
			if ((iClic - iMemo) == 2)
			{
				testCaseOc(caseCliquee, algoRegle, plateau);
				nbPionsBlanc -= 1;
				((CJeuDeDamesApp *)AfxGetApp( ))->setNbPionsBlanc(nbPionsBlanc);
			}

			// On d�s�lectionne toutes les cases
			for(int i = 0; i < nbCases; i++) {
				for(int j = 0; j < nbCases; j++)
				{
					if (plateau->getCaseDuTableau(i, j).getEtat() == NOIR_SEL) plateau->setCaseDuTableau(i, j, NOIR);
				} 
			}

			// On change de joueur
			((CJeuDeDamesApp *)AfxGetApp( ))->setJoueurEnCours(1);
		}

	}

}

void AlgoEtude::testCaseOc (Case caseCliquee, AlgoRegle* algoRegle, Plateau* plateau)
{
	int cpt = algoRegle->getCptMemoOc();

	Case caseAuxDroite = algoRegle->getCaseMemoOcDroite();
	Case caseAuxGauche = algoRegle->getCaseMemoOcGauche();
	
	if ( cpt == 1 ) // On ne peut �tre que sur la case de droite
	{
		int iD = caseAuxDroite.getLigne();
		int jD = caseAuxDroite.getColonne();

		plateau->setCaseDuTableau(iD, jD, NOIR);
	}

	if ( cpt == 2 ) // On ne peut �tre que sur la case de gauche
	{
		int iG = caseAuxGauche.getLigne();
		int jG = caseAuxGauche.getColonne();

		plateau->setCaseDuTableau(iG, jG, NOIR);
	}

	if ( cpt == 3 ) // On peut �tre � droite ou � gauche
	{
		int iC = caseCliquee.getLigne();
		int jC = caseCliquee.getColonne();

		// CAS o� on est � droite
		if (plateau->getCaseDuTableau(iC, jC - 4).getEtat() == NOIR_SEL)
		{
			int iD = caseAuxDroite.getLigne();
			int jD = caseAuxDroite.getColonne();

			plateau->setCaseDuTableau(iD, jD, NOIR);
		}
		// CAS o� on est � gauche
		else
		{
			int iG = caseAuxGauche.getLigne();
			int jG = caseAuxGauche.getColonne();

			plateau->setCaseDuTableau(iG, jG, NOIR);
		}
	}
}
