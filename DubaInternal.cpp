#include <bits/stdc++.h>
#include "DubaInternal.h"

template< class T >
Duba< T >::Duba(T masa, T volum, pair< double, double > coord, StrategieVehicul strategie, string frigorifica)
    : Vehicul< T >(masa, volum, coord, strategie), m_viteza((T)5)
{
    if(frigorifica == "Da" || frigorifica == "DA" || frigorifica == "da") {
        m_esteFrigorifica = true;
    }
    if(frigorifica == "Nu" || frigorifica == "NU" || frigorifica == "nu") {
        m_esteFrigorifica = false;
    }
}

template< class T >
T Duba< T >::GetViteza() {
    return this->m_viteza;
}

template< class T >
void Duba< T >::PrintData(std::ostream& out) {
    out << "Duba cu masa de: " << this->m_masaMaxima << 
    ". Volum disponibil: " << this->m_volumDisponibil;

    if(this->m_esteFrigorifica == true) {
        out << ". Duba frigorifica.\n";
    } else {
        out << ". Duba nefrigorifica.\n";
    }
}

template< class T >
double Duba< T >::GetDistance(const pair< double, double > & otherPos) {
    return abs(this->m_coordonate.first - otherPos.first) + abs(this->m_coordonate.second - otherPos.second);
}

template< class T >
Duba< T >::~Duba() {
}