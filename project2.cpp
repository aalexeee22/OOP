#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Utilaje
{
    string nume;
    double bugetIntretinere;
    int nrOreFolosit;
    bool inUz;
public:
    double getBugetIntretinere() const;
    bool getInUz() const;
    void setInUz(bool inUz);

    Utilaje& operator=(const Utilaje &uti);///supraincarcare operator =
    friend istream& operator>>(istream& in, Utilaje& uti);///supraincarcare operator citire
    friend ostream& operator<<(ostream&out,const Utilaje& uti);///supraincarcare operator afisare
    bool operator==(const Utilaje& u); ///supraincarcare operator==


    Utilaje();
    Utilaje(string nume, double bugetIntretinere,int nrOreFolosit,bool inUz);///constructor cu toti patametrii
    Utilaje(const Utilaje& uti);///copy constructor

    ~Utilaje();///destructor

    void citireDinLucrare();
    void acordareBugetIntretinere();///functionalitate=>calculare buget de intretinere
};
void Utilaje::setInUz(bool inUz)
{
    this->inUz=inUz;
}
double Utilaje::getBugetIntretinere() const
{
    return this->bugetIntretinere;
}
bool Utilaje::getInUz() const
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
istream& operator>>(istream& in, Utilaje& uti)///supraincarcare operator citire
{
    cout<<"Nume:";
    in>>uti.nume;
    cout<<"Buget intretinere:";
    in>>uti.bugetIntretinere;
    cout<<"Numarul de ore in care a fost utilizat:";
    in>>uti.nrOreFolosit;
    uti.acordareBugetIntretinere();
    cout<<"Este in uz?(0/1):";
    in>>uti.inUz;
    return in;
}
ostream& operator<<(ostream& out,const Utilaje& uti)///supraincarcare operator afisare
{
    out<<"Nume:"<<uti.nume<<'\n';
    out<<"Buget intretinere:"<<uti.bugetIntretinere<<'\n';
    out<<"Numarul de ore in care a fost utilizat:"<<uti.nrOreFolosit<<'\n';
    out<<"Este in uz:"<<uti.inUz<<'\n';
    return out;
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
void Utilaje::citireDinLucrare()
{
    cout<<"Nume:";
    cin>>this->nume;
}
void Utilaje::acordareBugetIntretinere()///functionalitate clasa Utilaje: buget intretinere
{
    if(this->nrOreFolosit>40)
        this->bugetIntretinere+=0.1*this->bugetIntretinere;
}
class Lucrare
{
    string nume;
    int nrOreNecesare;
    int nrUtilaje;
    Utilaje* utie;
public:
    int getNrOreNecesare() const;
    int getNrUtilaje() const;

    Lucrare& operator=(const Lucrare& lucr);///supraincarcare operator =
    friend istream&operator>>(istream &in,Lucrare &lucr);///supraincarcare operator citire
    friend ostream &operator<<(ostream& out,const Lucrare &lucr);///supraincarcare operator afisare

    Lucrare();///constructor default
    Lucrare(string nume,int nrOreNecesare,int nrUtilaje,Utilaje* utie);///constructor cu toti parametrii
    Lucrare(const Lucrare& lucr);///copy constructor
    ~Lucrare();///destructor

    bool disponibilitate(vector<Utilaje> uti);///functionalitate clasa:verificarea disponibilitatii utilajelor pentru executarea lucrarii
};
int Lucrare::getNrUtilaje() const
{
    return this->nrUtilaje;
}
int Lucrare::getNrOreNecesare() const
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
Lucrare::Lucrare(const Lucrare& lucr)
{
    this->nume=lucr.nume;
    this->nrOreNecesare=lucr.nrOreNecesare;
    this->nrUtilaje=lucr.nrUtilaje;
    this->utie=new Utilaje[this->nrUtilaje];
    for(int i=0;i<this->nrUtilaje;i++)
        this->utie[i]=lucr.utie[i];
}
Lucrare::~Lucrare()
{
    if(this->utie!=NULL)
        delete[] this->utie;
    this->utie=NULL;
}
bool Lucrare::disponibilitate(vector<Utilaje> uti)///functionalitate clasa:verificarea disponibilitatii utilajelor pentru executarea lucrarii
{
    int ok;
    for(int j=0;j<this->nrUtilaje;j++)
    {
        ok=0;
        for(int i=0;i<uti.size();i++)
        {
            if(uti[i].getInUz()==0&&uti[i]==this->utie[j])
            {
                ok=1;
                uti[i].setInUz(1);
                break;
            }
        }
    if(ok==0)
        return false;
    }
    return true;
}
class IOinterface///clasa abstracta/interfata
{
public:
    virtual istream& citire(istream& in) =0;
    virtual ostream& afisare(ostream& out)const =0;
};
class DatePersonale:virtual public IOinterface///clasa abstracta
{
protected:
    string nume;
    string prenume;
    char initialaTatalui;
public:
    DatePersonale& operator=(const DatePersonale& dp);///supraincarcare operator =
    bool operator==(const DatePersonale& dp);///supraincarcare operator ==

    istream& citire(istream& in);///citire
    friend istream& operator>> (istream& in, DatePersonale& dp);///supraincarcare operator citire

    ostream& afisare(ostream& out) const;///afisare
    friend ostream& operator << (ostream& out, const DatePersonale& dp);///supraincarcare operator afisare


    DatePersonale();///constructor default
    DatePersonale(string nume,string prenume,char initialaTatalui);///constructor cu toti parametrii
    DatePersonale(const DatePersonale& dp);///copy constructor
    ~DatePersonale();///destructor

    bool exista(vector<DatePersonale> dp);
};
DatePersonale& DatePersonale::operator=(const DatePersonale& dp)///supraincarcare operator =
{
    if(this!=&dp)
    {
        this->nume=dp.nume;
        this->prenume=dp.prenume;
        this->initialaTatalui=dp.initialaTatalui;
    }
    return *this;
}
bool DatePersonale::operator==(const DatePersonale& dp)///supraincarcare operator ==
{
    if((this->nume).compare(dp.nume)==0&&(this->prenume).compare(dp.prenume)==0&&this->initialaTatalui==dp.initialaTatalui)
        return true;
    return false;
}
istream& DatePersonale::citire(istream& in)///citire
{
    cout<<"Nume:";
    in>>this->nume;
    cout<<"Prenume:";
    in>>this->prenume;
    cout<<"Initiala tatalui:";
    in>>this->initialaTatalui;
    return in;
}
istream& operator>> (istream& in, DatePersonale& dp)///supraincarcare operator citire
{
    return dp.citire(in);
}
ostream& DatePersonale::afisare(ostream& out) const///afisare
{
    out<<"Numele:"<<this->nume<<endl;
    out<<"Prenume:"<<this->prenume<<endl;
    out<<"Initiala tatalui:"<<this->initialaTatalui<<endl;
    return out;
}
ostream& operator << (ostream& out, const DatePersonale& dp)///supraincarcare operator afisare
{
    return dp.afisare(out);
}
DatePersonale::DatePersonale()///constructor default
{
    this->nume="AnonimNume";
    this->prenume="AnonimPrenume";
    this->initialaTatalui='A';
}
DatePersonale::DatePersonale(string nume,string prenume,char initialaTatalui)///constructor cu toti parametrii
{
    this->nume=nume;
    this->prenume=prenume;
    this->initialaTatalui=initialaTatalui;
}
DatePersonale::DatePersonale(const DatePersonale& dp)///copy constructor
{
    this->nume=dp.nume;
    this->prenume=dp.prenume;
    this->initialaTatalui=dp.initialaTatalui;
}

DatePersonale::~DatePersonale()///destructor
{}
bool DatePersonale::exista(vector<DatePersonale> dap)
{
    for(int i=0;i<dap.size();i++)
        if(*this==dap[i])
            return true;
    return false;
}
class Angajat:public virtual DatePersonale
{
protected:
    int varsta;
    int vechime;
    int nrZileMuncite;
    int* nrOreMuncite;
    int* nrOreSuplimentare;
    double salariu;
public:
    void setZileMuncite(int* nrOreMuncite,int* nrOreSuplimentare,int nrZileMuncite);///setter pt int* si int
    double getSalariu() const;///getter salariu

    Angajat& operator =(const Angajat& ang);///spuraincarcare operator =
    istream& citire(istream& in);///citire
    ostream& afisare(ostream& out) const;///afisare

    Angajat();///constructor default
    Angajat(string nume, string prenume, char initialaTatalui,int varsta,int vechime,int nrZileMuncite,int* nrOreMuncite, int*nrOreSuplimentare,double salariu);///constructor cu toti parametrii
    Angajat(const Angajat& ang);///copy constructor
    ~Angajat();///destructor

    void calculSalariu();///functionalitate clasa Angajat:calcul salariu
};
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
double Angajat::getSalariu() const///getter salariu
{
    return this->salariu;
}
Angajat& Angajat::operator =(const Angajat& ang)///spuraincarcare operator =
{
    if(this!=&ang)
    {
        DatePersonale::operator=(ang);
        this->varsta=ang.varsta;
        this->vechime=ang.vechime;
        this->nrZileMuncite=ang.nrZileMuncite;

        if(this->nrOreMuncite!=NULL)
            delete[] this->nrOreMuncite;
        this->nrOreMuncite=new int[nrZileMuncite];
        for(int i=0;i<this->nrZileMuncite;i++)
            this->nrOreMuncite[i]=ang.nrOreMuncite[i];

        if(this->nrOreSuplimentare!=NULL)
            delete[] this->nrOreSuplimentare;
        this->nrOreSuplimentare=new int[nrZileMuncite];
        for(int i=0;i<this->nrZileMuncite;i++)
            this->nrOreSuplimentare[i]=ang.nrOreSuplimentare[i];
        this->salariu=ang.salariu;
    }
    return *this;
}
istream& Angajat::citire(istream& in)///citire
{
    DatePersonale::citire(in);
    cout<<"Varsta:";
    in>>this->varsta;
    cout<<"Vechime:";
    in>>this->vechime;
    cout<<"Numarul de zile muncite:";
    in>>this->nrZileMuncite;

    if(this->nrOreMuncite!=NULL)
        delete[] this->nrOreMuncite;
    this->nrOreMuncite=new int[this->nrZileMuncite];
    cout<<"Cate ore a muncit in fiecare zi?\n";
    for(int i=0;i<this->nrZileMuncite;i++)
        in>>this->nrOreMuncite[i];

    if(this->nrOreSuplimentare!=NULL)
        delete[] this->nrOreSuplimentare;
    this->nrOreSuplimentare=new int[this->nrZileMuncite];
    cout<<"Cate ore suplimentare a muncit in fiecare zi?\n";
    for(int i=0;i<this->nrZileMuncite;i++)
        in>>this->nrOreSuplimentare[i];
    this->calculSalariu();
    return in;
}
ostream& Angajat::afisare(ostream& out) const///afisare
{
    DatePersonale::afisare(out);
    out<<"Varsta:"<<this->varsta<<'\n';
    out<<"Vechime:"<<this->vechime<<'\n';
    out<<"Numarul de zile muncite:"<<this->nrZileMuncite<<'\n';

    out<<"Cate ore a muncit in fiecare zi?\n";
    for(int i=0;i<this->nrZileMuncite;i++)
        out<<this->nrOreMuncite[i]<<" ";
    out<<'\n';

    out<<"Cate ore suplimentare a muncit in fiecare zi?\n";
    for(int i=0;i<this->nrZileMuncite;i++)
        out<<this->nrOreSuplimentare[i]<<" ";
    out<<'\n';
    out<<"Salariu:"<<this->salariu<<'\n';
    return out;
}
Angajat::Angajat():DatePersonale()///constructor default
{
    this->varsta=0;
    this->vechime=0;
    this->nrZileMuncite=0;
    this->nrOreMuncite=NULL;
    this->nrOreSuplimentare=NULL;
    this->salariu=0;
}
Angajat::Angajat(string nume, string prenume, char initialaTatalui,int varsta,int vechime,int nrZileMuncite,int* nrOreMuncite, int* nrOreSuplimentare,double salariu):DatePersonale(nume,prenume,initialaTatalui)///constructor cu toti parametrii
{
    this->varsta=varsta;
    this->vechime=vechime;
    this->nrZileMuncite=nrZileMuncite;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(int i=0;i<this->nrZileMuncite;i++)
        this->nrOreMuncite[i]=nrOreMuncite[i];
    this->nrOreSuplimentare=new int[nrZileMuncite];
    for(int i=0;i<this->nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=nrOreSuplimentare[i];
    this->calculSalariu();
}
Angajat::Angajat(const Angajat& ang):DatePersonale(ang)///copy constructor
{
    this->varsta=ang.varsta;
    this->vechime=ang.vechime;
    this->nrZileMuncite=ang.nrZileMuncite;
    this->nrOreMuncite=new int[nrZileMuncite];
    for(int i=0;i<this->nrZileMuncite;i++)
        this->nrOreMuncite[i]=ang.nrOreMuncite[i];
    this->nrOreSuplimentare=new int[nrZileMuncite];
    for(int i=0;i<this->nrZileMuncite;i++)
        this->nrOreSuplimentare[i]=ang.nrOreSuplimentare[i];
    this->salariu=ang.salariu;
}
Angajat::~Angajat()///destructor
{
    if(this->nrOreMuncite!=NULL)
        delete[] this->nrOreMuncite;
    this->nrOreMuncite=NULL;
    if(this->nrOreSuplimentare!=NULL)
        delete[] this->nrOreSuplimentare;
    this->nrOreSuplimentare=NULL;
}
void Angajat::calculSalariu()///functionalitate clasa Angajat:calcul salariu
{
    int i;
    this->salariu=0;
    for(i=0;i<this->nrZileMuncite;i++)
        this->salariu+=20.5*this->nrOreMuncite[i]+25.5*this->nrOreSuplimentare[i];
}
class Client:public virtual DatePersonale
{
protected:
    Lucrare lucrarea;
    double pret;
public:
    double getPret() const;

    Client& operator=(const Client& cli);///supraincarcare operator =
    istream& citire(istream& in);///citire
    ostream& afisare(ostream& out) const;///afisare
    Client();///constructor default
    Client(string nume,string prenume, char initialaTatalui,Lucrare lucrarea,double pret);///constructor cu toti parametrii
    Client(const Client& cli);///copy constructor
    ~Client();///destructor
    virtual void calculPret();
};
double Client::getPret() const
{
    return this->pret;
}
Client& Client::operator=(const Client& cli)///supraincarcare operator =
{
    if(this!=&cli)
    {
        DatePersonale::operator=(cli);
        this->lucrarea=cli.lucrarea;
        this->pret=cli.pret;
    }
    return *this;
}
istream& Client::citire(istream& in)///citire
{
    DatePersonale::citire(in);
    cout<<"Lucrare:\n";
    in>>this->lucrarea;
    cout<<"Pret:";
    in>>this->pret;
    this->calculPret();
    cout<<'\n';
    return in;
}
ostream& Client::afisare(ostream& out) const///afisare
{
    DatePersonale::afisare(out);
    out<<"Lucrare:\n";
    out<<this->lucrarea;
    out<<'\n';
    out<<"Pret:"<<this->pret<<'\n';
    return out;
}
Client::Client():DatePersonale()///constructor default
{
    this->pret=0;
}
Client::Client(string nume, string prenume, char initialaTatalui,Lucrare lucrarea,double pret):DatePersonale(nume,prenume,initialaTatalui)///constructor cu toti parametrii
{
    this->lucrarea=lucrarea;
    this->pret=pret;
    this->calculPret();
}
Client::Client(const Client& cli):DatePersonale(cli)///copy constructor
{
    this->lucrarea=cli.lucrarea;
    this->pret=cli.pret;
}
Client::~Client()///destructor
{}
void Client::calculPret()
{
    if(this->lucrarea.getNrOreNecesare()>24)
        this->pret+=0.1*this->pret;
}
class ClientAngajat:public Angajat,public Client
{
public:

    ClientAngajat& operator=(const ClientAngajat& cliang);///supraincarcare operator =
    istream& citire(istream& in);///citire
    ostream& afisare(ostream& out) const;///afisare
    ClientAngajat();///constructor default
    ClientAngajat(string nume, string prenume, char initialaTatalui,int varsta,int vechime,int nrZileMuncite,int* nrOreMuncite, int*nrOreSuplimentare,double salariu,Lucrare lucrarea,double pret);///constructor cu toti parametrii
    ClientAngajat(const ClientAngajat& cliang);///copy constructor
    ~ClientAngajat();///destructor
    void calculPret();///functionalitate+exemplu virtualizare
};
ClientAngajat& ClientAngajat::operator=(const ClientAngajat& cliang)///supraincarcare operator =
{
    if(this!=&cliang)
    {
        DatePersonale::operator=(cliang);
        this->lucrarea=cliang.lucrarea;
        this->pret=cliang.pret;
    }
    return *this;
}
istream& ClientAngajat::citire(istream& in)///citire
{
    Angajat::citire(in);
    cout<<"Lucrare:\n";
    in>>this->lucrarea;
    cout<<"Pret:";
    in>>this->pret;
    this->calculPret();
    cout<<'\n';
    return in;
}
ostream& ClientAngajat::afisare(ostream& out) const
{
    Angajat::afisare(out);
    out<<"Lucrare:\n";
    out<<this->lucrarea;
    out<<'\n';
    out<<"Pret:"<<this->pret<<'\n';
    return out;
}
ClientAngajat::ClientAngajat():DatePersonale(),Angajat(),Client()///constructor default
{}
ClientAngajat::ClientAngajat(string nume, string prenume, char initialaTatalui,int varsta,int vechime,int nrZileMuncite,int* nrOreMuncite, int*nrOreSuplimentare,double salariu,Lucrare lucrarea,double pret):DatePersonale(nume,prenume,initialaTatalui),Angajat(nume, prenume, initialaTatalui,varsta,vechime,nrZileMuncite,nrOreMuncite, nrOreSuplimentare,salariu),Client(nume,prenume,initialaTatalui,lucrarea,pret)///constructor cu toti parametrii
{
this->calculPret();
}
ClientAngajat::ClientAngajat(const ClientAngajat& cliang):DatePersonale(cliang),Angajat(cliang),Client(cliang)///copy constructor
{
    this->lucrarea=cliang.lucrarea;
    this->pret=cliang.pret;
}
ClientAngajat::~ClientAngajat()///destructor
{
    if(this->nrOreMuncite!=NULL)
        delete[] this->nrOreMuncite;
    this->nrOreMuncite=NULL;
    if(this->nrOreSuplimentare!=NULL)
        delete[] this->nrOreSuplimentare;
    this->nrOreSuplimentare=NULL;
}
void ClientAngajat::calculPret()
{
    if(this->lucrarea.getNrOreNecesare()>24)
        this->pret+=0.1*this->pret;
    if(this->vechime>10)
        this->pret-=0.15*this->pret;
}
int main()
{
    vector<DatePersonale> dp;
    vector<Angajat> ang;
    vector<Client> cli;
    vector<ClientAngajat> cliang;
    vector<Utilaje> uti;
    vector<Lucrare> lucr;
    DatePersonale dp1;
    //Angajat ang1;
    Client cli1;
    //ClientAngajat cliang1;
    Utilaje uti1;
    Lucrare lucr1;
    int i,indice,ok=1,op,op1,op2,op3,op4,op5,op6;
    bool optIesireIntrare;

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
        cout<<"1=>Date Personale\n2=>Angajat\n3=>Client\n4=>Client care este si angajat\n5=>Utilaje\n6=>Lucrare\n";
        cout<<"Optiunea dumneavoastra:";cin>>op;
        while(op>6||op<1)
        {
            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
            cout<<"Alegeti categoria cu care vreti sa lucrati:\n";
            cout<<"1=>Date Personale\n2=>Angajat\n3=>Client\n4=>Client care este si angajat\n5=>Utilaje\n6=>Lucrare\n";
            cout<<"Optiunea dumneavoastra:";cin>>op;
        }
        switch(op)
        {
            case 1:
                cout<<"\nAti ales optiunea \"Date Personale\".\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"1=>Adaugare o persoana\n2=>Afisare o persoana\n3=>Afisare totala\n4=>Stergere o persoana\n5=>Exista in baza de date?\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>op1;
                while(op1>5||op1<1)
                {
                    cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare o persoana\n2=>Afisare o persoana\n3=>Afisare totala\n4=>Stergere o persoana\n5=>Exista in baza de date?\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op1;
                }
                switch(op1)
                {
                    case 1:
                        cout<<"\nAti ales optiunea \"Adaugare o persoana\".\n";
                        cin>>dp1;
                        dp.push_back(dp1);
                        break;
                    case 2:
                        cout<<"\nAti ales optiunea \"Afisare o persoana\".\n";
                        if(dp.size()<1)
                        {
                            cout<<"Introduceti persoane mai intai.";
                            break;
                        }
                        cout<<"Introduceti indicele persoanei dorite:";
                        cin>>indice;
                        while(indice>dp.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele persoanei dorite:";
                            cin>>indice;
                        }
                        cout<<'\n'<<dp[indice-1];
                        break;
                    case 3:
                        cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                        if(dp.size()<1)
                        {
                            cout<<"Introduceti persoane mai intai.";
                            break;
                        }
                        for(i=0;i<dp.size();i++)
                            cout<<dp[i]<<endl;
                        break;
                    case 4:
                        cout<<"\nAti ales optiunea \"Stergere o persoana\".\n";
                        if(dp.size()<1)
                        {
                            cout<<"Nu exista date personale introduse.";
                            break;
                        }
                        cout<<"Introduceti indicele persoanei dorite:";
                        cin>>indice;
                        while(indice>dp.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele persoanei dorite:";
                            cin>>indice;
                        }
                        dp.erase(dp.begin()+indice-1);
                        break;
                    case 5:
                        cout<<"\nAti ales optiunea \"Exista in baza de date?\".\n";
                        if(dp.size()<1)
                        {
                            cout<<"Nu exista date personale introduse.\n";
                            break;
                        }
                        cout<<"Introduceti datele persoanei ale carei date vreti sa vedeti daca exista in baza de date.\n";
                        cin>>dp1;
                        if(dp1.exista(dp)==true)
                            cout<<"Exista in baza de date.";
                        else
                            cout<<"Nu exista in baza de date.";
                        break;
                }

                break;
            case 2:
                cout<<"\nAti ales optiunea \"Angajat\".\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"1=>Adaugare angajat\n2=>Afisare angajat\n3=>Afisare totala\n4=>Stergere un angajat\n5=>Salariu\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>op2;
                while(op2>5||op2<1)
                {
                    cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare angajat\n2=>Afisare angajat\n3=>Afisare totala\n4=>Stergere un angajat\n5=>Salariu\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op2;
                }
                switch(op2)
                {
                    case 1:
                        {cout<<"\nAti ales optiunea \"Adaugare angajat\".\n";
                        Angajat ang1;
                        cin>>ang1;
                        ang.push_back(ang1);
                        ang1.~Angajat();
                        break;}
                    case 2:
                        cout<<"\nAti ales optiunea \"Adaugare angajat\".\n";
                        if(ang.size()<1)
                        {
                            cout<<"Introduceti angajati mai intai.";
                            break;
                        }
                        cout<<"Introduceti indicele angajatului dorit:";
                        cin>>indice;
                        while(indice>ang.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele angajatului dorit:";
                            cin>>indice;
                        }
                        cout<<'\n'<<ang[indice-1];
                        break;
                    case 3:
                        cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                        if(ang.size()<1)
                        {
                            cout<<"Introduceti angajati mai intai.";
                            break;
                        }
                        for(i=0;i<ang.size();i++)
                            cout<<ang[i]<<endl;
                        break;
                    case 4:
                        cout<<"\nAti ales optiunea \"Stergere angajat\".\n";
                        if(ang.size()<1)
                        {
                            cout<<"Nu exista angajati introdusi.";
                            break;
                        }
                        cout<<"Introduceti indicele angajatului dorit:";
                        cin>>indice;
                        while(indice>ang.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele angajatului dorit:";
                            cin>>indice;
                        }
                        ang.erase(ang.begin()+indice-1);
                        break;
                    case 5:
                        {cout<<"\nAti ales optiunea \"Salariu\".\n";
                        if(ang.size()<1)
                        {
                            cout<<"Nu exista angajati introdusi.";
                            break;
                        }
                        cout<<"Introduceti indicele angajatului dorit:";
                        cin>>indice;
                        while(indice>ang.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele angajatului dorit:";
                            cin>>indice;
                        }
                        Angajat ang1;
                        cout<<"Salariul actual este:"<<ang[indice-1].getSalariu()<<'\n';
                        cout<<"Pentru a calcula un posibil salariu, fara a modifica datele actuale, urmati urmatoarele instructiuni.\n";
                        int nrzilemuncite;
                        cout<<"Introduceti numarul de zile muncite:";cin>>nrzilemuncite;
                        int nroremuncite[nrzilemuncite],nroresuplimentare[nrzilemuncite];
                        cout<<"Introduceti numarul de ore muncite zilnic:";
                        for(i=0;i<nrzilemuncite;i++)
                            cin>>nroremuncite[i];
                        cout<<"Introduceti numarul de ore suplimentare muncite zilnic:";
                        for(i=0;i<nrzilemuncite;i++)
                            cin>>nroresuplimentare[i];
                        ang1.setZileMuncite(nroremuncite,nroresuplimentare,nrzilemuncite);
                        ang1.calculSalariu();
                        cout<<ang1.getSalariu();
                        ang1.~Angajat();
                        }
                }
                break;
            case 3:
                cout<<"\nAti ales optiunea \"Client\".\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"1=>Adaugare client\n2=>Afisare client\n3=>Afisare totala\n4=>Stergere un client\n5=>Pret\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>op3;
                while(op3>5||op3<1)
                {
                    cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare client\n2=>Afisare client\n3=>Afisare totala\n4=>Stergere un client\n5=>Pret\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op3;
                }
                switch(op3)
                {
                    case 1:
                        cout<<"\nAti ales optiunea \"Adaugare client\".\n";
                        cin>>cli1;
                        cli.push_back(cli1);
                        break;
                    case 2:
                        cout<<"\nAti ales optiunea \"Afisare client\".\n";
                        if(cli.size()<1)
                        {
                            cout<<"Introduceti clienti mai intai.";
                            break;
                        }
                        cout<<"Introduceti indicele clientului dorit:";
                        cin>>indice;
                        while(indice>cli.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele clientului dorit:";
                            cin>>indice;
                        }
                        cout<<'\n'<<cli[indice-1];
                        break;
                    case 3:
                        cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                        if(cli.size()<1)
                        {
                            cout<<"Introduceti persoane mai intai.";
                            break;
                        }
                        for(i=0;i<cli.size();i++)
                            cout<<cli[i]<<endl;
                        break;
                    case 4:
                        cout<<"\nAti ales optiunea \"Stergere client\".\n";
                        if(cli.size()<1)
                        {
                            cout<<"Nu exista date clienti introdusi.";
                            break;
                        }
                        cout<<"Introduceti indicele clientului dorit:";
                        cin>>indice;
                        while(indice>cli.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele clientului dorit:";
                            cin>>indice;
                        }
                        cli.erase(cli.begin()+indice-1);
                        break;
                    case 5:
                        cout<<"\nAti ales optiunea \"Pret\".\n";
                        if(cli.size()<1)
                        {
                            cout<<"Nu exista clienti introdusi.";
                            break;
                        }
                        cout<<"Introduceti indicele clientului dorit:";
                        cin>>indice;
                        while(indice>cli.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele clientului dorit:";
                            cin>>indice;
                        }
                        cout<<"Pretul lucrarii este:"<<cli[indice-1].getPret()<<'\n';
                        break;
                }
                break;
            case 4:
                cout<<"\nAti ales optiunea \"Client care este si angajat\".\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"1=>Adaugare client care este si angajat\n2=>Afisare client care este si angajat\n3=>Afisare totala\n4=>Stergere unui client care este si angajat\n5=>Pret\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>op4;
                while(op4>5||op4<1)
                {
                    cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare client care este si angajat\n2=>Afisare client care este si angajat\n3=>Afisare totala\n4=>Stergerea unui client care este si angajat\n5=>Pret\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op4;
                }
                switch(op4)
                {
                    case 1:
                        {cout<<"\nAti ales optiunea \"Adaugare client care este si angajat\".\n";
                        ClientAngajat cliang1;
                        cin>>cliang1;
                        cliang.push_back(cliang1);
                        cliang1.~ClientAngajat();
                        break;}
                    case 2:
                        cout<<"\nAti ales optiunea \"Afisare client care este si angajat\".\n";
                        if(cliang.size()<1)
                        {
                            cout<<"Introduceti clienti care sunt si angajati mai intai.";
                            break;
                        }
                        cout<<"Introduceti indicele clientului care este si angajat dorit:";
                        cin>>indice;
                        while(indice>cliang.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele clientului care este si angajat dorit:";
                            cin>>indice;
                        }
                        cout<<'\n'<<cliang[indice-1];
                        break;
                    case 3:
                        cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                        if(cliang.size()<1)
                        {
                            cout<<"Introduceti clienti care sunt si angajati mai intai.";
                            break;
                        }
                        for(i=0;i<cliang.size();i++)
                            cout<<cliang[i]<<endl;
                        break;
                    case 4:
                        cout<<"\nAti ales optiunea \"Stergerea unui client care este si angajat\".\n";
                        if(cliang.size()<1)
                        {
                            cout<<"Nu exista clienti care sunt si angajati introdusi.";
                            break;
                        }
                        cout<<"Introduceti indicele clientului care este si angajat dorit:";
                        cin>>indice;
                        while(indice>cliang.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele clientului care este si angajat dorit:";
                            cin>>indice;
                        }
                        cliang.erase(cliang.begin()+indice-1);
                        break;
                    case 5:
                        cout<<"\nAti ales optiunea \"Pret\".\n";
                        if(cliang.size()<1)
                        {
                            cout<<"Nu exista clienti introdusi.";
                            break;
                        }
                        cout<<"Introduceti indicele clientului dorit:";
                        cin>>indice;
                        while(indice>cliang.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele clientului dorit:";
                            cin>>indice;
                        }
                        cout<<"Pretul lucrarii este:"<<cliang[indice-1].getPret()<<'\n';
                        break;
                }
                break;
            case 5:
                cout<<"\nAti ales optiunea \"Utilaje\".\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"1=>Adaugare utilaj\n2=>Afisare utilaj\n3=>Afisare totala\n4=>Stergere un utilaj\n5=>Buget intretinere\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>op5;
                while(op5>5||op5<1)
                {
                    cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare utilaj\n2=>Afisare utilaj\n3=>Afisare totala\n4=>Stergere un utilaj\n5=>Buget intretinere\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op5;
                }
                switch(op5)
                {
                    case 1:
                        cout<<"\nAti ales optiunea \"Adaugare utilaj\".\n";
                        cin>>uti1;
                        uti.push_back(uti1);
                        break;
                    case 2:
                        cout<<"\nAti ales optiunea \"Afisare utilaj\".\n";
                        if(uti.size()<1)
                        {
                            cout<<"Introduceti utilaje mai intai.";
                            break;
                        }
                        cout<<"Introduceti indicele utilajului dorit:";
                        cin>>indice;
                        while(indice>uti.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele utilajului dorit:";
                            cin>>indice;
                        }
                        cout<<'\n'<<uti[indice-1];
                        break;
                    case 3:
                        cout<<"\nAti ales optiunea \"Afisare totala\".\n";
                        if(uti.size()<1)
                        {
                            cout<<"Introduceti utilaje mai intai.";
                            break;
                        }
                        for(i=0;i<uti.size();i++)
                            cout<<uti[i]<<endl;
                        break;
                    case 4:
                        cout<<"\nAti ales optiunea \"Stergere o persoana\".\n";
                        if(uti.size()<1)
                        {
                            cout<<"Nu exista utilaje introduse.";
                            break;
                        }
                        cout<<"Introduceti indicele utilajului dorit:";
                        cin>>indice;
                        while(indice>uti.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele utilajului dorit:";
                            cin>>indice;
                        }
                        uti.erase(uti.begin()+indice-1);
                        break;
                    case 5:
                        cout<<"\nAti ales optiunea \"Buget intretinere\".\n";
                        if(uti.size()<1)
                        {
                            cout<<"Nu exista utilaje introduse.";
                            break;
                        }
                        cout<<"Introduceti indicele utilajului dorit:";
                        cin>>indice;
                        while(indice>uti.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele utilajului dorit:";
                            cin>>indice;
                        }
                        cout<<"Bugetul de intretinere al utilajului este:"<<uti[indice-1].getBugetIntretinere()<<'\n';
                        break;
                }
                break;
            case 6:
                cout<<"\nAti ales optiunea \"Lucrare\".\n";
                cout<<"Alegeti ce doriti sa faceti:\n";
                cout<<"1=>Adaugare lucrare\n2=>Afisare lucrare\n3=>Afisare totala\n4=>Stergerea unei lucrari\n5=>Disponibilitate utilaje\n";
                cout<<"Optiunea dumneavoastra:";
                cin>>op6;
                while(op6>5||op6<1)
                {
                    cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                    cout<<"Alegeti ce doriti sa faceti:\n";
                    cout<<"1=>Adaugare lucrare\n2=>Afisare lucrare\n3=>Afisare totala\n4=>Stergerea unei lucrari\n5=>Disponibilitate utilaje\n";
                    cout<<"Optiunea dumneavoastra:";
                    cin>>op6;
                }
                switch(op6)
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
                        while(indice>lucr.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele lucrarii dorite:";
                            cin>>indice;
                        }
                        cout<<'\n'<<lucr[indice-1];
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
                        while(indice>lucr.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele lucrarii dorite:";
                            cin>>indice;
                        }
                        lucr.erase(lucr.begin()+indice-1);
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
                        while(indice>lucr.size()||indice<1)
                        {
                            cout<<"\nOptiune introdusa gresit.\nReintroduceti optiunea.";
                            cout<<"Introduceti indicele lucrarii dorite:";
                            cin>>indice;
                        }
                        if(uti.size()<lucr[indice-1].getNrUtilaje())
                        {
                            cout<<"Nu exista suficiente utilaje pentru a face aceasta lucrare.\n";
                            break;
                        }
                        if(lucr[indice-1].disponibilitate(uti)==1)
                            cout<<"Lucrarea poate fi realizata. Firma are suficiente utilaje disponibile.\n";
                        else
                             cout<<"Lucrarea nu poate fi realizata. Firma nu are suficiente utilaje disponibile. \n";
                        break;
                }
                break;
        }
    }

    return 0;
}
