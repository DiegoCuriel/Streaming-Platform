#include "Video.h"
#include <iostream>

using namespace std;

Video::Video()
{
    this->id = 0;
    this->nombre = "No data";
    this->genero = "No data";
    this->calificacion = 0;
}

Video::Video(int id, string nombre, string genero, double calificacion)
{
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
    this->calificacion = calificacion;
}

int Video::getId()
{
    return this->id;
}

string Video::getNombre()
{
    return this->nombre;
}

string Video::getGenero()
{
    return this->genero;
}

double Video::getCalificacion()
{
    return this->calificacion;
}

void Video::setId(int id)
{
    this->id = id;
}

void Video::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Video::setGenero(string genero)
{
    this->genero = genero;
}

void Video::setCalificacion(double calificacion)
{
    this->calificacion = (this->calificacion + calificacion)/2;
}

double Video::getDuracion(){
    return 0;
}

void Video::imprime() //Imprime todos los atributos del video
{
    cout << "------------------------------------\n";
    cout << "Id: " << this->id << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Genero: " << this->genero << endl;
    cout << "Calificacion: " << this->calificacion << endl;
}