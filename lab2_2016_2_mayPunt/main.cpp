
/* 
 * File:   main.cpp
 * Author: danitzamichi
 *
 * Created on September 10, 2024, 1:32 PM
 */


#include<iostream>
#include<cmath>
//
using namespace std;


int mayor_valor(int a, int b){
    if(a>=b) return a;
    else return b;
}

int obtenerPuntajeMaximo(int x,int y,int n,int m,int tablero[2][2]){
    
    //si llego a la posicion final
    if(x==n-1 and y==m-1) return tablero[x][y];
    
    //si sale del tablero
    if(x>n-1 or y>m-1 or x<0 or y<0) return 0;
    
    int der=obtenerPuntajeMaximo(x,y+1, n,m,tablero);//2
    int abaj=obtenerPuntajeMaximo(x+1,y, n,m,tablero);
    
    return mayor_valor(der, abaj )+ tablero[x][y] ;
    
    
}



int main(int argc, char** argv) {
    
    int n=3, m=2;
    int tablero[3][2]={{2,2},{3,5},{-2,4} };
    
    //puntaje maximo
    cout<<"Puntaje maximo obtenido: "<<obtenerPuntajeMaximo(0,0,n,m,tablero);
    

    return 0;
}

