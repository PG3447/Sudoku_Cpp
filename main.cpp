#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>


using namespace std;

int main()
{

    //Sudoku
    int x[9][9];
    int xrandom = rand() % 9 + 1;
    srand(time(0));
    //Generowanie pustego sudoku
    for (int j=0;j<9;j++) {
        for (int i=0;i<9;i++) {
            x[j][i] = 0;
        }
    }

    //Generowanie wypelnionego sudoku
    bool notok = true;
    int tablicaRandom[9] = {0,0,0,0,0,0,0,0,0};
    for (int j=0;j<9;j++) {
        for (int i=0;i<9;i++) {
            //Generowanie i wstawianie liczby do planszy sudoku
            notok = true;
            while (notok) {
                //Losowanie liczby: xrandom
                xrandom = rand() % 9 + 1;
                int dd=0;
                if (j<6 && j>2) {dd=3;}
                if (j>5) {dd=6;}
                for (int d=dd;d<dd+3;d++) {
                    int ff=0;
                    if (i<6 &&i>2) {ff=3;}
                    if (i>5) {ff=6;}
                    for (int f=ff;f<3+ff;f++) {
                        if (xrandom!=x[d][f]) {
                            //Kwadrat ok
                            notok = false;
                        } else {
                            notok = true;
                            break;
                        }
                    }
                    if (notok == true) {
                        break;
                    }
                }
                if (notok == false) {
                    for (int w=0;w<9;w++) {
                        if ((xrandom!=x[j][w]) ) {
                            //Poziom ok
                            notok = false;
                        } else {
                            notok = true;
                            break;
                        }
                    }
                    if (notok == false) {
                        for (int v=0;v<9;v++) {
                            if (xrandom!=x[v][i]) {
                                //Pion ok;
                                notok = false;
                            } else {
                                notok = true;
                                break;
                            }
                        }
                        if (notok == false) {
                            //Wstawianie do tablicy poprawnie wygenerowanej liczby
                            x[j][i]=xrandom;
                            for (int tab=0;tab<9;tab++) {
                                tablicaRandom[tab] = 0;
                            }
                        }
                    }
                }
                if (notok == true) {
                    //Oznaczanie niepoprawnej liczby
                    tablicaRandom[xrandom-1] = 1;
                }
                //Sprawdzanie czy wszystkie mozliwe kombinacje zostaly wykorzystane
                bool gitrandom=false;
                for (int okok=0;okok<9;okok++) {
                    if (tablicaRandom[okok]==0) {
                        gitrandom=true;
                    }
                }
                if (!gitrandom) {
                    //Zerowanie glownej tablicy
                    i=0;
                    j=0;
                    for (int jj=0;jj<9;jj++) {
                        for (int ii=0;ii<9;ii++) {
                            x[jj][ii] = 0;
                        }
                    }
                }
                //Petla WHILE jedno wykonanie
            }
        }
    }

    int poziomtrudnosc;

    cout<<"Podaj poziom trudnosc od 1 do 10:"<<endl;
    cin>>poziomtrudnosc;
    cout<<endl;

    //Generowanie wersji sudoku do uzupelnienia
    int gotowatabilca[9][9];
    bool pusto=true;
    bool pelno=true;
    while (pusto || pelno) {
        for (int j=0;j<9;j++) {
                for (int i=0;i<9;i++) {
                    if (poziomtrudnosc<=rand() % 11) {
                        pusto=false;
                        gotowatabilca[j][i] = x[j][i];
                    } else {
                        pelno=false;
                        gotowatabilca[j][i] = 0;
                    }
                }
        }
    }

    //Tworzenie pliku z wynikami
    fstream plikout;

    plikout.open("Sudoku.txt",ios::out);

    for (int j=0;j<9;j++) {
        for (int i=0;i<9;i++) {
            cout<<x[j][i]<<" ";
            plikout<<x[j][i]<<" ";
            if (i==2) {cout<<"| ";plikout<<"| ";}
            if (i==5) {cout<<"| ";plikout<<"| ";}
        }
        if (j==2) {cout<<endl<<"------+-------+-------";plikout<<endl<<"------+-------+-------";}
        if (j==5) {cout<<endl<<"------+-------+-------";plikout<<endl<<"------+-------+-------";}
        cout<<endl;
        plikout<<endl;
    }
    cout<<endl<<endl<<endl<<endl;
    plikout<<endl<<endl<<endl<<endl;

    for (int j=0;j<9;j++) {
        for (int i=0;i<9;i++) {
            cout<<gotowatabilca[j][i]<<" ";
            plikout<<gotowatabilca[j][i]<<" ";
            if (i==2) {cout<<"| ";plikout<<"| ";}
            if (i==5) {cout<<"| ";plikout<<"| ";}
        }
        if (j==2) {cout<<endl<<"------+-------+-------";plikout<<endl<<"------+-------+-------";}
        if (j==5) {cout<<endl<<"------+-------+-------";plikout<<endl<<"------+-------+-------";}
        cout<<endl;
        plikout<<endl;
    }

    plikout.close();
    system("pause>nul");

    return 0;
}
