#pragma once
#include "Case.h"
#include "Plateau.h"
#include "AlgoRegle.h"

#define TAILLE 200

#pragma once
class AlgoEtude
{
public:
	AlgoEtude(void);
	~AlgoEtude(void);
	void appliquerAlgoEtude (Case caseCliquee);
	void testCaseOc (Case caseCliquee, AlgoRegle* algoRegle, Plateau* plateau);

private:
	Case caseMemo;
	Case tableauDeCases[TAILLE][TAILLE];

};
