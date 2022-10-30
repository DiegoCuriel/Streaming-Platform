#ifndef VIDEO_H  
#define VIDEO_H
#include <iostream>
#include <string>

using namespace std;

class Video
{
    private:
        int id;
        string nombre;
        string genero;
        double calificacion;

    public:
        Video();
        Video(int, string, string, double);

        int getId();
        string getNombre();
        string getGenero();
        double getCalificacion();
        void setId(int);
        void setNombre(string);
        void setGenero(string);
        void setCalificacion(double);

        virtual double getDuracion();

        virtual void imprime();
};

#endif