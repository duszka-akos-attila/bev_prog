#include<stdio.h>
#include<math.h>
#include <unistd.h>
#include <iostream>


int drawBall(int x,int y)
{
	int i;

	for(i=0;i<x;i++)
	printf("\n");

	for(i=0;i<y;i++)
	printf(" ");

	printf("O\n");

	return 0;
} 

int main()
{
	int x=0,y=0;
	int width,height;

	printf("Give in the height and the width of the field (in this order): \n");
	scanf("%d %d", &height, &width);
	while(1)
	{
		system("clear");
		drawBall(abs(height-(x++%(height*2))),abs(width-(y++%(width*2))));
		usleep(50000);
	}

	return 0;
} 
