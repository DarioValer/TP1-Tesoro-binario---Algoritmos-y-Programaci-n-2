#include <iostream>
using namespace std;
#include "funciones.h"
casilla cDeshabilitada;
const int TURNOS_DESHABILITADOS = 5;

void deshabilitarCasilla(char **matriz1, char **matriz2, int fila, int columna){
	char deshabilitado = 'X';
	matriz1[fila][columna] = deshabilitado;
	matriz2[fila][columna] = deshabilitado;
	cDeshabilitada.filaDeshabilitada[cDeshabilitada.cantDeshabilitados] = fila;
	cDeshabilitada.columnaDeshabilitada[cDeshabilitada.cantDeshabilitados] = columna;
	cDeshabilitada.turnosDeshabilitados[cDeshabilitada.cantDeshabilitados] = TURNOS_DESHABILITADOS;
	(cDeshabilitada.cantDeshabilitados)+=1;
}

void descontarTurnoDeshabilitado(char **matriz1, char **matriz2){
    for(int i = 0; i < cDeshabilitada.cantDeshabilitados ; i++){
			if(cDeshabilitada.turnosDeshabilitados[i] > 0){
				(cDeshabilitada.turnosDeshabilitados[i])-=1;
			} else {
				vaciarCasilla(matriz1, cDeshabilitada.filaDeshabilitada[i], cDeshabilitada.columnaDeshabilitada[i]);
				vaciarCasilla(matriz2, cDeshabilitada.filaDeshabilitada[i], cDeshabilitada.columnaDeshabilitada[i]);
			}
	}
}

void ejecutarDeletesCasillas(){
	delete[] cDeshabilitada.filaDeshabilitada;
	delete[] cDeshabilitada.columnaDeshabilitada;
	delete[] cDeshabilitada.turnosDeshabilitados;
}