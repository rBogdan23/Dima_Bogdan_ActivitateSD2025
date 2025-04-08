#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS

int main() {
    // Definirea unui vector de 5 elemente (dimensiune fixă)
    int vector[5] = { 10, 20, 30, 40, 50 };

    // Accesarea și afișarea elementelor din vector
    printf("Elementele vectorului sunt:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elementul %d: %d\n", i + 1, vector[i]);
    }

    // Modificarea unui element al vectorului
    vector[2] = 100; // Schimbăm elementul de pe poziția 3 (index 2)

    printf("\nDupă modificare:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elementul %d: %d\n", i + 1, vector[i]);
    }

    return 0;
}
