/*
Name: Çaðrý Emre AKIN
ID: 1862457
Department: CNG

Decription:  Purble Shop is a code-breaker game, which aims to teach children memory, pattern recognition, and reasoning skills.
             In summary, in this game, the computer decides the color of up to five features (hat, eyes, nose, mouth and clothes)
             that are concealed from the player. Any color may be used for any feature, and a color can be used once, several times
             or not used at all. The player then attempts to deduce or guess the correct feature colors in a limited number of moves.
             There are two difficulty levels: Beginner with three features in three possible colors for 33 = 27 different possible 
             solutions and Advanced with 55 = 3125 solutions.
*/
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <time.h>

#define SIZE 8

void Menu ();
void MakeCode (int);
void Guess (int, int[]);
void CodeCheck (int, int[], int[], int*);
void DisplayGuess(int, int[], int, int, int*);

void FillColor (int, int);
void ClearColor ();
void PutButtons (int);

int main()
{
    printf("\n\t\t\t  ****PURBLE GAME****\n");
    
    initwindow(700,380,"Purble Game");
    outtextxy(438,50, "\a PURBLE GAME \a");
    
    setfillstyle(5,7);                   // head color
    fillellipse( 200, 125, 125, 100 );   // head
    
    ClearColor();
      
    Menu();
    
system("pause");
return 0;
}


void FillColor (int feature, int color)
{
    if (feature == 0)
    {
        setfillstyle(5,color);               // hat color
        fillellipse( 200, 35, 75, 20 );      // hat
    }
    
    else if (feature == 1)
    {
        setfillstyle(5,color);               // eyes color
        fillellipse( 160, 100, 15, 15 );     // eyes
        fillellipse( 240, 100, 15, 15 );     // eyes
    }
    
    else if (feature == 2)
    {
        setfillstyle(10,color);              // nose color
        fillellipse( 200, 135, 22, 22 );     // nose
    }
    
    else if (feature == 3)
    {
        setfillstyle(8,color);               // mouth color
        fillellipse( 200, 185, 50, 15 );     // mouth
    }
    
    else if (feature == 4)
    {
        setfillstyle(5,color);               // body color
        bar (175,225,225,300);               // body
        
        setfillstyle(4,color);               // hand and foot color
        bar (164,230,174,250);               // left hand
        bar (226,230,236,250);               // right hand
        
        bar (164,295,174,315);               // left foot
        bar (226,295,236,315);               // right foot
    }
    
}


void ClearColor ()
{
    setfillstyle(5,15);                  // body color
    bar (175,225,225,300);               // body
    
    setfillstyle(4,15);                  // hand and foot color
    bar (164,230,174,250);               // left hand
    bar (226,230,236,250);               // right hand
    
    bar (164,295,174,315);               // left foot
    bar (226,295,236,315);               // right foot

    setfillstyle(4,15);                  // hat color
    fillellipse( 200, 35, 75, 20 );      // hat
    
    setfillstyle(8,0);                   // eyes color
    fillellipse( 160, 100, 15, 15 );     // eyes
    fillellipse( 240, 100, 15, 15 );     // eyes
    
    setfillstyle(10,15);                 // nose color
    fillellipse( 200, 135, 22, 22 );     // nose
    
    setfillstyle(8,0);                   // mouth color
    fillellipse( 200, 185, 50, 15 );     // mouth
         
}


void PutButtons (int level)
{
    // ---------------------------------------------------------------------
    //  Buttons
    if (level == 5)
    {
        setfillstyle(1,4);                  // red button
        fillellipse( 400, 100, 20, 20 );   
    
        setfillstyle(1,2);                  // green button
        fillellipse( 450, 100, 20, 20 );   
        
        setfillstyle(1,1);                  // blue button
        fillellipse( 500, 100, 20, 20 );   
        
        setfillstyle(1,5);                  // purple button
        fillellipse( 550, 100, 20, 20 );   
    
        setfillstyle(1,14);                 // yellow button
        fillellipse( 600, 100, 20, 20 );   
    }
    
    if (level == 3)
    {
        setfillstyle(1,4);                  // red button
        fillellipse( 400, 100, 20, 20 );   
    
        setfillstyle(1,2);                  // green button
        fillellipse( 450, 100, 20, 20 );   
        
        setfillstyle(1,1);                  // blue button
        fillellipse( 500, 100, 20, 20 );   
        
        setfillstyle(0,0);                  // purple button
        fillellipse( 550, 100, 20, 20 );   
    
        setfillstyle(0,0);                 // yellow button
        fillellipse( 600, 100, 20, 20 );   
    }
    
    
    
}



void Menu()
{
     char level[SIZE];
     char levelBeg[]="beginner";
     char levelAdv[]="advance";
     char ch;      
     int i = 0,j = 0;
     int checkBeg = 0, checkAdv = 0;
     int levelSign = 0;
     
     printf("\nDo you want to play beginner or advance level (beginner/advance)? :");
     
     while ((ch = getchar()) !=  '\n')
     {
         level[i] = ch;
         i++;
     }
     level[i] = '\0';
     
     for (i = 0; i < SIZE; i++)
     { 
          if ( level[i] != levelBeg[i] )
              checkBeg = 1;
              

          if ( level[i] != levelAdv[i] )
              checkAdv = 1;
              
     }
     
     if (checkBeg == 0)
          levelSign = 3;
     if (checkAdv == 0)
          levelSign = 5;
     
     if (levelSign == 0)
     {
          printf("\a\nWARNING: You should enter \'beginner\' or \'advance\'\n");
          Menu();
     }    
     else
     {
          ClearColor();                      // Clearing all color
          PutButtons(levelSign);             // putting buttons according to the level
          MakeCode(levelSign);
     }
         
}

void MakeCode (int level)
{     
     int i;
     
     srand(time(NULL));
     
     int code[level];
     
     for (i = 0; i < level; i++)
     {
         code[i] = 1 + (rand() % level);
         printf("%d",code[i]);
     }
    
 //    int code[5] = { 1,1,1,1,1 };
     
     printf("\n\n");
     
     Guess(level,code);
}


void Guess (int level, int code[])
{
     static int guessNum = 1;
     int i = 0, j;
     int guess[level];
     char selection;
     int x,y;
     
     outtextxy(410,150, "Now, Let\'s make your guess!");     
     
     if (guessNum == 13)
     {
         printf("\n\nYou have made 12 guesses already! You lost!\n\n");
         outtextxy(380,180, "GAME OVER! You have lost the game");
         printf("\nWould you like to play again? (Y/N): ");
         fflush(stdin);
         scanf("%c",&selection);
         fflush(stdin);
         if (selection == 'Y' || selection == 'y')
         {
              guessNum = 1;
              Menu();
         }
         else if (selection == 'N' || selection == 'n')
         {
              printf("\n");
              system("pause");
              exit(1);     
         }
         else
         {
              printf("\aWARNING: you should enter \'Y\' or \'N\'\n");
              Guess(level,code);
         }
     }
     
     printf("\nGuess %d:\n------------\n",guessNum);
     
     while (i != level)
     {
         switch (i)                               // according to i value (which goes to level), automatically running correct printf function..
         {
              case 0:
                   printf("Enter your guess for hat");
                   break;
                   
              case 1:
                   printf("Enter your guess for eyes");
                   break;
                   
              case 2:
                   printf("Enter your guess for nose");
                   break; 
                   
              case 3:
                   printf("Enter your guess for mouth");
                   break;
                   
              case 4:
                   printf("Enter your guess for clothes");
                   break; 
         }
         FillColor(i,11);                                            // changing color of current feature
         
         if (level == 5)                                             // according to level, running correct printf function..
         printf(" (1:red, 2:green, 3:blue, 4:purple, 5:yellow): ");
         else
         printf(" (1:red, 2:green, 3:blue): ");
         
         while (1)                                                  // taking mouse clicks or running scanf function
         {            
                guess[i] = -1;
    // ---------------------------------------------------------------------------------------------------------  
    // NOTICE:  Make "Comment" here, If you want to use Mouse while guessing          
    
    // <== REMOVE HERE              /*         
    
                if ( scanf("%d",&guess[i]) != -1 )
                {
                     if (guess[i] > level)
                     continue;
                     
                     else
                     {
                         clearmouseclick(WM_LBUTTONDOWN);     
                         break;
                     }
                }
                
    //                      */
    // ---------------------------------------------------------------------------------------------------------  
    
                if ( ismouseclick(WM_LBUTTONDOWN) )
                {
                      x = mousex();
                      y = mousey();
                      
                      if ( ( (x >= 380 && x <= 420) && (y >= 80 && y <= 120) )  ||
                           ( (x >= 430 && x <= 470) && (y >= 80 && y <= 120) )  ||
                           ( (x >= 480 && x <= 520) && (y >= 80 && y <= 120) )  ||
                           ( (x >= 530 && x <= 570) && (y >= 80 && y <= 120) && level == 5 )  ||
                           ( (x >= 580 && x <= 620) && (y >= 80 && y <= 120) && level == 5 )  )
                      {
                                                 
                           clearmouseclick(WM_LBUTTONDOWN);      // if user clicks on correct place (buttons), take it..
                           break;
                      }
                      else
                      {
                           clearmouseclick(WM_LBUTTONDOWN);      // if user clicks on anywhere except buttons, wait to be clicked correctly..
                           continue;
                      }
                }
                

         }
      
                                                                   // Assigning guess[] array values according to the coordinates of mouse clicks
         if ( (x >= 380 && x <= 420) && (y >= 80 && y <= 120) )
         guess[i] = 1;
         if ( (x >= 430 && x <= 470) && (y >= 80 && y <= 120) )
         guess[i] = 2;
         if ( (x >= 480 && x <= 520) && (y >= 80 && y <= 120) )
         guess[i] = 3;
         if ( (x >= 530 && x <= 570) && (y >= 80 && y <= 120) )
         guess[i] = 4;
         if ( (x >= 580 && x <= 620) && (y >= 80 && y <= 120) )
         guess[i] = 5;
         
         
         if (guess[i] != -1)                                    
         printf("%d\n",guess[i]);                                  // this runs when Mouse is used.. 
    
         if (guess[i] == 1)                                        // Calling FillColor() function according to the guesses..
         FillColor(i,4);
         if (guess[i] == 2)
         FillColor(i,2);
         if (guess[i] == 3)
         FillColor(i,1);
         if (guess[i] == 4)
         FillColor(i,5);
         if (guess[i] == 5)
         FillColor(i,14);
           
         i++;                                                    // increasing i, which goes to level
     }
     guessNum++;                                                 // increasing guessNum
     
     CodeCheck(level,code,guess,&guessNum);                      // continue through CodeCheck()
}



void CodeCheck (int level, int code[], int guess[], int *guessNum)
{
     int i,j;
     int check[level];
     int colorCheck = 0;
     int rightColorRightFeature = 0;
     int rightColorWrongFeature = 0;
     
     for (i = 0; i < level; i++)
     {
          if ( code[i] == guess[i] )
          {
               rightColorRightFeature++;
               check[i] = 1;
          }
          else
          check[i] = 0;
     }
     
     
     for (i = 0; i < level; i++)
     {
          colorCheck = 0;
          for (j = 0; j < level; j++)
          {
               if ( code[j] == guess[i] && check[j] == 0 && check[i] == 0)
               colorCheck = 1;
          }
          
          if (colorCheck == 1)
          rightColorWrongFeature++;
     }
          
     
     DisplayGuess(level, code, rightColorRightFeature, rightColorWrongFeature, guessNum);
}



void DisplayGuess(int level, int code[], int rightColorRightFeature, int rightColorWrongFeature, int *guessNum)
{
     char selection;
     
     if (rightColorRightFeature != level )
     {    
          printf("\nYour Score:\n");
          printf("\nRight Color, Right Feature: %d",rightColorRightFeature);
          printf("\n\nRight Color, Wrong Feature: %d\n",rightColorWrongFeature);
          system("pause");
          Guess(level,code);
     }
     else
     {
          printf("\n\n!!!!!! CONGRATULATIONS! You have won the game with %d Guesses !!!!!!\n\n",*guessNum - 1);
          outtextxy(365,180, "CONGRATULATIONS! You have won the game");     
          
          do
          {
              fflush(stdin);
              printf("\nWould you like to play again? (Y/N): ");
              scanf("%c",&selection);
              fflush(stdin);
          
              if (selection == 'Y' || selection == 'y')
              {
                   *guessNum = 1;
                   Menu();
              }
              else if (selection == 'N' || selection == 'n')
              {
                   printf("\n");
                   system("pause");
                   exit(1);     
              }
              else
              {
                   printf("\aWARNING: you should enter \'Y\' or \'N\'\n");
              }
          }while (selection != 'Y' && selection != 'y' && selection != 'N' && selection != 'n');
     }
}
























