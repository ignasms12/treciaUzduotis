
#include "vars.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

struct Studentas {
  string name;
  string surname;
  int n;
  vector<int> nd_rezultatas;
  double egzamino_rezultatas;
  double bendras_pazymys;
};


void bubbleSort(Studentas pavyzdys, int n) {
  bool exchanges;
  do {
    exchanges = false;
    for (int c = 0; c < n - 1; c++) {
      if (pavyzdys.nd_rezultatas[c] > pavyzdys.nd_rezultatas[c + 1]) {
        double temp = pavyzdys.nd_rezultatas[c];
        pavyzdys.nd_rezultatas[c] = pavyzdys.nd_rezultatas[c + 1];
        pavyzdys.nd_rezultatas[c + 1] = temp;
        exchanges = true;
      }
    }
  } while (exchanges);
}

void compare(Studentas *pavyzdys) {
  if (pavyzdys->n <= 0) {
    cout << "Uzduociu kiekis negali buti maziau 1" << endl;
    cout << "Iveskite uzduociu kieki: ";
    cin >> pavyzdys->n;
    compare(pavyzdys);
  }
}

void ivedimas(int* pvz) {
  string pavyzdys;
  cin >> pavyzdys;
  if (pavyzdys == "Vidurkis" || pavyzdys == "vidurkis") {
    *pvz = 0;
  } else if (pavyzdys == "Mediana" || pavyzdys == "mediana") {
    *pvz = 1;
  } else {
    cout << "Neteisingai ivedete, iveskite Vidurkis arba Mediana: ";
    ivedimas(pvz);
  }
}

void input(Studentas *pavyzdys) {
  int indeksas = 0;
  while (indeksas < pavyzdys->n) {
    pavyzdys->nd_rezultatas.push_back(int());
    cout << indeksas + 1 << " - ";
    cin >> pavyzdys->nd_rezultatas[indeksas];
    while (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Neteisinga reiksme, iveskite skaiciu: " << endl;
      cout << indeksas + 1 << " - ";
      cin >> pavyzdys->nd_rezultatas[indeksas];
    }
    if (pavyzdys->nd_rezultatas[indeksas] > 10 || pavyzdys->nd_rezultatas[indeksas] < 1) {
      cout << "Pazymys turi buti intervale tarp 1 ir 10, iveskite tinkama pazymi:" << endl;
      input(pavyzdys);
    } else {
      indeksas++;
    }
  }
  indeksas = 0;
}

void input_result(Studentas *pavyzdys) {
  cin >> pavyzdys->egzamino_rezultatas;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Neteisinga reiksme, iveskite skaiciu: " << endl;
    cin >> pavyzdys->egzamino_rezultatas;
  }
  if (pavyzdys->egzamino_rezultatas > 10 || pavyzdys->egzamino_rezultatas < 1) {
    cout << "Egzamino rezultatas privalo buti intervale nuo 1 iki 10, iveskite "
            "tinkama rezultata:"
         << endl;
    input_result(pavyzdys);
  }
}

void validityCheck(Studentas *pavyzdys) {
  cin >> pavyzdys->n;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Neteisinga reiksme, iveskite skaiciu: " << endl;
    cin >> pavyzdys->n;
  }
}

void naujasIrasas(char *rankis, int *numeriukas){
  if(*numeriukas == 0){
    cout << "Ar norite prideti nauja irasa ? (Y/N)" << endl;
  }
  else if(*numeriukas > 0){
    cout << "Neteisingai ivedete - iveskite Y arba N" << endl;
  }
  cin >> *rankis;
  numeriukas++;
}


void galutinioSkaiciavimas(Studentas &rodiklis, int &porankis){

  int suma = 0;
  for (int a = 0; a < rodiklis.nd_rezultatas.size() ; a++) {
    suma += rodiklis.nd_rezultatas[a];
  }

  double mediana;
  if (porankis == 1) {

    if (rodiklis.n % 2 != 0) {
      int abc = round(rodiklis.n / 2);
      mediana = rodiklis.nd_rezultatas[abc];
    }

    else if (rodiklis.n % 2 == 0) {
      mediana = (rodiklis.nd_rezultatas[rodiklis.n / 2 - 1] + rodiklis.nd_rezultatas[rodiklis.n / 2])/2;
    }
    rodiklis.bendras_pazymys = (0.4 * mediana) + (0.6 * rodiklis.egzamino_rezultatas);
  }

  else if(porankis == 0){
    rodiklis.bendras_pazymys = (0.4 * ( suma / rodiklis.nd_rezultatas.size() ) ) + (0.6 * rodiklis.egzamino_rezultatas );
  }

}

bool comparation(Studentas &a, Studentas &b){
  return (a.name < b.name || (a.name == b.name && a.surname < b.surname));
}



int main() {
  int *rod;
  std::vector<Studentas> studentai;
  int pasirinkimas;
  char taipArbaNe;
  int i = 0;

  int ivedimoPorank;
  char ived;
  int ka;
  double skirtumas;
  

  std::cout << "Ar norite sukurti nauja faila ? Y/N" << std::endl;
  std::cin >> ived;

  if(ived == 'Y' || ived == 'y'){
    random_gen();
  }
  
  std::cout << std::endl;
  std::cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
  ivedimas(pasirinkimas);
  std::cout << std::endl;
  
  std::cout << "Kaip ivesite irasus:" << std::endl;
  std::cout << "0 - Irasai ivedami ranka" << std::endl;
  std::cout << "1 - Irasai nuskaitomi is failo" << std::endl;

  std::cin >> ivedimoPorank;

  ivedimoPorankis(studentai, pasirinkimas, i, ivedimoPorank, taipArbaNe);
  
  std::vector<Studentas> kietekai;
  std::vector<Studentas> vargsiukai;

  sort(studentai.begin(), studentai.end(), comparation);

  auto pradzia = std::chrono::steady_clock::now( );
  splitOutput(studentai, kietekai, vargsiukai);
  auto pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - pradzia );

  std::cout << "Skirstymas i atskiras kategorijas uztruko: " << pabaiga.count() << " ms" << std::endl;
  
  std::cout << "\nAr norite isvesti i konsole ar i atskira faila ?" << std::endl;
  std::cout << "0 - i konsole" << std::endl;
  std::cout << "1 - i faila" << std::endl;
  std::cin >> ka;

  if(ka == 0){
    print(studentai, vargsiukai, kietekai, pasirinkimas);
  }
  else if(ka==1){
    auto start = std::chrono::steady_clock::now( );
    
    outputToFile(kietekai, vargsiukai, pasirinkimas);

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - start );

    std::cout << std::endl;
    std::cout << "Isvedimas i failus uztruko: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;
  }

  
  string stop = "uztenka";
  string stop2 = "Uztenka";

  
  cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
  ivedimas(rodyklyte);

  int ivedimoPorankis;
  cout << "Kaip ivesite irasus:" << endl;
  cout << "0 - Irasai ivedami ranka" << endl;
  cout << "1 - Irasai nuskaitomi is failo" << endl;

  cin >> ivedimoPorankis;

  string word;
  int index = 0;

  if(ivedimoPorankis == 0){
      studentai.push_back(Studentas());
      cout << "Iveskite studento varda" << endl;
      cin >> studentai[i].name >> studentai[i].surname;

      char rodyklius;
      int rodiklius = 0;

      while ( i >= 0 ) {
        char *porankis;
        if (i > 0){
          int *skaiciuks;
          skaiciuks = &rodiklius;
          porankis = &rodyklius;
          naujasIrasas(porankis, skaiciuks);

          if(rodyklius == 'y' || rodyklius == 'Y'){
            studentai.push_back(Studentas());
            cout << "Iveskite studento varda" << endl;
            cin >> studentai[i].name;
            cin >> studentai[i].surname;
          }
          else if(rodyklius == 'n' || rodyklius == 'N'){
            break;
          }
          else{
            naujasIrasas(porankis, skaiciuks);
          }
        }

        rodykle = &studentai[i];
        cout << "Ar norite rezultatus sugeneruoti atsitiktinai ? Y/N" << endl;
        cin >> taipArbaNe;

        if (taipArbaNe == 'Y' || taipArbaNe == 'y') {

          srand(time(0));
          studentai[i].n = rand() % 15 + 1;
          for (int a = 0; a < studentai[i].n; a++) {
            studentai[i].nd_rezultatas.push_back(int());
            studentai[i].nd_rezultatas[a] = rand() % 10 + 1;
          }
          studentai[i].egzamino_rezultatas = rand() % 10 + 1;
          cout << endl;
          cout << endl;
          bubbleSort(studentai[i], studentai[i].n);
          cout << "Namu darbu rezultatai: " << endl;
          for (int a = 0; a < studentai[i].n; a++) {
            cout << studentai[i].nd_rezultatas[a] << endl;
          }
          cout << endl;
          cout << endl;
          cout << "Egzamino rezultatas: " << endl;
          cout << studentai[i].egzamino_rezultatas << endl;
          cout << endl;
        } 

        else if (taipArbaNe == 'N' || taipArbaNe == 'n') {
          cout << "Iveskite studento egzamino rezultata: " << endl;
          input_result(rodykle);
          cout << endl;

          cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:"
              << endl;
          cout << endl;

          cout << "Namu darbu uzduociu kiekis: ";

          Studentas *rodyklele = &studentai[i];
          validityCheck(rodyklele);
          compare(rodyklele);  // jei n mazesnis uz 0, useriui metamas erroras
          cout << endl;

          cout << "Namu darbu uzduociu ivertinimai: " << endl << endl;
          Studentas *wazeep;
          wazeep = &studentai[i];
          input(wazeep);

        }

        else {
          cout << "Iveskite Y arba N:" << endl;
          cin >> taipArbaNe;
        }

        

        
        galutinioSkaiciavimas(studentai[i], pasirinkimas);
        
        

        


        i++;
        rodiklius = 0;
      }
  }

  

  else if(ivedimoPorankis == 1){
    string Value = "";
    int count = 0;
    ifstream failas("kursiokai.txt");
    failas >> Value >> Value >> Value;
    while(Value[0] == 'N'){
      failas >> Value;
      count++;
    }
    while(!failas.eof()){
      studentai.push_back(Studentas());
      failas >> studentai[i].name >> studentai[i].surname; 
      for(int l = 0; l < count; l++){
        studentai[i].nd_rezultatas.push_back(int());
        failas >> studentai[i].nd_rezultatas[l];
      } 
      failas >> studentai[i].egzamino_rezultatas;
      galutinioSkaiciavimas(studentai[i], pasirinkimas);
      i++;
      if(i%1000 == 0){
        cout << i << endl;
      }
      }
      failas.close();
    
  }

  sort(studentai.begin(), studentai.end(), comparation);
  

  cout << endl;
  cout << endl;
  cout.width(15);
  cout << left << "Vardas";
  cout.width(15);
  cout << left << "Pavarde";
  
  cout.width(16);
  if (pasirinkimas == 0) {
    cout << left << "Galutinis (Vid.)" << endl;
  }

  else if (pasirinkimas == 1) {
    cout << left << "Galutinis (Med.)" << endl;
  }
  for (int n = 0; n < 60; n++) cout << "-";

  for(int sup=0; sup < studentai.size(); sup++) {
    cout << endl;
    cout.width(15);
    cout << left << studentai[sup].name;
    cout.width(20);
    cout << left << studentai[sup].surname;
    cout << fixed << setprecision(2) << studentai[sup].bendras_pazymys << endl;
  }
  cout << endl;

}