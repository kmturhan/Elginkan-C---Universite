#include <iostream>

using namespace std;
class universite
{
private:
    string ad,soyad,adres,kurumAdi;
public:
    universite()
    {
        kurumAdi = "SAKARYA UNIVERSITESI";
    }

    void bilgiGirisi()
    {
        cout<<"Ad : ";cin>>ad;  cout<<"Soyad : ";cin>>soyad;    cout<<"Adres : ";cin>>adres;
    }
    void Yazdir()
    {
        cout<<"Isim : "<<ad<<endl<<"Soyad : "<<soyad<<endl<<"Adres : "<<adres<<endl;
    }
};

class Ogrenci : public universite
{
private:
    string ogrNo,bolum,durum;
    double vize,fnl,ort;

public:
    void ogrBilgiGirisi()
    {
        bilgiGirisi();
        cout<<"Ogr No : ";cin>>ogrNo;
        int sec;
        cout<<"1- Bilgisayar Muhendisligi\n2-Kimya\n3-Elektrik";
        cout<<"\nBolum Secin : ";cin>>sec;
        if(sec == 1)
            bolum = "Bilgisayar Muhendisligi";
        else if(sec == 2)
            bolum = "Kimya";
        else
            bolum = "Elektrik";
        cout<<endl;

    }

    void ogrNotGirisi()
    {
        cout<<"\nVize : ";cin>>vize;
        cout<<"Final : ";cin>>fnl;
        ort = vize*0.4+fnl*0.6;
        if(ort>65)
            durum = "BASARILI";
        else
            durum = "BASARISIZ";
    }

    void ogrNotGuncelle()
    {
        ogrNotGirisi();
        ogrYazdir();
    }

    void ogrYazdir()
    {
        Yazdir();
        cout<<"Ogrenci No : "<<ogrNo<<endl<<"Bolum : "<<bolum<<endl<<"Ortalama : "<<ort<<endl<<"Durum : "<<durum<<endl;
    }

};

class Ogretmen : private universite
{
private:
    string brans;
    double maas,ekDersSaati,ekDersUcreti,netMaas,bilgisayar,elektrik,makine;
public:
    Ogretmen()
    {
        bilgisayar = 30;
        elektrik = 40;
        makine = 50;
        maas = 3000;
    }
    void ogrtBilgiGirisi()
    {
        bilgiGirisi();
        cout<<"1- Bilgisayar Muhendisiligi\n2- Elektrik\n3- Makine";
        int sec;
        cout<<"\nBrans Secin : ";cin>>sec;
        if(sec == 1)
        {
            brans = "Bilgisayar Muhendisligi";
            ekDersUcreti = bilgisayar;
        }
        else if(sec == 2)
        {
            brans = "Elektrik";
            ekDersUcreti = elektrik;
        }
        else
        {
            brans = "Makine";
            ekDersUcreti = makine;
        }

        cout<<"Maas : ";cin>>maas;
        cout<<"Ek Ders Saati ";cin>>ekDersSaati;
    }
    void ogrtEkDersUcretiHesapla()
    {
        netMaas = maas + ekDersSaati*ekDersUcreti;
    }

    void ogrtYazdir()
    {
        Yazdir();
        cout<<"Brans : "<<brans<<endl<<"Maas : "<<maas<<endl<<"Toplam Ek Ders Ucreti : "<<ekDersSaati*ekDersUcreti<<endl<<"Net Maas : "<<netMaas;
    }
};

class memur : protected universite
{
private:
    string calistigiBirim;
    double maas,mesaiSaati,mesaiUcreti,netMaas;
public:
    memur()
    {
        maas = 2500;
    }
    void mrBilgiGirisi()
    {
        bilgiGirisi();
        cout<<"Calistigi Birim : ";cin>>calistigiBirim;
        cout<<"Maas : ";cin>>maas;
        cout<<"Mesai Saati : ";cin>>mesaiSaati;
        cout<<"Saatlik Mesai Ucreti : ";cin>>mesaiUcreti;
    }
    void MrMesaiUcretiHesapla()
    {
        netMaas = maas + mesaiSaati*mesaiUcreti;
    }

    void mrYazdir()
    {
        Yazdir();
        cout<<"Calistigi Birim : "<<calistigiBirim<<endl<<"Maas : "<<maas<<endl<<"Toplam Mesai Ucreti : "<<mesaiSaati*mesaiUcreti<<endl<<"Net Maas : "<<netMaas;
    }
};
int main()
{
    int secim;
    char devam;
    do
    {
    cout<<"BILGI GIRISI\n\n";
    cout<<"1- Ogrenci\n2- Ogretmen\n3- Memur\n";
    cout<<"Seciniz : ";cin>>secim;

    switch(secim)
    {
    case 1:
        {
            Ogrenci ogr;
            ogr.ogrBilgiGirisi();

            do
            {
            cout<<"\n1- Not Girisi\n2-Not Guncelle\n3-Cikis\n";
            cout<<"Seciminiz : ";cin>>secim;


            if(secim == 1)
                ogr.ogrNotGirisi();
            else if(secim == 2)
                ogr.ogrNotGuncelle();
            cout<<"\n**YAZDIR**\n";
            ogr.ogrYazdir();
            }while(secim != 3);
            break;

        }
    case 2:
        {
            Ogretmen ogrt;
            ogrt.ogrtBilgiGirisi();
            cout<<"\n**Ogretmen Ek Ders Ucreti Hesapla**\n";
            ogrt.ogrtEkDersUcretiHesapla();
            cout<<endl;
            ogrt.ogrtYazdir();
            break;
        }
    case 3:
        {
            memur mr;
            mr.mrBilgiGirisi();

            cout<<"\n**Memur Mesai Ucreti Hesapla**\n";
            mr.MrMesaiUcretiHesapla();
            cout<<endl;
            mr.mrYazdir();
            break;
        }


    }
    cout<<"\nDevam etmek istiyor musunuz ? (e/h) : ";
    cin>>devam;
    }while(toupper(devam)== 'E' );
}
