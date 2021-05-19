///////////////////////////////////////////////////////////
//  cAlquiler.cpp
//  Implementation of the Class cAlquiler
//  Created on:      14-may.-2021 15:26:50
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAlquiler.h"

//LA PALABRA CONST NO VA
cAlquiler::cAlquiler(unsigned int _CantAdicionales, tm _FechaFin, tm _FechaInicio, float _MontoTotal, const string _DNI, const string _Patente, const string code)
	:DNI(_DNI), Patente(_Patente), Code(code)
{
	CantAdicionales = _CantAdicionales;
	FechaFin = _FechaFin;
	FechaInicio = _FechaInicio;
	MontoTotal = _MontoTotal;
}

cAlquiler::~cAlquiler(){

}

float cAlquiler::getMontoTotal()
{
	return MontoTotal;
}

void cAlquiler::Imprimir()
{
}

string cAlquiler::getClave() const
{
	return Code;
}

