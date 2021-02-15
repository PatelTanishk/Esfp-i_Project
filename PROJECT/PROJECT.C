/*
(Society Water Bill MS) Society Water management system takes following
input
1) House Number
2) Contact person
3) House Age
4) Contact Number
5) Registry Status
6) Basic Rental Amount
7) Tax charged
8) House Type(Bungalow/Duplex/Flat)
9) Number of flats
10) Date of payment
11) Maintenance Tax
Based on above inputs it will display the total bill along with following
condition
If the houses age is above 5 years in the society then tax charged
on basic rental is 5% of it.
If the house type is bungalow then 4% extra tax is added for
maintenance.
7% extra tax is added for maintenance for duplex house.
10% is charged if the number of flats at particular address
exceeds 5.
*/

//Header files
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct socity
{
	int HouseNo , HouseAge , Rent , HouseType , Noofflats;
	char Cperson[30] , ContactNo[11] , RegStat , DOP[9] ;
	float TaxCharged , MantTax , TotalBill , TaxAdder;
}S[10];

int i=0;

void dummy();
void input();
void display(int i);
void displayall();
void search();

void main()
{
	int choice;
	do{
		clrscr();
		printf("----MENU-----");
		printf("\n1.NEW ENTERY");
		printf("\n2.SEARCH ENTERY");
		printf("\n3.PRINT ALL ENTERY");
		printf("\n4.EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				input();
				break;
			case 2:
				clrscr();
				//printf("Hello");
				search();
				getch();
				//printf("SEARCH");
				break;
			case 3:
				clrscr();
				displayall();
				//printf("Display all");
				getch();
				break;
			default :
				choice=0;
		}
	}while(choice!=0);
}

void dummy(float *a)
{
	float b=*a;
	dummy(&b);
}

void input()
{
	float add=0;
	clrscr();
	printf("Enter the House Number               : ");
	printf("\nEnter the House Age                  : ");
	printf("\nEnter the House Rent                 : ");
	printf("\nEnter the Contact Person Name        : ");
	printf("\nEnter the Contact Number             : ");
	printf("\nEnter the Regesteration Status (Y/N) : ");
	printf("\nEnter the Date of Payment (DDMMYYYY) : ");
	printf("\nEnter the Tax Charged                : ");
	printf("\nEnetr the Mantenance Tax             : ");
	printf("\nEnter the House Type                 : ");
	printf("\n\t->Bunglow");
	printf("\n\t->Duplex");
	printf("\n\t->Flat");
	gotoxy(50,1);
	scanf("%d",&S[i].HouseNo);
	gotoxy(50,2);
	scanf("%d",&S[i].HouseAge);
	gotoxy(50,3);
	scanf("%d",&S[i].Rent);
	gotoxy(50,4);
	gets(S[i].Cperson);
	gets(S[i].Cperson);
	gotoxy(50,5);
	gets(S[i].ContactNo);
	gotoxy(50,6);
	scanf("%c",&S[i].RegStat);
	gotoxy(50,7);
	gets(S[i].DOP);
	gets(S[i].DOP);
	gotoxy(50,8);
	scanf("%f",&S[i].TaxCharged);
	gotoxy(50,9);
	scanf("%f",&S[i].MantTax);
	gotoxy(50,10);
	scanf("%d",&S[i].HouseType);
	S[i].Noofflats=0;
	if(S[i].HouseType==3)
	{
		gotoxy(1,14);
		printf("Enter number of flats                : ");
		gotoxy(50,14);
		scanf("%d",&S[i].Noofflats);
		//printf("\n%d",S[i].Noofflats);
		//getch();
	}
	if(S[i].HouseType==1)
	{
		//printf("\n%d",S[i].HouseType);
		add+=(4*S[i].MantTax)/100;
	}
	if(S[i].HouseType==2)
	{
		//printf("\n%d",S[i].HouseType);
		add+=(7*S[i].MantTax)/100;
	}
	if(S[i].HouseAge>=5)
	{
		//printf("\nHouse Age = %d",S[i].HouseAge);
		add+=(5*S[i].TaxCharged)/100;
	}
	if(S[i].Noofflats>=5)
	{
		add+=(5*S[i].Rent)/100;
		//printf("%f",add);
	}
	S[i].TotalBill=S[i].TaxCharged+S[i].MantTax+add;
	//printf("\nT=%f\nA=%f",S[i].TotalBill,add);
	S[i].TaxAdder=add;
	//S[i].Noofflats=flats;
	//printf("\nT=%f\nA=%f",S[i].TotalBill,S[i].TaxAdder);
	display(i);
	++i;
	getch();
}

void display(int j)
{
	char tl=218 , tr=191 , bl=192 , br=217 , hr=196 , vr=179 , RT=195 , LT=180 , TT=193 , BT=194 , P=197;
	int i;
	clrscr();
	gotoxy(3,7);
	printf("%c",tl);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<11 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<13 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<12 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",tr);
	gotoxy(3,8);
	//printf("%c",vr);
	printf("%c     HOUSE    %c     REGISTRY    %c   HOUSE   %c   CONTACT   %c    BASIC   %c",vr,vr,vr,vr,vr,vr);
	gotoxy(3,9);
	printf("%c    NUMBER    %c      STATUS     %c   TYPE    %c   NUMBER    %c    RENT    %c",vr,vr,vr,vr,vr,vr);
	gotoxy(3,10);
	printf("%c",RT);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<11 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<13 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<12 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",LT);
	gotoxy(3,11);
	printf("%c",vr);
	gotoxy(10,11);
	printf("%d",S[j].HouseNo);
	gotoxy(18,11);
	printf("%c",vr);
	gotoxy(28,11);
	printf("%c",S[j].RegStat);
	gotoxy(36,11);
	printf("%c",vr);
	gotoxy(42,11);
	printf("%d",S[j].HouseType);
	gotoxy(48,11);
	printf("%c",vr);
	gotoxy(50,11);
	printf("%s",S[j].ContactNo);
	gotoxy(62,11);
	printf("%c",vr);
	gotoxy(66,11);
	printf("%d",S[j].Rent);
	gotoxy(75,11);
	printf("%c",vr);
	gotoxy(3,12);
	printf("%c",RT);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<11 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<13 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<12 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",LT);
	gotoxy(3,13);
	printf("%c    NUMBER    %c   MAINTENANCE   %c    TAX    %c   DATE OF   %c    TOTAL   %c",vr,vr,vr,vr,vr,vr);
	gotoxy(3,14);
	printf("%c   OF FLATS   %c       TAX       %c   ADDED   %c   PAYMENT   %c   AMOUNT   %c",vr,vr,vr,vr,vr,vr);
	gotoxy(3,15);
	printf("%c",RT);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<11 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<13 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<12 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",LT);
	gotoxy(3,16);
	printf("%c",vr);
	gotoxy(11,16);
	printf("%d",S[j].Noofflats);
	gotoxy(18,16);
	printf("%c",vr);
	gotoxy(22,16);
	printf("%f",S[j].MantTax);
	gotoxy(36,16);
	printf("%c",vr);
	gotoxy(38,16);
	printf("%f",S[j].TaxAdder);
	gotoxy(48,16);
	printf("%c",vr);
	gotoxy(51,16);
	printf("%s",S[j].DOP);
	gotoxy(62,16);
	printf("%c",vr);
	gotoxy(64,16);
	printf("%f",S[j].TotalBill);
	gotoxy(75,16);
	printf("%c",vr);
	gotoxy(3,17);
	printf("%c",bl);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<11 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<13 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<12 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",br);
	gotoxy(27,18);
	printf("ENTER ANY KEY TO CONTINUE...");
}

void displayall()
{
	char tl=218 , tr=191 , bl=192 , br=217 , hr=196 , vr=179 , RT=195 , LT=180 , TT=193 , BT=194 , P=197;
	int i;
	clrscr();
	printf("%c",tl);
	for(i=0 ; i<6 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<20 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",BT);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",tr);
	printf("%c SNo. %c     NAME     %c   CONTACT NO.   %c  DATE OF PAYMENT   %c   TOTAL BILL    %c",vr,vr,vr,vr,vr,vr);
	printf("%c",RT);
	for(i=0 ; i<6 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<20 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",P);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",LT);
	for(i=0 ; i<::i ; ++i)
	{
		gotoxy(1,i+4);
		printf("%c",vr);
		gotoxy(8,i+4);
		printf("%c",vr);
		gotoxy(23,i+4);
		printf("%c",vr);
		gotoxy(41,i+4);
		printf("%c",vr);
		gotoxy(62,i+4);
		printf("%c",vr);
		gotoxy(80,i+4);
		printf("%c",vr);
		gotoxy(4,i+4);
		printf("%d",i+1);
		gotoxy(11,i+4);
		printf("%s",S[i].Cperson);
		gotoxy(28,i+4);
		printf("%s",S[i].ContactNo);
		gotoxy(49,i+4);
		printf("%s",S[i].DOP);
		gotoxy(65,i+4);
		printf("%f",S[i].TotalBill);
	}
	gotoxy(1,i+4);
	printf("%c",bl);
	for(i=0 ; i<6 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<14 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<20 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",TT);
	for(i=0 ; i<17 ; ++i)
	{
		printf("%c",hr);
	}
	printf("%c",br);
}

void search()
{
	char name[30];
	int i , flag=0;
	printf("Enter the Person Name to Search : ");
	gets(name);
	gets(name);
	for(i=0 ; i<::i ; ++i)
	{
		if(strcmp(name,S[i].Cperson)==0)
		{
			display(i);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nSorry Data Not Found For Person Searched %s",name);
	}
}