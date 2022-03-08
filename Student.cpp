#include "Student.h"

Student::Student(int ci, string nombre)
{
	this->ci = ci;
	this->nombre = nombre;
}

Student::Student(int ci)
{
	this->ci = ci;
}


Student::Student()
{

}

Student::~Student()
{

}

int Student::getCi()
{
	return ci;
}

string Student::getNombre()
{
	return nombre;
}

void Student::mostrar()
{
	cout << "Student:" << endl;
	cout << "Ci: " << ci << endl;
	cout << "nombre: " << nombre << endl;
}

void Student::mostrarNum()
{
	cout << nombre << endl;
}

bool Student::operator==(Student* Student)
{
	return nombre.compare(Student->nombre);
}

bool Student::operator>(Student* Student)
{
	return ci > Student->ci;
}

bool Student::cmpCiAsc(Student* c1, Student* c2)
{
	return c1->ci > c2->ci;
}

bool Student::cmpCiDes(Student* c1, Student* c2)
{
	return c1->ci < c2->ci;
}

void Student::mostrar(Student* Student)
{
	if (Student != NULL)
	{
		Student->mostrar();
	}
}

void Student::mostrarNum(Student* Student)
{
	if (Student != NULL)
	{
		Student->mostrarNum();
	}
}

bool Student::operator<(Student* Student)
{
	return ci < Student->ci;
}
