#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
float total(int c,int q)
{
	int tc=0;
	if(q<=2)
	tc=c*q;
	else if(q<=7)
	tc=c*q*(0.85);
	else 
	tc=c*q*(0.7);
	return tc;
}
int main()
{
	int item_no,item_cost,quantity,i;
	time_t t;
	float total_cost=0;
	char name[20],item_name[20];
	FILE *fp;
	fp = fopen("bills.txt","a");
	printf("\n\n");
	printf("    Welcome to Mumbai Foodcourt\n");
	printf("\n\n");
	printf("    Enter customer name:");
	scanf("%s",name);
	time(&t);
	fputs(name,fp);   
    fputs("\n",fp);  
	menu:
	system("CLS");
	printf("\n\n");
	printf("    Food Items list:\n");
	printf("\n");
	printf("     ____________________________________________________ \n");
	printf("    |Item number   |Item name        |Item cost (in Rs.) |\n");
	printf("    |--------------|-----------------|-------------------|\n");
	printf("    |1             |Cake             |50                 |\n");
	printf("    |2             |Nachos           |100                |\n");
	printf("    |3             |Pizza            |150                |\n");
	printf("    |______________|_________________|___________________|\n");
	printf("\n");
	printf("    Enter the Item number you want:");
	scanf("%d",&item_no);
	switch (item_no)
	{
		case 1:
			{
			strcpy(item_name,"Cake");
			item_cost=50;
			break;
			}
		case 2:
			{
			strcpy(item_name,"Nachos");
			item_cost=100;	
			break;
			}
		case 3:
			{
			strcpy(item_name,"Pizza");
			item_cost=150;
			break;
			}
		default:
			{
			printf("Invalid choice");
			getch();
			goto menu;
			}
	}
	printf("\n\n");
	printf("    OUR DISCOUNTS:\n");
	printf("\n");
	printf("    .No discount on 2 or less than 2 items\n");
	printf("    .15 percent discount on 3 and more than 3, but less than 8 items\n");
	printf("    .30 percent discount for 8 and more than 8 items\n");
	printf("\n\n");
	printf("    How many %s you want:",item_name);
	scanf("%d",&quantity);
	total_cost=total_cost+total(item_cost,quantity);
	printf("\n");
	fputs(item_name,fp);   
    fputs(":\t",fp);
    fprintf(fp,"%d",item_cost);   
    fputs("\t*\t",fp);
    fprintf(fp,"%d",quantity);   
    fputs("\n",fp);
	printf("    Do you want to buy more items?\n");
	printf("    press 1 to buy more and any other key to exit:");
	scanf("%d",&i);
	switch (i)
	{
		case 1:
			{
			goto menu;
			break;
			}
		default:
			break;		
	}
	system("CLS");
	printf("\n\n");
	printf("    Your total cost is Rs.%f\n",total_cost);  
    fputs("Total cost:",fp);
    fprintf(fp,"%f",total_cost);   
    fputs("\n\n",fp);
	printf("\n\n");
	printf("    Thankyou for buying from Mumbai Food Court\n");
	getch();
	return 0;
}
