#ifndef __MASINAINTERNAL_H_INCLUDED__
#define __MASINAINTERNAL_H_INCLUDED__

#include <iostream>

template< class T >
class Masina : public Vehicul< T > {
    private:
        T m_viteza;
    public:
        Masina(T, T, pair< double, double >, StrategieVehicul);

        T GetViteza();
        void PrintData(std::ostream&);
        double GetDistance(const pair< double, double > &);

        ~Masina();
};

#endif