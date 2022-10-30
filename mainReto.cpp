#include <iostream>
#include "Catalogo.h"
#include <conio.h> 

using namespace std;

int main(){
    Catalogo Netflix; //Crea catalogo
    Netflix.cargaDatos();

    bool continua = true;
    int opn = 4;

    int menu_lvl = 0;

    while (continua){ //Loop de continous
        system("cls");

        if(menu_lvl==0){
            switch(opn){ //Cambia de estado el menu
                case 0:
                    cout << "|+| Bienvenido a Netflix |+|\n\n";
                    cout << "Que es lo que quisiera hacer?\n";
                    cout << "1. Mostrar videos\n";
                    cout << "2. Mostrar los episodios de una serie\n";
                    cout << "3. Mostrar peliculas\n";
                    cout << "4. Calificar un titulo\n";
                    cout << "0. Salir <-" << endl;
                    break;
                case 1:
                    cout << "|+| Bienvenido a Netflix |+|\n\n";
                    cout << "Que es lo que quisiera hacer?\n";
                    cout << "1. Mostrar videos\n";
                    cout << "2. Mostrar los episodios de una serie\n";
                    cout << "3. Mostrar peliculas\n";
                    cout << "4. Calificar un titulo <-\n";
                    cout << "0. Salir" << endl;
                    break;
                case 2:
                    cout << "|+| Bienvenido a Netflix |+|\n\n";
                    cout << "Que es lo que quisiera hacer?\n";
                    cout << "1. Mostrar videos\n";
                    cout << "2. Mostrar los episodios de una serie\n";
                    cout << "3. Mostrar peliculas <-\n";
                    cout << "4. Calificar un titulo\n";
                    cout << "0. Salir" << endl;
                    break;
                case 3:
                    cout << "|+| Bienvenido a Netflix |+|\n\n";
                    cout << "Que es lo que quisiera hacer?\n";
                    cout << "1. Mostrar videos\n";
                    cout << "2. Mostrar los episodios de una serie <-\n";
                    cout << "3. Mostrar peliculas\n";
                    cout << "4. Calificar un titulo\n";
                    cout << "0. Salir" << endl;
                    break;
                case 4:
                    cout << "|+| Bienvenido a Netflix |+|\n\n";
                    cout << "Que es lo que quisiera hacer?\n";
                    cout << "1. Mostrar videos <-\n";
                    cout << "2. Mostrar los episodios de una serie\n";
                    cout << "3. Mostrar peliculas\n";
                    cout << "4. Calificar un titulo\n";
                    cout << "0. Salir" << endl;
                    break;
            }

            char desicion = getch();

            switch (desicion) //Lectura del teclado
            {
            case 'w':
                opn++;
                if (opn>=5) opn = 0;
                break;
            case 's':
                opn--;
                if (opn<0) opn = 4;
                break;
            case 'e':
                menu_lvl++;
                break;
            default:
                break;
            }
            continue;
        }

        if(menu_lvl == 1){ //Segunda capa del menu

            int opn2 = 0;
            char desicion2;
            bool continua2 = true;

            string nom;

            switch(opn){ //Alternacion de opciones
                case 0:
                    continua = false;
                    break;
                case 1:
                    cout << "|+| CALIFICAR TITULO |+|\n\n";
                    cout << "Ingrese el titulo que desea calificar:\n";
                    cout << ">> ";

                    getline(cin, nom);

                    cout << endl;

                    Netflix.calificarTitulo(nom);

                    opn2 = 1;

                    while(continua2){ //Verificacion de salida
                        system("cls");
                        switch(opn2){
                            case 0:
                                cout << "Que desea hacer?\n";
                                cout << "1. Calificar otro titulo\n";
                                cout << "2. Regresar al menu principal <-\n";
                                break;
                            case 1:
                                cout << "Que desea hacer?\n";
                                cout << "1. Calificar otro titulo <-\n";
                                cout << "2. Regresar al menu principal\n";
                                break;
                            default:
                                break;
                        }

                        desicion2 = getch(); //Lectura de teclado

                        switch (desicion2){
                            case 'w':
                                opn2++;
                                if (opn2>=2) opn2 = 0;
                                break;
                            case 's':
                                opn2--;
                                if (opn2<0) opn2 = 1;
                                break;
                            case 'e':
                                continua2 = false;
                                break;
                            default:
                                break;
                        }
                    }

                    if (opn2 == 0) menu_lvl = 0; //Restablecimiento de la capa 1

                    break;
                case 2:

                    opn2 = 3;

                    while(continua2){
                        system("cls");
                        switch(opn2){ //Estados del menu
                            case 0:
                                cout << "|+| MOSTRAR PELICULAS |+|\n\n";
                                cout << "Como desea filtrar las peliculas?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Menu principal <-\n";
                                break;
                            case 1:
                                cout << "|+| MOSTRAR PELICULAS |+|\n\n";
                                cout << "Como desea filtrar las peliculas?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima <-\n";
                                cout << "4. Menu principal\n";
                                break;
                            case 2:
                                cout << "|+| MOSTRAR PELICULAS |+|\n\n";
                                cout << "Como desea filtrar las peliculas?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima <-\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Menu principal\n";
                                break;
                            case 3:
                                cout << "|+| MOSTRAR PELICULAS |+|\n\n";
                                cout << "Como desea filtrar las peliculas?\n";
                                cout << "1. Sin filtro <-\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Menu principal\n";
                                break;
                            default:
                                break;
                        }

                        desicion2 = getch(); //Lectura del teclado

                        switch (desicion2){
                            case 'w':
                                opn2++;
                                if (opn2>=4) opn2 = 0;
                                break;
                            case 's':
                                opn2--;
                                if (opn2<0) opn2 = 3;
                                break;
                            case 'e':
                                continua2 = false;
                                break;
                            default:
                                break;
                        }
                    }

                    if (Netflix.imprimePeliculas(opn2)) menu_lvl = 0; //Ejecucion de subproceso catalogo

                    break;
                case 3:
                
                    opn2 = 3;

                    while(continua2){
                        system("cls");
                        switch(opn2){ //Alternacion de estados del menu
                            case 0:
                                cout << "|+| MOSTRAR EPISODIOS |+|\n\n";
                                cout << "Como desea filtrar las series?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Menu principal <-\n";
                                break;
                            case 1:
                                cout << "|+| MOSTRAR EPISODIOS |+|\n\n";
                                cout << "Como desea filtrar las series?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima <-\n";
                                cout << "4. Menu principal\n";
                                break;
                            case 2:
                                cout << "|+| MOSTRAR EPISODIOS |+|\n\n";
                                cout << "Como desea filtrar las series?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima <-\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Menu principal\n";
                                break;
                            case 3:
                                cout << "|+| MOSTRAR EPISODIOS |+|\n\n";
                                cout << "Como desea filtrar las series?\n";
                                cout << "1. Sin filtro <-\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Menu principal\n";
                                break;
                            default:
                                break;
                        }

                        desicion2 = getch(); //Lectura del teclado

                        switch (desicion2){
                            case 'w':
                                opn2++;
                                if (opn2>=4) opn2 = 0;
                                break;
                            case 's':
                                opn2--;
                                if (opn2<0) opn2 = 3;
                                break;
                            case 'e':
                                continua2 = false;
                                break;
                            default:
                                break;
                        }
                    }

                    if (Netflix.imprimeSeries(opn2)) menu_lvl = 0; //Ejecucion de metodo de catalogo

                    break;
                case 4:
                
                    opn2 = 4;

                    while(continua2){
                        system("cls");
                        switch(opn2){ //Cambio de estados del menu
                            case 0:
                                cout << "|+| MOSTRAR TITULOS |+|\n\n";
                                cout << "Como desea filtrar los titulos?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Por genero\n";
                                cout << "5. Menu principal <-\n";
                                break;
                            case 1:
                                cout << "|+| MOSTRAR TITULOS |+|\n\n";
                                cout << "Como desea filtrar los titulos?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Por genero <-\n";
                                cout << "5. Menu principal\n";
                                break;
                            case 2:
                                cout << "|+| MOSTRAR TITULOS |+|\n\n";
                                cout << "Como desea filtrar los titulos?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima <-\n";
                                cout << "4. Por genero\n";
                                cout << "5. Menu principal\n";
                                break;
                            case 3:
                                cout << "|+| MOSTRAR TITULOS |+|\n\n";
                                cout << "Como desea filtrar los titulos?\n";
                                cout << "1. Sin filtro\n";
                                cout << "2. Por calificacion minima <-\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Por genero\n";
                                cout << "5. Menu principal\n";
                                break;
                            case 4:
                                cout << "|+| MOSTRAR TITULOS |+|\n\n";
                                cout << "Como desea filtrar los titulos?\n";
                                cout << "1. Sin filtro <-\n";
                                cout << "2. Por calificacion minima\n";
                                cout << "3. Por duracion maxima\n";
                                cout << "4. Por genero\n";
                                cout << "5. Menu principal\n";
                                break;
                            default:
                                break;
                        }

                        desicion2 = getch(); //Lectura de teclado

                        switch (desicion2){
                            case 'w':
                                opn2++;
                                if (opn2>=5) opn2 = 0;
                                break;
                            case 's':
                                opn2--;
                                if (opn2<0) opn2 = 4;
                                break;
                            case 'e':
                                continua2 = false;
                                break;
                            default:
                                break;
                        }
                    }

                    if (Netflix.imprimeVideos(opn2)) menu_lvl = 0; //Ejecucion de metodo de catalogo

                    break;
                default:
                    break;
            }
        }
    }
    
    Netflix.guardaDatos(); //Guardar datos

}