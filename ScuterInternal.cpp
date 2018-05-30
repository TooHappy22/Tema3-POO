#include <bits/stdc++.h>
#include "ScuterInternal.h"

template< class T >
Scuter< T >::Scuter(T masa, T volum, pair< double, double > coord, StrategieVehicul strategie)
    : Vehicul< T >(masa, volum, coord, strategie), m_viteza((T)20)
{
}

template< class T >
T Scuter< T >::GetViteza() {
    return this->m_viteza;
}

template< class T >
void Scuter< T >::PrintData(std::ostream& out) {
    out << "Scuter cu masa de: " << this->m_masaMaxima << 
    ". Volum disponibil: " << this->m_volumDisponibil;
}

template< class T >
double Scuter< T >::GetDistance(const pair< double, double > & otherPos) {
    return sqrt((this->m_coordonate.first - otherPos.first) * (this->m_coordonate.first - otherPos.first) + (this->m_coordonate.second - otherPos.second) * (this->m_coordonate.second - otherPos.second));
}

template< class T >
Scuter< T >::~Scuter() {
}