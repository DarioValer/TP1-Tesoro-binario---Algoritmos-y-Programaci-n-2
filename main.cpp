#include <iostream>
#include "funciones.h"
using namespace std;
const int FILAS = 20;
const int TESOROS = 4;

int main(){
	char** matriz1 = new char *[FILAS];
	char** matriz2 = new char *[FILAS];
    crearMatriz(matriz1);
    crearMatriz(matriz2);
	cargarMatriz(matriz1);
	cargarMatriz(matriz2);
    int turno = 1;
	while(J1.tesoros != 0 && J2.tesoros != 0){
		int jugador = enumerarJugador(turno);
		if (jugador == 1){
			cout << "Turno Jugador 1"<< endl;
			imprimirMatriz(matriz1);
			if(turno == 1){
				//guardar tesoros
				for(int i = 0; i < TESOROS; i++){
					int tesoro = i +1;
					moverTesoro(matriz1, matriz2, jugador, tesoro);	
				} 
				//colocar 1er espía
				cout << "Ingrese donde quiere colocar su primer Espia" << endl;
				colocarEspia(matriz1, matriz2, turno, jugador);
			} else{
				//colocar espia
				cout << "Ingrese donde quiere colocar el Espia" << endl;
				colocarEspia(matriz1, matriz2, turno, jugador);
				//MOVER TESORO
				bool quiereMoverTesoro = validarMoverTesoro();
				if(quiereMoverTesoro){
					cout << "Ingrese el numero del Tesoro a mover" << endl;
					imprimirTesoros(jugador);
					int tesoro = asignarTesoro(jugador);
					vaciarCasilla(matriz1, J1.filasTesoros[tesoro -1], J1.columnasTesoros[tesoro -1]);
					moverTesoro(matriz1, matriz2, jugador, tesoro);
				}
			}
			cout << "Actual 1" << endl;
			imprimirMatriz(matriz1);
			turno++;
		} else{
			cout << "Turno Jugador 2"<< endl;
			imprimirMatriz(matriz2);
			if(turno == 2){
				//guardar tesoros
				for(int i = 0; i < TESOROS; i++){
					int tesoro = i +1;
					moverTesoro(matriz2, matriz1, jugador, tesoro);	
				}
				//colocar 1er espia
				cout << "Ingrese donde quiere colocar su primer Espia" << endl;
				colocarEspia(matriz2, matriz1, turno, jugador);
			} else {
				//colocar espia
				cout << "Ingrese donde quiere colocar el Espia" << endl;
				colocarEspia(matriz2, matriz1, turno, jugador);
				//mover tesoro
				bool quiereMoverTesoro = validarMoverTesoro();
				if(quiereMoverTesoro){
					cout << "Ingrese el numero del Tesoro a mover" << endl;
					imprimirTesoros(jugador);
					int tesoro = asignarTesoro(jugador);
					vaciarCasilla(matriz2, J2.filasTesoros[tesoro -1], J2.columnasTesoros[tesoro -1]);
					moverTesoro(matriz2, matriz1, jugador, tesoro);	
				}
			}
			cout << "Actual 2" << endl;
			imprimirMatriz(matriz2);
			turno++;
		}
		descontarTurnoDeshabilitado(matriz1, matriz2);
	}
	mostrarGanador();
	ejecutarDeletesJugadores();
	ejecutarDeletesCasillas();
    borrarMatriz(matriz1);
    borrarMatriz(matriz2);
	return 0;
}