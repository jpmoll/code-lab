#include <iostream>
using namespace std;

// Global vars

int p = 3;
int f = 3;
int c = 3;

void printM(int ***M){
    for (int ***i = M; i < M + p; i++){
        for (int **j = *i; j < *i + c; j++){
            for(int *k = *j; k < *j + c; k++){
                cout << *k << " ";
            }
        cout << endl;
        }
    cout << endl;
    }
}

void buscarRes(int ***M, int res){

    // Mover todo al mismo tiempo

    for(int **M1 = *M, **M2 = *(M+1), **M3 = *(M+2); M1 < *M + f; M1++, M2++, M3++){
        for(int *v1 = *M1, *v2 = *M2, *v3 = *M3; v1 < *M1 + c; v1++, v2++, v3++){
            int fila = M1 - *M;
            int col = v1 - *M1;
            if(res == (*v1 - *v2 - *v3)){
                cout << "Fil: " << fila << " | Col: " << col << " | "<< *v1 << " - " << *v2 << " - " << *v3 << " = " << res << endl;
                return;
            }
        }
    }
}


int main() {

    int ***M = new int**[p];
        
    for (int ***i = M; i < M + p; i++){
        *i = new int*[f]; 
        for (int **j = *i; j < *i + c; j++){
            *j = new int[c];
            for(int *k = *j; k < *j + c; k++){
                *k = rand()%10;
            }
        }
    }
    
    printM(M);

    // Probar las funciones

    int res = -10;
    buscarRes(M, res);
    
    // Eliminar
    
    for (int ***i = M; i < M + p; i++){
        for (int **j = *i; j < *i + f; j++){
            delete [] *j;
        }
        delete [] *i;
    }
    delete [] M;
}