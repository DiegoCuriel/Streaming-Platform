#include "Catalogo.h"
#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//--------------------------

void Catalogo::cargaDatos(){ //Guarda en un arreglo los datos del .txt

    bool is_serie = false;
    int cont = 0;
    int cont_s = 0;
    //Contadores de indice

    char tipo_video;
    vector <Episodio> lista_ep;
    Serie *serie_temp = new Serie;
    //Variables globales

    ifstream archivo;
    archivo.open("Catalogo.txt");
    //Archivo de texto

    if(archivo.is_open()){
        while (archivo >> tipo_video){
            if(tipo_video == 'p'){ //Verifica la apertura y comienza el flujo
                
                cont++;

                string tit, gen;
                double cal, dur;
                archivo >> tit >> gen >> cal >> dur;

                for (int i=0; i<tit.length(); i++){ //Quitar guiones bajos
                    if(tit[i] == '_'){
                        tit.replace(i,1," ");
                    }
                }
                
                lista_videos.push_back(new Pelicula(cont, tit, gen, cal, dur)); //Agregar la pelicula
            } 
            else if(tipo_video == 's'){ //Ahora aplica para serie

                cont++;

                is_serie = true;

                string tit, gen;
                double cal;
                archivo >> tit >> gen >> cal;

                for (int i=0; i<tit.length(); i++){ //Quitar guiones bajos
                    if(tit[i] == '_'){
                        tit.replace(i,1," ");
                    }
                }

                Serie *s = new Serie(cont, tit, gen, cal); //Crear puntero de serie
                serie_temp = s;

            }
            else if(is_serie){ //Consecuencia de bandera
                if(tipo_video == '+'){
                    is_serie = false;
                    lista_videos.push_back(serie_temp);
                    Serie *def = new Serie;
                    serie_temp = def;
                    cont_s = 0;
                    continue; //Actualizacion del puntero, añadir serie
                }

                cont_s++;
                string tit;
                int temp;
                double dur; 

                archivo >> tit >> temp >> dur;

                for (int i=0; i<tit.length(); i++){ //Quitar guiones bajos
                    if(tit[i] == '_'){
                        tit.replace(i,1," ");
                    }
                }

                Episodio nuev_ep(cont_s, tit, temp, dur);

                serie_temp->addEpisodio(nuev_ep);

            }
        }
        archivo.close();
    }
}

void Catalogo::guardaDatos(){ //Guarda los datos en el .txt
    ofstream archivo;
    archivo.open("Catalogo.txt", fstream::out);

    if(archivo.is_open()){ //Archivo de texto

        for(auto v:lista_videos){
            
            string linea;

            if (Pelicula* ptrPel = dynamic_cast<Pelicula*>(v)){ //Dynamic cast para identificar el tipo de video
                
                string tit = ptrPel->getNombre();
                string gen = ptrPel->getGenero();
                double cal = ptrPel->getCalificacion();
                double dur = ptrPel->getDuracion();

                for (int i=0; i<tit.length(); i++){
                    if(tit[i] == ' '){
                        tit.replace(i,1,"_");
                    }
                }

                linea += "p ";
                linea += tit + " ";
                linea += gen + " ";
                linea += to_string(cal) + " ";
                linea += to_string(dur);

                archivo << linea << endl; //Concatenacion de strings y sobrescritura

                continue;
            }

            if (Serie* ptrSer = dynamic_cast<Serie*>(v)){ //Dynamic cast para identificar el tipo de video
                
                string tit = ptrSer->getNombre();
                string gen = ptrSer->getGenero();
                double cal = ptrSer->getCalificacion();

                for (int i=0; i<tit.length(); i++){
                    if(tit[i] == ' '){
                        tit.replace(i,1,"_");
                    }
                }

                linea += "s ";
                linea += tit + " ";
                linea += gen + " ";
                linea += to_string(cal);

                archivo << linea << endl; //Concatenacion de strings y sobrescritura

                for (auto e:ptrSer->getEpisodios()){ //Recorre todos los episodios

                    string tit = e.getTitulo();

                    for (int i=0; i<tit.length(); i++){ //Añade guiones bajos
                    if(tit[i] == ' '){
                        tit.replace(i,1,"_");
                        }
                    }

                    linea = "- ";
                    linea += tit + " ";
                    linea += to_string(e.getTemporada()) + " ";
                    linea += to_string(e.getDuracion());

                    archivo << linea << endl; //Concatenacion de strings y sobrescritura
                }

                archivo << "+" << endl;

                continue;
            }
        }
    }
}

void Catalogo::buscarPorGenero(string genero_b){ //Buscar por genero
    for (auto v:lista_videos){
        string genero = v->getGenero();

        if (genero_b == genero){
            v->imprime();
        }
    }
}

void Catalogo::buscarPorCalMayorA(double filtro){ //Buscar por calificacion mayor a la introducida
    for (auto v:lista_videos){
        double cal = v->getCalificacion();

        if (cal>filtro){
            v->imprime();
        }
    }
}

void Catalogo::buscarPorDurMenorA(double dur_max){ //Buscar por duracion menor a la introducida
    for (auto v:lista_videos){
        double dur = v->getDuracion();

        if(dur<dur_max){
            v->imprime();
        }
    }
}

bool Catalogo::calificarTitulo(string tit){ //Califica el titulo introducido, promedia la nueva calificacion
    for (auto &v:lista_videos){ //Recorre toda la lista de videos
        for (auto &c:tit){
            c = tolower(c);
        }

        string eval = v->getNombre(); //Se asegura de que el string se encuentre en minusculas
        for (auto &c:eval){
            c = tolower(c);
        }

        if (tit==eval){ //Califica el titulo ingresado al encontrarlo
            cout << "Ingrese la calificacion:\n";
            cout << ">> ";

            double n_cal;
            cin >> n_cal;

            v->setCalificacion(n_cal); //Usar metodo para asignar nueva calificacion

            system("cls");
            cout << "Titulo actualizado:\n";
            v->imprime();

            cin.ignore();
            cout << "\nPresione enter para continuar...";
            cin.get();

            return true;
        }
    }
    
    system("cls");

    cout << "\nPresione enter para continuar...";
    cin.get();

    return false;
}

bool Catalogo::imprimePeliculas(int opn){ //Imprime las peliculas a pantalla
    system("cls");

    //Aqui va a entrar al menu de filtros para la impresion
    if (opn == 0) return true; 
    if (opn == 1){
        double dur_max;

        cout << "Ingresa la duracion maxima:\n";
        cout << ">> ";
        cin >> dur_max;

        system("cls");
        cout << "Desplegando peliculas.";
        Sleep(500);
        system("cls");
        cout << "Desplegando peliculas..";
        Sleep(500);
        system("cls");
        cout << "Desplegando peliculas..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de duracion
            if (Pelicula* ptrPels = dynamic_cast<Pelicula*>(v)){
                if (ptrPels->getDuracion()<dur_max) ptrPels->imprime();
            }
        }
        
        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 2){
        double cal_min;

        cout << "Ingresa la calificacion minima:\n";
        cout << ">> ";
        cin >> cal_min;

        system("cls");
        cout << "Desplegando peliculas.";
        Sleep(500);
        system("cls");
        cout << "Desplegando peliculas..";
        Sleep(500);
        system("cls");
        cout << "Desplegando peliculas..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de calificacion
            if (Pelicula* ptrPels = dynamic_cast<Pelicula*>(v)){
                if (ptrPels->getCalificacion()>cal_min) ptrPels->imprime();
            }
        }

        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 3){
        system("cls");
        cout << "Desplegando peliculas.";
        Sleep(500);
        system("cls");
        cout << "Desplegando peliculas..";
        Sleep(500);
        system("cls");
        cout << "Desplegando peliculas..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime todo
            if (Pelicula* ptrPels = dynamic_cast<Pelicula*>(v)){
                ptrPels->imprime();
            }
        }
        
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    return false;
}

bool Catalogo::imprimeSeries(int opn){
    system("cls");

    //Aqui va a entrar al menu de filtros para la impresion
    if (opn == 0) return true;
    if (opn == 1){
        double dur_max;

        cout << "Ingresa la duracion maxima:\n";
        cout << ">> ";
        cin >> dur_max;

        system("cls");
        cout << "Desplegando series.";
        Sleep(500);
        system("cls");
        cout << "Desplegando series..";
        Sleep(500);
        system("cls");
        cout << "Desplegando series..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de duracion
            if (Serie* ptrSer = dynamic_cast<Serie*>(v)){
                if (ptrSer->getDuracion()<dur_max) ptrSer->imprime();
            }
        }
        
        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 2){
        double cal_min;

        cout << "Ingresa la calificacion minima:\n";
        cout << ">> ";
        cin >> cal_min;

        system("cls");
        cout << "Desplegando series.";
        Sleep(500);
        system("cls");
        cout << "Desplegando series..";
        Sleep(500);
        system("cls");
        cout << "Desplegando series..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de calificacion
            if (Serie* ptrSer = dynamic_cast<Serie*>(v)){
                if (ptrSer->getCalificacion()>cal_min) ptrSer->imprime();
            }
        }

        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 3){
        system("cls");
        cout << "Desplegando series.";
        Sleep(500);
        system("cls");
        cout << "Desplegando series..";
        Sleep(500);
        system("cls");
        cout << "Desplegando series..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime todo
            if (Serie* ptrSer = dynamic_cast<Serie*>(v)){
                ptrSer->imprime();
            }
        }
        
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    return false;
}

bool Catalogo::imprimeVideos(int opn){
    system("cls");

    //Aqui va a entrar al menu de filtros para la impresion
    if (opn == 0) return true;
    if (opn == 1){
        string gen_b;

        cout << "Ingresa el genero:\n";
        cout << ">> ";
        cin >> gen_b;

        for (auto &c:gen_b){
            c = tolower(c);
        }

        system("cls");
        cout << "Desplegando titulos.";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de genero
            string gen = v->getGenero();

            for (auto &c:gen){
            c = tolower(c);
            }

            if (gen == gen_b) v->imprime();
        }
        
        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 2){
        double dur_max;

        cout << "Ingresa la duracion maxima:\n";
        cout << ">> ";
        cin >> dur_max;

        system("cls");
        cout << "Desplegando titulos.";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de duracion
            if (v->getDuracion()<dur_max) v->imprime();
        }
        
        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 3){
        double cal_min;

        cout << "Ingresa la calificacion minima:\n";
        cout << ">> ";
        cin >> cal_min;

        system("cls");
        cout << "Desplegando titulos.";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime si se cumple el filtro de calificacion
            if (v->getCalificacion()>cal_min) v->imprime();
        }

        cin.ignore();
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    if (opn == 4){
        system("cls");
        cout << "Desplegando titulos.";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");
        cout << "Desplegando titulos..";
        Sleep(500);
        system("cls");

        for (auto v:lista_videos){ //Imprime todo
            v->imprime();
        }
        
        cout << "\n\nPresione enter para continuar...";
        cin.get();
        return false;
    }
    return false;
}

Video* Catalogo::getVideo(int id){ //Regresa el video
    return lista_videos[id];
}

void Catalogo::addVideo(Video *n_video){ //Agrega un nuevo video al vector
    if (Pelicula* ptrPel = dynamic_cast<Pelicula*>(n_video)){
        lista_videos.push_back(ptrPel);
        return;
    }
    if (Serie* ptrSer = dynamic_cast<Serie*>(n_video)){
        lista_videos.push_back(ptrSer);
        return;
    }

}

void Catalogo::imprime(){ //Imprime
    for (auto v:lista_videos){
        v->imprime();
        cout << endl;
    }
}