//#include <stdio.h>
//#include <stdlib.h>
//
//// Definirea structurii unui nod
//typedef struct Nod {
//    int valoare;          // Valoarea stocată în nod
//    struct Nod* urmator;  // Pointer către următorul nod
//} Nod;
//
//// Funcție pentru a adăuga un element la sfârșitul listei
//void adauga_element(Nod** cap, int valoare) {
//    Nod* nou_nod = (Nod*)malloc(sizeof(Nod));  // Alocăm memorie pentru un nou nod
//    nou_nod->valoare = valoare;  // Setăm valoarea nodului
//    nou_nod->urmator = NULL;  // În primul rând, următorul nod este NULL (finalul listei)
//
//    if (*cap == NULL) {  // Dacă lista este goală, noul nod devine capul listei
//        *cap = nou_nod;
//    }
//    else {
//        Nod* temp = *cap;
//        while (temp->urmator != NULL) {  // Parcurgem lista până la ultimul nod
//            temp = temp->urmator;
//        }
//        temp->urmator = nou_nod;  // Adăugăm noul nod la sfârșitul listei
//    }
//}
//
//// Funcție pentru a afișa lista
//void afiseaza_lista(Nod* cap) {
//    if (cap == NULL) {
//        printf("Lista este goala!\n");
//        return;
//    }
//    Nod* temp = cap;
//    while (temp != NULL) {  // Parcurgem lista și afișăm valorile nodurilor
//        printf("%d -> ", temp->valoare);
//        temp = temp->urmator;
//    }
//    printf("NULL\n");
//}
//
//// Funcție pentru a elibera memoria alocată listei
//void elibereaza_lista(Nod* cap) {
//    Nod* temp;
//    while (cap != NULL) {
//        temp = cap;
//        cap = cap->urmator;  // Mutăm capul la următorul nod
//        free(temp);  // Eliberăm memoria pentru nodul curent
//    }
//}
//
//int main() {
//    Nod* lista = NULL;  // Inițial lista este goală (NULL)
//
//    // Adăugăm elemente în listă
//    adauga_element(&lista, 10);
//    adauga_element(&lista, 20);
//    adauga_element(&lista, 30);
//    adauga_element(&lista, 40);
//
//    // Afișăm lista
//    printf("Lista simpla: ");
//    afiseaza_lista(lista);
//
//    // Eliberăm memoria
//    elibereaza_lista(lista);
//
//    return 0;
//}
