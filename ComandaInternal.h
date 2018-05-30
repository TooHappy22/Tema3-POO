#ifndef __COMANDAINTERNAL_H_INCLUDED__
#define __COMANDAINTERNAL_H_INCLUDED__

#include <bits/stdc++.h>

enum StrategieComanda {
    ASZ = 1, // sa ajunga pana la o anumita secunda din zi
    ITM, // intr-un interval de timp maxim
    CMR // cat mai repede trebuie sa ajunga comanda
};

template< class T >
class Comanda {
    private:
        int m_nrArticole;
        T m_masaTotala;
        T m_volumTotal;
        vector< Articol< T > > m_articole;
        pair< double, double > m_pozitieStart;
        pair< double, double > m_pozitieFinal;
        StrategieComanda m_strategie;
        int m_valoareStrategie;
        pair< int, int > m_interval;
    public:
        Comanda();

        T GetMasaTotala() const;
        T GetVolumTotal() const;
        pair< double, double > GetStartPosition() const;
        pair< double, double > GetFinalPosition() const;
        bool NecesitaFrigorifica();
        StrategieComanda GetStrategie() const;
        int GetValoareStrategie() const;
        pair< int, int > GetInterval() const;

        friend class Firma< T >;

        template< class U > friend std::istream& operator>>(std::istream&, Comanda< U >&);

        ~Comanda();
};

#endif