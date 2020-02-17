#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Studentas{
    string name;
    string surname;
    int n = 2;
    int *nd_rezultatas = new int [n];
    double egzamino_rezultatas, bendras_pazymys, mediana;
};

int indeksas = 0;

void compare(int *kiekis){
    if(*kiekis<=0){
        cout << "Uzduociu kiekis negali buti maziau 1" << endl;
        cout << "Iveskite uzduociu kieki: "; cin >> *kiekis;
        compare(kiekis);
    }
}

void lengthCheck(int skaicius, string eilute){
    if(eilute.length() < skaicius){
        for(int a = 0; a < skaicius - eilute.length() + 5; a++){
            cout << " ";
        }
    }
    else if(eilute.length() > skaicius){
        for(int a = 0; a < eilute.length() + 5; a++){
            cout << " ";
        }
    }
    else{
        cout << "     ";
    }
}


void input(Studentas pavyzdys){
    while(indeksas < pavyzdys.n){
        cout << indeksas + 1 << " - "; cin >> pavyzdys.nd_rezultatas[indeksas];
        if( pavyzdys.nd_rezultatas[indeksas]>10 || pavyzdys.nd_rezultatas[indeksas]<1){
            cout << "Pazymys turi buti intervale tarp 1 ir 10, iveskite tinkama pazymi:" << endl;
            input(pavyzdys);
        }
        else{
            indeksas++;
        }
    }
}

void input_result(Studentas *pavyzdys){
    cin >> pavyzdys->egzamino_rezultatas;
    if(pavyzdys->egzamino_rezultatas > 10 || pavyzdys->egzamino_rezultatas < 1){
        cout << "Egzamino rezultatas privalo buti intervale nuo 1 iki 10, iveskite tinkama rezultata:" << endl;
        input_result(pavyzdys);
    }
}

int main(){
    int *rod;
    
    Studentas studentas1;
    Studentas* rodykle;
    rodykle = &studentas1;

    cout << "Iveskite studento varda" << endl;
    cin >> studentas1.name;
    cin >> studentas1.surname;

    cout << "Iveskite studento egzamino rezultata: " << endl;
    input_result(rodykle);
    cout << endl;

    cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:" << endl;
    cout << endl;

    cout << "Namu darbu uzduociu kiekis: "; 
    cin >> studentas1.n;
    rod = &studentas1.n;
    compare(rod); //jei n mazesnis uz 0, useriui metamas erroras
    cout << endl;

    

    cout << "Namu darbu uzduociu ivertinimai: " << endl << endl;

    input(studentas1);

    int suma = 0;
    for(int i=0; i < studentas1.n; i++){
        suma += studentas1.nd_rezultatas[i];
    }
    studentas1.bendras_pazymys = (0.4 * (suma/studentas1.n)) + (0.6 * studentas1.egzamino_rezultatas);  
    
    double mediana; // reikes daryti su moduliu (i.e. 6 skaitmenys, modulis = 0; kitu atveju modulis nelygu 0)

    cout << endl;
    cout << "Vardas";
    if(studentas1.name.length()>6){
        for(int i=0; i < studentas1.name.length() + 6; i++){
            cout << " ";
        }
    }
    if(studentas1.name.length() < 6){
        for(int i=0; i<5; i++){
            cout << " ";
        }
    }
    cout << "Pavarde";
    lengthCheck(7, studentas1.surname);
    cout << "Galutinis (Vid.)" << endl;

    for(int i=0; i < 40; i++)
        cout << "-";

    cout << endl;
    cout << studentas1.name;
    lengthCheck(6, studentas1.name);
    cout << studentas1.surname;
    lengthCheck(7, studentas1.surname);
    cout << fixed << setprecision(2) << studentas1.bendras_pazymys  << endl;
}