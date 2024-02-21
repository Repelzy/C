#include <stdio.h> 
#include <math.h>
int main()
{
    float area1,a,b,c,d, area2, h;
    
    printf("Enter 4 sides: ");
    scanf("%f%f%f%f",&a,&b,&c,&d);

    if (a<d){
        float p = (b+c+(d-a))/2;
        area2 = sqrt((p*(p-(d-a))*(p-b)*(p-c)));
        h = area2 * 2 / (d-a);
        printf("The area is: %f\n", area1= ((a+d)* h)/2);
    }
    else {
        float p1 = (b+c+(a-d))/2;
        area2 = sqrt(p1*(p1-(a-d))*(p1-b)*(p1-c));
         h = area2 * 2 / (a-d);
        printf("The area is: %f\n", area1= ((a+d)* h)/2);
    }
    
    return 0; 
}
