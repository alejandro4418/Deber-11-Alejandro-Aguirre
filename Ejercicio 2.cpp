#include<iostream>
#include<iomanip>
using namespace std;

void llenarDulzura(int chocolate[4][6]){
	cout<<"Ingrese el nivel de dulzura para cada trozo (del 1 al 9): \n";
	for (int i=0; i<4; i++){
		for (int j=0; j<6;j++){
			do {
				cout<<"Fila "<<i+1<<" | Columna "<<j+1<<": ";
				cin>>chocolate[i][j];
				if (chocolate[i][j] <1 || chocolate[i][j]>9){
					cout<<"Error. Los niveles de dulzura van del 1 al 9."<<endl;
				}
			} while ( chocolate[i][j] <1 || chocolate[i][j]>9);
		}
	}
}

double calcularPromedio(int chocolate[4][6]){
	int suma =0;
	int total = 4*6;
	for (int i=0; i<4; i++){
		for (int j=0; j<6;j++){
			suma += chocolate[i][j];	
		}
	}
	return static_cast<double>(suma)/total;
}

int main(){
	int chocolate[4][6];
	llenarDulzura(chocolate);
	double promedio = calcularPromedio(chocolate);
	cout<<"Promedio de dulzura en el chocolate: "<<fixed<<setprecision(2)<<promedio<<endl;
	
	return 0;
}
