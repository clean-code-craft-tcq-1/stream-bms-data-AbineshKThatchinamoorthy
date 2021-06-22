/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-IS - All Rights Reserved     *****
******************************************************************************/
/*!
***     \file        BMS_receiver.h
***
***     \author      Pratik Jaiswal
***
\par    File_description
***                  Header for the BMS data receiving source file
*\n*/
/*********************************************************************************/

/* ******************************Inclusions************************************ */

#include "BMS_receiver.h"
#include <stdio.h>

/* Function Details *******************************************************************************************
* Function Name : ReadData
* Description   : Reads the Data from the the sender
* Arguments     : DatafromConsole(char)
* Returns       : bool if the reading is successfull and the character is not NULL
* *********************************************************************************************************** */

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
/* Function Details *******************************************************************************************
* Function Name : GetValue
* Description   : receives value from console and stores it
* Arguments     : (char) _getvalue, (float) Value_
* Returns       : void
* *********************************************************************************************************** */
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
/* Function Details *******************************************************************************************
* Function Name : _ReadReceiver
* Description   : reads the value and stores the maximum,min value
* Arguments     : -
* Returns       : -
* *********************************************************************************************************** */
void _ReadReceiver()
{
  char DatafromConsole[datalen];
  float MinVal[datalen] = {TEMPMIN, SOCMIN};
  float MaxVal[datalen] = {TEMPMAX,SOCMAX };
  int Counter = 0;
  /* Reading the input stream */
  for (Counter = 0; Counter < datalen; Counter++) {
    
    /* Read one input set if the read is successful process parameters further*/
    bool IsOk = ReadData(DatafromConsole);
    if (IsOk)
    {
      
      float Value_[datalen] ;
      GetValue(DatafromConsole, Value_);
     
      for (int Countparam = 0; Countparam< datalen; Countparam++) {
        FindMinVal(&Value_[Countparam], &MinVal[Countparam]);
        FindMaxVal(&Value_[Countparam], &MaxVal[Countparam]);
    }
      printf(" Minumum Temperature : %f, Minimum SOC : %f \n ", MinVal[Temperature], MinVal[SOC]);
      printf(" Maximum Temperature : %f, Maximum SOC : %f \n ", MaxVal[Temperature], MaxVal[SOC]);
    }

  }
  
}
/* Function Details *******************************************************************************************
* Function Name : FindMinVal
* Description   : Checks the current value with the Previous min value
* Arguments     : Val_rx(float), MinVal(float)
* Returns       : current_value(float) or prev_maxi(float) which is greater
* *********************************************************************************************************** */
void FindMinVal(float *Val_rx, float *MinVal) {
   
   
    if (*MinVal > *Val_rx)
    {
      *MinVal = *Val_rx;

    }
}
/* Function Details *******************************************************************************************
* Function Name : FindMaxVal
* Description   : Checks the current value with the Previous ax value
* Arguments     : Val_rx(float), MaxVal(float)
* Returns       : Val_rx(float) or prev_maxi(float) which is greater
* *********************************************************************************************************** */
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
