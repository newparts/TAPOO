#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

//Implementator
class ZodiacImp{
	protected:
	int luna;
   public:
   ZodiacImp(){};
   ZodiacImp(int a){luna=a;};
	virtual void CalculeazaZodia(){cout<<"Zodia este...";};
};

//Implementatorii Concret
class ZodiacChinezescImp: public ZodiacImp{
	public:

   ZodiacChinezescImp(){};
   ZodiacChinezescImp(int a){luna=a;};
	void CalculeazaZodia(){cout<<"\nLuna "<<luna<<"; Zodia este CHINEZEASCA";};
};
class ZodiacEuropeanImp:public ZodiacImp{
	public:
   ZodiacEuropeanImp(){};
   ZodiacEuropeanImp(int a){luna=a;};
	void CalculeazaZodia(){cout<<"\nLuna "<<luna<<"; Zodia este EUROPEANA";};
};

//Abstractizarea
class Zodiac{
	protected:
	int luna;
   ZodiacImp *imp;
   public:
   virtual void Spune(){};

};

//Abstratizari Rafinate
class ZodiacChinezesc:public Zodiac{
	public:
  ZodiacChinezesc(){
                    imp=new ZodiacChinezescImp;
                    };
    ZodiacChinezesc(int a){

                    imp=new ZodiacChinezescImp(a);
                    };

   void Spune(){imp->CalculeazaZodia();};
};
class ZodiacEuropean:public Zodiac{
	public:
             ZodiacEuropean(){
                    imp=new ZodiacEuropeanImp;
                    };
             ZodiacEuropean(int a){
                    imp=new ZodiacEuropeanImp(a);
                    };

             void Spune(){imp->CalculeazaZodia();};
};


int main()
{

Zodiac *p=new ZodiacChinezesc(1);
p->Spune();

p=new ZodiacEuropean(1);
p->Spune();


return 0;
};
