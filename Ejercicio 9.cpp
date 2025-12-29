#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Pelicula {
	int id;
	string titulo;
	string director;
	bool enCartelera;
};

bool ingresarEstadoCartelera(){
	int opcion;
	do {
		cout<<"Estado de cartelera\n";
		cout<<"1. En cartelera\n";
		cout<<"2. Fuera de cartelera\n";
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		if (opcion == 1){
			return true;
		} else if (opcion == 2){
			return false;
		} else {
			cout<<"Opcion invalida. Intente nuevamente"<<endl;
		}
	} while (true);
}

void registrarPelicula(vector<Pelicula>& peliculas){
	Pelicula nueva;
	int idTemp;
	bool idExiste;
	do {
		idExiste = false;
		cout<<"ID: ";
		cin>>idTemp;
		cin.ignore();
		for (const auto& p : peliculas){
			if (p.id == idTemp){
				cout<<"Error. El id ya existe.\n";
				idExiste = true;
				break;
			}
		}
	} while (idExiste);
	nueva.id = idTemp;
	cout<<"Titulo: ";
	getline(cin, nueva.titulo);
	cout<<"Director: ";
	getline(cin, nueva.director);
	nueva.enCartelera = ingresarEstadoCartelera();
	peliculas.push_back(nueva);
	cout<<"Pelicula registrada exitosamente\n";
}

void listarPeliculas(vector<Pelicula>& peliculas){
	for (const auto& p : peliculas){
		cout<<"ID: "<<p.id<<" | Titulo: "<<p.titulo<<" | Director: "<<p.director<<" | Estado: "<<(p.enCartelera ? "En Cartelera" : "Fuera de Cartelera")<<endl;
	}
}

void buscarPelicula(vector<Pelicula>& peliculas){
	int idBuscado;
	cout<<"Ingresa la ID de la pelicula a buscar: ";
	cin>>idBuscado;
	bool encontrado = false;
	for (const auto& p : peliculas){
		if (p.id == idBuscado){
			cout<<"ID: "<<p.id<<" | Titulo: "<<p.titulo<<" | Director: "<<p.director<<" | Estado: "<<(p.enCartelera ? "En Cartelera" : "Fuera de Cartelera")<<endl;
			encontrado = true;
			break;
		}
	}
	if (!encontrado){
		cout<<"No se encontro una pelicula con el ID ingresado\n";
	}
}

void cambiarEstado(vector<Pelicula>& peliculas){
	int idBuscado;
	cout<<"Ingresa la ID de la pelicula a que quiere cambiar su estado: ";
	cin>>idBuscado;
	bool encontrado = false;
	for (auto& p : peliculas){
		if (p.id == idBuscado){
			if (p.enCartelera == true){
				p.enCartelera = false;
			} else if (p.enCartelera == false){
				p.enCartelera = true;
			}
			cout<<"El estado de la pelicula '"<<p.titulo<<"' fue cambiado.\n";
			encontrado = true;
			break;
		}
	}
	if (!encontrado){
		cout<<"No se encontro una pelicula con el ID ingresado\n";
	}
}

void eliminarPelicula(vector<Pelicula>& peliculas){
	int idBuscado;
	cout<<"Ingresa la ID de la pelicula a que quiere eliminar: ";
	cin>>idBuscado;
	bool encontrado = false;
	for (int i=0; i<peliculas.size(); i++){
		if (peliculas[i].id == idBuscado){
			encontrado = true;
			cout<<"Eliminando la pelicula: "<<peliculas[i].titulo<<endl;
			peliculas.erase(peliculas.begin()+i);
			cout<<"\nPelicula eliminada exitosamente\n";
			break;
		}
	}
	if (!encontrado){
		cout<<"No se encontro una pelicula con el ID ingresado\n";
	}
}

void filtrarPorEstado(vector<Pelicula>& peliculas){
	int opcion;
	int contador = 0;
	do {
		cout<<"1. Peliculas en Cartelera\n";
		cout<<"2. Peliculas fuera de Cartelera\n";
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		if (opcion != 1 && opcion!= 2){
			cout<<"Opcion invalida. Intente nuevamente.\n";
		}
	} while (opcion != 1 && opcion!= 2);
	cout<<"\nLista: \n";
	if (opcion == 1){
		for (const auto& p : peliculas){
			if (p.enCartelera == true){
				contador++;
				cout<<"ID: "<<p.id<<" | Titulo: "<<p.titulo<<" | Director: "<<p.director<<" | Estado: "<<(p.enCartelera ? "En Cartelera" : "Fuera de Cartelera")<<endl;
			}
		}
		if (contador == 0){
			cout<<"No hay peliculas en cartelera.\n";
		}
	} else if (opcion == 2){
		for (const auto& p : peliculas){
			if (p.enCartelera == false){
				contador++;
				cout<<"ID: "<<p.id<<" | Titulo: "<<p.titulo<<" | Director: "<<p.director<<" | Estado: "<<(p.enCartelera ? "En Cartelera" : "Fuera de Cartelera")<<endl;
			}
		}
		if (contador == 0){
			cout<<"No hay peliculas fuera de cartelera.\n";
		}
	}
}

int main(){
	vector<Pelicula> peliculas;
	int opcion;
	do {
		cout<<"\nMenu Gestion de Catalogo de Peliculas\n";
		cout<<"1. Registrar pelicula\n";
		cout<<"2. Listar peliculas\n";
		cout<<"3. Buscar pelicula por id\n";
		cout<<"4. Cambiar estado de la pelicula\n";
		cout<<"5. Eliminar pelicula\n";
		cout<<"6. Filtrar por estado\n";
		cout<<"0. Salir\n";
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		cin.ignore();
		switch (opcion) {
			case 1:
				cout<<"\n===Registrar Nueva Pelicula===\n";
				registrarPelicula(peliculas);
				break;
			case 2:
				if (peliculas.empty()){
					cout<<"\nNo hay peliculas registradas\n";
				} else {
					cout<<"\n===Listar Peliculas===\n";
					listarPeliculas(peliculas);
				}
				break;
			case 3:
				if (peliculas.empty()){
					cout<<"\nNo hay peliculas registradas\n";
				} else {
					cout<<"\n===Buscar Pelicula por ID===\n";
					buscarPelicula(peliculas);
				}
				break;
			case 4:
				if (peliculas.empty()){
					cout<<"\nNo hay peliculas registradas\n";
				} else {
					cout<<"\n===Cambiar Estado de la Pelicula===\n";
				    cambiarEstado(peliculas);
				}
				break;
			case 5:
				if (peliculas.empty()){
					cout<<"\nNo hay peliculas registradas\n";
				} else {
					cout<<"\n===Eliminar Pelicula===\n";
				    eliminarPelicula(peliculas);
				}
				break;
			case 6:
				if (peliculas.empty()){
					cout<<"\nNo hay peliculas registradas\n";
				} else {
					cout<<"\n===Filtrar por Estado===\n";
				    filtrarPorEstado(peliculas);
				}
				break;
			case 0:
				cout<<"Saliendo...\n";
				break;
			default:
				cout<<"Opcion invalida. INtente nuevamente\n";
				break;
		}
	} while (opcion!=0);

	return 0;
}
