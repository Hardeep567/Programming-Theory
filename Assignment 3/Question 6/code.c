#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct weatherforecast{
	int temperature;
	int rainfall;
	int wind_patterns;
}forecast;

typedef struct crops{
	char crop_type[40];
	char growth_stage[45];
	int expected_yeild;
	forecast * forecast;
} crop;

typedef struct equipment{
	char operational_status[40];
	int fuel_levels; 
	char activity_schedules[40];
} equipment;

typedef struct senior{
	int nutrients;
	int pH_levels;
	int pest_activity;
} senior;

typedef struct fields{
	int GPS_coordinates;
	int soil_health_metrics;
	int moisture_levels;
	equipment * equipments;
	crop * crops;
	senior * seniors;
	int numofequipments;
	int numofcrops;
	int numofsenior;
} field;

typedef struct regional_hubs{
	int yield_predictions;
	char resource[40];
	char distribution[40];
	char emergency_response_plans[100];
	field * fields;
} regional_hub;

typedef struct analytics_server{
	regional_hub*hubs;
	int numofhubs;
} analytics_server;

void addcrops(crop * crop, int numofcrops){
	for (int i = 0; i < numofcrops; i++) {
	printf("Enter the type of crop");
	scanf("%s", crop[i].crop_type);
	printf("Enter the growth stage");
	scanf(" %s", crop[i].growth_stage);
	printf("Enter the type expected yield");
	scanf("%d", &crop[i].expected_yeild);
    crop[i].forecast = (forecast *)malloc(sizeof(forecast));
    printf("Enter the temperature");
	scanf("%d", &crop[i].forecast->temperature);
	printf("Enter the Rainfall");
	scanf("%d", &crop[i].forecast->rainfall);
	printf("Enter the Wind Pattern");
	scanf("%d", &crop[i].forecast->wind_patterns);
	}
	return ;	
}

void addequipment(equipment * equipment, int numofequipment){
	for(int i=0;i<numofequipment;i++){
	printf("Enter the operational status");
	scanf("%s", equipment[i].operational_status);
	printf("Enter the fuel level");
	scanf("%d", &equipment[i].fuel_levels);
	printf("Enter the activity schedules");
	scanf("%s", equipment[i].activity_schedules);
	}
	return ;
}

void addsenior(senior * seniors,int numofsenior){
	for(int i=0;i<numofsenior;i++){
	printf("Enter the Nutrients");
	scanf("%d", &seniors[i].nutrients);
	printf("Enter the PH Level");
	scanf("%d", &seniors[i].pH_levels);
	printf("Enter the Pest activity");
	scanf("%d", &seniors[i].pest_activity);
	}
	return ;
}

void displayfield(field  fe){
	printf("\n\n\nGPS coordinates %d\n", fe.GPS_coordinates);
	printf("soil health metrics %d\n", fe.soil_health_metrics);
	printf("moisture levels %d\n",fe.moisture_levels);
	for (int i = 0; i < fe.numofcrops; i++) {
	printf("Type of crop %s\n", fe.crops[i].crop_type);
	printf("Growth stage %s\n", fe.crops[i].growth_stage);
	printf("Type expected yield %d\n", fe.crops[i].expected_yeild);
    printf("Temperature %d\n", fe.crops[i].forecast->temperature);
	printf("Rainfall %d\n", fe.crops[i].forecast->rainfall);
	printf("Wind Pattern %d\n", fe.crops[i].forecast->wind_patterns);
	}
	
	for(int i=0;i< fe.numofequipments;i++){
	printf("Operational status %s\n", fe.equipments[i].operational_status);
	printf("Fuel level %d\n", fe.equipments[i].fuel_levels);
	printf("Activity schedules %s\n", fe.equipments[i].activity_schedules );
	}
	
	for(int i=0;i< fe.numofsenior;i++){
	printf(" Nutrients %d\n", fe.seniors[i].nutrients);
	printf(" PH Level %d\n", fe.seniors[i].pH_levels);
	printf("Pest activity %d\n", fe.seniors[i].pest_activity);
	}
	
	return ;
}

int main(){
	field fe;
	printf("Enter the GPS coordinates");
	scanf("%d", &fe.GPS_coordinates);
	printf("Enter the soil health metrics");
	scanf("%d", &fe.soil_health_metrics);
	printf("Enter the moisture levels");
	scanf("%d", &fe.moisture_levels);
	printf("Enter the number of crops");
	scanf("%d", &fe.numofcrops);
	
	fe.crops=(crop *)malloc(sizeof(crop ) * fe.numofcrops);
	addcrops(fe.crops,fe.numofcrops);
	
	printf("Enter the number of  equipment");
	scanf("%d", &fe.numofequipments);
	fe.equipments = (equipment *)malloc(sizeof(equipment) * fe.numofequipments);
	addequipment(fe.equipments, fe.numofequipments);
	
	printf("Enter the number of Num of senior");
	scanf("%d", &fe.numofsenior);
	fe.seniors=(senior *)malloc(sizeof(senior) * fe.numofsenior);
	addsenior(fe.seniors,fe.numofsenior);
	
	displayfield(fe);
	for (int i = 0; i < fe.numofcrops; i++) {
        free(fe.crops[i].forecast);
    }
    free(fe.crops);
    free(fe.equipments);
    free(fe.seniors);
	return 0;
}
