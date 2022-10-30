#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

class Pelicula:public Video
{
    private:
        double duracion;

    public:
        Pelicula();
        Pelicula(int, string, string, double, double);

        double getDuracion() override;
        void setDuracion(double);

        void imprime() override;
};

#endif