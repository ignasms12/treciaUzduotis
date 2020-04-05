#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
#include <chrono>
#include <deque>



struct Studentas {
  std::string name;
  std::string surname;
  int n;
  std::deque<int> nd_rezultatas;
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

void splitOutput(std::deque<Studentas> &, std::deque<Studentas>&);

void print(std::deque<Studentas> , std::deque<Studentas>, int );

void outputToFile(std::deque<Studentas>, std::deque<Studentas>, int);

void readFile(std::deque<Studentas>&, int, int);

void ivedimoPorankis(std::deque<Studentas>&, int&, int , int , char );