#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Component{
public:
    virtual void afiseaza()=0;
};

class Litera:public Component
{
    char ch;
public:
    Litera(char c='\0')
        {
            ch=c;
        }
    void afiseaza()
        {
            cout<<ch;
        }
 };

class Cuvant:public Component
{
    vector <Component *> cuv;
public:
    Cuvant(  )
        {
        }

    void add(Component *comp)
        {
            cuv.push_back(comp);
        }
    void afiseaza()
        {
            //cout<<"\n";
            cout<<" ";
            for(int i=0;i<cuv.size();i++)
                { cuv[i]->afiseaza();}
            cout<<" ";
        }
};


int main()
{
//Cuvant c1;
//Cuvant c2;
Litera a='a';
Litera b='b';
Litera o='o';
Litera c='c';


Cuvant comp;
comp.add(&a);
comp.add(&b);
comp.add(&o);
cout<<"\n Composit format din litere: ";
comp.afiseaza();

Cuvant comp2;
comp2.add(&comp);
comp2.add(&comp);
comp2.add(&c);
comp2.add(&a);
comp2.add(&comp);
cout<<"\n Composit format din litere si cuvinte (alt composit): ";
comp2.afiseaza();
}

