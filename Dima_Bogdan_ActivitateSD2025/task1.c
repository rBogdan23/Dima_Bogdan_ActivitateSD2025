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
    scanf_s("%d", &b.cod);

    char buffer[100];
    printf("Introdu brandul: ");
    scanf_s("%s", buffer);
    b.brand = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(b.brand, buffer);

    printf("Introdu numarul de viteze: ");
    scanf_s("%d", &b.nrViteze);

    b.preturi = (float*)malloc(b.nrViteze * sizeof(float));
    printf("Introdu pretul pentru fiecare model: \n");
    for (int i = 0; i < b.nrViteze; i++) {
        printf("Model %d: ", i + 1);
        scanf_s("%f", &b.preturi[i]);
    }

    return b;

}
// Funcție pentru calculul pretului mediu
float pretMediu(Bicicleta b) {
    float suma = 0;
    for (int i = 0; i < b.nrViteze; i++) {
        suma += b.preturi[i];
    }
    return (b.nrViteze > 0) ? suma / b.nrViteze : 0;
}

