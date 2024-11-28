#include <stdio.h>
#include <string.h>
struct car{
    char name[20];
    int engine;
};
int main(){
    struct car c1;
    strcpy(c1.name,"ferrari");
    c1.engine = 1200;
    printf("Name of the car: %s\n",c1.name);
    printf("horse power of the engine: %d\n",c1.engine);
}