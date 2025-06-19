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
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>EMPLEADOS[i].num;
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        for(int j=0; j<12; j++)
            cin>>EMPLEADOS[i].ven[j];
        cin>>EMPLEADOS[i].sal;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<12; j++)
            EMPLEADOS[i].ventot = EMPLEADOS[i].ventot + EMPLEADOS[i].ven[j];
    }
    for(int i=0; i<n; i++){
        cout<<EMPLEADOS[i].ventot<<endl;
    }
    maxven = EMPLEADOS[0].ventot;
    for(int i=1; i<n; i++){
        if(EMPLEADOS[i].ventot > maxven)
            maxven = EMPLEADOS[i].ventot;
    }
    cout<<maxven;
    return 0;
}