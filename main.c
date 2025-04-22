#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/kota.h"
#include "header/listorang.h"
#include "header/boolean.h"

int main() {

    Kota element[10];
    Kota *pilihkota;
    infotype nama, namalama;
    int pil, indexkota, pil2;
    int running = 1;
    address Prec;
    int jumlah;

    // pilihkota = &element[1];

    inisialisasiKota(element);

    while (running) {
        pilihkota = NULL;
        
        printf("Pilihlah Menu Berikut : \n");
        printf("1. Tambah Kota\n");
        printf("2. Input orang\n");
        printf("3. Hapus Kota\n");
        printf("4. Tampilkan Kota\n");
        printf("5. Keluar\n");
        printf("Pilih : ");
        scanf("%d", &pil);
        while (getchar() != '\n');

        printf("\n========================= \n");

        switch (pil)
        {
        case 1:
            pilihkota = ambilKotaKosong(element);
            if (pilihkota == NULL) {
                printf("Array Kota Penuh\n");
                break;
            }
            printf("Masukkan Nama Kota: ");
            scanf("%s", nama);
            
            InsKota(pilihkota, nama);

            printf("\n========================= \n");

            break;
        case 2:
            tampilkanKota(element);

            printf("Pilih kota (1-10) : ");
            scanf("%d", &indexkota);

            if (indexkota < 1 || indexkota > 10) {
                printf("Kota tidak valid\n");
                printf("\n========================= \n");
                break;
            }
            if (strcmp(element[indexkota - 1].namakota, "") == 0) {
                printf("Kota tidak ada\n");
                printf("\n========================= \n");
                break;
            }

            pilihkota = &element[indexkota - 1];
            
            int submenu = 1;
            while (submenu) {
                printf("\n========================= \n");
                printf("Pilihlah Menu Berikut : \n");
                printf("1. Tambah Orang Depan\n");
                printf("2. Tambah Orang Belakang\n");
                printf("3. Tambah Orang After\n");
                printf("4. Hapus Orang Depan\n");
                printf("5. Hapus Orang Belakang\n");
                printf("6. Hapus Orang P\n");
                printf("7. Hapus Semua Orang\n");
                printf("8. Tampilkan Orang\n");
                printf("9. Jumlah Orang\n");
                printf("10. Keluar\n");
                printf("Pilih : ");
                scanf("%d", &pil2);
                while (getchar() != '\n');

                printf("\n========================= \n");
        
                switch (pil2)
                {
                    case 1:
                        printf("Masukkan Nama: ");
                        scanf("%s", nama);

                        InsFirst(pilihkota, nama);

                        printf("\n========================= \n");

                        break;
                    case 2:
                        printf("Masukkan Nama: ");
                        scanf("%s", nama);

                        InsLast(pilihkota, nama);

                        printf("\n========================= \n");
            
                        break;
                    case 3:
                        PrintInfo(*pilihkota);
                        
                        if(ListEmpty(*pilihkota)) {
                            printf("List Kosong\n");
                            printf("========================= \n");
            
                            break;
                        }else {
                            printf("Masukan Setelah : ");
                            scanf("%s", &namalama);
                            Prec = Search(*pilihkota, namalama);

                            printf("Masukkan Nama: ");
                            scanf("%s", nama);

                            InsertAfter(nama, Prec);
                        }

                        printf("\n========================= \n");
            
                        break;
                    case 4:
                        DelFirst(pilihkota, &namalama);
                        printf("Data yang dihapus : %s\n", namalama);
                        printf("========================= \n");

                        break;
                    case 5:
                        DelLast(pilihkota, &namalama);
                        printf("Data yang dihapus : %s\n", namalama);
                        printf("========================= \n");

                        break;
                    case 6:
                        PrintInfo(*pilihkota);

                        if(ListEmpty(*pilihkota)) {
                            printf("List Kosong\n");
                            printf("========================= \n");
            
                            break;
                        } else {
                            printf("Masukan Nama : ");
                            scanf("%s", &namalama);
                            DelP(pilihkota, namalama);
                            
                            printf("========================= \n");
                        }

                        break;
                    case 7:
                        DelAll(pilihkota);
                        printf("Semua data berhasil dihapus\n");
                        printf("========================= \n");

                        break;
                    case 8:
                        PrintInfo(*pilihkota);
                        
                        break;
                    case 9:
                        jumlah = HitungOrang(*pilihkota);

                        printf("Jumlah orang : %d\n", jumlah);
                        printf("========================= \n");
            
                        break;
                    case 10:
                        submenu = 0;

                        break;
                }
            }

            break;
        case 3:
            tampilkanKota(element);

            printf("Pilih kota (1-10) : ");
            scanf("%d", &indexkota);

            if (indexkota < 1 || indexkota > 10) {
                printf("Kota tidak valid\n");
                printf("\n========================= \n");
                break;
            }
            if (strcmp(element[indexkota - 1].namakota, "") == 0) {
                printf("Kota tidak ada\n");
                printf("\n========================= \n");
                break;
            }

            pilihkota = &element[indexkota - 1];

            DelKota(pilihkota);

            printf("\n========================= \n");

            break;
        case 4:
            tampilkanKota(element);

            printf("\n========================= \n");

            break;
        case 5:
            running = 0;

            break;
        }
    }

    
    return 0;
}