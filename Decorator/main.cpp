#include <iostream>

using namespace std;

class IRucsac
{
public:
  virtual void assemble() = 0;
  virtual ~IRucsac() {}
};

class StandardRucsac: public IRucsac
{
public:
  virtual void assemble(){cout<<"\n Componente standard";}
};

class RucsacDecorator: public IRucsac
{
public:
  RucsacDecorator(IRucsac* decorator):m_Decorator(decorator) {}

  virtual void assemble()
  {
    m_Decorator->assemble();
  }
private:
  IRucsac* m_Decorator;
};

class Laptop : public RucsacDecorator
{
public:
  Laptop(IRucsac* dcrator):RucsacDecorator(dcrator){}
  virtual void assemble()
  {
    RucsacDecorator::assemble();
    cout << " + Laptop";
  }
};

class USB : public RucsacDecorator
{
public:
    USB(IRucsac* dcrator):RucsacDecorator(dcrator){}
    virtual void assemble()
    {
        RucsacDecorator::assemble();
        cout << " + USB";
    }
};

class Sticla : public RucsacDecorator
{
public:
    Sticla(IRucsac* dcrator):RucsacDecorator(dcrator){}
    virtual void assemble()
    {
        RucsacDecorator::assemble();
        cout << " + Sticla de apa";
    }
};
int main()
{
    IRucsac* pRucsac =
   new Sticla(
    new USB(
     new Laptop(
      new RucsacDecorator(
       new StandardRucsac()))));

  pRucsac->assemble();
  delete pRucsac;

  return 0;
}
