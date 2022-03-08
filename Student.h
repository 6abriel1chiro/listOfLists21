#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int ci;
	string nombre;
public:
	Student(int ci, string nombre);
	Student(int ci);
	Student();
	~Student();
	int getCi();
	string getNombre();
	void mostrar();
	void mostrarNum();
	bool operator==(Student* Student);
	bool operator>(Student* Student);
	bool operator<(Student* Student);
	static bool cmpCiAsc(Student* c1, Student* c2);
	static bool cmpCiDes(Student* c1, Student* c2);
	static void mostrar(Student* Student);
	static void mostrarNum(Student* Student);
};

