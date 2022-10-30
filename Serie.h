#ifndef SERIE_H
#define SERIE_H
#include <iostream>
#include <string>
#include <vector>
#include "Pelicula.h"
#include "Episodio.h"

using namespace std;

class Serie:public Video
{
    private:
        vector <Episodio> listaEpisodios;

    public:
        Serie();
        Serie(int, string, string, double);

        Episodio getEpisodio(int);
        double getDuracion() override;
        vector<Episodio> getEpisodios();

        void addEpisodio(Episodio);
        void imprime() override;
};

#endif