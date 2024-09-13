/* 
 * File:   main.cpp
 * Author: danit
 *
 * Created on April 12, 2024, 1:00 PM
 */

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;
#define M 6
#define N 6

int detectaUnidades(int x, int y, int n, int m, int tablero[N][M]){
    int cant=0; 
    //caso base: sale del tablero o la posicion es cero
    if(y<0 or y>m or x<0 or x>n ) return 0;
    if(tablero[x][y]==1) return cant +1;
    
    
    //condicion del problema   
   
    //busca en la linea vertical
    if(y<n)  cant+=detectaUnidades(x,y+1,n, m, tablero); 
    if(y>0) cant+=detectaUnidades(x,y-1,n, m, tablero); 

       //busca en la linea horizontal
    if(x<m) cant+=detectaUnidades(x+1,y,n, m, tablero); 
    if(x>0) cant+=detectaUnidades(x-1,y,n, m, tablero);
    
//    if(y<n)  cant+=detectaUnidades(x,y+1,n, m, tablero); 
//    if(y>0) cant+=detectaUnidades(x,y-1,n, m, tablero); 
//
//       //busca en la linea horizontal
//    if(x<m) cant+=detectaUnidades(x+1,y,n, m, tablero); 
//    if(x>0) cant+=detectaUnidades(x-1,y,n, m, tablero); 
    
   
    return cant;

}

int main(int argc, char** argv) {
    
    
    int x=3, y=2;
    int tablero[N][M] = {{0,0,0,1,0,1},
                         {0,0,1,0,0,0},
                         {0,1,0,0,0,1},
                         {1,0,0,0,0,0},
                         {0,1,0,0,0,0},
                         {0,0,0,0,1,0}};
    
    //movimiento Y solo a la derecha
    //devuelve el numero de unidades encontradas
    
    cout<<"El resultado de la busqueda sera: "<<detectaUnidades(x, y, N, M,tablero);
    
    
    
    
    return 0;
}

