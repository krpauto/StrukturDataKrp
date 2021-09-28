#include<stdio.h>

int main()
{
	
//kartu tanda penduduk
	
	typedef struct{
		
	char nama[35];
	char tempatlahir[35];
	char jeniskelamin;
	float tinggi;
	}KartuTandaPenduduk;
	
	
	//kartu tanda mahasiswa
	
	typedef struct{
		
	int NIM;
	char Nama[25];
	float IPK;
	}KartuMahasiswa;
	
	KartuMahasiswa ktm[20];
	
	//fungsi sizeof
	
	printf("Ukuran tipe data ktp adalah		:%d\n",sizeof(KartuTandaPenduduk));
	printf("Ukuran tipe data ktm adalah		:%d\n",sizeof(KartuMahasiswa));
	
	return 0;
}
