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
  FILE * SensorIpFile = fopen("./BMS_Sender/SensorData.txt","r");  
  
  if (NULL != SensorIpFile) {
        for(int cnt = 0;fscanf(SensorIpFile, "%f\t\t%f\n", &TemperatureTemp,&StateOfChargeVal)!=EOF ;cnt++)
        {

        }		
   }
  else {
    printf("File open attempt failed\n");
  }
  
  return readSts_e;
}
