#include <stdio.h>
#include <string.h>
struct car{
    char engine[30];
    int fuel_tank_capacity;
    int seating_capacity;
    float car_milage;
}car1,car2;
int main(){
    strcpy(car1.engine,"v12");
    strcpy(car2.engine,"v6");
    printf("engine of the car 1 : %s\n",car1.engine);
    printf("engine of the car 2 : %s\n",car2.engine);
}