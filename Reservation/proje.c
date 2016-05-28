/*
Name: Çaðrý Emre AKIN
ID: 1862457
Department: CNG

Description:
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Menu ();
void reserve (int*, int*, int*, int*);
void cancel (int*, int*, int*);
void update (int, int[], int[], int[], int*, int*, int*);
void view (int, int[], int[], int[]);

int main()
{
    printf("\n|||-  WELCOME TO THE RESTAURANT RESERVATION SYSTEM  -|||\n\n");
    
    Menu();
    
    system("pause");
    return 0;
}

void Menu()
{    
     fflush(stdin);
     char a,b,c,d,q;
     char Choice, phantom;
     char opselect;
  
     printf("Choose one in the following menu of choices\n\n");
     
     printf(" \t a.Make a reservation.\n");
     printf(" \t b.Cancel a reservation.\n");
     printf(" \t c.Update a reservation.\n");
     printf(" \t d.Show reservations.\n");
     printf(" \t q.Quit.\n");
     printf("\nMENU SELECTION: ");
     scanf("%c",&opselect);
     fflush(stdin);     
     
     static int id = 0;
     static int meal[100];
     static int people[100];
     static int phone[100];
     
     int j;
     int phoneNumber, removeID = -1;

     switch (opselect)
     {
          case 'a':
              reserve(&id, &meal[id], &people[id], &phone[id]);
              break; 
                   
          case 'b':             
              do
              {
                   view(id, meal, people, phone); 
                   printf("\nEnter a phone number on the list: ");
                   scanf("%d",&phoneNumber);
                   
                   for (j = 0; j < id; j++)
                   {
                        if (phoneNumber == phone[j])
                        removeID = j;
                   }
                   if (removeID == -1)
                   printf("WARNING: You should enter a phone number from the list!");
                   
              }while (removeID == -1);
              
              cancel (&meal[removeID], &people[removeID], &phone[removeID]); 
              break;
              
          case 'c':
              update(id, meal, people, phone, &meal, &people, &phone); 
              break;
              
          case 'd':
              view(id, meal, people, phone); 
              break;
              
          case 'q':
              printf("\nProgram is terminating...\n");
              system("pause");
              exit(1); 
              break;
           
          default:
              printf("\nWARNING: Please enter correct character!\n");
              break;  
     }
     id++;
     Menu();
}
void reserve(int *i, int *mealTime, int *numPeople, int *phoneNum)
{
    static int  reserved1_1 = 0, reserved1_2 = 0, reserved1_3 = 0, reserved1_4 = 0;
    static int  reserved2_1 = 0, reserved2_2 = 0, reserved2_3 = 0, reserved2_4 = 0;
    int restPeople, j;
    
    printf("\nChoose your reservation time!\n");
    printf("1.Lunch\n");
    printf("2.Dinner\n\n");
    printf("RESERVATION TIME: ");
    scanf("%d",mealTime);
    
    printf("\nHow many people would you like to book?\n");
    printf("NUMBER OF PEOPLE: ");
    scanf("%d",numPeople);
    
       if (*mealTime == 1)
       {
            if (*numPeople <= 3 && reserved1_1 == 0)
                 reserved1_1 = 1;   
            else if (*numPeople <= 6 && reserved1_2 == 0)
                 reserved1_2 = 1;
            else if (*numPeople <= 12 && reserved1_3 == 0)
                 reserved1_3 = 1;
            else if (*numPeople <= 15 && reserved1_4 == 0)
                 reserved1_4 = 1;
            else if (*numPeople <= 36 && reserved1_1 == 0 && reserved1_2 == 0 && reserved1_3 == 0 && reserved1_4 == 0)
            {
                  restPeople = *numPeople;
                  reserved1_4 = 1;                        // assuming there are more than 15 ppl alrady..
                  restPeople = restPeople - 15;
                                    
                  reserved1_3 = (restPeople >= 12 ? 1 : 0);
                  
                  if (restPeople <= 12 && restPeople > 6)
                  {   
                       reserved1_3 = 1;
                       restPeople = restPeople - 12;
                  }
                  
                  reserved1_2 = (restPeople % 6 >= 1 ? 1 : 0);
                  
                  if (restPeople <= 6 && restPeople > 3)
                  {   
                       reserved1_2 = 1;
                       restPeople = restPeople - 12;
                  }
                  
                  reserved1_1 = (restPeople % 3 >= 1 ? 1 : 0);
                  
            }
            else 
            {
                 printf("There is no available table for %d people.\n",*numPeople);  
                 //system("pause");  
                 //exit(1);
                 Menu();
            }
       }
       
       if (*mealTime == 2)
       {
            if (*numPeople <= 3 && reserved2_1 == 0)
                 reserved2_1 = 1;   
            else if (*numPeople <= 6 && reserved2_2 == 0)
                 reserved2_2 = 1;
            else if (*numPeople <= 12 && reserved2_3 == 0)
                 reserved2_3 = 1;
            else if (*numPeople <= 15 && reserved2_4 == 0)
                 reserved2_4 = 1;
            else if (*numPeople <= 36 && reserved2_1 == 0 && reserved2_2 == 0 && reserved2_3 == 0 && reserved2_4 == 0)
            {
                  restPeople = *numPeople;
                  reserved2_4 = 1;                        // assuming there are more than 15 ppl alrady..
                  restPeople = restPeople - 15;
                                    
                  reserved2_3 = (restPeople >= 12 ? 1 : 0);
                  
                  if (restPeople <= 12 && restPeople > 6)
                  {   
                       reserved2_3 = 1;
                       restPeople = restPeople - 12;
                  }
                  
                  reserved2_2 = (restPeople % 6 >= 1 ? 1 : 0);
                  
                  if (restPeople <= 6 && restPeople > 3)
                  {   
                       reserved2_2 = 1;
                       restPeople = restPeople - 12;
                  }
                  
                  reserved2_1 = (restPeople % 3 >= 1 ? 1 : 0);
                  
            }
            else 
            {
                 printf("There is no available table for %d people.\n",*numPeople);  
                 //system("pause");  
                 //exit(1);
                 Menu();
            }
       }
    
    printf("\nPlease enter a phone number\n");
    printf("TELEPHONE NUMBER: ");
    scanf("%d",phoneNum);
    
 /*   printf("i degeri: %d  i adresi: %d   array degeri: %d   array adresi: %d\n\n",*i,i,*mealTime,mealTime);
    printf("i degeri: %d  i adresi: %d   array degeri: %d   array adresi: %d\n\n",*i,i,*numPeople,numPeople);
    printf("i degeri: %d  i adresi: %d   array degeri: %d   array adresi: %d\n\n",*i,i,*phoneNum,phoneNum);
  */  
    printf("\n>> The reservation is accomplished successfully!\n");
    
    if (reserved1_1 == 1)
    printf("Table 1 is reserved for Meal Time 1!\n");
    if (reserved1_2 == 1)
    printf("Table 2 is reserved for Meal Time 1!\n");
    if (reserved1_3 == 1)
    printf("Table 3 is reserved for Meal Time 1!\n");
    if (reserved1_4 == 1)
    printf("Table 4 is reserved for Meal Time 1!\n");
    if (reserved2_1 == 1)
    printf("Table 1 is reserved for Meal Time 2!\n");
    if (reserved2_2 == 1)
    printf("Table 2 is reserved for Meal Time 2!\n");
    if (reserved2_3 == 1)
    printf("Table 3 is reserved for Meal Time 2!\n");
    if (reserved2_4 == 1)
    printf("Table 4 is reserved for Meal Time 2!\n");

}


void view (int i, int mealTime[], int numPeople[], int phoneNum[])
{
     int counter = 0;
     printf("\n--------------------------------------------------------------\n"); 
      
     while (counter < i)
     {
           printf("ID: %d\tPhone No: %d\tMeal Time: %d\tNumber of People: %d\n",counter+1,phoneNum[counter],mealTime[counter],numPeople[counter]);
           counter++;
     }
     printf("\n--------------------------------------------------------------\n");      
}


void cancel (int *mealTime, int *numPeople, int *phoneNum)
{
     *mealTime = 0;
     *numPeople = 0;
     *phoneNum = 0;
     
     printf("\n>> The reservation is canceled successfully!\n");
} 


void update(int i, int mealTime[], int numPeople[], int phoneNum[], int *meal, int *people, int *phone)
{
     char select;
     int j,phoneNumber,removeID = -1;
     
     printf("NOTICE: You are about to change a reservation, this procedure will cancel the reservation in order to update!\n");
     printf("Do you accept this policy?\n (Y / N): ");
     scanf("%c",&select);
     fflush(stdin);
     
     switch (select)
     {
          case 'N':  
               Menu();
               break;
          
          case 'Y':
               
               do
               {
                    view(i, mealTime, numPeople, phoneNum);
                    printf("\nEnter a phone number on the list: ");
                    scanf("%d",&phoneNumber);
                   
                    for (j = 0; j < i; j++)
                    {
                         if (phoneNumber == phoneNum[j])
                         removeID = j;
                    }
                    if (removeID == -1)
                    printf("WARNING: You should enter a phone number from the list!");
                   
               }while (removeID == -1);
               
               
               cancel (&meal[removeID], &people[removeID], &phone[removeID]); 
               reserve (&removeID, &meal[removeID], &people[removeID], &phone[removeID]);
               break;
               
          default:
               printf("WARNING: You should enter Y or N to continue!");
               break;
               
     }
     
     Menu();
}
