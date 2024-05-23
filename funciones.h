#ifndef FUNCIONES_INCLUDED
#define FUNCIONES_INCLUDED
#include "Jugadores.h"
#include "Casilla.h"

//Casillas
void deshabilitarCasilla(char **matriz1, char **matriz2, int fila, int columna);
void descontarTurnoDeshabilitado(char **matriz1, char **matriz2);
void ejecutarDeletesCasillas();
//Jugadores
bool validarTesoro(int jugador,int tesoro);
int determinarTesoro(int jugador, int fila, int columna);
void colocarEspia(char **matrizActual,char **matrizValidar, int turno, int jugador);
void imprimirTesoros(int jugador);
void moverTesoro(char ** matrizActual, char ** matrizComparar,int jugador, int tesoro);
void mostrarGanador();
void ejecutarDeletesJugadores();
//Archivo
//void imprimirTablero();
void cargarMatriz(char **matriz);
void imprimirMatriz(char **matriz);
int preguntarFila();
int preguntarColumna();
int preguntarTesoro();
void esconderTesoro(char **matriz, int fila, int columna);
void vaciarCasilla(char **matriz, int fila, int columna);
bool encontrarEspia(char **matriz, int fila, int columna);
bool encontrarTesoro(char **matriz, int fila, int columna);
void colocarEspiaMatriz(char **matriz, int fila, int columna);
bool validarMoverTesoro();
int enumerarJugador(int turno);
int asignarTesoro(int jugador);
void crearMatriz(char **matriz);
void borrarMatriz(char **matriz);
#endif // FUNCIONES_INCLUDED
