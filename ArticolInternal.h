#ifndef __ARTICOLINTERNAL_H_INCLUDED__
#define __ARTICOLINTERNAL_H_INCLUDED__

#include <bits/stdc++.h>

template< class T >
class Articol {
    private:
        T m_masa;
        T m_volum;
        bool m_necesitaFrigorifica;
    public:
        Articol();

        T GetMasa() const;
        T GetVolum() const;
        bool NecesitaFrigorifica() const;
        void PrintData();

        template< class U > friend std::istream& operator>>(std::istream&, Articol< U >&);

}; 

#endif