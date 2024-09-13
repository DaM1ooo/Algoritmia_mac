
/* 
 * File:   main.cpp
 * Author: danitzamichi
 *
 * Created on September 12, 2024, 8:17 PM
 */


#include<iostream>
#include<cmath>

using namespace std;

//int buscaUnidades(int x,int y,int n,int m,int tablero[6][6]){
//    
//    //caso valida no se sale del tablero
//    if(x<0 or y<0 or x>=n or y>=m) return 0;
//        
//    int cont=0;
//    
//    //recursion
//    //puede crecer-retroceder
//    if(x>=0 and y>=0)
//        cont+= tablero[x][y]+buscaUnidades(x-1,y-1,n,m,tablero);
//    if(y<=m-1 and x<=n-1)
//        cont+= tablero[x][y]+buscaUnidades(x+1,y+1,n,m,tablero);
//    if(x>=0)
//        cont+= tablero[x][y]+buscaUnidades(x-1,y,n,m,tablero);
//    if(x<=n-1)
//        cont+= tablero[x][y]+buscaUnidades(x+1,y,n,m,tablero);
//    if(y>=0)
//        cont+= tablero[x][y]+buscaUnidades(x,y-1,n,m,tablero);  
//    if(y<=m-1)
//        cont+= tablero[x][y]+buscaUnidades(x,y+1,n,m,tablero); 
//    
//    return cont;
//}

int buscaUnidades(int x,int y,int n,int m,int tablero[6][6]){
    
    //caso valida no se sale del tablero
    if(x<0 or y<0 or x>=n or y>=m) return 0;
        
    int cont=0;
    
    //recursion
    //puede crecer-retroceder
    if(x>0 and y>0)
        cont+= tablero[x][y] + buscaUnidades(x-1,y-1,n,m,tablero);
    else
        for(int i=y; i<n-y-1; i++){   //horizontal
            cont+= tablero[x][i];   
        }
        for(int i=x; i<n-y-1; i++){   //vertical
            cont+= tablero[i][y];   
        }        
    
    if(y<m and x<n)
        cont+= tablero[x][y]+buscaUnidades(x+1,y+1,n,m,tablero);
    else
        for(int i=n-y-1; i>x+1; i--){   //horizontal
            cont+= tablero[i][y];   
        }
        for(int i=n-y-1; i>y+1; i--){   //vertical
            cont+= tablero[x][i];   
        } 

    
    return cont;
}

int main(int argc, char** argv) {

    int tablero[6][6]={ {0,0,0,1,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,1,0},
                        {0,0,0,0,1,0}
                        };


    
    cout<<"Unidades encontradas: "<<buscaUnidades(3,2,6,6,tablero);
    
    return 0;
}

