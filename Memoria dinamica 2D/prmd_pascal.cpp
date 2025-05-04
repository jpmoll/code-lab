#include <iostream>
using namespace std;

void verificar(int list[], int tam, int **P){

    int *ult = *(P+tam-1);
    int iter = 0;

    for(int *i = list; i < list + tam; i++, iter++){
        if (*i != *(ult + iter)){
            cout << "No es parte de la piramide de pascal" << endl;
            return;
        }
    }
    cout << "Es parte de la piramide de pascal" << endl;
}

int main()
{
    int list[]= {1,6,15,20,15,6,1};
    
    int tam = sizeof(list) / sizeof(int);
    
    int **P = new int*[tam];
    int t = 1;
    
    for(int **f = P; f < P + tam; f++, t++){
        
        *f = new int [t];
        
        for (int *v = *f; v < *f + t; v++){
            
            int *ini = *f;
            int *fin = *f+(t-1);
            
            *ini = 1;
            *fin = 1;
            
        }
        if (t > 2){
            int iter = 0;
            for (int *v = *f+1; v < *f + t-1; v++, iter++){
                *v = *(*(f-1)+iter)+*(*(f-1)+iter+1);
            }
        }
    }

    verificar(list, tam, P);
    
    for(int **f = P; f < P + tam; f++, t++){
        delete []*f;
    }
    
    delete [] P;
}