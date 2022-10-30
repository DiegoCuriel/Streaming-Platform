#ifndef CATALOGO_H
#define CATALOGO_H
#include "Serie.h"
#include "Pelicula.h"

using namespace std;

class Catalogo
{
    private:
        vector <Video*> lista_videos;

    public:
        void cargaDatos();
        void guardaDatos();

        void buscarPorGenero(string);
        void buscarPorCalMayorA(double);
        void buscarPorDurMenorA(double);
        bool calificarTitulo(string);
        bool imprimePeliculas(int);
        bool imprimeSeries(int);
        bool imprimeVideos(int);

        Video* getVideo(int);
        void addVideo(Video*);

        void imprime();
};

#endif