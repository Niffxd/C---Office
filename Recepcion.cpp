#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"

void menu(int &op){
	printf("\n---------------------- RECEPCION ----------------------\n\n");
	printf("1.- Iniciar Sesion.\n");
	printf("2.- Registrar Paciente.\n");
	printf("3.- Registrar Turno.\n");
	printf("4.- Listado de Atenciones.\n");
	printf("5.- Salir del Programa.\n\n");
	printf("---------------------- RECEPCION ----------------------\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 6){
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}

main(){
	system("cls");
	int op = 0, b = 1, log = 0, vFecha, dia, mes, anio, horain, minutoin, horaout, minutoout, totalTurnos, bmenu = 1;
	char obsocaux[30], nom[30], apel[30], apelYNom[30], usr[10], pass[10];
	bool notFound = true, founded = false;
	while(op != 5){
		menu(op);
		switch (op){
			case 1:
				Empleados = fopen("Empleados.dat", "rb");
	
				if(Empleados == NULL){
					printf("\nNingun Empleado registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(b != 0){
						if(bmenu == 0){
							printf("\n---------------------- RECEPCION ----------------------\n\n");
							printf("1.- Iniciar Sesion.\n");
							printf("2.- Registrar Paciente.\n");
							printf("3.- Registrar Turno.\n");
							printf("4.- Listado de Atenciones.\n");
							printf("5.- Salir del Programa.\n\n");
							printf("---------------------- RECEPCION ----------------------\n\n");
							printf("Ingrese opcion: 1\n");
						}
						printf("\nIngrese Usuario: ");
						_flushall();
						scanf("%s", &usr);
						
						while(fread(&empleado, sizeof(emp), 1, Empleados) != NULL){
							if(strcmp(usr, empleado.user) == 0){
								founded = true;
								printf("Ingrese contrase%ca: ", -92);
								scanf("%s", &pass);
								if(strcmp(pass, empleado.password) == 0){
									printf("\n\n\tEmpleado logueado con exito. Presione una tecla para continuar...");
									b = 0;
									log = 1;
									bmenu = 0;
									strcpy(apelYNom, empleado.apellidoYNombre);
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(Empleados);
									getch();
									system("cls");
									printf("\n---------------------- RECEPCION ----------------------\n\n");
									printf("1.- Iniciar Sesion.\n");
									printf("2.- Registrar Paciente.\n");
									printf("3.- Registrar Turno.\n");
									printf("4.- Listado de Atenciones.\n");
									printf("5.- Salir del Programa.\n\n");
									printf("---------------------- RECEPCION ----------------------\n\n");
									printf("Ingrese opcion: 1\n");
									printf("\nIngrese Usuario: %s\n", usr);
								}
							}
							else{
								founded = false;
							}
						}
						if(founded == false){
							printf("Usuario no registrado. Intente nuevamente...");
							rewind(Empleados);
							bmenu = 0;
							getch();
						}
					system("cls");
					}
				fclose(Empleados);
				}
			break;
			case 2:
				b = 1;
				
				if(log == 0){
					printf("\nEmpleado no logueado. No se puede realizar ninguna operacion sin loguearse.");
					getch();
					system("cls");
					break;
				}
				else{
					Empleados = fopen("Empleados.dat", "rb");
					
					if(Empleados == NULL){
						printf("\nNingun empleado registrado. Primero registre un empleado en Administracion.");
						getch();
						system("cls");
						break;
					}
					else{
						Pacientes = fopen("Pacientes.dat", "a+b");
						ObrasSociales = fopen("ObrasSociales.dat", "rb");
						
					
						printf("Complete los siguientes datos del paciente:\n\n");
						printf("Nombre: ");
						_flushall();
						scanf("%s", &nom);
						printf("Apellido: ");
						_flushall();
						scanf("%s", &apel);
						strcat(nom, " ");
						strcat(nom, apel);
						strcpy(paciente.apellidoYNombre, nom);
						printf("DNI: ");
						_flushall();
						scanf("%i", &paciente.dni);
						printf("Direccion: ");
						_flushall();
						scanf("%s", &paciente.direccion);
						printf("Localidad: ");
						_flushall();
						scanf("%s", &paciente.localidad);
						system("cls");
						
						while(b != 0){
							printf("Listado de obras sociales: \n\n");
							while(fread(&obraSocial, sizeof(obsoc), 1, ObrasSociales) != NULL){
								printf("\t%s\t\t\t\t\t\t $ %.2f\n\n", obraSocial.nombre, obraSocial.monto);
							}
							
							rewind(ObrasSociales);
							
							printf("\nIngrese una obra social del listado.\n");
							printf("\nObra social: ");
							_flushall();
							scanf("%s", &obsocaux);
							while(fread(&obraSocial, sizeof(obsoc), 1, ObrasSociales) != NULL){
								if(strcmp(obsocaux, obraSocial.nombre) == 0){
									notFound = true;
									break;
								}
								else{
									notFound = false;
								}
							}
							if(notFound == true){
								strcpy(paciente.obraSocial.nombre, obsocaux);
								b = 0;
							}
							else{
								printf("\nObra social no aceptada. Vuelva a ingresar una del listado");
								getch();
								system("cls");
								rewind(ObrasSociales);
							}
						}
						printf("\nEdad: ");
						_flushall();
						scanf("%i", &paciente.edad);
						printf("Altura (en cm): ");
						_flushall();
						scanf("%i", &paciente.altura);
						printf("Peso: ");
						_flushall();
						scanf("%i", &paciente.peso);
						printf("Fecha de nacimiento con formato (ddmmaaaa): ");
						_flushall();
						scanf("%i", &vFecha);
						convertirFecha(vFecha, dia, mes, anio);
						paciente.fechaNacimiento.dia = dia;
						paciente.fechaNacimiento.mes = mes;
						paciente.fechaNacimiento.anio = anio;
						fwrite(&paciente, sizeof(pac), 1, Pacientes);
						printf("\n\n\tPaciente registrado con exito!. Presione una tecla para continuar...");
						getch();
						system("cls");
						
						fclose(Pacientes);
						fclose(ObrasSociales);
						
						while(fread(&empleado, sizeof(emp), 1, Empleados) != NULL){
							if(strcmp(apelYNom, empleado.apellidoYNombre) == 0){
								if(empleado.cantRegistros == NULL || empleado.cantRegistros == 0){
									empleado.cantRegistros = 1;
									fwrite(&empleado, sizeof(emp), 1, Empleados);
								}
								else{
									empleado.cantRegistros += 1;
									fwrite(&empleado, sizeof(emp), 1, Empleados);
								}
							}
						}
					}
				}
				
				fclose(Empleados);
			break;
			case 3:
				Medicos = fopen("Medicos.dat", "r+b");
				Empleados = fopen("Empleados.dat", "rb");
				
				if(Empleados == NULL){
					printf("\nNingun empleado registrado. Primero registre un empleado en Administracion.");
					getch();
					system("cls");
					break;
				}
				else{
					if(log == 0){
						printf("\nEmpleado no logueado. No se puede realizar ninguna operacion sin loguearse.");
						getch();
						system("cls");
						break;
					}
					else{
						if(Medicos == NULL){
							printf("\nNingun Medico registrado. Primero registre un empleado en Administracion.");
							getch();
							system("cls");
							break;
						}
						else{
							system("cls");
							printf("\nListado de medicos y sus respectivos dias y horarios: \n\n");
							while(fread(&medico, sizeof(med), 1, Medicos) != NULL){
								printf("Nombre Completo: %s\n", medico.apellidoYNombre);
								printf("Dias: \n");
								if(medico.diasAtencion.lun == 1){
									printf("\n\tLunes: \n\t\t");
									convertirHora(medico.diasAtencion.lunh.desde, medico.diasAtencion.lunh.hasta, totalTurnos);
									medico.turnos.turnLun = totalTurnos;
									fwrite(&medico, sizeof(med), 1, Medicos);
								}
								if(medico.diasAtencion.mar == 1){
									printf("\n\tMartes: \n\t\t");
									convertirHora(medico.diasAtencion.marh.desde, medico.diasAtencion.marh.hasta, totalTurnos);
									medico.turnos.turnMar = totalTurnos;
									fwrite(&medico, sizeof(med), 1, Medicos);
								}
								if(medico.diasAtencion.mie == 1){
									printf("\n\tMiercoles: \n\t\t");
									convertirHora(medico.diasAtencion.mieh.desde, medico.diasAtencion.mieh.hasta, totalTurnos);
									medico.turnos.turnMie = totalTurnos;
									fwrite(&medico, sizeof(med), 1, Medicos);
								}
								if(medico.diasAtencion.jue == 1){
									printf("\n\tJueves: \n\t\t");
									convertirHora(medico.diasAtencion.jueh.desde, medico.diasAtencion.jueh.hasta, totalTurnos);
									medico.turnos.turnJue = totalTurnos;
									fwrite(&medico, sizeof(med), 1, Medicos);
								}
								if(medico.diasAtencion.vie == 1){
									printf("\n\tViernes: \n\t\t");
									convertirHora(medico.diasAtencion.vieh.desde, medico.diasAtencion.vieh.hasta, totalTurnos);
									medico.turnos.turnVie = totalTurnos;
									fwrite(&medico, sizeof(med), 1, Medicos);
								}
								if(medico.diasAtencion.sab == 1){
									printf("\n\tSabado: \n\t\t");
									convertirHora(medico.diasAtencion.sabh.desde, medico.diasAtencion.sabh.hasta, totalTurnos);
									medico.turnos.turnSab = totalTurnos;
									fwrite(&medico, sizeof(med), 1, Medicos);
								}
							}
							printf("Presione una tecla para continuar...");
							getch();
							system("cls");
						}
					}
				}
				fclose(Medicos);
				fclose(Empleados);
					
			break;
			case 4:
				Medicos = fopen("Medicos.dat", "rb");
				Pacientes = fopen("Pacientes.dat", "rb");
				Empleados = fopen("Empleados.dat", "rb");
				Listados = fopen("Listados.dat", "rb");
				
				founded = false;
				
				if(Empleados == NULL){
					printf("\nNingun Empleado registrado. Primero registre un empleado en Administracion.");
					getch();
					system("cls");
					break;
				}
				else{
					if(Medicos == NULL){
						printf("\nNingun Medico registrado. Primero registre un empleado en Administracion.");
						getch();
						system("cls");
						break;
					}
					else{
						if(Pacientes == NULL){
							printf("\nNingun Paciente registrado. Primero registre un empleado.");
							getch();
							system("cls");
							break;
						}
						else{
							if(Listados == NULL){
								printf("\nNingun listado registrado. Presione una tecla para continuar...");
								getch();
								system("cls");
								break;
							}
							else{
								printf("Ingrese fecha de listado (ddmmaaaa): ");
								scanf("%i", &vFecha);
								convertirFecha(vFecha, dia, mes, anio);
								printf("Fecha: %i/%i/%i.\n\n", dia, mes, anio);
								while(fread(&paciente, sizeof(pac), 1, Pacientes) != NULL){
									if(dia == paciente.fechaAtencion.dia){
										if(mes == paciente.fechaAtencion.mes){
											if(anio == paciente.fechaAtencion.anio){
												printf("Medico: %s", medico.apellidoYNombre);
												while(fread(&listado, sizeof(list), 1, Listados) != NULL){
													if(strcmp(medico.apellidoYNombre, listado.nomMedico) == 0){
														printf("Paciente: %s\n", listado.nomPaciente);
													}
												}
												rewind(Listados);
												founded = true;
											}
										}
									}
								}
								if(founded == false){
									printf("No hay registros para esta fecha.");
								}
							}
						}
					}
			 	}
				fclose(Medicos);
				fclose(Pacientes);
				fclose(Listados);
				fclose(Empleados);
			break;
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin del programa. Presione una tecla para continuar...\n\n\n");
	getch();
}
