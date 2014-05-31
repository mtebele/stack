#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"

/*
 * NOMBRE: Matias Tebele
 * PADRON: 95372
 */

/******************************************************************
 *                        PRUEBAS UNITARIAS
 ******************************************************************/

// Funciones auxiliares para imprimir si estuvo OK o no
void print_test(char* name, bool result)
{
	printf("* %s: %s\n", name, result? "OK" : "ERROR");
}

void print_test_loop(char* name, int value, bool result)
{
	printf("* %s %d: %s\n", name, value, result? "OK" : "ERROR");
}

// Pruebas para una pila de tamanio 0
void pruebas_pila_nula()
{
	printf("-- INICIO DE PRUEBAS CON PILA SIN ELEMENTOS -- \n");

	// Creo una pila
	pila_t* pila = pila_crear();
	
	// Inicio de pruebas
	print_test("Crear pila", pila != NULL);
	print_test("La pila esta vacia", pila_esta_vacia(pila));
	print_test("El tope es nulo", pila_ver_tope(pila) == NULL);
	print_test("No tengo elementos que desapilar", pila_desapilar(pila) == NULL);
		
	// Destruyo la pila
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

// Pruebas de guardar y obtener algunos elementos
void pruebas_pila_algunos_elementos()
{
	printf("-- INICIO DE PRUEBAS CON ALGUNOS ELEMENTOS -- \n");
	
	// Creo una pila y un vector con enteros
	pila_t* pila = pila_crear();
	int v[] = {0,5,22,-10,3,8};
	char c = 'w';
	char vc[] = {'_','z'};
	
	// Defino la cantidad de elementos del vector v
	int size = 6;
	
	// Pruebo apilar y desapilar
	print_test("Crear pila", pila != NULL);
	print_test("Apilo 22", pila_apilar(pila, &v[2]));
	print_test("Desapilo 22", pila_desapilar(pila) == &v[2]);
	print_test("Apilo 'w'", pila_apilar(pila, &c));
	print_test("Apilo vc[]", pila_apilar(pila, &vc));
	print_test("Desapilo vc[]", pila_desapilar(pila) == &vc);
	print_test("Desapilo 'w'", pila_desapilar(pila) == &c);	
	print_test("Desapilo nuevamente (null)", pila_desapilar(pila) == NULL);	
	print_test("La pila esta vacia", pila_esta_vacia(pila));
	
	for (int i = 0; i < size; i++)
		print_test_loop("Apilo", v[i], pila_apilar(pila, &v[i]));

	for (int i = size-1; i >=0; i--)
		print_test_loop("Desapilo", v[i], pila_desapilar(pila) == &v[i]);
	
	print_test("El tope es nulo", pila_ver_tope(pila) == NULL);
	print_test("La pila esta vacia", pila_esta_vacia(pila));
								
	// Destruyo la pila
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

// Pruebas de la pila al trabajar con un volumen grande de elementos
void pruebas_pila_volumen()
{
	printf("-- INICIO DE PRUEBAS DE VOLUMEN -- \n");
	
	// Creo una pila
	pila_t* pila = pila_crear();
	
	// Creo la pila
	print_test("Crear pila", pila != NULL);
	
	// Defino la cantidad de elementos a apilar
	int cant = 10000;
	int i;
	bool result = true;	
	
	// Pruebo apilar y desapilar		
	for (i = 0; i < cant; i++)
		result &= pila_apilar(pila, &i);
	print_test("Se apilaron todos los elementos", result);
	
	result = true;
	for (i = cant-1; i >=0; i--)
		result &= (pila_desapilar(pila) == &i);
	print_test("Se desapilaron todos los elementos", result);
	
	print_test("El tope es nulo", pila_ver_tope(pila) == NULL);
	print_test("La pila esta vacia", pila_esta_vacia(pila));
								
	// Destruyo la pila
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

// Ejecuto todas las pruebas
void pruebas_pila()
{
	pruebas_pila_nula();
	pruebas_pila_algunos_elementos();
	pruebas_pila_volumen();
}

// Programa principal
int main(int argc, char **argv)
{	
	pruebas_pila();
	return 0;
}
