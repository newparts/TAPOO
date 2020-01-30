#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

//clasa Existenta->Adaptabilul exista deja
class Personaj{
	char *nume;
	public:
	Personaj(){};
	Personaj(char *n)
		{nume=new char[strlen(n)+1];
		strcpy(nume,n);
		};
		//copy constructor
	virtual void FaCeva()
		{
		cout<<"\n"<<nume<<" este un personaj care se misca";
		};


};


//Targetul (este ceea ce dorim)
class Monstru{
	char *nume;
	public:
	Monstru(){};
	Monstru(char *n)
		{nume=new char[strlen(n)+1];
		strcpy(nume,n);
		};
		//constr copy
	void FaCeva()
		{
		cout<<"\n"<<nume<<" este un monstru care urla";
		}
};

//Adaptor de la personaj la monstru

class Adaptor{
	Monstru *p;///
	public:
	Adaptor(){};
	Adaptor(char *n)
		{
		p=new Monstru(n);
		};
	Adaptor(Monstru *cineva)
		{//de completat!!!
		    p=cineva;
		};
	void FaCeva();
};
void Adaptor::FaCeva() //se schimba operatia FaCeva corespunzator
	{
	p->FaCeva();
	};


int  main()
{

Adaptor *monstru=new Adaptor("Dracula");;
monstru->FaCeva();
Personaj *personaj=new Personaj("Scooby Doo");
personaj->FaCeva();
}

