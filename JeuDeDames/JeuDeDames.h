
// JeuDeDames.h : fichier d'en-tête principal pour l'application JeuDeDames
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CJeuDeDamesApp:
// Consultez JeuDeDames.cpp pour l'implémentation de cette classe
//

class CJeuDeDamesApp : public CWinApp
{
public:
	CJeuDeDamesApp();

	int getJoueurEnCours();
	void setJoueurEnCours( int param1 );


// Substitutions
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implémentation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

};

extern CJeuDeDamesApp theApp;
