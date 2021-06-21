#include "BMS_receiver.h"
#include <stdio.h>


void ReadData(char *DatafromConsole)
{
        if(DatafromConsole!=NULL)
        {
                scanf("%s",DatafromConsole);
                printf("Hello/n");
                      
        }
}
                      
 int main()
 {
         char *s = "hello receiver";
         ReadData(s);
         return 0;
 }
