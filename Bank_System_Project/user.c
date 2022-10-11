#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bank_account.h"


void create_account(ba_t* client)
{
	int i, j;
	char answer;
	

	
	//int flag=0;
	
	
	printf("Enter your full name\n");
	for (j=0;j<4;j++)
	{
	scanf("%s",&client->name[j][0]);
	}
	
	j=0;
	
	while(j<4)
	{
	printf("%s ",&client->name[j]);
	j++;
	}
	
	printf("\n");
	
	
	printf("Please enter your Full address \n");
	scanf("%s",&client->address);
	fflush(stdin);
	printf("Address= %s \n",client->address);
	
	
	printf("Please enter your age \n");
	scanf("%d",&client->age);
	fflush(stdin);
	printf("Age= %d \n",client->age);
	
	printf("Please enter your 14 digits national ID \n");
	scanf("%14lld",&client->nationalID);
	fflush(stdin);
	printf("nationalID= %14lld \n",client->nationalID);
	
	
	printf("Are you over 21? (y/n) \n");
	//scanf("%s",answer);
	answer= (char)getchar();
	fflush(stdin);
	printf("you answer is: %c \n",answer);

	
	if(answer=='n')
	{
		printf("Enter your Guardian nationalID \n");
		scanf("%14lld",&client->GuardianNationalID);
		fflush(stdin);
		printf("Your Guardian nationalID is %14lld \n",client->GuardianNationalID);
	}
	 else 
	{
		printf("You don't need a Guardian\n");
	}
	
	srand(time(NULL));
	const char list_id[] = PASSWARD;
	const char list_id2[] = BANKID_LIMITS;
	int rindex = 0;
	printf("This is your temporary passward: ");
	for(int i = 0; i < 8; i++)
	{
		rindex= rand() % (sizeof(list_id));
		client->passward[i] = list_id[rindex];
        printf("%c", client->passward[i]);
	}
	printf("\n");
	printf("\tWelcome %s \n",client->name);
	
	printf("This is your generated Bank ID: ");
	for(int i = 0; i < 10; i++)
	{
		rindex = rand() % 10;
		printf("%c", list_id2[rindex]);
		client->BankID[i]=list_id2[rindex];
	}
	printf("\n client->BankID[i]: %s\n", client->BankID);
	printf("\n Bank status: %d \n",client->status);
	printf("Balance = %f \n",client->Balance);
	
}

void Make_transaction (ba_t* client)
{
		 float amount;
		 char BankID2[100];
		printf("Make transaction \n");
		printf("please enter the 10 digits bank ID you want to tansfer the money to \n");
		scanf("%s",&BankID2);
		printf("please enter the desired amount \n");
		scanf("%f",&amount);		
	if ((client->Balance > amount) && (client->status==1))
	{
		client->Balance=client->Balance-amount;
		printf("The amount was successfully transfered");
		printf("Your balance now is %d",client->Balance);
	}
	else if  (client->Balance<amount && client->status==1)
	{
		printf("Your balance is insufficient");
	}
	else
	{
		printf("Your account needs activation");
	}
	
}

void Change_status(ba_t* client)
{
	char* status[3] = {
	    "Active",
		"Restricted",
		"Closed"
	};
	int action;
	printf("Change account status \n");
	printf("Your status has been reset to: \n");
	for(int action=0; action<3; action++)
	{
		printf(" %d: %s\n",action ,status[action]);
	}
	scanf("%d",&action);
	client->status=action;

}
void Get_Cash(ba_t* client)
{
	float amount;
	printf("Get Cash \n");
	printf("please enter the desired amount \n");
	scanf("%f",&amount);
	if ((client->Balance>amount) && (client->status==1))
	{
		client->Balance=client->Balance-amount;
		printf("The amount was successfully transfered\n");
		printf("Your balance now is %d\n",client->Balance);
	}
	else if ((client->Balance<amount) && (client->status==1))
	{
		printf("Your balance is insufficient\n");
	}
	else
	{
		printf("Your account needs activation");
	}
}

void Deposit(ba_t* client)
{
	float amount;
	printf("Deposit \n");
	printf("please enter the desired amount \n");
	fflush(stdin);
	scanf("%f",&amount);
	client->Balance=client->Balance+amount;
	printf("Your balance now is %f \n",client->Balance);
	
}

void change_password(ba_t* client)
{
	printf("Change account passward \n");
	scanf("%s", client->passward);
	printf("Your new passward is %s",client->passward);	
}