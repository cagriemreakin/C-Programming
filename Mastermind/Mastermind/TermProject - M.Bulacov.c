/* 1526235
   Mahmud Bulacov
   Term Project - THE MASTERMIND GAME
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void navigation();
void getNumber();
void generateNumber();
void scoreMeter(int);
void checkNumber();
void showScore();

int playerNum, computerNum;
int tries = 0, success = 0, failure = 0, countTries;

int main(void)
{
    intro();
    
    printf("\n\n");
    system("PAUSE");    
    return 0;
}

void intro(void)
{
    printf("\n\t---| WELCOME TO MASTERMIND |---\n\n");
    printf("GAME INFORMATION:\n\n  This is a guessing game between the computer and player.\n  The computer is going to generate a number between 0000 and 9999.\n");
    printf("\n  You have 10 rights to guess this number.\n  In each turn, it will show how many numbers you entered in right \n  and correct position, e.g. RESPONSE: (2,1)");
    printf("\n\nREADY TO PLAY? (Y/N): ");
    navigation();
}

void navigation()
{
    char choice;
    scanf("%c",&choice);
    getchar();
    switch (choice)
    {    
        case 'Y':
             generateNumber();
             countTries = 1;
             getNumber();
             break;
        case 'y':
             generateNumber();
             countTries = 1;
             getNumber();
             break;
        case 'N':
             showScore();
             system("pause");
             exit(0);
             break;
        case 'n':
             showScore();
             system("pause");
             exit(0);
             break;
        default:
             printf("\n  You must input proper entry (Y,y or N,n)\n\n==> ");
             navigation();
             break;
    }
}


void getNumber()
{   
    printf("\nEnter a number between 0000 and 9999.\nGUESS NUMBER: ");
    scanf("%d",&playerNum);
    if (playerNum < 0 || playerNum > 9999)
    {
         printf("WARNING: You entered wrong number!\n");
         getNumber();
    }
    checkNumber();
}

void generateNumber()
{
    srand(time(NULL));
    computerNum = rand() % 10000;
}

void scoreMeter(int check)
{
    switch (check)
    {
         case 1:
              tries++;
              break;
         case 2:
              success++;
              break;
         case 3:
              failure++;
              break;
         default:
              printf("FATAL ERROR!");
    }
}

void checkNumber()
{
    int digit1, digit2, digit3, digit4, guessDigit1, guessDigit2, guessDigit3, guessDigit4;
    int rightNum = 0, rightPlace = 0;
    
    digit1 = computerNum / 1000;
    digit2 = (computerNum % 1000) / 100;
    digit3 = (computerNum % 100) / 10;
    digit4 = (computerNum % 10);
    
    guessDigit1 = playerNum / 1000;
    guessDigit2 = (playerNum % 1000) / 100;
    guessDigit3 = (playerNum % 100) / 10;
    guessDigit4 = (playerNum % 10);
    
    if (digit1 == guessDigit1)
    rightPlace++;
    
    else if (guessDigit1 == digit2 && guessDigit2 != digit2)
         rightNum++;
    
    else if (guessDigit1 == digit3 && guessDigit3 != digit3)
         rightNum++;
       
    else if (guessDigit1 == digit4 && guessDigit4 != digit4)
         rightNum++;
        
    if (digit2 == guessDigit2)
    rightPlace++;     
    
    else if (guessDigit2 == digit1 && guessDigit1 != digit1)
         rightNum++;
    
    else if (guessDigit2 == digit3 && guessDigit3 != digit3)
         rightNum++;
    
    else if (guessDigit2 == digit4 && guessDigit4 != digit4)
         rightNum++;
    
    if (digit3 == guessDigit3)
    rightPlace++;
    
    else if (guessDigit3 == digit1 && guessDigit1 != digit1)
         rightNum++;
    
    else if (guessDigit3 == digit2 && guessDigit2 != digit2)
         rightNum++;
    
    else if (guessDigit3 == digit4 && guessDigit4 != digit4)
         rightNum++;
    
    if (digit4 == guessDigit4)
    rightPlace++;
    
    else if (guessDigit4 == digit1 && guessDigit1 != digit1)
         rightNum++;
    
    else if (guessDigit4 == digit2 && guessDigit2 != digit2)
         rightNum++;
    
    else if (guessDigit4 == digit3 && guessDigit3 != digit3)
         rightNum++;
    
    
    if (computerNum == playerNum)
    {
         scoreMeter(1);
         scoreMeter(2);
         printf("\nCONGRATULATIONS!\n\n  You have cracked the secret code!\n  Do you want to try another game?\n\n==> ");
         getchar();
         navigation();
    }
    
    if (countTries == 10)
    {
         scoreMeter(1);
         scoreMeter(3);
         printf("\nOK!\n\n  You have run out of tries. The answer is %4d. \n  Better luck next time! \n  Do you want to try again?\n\n==> ",computerNum);
         getchar();
         navigation();
    }
    
//    printf("\nCODE: %d\n",computerNum);
    printf("\n\nRESPONSE: (%d,%d)\n",rightPlace,rightNum);
    
    
    countTries++;
    getNumber();  
}

void showScore()
{
    printf("\n  You have tried Game of Mastermind %d times %d Successes and %d Failures\n\nEND!\n\n",tries,success,failure);
}
