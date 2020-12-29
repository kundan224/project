#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

//Main Function
int main()
{
    int choice;
    interest_rate();
    start:
    system("cls");
    printf("===SMART BANK===");
    printf("\n1. New account\n2. Transaction\n3. Update\n4. show_details\n5. exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            system("cls");
            new_account();
        break;
        case 2:
            transaction();
        break;
        case 3:
            update();
        break;
        case 4:
            show_details();
        break;
        case 5:
            exit(0);
    }
    goto start;
    return 0;
}

//Interest Rate Function
void interest_rate()
{
    FILE *pt,*account_name,*date_file;
    int tm,i,count;
    float interest_ammount;
    int day,month,year,months,total_months,years,total_years;
    long long int exist_ammount,total_ammount;
    char a[16],account_type[30];
    char *extension=".txt";

    //Open First Name file to put the account name of a particular user using their first name.
    account_name=fopen("first_name.text","r");
    date_file=fopen("interest_date.text","r");  //open Interest date file to get last date of putted interest

    count=0;
    fseek(date_file,count,0);
    fscanf(date_file,"%d",&day);
    count+=2;
    fseek(date_file,count,0);
    fscanf(date_file,"%d",&month);
    count+=4;
    fseek(date_file,count,0);
    fscanf(date_file,"%d",&year);

    //find the current time and date of the computer.
    SYSTEMTIME time;
    GetSystemTime(&time);

    if(month>time.wMonth)
        months=month-time.wMonth;
    else
        months=time.wMonth-month;

    years=time.wYear-year;

   // printf("\n%d %d %d",day,month,year);
   // printf("\n%d  %d",months,years);
    total_months=(12*years)+months;
 //   printf("\nTotal Months: %d",total_months);

    {

            m:
            tm=fgets(a,15,account_name);  //getting first name to access any account using using first name as a account's file name
            if(tm==NULL)
            {
                goto ed;
            }
            a[strlen(a)-1]='\0';
            char fileSpec[strlen(a)+strlen(extension)+1];

            //concatinate first name with .txt to open any particular account
            snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
            pt = fopen( fileSpec, "r+" );

            for(i=10;i>=1;i--)
            {
                fseek(pt,-i,2);
                fscanf(pt,"%lld",&exist_ammount);
                if(exist_ammount!=0)
                    break;
            }

            {
                fseek(pt,0,0);
                while(fgets(account_type,28,pt))
                {
                    account_type[strlen(account_type)-1]='\0';
                    if(strcmp(account_type,"saving")==0)
                        break;
                    if(strcmp(account_type,"current")==0)
                        break;
                    if(strcmp(account_type,"fixed1")==0)
                        break;
                    if(strcmp(account_type,"fixed2")==0)
                        break;
                    if(strcmp(account_type,"fixed3")==0)
                        break;
                }
                {
                    if(strcmp(account_type,"saving")==0)
                    {
                        interest_ammount=exist_ammount*((float)2/100)/12*total_months;
                        total_ammount=exist_ammount+interest_ammount;
                        fseek(pt,0,2);
                        fprintf(pt,"\n000000");
                        fprintf(pt,"\n%lld",total_ammount);
                    }
                    if(strcmp(account_type,"fixed1")==0 || strcmp(account_type,"fixed2")==0 || strcmp(account_type,"fixed3")==0)
                    {
                        interest_ammount=exist_ammount*((float)1.2/100)/12*total_months;
                        total_ammount=exist_ammount+interest_ammount;
                        fseek(pt,0,2);
                        fprintf(pt,"\n000000");
                        fprintf(pt,"\n%lld",total_ammount);
                    }
                }
            }
            fclose(pt);  //closing file
            goto m;
        }
        ed:
        fclose(date_file);  //close interest date file

        {
            date_file=fopen("interest_date.text","w");  //again open interest date file
            count=0;
            fseek(date_file,count,0);
            if(time.wDay<=9)// update interest date file with current date
                fprintf(date_file,"0%d\n",time.wDay);
            else
                fprintf(date_file,"%d\n",time.wDay);

            if(time.wMonth<=9)
                fprintf(date_file,"0%d\n",time.wMonth);
            else
                fprintf(date_file,"%d\n",time.wMonth);

            fprintf(date_file,"%d",time.wYear);
        }

        fclose(account_name);  //close first name file
        fclose(date_file); //close interest date file
        //fclose(pt);
}

//New Account Function...
void new_account()
{
    struct name
    {
        char first_name[10];
        char middle_name[10];
        char last_name[10];
    };

    struct date
    {
        int day;
        int month;
        int year;
    };

    struct address
    {
        char main_address[10];
        int pin_code;
        char city[10];
        char state[10];
    };

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

    FILE *pt,*lt_account,*account_name;
    SYSTEMTIME time;
    long long int temp,temp_ammount=0000000000;
    int age=0;
    int choice,count=0,count1=0,count2=0,t=0;
    int end1=0,i,pn,tm;
    long long int mb,ad,check_mobile_no;
    char a[16],x;
    char name[15]="";
    char* extension = ".txt";
    add.account_no=temp;
    add.account_no++;
    temp=add.account_no;
    GetSystemTime(&time);
    system("cls");

    account_name=fopen("first_name.text","a+"); //open first name file to get the file name to any particular account
    lt_account=fopen("leatest_account.text","r");  //open leatest account file to get the account number

    //form now user have to enter their data
    printf("Enter name of customer:");
    printf("\nFirst name=");
    scanf("%s",&add.name1.first_name);
    {
        //convert first latter of customer's fitst name into upper latter
        x=toupper(add.name1.first_name[0]);
        add.name1.first_name[0]=x;
    }
    printf("Middle name=");
    scanf("%s",&add.name1.middle_name);
    printf("Last name=");
    scanf("%s",&add.name1.last_name);

    printf("\n\nEnter father's name:");
    printf("\nFirst name=");
    scanf("%s",&add.name2.first_name);
    printf("middle name=");
    scanf("%s",&add.name2.middle_name);
    printf("Last name=");
    scanf("%s",&add.name2.last_name);

    printf("\n\nEnter address:");
    printf("\nMain address=");
    scanf("%s",&add.local_address.main_address);
    printf("City=");
    scanf("%s",&add.local_address.city);
    printf("State=");
    scanf("%s",&add.local_address.state);
    {
        //checking the either pin code is valid or not
        p:
            t=0;
        printf("Pin code=");
        scanf("%d",&add.local_address.pin_code);

        pn=add.local_address.pin_code;

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
    printf("\nEnter your choice: ");
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
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    {
        //checking DOB validation
        if(add.dob.day<1 || add.dob.day>31 || add.dob.month<1 || add.dob.month>12 || add.dob.year<1900 || add.dob.year>=time.wYear)
        {
            printf("Invalid DOB!\n");
            goto d;
        }

        { //finding age using DOB and current date
            if(time.wDay>=add.dob.day && time.wMonth>=add.dob.month || time.wDay<add.dob.day && time.wMonth>add.dob.month)
            {
                for(i=add.dob.year;i<time.wYear;i++)
                {
                    age++;
                }
            }
            else
            {
                for(i=add.dob.year;i<time.wYear-1;i++)
                {
                    age++;
                }
            }
        }
    }
    printf("Enter Nationality: ");
    fflush(stdin);
    scanf("%s",&add.nationality);

    {
        //checking mobile no validation
        mbl:
        count=0;
        fseek(account_name,0,0);
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
            goto mbl;
        }

        {

            m:
            tm=fgets(a,15,account_name);
            if(tm==NULL)
            {
                goto ed;
            }
            a[strlen(a)-1]='\0';
            char fileSpec[strlen(a)+strlen(extension)+1];


            snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
            pt = fopen( fileSpec, "r+" );

            fscanf(pt,"%lld",&check_mobile_no);
            if(add.mobile_no==check_mobile_no)
            {
                printf("This Mobile No already exist!...\n");
                goto mbl;
            }
            else
                goto m;

        }

    }

    ed:
    {
        e:
        printf("Enter Email ID: ");
        scanf("%s",&add.mail_id);

        {
            //Checking email id validation
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
                goto e;
            }
        }

    }

    {
        adr:
        count2=0;
        printf("Enter Adhar Card no: ");
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
        temp_ammount=temp_ammount+add.initial_amount;
        add.initial_amount=temp_ammount;
    }

    {
        char nm[10];
        int count=0;
        strcpy(name,add.name1.first_name);
        printf("\nName=%s",name);
        while(1)
        {
            fseek(account_name,count,0);
            if(fscanf(account_name,"%s",&nm)==EOF)
            {
                break;
            }
            if(strcmp(nm,name)==0)
            {
                strcat(name,"1");
            }
            count+=strlen(nm);
            count+=2;
        }
        fprintf(account_name,"%s\n",name);
    }

    char fileSpec[strlen(name)+strlen(extension)+1];
    {
        snprintf( fileSpec, sizeof( fileSpec ), "%s%s", name, extension );
        pt = fopen( fileSpec, "a+" );
    }
    fscanf(lt_account,"%lld",&temp);

    {
        //Printing user's data into particular file
        fprintf(pt,"%lld %lld",add.mobile_no,temp);
        fprintf(pt,"\n%s",add.mail_id);
        fprintf(pt,"\n%s",add.marital_status);
        fprintf(pt,"\n%s %s %s",add.name1.first_name,add.name1.middle_name,add.name1.last_name);
        fprintf(pt,"\n%s %s %s",add.name2.first_name,add.name2.middle_name,add.name2.last_name);
        fprintf(pt,"\n%s %s %s %d",add.local_address.main_address,add.local_address.city,add.local_address.state,add.local_address.pin_code);
        fprintf(pt,"\n%s",add.gender);
        fprintf(pt,"\n%s",add.nationality);
        fprintf(pt,"\n%lld",add.adhar_no);
        fprintf(pt,"\n%s",add.account_type);
        fprintf(pt,"\n%d/%d/%d",add.dob.day,add.dob.month,add.dob.year);
        fprintf(pt,"\n%s",add.pan_card);
        fprintf(pt,"\n000000");
        fprintf(pt,"\n%d",add.initial_amount);
    }


    fclose(account_name);
    fclose(pt);
    fclose(lt_account);

    printf("\nAccount Number: %lld",temp);

    lt_account=fopen("leatest_account.text","w");
    temp++;
    fprintf(lt_account,"%lld",temp); //updating account number into file

    fclose(lt_account);


    printf("\n\n Your Account created successfully");
    getch();

}

//Transaction Function
void transaction()
{
    int choice,set=0,i,tm,count=-20;
    char t[25];
    long long int account_number,phone_number,temp_ammount,exist_ammount,temp;
    long long int faccount_number,fphone_number,t_account;
    char f_name[10];
    FILE *p,*pt;

    char a[16];
    char arr[16];
    char* extension = ".txt";
    char fileSpec[strlen(a)+strlen(extension)+1];

    p=fopen("first_name.text","r"); //Open first file name to get file name


    printf("You open your account with:");
    printf("\n1. Account No\n2. Phone No");
    c:
    printf("\nEnter your choice: ");
    scanf("%d",&choice);



    {

            m:
            tm=fgets(a,15,p);
            if(tm==NULL)
            {
                printf("\nSorry Your Account is not Found!");
                getch();
                return;
            }
            a[strlen(a)-1]='\0';
            char fileSpec[strlen(a)+strlen(extension)+1];


        snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
        pt = fopen( fileSpec, "r+" );

        if(pt==NULL)
        {
            printf("File is not open!");
            getch();
            return;
        }

    }

    switch(choice)
    {
        case 1:
        {
            printf("Enter account No: ");
            scanf("%lld",&account_number);

            {
                ma:
                tm=fgets(a,15,p);
                if(tm==NULL)
                {
                    printf("\nSorry Your Account is not Found!");
                    getch();
                    return;
                }
                a[strlen(a)-1]='\0';
                char fileSpec[strlen(a)+strlen(extension)+1];

                snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
                pt = fopen( fileSpec, "r+" );

                if(pt==NULL)
                {
                    printf("File is not open!");
                    getch();
                    return;
                }

            }

            fseek(pt,11,0);

            fscanf(pt,"%lld",&faccount_number); //getting user's account number from file

            if(account_number!=faccount_number) //matching user's account no to entered account no
                goto ma;
            else
            {
                set=1;
                break;
            }
        }
        case 2:
        {
            printf("Enter Phone No: ");
            scanf("%lld",&phone_number);

            {

                mp:
                tm=fgets(a,15,p);
                if(tm==NULL)
                {
                    printf("\nSorry Your Account is not Found!");
                    getch();
                    return;
                }
                a[strlen(a)-1]='\0';
                char fileSpec[strlen(a)+strlen(extension)+1];

                snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
                pt = fopen( fileSpec, "r+" );

                if(pt==NULL)
                {
                    printf("File is not open!");
                    getch();
                    return;
                }

            }

            fseek(pt,0,0);
            fscanf(pt,"%lld",&fphone_number); //getting user's phone no

            if(phone_number!=fphone_number) //matching user's phone no to entered phone number
                goto mp;
            else
            {
                set=1;
                break;
            }
        }
        default:
        {
            printf("Invalid choice!");
            goto c;
        }
    }

    if(set==1) //account or phone no matched with a account
    {
        printf("\nDo you want to Withdrawal or Deposit:");
        printf("\n1. Withdrawal\n2. Deposit");
        ch:
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                amm:
                printf("Enter amount:  ");
                scanf("%lld",&temp_ammount);

                for(i=10;i>=1;i--)
                {
                    fseek(pt,-i,2);
                    fscanf(pt,"%lld",&exist_ammount);
                    if(exist_ammount!=0)
                        break;
                }
                if(exist_ammount<temp_ammount) //checking exist amount with entered amount either it is less of grater
                {
                    printf("\nInvalid Amount!");
                    goto amm;
                }
                else
                {
                    temp=exist_ammount;
                    count=0;
                    {
                        while(temp!=0)
                        {
                            count++;
                            temp/=10;
                        }
                    }
                    exist_ammount=exist_ammount-temp_ammount;
                    fseek(pt,1,2);
                    fprintf(pt,"\n000000");
                    fprintf(pt,"\n%lld",exist_ammount); //updating amount into file
                    printf("Withdrawal Successfully");
                    printf("\nAvailable Amount: %lld",exist_ammount);
                    getch();
                    break;
                }
            }
            case 2:
            {
                printf("Enter amount: ");
                scanf("%lld",&temp_ammount);

                for(i=10;i>=1;i--)
                {
                    fseek(pt,-i,2);
                    fscanf(pt,"%lld",&exist_ammount);
                    if(exist_ammount!=0)
                        break;
                }
                exist_ammount=exist_ammount+temp_ammount;
                {
                    temp=exist_ammount;
                    count=0;
                    while(temp!=0)
                    {
                        count++;
                        temp/=10;
                    }
                }
                fseek(pt,1,2);
                fprintf(pt,"\n000000");
                fprintf(pt,"\n%lld",exist_ammount);
                printf("Deposit Successfully");
                printf("\nAvalable Ammount: %lld",exist_ammount);
                getch();
                break;
            }
            default:
            {
                printf("Invalid choice!");
                goto ch;
            }
        }
    }

    fclose(pt);

}

//Update Function
void update()
{
    FILE *p,*pt;
    int choice,set=0,tm,count,end1=0,i,emls,nmls;
    long long int account_number,phone_number,temp_ammount,exist_ammount,temp,t,mb;
    long long int faccount_number,fphone_number,t_account;
    long long int old_phone,new_phone,exist_phone;
    char old_email[25],temp_email[40],new_email[25],exist_email[25],t_email[25];
    char new_marital[10],new_pan[15];
    char a[16];
    char arr[10];
    char* extension = ".txt";

    p=fopen("first_name.text","r");

    start:
    printf("You want to open your Account with:");
    printf("\n1. Account No\n2. Phone No");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1:
        {
            printf("Enter account No: ");
            scanf("%lld",&account_number);

             {

                ma:
                tm=fgets(a,15,p);
                if(tm==NULL)
                {
                    printf("\nSorry Your Account is not Found!");
                    getch();
                    return;
                }
                a[strlen(a)-1]='\0';
                char fileSpec[strlen(a)+strlen(extension)+1];


                snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
                pt = fopen( fileSpec, "r+" );

                if(pt==NULL)
                {
                    printf("File is not open!");
                    getch();
                    return;
                }
            }

            fseek(pt,11,0);

            fscanf(pt,"%lld",&faccount_number);

            if(account_number!=faccount_number)
                goto ma;
            else
            {
                set=1;
                break;
            }
        }
        case 2:
        {
            printf("Enter Phone No: ");
            scanf("%lld",&phone_number);

             {

                mp:
                tm=fgets(a,15,p);
                if(tm==NULL)
                {
                    printf("\nSorry Your Account is not Found!");
                    getch();
                    return;
                }
                a[strlen(a)-1]='\0';
                char fileSpec[strlen(a)+strlen(extension)+1];


                snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
                printf("\n%s->me",fileSpec);
                pt = fopen( fileSpec, "r+" );

                if(pt==NULL)
                {
                    printf("File is not open!");
                    getch();
                    return;
                }
            }

            fseek(pt,0,0);
            fscanf(pt,"%lld",&fphone_number);

            if(phone_number!=fphone_number)
                goto mp;
            else
            {
                set=1;
                break;
            }
        }
        default:
        {
            printf("Invalid choice!");
            goto start;
        }
    }

    if(set==1)
    {
        s:
        printf("\nYou want to update your:");
        printf("\n1. Mobile No\n2. Marital status\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter Old Mobile No: ");
                scanf("%lld",&old_phone);
                fseek(pt,0,0);
                fscanf(pt,"%lld",&exist_phone); //getting exist phone number
                printf("%lld",exist_phone);

                if(old_phone!=exist_phone) //matching old phone number with entered phone number
                {
                    printf("\nInvalid Mobile No!");
                    getch();
                    return;
                }
                else
                {
                    mbl:
                    printf("\nEnter New Mobile No: ");
                    scanf("%lld",&new_phone);
                    {
                        count=0;
                        mb=new_phone;
                        while(mb!=0)
                        {
                            count++;
                            mb/=10;
                        }
                        if(count!=10)
                        {
                            printf("Invalid Mobile No!\n");
                            goto mbl;
                        }
                    }

                    fseek(pt,0,0);
                    fprintf(pt,"%lld",new_phone); //updating phone number
                    printf("\nMobile Number Update Successfully");
                    getch();
                    break;
                }
            }

            case 2:
            {
                printf("\nEnter Marital status: ");
                scanf("%s",&new_marital);

                {
                    fseek(pt,22,0);
                    fscanf(pt,"%s",&t_email);
                    getch();
                    count=strlen(t_email);
                    count=count+24;
                    if(strcmp(new_marital,"married")==0||strcmp(new_marital,"Married")==0)
                    {
                        strcat(new_marital,"  ");
                    }
                    fseek(pt,count,0);
                    fprintf(pt,"\n%s",new_marital); //updating marital status
                    printf("\nMarital Status Update Successfully");
                    break;
                }
            }
            default:
            {
                printf("\nInvalid Choice!");
                goto s;
            }
        }
    }
    getch();
    fclose(pt);
    fclose(p);
}

//Show Details Function
void show_details()
{
    FILE *p,*pt;
    char a[16];
    char arr[10];
    char* extension = ".txt";
    int choice,tm,set=0,count=0,t,i;
    long long int phone,account,exist_phone,exist_account,adhar_no,ammount;
    long long int phone_no,account_no,pin_code;
    char email[40],temp_email[40],merital[10],merital1[10];
    char main_address[10],city[10],state[10];
    char c_fname[10],c_mname[10],c_lname[10];
    char f_fname[10],f_mname[10],f_lname[10];
    char gender[8],nationality[10],account_type[10],temp[10];

    p=fopen("first_name.text","r");

    start:
    printf("\nYou want to open your Account with:");
    printf("\n1. Account No\n2. Phone No");
    m:
    printf("\nEnter your choice: ");
    scanf("%d",&choice);



    switch(choice)
    {
        case 1:
        {
            printf("Enter Account Number: ");
            scanf("%lld",&account);

             {
                ma:
                tm=fgets(a,15,p);
                    if(tm==NULL)
                    {
                        printf("\nSorry Your Account is not Found!");
                        getch();
                        return;
                    }
                    a[strlen(a)-1]='\0';
                    char fileSpec[strlen(a)+strlen(extension)+1];


                snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
                printf("\n%s->me",fileSpec);
                pt = fopen( fileSpec, "r+" );

                if(pt==NULL)
                {
                    printf("File is not open!");
                    getch();
                    return;
                }
            }

            fseek(pt,11,0);
            fscanf(pt,"%lld",&exist_account);

            if(account!=exist_account)
            {
//                printf("\nInvalid Account Number!");
                goto ma;
            }
            else
            {
                set=1;
                break;
            }
        }
        case 2:
        {
            printf("Enter Phone No: ");
            scanf("%lld",&phone);
            {
                mp:
                tm=fgets(a,15,p);
                    if(tm==NULL)
                    {
                        printf("\nSorry Your Account is not Found!");
                        getch();
                        return;
                    }
                    a[strlen(a)-1]='\0';
                    char fileSpec[strlen(a)+strlen(extension)+1];


                snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
                pt = fopen( fileSpec, "r+" );

                if(pt==NULL)
                {
                    printf("File is not open!");
                    getch();
                    return;
                }
            }
            fseek(pt,0,0);
            fscanf(pt,"%lld",&exist_phone);
            if(phone!=exist_phone)
            {
//                printf("\nInvalid Phone Number!");
                goto mp;
            }
            else
            {
                set=1;
                break;
            }
        }
        default:
        {
            printf("\nInvalid Choice!");
            goto m;
        }
    }

 /*   if(set==1)
    {
        fseek(pt,0,0);
        fscanf(pt,"%lld",&phone_no);
        fseek(pt,11,0);
        fscanf(pt,"%lld",&account_no);
        fseek(pt,22,0);
        fscanf(pt,"%s",&email);
        count=strlen(email);
        count=count+24;
        fseek(pt,count,0);
        fscanf(pt,"%s",&merital);
        printf("\nMerital: %s",merital);
        count=count+strlen(merital);
        count=count+2;
        fseek(pt,count,0);
        fscanf(pt,"%s",c_fname);
        count=count+strlen(c_fname);
        count=count+2;
        fseek(pt,count,0);
        fscanf(pt,"%s",c_mname);
        count=count+strlen(c_mname);
        count=count+1;
        fseek(pt,count,0);
        fscanf(pt,"%s",c_lname);
        count=count+strlen(c_lname);
        count=count+1;
        fseek(pt,count,0);
        fscanf(pt,"%s",f_fname);
        count=count+strlen(f_fname);
        count=count+2;
        fseek(pt,count,0);
        fscanf(pt,"%s",f_mname);
        count=count+strlen(f_mname);
        count=count+1;
        fseek(pt,count,0);
        fscanf(pt,"%s",f_lname);
        count=count+strlen(f_lname);
        count=count+1;
        fseek(pt,count,0);
        //fscanf(pt,"%s",&main_address);
        printf("\nMerital: %s",merital);
        //count=count+strlen(main_address);
        //count=count+2;
        fseek(pt,count,0);
        fscanf(pt,"%s",&city);
        count=count+strlen(city);
        count=count+1;
        fseek(pt,count,0);
        fscanf(pt,"%s",&state);
        count=count+strlen(state);
        count=count+1;
        fseek(pt,count,0);
        fscanf(pt,"%lld",&pin_code);
        count=count+7;
        fseek(pt,count,0);
        fscanf(pt,"%s",gender);
        count=count+strlen(gender);
        count=count+2;
        fseek(pt,count,0);
        fscanf(pt,"%s",nationality);
        count=count+strlen(nationality);
        count=count+2;
        fseek(pt,count,0);
        fscanf(pt,"%lld",&adhar_no);
        count=count+14;
        fseek(pt,count,0);
        fscanf(pt,"%s",account_type);
        count=count+strlen(account_type);
        for(i=10;i>=1;i--)
        {
            fseek(pt,-i,2);
            fscanf(pt,"%lld",&ammount);
            if(ammount!=0)
                break;
        }
        */


        if(set==1) //matched account or phone number
        { //Getting user's details from file
            fseek(pt,0,0);
            fscanf(pt,"%lld",&phone_no);
            fseek(pt,11,0);
            fscanf(pt,"%lld",&account_no);
            fseek(pt,22,0);
            fscanf(pt,"%s",&email);

            count=strlen(email);
            //count+=temail_size;
            count=count+24;
            fseek(pt,count,0);
            fscanf(pt,"%s",&merital);
            if(strlen(merital)==7)
                count+=2;
            count=count+strlen(merital);

            count=count+2;
            fseek(pt,count,0);
            fscanf(pt,"%s",c_fname);
            count=count+strlen(c_fname);
            count=count+2;
            fseek(pt,count,0);
            fscanf(pt,"%s",c_mname);
            count=count+strlen(c_mname);
            count=count+1;
            fseek(pt,count,0);
            fscanf(pt,"%s",c_lname);
            count=count+strlen(c_lname);
            count=count+1;
            fseek(pt,count,0);
            fscanf(pt,"%s",f_fname);
            count=count+strlen(f_fname);
            count=count+2;
            fseek(pt,count,0);
            fscanf(pt,"%s",f_mname);
            count=count+strlen(f_mname);
            count=count+1;
            fseek(pt,count,0);
            fscanf(pt,"%s",f_lname);
            count=count+strlen(f_lname);
            count=count+1;
            fseek(pt,count,0);
            fscanf(pt,"%s",main_address);
            count=count+strlen(main_address);
            count=count+2;
            fseek(pt,count,0);
            fscanf(pt,"%s",&city);
            count=count+strlen(city);
            count=count+1;
            fseek(pt,count,0);
            fscanf(pt,"%s",&state);
            count=count+strlen(state);
            count=count+1;
            fseek(pt,count,0);
            fscanf(pt,"%lld",&pin_code);
            count=count+7;
            fseek(pt,count,0);
            fscanf(pt,"%s",gender);
            count=count+strlen(gender);
            count=count+2;
            fseek(pt,count,0);
            fscanf(pt,"%s",nationality);
            count=count+strlen(nationality);
            count=count+2;
            fseek(pt,count,0);
            fscanf(pt,"%lld",&adhar_no);
            count=count+14;
            fseek(pt,count,0);
            fscanf(pt,"%s",account_type);
            count=count+strlen(account_type);
            for(i=10;i>=1;i--)
            {
                fseek(pt,-i,2);
                fscanf(pt,"%lld",&ammount);
                if(ammount!=0)
                    break;
            }

            //Printing user's details on output screen
            printf("\nFirst Name: %s %s %s",c_fname,c_mname,c_lname);
            printf("\nFather Name: %s %s %s",f_fname,f_mname,f_lname);
            printf("\nMain Address: %s %s %s %lld",main_address,city,state,pin_code);
            printf("\nPhone no: %lld",phone_no);
            printf("\nAccount no: %lld",account_no);
            printf("\nEmail id: %s",email);
            printf("\nMerital: %s",merital);
            printf("\nGemder: %s",gender);
            printf("\nNationality: %s",nationality);
            printf("\nAdhar No: %lld",adhar_no);
            printf("\nAccount Type: %s",account_type);
            printf("\nAmmount: %lld",ammount);


            getch();
        }
    fclose(pt); //close user's account file
    fclose(p); //close first name file
}

