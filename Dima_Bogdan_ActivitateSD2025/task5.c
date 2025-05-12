#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura Bicicleta
typedef struct {
    int cod;
    char* brand;
    int nrViteze;
} Bicicleta;

// Nod pentru lista simplu inlantuita
typedef struct Nod {
    Bicicleta b;
    struct Nod* next;
} Nod;

// Functie pentru creare bicicleta
Bicicleta creareBicicleta(int cod, const char* brand, int nrViteze) {
    Bicicleta b;
    b.cod = cod;
    b.nrViteze = nrViteze;
    b.brand = strdup(brand);
    return b;
}

// Inserare sortata dupa nrViteze
void inserareSortata(Nod** cap, Bicicleta b) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    nodNou->b = creareBicicleta(b.cod, b.brand, b.nrViteze);
    nodNou->next = NULL;

    if (*cap == NULL || b.nrViteze < (*cap)->b.nrViteze) {
        nodNou->next = *cap;
        *cap = nodNou;
    }
    else {
        Nod* temp = *cap;
        while (temp->next && temp->next->b.nrViteze < b.nrViteze) {
            temp = temp->next;
        }
        nodNou->next = temp->next;
        temp->next = nodNou;
    }
}

// Afisare lista
void afisareLista(Nod* cap) {
    int i = 0;
    while (cap) {
        printf("Bicicleta %d: Cod: %d, Brand: %s, Viteze: %d\n", ++i, cap->b.cod, cap->b.brand, cap->b.nrViteze);
        cap = cap->next;
    }
}

// Stergere nod la o pozitie data
void stergeLaPozitie(Nod** cap, int pozitie) {
    if (*cap == NULL) return;

    Nod* temp = *cap;

    if (pozitie == 0) {
        *cap = temp->next;
        free(temp->b.brand);
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < pozitie - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Nod* nodDeSters = temp->next;
    temp->next = nodDeSters->next;
    free(nodDeSters->b.brand);
    free(nodDeSters);
}

// Interschimbare elemente pe pozitii
void interschimbaPozitii(Nod* cap, int p1, int p2) {
    if (p1 == p2) return;

    Nod* n1 = NULL, * n2 = NULL;
    Nod* temp = cap;
    int i = 0;

    while (temp) {
        if (i == p1) n1 = temp;
        if (i == p2) n2 = temp;
        temp = temp->next;
        i++;
    }

    if (n1 && n2) {
        Bicicleta aux = n1->b;
        n1->b = n2->b;
        n2->b = aux;
    }
}

// Salvare in vector (deep copy) biciclete cu nrViteze > prag
Bicicleta* salvareInVector(Nod* cap, int* dim, int prag) {
    int count = 0;
    Nod* temp = cap;

    while (temp) {
        if (temp->b.nrViteze > prag) count++;
        temp = temp->next;
    }

    *dim = count;
    Bicicleta* vector = (Bicicleta*)malloc(count * sizeof(Bicicleta));

    temp = cap;
    int i = 0;
    while (temp) {
        if (temp->b.nrViteze > prag) {
            vector[i].cod = temp->b.cod;
            vector[i].nrViteze = temp->b.nrViteze;
            vector[i].brand = strdup(temp->b.brand);
            i++;
        }
        temp = temp->next;
    }

    return vector;
}

// Eliberare memorie lista
void elibereazaLista(Nod* cap) {
    while (cap) {
        Nod* temp = cap;
        cap = cap->next;
        free(temp->b.brand);
        free(temp);
    }
}

int main() {
    Nod* lista = NULL;

    inserareSortata(&lista, creareBicicleta(1, "Cube", 18));
    inserareSortata(&lista, creareBicicleta(2, "Merida", 24));
    inserareSortata(&lista, creareBicicleta(3, "Scott", 10));
    inserareSortata(&lista, creareBicicleta(4, "Trek", 21));

    printf("\nLista initiala:\n");
    afisareLista(lista);

    stergeLaPozitie(&lista, 2);
    printf("\nLista dupa stergerea pozitiei 2:\n");
    afisareLista(lista);

    interschimbaPozitii(lista, 0, 1);
    printf("\nLista dupa interschimbarea pozitiilor 0 si 1:\n");
    afisareLista(lista);

    int dimVector;
    Bicicleta* vector = salvareInVector(lista, &dimVector, 15);
    printf("\nVectorul de biciclete cu nrViteze > 15:\n");
    for (int i = 0; i < dimVector; i++) {
        printf("Bicicleta: Cod: %d, Brand: %s, Viteze: %d\n", vector[i].cod, vector[i].brand, vector[i].nrViteze);
        free(vector[i].brand);
    }
    free(vector);

    elibereazaLista(lista);
    return 0;
}
