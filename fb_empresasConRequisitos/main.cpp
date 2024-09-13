/* 
 * File:   main.cpp
 * Author: danit
 *
 * Created on April 9, 2024, 1:58 PM
 */
#include<iostream>
#include<iomanip>
#include<cmath>
#define Y 3
using namespace std;

void cargaBin(int num,int *cromo, int n){
    int i=0;
    while(num>0){
        cromo[i]=num%2;
        num=num/2;
        i++;
    }
}

bool verificaRequisito(int *inversion, int *cromo,int requisito[][Y],int n){
    
    for(int i=0; i<n; i++){
        if(cromo[i]){
            for(int j=0; j<Y; j++){
                if(!cromo[requisito[i][j]-1]) return false;
            }

        }        
 
    }
    return true;
}


int main(int argc, char** argv) {
    
    int xn=8;
    int inversion[n]={32,8,41,41,20,4,16,16};
    int beneficio[n]={60,32,120,60,32,20,48,60};
    int requisito[n][Y]={{0,0,0},
                        {0,0,0},
                        {1,2,0},
                        {0,0,0},
                        {0,0,0},
                        {2,0,0},
                        {6,0,0},
                        {6,0,0}
                        };

    int p=100; //monto maximo asignado
    int combinaciones=pow(2, n);
    int cromo[n];
    int inversionParcial;
    int mayorGanancia=0, ganancia, solucion;
    
    for(int i=1; i<combinaciones; i++){
        inversionParcial=0;
        ganancia=0;
        cargaBin(i,cromo, n);
        for(int j=0; j<n;j++){
            if(cromo[j]){
                inversionParcial+=inversion[j];
                ganancia+=beneficio[j];
            }
        }

        if(inversionParcial<=p and verificaRequisito(inversion, cromo,requisito, n)){
            //encuentra una solucion y verifica que cumpla con el requisito          
            if(mayorGanancia<ganancia){                
                mayorGanancia=ganancia;
                solucion=i;

            }

        }
    }
    
        
    cargaBin(solucion,cromo, n);
    cout<<"Inversiones: "<<endl;
    for(int j=0; j<n;j++){
        if(cromo[j]) cout<<"P"<<j+1<<" "<<inversion[j]<<endl;
    }
    cout<<endl;
    
    
    return 0;
}

