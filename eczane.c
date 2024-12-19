#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Reçete kodlarını tanımlayan enum
enum recetekod {
    M10A2315,    // Antibiyotikler
    RXAB12345,   // Antidepresanlar
    RXBR56789,   // İltihap gidericiler
    RX20241101   // Ağrı kesiciler
};

int main() {
    setlocale(LC_ALL, "Turkish");
    char receteyaz;
    char sifre[] = "Veysel1234";  
    char girilenSifre[100];  
    char name[] = "Veysel";
    char gerekliname[50];

    printf("ECZANE OTOMASYONUNA HOS GELDINIZ\n");

    // Kullanıcı adı doğrulama
    while (1) {  
        printf("Adinizi girin: ");
        scanf("%s", gerekliname);

        if (strcmp(gerekliname, name) != 0) {
            printf("Yanlis kullanici, tekrar deneyiniz.\n");
        } else {
            printf("Devam Edin\n");
            break;  
        }
    }

    // Şifre doğrulama
    while (1) {  
        printf("Sifrenizi giriniz: ");
        scanf("%s", girilenSifre);

        if (strcmp(girilenSifre, sifre) != 0) {
            printf("Sifreniz yanlis, tekrar deneyiniz.\n");
        } else {
            printf("Sifreniz doğru\n");
            break;  
        }
    }

    printf("Giris basarili, programa devam ediliyor...\n");

    while (1) {
        // Reçete kodu girme
        printf("Recep kodunuzu giriniz (R - Ağrı Kesici, M - Antibiyotik, A - Antidepresan, B - İltihap Giderici): ");
        while (getchar() != '\n');  // buffer temizleme
        receteyaz = getchar();  

        enum recetekod recete;

        // Reçete koduna göre enum değerini atama
        switch (receteyaz) {
            case 'R':
                recete = RX20241101;
                break;
            case 'M':
                recete = M10A2315;
                break;
            case 'A':
                recete = RXAB12345;
                break;
            case 'B':
                recete = RXBR56789;
                break;
            default:
                recete = -1;  // Geçersiz seçim
        }

        // Reçete koduna göre ilaçları listeleme
        switch (recete) {
            case RX20241101:
                printf("Agri Kesiciler: Paracetamol, Ibuprofen\n");
                printf("Antiinflamatuar ilaçlar: Diklofenak\n");
                break;
            case M10A2315:
                printf("Antibiyotikler: Amoksisilin, Sefaleksin\n");
                break;
            case RXAB12345:
                printf("Antidepresanlar: Sertralin, Fluoksetin\n");
                break;
            case RXBR56789:
                printf("Iltihap Giderici: Prednizon, Metilprednizolon\n");
                break;
            default:
                printf("Bilinmeyen reçete kodu.\n");
                break;
        }

        // Kullanıcıya tekrar reçete girme sorusu
        char devamEt;
        printf("\nBaşka bir reçete girmek ister misiniz? (E/H): ");
        while (getchar() != '\n');  // buffer temizleme
        devamEt = getchar();

        if (devamEt != 'E' && devamEt != 'e') {
            printf("Programdan çikiliyor...\n");
            break;  // Programdan çıkma
        }
    }

    return 0;
}
