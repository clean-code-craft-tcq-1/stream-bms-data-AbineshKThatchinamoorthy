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

BMSParams_t battParams_e;

/*---------------------------------------------------------------------------*/
/*     FUNCTION: readSensorData_e()
 */
/*!    \brief    Reads & Stores the BMS sensor data from SensorData.txt file
 *
 *     \param    NIL
 *
 *     \returns  Bms_DataTransSts - Status of the Read Operation
 *//*------------------------------------------------------------------------*/
Bms_DataTransSts readSensorData_e()
{
  Bms_DataTransSts readSts_e = STATUS_FAILED;
 
  FILE * sensorIpFile = fopen("./BMS_Sender/SensorData.txt","r");  
  
  if (NULL != SensorIpFile) {
    printf("File Open is SUCCESSFUL !!!\n");
    for(int cnt_i = 0;fscanf(sensorIpFile, "%f\t\t%f\n", &temperatureVal,&socVal)!=EOF ;cnt_i++)
    {
        battParams_e.bmsTempVal_f[cnt_i] = temperatureVal;
        battParams_e.bmsSOCVal_f[cnt_i]  = socVal;
    }
    readSts_e = STARUS_SUCCESSFUL;
   }
  else {
    printf("File Open is FAILED !!!\n Please check the validity of the PATH or FILE.\n");
  }
  
  return readSts_e;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: sendDataToConsole_e()
 */
/*!    \brief    Sends the BMS data(read from SensorData.txt) to console
 *
 *     \param    NIL
 *
 *     \returns  Bms_DataTransSts - Status of the Stream Operation
 *//*------------------------------------------------------------------------*/
Bms_DataTransSts sendDataToConsole_e()
{
  Bms_DataTransSts streamSts_e = STATUS_FAILED;
  int dataLen_i = sizeof(battParams_e.bmsTempVal_f) / sizeof(float)
    
  for(int index_i=0; index_i < dataLen_i; index_i++)
  {
     printf("Dataset %d \n", index_i);
     printf("Temperature : %f\n", battParams_e.bmsTempVal_f[index_i]);
     printf("State of Charge : %f\n", battParams_e.bmsSOCVal_f[index_i]);
  }
  
  return streamSts_e;
}

/* EOF*/
