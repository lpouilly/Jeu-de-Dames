#pragma once
#include "afxwin.h"

#define SERVEUR 1
#define CLIENT 2


// Boîte de dialogue CDlgMenu

class CDlgMenu : public CDialog
{
	DECLARE_DYNAMIC(CDlgMenu)

public:
	CDlgMenu(CWnd* pParent = NULL);   // constructeur standard
	virtual ~CDlgMenu();

// Données de boîte de dialogue
	enum { IDD = IDD_MENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CComboBox ma_combo_box_cases;
	CComboBox ma_combo_box_reseau;
	int cases;
	int reseau;
	bool deverouiller;
	afx_msg void OnCbnSelchangeServeurclient();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
