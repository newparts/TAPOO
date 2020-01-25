
#include <iostream>

using namespace std;

//--------------------------------------------------------------------

class Mediator;

//--------------------------------------------------------------------

class Coleg{ //colleague

protected:

Mediator *m;

int ID;

public:

Coleg(){};

Coleg(int id){ID=id;};

void Primeste(char *s){cout<<"\n The colleague "<<ID<<" received the message!"<<s;};

void Trimite(char *s){cout<<s;};

friend int egal(Coleg,Coleg); //tests the equality of two colleagues

};

//--------------------------------------------------------------------

class Mediator{ //mediator1

public:

virtual void TrimiteMesaj(char *s, Coleg c){};

};

//--------------------------------------------------------------------

class CMediator:public Mediator{

int nc;

Coleg c[10]; //colleague from chat

public:

CMediator(){nc=0;};

CMediator(int ncc){nc=ncc;};

void TrimiteMesaj (char *s, Coleg dest);

void Add(Coleg cc);

};

//--------------------------------------------------------------------

int egal(Coleg c1, Coleg c2)

{

if (c1.ID==c2.ID) return 0;

return 1;

};

//--------------------------------------------------------------------

void CMediator::Add(Coleg cc)

{

nc=nc+1;

c[nc]=cc;

};

//--------------------------------------------------------------------

void CMediator::TrimiteMesaj(char *s, Coleg dest)

{

int i;

for(i=1;i<=nc;i++) //searching destination's colleague

if (egal(c[i],dest))

c[i].Primeste(s);

};

//--------------------------------------------------------------------

class ConcretColeg:public Coleg

{

public:

ConcretColeg(){};

ConcretColeg(int id):Coleg(id){};

ConcretColeg(Mediator &mm, int id):Coleg(id)

{ m=new Mediator; m=&mm; }

void Trimite(char *s)

{ m->TrimiteMesaj(s,*this); };

void Primeste(char *s)

{ cout<<ID<<" will receive the message! "<<s; };

};

//--------------------------------------------------------------------

int main()

{

CMediator cm;

ConcretColeg c1(cm,1);

ConcretColeg c2(cm,2);

cm.Add(c2);

cm.Add(c1);

c1.Trimite("\t Greetings from first colleague!");

c2.Trimite("\t Greetings from second colleague!");

}
