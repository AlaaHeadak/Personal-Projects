#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_


#define MAX_NUMBER_OF_CLIENTS 	 100
#define BANKID_LIMITS 			"1234567890"
#define PASSWARD 				"1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*"


typedef struct bank_acount
{
	char name[6][10];
	unsigned int age;
	char address[100];
	long long int nationalID;
	long long int GuardianNationalID;
	char passward[100];
	char BankID[100];
	float Balance;
	int status;
	

} ba_t;

void Deposit(ba_t* client);
void Get_Cash(ba_t* client);
void Change_status(ba_t* client);
void Make_transaction (ba_t* client);
void create_account(ba_t* client);
void change_password(ba_t* client);

#endif /* _BANK_ACCOUNT_H_ */