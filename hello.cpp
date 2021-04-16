#include<stdio.h>

float getVolume(float d)
{
	float r = d/2;
	float ans = 4*(3.1416)*r*r*r;
	return ans/3;
}

int main()
{

float d;
scanf("%f",&d);
printf("%f\n",getVolume(d));


}