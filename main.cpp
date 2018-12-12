#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

class Program
    {
      public: float SumaSzeregu(float X, float Eps,string what="Suma")
        {
            float Suma = 0.0F;
            float W = 1.0f;
            int k = 0;
            do
            {
                k++;
                W=W*((X+1)/k);
                Suma = Suma + W;

            } while (abs(W) > Eps);
            if(what=="iteracje")
                return k;
            else
                return Suma;
        }
    };

int main()
{
   Program program;
   char wybor_opcji;
   cout<<"Program umozliwa obliczanie wartosciu szeregu w zadanym punkcie X oraz tablicowanie zmian wartosci szeregu w zadanym przedziale [Xd,Xg] z krokiem h"<<endl;
   do{
    cout<<"Menu programu: "<<endl;
    cout<<"A. Obliczanie wartosci szeregu"<<endl;
    cout<<"B. Tablicowanie zmian wartosci szeregu" <<endl;
    cout<<"X. Zakonczenie programu"<<endl;
    cin>>wybor_opcji;
    wybor_opcji=toupper(wybor_opcji);
    switch(wybor_opcji){
        case 'A':
            {float X, eps,SumaSzereguPotegowego;
            int licznik_zsumowanych_wyrazow;
            string s;
            cout<<"Podaj wartosc zmienej niezaleznej X"<<endl;
            cin>>X;
            while(!cin.good()){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout<<"ERROR W zapisie wartosci X wystapil niedozwolony znak!!!"<<endl;
                cout<<"Podaj ponowanie wartosc zmienej X"<<endl;
                cin>>X;
            }
            do{
                cout<<"Podaj wartosc zmienej eps"<<endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>eps;
                while(!cin.good()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout<<"ERROR W zapisie wartosci Eps wystapil niedozwolony znak!!!"<<endl;
                    cout<<"Podaj ponowanie wartosc zmienej eps"<<endl;
                    cin>>eps;
                }
                if((eps<=0 or eps>=1) and cin.good()){
                    cout<<"ERROR dokladnosc obliczen musi spelniac warunek 0.0<Eps<1.0"<<endl;
                }
            }while(eps<=0 or eps>=1);
            SumaSzereguPotegowego=program.SumaSzeregu(X,eps);
            cout<<"Suma szeregu potegowego dla eps: "<<eps<<" wynosi: "<<SumaSzereguPotegowego<<endl<<endl;
            cout<<"Aby kontynulowac wcisnij enter..."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            getline(std::cin, s);
            cout<<endl<<endl;}
            break;
        case 'B':
            float Xd,Xg,h,eps;
            vector <float> sumy,wartosci;
            cout<<"Podaj wartosc dolnej granicy przedzialu Xd"<<endl;
            cin>>Xd;
            while(!cin.good()){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout<<"ERROR W zapisie wartosci Xd wystapil niedozwolony znak!!!"<<endl;
                cout<<"Podaj ponowanie wartosc dolnej granicy Xd"<<endl;
                cin>>Xd;
            }
            do{
                cout<<"Podaj wartosc gornej granicy przedzialu Xg"<<endl;
                cin>>Xg;
                while(!cin.good()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout<<"ERROR W zapisie wartosci Xd wystapil niedozwolony znak!!!"<<endl;
                    cout<<"Podaj ponowanie wartosc gornej granicy Xg"<<endl;
                    cin>>Xg;
                }
                if(Xg<=Xd){
                    cout<<"Podales wartosc gornej granicy Xg mniejsza lub rowna wartosci dolnej Xd";
                }
            } while(Xg<=Xd);
            do{
                cout<<"Podaj wartosc kroku h"<<endl;
                cin>>h;
                while(!cin.good()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout<<"ERROR W zapisie wartosci kroku h wystapil niedozwolony znak!!!"<<endl;
                    cout<<"Podaj ponowanie wartosc kroku h"<<endl;
                    cin>>h;
                }
                if(h<=0 or h>=1){
                    cout<<"ERROR Krok musi spelniac warunek 0.0<h<1.0"<<endl;
                }
                if(h>(Xg-Xd)/2){
                    cout<<"ERROR Krok musi spelniac warunek h<(Xg-Xd)/2"<<endl;
                }
            } while(h<=0 or h>(Xg-Xd) or h>=1);
             do{
                cout<<"Podaj wartosc zmienej eps"<<endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>eps;
                while(!cin.good()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout<<"ERROR W zapisie wartosci Eps wystapil niedozwolony znak!!!"<<endl;
                    cout<<"Podaj ponowanie wartosc zmienej eps"<<endl;
                    cin>>eps;
                }
                if((eps<=0 or eps>=1) and cin.good()){
                    cout<<"ERROR dokladnosc obliczen musi spelniac warunek 0.0<Eps<1.0"<<endl;
                }
            }while(eps<=0 or eps>=1);
            cout<<left<<setw(10)<<"Wartosc zmienej X";
            cout<<right<<setw(30)<<"Wartosc szeregu potegowego";
            cout<<right<<setw(40)<<"Ilosc zsumowanych wyrazow ciagu"<<endl;
            cout<<left<<setw(10)<<"-----------------";
            cout<<right<<setw(30)<<"--------------------------";
            cout<<right<<setw(40)<<"-------------------------------"<<endl;
            bool petla_osiagnela_Xg = false;
            for(float i=Xd; i<Xg; i+=h){
                wartosci.push_back(i);
                cout<<left<<setw(30)<<wartosci[wartosci.size()-1];
                sumy.push_back(program.SumaSzeregu(i,eps));
                cout<<left<<setw(30)<<sumy[sumy.size()-1];
                cout<<right<<setw(15)<<program.SumaSzeregu(i,eps,"iteracje")<<endl;
                if(i==Xg){
                    petla_osiagnela_Xg==true;
                }
            }
            if(!(petla_osiagnela_Xg)){
                wartosci.push_back(Xg);
                cout<<left<<setw(30)<<wartosci[wartosci.size()-1];
                sumy.push_back(program.SumaSzeregu(Xg,eps));
                cout<<left<<setw(30)<<sumy[sumy.size()-1];
                cout<<right<<setw(15)<<program.SumaSzeregu(Xg,eps,"iteracje")<<endl;
            }
            char wybor_tabelka;
            do{
            cout<<endl<<endl;
            cout<<"Aby kontynulowac wcisnij 'X'"<<endl;
            cout<<"Aby zobaczyc tabelke z wynikami w roznych formatach wcisnij 'T'"<<endl;
            cout<<"Aby zapisac tabelke z wynikami do pliku wcisnij 'Z'"<<endl;
            cin>>wybor_tabelka;
            wybor_tabelka=toupper(wybor_tabelka);
                switch(wybor_tabelka){
                    default:
                        cout<<endl<<endl;
                        cout<<"ERROR wpisano bledny klawisz!!!"<<endl;
                        break;
                    case 'X':
                            cout<<endl<<endl;
                            break;
                    case 'T':
                    cout<<endl<<endl;
                    cout<<left<<setw(10)<<"Wartosc zmienej X";
                    cout<<right<<setw(30)<<"Wartosc szeregu potegowego";
                    cout<<right<<setw(30)<<"Wartosc szeregu potegowego";
                    cout<<right<<setw(30)<<"Wartosc szeregu potegowego";
                    cout<<right<<setw(30)<<"Wartosc szeregu potegowego"<<endl;
                    cout<<right<<setw(45)<<"w formacie domyslnym";
                    cout<<right<<setw(30)<<"w formacie wykladniczym";
                    cout<<right<<setw(32)<<"w formacie stalopozycyjnym";
                    cout<<right<<setw(25)<<"w formacie zwiezlym"<<endl;
                    for(int i=0; i<sumy.size(); i++){
                        cout<<setprecision(6);
                        cout<<left<<setw(10)<<wartosci[i];
                        cout<<right<<setw(30)<<sumy[i];
                        cout<<setprecision(8);
                        cout<<right<<setw(30)<<scientific<<sumy[i];
                        cout.unsetf(ios::scientific);
                        cout<<right<<setw(30)<<showpoint<<sumy[i]<<endl;
                        cout.unsetf(ios::showpoint);
                    }
                    break;

                    case 'Z':
                        fstream plik;
                        plik.open("plik.txt", ios::out | ios::trunc);
                        if(plik.good() == true)
                        {
                            plik<<left<<setw(10)<<"Wartosc zmienej X";
                            plik<<right<<setw(30)<<"Wartosc szeregu potegowego";
                            plik<<right<<setw(30)<<"Wartosc szeregu potegowego";
                            plik<<right<<setw(30)<<"Wartosc szeregu potegowego";
                            plik<<right<<setw(30)<<"Wartosc szeregu potegowego"<<endl;
                            plik<<right<<setw(45)<<"w formacie domyslnym";
                            plik<<right<<setw(30)<<"w formacie wykladniczym";
                            plik<<right<<setw(32)<<"w formacie stalopozycyjnym";
                            plik<<right<<setw(25)<<"w formacie zwiezlym"<<endl;
                            for(int i=0; i<sumy.size(); i++){
                                plik<<setprecision(6);
                                plik<<left<<setw(10)<<wartosci[i];
                                plik<<right<<setw(30)<<sumy[i];
                                plik<<setprecision(8);
                                plik<<right<<setw(30)<<scientific<<sumy[i];
                                plik.unsetf(ios::scientific);
                                plik<<right<<setw(30)<<showpoint<<sumy[i]<<endl;
                                plik.unsetf(ios::showpoint);

                            }
                            plik.close();
                            cout<<"Plik zostal zapisany!!!"<<endl;
                            }
                            break;
                }

                }while (wybor_tabelka!='X');
    }

   }while (wybor_opcji!='X' and wybor_opcji!='x');
   cout<<endl<<endl;
   cout<<"Autor:"<<endl;
   cout<<"Jan"<<endl;
   cout<<"Pedziwiatr"<<endl;
   cout<<"Nr indeksu 289021"<<endl;
   return 0;
}
