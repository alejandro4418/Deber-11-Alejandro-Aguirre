#include<iostream>
#include<string>
using namespace std;

struct Vehiculo{
	string marca;
	string modelo;
	int anio;
};

void ingresarVehiculo(Vehiculo &vehiculo){
	cout<<"Ingrese la marca del vehiculo: ";
	cin.ignore();
	getline(cin, vehiculo.marca);
	cout<<"Ingrese el modelo del vehiculo: ";
	getline(cin, vehiculo.modelo);
	cout<<"Ingrese el anio del vehiculo: ";
	cin>>vehiculo.anio;
	
}

Vehiculo encontrarMasReciente(Vehiculo vehiculos[], int vehiculosMaximos){
	Vehiculo masReciente = vehiculos[0];
	for (int i=0; i<vehiculosMaximos; i++){
		if (vehiculos[i].anio > masReciente.anio){
			masReciente = vehiculos[i];
		}
	}
	return masReciente;
}

int main(){
	const int vehiculosMaximos = 5;
	Vehiculo vehiculos[vehiculosMaximos];
	cout<<"Registro de Vehiculo\n";
	for (int i=0; i<vehiculosMaximos; i++){
		cout<<"Vehiculo "<<i+1<<endl;
		ingresarVehiculo(vehiculos[i]);
	}
	Vehiculo masReciente = encontrarMasReciente(vehiculos, vehiculosMaximos);
	cout<<"\nVehiculo mas reciente: "<<endl;
	cout<<"Marca :"<<masReciente.marca<<endl;
	cout<<"Modelo: "<<masReciente.modelo<<endl;
	cout<<"Anio: "<<masReciente.anio<<endl;
	
	
	return 0;
}
