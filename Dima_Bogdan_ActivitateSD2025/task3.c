#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

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

float pretMediu(Bicicleta b) {
    float suma = 0;
    for (int i = 0; i < b.nrViteze; i++) {
        suma += b.preturi[i];
    }
    return (b.nrViteze > 0) ? suma / b.nrViteze : 0;
}

void modificaBrand(Bicicleta* b, const char* nouBrand) {
    free(b->brand);
    b->brand = (char*)malloc((strlen(nouBrand) + 1) * sizeof(char));
    strcpy(b->brand, nouBrand);
}

void afisareBicicleta(Bicicleta b) {
    printf("Cod: %d\n", b.cod);
    printf("Brand: %s\n", b.brand);
    printf("Numar viteze: %d\n", b.nrViteze);
    printf("Preturi pe model: ");
    for (int i = 0; i < b.nrViteze; i++) {
        printf("%.2f ", b.preturi[i]);
    }
    printf("\n");
    printf("Pret mediu: %.2f\n", pretMediu(b));
}

void elibereazaMemorie(Bicicleta* b) {
    free(b->brand);
    free(b->preturi);
}

// Functie care filtreaza bicicletele cu mai mult de X viteze
Bicicleta* filtreazaViteze(Bicicleta* vector, int n, int minViteze, int* nouN) {
    Bicicleta* rezultat = (Bicicleta*)malloc(n * sizeof(Bicicleta));
    *nouN = 0;
    for (int i = 0; i < n; i++) {
        if (vector[i].nrViteze > minViteze) {
            rezultat[*nouN] = vector[i];
            (*nouN)++;
        }
    }
    return rezultat;
}

// Functie care muta bicicletele cu pret mediu sub o valoare intr-un nou vector
Bicicleta* mutaPretMic(Bicicleta* vector, int n, float limita, int* nouN) {
    Bicicleta* rezultat = (Bicicleta*)malloc(n * sizeof(Bicicleta));
    *nouN = 0;
    for (int i = 0; i < n; i++) {
        if (pretMediu(vector[i]) < limita) {
            rezultat[*nouN] = vector[i];
            (*nouN)++;
        }
    }
    return rezultat;
}

// Functie care concateneaza doi vectori de biciclete
Bicicleta* concateneaza(Bicicleta* v1, int n1, Bicicleta* v2, int n2, int* nTotal) {
    *nTotal = n1 + n2;
    Bicicleta* rezultat = (Bicicleta*)malloc((*nTotal) * sizeof(Bicicleta));
    for (int i = 0; i < n1; i++) rezultat[i] = v1[i];
    for (int i = 0; i < n2; i++) rezultat[n1 + i] = v2[i];
    return rezultat;
}

// Functie pentru afisarea unui vector de biciclete
void afisareVector(Bicicleta* vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nBicicleta %d:\n", i + 1);
        afisareBicicleta(vector[i]);
    }
}
// Functie pentru scrierea unui obiect in fisier text
void salveazaObiectInFisier(Bicicleta b, FILE* f) {
    fprintf(f, "%d %s %d ", b.cod, b.brand, b.nrViteze);
    for (int i = 0; i < b.nrViteze; i++) {
        fprintf(f, "%.2f ", b.preturi[i]);
    }
    fprintf(f, "\n");
}
// Functie care salveaza un vector de obiecte intr-un fisier text
void salveazaVectorInFisier(const char* numeFisier, Bicicleta* vector, int n) {
    FILE* f = fopen(numeFisier, "w");
    if (f == NULL) {
        printf("Eroare deschidere fisier pentru scriere.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        salveazaObiectInFisier(vector[i], f);
    }
    fclose(f);
}
// Functie care citeste obiecte din fisier si le returneaza ca vector
Bicicleta* citesteDinFisier(const char* numeFisier, int* n) {
    FILE* f = fopen(numeFisier, "r");
    if (!f) {
        printf("Eroare deschidere fisier pentru citire.\n");
        *n = 0;
        return NULL;
    }

    Bicicleta* vector = (Bicicleta*)malloc(20 * sizeof(Bicicleta)); // presupunem max 20
    *n = 0;
    while (!feof(f)) {
        Bicicleta b;
        char buffer[100];
        fscanf(f, "%d %s %d", &b.cod, buffer, &b.nrViteze);
        b.brand = (char*)malloc(strlen(buffer) + 1);
        strcpy(b.brand, buffer);

        b.preturi = (float*)malloc(b.nrViteze * sizeof(float));
        for (int i = 0; i < b.nrViteze; i++) {
            fscanf(f, "%f", &b.preturi[i]);
        }
        vector[(*n)++] = b;
    }
    fclose(f);
    return vector;
}

int main() {
    int n = 5;
    Bicicleta* biciclete = (Bicicleta*)malloc(n * sizeof(Bicicleta));
    printf("Citeste %d biciclete:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nBicicleta %d:\n", i + 1);
        biciclete[i] = citireBicicleta();
    }

    printf("\nToate bicicletele:\n");
    afisareVector(biciclete, n);

    // Filtrare viteze > 10
    int nFiltrate;
    Bicicleta* filtrate = filtreazaViteze(biciclete, n, 10, &nFiltrate);
    printf("\nBiciclete cu mai mult de 10 viteze:\n");
    afisareVector(filtrate, nFiltrate);

    // Mutare biciclete cu pret mic
    int nIeșite;
    Bicicleta* pretMic = mutaPretMic(biciclete, n, 1500.0f, &nIeșite);
    printf("\nBiciclete cu pret mediu sub 1500:\n");
    afisareVector(pretMic, nIeșite);

    // Concatenare
    int nConcat;
    Bicicleta* toate = concateneaza(filtrate, nFiltrate, pretMic, nIeșite, &nConcat);
    printf("\nVector concatenat:\n");
    afisareVector(toate, nConcat);

    // Eliberare memorie doar pentru cele originale
    for (int i = 0; i < n; i++) {
        elibereazaMemorie(&biciclete[i]);
    }
    free(biciclete);
    free(filtrate);
    free(pretMic);
    free(toate);

    // Salvare in fisier a vectorului original
    salveazaVectorInFisier("biciclete.txt", biciclete, n);

    // Citire din fisier
    int nFisier;
    Bicicleta* citite = citesteDinFisier("biciclete.txt", &nFisier);
    printf("\nBiciclete citite din fisier:\n");
    afisareVector(citite, nFisier);

    // Eliberare memorie citite
    for (int i = 0; i < nFisier; i++) {
        elibereazaMemorie(&citite[i]);
    }
    free(citite);

    return 0;
}