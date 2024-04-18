#include <stdio.h>
#include <string.h>
#include<time.h>

struct card{
	char name[20];
	int balance;
    char pins[5];
    char number[13];

}holders[15];



void delay(int seconds) 
{ 
   
    int milli = 1000 * seconds;  
    clock_t start = clock();   
    while (clock() < start + milli); 
        
} 


/////////////////////////////////////////////////////////////
//to check pin number
int pin(char a[5],int j)
{
    FILE *f1;
	char buffer[5];
	int i;
    f1 = fopen("pins.txt","r");
    int k=0;

	if(f1 == NULL)            
	{
		printf("Error!");
	}
	else
    {    
		for(i=0;i<10;i++)
		{            
			fscanf(f1,"%s",&buffer);
            if(i==j)
            {
   			if (strcmp(a,buffer)==0)
            {   
                k=0;
		        break;    
            }    
            else 
            {           
				k=1;
                	
            } 
        } 
        }
        if (k==1)
            printf("invalid pin\n");
        return k;	
    }
	fclose(f1);
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//checking account number
void account(char a[8],int p[2])
{
	char pin;
    FILE *f2; 
	char buffer[9];
    p[1]=0; 
    int i;
    f2 = fopen("account.txt","r");

	if(f2 == NULL)            
	{
		printf("Error!");
	}
	else
    {    
		for(i=0;i<10;i++) //checks till end of line
    	{    
            fscanf(f2,"%s",&buffer);
   			if (strcmp(a,buffer)==0)
            {               
                p[0]=0;
                break;    
            }    
            else
            {
                p[1]++; 
                p[0]=1;
            }   
        } 
        if (p[0]==1)
            printf("invalid number\n");
    }
	fclose(f2);
}
///////////////////////////////////////////////////////////////////
int main()
{


	FILE *f1,*f2,*f3, *f4,*f5;
	
	f1 = fopen("pins.txt","r");
	f2 = fopen("account.txt","r");
	f3 = fopen("name.txt","r");
	f4 = fopen("balance.txt","r");
    f5 = fopen("number.txt","r");
	
	char pins[5];
    char a[4];
    char b[8];
    int i=0, j,k;

	

	
 //////////////////////////////////////////////////////
    //storing name in struct
    if(f3 == NULL)            
	{
		printf("Error!");
	}
	else
    {		
		for(i=0;i<10;i++) //checks till end of line
    	{    
		 	fgets(holders[i].name,20,f3);
        } 
	}
 //////////////////////////////////////////////////////
		
 ////////////////////////////////////////////////////////////
	//storing balance in struct
	 if(f4 == NULL)            
	{
		printf("Error!");
	}
	else
    {  
		for(i=1;i<10;i++) 
		{	   
    		fscanf(f4,"%d",&holders[i].balance);
        } 
	}
    //////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
	//storing pins in struct
	 if(f1 == NULL)            
	{
		printf("Error!");
	}
	else
    {  
		for(i=1;i<10;i++) 
		{	   
    		fscanf(f1,"%s",&holders[i].pins);
        } 
	}
    ////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////
	//storing phone in struct
	if(f5 == NULL)            
	{
		printf("Error!");
	}
	else
    {  
		for(i=1;i<10;i++) 
		{	   
    		fscanf(f5,"%s",&holders[i].number);
        } 
	}
    ////////////////////////////////////////////////////////////


	
	
 //////////////////////////////////////////////////////////////
//    //testing values
//     for(i=1;i<10;i++)
//     {
//     	printf("balance: %d\n",holders[i].balance);
//         printf("pins: %s\n",holders[i].pins);
//         printf("Number: %s\n",holders[i].number);
//     	printf("Name: %s\n",holders[i].name);

//     }

///////////////////////////////////////////////////////////////////////

    printf("\n\n\n\n\n\n\n \t\t\t\t******** Welcome to I.B.U ATM Service **********\n\n");
	delay(2);
	system("cls");

    //checking account number
    int p[2];
    do 
    {
        printf("Enter your account number: ");
        gets(b);
        account(b,p);
        k=p[0];
        j=p[1];

    }while((k==1));
 
    //checking pin 
    do 
    {
        printf("Enter your secret pin number:");
        gets(a);
        k=pin(a,j);

    }while((k==1));
 



    //starting menu

    int choice;
    int wdraw,dpot;
    char transaction;  
    int num[13];
    char r[5];
    j=j+1;

    do
    {
    printf("\n\n\n");
    printf("*********************\n");
    printf("Hello %s Welcome to our ATM Service\n",holders[j].name);
    printf("1. Balance Checking\n");
    printf("2. Cash Withdrawal\n");
    printf("3. Cash Deposition\n");
    printf("4. Reset pin\n");
    printf("5. Reset phone number\n");
    printf("6. Exit\n");
    printf("*********************\n");
    printf("Please proceed with your choice: ");
    scanf("%d", &choice);
	
    switch (choice)
    {
    case 1:
        printf("\n The account balance in Rs: %d ", holders[j].balance);
        break;

    case 2:
        printf("\n Insert the amount to be withdrawal: ");
        scanf("%d", &wdraw);
        
        if (wdraw % 100 != 0)
        {
            printf("\n You are requested to insert the amount in multiples of 100");
        }
        else if (wdraw >(holders[j].balance - 500))
        {
            printf("\n You are having an insufficient balance");
        }
        else
        {
            holders[j].balance = holders[j].balance - wdraw;
            printf("balance:%d",holders[j].balance);
            printf("\nj:%d",j);
            printf("wdraw:%d",wdraw);
            
            printf("\n\n You can now collect the cash"); // after having a sufficient amount in the account the ATM machine will provide the cash amount.
            printf("\n The current balance is %d", holders[j].balance);
        }
        break;

    case 3:
        printf("\n Insert the amount to be deposited: ");
        scanf("%d", &dpot);
        holders[j].balance = holders[j].balance + dpot;
        printf("The balance is %d", holders[j].balance); // Displays the new current balance after the cash deposition in the user’s account
        break;

    case 4:
    k=0;
    do
    {
        printf("Enter previous pin: ");
        scanf("%s",&r);
        if (strcmp(r,holders[j].pins)==0)
            {
                printf("Enter new pin: ");
                scanf("%s",&holders[j].pins);
                k=0;
            }
        else 
        {
            printf("Pin incorect\n");
            k=1;
        }
    }while(k==1);
        break;

    case 5:
    k=0;
    do
    {
        printf("Enter previous phone number: ");
        scanf("%s",&num);
        if (strcmp(num,holders[j].number)==0)
            {
                printf("Enter new phone number: ");
                scanf("%s",&holders[j].number);
                k=0;
            }
        else 
        {
            printf("Phone number incorect\n");
            k=1;
        }
    }while(k==1);
        break;

    case 6:
        printf("\n We are thankful to you for USING our IBU ATM services!");
        break;

    default:
        printf("\n You have made an invalid choice"); // Defines that the user have done something wrong with the ATM service options
    }

    printf("\n\n\n Would you like to have another ATM transaction?(y/n): \n");
    fflush(stdin);
    scanf("%c", &transaction);
    if (transaction == 'n'|| transaction == 'N')
        k = 1;
        
    }while (!k);

    printf("\n\n Thank you so much %s your time to choose The our ATM services!",holders[j].name);


    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);

    ///////////////////////////////////////////////////////////
    //updating balance file
    f4 = fopen("balance.txt","w");
    if(f4 == NULL) 
    {
        printf("Error!");
    }
    else
    {
    for (i=1;i<10;i++)
    {
        fprintf(f4,"%d\n",holders[i].balance);
    }
    
    fclose(f4);
    }
    ////////////////////////////////////////////////

    ///////////////////////////////////////////////
    //updating pin file
    f1 = fopen("pins.txt","w");
    if(f1 == NULL) 
    {
        printf("Error!");
    }
    else
    {
    for (i=1;i<10;i++)
    {
        fprintf(f1,"%s\n",holders[i].pins);
    }


    fclose(f1);
    }
    /////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    //updating number file
    f5 = fopen("number.txt","w");
    if(f5 == NULL) 
    {
        printf("Error!");
    }
    else
    {
    for (i=1;i<10;i++)
    {
        fprintf(f5,"%s\n",holders[i].number);
    }    
    fclose(f5);
    }
    ////////////////////////////////////////////////
}
    




    
    
    



	
