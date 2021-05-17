///////////////////////////////////////////////////////////
//  cCaminoeta.h
//  Implementation of the Class cCaminoeta
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_)
#define EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_

#include "cVehiculo.h"

class cCamioneta : public cVehiculo
{

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cCamioneta
	* constructor de automovil
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cCamioneta(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq,
		unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento);

	/**
	* ~cCamioneta
	* destructor de la clase Camioneta
	*/
	virtual ~cCamioneta();

#pragma endregion

	void AnadirAdicionales(unsigned int cant);
	float CalcularTarifa();
	void PasosMantenimiento();

};
#endif // !defined(EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_)
