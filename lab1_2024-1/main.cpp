
/* 
 * File:   main.cpp
 * Author: danitzamichi
 *
 * Created on September 4, 2024, 2:51 PM
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
    

bool cumple_requisito_arma(int *cromo, int armas_preRquisito[12][3],int n){
    int arma, cont=0, cumple=0, arma_seleccionada=0;
    
    for(int i=0; i<12; i++){
        if(cromo[i]!=0){
            arma_seleccionada++;
            arma=cromo[i]*i;
            int j;
            for(int j=0; j<3; j++){
                if(armas_preRquisito[arma][j]==0) break;
                if(cromo[ armas_preRquisito[arma][j] -1 ] ==1  ) cont++;
            }
            if(cont==j) cumple++;
        }
    }
    if(cumple==arma_seleccionada) return true;
    return false;
}


bool cumple_tipo_arma(int *cromo, int tipo_arma, int n){
    int m, cont=0, activo=0;
   for(m=0; m<12;m++){
       if(cromo[1]==1) activo++;
        if(cromo[m]==tipo_arma)
            cont++;
    } 
    if(cont==activo) return true;
    return false;
}
    //superar el poder del guerrero con un arma en especifico
    //armas con prerequisito viaja en la misma mochila, armas prerequisitos juntas
    //poder de armass en mochilass mayor al del guerrero
 
    //poo vence a estos 3 guerreros

int main(int argc, char** argv) {
    
    int guerreros_maximos=3;
    int guerrero_poder[3]={120,160,80};
    int guerrero_tipo_arma[3][3]={
                                {2,0,0},
                                {1,3,0},
                                {3,0,0}
                            };
    
    int n_arma=12;
    int arma_poder[12]={60,80,38,25,49,57,68,35,62,42,36,54};
    int arma_tipo[12]={3,1,2,2,2,1,3,2,2,2,1,3};
    int armas_preRquisito[12][3]={
        {0,0,0},
        {1,0,0},
        {0,0,0},
        {3,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {1,5,0},
        {3,0,0},
        {0,0,0},
        {1,0,0},
        {0,0,0},
    };
    
    
    int opciones=pow(2,12); // 
    int poder_parcial_acumulado=0;
    int cromo[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    int cromo_solucion[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    int cromo_mejor_solucion[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(int g=0; g<3;g++){
        int poder_guerrero=guerrero_poder[g];
        int mejor_solucion=0;
        
        for(int t=0; t<3; t++){
            int tipo_arma=guerrero_tipo_arma[g][t];
            
         //busca soluciones   
             for(int i=0; i<opciones; i++){
                poder_parcial_acumulado=0;
                cargarBin(cromo, i);
                for(int j=0; j<12;j++){
                    poder_parcial_acumulado+=cromo[j]*arma_poder[j]; 
                    
//                    if(cromo[j]*arma_tipo[j] == tipo_arma){
//                        poder_parcial_acumulado+=cromo[j]*arma_poder[j]; 
//                        cromo_solucion[j]=cromo[j];
//                    }
//                    cromo_solucion[j]=0;  
                }

                if(poder_parcial_acumulado<=poder_guerrero){
                    
                    if(cumple_requisito_arma(cromo_solucion, armas_preRquisito, n_arma)){
                        if(cumple_tipo_arma(cromo, tipo_arma, n_arma)){
                            cout<<"poder: "<<poder_guerrero<<endl;
        
                            for(int m=0; m<12;m++){
                                if(cromo[m]!=0)
                                    cout<<m+1<<" ";
                            }
                            
                        }
                    }
                }
            }
        }
        
    }
    
    

    return 0;
}

