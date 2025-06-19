#include <iostream>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], sal, ventot;
};

int main(){
    EMP EMPLEADOS[100];
    int n, maxven, numemp;
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
    maxven = EMPLEADOS[0].ventot;
    numemp = 0;
    for(int i=1; i<n; i++){
        if(EMPLEADOS[i].ventot > maxven)
            maxven = EMPLEADOS[i].ventot;
            numemp = i;
    }
    cout<<"\nEMPLEADO CON MAYOR VENTA TOTAL\n";
    cout<<"Numero: "<<EMPLEADOS[numemp].num<<endl;
    cout<<"Nombre: "<<EMPLEADOS[numemp].nom<<endl;
    for(int i=1; i<n; i++){
        if(EMPLEADOS[i].ventot > 100)
            EMPLEADOS[i].sal = EMPLEADOS[i].sal*1.1;
    }
    cout<<"\nSALARIOS\n";
    for(int i=0; i<n; i++){
        cout<<"Empleado #"<<EMPLEADOS[i].num<<": "
            <<EMPLEADOS[i].sal<<endl;
    }
    cout<<"\nVENTAS DE DICIEMBRE MENORES A 30\n";
    for(int i=0; i<n; i++){
        if(EMPLEADOS[i].ven[11]<30){
            cout<<"\nNumero: "<<EMPLEADOS[i].num<<endl;
            cout<<"Nombre: "<<EMPLEADOS[i].nom<<endl;
        }
    }
    return 0;
}