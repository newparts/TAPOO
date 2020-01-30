#include <iostream>

using namespace std;

class Maner_AbstractProduct
{
public:
 // O functie care printeaza un numar
 virtual void printSerialNumber() = 0;
};

class KIAManer_Product : public Maner_AbstractProduct
{
public:
    // Printeaza seria specifica
    void printSerialNumber (){
        std::cout << " Maner KIA Ceed \n";
    }
};

class FordManer_Product : public Maner_AbstractProduct
{
public:
    // Printeaza seria specifica
    void printSerialNumber (){
        std::cout << " Maner Ford Transit \n";
    }
};

class Automobil_AbstractFactory
{
public:
 virtual Maner_AbstractProduct* createManer () = 0;
 //virtual Parbriz_AbstractProduct* createParbriz () = 0;
};

class KIAauto_ConcreteFactory : public Automobil_AbstractFactory
{
public:
    Maner_AbstractProduct* createManer (){
        return new KIAManer_Product;
    }
};
class Fordauto_ConcreteFactory : public Automobil_AbstractFactory
{
public:
    Maner_AbstractProduct* createManer (){
        return new FordManer_Product;
    }
};

int main()
{
    // Clientul are nevoie de un maner
    Automobil_AbstractFactory* abstractFactory;
    Maner_AbstractProduct* dManer_AbstractProduct;

    // Clientul doreste produse din gama ford
    abstractFactory = new Fordauto_ConcreteFactory;
    // Ford concrete factory le creeaza si le returneaza clientului

    dManer_AbstractProduct = abstractFactory->createManer();

    // Clientul utilizeaza produsele

    dManer_AbstractProduct -> printSerialNumber();

    // KIA la fel
    abstractFactory = new KIAauto_ConcreteFactory;

    dManer_AbstractProduct = abstractFactory->createManer();

    dManer_AbstractProduct -> printSerialNumber();
    return 0;
}
