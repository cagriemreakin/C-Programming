#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 12


struct playerInfo
{
    char playerName[25];
    char position[2];
    float freethrowscored;
    float freethrowshots;
    float twopointsscored;
    float twopointsshots;
    float threepointsscored;
    float threepointsshots;
};

int readPlayer(FILE *, struct playerInfo []);
void displayPlayer(struct playerInfo []);
void savePlayer(struct playerInfo []);


int main()
{
    FILE *inFile;
    
    struct playerInfo numPlayer [SIZE];
    
    inFile=fopen("basketball.txt","r");
    
    if(inFile==NULL)
    {
       printf("The file was not successfully opened.");
       exit(1);                
    }    
    printf("file is opened successfully.\n");
    
    
    
    readPlayer(inFile,numPlayer);
    
    
    system("pause");
    return 0;
}


int readPlayer(FILE *fname,struct playerInfo numPlayer [])
{
    char entry [500];
    char temp [100];
    char line[500];
    char *ch;
    char *space = " ";
    int i = 0, j = 0, k = 0, count = 0;
    int nextPlace, prevPlace, colonCount;
    
  //   fgets(entry,500,fname); 
 //    printf("%s\n",entry);
    
    while (fscanf(fname, "%s",line) != EOF)
    {
      //    printf("%s ",line);
         i = 0;
         
         while (line[i] != '\0')
         {
              entry[j] = line[i];
              i++;
              j++; 
         }
      //   printf("%d =====i\n",i);
         printf("%s\n\n",line);
         entry[j] = ':';
         j++;
         entry[j] = '\0';
        
    }
  printf("%s\n\n",entry);
    
     ch = strtok(entry,":");
    while (  ch != NULL && k < 12)
    {
        count = 0;
       
        while (count != 9)
        {
            switch(count)
            {
               case 0:
                    printf("Check 1\n"); 
                    strcpy(numPlayer[k].playerName,ch);
                    break;          
               case 1:
                    printf("Check 1\n"); 
                    strcat(numPlayer[k].playerName,space);
                    strcat(numPlayer[k].playerName,ch);
                    break;
               case 2:
                    printf("Check 2\n");
                    strcpy(numPlayer[k].position,ch);
                    break;
               case 3:
                    printf("Check 3\n");

                    strcpy(temp,ch);
                    numPlayer[k].freethrowscored = atoi(temp);
                    break;
               case 4:
                    printf("Check 4\n");

                    strcpy(temp,ch);
                    numPlayer[k].freethrowshots = atoi(temp);
                    break;
               case 5:
                    printf("Check 5\n");
                    strcpy(temp,ch);
                    numPlayer[k].twopointsscored = atoi(temp);
                    break;
               case 6:
                    printf("Check 6\n");

                    strcpy(temp,ch);
                    numPlayer[k].twopointsshots = atoi(temp);
                    break;
               case 7:
                    printf("Check 7\n");

                    strcpy(temp,ch);
                    numPlayer[k].threepointsscored = atoi(temp);
                    break;
               case 8:
                    printf("Check 8\n");
                    
                    strcpy(temp,ch);
                    numPlayer[k].threepointsshots = atoi(temp);
                    break;
            }
            
            count++;
            
            ch = strtok('\0',":");
        }
        printf("Check Loop\n");
        k++;
        printf("%d ",k);
        
        
 //       system("pause");
    }
    displayPlayer (numPlayer);
return k;
}


void displayPlayer (struct playerInfo numPlayer [])
{
    int i;
    float PointsScored, FreeThrow, TwoPoints, ThreePoints;
    printf("\nPlayer\t\t\tPoints Scored    Free Throw    TwoPoints   ThreePoints\t\n");
    
    for (i = 0; i < 12; i++)
    {
        PointsScored = (float) numPlayer[i].freethrowscored*1 + numPlayer[i].twopointsscored*2 + numPlayer[i].threepointsscored*3;
        FreeThrow = (float) numPlayer[i].freethrowscored / numPlayer[i].freethrowshots * 100;
        TwoPoints = (float) numPlayer[i].twopointsscored / numPlayer[i].twopointsshots * 100;
        ThreePoints = (float) numPlayer[i].threepointsscored / numPlayer[i].threepointsshots * 100;
    
        printf("%.15s\t\t",numPlayer[i].playerName);
        printf(" %3.2f\t\t",PointsScored);
        printf("  %3.2f\t\t",FreeThrow);
        printf("%3.2f\t",TwoPoints);
        printf("    %3.2f",ThreePoints);
        printf("\n");
    }    
    printf("\n");
    savePlayer (numPlayer);
}

void savePlayer (struct playerInfo numPlayer [])
{
     int count,l;
     char select;
     char phantom;
     char line[100];

     FILE *fname;
     
     fname = fopen("stats-12-dev-adam.txt","w");
    
     if (fname == NULL)
     {
          printf("Failed to open the file.\nCheck the file exist or not\n");
          system("PAUSE");
          exit(1);        
     }
     printf("The file is succesfully opened\n\n");
     
     int i;
     float PointsScored, FreeThrow, TwoPoints, ThreePoints;
    
  
     for (i = 0; i < 12; i++)
     {
          PointsScored = (float) numPlayer[i].freethrowscored*1 + numPlayer[i].twopointsscored*2 + numPlayer[i].threepointsscored*3;
          FreeThrow = (float) numPlayer[i].freethrowscored / numPlayer[i].freethrowshots * 100;
          TwoPoints = (float) numPlayer[i].twopointsscored / numPlayer[i].twopointsshots * 100;
          ThreePoints = (float) numPlayer[i].threepointsscored / numPlayer[i].threepointsshots * 100;
         
         
          fprintf(fname,"%.15s\t\t",numPlayer[i].playerName);
          fprintf(fname," %3.2f\t\t",PointsScored);
          fprintf(fname,"  %3.2f\t\t",FreeThrow);
          fprintf(fname,"%3.2f\t",TwoPoints);
          fprintf(fname,"    %3.2f\n",ThreePoints);
     
     }
     
     fclose(fname);
}

