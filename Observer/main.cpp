#include <iostream>
#include <vector>

using namespace std;

class Subiect {
    vector < class Observator * > observatori;
    bool scor;                    // trigger, event
public:
    // se inregistreaza singur
    void attach(Observator *obs) {
        observatori.push_back(obs);
    }

   // event
   // set daca se marcheaza si notifica pe fiecare
   void setScor(bool Scorx) {
      scor = Scorx;
      notify();
   }
bool getScor() {
      return scor;
   }
  // notifica implementarea
   void notify();
};

class Observator
{
    Subiect *subj;
    int exciteLevel;               // stare
  public:
    Observator(Subiect *mod, int excLevel)
    {
        subj = mod;
        exciteLevel = excLevel;
        // Observatorii se inregistreaza si se ataseaza la subiect
        subj->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subiect *getSubiect() {
       return subj;
    }
    void setExciteLevel(int excLevel) {
       exciteLevel = excLevel;
    }
    int getExciteLevel() {
       return exciteLevel;
    }
};
//notifica observatorii pentru update
void Subiect::notify() {
  for (int i = 0; i < observatori.size(); i++)
    observatori[i]->update();
}

class Old_ConcretObservator: public Observator
{
   public:
     // Apeleaza constructorul parinte pentru a se inregistra la subiect
     Old_ConcretObservator(Subiect *mod, int div)
        :Observator(mod, div){}
     // Pentru old daca nivelul de excitatie creste peste  intervine riscul

     void update()
     {
        bool scor = getSubiect()->getScor();
        setExciteLevel(getExciteLevel() + 1);
        if (scor && getExciteLevel() > 150)
        {
          cout << "Echipa celor batrani a inscris!!"
               << " Nivelul de excitatie al lor este "
               << getExciteLevel()
               << " atentie la riscuri"<<endl;
        }else{
          cout << "Echipa nu a marcat. Nu trebuie sa va faceti griji"
               << endl;
        }
    } // sgarsit update()
};

class Young_ConcretObservator: public Observator
{
   public:
     // Apeleaza constructorul parinte pentru a se inregistra la subiect
     Young_ConcretObservator(Subiect *mod, int div)
       : Observator(mod, div){}

     void update()
     {
        bool scor = getSubiect()->getScor();
        setExciteLevel(getExciteLevel() + 1);
        if (scor && getExciteLevel() > 100)
        {
          cout << "Echipa tinerilor a marcat!!"
               << " Nivelul lor de excitatie este "
               << getExciteLevel()
               << " atentie la riscuri!!" << endl;
        }else{
          cout << "Echipa tinerilor nu a marcat. Nu ne facem griji!"
               << endl;
       }
    } // sfarsit update()
};

int main()
{
    Subiect subj;
   Young_ConcretObservator youngObs1(&subj, 100);
   Old_ConcretObservator oldObs1(&subj, 150);
   Young_ConcretObservator youngObs2(&subj, 52);
   subj.setScor(true);
}
