#include <bits/stdc++.h>
#include "VehiculInternal.h"
#include "Scuter.h"
#include "Masina.h"
#include "Duba.h"

template< class T >
Vehicul< T >::Vehicul()
    : m_masaMaxima(T()), m_volumDisponibil(T()), 
    m_coordonate(make_pair(0, 0)), m_disponibil(true),
    m_strategieVehicul(FCFS)
{
}

template< class T >
Vehicul< T >::Vehicul(T masa, T volum, pair< double, double > coord, StrategieVehicul strategie)
    : m_masaMaxima(masa), m_volumDisponibil(volum),
    m_coordonate(coord), m_disponibil(true),
    m_strategieVehicul(strategie)
{
}

template< class T >
T Vehicul< T >::GetMasaMaximaAdmisa() const {
    return this->m_masaMaxima;
}

template< class T >
T Vehicul< T >::GetVolumDisponibil() const {
    return this->m_volumDisponibil;
}

template< class T >
pair< double, double > Vehicul< T >::GetPosition() const {
    return this->m_coordonate;
}

template< class T >
bool Vehicul< T >::CheckDisponibilitate() const {
    return this->m_disponibil;
}

template< class T >
void Vehicul< T >::SetPosition(const pair< double, double > &newPosition) {
    this->m_coordonate = newPosition;
}

template< class T >
void Vehicul< T >::ChangeDisponibilitate() {
    this->m_disponibil = !this->m_disponibil;
}

template< class T >
Vehicul< T >* Vehicul< T >::GetVehicul(string vehicleName, T masa, T volum, pair< double, double > coord, StrategieVehicul strategie, string frigorifica) {
    if(vehicleName == "Scuter") {
        return new Scuter< T >(masa, volum, coord, strategie);
    }
    if(vehicleName == "Masina") {
        return new Masina< T >(masa, volum, coord, strategie);
    }
    if(vehicleName == "Duba") {
        return new Duba< T >(masa, volum, coord, strategie, frigorifica);
    }
    std::bad_alloc exception;
    throw exception;
}