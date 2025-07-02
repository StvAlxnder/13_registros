#include "gestorContactos.h"
#include "contacto.h"
#include <iostream>
#include <string>

void agregarContacto(contactoEmail lista[], contactoEmail cE, int &cant){
        lista[cant] = cE;
        cant++;
}

void mostrarContactos(contactoEmail lista[], int cant){
    for(int i = 0; i < cant; i++){
        cout<<"Contacto #"<<i+1<<endl;
        imprimeContacto(lista[i]);
        cout<<"----------------------------------------"<<endl;
    }
}