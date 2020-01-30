#include <iostream>
#include <stdio.h>

using namespace std;

class Persoana //handler
	{
	private:
		int cod;
        protected:
		Persoana *succesor;
	public:
		Persoana(int c){cod=c;};
		Persoana(Persoana *);
		virtual void Cerere(int ceva);
		void SetSuccesor(Persoana *);
	};

void Persoana::Cerere(int ceva)
{
	if (succesor!=0)
		{
		succesor->Cerere(ceva);
		}
};

void Persoana::Persoana(Persoana *p=0)
{
    succesor = p;

};

void Persoana::SetSuccesor(Persoana *p)
{
this->succesor=p;
};

class Angajat:public Persoana //handler concret
{

	int vechime;

	public:
	 Angajat(){};
	 Angajat(int c):Persoana(c){};
	 Angajat(int v,int c):Persoana(c){vechime=v;};
	 void Cerere(int);
};

void Angajat::Cerere (int ceva)
{
	if (ceva>=20)
		{
		succesor->Cerere(ceva);
		}
	else
	 if (succesor!=0)
	 cout<<"Angajatul a procesat"<<ceva<<endl;
};

class Manager:public Persoana //alt handler concret
{
	int vechime;
       public:
	      void Cerere (int);
	      Manager(int c):Persoana(c){};
	      Manager(int v,int c):Persoana(c){vechime=v;};
};
void Manager::Cerere(int ceva)
{
	if (ceva>=40)
		{
		succesor->Cerere(ceva);
		}
	else
		if (succesor!=0)
		cout<<"Managerul a procesat "<<ceva<<endl;
};


int main()
{
    Persoana *cineva1=new Angajat(1);
    Persoana *cineva2=new Manager(2);
    cineva1->SetSuccesor(cineva2);
    cineva1->Cerere(10);
}
