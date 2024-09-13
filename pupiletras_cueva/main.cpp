/* 
 * File:   main.cpp
 * Author: danit
 *
 * Created on April 9, 2024, 12:30 PM
 */

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
#define MAXCOL 5
int mov[][MAXCOL];

    
void movimientosPermitidos(){
    mov[0][0]=-1;   mov[0][1]=1;
    mov[1][0]=1;   mov[1][1]=1;
    mov[2][0]=1;   mov[2][1]=1;
    mov[3][0]=1;   mov[3][1]=1;
    mov[4][0]=1;   mov[4][1]=1;
    mov[5][0]=1;   mov[5][1]=1;
    mov[6][0]=1;   mov[6][1]=1;
    mov[7][0]=1;   mov[7][1]=1;
 
}


int main(int argc, char** argv) {
    
    char tablero[][MAXCOL]={
                            {'G','A','T','O','G'},
                            {'O','G','O','A','O'},
                            {'L','B','O','C','L'},
                            {'R','A','T','L','N'}
    };
    
    //palabra a buscar
    int n=3;
    char palabra[]={'G','O','L'};
    movimientosPermitidos();
    
    

    return 0;
}

