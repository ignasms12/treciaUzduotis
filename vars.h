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



class Studentas {

  //Custom Print Operator
  friend std::ostream& operator<<(std::ostream&, const Studentas&);
  friend std::ostream& operator>>(std::ostream&, const Studentas&);
  private:
    std::string name;
    std::string surname;
    int n;
    std::vector<int> nd_rezultatas;
    double egzamino_rezultatas;
    double bendras_pazymys;

  public:
    //Copy Constructor
    Studentas(const Studentas&);

    //Overloaded Assignment Operator
    Studentas& operator=(const Studentas& );


    Studentas() : egzamino_rezultatas(0) { }
    inline std::string vardas() const {return name;} // get'eriai
    inline std::string pavarde() const {return surname;} // get'eriai
    inline int nd(int a) {return nd_rezultatas[a] ; } // get'eriai
    inline double exam() const {return egzamino_rezultatas;} // get'eriai
    inline double final() const {return bendras_pazymys;} //get'eriai
    inline int kiekis() const {return n;} //get'eriai
    void galutinioSkaiciavimas(int);
    void readStudent(int, std::ifstream&, int);
    void input();
    void vienoStudentoIvedimas(int &, int& , int , char );

};



void bubbleSort(Studentas , int );

template <typename T>

void validityCheck(T&);

int digitCounter(int);

void random_gen();

void compare(Studentas&);

void ivedimas(int&);

void input_result(Studentas*);

void naujasIrasas(char*, int*);

bool comparation(Studentas&, Studentas&);

void splitOutput(std::vector<Studentas> &, std::vector<Studentas>& , std::vector<Studentas>& );

void print(std::vector<Studentas> , std::vector<Studentas>, std::vector<Studentas>, int );

void outputToFile(std::vector<Studentas>, std::vector<Studentas>, int);

void readFile(std::vector<Studentas> &, int , int );

void ivedimoBudas(std::vector<Studentas>&, int&, int , int , char );