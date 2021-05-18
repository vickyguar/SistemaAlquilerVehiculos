///////////////////////////////////////////////////////////
//  cTrafic.cpp
//  Implementation of the Class cTrafic
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTrafic.h"

float cTrafic::PrecioAlquilerXDia=1800.0;
cTrafic::cTrafic(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento):
	cVehiculo::cVehiculo(estado, tarifa_base, adicionales, color, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cTrafic::~cTrafic(){

}

void cTrafic::AnadirAdicionales(unsigned int cant_asientos, unsigned int cant_sillas){
	if (cant_asientos >= 1|| cant_asientos <= 10) //si quiere a�adir asientos retraibles
		PrecioAlquilerXDia += cant_asientos * ((int)eAdicionales::ASIENTOS_REBATIBLES); //se suma el costo a el precio por d�a

	if (cant_sillas >= 1 || cant_sillas <= 5) //si quiere a�adir 1 o m�s (hasta 5) sillas de seguridad 
		PrecioAlquilerXDia += cant_sillas * ((int)eAdicionales::SILLA_SEGURIDAD); //se suma el costo a el precio por d�a
	return;
}


float cTrafic::CalcularTarifa(unsigned int dia){

	float result = getTarifaBase() + PrecioAlquilerXDia*dia;

	return result;
}


string cTrafic::PasosMantenimiento(){

}