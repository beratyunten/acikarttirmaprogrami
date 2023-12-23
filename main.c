#include <stdio.h>
#include <stdlib.h>

// Bid struct'i tanimliyoruz
typedef struct {
    int teklifveren_no;
    double teklif;
} Bid;

// Arttirma struct'ini tanimliyoruz
typedef struct {
    Bid *teklifler; // Teklif dizisi
    int teklifveren_sayisi; // Teklif veren sayisini tanimladik
} Arttirma;

// Fonksiyon prototiplerimiz
double odemeyi_hesapla(Arttirma a, int kazanan_no);
void acikarttirma(Arttirma a);

int main() {
    // Kullanicidan teklif veren kisi sayisini alacak
    printf("Teklif Veren Sayisini Giriniz: ");
    int teklifveren_sayisi;
    scanf("%d", &teklifveren_sayisi);

    // Arttirma yapisinin olusturulmasi
    Arttirma arttirma;
    arttirma.teklifveren_sayisi = teklifveren_sayisi;
    arttirma.teklifler = (Bid *)malloc(arttirma.teklifveren_sayisi * sizeof(Bid));

    // Kullanicidan teklifleri al
    for (int i = 0; i < arttirma.teklifveren_sayisi; i++) {
        printf("Teklif Veren #%d:\n", i + 1);
        arttirma.teklifler[i].teklifveren_no = i + 1;

        printf("Teklif Miktarini Giriniz: ");
        scanf("%lf", &arttirma.teklifler[i].teklif);
    }

    // Acik arttirmanin gerçeklestirilmesi
    acikarttirma(arttirma);

    // Bellekten ayrilmasi
    free(arttirma.teklifler);

    return 0;
}

// Odemeyi hesapla fonksiyonu
double odemeyi_hesapla(Arttirma a, int kazanan_no) {
    double odeme = 0.0;

    for (int i = 0; i < a.teklifveren_sayisi; i++) {
        if (i != kazanan_no) {
            odeme += a.teklifler[i].teklif;
        }
    }

    return odeme;
}

// Acik arttirma fonksiyonu
void acikarttirma(Arttirma a) {
    double enyuksek_teklif = -1.0;
    int kazanan_no = -1;

    for (int i = 0; i < a.teklifveren_sayisi; i++) {
        // Kazanan teklif sahibini belirle
        if (a.teklifler[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = i;
        }
    }

    // Kazanan teklif sahibini ve ödemeyi göster
    printf("Kazanan Teklif Sahibi: %d\n", a.teklifler[kazanan_no].teklifveren_no);
    printf("Odeme: %.2f\n", enyuksek_teklif);
}

