#ifndef kota_H
#define kota_H

#include "listorang.h"
#include "boolean.h"

#define Nil NULL
#define NamaKota(P) (P)->namakota
#define Head(P) (P)->head

typedef struct Kota {
	infotype namakota;
	Node *head;
} Kota;

void inisialisasiKota(Kota x[10]);

Kota* ambilKotaKosong(Kota x[10]);

void InsKota(Kota *x, infotype nama);

void DelKota(Kota *x);

void tampilkanKota(Kota x[10]);


#endif
