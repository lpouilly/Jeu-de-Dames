#include "StdAfx.h"
#include "Case.h"
#include "Clic.h"
#include "Plateau.h"
#include "JeuDeDames.h"


Clic::Clic(void)
{

}


Clic::~Clic(void)
{

}


int Clic::LigneDuClic( CPoint point )
{
	int calcul;
	int taillePlateau;

	calcul = point.y - 80;
	calcul = calcul / 50;

	taillePlateau = ((CJeuDeDamesApp*) AfxGetApp() )->getTaillePlateau();

	if((calcul<taillePlateau)&&(calcul>=0))	return calcul;
	else return -1;
}

int Clic::ColonneDuClic( CPoint point )
{
	int calcul;
	int taillePlateau;

	calcul = point.x - 80;
	calcul = calcul / 50;

	taillePlateau = ((CJeuDeDamesApp *)AfxGetApp( ))->getTaillePlateau();

	if((calcul<taillePlateau)&&(calcul>=0))	return calcul;
	else return -1;
}
