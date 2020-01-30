#include <iostream>
#include <stdio.h>

using namespace std;

class algoritm{ //Strategie
public:
	virtual void sortare (int v[],int dim)=0;
};

class vector{ //Context
	int x[10];
	int n;
	algoritm *a;
 public:
 	vector(){};
 	vector(algoritm *un){a=un;};
	void ordoneaza();
	void tiparireSir();
	void citireSir();
	void setStrategie(algoritm *nou) //interactiune Strategy- Context
	{
        a=nou;
	}
};

void vector::citireSir()
{
int i;
printf("\nDati n=");
scanf("%d",&n);
for(i=0;i<n;i++)
	{printf("\nX[%d]=",i+1);scanf("%d",&x[i]);	}
}


void vector::tiparireSir()
{
int i;
for(i=0;i<n;i++)
	printf("%d  ",x[i]);
}

void vector::ordoneaza()
{
	a->sortare(x,n);
};

class algoritm_selectie:public algoritm
{
public:
	void sortare(int x[],int n);
};
void algoritm_selectie::sortare (int x[],int n)
	{
	cout<<"\n Se face o sortare prin selectie!"<<endl;
	int i,j,aux,poz;
	for(i=0;i<n;i++)
	{
	aux=x[i];poz=i;
	for(j=i+1;j<n;j++)
		if (x[j]<aux) {aux=x[j];poz=j;}
	x[poz]=x[i];
	x[i]=aux;
	}
};

class algoritm_insertie:public algoritm{
  public:
	void sortare(int x[],int n);
};
void algoritm_insertie::sortare(int x[],int n)
{
	cout<<"\n Se face o sortare prin insertie!"<<endl;
	int i,j,aux,k;
	for(i=1;i<n;i++)
	{
	k=i-1; aux=x[i];
	while ((aux<x[k])&& (k>=0))
		{x[k+1]=x[k];
		k--;
		}
	x[k+1]=aux;
	}
};


int main()
{
    algoritm *ssort=new algoritm_selectie;
algoritm *sinsert=new algoritm_insertie;
vector v(ssort);
v.citireSir();
v.ordoneaza();
v.tiparireSir();
v.setStrategie(sinsert);
v.ordoneaza();
v.tiparireSir();

}
