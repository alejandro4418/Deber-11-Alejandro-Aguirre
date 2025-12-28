#include<iostream>
#include<string>
using namespace std;

int contarPalabras(string cadena){
	int palabras = 0;
	cadena+=" ";
	for (int i=0; i<cadena.length(); i++){
		if (cadena[i]!= ' ' && cadena[i+1] == ' '){
			palabras++;
		}
	}
	return palabras;
}

int main(){
	string cadena;
	cout<<"Ingrese una cadena de texto: ";
	getline(cin, cadena);
	int total = contarPalabras(cadena);
	cout<<"El total de palabras es: "<<total<<endl;
	
	
	return 0;
}
