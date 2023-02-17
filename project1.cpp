#include <iostream>
#include <cstring>
#include <cmath>
/*
Ordinea:
clasa cu atribute si antetul functiilor(setteri,getteri,supraincarcare operatori,constructori,destructor)
corpul functiilor(in ordinea din paranteza anterioara)
Pentru supraincarcare cast explicit corpul functiei este langa antet, in interiorul clasei.
*/
using namespace std;
class Utilaje{
    char* nume;
    double bugetIntretinere;
    long oreFolosite;
    bool inUz;///este folosit deja la o alta lucrare sau este liber
public:
    void setBugetIntretinere(double bugetIntretinere);///setter double
    void setOreFolosite(long oreFolosite);///setter long
    void setInUz(bool inUz);///setter bool

    double getBugetIntretinere() const;///getter double
    long getOreFolosite() const;///getter long
    bool getInUz() const;///getter bool
    const char* getNume() const;///getter char*

    friend istream&operator>>(istream &in,Utilaje &u);///supraincarcare operator citire
    friend ostream &operator<<(ostream& out,const Utilaje &u);///supraincarcare operator afisare
    Utilaje& operator=(const Utilaje& uti);///supraincarcare operator =
    char& operator[]( int index);///supraincarcare operator indexare
    double operator+(double a);///supraincarcare operator adunare la dreapta a+2
    friend double operator+ (double a, Utilaje u);///supraincarcarea operator adunare la stanga 2+a
    double operator+ (Utilaje u);///supraincarcare operator pt adunare pe 2 obiecte din clasa
    Utilaje operator-(int a);///supraincarcare operator scadere la dreapta a-2
    friend Utilaje operator- (int a, Utilaje u);///supraincarcarea operator scadere la stanga 2-a
    Utilaje operator- (Utilaje u);///supraincarcare operator pt scadere pe 2 obiecte din clasa
    explicit operator int()///supraincarcare operator cast explicit
    {return (int)this->bugetIntretinere;}
    operator double() const;///supraincarcare operator cast implicit
    Utilaje &operator++();///supraincarcare operatot preincrementare
    Utilaje operator++(int);///supraincarcare operatot postincrementare
    bool operator==(const Utilaje& u); ///supraincarcare operator==
    bool operator<(const Utilaje& u);///supraincarcare operator <

    Utilaje();///constructor default
    Utilaje(char* nume);///constructor pt utilaje noi fara costuri de intretinere
    Utilaje(char* nume,double bugetIntretinere);///constructor pt utilaje noi
    Utilaje(char*nume, double bugetIntretinere, long oreFolosite,bool inUz);///constructor cu toti parametrii
    Utilaje(const Utilaje&uti);///copy constructor

    ~Utilaje();///destructor

    void Afisare();///functie de afisare
    void Citire();///functie de citire
};
void Utilaje::setBugetIntretinere(double bugetIntretinere)///setter double
{
    this->bugetIntretinere=bugetIntretinere;
}
void Utilaje::setOreFolosite(long oreFolosite)///setter long
{
    this->oreFolosite=oreFolosite;
}
void Utilaje::setInUz(bool inUz)///setter bool
{
    this->inUz=inUz;
}
double Utilaje::getBugetIntretinere() const///getter double
{
    return this->bugetIntretinere;
}
long Utilaje::getOreFolosite() const///getter long
{
    return this->oreFolosite;
}
bool Utilaje::getInUz() const///getter bool
{
    return this->inUz;
}
const char* Utilaje::getNume() const///getter char*
{
    return this->nume;
}
istream&operator>>(istream &in,Utilaje &u)///supraincarcare operator citire
{
    cout<<"Introduceti numele utilajului:";
    if(u.nume!=NULL)
        delete[] u.nume;
    char nume1[100];
    in>>nume1;
    u.nume=new char[strlen(nume1)+1];
    strcpy(u.nume,nume1);
    cout<<"Introduceti bugetul de intretinere:";
    in>>u.bugetIntretinere;
    cout<<"Introduceti numarul de ore in care a fost utilizat:";
    in>>u.oreFolosite;
    cout<<"Introduceti 0/1 daca utilajul nu este/este in uz:";
    in>>u.inUz;
    return in;
}
ostream &operator<<(ostream& out,const Utilaje &u)///supraincarcare operator afisare
{
    out<<"Nume utilaj:"<<u.nume<<'\n';
    out<<"Bugetul de intretinere:"<<u.bugetIntretinere<<'\n';
    out<<"Numarul de ore in care a fost utilizat:"<<u.oreFolosite<<'\n';
    out<<"Utilajul este in uz? ";
    if(u.inUz==0)
        out<<"Nu\n";
    else
        out<<"Da\n";
    return out;
}
Utilaje& Utilaje::operator=(const Utilaje& uti)///supraincarcare operator =
{
    if(this!=&uti)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(uti.nume)+1];
        strcpy(this->nume,uti.nume);
        this->bugetIntretinere=uti.bugetIntretinere;
        this->oreFolosite=uti.oreFolosite;
        this->inUz=uti.inUz;
    }
    return *this;
}
char& Utilaje::operator[]( int index)///supraincarcare operator indexare
{
    if (0 <= index && index <strlen(this->nume))
        return this->nume[index];
    cout << "Index introdus gresit";
}
double Utilaje::operator+(double a)///supraincarcare operator adunare la dreapta a+2
{
    Utilaje aux(*this);
    aux.bugetIntretinere+=a;
    return aux.bugetIntretinere;
}
double operator+ (double a, Utilaje u)///supraincarcarea operator adunare la stanga 2+a
{
    u.bugetIntretinere+=a;
    return u.bugetIntretinere;
}
double Utilaje::operator+ (Utilaje u)///supraincarcare operator pt adunare pe 2 obiecte din clasa
{
    u.bugetIntretinere+=this->bugetIntretinere;
    return u.bugetIntretinere;
}
Utilaje Utilaje::operator-(int a)///supraincarcare operator scadere la dreapta a-2
{
    Utilaje aux(*this);
    aux.bugetIntretinere-=a;
    return aux;
}
Utilaje operator- (int a, Utilaje u)///supraincarcarea operator scadere la stanga 2-a
{
    u.bugetIntretinere=a-u.bugetIntretinere;
    return u;
}
Utilaje Utilaje::operator- (Utilaje u)///supraincarcare operator pt scadere pe 2 obiecte din clasa
{
    u.bugetIntretinere=this->bugetIntretinere-u.bugetIntretinere;
    return u;
}

Utilaje::operator double() const///supraincarcare operator cast implicit
{
    return this->bugetIntretinere;
}
Utilaje& Utilaje::operator++()///supraincarcare operatot preincrementare
{
    this->oreFolosite++;
    return *this;
}
Utilaje Utilaje::operator++(int)///supraincarcare operatot postincrementare
{
    Utilaje aux(*this);
    this->oreFolosite++;
    return aux;
}
bool Utilaje::operator==(const Utilaje& u) ///supraincarcare operator==
{
    if (strcmp(this->nume,u.nume))
        return false;
    return true;
}
bool Utilaje::operator<(const Utilaje& u)///supraincarcare operator <
{
    if (this->bugetIntretinere < u.bugetIntretinere)
        return true;
    return false;
}
Utilaje::Utilaje()///constructor default
{
    this->nume=new char[strlen("nume utilaj")+1];
    strcpy(this->nume,"nume utilaj");
    this->bugetIntretinere=0;
    this->oreFolosite=0;
    this->inUz=0;
}
Utilaje::Utilaje(char* nume)///constructor pt utilaje noi fara costuri de intretinere
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->bugetIntretinere=0;
    this->oreFolosite=0;
    this->inUz=0;
}
Utilaje::Utilaje(char* nume,double bugetIntretinere)///constructor pt utilaje noi
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->bugetIntretinere=bugetIntretinere;
    this->oreFolosite=0;
    this->inUz=0;
}
Utilaje::Utilaje(char*nume, double bugetIntretinere, long oreFolosite,bool inUz)///constructor cu toti parametrii
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->bugetIntretinere=bugetIntretinere;
    this->oreFolosite=oreFolosite;
    this->inUz=inUz;
}
Utilaje::Utilaje(const Utilaje&uti)///copy constructor
{
    this->nume=new char[strlen(uti.nume)+1];
    strcpy(this->nume,uti.nume);
    this->bugetIntretinere=uti.bugetIntretinere;
    this->oreFolosite=uti.oreFolosite;
    this->inUz=uti.inUz;
}
Utilaje::~Utilaje()///destructor
{
    if(this->nume!=NULL)
        delete[] this->nume;
}
void Utilaje::Citire()
{
    cout<<"Introduceti numele utilajului:";
    if(this->nume!=NULL)///verificam daca zona de memorie este ocupata, iar in ca afirmativ o eliberam
        delete[] this->nume;
    char nume1[100];
    cin>>nume1;
    this->nume=new char[strlen(nume1)+1];
    strcpy(this->nume,nume1);
    cout<<"Introduceti bugetul de intretinere:";
    cin>>this->bugetIntretinere;
    cout<<"Introduceti numarul de ore in care a fost utilizat:";
    cin>>this->oreFolosite;
    cout<<"Introduceti 0/1 daca utilajul nu este/este in uz:";
    cin>>this->inUz;
}
void Utilaje::Afisare()
{
    cout<<"Nume utilaj:"<<this->nume<<'\n';
    cout<<"Bugetul de intretinere:"<<this->bugetIntretinere<<'\n';
    cout<<"Numarul de ore in care a fost utilizat:"<<this->oreFolosite<<'\n';
    cout<<"Utilajul este in uz? ";
    if(this->inUz==0)
        cout<<"Nu\n";
    else cout<<"Da\n";
}
class Lucrare
{
    char* nume;
    int oreNecesare;
    int nrUtilajeNecesare;
    string utilajNecesar;
    float pretPeOra;
public:
    void setPretPeOra(float pretPeOra);///setter float

    float getPretPeOra() const;///getter float

    friend istream&operator>>(istream &in,Lucrare &lucr);///supraincarcare operator citire
    friend ostream &operator<<(ostream& out,const Lucrare &lucr);///supraincarcare operator afisare
    Lucrare& operator=(const Lucrare& lucr);///supraincarcare operator =
    char& operator[]( int index);///supraincarcare operator indexare
    Lucrare operator+(float a);///supraincarcare operator adunare la dreapta a+2
    friend Lucrare operator+ (float a, Lucrare lucr);///supraincarcarea operator adunare la stanga 2+a
    Lucrare operator+ (Lucrare lucr);///supraincarcare operator pt adunare pe 2 obiecte din clasa
    Lucrare operator-(float a);///supraincarcare operator scadere la dreapta a-2
    friend Lucrare operator- (float a, Lucrare lucr);///supraincarcarea operator scadere la stanga 2-a
    Lucrare operator- (Lucrare lucr);///supraincarcare operator pt scadere pe 2 obiecte din clasa
    explicit operator int()///supraincarcare operator cast explicit
    {return (int)this->pretPeOra;}
    operator float() const;///supraincarcare operator cast implicit
    Lucrare &operator++();///supraincarcare operatot preincrementare
    Lucrare operator++(int);///supraincarcare operatot postincrementare
    bool operator==(const Lucrare& lucr);///supraincarcare operator==
    bool operator<(const Lucrare& lucr);///supraincarcare operator <

    Lucrare();///constructor default
    Lucrare(char*nume,int oreNecesare,string utilajNecesar,float pretPeOra);///constructor cu parametrii(pentru lucrari mici, care nu au nevoie decat de 1 utilaj)
    Lucrare(char*nume,int oreNecesare,int nrUtilajeNecesare,string utilajNecesar);///constructor cu parametrii(pentru lucrari pro bono)
    Lucrare(char*nume,int oreNecesare,int nrUtilajeNecesare,string utilajNecesar,float pretPeOra);///constructor cu toti parametrii
    Lucrare(const Lucrare&lucr);///copy constructor

    ~Lucrare();///destructor

    void Citire();
    void Afisare();
    float PretLucrare(Lucrare l);
};

void Lucrare::setPretPeOra(float pretPeOra)///setter float
{
    this->pretPeOra=pretPeOra;
}
float Lucrare::getPretPeOra() const///getter float
{
    return this->pretPeOra;
}
istream&operator>>(istream &in,Lucrare &lucr)///supraincarcare operator citire
{
    cout<<"Introduceti numele lucrarii:";
    if(lucr.nume!=NULL)
        delete[] lucr.nume;
    char nume1[100];
    in>>nume1;
    lucr.nume=new char(strlen(nume1)+1);
    strcpy(lucr.nume,nume1);
    cout<<"Introduceti numarul de ore necesar pentru completarea lucrarii:";
    in>>lucr.oreNecesare;
    cout<<"Introduceti numarul de utilaje necesar:";
    in>>lucr.nrUtilajeNecesare;
    cout<<"Introduceti utilajul necesar:";
    in>>lucr.utilajNecesar;
    cout<<"Introduceti pretul pe ora:";
    in>>lucr.pretPeOra;
    return in;
}
ostream &operator<<(ostream& out,const Lucrare &lucr)///supraincarcare operator afisare
{
    out<<"Numele lucrarii:"<<lucr.nume<<'\n';
    out<<"Numar ore necesar pentru completarea lucrarii:"<<lucr.oreNecesare<<'\n';
    out<<"Numarul de utilaje necesar:"<<lucr.nrUtilajeNecesare<<'\n';
    out<<"Utilajul necesar:"<<lucr.utilajNecesar<<'\n';
    out<<"Pretul pe ora:"<<lucr.pretPeOra<<" lei\n";
    return out;
}
Lucrare& Lucrare::operator=(const Lucrare& lucr)///supraincarcare operator =
{
    if(this!=&lucr)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(lucr.nume)+1];
        strcpy(this->nume,lucr.nume);
        this->oreNecesare=lucr.oreNecesare;
        this->nrUtilajeNecesare=lucr.nrUtilajeNecesare;
        this->utilajNecesar=lucr.utilajNecesar;
        this->pretPeOra=lucr.pretPeOra;
    }
    return *this;
}
char& Lucrare::operator[]( int index)///supraincarcare operator indexare
{
    if (0 <= index && index <strlen(this->nume))
        return this->nume[index];
    cout << "Index introdus gresit";
}
Lucrare Lucrare::operator+(float a)///supraincarcare operator adunare la dreapta a+2
{
    Lucrare aux(*this);
    aux.pretPeOra+=a;
    return aux;
}
Lucrare operator+ (float a, Lucrare lucr)///supraincarcarea operator adunare la stanga 2+a
{
    lucr.pretPeOra+=a;
    return lucr;
}
Lucrare Lucrare::operator+ (Lucrare lucr)///supraincarcare operator pt adunare pe 2 obiecte din clasa
{
    lucr.pretPeOra+=this->pretPeOra;
    return lucr;
}
Lucrare Lucrare::operator-(float a)///supraincarcare operator scadere la dreapta a-2
{
    Lucrare aux(*this);
    aux.pretPeOra-=a;
    return aux;
}
Lucrare operator- (float a, Lucrare lucr)///supraincarcarea operator scadere la stanga 2-a
{
    lucr.pretPeOra=a-lucr.pretPeOra;
    return lucr;
}
Lucrare Lucrare::operator- (Lucrare lucr)///supraincarcare operator pt scadere pe 2 obiecte din clasa
{
    lucr.pretPeOra=this->pretPeOra-lucr.pretPeOra;
    return lucr;
}
Lucrare::operator float() const///supraincarcare operator cast implicit
{
    return this->pretPeOra;
}
Lucrare& Lucrare::operator++()///supraincarcare operatot preincrementare
{
    this->nrUtilajeNecesare++;
    return *this;
}
Lucrare Lucrare::operator++(int)///supraincarcare operatot postincrementare
{
    Lucrare aux(*this);///cream cu copy constructor pentru a folosi aux in functie
    this->nrUtilajeNecesare++;
    return aux;
}
bool Lucrare::operator==(const Lucrare& lucr) ///supraincarcare operator==
{
    if (strcmp(this->nume,lucr.nume))
        return false;
    return true;
}
bool Lucrare::operator<(const Lucrare& lucr)///supraincarcare operator <
{
    if (this->pretPeOra < lucr.pretPeOra)
        return true;
    return false;
}
Lucrare::Lucrare()///constructor default
{
    this->nume=new char[strlen("nume lucrare")+1];
    strcpy(this->nume,"nume lucrare");
    this->oreNecesare=0;
    this->nrUtilajeNecesare=0;
    this->utilajNecesar=utilajNecesar;
    this->pretPeOra=0;
}
Lucrare::Lucrare(char*nume,int oreNecesare,string utilajNecesar,float pretPeOra)///constructor cu parametrii(pentru lucrari mici, care nu au nevoie decat de 1 utilaj)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->oreNecesare=oreNecesare;
    this->nrUtilajeNecesare=1;
    this->utilajNecesar=utilajNecesar;
    this->pretPeOra=pretPeOra;
}
Lucrare::Lucrare(char*nume,int oreNecesare,int nrUtilajeNecesare,string utilajNecesar)///constructor cu parametrii(pentru lucrari pro bono)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->oreNecesare=oreNecesare;
    this->nrUtilajeNecesare=nrUtilajeNecesare;
    this->utilajNecesar=utilajNecesar;
    this->pretPeOra=0;
}
Lucrare::Lucrare(char*nume,int oreNecesare,int nrUtilajeNecesare,string utilajNecesar,float pretPeOra)///constructor cu toti parametrii
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->oreNecesare=oreNecesare;
    this->nrUtilajeNecesare=nrUtilajeNecesare;
    this->utilajNecesar=utilajNecesar;
    this->pretPeOra=pretPeOra;
}
Lucrare::Lucrare(const Lucrare&lucr)///copy constructor
{
    this->nume=new char[strlen(lucr.nume)+1];
    strcpy(this->nume,lucr.nume);
    this->oreNecesare=lucr.oreNecesare;
    this->nrUtilajeNecesare=lucr.nrUtilajeNecesare;
    this->utilajNecesar=lucr.utilajNecesar;
    this->pretPeOra=lucr.pretPeOra;
}
Lucrare::~Lucrare()///destructor
{
    if(this->nume!=NULL)
        delete[] this->nume;
}
void Lucrare::Citire()
{
    cout<<"Introduceti numele lucrarii:";
    if(this->nume!=NULL)
        delete[] this->nume;
    char nume1[100];
    cin>>nume1;
    this->nume=new char(strlen(nume1)+1);
    strcpy(this->nume,nume1);
    cout<<"Introduceti numarul de ore necesar pentru completarea lucrarii:";
    cin>>this->oreNecesare;
    cout<<"Introduceti numarul de utilaje necesar:";
    cin>>this->nrUtilajeNecesare;
    cout<<"Introduceti utilajul necesar:";
    cin>>this->utilajNecesar;
    cout<<"Introduceti pretul pe ora:";
    cin>>this->pretPeOra;
}
void Lucrare::Afisare()
{
    cout<<"Numele lucrarii:"<<this->nume<<'\n';
    cout<<"Numar ore necesar pentru completarea lucrarii:"<<this->oreNecesare<<'\n';
    cout<<"Numarul de utilaje necesar:"<<this->nrUtilajeNecesare<<'\n';
    cout<<"Utilajul necesar:"<<this->utilajNecesar<<'\n';
    cout<<"Pretul pe ora:"<<this->pretPeOra<<" lei\n";
}
float Lucrare::PretLucrare(Lucrare l)
{
    return this->oreNecesare*this->nrUtilajeNecesare*this->pretPeOra;
}
class Client{
    char* nume;
    char* prenume;
    string numeLucrare;
    double pret;
public:
    void setPret(double pret);///setter double

    double getPret() const;///getter double

    Client &operator=(const Client &cli);///supraincarcare operator =
    friend istream&operator>>(istream &in,Client &c);///supraincarcare operator citire
    friend ostream &operator<<(ostream&out,const Client &c);///supraincarcare operator afisare
    char& operator[]( int index);///supraincarcare operator indexare
    double operator+(double a);///supraincarcare operator adunare la dreapta cli+2
    friend double operator+ (double a, Client cli);///supraincarcarea operator adunare la stanga 2+cli
    double operator+ (Client cli);///supraincarcare operator pt adunare pe 2 obiecte din clasa
    Client operator-(double a);///supraincarcare operator scadere la dreapta a-2
    friend Client operator- (double a, Client cli);
    Client operator- (Client cli);///supraincarcare operator pt scadere pe 2 obiecte din clasa
    explicit operator int()///supraincarcare operator cast explicit
    {return (int)this->pret;}
    operator double() const;///supraincarcare operator cast implicit
    Client &operator++();///supraincarcare operatot preincrementare
    Client operator++(int);///supraincarcare operatot postincrementare
    bool operator==(const Client& cli);///supraincarcare operator==
    bool operator<(const Client& cli);///supraincarcare operator <

    Client();///constructor default
    Client (char*nume,char*prenume);///constructor client fara lucrare
    Client(char*nume, char*prenume, string numeLucrare);///constructor cu parametrii, pret standard de 1000 lei
    Client(char* nume, char*prenume, string numeLucrare,double pret);///constructor cu toti parametrii
    Client(const Client &cli);///copy constructor
    ~Client();
    void Citire();
    void Afisare();
};
void Client::setPret(double pret)///setter double
{
    this->pret=pret;
}
double Client::getPret() const///getter double
{
    return this->pret;
}
Client& Client::operator=(const Client &cli)///supraincarcare operator =
{
    if(this!=&cli)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(cli.nume)+1];
        strcpy(this->nume,cli.nume);
        if(this->prenume!=NULL)
            delete[] this->prenume;
        this->prenume=new char[strlen(cli.prenume)+1];
        strcpy(this->prenume,cli.prenume);
        this->numeLucrare=cli.numeLucrare;
        this->pret=cli.pret;
    }
    return *this;
}
istream&operator>>(istream &in,Client &c)///supraincarcare operator citire
{
    cout<<"Introduceti numele clientului:";
    if(c.nume!=NULL)
        delete[] c.nume;
    char nume1[100];
    in>>nume1;
    c.nume=new char[strlen(nume1)+1];
    strcpy(c.nume,nume1);
    cout<<"Introduceti prenumele clientului:";
    if(c.prenume!=NULL)
        delete[] c.prenume;
    char prenume1[100];
    in>>prenume1;
    c.prenume=new char[strlen(prenume1)+1];
    strcpy(c.prenume,prenume1);
    cout<<"Introduceti numele lucrarii:";
    in>>c.numeLucrare;
    cout<<"Introduceti pretul lucrarii:";
    in>>c.pret;
    return in;
}
ostream &operator<<(ostream&out,const Client &c)
{
    out<<"Numele clientului:"<<c.nume<<'\n';
    out<<"Prenumele clientului:"<<c.prenume<<'\n';
    out<<"Numele lucrarii:"<<c.numeLucrare<<'\n';
    out<<"Pret:"<<c.pret<<'\n';
    return out;
}
char& Client::operator[]( int index)///supraincarcare operator indexare
{
    if (0 <= index && index <strlen(this->nume))
        return this->nume[index];
    cout << "Index introdus gresit";
}
double Client::operator+(double a)///supraincarcare operator adunare la dreapta a+2
{
    Client aux(*this);
    aux.pret+=a;
    return aux.pret;
}
double operator+ (double a, Client cli)///supraincarcarea operator adunare la stanga 2+a
{
    cli.pret+=a;
    return cli.pret;
}
double Client::operator+ (Client cli)///supraincarcare operator pt adunare pe 2 obiecte din clasa
{
    cli.pret+=this->pret;
    return cli.pret;
}
Client Client::operator-(double a)///supraincarcare operator scadere la dreapta a-2
{
    Client aux(*this);
    aux.pret-=a;
    return aux;
}
Client operator- (double a, Client cli)///supraincarcarea operator scadere la stanga 2-a
{
    cli.pret=a-cli.pret;
    return cli;
}
Client Client::operator- (Client cli)///supraincarcare operator pt scadere pe 2 obiecte din clasa
{
    cli.pret=this->pret-cli.pret;
    return cli;
}
Client::operator double() const///supraincarcare operator cast implicit
{
    return this->pret;
}
Client& Client::operator++()///supraincarcare operatot preincrementare
{
    this->pret++;
    return *this;
}
Client Client::operator++(int)///supraincarcare operatot postincrementare
{
    Client aux(*this);
    this->pret++;
    return aux;
}
bool Client::operator==(const Client& cli)///supraincarcare operator==
{
    if (strcmp(this->nume,cli.nume))
        return false;
    return true;
}
bool Client::operator<(const Client& cli)///supraincarcare operator <
{
    if (this->pret < cli.pret)
        return true;
    return false;
}
Client::Client()///constructor default
{
    this->nume=new char[strlen("anonim")+1];
    strcpy(this->nume,"anonim");
    this->prenume=new char[strlen("la fel de anonim")+1];
    strcpy(this->prenume,"la fel de anonim");
    this->numeLucrare="nume lucrare";
    this->pret=0;
}
Client::Client(char*nume,char*prenume)///constructor client fara lucrare
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->prenume=new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
    this->numeLucrare="nume lucrare";
    this->pret=0;
}
Client::Client(char*nume, char*prenume, string numeLucrare)///constructor cu parametrii, pret standard de 1000 lei
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->prenume=new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
    this->numeLucrare=numeLucrare;
    this->pret=1000;
}
Client::Client(char* nume, char*prenume, string numeLucrare,double pret)///constructor cu toti parametrii
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->prenume=new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
    this->numeLucrare=numeLucrare;
    this->pret=pret;
}
Client::Client(const Client &cli)///copy constructor
{
    this->nume=new char[strlen(cli.nume)+1];
    strcpy(this->nume,cli.nume);
    this->prenume=new char[strlen(cli.prenume)+1];
    strcpy(this->prenume,cli.prenume);
    this->numeLucrare=cli.numeLucrare;
    this->pret=cli.pret;
}
Client::~Client()
{
    if(this->nume!=NULL)
        delete[] this->nume;
    if(this->prenume!=NULL)
        delete[] this->prenume;
}
void Client::Citire()
{
    cout<<"Introduceti numele clientului:";
    if(this->nume!=NULL)
        delete[] this->nume;
    char nume1[100];
    cin>>nume1;
    this->nume=new char[strlen(nume1)+1];
    strcpy(this->nume,nume1);
    cout<<"Introduceti prenumele clientului:";
    if(this->prenume!=NULL)
        delete[] this->prenume;
    char prenume1[100];
    cin>>prenume1;
    this->prenume=new char[strlen(prenume1)+1];
    strcpy(this->prenume,prenume1);
    cout<<"Introduceti numele lucrarii:";
    cin>>this->numeLucrare;
    cout<<"Introduceti pretul lucrarii:";
    cin>>this->pret;
}
void Client::Afisare()
{
    cout<<"Numele clientului:"<<this->nume<<'\n';
    cout<<"Prenumele clientului:"<<this->prenume<<'\n';
    cout<<"Numele lucrarii:"<<this->numeLucrare<<'\n';
    cout<<"Pret:"<<this->pret<<'\n';
}
class Angajat{
    char* nume;
    char initialaTatalui;
    char* prenume;
    const int iDAngajat;
    int varsta;
    int nrZileMuncite;
    int* nrOreMuncite;
    int* nrOreSuplimentare;
    float salariu;
    static int contorID;
public:
    void setNume(char* nume);///setter pentru char*
    void setZileMuncite(int* nrOreMuncite,int* nrOreSuplimentare,int nrZileMuncite);///setter pt int* si int
    void setInitialaTatalui(char initialaTatalui);///setter pt char
    void setContor(int contorID);///setter pentru static

    const char* getNume() const;///getter char
    int getVarsta() const; ///getter int
    int getNrZileMuncite() const;///getter int
    const int* getNrOreMuncite() const;///getter int*
    const int* getNrOreSuplimentare() const;///getter int*
    char getInitialaTatalui() const;///getter char
    const int getIDAngajat() const;///getter const
    int getContorID() const;///getter static

    friend istream&operator>>(istream &in,Angajat &ang);///supraincarcare operator citire
    friend ostream &operator<<(ostream& out,const Angajat &ang);///supraincarcare operator afisare
    Angajat& operator=(const Angajat& ang);
    Angajat operator+(int a);///supraincarcare operator adunare la dreapta a+2
    friend Angajat operator+ (int a, Angajat ang);///supraincarcarea operator adunare la stanga 2+a
    Angajat operator+ (Angajat ang);///supraincarcare operator pt adunare pe 2 obiecte din clasa
    Angajat operator-(int a);///supraincarcare operator scadere la dreapta a-2
    friend Angajat operator- (int a, Angajat ang);
    Angajat operator- (Angajat ang);///supraincarcare operator pt scadere pe 2 obiecte din clasa
    explicit operator int()///supraincarcare operator cast explicit
    {return (int)this->varsta;}
    operator int() const;///supraincarcare operator cast implicit
    Angajat &operator++();///supraincarcare operatot preincrementare
    Angajat operator++(int);///supraincarcare operatot postincrementare
    bool operator==(const Angajat& ang);///supraincarcare operator ==
    bool operator<(const Angajat& ang);///supraincarcare operator <
    int& operator[]( int index);///supraincarcare operator []

    Angajat();///constructor default
    Angajat(char* nume,char initialaTatalui, char* prenume, int varsta,int nrZileMuncite,int* nrOreMuncite,float salariu);///constructor cu paramentrii(pt angajatii fara ore suplimentare de munca)
    Angajat(char* nume,char initialaTatalui, char* prenume, int varsta,int nrZileMuncite,int* nrOreMuncite,int*nrOreSuplimentare);///constructor cu paramentrii(pt angajatii cu ore suplimentare de munca)
    Angajat(char* nume,char initialaTatalui, char* prenume, int varsta,int nrZileMuncite,int* nrOreMuncite, int* nrOreSuplimentare,float salariu);///constructor cu toti parametrii
    Angajat(const Angajat& ang);///copy constructor
    ~Angajat();///destructor

    void Citire();///functie de citire
    void Afisare();///functie de afisare fara salariu
    void AfisareCompleta();///functie de afisare cu calculul salariului
    float Salariu(int* nrOreMuncite,int* nrOreSuplimentare,int nrZileMuncite);///functie de calul salariu
};
int Angajat::contorID=0;///initializam contorID
void Angajat::setNume(char* nume)///setter char*
{
    if(this->nume!=NULL)
        delete[] this->nume;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}
void Angajat::setZileMuncite(int* nrOreMuncite,int* nrOreSuplimentare,int nrZileMuncite)///setter pt int* si int
{
    this->nrZileMuncite=nrZileMuncite;
    if(this->nrOreMuncite!=NULL)
        delete[] this->nrOreMuncite;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(int i=0;i<this->nrZileMuncite;i++)
        this->nrOreMuncite[i]=nrOreMuncite[i];
    if(this->nrOreSuplimentare!=NULL)
        delete[] this->nrOreSuplimentare;
    this->nrOreSuplimentare=new int[nrZileMuncite];
    for(int i=0;i<this->nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=nrOreSuplimentare[i];
}
void Angajat::setInitialaTatalui(char initialaTatalui)///setter pentru char
{
    this->initialaTatalui=initialaTatalui;
}
void Angajat::setContor(int contorID)///setter pentru static
{
    this->contorID=contorID;
}
const char* Angajat::getNume() const///getter char*
{
    return this->nume;
}
int Angajat::getVarsta() const
{
    return this->varsta;
}
int Angajat::getNrZileMuncite() const///getter int
{
    return this->nrZileMuncite;
}
const int* Angajat::getNrOreMuncite() const///getter int*
{
    return this->nrOreMuncite;
}
const int* Angajat::getNrOreSuplimentare() const///getter int*
{
    return this->nrOreSuplimentare;
}
char Angajat::getInitialaTatalui() const///getter char
{
    return this->initialaTatalui;
}
const int Angajat::getIDAngajat() const ///getter const
{
    return this->iDAngajat;
}
int Angajat::getContorID() const///getter static
{
    return this->contorID;
}
istream&operator>>(istream &in,Angajat &ang)///supraincarcare operator citire
{
    cout<<"Introduceti nume:";
    if(ang.nume!=NULL)
        delete[] ang.nume;
    char nume1[80];
    in>>nume1;
    ang.nume=new char[strlen(nume1)+1];
    strcpy(ang.nume,nume1);

    cout<<"Introduceti initiala tatalui:";
    in>>ang.initialaTatalui;

    cout<<"Introduceti prenumele:";
    if(ang.prenume!=NULL)
        delete[] ang.prenume;
    char prenume1[100];
    in>>prenume1;
    ang.prenume=new char[strlen(prenume1)+1];
    strcpy(ang.prenume,prenume1);

    cout<<"Introduceti varsta:";
    in>>ang.varsta;

    cout<<"Introduceti numarul de zile muncite:";
    in>>ang.nrZileMuncite;

    int i;
    cout<<"Introduceti numarul de ore muncite in fiecare zi:";
    if(ang.nrOreMuncite!=NULL)
        delete[] ang.nrOreMuncite;
    ang.nrOreMuncite=new int[ang.nrZileMuncite];
    for(i=0;i<ang.nrZileMuncite;i++)
        in>>ang.nrOreMuncite[i];

    cout<<"Introduceti numarul de ore suplimentare in fiecare zi:";
    if(ang.nrOreSuplimentare!=NULL)
        delete[] ang.nrOreSuplimentare;
    ang.nrOreSuplimentare=new int[ang.nrZileMuncite];
    for(i=0;i<ang.nrZileMuncite;i++)
        in>>ang.nrOreSuplimentare[i];
    cout<<'\n';
    return in;
}
ostream &operator<<(ostream& out,const Angajat &ang)///supraincarcare operator afisare
{
    out<<"Nume:"<<ang.nume<<'\n';
    out<<"Initiala tatalui:"<<ang.initialaTatalui<<'\n';
    out<<"Prenume:"<<ang.prenume<<'\n';
    out<<"ID-ul angajatului:"<<ang.iDAngajat<<'\n';
    out<<"Varsta:"<<ang.varsta<<'\n';
    out<<"Numar de zile muncite:"<<ang.nrZileMuncite<<'\n';
    int i;
    out<<"In "<<ang.nrZileMuncite<<" a muncit urmatoarele numere de ore pe zi:";
    for(i=0;i<ang.nrZileMuncite;i++)
        out<<ang.nrOreMuncite[i]<<' ';
    out<<"\nIn "<<ang.nrZileMuncite<<" a muncit suplimentar urmatoarele numere de ore pe zi:";
    for(i=0;i<ang.nrZileMuncite;i++)
        out<<ang.nrOreSuplimentare[i]<<' ';
    out<<'\n';
    out<<"Salariu:"<<ang.salariu<<" lei \n";
    return out;
}
Angajat& Angajat::operator=(const Angajat& ang)///supraincarcare operator =
{
    if(this!=&ang)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(ang.nume)+1];
        strcpy(this->nume,ang.nume);
        this->initialaTatalui=ang.initialaTatalui;
        if(this->prenume!=NULL)
            delete[] this->prenume;
        this->prenume= new char[strlen(ang.prenume)+1];
        strcpy(this->prenume,ang.prenume);
        this->varsta=ang.varsta;
        this->nrZileMuncite=ang.nrZileMuncite;
        int i;
        if(this->nrOreMuncite!=NULL)
            delete[] this->nrOreMuncite;
        this->nrOreMuncite=new int[ang.nrZileMuncite];
        for(i=0;i<ang.nrZileMuncite;i++)
            this->nrOreMuncite[i]=ang.nrOreMuncite[i];
        if(this->nrOreSuplimentare!=NULL)
            delete[] this->nrOreSuplimentare;
        this->nrOreSuplimentare=new int[ang.nrZileMuncite];
        for(i=0;i<ang.nrZileMuncite;i++)
            this->nrOreSuplimentare[i]=ang.nrOreSuplimentare[i];
        this->salariu=ang.salariu;
    }
    return *this;
}
Angajat Angajat::operator+(int a)///supraincarcare operator adunare la dreapta a+2
{
    Angajat aux(*this);
    aux.varsta+=a;
    return aux;
}
Angajat operator+ (int a, Angajat ang)///supraincarcarea operator adunare la stanga 2+a
{
    ang.varsta+=a;
    return ang;
}
Angajat Angajat::operator+ (Angajat ang)///supraincarcare operator pt adunare pe 2 obiecte din clasa
{
    cout<<"Impreuna au varsta:";
    ang.varsta+=this->varsta;
    return ang;
}
Angajat Angajat::operator-(int a)///supraincarcare operator scadere la dreapta a-2
{
    Angajat aux(*this);
    aux.varsta-=a;
    return aux;
}
Angajat operator- (int a, Angajat ang)///supraincarcarea operator scadere la stanga 2-a
{
    ang.varsta=a-ang.varsta;
    return ang;
}
Angajat Angajat::operator- (Angajat ang)///supraincarcare operator pt scadere pe 2 obiecte din clasa
{
    cout<<"Impreuna au varsta:";
    ang.varsta=this->varsta-ang.varsta;
    return ang;
}
Angajat::operator int() const///supraincarcare operator cast implicit
{
    return this->varsta;
}
Angajat& Angajat::operator++()///supraincarcare operatot preincrementare
{
    this->varsta++;
    return *this;
}
Angajat Angajat::operator++(int)///supraincarcare operatot postincrementare
{
    Angajat aux(*this);
    this->varsta++;
    return aux;
}
bool Angajat::operator==(const Angajat& ang)///supraincarcare operator ==
{
    if (strcmp(this->nume,ang.nume)==0 && strcmp(this->prenume,ang.prenume)==0)
        return true;
    return false;
}
bool Angajat::operator<(const Angajat& ang)///supraincarcare operator <
{
    if (this->varsta < ang.varsta)
        return true;
    return false;
}
int& Angajat::operator[]( int index)///supraincarcare operator []
{
    if(0 <= index && index < this->nrZileMuncite)
        return this->nrOreMuncite[index];
    cout << "Index introdus gresit";
}
Angajat::Angajat():iDAngajat(contorID++)///constructor default
{
    this->nume=new char[strlen("anonim")+1];///alocam memorie pentru numele de familie
    strcpy(this->nume,"anonim");
    this->initialaTatalui='A';
    this->prenume=new char[strlen("la fel de anonim")+1];
    strcpy(this->prenume,"la fel de anonim");
    this->varsta=0;
    this->nrZileMuncite=0;
    this->nrOreMuncite=NULL;
    this->nrOreSuplimentare=NULL;
    this->salariu=0;
}
Angajat::Angajat(char* nume,char initialaTatalui, char* prenume, int varsta,int nrZileMuncite,int* nrOreMuncite,float salariu):iDAngajat(contorID++)///constructor cu paramentrii(pt angajatii fara ore suplimentare de munca)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->initialaTatalui=initialaTatalui;
    this->prenume= new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
    this->varsta=varsta;
    this->nrZileMuncite=nrZileMuncite;
    int i;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(i=0;i<nrZileMuncite;i++)
        this->nrOreMuncite[i]=nrOreMuncite[i];
    this->nrOreSuplimentare=new int[nrZileMuncite];
    for(i=0;i<nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=0;
    this->salariu=Salariu(this->nrOreMuncite,this->nrOreSuplimentare,this->nrZileMuncite);
}
Angajat::Angajat(char* nume,char initialaTatalui, char* prenume, int varsta,int nrZileMuncite,int* nrOreMuncite,int*nrOreSuplimentare):iDAngajat(contorID++)///constructor cu paramentrii(pt angajatii cu ore suplimentare de munca)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->initialaTatalui=initialaTatalui;
    this->prenume= new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
    this->varsta=varsta;
    this->nrZileMuncite=nrZileMuncite;
    int i;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(i=0;i<nrZileMuncite;i++)
        this->nrOreMuncite[i]=nrOreMuncite[i];
    this->nrOreSuplimentare=new int[nrZileMuncite];
    for(i=0;i<nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=nrOreSuplimentare[i];
    this->salariu=Salariu(this->nrOreMuncite,this->nrOreSuplimentare,this->nrZileMuncite);
}
Angajat::Angajat(char* nume,char initialaTatalui, char* prenume, int varsta,int nrZileMuncite,int* nrOreMuncite, int* nrOreSuplimentare,float salariu):iDAngajat(contorID++)///constructor cu toti parametrii
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->initialaTatalui=initialaTatalui;
    this->prenume= new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
    this->varsta=varsta;
    this->nrZileMuncite=nrZileMuncite;
    int i;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(i=0;i<nrZileMuncite;i++)
        this->nrOreMuncite[i]=nrOreMuncite[i];
    this->nrOreSuplimentare=new int[nrZileMuncite];
    for(i=0;i<nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=nrOreSuplimentare[i];
    this->salariu=Salariu(this->nrOreMuncite,this->nrOreSuplimentare,this->nrZileMuncite);
}
Angajat::Angajat(const Angajat& ang):iDAngajat(ang.iDAngajat)///copy constructor
{
    this->nume=new char[strlen(ang.nume)+1];
    strcpy(this->nume,ang.nume);
    this->initialaTatalui=ang.initialaTatalui;
    this->prenume= new char[strlen(ang.prenume)+1];
    strcpy(this->prenume,ang.prenume);
    this->varsta=ang.varsta;
    this->nrZileMuncite=ang.nrZileMuncite;
    int i;
    this->nrOreMuncite=new int[ang.nrZileMuncite];
    for(i=0;i<ang.nrZileMuncite;i++)
        this->nrOreMuncite[i]=ang.nrOreMuncite[i];
    this->nrOreSuplimentare=new int[ang.nrZileMuncite];
    for(i=0;i<ang.nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=ang.nrOreSuplimentare[i];
    this->salariu=ang.salariu;
}
Angajat::~Angajat()///destructor
{
    if(this->nume!=NULL)
        delete[] this->nume;
    if(this->prenume!=NULL)
        delete[] this->prenume;
    if(this->nrOreMuncite!=NULL)
        delete[] this->nrOreMuncite;
    if(this->nrOreSuplimentare!=NULL)
        delete[] this->nrOreSuplimentare;
}
void Angajat::Citire()///functie de citire
{
    cout<<"Introduceti nume:";
    if(this->nume!=NULL)
        delete[] this->nume;
    char nume1[80];
    cin>>nume1;
    this->nume=new char[strlen(nume1)+1];
    strcpy(this->nume,nume1);

    cout<<"Introduceti initiala tatalui:";
    cin>>this->initialaTatalui;

    cout<<"Introduceti prenumele:";
    if(this->prenume!=NULL)
        delete[] this->prenume;
    char prenume1[100];
    cin>>prenume1;
    this->prenume=new char[strlen(prenume1)+1];
    strcpy(this->prenume,prenume1);

    cout<<"Introduceti varsta:";
    cin>>this->varsta;

    cout<<"Introduceti numarul de zile muncite:";
    cin>>this->nrZileMuncite;

    int i;
    cout<<"Introduceti numarul de ore muncite in fiecare zi:";
    if(this->nrOreMuncite!=NULL)
        delete[] this->nrOreMuncite;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(i=0;i<this->nrZileMuncite;i++)
        cin>>this->nrOreMuncite[i];

    cout<<"Introduceti numarul de ore suplimentare in fiecare zi:";
    if(this->nrOreSuplimentare!=NULL)
        delete[] this->nrOreSuplimentare;
    this->nrOreSuplimentare=new int[this->nrZileMuncite];
    for(i=0;i<this->nrZileMuncite;i++)
        cin>>this->nrOreSuplimentare[i];

    this->salariu=Salariu(this->nrOreMuncite,this->nrOreSuplimentare,this->nrZileMuncite);
    cout<<'\n';
}
void Angajat::Afisare()///functie de afisare, fara salariu
{
    cout<<"Nume:"<<this->nume<<'\n';
    cout<<"Initiala tatalui:"<<this->initialaTatalui<<'\n';
    cout<<"Prenume:"<<this->prenume<<'\n';
    cout<<"Varsta:"<<this->varsta<<'\n';
    cout<<"Numar de zile muncite:"<<this->nrZileMuncite<<'\n';
    int i;
    cout<<"In "<<this->nrZileMuncite<<" a muncit urmatoarele numere de ore pe zi:";
    for(i=0;i<this->nrZileMuncite;i++)
        cout<<this->nrOreMuncite[i]<<' ';
    cout<<"\nIn "<<this->nrZileMuncite<<" a muncit suplimentar urmatoarele numere de ore pe zi:";
    for(i=0;i<this->nrZileMuncite;i++)
        cout<<this->nrOreSuplimentare[i]<<' ';
    cout<<'\n';
}
void Angajat::AfisareCompleta()///functie de afisare cu tot cu salariu
{
    cout<<"Nume:"<<this->nume<<'\n';
    cout<<"Initiala tatalui:"<<this->initialaTatalui<<'\n';
    cout<<"Prenume:"<<this->prenume<<'\n';
    cout<<"ID-ul angajatului:"<<this->iDAngajat<<'\n';
    cout<<"Varsta:"<<this->varsta<<'\n';
    cout<<"Numar de zile muncite:"<<this->nrZileMuncite<<'\n';
    int i;
    cout<<"In "<<this->nrZileMuncite<<" a muncit urmatoarele numere de ore pe zi:";
    for(i=0;i<this->nrZileMuncite;i++)
        cout<<this->nrOreMuncite[i]<<' ';
    cout<<"\nIn "<<this->nrZileMuncite<<" a muncit suplimentar urmatoarele numere de ore pe zi:";
    for(i=0;i<this->nrZileMuncite;i++)
        cout<<this->nrOreSuplimentare[i]<<' ';
    cout<<'\n';
    cout<<"Salariu:"<<this->salariu<<" lei \n";
    cout<<"ContorID:"<<this->contorID<<" \n";
}
float Angajat::Salariu(int* nrOreMuncite,int* nrOreSuplimentare,int nrZileMuncite)
{
    int i;
    float salariu=0;
    for(i=0;i<nrZileMuncite;i++)
        salariu+=20.5*nrOreMuncite[i]+25.5*nrOreSuplimentare[i];
    return salariu;

}
void vechime(Utilaje u)
{
    if(u.getOreFolosite()>30)
        cout<<"Utilajul este vechi.";
    else
        if(u.getOreFolosite()==0)
            cout<<"Utilajul este inca nou.";
    else
        cout<<"Utilajul nu este nici nou, nici vechi.";
}
double Reducere(double pret)///functionlaitate clasa client(reducere pt lucrare)
{
    if(pret>=5000)
        return pret-0.1*pret;
    return pret;
}

double operator+(Client& cli, Utilaje& uti)///supraincarcare operator + pentru cerinta 9(adunare pretul lucrarii clientului si buget intretinere utilaj)
{
    return cli.getPret()+uti.getBugetIntretinere();
}
double operator+(Utilaje& uti, Client& cli)///supraincarcare operator + pentru cerinta 9(adunare buget intretinere utilaj si pretul lucrarii clientului)
{
    return uti.getBugetIntretinere()+cli.getPret();
}

int main()
{
    int nrOreM[4]={12,1,5},nrOreS[4]={0,0,6},nrOreM1[4]={12,1,5,4},nrOreS1[4]={1,0,0,6};
    ///evidentiere constructori
    Angajat a1,a2("Popescu",'E',"Gigel",25,3,nrOreM,nrOreS),a3("Popescu1",'E',"Gigel1",24,3,nrOreM,nrOreS);
    Utilaje u1,u2("miniexcavator",2000,40,1),u3("buldoexcavator",1500),u4("buldozer");
    Lucrare l1,l2("Decopertare",10,4,"miniexcavator"),l3("Demolare",20,4,"buldozer",504.5);
    Client c1,c2("Ionescu","Ion","nivelare"),c3("Georgescu","George","demolare",1234.5),c4("Moise","Alina");

    int i=0,i2=0,i3=0,i4=0,ok=1,j,k,p,op,op1,op2,op3,op4,op21,op22,op23,op31,op32,op41,op42;
    bool optIesireIntrare;
    Utilaje uti1;
    Angajat ang[1000];
    Utilaje uti[1000];
    Client cli[1000];
    Lucrare lucr[2000];
    ///Meniu interactiv
    while(ok!=0)
    {
        if(ok==2)
            {
                cout<<"\nMai vreti sa lucrati? Tastati 1 daca da sau 0 daca nu.\n";
                cout<<"Optiunea dumneavoastra:";cin>>optIesireIntrare;
                if(optIesireIntrare==0)
                    {ok=0;break;}
            }
        else
            ok=2;
        cout<<"Alegeti categoria cu care vreti sa lucrati:\n";
        cout<<"1=>Angajat\n2=>Utilaje\n3=>Lucrare\n4=>Client\n5=>Daca un client se plange ca este pretul prea mare\n";
        cout<<"Optiunea dumneavoastra:";cin>>op;
        while(op>5||op<1)
        {
            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
            cout<<"Alegeti categoria cu care vreti sa lucrati:\n";
            cout<<"1=>Angajat\n2=>Utilaje\n3=>Lucrare\n4=>Client\n";
            cout<<"Optiunea dumneavoastra:";cin>>op;
        }
        switch(op)
        {
            case 1:
                cout<<"\nAti ales optiunea Angajat.\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire angajat\n2=>Afiseaza date genereale angajat\n3=>Afiseaza toate datele\n4=>Modifica date angajat\n5=>Afisare separata\n6=>Crestere varsta cu un an\n7=>Joculet cu varste\n8=>Stergere angajat\n9=>Afisarea tuturor angajatilor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op1;
                while(op1>9||op1<1)
                {
                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire angajat\n2=>Afiseaza date genereale angajat\n3=>Afiseaza toate datele\n4=>Modifica date angajat\n5=>Afisare separata\n6=>Crestere varsta cu un an\n7=>Joculet cu varste\n8=>Stergere angajat\n9=>Afisarea tuturor angajatilor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op1;
                }
                switch(op1)
                {
                    case 1:
                        cout<<"\nAti ales optiunea de \"citire angajat\".\n";
                        i++;
                        ang[i].Citire();
                        break;
                    case 2:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"afisare date generale angajat\".\n";
                            cout<<"Ce angajat vreti sa afisati?\nIntroduceti indicele de inscriere:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce angajat vreti sa afisati? Introduceti indicele de inscriere:";
                                cin>>j;
                            }
                            ang[j].Afisare();
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                    case 3:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"afisare completa a unui angajat\".\n";
                            cout<<"Ce angajat vreti sa afisati?\nIntroduceti indicele de inscriere:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce angajat vreti sa afisati? Introduceti indicele de inscriere:";
                                cin>>j;
                            }
                            ang[j].AfisareCompleta();
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                    case 4:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"modificare date angajat\".\n";
                            cout<<"La ce angajat vreti sa modificati datele?\nIntroduceti indicele de inscriere:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce angajat vreti sa modificati datele? Introduceti indicele de inscriere:";
                                cin>>j;
                            }
                            cout<<"Ce vreti sa modificati?\n";
                            cout<<"1=>nume\n2=>zile muncite si orele aferente\n3=>initiala tatalui\n4=>contor ID\n";
                            cout<<"Optiunea dumneavoastra:";cin>>op2;
                            while(op2>4||op2<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Ce vreti sa modificati?\n";
                                cout<<"1=>nume\n2=>zile muncite si orele aferente\n3=>initiala tatalui\n4=>contor ID\n";
                                cout<<"Optiunea dumneavoastra:";cin>>op2;
                            }
                            switch(op2)
                            {
                                case 1:
                                    char nume[100];
                                    cout<<"Intoduceti nume:";cin>>nume;
                                    ang[j].setNume(nume);
                                    break;
                                case 2:
                                    int nrZileMuncitE,nrOreMuncitE[32],nrOreSuplimentarE[32];
                                    cout<<"Introduceti numarul de zile muncite:";
                                    cin>>nrZileMuncitE;
                                    cout<<"Introduceti numarul de ore muncite in fiecare zi:";
                                    for(i=0;i<nrZileMuncitE;i++)
                                        cin>>nrOreMuncitE[i];
                                    cout<<"Introduceti numarul de ore suplimentare muncite in fiecare zi:";
                                    for(i=0;i<nrZileMuncitE;i++)
                                        cin>>nrOreSuplimentarE[i];
                                    ang[j].setZileMuncite(nrOreMuncitE,nrOreSuplimentarE,nrZileMuncitE);
                                    ang[j].Afisare();
                                    break;
                                case 3:
                                    char it;
                                    cout<<"Introduceti initiala tatalui:";
                                    cin>>it;
                                    ang[j].setInitialaTatalui(it);
                                    break;
                                case 4:
                                    int contor;
                                    cout<<"Introduceti contor:";
                                    cin>>contor;
                                    ang[j].setContor(contor);
                                    break;
                            }
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                    case 5:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"Afisare separata\".\n";
                            cout<<"Pentru ce angajat vreti sa afisati separat?\nIntroduceti indicele de inscriere:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce angajat vreti sa afisati separat? Introduceti indicele de inscriere:";
                                cin>>j;
                            }
                            cout<<"Ce vreti sa afisati?\n";
                            cout<<"1=>nume\n2=>varsta\n3=>numarul de zile muncite\n4=>numarul de ore muncite in fiecare zi\n5=>numarul de ore muncite intr-o anumita zi\n6=>numarul de ore suplimentare muncite\n7=>initiala tatalui\n8=>ID Angajat\n9=>contorul ID-ului angajatului\n";
                            cout<<"Optiunea dumneavoastra:";cin>>op3;
                            while(op3>9||op3<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Ce vreti sa afisati?\n";
                                cout<<"1=>nume\n2=>varsta\n3=>numarul de zile muncite\n4=>numarul de ore muncite in fiecare zi\n5=>numarul de ore muncite intr-o anumita zi\n6=>numarul de ore suplimentare muncite\n7=>initiala tatalui\n8=>ID Angajat\n9=>contorul ID-ului angajatului\n";
                                cout<<"Optiunea dumneavoastra:";cin>>op2;
                            }
                            switch(op3)
                            {
                                case 1:cout<<ang[j].getNume();break;
                                case 2:cout<<ang[j].getVarsta();break;
                                case 3:cout<<ang[j].getNrZileMuncite();break;
                                case 4:
                                    for(i=0;i<ang[j].getNrZileMuncite();i++)
                                        cout<<ang[j].getNrOreMuncite()[i]<<" ";
                                    break;
                                case 5:
                                    int zi;
                                    cout<<"Introduceti ziua dorita:";cin>>zi;
                                    cout<<"In ziua a "<<zi<<"-a a lucrat:"<<ang[j][zi-1];///zi-1 pentru ca vectorul de ore muncite pe zi este indexat de la 0
                                    break;
                                case 6:
                                    for(i=0;i<ang[j].getNrZileMuncite();i++)
                                        cout<<ang[j].getNrOreSuplimentare()[i]<<" ";
                                    break;
                                case 7:cout<<ang[j].getInitialaTatalui();break;
                                case 8:cout<<ang[j].getIDAngajat();break;
                                case 9:cout<<ang[j].getContorID();break;
                            }
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                    case 6:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"Cresterea varstei unui angajat cu un an\".\n";
                            cout<<"Pentru ce angajat vreti sa cresteti varsta cu un an?\nIntroduceti indicele de inscriere:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce angajat vreti sa cresteti varsta cu un an? Introduceti indicele de inscriere:";
                                cin>>j;
                            }
                            ang[j]++;
                        }
                        else
                            cout<<"Introduceti angajati mai intai.";
                        break;
                    case 7:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"Joculet cu varste\".\n";
                            cout<<"Acest joc nu va afecta datele angajatilor.\n";
                            cout<<"Cu ce angajat vreti sa jucati?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Cu ce angajat vreti sa jucati?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            cout<<"Ce doriti sa faceti?\n";
                            cout<<"1=>creste varsta angajat la dreapta\n2=>creste varsta angajat la stanga\n3=>aduna varsta a doi angajati\n4=>scade varsta unui angajat din ceva\n5=>scade ceva din varsta unui angajat\n6=>diferenta de varsta dintre doi angajati\n";
                            cout<<"Optiunea dumneavoastra:";cin>>op4;
                            while(op4>6||op4<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Ce doriti sa faceti?\n";
                                cout<<"1=>creste varsta angajat la dreapta\n2=>creste varsta angajat la stanga\n3=>aduna varsta a doi angajati\n4=>scade varsta unui angajat din ceva\n5=>scade ceva din varsta unui angajat\n6=>diferenta de varsta dintre doi angajati\n";
                                cout<<"Optiunea dumneavoastra:";cin>>op2;
                            }
                            switch(op4)
                            {
                                case 1:
                                    int ad1;
                                    cout<<"Introduceti numarul cu care vreti sa cresteti varsta angajatului:";
                                    cin>>ad1;
                                    cout<<(ang[j]+ad1).getVarsta();
                                    break;
                                case 2:
                                    int ad2;
                                    cout<<"Introduceti numarul cu care vreti sa cresteti varsta angajatului:";
                                    cin>>ad2;
                                    cout<<(ad2+ang[j]).getVarsta();
                                    break;
                                case 3:
                                    cout<<"Cu ce alt angajat vreti sa calculati suma varstelor?\nIntroduceti indicele acestuia:";
                                    cin>>k;
                                    while(k>i||k<1)
                                    {
                                        cout<<"Indice incorect.Reintroduceti indicele.\n";
                                        cout<<"Cu ce alt angajat vreti sa calculati suma varstelor?\nIntroduceti indicele acestuia:";
                                        cin>>k;
                                    }
                                    cout<<(ang[j]+ang[k]).getVarsta();
                                    break;
                                case 4:
                                    int sc1;
                                    cout<<"Introduceti numarul din care vreti sa scadeti varsta angajatului:";
                                    cin>>sc1;
                                    cout<<(sc1-ang[j]).getVarsta();
                                    break;
                                case 5:
                                    int sc2;
                                    cout<<"Introduceti numarul cu care vreti sa scadeti varsta angajatului:";
                                    cin>>sc2;
                                    cout<<(ang[j]-sc2).getVarsta();
                                    break;
                                case 6:
                                    cout<<"Cu ce alt angajat vreti sa calculati diferenta de varsta?\nIntroduceti indicele acestuia:";
                                    cin>>k;
                                    while(k>i||k<1)
                                    {
                                        cout<<"Indice incorect.Reintroduceti indicele.\n";
                                        cout<<"Cu ce alt angajat vreti sa calculati diferenta de varsta?\nIntroduceti indicele acestuia:";
                                        cin>>k;
                                    }
                                    cout<<abs((ang[j]-ang[k]).getVarsta());
                                    break;
                            }
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                    case 8:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"Stergere angajat\".\n";
                            cout<<"Ce angajat vreti sa stergeti?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Cu ce alt angajat vreti sa stergeti?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            for(p=j;p<i;p++)
                                ang[p]=ang[p+1];
                            i--;
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                    case 9:
                        if(i!=0)
                        {
                            cout<<"\nAti ales optiunea \"Afisare a tuturor angajatilor\".\n";
                            for(p=1;p<=i;p++)
                                cout<<ang[p]<<'\n';
                        }
                        else
                            cout<<"Introuceti angajati mai intai.";
                        break;
                }
                break;
            case 2:
                cout<<"\nAti ales optiunea Utilaje.\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire utilaj\n2=>Afiseaza date utilaj\n3=>Modificare o litera din nume\n4=>Modifica date utilaj\n5=>Afisare separata a datelor unui utilaj\n6=>Crestere ore de folosinta cu o ora\n7=>Verificare daca utilajul este vechi\n8=>Stergere utilaj\n9=>Afisarea tuturor utilajelor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op21;
                while(op21>9||op21<1)
                {
                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire utilaj\n2=>Afiseaza date utilaj\n3=>Modificare o litera din nume\n4=>Modifica date utilaj\n5=>Afisare separata a datelor unui utilaj\n6=>Crestere ore de folosinta cu o ora\n7=>Verificare daca utilajul este vechi\n8=>Stergere utilaj\n9=>Afisarea tuturor utilajelor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op21;
                }
                switch(op21)
                {
                    case 1:
                        cout<<"\nAti ales optiunea de \"citire utilaj\".\n";
                        i2++;
                        uti[i2].Citire();
                        break;
                     case 2:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"afisare date utilaj\".\n";
                            cout<<"Ce utilaj vreti sa afisati?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce utilaj vreti sa afisati? Introduceti indicele acestuia:";
                                cin>>j;
                            }
                            uti[j].Afisare();
                        }
                        else
                            cout<<"Introuceti utilaje mai intai.";
                        break;
                    case 3:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea\"modificare o litera din nume\".\n";
                            cout<<"La ce utilaj vreti sa schimbati o litera din nume?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce utilaj vreti sa schimbati o litera din nume?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            int nrLitera;
                            char litera;
                            cout<<"Introduceti a cata litera trebuie schimbata:";
                            cin>>nrLitera;
                            while(nrLitera>strlen(uti[j].getNume())-1||nrLitera<1)
                            {
                                cout<<"Numarul literei introdus gresit.";
                                cout<<"Introduceti a cata litera trebuie schimbata:";
                                cin>>nrLitera;
                            }
                            cout<<"Introduceti litera cu care doriti sa schimbati:";
                            cin>>litera;
                            uti[j][nrLitera-1]=litera;
                        }
                        else
                            cout<<"Introuceti utilaje mai intai.";
                        break;

                    case 4:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"modificare date utilaj\".\n";
                            cout<<"La ce utilaj vreti sa modificati datele?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce utilaj vreti sa modificati datele? Introduceti indicele acestuia:";
                                cin>>j;
                            }
                            cout<<"Ce vreti sa modificati?\n";
                            cout<<"1=>bugetul de intretinere\n2=>numarul de ore in care a fost folosit\n3=>daca este sau nu in uz\n";
                            cout<<"Optiunea dumneavoastra:";cin>>op22;
                            while(op22>3||op22<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Ce vreti sa modificati?\n";
                                cout<<"1=>bugetul de intretinere\n2=>numarul de ore in care a fost folosit\n3=>daca este sau nu in uz\n";
                                cout<<"Optiunea dumneavoastra:";cin>>op22;
                            }
                            switch(op22)
                            {
                                case 1:
                                    double bugetNou;
                                    cout<<"Introduceti noul buget de intretinere:";
                                    cin>>bugetNou;
                                    uti[j].setBugetIntretinere(bugetNou);
                                    break;
                                case 2:
                                    long oreUpdatate;
                                    cout<<"Introduceti noul numar de ore in care a fost folosit utilajul:";
                                    cin>>oreUpdatate;
                                    uti[j].setOreFolosite(oreUpdatate);
                                    break;
                                case 3:
                                    bool inUzAcum;
                                    cout<<"Utilajul este in uz? Introduceti 1 in caz afirmativ sau 0 daca nu:";
                                    cin>>inUzAcum;
                                    uti[j].setInUz(inUzAcum);
                                    break;
                            }
                        }
                        else
                            cout<<"Introuceti utilaje mai intai.";
                        break;
                    case 5:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"Afisare separata a datelor unui utilaj\".\n";
                            cout<<"Pentru ce utilaj vreti sa afisati separat?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce utilaj vreti sa afisati separat? Introduceti indicele de inscriere:";
                                cin>>j;
                            }
                            cout<<"Ce vreti sa afisati?\n";
                            cout<<"1=>nume\n2=>bugetul de intretinere\n3=>numarul de ore in care a fost folosit\n4=>daca utilajul este sau nu in uz\n";
                            cout<<"Optiunea dumneavoastra:";cin>>op23;
                            while(op3>9||op3<1)
                            {
                                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                                cout<<"Ce vreti sa afisati?\n";
                                cout<<"1=>nume\n2=>bugetul de intretinere\n3=>numarul de ore in care a fost folosit\n4=>daca utilajul este sau nu in uz\n";
                                cout<<"Optiunea dumneavoastra:";cin>>op23;
                            }
                            switch(op23)
                            {
                                case 1:cout<<uti[j].getNume();break;
                                case 2:cout<<uti[j].getBugetIntretinere();break;
                                case 3:cout<<uti[j].getOreFolosite();break;
                                case 4:
                                    if(uti[j].getInUz()==1)
                                        cout<<"Da.";
                                    else
                                        cout<<"Nu";
                                    break;
                            }
                        }
                         else
                            cout<<"Introuceti utilaje mai intai.";
                        break;
                    case 6:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"Crestere ore de folosinta cu o ora\".\n";
                            cout<<"Pentru ce utilaj vreti sa cresteti ora de folosinta cu o ora?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce utilaj vreti sa cresteti ora de folosinta cu o ora? Introduceti indicele acestuia:";
                                cin>>j;
                            }
                            uti[j]++;
                        }
                        else
                            cout<<"Introduceti utilaje mai intai.";
                        break;
                    case 7:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"Verificare daca utilajul este vechi\".\n";
                            cout<<"Pentru ce utilaj vreti sa verificati daca este vechi?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce utilaj vreti sa verificati daca este vechi?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                           vechime(uti[j]);
                        }
                        else
                            cout<<"Introduceti utilaje mai intai.";
                        break;
                    case 8:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"Stergere utilaj\".\n";
                            cout<<"Ce utilaj vreti sa stergeti?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i2||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce utilaj vreti sa stergeti?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            for(p=j;p<i2;p++)
                                uti[p]=uti[p+1];
                            i2--;
                        }
                        else
                            cout<<"Introuceti utilaje mai intai.";
                        break;
                    case 9:
                        if(i2!=0)
                        {
                            cout<<"\nAti ales optiunea \"Afisarea tuturor utilajelor\".\n";
                            for(p=1;p<=i2;p++)
                                cout<<uti[p]<<'\n';
                        }
                        else
                            cout<<"Introuceti utilaje mai intai.";
                        break;
                }
                break;
            case 3:
                cout<<"\nAti ales optiunea Lucrare.\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire lucrare\n2=>Afisare date lucrare\n3=>Modificare pret pe ora pentru o lucrare aleasa\n4=>Afisare pret pe ora pentru o lucrare aleasa\n5=>Suplimentare cu un untilaj a numarului necesar\n6=>Calculare pret lucrare\n7=>Stergere lucrare\n8=>Afisarea tuturor lucrarilor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op31;
                while(op31>8||op31<1)
                {
                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire lucrare\n2=>Afisare date lucrare\n3=>Modificare pret pe ora pentru o lucrare aleasa\n4=>Afisare pret pe ora pentru o lucrare aleasa\n5=>Suplimentare cu un untilaj a numarului necesar\n6=>Calculare pret lucrare\n7=>Stergere lucrare\n8=>Afisarea tuturor lucrarilor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op31;
                }
                switch(op31)
                {
                    case 1:
                        cout<<"\nAti ales optiunea de \"citire lucrare\".\n";
                        i3++;
                        lucr[i3].Citire();
                        break;
                     case 2:
                        if(i3!=0)
                        {
                            cout<<"\nAti ales optiunea \"afisare date lucrare\".\n";
                            cout<<"Ce lucrare vreti sa afisati?\nIntroduceti indicele acesteia:";
                            cin>>j;
                            while(j>i3||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce lucrare vreti sa afisati? Introduceti indicele acesteia:";
                                cin>>j;
                            }
                            lucr[j].Afisare();
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                    case 3:
                        if(i3!=0)
                        {
                            cout<<"\nAti ales optiunea \"modificare pret lucrare\".\n";
                            cout<<"La ce lucrare vreti sa modificati pretul pe ora?\nIntroduceti indicele acesteia:";
                            cin>>j;
                            while(j>i3||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce lucrare vreti sa modificati pretul pe ora?\nIntroduceti indicele acesteia:";
                                cin>>j;
                            }
                            cout<<"\nCum vreti sa modificati pretul pe ora?\n";
                            cout<<"Alegeti optiunea dorita:\n";
                            cout<<"1=>creste pretul pe ora\n2=>scade pretul pe ora\n3=>schimba pretul pe ora\n";
                            cout<<"Optiunea dumneavoastra:";
                            cin>>op32;
                            while(op32<1||op32>3)
                            {
                                cout<<"Optiune introdusa gresit";
                                cout<<"Alegeti optiunea dorita:\n";
                                cout<<"1=>creste pretul pe ora\n2=>scade pretul pe ora\n3=>schimba pretul pe ora\n";
                                cout<<"Optiunea dumneavoastra:";
                                cin>>op32;
                            }
                            switch(op32)
                            {
                                case 1:
                                    float crestere;
                                    cout<<"Introduceti cu cat doriti sa creasca pretul pe ora:";
                                    cin>>crestere;
                                    lucr[j].setPretPeOra(lucr[j].getPretPeOra()+crestere);
                                    break;
                                case 2:
                                    float scadere;
                                    cout<<"Introduceti cu cat doriti sa scada pretul pe ora:";
                                    cin>>scadere;
                                    while(scadere>=lucr[j].getPretPeOra())
                                    {
                                        cout<<"Scadere prea mare.\n";
                                        cout<<"Reintroduceti cu cat doriti sa scada pretul pe ora:";
                                        cin>>scadere;
                                    }
                                    lucr[j].setPretPeOra(lucr[j].getPretPeOra()-scadere);
                                    break;
                                case 3:
                                    float pretNou;
                                    cout<<"Introduceti noul pret:";
                                    cin>>pretNou;
                                    lucr[j].setPretPeOra(pretNou);
                                    break;
                            }
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                    case 4:
                        if(i3!=0)
                        {
                            cout<<"Ati ales optiunea de \"afisare pret pe ora pentru o lucrare aleasa\"\n";
                            cout<<"La ce lucrare vreti sa afisati pretul pe ora?\nIntroduceti indicele acesteia:";
                            cin>>j;
                            while(j>i3||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce lucrare vreti sa afisati pretul pe ora?\nIntroduceti indicele acesteia:";
                                cin>>j;
                            }
                            cout<<lucr[j].getPretPeOra();
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                    case 5:
                        if(i3!=0)
                        {
                            cout<<"Ati ales optiunea de \"suplimentare cu un untilaj a numarului necesar\"\n";
                            cout<<"La ce lucrare vreti sa suplimentati cu un untilaj numarul necesar?\nIntroduceti indicele acesteia:";
                            cin>>j;
                            while(j>i3||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce lucrare vreti sa suplimentati cu un untilaj a numarul necesar?\nIntroduceti indicele acesteia";
                                cin>>j;
                            }
                            lucr[j]++;
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                    case 6:
                        if(i3!=0)
                        {
                            cout<<"Ati ales optiunea de \"calculare pret lucrare\"\n";
                            cout<<"La ce lucrare vreti sa calculati pretul?\nIntroduceti indicele acesteia:";
                            cin>>j;
                            while(j>i3||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"La ce lucrare vreti sa calculati pretul?\nIntroduceti indicele acesteia:";
                                cin>>j;
                            }
                            cout<<lucr[j].PretLucrare(lucr[j]);
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                     case 7:
                        if(i3!=0)
                        {
                            cout<<"\nAti ales optiunea \"Stergere lucrare\".\n";
                            cout<<"Ce lucrare vreti sa stergeti?\nIntroduceti indicele acesteia:";
                            cin>>j;
                            while(j>i3||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce lucrare vreti sa stergeti?\nIntroduceti indicele acesteia:";
                                cin>>j;
                            }
                            for(p=j;p<i3;p++)
                                lucr[p]=lucr[p+1];
                            i3--;
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                    case 8:
                        if(i3!=0)
                        {
                            cout<<"\nAti ales optiunea \"Afisare a tuturor lucrarilor\".\n";
                            for(p=1;p<=i3;p++)
                                cout<<lucr[p]<<'\n';
                        }
                        else
                            cout<<"Introuceti lucrari mai intai.";
                        break;
                    }
                break;
            case 4:
                cout<<"\nAti ales optiunea Client.\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire client\n2=>Afisare date client\n3=>Modificare pret\n4=>Afisare pret \n5=>Reducere la cerere\n6=>Stergere client\n7=>Afisarea tuturor clientilor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op41;
                while(op41>7||op41<1)
                {
                cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"\n1=>Citire client\n2=>Afisare date client\n3=>Modificare pret\n4=>Afisare pret \n5=>Reducere la cerere\n6=>Stergere client\n7=>Afisarea tuturor clientilor\n";
                cout<<"Optiunea dumneavoastra:";cin>>op41;
                }
                switch(op41)
                {
                    case 1:
                        cout<<"\nAti ales optiunea de \"citire client\".\n";
                        i4++;
                        cli[i4].Citire();
                        break;
                     case 2:
                        if(i4!=0)
                        {
                            cout<<"\nAti ales optiunea \"afisare date client\".\n";
                            cout<<"Ce client vreti sa afisati?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i4||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce client vreti sa afisati? Introduceti indicele acestuia:";
                                cin>>j;
                            }
                            cli[j].Afisare();
                        }
                        else
                            cout<<"Introuceti clienti mai intai.";
                        break;
                    case 3:
                        if(i4!=0)
                        {
                            cout<<"\nAti ales optiunea \"modificare pret\".\n";
                            cout<<"Pentru ce client vreti sa modificati pretul?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i4||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce client vreti sa modificati pretul?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            cout<<"\nCum vreti sa modificati pretul?\n";
                            cout<<"Alegeti optiunea dorita:\n";
                            cout<<"1=>cresteti pretul\n2=>scadeti pretul\n3=>schimbati pretul\n";
                            cout<<"Optiunea dumneavoastra:";
                            cin>>op42;
                            while(op42<1||op42>3)
                            {
                                cout<<"Optiune introdusa gresit";
                                cout<<"Alegeti optiunea dorita:\n";
                                 cout<<"1=>cresteti pretul\n2=>scadeti pretul\n3=>schimbati pretul\n";
                                cout<<"Optiunea dumneavoastra:";
                                cin>>op42;
                            }
                            switch(op42)
                            {
                                case 1:
                                    float crestere;
                                    cout<<"Introduceti cu cat doriti sa creasca pretul pe ora:";
                                    cin>>crestere;
                                    cli[j].setPret(cli[j]+crestere);
                                    break;
                                case 2:
                                    float scadere;
                                    cout<<"Introduceti cu cat doriti sa scada pretul:";
                                    cin>>scadere;
                                    while(scadere>=cli[j].getPret())
                                    {
                                        cout<<"Scadere prea mare.\n";
                                        cout<<"Reintroduceti cu cat doriti sa scada pretul:";
                                        cin>>scadere;
                                    }
                                    cli[j].setPret(cli[j].getPret()-scadere);
                                    break;
                                case 3:
                                    float pretNou;
                                    cout<<"Introduceti noul pret:";
                                    cin>>pretNou;
                                    cli[j].setPret(pretNou);
                                    break;
                            }
                        }
                        else
                            cout<<"Introuceti clienti mai intai.";
                        break;
                    case 4:
                        if(i4!=0)
                        {
                            cout<<"Ati ales optiunea de \"afisare pret pentru un client ales\"\n";
                            cout<<"Pentru ce client vreti sa afisati pretul?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i4||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce client vreti sa afisati pretul?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            cout<<cli[j].getPret();
                        }
                        else
                            cout<<"Introuceti clienti mai intai.";
                        break;
                    case 5:
                        if(i4!=0)
                        {
                            cout<<"Ati ales optiunea de \"reducere la cerere\"\n";
                            cout<<"Pentru ce client vreti sa recalculati pretul cu reducere?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i4||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Pentru ce client vreti sa recalculati pretul cu reducere?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            cli[j].setPret(Reducere(cli[j].getPret()));
                        }
                        else
                            cout<<"Introuceti clienti mai intai.";
                        break;
                     case 6:
                        if(i4!=0)
                        {
                            cout<<"\nAti ales optiunea \"Stergere client\".\n";
                            cout<<"Ce client vreti sa stergeti?\nIntroduceti indicele acestuia:";
                            cin>>j;
                            while(j>i4||j<1)
                            {
                                cout<<"Indice incorect.Reintroduceti indicele.\n";
                                cout<<"Ce client vreti sa stergeti?\nIntroduceti indicele acestuia:";
                                cin>>j;
                            }
                            for(p=j;p<i3;p++)
                                cli[p]=cli[p+1];
                            i4--;
                        }
                        else
                            cout<<"Introuceti clienti mai intai.";
                        break;
                    case 7:
                        if(i4!=0)
                        {
                            cout<<"\nAti ales optiunea \"Afisare a tuturor clientilor\".\n";
                            for(p=1;p<=i4;p++)
                                cout<<cli[p]<<'\n';
                        }
                        else
                            cout<<"Introuceti clienti mai intai.";
                        break;
                    }
                break;
            case 5:
                if(i4!=0&&i2!=0)
                {
                    cout<<"\nAti ales optiunea \"Daca un client se plange ca este pretul prea mare\".\n";
                    cout<<"Introduceti indicele clientului:";
                    cin>>j;
                    while(j>i4||j<1)
                    {
                        cout<<"Indice incorect.\n";
                        cout<<"Reintroduceti indicele clientului:";
                        cin>>j;
                    }
                    cout<<"Introduceti indicele utilajului:";
                    cin>>k;
                    while(k>i2||k<1)
                    {
                        cout<<"Indice incorect.\n";
                        cout<<"Reintroduceti indicele utilajului:";
                        cin>>k;
                    }
                    cout<<"Pretul de intretinere al utilajelor+pretul lucrarii la alte firme:\n";
                    cout<<uti[k]+cli[j]<<'\n';
                    cout<<cli[j]+uti[k]<<'\n';
                    cout<<"Uniele firme au pretul de intretinere dublu:\n";
                    cout<<uti[k]+cli[j]+uti[k]<<'\n';
                    cout<<uti[k]+uti[k]+cli[j]<<'\n';
                    cout<<"Unele firme au si pretul total dublu:\n";
                    cout<<uti[k]+cli[j]+uti[k]+cli[j]<<'\n';
                    cout<<cli[k]+uti[k]+cli[j]+uti[k]<<'\n';
                    cout<<uti[k]+uti[k]+cli[j]+cli[j]<<'\n';
                    cout<<cli[j]+uti[k]+uti[k]+cli[j];
                }
                else
                    cout<<"Mai intai introduceti clienti si/sau utilaje";
                break;
        }
    }
    return 0;
}
