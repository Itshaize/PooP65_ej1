#include<iostream>
using namespace std;
void analizarRango(int valor){
    if(valor>10 or valor<=0){
        cout<<"nota fuera de los parametros"<<endl;
    }
}
int main (){
    float nota1, nota2, nota3, nota4;
    float prom;
    do{
        cout<<"Ingrese la nota de deberes [1-10]: ";
        cin>>nota1;
        analizarRango(nota1);
    }while(nota1<=0 or nota1>10);
    do{
        cout<<"Ingrese la nota de trabajos[1-10] : ";
        cin>>nota2;
        analizarRango(nota2);
    }while(nota2<=0 or nota2>10);

    do{

        cout<<"Ingrese la nota de pruebas [1-10]: ";
        cin>>nota3;
        analizarRango(nota3);
    }while(nota3<=0 or nota3>10);

    do{

        cout<<"Ingrese la nota de examen [1-10]: ";
        cin>>nota4;
        analizarRango(nota4);
    }while(nota4<=0 or nota4>10);
    prom=(nota1+nota2+nota3+nota4)/4;
    cout<<"El promedio es: "<<prom<<endl;
    if(prom>=7){
        cout<<"Aprobado"<<endl;
    }else if(prom>=5 or prom<7){
        cout<<"Suspendido"<<endl;
    }else if(prom>=1 or prom<5){
        cout<<"Reprobado"<<endl;
    }
    return 0;
}
