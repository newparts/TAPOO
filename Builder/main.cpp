#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Clasa pizza cu 3 setteri si o metoda
class Pizza_Product
{
public:
 void setAluat(const string& aluat) { m_aluat = aluat; }
 void setSos(const string& sos) { m_sos = sos; }
 void setTopping(const string& topping) { m_topping = topping; }
void gust() const
{
  cout << "Pizza cu " << m_aluat << " aluat, "
       << m_sos << " sos si "
       << m_topping << " topping. Mmmmmmm." << endl;
}
private:
 string m_aluat;
 string m_sos;
 string m_topping;
};
// Pizza obiect abstract, o interfata. Plus metoda de instantiere ce implementeaza cele doua exemple de pizza de mai jos
class Pizza_Builder
{
public:
  virtual ~Pizza_Builder() {};
  Pizza_Product* getPizza()
  { return m_pizza.release(); }
  void createNewPizzaProduct()
  {
    m_pizza = make_unique<Pizza_Product>();
  }
  virtual void buildAluat() = 0;
  virtual void buildSos() = 0;
  virtual void buildTop()   = 0;

protected:
  unique_ptr<Pizza_Product> m_pizza;
};
//Ambele implementeaza metoda m_pizza din clasa parinte abstracta
class Margherita_ConcreteBuilder : public Pizza_Builder
{
public:
 virtual void buildAluat() { m_pizza->setAluat("fraged"); }
 virtual void buildSos() { m_pizza->setSos("bulion"); }
 virtual void buildTop() { m_pizza->setTopping("mozzarela+busuioc"); }
};
class Spicy_ConcreteBuilder : public Pizza_Builder
{
public:
 virtual void buildAluat() { m_pizza->setAluat("de pizza"); }
 virtual void buildSos() { m_pizza->setSos("rosii+picant"); }
 virtual void buildTop(){ m_pizza->setTopping("carnati picanti+salam picant"); }
};
//Are o variabilă Pizza_Builder. Folosește makePizza () pentru a primi un constructor ca parametru. Apoi apelează operațiunile de construire care funcționează în mod corespunzător pentru ambele reprezentări.
//Metoda tastePizza () constă în tipărirea conținutului unei pizza.
class Cook_Director
{
public:
 void gustPizza(){ m_pizzaBuilder->getPizza()->gust(); }
void makePizza(Pizza_Builder* pb)
 {
   m_pizzaBuilder = pb;
   m_pizzaBuilder->createNewPizzaProduct();
   m_pizzaBuilder->buildAluat();
   m_pizzaBuilder->buildSos();
   m_pizzaBuilder->buildTop();
 }
private:
 Pizza_Builder* m_pizzaBuilder;
};


int main()
{
    Cook_Director cook;
  Margherita_ConcreteBuilder margheritaBuilder;
  Spicy_ConcreteBuilder spicyPizzaBuilder;
  cook.makePizza(&margheritaBuilder);
  cook.gustPizza();
  cook.makePizza(&spicyPizzaBuilder);
  cook.gustPizza();
}
