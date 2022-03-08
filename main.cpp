
#include <iostream>
#include <fstream>

#include "ListaDeListas.h"
#include "Cabecera.h"
#include "List7.h"
#include "Student.h"

void leerDefilevo(ListaDeListas<Student>& materias)
{
	ifstream file;

	char nombres[20];

	string titulo;
	bool start = true;
	string estudiantes;
	Student* materia = new Student();
	
	file.open("filevoClases.txt");

	if (!file)
		cout << "No se puede abrir";
	else
		while (!file.eof() && file >> nombres)
		{
			if (strlen(nombres)<2 || strcmp(nombres,"start"))
			{
				titulo = nombres;
				Student* materia = new Student(1, titulo);
				start = false;
			}
			else
			{
				start = false;
				int i = 0;
				while (i < strlen(nombres))
				{
					if (isdigit(i) == true)
					{
						start = true;
					}
					i++;
				}
				if (start == false)
				{
					Student* estudiante = new Student(1, nombres);
					materias.addDatoEnLista(materia, estudiante);
				}
			}
		}
	file.close();
}

/*
void leerDefilevo2(ListaDeListas<Student>& materias)
{
	ifstream file;

	string nombres;

	string titulo;
	bool start = true;
	bool EsNumero = true;
	Student* materia = new Student();
	Lista8<Student> materias;
	int num=10;

	file.open("filevoClases.txt");

	if (!file)
		cout << "No se puede abrir";
	else
		while (!file.eof() && file >> nombres)
		{

			if ((start == true))
			{
				titulo = nombres;
				materias.addBack(new Student(1, nombres));
				start = false;
				
			}
			else if (num > 0 && start == false && EsNumero == false)
			{
				Student* estudiante = new Student(1, nombres);
				materias.buscarRecursivamente();
				Student* materia = new Student(1, titulo);
				materias.addDatoEnLista(materia, estudiante);
				if (num == 1)
				{
					start = true;
					EsNumero = true;
				}
			}
			num = num - 1;
			if (nombres.length()==1)
			{
				num = stoi(nombres);
				EsNumero = false;
				
			}
		}
	file.close();
}
*/

void leerDefilevo3(ListaDeListas<string>& materias)
{
	ifstream file;
	string criterio, nombres;
	int cant;

	file.open("FILENAME.txt");

	if (!file)
		cout << "No se puede abrir";
	else
		while (!file.eof())
		{
			file >> criterio;
			file >> cant;
			
			for (int i = 0; i < cant; i++)
			{
				file >> nombres;
				//materias.addDatoEnLista();
			}
		}
	file.close();
}

int main()
{
    ListaDeListas<Student> materias;

	Student* materia1 = new Student(1, "CALCULO");
	Student* materia2 = new Student(2, "FISICA");
	Student* materia3 = new Student(3, "ESTRUCTURA");
	Student* materia4 = new Student(2, "FISICA");

	Student* persona1 = new Student(155, "pedro");
	Student* persona2 = new Student(242, "juan");
	Student* persona3 = new Student(341, "rosa");
	Student* persona4 = new Student(412, "maria");
	Student* persona5 = new Student(823, "julieta");
	Student* persona6 = new Student(412, "jose");
	Student* persona7 = new Student(823, "carmen");
	Student* persona8 = new Student(823, "lucas");

	materias.addDatoEnLista(materia1, persona1);
	materias.addDatoEnLista(materia1,persona2);
	materias.addDatoEnLista(materia1, persona3);
	materias.addDatoEnLista(materia2, persona4);
	materias.addDatoEnLista(materia2, persona5);
	materias.addDatoEnLista(materia3, persona6);
	materias.addDatoEnLista(materia3, persona7);
	materias.addDatoEnLista(materia2, persona8);

	materias.mostrar(Student::mostrar);

	


	return 0;
}
