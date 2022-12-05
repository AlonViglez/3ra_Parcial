#include<stdio.h>
#include<stdlib.h>


int nivel = 0;

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
	int dato;
};

struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);
	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
	nuevo_nodo->dato = dato;
	nuevo_nodo->hijo_izq = NULL;
	nuevo_nodo->hijo_der = NULL;

	return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
	if(dato > nd->dato){
		if(nd->hijo_der == NULL){
			nd->hijo_der = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_der, dato);
		}
	}else{
		if(nd->hijo_izq == NULL){
			nd->hijo_izq = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_izq, dato);
		}
	}
}


void busqueda(struct nodo* nd, int numero){
	nivel++;
	if(numero == nd->dato){
		printf("Numero %d esta en el %d nivel\n", numero, nivel);
	}else if(numero < nd->dato && nd->hijo_izq != NULL){
		busqueda(nd->hijo_izq, numero);
	}else if(numero > nd->dato && nd->hijo_der != NULL){
		busqueda(nd->hijo_der, numero);
	}else{
		printf("Numero %d no existe en el arbol\n", numero);
	}
}

int main(){
	int numero;
	//Raiz
	struct nodo* raiz = NULL;
	raiz = nuevoNodo(6);
	//Hijos
	insertarNodo(raiz, 5);
	insertarNodo(raiz, 11);
	insertarNodo(raiz, 4);
	insertarNodo(raiz, 8);
	insertarNodo(raiz, 12);
	insertarNodo(raiz, 3);
	insertarNodo(raiz, 9);
	insertarNodo(raiz, 21);
    //Pedir numero
	printf("\nIngrese el numero que desea buscar: ");
	scanf("%d", &numero);
    //Llamar funcion busqueda
	busqueda(raiz, numero);

	return 0;
}