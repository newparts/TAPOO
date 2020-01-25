#include <iostream>
#include <stdio.h>
#include <string.h>


//Target
class Pasare{
	char *nume;
	public:
	Pasare(){};
	Pasare(char *);
	virtual void DaNume(char*);
	virtual void Misca();
};

Pasare::Pasare(char *n)
{
  nume = new char[strlen(n)+1];
  strcpy(nume,n);
};

void Pasare::Misca()
{
 cout<<"\nPasarea "<<nume<<" zboara si face oua !!!";
};

void Pasare::DaNume(char *n)
{
  nume= new char[strlen(n)+1];
  strcpy(nume,n);
};


//Adaptabilul
class Pinguin{
	char *nume;
   public:
   Pinguin(){};
   Pinguin(char *);
   void Misca();

};

void Pinguin::Misca(){
	cout<<"\nPinguinul "<<nume<<" nu zboara bine dar face oua:!!!";
};

void Pinguin::Pinguin(char *n){
  nume= new char[strlen(n)+1];
  strcpy(nume,n);

};


//Adaptor
class MamiferCuAripi:public Pasare,private Pinguin{
	char *nume;
	public:
	MamiferCuAripi(){};
	MamiferCuAripi(char *);
	void Misca();
};


MamiferCuAripi::MamiferCuAripi(char *n)
{
  nume=new char[strlen(n)+1];
  strcpy(nume,n);
};

void MamiferCuAripi::Misca()
{
 cout<<"\n\n";
 Pasare::Misca();
 cout<<"\n\t....dar zboara GREU!!!";

};




int main()
{
Pasare p("Rindunica\t");
p.Misca();


Pinguin pp("Angel\t");
pp.Misca();


Pasare *ping=new MamiferCuAripi;
ping->DaNume("Rico");
ping->Misca();

return 0;
}
