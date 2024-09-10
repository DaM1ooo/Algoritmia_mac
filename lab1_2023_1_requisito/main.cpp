
/* 
 * File:   main.cpp
 * Author: danitzamichi
 *
 * Created on August 28, 2024, 11:21 AM
 */

#include<iostream>
#include<cmath>


using namespace std;


void cargaBin(int cromo[], int decimal){
    int i=0;
    while(decimal>0){
        cromo[i]=decimal%2;
        decimal=decimal/2;
        i++;
    }
    
}

bool tiene_requisitos_completos(int requisito[8][2], int cromo[],int n){
    int control, valido=0;
    for(int i=0; i<n; i++){
        if(cromo[i]==1){
            int j;
            for(j=0; j<2; j++){
                if(requisito[i][j]==0) break;   //no tiene requisito previo
                control=requisito[i][j];
                if(cromo[control-1]==1) valido++;
                
            }
            if(valido==j) return true;  //cumple con todos los requisitos
        }
        
    }

    return false;
}


int main(int argc, char** argv) {
    int n=8;
    int inversion[]={32,8,40,40,20,4,16,16};
    
    int beneficio[]={60,32,120,60,32,20,48,60};
    int requisito[8][2]={
                        {0,0},
                        {0,0},
                        {1,2},
                        {0,0},
                        {0,0},
                        {2,0},
                        {6,0},
                        {6,0}
                    };
    
    int asignacion=100;
    
    int opciones=pow(2,n);
    int costo_parcial=0, beneficio_parcial=0, mayor_beneficio, mejor_solucion;
    int cromo[]={0,0,0,0,0,0,0,0};
    
    for(int i=0; i<opciones; i++){
        costo_parcial=0;
        beneficio_parcial=0;
        
        cargaBin(cromo, i);
        
        for(int j=0; j<n; j++){
            costo_parcial+=cromo[j]*inversion[j];
            beneficio_parcial+=cromo[j]*beneficio[j];
        }
        
        if(costo_parcial==asignacion){
            if(tiene_requisitos_completos(requisito,cromo, n)){
                if(mayor_beneficio<beneficio_parcial){
                    mayor_beneficio=beneficio_parcial; 
                    mejor_solucion=i;
                    
                }
            }
        }
    }
    
    cout<<"mayor beneficio: "<<mayor_beneficio<<endl;
    cargaBin(cromo, mejor_solucion);
    for(int j=0; j<n; j++){
            if(cromo[j]==1) cout<<j+1<<" ";
        }
    
    
    
    
    
    return 0;
}

