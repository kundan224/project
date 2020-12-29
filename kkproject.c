#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

void account(void);
void for_transaction(void);
struct name
{
    char first_name[10];
    char middle_name[10];
    char last_name[10];
}hello;

struct date
{
    int day;
    int month;
    int year;
}hi;

struct address
{
    char main_address[10];
    int pin_code;
    char city[10];
    char state[10];
}fact;

struct acc
{
    struct name name1,name2;
    struct date dob;
    struct address local_address;
    char gender[7];
    char nationality[10];
    char mail_id[20];
    long long int mobile_no;
    char pan_card[12];
    char marital_status[10];
    char account_type[10];
    int initial_amount;
    long long int adhar_no;
    long long int account_no;
}add;

int main()
{
	int choice;
	printf("***smart banking system***");
	
	printf("\n1.create new account");
	printf("\n2.update your account");
	printf("\n3.check your account");
	printf("\n4.for transaction");
	printf("\n5.remove account");
	printf("\n enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			 account();
			 break;
			 case 2:
			 	printf("comming soon:");
			 	break;
			 	case 3:
			 		printf("comming soon:");
			 	break;
			 	case 4:
			 		for_transaction();
			 		break;
			 		case 5:
			 			printf("comming soon:");
			 	break;
			 	default:
			 		printf("please choose a currect option ");
			 			
			 			}
   
    return 0;
}
void account()
{
	 FILE *pt;
    SYSTEMTIME time;
    static long long int temp=12345670000;
    int age=0;
    int choice,count=0,count1=0,count2=0,t=0;
    int end1=0,i,pn;
    long long int mb,ad;
    add.account_no=temp;
    add.account_no++;
    temp=add.account_no;
    GetSystemTime(&time);
    system("cls");
    
    pt=fopen("account.text","a+");


    printf("enter name of customer:");
    printf("\nFirst name=");
    scanf("%s",&hello.first_name);
    printf("Middle name=");
    scanf("%s",&hello.middle_name);
    printf("Last name=");
    scanf("%s",&hello.last_name);

    printf("\n\nEnter father's name:");
    printf("\nFirst name=");
    scanf("%s",&hello.first_name);
    printf("middle name=");
    scanf("%s",&hello.middle_name);
    printf("Last name=");
    scanf("%s",&hello.last_name);

    printf("\n\nenter address:");
    printf("\nMain address=");
    scanf("%s",&fact.main_address);
    printf("City=");
    scanf("%s",&fact.city);
    printf("State=");
    scanf("%s",&fact.state);
    {
        p:
            t=0;
        printf("Pin code=");
        scanf("%d",&fact.pin_code);

        pn=fact.pin_code;

        while(pn!=0)
        {
            t++;
            pn/=10;
        }
        if(t!=6)
        {
            printf("Invalid Pin_code!\n");
            goto p;
        }
    }
    printf("\n\nEnter gender:\n");
    printf("1. Male\n2. Female\n3. Other");
    start:
    printf("\nenter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            strcpy(add.gender,"male");
        break;
        case 2:
            strcpy(add.gender,"female");
        break;
        case 3:
            strcpy(add.gender,"other");
        default:
            {
                printf("Invalid Choice!");
                goto start;
            }
    }
    d:
    printf("\n\nEnter DOB DD/MM/YYYY:");
    scanf("%d/%d/%d",&hi.day,&hi.month,&hi.year);
    {
        if(hi.day<1 || hi.day>31 || hi.month<1 || hi.month>12 || hi.year<1900 || add.dob.year>=time.wYear)
        {
            printf("Invalid DOB!\n");
            goto d;
        }

        {
            if(time.wDay>=hi.day && time.wMonth>=hi.month || time.wDay<hi.day && time.wMonth>hi.month)
            {
                for(i=hi.year;i<time.wYear;i++)
                {
                    age++;
                }
            }
            else
            {
                for(i=hi.year;i<time.wYear-1;i++)
                {
                    age++;
                }
            }
        }
    }
    printf("enter Nationality: ");
    fflush(stdin);
    scanf("%s",&add.nationality);
    {
        m:
        count=0;
        printf("Enter Mobile No: ");
        scanf("%lld",&add.mobile_no);
        mb=add.mobile_no;
        while(mb!=0)
        {
            count++;
            mb/=10;
        }
        if(count!=10)
        {
            printf("Invalid Mobile No!\n");
            goto m;
        }
    }

    {
        e:
        printf("Enter Email ID: ");
        scanf("%s",&add.mail_id);

        {
            for(i=0;i<strlen(add.mail_id);i++)
            {
                if(add.mail_id[i]=='@')
                {
                    end1=i+1;
                    break;
                }
            }
            if(end1==0)
            {
                printf("invalid email!\n");
                goto e;
            }

            for(i=end1;i<strlen(add.mail_id);i++)
            {
                if(add.mail_id[i]=='.')
                {
                    end1=1;
                    break;
                }
            }

            if(end1==1)
            {
                printf("\n");
            }
            else
            {
                printf("invalid email!\n");
                goto m;
            }
        }

    }


    {
        adr:
        count2=0;
        printf("enter Adhar Card no: ");
        scanf("%lld",&add.adhar_no);
        ad=add.adhar_no;

        while(ad!=0)
        {
            count2++;
            ad/=10;
        }

        if(count2!=12)
        {
            printf("Invalid Adhar no!\n");
            goto adr;
        }

    }


    if(age>=18)
    {
        pn:
        printf("\nEnter PAN Card No: ");
        scanf("%s",&add.pan_card);
        {
            if(strlen(add.pan_card)!=10)
            {
                printf("Invalid Pan_Number!");
                goto pn;
            }

        }
    }


    s:
    printf("\nEnter Marital status:");
    printf("\n1. Married");
    printf("\n2. Unmarried");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            strcpy(add.marital_status,"married");
            if(age<18 && (strcmp(add.gender,"female")==0) || age<21 && (strcmp(add.gender,"male")==0))
                goto s;
        }
        break;
        case 2:
            strcpy(add.marital_status,"unmarried");
        break;
        default:
            {
                printf("Invalid choice!");
                goto s;
            }
    }

    a:
    printf("\nEnter Account Type:");
    printf("\n1. Saving");
    printf("\n2. Current");
    printf("\n3. Fixed 1(1 Year)");
    printf("\n4. Fixed 2(2 Year)");
    printf("\n5. Fixed 3(3 Year)");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            strcpy(add.account_type,"saving");
        break;
        case 2:
            strcpy(add.account_type,"current");
        break;
        case 3:
            strcpy(add.account_type,"fixed1");
        break;
        case 4:
            strcpy(add.account_type,"fixed2");
        break;
        case 5:
            strcpy(add.account_type,"fixed3");
        break;
        default:
        {
            printf("Invalid choice!");
            goto a;
        }
    }


    am:
    printf("\nEnter amount to be deposit(Minimum '1000 rs'): ");
    scanf("%d",&add.initial_amount);
    {
        if(add.initial_amount<1000)
        {
            printf("Invalid amount!");
            goto am;
        }
    }


    {
        fprintf(pt,"%s %s %s",hello.first_name,hello.middle_name,hello.last_name);
        fprintf(pt,"\n%s %s %s",hello.first_name,hello.middle_name,hello.last_name);
        fprintf(pt,"\n%s %s %s %d",fact.main_address,fact.city,fact.state,fact.pin_code);
        fprintf(pt,"\n%s",add.gender);
        fprintf(pt,"\n%d/%d/%d",hi.day,hi.month,hi.year);
        fprintf(pt,"\n%s",add.nationality);
        fprintf(pt,"\n%lld",add.mobile_no);
        fprintf(pt,"\n%s",add.mail_id);
        fprintf(pt,"\n%lld",add.adhar_no);
        fprintf(pt,"\n%s",add.pan_card);
        fprintf(pt,"\n%s",add.marital_status);
        fprintf(pt,"\n%s",add.account_type);
        fprintf(pt,"\n%d",add.initial_amount);
    }
    fclose(pt);

    printf("\n\n Your Account created successfully");
    printf("\nAccount Number: %lld",add.account_no);


    printf("\n\nfirst name=%s\nmiddle name=%s\nlast name=%s",add.name1.first_name,add.name1.middle_name,add.name1.last_name);
    printf("\naddress=%s",add.local_address.main_address);
    printf("\nE-mail=%s",add.mail_id);


}
void for_transaction()
{
	FILE *pt;
	 pt=fopen("account.txt","a+");
    long long int mob,acc,dep,count=0;
    int bal=1000,widr,choice;

   printf("\n**** FOR TRANSACTION****");
   printf("\n 1.through phone number");
   fprintf(pt,"1.through phone number");
   printf("\n 2.through account number");
   fprintf(pt,"\n2.through account number");
   printf("\n enter your choose:");
   scanf("%d",&choice);
   fprintf(pt,"\n enter your choice=%d",choice);
   switch(choice)
   {
   case 1:
    printf("\n****account find****");
    printf("\n enter a valid mobile number:");
    scanf("%lld",&mob);
    fprintf(pt,"\n enter your valid mobile number=%lld",mob);
    while(mob>0)
    {
        mob=mob/10;
        count++;
    }
    if(count!=10)
    {
        printf("number is invalid");


        printf("\n again enter a valid number:");
        scanf("%lld",&mob);
        count=0;
        while(mob>0)
    {
        mob=mob/10;
        count++;
    }
    }
    if(count==10)
    printf("\n ****please choice next option**** ");
    else
    {
     printf("sorry you can not transaction");
            break;
    }

    printf("\n 1.do you want deposite");
    fprintf(pt,"\n 1.do you want deposite");
    printf("\n 2.do you want withdrow ");
    fprintf(pt,"\n 2.do you want withdrow");
    printf("\n enter your choice: ");
    scanf("%d",&choice);
    fprintf(pt,"\n enter your choice=%d",choice);
  

     switch(choice)
     {
     case 1:
        printf("\n enter your deposite ammout:");
        scanf("%d",&dep);
        fprintf(pt,"\n enter your deposite ammount=%d",dep);
        printf("your balance is:%d",dep+bal);
        fprintf(pt,"\n your total balance is=%d",dep+bal);
        break;

     case 2:
        printf("your withdrow amount:");
        scanf("%d",&widr);
        fprintf(pt,"\n your withdrow ammount=%d",widr);
        printf("your total balance is:-%d",bal-widr);
        fprintf(pt,"\n your total balance=%d",bal-widr);
        break;
     default:
        printf("number is not exit");
     }
     break;

     case 2:
         printf("\n****account find****");
         fprintf(pt,"\n****account find****");
  
         printf("\n enter a account number:");
         scanf("%lld",&acc);
         fprintf(pt,"enter your account number=%lld",acc);
  
        while(acc>0)
    {
        acc=acc/10;
        count++;
    }
    if(count!=12)
    {
        printf("account number  is invalid");


        printf("\n again enter a valid account number:");
        scanf("%lld",&mob);
        count=0;
        while(mob>0)
    {
        mob=mob/10;
        count++;
    }
    }
    if(count==12)
    printf("\n ****please choice next option**** ");
    else
    {
     printf("sorry you can not transaction");
            break;
    }
    printf("\n 1.do you want deposite");
    fprintf(pt,"\n 1.do you want deposite");
    printf("\n 2.do you want withdrow ");
    fprintf(pt,"\n 2.do you want withdrew");
    printf("\n enter your choice: ");
    scanf("%d",&choice);
    fprintf(pt,"\n enter your choice=%d",choice);

     switch(choice)
     {
     case 1:
        printf("\n enter your deposite ammout:");
        scanf("%d",&dep);
        fprintf(pt,"\n enter your deposite ammount=%d",dep);
        printf("your balance is:%d",dep+bal);
        fprintf(pt,"your balance is=%d",dep+bal);
        break;

     case 2:
        printf("\nyour withdrow amount:");
        scanf("%d",&widr);
        fprintf(pt,"\n your withdrow ammount=%d",widr);
        printf("your total balance is:%d",bal-widr);
        fprintf(pt,"\n your total balance is=%d",bal-widr);

        default:
        printf("number is not exit");
     }
     default:
        printf("number is not exit");
        break;
}
   
   fclose(pt);
}
void check_account()
{
}

