#include <stdio.h>
#include <math.h>

//variables

struct constant_values{
	
double g;
double m;
double area;
double time_difference;
};

struct tools_values{
	
 int flag;
 int menu;
 int counter_hundred;
 int counter;
 int degisiklik;
 int devam;
};

struct previous_values{
	
double previous_speed;
double previous_height;
double previous_acceleration;
double previous_time;

};

struct current_values{
	
double current_time;
double current_speed;
double current_height;
double current_acceleration;
};

struct f_values{
	
double F_d;
double F_thrust;
double F_net;
};

double F_g;
int checkpoint_step;
double checkpoint_time;

int adimsayar = 0; //Counter

//Main function
int main(void){
	
	//structures
	struct tools_values tools = {0,0,0,0,0,0};
	struct constant_values constant = {9.81,20,1,0.1};  //5. değer time_difference
	struct previous_values previous[100] = {0,9,9.81,0};
	struct current_values current[100] = {0,0,0,0};
	struct f_values force[100] = {0,0,0};
	
    F_g = constant.m*constant.g;
    
    do{	
    	//T = 0
    	if(tools.counter == 0){
    		
    		current[adimsayar].current_speed = previous[adimsayar].previous_speed + (previous[adimsayar].previous_acceleration*0);
            current[adimsayar].current_height = (previous[adimsayar].previous_height - (previous[adimsayar].previous_speed*0)) - ((0.5)*(previous[adimsayar].previous_acceleration*(pow(0,2))));
		}
		// İlk adımdan sonrakiler
    	
    	else{
    	current[adimsayar].current_speed = previous[adimsayar].previous_speed + (previous[adimsayar].previous_acceleration*constant.time_difference);
        current[adimsayar].current_height = (previous[adimsayar].previous_height - (previous[adimsayar].previous_speed*constant.time_difference)) - ((0.5)*(previous[adimsayar].previous_acceleration*(pow(constant.time_difference,2))));
		}
		
		force[adimsayar].F_d = 0.5*1.225*0.75*constant.area*pow(current[adimsayar].current_speed,2);
		force[adimsayar].F_net = F_g - force[adimsayar].F_thrust - force[adimsayar].F_d;
		current[adimsayar].current_acceleration = force[adimsayar].F_net/constant.m;
		
		 //Display
	    printf("---------------------------------------------The values are---------------------------------------------\n");
	    printf("Current Time = %.2lf\n",current[adimsayar].current_time);
	    printf("Current Acceleration = %lf\n",current[adimsayar].current_acceleration);
		printf("Current Speed = %lf\n",current[adimsayar].current_speed);
	    printf("Current Height = %lf\n",current[adimsayar].current_height);
	    printf("F_d = %lf\n",force[adimsayar].F_d);
	    printf("F_g = %lf\n",F_g);
	    printf("F_net = %lf\n",force[adimsayar].F_net);
	    printf("F_Thrust = %lf\n",force[adimsayar].F_thrust);
	    printf("--------------------------------------------------------------------------------------------------------\n");
	    printf(" F_thrust degeri girmek icin 1\n Eski t suresine gitmek icin 2\n Programi kapatmak icin 9\n Hic bir sey yapmamak icin 0 \n Ne yapmak istersin =  ");
	    scanf("%d",&tools.menu);
	    
	    //Menu 1
	    if(tools.menu == 1){
	    	printf("F_thrust = ");
	    	scanf("%lf",&force[adimsayar+1].F_thrust);
		}
		
		//Menu 2 
		else if(tools.menu == 2)
		{
			printf("Hangi sureye gitmek istersin = ");
			scanf("%lf",&checkpoint_time);
			
			checkpoint_step = (checkpoint_time / constant.time_difference);
			
		printf("---------------------------------------------The values are---------------------------------------------\n");
	    printf("Current Time = %.2lf\n",current[checkpoint_step].current_time);
	    printf("Current Acceleration = %lf\n",current[checkpoint_step].current_acceleration);
		printf("Current Speed = %lf\n",current[checkpoint_step].current_speed);
	    printf("Current Height = %lf\n",current[checkpoint_step].current_height);
	    printf("F_d = %lf\n",force[checkpoint_step].F_d);
	    printf("F_g = %lf\n",F_g);
	    printf("F_net = %lf\n",force[checkpoint_step].F_net);
	    printf("F_Thrust = %lf\n",force[checkpoint_step].F_thrust);
	    printf("--------------------------------------------------------------------------------------------------------\n");
	    
	    printf("T = %.2lf suresinden mi devam etmek icin 1, T = %.2lf icin 2'yi tuslayabilirsin",checkpoint_time,current[adimsayar].current_time);
	    scanf("%d",&tools.devam);
	    
		//Checkpoint_time dan devam et
	    if(tools.devam == 1)
	    {
	    	adimsayar = checkpoint_step;
		} }
		
		// Anlık zamanımız bir sonraki döngü için zaman farkı kadar artıyor
		current[adimsayar+1].current_time = current[adimsayar].current_time + constant.time_difference;
			//Şuanki yüksekliğimiz bir sonraki adımımızın önceki yüksekliği oluyor
		previous[adimsayar+1].previous_height = current[adimsayar].current_height;
			//Şuanki ivmemiz bir sonraki adımımızın önceki ivmemiz oluyor
		previous[adimsayar+1].previous_acceleration = current[adimsayar].current_acceleration;
			//Şuanki hızımız bir sonraki adımımızın önceki hızımız oluyor
		previous[adimsayar+1].previous_speed = current[adimsayar].current_speed;
	    tools.counter++;
	    adimsayar++;
	    
	    printf("========================================================================================================\n\n\n");
	}while(tools.menu != 9);
	
	return 0;
}

