#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Jugador {
    int id;
    string nombre;
    string posicion; 
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores; // anidado
};

void registrarEquipo(vector<Equipo>& equipos){
	Equipo nuevo;
	int idTemp;
	bool idExiste;
	do {
		idExiste = false;
		cout<<"ID: ";
		cin>>idTemp;
		cin.ignore();
		for (const auto& p : equipos){
			if (p.id == idTemp){
				cout<<"Error. El id ya existe.\n";
				idExiste = true;
				break;
			}
		}
	} while (idExiste);
	nuevo.id = idTemp;
	cout<<"Nombre del equipo: ";
	getline(cin, nuevo.nombre);
	cout<<"Entrenador del equipo: ";
	getline(cin, nuevo.entrenador);
	equipos.push_back(nuevo);
	cout<<"Equipo creado correctamente.\n";
}

void agregarJugador(vector<Equipo>& equipos){
	int idEquipo;
	cout<<"ID del equipo al que agregar jugador: ";
	cin>>idEquipo;
	bool encontrado = false;
	int indiceEquipo = -1;
	for (int i=0; i<equipos.size(); i++){
		if (equipos[i].id == idEquipo){
			encontrado = true;
			indiceEquipo = i;
			break;
		}
	}
	if (!encontrado){
		cout<<"\nNo se encontro un equipo con el ID ingresado.\n";
		return;
	}
	Jugador nuevo;
	int idJugador;
	bool idJugadorExiste;
	do {
		idJugadorExiste = false;
		cout<<"ID del jugador: ";
		cin>>idJugador;
		for (const auto& j : equipos[indiceEquipo].jugadores){
			if (j.id == idJugador){
				cout<<"Error. El id ingresado ya existe en este equipo.\n";
				idJugadorExiste = true;
				break;
			}
		}
	} while (idJugadorExiste);
	nuevo.id = idJugador;
	cin.ignore();
	cout<<"Nombre del jugador: ";
	getline(cin, nuevo.nombre);
	cout<<"Posicion: ";
	getline(cin, nuevo.posicion);
	cout<<"Edad: ";
	cin>>nuevo.edad;
	equipos[indiceEquipo].jugadores.push_back(nuevo);
	cout<<"Jugador agragado exitosamente\n";
}

void listarEquiposJugadores(vector<Equipo>& equipos){
	for (const auto& equipo : equipos){
		cout<<"\nEquipo: "<<equipo.nombre<<endl;
		cout<<"ID: "<<equipo.id<<endl;
		cout<<"Entrenador: "<<equipo.entrenador<<endl;
		if (!equipo.jugadores.empty()){
			cout<<"Jugadores: \n";
			for (const auto& jugador : equipo.jugadores){
				cout<<"ID: "<<jugador.id<<" | Nombre: "<<jugador.nombre<<" | Posicion: "<<jugador.posicion<<" | Edad: "<<jugador.edad<<endl;
			}
		} else {
			cout<<"\nNo hay jugadores registrados en este equipo.\n";
		}
	}
}

void buscarEquipo(vector<Equipo>& equipos){
	int idEquipo;
	cout<<"Ingresa el ID del equipo a buscar: ";
	cin>>idEquipo;
	bool encontrado = false;
	for (const auto& equipo : equipos){
		if (equipo.id == idEquipo){
			encontrado = true;
			cout<<"\nEquipo Encontrado\n";
			cout<<"\nEquipo: "<<equipo.nombre<<endl;
			cout<<"ID: "<<equipo.id<<endl;
			cout<<"Entrenador: "<<equipo.entrenador<<endl;
			if (!equipo.jugadores.empty()){
				cout<<"Jugadores: \n";
				for (const auto& jugador : equipo.jugadores){
					cout<<"ID: "<<jugador.id<<" | Nombre: "<<jugador.nombre<<" | Posicion: "<<jugador.posicion<<" | Edad: "<<jugador.edad<<endl;
				}
			} else {
				cout<<"No hay jugadores registrados en este equipo.\n";
			}
			break;
		}
	}
	if (!encontrado){
		cout<<"\nNo se encontro a un equipo con este ID.\n";
	}
}

void eliminarJugador(vector<Equipo>& equipos){
	int idEquipo;
	int idJugador;
	cout<<"Ingresa el ID del equipo del jugador a eliminar: ";
	cin>>idEquipo;
	bool encontradoEquipo = false;
	for (int i=0; i<equipos.size();i++){
		if (equipos[i].id == idEquipo){
			encontradoEquipo = true;
			cout<<"\nEquipo Encontrado\n";
			cout<<"Ingresa el ID del jugador a eliminar: ";
			cin>>idJugador;
			bool encontradoJugador = false;
			for (int j=0; j < equipos[i].jugadores.size(); j++){
				if (equipos[i].jugadores[j].id == idJugador){
					encontradoJugador = true;
					cout<<"Eliminando al jugador: "<<equipos[i].jugadores[j].nombre<<endl;
					equipos[i].jugadores.erase(equipos[i].jugadores.begin() + j);
					cout<<"\nJugador eliminado correctamente.\n";
					break;
				}
			}
			if (!encontradoJugador){
				cout<<"No se encontro a un jugador con el ID ingresado.\n";
			}
			return;
		}
	}
	if (!encontradoEquipo){
		cout<<"\nNo se encontro a un equipo con el ID ingresado.\n";
	}
}

void filtrarEquipos(vector<Equipo>& equipos){
	string entrenadorBuscado;
	cin.ignore();
	cout<<"Ingrese el nombre del entrenador: ";
	getline(cin, entrenadorBuscado);
	bool encontrado = false;
	cout<<"\n===Equipos del Entrenador Buscado===\n";
	for (const auto& equipo : equipos){
		if (equipo.entrenador == entrenadorBuscado){
			encontrado = true;
	        cout<<"\n- Equipo: "<<equipo.nombre<<endl;
			cout<<"ID: "<<equipo.id<<endl;
			cout<<"Entrenador: "<<equipo.entrenador<<endl;
			if (!equipo.jugadores.empty()){
				cout<<"Jugadores: \n";
				for (const auto& jugador : equipo.jugadores){
					cout<<"ID: "<<jugador.id<<" | Nombre: "<<jugador.nombre<<" | Posicion: "<<jugador.posicion<<" | Edad: "<<jugador.edad<<endl;
				}
			} else {
				cout<<"No hay jugadores registrados en este equipo.\n";
			}
		}
	}
	if (!encontrado){
		cout<<"\nNo se encontro ningun equipo con este entrenador.\n";
	}
}

void eliminarEquipo(vector<Equipo>& equipos){
	int idEquipo;
	cout<<"Ingresa el ID del equipo a eliminar: ";
	cin>>idEquipo;
	bool encontradoEquipo = false;
	for (int i=0; i<equipos.size();i++){
		if (equipos[i].id == idEquipo){
			encontradoEquipo = true;
			cout<<"Eliminando al equipo: "<<equipos[i].nombre<<endl;
			equipos.erase(equipos.begin()+i);
			cout<<"\nEquipo eliminado exitosamente\n";
			break;
		}
	}
	if (!encontradoEquipo){
		cout<<"\nNo se encontro a un equipo con el ID ingresado.\n";
	}
}

int main(){
	int opcion;
	vector<Equipo> equipos;
	do {
		cout<<"\nMenu Club Deportivo\n";
		cout<<"1. Registrar equipo\n";
		cout<<"2. Agregar jugador a un equipo\n";
		cout<<"3. Listar equipos con sus jugadores\n";
		cout<<"4. Buscar equipo por ID\n";
		cout<<"5. Eliminar jugador de un equipo\n";
		cout<<"6. Filtrar equipos por entrenador\n";
		cout<<"7. Eliminar equipo completo\n";
		cout<<"0. Salir\n";
		cout<<"Selecciona una opcion: ";
		cin>>opcion;
		cin.ignore();
		switch (opcion) {
			case 1:
				cout<<"\n===Registrar Equipo===\n";
				registrarEquipo(equipos);
				break;
			case 2:
				if (equipos.empty()){
					cout<<"No hay equipos registrados.\n";
				} else {
					cout<<"\n===Agregar Jugador===\n";
					agregarJugador(equipos);
				}
				break;
			case 3:
				if (equipos.empty()){
					cout<<"No hay equipos registrados.\n";
				} else {
					cout<<"\n===Listar Equipos y sus Jugadores===\n";
					listarEquiposJugadores(equipos);
				}
				break;
			case 4:
				if (equipos.empty()){
					cout<<"No hay equipos registrados.\n";
				} else {
					cout<<"\n===Buscar Equipo por ID===\n";
				    buscarEquipo(equipos);
				}	
				break;
			case 5:
				if (equipos.empty()){
					cout<<"No hay equipos registrados.\n";
				} else {
					cout<<"\n===Eliminar Jugador de un Equipo===\n";
				    eliminarJugador(equipos);
				}
				break;
			case 6:
				if (equipos.empty()){
					cout<<"No hay equipos registrados.\n";
				} else {
					cout<<"\n===Filtrar equipos por entrenador===\n";
					filtrarEquipos(equipos);
				}
			    break;
			case 7:
				if (equipos.empty()){
					cout<<"No hay equipos registrados.\n";
				} else {
					cout<<"\n===Eliminar Equipo Completo===\n";
					eliminarEquipo(equipos);
				}
				break;
			case 0:
				cout<<"Saliendo...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente nuevamente.\n";
				break;
		}
	}while (opcion!=0);
	
	return 0;
}
