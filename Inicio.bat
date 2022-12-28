@echo off
:menu
echo ---------------------- MENU PRINCIPAL ----------------------

echo 1.- Modulo Administracion.
echo 2.- Modulo Recepcion.
echo 3.- Modulo Consultorio.
echo 4.- Salir del Programa.

echo ---------------------- MENU PRINCIPAL ----------------------
SET /P ver=Ingrese opcion: 

if %ver% == 1 START Administracion.exe
if %ver% == 2 START Recepcion.exe
if %ver% == 3 START Consultorio.exe
if %ver% == 4 PAUSE