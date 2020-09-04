#include<iostream>
using namespace std;
struct node
{
	int no;
	string ad;
	string soyad;
	int kod;
	node* sol;
	node* sag;
};

class Seminer
{
public:
	Seminer();
	void ekle(int no, string ad, string soyad, int kod);
	void ekleArray(int no, string ad, string soyad, int kod);
	node* min();
	node* max();
	node* ListeGetir();
	node* ListeGetirKod(int kod);
	void ListeBul(node* kok);
	void ListeBulKod(node* kok, int kod);
	void arraySifirla();
	void listeSifirla(node* kok);
	node* listeSifirlaNo(node* kok, int no);
	node* kokGetir();
	int kotaGetir(int kod);
	void duzenle(int no, string ad, string soyad, int kod);
	int boyut = 0, e1 = 0, e2 = 0, e3 = 0, e4 = 0;
private:
	node* nodeYarat(int no, string ad, string soyad, int kod);
	node* nodeYaratArray(int no, string ad, string soyad, int kod);
	node* kok;
	node* array;
};

Seminer::Seminer()
{
	kok = NULL;
	array = NULL;
}

node* Seminer::nodeYarat(int no, string ad, string soyad, int kod)
{
	node* n = new node;
	n->no = no;
	n->ad = ad;
	n->soyad = soyad;
	n->kod = kod;
	n->sol = NULL;
	n->sag = NULL;

	return n;
}

node* Seminer::nodeYaratArray(int no, string ad, string soyad, int kod)
{
	node* n = new node;
	n->no = no;
	n->ad = ad;
	n->soyad = soyad;
	n->kod = kod;
	n->sag = NULL;

	return n;
}

void Seminer::ekle(int no, string ad, string soyad, int kod)
{
	if (kok == NULL)
	{
		kok = nodeYarat(no, ad, soyad, kod);
		boyut++;
		return;
	}

	node* onc = NULL;
	node* akt = kok;

	while (akt != NULL)
	{
		onc = akt;
		if (no > akt->no)
			akt = akt->sag;
		else
			akt = akt->sol;
	}

	if (no > onc->no)
		onc->sag = nodeYarat(no, ad, soyad, kod);
	else
		onc->sol = nodeYarat(no, ad, soyad, kod);
	switch (kod)
	{
	case 1:
		e1++;
		break;
	case 2:
		e2++;
		break;
	case 3:
		e3++;
		break;
	case 4:
		e4++;
		break;
	default:
		break;
	}
	boyut++;
}

void Seminer::ekleArray(int no, string ad, string soyad, int kod)
{
	if (array == NULL)
	{
		array = nodeYaratArray(no, ad, soyad, kod);
		return;
	}
	else
	{
		node* iter;
		iter = array;
		while (iter->sag != NULL) iter = iter->sag;
		iter->sag = nodeYaratArray(no, ad, soyad, kod);
	}
}

node* Seminer::min()
{
	node* akt = kok;
	if (akt == NULL)
		return NULL;

	while (akt->sol != NULL)
	{
		akt = akt->sol;
	}
	return akt;
}

node* Seminer::max()
{
	node* aktif = kok;
	if (aktif == NULL)
		return NULL;

	while (aktif->sag != NULL)
	{
		aktif = aktif->sag;
	}

	return aktif;
}
node* Seminer::ListeGetir()
{
	ListeBul(kok);
	return array;
}

node* Seminer::ListeGetirKod(int kod)
{
	ListeBulKod(kok, kod);
	return array;
}

void Seminer::ListeBul(node* kok)
{
	if (kok == NULL) {
		return;
	}
	ListeBul(kok->sol);
	ekleArray(kok->no, kok->ad, kok->soyad, kok->kod);
	ListeBul(kok->sag);
}

void Seminer::ListeBulKod(node* kok, int kod)
{
	if (kok == NULL) {
		return;
	}
	ListeBulKod(kok->sol, kod);
	if (kok->kod == kod)
		ekleArray(kok->no, kok->ad, kok->soyad, kok->kod);
	ListeBulKod(kok->sag, kod);
}

int Seminer::kotaGetir(int kod)
{
	switch (kod)
	{
	case 1:
		return e1;
		break;
	case 2:
		return e2;
		break;
	case 3:
		return e3;
		break;
	case 4:
		return e4;
		break;
	default:
		return -1;
		break;
	}
}

void Seminer::arraySifirla()
{
	node* current = array;
	node* iter;

	while (current != NULL)
	{
		iter = current->sag;
		delete current;
		current = iter;
	}

	array = NULL;
}

void Seminer::listeSifirla(node* kok)
{
	if (kok != NULL)
	{
		listeSifirla(kok->sol);
		listeSifirla(kok->sag);
		delete(kok);
		if (kok->sol != NULL)
			kok->sol = NULL;
		if (kok->sag != NULL)
			kok->sag = NULL;
		kok = NULL;
	}
	this->kok = NULL;
}

node* Seminer::listeSifirlaNo(node* kok, int no)
{
	if (kok == NULL)
		return kok;
	if (kok->no > no) {
		kok->sol = listeSifirlaNo(kok->sol, no); //torunları özyinelemeli cagirir
		return kok;
	}
	else if (kok->no < no) {
		kok->sag = listeSifirlaNo(kok->sag, no);
		return kok;
	}
	if (kok->sol == NULL) { // Eger çocuklardan biri NULL ise
		node* temp = kok->sag;
		delete kok;
		return temp;
	}
	else if (kok->sag == NULL) {
		node* temp = kok->sol;
		delete kok;
		return temp;
	}
	else { // Eger iki çocuk da varsa
		node* succParent = kok;
		node* succ = kok->sag;
		while (succ->sol != NULL) {
			succParent = succ;
			succ = succ->sol;
		}
		if (succParent != kok)
			succParent->sol = succ->sag;
		else
			succParent->sol = succ->sag;
		kok->no = succ->no;
		delete succ;
		return kok;
	}
}

void Seminer::duzenle(int no, string ad, string soyad, int kod)
{
	node* iter = kok;
	while (iter != NULL && iter->no != no)
	{
		if (no > iter->no)
			iter = iter->sag;
		else
			iter = iter->sol;
	}
	iter->ad = ad;
	iter->soyad = soyad;
	iter->kod = kod;
	switch (kod)
	{
	case 1:
		e1++;
		break;
	case 2:
		e2++;
		break;
	case 3:
		e3++;
		break;
	case 4:
		e4++;
		break;
	default:
		break;
	}
}

node* Seminer::kokGetir()
{
	return kok;
}
