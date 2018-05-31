#include <bits/stdc++.h>
#include "FirmaInternal.h"

double EuclidianDist(const pair< double, double > &p1, const pair< double, double > &p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double ManhattanDist(const pair< double, double > &p1, const pair< double, double > &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

template< class T >
Firma< T >::Firma() : m_vehicule(vector< Vehicul< T >* >()), m_strategie(VA) {
}

template< class T >
int Firma< T >::getSize() const {
    return (int)this->m_vehicule.size();
}

template< class T >
StrategieFirma Firma< T >::getStrategie() const {
    return this->m_strategie;
}

template< class T >
void Firma< T >::AdaugaVehicul(Vehicul< T >* other) {
    this->m_vehicule.push_back(other);
}

template< class T >
T Firma< T >::GetMasaMaxima() const {
    T maxim = T();
    for(int i = 0; i < this->getSize(); ++i) {
        maxim = max(maxim, this->m_vehicule[i]->GetMasaMaximaAdmisa());
    }

    return maxim;
}

template< class T >
T Firma< T >::GetVolumMaxim() const {
    T maxim = T();
    for(int i = 0; i < this->getSize(); ++i) {
        maxim = max(maxim, this->m_vehicule[i]->GetVolumDisponibil());
    }

    return maxim;
}

template< class T >
int Firma< T >::GetBestVehicle(Comanda< T >& comanda, const int &currentTime, int &finalTime) {
    int bestVehicle = 0, bestTime = 1e9;

    if(comanda.NecesitaFrigorifica() == true) {
        for(int i = 0; i < this->getSize(); ++i) {
            if(this->m_vehicule[i]->CheckDisponibilitate() == false || this->m_vehicule[i]->GetViteza() != T(5)) {
                continue;
            }

            double tempDistToStart = this->m_vehicule[i]->GetDistance(comanda.GetStartPosition());
            double tempDistStartToDest = 0;
            int tempTime = 0;

            if(this->m_vehicule[i]->GetViteza() == T(20)) {
                tempDistStartToDest = EuclidianDist(comanda.GetStartPosition(), comanda.GetFinalPosition());
                double tempDist = tempDistToStart + tempDistStartToDest;
                tempTime = ceil(tempDist / 20.0);
            } else {
                tempDistStartToDest = ManhattanDist(comanda.GetStartPosition(), comanda.GetFinalPosition());
                double tempDist = tempDistToStart + tempDistStartToDest;
                tempTime = ceil(tempDist / double(this->m_vehicule[i]->GetViteza()));
            }

            if(comanda.GetStrategie() == 2) {
                if(tempTime < bestTime && currentTime + tempTime >= comanda.GetInterval().first
                    && currentTime + tempTime <= comanda.GetInterval().second
                    && this->m_vehicule[i]->GetMasaMaximaAdmisa() >= comanda.GetMasaTotala()
                    && this->m_vehicule[i]->GetVolumDisponibil() >= comanda.GetVolumTotal()) {
                    bestTime = tempTime;
                    bestVehicle = i;
                }
            } else {
                if(tempTime < bestTime && this->m_vehicule[i]->GetMasaMaximaAdmisa() >= comanda.GetMasaTotala() && this->m_vehicule[i]->GetVolumDisponibil() >= comanda.GetVolumTotal()) {
                    bestTime = tempTime;
                    bestVehicle = i;
                }
            }
        }
    } else {
        for(int i = 0; i < this->getSize(); ++i) {
            if(this->m_vehicule[i]->CheckDisponibilitate() == false) {
                continue;
            }

            double tempDistToStart = this->m_vehicule[i]->GetDistance(comanda.GetStartPosition());
            double tempDistStartToDest = 0;
            int tempTime = 0;

            if(this->m_vehicule[i]->GetViteza() == T(20)) {
                tempDistStartToDest = EuclidianDist(comanda.GetStartPosition(), comanda.GetFinalPosition());
                double tempDist = tempDistToStart + tempDistStartToDest;
                tempTime = ceil(tempDist / 20.0);
            } else {
                tempDistStartToDest = ManhattanDist(comanda.GetStartPosition(), comanda.GetFinalPosition());
                double tempDist = tempDistToStart + tempDistStartToDest;
                tempTime = ceil(tempDist / double(this->m_vehicule[i]->GetViteza()));
            }

            if(comanda.GetStrategie() == 2) {
                if(tempTime < bestTime && currentTime + tempTime >= comanda.GetInterval().first
                    && currentTime + tempTime <= comanda.GetInterval().second
                    && this->m_vehicule[i]->GetMasaMaximaAdmisa() >= comanda.GetMasaTotala()
                    && this->m_vehicule[i]->GetVolumDisponibil() >= comanda.GetVolumTotal()) {
                    bestTime = tempTime;
                    bestVehicle = i;
                }
            } else {
                if(tempTime < bestTime && this->m_vehicule[i]->GetMasaMaximaAdmisa() >= comanda.GetMasaTotala() && this->m_vehicule[i]->GetVolumDisponibil() >= comanda.GetVolumTotal()) {
                    bestTime = tempTime;
                    bestVehicle = i;
                }
            }
        }
    }

    if(bestTime == 1e9) {
        return -1;
    }

    finalTime = currentTime + bestTime;

    this->m_vehiculeBlocate.push({currentTime + bestTime, bestVehicle});
    this->m_vehicule[bestVehicle]->ChangeDisponibilitate();
    this->m_vehicule[bestVehicle]->SetPosition(comanda.GetFinalPosition());

    return bestVehicle;
}

template< class T >
void Firma< T >::ElibereazaVehicul(const int& currentTime) {
    if(!this->m_vehiculeBlocate.empty()) {
        if(this->m_vehicule[this->m_vehiculeBlocate.top().first == currentTime]) {
            this->m_vehicule[this->m_vehiculeBlocate.top().second]->ChangeDisponibilitate();
            this->m_vehiculeBlocate.pop();
        }
    }
}

template< class T >
void Firma< T >::PrintDataVehicul(const int &idx) {
    this->m_vehicule[idx]->PrintData(cout);
}

template< class T >
std::istream& operator >> (std::istream& in, Firma< T >& other) {
    int nrVehicule; in >> nrVehicule;

    for(int i = 0; i < nrVehicule; ++i) {
        string type, strategie;
        in >> type;
        int masa, volum;
        double x, y;
        in >> masa >> volum >> x >> y;
        in >> strategie;

        string frigorifica = "";
        if(type == "Duba") {
            in >> frigorifica;
        }

        if(strategie == "CMA") {
            try {
                other.AdaugaVehicul(Vehicul< T >::GetVehicul(type, masa, volum, {x, y}, CMA, frigorifica));
            } catch(std::bad_alloc &exception) {
                cout << "Vehicul Invalid\n";
            }
        }
        if(strategie == "CMU") {
            try {
                other.AdaugaVehicul(Vehicul< T >::GetVehicul(type, masa, volum, {x, y}, CMU,frigorifica));
            } catch(std::bad_alloc &exception) {
                cout << "Vehicul Invalid\n";
            }
        }
        if(strategie == "FCFS") {
            try {
                other.AdaugaVehicul(Vehicul< T >::GetVehicul(type, masa, volum, {x, y}, FCFS, frigorifica));
            } catch(std::bad_alloc &exception) {
                cout << "Vehicul Invalid\n";
            }
        }
    }

    return in;
}

template< class T >
std::ostream& operator<<(std::ostream& out, const Firma< T >& other) {
    for(int i = 0; i < (int)other.m_vehicule.size(); ++i) {
        other.m_vehicule[i]->PrintData(out);
    }

    return out;
}

template< class T >
Firma< T >::~Firma() {
    for(int i = 0; i < (int)this->m_vehicule.size(); ++i) {
        delete this->m_vehicule[i];
    }
    this->m_vehicule.erase(this->m_vehicule.begin(), this->m_vehicule.end());
}