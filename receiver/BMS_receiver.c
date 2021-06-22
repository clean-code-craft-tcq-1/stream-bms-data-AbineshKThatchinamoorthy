#include "BMS_receiver.h"
#include <stdio.h>

#define datalen 50

#define TEMPMAX  45.f
#define TEMPMIN  0.f

#define SOCMAX  0.8f
#define SOCMIN  0.f

typedef enum Entity
{
  Temperature,
  SOC
}Entity;

void GetValue(char *_getvalue, float *Value_);
void FindMinVal(float *Val_rx, float *MinVal);
void FindMaxVal(float *Val_rx, float *MaxVal);
void _ReadReceiver();

bool ReadData(char *DatafromConsole)
{
	int i=0;
        if(DatafromConsole!=NULL)
        {
		    scanf("%s",DatafromConsole);
		    i = strtod(DatafromConsole,NULL);
  
		    DatafromConsole[i] = '\n';
		    DatafromConsole[i + 1] = '\0';
		    printf("DatafromConsole = %s\n", DatafromConsole); 
		return true;
                      
        }
        return false;
   }

void GetValue(char *_getvalue, float *Value_)
{
  int i = 0, j = 0; 
  char par[datalen]; 
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

void _ReadReceiver()
{
  char DatafromConsole[datalen];
  float paramMin[datalen] = {TEMPMIN, SOCMIN};
  float paramMax[datalen] = {TEMPMAX,SOCMAX };
  int paramSetCounter = 0;
  /* Reading the input stream */
  for (paramSetCounter; paramSetCounter < datalen; paramSetCounter++) {
    
    /* Read one input set if the read is successful process parameters further*/
    bool IsOk = ReadData(DatafromConsole);
    if (IsOk)
    {
      
      float Value_[datalen] ;
      GetValue(DatafromConsole, Value_);
     
      for (int parameterCount = 0; parameterCount< datalen; parameterCount++) {
        calculateMinValue(&Value_[parameterCount], &paramMin[parameterCount]);
        calculateMaxValue(&Value_[parameterCount], &paramMax[parameterCount]);
    }
      printf(" Minumum Temperature : %f, Minimum SOC : %f \n ", paramMin[Temperature], paramMin[SOC]);
      printf(" Maximum Temperature : %f, Maximum SOC : %f \n ", paramMax[Temperature], paramMax[SOC]);
    }

  }
  
}

void FindMinVal(float *Val_rx, float *MinVal) {
   
   
    if (*MinVal > *Val_rx)
    {
      *MinVal = *Val_rx;

    }
}

void FindMaxVal(float *Val_rx, float *MaxVal) {
 
  if (*MaxVal < *Val_rx)
  {
    *MaxVal = *Val_rx;
  }
}                      
 int main()
 {
        _ReadReceiver();
         return 0;
 }
