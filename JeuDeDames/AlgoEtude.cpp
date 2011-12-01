#include "StdAfx.h"
#include "Case.h"
#include "AlgoEtude.h"
#include "AlgoRegle.h"
#include "JeuDeDames.h"
#include "Plateau.h"
#include "JeuDeDames.h"


AlgoEtude::AlgoEtude(void)
{
}


AlgoEtude::~AlgoEtude(void)
{
}

AlgoEtude::AlgoEtude(Case caseCliquee)
{
	AlgoRegle* algoRegle = new AlgoRegle;
	Plateau* plateau = new Plateau;

	nbCases = plateau->getNbCases();
	int joueurEnCours = ((CJeuDeDamesApp *)AfxGetApp( ))->getJoueurEnCours();

	for(int i=0;i<nbCases;i++)
	{
		for(int j=0;j<nbCases;j++)
		{
			tableauDeCases[i][j] = plateau->getCaseDuTableau(i,j);
		} 
	}



	if(joueurEnCours == 1 )
	{
		if(caseCliquee.getEtat() == NOIR_OC_BLANC) //Il clique sur un de ses pions
		{
			caseMemo = algoRegle->AlgoADerouler(caseCliquee);	
		}
		if(caseCliquee.getEtat() == NOIR_SEL)
		{
			//faire le changement de case
			caseMemo.setEtat(NOIR);
			caseCliquee.setEtat(NOIR_OC_BLANC);

			//faire le changement de joueur
			((CJeuDeDamesApp *)AfxGetApp( ))->setJoueurEnCours(2);
		}
		
	}
	if(joueurEnCours == 2 )
	{
		if(caseCliquee.getEtat() == NOIR_OC_ROUGE) //Il clique sur un de ses pions
		{
			caseMemo = algoRegle->AlgoADerouler(caseCliquee);
		}
		if(caseCliquee.getEtat() == NOIR_SEL)
		{
			//faire le changement de case
			caseMemo.setEtat(NOIR);
			caseCliquee.setEtat(NOIR_OC_ROUGE);

			//faire le changement de joueur
			((CJeuDeDamesApp *)AfxGetApp( ))->setJoueurEnCours(1);
		}
	}

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			plateau->setTableauCases(tableauDeCases[i][j],i,j);
		}
	}	

}

Case AlgoEtude::getCaseDuTableauTemp (int ligne, int colonne)
{
	return tableauDeCases[ligne][colonne];
}

void AlgoEtude::setTableauCases(Case unecase, int ligne, int colonne)
{
	tableauDeCases[ligne][colonne] = unecase;
}
