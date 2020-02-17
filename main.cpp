#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>


using namespace std;

struct Studentas{
    string name;
    string surname;
    int n = 2;
    int *nd_rezultatas = new int [n];
    double egzamino_rezultatas, bendras_pazymys, mediana;
};


int indeksas = 0;

void bubbleSort(Studentas pavyzdys, int n) {
    bool exchanges;
    do {
       exchanges = false;  
       for (int i=0; i<n-1; i++) {
          if (pavyzdys.nd_rezultatas[i] > pavyzdys.nd_rezultatas[i+1]) {
             double temp = pavyzdys.nd_rezultatas[i]; pavyzdys.nd_rezultatas[i] = pavyzdys.nd_rezultatas[i+1]; pavyzdys.nd_rezultatas[i+1] = temp;
             exchanges = true;  
          }
       }
    } while (exchanges);
 }

void compare(Studentas *pavyzdys){
    if(pavyzdys->n<=0){
        cout << "Uzduociu kiekis negali buti maziau 1" << endl;
        cout << "Iveskite uzduociu kieki: "; cin >> pavyzdys->n;
        compare(pavyzdys);
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

void ivedimas(int *pvz){
    string pavyzdys;
    cin >> pavyzdys;
    if(pavyzdys == "Vidurkis" || pavyzdys == "vidurkis"){
        *pvz = 0;
    }
    else if(pavyzdys == "Mediana" || pavyzdys == "mediana" ){
        *pvz = 1;
    }
    else{
        cout << "Neteisingai ivedete, iveskite Vidurkis arba Mediana: ";
        ivedimas(pvz);
    }  
}


void input(Studentas pavyzdys){
    while(indeksas < pavyzdys.n){
        cout << indeksas + 1 << " - "; cin >> pavyzdys.nd_rezultatas[indeksas];
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n'); 
            cout << "Neteisinga reiksme, iveskite skaiciu: " << endl;
            cout << indeksas + 1 << " - "; cin >> pavyzdys.nd_rezultatas[indeksas];
        }
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
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n'); 
        cout << "Neteisinga reiksme, iveskite skaiciu: " << endl;
        cin >> pavyzdys->egzamino_rezultatas;
    }
    if(pavyzdys->egzamino_rezultatas > 10 || pavyzdys->egzamino_rezultatas < 1){
        cout << "Egzamino rezultatas privalo buti intervale nuo 1 iki 10, iveskite tinkama rezultata:" << endl;
        input_result(pavyzdys);
    }
}

void validityCheck(Studentas *pavyzdys){
    cin >> pavyzdys->n;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n'); 
        cout << "Neteisinga reiksme, iveskite skaiciu: " << endl;
        cin >> pavyzdys->n;
    }
}


int main(){
    int *rod;
    
    Studentas studentas1;
    Studentas* rodykle;
    rodykle = &studentas1;
    char taipArbaNe;

    cout << "Iveskite studento varda" << endl;
    cin >> studentas1.name;
    cin >> studentas1.surname;

    cout << "Ar norite rezultatus sugeneruoti atsitiktinai ? Y/N" << endl;
    cin >> taipArbaNe;

    if(taipArbaNe == 'Y' || taipArbaNe == 'y'){
        srand(time(NULL));
        studentas1.n = rand() % 30 + 1;
        for(int i=0; i<studentas1.n; i++){
            studentas1.nd_rezultatas[i] = rand() % 10 + 1;
        }
        studentas1.egzamino_rezultatas = rand() % 10 + 1;
        cout << endl;
        cout << endl;
        cout << "Namu darbu rezultatai: " << endl;
        for(int i=0; i<studentas1.n; i++){
            cout << studentas1.nd_rezultatas[i] << endl;
        }
        cout << endl;
        cout << endl;
        cout << studentas1.egzamino_rezultatas << endl;
        cout << endl;
    }
    else if(taipArbaNe == 'N' || taipArbaNe == 'n'){


        cout << "Iveskite studento egzamino rezultata: " << endl;
        input_result(rodykle);
        cout << endl;

        cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:" << endl;
        cout << endl;

        cout << "Namu darbu uzduociu kiekis: "; 
        
        Studentas *rodyklele = &studentas1;
        validityCheck(rodyklele);
        compare(rodyklele); //jei n mazesnis uz 0, useriui metamas erroras
        cout << endl;
        
        

        cout << "Namu darbu uzduociu ivertinimai: " << endl << endl;

        input(studentas1);

        
        


    }
    else{
        cout << "Iveskite Y arba N:" << endl;
        cin >> taipArbaNe;
    }

    bubbleSort(studentas1, studentas1.n);

    int suma = 0;
    for(int i=0; i < studentas1.n; i++){
        suma += studentas1.nd_rezultatas[i];
    }
        
    double mediana;

    if(studentas1.n%2 != 0){
        int abc = round(studentas1.n/2);
        mediana = studentas1.nd_rezultatas[abc]; 
    }
    else if(studentas1.n%2 == 0){
        mediana = ( studentas1.nd_rezultatas[studentas1.n/2-1] + studentas1.nd_rezultatas[studentas1.n/22] ) / 2;
    }

    int pasirinkimas;
    int *rodyklyte;
    rodyklyte = &pasirinkimas;
    cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
    ivedimas(rodyklyte);
    
    if(pasirinkimas == 0){
        studentas1.bendras_pazymys = (0.4 * (suma/studentas1.n)) + (0.6 * studentas1.egzamino_rezultatas);
    }
    else if(pasirinkimas == 1){
        studentas1.bendras_pazymys = (0.4 * mediana) + (0.6 * studentas1.egzamino_rezultatas);
    }

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

    if(pasirinkimas == 0){
        cout << "Galutinis (Vid.)" << endl;
    }

    if(pasirinkimas == 1){
    cout << "Galutinis (Med.)" << endl;
    }

    for(int i=0; i < 60; i++)
        cout << "-";

    cout << endl;
    cout << studentas1.name;
    lengthCheck(6, studentas1.name);
    cout << studentas1.surname;
    lengthCheck(7, studentas1.surname);

    
    cout << fixed << setprecision(2) << studentas1.bendras_pazymys<<endl;
    
}