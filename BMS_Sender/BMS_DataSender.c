/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-IS - All Rights Reserved     *****
******************************************************************************/
/*!
***     \file        BMS_DataSender.c
***
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***
\par    File_description
***                  Implementation of BMS data streaming to console
*\n*/
/*********************************************************************************/


/* INCLUSIONS */
#include <stdio.h>

Bms_DataTransSts readSensorData_e()
{
  Bms_DataTransSts readSts_e;
  BMSParams_t battParams_e;
  FILE * SensorIpFile = fopen("./BMS_Sender/SensorData.txt","r");  
  
  if (NULL != SensorIpFile) {
    printf("File Open is SUCCESSFUL !!!\n");
        for(int cnt_i = 0;fscanf(SensorIpFile, "%f\t\t%f\n", &temperatureVal,&socVal)!=EOF ;cnt_i++)
        {
            battParams_e.bmsTempVal_i[cnt_i] = temperatureVal;
            battParams_e.bmsSOCVal_i[cnt_i]  = socVal;
        }		
   }
  else {
    printf("File Open is FAILED !!!\n Please check the validity of the PATH or FILE.\n");
  }
  
  return readSts_e;
}
