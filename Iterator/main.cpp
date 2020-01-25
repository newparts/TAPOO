#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class List{
int size;
int *colectie;
public:
	List(){};
	List(int n);
	int Size(){return size;};
	int Get(int i){return colectie[i];};
};
List::List(int n)
	 {size=n;
	 for(int i=1;i<=size;i++)
	     colectie[i-1]=i;};

	     class ListIterator{
protected:
	List *list;
	int poz;
public:
	ListIterator(){};
	ListIterator(List *alist){list=alist;};
	void First(){poz=0;};
	void Next()
	  {poz++;};
	int IsDone(){ return (poz>=list->Size()) ;};
        int Current(){return list->Get(poz);};
};


int main()
{
    //clrscr();
 List *alist=new List(9);
 ListIterator *i=new ListIterator(alist);
for(i->First();!i->IsDone();i->Next())
	{ cout<<" "<<i->Current(); }

}
