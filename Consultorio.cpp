#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"

void menu(int &op){
	printf("\n---------------------- CONSULTORIO ----------------------\n\n");
	printf("1.- Iniciar Sesion.\n");
	printf("2.- Llamar paciente.\n");
	printf("3.- Salir del Programa.\n\n");
	printf("---------------------- CONSULTORIO ----------------------\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 4){
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}

main(){
	system("cls");
	int op = 0, b = 1, log = 0, vFecha, dia, mes, anio, bmenu = 1;
	char pass[30], apelYNom[30], mat[30], nom[30], apel[30];
	bool notFound = true, founded = false;
	while(op != 3){
		menu(op);
		switch (op){
			case 1:
				Medicos = fopen("Medicos.dat", "rb");
	
				if(Medicos == NULL){
					printf("\nNingun Medico registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(b != 0){
						if(bmenu == 0){
							printf("\n---------------------- CONSULTORIO ----------------------\n\n");
							printf("1.- Iniciar Sesion.\n");
							printf("2.- Llamar paciente.\n");
							printf("3.- Salir del Programa.\n\n");
							printf("---------------------- CONSULTORIO ----------------------\n\n");
							printf("Ingrese opcion: 1\n");
						}
						printf("\nIngrese Matricula: ");
						_flushall();
						scanf("%s", &mat);
						
						while(fread(&medico, sizeof(med), 1, Medicos) != NULL){
							if(strcmp(mat, medico.matricula) == 0){
								founded = true;
								printf("Ingrese contrase%ca: ", -92);
								scanf("%s", &pass);
								if(strcmp(pass, medico.password) == 0){
									printf("\n\n\tMedico logueado con exito. Presione una tecla para continuar...");
									b = 0;
									log = 1;
									bmenu = 0;
									strcpy(apelYNom, medico.apellidoYNombre);
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(Medicos);
									getch();
									system("cls");
									printf("\n---------------------- CONSULTORIO ----------------------\n\n");
									printf("1.- Iniciar Sesion.\n");
									printf("2.- Llamar paciente.\n");
									printf("3.- Salir del Programa.\n\n");
									printf("---------------------- CONSULTORIO ----------------------\n\n");
									printf("Ingrese opcion: 1\n");
									printf("\nIngrese Matricula: %s\n", mat);
								}
							}
							else{
								founded = false;
							}
						}
						if(founded == false){
							printf("Matricula no registrada. Intente nuevamente...");
							rewind(Medicos);
							bmenu = 0;
							getch();
						}
					system("cls");
					}
				fclose(Medicos);
				}
			break;
			case 2:
				b = 1;
				
				if(log == 0){
					printf("\nMedico no logueado. No se puede realizar ninguna operacion sin loguearse.");
					getch();
					system("cls");
					break;
				}
				else{
					Medicos = fopen("Medicos.dat", "r+b");
					Pacientes = fopen("Pacientes.dat", "r+b");
					Listados = fopen("Listados.dat", "a+b");
					char apelNom[30];
					
					if(Pacientes == NULL){
						printf("\nNo hay pacientes registrados. Presione una tecla para continuar...");
						getch();
						system("cls");
						break;
					}
					else{
						while(b != 0){
							printf("\nIngrese el nombre y apellido del paciente: \n\n");
							printf("Nombre: ");
							_flushall();
							scanf("%s", &nom);
							printf("Apellido: ");
							_flushall();
							scanf("%s", &apel);
							strcat(nom, " ");
							strcat(nom, apel);
							while(fread(&paciente, sizeof(pac), 1, Pacientes) != NULL){
								if(strcmp(nom, paciente.apellidoYNombre) == 0){
									system("cls");
									printf("\n\n\tPaciente encontrado..");
									Sleep(700);
									printf("\n\n\tCargando datos");
									Sleep(700);
									printf(".");
									Sleep(700);
									printf(".");
									Sleep(700);
									printf(".");
									Sleep(700);
									printf(".\n\n\n");
									Sleep(300);
									printf("\t\tApellido y Nombre: %s\n", paciente.apellidoYNombre);
									printf("\t\tNumero de documento (DNI): %i\n", paciente.dni);
									printf("\t\tFecha de Nacimiento: %i/%i/%i\n", paciente.fechaNacimiento.dia, paciente.fechaNacimiento.mes, paciente.fechaNacimiento.anio);
									printf("\t\tLocalidad: %s\n", paciente.localidad);
									printf("\t\tEdad: %i a%cos\n", paciente.edad, -92);
									printf("\t\tPeso: %i kg.\n", paciente.peso);
									printf("\t\tAltura: %i cm.\n", paciente.edad, -92);
									printf("\t\tObra social: %s\n", paciente.obraSocial.nombre);
									printf("\t\tIngrese evolucion del paciente: ");
									scanf("%s", &paciente.evol);
									printf("\t\tFecha de atencion con formato (ddmmaaaa): ");
									_flushall();
									scanf("%i", &vFecha);
									convertirFecha(vFecha, dia, mes, anio);
									paciente.fechaAtencion.dia = dia;
									paciente.fechaAtencion.mes = mes;
									paciente.fechaAtencion.anio = anio;
									paciente.borrado = true;
									fwrite(&paciente, sizeof(pac), 1, Pacientes);
									
									strcpy(paciente.sawBy, apelYNom);
									strcpy(listado.nomMedico, apelYNom);
									strcpy(listado.nomPaciente, paciente.apellidoYNombre);
									fwrite(&listado, sizeof(list), 1, Listados);
									
									rewind(Pacientes);
									
									notFound = false;
									b = 0;
									
									printf("\n\n\t\t\tTurno finalizado... Presione una tecla para continuar");
									getch();
									system("cls");
									
									while(fread(&medico, sizeof(med), 1, Medicos) != NULL){
										if(strcmp(paciente.sawBy, medico.apellidoYNombre) == 0){
											medico.liquidacion += paciente.obraSocial.monto;
											fwrite(&medico, sizeof(med), 1, Medicos);
										}
									}
									break;
								}
								else{
									notFound = true;
								}
							}
							if(notFound == true){
								rewind(Pacientes);
								printf("\nNo se encontro paciente solicitado. Busque otro paciente...");
								getch();
								system("cls");
								printf("\n---------------------- CONSULTORIO ----------------------\n\n");
								printf("1.- Iniciar Sesion.\n");
								printf("2.- Llamar paciente.\n");
								printf("3.- Salir del Programa.\n\n");
								printf("---------------------- CONSULTORIO ----------------------\n\n");
								printf("Ingrese opcion: 2\n");
							}
						}
					}
					fclose(Pacientes);
					fclose(Medicos);
				}
			break;
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin del programa. Presione una tecla para continuar...\n\n\n");
	getch();
}
