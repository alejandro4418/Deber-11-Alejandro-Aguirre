#include<iostream>
#include<cstdlib> 
#include<ctime>
using namespace std;

void inicializarTablero(char tablero[6][6]){
	for (int i=0; i<6; i++){
		for (int j=0; j<6; j++){
			tablero[i][j] = '~';
		}
	}
	srand(time(0));
	int filaBarco = rand() % 6;
	int columnaInicio = rand() % 4;
    tablero[filaBarco][columnaInicio] = 'B';
    tablero[filaBarco][columnaInicio + 1] = 'B';
    tablero[filaBarco][columnaInicio + 2] = 'B';
    cout<<"Barco colocado en una posicion al azar\n";
}

void mostrarTablero(const char tablero[6][6]){
	cout<<"\nTablero actual\n";
	for (int i=0; i<6; i++){
		for (int j=0; j<6; j++){
			if (tablero[i][j] == 'B'){
				cout<<"~ ";
			} else {
				cout<<tablero[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

void disparar(char tablero[6][6], int fila, int columna){
	fila--;
	columna--;
	if (tablero[fila][columna] == 'B'){
		tablero[fila][columna] = 'X';
		cout<<"Barco golpeado"<<endl;
	} else if (tablero[fila][columna] == '~'){
		tablero[fila][columna] = 'O';
		cout<<"Solo es agua"<<endl;
	} else {
		cout<<"Ya disparaste aqui"<<endl;
	}
}

bool hundido(const char tablero[6][6]){
	for (int i=0; i<6; i++){
		for (int j=0; j<4; j++){
			if (tablero[i][j] == 'X' && tablero[i][j+1] == 'X' && tablero[i][j+2] == 'X'){
				return true;
			}
		}
	}
	return false;
}

int main(){
	char tablero[6][6];
	inicializarTablero(tablero);
	cout<<"\nBatalla Naval\n";
	mostrarTablero(tablero);
	while (true){
		int fila, columna;
		cout<<"Ingrese coordenadas para disparar: "<<endl;
		cout<<"Fila (1-6): ";
		cin>>fila;
		cout<<"Columna (1-6): ";
		cin>>columna;
		if (fila<1 || fila>6 || columna<1 || columna>6){
			cout<<"Coordenadas invalidas."<<endl;
			continue;
		}
		disparar(tablero, fila, columna);
		mostrarTablero(tablero);
		if (hundido(tablero)){
			cout<<"\nBarco Hundido\n";
			break;
		}
	}
	
	return 0;
}

