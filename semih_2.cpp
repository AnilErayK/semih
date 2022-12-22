#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int odalar[100];

class Rezervasyon 
{
public:
  int odaNumarasi;
  string isim;
  string soyisim;
  int kalmaSuresi;
  int no;
};

vector<Rezervasyon> rezervasyonlar;


void dosyadanOku() {
  // Dosya okuma işlemleri burada yapılacak
  ifstream dosya("rezervasyonlar.txt");
  if (dosya.is_open()) {
    int odaNumarasi;
    string isim;
    string soyisim;
    int kalmaSuresi;
    int no;
    while (dosya >> odaNumarasi >> isim >> soyisim >> kalmaSuresi>>no) {
      Rezervasyon rez;
      rez.no= no;
      rez.odaNumarasi = odaNumarasi;
      rez.isim = isim;
      rez.soyisim = soyisim;
      rez.kalmaSuresi = kalmaSuresi;
      rezervasyonlar.push_back(rez);
    }
    dosya.close();
  }
}

void dosyayaYaz() {
  // Dosya yazma işlemleri burada yapılacak
  ofstream dosya("rezervasyonlar.txt");    
  if (dosya.is_open()) {
    for (int i = 0; i < rezervasyonlar.size(); i++) {
      rezervasyonlar[i].no=i+1;
      dosya << rezervasyonlar[i].odaNumarasi << " "
            << rezervasyonlar[i].isim << " "
            << rezervasyonlar[i].soyisim << " "
            << rezervasyonlar[i].kalmaSuresi << " " 
            << rezervasyonlar[i].no<<endl;
    }
    dosya.close();
  }
}

void odaolustur(){//odalar dosyadan okunuanarak oluşacak dolular 1 boşlar 0
  for (int i=0;i<100;i++)
    odalar[i]=0;

  for (int i=0;i<rezervasyonlar.size();i++)
    odalar[rezervasyonlar[i].odaNumarasi-1]=1;
  
}

void dosyayigoster(){
  // Dosya yazma işlemleri burada yapılacak
  ofstream dosya("rezervasyonlar.txt");
  if (dosya.is_open()) {
    for (int i = 0; i < rezervasyonlar.size(); i++) {
      cout << rezervasyonlar[i].odaNumarasi << " / "
            << rezervasyonlar[i].isim << " / "
            << rezervasyonlar[i].soyisim << " / "
            << rezervasyonlar[i].kalmaSuresi <<  " / "
            << rezervasyonlar[i].no << endl;
            rezervasyonlar[i].no=i+1;
      dosya << rezervasyonlar[i].odaNumarasi << " "
            << rezervasyonlar[i].isim << " "
            << rezervasyonlar[i].soyisim << " "
            << rezervasyonlar[i].kalmaSuresi << " " 
            << rezervasyonlar[i].no<<endl;
    }
    dosya.close();
  }
}



void rezervasyonEkle() {
  system("cls");
  int odaNumarasi,kalmaSuresi;
  string isim,soyisim;
  Rezervasyon rez;
  bool flag=0;
  cout<<"Tahsis etmek istediginiz oda numarasini giriniz."<<endl;
do
{
  cin>>odaNumarasi;
  rez.odaNumarasi = odaNumarasi;

  if(odalar[odaNumarasi-1]==0){
    odalar[odaNumarasi-1]=1;
    flag=0; }
  
  else{
    cout<<"Tahsis etmeye calisiginiz oda dolu baska bir odayi deneyiniz."<<endl;
    odalar[odaNumarasi-1]==1;
    flag=1;
    }

}while(flag==1);

  cout<<"İsminizi Giriniz."<<endl;
  cin>>isim;
  rez.isim = isim;
  cout<<"Soyisiminizi giriniz"<<endl;
  cin>>soyisim;
  rez.soyisim = soyisim;
  cout<<"Kac gun konaklayacaksiniz"<<endl; 
  cin>>kalmaSuresi;
  rez.kalmaSuresi = kalmaSuresi;
  rez.no=rezervasyonlar.size()+1;
  rezervasyonlar.push_back(rez);
  dosyayaYaz();
  cout<<"Rezervasyonunuz basari ile tamamlanmistir."<<endl<<endl;
}

void kayitDuzenle(){
    system("cls");
    bool flag=false;
    int no;
    dosyayigoster();
do{
    cout<<"Duzenlemek istediğiniz musteri numarasini giriniz."<<endl;
    cin>>no;
    for(int i=0;i<rezervasyonlar.size();i++){
      if(rezervasyonlar[i].no==no)
        flag=true;
        }
    if(flag==false){
      cout<<"Yanlis bir müsteri numarasi girdiniz. Tekrar deneyiniz."<<endl;
      }
    
    }while(flag==false);

    odalar[rezervasyonlar[no-1].odaNumarasi-1]=0;
    int odaNumarasi,kalmaSuresi;
	  string isim,soyisim;
    flag=false;
do{
    cout<<"Tahsis etmek istediğiniz oda numarasini giriniz"<<endl;
    cin>>odaNumarasi;
    for(int i=0;i<rezervasyonlar.size();i++){
      if(odalar[rezervasyonlar[i].odaNumarasi-1]==0)
        flag=true;
        }
    if(flag==false)
      cout<<"Tahsis etmek istediginiz oda dolu baska bir odayi deneyiniz."<<endl;  
}while(flag==false);
    rezervasyonlar[no-1].odaNumarasi = odaNumarasi;
    odalar[odaNumarasi-1]=1;
    cout<<"İsminizi Giriniz."<<endl;
    cin>>isim;
    rezervasyonlar[no-1].isim = isim;
    cout<<"Soyisiminizi giriniz."<<endl;
    cin>>soyisim;
    rezervasyonlar[no-1].soyisim = soyisim;
    cout<<"Kac gun konaklayacaksiniz."<<endl;
    cin>>kalmaSuresi;
    rezervasyonlar[no-1].kalmaSuresi = kalmaSuresi;
    rezervasyonlar[no-1].no =no;
    dosyayaYaz();
    cout<<endl<<"Kayit basariyla duzenlenmistir."<<endl<<endl;
}

void odacikis(){
    system("cls");
    bool flag=false;
    int No,odaNum;
    do{
      cout<<"Cikis yapmak İstediğiniz istediğiniz oda numarasini giriniz"<<endl;
      cin>>odaNum;
    for(int i=0;i<rezervasyonlar.size();i++){
      if(odaNum==rezervasyonlar[i].odaNumarasi){//rezervasyonlardaki herhangi bir oda numarasına eşit bir numara girilirse
        No=rezervasyonlar[i].no;//rezervasyondaki numara tutulur
        odalar[rezervasyonlar[i].odaNumarasi-1]=0;//numara kullanılarak odayı boşalttık
        flag=true;
        }
        }
    if(flag==false)
      cout<<endl<<"Belirtilen oda numarasi icin bir rezervasyon bulunamadi."<<endl;
    }while(flag==false);
      rezervasyonlar.erase(rezervasyonlar.begin() + No-1);//numara kullanılarak rezervasyon silinir
  
  dosyayaYaz();//dosya tekrardan yazılır.
}

void odalargoruntule(){
  system("cls");
	cout<<"    ";
    cout<<"Oteldeki Dolu Odalar"<<endl;
      // Dosya yazma işlemleri burada yapılacak
  ofstream dosya("rezervasyonlar.txt");
  if (dosya.is_open()) {
    for (int i = 0; i < rezervasyonlar.size(); i++) {
      cout <<rezervasyonlar[i].odaNumarasi << endl;

      dosya << rezervasyonlar[i].odaNumarasi << " "
      << rezervasyonlar[i].isim << " "
      << rezervasyonlar[i].soyisim << " "
      << rezervasyonlar[i].kalmaSuresi << " " 
      << rezervasyonlar[i].no<<endl;
    }
    dosya.close();
  }
    
}

void menu(){
 char a;  

    while(a!='5'){
    cout<<"1-Rezervasyon ekle."<<endl;
    cout<<"2-Kayitlari duzenle."<<endl;
    cout<<"3-Dolu Odalari goruntule."<<endl;
    cout<<"4-Musteri cikis."<<endl;
    cout<<"5-Sistemden cikis yap."<<endl;
    a = getch();
    
    if(a=='1'){
        rezervasyonEkle();}

    else if(a=='2'){
        kayitDuzenle();}

    else if(a=='3'){
        odalargoruntule();}

    else if(a=='4'){
      odacikis();}

    else if(a=='5')
      cout<<"Sistemden cikis yaptiniz.";
    
    else
        cout<<endl<<"5 seçimden birini seciniz."<<endl;  
}
        
}

int main() {
    dosyadanOku();
    odaolustur();
    int sifre;
  do{
  cout<<"Admin Sifresini giriniz."<<endl;
  cin>>"%d",sifre;

    if(sifre!=1453)
      cout<<"sifreyi yanlis girdiniz."<<endl;      
  }while(sifre!=1453);
    
    system("cls");

  for(int i =0;i<2;i++){
    cout<<endl<<endl<<endl<<endl<<"               "<<"Sisteme giris yapiliyor.";
    cout<<endl<<endl<<endl<<endl<<"               "<<"Sisteme giris yapiliyor..";
    cout<<endl<<endl<<endl<<endl<<"               "<<"Sisteme giris yapiliyor...";
    system("cls");
  }
  menu();
  return 0;
}