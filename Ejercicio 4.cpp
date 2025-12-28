#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct PosionMagica{
	string nombre;
	vector<string> ingredientes;
	int tiempoPreparacion;
	string efectoMagico;
};

void buscarPorIngrediente(const vector<PosionMagica>& pociones, const string& ingredienteBuscado){
	cout << "\nPociones que usan '" << ingredienteBuscado << "'\n";
    bool encontrada = false;
    for (const PosionMagica& pocion : pociones) {
        for (const string& ingrediente : pocion.ingredientes) {
            if (ingrediente == ingredienteBuscado) {
                cout << "- " << pocion.nombre << endl;
                encontrada = true;
                break;
            }
        }
    }
    if (!encontrada) {
        cout << "(No se encontraron pociones con ese ingrediente)\n";
    }
    cout << endl;
}


int main(){
	vector<PosionMagica> posiones;
	PosionMagica pocion1;
	pocion1.nombre = "Pocion de Curacion";
	pocion1.ingredientes = {"Agua embotellada","Sandia luminosa","Polvo de glowstone"};
	pocion1.tiempoPreparacion = 14;
	pocion1.efectoMagico = "Restaura instantaneamente la salud";
	posiones.push_back(pocion1);
	
	PosionMagica pocion2;
	pocion2.nombre = "Pocion de Fuerza";
	pocion2.ingredientes = {"Agua embotellada","Polvo de blaze","Polvo de glowstone"};
	pocion2.tiempoPreparacion = 56;
	pocion2.efectoMagico = "Aumenta el daño cuerpo a cuerpo en un 130%";
	posiones.push_back(pocion2);
	
	PosionMagica pocion3;
	pocion3.nombre = "Pocion de Invisibilidad";
	pocion3.ingredientes = {"Pocion de vision nocturna","Ojo de araña fermentado", "Sandia luminosa"};
	pocion3.tiempoPreparacion = 128;
	pocion3.efectoMagico = "Hace al usuario completamente transparente";
	posiones.push_back(pocion3);
	
	string ingredienteBuscado;
	cout<<"Ingresa un ingrediente para buscar: ";
	getline(cin, ingredienteBuscado);
	buscarPorIngrediente(posiones, ingredienteBuscado);
	
	return 0;
}
