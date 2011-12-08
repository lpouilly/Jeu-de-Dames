#pragma once

#define BLANC 0
#define NOIR 1
#define NOIR_OC_BLANC 2
#define NOIR_OC_ROUGE 3
#define NOIR_SEL 4
#define NOIR_OC_BLANC_SEL 7
#define NOIR_OC_ROUGE_SEL 6

#define LARGEUR_CASE 50

class Case : public CObject
{
private:
	DECLARE_SERIAL(Case);
	int etat;
	int ligne;
	int colonne;
	CImage image;

public:
	Case();
	Case(int monEtat, int maLigne, int maColonne);
	~Case(void);
	Case(const Case &rCase);
	const Case& operator=(const Case& Src);

	void CopyFrom(const Case & Src );

	// Accesseurs
	int getEtat ();
	int getLigne ();
	int getColonne ();
	void setEtat (int monEtat);
	void setLigne( int maLigne );
	void setColonne( int maColonne );

	// Utilisateur
	void dessinerCase (CDC* pDC);
	void Serialize (CArchive& ar);
	
};


