#include <iostream>
#include <dinstring.hpp>
#include <list.hpp>

using namespace std;

class Proizvod{
public:
    int cena;
    DinString naziv;

    Proizvod(int a, Dinstring b){
        cena=a;
        naziv=b;
    }

    virtual void izracunajPopust()=0;

    virtual void ispisi()=0;
};

class Voce: public Proizvod{
public:
    DinString zemljaPorekla;
    int rokTrajanja;

    Voce(DinString a, int b, int c, DinString d){
        zemljaPorekla=a;
        rokTrajanja=b;
        cena=c;
        naziv=d;
    }

    void izracunajPopust(){
        if(rokTrajanja>5)
            cena=(100*cena-33*cena)/100;
        if(rokTrajanja=>1 && rokTrajanja<=5)
            cena=(100*cena-66*cena)/100;
        if(rokTrajanja<1)
            cena=0;
    }

    void ispisi(){
        cout<<"zemlja porekla "<<zemljaPorekla<<endl;
        cout<<"rok trajanja "<<rokTrajanja<<endl;
        cout<<"cena "<<cena<<endl;
        cout<<"naziv "<<naziv<<endl;
    }

};

enum Vel{XS,S,M,L,XL};

enum Tipodece{MAJICA,PANTALONE};

class Odeca: public Proizvod{
private:
    Vel velicina;
    Tipodece tip;

public:/*
    int izbroj(){
        int i, n=0;
        for(i=0;i<size;i++){
            if(tip==L || tip==XL){
                n++;
            }
        }
        return n;
    }*/

    Odeca(Vel v, Tipodece t, DinString a, int b, int c, DinString d){
        zemljaPorekla=a;
        rokTrajanja=b;
        cena=c;
        naziv=d;
        velicina=v;
        tip=t;
    }

    virtual void izracunajPopust(){
        if(velicina==XS && tip==MAJICA)
            cena=(100*cena-60*cena)/100;
        else if(tip==MAJICA)
            cena=(100*cena-50*cena)/100;
        else if(tip==PANTALONE)
            cena=(100*cena-33*cena)/100;
    };

    void ispisi(){
        cout<<"zemlja porekla "<<zemljaPorekla<<endl;
        cout<<"rok trajanja "<<rokTrajanja<<endl;
        cout<<"cena "<<cena<<endl;
        cout<<"naziv "<<naziv<<endl;
        cout<<"velicina "<<velicina<<endl;
        cout<<"tip "<<tip<<endl;
    }


};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
