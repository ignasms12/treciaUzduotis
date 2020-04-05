#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>



struct Studentas {
  std::string name;
  std::string surname;
  int n;
  std::vector<int> nd_rezultatas;
  double egzamino_rezultatas;
  double bendras_pazymys;
};


double diffclock( clock_t , clock_t);

void bubbleSort(Studentas , int );

int digitCounter(int);

void random_gen();

void compare(Studentas*);

void ivedimas(int&);

void input(Studentas*); 

void input_result(Studentas*);

void validityCheck(Studentas*);

void naujasIrasas(char*, int*);

void galutinioSkaiciavimas(Studentas&, int&);

bool comparation(Studentas&, Studentas&);

void splitOutput(std::vector<Studentas> &, std::vector<Studentas>&);

void print(std::vector<Studentas> , std::vector<Studentas>, int );

void outputToFile(std::vector<Studentas>, std::vector<Studentas>, int);

void readFile(std::vector<Studentas>&, int, int);

void ivedimoPorankis(std::vector<Studentas>&, int&, int , int , char );