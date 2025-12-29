#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Estudiante{
	int id;
	string nombre;
	string carrera;
	double promedio;
};

void registrarEstudiante(vector<Estudiante>& estudiantes){
	Estudiante nuevo;
	int idTemp;
	bool idExiste;
	do {
		idExiste = false;
		cout<<"ID: ";
		cin>>idTemp;
		cin.ignore();
		for (const auto& e : estudiantes){
			if (e.id == idTemp){
				cout<<"Error. El id ya existe.\n";
				idExiste = true;
				break;
			}
		}
	} while (idExiste);
    nuevo.id = idTemp;
	cout<<"Nombre: ";
	getline(cin, nuevo.nombre);
	cout<<"Carrera: ";
	getline(cin, nuevo.carrera);
	do {
		cout<<"Promedio (0-20): ";
		cin>>nuevo.promedio;
		if (nuevo.promedio < 0 || nuevo.promedio > 20){
			cout<<"Error. El rango del promedio es de 0 a 20.\n";
		}
	} while (nuevo.promedio < 0 || nuevo.promedio > 20);

	estudiantes.push_back(nuevo);
	cout<<"Estudiante registrado exitosamente\n";
}

void listarEstudiantes(vector<Estudiante>& estudiantes){
	for (const auto& e : estudiantes){
		cout<<"ID: "<<e.id<<" | Nombre: "<<e.nombre<<" | Carrera: "<<e.carrera<<" | Promedio: "<<e.promedio<<endl;
	}
}

void buscarEstudiante(vector<Estudiante>& estudiantes){
	int idBuscado;
	cout<<"Ingrese el ID del alumno a buscar: ";
	cin>>idBuscado;
	bool encontrado = false;
	for (const auto& e : estudiantes){
		if (e.id == idBuscado){
			cout<<"Encontrado\n";
			cout<<"ID: "<<e.id<<" | Nombre: "<<e.nombre<<" | Carrera: "<<e.carrera<<" | Promedio: "<<e.promedio<<endl;
			encontrado = true;
			break;
		}
	}
	if (!encontrado){
		cout<<"No se encontro un alumno con el ID ingresado.\n";
	}
}

void actualizarEstudiante(vector<Estudiante>& estudiantes){
	int idBuscado;
	string nuevoNombre;
	string nuevaCarrera;
	string promedioTemp;
	double nuevoPromedio;
	cout<<"Ingrese el ID del alumno a actualizar: ";
	cin>>idBuscado;
	cin.ignore();
	bool encontrado = false;
	for (auto& e : estudiantes){
		if (e.id == idBuscado){
			encontrado = true;
			cout<<"Encontrado. Ingrese los nuevos datos\n";
			cout<<"Nuevo nombre: ";
			getline(cin, nuevoNombre);
			if (!nuevoNombre.empty()){
				e.nombre = nuevoNombre;
			}
			cout<<"Nueva carrera: ";
			getline(cin, nuevaCarrera);
			if (!nuevaCarrera.empty()){
				e.carrera = nuevaCarrera;
			}
			cout<<"Nuevo promedio: ";
			cin>>promedioTemp;
			if (!promedioTemp.empty()){
				nuevoPromedio = stod(promedioTemp);
				if (nuevoPromedio >=0 && nuevoPromedio <=20){
					e.promedio = nuevoPromedio;
				} else {
					cout<<"Promedio no valido. No hya cambios en el promedio\n";
				}
			}
			cout<<"Estudiante actualizado exitosamente\n";
			break;
		}
	}
	if (!encontrado){
		cout<<"No se encontro un alumno con el ID ingresado.\n";
	}
}

void eliminarEstudiante(vector<Estudiante>& estudiantes){
	int idBuscado;
	cout<<"Ingrese el ID del alumno a eliminar: ";
	cin>>idBuscado;
	bool encontrado = false;
	for (int i=0; i<estudiantes.size(); i++){
		if (estudiantes[i].id == idBuscado){
			encontrado = true;
			cout<<"\nEliminando: "<<estudiantes[i].nombre<<endl;
			estudiantes.erase(estudiantes.begin() + i);
			cout<<"Estudiante eliminado exitosamente\n";
			break;
		}
	}
	if (!encontrado){
		cout<<"No se encontro un alumno con el ID ingresado.\n";
	}
}

vector<Estudiante> estudiantesAprobados(vector<Estudiante>& estudiantes){
	vector<Estudiante> aprobados;
	for (const auto& e : estudiantes){
		if (e.promedio >= 14.0){
			aprobados.push_back(e);
		}
	}
	return aprobados;
}

int main(){
	vector<Estudiante> estudiantes;
	int opcion;
	do {
		cout<<"\n===Menu Gestion de Estudiantes===\n";
		cout<<"1. Registrar estudiante\n";
		cout<<"2. Listar estudiantes\n";
		cout<<"3. Buscar estudiante\n";
		cout<<"4. Actualizar estudiante\n";
		cout<<"5. Eliminar estudiante\n";
		cout<<"6. Mostrar estudiantes aprobados\n";
		cout<<"0. Salir\n";
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		switch (opcion) {
			case 1:
				cout<<"\n===Registrar un Nuevo Estudiante===\n";
				registrarEstudiante(estudiantes);
				break;
			case 2:
			    if (estudiantes.empty()) {
			        cout << "\nNo hay estudiantes registrados.\n";
			    } else {
			    	cout<<"\n===Lista de estudiantes===\n";
					listarEstudiantes(estudiantes);
				}
				break;
			case 3:
			    if (estudiantes.empty()) {
			        cout << "\nNo hay estudiantes registrados.\n";
			    } else {
					cout<<"\n===Buscar Estudiante===\n";
					buscarEstudiante(estudiantes);
				}
				break;
			case 4:
			    if (estudiantes.empty()) {
			        cout << "\nNo hay estudiantes registrados.\n";
			    } else {
					cout<<"\n===Actualizar Estudiante===\n";
					actualizarEstudiante(estudiantes);
				}
				break;
			case 5:
			    if (estudiantes.empty()) {
			        cout << "\nNo hay estudiantes registrados.\n";
			    } else {
					cout<<"\n===Eliminar Estidiante===\n";
					eliminarEstudiante(estudiantes);
				}
				break;
			case 6: {
				vector<Estudiante> aprobados = estudiantesAprobados(estudiantes);
				if (aprobados.empty()){
					cout<<"\nNo hay estudiantes aprobados.\n";
				} else {
					cout<<"\n===Estudiantes aprobados===\n";
					for (const auto& e : aprobados){
						cout<<"ID: "<<e.id<<" | Nombre: "<<e.nombre<<" | Carrera: "<<e.carrera<<" | Promedio: "<<e.promedio<<endl;
					}
					cout<<"Total de alumnos aprobados: "<<aprobados.size()<<endl;
				}
				break;
			}
			case 0:
				cout<<"Saliendo...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente nuevamente\n";
				break;
		}
	} while (opcion != 0);
	
	return 0;
}
