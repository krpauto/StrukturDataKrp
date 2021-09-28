/* data struktur ktm */

#include<stdio.h> 

int main ()
{
typedef struct{

int NIM;
char Nama[25]; 
float IPK;
}kartumahasiswa;

int i,jumlah; kartumahasiswa ktm[20];
printf("|| Data Kartu Tanda mahasiswa ||\n\n"); 
printf("Masukan jumlah Data : ");
scanf("%d", &jumlah);

for(i=0;i<jumlah;i++)
{
printf("Masukan Nama : "); 
scanf("%s",&ktm[i].Nama); 
printf("Masukan NIM : "); 
scanf("%i",&ktm[i].NIM); 
printf("Masukan IPK : "); 
scanf("%f", &ktm[i].IPK); 
printf("\n");
}
for(i=0;i<jumlah;i++)
{
printf("Data ke-%d\n", i+1); 
printf("Nama	: %s\n", ktm[i].Nama);
printf("NIM	: %d\n", ktm[i].NIM);
printf("IPK 	: %.2f\n",ktm[i].IPK);
puts("");
}

float max=ktm[0].IPK;
int nama_mahasiswa;
for(i=0;i<jumlah;i++){
	if(max<ktm[i].IPK){
		max = ktm[i].IPK;
		nama_mahasiswa=i;
	}
	
	printf("\nMahasiswa dengan IPK tertinggi adalah :\n");
	printf("Nama	:%s\n",ktm[nama_mahasiswa].Nama);
	printf("IPK		:%2.f",ktm[nama_mahasiswa].IPK);
	
	
}

return 0;
}


