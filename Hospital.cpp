#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

struct HospitalBasicInfo {

	char nombre[100];
	char direccion[150];
	char numerotlf [15];
};
	HospitalBasicInfo BasicInfo;

	
int main(){
	
	cout << "Ingresa un nombre" << endl;
	cin.ignore();
    cin.getline(BasicInfo.nombre, 100);
    
    if (sizeof(BasicInfo.nombre)> 100) {
    	cout << "Reingrese el nombre, maximo 100 caracteres" << endl;
    	cin.ignore();
    	cin.getline(BasicInfo.nombre, 100);
	}
	cout << "Bienvenido al Hospital " << BasicInfo.nombre << endl;
	
	cout << "Ingresa la direccion" << endl;
	cin.ignore();
    cin.getline(BasicInfo.direccion, 150);
	cout << "El Hospital " << BasicInfo.nombre << " se encuentra en " << BasicInfo.direccion << endl;
	
	cout << "Ingresa un numero telefonico" << endl;
	cin.ignore();
    cin.getline(BasicInfo.numerotlf, 15);
	cout << "Tambien puede llamar al " << BasicInfo.numerotlf << " para agendar una cita" << endl;
	
	
	
}
