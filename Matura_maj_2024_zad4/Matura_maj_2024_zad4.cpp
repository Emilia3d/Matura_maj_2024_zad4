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

    int ile_dzielnikow = 0;

    for (int i = 0; i < (int)liczby1.size(); i++) {
        int a = liczby1[i];
        bool jestDzielnikiem = false;

        for (int j = 0; j < (int)liczby2.size(); j++) {
            long long b = liczby2[j];
            if (b % a == 0) {
                jestDzielnikiem = true;
                break;
            }
        }

        if (jestDzielnikiem) ile_dzielnikow++;
    }


    vector<int> kopia = liczby1;
    sort(kopia.rbegin(), kopia.rend());
    

    int najw101 = kopia[101]; // zakładamy, że N1 >= 2

    cout << "4.1 " << ile_dzielnikow << endl;
    cout << "4.2 " << najw101 << endl;


    cout << "Zapisano odpowiedzi do wyniki4.txt" << endl;

    return 0;
}