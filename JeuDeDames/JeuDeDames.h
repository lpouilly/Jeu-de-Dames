
// JeuDeDames.h : fichier d'en-tête principal pour l'application JeuDeDames
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux
#include "Plateau.h"
#include "AlgoEtude.h"
#include "AlgoRegle.h"
#include "JeuDeDamesDoc.h"


// CJeuDeDamesApp:
// Consultez JeuDeDames.cpp pour l'implémentation de cette classe
//

class CJeuDeDamesApp : public CWinApp
{
//ATTRIBUTS
private:
	Plateau* plateau;
	int joueurEnCours;
	int taillePlateau;
	AlgoEtude* algoEtude;
	AlgoRegle* algoRegle;
	int nbPionsBlanc;
	int nbPionsRouge;

//METHODES
public:
	CJeuDeDamesApp();
	Plateau* getPlateau ();
	int getJoueurEnCours();
	int getTaillePlateau();
	AlgoEtude* getAlgoEtude ();
	AlgoRegle* getAlgoRegle ();
	void setJoueurEnCours( int numJoueur );
	int getNbPionsBlanc ();
	int getNbPionsRouge ();
	void setNbPionsBlanc (int nbPB);
	void setNbPionsRouge (int nbPR);

// Substitutions
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implémentation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()


	afx_msg void OnGestiondespartiesNouvellepartie();
	CJeuDeDamesDoc* GetDocument() const /* la version non Debug est inline */;
};

extern CJeuDeDamesApp theApp;

#ifndef _DEBUG  // version debug dans JeuDeDamesView.cpp
inline CJeuDeDamesDoc* CJeuDeDamesView::GetDocument() const
{ return reinterpret_cast<CJeuDeDamesDoc*>(m_pDocument); }
#endif
