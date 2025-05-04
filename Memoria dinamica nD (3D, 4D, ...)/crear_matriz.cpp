
// Crear una matriz de p x f x c en memoria dinamica

#include <iostream>

int main() {
    
    int p = 3; // Planos
    int f = 2; // Filas
    int c = 2; // Columnas
    
    // (1) Generar raiz de la matriz (Número de planos) [O * o * o]
    
    int ***M = new int**[p];
    
    //(2.2) ***M = [int**, int**, int** ...]
    
    for (int ***i = M; i < M + p; i++){ // iterar p (planos)
    
        *i = new int*[f]; 
        
        // (2.1) Dref i (***i -> **i | ¿Qué será **i? - Array de *i | new int*[número de fils]) [X * O * o]
        // (2.2) **i = [int*, int*, int* ...]
        
        for (int **j = *i; j < *i + c; j++){ // iterar f (filas)
        
            *j = new int[c];
            
            // (3.1) Dref j (**j -> *j | ¿Qué será *j? - Array de j | new int[número de colums]) [X * X * O]
            // (3.2) *j = [int, int, int ...] 
            
        }
    }
    
    //[... Programa]

    // Limpieza de la matriz
    for (int ***i = M; i < M + p; i++){
        for (int **j = *i; j < *i + f; j++){
            delete [] *j;    // Eliminar columnas ***j
        }
        delete [] *i;        // Eliminar filas **i
    }
    delete [] M;             // Eliminar matriz M ("*M") | Nombre del array puntero al primer elemento

}