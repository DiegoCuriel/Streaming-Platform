#include "Episodio.h"
#include <iostream>

using namespace std;

Episodio::Episodio()
{
    this->id = 0;
    this->titulo = "No data";
    this->temporada = 0;
    this->duracion = 0;
}

Episodio::Episodio(int id, string titulo, int temporada, double duracion)
{
    this->id = id;
    this->titulo = titulo;
    this->temporada = temporada;
    this->duracion = duracion;
}

int Episodio::getId()
{
    return this->id;
}

string Episodio::getTitulo()
{
    return this->titulo;
}

int Episodio::getTemporada()
{
    return this->temporada;
}

double Episodio::getDuracion()
{
    return this->duracion;
}

void Episodio::setId(int id)
{
    this->id = id;
}

void Episodio::setTitulo(string titulo)
{
    this->titulo = titulo;
}

void Episodio::setTemporada(int Temporada)
{
    this->temporada = temporada;
}

void Episodio::setDuracion(double duracion)
{
    this->duracion = duracion;
}

std::ostream &operator << (std::ostream & salida, const Episodio& miEp){ //Sobrecarga del metodo de salida para poder imprimir el episodio sin necesidad de un metodo
    salida << "- Episodio " << miEp.id << ":\nNombre: " << miEp.titulo << "\nTemporada: " << miEp.temporada << "\nDuracion: " << miEp.duracion << endl;
    return salida;
}

void Episodio::imprime() //Imprime los atributos del episodio
{
    cout << "Nombre: " << Episodio::getTitulo() << endl;
    cout << "Temporada: " << Episodio::getTemporada() << endl;
    cout << "Duracion: " << Episodio:: getDuracion() << endl;
}