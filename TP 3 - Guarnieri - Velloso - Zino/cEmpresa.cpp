///////////////////////////////////////////////////////////
//  cEmpresa.cpp
//  Implementation of the Class cEmpresa
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cEmpresa.h"


cEmpresa::cEmpresa(){
}

cEmpresa::~cEmpresa(){

}

void cEmpresa::Adquirir(cVehiculo* newVehiculo) {
	if (newVehiculo != NULL) {
		for (int i = 0; i < ListaVehiculos().getCA(); i++) {
			if (ListaVehiculos()[i]->getPatente() == newVehiculo->getPatente())
				throw new exception(("El auto con patente " + newVehiculo->getPatente() + "ya esta en la empresa").c_str());
		}
		ListaVehiculos().Agregar(newVehiculo);
		newVehiculo->setEstado(eEstadoVehiculo::DISPONIBLE);
	}
}

void cEmpresa::Alquilar(cVehiculo* newVehiculo){

}

void cEmpresa::Mantenimiento(cVehiculo *Vehiculo){
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado()!=eEstadoVehiculo::DISPONIBLE)
			throw new exception(("El auto con patente " + Vehiculo->getPatente() + 
				"no esta disponible y por lo tanto puede someterse a mantenimiento").c_str());
		else {
			Vehiculo->PasosMantenimiento();
			Vehiculo->setEstado(eEstadoVehiculo::EN_MANTENIMIENTO);
		}
	}
	
}

void cEmpresa::RetirarCirculacion(cVehiculo* newVehiculo){

}
