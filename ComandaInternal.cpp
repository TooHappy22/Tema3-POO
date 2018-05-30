#include <bits/stdc++.h>
#include "ComandaInternal.h"

template< class T >
Comanda< T >::Comanda()
    : m_nrArticole(0), m_masaTotala(T()),
    m_volumTotal(T()), m_articole(vector< Articol< T > >()),
    m_pozitieStart({0, 0}), m_pozitieFinal({0, 0}),
    m_strategie(CMR), m_interval({0, 0})
{
}

template< class T >
T Comanda< T >::GetMasaTotala() const {
    return this->m_masaTotala;
}

template< class T >
T Comanda< T >::GetVolumTotal() const {
    return this->m_volumTotal;
}

template< class T >
pair< double, double > Comanda< T >::GetStartPosition() const {
    return this->m_pozitieStart;
}

template< class T >
pair< double, double > Comanda< T >::GetFinalPosition() const {
    return this->m_pozitieFinal;
}

template< class T >
bool Comanda< T >::NecesitaFrigorifica() {
    bool ans = false;
    for(int i = 0; i < this->m_nrArticole; ++i) {
        ans |= this->m_articole[i].NecesitaFrigorifica();
    }

    return ans;
}

template< class T >
StrategieComanda Comanda< T >::GetStrategie() const {
    return this->m_strategie;
}

template< class T >
int Comanda< T >::GetValoareStrategie() const {
    return this->m_valoareStrategie;
}

template< class T >
pair< int, int > Comanda< T >::GetInterval() const {
    return this->m_interval;
}

template< class T >
std::istream& operator>>(std::istream& in, Comanda< T >& other) {
    in >> other.m_nrArticole;

    other.m_articole.resize(other.m_nrArticole);
    for(int i = 0; i < other.m_nrArticole; ++i) {
        in >> other.m_articole[i];
        other.m_masaTotala += other.m_articole[i].GetMasa();
        other.m_volumTotal += other.m_articole[i].GetVolum();
    }

    double x, y; 
    in >> x >> y;
    other.m_pozitieStart = make_pair(x, y);
    
    in >> x >> y;
    other.m_pozitieFinal = make_pair(x, y);

    string strategie; in >> strategie;
    if(strategie == "ASZ") {
        other.m_strategie = ASZ;
        in >> other.m_valoareStrategie;
    }
    if(strategie == "ITM") {
        other.m_strategie = ITM;
        in >> other.m_interval.first >> other.m_interval.second;
    }
    if(strategie == "CMR") {
        other.m_strategie = CMR;
    }

    for(int i = 0; i < other.m_nrArticole; ++i) {
        other.m_masaTotala += other.m_articole[i].GetMasa();
        other.m_volumTotal += other.m_articole[i].GetVolum();
    }

    return in;
}

template< class T >
Comanda< T >::~Comanda() {
}

