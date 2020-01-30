#include <iostream>

using namespace std;

class Observer;
class Subject
{
    int stare;
    Observer* obs[10];
    int nr; //nmarul de observatori
  public:
    Subject(){nr=0;};
    Subject(int nou){stare=nou;};
    void attach(Observer *obs);
    void set_val(int value);
    int get_val()    {return stare;};
    void notify();
};

class Observer
{
  protected:
     Subject *s; //subiectul observat
  int stare_obs;
  public:
    virtual void update(int)=0 ;
};

class ConcreteObserver: public Observer
{
    public:
    ConcreteObserver(Subject *model, int stare_)
    {
	s=model; //cuplarea modelului observat cu observatorul concret
	stare_obs = stare_;
	model->attach(this);
	cout<<"\n\t S-a creat obs cu starea " <<stare_obs;
    }
    void update(int care)
    {
	stare_obs=s->get_val();
	cout << "\n Starea observatorului "<<care<<"devine " << stare_obs;
    };
};

void Subject::attach(Observer *o)
    {
	obs[nr++]=o;
    };
void Subject::set_val(int value)
    {
	stare= value;
	notify();
    };
void Subject::notify()
    {
    cout<<"\n  S-a schimbat subiectul!!!";
	for (int i = 0; i < nr; i++)
	  obs[i]->update(i+1);
    };


int main()
{
    Subject subj;
  ConcreteObserver obs1(&subj, 4);
  ConcreteObserver obs2(&subj, 5);
  ConcreteObserver obs3(&subj, 6);
  subj.set_val(7);
return 1;

}
