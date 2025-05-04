#include <iostream>
using namespace std;

const int fil = 4;
const int col = 4;

int isla = 2;

void cuadrante (int *i, int *inicio, int *fin){
    
    if (*i > 0){    // Si es 0 no es necesario comprobar nada
            
        // Ver si el valor analizado es una nueva isla o es el inicio de una

        if (*i == 1){
            *i = isla;
            isla++;
        };
            
        // Crear lista para manipular los valores
        
        int valores[col] = {0};      // Lista de valores (Arriba, Abajo, Derecha, Izquierda)
            
        // Busqueda de los valores
            
        //Arriba
        if(i-col >= inicio){             // No salirse de los limites
            *valores = *(i-col);         // Añadir a lista de valores
            if (*valores == 1){          // Si el valor de la lista fue modificado entonces ...
                *(i-col) = *i;           // ... modificar el valor en la matriz principal (¿Porqué? - Propagación del valor) 
            }
        };
        //Abajo
        if(i+col < fin){
            *(valores+1) = *(i+col);
            if (*(valores+1) == 1){
                *(i+col) = *i;
            }
        };
        // Derecha
        if(((i-inicio)+1) % col != 0){    // % para no salirse de los limites
            *(valores+2) = *(i+1);
            if (*(valores+2) == 1){
                *(i+1) = *i;
            }
        };
        // Izquierda
        if((i-inicio) % col != 0){        // % para no salirse de los limites
            *(valores+3) = *(i-1);
            if (*(valores+3) == 1){
                *(i-1) = *i;
            }
        };
    }
};

int main() {
    
    int A[fil][col] = {
        
        {1, 1, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1}
        
    };

    // Buscar las islas

    for(int (*i)[fil]=A; i < A + fil; i++){
        for(int *j = *i; j < *i + col; j++){
            cuadrante(j,*A, *A+(fil*col));      // cuadrante(Matriz, inicio, fin)
        }
    }
    
    // Imprimir matriz
    
    for(int (*i)[fil]=A; i < A + fil; i++){
        for(int *j = *i; j < *i + col; j++){
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    cout << "El número de islas es: " << isla-2;  // Inicia en 1 al final le agrega 1 entonces se debe reducir en 2 para ver el tamaño

    return 0;
}