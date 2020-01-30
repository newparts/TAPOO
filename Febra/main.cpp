#include <iostream>

using namespace std;

class Handler //Cine ar putea trata febra
	{
	private:
		int cod;
	protected:
		Handler *succesor;
	public:
		Handler(){};
		Handler(int c){cod=c;};
		virtual void TrateazaFebra(int febra);
		void SetSuccesor(Handler *);
	};

	void Handler::TrateazaFebra(int febra)
{   //implementare implicita
	if (succesor!=0)
		{
		succesor->TrateazaFebra(febra);
		}
};

void Handler::SetSuccesor(Handler *p)
{
 this->succesor=p;
};

//Handler concret
class Neprofesionist:public Handler
{//cine poate trata efectiv febra
	public:
		Neprofesionist(){};
		void TrateazaFebra(int);
};

//rescrierea metodei request -cerere
void Neprofesionist::TrateazaFebra(int febra)
{
	if (febra>37)
		{
		succesor->TrateazaFebra(febra);
		}
	else
		if (succesor!=0)
		cout<<"Cu temperatura "<<febra<<"vecinul mi-a dat un ceai si am scapat!"<<endl;

};

class MedicDeFamilie:public Handler
{//Handler concret
	public:
	      void TrateazaFebra(int);
	     };

void MedicDeFamilie::TrateazaFebra(int febra)
{
	if (!(febra<39)&&(febra>=38))
		{
		succesor->TrateazaFebra(febra);
		}
	else
		if (succesor!=0)
		cout<<"Cu temperatura "<<febra<<" medicul de familie mi-a dat un paracetamol si am scapat"<<endl;
};

class MedicSalvare:public Handler
{//Handler concret
	public:
	void TrateazaFebra(int);
};
void MedicSalvare::TrateazaFebra(int febra)
{
	if (!(febra<40)&&(febra>=39))
		{
		succesor->TrateazaFebra(febra);
		}
	else
		if (succesor!=0)
		cout<<"Cu temperatura "<<febra<<" am chemat salvarea si am scapat"<<endl;
};

class Altcineva:public Handler
{//alt Handler concret
  public:
	void TrateazaFebra(int);
};
void Altcineva::TrateazaFebra(int febra)
{
if (febra>=40)
	{
	 if (succesor!=0)
   cout<<"Cu temperatura "<<febra<<" nu mai scap!"<<endl;

	};
}


int main()
{
    Handler *h1=new Neprofesionist;
Handler *h2=new MedicDeFamilie;
Handler *h3=new  MedicSalvare;
Handler *h4=new Altcineva;
h1->SetSuccesor(h2);
h2->SetSuccesor(h3);
h3->SetSuccesor(h4);
int ceva;
cout<<"Ce temperatura ai?";
cin>>ceva;
       h1->TrateazaFebra(ceva);

}
