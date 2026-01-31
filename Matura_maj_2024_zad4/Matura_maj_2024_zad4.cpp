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


    for (int liczba1 : liczby1) {
        for (int liczba2 : liczby2) {
            if (liczba2 % liczba1 == 0) {
                licznik++;
                break;             }
        }
    }
    cout << licznik << endl;

    cout << "4.2 " << endl;
    vector<int> kopia = liczby1;
    sort(kopia.rbegin(), kopia.rend());
    
    int najw101 = kopia[101]; 
 
    cout << najw101 << endl;

    cout << "4.3 " << endl;//poprawić
    int licznik1 = 0;

    sort(liczby1.begin(), liczby1.end());
    vector<int> kopia1 = liczby1;
    vector<long long> kopia2 = liczby2;

    for (int j = 0; j < liczby2.size(); j++) {
        liczby1 = kopia1;
        for (int i = 0; i < liczby1.size(); i++) {
            if (liczby2[j] % liczby1[i] == 0) {
                liczby2[j] /= liczby1[i];
                liczby1.erase(liczby1.begin() + i);
                i--; // cofamy indeks
            }
        }
        if (liczby2[j] == 1) {
            cout << kopia2[j]<<endl;
        }
    }

   return 0;
}