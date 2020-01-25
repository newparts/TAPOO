#include <iostream>
#include <string>

using namespace std;

class MoveLogic {
public:
    virtual void move() = 0;
};

class Mers : public MoveLogic {
public:
    void move() { cout << "Se misca alternand pasii\n"; }
};

class Zboara : public MoveLogic {
public:
    void move() { cout << "Falfaie din aripi\n"; }
};

class Animal {
public:
    virtual void cumMaMisc() = 0;
};

class Persoana : public Animal {
    MoveLogic* _myMoveLogic;
public:
    // Constructorul primeste obiectul movelogic spre initializare
    Persoana(MoveLogic *obj): _myMoveLogic(obj){}
    void cumMaMisc() {
        _myMoveLogic->move();
    }
};

class Pasare : public Animal {
    MoveLogic* _myMoveLogic;
public:
    Pasare(MoveLogic *obj) :_myMoveLogic(obj){}
    void cumMaMisc() {
        _myMoveLogic->move();
    }
};

int main()
{
    MoveLogic* mers = new Mers();
    MoveLogic* zboara  = new Zboara();

    Animal* animalA = new Persoana(mers);
    Animal* animalB = new Pasare(zboara);

    animalA->cumMaMisc();
    animalB->cumMaMisc();

    return 1;
}
