#include <iostream>
#include <string.h>

using namespace std;

class Memento;
class Originator{
 char *stare; //starea curenta
 public:
	Originator(){};
	Originator(char *ss){
	    stare=new char[strlen(ss)+1];
	    strcpy(stare,ss);};
   void modificaStare(char *ss){strcpy(stare,ss);};
	Memento* CreareMemento();
	void SetMemento(Memento *);
	void afis()
	{
        cout<<stare;
	};
};
class Memento{
  char *stare; //clona Originator
  public:
	Memento(){};
	Memento(char *ss)
    {
        stare=new char[strlen(ss)+1];
        strcpy(stare,ss);};
	void SetStare (char *ss)
     {strcpy(stare,ss);};
	char * GetStare (){return stare;};
};
Memento* Originator:: CreareMemento()
	{
		 return new Memento(stare);
//creaza un memento cu starea originatorului
	};
void Originator::SetMemento(Memento *m)
{
	 strcpy(stare,m->GetStare());
};//restaureaza starea salvata in memento
class careTaker
{
int nm;//nr de amintiri
Memento m[100]; //lista amintirilor
public:
    careTaker(){nm=0;};
   void addMemento(Memento *mm);
   Memento* getMemento(int i); //a catea?
};

void careTaker::addMemento(Memento* mm)
{
 nm++;
 m[nm]=*mm;//atentie
};
Memento* careTaker::getMemento(int i)
{
   return &m[i];
};
int main()
{
careTaker ct;
Originator o("1");
//Memento m;
ct.addMemento(o.CreareMemento()); //salvare amintire
cout<<"Originalul:";
o.afis();
o.modificaStare("2");
cout<<"\nDupa modificare:";
o.afis();
o.SetMemento(ct.getMemento(1)); //restaurare stare
cout<<"\n UNDO:";
o.afis();

return 0;
}

