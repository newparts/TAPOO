#include <iostream>
using namespace std;

class magazin //reciever
{
public:
    void proceseaza()
    {
        cout<<"comanda trimisa la magazin...";
    };
};
class mag_altex:public magazin //receiver 1
{

};
class mag_domo:public magazin //reciever 2
{

};

class emag //comanda
{
protected:
    magazin m;
public:
    emag(){};
    emag(emag* c)
    {
       this-> m=c->m;
    }
    virtual void trimite(){};

};

class altex:public emag{
public:
    void trimite()
     {
         cout<<"\n ALTEX ";
        m.proceseaza();
    }
};
class domo:public emag{
public:

    void trimite()
     {
         cout<<"\n DOMO ";
        m.proceseaza();
    }
};

class flanco:public emag{
public:

    void trimite()
     {
         cout<<"\n FLANCO  ";
        m.proceseaza();
    }
};

class cumparator //Invoker
{
    emag *e;
public:
    cumparator(){};
    void adaugacomanda(emag *e1)
    {
        e=e1;
    }
    void finalizeazacomanda()
    {
        e->trimite();
    }
};

int main()
{
    cumparator *ixul=new cumparator; //invoker
    emag *com=new altex; //comanda
    ixul->adaugacomanda(com); //seteaza comanda
    ixul->finalizeazacomanda(); //trimite comanda la magazin, actiune

    com=new flanco;
    ixul->adaugacomanda(com); //seteaza comanda
    ixul->finalizeazacomanda(); //trimite comanda la magazin

return 0;
}
