#include <iostream>

using namespace std;

class Chelner_Subsystem1
{
public:
  void scrieComanda(){ cout << " Chelnerul preia comanda\n";}
  void trimiteBucatarie(){ cout << " Trimite comanda la bucatarie\n";}
  void servesteClientul(){ cout << " Clientul este servit\n";}
};

class Bucatarie_Subsystem2
{
public:
    void pregatesteMancarea(){ cout << " Se pregateste mancarea\n";}
    void cheamaChelner() { cout << " Bucataria cheama chelnerul\n";}
    void spalaVase() { cout << " Se spala vasele\n";}
};

class Comanda_Facade
{
private:
    Chelner_Subsystem1 chelner;
    Bucatarie_Subsystem2 bucatarie;
public:
    void comandaMancare()
    {
        cout << "O serie de interogari independente pe diferite subsisteme:\n";
        chelner.scrieComanda();
        chelner.trimiteBucatarie();
        bucatarie.pregatesteMancarea();
        bucatarie.cheamaChelner();
        chelner.servesteClientul();
        bucatarie.spalaVase();
    }
};
int main()
{
    Comanda_Facade facade;
    facade.comandaMancare();
return 0;;
}
