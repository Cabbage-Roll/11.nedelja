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

class Odeca: public Proizvod{


};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
