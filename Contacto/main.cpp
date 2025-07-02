#include <iostream>
#include "contacto.h"
#include "gestorContactos.h"
#define MAX 10
using namespace std;

int main(){
    int n, op, op2, edad, m;
    string nom, user, domain, serv;
    char sex, SN;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones-------------------"<<endl;
        cout<<"1. Agregar un contacto"<<endl;
        cout<<"2. Modificar un contacto"<<endl;
        cout<<"3. Mostrar contactos"<<endl;
        cout<<"4. Buscar contacto por servidor de correo"<<endl;
        cout<<"5. Eliminar un contacto"<<endl;
        cout<<"6. Buscar contacto por email"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                system("cls");
                cout<<"\nIngrese los datos de un usuario"<<endl;
                cout<<"Ingrese el nombre del contacto: ";
                cin.ignore();
                getline(cin, nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio):"<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;

                leerCorreo(email, user, domain);
                leerContacto(cont, nom, sex, edad, email);

                cout<<"\nHa ingresado la siguiente informacion: "<<endl;
                imprimeContacto(cont);
                cout<<"Esta informacion es correcta? (S/N): ";
                cin>>SN;
                if(SN == 'S' || SN == 's'){
                    if(n<MAX){
                        agregarContacto(lista, cont, n);
                        cout<<"Registro exitoso"<<endl;
                    }
                    else{
                        cout<<"Limite de contactos alcanzado<<endl";
                    }
                }
                else{
                    cout<<"Se cancelo la operacion"<<endl;
                }
                system("pause");
                break;
            case 2:
                system("cls");
                if(n == 0){
                    cout<<"Aun no se han registrado contactos.";
                }
                else{
                    mostrarContactos(lista, n);
                }
                cout<<"Modificar un contacto"<<endl;
                cout<<"Ingrese el numero de contacto que desea modificar: "; cin>>m;
                cout<<"Indique el dato que va a modificar"<<endl;
                cout<<"1. Nombre"<<endl;
                cout<<"2. Sexo"<<endl;
                cout<<"3. Edad"<<endl;
                cout<<"4. Usuario del correo electronico"<<endl;
                cout<<"5. Dominio del correo electronico"<<endl;
                cin>>op2;
                switch(op2){
                    case 1:
                        cout<<"Ingrese el nombre: ";
                        cin.ignore();
                        getline(cin, lista[m-1].nom);
                        break;
                    case 2:
                        cout<<"Ingrese el sexo: "; cin>>lista[m-1].sex;
                        break;
                    case 3:
                        cout<<"Ingrese la edad: "; cin>>lista[m-1].edad;
                        break;
                    case 4:
                        cout<<"Ingrese el usuario del correo del electronico: "; cin>>lista[m-1].email.user;
                        break;
                    case 5:
                        cout<<"Ingrese el dominio del correo electronico: "; cin>>lista[m-1].email.domain;
                        break;
                }
                break;
            case 3:
                system("cls");
                for(int i = 0; i<n; i++){
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<"--------------------"<<endl;
                }
                system("pause");
                break;
            case 4:
                system("cls");
                cout<<"Buscar contacto por servidor de correo"<<endl;
                cout<<"Ingrese el servidor: "; cin>>serv;
                for(int i=0; i<n; i++){
                    if(lista[i].email.domain==serv){
                        cout<<"Contacto #"<<i+1<<endl;
                        imprimeContacto(lista[i]);
                        cout<<endl;
                    }
                }
                system("pause");
                break;
            case 5:
                system("cls");
                cout<<"Ingrese el numero de contacto que desea eliminar: "; cin>>m;
                for(int i=m-1; i<n; i++){
                    lista[i]=lista[i+1];
                }
                n-=1;
                break;
            case 6:
                system("cls");
                cout<<"Busqueda de conctacto por email"<<endl;
                cout<<"Ingrese el usuario: "; cin>>user;
                cout<<"Ingrese el dominio: "; cin>>domain;
                leerCorreo(email, user, domain);
                for(int i=0; i<n; i++){
                    if((email.user==lista[i].email.user)&&(email.domain==lista[i].email.domain)){
                        imprimeContacto(lista[i]);
                    }
                system("pause");
                }
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N)"<<endl;
                cin>>SN;
                switch(SN){
                    case 'S':
                        system("cls");
                        cout<<"Fin del programa.";
                        break;
                    case 'N':
                        op=op+1;
                        break;
                }
                break;
            default:
                break;
        }
    } while(op != 0);
    return 0;
}