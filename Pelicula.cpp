#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula():Video()
{
    this->duracion = 0;
}

Pelicula::Pelicula(int id, string nombre, string genero, double calificacion, double duracion):Video(id, nombre, genero, calificacion)
{
    this->duracion = duracion;
}

double Pelicula::getDuracion()
{
    return this->duracion;
}

void Pelicula::setDuracion(double duracion)
{
    this->duracion = duracion;
}

void Pelicula::imprime()
{
    Video::imprime();
    cout << "Duracion: " << this->duracion << endl;
}