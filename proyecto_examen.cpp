/*
    realizar un df en donde pida el nombre de un alumno junto con 5 calificaciones utilizando; posteriormente indique si aprobó o no,
    tomando en cuenta que la cantidad minima aprobatoria es de 70, en caso de aprobar que indique: "Excelente" si obtuvo un 100,
    "muy bien" si es 90, "Bien" si es 80 o bien regular si es 70; en caso de un valor menor a 70 indicar Insuficiente. 
    El usuario podrá calcular los promedios hasta que decida ya no hacerlo. Mostrar los mensajes (nombre del alumno, 
    promedio y mensaje correspondiente). 
*/

/*
  y si, lo se, hay muchas cosas que están de mas y que se pueden simplificar, pero había poco tiempo para entregar así que este es el resultado <:-D
*/

#include <iostream>
#include <stdlib.h>		//librerias
#include <windows.h>
#include <stdio.h>

using namespace std;


//declaracion de funciones

	bool AjustarVentana(int Ancho, int Alto); 
	void GoToXY(int x, int y);		
	void marcos();					//dibuja los marcos de la ventana
	void pruebas(); 				//función para pruebas de subprocesos
	void menu();					//funcion de menu principal
	void indicar_materias(); 		//se le pide al usuario que indique las materias que se vana  evaluar
	void usuarios();
	void promedios();
	void errors();
	void new_alumnos();	//funcion para agregar alumnos al arreglo
	void calificaciones();

//

//variables de tipo publico

	int cant_alumnos = 0;
	int cant_materias = 0;
	
//


struct usuario
{
	
	char catedratico[35];
	int edad;
	char direccion[45];
	char especialidad[25];
	char contacto[15];
	
}
catedratico = {"Usuario por defecto",0,"na","na","na"}
;

struct materias
{
	
	char asignatura[18]; //se guarda el nombre de la materia
	double val_calif;	//se guarda el valor de la calificacion	individual de cada alumno
	double promedio_grupo;	//se guarda el valor del promedio del grupo
	
}materia[5];

struct estudiante
{
	
	char nombre [30];
	int edad;
	char escuela_proc[30];
	char contacto[15];
	char tutor[30];
	struct materias calificacion;
	double promedio_gen;
	
}alumnos[100];

int main(int argc, const char** argv)
{
	AjustarVentana(150,40);
	//errors();
	//pruebas();
	menu();
	//new_alumnos();
	//usuarios();
	return 0;
}

bool AjustarVentana(int Ancho, int Alto)
{
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;

    // Obtener el handle de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustar el buffer al nuevo tamaño
    SetConsoleScreenBufferSize(hConsola, Coordenada);

    // Cambiar tamaño de consola a lo especificado en el buffer
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}

void GoToXY(int x, int y) //GoToXY para identificacion de pocision en consola
{  
    HANDLE hCon;  //se llama a el identificador identificado con el comando HANDLE
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void marcos(){
	
    //dibujado de lineas horizontales
    for(int i = 2; i < 148; i++)
    {
        GoToXY(i,3); printf("%c", 178);
        GoToXY(i,38); printf("%c", 178);
    }

    //dibujado de lineas verticales
    for(int i = 4; i < 38; i++)
    {
        GoToXY(2,i); printf("%c", 178);
        GoToXY(3,i); printf("%c", 178);
        GoToXY(147,i); printf("%c", 178);
        GoToXY(146,i); printf("%c", 178);
    }   
	  
}


void menu()
{
	
	system("color 1F");
	marcos();
	
	//dibujado de marcos formularios y estilos

		//dibujo de marco interior para encabezado
			//lineas horizontales
			for(int i = 45; i < 106; i++)
			{
				GoToXY(i,12); printf("%c", 219);
				GoToXY(i,18); printf("%c", 219);
				GoToXY(i,22); printf("%c", 219);
			}
			//lineas vesticales del recuadro
			for(int i = 13; i < 22; i++)
			{
				GoToXY(45,i); printf("%c", 219);
				GoToXY(105,i); printf("%c", 219);
			}
		//
	
		GoToXY(46,13); cout<<"EEEEEE SSSSSSSS  CCCCCC HH   HH    OO       OO     LL";
		GoToXY(46,14); cout<<"EE     SSSS     CCC     HH   HH  OO  OO   OO  OO   LL";
		GoToXY(46,15); cout<<"EEEE   SSSSSSSS CCC     HHHHHHH OO    OO OO    OO  LL";
		GoToXY(46,16); cout<<"EE         SSSS CCC     HH   HH  OO  OO   OO  OO   LL";
		GoToXY(46,17); cout<<"EEEEEE SSSSSSSS  CCCCCC HH   HH    OO       OO     LLLLLL";
	
		GoToXY(47,20); cout<<"Sistema rapido de calificaciones escolares";
		
		//dibujado de marcos y contornos para formulario de menú
			
			//lineas horizontales
			for(int i = 15; i < 135; i++)
			{
				GoToXY(i,24); printf("%c",205);
				GoToXY(i,26); printf("%c",205);
				GoToXY(i,28); printf("%c",205);
				GoToXY(i,30); printf("%c",205);
			}
			for(int i = 15; i< 134; i++)
			{
				GoToXY(i+1,25); printf("%c",219); //linea que va en el título del menú
			}
			
			//lineas verticales
			for(int i = 24; i <31; i++)
			{
				GoToXY(15,i); printf("%c",186);
				GoToXY(55,i); printf("%c",186);
				GoToXY(95,i); printf("%c",186);
				GoToXY(134,i); printf("%c",186);
			}
			
			GoToXY(61,25); cout<<"|  Menu principal de opciones  |";
			GoToXY(20,27); cout<<"a) Asignar materias a evaluar";
			GoToXY(59,27); cout<<"b) Asignar calificaciones";
			GoToXY(98,27); cout<<"c) Consultar promedios";
			GoToXY(20,29); cout<<"d) Agregar alumnos";
			GoToXY(59,29); cout<<"e) Modificar usuario";
			GoToXY(96,29); cout<<"Indique la opcion deseada:    ";
			
		//
	
	//
	
	//condicionales para seleccion de respuesta
	
		char respuesta; //variable para validar la respuesta
		
		GoToXY(125,29); cin>>respuesta;
		
		if((respuesta == 'a')||(respuesta == 'A'))
		{
			system("cls");
			indicar_materias();
		}
		if((respuesta == 'b')||(respuesta == 'B'))
		{
			system("cls");
			calificaciones();
		}
		if((respuesta == 'c')||(respuesta == 'C'))
		{
			system("cls");
			promedios();
		}
		if((respuesta == 'd')||(respuesta == 'D'))
		{
			
			system("cls");
			new_alumnos();
		}
		if((respuesta == 'e')||(respuesta == 'E'))
		{
			system("cls");
			usuarios();
		}
		else
		{
			system("cls");
			errors();
			GoToXY(65,34); system("pause");
			system("cls");
			menu();
		}
		
	//
		
		GoToXY(70,38); cin.get();

}

void errors(){

    //VENTANA DE CUADRO PARA ERRORES
    system("cls");
    system("color 0C");
    marcos();

    for(int i = 3; i < 146; i++){
        //lineas horizontales
        GoToXY(i,3); printf("%c", 219);
        GoToXY(i,4); printf("%c", 219);
        GoToXY(i,5); printf("%c", 219);
        GoToXY(i,6); printf("%c", 219);

        GoToXY(i,34); printf("%c", 219);
        GoToXY(i,35); printf("%c", 219);
        GoToXY(i,36); printf("%c", 219);
        GoToXY(i,37); printf("%c", 219);

    }

    //lineas verticales
    for(int i = 4; i < 34; i++){

        GoToXY(4,i); printf("%c", 219);
        GoToXY(5,i); printf("%c", 219);

        GoToXY(144,i); printf("%c", 219);
        GoToXY(145,i); printf("%c", 219);

    }

    GoToXY(47,11); cout<<"|  ******  ******   ******    ***    ******  |";
    GoToXY(47,12); cout<<"|  **      **   **  **   **  ** **   **   ** |";
    GoToXY(47,13); cout<<"|  ****    **  **   **  **  **   **  **  **  |";
    GoToXY(47,14); cout<<"|  **      *****    *****    ** **   *****   |";
    GoToXY(47,15); cout<<"|  ******  **  **   **  **    ***    **  **  |";

    GoToXY(40,20); cout<<"+============================================================+";
    GoToXY(40,21); cout<<"|     EL COMANDO EJECUTADO POR EL USUARIO NO ESTA  DENTRO    |";
    GoToXY(40,22); cout<<"|     DEL RANGO DE  OPCIONES O NO HA SIDO DEFINIDA POR EL    |";
    GoToXY(40,23); cout<<"|     SISTEMA                                                |";
    GoToXY(40,24); cout<<"+============================================================+";
    GoToXY(40,25); cout<<"|     ERROR DE ACCESIBILIDAD INTENTE DE NUEVO                |";
    GoToXY(40,26); cout<<"+============================================================+";

}

void new_alumnos()
{
	
	char respuesta;
	
	int i = cant_alumnos; //numero indice para arreglo de alumnos
	
	do
	{

		system("color 80");
		marcos();
		
		GoToXY(49,8);  cout<<"+============================================+";
		GoToXY(49,9);  cout<<"|============================================+";
		GoToXY(49,10); cout<<"|       MODULO DE INFORMACION DE ALUMNO      |";
		GoToXY(49,11); cout<<"|============================================+";
		GoToXY(49,12); cout<<"|============================================+";
		
		// formulario para informacion de alumno
		
			//LINEAS HORIZONTALES
			for(int i = 47; i < 97; i++)
			{
				GoToXY(i,18); printf("%c", 205);
				GoToXY(i,20); printf("%c", 205);
				GoToXY(i,22); printf("%c", 205);
				GoToXY(i,24); printf("%c", 205);
				GoToXY(i,26); printf("%c", 205);
				GoToXY(i,28); printf("%c", 205);
				GoToXY(i,30); printf("%c", 205);
			}
			
			//lineas verticales
			for(int i = 18; i < 31; i++)
			{
				GoToXY(47,i); printf("%c", 186);
				GoToXY(71,i); printf("%c", 186);
				GoToXY(96,i); printf("%c", 186);
			}
		
		//
		
		cin.ignore();
		GoToXY(49,19); cout<<"Nombre del alumno";
		GoToXY(49,21); cout<<"Edad del alumno";
		GoToXY(49,23); cout<<"Escuela de proedencia";
		GoToXY(49,25); cout<<"Medio de contacto";
		GoToXY(49,27); cout<<"Tutor del alumno";
		GoToXY(49,29); cout<<"Agragar otro alumno?";
		
		//=============================================================================
		
		GoToXY(72,19); cin.getline(alumnos[i].nombre,30,'\n');
		GoToXY(72,21); cin>>alumnos[i].edad;	GoToXY(79,37); cin.ignore();
		GoToXY(72,23); cin.getline(alumnos[i].escuela_proc,30,'\n');
		GoToXY(72,25); cin.getline(alumnos[i].contacto,15,'\n');
		GoToXY(72,27); cin.getline(alumnos[i].tutor,30,'\n'); 
		GoToXY(72,29); cin>>respuesta;
		
		i++;
		cant_alumnos += 1;

		system("cls");
		
	}while((respuesta == 's')||(respuesta == 'S'));
	
	menu();
}


void usuarios()
{	
	system("color 80");
	char respuesta;
	
	respuesta = 's';

	marcos();
	
	GoToXY(49,8);  cout<<"+============================================+";
	GoToXY(49,9);  cout<<"|============================================+";
	GoToXY(49,10); cout<<"|      MODULO DE INFORMACION DE USUARIOS     |";
	GoToXY(49,11); cout<<"|============================================+";
	GoToXY(49,12); cout<<"|============================================+";

	// formulario para informacion de alumno
	
		//LINEAS HORIZONTALES
		for(int i = 47; i < 97; i++)
		{
			GoToXY(i,18); printf("%c", 205);
			GoToXY(i,20); printf("%c", 205);
			GoToXY(i,22); printf("%c", 205);
			GoToXY(i,24); printf("%c", 205);
			GoToXY(i,26); printf("%c", 205);
			GoToXY(i,28); printf("%c", 205);
			GoToXY(i,30); printf("%c", 205);
		}
		
		//lineas verticales
		for(int i = 18; i < 31; i++)
		{
			GoToXY(47,i); printf("%c", 186);
			GoToXY(96,i); printf("%c", 186);
		}
		for(int i=18; i < 29; i++)
		{
			GoToXY(71,i); printf("%c", 186);
		}
	//

	GoToXY(72,19); cout<<catedratico.catedratico;
	GoToXY(72,21); cout<<catedratico.edad;
	GoToXY(72,23); cout<<catedratico.direccion;
	GoToXY(72,25); cout<<catedratico.especialidad;
	GoToXY(72,27); cout<<catedratico.contacto;

	cin.ignore();
	GoToXY(49,19); cout<<"Nombre del Catedratico";
	GoToXY(49,21); cout<<"Edad del catedratico";
	GoToXY(49,23); cout<<"Direccion";
	GoToXY(49,25); cout<<"Area de Especialidad";
	GoToXY(49,27); cout<<"medio de contacto";

	GoToXY(101,17); cout<<"Desea modificar el ususario   | s | n |     |";
	GoToXY(140,17); cin>>respuesta;

	if((respuesta == 's')||(respuesta == 'S'))
	{
		cin.ignore();

		GoToXY(72,19); cin.getline(catedratico.catedratico,35,'\n');
		GoToXY(72,21); cin>>catedratico.edad; GoToXY(79,37); cin.ignore();
		GoToXY(72,23); cin.getline(catedratico.direccion,45,'\n');
		GoToXY(72,25); cin.getline(catedratico.especialidad,25,'\n');
		GoToXY(72,27); cin.getline(catedratico.contacto,15,'\n');
		GoToXY(50,29); cout<<"El usuario ha sido modificado";

		GoToXY(72,29); cout<<"usuario modificado"; GoToXY(102,29); system("pause");
	}
	else
	{
		system("cls");
		menu();
	}
	system("cls");
	menu();
}


void calificaciones()
{
	marcos();
	system("color 0E");

	GoToXY(49,4); cout<<"+============================================+";
	GoToXY(49,5); cout<<"|============================================+";
	GoToXY(49,6); cout<<"|   MODULO DE ASIGNACION DE CALIFICACIONES   |";
	GoToXY(49,7); cout<<"|============================================+";
	GoToXY(49,8); cout<<"|============================================+";

	int h = 11; //coordenada 'y' para la linea de la tabla, que se modifica de acuerdo a cantidad de alumno
	int l = 0;  //cantidad de lineas
	

	//condicional en caso de tener 0 alumnos a evaluar
	
		if(cant_alumnos == 0)
		{
			GoToXY(49,9);  cout<<"|        No existen alumnos a evaluar        |";
			GoToXY(49,10); cout<<"|============================================+";
			GoToXY(75,37); system("pause");
			system("cls");
			menu();
		}
		if(cant_materias == 0)
		{
			GoToXY(49,9);  cout<<"|       No existen materias a evaluar        |";
			GoToXY(49,10); cout<<"|============================================+";
			GoToXY(75,37); system("pause");
			system("cls");
			menu();
		}
		else
		{
			//dibujado de tabla para alumnos y calificaciones

				//dibujado de tabla dinamica

					//titulos de tabla
						int t = 41;
						GoToXY(6,9); cout<<" ALUMNO ";
						for(int i = 0; i <= cant_materias; i++)
						{
							GoToXY(t,9); cout<<materia[i].asignatura;
							t = t + 21;
						}

					//
					while(l <= cant_alumnos)
					{
						for(int i = 5; i < 145; i++)
						{
							GoToXY(i,h); printf("%c", 196);
						}
						h = h+2;
						l++;
					}
					for(int i = 10; i < h; i++)	//lineas verticales de la tabla
					{
						GoToXY(5,i);   printf("%c", 179);
						GoToXY(40,i);  printf("%c", 179);
						GoToXY(61,i);  printf("%c", 179);
						GoToXY(82,i);  printf("%c", 179);
						GoToXY(103,i); printf("%c", 179);
						GoToXY(124,i); printf("%c", 179);
						GoToXY(144,i); printf("%c", 179);
					}

				//
			//
			int d = 12;
			int k = 0;
			//llenado de la tabla con datos de alumnos
			
				for(int i = 0; i <= cant_alumnos; i++)
				{
					GoToXY(9,d); cout<<alumnos[k].nombre;
					d = d + 2;
					k++;
				}

			//
			k = 0;
			d = 12;
			t = 42;
			double suma;
			double promedio;
			//proceso para pedir calificaciones

				for(int i = 0; i < cant_alumnos; i++)
				{
					suma = 0;
					promedio = 0;
					t = 42;
					for(int j = 0; j < cant_materias; j++)
					{
						GoToXY(t,d); cin>>alumnos[k].calificacion.val_calif;
						t = t + 21;
						suma = suma + alumnos[k].calificacion.val_calif;
					}
					promedio = suma / 5;
					alumnos[i].promedio_gen = promedio;
					d = d + 2;
					k++;
				}

			//
		
		}
		
	//

	
	GoToXY(75,37); system("pause");
	system("cls");
	GoToXY(65,37); system("ipconfig/flushdns");
	menu();
}


void indicar_materias()
{
	
	marcos();
	char respuesta;
	
	GoToXY(49,8);  cout<<"+============================================+";
	GoToXY(49,9);  cout<<"|============================================+";
	GoToXY(49,10); cout<<"|      MODULO DE ASIGNACION DE MATERIAS      |";
	GoToXY(49,11); cout<<"|============================================+";
	GoToXY(49,12); cout<<"|============================================+";
	GoToXY(49,13); cout<<"|Desea continuar con el proceso  | s | n |   |";
	GoToXY(49,14); cout<<"|============================================+";
	GoToXY(92,13); cin>>respuesta;

	if((respuesta == 's')||(respuesta == 'S'))
	{
		// formulario para indicar las materias
	
			//LINEAS HORIZONTALES
			for(int i = 47; i < 97; i++)
			{
				GoToXY(i,18); printf("%c", 205);
				GoToXY(i,20); printf("%c", 205);
				GoToXY(i,22); printf("%c", 205);
				GoToXY(i,24); printf("%c", 205);
				GoToXY(i,26); printf("%c", 205);
				GoToXY(i,28); printf("%c", 205);
				GoToXY(i,30); printf("%c", 205);
			}
			
			//lineas verticales
			for(int i = 18; i < 31; i++)
			{
				GoToXY(47,i); printf("%c", 186);
				GoToXY(96,i); printf("%c", 186);
			}
			for(int i=18; i < 29; i++)
			{
				GoToXY(71,i); printf("%c", 186);
			}
		//

		int k = 1;		//contador para impresión en pantalla del numero de materia
		int m = 19;

		for(int i = 0; i <= 4; i++)
		{
			//texto en tabla
			GoToXY(48,m); cout<<"Materia "<<k<<" a evaluar";
			m = m + 2;
			k++;
		}
		m = 19; //la igualo a la posicion inicial de nuevo
 		for(int i = 0; i <= 4; i++)
		{
			GoToXY(72,m); cin>>materia[i].asignatura; //para llenado de informacion y arreglo de la estructura
			cin.ignore();							  //para no saturar el buffer y ahogar la salida
			m = m + 2;
			cant_materias = cant_materias + 1;
		}

		GoToXY(48,29); cout<<"Materias asignadas con exito";

		GoToXY(65,37); system("pause");

		system("cls");
		menu();

	}
	else
	{
		system("cls");
		menu();
	}
	

	/*
	for(i = 0; i <= no_alumnos; i++)
	{
		GoToXY(27,m); cout<<"|\t                             |                 |                 |";
		GoToXY(28,m); cout<<alumnos[i].nombre; GoToXY(75,m); cout<<alumnos[i].edad; GoToXY(88,m); cout<<alumnos[i].promedio_gen;
		m++;
	}
	*/
	
	GoToXY(37,60); system("pause");
	
}

void promedios()
{
	//aquí se imprime en una tabla los promedios y estatus de cada alumno

	marcos();
	system("color 02");

	GoToXY(49,4); cout<<"+============================================+";
	GoToXY(49,5); cout<<"|============================================+";
	GoToXY(49,6); cout<<"|       MODULO DE CONSULTA DE PROMEDIOS      |";
	GoToXY(49,7); cout<<"|============================================+";
	GoToXY(49,8); cout<<"|============================================+";

	int h = 11; //coordenada 'y' para la linea de la tabla, que se modifica de acuerdo a cantidad de alumno
	int l = 0;  //cantidad de lineas
/*
	cant_materias = 5;
	cant_alumnos = 6;
*/

	if(cant_alumnos == 0)
	{
		GoToXY(49,9);  cout<<"|        No existen alumnos a evaluar        |";
		GoToXY(49,10); cout<<"|============================================+";
		GoToXY(75,37); system("pause");
		system("cls");
		menu();
	}
	if(cant_materias == 0)
	{
		GoToXY(49,9);  cout<<"|       No existen materias a evaluar        |";
		GoToXY(49,10); cout<<"|============================================+";
		GoToXY(75,37); system("pause");
		system("cls");
		menu();
	}
	else
	{

		//titulos de la tabla

			GoToXY(21,9); cout<<" Alumno "; GoToXY(56,9); cout<<" Promedio "; GoToXY(91,9); cout<<" estatus ";

		//
		
		//lineas orizontales dinamicas

			while(l <= cant_alumnos)
			{
				for(int i = 20; i < 125; i++)
				{
					GoToXY(i,h); printf("%c", 196);
				}
				h = h+2;
				l++;
			}
		//
		//lineas verticales dinamicas

			for(int i = 10; i < h; i++)	//lineas verticales de la tabla
			{
				GoToXY(20,i);    printf("%c", 179);
				GoToXY(55,i);    printf("%c", 179);
				GoToXY(90,i);    printf("%c", 179);
				GoToXY(124,i);   printf("%c", 179);
				
			}

		//

		int d = 12;
		int k = 0;
		//llenado de la tabla con datos de alumnos
		
			for(int i = 0; i < cant_alumnos; i++)
			{
				GoToXY(21,d); cout<<alumnos[k].nombre;
				GoToXY(58,d); cout<<alumnos[k].promedio_gen;

				if(alumnos[k].promedio_gen < 70)
				{
					GoToXY(92,d); cout<<"No aprobado";
				}
				if((alumnos[k].promedio_gen >= 70)&&(alumnos[k].promedio_gen <= 80))
				{
					GoToXY(92,d); cout<<"Bien/Regular";
				}
				if((alumnos[k].promedio_gen >= 80)&&(alumnos[k].promedio_gen <= 90))
				{
					GoToXY(92,d); cout<<"Bien";
				}
				if((alumnos[k].promedio_gen >= 90)&&(alumnos[k].promedio_gen <= 100))
				{
					GoToXY(92,d); cout<<"Muy Bien";
				}
				if(alumnos[k].promedio_gen >= 100)
				{
					GoToXY(92,d); cout<<"Excelente";
				}

				d = d + 2;
				k++;
			}

		//

	}
	GoToXY(75,37); system("pause");
	system("cls");
	menu();
}





//void pruebas()
//{
//	
//	int i = 0;
//	int m = 17;
//	int n = 18;
//	double suma;
//	
//	for(int e = 0; e <= 4; e++)
//	{
//		
//		GoToXY(27,m); cout<<"materia a calificar: "<<materia[e].asignatura<<endl; 
//		GoToXY(27,n); cout<<"calificaion: "; cin>>alumnos[i].calificacion.val_calif;
//		GoToXY(27,m); cin.ignore();
//		
//		suma = suma + alumnos[i].calificacion.val_calif;
//		
//		m = m + 2;
//		n = n + 2;
//	}	
//}
