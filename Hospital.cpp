#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <limits>
using namespace std;

struct Historial_Medico{
	
	int ID_consulta;
	char Fecha_consulta[11];
	char Hora_consulta[6];
	char Diagnostico[200];
	char Tratamiento_prescrito[200];
	char Medicamentos_recetados[150];
	int idDoctor;
	float consulta_costo;
	
};

struct pacientes{
	
	int id = 0;
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
	

struct doctores{
	
	int id = 0;
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

struct Hospital {

	char nombre[100];
	char direccion[150];
	char numerotlf [15];
	int ID_pacientes = 0;
	int ID_docs = 0;
	int ID_cita = 0;
	int ID_consultas = 0;
	
	pacientes* Paciente;
	int cantidad_pacientes = 0;
	int capacidad_pacientes = 10;
	
	doctores* Doctores;
	int cantidad_docs = 0;
	int capacidad_docs = 10;
	
	citas* Citas;
	int cantidad_citas;
	int capacidad_citas = 20;

    Hospital(){
        Paciente = new pacientes[capacidad_pacientes];  
        Doctores = new doctores[capacidad_docs];
        
    }

    ~Hospital(){
        delete[] Paciente;
        delete[] Doctores;
    }
};



pacientes* crearPaciente(Hospital* hospital, const char* nombre, const char* apellido, const char* cedula, int edad, char sexo){

if (hospital->cantidad_pacientes >= hospital->capacidad_pacientes){
        hospital->capacidad_pacientes *= 2;
    }

    int i = hospital->cantidad_pacientes;
	
	++hospital->ID_pacientes;
	hospital->Paciente[i].id = hospital->ID_pacientes;
	strcpy(hospital->Paciente[i].Nombre, nombre);
	strcpy(hospital->Paciente[i].Apellido, apellido);
	strcpy(hospital->Paciente[i].Cedula, cedula);
	hospital->Paciente[i].Edad = edad;
	hospital->Paciente[i].Sexo = sexo;
	hospital->Paciente[i].activo = true; 
	hospital->Paciente[i].citasAgendadas = new int [hospital->Paciente[i].capacidadCitas];
	hospital->Paciente[i].Historial_paciente = new Historial_Medico[hospital->Paciente[i].capacidad_consultas];
	
	for (int j = 0; j < 500; ++j) {
    	
		hospital->Paciente[i].Alergias[j] = '\0';

	};
	
	for (int j = 0; j < 500; ++j) {
    	
		hospital->Paciente[i].Observaciones_generales[j] = '\0';

	};
	
    hospital->cantidad_pacientes++;

	return &hospital->Paciente[i];
	
};

pacientes* Buscarpaciente_Cedula(Hospital* hospital, const char* cedula){
	
	
	for (int i = 0; i < hospital->cantidad_pacientes; i++) {
		
		if ( strcmp (cedula, hospital->Paciente[i].Cedula) == 0 && hospital->Paciente[i].activo){
			return &hospital->Paciente[i];
		};
 	}
 		return nullptr;

}

pacientes* Buscarpaciente_Nombre(Hospital* hospital, const char* nombre){
	
	
	for (int i = 0; i < hospital->cantidad_pacientes; i++) {
		
		if ( strcmp (nombre, hospital->Paciente[i].Nombre) == 0 && hospital->Paciente[i].activo){
			return &hospital->Paciente[i];
		};
 	}
 		return nullptr;

};

pacientes* BuscarpacienteID(Hospital* hospital, int id){
	
	
	for (int i = 0; i < hospital->cantidad_pacientes; i++) {
		
		if ( (id == hospital->Paciente[i].id) && hospital->Paciente[i].activo){
			return &hospital->Paciente[i];
		};
 	}
 		return nullptr;

};

bool actualizarPaciente(Hospital* hospital, int id){
		
		for (int i = 0; i < hospital->cantidad_pacientes; i++) {
		
			if ( (id == hospital->Paciente[i].id) && hospital->Paciente[i].activo){
				return true;
			};
 
		};
		
		return false;
		
 	};
 	
bool eliminarPaciente(Hospital* hospital, int id){
		
		for (int i = 0; i < hospital->cantidad_pacientes; i++) {
		
			if ( (id == hospital->Paciente[i].id) && hospital->Paciente[i].activo){
				
				 delete[] hospital->Paciente[i].citasAgendadas;
				 hospital->Paciente[i].citasAgendadas = nullptr;
				 delete[] hospital->Paciente[i].Historial_paciente;
				 hospital->Paciente[i].Historial_paciente = nullptr;
				 
			for (int j = i; j < hospital->cantidad_pacientes - 1; ++j) {
                hospital->Paciente[j] = hospital->Paciente[j + 1];
            }
				--hospital->cantidad_pacientes;
				return true;
			};

		};
		
		return false;
		
 	};

void listartodospacientes(Hospital* hospital){

cout <<	"+------------------------------------------------------------+" << endl;
cout <<	"¦                    LISTA DE PACIENTES                      ¦" << endl;
cout <<	"¦------------------------------------------------------------¦" << endl;
cout <<	"¦ ID  ¦ NOMBRE COMPLETO     ¦ CÉDULA       ¦ EDAD ¦ CONSULTAS¦" << endl;
cout <<	"¦-----+---------------------+--------------+------+----------¦" << endl;
	for (int i = 0; i < hospital->cantidad_pacientes; i++){

		cout <<	left << setw(10) << hospital->Paciente[i].id <<	left << setw(5) << hospital->Paciente[i].Nombre << left << setw(15) << hospital->Paciente[i].Apellido << left << setw(15) << hospital->Paciente[i].Cedula << left<< setw(15) << hospital->Paciente[i].Edad << endl;
		
	}
cout <<	"+------------------------------------------------------------+" << endl;
}

doctores* crearDoctores(Hospital* hospital, const char* nombre, const char* apellido, const char* cedula, const char* especialidad, int aniosExperiencia, float costoConsulta){

if (hospital->cantidad_docs >= hospital->capacidad_docs){
        hospital->capacidad_docs *= 2;
    }

    int i = hospital->cantidad_docs;
	
	++hospital->ID_docs;
	hospital->Doctores[i].id = hospital->ID_docs;
	strcpy(hospital->Doctores[i].Nombre, nombre);
	strcpy(hospital->Doctores[i].Apellido, apellido);
	strcpy(hospital->Doctores[i].Cedula, cedula);
	strcpy(hospital->Doctores[i].Especialidad, especialidad);
	hospital->Doctores[i].Experiencia = aniosExperiencia;
	hospital->Doctores[i].consulta_costo = costoConsulta;
	hospital->Doctores[i].disponible = true; 
	hospital->Doctores[i].citas_Agendadas = new int[hospital->Doctores[i].capacidad_citas];
	hospital->Doctores[i].pacientes_Asignados = new int [hospital->Doctores[i].Capacidad_pacientes];
	
    hospital->cantidad_docs++;

	return &hospital->Doctores[i];
	
};

void limpiarPantalla() {
    system("cls");
}

int main(){
	
	Hospital* hospital = new Hospital();
	int seleccion;
	char decision;
	bool ayuda;
	
	do{
	cout << "SISTEMA DE GESTIÓN HOSPITALARIA" << endl;
	cout << "1. Gestion de Pacientes" << endl;
	cout << "2. Gestion de Doctores" << endl;
	cout << "3. Gestion de Citas" << endl;
	cout << "4. Salir" << endl;
	if (ayuda == true){
		cout << "Ingrese un numero, no ingreses caracteres" << endl;
	}
	cin >> seleccion;
	
		if(cin.fail());{
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			ayuda = true;
		};
	
		if (seleccion == 1){
			
			do{
				limpiarPantalla();
			cout << "Menú de Pacientes:" << endl;
			cout << "1. Registrar nuevo paciente" << endl;
			cout << "2. Buscar paciente por cédula" << endl;
			cout << "3. Buscar paciente por nombre" << endl;
			cout << "4. Buscar paciente por ID" << endl;
			cout << "5. Ver historial médico completo" << endl;
			cout << "6. Actualizar datos del paciente" << endl;
			cout << "7. Listar todos los pacientes" << endl;
			cout << "8. Eliminar paciente" << endl;
			cout << "0. Volver al menú principal" << endl;
			cin >> seleccion;
			
			if (seleccion == 1){
					
					do{
						limpiarPantalla();
					
					
						char* nombre = new char[50];
						char* apellido = new char[50];
						char* cedula = new char[20];
						int edad;
						char sexo;
					    
					    cout << "Ingrese el nombre del paciente" << endl;
					    cin.ignore();
					    cin.getline(nombre, 50);
					    
					    cout << "Ingrese el apellido del paciente" << endl;
					    cin.getline(apellido, 50);
					    cout << "Ingrese la cedula del paciente" << endl;
					    cin.getline(cedula, 20);
					    
					    	bool valido;
                        do{
                            valido = true;
                            for (int j = 0; j < hospital->cantidad_pacientes ; ++j){
                                
                                if (j < hospital->cantidad_pacientes){
                                    if (strcmp(cedula, hospital->Paciente[j].Cedula) == 0){
                                        cout << "La cedula ingresada ya existe en pacientes, ingrese otra cedula" << endl;
                                        cin.getline(cedula, 20);
                                        valido = false;
                                        break;
                                    }
                                } 
                                    }
                                }while (!valido);
                                
                        do{
                            valido = true;
                            for (int j = 0; j < hospital->cantidad_docs; ++j){
                                
                                if (j < hospital->cantidad_docs){
                                    if (strcmp(cedula, hospital->Doctores[j].Cedula) == 0){
                                        cout << "La cedula ingresada ya existe en doctores, ingrese otra cedula" << endl;
                                        cin.getline(cedula, 20);
                                        valido = false;
                                        break;
                                		} 
                                    }
                                }
							}while (!valido);
                                

                                    
					    
					    cout << "Ingrese la edad del paciente" << endl;
					    cin >> edad;
					    	do {
			
					    	if  ((edad < 0) || (edad > 120)){
					    		
					    		cout << "Por favor ingrese un rango entre los 1-120 anos de edad" << endl;
					    		cin >> edad;
					    		
							};
							}while((edad < 0) || (edad > 120));
					    cout << "Ingrese el sexo del paciente (M/F)" << endl;
					    cin >> sexo;
					    
					    	do {
					    	if ( (sexo != 'm') && (sexo != 'M') && (sexo != 'f') && (sexo != 'F') ){
					    		
					    		cout << "...uh, ingrese un genero valido, M o F" << endl;
					    		cin >> sexo;
					    		
							} else;
							}while ( (sexo != 'm') && (sexo != 'M') && (sexo != 'f') && (sexo != 'F') );
					    
                        pacientes* nuevoPaciente = crearPaciente(hospital, nombre, apellido, cedula, edad, sexo);
                        if (nuevoPaciente != nullptr){
                            cout << "Paciente registrado exitosamente!" << endl;
                            cout << "ID del paciente: " << nuevoPaciente->id << endl;
                            cout << "Nombre: " << nuevoPaciente->Nombre << endl;
                            cout << "Apellido: " << nuevoPaciente->Apellido << endl;
                            cout << "Cedula: " << nuevoPaciente->Cedula << endl;
                            cout << "Edad: " << nuevoPaciente->Edad << endl;
                            cout << "Sexo: " << nuevoPaciente->Sexo << endl;
                        }
					         
					    delete[] nombre;
					    delete[] apellido;
					    delete[] cedula;
						
						cout << "Quiere ingresar otro paciente? (Y/N)" << endl;
						cin >> decision;
						
					} while (decision == 'y' || decision == 'Y');
					
			} else if (seleccion == 2){
				
				do{
					limpiarPantalla();
				
				char* cedula = new char[20];
                cout << "Ingrese la cedula del paciente buscar" << endl;
                cin.ignore();
                cin.getline(cedula, 20);
					
				
                    pacientes* encontradoPaciente = Buscarpaciente_Cedula(hospital, cedula);
                    if (encontradoPaciente) {
                        cout << "Paciente encontrado:" << endl;
                        cout << "ID: " << encontradoPaciente->id << endl;
                        cout << "Nombre: " << encontradoPaciente->Nombre << endl;
                        cout << "Apellido: " << encontradoPaciente->Apellido << endl;
                        cout << "Cedula: " << encontradoPaciente->Cedula << endl;
                        cout << "Edad: " << encontradoPaciente->Edad << endl;
                        cout << "Sexo: " << encontradoPaciente->Sexo << endl;
                    } else {
                        cout << "Paciente no encontrado." << endl;
                    }
                    
						cout << "Quiere ingresar otro paciente? (Y/N)" << endl;
						cin >> decision;
						
					
                    delete[] cedula;
                } while (decision == 'y' || decision == 'Y');
                } else if (seleccion == 3){
                
				do{	
					limpiarPantalla();
				
				
				
				char* nombre = new char[50];
                cout << "Ingrese el nombre del paciente buscar" << endl;
                cin.ignore();
                cin.getline(nombre, 50);
					
				
                    pacientes* encontradoPaciente = Buscarpaciente_Nombre(hospital, nombre);
                    if (encontradoPaciente) {
                        cout << "Paciente encontrado:" << endl;
                        cout << "ID: " << encontradoPaciente->id << endl;
                        cout << "Nombre: " << encontradoPaciente->Nombre << endl;
                        cout << "Apellido: " << encontradoPaciente->Apellido << endl;
                        cout << "Cedula: " << encontradoPaciente->Cedula << endl;
                        cout << "Edad: " << encontradoPaciente->Edad << endl;
                        cout << "Sexo: " << encontradoPaciente->Sexo << endl;
                    } else {
                        cout << "Paciente no encontrado." << endl;
                    }
                    
						cout << "Quiere buscar otro paciente? (Y/N)" << endl;
						cin >> decision;
						
					
                    delete[] nombre;
                } while (decision == 'y' || decision == 'Y');                	
                	
				} else if (seleccion == 4){
				
				do{	
					limpiarPantalla();
				
				
				
				int id;
                cout << "Ingrese la ID del paciente buscar" << endl;
                cin >> id;
					
				
                    pacientes* encontradoPaciente = BuscarpacienteID(hospital, id);
                    if (encontradoPaciente) {
                        cout << "Paciente encontrado:" << endl;
                        cout << "ID: " << encontradoPaciente->id << endl;
                        cout << "Nombre: " << encontradoPaciente->Nombre << endl;
                        cout << "Apellido: " << encontradoPaciente->Apellido << endl;
                        cout << "Cedula: " << encontradoPaciente->Cedula << endl;
                        cout << "Edad: " << encontradoPaciente->Edad << endl;
                        cout << "Sexo: " << encontradoPaciente->Sexo << endl;
                    } else {
                        cout << "Paciente no encontrado." << endl;
                    }
                    
						cout << "Quiere buscar otro paciente? (Y/N)" << endl;
						cin >> decision;
						
                } while (decision == 'y' || decision == 'Y');     
					
				} else if (seleccion == 6){
					
					do {
						
						limpiarPantalla();
						int id;
						cout << "Ingrese la ID del paciente a modificar" << endl;
                		cin >> id;
                		
                		bool pacienteEncontrado = actualizarPaciente(hospital, id);
                		pacientes* encontradoPaciente = BuscarpacienteID(hospital, id);
                		if (pacienteEncontrado){
                			cout << "Se encontro el paciente" << endl;
                			cout << "ID: " << encontradoPaciente->id << endl;
	                        cout << "Nombre: " << encontradoPaciente->Nombre << endl;
	                        cout << "Apellido: " << encontradoPaciente->Apellido << endl;
	                        cout << "Cedula: " << encontradoPaciente->Cedula << endl;
	                        cout << "Edad: " << encontradoPaciente->Edad << endl;
	                        cout << "Sexo: " << encontradoPaciente->Sexo << endl;
	                        cout << "Esta seguro que quiere modificar a este paciente?" << endl;
                			cin >> decision;
                			
                			if (decision == 'y' || decision == 'Y'){
                				
                				char* nombre = new char[50];
								char* apellido = new char[50];
								char* cedula = new char[20];
								int edad;
								char sexo;
							    
							    cout << "Ingrese el nombre del paciente" << endl;
							    cin.ignore();
							    cin.getline(nombre, 50);
							    cout << "Ingrese el apellido del paciente" << endl;
							    cin.getline(apellido, 50);
							    cout << "Ingrese la cedula del paciente" << endl;
							    cin.getline(cedula, 20);
							    
							    	bool valido;
			                        do{
			                            valido = true;
			                            for (int j = 0; j < hospital->cantidad_pacientes + hospital->cantidad_docs; ++j){
			                                
			                                if (j < hospital->cantidad_pacientes){
			                                    if (strcmp(cedula, hospital->Paciente[j].Cedula) == 0){
			                                        cout << "La cedula ingresada ya existe en pacientes, ingrese otra cedula" << endl;
			                                        cin.getline(cedula, 20);
			                                        valido = false;
			                                        break;
			                                    }
			                                } else {
			                                    int idx = j - hospital->cantidad_pacientes;
			                                    if (strcmp(cedula, hospital->Doctores[idx].Cedula) == 0){
			                                        cout << "La cedula ingresada ya existe en doctores, ingrese otra cedula" << endl;
			                                        cin.getline(cedula, 20);
			                                        valido = false;
			                                        break;
			                                    }
			                                }
			                            }
			                        } while (!valido);
							    
							    cout << "Ingrese la edad del paciente" << endl;
							    cin >> edad;
							    	do {
									
											if(cin.fail());{
			
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											};
							    	if  ((edad < 0) || (edad > 120)){
							    		
							    		cout << "Por favor ingrese un rango entre los 1-120 anos de edad" << endl;
							    		cin >> edad;
							    		
									};
									}while((edad < 0) || (edad > 120));
							    cout << "Ingrese el sexo del paciente (M/F)" << endl;
							    cin >> sexo;
							    
							    	do {
							    	if ( (sexo != 'm') && (sexo != 'M') && (sexo != 'f') && (sexo != 'F') && (sexo != '\n') ){
							    		
							    		cout << "...uh, ingrese un genero valido, M o F" << endl;
							    		cin >> sexo;
							    		
									} else;
									}while ( (sexo != 'm') && (sexo != 'M') && (sexo != 'f') && (sexo != 'F') && (sexo != '\n') );
                				
                				cout << "Estos son los valores que se usted ingreso para reemplazar a los anteriores" << endl;
                				cout << nombre << endl;
                				cout << apellido << endl;
                				cout << cedula << endl;
                				cout << edad << endl;
                				cout << sexo << endl;
                				cout << "De verdad esta seguro que quiere modificar los datos del paciente?" << endl;
                				cin >> decision;
                					
                					if(decision == 'y' || decision == 'Y'){
                						
                						if (strlen(nombre) > 0){
                							strcpy(encontradoPaciente->Nombre, nombre);
										};
										
										if (strlen(apellido) > 0){
                							strcpy(encontradoPaciente->Apellido, apellido);
										};
										
										if (strlen(cedula) > 0){
                							strcpy(encontradoPaciente->Cedula, cedula);
										};
                						
                						if(edad > 0){
                							
                							encontradoPaciente->Edad = edad;
                							
										}
                						
                						if (sexo != '\n'){
                							
                							encontradoPaciente->Sexo = sexo;
                							
										}
										
										cout << "Paciente modificado, la nueva informacion es:" << endl;
										cout << "Nombre: " << encontradoPaciente->Nombre << endl;
	                        			cout << "Apellido: " << encontradoPaciente->Apellido << endl;
	                        			cout << "Cedula: " << encontradoPaciente->Cedula << endl;
	                        			cout << "Edad: " << encontradoPaciente->Edad << endl;
	                        			cout << "Sexo: " << encontradoPaciente->Sexo << endl;
	                        			
	                        			delete[] nombre;
					    				delete[] apellido;
					    				delete[] cedula;
									} else {
										delete[] nombre;
					    				delete[] apellido;
					    				delete[] cedula;
										
									}
							};
                			
						} else {
							cout << "No se encontro el paciente" << endl;
						};
						
						cout << "Quiere modificar otro paciente? (Y/N)" << endl;
						cin >> decision;
					
					} while (decision == 'y' || decision == 'Y');
				} else if (seleccion == 7){
					
					do{
					
						limpiarPantalla();
						listartodospacientes(hospital);
						cout << "Volver a ver la lista? (Y/N)" << endl;
						cin >> decision;
						
					} while (decision == 'y' || decision == 'Y');
					
					
				} else if (seleccion == 8){
					
					do{
					
						limpiarPantalla();
						int id;
						cout << "Ingrese la ID del paciente que va eliminar" << endl;
						cin >> id;
						
						cout << "Esta seguro de querer eliminar a este paciente? (LA ELIMINACION ES IRREVERSIBLE)" << endl;
						cin >> decision;
						
						if (decision == 'y' || decision == 'Y') {
			
							eliminarPaciente(hospital, id);
							bool pacienteEliminado = eliminarPaciente(hospital, id);
							
							if (pacienteEliminado){
						
							cout << "Paciente eliminado con exito" << endl;
							
							} else {
								
								cout << "El paciente no puedo ser eliminado" << endl;
							}
						};
						
						cout << "Desea eliminar otro paciente? (Y/N)" << endl;
					} while (decision == 'y' || decision == 'Y');
				}
			}while (seleccion != 0);
			
			
		} 	else if (seleccion == 2){
			
			do {
			
			limpiarPantalla();
			cout << "Menú de Doctores:" << endl;
			cout << "1. Registrar nuevo doctor" << endl;
			cout << "2. Buscar doctor por ID" << endl;
			cout << "3. Buscar doctores por especialidad" << endl;
			cout << "4. Asignar paciente a doctor" << endl;
			cout << "5. Ver pacientes asignados a doctor" << endl;
			cout << "6. Listar todos los doctores" << endl;
			cout << "7. Eliminar doctor" << endl;
			cout << "0. Volver al menú principal" << endl;
			cin >> seleccion;
			
			if (seleccion == 1){
				
				do{
					
					limpiarPantalla();
						char* nombre = new char[50];
						char* apellido = new char[50];
						char* cedula = new char[20];
						char* especialidad = new char[50];
						int aniosExperiencia;
						float costoConsulta;
						
						cout << "Ingrese el nombre del doctor" << endl;
					    cin.ignore();
					    cin.getline(nombre, 50);
					    cout << "Ingrese el apellido del doctor" << endl;
					    cin.getline(apellido, 50);
					    cout << "Ingrese la cedula del doctor" << endl;
					    cin.getline(cedula, 20);
					    bool valido;
                        do{
                            valido = true;
                            for (int j = 0; j < hospital->cantidad_pacientes + hospital->cantidad_docs; ++j){
                                
                                
                                    if (strcmp(cedula, hospital->Paciente[j].Cedula) == 0){
                                        cout << "La cedula ingresada ya existe en pacientes, ingrese otra cedula" << endl;
                                        cin.getline(cedula, 20);
                                        valido = false;
                                        
                                    };
                                    
                                    if (strcmp(cedula, hospital->Doctores[j].Cedula) == 0){
                                        cout << "La cedula ingresada ya existe en doctores, ingrese otra cedula" << endl;
                                        cin.getline(cedula, 20);
                                        valido = false;
                                        
                                    };
                              	}
							  }  while (!valido);
					    cout << "Ingrese la especialidad del doctor" << endl;
					    cin.getline(especialidad, 50);
					    cout << "Ingrese los anios de experiencia  del doctor" << endl;
					    cin >> aniosExperiencia;
					    	
					   	while (cin.fail() || aniosExperiencia < 0){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Agregue un valor positivo a años de experiencia" << endl;
                            cin >> aniosExperiencia;
                        }
							
					    cout << "Ingresa el costo por consulta que cobra el doctor" << endl;
					    cin >> costoConsulta;
					    
					    while (cin.fail() || costoConsulta < 0){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Valora el trabajo de los doctores, agrega un costo por consulta positivo" << endl;
                            cin >> costoConsulta;
                        }
						
					crearDoctores(hospital, nombre, apellido, cedula, especialidad, aniosExperiencia, costoConsulta);
					
					    doctores* nuevoDoctor = crearDoctores(hospital, nombre, apellido, cedula, especialidad, aniosExperiencia, costoConsulta);
                        if (nuevoDoctor != nullptr){
                            cout << "Doctor registrado exitosamente!" << endl;
                            cout << "ID del paciente: " << nuevoDoctor->id << endl;
                            cout << "Nombre: " << nuevoDoctor->Nombre << endl;
                            cout << "Apellido: " << nuevoDoctor->Apellido << endl;
                            cout << "Cedula: " << nuevoDoctor->Cedula << endl;
                            cout << "Especialidad: " << nuevoDoctor->Especialidad << endl;
                            cout << "Anios de Experiencia: " << nuevoDoctor->Experiencia << endl;
                            cout << "Costo de una consulta: " << nuevoDoctor->consulta_costo << endl;
                        }
                        delete[] nombre;
					    delete[] apellido;
					    delete[] cedula;
					    delete[] especialidad;
						
						cout << "Quiere ingresar otro doctor? (Y/N)" << endl;
						cin >> decision;
						
				} while (decision == 'y' || decision == 'Y');
				
			} else if (seleccion == 2){
			} else if (seleccion == 3){
			} else if (seleccion == 4){
			} else if (seleccion == 5){
			} else if (seleccion == 6){
			} else if (seleccion == 7){
			};
			
			}while (seleccion != 0);
			
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

    return 0;
}
