#ifndef __FIRMAINCLUDED_H_INCLUDED__
#define __FIRMAINCLUDED_H_INCLUDED__

#include <bits/stdc++.h>

enum StrategieFirma {
    VA = 1, // vehiculul cel mai apropiat
    VR, // vehiculul cel mai rapid
    VI // vechiculul cel mai putin incarcat
};

template< class T > class Comanda;

template< class T >
class Firma {
    private:
        vector< Vehicul< T >* > m_vehicule;
        StrategieFirma m_strategie;
        // first = urmatorul moment de timp cand se elibereaza o masina
        // second = numarul de ordine al masinii ce trebuie deblocata
        priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > m_vehiculeBlocate;
    public:
        Firma();

        int getSize() const;
        StrategieFirma getStrategie() const;

        void AdaugaVehicul(Vehicul< T >*);
        T GetMasaMaxima() const;
        T GetVolumMaxim() const;
        int GetBestVehicle(Comanda< T >&, const int&, int&);
        void ElibereazaVehicul(const int&);
        void PrintDataVehicul(const int &);

        template< class U > friend istream& operator>> (istream&, Firma< U >&);
        template< class U > friend ostream& operator<< (ostream&, const Firma< U >&);

        ~Firma();
};

#endif