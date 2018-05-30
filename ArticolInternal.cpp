#include <bits/stdc++.h>
#include "ArticolInternal.h"

template< class T >
Articol< T >::Articol() : m_masa(T()), m_volum(T()), m_necesitaFrigorifica(false) {
}

template< class T >
T Articol< T >::GetMasa() const {
    return this->m_masa;
}

template< class T >
T Articol< T >::GetVolum() const {
    return this->m_volum;
}

template< class T >
bool Articol< T >::NecesitaFrigorifica() const {
    return this->m_necesitaFrigorifica;
}

template< class T >
void Articol< T >::PrintData() {
    cout << "Masa articolului este: " << this->m_masa << 
    ". Volumul este: " << this->m_volum << ". ";
    if(this->m_necesitaFrigorifica == true) {
        cout << "Necesita lada frigorifica.\n";
    } else {
        cout << "Nu necesita lada frigorifica.\n";
    }
}

template< class T >
std::istream& operator>> (std::istream& in, Articol< T >& other) {
    in >> other.m_masa;
    in >> other.m_volum;
    string ans; in >> ans;

    std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

    if(ans == "da") {
        other.m_necesitaFrigorifica = true;
    }
    if(ans == "nu") {
        other.m_necesitaFrigorifica = false;
    }

    return in;
}