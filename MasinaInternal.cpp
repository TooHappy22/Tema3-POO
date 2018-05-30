#include <bits/stdc++.h>
#include "MasinaInternal.h"

template< class T >
Masina< T >::Masina(T masa, T volum, pair< double, double > coord, StrategieVehicul strategie)
    : Vehicul< T >(masa, volum, coord, strategie), m_viteza((T)10)
{
}

template< class T >
T Masina< T >::GetViteza() {
    return this->m_viteza;
}

template< class T >
void Masina< T >::PrintData(std::ostream& out) {
    out << "Masina cu masa de: " << this->m_masaMaxima << 
    ". Volum disponibil: " << this->m_volumDisponibil;
}

template< class T >
double Masina< T >::GetDistance(const pair< double, double > & otherPos) {
    return abs(this->m_coordonate.first - otherPos.first) + abs(this->m_coordonate.second - otherPos.second);
}

template< class T >
Masina< T >::~Masina(){
}