#include "Serie.h"
#include <iostream>

using namespace std;

Serie::Serie(){
    listaEpisodios.clear();
}

Serie::Serie(int id, string nombre, string genero, double calificacion):Video(id, nombre, genero, calificacion){

}

Episodio Serie::getEpisodio(int i){
    if (listaEpisodios.size() > 0 && i < listaEpisodios.size()){ //Verificamos el indice para evitar error
        return listaEpisodios[i];
    }
    throw std::invalid_argument("Indice fuera de rango"); //Arrojar error
}

double Serie::getDuracion(){
    float acum = 0;
    for (auto ep:listaEpisodios){
        acum += ep.getDuracion();
    }
    return acum;
}

vector <Episodio> Serie::getEpisodios(){
    return listaEpisodios;
}

void Serie::addEpisodio(Episodio nuevo_ep){
    listaEpisodios.push_back(nuevo_ep);
}

void Serie::imprime(){ //Imprime todos los episodios junto con sus duraciones
    Video::imprime();
    cout << "Duracion total de la serie: " << Serie::getDuracion() << " horas\n";
    cout << "---\nLista de episodios:\n";
    for (auto ep:listaEpisodios){
        cout << "Episodio " << ep.getId() << ":" << endl;
        ep.imprime();
    }
}