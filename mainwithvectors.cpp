#include "vars.h"

int main() {
  int *rod;
  std::vector<Studentas> studentai;
  int pasirinkimas;
  char taipArbaNe;
  int i = 0;
  int ivedimoPorank;

  std::cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
  ivedimas(pasirinkimas);

  
  std::cout << "Kaip ivesite irasus:" << std::endl;
  std::cout << "0 - Irasai ivedami ranka" << std::endl;
  std::cout << "1 - Irasai nuskaitomi is failo" << std::endl;

  std::cin >> ivedimoPorank;

  ivedimoPorankis(studentai, pasirinkimas, i, ivedimoPorank, taipArbaNe);

  sort(studentai.begin(), studentai.end(), comparation);
  
  print(studentai, pasirinkimas);
  
}