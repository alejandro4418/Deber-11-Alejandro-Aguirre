#include<iostream>
#include<string>
using namespace std;

void dividirMensaje(const string& chat, string& hora, string& usuario, string& mensaje){
	size_t posicion1 = chat.find("//");
	hora = chat.substr(0, posicion1);
	size_t posicion2 = chat.find("//", posicion1 + 2);
	usuario = chat.substr(posicion1 + 2, posicion2 - posicion1 - 2);
	mensaje = chat.substr(posicion2 + 2);
}

void mostrarArreglos(const string horas[], const string usuarios[], const string mensajes[], int numMensajes) {
    cout<<"Mostrando contenido del chat a traves de 3 arreglos"<<endl;
    cout << "\nHORAS\t\tUSUARIOS\t\tMENSAJES\n" << endl;
    for (int i = 0; i < numMensajes; i++) {
        cout<<horas[i]<<"\t\t"<<usuarios[i]<<"\t\t"<<mensajes[i]<<endl;
    }
}

void contarMensajes(const string usuarios[], int numeroMensajes, int& mensajesRoberto, int& mensajesBelen){
	mensajesRoberto = 0;
	mensajesBelen = 0;
	for (int i=0; i<numeroMensajes; i++){
		if (usuarios[i] == "Roberto"){
			mensajesRoberto++;
		} else if (usuarios[i] == "Belen") {
			mensajesBelen++;
		}
	}
}

int main(){
	string chat[] = {
	    "08:15//Roberto//Hola perdida, ¿como estas?",
	    "08:17//Belen//Bien, gracias. ¿Y tu?",
	    "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
	    "08:21//Belen//Tu novia, ¿si te da permiso?",
	    "08:22//Roberto//Cual novia?. Es una amiga nomas",
	    "08:23//Roberto//mejor tu pide permiso a tu novio?"
	};
	int numeroMensajes = sizeof(chat)/sizeof(chat[0]);
	string horas[numeroMensajes];
	string usuarios[numeroMensajes];
	string mensajes[numeroMensajes];
	for (int i=0; i<numeroMensajes; i++){
		string hora, usuario, mensaje;
		dividirMensaje(chat[i], hora, usuario, mensaje);
		horas[i] = hora;
		usuarios[i] = usuario;
		mensajes[i] = mensaje;
	}
	mostrarArreglos(horas, usuarios, mensajes, numeroMensajes);
	int mensajesRoberto, mensajesBelen;
	contarMensajes(usuarios, numeroMensajes, mensajesRoberto, mensajesBelen);
	cout<<"\nReporte\n";
	cout<<"\nRobert ha enviado "<<mensajesRoberto<<" mensajes en total.\n";
	cout<<"Belen ha enviado "<<mensajesBelen<<" mensajes en total.\n";
	
	return 0;
}



