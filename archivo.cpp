#include <iostream>
using namespace std;
#include "funciones.h"

const int FILAS = 20;
const int COLUMNAS = 20;

void imprimirTablero(){
	int matriz[FILAS][COLUMNAS];
	cout << matriz << endl;
}

void cargarMatriz(char **matriz){
	char caracter = '-';
	for(int i = 0; i < COLUMNAS; i++){
		for (int j = 0; j < FILAS; j++){
			matriz[i][j] = caracter;
		}
	}
}

void imprimirMatriz(char **matriz){
	for(int i = 0; i < COLUMNAS; i++){
		for (int j = 0; j < FILAS; j++){
			cout << matriz[i][j];
		}
		cout << endl;
	}
}

int preguntarFila(){
	int fila;
	cout<< "Fila" << endl;
	cin >> fila;
	
	return fila;
}

int preguntarColumna(){
	int columna;
	cout<< "Columna" << endl;
	cin >> columna;
	
	return columna;
}

int preguntarTesoro(){
	int tesoro;
	cout<< "Numero de Tesoro" << endl;
	cin >> tesoro;
	
	return tesoro;
}

void esconderTesoro(char **matriz, int fila, int columna){
	char tesoro = 'T';
	matriz[fila][columna] = tesoro;
}

void vaciarCasilla(char **matriz, int fila, int columna){
	char vacio = '-';
	matriz[fila][columna] = vacio;
}

bool encontrarEspia(char **matriz, int fila, int columna){
	bool respuesta = false;
	if (matriz[fila][columna] == 'E'){
		respuesta = true;
	}
	return respuesta;
}

bool encontrarTesoro(char **matriz, int fila, int columna){
	bool respuesta = false;
	if (matriz[fila][columna] == 'T'){
		respuesta = true;
	}
	return respuesta;
}

void colocarEspiaMatriz(char **matriz, int fila, int columna){
	char espia = 'E';
	matriz[fila][columna] = espia;
}

bool validarMoverTesoro(){
	bool valido = false;
	char afirmativo = 's';
	char respuesta;
	cout<< "¿Quiere mover un Tesoro? (s/n)" << endl;
	cin >> respuesta;
	if (respuesta == afirmativo){
		valido = true;
	}
	return valido;
}

int enumerarJugador(int turno){
	int jugador;
	if (turno % 2 != 0){
		jugador = 1;
	} else{
		jugador = 2;
	}
	return jugador;
}

int asignarTesoro(int jugador){
	bool valido = false;
	int tesoro;
	while(valido == false){
		tesoro = preguntarTesoro();
		if(validarTesoro(jugador, tesoro)){
			valido = true;
		}
	}
	return tesoro;
}

void crearMatriz(char **matriz){
	for(int i = 0; i < 20; i++){
		matriz[i] = new char[20];
	}
}

void borrarMatriz(char **matriz){
	for(int i = 0; i < FILAS; i++){
		delete [] matriz[i];
	}
	delete [] matriz;
}