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
  BMSParams_t battParams_e;
  FILE * sensorIpFile = fopen("./BMS_Sender/SensorData.txt","r");  
  
  if (NULL != SensorIpFile) {
    printf("File Open is SUCCESSFUL !!!\n");
    for(int cnt_i = 0;fscanf(sensorIpFile, "%f\t\t%f\n", &temperatureVal,&socVal)!=EOF ;cnt_i++)
    {
        battParams_e.bmsTempVal_i[cnt_i] = temperatureVal;
        battParams_e.bmsSOCVal_i[cnt_i]  = socVal;
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
  
  return streamSts_e;
}
