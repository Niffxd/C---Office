#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"

void menu(int &op){
	printf("\n---------------------- ADMINISTRACION ----------------------\n\n");
	printf("1.- Registrar Medico.\n");
	printf("2.- Registrar Empleado.\n");
	printf("3.- Registrar Obra Social y Monto.\n");
	printf("4.- Liquidacion de Medicos.\n");
	printf("5.- Empleado con Mayor Registro.\n");
	printf("6.- Salir del Programa.\n\n");
	printf("---------------------- ADMINISTRACION ----------------------\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 7){
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}

main(){
	system("cls");
	int op = 0, b = 1, log = 0, vFecha, dia, mes, anio ,lun, mar, mie, jue, vie, sab, mayReg = 0, contMayus = 0, contMinus = 0, contNum = 0, contEsp = 0, contLet = 0;
	char usr[30], pass[30], mat[30], cadAux[30], nom[30], apel[30];
	bool notFound = true, cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
	while(op != 6){
		menu(op);
		system("cls");
		switch (op){
			case 1:
				Medicos = fopen("Medicos.dat", "a+b");
				
				printf("\nComplete los siguientes datos del Medico:\n\n");
				printf("Nombre: ");
				_flushall();
				scanf("%s", &nom);
				printf("Apellido: ");
				_flushall();
				scanf("%s", &apel);
				strcat(nom, " ");
				strcat(nom, apel);
				strcpy(medico.apellidoYNombre, nom);
				printf("Especialidad: ");
				_flushall();
				scanf("%s", &medico.especialidad);
				system("cls");
				calcularSemana();
				system("cls");
				while(b != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					printf("\nIngrese Matricula: \n");
					printf("\n\ta. Comenzar con una letra minuscula.");
					printf("\n\tb. Tener al menos 2 letras mayusculas.");
					printf("\n\tc. Tener como maximo 3 numeros.");
					printf("\n\td. Minimo 6 y maximo de 10 caracteres de longitud.\n\n");
					printf("Matricula: ");
					_flushall();
					scanf("%s", &mat);					
					printf("\n");
					
					if(strlen(mat) > 10 || strlen(mat) < 6){
						printf("Matricula no cumple con la condicion \"D.\"\n");
					}
					else{
						cumpleD = true;
					}
					
					contNum = contadorNum(mat);
					if(contNum > 3){
						printf("Matricula no cumple con la condicion \"C.\"\n");
					}
					else{
						cumpleC = true;
					}
					
					strcpy(cadAux, mat);
					strupr(cadAux);
					for(int i=0;i<strlen(mat);i++){
						if((mat[i] == cadAux[i]) && (mat[i] != 0  || mat[i] != 1 || mat[i] != 2 || mat[i] != 3 || mat[i] != 4 || mat[i] != 5 || mat[i] != 6 || mat[i] != 7 || mat[i] != 8 || mat[i] != 9)){
							contMayus += 1;
						}
					}
					if(contMayus < 2){
						printf("Matricula no cumple con la condicion \"B.\"\n");
					}
					else{
						cumpleB = true;
					}
					
					if(mat[0] == cadAux[0]){
						printf("Matricula no cumple con la condicion \"A.\"\n");
					}
					else{
						strlwr(cadAux);
						if(mat[0] == 0 || mat[0] == 1 || mat[0] == 2 || mat[0] == 3 || mat[0] == 4 || mat[0] == 5 || mat[0] == 6 || mat[0] == 7 || mat[0] == 8 || mat[0] == 9){
							printf("Matricula no cumple con la condicion \"A.\"\n");
						}
						else{
							if(mat[0] == cadAux[0]){
								cumpleA = true;
							}
							else{
								printf("Matricula no cumple con la condicion \"A.\"\n");
							}
						}
					}
					
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true){
						b = 0;
					}
				}
				
				b = 1;
				
				while(b != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					system("cls");
					printf("\nIngrese contrase%ca: \n", -92);
					printf("\n\ta. Debera contener al menos una letra mayuscula, una letra minuscula y un numero.");
					printf("\n\tb. No podra contener ningun caracter de puntuacion,");
					printf("\n\t   ni acentos, ni espacios. Solo caracteres alfanumericos.");
					printf("\n\tc. Debera tener entre 6 y 32 caracteres.");
					printf("\n\td. No debe tener mas de 3 caracteres numericos consecutivos.");
					printf("\n\te. No debe tener 2 caracteres consecutivos que refieran a letras");
					printf("\n\t   alfabeticamente consecutivas (ascendentemente). Este criterio");
					printf("\n\t   es valido tanto para letras mayusculas, minusculas o combinacion de ambas.\n\n");
					printf("Contrase%ca: ", -92);
					_flushall();
					scanf("%s", &pass);
					
					strcpy(cadAux, pass);
					strupr(cadAux);
					for(int i=0;i<strlen(pass);i++){
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMayus += 1;
						}
					}
					strlwr(cadAux);
					for(int i=0;i<strlen(pass);i++){
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMinus += 1;
						}
					}
					contNum = contadorNum(pass);
					
					if(contMayus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contMinus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contNum < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else{
						cumpleA = true;
					}
					
					validaCarEsp(pass, contEsp);
					if(contEsp >= 1){
						printf("Contrase%ca no cumple con la condicion \"B.\"\n", -92);
					}
					else{
						cumpleB = true;
					}
					
					if(strlen(pass) < 6 || strlen(pass) > 32){
						printf("Contrase%ca no cumple con la condicion \"C.\"\n", -92);
					}
					else{
						cumpleC = true;
					}
					
					numConsecutivos(pass, contNum);
					if(contNum > 3){
						printf("Contrase%ca no cumple con la condicion \"D.\"\n", -92);
					}
					else{
						cumpleD = true;
					}
					
					letConsecutivas(pass, contLet);
					if(contLet >= 1){
						printf("Contrase%ca no cumple con la condicion \"E.\"\n", -92);
					}
					else{
						cumpleE = true;
					}
					
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false || cumpleE == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true && cumpleE == true){
						b = 0;
					}
				}
				strcpy(medico.matricula, mat);
				strcpy(medico.password, pass);
				medico.liquidacion = 0;
				
				fwrite(&medico, sizeof(med), 1, Medicos);
				
				printf("\n\n\tMedico registrado con exito!. Presione una tecla para continuar...");
				getch();
				system("cls");
				
				fclose(Medicos);
				
			break;
			case 2:
				Empleados = fopen("Empleados.dat", "a+b");
				
				printf("\nComplete los siguientes datos del Empleado:\n\n");
				printf("Nombre: ");
				_flushall();
				scanf("%s", &nom);
				printf("Apellido: ");
				_flushall();
				scanf("%s", &apel);
				strcat(nom, " ");
				strcat(nom, apel);
				strcpy(empleado.apellidoYNombre, nom);
				system("cls");
				
				b = 1;
				
				while(b != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					printf("\nIngrese Usuario: \n");
					printf("\n\ta. Comenzar con una letra minuscula.");
					printf("\n\tb. Tener al menos 2 letras mayusculas.");
					printf("\n\tc. Tener como maximo 3 numeros.");
					printf("\n\td. Minimo 6 y maximo de 10 caracteres de longitud.\n\n");
					printf("Usuario: ");
					_flushall();
					scanf("%s", &usr);					
					printf("\n");
					
					if(strlen(usr) > 10 || strlen(usr) < 6){
						printf("Usuario no cumple con la condicion \"D.\"\n");
					}
					else{
						cumpleD = true;
					}
					
					contNum = contadorNum(usr);
					if(contNum > 3){
						printf("Usuario no cumple con la condicion \"C.\"\n");
					}
					else{
						cumpleC = true;
					}
					
					strcpy(cadAux, usr);
					strupr(cadAux);
					for(int i=0;i<strlen(usr);i++){
						if((usr[i] == cadAux[i]) && (usr[i] != 0  || usr[i] != 1 || usr[i] != 2 || usr[i] != 3 || usr[i] != 4 || usr[i] != 5 || usr[i] != 6 || usr[i] != 7 || usr[i] != 8 || usr[i] != 9)){
							contMayus += 1;
						}
					}
					if(contMayus < 2){
						printf("Usuario no cumple con la condicion \"B.\"\n");
					}
					else{
						cumpleB = true;
					}
					
					if(usr[0] == cadAux[0]){
						printf("Usuario no cumple con la condicion \"A.\"\n");
					}
					else{
						strlwr(cadAux);
						if(usr[0] == 0 || usr[0] == 1 || usr[0] == 2 || usr[0] == 3 || usr[0] == 4 || usr[0] == 5 || usr[0] == 6 || usr[0] == 7 || usr[0] == 8 || usr[0] == 9){
							printf("Usuario no cumple con la condicion \"A.\"\n");
						}
						else{
							if(usr[0] == cadAux[0]){
								cumpleA = true;
							}
							else{
								printf("Matricula no cumple con la condicion \"A.\"\n");
							}
						}
					}
					
					
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true){
						b = 0;
					}
				}
				
				b = 1;
				
				while(b != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					system("cls");
					printf("\nIngrese contrase%ca: \n", -92);
					printf("\n\ta. Debera contener al menos una letra mayuscula, una letra minuscula y un numero.");
					printf("\n\tb. No podra contener ningun caracter de puntuacion,");
					printf("\n\t   ni acentos, ni espacios. Solo caracteres alfanumericos.");
					printf("\n\tc. Debera tener entre 6 y 32 caracteres.");
					printf("\n\td. No debe tener mas de 3 caracteres numericos consecutivos.");
					printf("\n\te. No debe tener 2 caracteres consecutivos que refieran a letras");
					printf("\n\t   alfabeticamente consecutivas (ascendentemente). Este criterio");
					printf("\n\t   es valido tanto para letras mayusculas, minusculas o combinacion de ambas.\n\n");
					printf("Contrase%ca: ", -92);
					_flushall();
					scanf("%s", &pass);
					
					strcpy(cadAux, pass);
					strupr(cadAux);
					for(int i=0;i<strlen(pass);i++){
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMayus += 1;
						}
					}
					strlwr(cadAux);
					for(int i=0;i<strlen(pass);i++){
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMinus += 1;
						}
					}
					contNum = contadorNum(pass);
					
					if(contMayus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contMinus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contNum < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else{
						cumpleA = true;
					}
					
					validaCarEsp(pass, contEsp);
					if(contEsp >= 1){
						printf("Contrase%ca no cumple con la condicion \"B.\"\n", -92);
					}
					else{
						cumpleB = true;
					}
					
					if(strlen(pass) < 6 || strlen(pass) > 32){
						printf("Contrase%ca no cumple con la condicion \"C.\"\n", -92);
					}
					else{
						cumpleC = true;
					}
					
					numConsecutivos(pass, contNum);
					if(contNum > 3){
						printf("Contrase%ca no cumple con la condicion \"D.\"\n", -92);
					}
					else{
						cumpleD = true;
					}
					
					letConsecutivas(pass, contLet);
					if(contLet >= 1){
						printf("Contrase%ca no cumple con la condicion \"E.\"\n", -92);
					}
					else{
						cumpleE = true;
					}
					
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false || cumpleE == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true && cumpleE == true){
						b = 0;
					}
				}
				empleado.cantRegistros = 0;
				strcpy(empleado.user, usr);
				strcpy(empleado.password, pass);
				
				fwrite(&empleado, sizeof(emp), 1, Empleados);
				
				printf("\n\n\tEmpleado registrado con exito!. Presione una tecla para continuar...");
				getch();
				system("cls");
				
				fclose(Empleados);
				
			break;
			case 3:
				ObrasSociales = fopen("ObrasSociales.dat", "a+b");
				
				printf("\nIngrese el nombre de la obra social: ");
				_flushall();
				scanf("%s", &obraSocial.nombre);
				
				printf("Ingrese el monto: ");
				_flushall();
				scanf("%f", &obraSocial.monto);
				
				fwrite(&obraSocial, sizeof(obsoc), 1, ObrasSociales);
				system("cls");
				
				fclose(ObrasSociales);
				
				printf("\n\tObra Social registrada con exito!. Presione una tecla para continuar...");
				getch();
				system("cls");
				
			break;
			case 4:
				Medicos = fopen("Medicos.dat", "rb");
				
				if(Medicos == NULL){
					printf("\n\tNingun Medico registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(fread(&medico, sizeof(med), 1, Medicos) != NULL){
						printf("\n\tMedico: %s\n", medico.apellidoYNombre);
						printf("\t  Liquidacion: $ %.2f\n\n", medico.liquidacion);
					}
					
					printf("\n\n\t\tPresione una tecla para volver al menu...");
					getch();
					system("cls");
				}
			break;
			case 5:
				Empleados = fopen("Empleados.dat","rb");
				
				if(Empleados == NULL){
					printf("\n\n\tNingun empleado registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(fread(&empleado, sizeof(emp), 1, Empleados) != NULL){
						if(empleado.cantRegistros > mayReg){
							mayReg = empleado.cantRegistros;
						}
					}
					
					rewind(Empleados);
					
					while(fread(&empleado, sizeof(emp), 1, Empleados) != NULL){
						if(mayReg == empleado.cantRegistros){
							printf("\n\tGanador del bono: \n\n");
							printf("\n\tEmpleado: %s", empleado.apellidoYNombre);
							printf("\n\tCantidad de Registros: %i", empleado.cantRegistros);
						}
					}
					printf("\n\n\tPresione una tecla para continuar...");
					getch();
					system("cls");
				}
				fclose(Empleados);
			break;
		}
	}
	printf("\n\n\n\t\tFin del programa. Presione una tecla para continuar...\n\n\n");
	getch();
}
