///////////////////////////////////////////////////////////
//  cCaminoeta.cpp
//  Implementation of the Class cCaminoeta
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cCamioneta.h"

float cCamioneta::PrecioAlquilerXDia=1000.0;
cCamioneta::cCamioneta(eEstadoVehiculo estado, float tarifa_base, eColor color, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento, const unsigned int capacidad):
	cVehiculo::cVehiculo(estado, tarifa_base, color, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cCamioneta::~cCamioneta(){

}

void cCamioneta::AnadirAdicionales(unsigned int cant_portaequipaje, unsigned int cant_sillas) {
	if (cant_portaequipaje == 1) //si quiere a�adir un portaequipaje
		PrecioAlquilerXDia += cant_portaequipaje * ((int)eAdicionales::PORTA_EQUIPAJE); //se suma el costo a el precio por d�a

	if (cant_sillas >= 1 || cant_sillas <= 3) //si quiere a�adir 1 o m�s (hasta 3) sillas de seguridad 
		PrecioAlquilerXDia += cant_sillas * ((int)eAdicionales::SILLA_SEGURIDAD); //se suma el costo a el precio por d�a
	return;
}


float cCamioneta::CalcularTarifa(unsigned int dias){
	float result = getTarifaBase() + PrecioAlquilerXDia*dias;

	return result;
}


string cCamioneta::PasosMantenimiento(){
	
	string steps = "PASOS MANTENIMIENTO MOTOCICLETA: \n";
	steps += "1. Revisi�n de fluidos \n";
	steps += "2. Estado de bater�a\n";
	steps += "3. Revision de frenos\n";
	steps += "4. Neum�ticos\n";
	steps += "5. Amortiguadores\n";
	steps += "6. Revisi�n de las luces\n";
	return steps;

}

string cCamioneta::To_string() const
{
	string output;

	output += "\nTipo de vehiculo: Camioneta\n";

	output += cVehiculo::To_string();

	return output;
}

void cCamioneta::Imprimir() const
{
	cout << To_string();
}

float cCamioneta::getPrecioXDia() const
{
	return PrecioAlquilerXDia;
}
