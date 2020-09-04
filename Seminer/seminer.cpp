#include "seminer.h"
#include <string>
using namespace std;

int main()
{
	Seminer st;
	int secenek = -1, no = 0, kod = 0;
	string ad;
	string soyad;
	node* temp;
	st.ekle(30, "Deniz", "Ozogul", 1);
	st.ekle(20, "Emirhan", "Taner", 2);
	st.ekle(25, "Betul", "Dikmen", 4);
	st.ekle(42, "Ecem", "Cetin", 1);
	st.ekle(32, "Mert", "Acunman", 4);
	st.ekle(47, "Gunce", "Er", 3);
	st.ekle(10, "Fatih", "Balci", 3);
	st.ekle(23, "Ahsen", "Konak", 2);
	st.ekle(17, "Ece", "Surucu", 1);
	st.ekle(40, "Yaren", "Sari", 3);

	while (true) {
		cout << "1.Kayitli tum ogrencileri goruntule" << endl;
		cout << "2.Seminerde toplam kac kayit oldugunu goruntule" << endl;
		cout << "3.Yeni ogrenci ekle" << endl;
		cout << "4.Ogrenci sil" << endl;
		cout << "5.Ogrenci duzenle" << endl;
		cout << "6.Surpriz hediye cekilisi" << endl;
		cout << "7.Sistemden cik" << endl;
		cout << "**********************************************************************" << endl;
		cout << "Gerceklestirmek istediginiz eylemin numarasini giriniz(orn. 4):";
		cin >> secenek;
		system("CLS");
		switch (secenek)
		{
		case 1:
			cout << "1.Tum listeyi goruntule" << endl;
			cout << "2.Egitim kodu bazli liste goruntule" << endl;
			cout << "Gerceklestirmek istediginiz eylemin numarasini giriniz(orn. 2):" << endl;
			cout << "**********************************************************************" << endl;
			cin >> secenek;
			switch (secenek)
			{
			case 1:
				temp = st.ListeGetir();
				if (temp == NULL) cout << "Liste bos" << endl;
				else
					while (temp != NULL) {
						cout << "No: " + to_string(temp->no) + " Ad: " + temp->ad + " Soyad: " + temp->soyad + " Kod: " + to_string(temp->kod) << endl;
						temp = temp->sag;
					}
				st.arraySifirla();
				break;
			case 2:
				cout << "Goruntulemek istediginiz egitim kodunu giriniz(orn. 3):";
				cin >> secenek;
				temp = st.ListeGetirKod(secenek);
				if (temp == NULL) cout << "Liste bos" << endl;
				else
					while (temp != NULL) {
						cout << "No: " + to_string(temp->no) + " Ad: " + temp->ad + " Soyad: " + temp->soyad + " Egitim kodu: " + to_string(temp->kod) << endl;
						temp = temp->sag;
					}
				st.arraySifirla();
				break;
			default:
				cout << "Gecersiz secim" << endl;
				break;
			}
			cout << "**********************************************************************" << endl;
			break;
		case 2:
			cout << "Seminerde toplam " + to_string(st.boyut) + " kayit bulunmaktadir" << endl;
			cout << "**********************************************************************" << endl;
			break;
		case 3:
			cout << "Ogrenci Numarasi:";
			cin >> no;
			cout << "Ad: ";
			cin >> ad;
			cout << "Soyad: ";
			cin >> soyad;
			cout << "Egitim Kodu: ";
			cin >> kod;
			if ((st.kotaGetir(kod) + 1) > 4) cout << "Uzgunuz, egitimimizin kotasi dolmustur" << endl;
			else st.ekle(no, ad, soyad, kod);
			cout << "**********************************************************************" << endl;
			break;
		case 4:
			cout << "1.Tum ogrencileri sil" << endl;
			cout << "2.Tek bir ogrenciyi sil" << endl;
			cin >> secenek;
			switch (secenek)
			{
			case 1:
				st.listeSifirla(st.kokGetir());
				cout << "Liste sifirlandi" << endl;
				break;
			case 2:
				cout << "Silinmesini istediginiz ogrencinin numarasini giriniz:";
				cin >> no;
				st.listeSifirlaNo(st.kokGetir(), no);
				cout << "Ogrenci silindi" << endl;
				break;
			default:
				cout << "Gecersiz secim" << endl;
				break;
			}
			cout << "**********************************************************************" << endl;
			break;
		case 5:
			cout << "Duzenlemek istediginiz ogrencinin numarasini giriniz:";
			cin >> no;
			cout << "Ad: ";
			cin >> ad;
			cout << "Soyad: ";
			cin >> soyad;
			cout << "Egitim Kodu: ";
			cin >> kod;
			if ((st.kotaGetir(kod) + 1) > 4) cout << "Uzgunuz, bu egitimin kotasi dolmustur" << endl;
			else st.duzenle(no, ad, soyad, kod);
			cout << "**********************************************************************" << endl;
			break;
		case 6:
			cout << "No: " + to_string(st.min()->no) + " Ad: " + st.min()->ad + " Soyad: " + st.min()->soyad + " Egitim kodu: " + to_string(st.min()->kod) << endl;
			cout << "No: " + to_string(st.max()->no) + " Ad: " + st.max()->ad + " Soyad: " + st.max()->soyad + " Egitim kodu: " + to_string(st.max()->kod) << endl;
			cout << "**********************************************************************" << endl;
			break;
		case 7:
			cout << "Programdan cikiliyor";
			exit(0);
			break;
		default:
			cout << "Gecersiz secim" << endl;
			cout << "**********************************************************************" << endl;
			break;
		}
	}
	return 0;
}
