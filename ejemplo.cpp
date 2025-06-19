#include <iostream>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], sal, ventot;
};

int main(){
    EMP EMPLEADOS[100];
    int n, maxven;
    cout<<"\nREGISTRO DE DATOS DE LOS EMPLEADOS\n";
    cout<<"Numero de empleados: ";  cin>>n;
    for(int i=0; i<n; i++){
        cout<<"\nEMPLEADO #"<<i+1<<endl;
        cout<<"Numero: ";   cin>>EMPLEADOS[i].num;
        cout<<"Nombre: ";
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        cout<<"Ventas del ano:\n";
        for(int j=0; j<12; j++){
            cout<<"Mes "<<j+1<<": ";    cin>>EMPLEADOS[i].ven[j];
        }
        cout<<"Salario: ";  cin>>EMPLEADOS[i].sal;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<12; j++)
            EMPLEADOS[i].ventot = EMPLEADOS[i].ventot + EMPLEADOS[i].ven[j];
    }
    for(int i=0; i<n; i++){
        cout<<"Venta total del empleado #"<<i+1<<": ";
        cout<<EMPLEADOS[i].ventot<<endl;
    }
    maxven = EMPLEADOS[0].ventot;
    for(int i=1; i<n; i++){
        if(EMPLEADOS[i].ventot > maxven)
            maxven = EMPLEADOS[i].ventot;
    }
    cout<<"Mayor venta total: "<<maxven<<endl;
    return 0;
}