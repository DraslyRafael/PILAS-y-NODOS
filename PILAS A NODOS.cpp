//============================================================================
// Name        : PILAS.cpp
// Author      : DRASLY RAFAEL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

				//REGISTRO DE ESTUDIANTES CRIMINOLOGOS DE GUATEMALA//
using namespace std;

struct ESTUDIANTE {
    char Nombre[60];
    int Edad;
    char Carnet[30];
    char Semestre[10];
    char Curso[30];
    char Nota[8];

};

struct Nodo
{
    struct ESTUDIANTE dato;
    struct Nodo *siguiente;
};

struct Nodo *nuevo();
int vacio(struct Nodo *);
struct Nodo *crear(struct Nodo *, struct ESTUDIANTE);
void Mostrar(struct Nodo *);

int main()
{
    struct Nodo *primero=NULL, *ultimo=NULL;
    struct ESTUDIANTE est;
    int cantidad;
    int a=0;
    cout << "*****REGISTRO ESTUDIANTES DE CRIMINOLOGIA UMG *****"<<endl;
    cout << "CUANTOS DATOS DESEA REGISTRAR : " << endl;
   cin >> cantidad;


    while(a< cantidad)
    {
        cout << "INGRESE NOMBRE DEL ESTUDIANTE : "<<endl;
        cin >> est.Nombre;
        cout << "INGRESE LA EDAD : "<<endl;
        cin >> est.Edad;
        cout << "INGRESE EL NUMERO DE CARNET : " <<endl;
        cin >> est.Carnet;
        cout << "INGRESE EL SEMESTRE : " <<endl;
        cin >> est.Semestre;
        cout << "INGRESE EL NOMBRE DEL CURSO : " <<endl;
        cin >> est.Curso;
        cout << "INGRESE LA NOTA : " <<endl;
         cin >> est.Nota;
        ultimo=crear(ultimo, est);
        if(primero==NULL) primero=ultimo;
        a++;

        cout << "***************************************+" << endl;
    }
    if(vacio(primero)==1) {
            cout << "No se ingresaron registros";
    } else Mostrar(primero);
}

struct Nodo *nuevo()
{
    struct Nodo *p;
    p=(struct Nodo *)malloc(sizeof(struct Nodo));
    if(p==NULL)
    {
        cout << "Memoria RAM Llena"<<endl;
        getch();
        exit(0);
    }
    return p;
}

struct Nodo *crear(struct Nodo *ultimo, struct ESTUDIANTE est)
{
    struct Nodo *p;
    p=nuevo();
    (*p).dato=est;
    (*p).siguiente=NULL;
    if(ultimo!=NULL) (*ultimo).siguiente=p;
    return p;
}

int vacio(struct Nodo *primero)
{
    if(primero==NULL) return 1;
    else return 0;
}

void Mostrar(struct Nodo *primero)
{
    struct Nodo *aux;
    while(primero!=NULL)
    {

        cout << "Nombre:  " <<primero->dato.Nombre<<endl;
        cout << " EDAD : " << primero->dato.Edad<<endl;
        cout << "CARNET: " <<primero->dato.Carnet<<endl;
        cout << "SEMESTRE: " <<primero->dato.Semestre<<endl;
        cout << "CURSO : " <<primero->dato.Curso<<endl;
        cout << "  NOTA: "  << primero->dato.Nota <<endl;
        aux=primero;
        primero=(*primero).siguiente;
        free(aux);
    }
    getch();
}
