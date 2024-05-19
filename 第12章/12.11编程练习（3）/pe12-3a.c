#include<stdio.h>
 
void get_info(int);
void show_info(int,int,double);

void get_info(int pattern)
	{
	int distance;
	double fuel_consumed;
	if(pattern==0)
		{
		printf("Enter distance traveled in kilometers: ");
		scanf("%d",&distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf",&fuel_consumed);
		}
	else
		{
		if(pattern!=1)
			printf("Invalid mode specified. Mode 1 (US) used.\n");

			printf("Enter distance traveled in miles: ");
			scanf("%d",&distance);
			printf("Enter fuel consumed in gallons: ");
			scanf("%lf",&fuel_consumed);
		}
	show_info(pattern,distance,fuel_consumed);
	return;
	}
void show_info(int pattern,int distance,double fuel_consumed)
	{
	if(pattern==0)
		printf("Fuel consumption is %0.2f liters per 100 km.\n",fuel_consumed/distance*100);
	else
		printf("Fuel consumption is %0.1f miles per gallons.\n",distance/fuel_consumed);
	return;
	}
