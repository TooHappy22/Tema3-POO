#ifndef __DUBAINTERNAL_H_INCLUDED__
#define __DUBAINTERNAL_H_INCLUDED__

#include <bits/stdc++.h>

template< class T >
class Duba : public Vehicul< T > {
    private:
        T m_viteza;
        bool m_esteFrigorifica;
    public:
        Duba(T, T, pair< double, double >, StrategieVehicul, string);

        T GetViteza();
        void PrintData(std::ostream&);
        double GetDistance(const pair< double, double > &);
        
        ~Duba();
};

#endif