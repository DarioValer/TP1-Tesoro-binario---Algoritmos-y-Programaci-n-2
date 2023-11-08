#include <iostream>
using namespace std;
#include "funciones.h"
#include "archivo.cpp"
jugador1 J1;
jugador2 J2;
const int TESOROS = 4;

bool validarTesoro(int jugador,int tesoro){
	bool respuesta = false;
	if(jugador == 1){
		if(tesoro > J1.tesoros || tesoro < 1){
			cout << "Ingrese un número de Tesoro válido" << endl;
		} else {
			respuesta = true;
		}
	} else {
		if(tesoro > J2.tesoros || tesoro < 1){
			cout << "Ingrese un número de Tesoro válido" << endl;
		} else {
			respuesta = true;
		}
	}
	return respuesta;
}

int determinarTesoro(int jugador, int fila, int columna){
	int tesoro = 0;
	int i= 0;
	bool encontrado = false;
	if(jugador == 1){
		while( i < TESOROS && encontrado == false){
			if(J2.filasTesoros[i] == fila && J2.columnasTesoros[i] == columna){
				tesoro = i+1;
				encontrado = true;
			} else {
				i++;
			}
		}
	} else {
		while( i < TESOROS && encontrado == false){
			if(J1.filasTesoros[i] == fila && J1.columnasTesoros[i] == columna){
				tesoro = i+1;
				encontrado = true;
			} else {
				i++;
			}
		}
	}
	return tesoro;
}

void colocarEspia(char **matrizActual,char **matrizValidar, int turno, int jugador){
	bool validacion = false;
	char vacio = '-';
	char deshabilidada = 'X';
	while(validacion == false){
		int filaEspia = (preguntarFila())-1;
		int columnaEspia= (preguntarColumna())-1;
		if(jugador == 1){
			J1.filasEspias[turno - 1] = filaEspia;
			J1.columnasEspias[turno - 1] = columnaEspia;
		} else {
			J2.filasEspias[turno - 1] = filaEspia;
			J2.columnasEspias[turno - 1] = columnaEspia;
		}
		if(matrizActual[filaEspia][columnaEspia] == deshabilidada){
			cout << "La casilla seleccionada esta deshabilitada, ingrese una nueva" << endl;
		} else if(encontrarTesoro(matrizValidar, filaEspia, columnaEspia)){
			cout << "Encontraste un tesoro"<< endl;
			if (jugador == 1){
				J2.tesoros-=1;
				int tesoro = determinarTesoro(jugador, filaEspia, columnaEspia);
				cout << "Tesoro numero " << tesoro << endl;
				J2.filasTesoros[tesoro -1] = 999;
				cout <<"posicion fila nueva " << J2.filasTesoros[tesoro -1] << endl;
				J2.columnasTesoros[tesoro -1] = 999;
			} else {
				J1.tesoros-=1;
				int tesoro = determinarTesoro(jugador, filaEspia, columnaEspia);
				J1.filasTesoros[tesoro -1] = 999;
				J1.columnasTesoros[tesoro -1] = 999;
			}
			cout << "La casilla se deshabilita por los siguientes 5 turnos" << endl;
			deshabilitarCasilla(matrizActual, matrizValidar, filaEspia, columnaEspia);
			validacion = true;
		} else if (encontrarEspia(matrizValidar, filaEspia, columnaEspia)){
			cout << "Encontraste un espía enemigo" << endl;
			vaciarCasilla(matrizActual, filaEspia, columnaEspia);
			vaciarCasilla(matrizValidar, filaEspia, columnaEspia);
			validacion = true;
		} else if(matrizActual[filaEspia][columnaEspia] == vacio){
			colocarEspiaMatriz(matrizActual, filaEspia, columnaEspia);
			validacion = true;
		} else {
			cout << "No puedes colocar un espía porque ya tienes un espia o tesoro propio aqui"<< endl;
		}
	}
}

void imprimirTesoros(int jugador){
	if (jugador == 1){
		for(int i = 0; i < TESOROS; i++){
			if(J1.filasTesoros[i] != 999 && J1.columnasTesoros[i] != 999){
				cout << "Tesoro " << i +1 << " -Fila: " << (J1.filasTesoros[i])+1 << " -Columna: " << (J1.columnasTesoros[i])+1 << endl;
			}
		}
	} else {
		for(int i = 0; i < TESOROS; i++){
			if(J2.filasTesoros[i] != 999 && J2.columnasTesoros[i] != 999){
				cout << "Tesoro " << i +1 << " -Fila: " << (J2.filasTesoros[i])+1 << " -Columna: " << (J2.columnasTesoros[i])+1 << endl;
			}
		}
	}
}

void moverTesoro(char ** matrizActual, char ** matrizComparar,int jugador, int tesoro){
	bool valido = false;
	char deshabilitado = 'X';
	while(valido == false){
		cout << "Ingrese el lugar donde colocar el tesoro " << tesoro << endl;
		int fila =  preguntarFila()-1;
		int columna = preguntarColumna()-1;
		if (matrizActual[fila][columna] == deshabilitado){
			cout << "La casilla está deshabilitada" << endl;
		} else if(encontrarTesoro(matrizActual, fila, columna)){
			cout << "No puedes colocar dos Tesoros en una misma casilla" << endl;
		} else if(encontrarEspia(matrizActual, fila, columna)){
			cout << "no puedes colocar un Tesoro donde tienes un espía" << endl;
		} else if(encontrarTesoro(matrizComparar, fila, columna)){
			cout << "Hay un tesoro enemigo en esta casilla, elija otra fila y columna para el Tesoro y mande un espía" << endl;
		} else if(encontrarEspia(matrizComparar, fila, columna)){
			cout << "¡OH NO! Colocaste el tesoro donde hay un espía enemigo" << endl;
			cout << "¡Tu tesoro está siendo robado!" << endl;
			if (jugador == 1){
				J1.tesoros-=1;
				vaciarCasilla(matrizActual, J1.filasTesoros[tesoro-1], J1.columnasTesoros[tesoro-1]);
				J1.filasTesoros[tesoro -1] = 999;
				J1.columnasTesoros[tesoro -1] = 999;
			} else {
				J2.tesoros-=1;
				vaciarCasilla(matrizActual, J2.filasTesoros[tesoro-1], J2.columnasTesoros[tesoro-1]);
				J2.filasTesoros[tesoro -1] = 999;
				J2.columnasTesoros[tesoro -1] = 999;
			}
			cout << "La casilla se deshabilita por los siguientes 5 turnos" << endl;
			deshabilitarCasilla(matrizActual, matrizComparar, fila, columna);
			valido = true;
		} else {
			if (jugador == 1){
				J1.filasTesoros[tesoro -1] = fila;
				J1.columnasTesoros[tesoro -1] = columna;
				esconderTesoro(matrizActual, fila, columna);
					
			} else {
				J2.filasTesoros[tesoro -1] = fila;
				J2.columnasTesoros[tesoro -1] = columna;
				esconderTesoro(matrizActual, fila, columna);
			}
			valido = true;
		}
		
	}	
}

void mostrarGanador(){
	int ganador = 0;
	if (J1.tesoros == 0){
		ganador = 2;
	} else {
		ganador = 1;
	}
	cout << "GANA EL JUGADOR " << ganador << ", ¡FELICITACIONES!" << endl;
}

void ejecutarDeletesJugadores(){
	delete[] J1.filasTesoros;
	delete[] J1.columnasTesoros;
	delete[] J1.filasEspias;
	delete[] J1.columnasEspias;
	delete[] J2.filasTesoros;
	delete[] J2.columnasTesoros;
	delete[] J2.filasEspias;
	delete[] J2.columnasEspias;
}