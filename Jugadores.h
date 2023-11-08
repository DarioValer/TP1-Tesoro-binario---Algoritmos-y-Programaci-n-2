#ifndef JUGADORES_INCLUDED
#define JUGADORES_INCLUDED

typedef struct Jugadores {
	int * filasTesoros;
	int * columnasTesoros;
	int * filasEspias;
	int * columnasEspias;
	int tesoros;
	Jugadores(): filasTesoros(new int[4]), columnasTesoros(new int[4]), filasEspias(new int[200]), columnasEspias(new int[200]), tesoros(4) {}
}jugador1, jugador2;
#endif // JUGADORES_INCLUDED
