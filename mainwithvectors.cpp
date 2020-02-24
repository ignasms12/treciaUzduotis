#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

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
    
    vector<Studentas> studentai;
    Studentas* rodykle;
    
    int pasirinkimas;
    int *rodyklyte;

    char taipArbaNe;
    int i = 0;
    string stop = "uztenka";
    string stop2 = "Uztenka";

    studentai.push_back(Studentas());
    


    cout << "Iveskite studento varda" << endl;
    cin >> studentai[i].name >> studentai[i].surname;

    while(cin >> studentai[i].name ){
        if(i==2){
            break;
        }
        if(i>0){
            studentai.push_back(Studentas());
            cout << "Iveskite studento varda" << endl;
            cin >> studentai[i].name;
            cin >> studentai[i].surname;
        }
        
        

        rodykle = &studentai[i];
        cout << "Ar norite rezultatus sugeneruoti atsitiktinai ? Y/N" << endl;
        cin >> taipArbaNe;

        if(taipArbaNe == 'Y' || taipArbaNe == 'y'){
            srand(time(NULL));
            studentai[i].n = rand() % 30 + 1;
            for(int a=0; a<studentai[i].n; a++){
                studentai[i].nd_rezultatas[a] = rand() % 10 + 1;
            }
            studentai[i].egzamino_rezultatas = rand() % 10 + 1;
            cout << endl;
            cout << endl;
            cout << "Namu darbu rezultatai: " << endl;
            for(int a=0; a<studentai[i].n; a++){
                cout << studentai[i].nd_rezultatas[a] << endl;
            }
            cout << endl;
            cout << endl;
            cout << "Egzamino rezultatas: "<<endl;
            cout << studentai[i].egzamino_rezultatas << endl;
            cout << endl;
        }
        else if(taipArbaNe == 'N' || taipArbaNe == 'n'){


            cout << "Iveskite studento egzamino rezultata: " << endl;
            input_result(rodykle);
            cout << endl;

            cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:" << endl;
            cout << endl;

            cout << "Namu darbu uzduociu kiekis: "; 
            
            Studentas *rodyklele = &studentai[i];
            validityCheck(rodyklele);
            compare(rodyklele); //jei n mazesnis uz 0, useriui metamas erroras
            cout << endl;
            
            

            cout << "Namu darbu uzduociu ivertinimai: " << endl << endl;

            input(studentai[i]);

            
            


        }
        else{
            cout << "Iveskite Y arba N:" << endl;
            cin >> taipArbaNe;
        }

        bubbleSort(studentai[i], studentai[i].n);
        int suma = 0;
        for(int n=0; n < studentai[i].n; n++){
            suma += studentai[i].nd_rezultatas[n];
        }
        
        rodyklyte = &pasirinkimas;
        cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
        ivedimas(rodyklyte);

        double mediana;
        if(pasirinkimas == 1){
            if(studentai[i].n%2 != 0){
                int abc = round(studentai[i].n/2);
                mediana = studentai[i].nd_rezultatas[abc]; 
            }

            else if(studentai[i].n%2 == 0){
                mediana = ( studentai[i].nd_rezultatas[studentai[i].n/2-1] + studentai[i].nd_rezultatas[studentai[i].n/2] ) / 2;
            }
        }
        
        if(pasirinkimas == 0){
            studentai[i].bendras_pazymys = (0.4 * (suma/studentai[i].n)) + (0.6 * studentai[i].egzamino_rezultatas);
        }
        else if(pasirinkimas == 1){
            studentai[i].bendras_pazymys = (0.4 * mediana) + (0.6 * studentai[i].egzamino_rezultatas);
        }
        
        i++;
    }

    i = 0;

    while(i){

        cout << "Vardas";

        if(studentai[0].name.length()>6){
            for(int i=0; i < studentai[i].name.length() + 6; i++){
                cout << " ";
            }
        }

        if(studentai[0].name.length() < 6){
            for(int n=0; n<5; n++){
                cout << " ";
            }
        }

        cout << "Pavarde";
        lengthCheck(7, studentai[0].surname);

        if(pasirinkimas == 0){
            cout << "Galutinis (Vid.)" << endl;
        }

        if(pasirinkimas == 1){
        cout << "Galutinis (Med.)" << endl;
        }

        for(int n=0; n < 60; n++)
            cout << "-";

        cout << endl;
        cout << studentai[i].name;
        lengthCheck(6, studentai[i].name);
        cout << studentai[i].surname;
        lengthCheck(7, studentai[i].surname);

        
        cout << fixed << setprecision(2) << studentai[i].bendras_pazymys<<endl;
        i++;
    }

}