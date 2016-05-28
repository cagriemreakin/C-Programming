#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <windows.h>

#define R 50

int main()
{
     int i, click, count = 0;
     int x, y, cx, cy;
     double distance;
     initwindow(800, 600);
     getdisplaycolor(GREEN);
     
     srand(time(NULL));
     while(1)
     {  
          x = rand() % 601;
          y = rand() % 601; 
          setcolor(rand() % 15); 
        //  printf("HELLo World");
          circle(x, y, 20);
          delay(3000);  
          if(ismouseclick(WM_LBUTTONDOWN))
          {
               getmouseclick(WM_LBUTTONDOWN, cx, cy);
               distance = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
               if(distance < R)
               {
                    printf("\a");
               }
               clearmouseclick(WM_LBUTTONDOWN);
          }
          cleardevice(); 
     } 
     closegraph();
     return 0;
}
