#ifndef __VEHICULINTERNAL_H_INCLUDED__
#define __VEHICULINTERNAL_H_INCLUDED__

#include <bits/stdc++.h>

enum StrategieVehicul {
    CMU = 1, // cel mai urgent colet
    CMA, // cel mai aproapiat colet
    FCFS // first come first served
};

template< class T >
class Vehicul {
    public:
        T m_masaMaxima;
        T m_volumDisponibil;
        pair< double, double > m_coordonate;
        bool m_disponibil;
        StrategieVehicul m_strategieVehicul;

        Vehicul();
        Vehicul(T, T, pair< double, double >, StrategieVehicul);

        T GetMasaMaximaAdmisa() const;
        T GetVolumDisponibil() const;
        pair< double, double > GetPosition() const;
        bool CheckDisponibilitate() const;

        void SetPosition(const pair< double, double >&);
        void ChangeDisponibilitate();

        virtual void PrintData(std::ostream&) = 0;
        virtual double GetDistance(const pair< double, double > &) = 0;
        virtual T GetViteza() = 0;
        static Vehicul* GetVehicul(string, T, T, pair< double, double >, StrategieVehicul, string);

        virtual ~Vehicul() = default;
};

#endif