#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;

void yazdir();
void basaEkle(int veri);
void arayaEkle(int veri, int sira);
void sonaEkle(int veri);
void dugumSil();

int main() {
    int secim, veri, sira;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Listeyi goruntule\n");
        printf("2. Basa eleman ekle\n");
        printf("3. Araya eleman ekle\n");
        printf("4. Sona eleman ekle\n");
        printf("5. Eleman sil\n");
        printf("6. Cikis yap\n");
        printf("Secim yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                yazdir();
                break;
            case 2:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                basaEkle(veri);
                break;
            case 3:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                printf("Hangi indekse ekleme yapilsin: ");
                scanf("%d", &sira);
                arayaEkle(veri, sira);
                break;
            case 4:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                sonaEkle(veri);
                break;
            case 5:
                dugumSil();
                break;
            case 6:
                printf("Cikis yapiliyor.\n");
                exit(0);
            default:
                printf("Gecersiz secim yapildi.\n");
                break;
        }
    }

    return 0;
}

void yazdir() {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void basaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->next = head;
    head = yeni;
    printf("%d degeri listenin basina eklendi.\n", veri);
}

void arayaEkle(int veri, int sira) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->next = NULL;

    if (sira == 0) {
        basaEkle(veri);
        free(yeni); // basaEkle zaten malloc yapıyor
        return;
    }

    Node* temp = head;
    for (int i = 0; i < sira - 1; i++) {
        if (temp == NULL) {
            printf("Girilen indeks, liste boyutundan buyuktur! Ekleme yapilamadi.\n");
            free(yeni);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Girilen indeks, liste boyutundan buyuktur! Ekleme yapilamadi.\n");
        free(yeni);
        return;
    }

    yeni->next = temp->next;
    temp->next = yeni;
    printf("%d. indekse %d degeri eklendi.\n", sira, veri);
}

void sonaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->next = NULL;

    if (head == NULL) {
        head = yeni;
        printf("%d degeri listenin sonuna eklendi.\n", veri);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = yeni;
    printf("%d degeri listenin sonuna eklendi.\n", veri);
}

void dugumSil() {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    int girdi;
    printf("Sileceginiz elemani girin: ");
    scanf("%d", &girdi);

    
    if (head->data == girdi) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Eleman silindi.\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != girdi) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Eleman bulunamadi.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Eleman silindi.\n");
}
