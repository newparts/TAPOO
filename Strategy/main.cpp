#include <iostream>


#include <stdio.h>

using namespace std;

//----------------------------------------------------------------------

class algoritm{ //Strategy

public:

virtual void sortare (int v[],int dim)=0;

};

//----------------------------------------------------------------------

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

void setStrategie(algoritm *nou) //int between Strategy- Context

{

a=nou;

}

};

//----------------------------------------------------------------------

void vector::citireSir()

{

int i;

printf("\n Choose a value for n=");

scanf("%d",&n);

for(i=0;i<n;i++)

{

printf("\nX[%d]=",i+1);scanf("%d",&x[i]);

}

}

//----------------------------------------------------------------------

void vector::tiparireSir()

{

int i;

for(i=0;i<n;i++)

printf("%d ",x[i]);

}

//----------------------------------------------------------------------

void vector::ordoneaza()

{

a->sortare(x,n);

};

//----------------------------------------------------------------------

class algoritm_selectie:public algoritm

{

public:

void sortare(int x[],int n);

};

//----------------------------------------------------------------------

void algoritm_selectie::sortare (int x[],int n)

{

cout<<"\n Selection method sort done!"<<endl;

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

//----------------------------------------------------------------------

class algoritm_insertie:public algoritm

{

public:

void sortare(int x[],int n);

};

//----------------------------------------------------------------------

void algoritm_insertie::sortare(int x[],int n)

{

cout<<"\n Insertion method sort done!"<<endl;

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

//----------------------------------------------------------------------

class algoritm_bubble:public algoritm

{

public:

void sortare(int x[], int n);

};

//----------------------------------------------------------------------

void algoritm_bubble::sortare(int x[], int n)

{

cout<<"\n Bubble sort done!"<<endl;

int i,j,a[10],temp;

for(i=1;i<n;++i)

{

for(j=0;j<(n-i);++j)

if(a[j]>a[j+1])

{

temp=a[j];

a[j]=a[j+1];

a[j+1]=temp;

}

}

};

//----------------------------------------------------------------------

int main()

{

algoritm *ssort=new algoritm_selectie;

algoritm *sinsert=new algoritm_insertie;

algoritm *bsort=new algoritm_bubble;

vector v(ssort);

v.citireSir();

v.ordoneaza();

v.tiparireSir();

v.setStrategie(sinsert);

v.ordoneaza();

v.tiparireSir();

v.setStrategie(bsort);

v.ordoneaza();

v.tiparireSir();

}
