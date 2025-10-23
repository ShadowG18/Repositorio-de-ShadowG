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
	
int capacidadpacientes;
	
struct pacientes{
};

pacientes* Pacientes = new pacientes[capacidadpacientes];

int capacidaddocs;
	
struct doctores{
};

doctores* Doctores = new doctores[capacidaddocs];

int capacidadcitas;
	
struct citas{
};

citas* Citas = new citas[capacidadcitas];

auto incrementar = [](int* ptr) {
        *ptr += 1;
    };
    
	int IDN = 1;
	int* IDpacientes = &IDN;
	int IDdocs = 1;
	int IDcita = 1;
	int IDconsultas = 1;



	
int main(){
	
	cout << "Antes de ingresar un paciente la ID es " << IDN << endl;
	incrementar(&IDN);
	cout << "Despues de ingresar un paciente la ID es " << IDN << endl;
	
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
