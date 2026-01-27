#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

 fstream plik("liczby.txt");
 const int N1 = 3000;
 const int N2 = 20;

//fstream plik("liczby_przyklad.txt");
//const int N1 = 200;
//const int N2 = 20;

 vector<int> rozkladNaPierwsze(int liczba) {
     vector<int> czynniki;
     for (int i = 2; i <= liczba; i++) {
         while (liczba % i == 0) {
             czynniki.push_back(i);
             liczba /= i;
         }
         if (liczba == 1) break;
     }
     return czynniki;
 }

int main() {
    vector<int> liczby1;
    vector<long long> liczby2;

    // Wczytanie N1 liczb z pierwszego wiersza
    for (int i = 0; i < N1; i++) {
        int x;
        plik >> x;
        liczby1.push_back(x);
    }

    // Wczytanie N2 liczb z drugiego wiersza
    for (int i = 0; i < N2; i++) {
        long long y;
        plik >> y;
        liczby2.push_back(y);
    }

    cout << 4.1 << endl;

    int licznik = 0;

    // Sprawdzanie podzielności
    for (int liczba1 : liczby1) {
        for (int liczba2 : liczby2) {
            if (liczba2 % liczba1 == 0) {
                licznik++;
                break; // Przerwij wewnętrzną pętlę, gdy znajdziesz podzielną liczbę
            }
        }
    }
    cout << licznik << endl;

    cout << "4.2 " << endl;
    vector<int> kopia = liczby1;
    sort(kopia.rbegin(), kopia.rend());
    
    int najw101 = kopia[101]; 
 
    cout << najw101 << endl;

   return 0;
}