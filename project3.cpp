#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <typeinfo>
#include <cstring>
using namespace std;
class IOinterface///clasa abstracta/interfata
{
public:
    virtual istream& citire(istream& in) =0;
    virtual ostream& afisare(ostream& out)const =0;
};
class Utilaje:public IOinterface
{
protected:
    string nume;
    double bugetIntretinere;
    int nrOreFolosit;
    bool inUz;
public:
    void setInUz(bool inUz);///setter este/nu este in uz
    double getBugetIntretinere() const;///getter buget intretinere
    bool getInUz() const;///getter este in uz?

    Utilaje& operator=(const Utilaje &uti);///supraincarcare operator =
    istream& citire(istream& in);///citire
    friend istream& operator>>(istream& in, Utilaje& uti);///supraincarcare operator citire
    ostream& afisare(ostream& out) const;///afisare
    friend ostream& operator<<(ostream&out,const Utilaje& uti);///supraincarcare operator afisare
    bool operator==(const Utilaje& u); ///supraincarcare operator==


    Utilaje();///constructor default
    Utilaje(string nume, double bugetIntretinere,int nrOreFolosit,bool inUz);///constructor cu toti patametrii
    Utilaje(const Utilaje& uti);///copy constructor

    ~Utilaje();///destructor

    void citireDinLucrare();///citire speciala pentru lucrare
    void acordareBugetIntretinere();///functionalitate=>calculare buget de intretinere
};
void Utilaje::setInUz(bool inUz)///setter este/nu este in uz
{
    this->inUz=inUz;
}
double Utilaje::getBugetIntretinere() const///getter buget intretinere
{
    return this->bugetIntretinere;
}
bool Utilaje::getInUz() const///getter este in uz?
{
    return this->inUz;
}
Utilaje& Utilaje::operator=(const Utilaje& uti)///supraincarcare operator =
{
    if(this!=&uti)
    {
        this->nume=uti.nume;
        this->bugetIntretinere=uti.bugetIntretinere;
        this->nrOreFolosit=uti.nrOreFolosit;
        this->inUz=uti.inUz;
    }
    return *this;
}
istream& Utilaje::citire(istream& in)///citire
{
    cout<<"Nume:";
    in>>this->nume;
    cout<<"Buget intretinere:";
    in>>this->bugetIntretinere;
    cout<<"Numarul de ore in care a fost utilizat:";
    in>>this->nrOreFolosit;
    this->acordareBugetIntretinere();
    cout<<"Este in uz?(0/1):";
    in>>this->inUz;
    return in;
}
istream& operator>>(istream& in, Utilaje& uti)///supraincarcare operator citire
{
    return uti.citire(in);
}
ostream& Utilaje::afisare(ostream& out) const///afisare
{
    out<<"Nume:"<<this->nume<<'\n';
    out<<"Buget intretinere:"<<this->bugetIntretinere<<'\n';
    out<<"Numarul de ore in care a fost utilizat:"<<this->nrOreFolosit<<'\n';
    out<<"Este in uz:"<<this->inUz<<'\n';
    return out;
}
ostream& operator<<(ostream& out,const Utilaje& uti)///supraincarcare operator afisare
{
    return uti.afisare(out);
}
bool Utilaje::operator==(const Utilaje& u) ///supraincarcare operator==
{
    if (this->nume.length()!=u.nume.length())
        return false;
    int n=this->nume.length();
    for(int i=0;i<n;i++)
        if(this->nume[i]!=u.nume[i])
            return false;
    return true;
}
Utilaje::Utilaje()///constructor default
{
    this->nume="nume";
    this->bugetIntretinere=0;
    this->nrOreFolosit=0;
    this->inUz=0;
}
Utilaje::Utilaje(string nume, double bugetIntretinere,int nrOreFolosit,bool inUz)///constructor cu toti patametrii
{
    this->nume=nume;
    this->bugetIntretinere=bugetIntretinere;
    this->nrOreFolosit=nrOreFolosit;
    this->acordareBugetIntretinere();
    this->inUz=inUz;
}
Utilaje::Utilaje(const Utilaje& uti)///copy constructor
{
    this->nume=uti.nume;
    this->bugetIntretinere=uti.bugetIntretinere;
    this->nrOreFolosit=uti.nrOreFolosit;
    this->inUz=uti.inUz;
}
Utilaje::~Utilaje()///destructor
{}
void Utilaje::citireDinLucrare()///citire speciala pentru lucrare
{
    cout<<"Nume:";
    cin>>this->nume;
}
void Utilaje::acordareBugetIntretinere()///functionalitate clasa Utilaje: buget intretinere
{
    if(this->nrOreFolosit>40)
        this->bugetIntretinere+=0.1*this->bugetIntretinere;
}
class UtilajeMici:public Utilaje
{
    float masa;
public:

    UtilajeMici& operator=(const UtilajeMici &utimi);///supraincarcare operator =
    istream& citire(istream& in);///citire
    ostream& afisare(ostream& out) const;///afisare


    UtilajeMici();///constructor default
    UtilajeMici(string nume,double bugetIntretinere,int nrOreFolosit, bool inUz,float masa);///constructor cu toti parametrii
    UtilajeMici(const UtilajeMici& utimi);///copy constructor
    ~UtilajeMici();///destructor

    bool incape();
};
UtilajeMici& UtilajeMici::operator =(const UtilajeMici& utimi)///spuraincarcare operator =
{
    if(this!=&utimi)
    {
        Utilaje::operator=(utimi);
        this->masa=utimi.masa;
    }
    return *this;
}
istream& UtilajeMici::citire(istream& in)///citire
{
    Utilaje::citire(in);
    cout<<"Masa:";
    in>>this->masa;
    return in;
}
ostream& UtilajeMici::afisare(ostream& out) const///afisare
{
    Utilaje::afisare(out);
    out<<"Masa:"<<this->masa<<'\n';
    return out;
}
UtilajeMici::UtilajeMici():Utilaje()///constructor default
{
    this->masa=0;
}
UtilajeMici::UtilajeMici(string nume,double bugetIntretinere,int nrOreFolosit, bool inUz,float masa):Utilaje(nume,bugetIntretinere,nrOreFolosit,inUz)///constructor cu toti parametrii
{
    this->masa=masa;
}
UtilajeMici::UtilajeMici(const UtilajeMici& utimi):Utilaje(utimi)///copy constructor
{
    this->masa=utimi.masa;
}
UtilajeMici::~UtilajeMici(){}///destructor
bool UtilajeMici::incape()///functionalitate:portabilitate
{
    if(this->masa<100)
        return true;
    else
        return false;
}
class UtilajeMari:public Utilaje
{
protected:
    bool angajatCalificat;
    int oreNecesareExperientaPeUtilaj;
public:
    UtilajeMari& operator=(const UtilajeMari &utima);///supraincarcare operator =
    istream& citire(istream& in);///citire
    ostream& afisare(ostream& out) const;///afisare

    UtilajeMari();///constructor default
    UtilajeMari(string nume,double bugetIntretinere,int nrOreFolosit, bool inUz,bool angajatCalificat);///constructor cu toti parametrii
    UtilajeMari(const UtilajeMari& utima);///copy constructor
    ~UtilajeMari();///destructor

    virtual bool avemAngajatSpecializat();///functionalitate: disponibilitate angajati calificati
};
UtilajeMari& UtilajeMari::operator =(const UtilajeMari& utima)///spuraincarcare operator =
{
    if(this!=&utima)
    {
        Utilaje::operator=(utima);
        this->angajatCalificat=utima.angajatCalificat;
        this->oreNecesareExperientaPeUtilaj=utima.oreNecesareExperientaPeUtilaj;
    }
    return *this;
}
istream& UtilajeMari::citire(istream& in)///citire
{
    Utilaje::citire(in);
    cout<<"Exista angajat calificat(0/1):";
    in>>this->angajatCalificat;
    cout<<"Numarul necesar de ore de experienta de lucru pe un astfel de utilaj:";
    in>>this->oreNecesareExperientaPeUtilaj;
    return in;
}
ostream& UtilajeMari::afisare(ostream& out) const///afisare
{
    Utilaje::afisare(out);
    if(this->angajatCalificat==true)
        out<<"Exista angajat calificat pentru acest utilaj.\n";
    else
        out<<"Nu exista angajati calificat pentru acest utilaj.\n";
    out<<"Numarul necesar de ore de experienta de lucru pe un astfel de utilaj:";
    out<<this->oreNecesareExperientaPeUtilaj;
    return out;
}
UtilajeMari::UtilajeMari():Utilaje()///constructor default
{
    this->angajatCalificat=false;
    this->oreNecesareExperientaPeUtilaj=0;
}
UtilajeMari::UtilajeMari(string nume,double bugetIntretinere,int nrOreFolosit, bool inUz,bool angajatCalificat):Utilaje(nume,bugetIntretinere,nrOreFolosit,inUz)///constructor cu toti parametrii
{
    this->angajatCalificat=angajatCalificat;
    this->oreNecesareExperientaPeUtilaj=oreNecesareExperientaPeUtilaj;
}
UtilajeMari::UtilajeMari(const UtilajeMari& utima):Utilaje(utima)///copy constructor
{
    this->angajatCalificat=utima.angajatCalificat;
    this->oreNecesareExperientaPeUtilaj=utima.oreNecesareExperientaPeUtilaj;
}
UtilajeMari::~UtilajeMari(){}///destructor
bool UtilajeMari::avemAngajatSpecializat()///functionalitate: disponibilitate angajati calificati
{
    if(angajatCalificat==1)
        return true;
    else
        return false;
}
class UtilajeFoarteMari:public UtilajeMari
{
public:
    UtilajeFoarteMari& operator=(const UtilajeFoarteMari &uti);///supraincarcare operator =
    istream& citire(istream& in);///citire
    ostream& afisare(ostream& out) const;///afisare

    UtilajeFoarteMari();///constructor default
    UtilajeFoarteMari(string nume,double bugetIntretinere,int nrOreFolosit, bool inUz,bool angajatCalificat, int oreNecesareExperientaPeUtilaj);///constructor cu toti parametrii
    UtilajeFoarteMari(const UtilajeFoarteMari& utifma);///copy constructor
    ~UtilajeFoarteMari();///destructor

    bool avemAngajatSpecializat();///functionalitate: disponibilitate angajati calificati(altfel->functii virtuale)
};
UtilajeFoarteMari& UtilajeFoarteMari::operator =(const UtilajeFoarteMari& utifma)///spuraincarcare operator =
{
    if(this!=&utifma)
    {
        UtilajeMari::operator=(utifma);
    }
    return *this;
}
istream& UtilajeFoarteMari::citire(istream& in)///citire
{
    UtilajeMari::citire(in);
    return in;
}
ostream& UtilajeFoarteMari::afisare(ostream& out) const///afisare
{
    UtilajeMari::afisare(out);
    return out;
}
UtilajeFoarteMari::UtilajeFoarteMari():UtilajeMari()///constructir default
{}
UtilajeFoarteMari::UtilajeFoarteMari(string nume,double bugetIntretinere,int nrOreFolosit, bool inUz,bool angajatCalificat,int oreNecesareExperientaPeUtilaj):UtilajeMari(nume,bugetIntretinere,nrOreFolosit,inUz,angajatCalificat)///constructor cu toti parametrii
{}
UtilajeFoarteMari::UtilajeFoarteMari(const UtilajeFoarteMari& utifma):UtilajeMari(utifma)///copy constructor
{}
UtilajeFoarteMari::~UtilajeFoarteMari(){}///destructor
bool UtilajeFoarteMari::avemAngajatSpecializat()///functionalitate: disponibilitate angajati calificati(altfel->functii virtuale)
{
    if(this->angajatCalificat==1 && this->oreNecesareExperientaPeUtilaj<20)
        return 1;
    else
        return 0;
}
class Lucrare
{
    string nume;
    int nrOreNecesare;
    int nrUtilaje;
    Utilaje* utie;
public:
    int getNrUtilaje() const;///getter numar de utilaje
    int getNrOreNecesare() const;///getter numar de ore necesare

    Lucrare& operator=(const Lucrare& lucr);///supraincarcare operator =
    friend istream&operator>>(istream &in,Lucrare &lucr);///supraincarcare operator citire
    friend ostream &operator<<(ostream& out,const Lucrare &lucr);///supraincarcare operator afisare

    Lucrare();///constructor default
    Lucrare(string nume,int nrOreNecesare,int nrUtilaje,Utilaje* utie);///constructor cu toti parametrii
    Lucrare(const Lucrare& lucr);///copy constructor
    ~Lucrare();///destructor

    bool disponibilitate(list<Utilaje*> uti);///functionalitate clasa:verificarea disponibilitatii utilajelor pentru executarea lucrarii
};
int Lucrare::getNrUtilaje() const///getter numar de utilaje
{
    return this->nrUtilaje;
}
int Lucrare::getNrOreNecesare() const///getter numar de ore necesare
{
    return this->nrOreNecesare;
}
Lucrare& Lucrare::operator=(const Lucrare& lucr)///supraincarcare operator =
{
    if(this!=&lucr)
    {
        this->nume=lucr.nume;
        this->nrOreNecesare=lucr.nrOreNecesare;
        this->nrUtilaje=lucr.nrUtilaje;
        if(this->utie!=NULL)
            delete[] this->utie;
        this->utie=new Utilaje[this->nrUtilaje];
        for(int i=0;i<this->nrUtilaje;i++)
            this->utie[i]=lucr.utie[i];
    }
    return *this;
}
istream& operator>>(istream &in,Lucrare &lucr)///supraincarcare operator citire
{
    cout<<"Nume:";
    in>>lucr.nume;
    cout<<"Numarul de ore necesar completarii lucrarii:";
    in>>lucr.nrOreNecesare;
    cout<<"Numarul necesar de utilaje:";
    in>>lucr.nrUtilaje;
    if(lucr.utie!=NULL)
        delete[] lucr.utie;
    lucr.utie=new Utilaje[lucr.nrUtilaje];
    cout<<"Utilaje:\n";
    for(int i=0;i<lucr.nrUtilaje;i++)
        lucr.utie[i].citireDinLucrare();
    return in;
}
ostream& operator<<(ostream& out,const Lucrare &lucr)///supraincarcare operator afisare
{
    out<<"Nume:"<<lucr.nume<<'\n';
    out<<"Numarul de ore necesar completarii lucrarii:"<<lucr.nrOreNecesare<<'\n';
    out<<"Numarul necesar de utilaje:"<<lucr.nrUtilaje<<'\n';
    out<<"Utilaje:\n";
    for(int i=0;i<lucr.nrUtilaje;i++)
        out<<lucr.utie[i];
    return out;
}
Lucrare::Lucrare()///constructor default
{
    this->nume="nume";
    this->nrOreNecesare=0;
    this->nrUtilaje=0;
    this->utie=NULL;
}
Lucrare::Lucrare(string nume,int nrOreNecesare,int nrUtilaje,Utilaje* utie)///constructor cu toti parametrii
{
    this->nume=nume;
    this->nrOreNecesare=nrOreNecesare;
    this->nrUtilaje=nrUtilaje;
    this->utie=new Utilaje[this->nrUtilaje];
    for(int i=0;i<this->nrUtilaje;i++)
        this->utie[i]=utie[i];
}
Lucrare::Lucrare(const Lucrare& lucr)///copy constructor
{
    this->nume=lucr.nume;
    this->nrOreNecesare=lucr.nrOreNecesare;
    this->nrUtilaje=lucr.nrUtilaje;
    this->utie=new Utilaje[this->nrUtilaje];
    for(int i=0;i<this->nrUtilaje;i++)
        this->utie[i]=lucr.utie[i];
}
Lucrare::~Lucrare()///destructor
{
    if(this->utie!=NULL)
        delete[] this->utie;
    this->utie=NULL;
}
bool Lucrare::disponibilitate(list<Utilaje*> uti)///functionalitate clasa:verificarea disponibilitatii utilajelor pentru executarea lucrarii
{
    int ok;
    for(int j=0;j<this->nrUtilaje;j++)
    {
        ok=0;
        list<Utilaje*>::iterator it;
        for (it = uti.begin(); it != uti.end(); ++it)
        {
            if((*it)->getInUz()==0&&**it==this->utie[j])
            {
                ok=1;
                (*it)->setInUz(1);
                break;
            }
        }
    if(ok==0)
        return false;
    }
    return true;
}
class Facturare
{
    string numeClient;
    Lucrare lucrare;
    string dataInceput;
    double sumaTotala;
    map <string,double> ramasDePlataLaData;
public:
    string getDataInceput() const;
    Facturare & operator=(const Facturare &fact);///supraincarcare operator =
    friend istream &operator >>(istream & in, Facturare& fact);///supraincarcare operator citire
    friend ostream &operator <<(ostream& out, const Facturare& fact);///supraincarcare operator afisare
    Facturare();///constructor default
    Facturare(string numeClient,Lucrare lucrare,string dataInceput, double sumaTotala, map<string,double> dateEsentiale);///constructor cu toti parametrii
    ~Facturare();///destructor
    string adaugareSumaRamasaInIstoric(double plata);///functionalitate clasa=plata

};
string Facturare::getDataInceput() const
{
    return this->dataInceput;
}
Facturare & Facturare::operator=(const Facturare &fact)///supraincarcare operator =
{
    if(this!=&fact)
    {
        this->numeClient=fact.numeClient;
        this->lucrare=fact.lucrare;
        this->dataInceput=fact.dataInceput;
        this->sumaTotala=fact.sumaTotala;
    }
    return *this;
}
istream &operator >>(istream & in, Facturare& fact)///supraincarcare operator citire
{
    cout<<"Introduceti numele clientului:\n";
    in>>fact.numeClient;
    cout<<"Introduceti lucrarea care urmeaza sa fie executata:\n";
    in>>fact.lucrare;
    cout<<"Introuduceti data inceperii platii(zz/ll/aaaa):";
    in>>fact.dataInceput;
    cout<<"Introduceti suma totala:";
    in>>fact.sumaTotala;
    if(fact.ramasDePlataLaData.empty()!=true)
        fact.ramasDePlataLaData.clear();///curata map-ul pt a o lua de la capat cand citim o noua factura
    fact.ramasDePlataLaData[fact.dataInceput]=fact.sumaTotala;
    return in;
}
ostream &operator <<(ostream& out, const Facturare& fact)///supraincarcare operator afisare
{
    out<<"Clientul "<<fact.numeClient<<" are lucrarea:\n"<<fact.lucrare<<'\n';
    out<<"Suma totala de plata este:"<<fact.sumaTotala<<'\n';
    out<<"Istoricul platii:\n";
    map<string,double>::const_iterator it;
    for(it=fact.ramasDePlataLaData.begin();it!=fact.ramasDePlataLaData.end();++it)
        out<<"->la data:"<<it->first<<" a ramas de plata:"<<it->second<<'\n';

    return out;
}
Facturare::Facturare()///constructor default
{
    this->numeClient="Anonim";
    this->dataInceput="zz/ll/aaaa";
    this->sumaTotala=0;
    if(this->ramasDePlataLaData.empty()!=true)
        this->ramasDePlataLaData.clear();///curata map-ul pt a o lua de la capat cand avem o noua factura
}
Facturare::Facturare(string numeClient,Lucrare lucrare,string dataInceput, double sumaTotala, map<string,double> dateEsentiale)///constructor cu toti parametrii
{
    this->numeClient=numeClient;
    this->lucrare=lucrare;
    this->dataInceput=dataInceput;
    this->sumaTotala=sumaTotala;
    if(this->ramasDePlataLaData.empty()!=true)
        this->ramasDePlataLaData.clear();///curata map-ul pt a o lua de la capat cand avem o noua factura
    this->ramasDePlataLaData[this->dataInceput]=this->sumaTotala;
}
Facturare::~Facturare()///destructor
{}
string Facturare::adaugareSumaRamasaInIstoric(double plata)///functionalitate clasa=plata
{
    string data;

    if(this->ramasDePlataLaData.rbegin()->second==0)
    {
        cout<<"Lucrarea este platita.";
        return "Nu mai aveti ce plati";
    }
    else
    {
        cout<<"Introduceti data(zz/ll/aaaa):";
        cin>>data;
        if(this->ramasDePlataLaData.rbegin()->second<plata)
        {
            cout<<"Lucrarea este platita. Restul dumneavoastra este:"<<plata-this->ramasDePlataLaData.rbegin()->second;
            this->ramasDePlataLaData.insert({data,0});
        }
        else
        {
            cout<<"O parte din plata a fost efectuata. Mai aveti de platit:"<<this->ramasDePlataLaData.rbegin()->second-plata;
            this->ramasDePlataLaData.insert({data,this->ramasDePlataLaData.rbegin()->second-plata});
        }
        return data;
    }

}
template <class T>///clasa template
class Indice
{
    T indice;
public:
    T getIndice() const;///setter
    void setIndice(T indice);///getter

    Indice(T indice=0);///constructor
    friend istream& operator >>(istream&in, Indice<T>& ind)///supraincarcare citire
    {
    in>>ind.indice;
    return in;
    }
    friend ostream& operator <<(ostream& out,const Indice<T>& ind)///supraincarcare afisare
    {
    out<<ind.indice;
    return out;
}
};
template <typename T>
Indice<T>::Indice(T indice)///constructor
{
    this->indice=indice;
}
template<typename T>
T Indice<T>::getIndice() const///getter
{
    return this->indice;
}
template<typename T>
void Indice<T>::setIndice(T indice)///setter
{
    this->indice=indice;
}


class MeniuInteractiv///clasa Singleton
{
private:
    static MeniuInteractiv *obiect;
    MeniuInteractiv(){}
public:
    static MeniuInteractiv* getInstance()
    {
        if(!obiect)
            obiect=new MeniuInteractiv();
        return obiect;
    }
    void meniu()///meniu interactiv
    {
        list<Utilaje*> uti;
        vector<UtilajeMici*> utimi;
        vector<UtilajeMari*> utima;
        vector<UtilajeMari*> utifma;
        vector<Lucrare> lucr;
        vector<Facturare> facta;
        set<string> dateImportante;///date in care s-au efectuat plati si data curenta

        Utilaje uti1;
        UtilajeMici utimi1;
        UtilajeMari utima1;
        UtilajeFoarteMari utifma1;
        Lucrare lucr1;
        Facturare fact1;
        int i;
        string data;
        double plataDvs;

        Indice<int> op,op1,op2,op3,op4,op5,indice,ok,op6;
        ok.setIndice(1);
        Indice<bool> optIesireIntrare;
        while(ok.getIndice()!=0)
        {
            if(ok.getIndice()==2)
            {
                cout<<"\nMai vreti sa lucrati? Tastati 1 daca da sau 0 daca nu.\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>optIesireIntrare;
                if(optIesireIntrare.getIndice()==0)
                    {ok.setIndice(0);break;}
            }
            else
            {
                cout<<"Introduceti data de azi(zz/ll/aaaa):";
                cin>>data;
                dateImportante.insert(data);
                ok.setIndice(2);
            }
            cout<<"Alegeti categoria cu care vreti sa lucrati:\n";
            cout<<"1=>Utilaje\n2=>Utilaje mici\n3=>Utilaje mari\n4=>Utilaje foarte mari\n5=>Lucrare\n6=>Facturare\n7=>Afisare date importante\n";
            cout<<"Optiunea dumneavoastra:";cin>>op;
            while(op.getIndice()>7||op.getIndice()<1)
            {
                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                cout<<"Alegeti categoria cu care vreti sa lucrati:\n";
                cout<<"1=>Utilaje\n2=>Utilaje mici\n3=>Utilaje mari\n4=>Utilaje foarte mari\n5=>Lucrare\n6=>Facturare\n7=>Afisare date importante\n";
                cout<<"Optiunea dumneavoastra:";cin>>op;
            }
            switch(op.getIndice())
            {
                case 1:
                    cout<<"\nAti ales optiunea \"Utilaje\".\n";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare utilaj\n2=>Afisare totala\n3=>Stergere un utilaj\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op1;
                    while(op1.getIndice()>3||op1.getIndice()<1)
                    {
                        cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                        cout<<"Alegeti ce doriti sa faceti:\n";
                        cout<<"1=>Adaugare utilaj\n2=>Afisare totala\n3=>Stergere un utilaj\n";
                        cout<<"Optiunea dumneavoastra:";
                        cin>>op1;
                    }
                    switch(op1.getIndice())
                    {
                        case 1:
                        {
                            cout<<"\nAti ales optiunea \"Adaugare utilaj\".\n";
                            uti1.citire(cin);
                            uti.push_back(new Utilaje(uti1));
                            break;
                        }
                        case 2:
                        {
                            cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                            if(uti.size()<1)
                            {
                                cout<<"Introduceti utilaje mai intai.";
                                break;
                            }
                            list<Utilaje*>::iterator it;
                            for (it = uti.begin(); it != uti.end(); ++it)
                                cout<<**it;
                            break;
                        }
                        case 3:
                        {
                            cout<<"\nAti ales optiunea \"Stergere un utilaj\".\n";
                            if(uti.size()<1)
                            {
                                cout<<"Nu exista utilaje introduse.";
                                break;
                            }
                            cout<<"Ce utilaj vreti sa stergeti?";
                            cin>>uti1;
                            list<Utilaje*>::iterator it;
                            for (it = uti.begin(); it != uti.end(); ++it)
                                if(uti1==**it)
                                    if(typeid(**it)==typeid(utimi1))
                                    {
                                        for(i=0;i<utimi.size();i++)
                                            if(*utimi[i]==**it)
                                        utimi.erase(utimi.begin()+i);
                                        uti.erase(it);
                                        break;
                                    }
                                    else
                                        if(typeid(**it)==typeid(utima1))
                                        {
                                            for(i=0;i<utima.size();i++)
                                                if(*utima[i]==**it)
                                            utima.erase(utima.begin()+i);
                                            uti.erase(it);
                                            break;
                                        }
                                        else
                                            if(typeid(**it)==typeid(utifma1))
                                            {
                                                for(i=0;i<utifma.size();i++)
                                                    if(*utifma[i]==**it)
                                                        utifma.erase(utifma.begin()+i);
                                                uti.erase(it);
                                                break;
                                            }
                                            else
                                                uti.erase(it);
                            break;
                        }
                    }
                    break;
                case 2:
                    cout<<"\nAti ales optiunea \"Utilaje mici\".\n";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare utilaj mic\n2=>Afisare utilaj mic\n3=>Afisare totala\n4=>Stergere un utilaj mic\n5=>Portabilitate\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op2;
                    while(op2.getIndice()>5||op2.getIndice()<1)
                    {
                        cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                        cout<<"Alegeti ce doriti sa faceti:\n";
                        cout<<"1=>Adaugare utilaj mic\n2=>Afisare utilaj mic\n3=>Afisare totala\n4=>Stergere un utilaj mic\n5=>Portabilitate\n";
                        cout<<"Optiunea dumneavoastra:";
                        cin>>op2;
                    }
                    switch(op2.getIndice())
                    {
                        case 1:
                        {
                            cout<<"\nAti ales optiunea \"Adaugare utilaj mic\".\n";
                            utimi1.citire(cin);
                            uti.push_back(new UtilajeMici(utimi1));
                            utimi.push_back(new UtilajeMici(utimi1));
                            break;
                        }
                        case 2:
                            cout<<"\nAti ales optiunea \"Afisare utilaj mic\".\n";
                            if(utimi.size()<1)
                            {
                                cout<<"Introduceti utilaje mai intai.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului mic dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utimi.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului mic dorit:";
                                cin>>indice;
                            }
                            cout<<'\n'<<*utimi[indice.getIndice()-1];
                            break;
                        case 3:
                            cout<<"\nAti ales optiunea \"Afisare totala utilaje mici\".\n";
                            if(utimi.size()<1)
                            {
                                cout<<"Introduceti utilaje mici mai intai.";
                                break;
                            }
                            for(i=0;i<utimi.size();i++)
                                cout<<*utimi[i]<<endl;
                            break;
                        case 4:
                        {
                            cout<<"\nAti ales optiunea \"Stergere un utilaj mic\".\n";
                            if(utimi.size()<1)
                            {
                                cout<<"Nu exista utilaje introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului mic dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utimi.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului mic dorit:";
                                cin>>indice;
                            }
                            list<Utilaje*>::iterator it;
                            for (it = uti.begin(); it != uti.end(); ++it)
                                if(*utimi[indice.getIndice()-1]==**it)
                                {
                                    uti.erase(it);
                                    break;
                                }
                            utimi.erase(utimi.begin()+indice.getIndice()-1);
                            break;
                            }
                        case 5:
                            cout<<"\nAti ales optiunea \"Portabilitate\".\n";
                            if(utimi.size()<1)
                            {
                                cout<<"Nu exista utilaje introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului mic dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utimi.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului mic dorit:";
                                cin>>indice;
                            }
                            if(utimi[indice.getIndice()-1]->incape())
                                cout<<"Utilajul este portabil.";
                            else
                                cout<<"Utilajul nu este portabil.";

                    }
                    break;
                case 3:
                    cout<<"\nAti ales optiunea \"Utilaje mari\".\n";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare utilaj mare\n2=>Afisare utilaj mare\n3=>Afisare totala utilaje mari\n4=>Stergere un utilaj mare\n5=>Disponibilitate angajat calificat\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op3;
                    while(op3.getIndice()>5||op3.getIndice()<1)
                    {
                        cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                        cout<<"Alegeti ce doriti sa faceti:\n";
                        cout<<"1=>Adaugare utilaj mare\n2=>Afisare utilaj mare\n3=>Afisare totala utilaje mari\n4=>Stergere un utilaj mare\n5=>Disponibilitate angajat calificat\n";
                        cout<<"Optiunea dumneavoastra:";
                        cin>>op3;
                    }
                    switch(op3.getIndice())
                    {
                        case 1:
                        {
                            cout<<"\nAti ales optiunea \"Adaugare utilaj mare\".\n";
                            utima1.citire(cin);
                            uti.push_back(new UtilajeMari(utima1));
                            utima.push_back(new UtilajeMari(utima1));
                            break;
                        }
                        case 2:
                            cout<<"\nAti ales optiunea \"Afisare utilaj mare\".\n";
                            if(utima.size()<1)
                            {
                                cout<<"Introduceti utilaje mari mai intai.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului mare dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utima.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului mare dorit:";
                                cin>>indice;
                            }
                            cout<<'\n'<<*utima[indice.getIndice()-1];
                            break;
                        case 3:
                            cout<<"\nAti ales optiunea \"Afisare totala utilaje mari\".\n";
                            if(utima.size()<1)
                            {
                                cout<<"Introduceti utilaje mari mai intai.";
                                break;
                            }
                            for(i=0;i<utima.size();i++)
                                cout<<*utima[i]<<endl;
                            break;
                        case 4:
                            {cout<<"\nAti ales optiunea \"Stergere un utilajmare\".\n";
                            if(utima.size()<1)
                            {
                                cout<<"Nu exista utilaje mari introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului mare dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utima.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului mare dorit:";
                                cin>>indice;
                            }
                            list<Utilaje*>::iterator it;
                            for (it = uti.begin(); it != uti.end(); ++it)
                                if(*utima[indice.getIndice()-1]==**it)
                                {
                                    uti.erase(it);
                                    break;
                                }
                            utima.erase(utima.begin()+indice.getIndice()-1);

                            break;
                    }
                        case 5:
                            cout<<"\nAti ales optiunea \"Disponibilitate angajat calificat\".\n";
                            if(utima.size()<1)
                            {
                                cout<<"Nu exista utilaje mari introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului mare dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utima.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului mare dorit:";
                                cin>>indice;
                            }
                            if(utima[indice.getIndice()-1]->avemAngajatSpecializat())
                                cout<<"Exista persoane calificate pentru a lucra cu acest utilaj.";
                            else
                                cout<<"Nu exista persoane calificate pentru a lucra cu acest utilaj.";
                            break;

                    }
                    break;
                case 4:
                    cout<<"\nAti ales optiunea \"Utilaje foarte mari\".\n";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare utilaj foarte mare\n2=>Afisare utilaj foarte mare\n3=>Afisare totala utilaje mari\n4=>Stergere un utilaj foarte mare\n5=>Disponibilitate angajat calificat\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op4;
                    while(op4.getIndice()>5||op4.getIndice()<1)
                    {
                        cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                        cout<<"Alegeti ce doriti sa faceti:\n";
                        cout<<"1=>Adaugare utilaj foarte mare\n2=>Afisare utilaj foarte mare\n3=>Afisare totala utilaje mari\n4=>Stergere un utilaj foarte mare\n5=>Disponibilitate angajat calificat\n";
                        cout<<"Optiunea dumneavoastra:";
                        cin>>op4;
                    }
                    switch(op4.getIndice())
                    {
                        case 1:
                        {
                            cout<<"\nAti ales optiunea \"Adaugare utilaj foarte mare\".\n";
                            utifma1.citire(cin);
                            uti.push_back(new UtilajeFoarteMari(utifma1));
                            utifma.push_back(new UtilajeFoarteMari(utifma1));
                            break;
                        }
                        case 2:
                            cout<<"\nAti ales optiunea \"Afisare utilaj foarte mare\".\n";
                            if(utifma.size()<1)
                            {
                                cout<<"Introduceti utilaje foarte mari mai intai.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului foarte mare dorit:";
                            cin>>indice;
                            while(indice.getIndice()>uti.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului foarte mare dorit:";
                                cin>>indice;
                            }
                            cout<<'\n'<<*utifma[indice.getIndice()-1];
                            break;
                        case 3:
                            cout<<"\nAti ales optiunea \"Afisare totala utilaje foarte mari\".\n";
                            if(utifma.size()<1)
                            {
                                cout<<"Introduceti utilaje foarte mari mai intai.";
                                break;
                            }
                            for(i=0;i<utifma.size();i++)
                                cout<<*utifma[i]<<endl;
                            break;
                        case 4:
                            {cout<<"\nAti ales optiunea \"Stergere un utilaj foarte mare\".\n";
                            if(utifma.size()<1)
                            {
                                cout<<"Nu exista utilaje foarte mari introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului foarte mare dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utifma.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului foarte mare dorit:";
                                cin>>indice;
                            }
                            list<Utilaje*>::iterator it;
                            for (it = uti.begin(); it != uti.end(); ++it)
                                if(*utifma[indice.getIndice()-1]==**it)
                                {
                                    uti.erase(it);
                                    break;
                                }
                            utifma.erase(utifma.begin()+indice.getIndice()-1);
                            break;
                            }
                        case 5:
                            cout<<"\nAti ales optiunea \"Disponibilitate angajat calificat\".\n";
                            if(utifma.size()<1)
                            {
                                cout<<"Nu exista utilaje foarte mari introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele utilajului foarte mare dorit:";
                            cin>>indice;
                            while(indice.getIndice()>utifma.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele utilajului foarte mare dorit:";
                                cin>>indice;
                            }
                            //if(utifma[indice.getIndice()-1]->avemAngajatSpecializat() )
                            if((dynamic_cast<UtilajeFoarteMari*>(utifma[indice.getIndice()-1]))->avemAngajatSpecializat())
                                cout<<"Exista persoane calificate pentru a lucra cu acest utilaj.";
                            else
                                cout<<"Nu exista persoane calificate pentru a lucra cu acest utilaj.";
                            break;

                    }
                    break;
                case 5:
                    cout<<"\nAti ales optiunea \"Lucrare\".\n";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare lucrare\n2=>Afisare lucrare\n3=>Afisare totala\n4=>Stergerea unei lucrari\n5=>Disponibilitate utilaje\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op5;
                    while(op5.getIndice()>5||op5.getIndice()<1)
                    {
                        cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                        cout<<"Alegeti ce doriti sa faceti:\n";
                        cout<<"1=>Adaugare lucrare\n2=>Afisare lucrare\n3=>Afisare totala\n4=>Stergerea unei lucrari\n5=>Disponibilitate utilaje\n";
                        cout<<"Optiunea dumneavoastra:";
                        cin>>op5;
                    }
                    switch(op5.getIndice())
                    {
                        case 1:
                            cout<<"\nAti ales optiunea \"Adaugare lucrare\".\n";
                            cin>>lucr1;
                            lucr.push_back(lucr1);
                            break;
                        case 2:
                            cout<<"\nAti ales optiunea \"Afisare lucrare\".\n";
                            if(lucr.size()<1)
                            {
                                cout<<"Introduceti lucrari mai intai.";
                                break;
                            }
                            cout<<"Introduceti indicele lucrarii dorite:";
                            cin>>indice;
                            while(indice.getIndice()>lucr.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele lucrarii dorite:";
                                cin>>indice;
                            }
                            cout<<'\n'<<lucr[indice.getIndice()-1];
                            break;
                        case 3:
                            cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                            if(lucr.size()<1)
                            {
                                cout<<"Introduceti lucrari mai intai.";
                                break;
                            }
                            for(i=0;i<lucr.size();i++)
                                cout<<lucr[i]<<endl;
                            break;
                        case 4:
                            cout<<"\nAti ales optiunea \"Stergere o lucrare\".\n";
                            if(lucr.size()<1)
                            {
                                cout<<"Nu exista lucrari introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele lucrarii dorite:";
                            cin>>indice;
                            while(indice.getIndice()>lucr.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele lucrarii dorite:";
                                cin>>indice;
                            }
                            lucr.erase(lucr.begin()+indice.getIndice()-1);
                            break;
                        case 5:
                            cout<<"\nAti ales optiunea \"Disponibilitate utilaje\".\n";
                            cout<<"Introduceti indicele lucrarii dorite:";
                            cin>>indice;
                            if(uti.size()<1)
                            {
                                cout<<"Nu exista utilaje.\n";
                                break;
                            }
                            while(indice.getIndice()>lucr.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele lucrarii dorite:";
                                cin>>indice;
                            }
                            if(uti.size()<lucr[indice.getIndice()-1].getNrUtilaje())
                            {
                                cout<<"Nu exista suficiente utilaje pentru a face aceasta lucrare.\n";
                                break;
                            }
                            if(lucr[indice.getIndice()-1].disponibilitate(uti)==1)
                                cout<<"Lucrarea poate fi realizata. Firma are suficiente utilaje disponibile.\n";
                            else
                                 cout<<"Lucrarea nu poate fi realizata. Firma nu are suficiente utilaje disponibile. \n";
                            break;

                    }
                    break;
                    case 6:
                        cout<<"\nAti ales optiunea \"Facturare\".\n";
                        cout<<"Alegeti ce doriti sa faceti:\n";
                        cout<<"1=>Adaugare factura\n2=>Afisare factura\n3=>Afisare totala\n4=>Stergerea unei facturi\n5=>Plata\n";
                        cout<<"Optiunea dumneavoastra:";
                        cin>>op6;
                        while(op6.getIndice()>5||op6.getIndice()<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Alegeti ce doriti sa faceti:\n";
                            cout<<"1=>Adaugare factura\n2=>Afisare factura\n3=>Afisare totala\n4=>Stergerea unei facturi\n5=>Plata\n";
                            cout<<"Optiunea dumneavoastra:";
                            cin>>op6;
                        }
                        switch(op6.getIndice())
                        {
                        case 1:
                            cin>>fact1;
                            facta.push_back(fact1);
                            dateImportante.insert(fact1.getDataInceput());
                            break;
                        case 2:
                            cout<<"\nAti ales optiunea \"Afisare factura\".\n";
                            if(facta.size()<1)
                            {
                                cout<<"Introduceti facturi mai intai.";
                                break;
                            }
                            cout<<"Introduceti indicele factuii dorite:";
                            cin>>indice;
                            while(indice.getIndice()>facta.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele facturii dorite:";
                                cin>>indice;
                            }
                            cout<<'\n'<<facta[indice.getIndice()-1];
                            break;
                        case 3:
                            cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                            if(facta.size()<1)
                            {
                                cout<<"Introduceti facturi mai intai.";
                                break;
                            }
                            for(i=0;i<facta.size();i++)
                                cout<<facta[i]<<endl;
                            break;
                        case 4:
                            cout<<"\nAti ales optiunea \"Stergere o factura\".\n";
                            if(facta.size()<1)
                            {
                                cout<<"Nu exista facturi introduse.";
                                break;
                            }
                            cout<<"Introduceti indicele facturii dorite:";
                            cin>>indice;
                            while(indice.getIndice()>facta.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele facturii dorite:";
                                cin>>indice;
                            }
                            facta.erase(facta.begin()+indice.getIndice()-1);
                            break;
                        case 5:
                            cout<<"\nAti ales optiunea \"Plata\".\n";
                            if(facta.size()<1)
                            {
                                cout<<"Introduceti facturi mai intai.";
                                break;
                            }
                            cout<<"Introduceti indicele facturii dorite:";
                            cin>>indice;
                            while(indice.getIndice()>facta.size()||indice.getIndice()<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Introduceti indicele facturii dorite:";
                                cin>>indice;
                            }
                            cout<<"Introduceti suma pe care doriti sa o platiti:";
                            cin>>plataDvs;
                            data=facta[indice.getIndice()-1].adaugareSumaRamasaInIstoric(plataDvs);
                            if(data.compare("Nu mai aveti ce plati")!=0)
                                dateImportante.insert(data);
                            break;
                        }
                        break;
                    case 7:
                        cout<<"\nAti ales optiunea \"Afisare date importante\".\n";
                        cout<<"Datele importante sunt:\n";
                        for(set<string>::iterator it = dateImportante.begin();it!=dateImportante.end();it++)
                            cout<<*it<<'\n';
                        break;
            }
        }
    }
};
MeniuInteractiv* MeniuInteractiv::obiect=0;
int main()
{
    MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
    return 0;
}
