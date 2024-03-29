///////////////////////////////////////////////////////////
//  cTrafic.h
//  Implementation of the Class cTrafic
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
#define EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_

#include "cVehiculo.h"

class cTrafic : public cVehiculo
{
private:
	static float PrecioAlquilerXDia;
public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cTrafic
	* constructor de trafic
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cTrafic(eEstadoVehiculo estado, float tarifa_base, eColor color,
		const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento, const unsigned int capacidad = 10);

	/**
	* ~cTrafic
	* destructor de la clase Trafic
	*/
	~cTrafic();

#pragma endregion
	/**
* AņadirAdicionales
* permite que se aņadan adicionales al alquiler. El precio de estos se agrega a precio por dia
*/
	void AnadirAdicionales(unsigned int cant_portaequipaje, unsigned int cant_sillas);

	/**
	* CalcularTarifas
	* calcula la tarifa a abonar por el cliente
	*/
	float CalcularTarifa(unsigned int dias);

	/**
* PasosMantenimiento
* crea un string con los pasos de mantenimiento de un auto
*/
	string PasosMantenimiento();
	/**
* To_string
* crea un string con todos los atributos de la calse
*/
	string To_string() const;
	/**
	* Imprimir 
	* imprime los atributos en pantalla
	*/
	void Imprimir() const;

	float getPrecioXDia()const; //getter

};
#endif // !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
