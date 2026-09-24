
#include <stdio.h>
#include <stdbool.h>

#define park_kapasitesi 4
#define gecici_kapasite 4

typedef struct {
    int arac_id[park_kapasitesi];
    int tepe;

    
}ParkAlani;


typedef struct {
    int arac_id[gecici_kapasite];
    int on;  
    int arka; 
} GeciciAlan;

ParkAlani parklar [4];
GeciciAlan geciciAlan;

void print_status();
void leave(int alan_no, int sira);

int main(){
    for(int i=0; i<4; i++){
        parklar[i].tepe = -1;
    }
    geciciAlan.on = 0;
    geciciAlan.arka = 0;
    
    //Park alanına araç ekleme 
    parklar[0].tepe++;
    parklar[0].arac_id[parklar[0].tepe]= 101;

    parklar[0].tepe++;
    parklar[0].arac_id[parklar[0].tepe]= 102;

    parklar[0].tepe++;
    parklar[0].arac_id[parklar[0].tepe]= 103;

    parklar[0].tepe++;
    parklar[0].arac_id[parklar[0].tepe]= 104;

    parklar[1].tepe++;
    parklar[1].arac_id[parklar[1].tepe]= 201;

    parklar[1].tepe++;
    parklar[1].arac_id[parklar[1].tepe]= 202;

    parklar[1].tepe++;
    parklar[1].arac_id[parklar[1].tepe]= 203;

    parklar[1].tepe++;
    parklar[1].arac_id[parklar[1].tepe]= 204;

    parklar[2].tepe++;
    parklar[2].arac_id[parklar[2].tepe]= 301;

    parklar[2].tepe++;
    parklar[2].arac_id[parklar[2].tepe]= 302;

    parklar[2].tepe++;
    parklar[2].arac_id[parklar[2].tepe]= 303;


    parklar[3].tepe++;
    parklar[3].arac_id[parklar[3].tepe]= 401;

    parklar[3].tepe++;
    parklar[3].arac_id[parklar[3].tepe]= 402;

    parklar[3].tepe++;
    parklar[3].arac_id[parklar[3].tepe]= 403;

    parklar[3].tepe++;
    parklar[3].arac_id[parklar[3].tepe]= 404;

    //ilk durumu gösterme
    printf("--------İlk durum:------------\n");

    print_status();

    //Ayrılma durumu

    printf("----- 1. park alanından ilk giren araça ayrılıyor-----\n");
    leave(0,0);


    printf("------ son durum ------\n");
    print_status();




}
void print_status(){

    for(int i=0; i<4; i++){
        printf("Park yeri %d durum\n",i);
        for (int j = 0; j <= parklar[i].tepe; j++)
        {
            printf("Plakalar: %d\n",parklar[i].arac_id[j]);
        }
    printf("\n");
    }
    printf("Gecici alan durumu:\n");
    for (int k = geciciAlan.on; k < geciciAlan.arka; k++)
    {
        printf("%d ",geciciAlan.arac_id[k]);
    }
    printf("\n");
    


}

void leave(int alan_no, int sira){
    int hedef_arac = parklar[alan_no].arac_id[sira]; 
    
    printf("%d numarali park yerinden, %d plakali arac cikiyor\n", alan_no, hedef_arac);

    while (parklar[alan_no].tepe>sira)
    {
        int cikanArac= parklar[alan_no].arac_id[parklar[alan_no].tepe];
        parklar[alan_no].tepe--;

        int i;

        for ( i = 0; i < 4; i++)
        {
            if (i != alan_no && parklar[i].tepe < 3)
            {
        
                parklar[i].tepe++;
                parklar[i].arac_id[parklar[i].tepe] = cikanArac;
                break;

            }
            
        }
        if (i == 4) {
            geciciAlan.arac_id[geciciAlan.arka] = cikanArac;
            geciciAlan.arka++;
            printf("-> %d plakali engelleyen arac, Gecici Alana tasindi.\n", cikanArac);
        }

    }
    parklar[alan_no].tepe--;
    printf("%d PLAKALI HEDEF ARAC OTOPARKTAN AYRILDI!\n", hedef_arac);

    while (geciciAlan.on<geciciAlan.arka)
    {
        int bekleyenArac= geciciAlan.arac_id[geciciAlan.on];
        int j;

        for ( j = 0; j <4 ; j++)
        {
            if (parklar[j].tepe<3)
            {
            parklar[j].tepe++;
            parklar[j].arac_id[parklar[j].tepe]= bekleyenArac;
            geciciAlan.on++;
            printf("Gecici alandaki %d, %d numarali park yerine alindi.\n", bekleyenArac, j);
                break;
            }
            
        }
        if (j == 4) {
            break; 
        }
    }
    




}
