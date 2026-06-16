#include <stdio.h>
#include <string.h>

struct Kereta {
    char kode[10];
    char nama[50];
    char asal[30];
    char tujuan[30];
    char jam[10];
};

// Sequential Search berdasarkan tujuan
int sequentialSearch(struct Kereta data[], int n, char target[]) {
    int i;
	for (i = 0; i < n; i++) {
        if (strcmp(data[i].tujuan, target) == 0)
            return i;
    }
    return -1;
}

// Binary Search berdasarkan kode kereta (data terurut)
int binarySearch(struct Kereta data[], int n, char target[]) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int hasil = strcmp(data[mid].kode, target);

        if (hasil == 0)
            return mid;
        else if (hasil < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    struct Kereta data[8] = {
        {"KA001", "Argo Bromo Anggrek", "Surabaya",  "Jakarta",   "06:00"},
        {"KA002", "Argo Wilis",         "Surabaya",  "Bandung",   "07:30"},
        {"KA003", "Bima",               "Surabaya",  "Jakarta",   "17:00"},
        {"KA004", "Gajayana",           "Malang",    "Jakarta",   "16:30"},
        {"KA005", "Jayabaya",           "Surabaya",  "Jakarta",   "13:00"},
        {"KA006", "Kertajaya",          "Surabaya",  "Jakarta",   "09:00"},
        {"KA007", "Malioboro",          "Yogyakarta","Jakarta",   "08:00"},
        {"KA008", "Turangga",           "Surabaya",  "Bandung",   "19:00"}
    };

    int pilihan;
    char lagi;

    do {
        printf("\n=== Pencarian Jadwal Kereta Api ===\n");
        printf("1. Cari berdasarkan Kode  (Binary Search)\n");
        printf("2. Cari berdasarkan Tujuan (Sequential Search)\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            char kode[10];
            printf("Masukkan kode kereta: ");
            scanf("%s", kode);

            int hasil = binarySearch(data, 8, kode);

            if (hasil != -1) {
                printf("\nData Ditemukan!\n");
                printf("Kode    : %s\n", data[hasil].kode);
                printf("Nama    : %s\n", data[hasil].nama);
                printf("Asal    : %s\n", data[hasil].asal);
                printf("Tujuan  : %s\n", data[hasil].tujuan);
                printf("Jam     : %s\n", data[hasil].jam);
            } else {
                printf("\nData tidak ditemukan!\n");
            }

        } else if (pilihan == 2) {
            char tujuan[30];
            printf("Masukkan kota tujuan: ");
            scanf(" %[^\n]", tujuan);

            int hasil = sequentialSearch(data, 8, tujuan);

            if (hasil != -1) {
                printf("\nData Ditemukan!\n");
                printf("Kode    : %s\n", data[hasil].kode);
                printf("Nama    : %s\n", data[hasil].nama);
                printf("Asal    : %s\n", data[hasil].asal);
                printf("Tujuan  : %s\n", data[hasil].tujuan);
                printf("Jam     : %s\n", data[hasil].jam);
            } else {
                printf("\nData tidak ditemukan!\n");
            }

        } else if (pilihan != 0) {
            printf("Pilihan tidak valid!\n");
        }

        if (pilihan != 0) {
            printf("\nCari lagi? (y/n): ");
            scanf(" %c", &lagi);
        }

    } while (pilihan != 0 && lagi == 'y');

    printf("Terima kasih!\n");
    return 0;
}
