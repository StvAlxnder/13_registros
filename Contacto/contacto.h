#ifndef CONTACTO_H
#define CONTACTO_H //guarda

#include <iostream>
#include <string>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerContacto(contactoEmail &, string, char, int, correo);
void leerCorreo(correo &, string, string);
void imprimeContacto(contactoEmail &);

#endif //fin de guarda