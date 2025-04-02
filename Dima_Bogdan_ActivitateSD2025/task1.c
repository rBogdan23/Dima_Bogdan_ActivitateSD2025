#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definirea structurii Bicicleta
typedef struct {
    int cod;
    char* brand;
    int nrViteze;
    float* preturi;
} Bicicleta;
// Funcție pentru citirea unui obiect de tip Bicicleta
Bicicleta citireBicicleta() {
    Bicicleta b;
    printf("Introdu codul: ");
    scanf("%d", &b.cod);

    char buffer[100];
    printf("Introdu brandul: ");
    scanf("%s", buffer);
    b.brand = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(b.brand, buffer);

    printf("Introdu numarul de viteze: ");
    scanf("%d", &b.nrViteze);

    b.preturi = (float*)malloc(b.nrViteze * sizeof(float));
    printf("Introdu pretul pentru fiecare model: \n");
    for (int i = 0; i < b.nrViteze; i++) {
        printf("Model %d: ", i + 1);
        scanf("%f", &b.preturi[i]);
    }

    return b;
}
