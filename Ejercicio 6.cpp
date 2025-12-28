#include<iostream>
#include<string>
#include<vector>
using namespace std;

void separarExpresion(string expresion){
	string numeros = "";
	string operadores = "";
	string otros = "";
	size_t posicion = 0;
	while (posicion < expresion.length()){
		if (expresion[posicion] >= '0' && expresion[posicion] <= '9'){
			size_t inicio = posicion;
			while (posicion<expresion.length() && expresion[posicion] >= '0' && expresion[posicion]<='9'){
				posicion++;
				
			}
			string numero = expresion.substr(inicio, posicion - inicio);
			if (!numeros.empty()){
				numeros += ", ";
			}
			numeros += numero;
			continue;
		} else if (expresion.find_first_of("+-*/=", posicion) == posicion){
			if (!operadores.empty()){
				operadores += ", ";
			}
			operadores += expresion[posicion];
			posicion++;
			continue;
		} else if (expresion.find_first_of("()[]{}", posicion) == posicion){
			if (!otros.empty()){
				otros += ", ";
			}
			otros += expresion[posicion];
			posicion++;
			continue;
		}
		posicion++;
	}
	cout<<"\nNumeros: "<<(numeros.empty() ? "(ninguno)" : numeros)<<endl;
	cout<<"Operadores: "<<(operadores.empty() ? "(ninguno)" : operadores)<<endl;
	cout<<"Otros: "<<(otros.empty() ? "(ninguno)" : otros)<<endl;
}

int main(){
	string expresion;
	cout<<"Ingrese una operacion matematica: ";
	getline(cin, expresion);
	cout<<"\nOperacion: "<<expresion<<endl;
	separarExpresion(expresion);
	
	
	return 0;
}
