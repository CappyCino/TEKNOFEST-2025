#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793



struct values{
	
	double pressure;
	double temperature;
	double area_ratio;
	double yogunluk;
	double speed;
	double mach;
	double alan;
	double kutlesel_debi;
	double force;
	double radius;
	double yakinsak_uzunluk;
	double iraksak_uzunluk;
}bogaz,cikis;

struct constant{
	
double	pressure;
double 	temperature;
double 	k;
double	sabit_oran;
double yogunluk;
double mach;
double alan;
double kutlesel_debi;
double force;
double speed;
double radius;
double iraksak_uzunluk;
double yakinsak_uzunluk;
	double kutlesel_debi_deneme;
}giris;

double T_constant = 0.8333; //T sab
double alan_orani;
double kuvvet;
double ses_hizi;
double alpha;
double beta;
int devam = 1;
double counter=0;
int sayac=0;


double eq_1;
double eq_2;
double eq_3;

int main(void){
	
	
	printf("Giris basinci = ");
	scanf("%lf",&giris.pressure);
	printf("Giris Sicakligi = ");
	scanf("%lf",&giris.temperature);
	giris.k = 1.4;
	giris.sabit_oran = 0.287;
	
	bogaz.temperature = 0.8333 * giris.temperature; //
	printf("Bogaz sicakligi = %lf\n",bogaz.temperature);
	bogaz.pressure = 0.5283 * giris.pressure; ////
	printf("Bogaz basinci = %lf\n",bogaz.pressure);
	
	giris.yogunluk = giris.pressure/ (giris.sabit_oran * giris.temperature);
	printf("Giris yogunlugu = %lf\n",giris.yogunluk);
	bogaz.yogunluk = 0.6339 * giris.yogunluk; ////
	printf("Bogaz yogunlugunu = %lf\n",bogaz.yogunluk);
	bogaz.speed = sqrt(giris.k*bogaz.temperature*giris.sabit_oran*1000); ////
	printf("Bogaz hizi = %lf\n",bogaz.speed);
	printf("Cikis basinci giriniz = ");
	scanf("%lf",&cikis.pressure);
	cikis.mach=sqrt(pow(cikis.pressure/giris.pressure,(giris.k-1/-(giris.k)-1))/(giris.k-1/2));  ////
	printf("Cikis mach = %lf\n",cikis.mach);
	cikis.temperature = giris.temperature * pow(((1+((giris.k-1)/2))*pow(cikis.mach,2)),-1); ////
	printf("Cikis sicaklik = %lf\n",cikis.temperature);
	cikis.yogunluk = (cikis.temperature/giris.sabit_oran) * cikis.temperature; ////
	printf("Cikis yogunluk = %lf\n",cikis.yogunluk);
	cikis.speed = (cikis.mach)*sqrt(giris.k*giris.sabit_oran*cikis.temperature*1000); ////
	printf("Cikis Hiz = %lf\n",cikis.speed);
	alan_orani = 1/cikis.mach*pow(((2/(giris.k+1)*((1+giris.k-1/2)*pow(cikis.mach,2)))),((giris.k+1)/2*(giris.k-1)));
	printf("Alan orani = %lf\n",alan_orani);
	printf("Bogaz capi = ");
	scanf("%lf",&bogaz.radius);

    
    cikis.radius = sqrt(alan_orani*pow(bogaz.radius,2));
    printf("Cikisin capi = %lf\n",cikis.radius);
    bogaz.alan = (PI*pow(bogaz.radius,2))/4;
    printf("Bogaz alani = %lf\n",bogaz.alan);
	cikis.alan = bogaz.alan * alan_orani;
    printf("Cikis alani = %lf\n",cikis.alan);
	ses_hizi = sqrt(giris.k*giris.sabit_oran*giris.temperature*1000);  //giris sabit oran  ve giris temperature 
	printf("Ses hizi = %lf\n",ses_hizi);
	bogaz.kutlesel_debi = bogaz.yogunluk * bogaz.alan * bogaz.speed;
	printf("Bogaz kutlesel debi = %lf\n",bogaz.kutlesel_debi);
	cikis.kutlesel_debi = cikis.yogunluk * cikis.alan * cikis.speed;
	printf("Cikis kutlesel debi = %lf\n",cikis.kutlesel_debi);
    kuvvet = (bogaz.kutlesel_debi * cikis.speed) + ((100000 - 101325) * cikis.alan);
    printf("Kuvvet = %lf\n",kuvvet);
    // Sıcaklık 
	
	
    do{
    	
    	printf("Mach degeri =");
    	scanf("%lf",&giris.mach);
    	giris.speed = giris.mach*ses_hizi;
    	printf("Giris hizi = %lf , giris mach = %lf \n",giris.speed,giris.mach);
    	printf("Mach degeri tekrar girmek icin 1 Mach degeri girmeden devam etmek icin 9 = ");
    	scanf("%d",&sayac);
    	
	}while(sayac != 9);
	

}