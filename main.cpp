#include <iostream>
#include <cstdio>
#define ROZMIAR_TAB 10

void WypiszTablice(int *wsk, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("Pozycja [%d] = %d\n", i, wsk[i]);
    }
}

int ZnajdzMax(int *wsk, int rozmiar) {
    int maksimum = wsk[0];
    for (int i = 1; i < rozmiar; i++) {
        if (maksimum < wsk[i]) {
            maksimum = wsk[i];
        }
    }
    return maksimum;
}

int ZnajdzMin(int *wsk, int rozmiar) {
    int minimum = wsk[0];
    for (int i = 1; i < rozmiar; i++) {
        if (minimum > wsk[i]) {
            minimum = wsk[i];
        }
    }
    return minimum;
}

int SumaTablicy(int *wsk, int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += *(wsk + i);
    }
    return suma;
}

float SredniaArytmetyczna(int *wsk, int rozmiar) {
    return (float)SumaTablicy(wsk, rozmiar) / rozmiar;
}

void SortujBabelkowo(int *wsk, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (*(wsk + j) > *(wsk + j + 1)) {
                int bufor = *(wsk + j);
                *(wsk + j) = *(wsk + j + 1);
                *(wsk + j + 1) = bufor;
            }
        }
    }
}

void KlonujTablice(int *zrodlo, int *cel, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        *(cel + i) = *(zrodlo + i);
    }
}

double ZnajdzMediane(int *wsk, int rozmiar) {
    int temp[ROZMIAR_TAB];
    KlonujTablice(wsk, temp, rozmiar);
    SortujBabelkowo(temp, rozmiar);

    if (rozmiar % 2 != 0) {
        return (double)temp[rozmiar / 2];
    } else {
        return (temp[rozmiar / 2 - 1] + temp[rozmiar / 2]) / 2.0;
    }
}

void PokazMenu() {
    printf("\nMENU GLOWNE\n");
    printf("1. pokaz elementy tablicy\n");
    printf("2. wypisz najwieksza liczbe\n");
    printf("3. wypisz najmniejsza liczbe\n");
    printf("4. oblicz sume wszystkich liczb\n");
    printf("5. oblicz srednia arytmetyczna\n");
    printf("6. wyznacz mediane\n");
    printf("0. wyjdz z aplikacji\n");
    printf("twoj wybor: ");
}

int main() {
    int liczby[ROZMIAR_TAB] = {12, 5, 88, 3, 11, 42, 7, 19, 60, 2};
    int opcja;

    do {
        PokazMenu();
        scanf("%d", &opcja);

        switch (opcja) {
            case 1:
                printf("\nobecny stan tablicy:\n");
                WypiszTablice(liczby, ROZMIAR_TAB);
                break;
            case 2:
                printf("\nmaksimum wynosi: %d\n", ZnajdzMax(liczby, ROZMIAR_TAB));
                break;
            case 3:
                printf("\nminimum wynosi: %d\n", ZnajdzMin(liczby, ROZMIAR_TAB));
                break;
            case 4:
                printf("\nsuma wynosi: %d\n", SumaTablicy(liczby, ROZMIAR_TAB));
                break;
            case 5:
                printf("\nsrednia wynosi: %.2f\n", SredniaArytmetyczna(liczby, ROZMIAR_TAB));
                break;
            case 6:
                printf("\nmediana wynosi: %.2f\n", ZnajdzMediane(liczby, ROZMIAR_TAB));
                break;
            case 0:
                printf("\nkoniec dzialania programu.\n");
                break;
            default:
                printf("\nnieprawidlowa opcja!\n");
                break;
        }
    } while (opcja != 0);

    return 0;
}