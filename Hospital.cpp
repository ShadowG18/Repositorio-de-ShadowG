#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
using namespace std;

struct Hospital {

	char nombre[100];
	char direccion[150];
	char numerotlf [15];
	int ID_pacientes = 0;
	int ID_docs = 0;
	int ID_cita = 0;
	int ID_consultas = 0;
	
	int cantidad_pacientes;
	int capacidad_pacientes;
	
	int cantidad_docs;
	int capacidad_docs;
	
	int cantidad_citas;
	int capacidad_citas;

};

struct Historial_Medico{
	
	int ID_consulta;
	char Fecha_consulta[11];
	char Hora_consulta[6];
	char Diagnostico[200];
	char Tratamiento_prescrito[200];
	char Medicamentos_recetados[150];
	//ID del dcotor que lo atendio
	float consulta_costo;
	
};

struct pacientes{
	
	int id;
	char Nombre [50];
	char Apellido[50];
	char Cedula[20];
	int Edad;
	char Sexo;
	char Tipo_de_sangre[5];
	char Tlf[15];
	char Direccion[100];
	char Email[50];
	Historial_Medico* Historial_paciente;
	int cantidad_consultas;
	int capacidad_consultas;
	int* citasAgendadas;
    int cantidadCitas;
    int capacidadCitas;
	char Alergias[500];
	char Observaciones_generales[500];
	bool activo;

};

	pacientes* Pacientes;

struct doctores{
	
	char Nombre [50];
	char Apellido[50];
	char Cedula[20];
	char Especialidad[50];
	int Experiencia;
	float consulta_costo;
	char Tlf[15];
	char Email[50];
	int* pacientes_Asignados;
	int Cantidad_pacientes;
	int Capacidad_pacientes;
	int* citas_Agendadas;
    int cantidad_citas;
    int capacidad_citas;
    bool disponible;
	
};

struct citas{
	
	int id;
	int id_paciente;
	int id_doctor;
	char fecha[11];
	char hora[6];
	char motivo[150];
	char estado[20];
	char Observaciones [200];
	bool Atendida = false;
	
};

void crearPaciente(){
	cout << "Ingrese el nombre del paciente" << endl;
	cin.getline(Pacientes->Nombre, 50, 50);
	cout << "Ingrese el apellido del paciente" << endl;
	cin.getline(Pacientes->Apellido, 50, 50);
	cout << "Ingrese la cedula del paciente" << endl;
	cin.getline(Pacientes->Cedula, 50, 50);
	cout << "Ingrese el genero del paciente" << endl;
	cin >> Pacientes->Sexo;
	cout << "Ingrese el nombre del paciente" << endl;
	cin >> Pacientes->Edad
};
        

auto incrementar = [](int* ptr) {
        *ptr += 1;
    };
    
void limpiarPantalla() {
    system("cls");
}
int main(){
	
	int seleccion;
	
	do{
	cout << "SISTEMA DE GESTIÓN HOSPITALARIA" << endl;
	cout << "1. Gestion de Pacientes" << endl;
	cout << "2. Gestion de Doctores" << endl;
	cout << "3. Gestion de Citas" << endl;
	cout << "4. Salir" << endl;
	cin >> seleccion;
	
		if (seleccion == 1){
			
			do{
			cout << "Menú de Pacientes:" << endl;
			cout << "1. Registrar nuevo paciente" << endl;
			cout << "2. Buscar paciente por cédula" << endl;
			cout << "3. Buscar paciente por nombre" << endl;
			cout << "4. Ver historial médico completo" << endl;
			cout << "5. Actualizar datos del paciente" << endl;
			cout << "6. Listar todos los pacientes" << endl;
			cout << "7. Eliminar paciente" << endl;
			cout << "0. Volver al menú principal" << endl;
			cin >> seleccion;
			
			if (seleccion == 1){
				crearPaciente;
			} else {
			};
			} while (seleccion != 0);
			
			
		} 	else if (seleccion == 2){
			
			cout << "Menú de Pacientes:" << endl;
			cout << "1. Registrar nuevo doctor" << endl;
			cout << "2. Buscar doctor por ID" << endl;
			cout << "3. Buscar doctores por especialidad" << endl;
			cout << "4. Asignar paciente a doctor" << endl;
			cout << "5. Ver pacientes asignados a doctor" << endl;
			cout << "6. Listar todos los doctores" << endl;
			cout << "7. Eliminar doctor" << endl;
			cout << "0. Volver al menú principal" << endl;
			cin >> seleccion;
			
			} 	else if (seleccion == 3){
				
				cout << "1. Agendar nueva cita" << endl;
				cout << "2. Cancelar cita" << endl;
				cout << "3. Atender cita" << endl;
				cout << "4. Ver citas de un paciente" << endl;
				cout << "5. Ver citas de un doctor" << endl;
				cout << "6. Ver citas de una fecha" << endl;
				cout << "7. Ver citas pendientes" << endl;
				cout << "0. Volver al menú principal" << endl;
				cin >> seleccion;
				
				} 	else if (seleccion == 4){
					}	else {
						cout << "Seleccion invalida, por favor ponga una accion valida" << endl;
					};
					
	limpiarPantalla();
	}while (seleccion != 4);
	
	cout << "Gracias por use nuestra gestion hospitalaria";
}
