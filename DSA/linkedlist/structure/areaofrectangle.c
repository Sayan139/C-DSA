#include <stdio.h>
struct point{
    float x;
    float y;
};
struct rectangle {
    struct point upper_left;
    struct point lower_right;
};
float area(struct rectangle r){
    int length,breadth;
    if (r.lower_right.x > r.upper_left.x) {
        length = r.lower_right.x - r.upper_left.x;
    } else {
        length = r.upper_left.x - r.lower_right.x;
    }
    if (r.upper_left.y > r.lower_right.y) {
        breadth = r.upper_left.y - r.lower_right.y;
    } else {
        breadth = r.lower_right.y - r.upper_left.y;
    }
    return length*breadth;
}
int main(){
    struct rectangle r;
    printf("enter the value of the upper left part : ");
    scanf("%f %f",&r.upper_left.x,&r.upper_left.y);
    printf("enter the value of the  lower right part : ");
    scanf("%f %f",&r.lower_right.x,&r.lower_right.y);
    printf("The area of the rectangle is : %f\n",area(r));
}