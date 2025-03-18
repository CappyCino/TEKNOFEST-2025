#include <stdio.h>
#include <math.h>


//variables
double g = 9.81; //Yerçekimi ivmesi 9.81
double m = 25;   //Kütle 25 kg
double area = 2.4726; // Alan 2.4726 m^2
double previous_speed= 0; //Önceki Hız program ilk başlatılırken yani t=0 süresinde hız = 0 ile başlar sonrasında fonksiyonlarımıza göre değişebilir
double time_difference = 0.0001; // Zaman farklarımız 0.25 
double current_time=0; // t=0 süresinden başladığımız için anlık zaman 0 dan başlar time_difference değeri kadar artar
double previous_height= 7.8; // previous_height değeri t=0 değerinde 9 metre yükseklikten başladığı için başlangıçta 9 metredir
double previous_acceleration = 9.81; // Önceki ivme değerimiz t=0 süresinde yerçekimi ivmesi kadar oldugu için 9.81 dir.


double F_d = 0; double F_thrust = 0;
double F_net,F_g;
double current_speed; 
double previous_time;  
double current_height;
double current_acceleration;
int counter;
int flag = 0;
int menu = 0;
int counter = 0;
int main(void)
{
	printf("Starting...\n");
	
	// 1.Fonksiyon (1 kere çalışır döngü dışındadır.)
	 F_g = m*g;
	 
	 
	 
	do //Döngü başlangıcı
	{
		
		if(counter == 0) //initialize
		{
			current_speed = (previous_speed + (previous_acceleration*0));
			counter++;
		}
		else{
		// 2.Fonksiyon (döngü içinde)
		current_speed = (previous_speed + (previous_acceleration*time_difference));
	}
	
	
	
	if(counter == 1)//initialize
	{
		current_height = (previous_height - (previous_speed * 0)) - ((0.5)* (previous_acceleration*(pow(0,2))));
		counter++;
	}
	else{
		//3. fonksiyon (döngü içinde)
		current_height = (previous_height - (previous_speed * time_difference)) - ((0.5)* (previous_acceleration*(pow(time_difference,2))));
	}
	
	
	
		//4. fonksiyon (döngü içinde)
	    F_d = 0.5 * 1.225 * 0.75 * area * pow(current_speed, 2);
	    
	    //5. fonksiyon (döngü içinde)
		F_net = F_g - F_thrust - F_d;
		
		//6. fonksiyon (döngü içinde)
        current_acceleration = F_net/m;
        
        
	    //Display
	    printf("---------------------------------------------The values are---------------------------------------------\n");
	    printf("Current Time = %.8lf\n",current_time);
	    printf("Current Acceleration = %lf\n",current_acceleration);
		printf("Current Speed = %.8lf\n",current_speed);
	    printf("Current Height = %.8lf\n",current_height);
	    printf("F_d = %lf\n",F_d);
	    printf("F_g = %lf\n",F_g);
	    printf("F_d = %lf\n",F_d);
	    printf("F_net = %lf\n",F_net);
	    printf("F_Thrust = %lf\n",F_thrust);
	    printf("--------------------------------------------------------------------------------------------------------\n");
	   printf("Change(1 or 0) = ");
	    scanf("%d",&flag);
	    if(flag == 1){
	    	printf("Enter the F_thrust = ");
	    	scanf("%lf",&F_thrust);
		}
		
		else if(flag == 0){
	    printf("Exit(1 or 0) = ");
	    scanf("%d",&menu);
		}
	    //Display finish
	  
	// Anlık zamanımız bir sonraki döngü için zaman farkı kadar artıyor
	current_time = current_time + time_difference;
	
	//Şuanki yüksekliğimiz bir sonraki adımımızın önceki yüksekliği oluyor
	previous_height = current_height;
	//Şuanki ivmemiz bir sonraki adımımızın önceki ivmemiz oluyor
	previous_acceleration = current_acceleration;
	//Şuanki hızımız bir sonraki adımımızın önceki hızımız oluyor
	previous_speed = current_speed;	
	
	
	
	
	printf("========================================================================================================\n\n\n");} while (menu != 1); //Döngü bitişi
		
		
		return 0;
 }