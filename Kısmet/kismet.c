/*
  Project    : KISMET GAME
  Author     : EMRE AKIN
  ID         : 1862547
  Date       : 12.04.2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  --------------------------------------------------------------------------- prototypes of functions
void roll (int);
int score ();
int basicScore (int);

//  --------------------------------------------------------------------------- definiing global variables

int dice1,dice2,dice3,dice4,dice5;
char dice1Color,dice2Color,dice3Color,dice4Color,dice5Color;
int scoreP1 = 0;
int scoreP2 = 0;
int kismetP1 = 0;
int kismetP2 = 0;
int basicScoreP1 = 0;
int basicScoreP2 = 0;

int main()
{
    int round = 1;
    int player;
    
    printf("WELCOME TO KISMET GAME\nGame begins...");
    
    //  ----------------------------------------------------------------------- counting game rounds
    
    while (round != 7)
    {
         player = 1;
         //  ------------------------------------------------------------------ switching between 2 players
         while (player != 3)
         {
              printf("\n\n-----------------------------------\nPlayer %d - Round %d\n-----------------------------------\n\n",player,round);
              
              roll(0);     //  ------------------------------------------------ rolling dices
              if (player == 1)
              {
                   kismetP1 = score();     //  -------------------------------- calculating Player 1 kismet score
                   basicScoreP1 = basicScore(round);    //  ------------------- calculating Player 1 basic score          
                   scoreP1 = scoreP1 + kismetP1 + basicScoreP1;    //  -------- calculating Player 1 total score
                   printf("\nYour basic score is %d and your kismet score is %d with a total %d!\n",basicScoreP1,kismetP1,scoreP1);
              }
              
              if (player == 2)
              {
                   kismetP2 = score();      //  -------------------------------- calculating Player 2 kismet score
                   basicScoreP2 = basicScore(round);     //  ------------------- calculating Player 2 basic score     
                   scoreP2 = scoreP2 + kismetP2 + basicScoreP2;   //  ---------- calculating Player 2 total score
                   printf("\nYour basic score is %d and your kismet score is %d with a total %d!\n",basicScoreP2,kismetP2,scoreP2);
              }
         
              player++;   //   changing player
         }
         round++;    //   changing round
    }
    
    //  ----------------------------------------------------------------------- showing final result
    if (scoreP1 > scoreP2)                    
    printf("\nTHE WINNER IS PLAYER 1!!!\n\n");
    
    if (scoreP1 < scoreP2)
    printf("\nTHE WINNER IS PLAYER 2!!!\n\n");
    
    system("PAUSE");
    return 0;
}

//  --------------------------------------------------------------------------- rolling fuction
void roll(int rollOneDice)
{
     char choice, phantom;
     srand(time(NULL));
     //  ---------------------------------------------------------------------- THIS IS a checking condition that is used when rolling ONLY ONE DICE!!
     if (rollOneDice == 1)   // ----------------------------------------------- rollOneDice is a check variable
     dice1 = (rand() % 6) + 1;
     else if (rollOneDice == 2)
     dice2 = (rand() % 6) + 1;
     else if (rollOneDice == 3)
     dice3 = (rand() % 6) + 1;
     else if (rollOneDice == 4)
     dice4 = (rand() % 6) + 1;
     else if (rollOneDice == 5)
     dice5 = (rand() % 6) + 1;
     
     else
     {   //  ------------------------------------------------------------------ here is assigning random numbers to ALL dices between 1-6
         dice1 = (rand() % 6) + 1;
         dice2 = (rand() % 6) + 1;
         dice3 = (rand() % 6) + 1;
         dice4 = (rand() % 6) + 1;
         dice5 = (rand() % 6) + 1;
     }
//  --------------------------------------------------------------------------- assigning color variable according to the dices..
     if (dice1 == 1 || dice1 == 6)
     dice1Color = 'b';
     if (dice1 == 2 || dice1 == 5)
     dice1Color = 'r';
     if (dice1 == 3 || dice1 == 4)
     dice1Color = 'g';
     
     if (dice2 == 1 || dice2 == 6)
     dice2Color = 'b';
     if (dice2 == 2 || dice2 == 5)
     dice2Color = 'r';
     if (dice2 == 3 || dice2 == 4)
     dice2Color = 'g';
     
     if (dice3 == 1 || dice3 == 6)
     dice3Color = 'b';
     if (dice3 == 2 || dice3 == 5)
     dice3Color = 'r';
     if (dice3 == 3 || dice3 == 4)
     dice3Color = 'g';
     
     if (dice4 == 1 || dice4 == 6)
     dice4Color = 'b';
     if (dice4 == 2 || dice4 == 5)
     dice4Color = 'r';
     if (dice4 == 3 || dice4 == 4)
     dice4Color = 'g';
     
     if (dice5 == 1 || dice5 == 6)
     dice5Color = 'b';
     if (dice5 == 2 || dice5 == 5)
     dice5Color = 'r';
     if (dice5 == 3 || dice5 == 4)
     dice5Color = 'g';
     
     //  ---------------------------------------------------------------------- printing dices and asking SCORE or ROLL..
     printf("Dice 1: %d\tDice 2: %d\tDice 3: %d\tDice 4: %d\tDice 5: %d\n\n",dice1,dice2,dice3,dice4,dice5);
     printf("Do you want to get a score or roll a dice (s/r)?\nCHOICE: ");
     scanf("%c%c",&choice,&phantom);
     
     if (choice == 'r')
     {   
          printf("Which dice you would like to roll again (1-5)?\nCHOICE: ");// asking a specific dice to roll it again.
          scanf("%d%c",&rollOneDice,&phantom);  //  --------------------------- phantom variable prevents errors (which occurs when taking a char in a loop)
          
          if (rollOneDice >= 1 && rollOneDice <= 5)
          {
               roll(rollOneDice);  //  ---------------------------------------- calling roll() function with THIS rollOneDice variable..
          }                        //                                           with this, only necessary dice is going to be rolled again.
          else
          {
               printf("WARNING: You had to enter a number between 1-5! Program is terminating.. \n");
               system("pause");
               exit(1);  //  -------------------------------------------------- exiting program If the user's input is not correct!!
          } 
     }
     
     else if (choice == 's')
     {}    //  ---------------------------------------------------------------- doing nothing here If user chooses 's', 
     else  //                                                                   score will be calculated later by calling score() function in main()
     {
         printf("WARNING: You must enter \'s\' or \'r\' to continue! Program is terminating.. \n");
         system("pause");
         exit(1);   //  ------------------------------------------------------- exiting program If the user's input is not correct!!
     }    
}


//  --------------------------------------------------------------------------- calculating basic score
int basicScore (int round)     //                                               that take a round variable which is used to find basic score acc
{                              //                                               according to the matching these two: Current Round and Any Dice Value
    int result = 0;
    
    if (round == dice1)
    result = result + dice1;
    
    if (round == dice2)
    result = result + dice2;
    
    if (round == dice3)
    result = result + dice3;
    
    if (round == dice4)
    result = result + dice4;
    
    if (round == dice5)
    result = result + dice5;
    
    return result;   
}



//  --------------------------------------------------------------------------- calculating score
int score ()
{
    int diceSum = dice1 + dice2 + dice3 + dice4 + dice5;
    int scorePlayer = 0;
    
    if (diceSum == 15 || diceSum == 20)
    {
         if ( (dice5 != dice4) && (dice4 != dice3) && (dice3 != dice2) && (dice2 != dice1) && (dice5 != dice3) && (dice3 != dice1) && (dice1 != dice5) && (dice2 != dice4)  && (dice2 != dice5) && (dice1 != dice4) )
         {
              printf("\nSCORE: Straight\n");
              scorePlayer = scorePlayer + 30;
         }
         
         else
         {
              printf("\nSCORE: Yarborough\n"); 
              scorePlayer = scorePlayer + diceSum;
         }
         
         
    }
    
    else if ( (dice1Color == dice2Color) && (dice2Color == dice3Color) && (dice3Color == dice4Color) && (dice4Color == dice5Color) )
    {
         printf("\nSCORE: Flush\n");
         scorePlayer = scorePlayer + 35;
    }
    
    else if ( (dice1 == dice2) && (dice2 == dice3) && (dice3 == dice4) && (dice4 == dice5) )
    {
         printf("\nSCORE: Kismet\n"); 
         scorePlayer = scorePlayer + 50 + diceSum;
    }
    
    else
    {
         printf("\nSCORE: Yarborough\n"); 
         scorePlayer = scorePlayer + diceSum;
    }

    return scorePlayer;
}









