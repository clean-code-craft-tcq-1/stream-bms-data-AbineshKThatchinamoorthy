#include "BMS_receiver.h"
#include <stdio.h>

static int array_temp[10];
static int array_soc[10];
static char data[500];

void ReadData()
{
        if(DatafromConsole!=NULL)
        {
               // scanf("%s",DatafromConsole);
                printf("Hello/n");
                      
        }
        while (fgets(data, 500, stdin))
   {
	char * flag = strtok(data, "/n");
   	while( flag != NULL ) 
	{
		if(isdigit(*flag))
		{
			if(i<10)	
				array_temp[i] = atoi(flag);
			else
				array_soc[i] = atoi(flag);
			i++;
		}	
      		flag = strtok(NULL, "/n");
   	}
    }
}
                      
 int main()
 {
         char *s = "hello receiver";
         ReadData();
         return 0;
 }
