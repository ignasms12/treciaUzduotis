#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

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

void lengthCheck(int skaicius, string eilute) {
  if (eilute.length() < skaicius) {
    for (int a = 0; a < skaicius - eilute.length() + 5; a++) {
      cout << " ";
    }
  } else if (eilute.length() > skaicius) {
    for (int a = 0; a < eilute.length() + 5; a++) {
      cout << " ";
    }
  } else {
    cout << "     ";
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

int main() {
  int *rod;

  vector<Studentas> studentai;
  Studentas *rodykle;

  int pasirinkimas;
  int *rodyklyte = &pasirinkimas;

  char taipArbaNe;
  int i = 0;
  string stop = "uztenka";
  string stop2 = "Uztenka";

  studentai.push_back(Studentas());
  
  cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
  ivedimas(rodyklyte);

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

    

    int suma = 0;
    for (int a = 0; a < studentai[i].nd_rezultatas.size() ; a++) {
      suma += studentai[i].nd_rezultatas[a];
      
    }
    
    
    

    double mediana;
    if (pasirinkimas == 1) {

      if (studentai[i].n % 2 != 0) {
        int abc = round(studentai[i].n / 2);
        mediana = studentai[i].nd_rezultatas[abc];
      }

      else if (studentai[i].n % 2 == 0) {
        mediana = (studentai[i].nd_rezultatas[studentai[i].n / 2 - 1] + studentai[i].nd_rezultatas[studentai[i].n / 2])/2;
      }
      studentai[i].bendras_pazymys = (0.4 * mediana) + (0.6 * studentai[i].egzamino_rezultatas);
    }

    else if(pasirinkimas == 0){
      studentai[i].bendras_pazymys = (0.4 * ( suma / studentai[i].nd_rezultatas.size() ) ) + (0.6 * studentai[i].egzamino_rezultatas );
    }


    i++;
    rodiklius = 0;
  }

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
    cout.width(15);
    cout << left << studentai[sup].surname;
    cout << fixed << setprecision(2) << studentai[sup].bendras_pazymys << endl;
  }
  cout << endl;
}