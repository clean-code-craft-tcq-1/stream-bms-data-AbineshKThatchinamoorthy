#include "BMS_receiver.h"
#include <stdio.h>

#define lengthofParm 50
void getvalueFromsender(char *valuefromsender_get, float *tempValue);

void ReadData(char *DatafromConsole)
{
        if(DatafromConsole!=NULL)
        {
		    scanf("%s",DatafromConsole);
		    i = strtod(DatafromConsole,NULL);
  
		    DatafromConsole[i] = '\n';
		    DatafromConsole[i + 1] = '\0';
		    printf("DatafromConsole = %f\n", DatafromConsole); 
                      
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

void getvalueFromsender(char *_getvalue, float *Value_)
{
  int i = 0, j = 0; 
  char par[lengthofParm]; 
  int parNum = 0;  //count of parameters
    for (j = 0;_getvalue[i] != NULL;j++, i++)
    {
    par[j] = _getvalue[i];
    par[j] = '\0'; 
    }
    /* Convert string to float number to evaluate further */
    Value_[parNum] = atof(par);
    printf("Paramter value = %f\n", Value_[parNum]); 

}
                      
 int main()
 {
         char *s = "hello receiver";
         ReadData();
         return 0;
 }
