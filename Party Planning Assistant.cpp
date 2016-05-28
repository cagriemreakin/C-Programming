#include <stdio.h>
#include <stdlib.h>

#define peoplePerKeg 20
#define peoplePerCase 6
#define peoplePerPizza 4

void welcome();
void guestNum();
void beverageOrder();
void foodOrder();
void displayAll();
void bye();

int allPeople,beerKegs,dietCokeCases,pizzas;

int main ()
{
    char opselect;
    char a,b,c,d,e;
    
    printf("\n||||  WELCOME TO THE PARTY PLANNING ASSISTANT  ||||\n\n");
    printf("Choose one in the following menu of choices\n\n");
    
    welcome();


system("PAUSE");
return 0;   
}
    
    
    
void welcome()
{
    char opselect;
    char a,b,c,d,e;
    char phantom;
    

    printf("\ta. Enter number of invited guests.\n");
    printf("\tb. Determine beverage order.\n");
    printf("\tc. Determine food order.\n");
    printf("\td. Display all information.\n");
    printf("\te. Quit.\n\n");
    
    printf("MENU SELECTION: ");
    scanf("%c%c",&opselect,&phantom);
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    
    if (opselect == 'a') {opselect=1; }
    else if (opselect == 'b') { opselect=2; }
    else if (opselect == 'c') { opselect=3; }
    else if (opselect == 'd') { opselect=4; }
    else if (opselect == 'e') { opselect=5; }
    
    switch (opselect)
    {
           case 1:
                guestNum();
                break;
           case 2:
                beverageOrder();
                break;
           case 3:
                foodOrder();
                break;
           case 4:
                displayAll();
                break;
           case 5:
                bye();
                break;
           default:
                printf("------------------------------------ Echoing -----------------------------------\n\n");
                printf("Please select a valid choice\n\n");
                return (welcome());                  
                }
}


void guestNum()
{
     char phantom;
     
     printf("Please enter the number of invited guests: ");
     scanf("%d%c",&allPeople,&phantom);
     if (allPeople <= 0)
     {
          printf("\nNo one wants to join your party!\nOr\nEnter an positive decimal number\n\n");
          return (guestNum());
          }
     else
     {
          printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
          return (welcome());
          }
}


void beverageOrder()
{
     char phantom;
         
     if (allPeople == 0)
     {
          printf("There is no inveted guest!\nPlease select 'a' in menu option to determine the number of guests\n");
          printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
          welcome();
          }
     else
     {
          int beerPeople,dietCokePeople,beerRemainder,dietCokeRemainder;
         
          printf("%d People are inveted to the your party.\n",allPeople);
          printf("Please determine how many people may drink beer\n");
          printf("[Others will be determined automatically]\n");
          printf("\tFor Beer\t: ");
          scanf("%d%c",&beerPeople,&phantom);
          
          if (beerPeople > allPeople)
          {
               printf("\n\tWARNING: This number cannot be bigger than %d and lower than 0\n\n",allPeople);
               return (beverageOrder());
               }
               
          dietCokePeople = allPeople - beerPeople;
          printf("\tFor Diet Coke\t: %d",dietCokePeople);
          
          //   Calculation of Kegs and Cases
          
          beerRemainder = beerPeople / peoplePerKeg;
          dietCokeRemainder = dietCokePeople / peoplePerCase;
          
          if (beerPeople == 0)
          { beerKegs = 0; }
          else if ((beerPeople > 0) && (beerPeople <= peoplePerKeg))
          { beerKegs = 1; }
          else if (beerPeople > peoplePerKeg)
          {
               if (beerRemainder == 0)
               { beerKegs = beerRemainder; }
               else if (beerPeople < peoplePerKeg)
               { beerKegs = 1; }
               else 
               { beerKegs = beerRemainder + 1; }
          }
          
          if (dietCokePeople == 0)
          { dietCokeCases = 0; }
          else if ((dietCokePeople > 0) && (dietCokePeople <= peoplePerCase))
          { dietCokeCases = 1; }
          else if (dietCokePeople > peoplePerCase)
          {
               if (dietCokeRemainder == 0)
               { dietCokeCases = dietCokeRemainder; }
               else if (dietCokePeople < peoplePerCase)
               { dietCokeCases = 1; }
               else
               { dietCokeCases = dietCokeRemainder + 1; }
          }
          
          printf("\n\nYou have to buy\n\t%d Kegs of Beer\n\t%d Cases of Diet Coke\n",beerKegs,dietCokeCases);
          printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
          return (welcome());
     }
}

void foodOrder()
{
     char phantom;
         
     if (allPeople == 0)
     {
          printf("There is no inveted guest!\nPlease select 'a' in menu option to determine the number of guests\n");
          printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
          welcome();
          }
     else
     {
         int pizzaRemainder;
         pizzaRemainder = allPeople / peoplePerPizza;
         
         if (pizzaRemainder == 0)
         { pizzas = pizzaRemainder; }
         else if (allPeople < peoplePerPizza)
         { pizzas = 1; }
         else 
         { pizzas = pizzaRemainder + 1; }
         
         printf("\n\nFor %d Guests, You have to buy\n\t%d Pizzas\n",allPeople,pizzas);
         printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
         return (welcome());
     }
}

void displayAll()
{
     printf("\nThe number of people having been invited is %d\n",allPeople);
     printf("\nGoods required to purchase;\n\n");
     printf("\t%d Kegs of Beer.\n\t%d Cases of Diet Coke.\n\t%d Pizzas.\n",beerKegs,dietCokeCases,pizzas);
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
     return (welcome());
}

void bye()
{
     printf("\nThe Party Planning Assistant has been ended\n");
}



