//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// Structura nodului
//typedef struct Nod {
//    int valoare;
//    struct Nod* urmator;
//    struct Nod* precedent;
//} Nod;
//
//// Inserare la final
//void inserareFinal(Nod** cap, int valoare) {
//    Nod* nou = (Nod*)malloc(sizeof(Nod));
//    nou->valoare = valoare;
//    nou->urmator = NULL;
//    nou->precedent = NULL;
//
//    if (*cap == NULL) {
//        *cap = nou;
//    }
//    else {
//        Nod* temp = *cap;
//        while (temp->urmator != NULL)
//            temp = temp->urmator;
//        temp->urmator = nou;
//        nou->precedent = temp;
//    }
//}
//// Afișare de la cap la coadă
//void afisareDirecta(Nod* cap) {
//    printf("Lista direct: ");
//    while (cap != NULL) {
//        printf("%d ", cap->valoare);
//        cap = cap->urmator;
//    }
//    printf("\n");
//}
//// Afișare de la coadă la cap
//void afisareInversa(Nod* cap) {
//    if (cap == NULL) return;
//
//    while (cap->urmator != NULL)
//        cap = cap->urmator;
//
//    printf("Lista invers: ");
//    while (cap != NULL) {
//        printf("%d ", cap->valoare);
//        cap = cap->precedent;
//    }
//    printf("\n");
//}
//// Căutare a unui element
//Nod* cauta(Nod* cap, int valoare) {
//    while (cap != NULL) {
//        if (cap->valoare == valoare)
//            return cap;
//        cap = cap->urmator;
//    }
//    return NULL;
//}
//// Ștergere nod cu valoare dată
//void sterge(Nod** cap, int valoare) {
//    Nod* temp = *cap;
//
//    while (temp != NULL && temp->valoare != valoare)
//        temp = temp->urmator;
//
//    if (temp == NULL) {
//        printf("Valoarea %d nu a fost gasita.\n", valoare);
//        return;
//    }
//
//    if (temp->precedent != NULL)
//        temp->precedent->urmator = temp->urmator;
//    else
//        *cap = temp->urmator;
//
//    if (temp->urmator != NULL)
//        temp->urmator->precedent = temp->precedent;
//
//    free(temp);
//    printf("Nodul cu valoarea %d a fost sters.\n", valoare);
//}
//
//// Eliberare memorie
//void elibereazaLista(Nod** cap) {
//    while (*cap != NULL) {
//        Nod* temp = *cap;
//        *cap = (*cap)->urmator;
//        free(temp);
//    }
//}
//int main() {
//    Nod* lista = NULL;
//
//    inserareFinal(&lista, 10);
//    inserareFinal(&lista, 20);
//    inserareFinal(&lista, 30);
//    inserareFinal(&lista, 40);
//
//    afisareDirecta(lista);
//    afisareInversa(lista);
//
//    Nod* gasit = cauta(lista, 30);
//    if (gasit != NULL)
//        printf("Valoarea %d a fost gasita in lista.\n", gasit->valoare);
//    else
//        printf("Valoarea nu a fost gasita.\n");
//
//    sterge(&lista, 20);
//    afisareDirecta(lista);
//
//    elibereazaLista(&lista);
//    return 0;
//}