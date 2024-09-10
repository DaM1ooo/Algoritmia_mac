
/* 
 * File:   main.cpp
 * Author: danitzamichi
 *
 * Created on September 4, 2024, 1:34 PM
 */


#include <iostream>
#include <cmath>


using namespace std;


void cargarBin(int *cromo, int decimal){
    int i=0;
    while(decimal>0){
        cromo[i]=decimal%2;
        decimal/=2;
        i++;
    }
}

bool cumple_requisitos(int *inversion, int *cromo,int  requisitos[8][2], int n){
    int i, control, cont=0, cumplen=0, proyectos=0;
    
    for(i=0; i<n; i++){     // 0 0 [1] 0 1 1 0 0
        control=cromo[i]*i;
        
        if(control!=0){
            proyectos++;
            
            int j;
            cont=0;
            for(j=0; j<2;j++){
                if(requisitos[control][j]==0) break;
                if(cromo[ requisitos[control][j]-1 ]==1) cont++;
            }
            if(cont==j) cumplen++;
        }
    }
    
    
    if(cumplen==proyectos) return true;
    return false;
}





int main(int argc, char** argv) {

    int n=8;
    int inversion[8]={32,8,40,40,20,4,16,16};
    int beneficio[8]={60,32,120,60,32,20,48,60};
    int requisitos[8][2]={
                            {0,0},
                            {0,0},
                            {1,2},
                            {0,0},
                            {0,0},
                            {2,0},
                            {6,0},
                            {6,0}
                            };
    int max_inversion=100;
    
    int opciones=pow(2, n);
    int cromo[8]={0,0,0,0,0,0,0,0};
    int inversion_parcial=0, max_beneficio=0, beneficio_parcial=0, mejor_solucion=0;
    
    
    for(int i=1; i<opciones; i++){
        inversion_parcial=0;
        beneficio_parcial=0;
        cargarBin(cromo, i);
        
        for(int j=0; j<n; j++){
            inversion_parcial+=cromo[j]*inversion[j];
            beneficio_parcial+=cromo[j]*beneficio[j];
        }
        
        if(inversion_parcial<=max_inversion){
            if(cumple_requisitos(inversion, cromo, requisitos, n)){
                if(max_beneficio<beneficio_parcial){
                    max_beneficio=beneficio_parcial;
                    mejor_solucion=i;
                    
                }
            }
        }
    }
    
    
    cargarBin(cromo, mejor_solucion);
    for(int j=0; j<n; j++){
        if(cromo[j]!=0)
            cout<<j+1<< " ";
    }
    cout<<endl<<"Mayor beneficio: "<<max_beneficio<<endl;
    
    
    return 0;
}

