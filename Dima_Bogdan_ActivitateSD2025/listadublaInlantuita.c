#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura nodului
typedef struct Nod {
    int valoare;
    struct Nod* urmator;
    struct Nod* precedent;
} Nod;

// Inserare la final
void inserareFinal(Nod** cap, int valoare) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->valoare = valoare;
    nou->urmator = NULL;
    nou->precedent = NULL;

    if (*cap == NULL) {
        *cap = nou;
    }
    else {
        Nod* temp = *cap;
        while (temp->urmator != NULL)
            temp = temp->urmator;
        temp->urmator = nou;
        nou->precedent = temp;
    }
}