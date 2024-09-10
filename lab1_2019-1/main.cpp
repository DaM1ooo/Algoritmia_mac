
/* 
 * File:   main.cpp
 * Author: danitzamichi
 *
 * Created on August 28, 2024, 10:24 AM
 */

#include<iostream>
#include<cmath>

using namespace std;

void cargaBin(int cromo[], int n,int dec){
    int i=0, dig;
    while(dec>0){
        dig=dec%2;
        dec/=2;
        cromo[i]=dig;
        i++;
    } 
}


int main(int argc, char** argv) {
    
    int peso_maximo=25;
    int n=6;
    int pesos[]={8,2,10,10,5,5};
    int ganancia[]={15,20,5,10,8,5};
    
    int opciones=pow(2,n), mejor_opcion;
    double mayor_ganancia=0, ganacia_parcial=0;
    double peso_parcial;
    int cromo[6]={0,0,0,0,0,0};
    
    for(int i=1; i<opciones; i++){
        peso_parcial=0;
        ganacia_parcial=0;
        
        cargaBin(cromo, n, i);
        
        for(int j=0; j<n; j++){
            peso_parcial+=cromo[j]*pesos[j];
            ganacia_parcial+=cromo[j]*ganancia[j];
        }
        
        if(peso_parcial<=peso_maximo){
            if(mayor_ganancia<ganacia_parcial){
                mayor_ganancia=ganacia_parcial;
                mejor_opcion=i;
            }
        }
        
    }
    
    //impresion de las soluciones
    
    cargaBin(cromo, n, mejor_opcion);
    cout<<endl<<"Articulos: ";
    for(int j=0; j<n; j++){
        //cout<<cromo[j]<<" ";
        if(cromo[j]==1) cout<<j+1<<" ";
    }
    cout<<endl<<"Ganancia Total: "<< mayor_ganancia<<endl;
    //
    
    return 0;
}

