#include <bits/stdc++.h>
using namespace std;
#include "library.h"

const int sfarsitulZilei = 86400;
ifstream in;
ofstream out;

unordered_map< int, Comanda< double > > comenzi;
Firma< double > firma;
vector< bool > secunde(86405, false);

void ConvertSecondsToHoursAndMinutes(int seconds, int &hours, int &minutes) {
    hours = seconds / 3600;
    if(hours == 0) {
        minutes = seconds / 60;
    } else {
        minutes = seconds % (hours * 60);
        minutes %= 60;
    }
}

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

            int h = 0, min = 0; ConvertSecondsToHoursAndMinutes(i, h, min);
            if(h == 0) {
                if(min < 10) {
                    cout << "s-a facut la ora: 0" << h << ":0" << min << ".\n";        
                } else {
                    cout << "s-a facut la ora: 0" << h << ":" << min << ".\n";    
                }  
            } else {
                if(min < 10) {
                    cout << "s-a facut la ora: " << h << ":0" << min << ".\n";        
                } else {
                    cout << "s-a facut la ora: " << h << ":" << min << ".\n";    
                }  
            }

            int finalTime = 0;
            int idx = firma.GetBestVehicle(comenzi[i], i, finalTime); // cout << finalTime << "\n";

            if(idx == -1) {
                cout << "\tComanda " << cntComanda << " nu a putut fi preluata. Nu am gasit o masina care sa respecte conditiile!\n\n";
            } else {
                ConvertSecondsToHoursAndMinutes(finalTime, h, min);
                cout << "\tComanda acceptata. Comanda va fi preluata de catre masina cu numarul: " << idx + 1 << ".\n";
                cout << "\tAici aveti detaliile despre vehicul:\n\t\t"; firma.PrintDataVehicul(idx); cout << "\n";
            }
        }
    }

    return 0;
}