#ifndef EPISODIO_H
#define EPISODIO_H
#include <iostream>
#include <string>

using namespace std;

class Episodio
{
    private:
        int id;
        string titulo;
        int temporada;
        double duracion;

    public:
        Episodio();
        Episodio(int, string, int, double);

        int getId();
        string getTitulo();
        int getTemporada();
        double getDuracion();

        void setId(int);
        void setTitulo(string);
        void setTemporada(int);
        void setDuracion(double);

        friend std::ostream& operator<< (std::ostream &, const Episodio&);
        void imprime();

};

#endif