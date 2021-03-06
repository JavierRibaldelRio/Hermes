#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <limits>

using namespace std;

//Funciones
void imprimirMenuSelector();

void imprimirMenuSelectorArchivo();

void imprimirOpcion(string, int empezar = 0);

int main()
{
	array<string, 4> selectores;

	//Guia del principiante
	selectores[0] = "Algunas cosas basicas\n - sudo -> Pie el acceso a root\n - root -> Nombre del administrador (super usuario)\n - apt -> Para hacer una ación con el gestor de archivos\n\n - Directorio y carpeta significan lo mismo\n - Fichero y archivo significan lo mismo";

	//Actualizar la raspi

	selectores[1] = "Hay distintas formas de actualizar la raspi:\n\t 1.) Actualizar los paquetes y ficheros de los cuales obtienen la información: {sudo apt update}\n\t 2.) Actualizar el sistema: {sudo apt-get upgrade}";

	//configurar la raspi

	selectores[2] = "Para configurar la raspi hay que ejecutar: {sudo raspi-config}";

	//Apagar la rasperry

	selectores[3] = "Apagar:\n\t 1.) {sudo shutdown} : Esto hace que en un minuto la Raspi se apague, para cancelar usar: {shutdown -c}\n\t 2.) {sudo shutdown now}: Apaga la Raspi de forma instantanea\n\t 3.)Apagar la Raspi con temporizador: {sudo shutdown +60 } ; el sesenta es el número de minutos del temporizador\n\n Reiniciar:\n\t -)sudo reboot ";

	int respuestaUsuario = 0;

	while (respuestaUsuario != -1)
	{
		cout << endl;

		imprimirMenuSelector();

		cout << ":";

		cin >> respuestaUsuario;

		system("clear");

		if (respuestaUsuario < -1 || respuestaUsuario > 4)
		{
			cout << "Por favor inserte un valor valido" << endl
				 << endl;
		}

		else if (respuestaUsuario == 4)
		{

			array<string, 11> archivos;

			archivos[1] = "Una ruta es la manera que tiene linux para decir la ubicación de almacenamiento.\n Ejemplo: /home/pi/Desktop/HelloWorld.txt\n\t Esta ruta significa: que en el directorio raiz, el primero representado por una barra hay una carpeta llamada 'home', para indicar el salto entre carpetas se utiliza la /, la cual dentro tien otra llamada pi la cual tiene a su vez una carpeta llamada Desktop (escritorio en inglés) la cual tiene un archivo llamado 'helloworld.txt ";

			archivos[2] = "En la terminal siempre estas dentro de una carpeta, inicialmente te encuentra en el directorio de casa (/home/pi/).\nPara vel las carpetas y archivos de tu actual directorio lo podemos hacer así:\n\t1.){ls}:te ensenya en colores los diferentes tipo de archivos. Un truco para recordarlo es pensar en la palabra LiSta\n\t2.){dir}: ten ensenya con el mismo color todos los archivos. Un truquet per a recordar-ho es pensar en la paraula valenciana DIR. ";

			archivos[3] = "Para mover se utiliza el comando {mv} (MoVer) despues va el archivo o directorio que desea mover y la ruta a la cual desea trasladarlo\n Ejemplo: {mv archivo1.txt recetas_de_cocina/macarrones/} esto moveria el archivo 1 a recetas de cocina y dentro lo pondira en macarrones";
			int submenu = 0;

			archivos[4] = "Para renombra un archivo usamos mv (si como para mover), peonemos el actual nombre del archivo y depues el nuevo.\nEjemplo: mv archivoViejo.pdf  archivoNuevo.pdf";

			archivos[5] = "Eliminar archivo: rm (ReMove) nombre del archivo.\n Ejemplo: rm archivo_a_eliminar.odt\n\tNOTA: como muchos comandos en la terminal puede requerir usar sudo en las carpetas protegidas";

			archivos[6] = "{cd} es el comando para moverte por la carpetas.\nFuncionamiento:{cd Asignaturas/Ingles} Entraría en la carpeta asignaturas la cual tiene que estar en su actual area de trabajo.\nSi se utiliza cd sin especificar la ruta se volvera a la carpeta personal (/home/pi/)";

			archivos[7] = "{pwd} te dice la ruta absoluta de tu area de trabajo.";

			archivos[8] = "Crear un directorio:{mkdir NombreCArpeta}. Recomiendo no poner espacio en la carpeta";

			archivos[9] = "{touch nombredelarchivo.ext}";

			archivos[10] = "Nano es el editor predeterminado para editar archvos, para abrilo hay que poner {nano} en la terminal de comandos";

			cout
				<< "Es recomendable saber lo que es una ruta para estas explicaciones" << endl;

			while (submenu != -1)
			{
				cout << endl;

				cout << "Inserte el numero para aprender sobre los archivos:\n"
					 << endl;

				imprimirMenuSelectorArchivo();

				cout << "Inserte -1 para volver al menu anterior" << endl;

				cout << ":";

				cin >> submenu;

				system("clear");

				if (submenu > 0 && submenu < 11)
				{

					cout << archivos[submenu];

					cout << endl;
				}
				else
				{

					cout << "Inserte un valor valido" << endl;
				}
			}
		}
		else if (respuestaUsuario != -1)
		{

			cout << selectores[respuestaUsuario];

			cout << endl;
		}
	}
	system("clear");
	return 0;
}

void imprimirMenuSelector()
{

	cout << "Inserte un número para aprender a :" << endl
		 << endl;

	cout << "1: Actualizar la raspberry" << endl;

	std::cout << "2: Configurar la raspberry" << endl;

	cout << "3: Apagar la raspberry" << endl;

	cout << "4: Para las opciones de archivos" << endl;

	cout << endl
		 << "Para salir de hermes introduzca -1, para leer unas cosas basicas inserte 0 ." << endl;
}

void imprimirMenuSelectorArchivo()
{

	imprimirOpcion("Rutas", 1);
	imprimirOpcion("Ver archivos");
	imprimirOpcion("Mover Archivos");
	imprimirOpcion("Renombrar archivos");
	imprimirOpcion("Eliminar archivos");
	imprimirOpcion("Navegar por las carpetas");
	imprimirOpcion("Saber en que carpeta estas");
	imprimirOpcion("Crear un directorio");
	imprimirOpcion("Crae un archivo");
	imprimirOpcion("Crear un archivo con nano");
}

void imprimirOpcion(string texto, int empezar)
{
	static int contador = 1;

	if (empezar == 1)
	{
		contador = 1;
	}

	cout << contador << ": " << texto << endl;

	contador++;
}
