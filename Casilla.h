#ifndef CASILLAS_INCLUDED
#define CASILLAS_INCLUDED

typedef struct Casillas {
	int * filaDeshabilitada;
	int * columnaDeshabilitada;
	int * turnosDeshabilitados;
	int cantDeshabilitados;
	Casillas(): filaDeshabilitada(new int[8]), columnaDeshabilitada(new int[8]), turnosDeshabilitados(new int[8]), cantDeshabilitados(0) {}
}casilla;
#endif // CASILLA_INCLUDED
