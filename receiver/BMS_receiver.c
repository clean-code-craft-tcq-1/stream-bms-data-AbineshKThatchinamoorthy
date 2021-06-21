#include "BMS_receiver.h"
#include <stdio.h>

#define datalen 50

#define TemperatureMax  45.f
#define TemperatureMin  0.f

#define SocMAX  0.8f
#define SOcMin  0.f

typedef enum Entity
{
  Temperature,
  SOC
}Entity;

void GetValue(char *valuefromsender_get, float *tempValue);
void calculateMinValue(float *paramValue, float *paramValueMin);
void calculateMaxValue(float *paramValue, float *paramValueMax);
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
		    printf("DatafromConsole = %f\n", DatafromConsole); 
		return true
                      
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
  float paramMin[datalen] = {TemperatureMin, SocMin};
  float paramMax[datalen] = {TemperatureMax,SocMAX };
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

void calculateMinValue(float *paramValue, float *paramValueMin) {
   
   
    if (*paramValueMin > *paramValue)
    {
      *paramValueMin = *paramValue;

    }
}

void calculateMaxValue(float *paramValue, float *paramValueMax) {
 
  if (*paramValueMax < *paramValue)
  {
    *paramValueMax = *paramValue;
  }
}                      
 int main()
 {
        _ReadReceiver();
         return 0;
 }
