#include "../header/kota.h"
#include "../header/listorang.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inisialisasiKota(Kota x[10])
{
    for (int i = 0; i < 10; i++) {
        strcpy(x[i].namakota, "");
        x[i].head = NULL;
    }
    
}

Kota* ambilKotaKosong(Kota x[10])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(x[i].namakota, "") == 0)
        {
            return &x[i];
        }
    }
    return NULL;
}

void InsKota(Kota *x, infotype nama)
{
    strcpy(NamaKota(x), nama);
    Head(x) = Nil;
}

void tampilkanKota(Kota x[10])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(x[i].namakota, "") == 0)
        {
            printf("Kota %d: Kosong\n", i + 1);
        }else
        {
            printf("Kota %d: %s\n", i + 1, x[i].namakota);
            PrintInfo(x[i]);
        }
    }
}

void DelKota(Kota *x) 
{
    DelAll(x);
    printf("Berhasil menghapus semua orang dikota\n");

    strcpy(NamaKota(x), "");
    Head(x) = NULL;
}