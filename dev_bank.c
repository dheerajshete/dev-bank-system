#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000
#define MIN 0
long long int transactionHistory[100];
int count = 0;
int count2 = 0;
void starter(){
        printf("\nProgram Started\nWelcome To Dev Bank\n");
    }

    void getCustomerName(char *a, char *b){
        printf("Enter your name : ");
        scanf("%s",a);
        printf("Enter your surname : ");
        scanf("%s",b);
    }

    long long int createaccount(long long int backup_key){
        int len, mobilelen, panlen;
        long long int account;

        int choice2 = 0;
        char aadhar[20], mobile[20], pan[20];
        printf("\nWhich account \n1. saving Account\n2. current account\n0. Exit \n");
        printf("Enter you choice : ");
        scanf("%d",&choice2);
        switch(choice2){
            case 1 : printf("\nFor saving Account provide following information\n");
            printf("enter your aadhar number : ");
            scanf("%s", aadhar);
            len = strlen(aadhar);
            if(len != 12){
                printf("\nInvalid aadhar\n");
            }
            else{
                printf("\naadhar confirm \n");
            }
            printf("enter your mobile number : +91 - ");
            scanf("%s", mobile);
            mobilelen = strlen(mobile);
            if(mobilelen != 10){
                printf("\nInvalid phone number\n");
            }
            else{
                printf("\nphone number confirm \n");
            }
            printf("enter your Pan number : ");
            scanf("%s", pan);
            panlen = strlen(pan);
            if(panlen != 10){
                printf("\nInvalid Pan number\n");
            }
            else{
                printf("\npan number confirm \n");
            }

            account = 100000 + rand ()%900000;;
            backup_key = account;
            printf("\nThis is your bank account number : %lld\n", account);
            break;

            case 2:  printf("\nFor current Account provide following information\n");
            printf("Enter your aadhar number : ");
            scanf("%s", aadhar);
            len = strlen(aadhar);
            if(len != 12){
                printf("\nInvalid aadhar\n");
            }
            else{
                printf("\nAadhar confirm \n");
            }
            printf("Enter your mobile number : +91 - ");
            scanf("%s", mobile);
            mobilelen = strlen(mobile);
            if(mobilelen != 10){
                printf("\nInvalid phone number\n");
            }
            else{
                printf("\nPhone number confirm \n");
            }
            printf("Enter your Pan number : ");
            scanf("%s", pan);
            panlen = strlen(pan);
            if(panlen != 10){
                printf("\nInvalid Pan number\n");
            }
            else{
                printf("\nPan number confirm \n");
            }
            
             account = 100000 + rand ()%900000;
             backup_key = account;
            printf("\nThis is your bank account number : %lld\n",account);
            break;

            default: 
                printf("\nInvalid choice\n");
                break;
        }
        return backup_key;
    }

    long long int deposit(long long int total){
        long long int a;
        printf("\nEnter amount to deposit : ");
        scanf("%lld", &a);
        if(a > MAX){
            printf("Can't deposit more then 10M\n");
        }
        else{
            total += a;
            
            printf("Current Balance Added: %lld\n", total);
        }
        transactionHistory[count] = a;
        count++;
    return total;
    }

    long long int withdraw(long long int total){
        long long int a;
        printf("\nEnter amount to withdraw : ");
        scanf("%lld", &a);
        if(a > MAX){
            printf("Can't Withdraw more then 10M\n");
        }

        else{
             if (total == 0){
                printf("\nDeposit money your balance is 0\n");
            }
            else if(a > total){
                printf("\nInsufficient balance\n");
            }
            else{
            total -= a;
            printf("Current Balance Added: %lld\n", total);
            transactionHistory[count] = -(a);
            count++;
        }
        }
        
    return total;
    }

int main(){
    srand(time(0));
    starter();

    char name[50];
    char surname[50];

    getCustomerName(name,surname);

    strcat(surname, " ");
    strcat(surname, name);
    int mainchoice=1;
    long long int balance = 0;
    long long int key = 0;
    long long int accnum = 0;
    long long int history[100];
   do{ 
        printf("\nEnter 1 to start Process\nEnter 0 to exit \n");
        printf("Enter you choice : ");
        scanf("%d",&mainchoice);
    int choice = 0;
    if(mainchoice == 1){
        do{
    printf("\nSelect your use\n1. Create Account\n2. Deposit Money \n3. Withdraw Money \n4. Check Balance\n5. Check your id\n6. Balance history\n7. Transaction history\n0. Exit \n\n");
    printf("Enter you choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        key = createaccount(key);
        break;
    
    case 2:
        balance = deposit(balance);
        history[count2] = balance;
        count2++;
        break;
    case 3:
        balance = withdraw(balance);
        history[count2] = balance;
        count2++;
        break;
    case 4:
        printf("\nYour current balance is %lld\n", balance);
    break;
    case 5:
        printf("\nWelcome to Dev-Bank\n");
        printf("Enter your account number : ");
        scanf("%lld", &accnum);
        if(accnum == key){
            printf("\nAccount number Confirm\n ");
            printf("\nName : %s \nAccount number : %lld\n", surname, key);
            printf("\nThanks for co-operating\n ");
        }
        else{
            printf("\nWrong Account number\n");
        }
        return 0;
    case 6:
        for(int i = 0; i < count2; i++){
            printf("%lld\n", history[i]);
        }
        break;
    case 7:
        for(int i = 0; i < count; i++){
            printf("%lld\n", transactionHistory[i]);
        }
        break;
    case 0:
        break;
    default:
        printf("\nInvalid option\n");
        break;
    }
    }while (choice != 0);
    }
} while (mainchoice != 0);
printf("\n%s Thanks for Choosing Dev-Bank \n", surname);
printf("\nProgram ended \n");
    return 0;

}