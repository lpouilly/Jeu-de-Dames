
// JeuDeDames.cpp : D�finit les comportements de classe pour l'application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "JeuDeDames.h"
#include "MainFrm.h"

#include "JeuDeDamesDoc.h"
#include "JeuDeDamesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJeuDeDamesApp

BEGIN_MESSAGE_MAP(CJeuDeDamesApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CJeuDeDamesApp::OnAppAbout)
	// Commandes de fichier standard
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Commande standard de configuration de l'impression
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// construction CJeuDeDamesApp

CJeuDeDamesApp::CJeuDeDamesApp()
{
	// prend en charge le Gestionnaire de red�marrage
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Si l'application est cr��e � l'aide de la prise en charge Common Language Runtime (/clr):
	//     1) Ce param�tre suppl�mentaire est n�cessaire � la prise en charge du Gestionnaire de red�marrage.
	//     2) Dans votre projet, vous devez ajouter une r�f�rence � System.Windows.Forms pour la g�n�ration.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: remplacer la cha�ne d'ID de l'application ci-dessous par une cha�ne ID unique�; le format recommand�
	// pour la cha�ne est CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("JeuDeDames.AppID.NoVersion"));

	// TODO: ajoutez ici du code de construction,
	// Placez toutes les initialisations significatives dans InitInstance
}

// Seul et unique objet CJeuDeDamesApp

CJeuDeDamesApp theApp;


// initialisation de CJeuDeDamesApp

BOOL CJeuDeDamesApp::InitInstance()
{
	// InitCommonControlsEx() est requis sur Windows�XP si le manifeste de l'application
	// sp�cifie l'utilisation de ComCtl32.dll version�6 ou ult�rieure pour activer les
	// styles visuels.  Dans le cas contraire, la cr�ation de fen�tres �chouera.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// � d�finir pour inclure toutes les classes de contr�les communs � utiliser
	// dans votre application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Initialiser les biblioth�ques OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() est requis pour utiliser un contr�le RichEdit	
	// AfxInitRichEdit2();

	// Initialisation standard
	// Si vous n'utilisez pas ces fonctionnalit�s et que vous souhaitez r�duire la taille
	// de votre ex�cutable final, vous devez supprimer ci-dessous
	// les routines d'initialisation sp�cifiques dont vous n'avez pas besoin.
	// Changez la cl� de Registre sous laquelle nos param�tres sont enregistr�s
	// TODO: modifiez cette cha�ne avec des informations appropri�es,
	// telles que le nom de votre soci�t� ou organisation
	SetRegistryKey(_T("Applications locales g�n�r�es par AppWizard"));
	LoadStdProfileSettings(1);  // Charge les options de fichier INI standard (y compris les derniers fichiers utilis�s)


	// Inscrire les mod�les de document de l'application. Ces mod�les
	//  lient les documents, fen�tres frame et vues entre eux
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CJeuDeDamesDoc),
		RUNTIME_CLASS(CMainFrame),       // fen�tre frame SDI principale
		RUNTIME_CLASS(CJeuDeDamesView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Analyser la ligne de commande pour les commandes shell standard, DDE, ouverture de fichiers
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Commandes de dispatch sp�cifi�es sur la ligne de commande. Retournent FALSE si
	// l'application a �t� lanc�e avec /RegServer, /Register, /Unregserver ou /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// La seule fen�tre a �t� initialis�e et peut donc �tre affich�e et mise � jour
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// appelle DragAcceptFiles uniquement s'il y a un suffixe
	//  Dans une application SDI, cet appel doit avoir lieu juste apr�s ProcessShellCommand
	return TRUE;
}

int CJeuDeDamesApp::ExitInstance()
{
	//TODO: g�rez les ressources suppl�mentaires que vous avez ajout�es
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// gestionnaires de messages pour CJeuDeDamesApp


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Commande App pour ex�cuter la bo�te de dialogue
void CJeuDeDamesApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CJeuDeDamesApp::setJoueurEnCours( int param1 )
{

}

int CJeuDeDamesApp::getJoueurEnCours()
{
	return 0; //� coder
}

// gestionnaires de messages pour CJeuDeDamesApp



