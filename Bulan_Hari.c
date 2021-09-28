#include<stdio.h>

int main (){
	
printf("NAMA  : KEVIN RIVALDO PANGGABEAN\n");
printf("NIM   : 3312001030\n");
printf("KELAS : IF 2A PAGI\n");
printf("===================================================================\n");
printf("========PROGRAM UNTUK MENAMPILKAN JUMLAH HARI DALAM 1 BULAN========\n");
printf("-------------------------------------------------------------------\n");	
int jum_hari[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

char nama_bulan[12][10]= {"Januari","Februari","Maret","April"
,"Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"};

int input_angka;
printf("Masukan Bulan keberapa(angka) : "); 
scanf("%i",&input_angka);

printf("\n\n>>> Pada Bulan %s Jumlah Hari = %i Hari <<<", nama_bulan[input_angka- 1],jum_hari[input_angka-1]);

}

