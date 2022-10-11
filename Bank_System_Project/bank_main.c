#include <stdio.h>
#include <stdlib.h>
#include <bank_account.h>
#include <string.h>



void main(void)
{
	int menue, exit = 0, quite=1; 
	ba_t clients[MAX_NUMBER_OF_CLIENTS];
	memset(clients,0,sizeof clients);
	clients[0].status=1;
	char * mode=malloc(sizeof(char)*100);
	char* service1[3] = {
		"Create new account",
		"Open existing account",
		"Exist account"
	};
	char* service2[6] = {
		"Make transaction",
		"Change account passward",
		"Get Cash",
		"Deposit",
		"Return",
		"Back to the admin menue"
	};

	unsigned int BankID2;
	int choice;
	char temp[100], temp1[100];
	while(1)
	{
		
		// 1. Read user inputs
		// 2. Check user input args
		// if admin
		printf("Enter the required mode");
		scanf("%s",mode);
		if(*mode== 'a' || *mode== 'A')
		{
			// 1. Admin window
			while(!exit)
			{
				printf("You are in the Admin modes\n");
				printf("Enter you required operation \n");
				for(int i = 1; i<4	; i++)
				{
					printf("Operation %d: %s\n",i ,service1[i-1]);
				}
				scanf("%d",&menue);
				
				switch(menue)
				{
					case 1:
							printf("Create new account \n");
							create_account(&clients[0]);
							break;
					case 2:
						printf("Please enter your Bank ID");
						
							scanf("%s", temp);
						int ret = strcmp(clients[0].BankID, temp);
						if (ret==0)
						{
							printf("\tWelcome %s \n",clients[0].name);
						}
						else
						{
							printf("wrong ID");
						}	
						do 
						{
						printf("\n You are in the admin mode \n");
						printf("Enter you required operation \n");
							for(int i =0; i<5; i++)
							{
								printf("Operation %d: %s\n",i ,service2[i]);
							}
							scanf ("%d", &choice);
							switch( choice )
							{
								case 0:
						
										Make_transaction(&clients[0]);
										break;
								case 1:
										Change_status(&clients[0]);
										break;
								case 2:
										Get_Cash(&clients[0]);
										break;
								case 3:
										Deposit(&clients[0]);
										break;
								case 4:
										printf("return \n");
										quite=0;
										break;
								case 5:
								printf("Back to the admin menue \n");
								quite=1;
								break;
								default:
										printf("Error, Please enter the correct operation");
							}
						}while(!quite);
							break;
					case 3:
							printf("Exist account \n");
							exit =1;
							break;
					default:
							printf("Error, please enter the correct operation \n");
							break;
				} 
			}
		}
	else
		{
			// 2. Client Window
			do 
			{
			printf("You are in the Client mode");
			printf("Enter you BankID");
			scanf("%s",temp);
			printf("Enter you passward");
			scanf("%s",temp1);
			
			if ((strcmp(clients[0].BankID, temp) == 0) && (strcmp(clients[0].passward, temp1) == 0))
			{
			printf("Enter you required operation \n");
				for(int i=0; i<5; i++)
				{
					printf("Operation %d: %s\n",i ,service2[i]);
				}
				scanf("%d",&choice);
				switch(choice)
				{
					case 0:
						Make_transaction(&clients[0]);
							break;
					case 1:

							break;
					case 2:
							Get_Cash(&clients[0]);
							break;
					case 3:
							Deposit(&clients[0]);
							break;
					case 4:

							printf("return \n");
							*mode='a';
							quite=0;
							break;
					default:
							printf("Error, Please enter the correct operation");
				}
			}
			else 
				
				{
					printf("This user doesn't exist \n");
				}
			}
			while(!quite);		
		}
	}
}