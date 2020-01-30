#include <iostream>

using namespace std;

class StivaIterator;
class Stiva
{   int elem[10];
    int dim;
  public:
  Stiva()
      {   dim =  - 1; }
    void push(int in)
      {   elem[++dim] = in;}
    int pop()
      { return elem[dim--];   }
    int isEmpty()
      { return (dim ==  - 1);   }
    int Get_dim()
       {return dim;};
    int Get_elem(int i)
        {return elem[i];};
    StivaIterator *createIterator();
};

class StivaIterator
{
   Stiva *stiva;
    int index;
  public:
    StivaIterator(Stiva *s)
       {     stiva = s;   }
    void first()
       {  index = 0;   }
    void next()
        {  index++;  }
    int isDone()
          {  return index == stiva->Get_dim() + 1;   }
    int currentItem()
        { return stiva->Get_elem(index);   }
};

StivaIterator *Stiva::createIterator()
{
  return new StivaIterator(this);
}


int main()
{
    int i;
  Stiva s1;
  for (i = 1; i < 5; i++)
    s1.push(i);
  for (i = 1; i < 5; i++)
    cout<<s1.pop();

}
