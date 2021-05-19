///////////////////////////////////////////////////////////
//  cVehiculo.cpp
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cVehiculo.h"

float cVehiculo::TarifaBase= 10000;
cVehiculo::cVehiculo(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento):
	CapacidadPasajeros(capacidad), Chasis(chasis), Patente(patente), Poliza(poliza)
{
	this->Tipo = tipo;
	this->Estado = estado;
	this->TarifaBase = tarifa_base;
	this->Adicionales = adicionales;
	this->Color = color;
	this->CantAdicionalesAlquilados = 0;
	this->UltimoMantenimiento = fecha_ult_mantenimiento;
}

cVehiculo::~cVehiculo(){
}

void cVehiculo::AnadirAdicionales(unsigned int cant){
	this->CantAdicionalesAlquilados = cant;
}

float cVehiculo::CalcularTarifas(){
	return float();
}

string cVehiculo::PasosMantenimiento(){
	return string();
}


string cVehiculo::getClave() const
{
	return Patente;
}

float cVehiculo::getTarifaBase() const
{
	return TarifaBase;
}

eEstadoVehiculo cVehiculo::getEstado() const
{
	return Estado;
}

void cVehiculo::setEstado(eEstadoVehiculo newEstado)
{
	Estado = newEstado;
}

void cVehiculo::setFechaUltMantenimiento(tm newUltMantenimiento)
{
	UltimoMantenimiento = newUltMantenimiento;
}

string cVehiculo::To_string()const
{
	string output;
	//----------------------------------------------------------------------------------------------------
	switch (Tipo) {
	case eTipoVehiculo::AUTOMOVIL: output += "----Automovil----" + '\n'; break;
	case eTipoVehiculo::CAMIONETA:output += "----Camioneta----" + '\n'; break;
	case eTipoVehiculo::TRAFIC:output += "----Trafic----" + '\n'; break;
	case eTipoVehiculo::MOTOCICLETA:output += "----Motocicleta----" + '\n'; break;
	}
	//----------------------------------------------------------------------------------------------------
	switch (Estado) {
	case eEstadoVehiculo::ALQUILADO: output += "Estado de vehiculo: Alquilado " + '\n'; break;
	case eEstadoVehiculo::DISPONIBLE: output += "Estado de vehiculo: Disponible " + '\n'; break;
	case eEstadoVehiculo::EN_MANTENIMIENTO: output += "Estado de vehiculo: En mantenimiento " + '\n'; break;
	case eEstadoVehiculo::FUERA_CIRCULACION: output += "Estado de vehiculo: Fuera de circulacion " + '\n'; break;
	}
	//----------------------------------------------------------------------------------------------------
	switch (Color) {
	case eColor::AZUL: output += "Color: azul" + '\n';
	case eColor::BLANCO:output += "Color: blanco" + '\n';
	case eColor::GRIS:output += "Color: gris" + '\n';
	case eColor::NEGRO:output += "Color: negro" + '\n';
	case eColor::ROJO:output += "Color: rojo" + '\n';
	}
	//----------------------------------------------------------------------------------------------------
	output += "Capacidad de pasajeros: " + CapacidadPasajeros + '\n';
	output +=""

	eAdicionales Adicionales;
	unsigned int CantAdicionalesAlquilados;
	const unsigned int CapacidadPasajeros;
	const string Chasis;
	const string Patente;
	const string Poliza;
	tm UltimoMantenimiento;
}
void cVehiculo::setTarifaBase(float tarifa)
{
	TarifaBase = tarifa;
}
