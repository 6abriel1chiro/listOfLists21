#pragma once

#include <sstream>
#include <iostream>
using namespace std;

class emptyListException : public exception
{
private:
	string mensaje;
public:
	emptyListException() {
		stringstream ss;
		ss << "lista vacia";
		mensaje = ss.str();
	}
	const char* what() const throw ()
	{
		return mensaje.c_str();
	}
};


