#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n, kiekis;
    srand(time(NULL));
    cout << "Iveskite namu darbu kieki: ";
    cin >> n;
    cout << "\n Iveskite irasu kieki: ";
    cin >> kiekis;
    ofstream failas;
    failas.open("random.txt");
    failas << "Vardas" << "    " << "Pavarde" << "    ";
    for(int i=1; i< n+1; i++){
        failas << "ND" << i << "    ";
    }
    failas << "Egz. Rezult" << endl;
    for(int i=0; i<kiekis; i++){
        failas << "Vardas" << i << "    " << "Pavarde" << i << "    ";
        for(int j=0; j<n; j++){
            failas << rand() % 10 + 1 << "    ";
        }
        failas << rand() % 10 + 1 << endl;


    }
}