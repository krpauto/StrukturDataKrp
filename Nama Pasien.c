#include <stdio.h>
#include <conio.h>

typedef struct
{
            int data[100];
            char data1[100][20];
            char data2[100][30];
            char data3[100][15];
            int depan;
            int belakang;
}Queue;
Queue antrian;
Queue no;
Queue nama;
Queue poli;

int pilihan, data, i, j;
char data1[20], data2[30], data3[15];

int isEmpty()
{
            if (antrian.belakang==-1)
                        return 1;
            else
                        return 0;
}

int isFull()
{
            if(antrian.belakang==100)
                        return 1;
            else
                        return 0;
}

void Enqueue(int data, char data1[20], char data2[30], char data3[15])
{
            if(isEmpty()==1)
            {
                        antrian.depan=antrian.belakang=0;
                        nama.depan=nama.belakang=0;
                        poli.depan=poli.belakang=0;
                        no.depan=no.belakang=0;
                        antrian.data[antrian.belakang]=data;
                        for(i=0;i<20;i++)
                        {nama.data1[nama.belakang][i]=data1[i];}
                        for(i=0;i<30;i++)
                        {poli.data2[poli.belakang][i]=data2[i];}
                        for(i=0;i<15;i++)
                        {no.data3[no.belakang][i]=data3[i];}
                        printf("data anda telah masuk. silahkan menunggu panggilan");
            }
            else if(isFull()==0)
            {
                        antrian.belakang++;
                        nama.belakang++;
                        poli.belakang++;
                        no.belakang++;
                        antrian.data[antrian.belakang]=data;
                        for(i=0;i<20;i++)
                        {nama.data1[nama.belakang][i]=data1[i];}
                        for(i=0;i<30;i++)
                        {poli.data2[poli.belakang][i]=data2[i];}
                        for(i=0;i<15;i++)
                        {no.data3[no.belakang][i]=data3[i];}
                        printf("data anda telah masuk. silahkan menunggu panggilan");
            }
}

int Dequeue()
{
            if(isEmpty()==0)
            {
            int i,e ;
            char a[20], b[30];
            e=antrian.data[antrian.depan];
            for(i=0;i<20;i++)
            {
                        a[i]=nama.data1[nama.depan][i];
            }
            for(i=0;i<30;i++)
            {
                        b[i]=poli.data2[poli.depan][i];
            }
            for(i=antrian.depan;i<antrian.belakang;i++)
            {
                        antrian.data[i]=antrian.data[i+1];
                        for(j=0;j<20;j++)
                        {nama.data1[i][j]=nama.data1[i+1][j];}
                        for(j=0;j<30;j++)
                        {poli.data2[i][j]=poli.data2[i+1][j];}
                        for(j=0;j<15;j++)
                        {no.data3[i][j]=no.data3[i+1][j];}
            }
            antrian.belakang--;
            nama.belakang--;
            poli.belakang--;
            no.belakang--;
            printf("antrian no %i dengan nama %s silahkan memasuki poli %s !", e, a, b);
            return e;
            return a[20];
            return b[30];
            }
            else
            {
                        printf("antrian kosong");
            }
}

void buat()
{
            antrian.depan=antrian.belakang=-1;
            nama.depan=nama.belakang=-1;
            poli.depan=poli.belakang=-1;
            no.depan=no.belakang=-1;
}

void main()
{
            int n;
            buat();
            n=1;
            do
            {
                        system("cls");
                        puts("PROGRAM ANTRIAN PASIEN");
                        puts("============================\n");
                        puts(" menu :");
                        puts("1. Tambah Pasien");
                        puts("2. Panggil Pasien");
                        puts("3. Tampil Daftar Antrian");
                        puts("4. Keluar");
                        printf("silahkan masukkan pilihan (1-4) : "); scanf("%i", &pilihan);
                        switch(pilihan)
                        {
                                    case 1 :
                                                printf("no antrian anda adalah %i\n", n);
                                                data=n;
                                                printf("masukkan no. rekam medis anda :"); scanf("%s",&data3);
                                                printf("masukkan nama lengkap anda(gunakan tanda (_) untuk spasi) :"); scanf("%s",&data1);
                                                printf("masukkan poli berobat anda (gunakan tanda (_) untuk spasi):"); scanf("%s",&data2);
                                                Enqueue(data, data1, data2, data3);
                                                n++;
                                    break;

                                    case 2 :
                                                Dequeue();
                                    break;

                                    case 3 :
                                                if(isEmpty()==1)
                                                {
                                                            printf("antrian kosong !");
                                                            break;
                                                }
                                                puts("no antrian           no.reka medis              nama lengkap              poli berobat");
                                                for(i=antrian.depan;i<=antrian.belakang;i++)
                                                {
                                                            printf("%i                    %s                   %s                   %s\n", antrian.data[i], no.data3[i], nama.data1[i], poli.data2[i]);
                                                }

                                    break;
                                    case 4 :
                                                printf("terimakasih atas partisipasinya !!!");
                                    break;
                                    default :
                                                puts("salah tuh pilihannya !!!");
                                    break;
                        }
                        getch();
            }while(pilihan!=4);

}
