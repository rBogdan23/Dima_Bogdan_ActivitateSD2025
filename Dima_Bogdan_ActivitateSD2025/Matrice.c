#include <stdio.h>
#include <stdlib.h>

// Funcție pentru alocarea unei matrici dinamice
int** alocaMatrice(int linii, int coloane) {
    int** matrice = (int**)malloc(linii * sizeof(int*));
    for (int i = 0; i < linii; i++) {
        matrice[i] = (int*)malloc(coloane * sizeof(int));
    }
    return matrice;
}

// Funcție pentru citirea valorilor în matrice
void citesteMatrice(int** matrice, int linii, int coloane) {
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            printf("matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

// Funcție pentru afișarea matricei
void afiseazaMatrice(int** matrice, int linii, int coloane) {
    printf("Matricea este:\n");
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

// Funcție pentru suma elementelor
int sumaElemente(int** matrice, int linii, int coloane) {
    int suma = 0;
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            suma += matrice[i][j];
        }
    }
    return suma;
}

// Funcție pentru modificarea unui element
void modificaElement(int** matrice, int linie, int coloana, int nouaValoare) {
    matrice[linie][coloana] = nouaValoare;
}

// Funcție pentru eliberarea memoriei
void elibereazaMatrice(int** matrice, int linii) {
    for (int i = 0; i < linii; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

int main() {
    int linii, coloane;

    printf("Introdu numarul de linii: ");
    scanf("%d", &linii);
    printf("Introdu numarul de coloane: ");
    scanf("%d", &coloane);

    int** matrice = alocaMatrice(linii, coloane);

    citesteMatrice(matrice, linii, coloane);
    afiseazaMatrice(matrice, linii, coloane);

    printf("Suma elementelor: %d\n", sumaElemente(matrice, linii, coloane));

    printf("Modificare element [0][0] in 999...\n");
    modificaElement(matrice, 0, 0, 999);
    afiseazaMatrice(matrice, linii, coloane);

    elibereazaMatrice(matrice, linii);
    return 0;
}
