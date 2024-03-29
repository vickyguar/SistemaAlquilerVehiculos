#pragma once

#include <iostream>
#include <string>
#include <ostream>

#define NMAX 50

using namespace std;

template<class T>
class cListaTemplate
{
protected:
	T** Lista;
	unsigned int CA, TAM;
	bool Delete;

public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cListaTemplate(unsigned int _TAM = NMAX, bool _Delete = true);
	virtual ~cListaTemplate();
#pragma endregion

#pragma region AGREGAR, QUITAR, ELIMINAR
	void Agregar(T* newItem);
	T* Quitar(const string Key);
	void Eliminar(const string Key);

#pragma endregion
	void Redimensionar();

#pragma region BUSCAR
	T* BuscarItem(const string Key);
	T* BuscarXPos(unsigned int Index);
#pragma endregion

#pragma region GETTERS
	unsigned int getIndex(const string Key)const;
	unsigned int getCA()const;
	unsigned int getTAM()const;
#pragma endregion

	void Listar()const; 

#pragma region SOBRECARGA
	T* operator[](unsigned int pos);
	void operator+(T* newItem);
#pragma endregion
};

template<class T>
cListaTemplate<T>::cListaTemplate(unsigned int _TAM, bool _Delete)
{
	TAM = _TAM;
	CA = 0;
	Delete = _Delete;

	//Creo la lista dinamica
	Lista = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++) {
		Lista[i] = NULL;
	}
}

template<class T>
cListaTemplate<T>::~cListaTemplate()
{
	if (Lista != NULL) {
		if (Delete) {
			for (unsigned int i = 0; i < CA; i++)
			{
				if(Lista[i]!= NULL)
					delete Lista[i];
			}
		}
		delete[] Lista;
	}
}

template<class T>
void cListaTemplate<T>::Agregar(T* newItem)
{
	if (newItem != NULL) {

		if (CA == TAM) //Si la cantidad actual es igual al tama�o m�ximo
			Redimensionar(); //Redimensiono la lista

		try {
			int pos = getIndex(newItem->getClave()); //busco el elemento en la lista
		}
		catch (exception* ex) { //si el elemento no existe
			delete ex;
			Lista[CA] = newItem; //lo agrego a la lista
			CA++;
			return;
		}
		throw new exception("El item ya esta en la lista");
	}
	throw new exception("El nuevo item que se desea agregar a la lista es NULL");
}

template<class T>
T* cListaTemplate<T>::Quitar(const string Key)
{
	int pos = -1; //Solo para inicializar

	try { pos = getIndex(Key); } //busco el elemento
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("No se puede quitar el item: " + error).c_str());
		throw ex;
	}

	T* aux = Lista[pos]; //me lo guardo si lo encuentra

	for (int i = pos; i < CA - 1; i++)
		Lista[i] = Lista[i + 1]; //Corremos todo una posici�n para arriba

	Lista[--CA] = NULL; //El ultimo elemento es aux. Tambien hacemos un predecremento de CA

	return aux; //Retornamos aux

}

template<class T>
void cListaTemplate<T>::Eliminar(const string Key)
{
	T* aux = NULL; //auxiliar

	if (Lista != NULL) {
		try { aux = Quitar(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("No se puede eliminar el item: " + error).c_str());
			throw ex;
		}
		delete aux; //Eliminamos
	}
	throw new exception("Error al eliminar: la lista es NULL");
	
}


template<class T>
void cListaTemplate<T>::Redimensionar()
{
	unsigned int n = 2 * TAM;
	T** aux = new T * [n]; //La redimensionamos al doble de su tama�o

	//--------------------------------------------
	for (unsigned int i = 0; i < TAM * 2; i++)
		aux[i] = NULL;

	for (unsigned int i = 0; i < TAM; i++) 
		aux[i] = Lista[i]; //me copio el elemento
	
	//--------------------------------------------

	delete[] Lista; //borro el puntero grande

	Lista = aux; //Lista ahora apunta a la lista redimencionada
	TAM += TAM; //cambio el TAM 
}

template<class T>
T* cListaTemplate<T>::BuscarItem(const string Key)
{
	int pos = -1; //Solo para inicializar

	if (Lista != NULL) {
		try { pos = getIndex(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("Error al buscar item: " + error).c_str());
			throw ex;
		}
		return Lista[pos];
	}
	throw new exception("Error al buscar el item"); 
}

template<class T>
T* cListaTemplate<T>::BuscarXPos(unsigned int Index)
{
	if (Index > CA)
		throw new exception(("La posicion " + to_string(Index) + "no existe en la lista").c_str());
	return Lista[Index];
}

template<class T>
unsigned int cListaTemplate<T>::getIndex(const string Key) const
{
	for (unsigned int i = 0; i < CA; i++) { 
		if (Lista[i]->getClave() == Key) //si tiene la misma clave
			return i; //retorno la posici�n donde lo encontr�
	}

	throw new exception((Key + " El item no existe").c_str());
}

template<class T>
unsigned int cListaTemplate<T>::getCA() const
{
	return CA;
}

template<class T>
unsigned int cListaTemplate<T>::getTAM() const
{
	return TAM;
}

template<class T>
void cListaTemplate<T>::Listar() const
{
	for (unsigned int i = 0; i < CA; i++) //recorro la lista
	{
		cout << "\n\t# " << i + 1 << endl;
		cout << Lista[i]->To_string();
	}
}

template<class T>
T* cListaTemplate<T>::operator[](unsigned int pos) {
	return BuscarXPos(pos);
}

template<class T>
inline void cListaTemplate<T>::operator+(T* newItem)
{
	try { Agregar(newItem); }
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error al usar operator+: " + error).c_str());
		throw ex;
	}
	return;
}

template<class T>
void operator<<(ostream& o, cListaTemplate<T>& obj)
{
	for (unsigned int i = 0; i < obj.getCA(); i++)
	{
		o << obj[i]->To_string(); 
	}
}