/* 
 * File:   main.cpp
 * Author: danit
 *
 * Created on April 11, 2024, 9:58 PM
 */
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

//  BUSCA EN ARREGLO ***********************************************************
//arreglo, tamaño del arreglo, posicion inicial, elemento a buscar
//int buscaRecursivo(int arr[],int n,int i, int elemento){
//    //caso base
//    if(i==n) return -1;  //llego al final del arreglo y no encontro nada
//    if(arr[i]==elemento) return i; //encontro el elemnto en el arreglo
//    
//    //si no  encuentra en esta poscion busca en la siguiente
//    return buscaRecursivo(arr, n, i+1, elemento);
//}
//
//int main(){
//    int n=5;
//    int arr[n]={5,8,6,7,9};
//    cout<<"Posicion en el arreglo: "<<buscaRecursivo(arr, n, 0, 8);
//
//    return 0;
//}

//   BUSCA EL MAYOR*************************************************************
//int buscaRecursivoMayor(int arr[], int n, int i, int mayor){
//    //caso base
//    if(n==i) return mayor;
//    //condicion del problema
//    if(arr[i]>mayor){
//        mayor=arr[i];
//    }
//    
//    //en la recursion
//    return buscaRecursivoMayor(arr, n, i+1, mayor);
//}
//
//
//int main(){
//    int n=5;
//    int arr[n]={5,8,6,7,9};
//    cout<<"Posicion del mayor en el arreglo: "<<buscaRecursivoMayor(arr, n, 0, arr[0]);
//
//    return 0;
//}


#define N 3
#define M 3

using namespace std;
//int robotSumaValores(int x,int y,int n,int m,int  tablero[N][M]){
//    //caso base
//    if(x==n-1 or y==m-1)    //no quiere que salgo del tablero, obtiene el valor en esa poscion
//        return tablero[x][y];   //retorna el ultimo valor en el tablero
//    
//    //condicion del probleam
//    int derecha=-999999, abajo=-9999;
//    //obtiene valor de la derecha
//    if(y+1<m) derecha=robotSumaValores(x, y+1, n,m,tablero); 
//    //valor de abajo
//    if(x+1<n) abajo=robotSumaValores(x+1, y, n,m,tablero);
//    
//    if(derecha>abajo) return derecha+tablero[x][y];
//    //valor de la derecha es mayor, lo suma al valor actual y se mueve a derecha    
//    //else suma el valor actual mas el de abajo
//    return abajo+tablero[x][y];
//}


int robotSumaValores(int x,int y,int n,int m, int tablero[N][M]){
    //caso base
    if(x==n-1 or y==m-1) return tablero[x][y];
    
    
    int abajo=-999999, derecha=-999999; //movimiento abajo
    if(x<n){
        abajo=robotSumaValores(x+1,y,n,m, tablero);//obtiene el valor de abajo
    }
    if(y<m){ //movmiento derecha
        derecha=robotSumaValores(x,y+1,n,m, tablero);//obtiene el valor de la derecha
    }
    
    //condicion del problema
    if(derecha>abajo){
        return derecha+tablero[x][y];
    }else{
        return abajo+tablero[x][y];
    }
 
}

int main(){
	int tablero[N][M] = {{2,8,6},
                            {3,10,2},
                            {0,10,1}};
	int n=3, m=3;
	cout << robotSumaValores(0,0,n,m, tablero);
	return 0;
}






















