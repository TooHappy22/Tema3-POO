#ifndef __SCUTERINTERNAL_H_INCLUDED__
#define __SCUTERINTERNAL_H_INCLUDED__

#include <bits/stdc++.h>
#include "Vehicul.h"

template< class T >
class Scuter : public Vehicul< T > {
    private:
        T m_viteza;
    public:
        Scuter(T, T, pair< double, double >, StrategieVehicul);

        T GetViteza();
        void PrintData(std::ostream&);
        double GetDistance(const pair< double, double > &);

        ~Scuter();
};

#endif