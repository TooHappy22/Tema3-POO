#include <bits/stdc++.h>
using namespace std;
#include "library.h"

const int sfarsitulZilei = 86400;
ifstream in;
ofstream out;

unordered_map< int, Comanda< double > > comenzi;
Firma< double > firma;
vector< bool > secunde(86405, false);

int main() {
    in.open("vehicule.in", istream::in); out.open("vehicule.out", ostream::out);

    in >> firma;
    out << firma << "\n";

    in.close(); out.close();

    in.open("comenzi.in", istream::in);

    int nrComenzi;
    in >> nrComenzi;
    for(int i = 1; i <= nrComenzi; ++i) {
        int timp; in >> timp;
        in >> comenzi[timp];
        secunde[timp] = true;
    }

    in.close();

    int cntComanda = 0;
    for(int i = 1; i <= sfarsitulZilei; ++i) {
        firma.ElibereazaVehicul(i);
        if(secunde[i] == true) {
            ++cntComanda;
            cout << "Comanda numarul " << cntComanda << " ";

            int hour = i / 3600;
            if(hour == 0) {
                cout << "s-a facut la ora: 00:" << i / 60 << ".\n";
            } else {
                int minut = i % (hour * 60);
                cout << "s-a facut la ora: " << hour << ":" << minut % 60 << ".\n";
            }

            int idx = firma.GetBestVehicle(comenzi[i], i);

            if(idx == -1) {
                cout << "\tComanda " << cntComanda << " nu a putut fi preluata. Nu am gasit o masina care sa respecte conditiile!\n\n";
            } else {
                cout << "\tComanda acceptata. Comanda va fi preluata de catre masina cu numarul: " << idx + 1 << ".\n";
                cout << "\tAici aveti detaliile despre vehicul:\n\t\t"; firma.PrintDataVehicul(idx); cout << "\n";
            }
        }
    }

    return 0;
}