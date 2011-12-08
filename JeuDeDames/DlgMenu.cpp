// DlgMenu.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "JeuDeDames.h"
#include "DlgMenu.h"
#include "afxdialogex.h"


// Bo�te de dialogue CDlgMenu

IMPLEMENT_DYNAMIC(CDlgMenu, CDialog)

CDlgMenu::CDlgMenu(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMenu::IDD, pParent)
{

}

CDlgMenu::~CDlgMenu()
{
}

void CDlgMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NOMBRECASES, ma_combo_box_cases);
	DDX_Control(pDX, IDC_SERVEURCLIENT, ma_combo_box_reseau);
}


BEGIN_MESSAGE_MAP(CDlgMenu, CDialog)
	ON_CBN_SELCHANGE(IDC_SERVEURCLIENT, &CDlgMenu::OnCbnSelchangeServeurclient)
END_MESSAGE_MAP()


// Gestionnaires de messages de CDlgMenu


void CDlgMenu::OnCbnSelchangeServeurclient()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contr�le
}


BOOL CDlgMenu::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Ajoutez ici une initialisation suppl�mentaire

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION�: les pages de propri�t�s OCX devraient retourner FALSE
}


void CDlgMenu::OnOK()
{
	int recuperationCases;
	int recuperationReseau;
	recuperationCases = ma_combo_box_cases.GetCurSel();
	recuperationReseau = ma_combo_box_reseau.GetCurSel();

	switch(recuperationCases)
	{
	case 0 : cases = 4;
		break;

	case 1 : cases = 6;
		break;

	case 2 : cases = 8;
		break;

	case 3 : cases = 10;
		break;

	default: cases = 8;
		break;
	}

	switch(recuperationReseau)
	{
	case 1 : reseau = SERVEUR;
		break;

	case 2 : reseau = CLIENT;
		break;
	}

	CDialog::OnOK();
}
