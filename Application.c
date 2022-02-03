/*Necessary header files*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/*Necessary functions*/

/*Front display functions*/
/*creator tag contains creators*/
/*option pannel contains what to do things*/
/*create is responsible for creating users*/
/*Contribution by saman bajracharya*/
void creatorTag();
void optionPannel();
void create();

/*display details and total balance functions are responsible for displaying data of a user*/
/*Contribution by venus kc*/
void displayDetails(char *,char *);
float totalBalance(char *);

/*deposit function is responsible for depositing money to a particular user's account*/
/*Contribution by pratik kumar goyal*/
void deposit(char *,char *);

/*Full operation of application is handled by main page*/
/*Contribution by ashirwad regmi*/
void mainPage();

void main()
{
  /*main page is the actual administrator of this application*/
    mainPage();
}

void creatorTag()
{
  /*This is to notify that Pratik Goyal, Venus KC, Saman Bajracharya and Ashirwad Regmi together completed this entire project work in a team work*/
    printf("\t\t\t\t            Banking Deposit and Withdraw System\n");
    printf("\t\t\t\t\t\t       Created by\n");
    printf("\t\t\t\t------------------------------------------------------------\n");
    printf("\t\t\t\tPratik Goyal, Venus KC, Saman Bajracharya and Ashirwad Regmi\n");
    printf("\t\t\t\t------------------------------------------------------------\n\n");
}

/*total balance function is responsible for extracting existing amount in the user's account*/
float totalBalance(char *User_Name)
{
  char Name_Of_User[1000];
  strcpy(Name_Of_User,User_Name);
  strcat(Name_Of_User,".dat");
  float Total_Amount;
  FILE *createFile;
  createFile = fopen(Name_Of_User,"rb");
  fread(&Total_Amount,sizeof(float),1,createFile);
  fclose(createFile);
  return(Total_Amount);
}

/*Entire task is conducted by main page*/
void mainPage()
{
  char Yes_Or_No;
  int choice;
  do{
    /*Main program starts from here*/
    creatorTag(); /*Control transfers to creator tag function*/

    optionPannel(); /*control transfers to option pannel function*/

    printf("\t\t\t\t------------------------------------------------------------\n");
    printf("\t\t\t\t->");
    scanf("%d",&choice);
    printf("\t\t\t\t------------------------------------------------------------\n");
    switch(choice)
    {
      case 1:
      {
        create(); /*Control transfers to create tag function*/
        break;
      }
      case 2:
      {
        char User_Name[1000],Name_Of_User[1000];
        Not_Exist:
        system("cls");
        creatorTag(); /*Control transfers to creator tag function*/
        printf("\t\t\t\tNote: To exit enter \"-1\"\n\t\t\t\tEnter name of account to deposit\n");
        printf("\t\t\t\t->");
        fflush(stdin);
        gets(User_Name);
        strcpy(Name_Of_User,User_Name);
        if(strcmp(User_Name,"-1")==0)
          {
            break;
          }
        strcat(User_Name,".dat");

        /*Checking whether the data file exists or not*/
        FILE *Check_Existence_Of_File;
        Check_Existence_Of_File = fopen(User_Name,"rb");
        if(Check_Existence_Of_File == NULL)
        {
          printf("\t\t\t\tSorry! the name of account you searched for is not available\n");
          printf("\t\t\t\tPress enter to try again!!!");
          getch();
          goto Not_Exist;
        }
        fclose(Check_Existence_Of_File);

        deposit(User_Name,Name_Of_User); /*control transfers to deposit function*/
        break;
      }
      case 3:
      {
        char Yes_Or_No;
        int removed;
        char User_Name[1000];
        do{
          Name_Not_Available:
          system("cls");
          creatorTag(); /*Control transfers to creator tag function*/
          printf("\t\t\t\tNote: To exit enter \"-1\"\n\t\t\t\tEnter name of account to remove\n");
          printf("\t\t\t\t->");
          fflush(stdin);
          scanf("%[^\n]",User_Name);

          if(strcmp(User_Name,"-1")==0)
          {
            break;
          }

          strcat(User_Name,".dat");
          removed = remove(User_Name);
          if(removed == 0)
          {
            printf("\t\t\t\t----------------------------\n");
            printf("\t\t\t\tAccount removed successfully\n");
            printf("\t\t\t\t----------------------------\n");
          }
          else
          {
            printf("\t\t\t\t---------------------\n");
            printf("\t\t\t\tAccount not available\n");
            printf("\t\t\t\t---------------------\n");
          }

          printf("\t\t\t\tDo you want to remove other datas?\n");
          printf("\t\t\t [y/n]->");
          fflush(stdin);
          Yes_Or_No = getchar();
        }while((Yes_Or_No != 'n' || Yes_Or_No != 'N') && (Yes_Or_No == 'y' || Yes_Or_No == 'Y'));
        break;
      }
      case 4:
      {
        char Yes_Or_No;
        do{
          system("cls");
          creatorTag(); /*Control transfers to creator tag function*/
          char User_Name[1000],User_Data_File_Name[1000];
          printf("\t\t\t\tEnter name of account to display information\n");
          printf("\t\t\t\t->");
          fflush(stdin);
          gets(User_Name);
          strcpy(User_Data_File_Name,User_Name);
          strcat(User_Data_File_Name,".dat");
          displayDetails(User_Data_File_Name,User_Name); /*control transfers to display details functions*/
          
          printf("\t\t\t\tDo you want to view other datas?\n");
          printf("\t\t\t [y/n]->");
          fflush(stdin);
          Yes_Or_No = getchar();
        }while((Yes_Or_No != 'n' || Yes_Or_No != 'N') && (Yes_Or_No == 'y' || Yes_Or_No == 'Y'));
        break;
      }
      case 5:
      {
        break;
      }
      default:
      {
        printf("\t\t\t\tInvalid choice!\n");
        break;
      }
    }
    printf("\t\t\t\tDo you really want to exit?\n");
    printf("\t\t\t [y/n]->");
    fflush(stdin);
    Yes_Or_No = getchar();
    system("cls");
    }while((Yes_Or_No == 'n' || Yes_Or_No == 'N') && (Yes_Or_No != 'y' || Yes_Or_No != 'Y'));
    /*Main program ends here*/
}

/*deposit is responsible for adding amount to a user's account*/
void deposit(char *User_Data_File,char *Name_Of_User)
{
  float Total_Balance_Before_Execution,Total_Balance_After_Execution,Execution;
  char Name_Of_User_Data_File[1000];
  char Yes_Or_No;

    do{
      Overdraft:
        system("cls");
        creatorTag(); /*Control transfers to creator tag function*/

      /*If the account already exists then only adding performs*/

        Total_Balance_Before_Execution = totalBalance(Name_Of_User);
        printf("\t\t\t\tYour balance is: %f\n",Total_Balance_Before_Execution);
        printf("\t\t\t\tNote: To withdraw, give your amount in -ve and to exit enter amount \"0 or 0.0\"\n\t\t\t\tHow much amount you want to deposit/withdraw into your account?\n\t\t\t\t->");
        scanf("%f",&Execution);
        if(Execution<Total_Balance_Before_Execution && Execution!=0)
        {
          Execution = -Execution;
          if(Execution>Total_Balance_Before_Execution)
          {
            printf("\t\t\t\tWithdraw more than balance is invalid\n\t\t\t\tTry again");
            getch();
            goto Overdraft;
          }
          else
          {
            Execution = -Execution;
            goto Continue_Transaction;
          }
        }
        else if(Execution == 0.0)
        {
          goto Exit_Deposit_Transaction_Process;
        }

        Continue_Transaction:
        Total_Balance_After_Execution = totalBalance(Name_Of_User); /*control transfers to total balance function*/
        Total_Balance_After_Execution += Execution;
        printf("\t\t\t\tYour final balance is: %f\n",Total_Balance_After_Execution);
        /*Updating balance in user account*/
        strcpy(Name_Of_User_Data_File,User_Data_File);
        if(fopen(Name_Of_User_Data_File,"rb") != NULL)
        {
          FILE *Open_User_Data_File;
          Open_User_Data_File = fopen(Name_Of_User_Data_File,"wb");
          fwrite(&Total_Balance_After_Execution,sizeof(float),1,Open_User_Data_File);
          fclose(Open_User_Data_File);
        }
        else
        {
          printf("\t\t\t\tSorry! the name of data your searched for is not available\n");
        }
      
        Exit_Deposit_Transaction_Process:
        printf("\t\t\t\tDo you want to deposit again?\n");
        printf("\t\t\t [y/n]->");
        fflush(stdin);
        Yes_Or_No = getchar();
    }while((Yes_Or_No=='y' || Yes_Or_No == 'Y')&&(Yes_Or_No!='n' || Yes_Or_No!='N'));
}

/*Responsible for displaying details extracted by total balance function*/
void displayDetails(char *Name_Of_User_Data_File,char *Name_Of_User) /*Input should be in the form filename.dat*/
{
  char Yes_Or_No;
    char User_Data_File[1000];
    strcpy(User_Data_File,Name_Of_User_Data_File);
    float BalanceAmount;
    FILE *Open_User_Data_File;
    Open_User_Data_File = fopen(User_Data_File,"rb");
    if(Open_User_Data_File == NULL)
    {
      printf("\t\t\t\tsorry! user data file not available\n");
      printf("\t\t\t\tPlease try again!!!\n");
      return;
    }
    fread(&BalanceAmount,sizeof(float),1,Open_User_Data_File);
    fclose(Open_User_Data_File);
    char User_Name[1000];
    strcpy(User_Name,Name_Of_User);
    BalanceAmount = totalBalance(User_Name); /*Control transfers to total balance function*/
  printf("\t\t\t\tYour total balance: %f\n",BalanceAmount);
}

/*create function is responsible for creating a unique user*/
void create()
{
  char User_Name[1000],Yes_Or_No;
  float Default_Value=0;
  do{
    system("cls");
    creatorTag();
    printf("\t\t\t\t~ Create A New Account ~\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\tNote: To exit enter \"-1\"\n\t\t\t\tEnter user name\n");
    printf("\t\t\t\t->");
    fflush(stdin);
    gets(User_Name);
    if(strcmp(User_Name,"-1")==0)
    {
      break;
    }
    strcat(User_Name,".dat");
    if(fopen(User_Name,"rb")==NULL)
    {
      FILE *Create_User_Data_File;
      Create_User_Data_File = fopen(User_Name,"wb");
      if(Create_User_Data_File == NULL)
      {
        printf("\n\t\t\t\tUnable to create user data file");
        getch();
      }
      fprintf(Create_User_Data_File,"%f",Default_Value);
      fclose(Create_User_Data_File);
    }
    else
    {
      printf("\t\t\t\tSorry! username already exists\n");
    }

    printf("\t\t\t\tDo you want to again create another account?\n");
    printf("\t\t\t [y/n]->");
    fflush(stdin);
    Yes_Or_No = getchar();
  }while((Yes_Or_No != 'n' || Yes_Or_No != 'N') && (Yes_Or_No == 'y' || Yes_Or_No == 'Y'));
}

/*option pannel displays the tasks in order to use this application smoothly*/
void optionPannel()
{
  printf("\t\t\t\tChoose any options below\n\n");
  printf("\t\t\t\t\tCreate new account :: 1\n");
  printf("\t\t\t\t\tDeposit/Withdraw :: 2\n");
  printf("\t\t\t\t\tRemove an account :: 3\n");
  printf("\t\t\t\t\tDisplay user details :: 4\n");
  printf("\t\t\t\t\tExit :: 5\n");
  printf("\t\t\t\t\t\n");
}