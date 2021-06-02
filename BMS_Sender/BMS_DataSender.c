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
  Bms_DataTransSts readSts_e   = OP_MODE_STATUS_INIT;
  Bms_DataTransSts streamSts_e = OP_MODE_STATUS_INIT;
 
  FILE * sensorIpFile_p = fopen("./BMS_Sender/SensorData.txt","r");  
  
  if (NULL != sensorIpFile_p) {
    printf("File Open is SUCCESSFUL !!!\n");
    for(int cnt_i = 0;fscanf(sensorIpFile_p, "%f\t\t%f\n", &temperatureVal,&socVal)!=EOF ;cnt_i++)
    {
        sendDataToConsole_e(temperatureVal, socVal);
    }
    readSts_e   = STATUS_SUCCESSFUL;
    streamSts_e = STATUS_SUCCESSFUL;
   }
  else {
    printf("File Open is FAILED !!!\n Please check the validity of the PATH or FILE.\n");
    readSts_e = OP_MODE_STATUS_FAILED;
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
Bms_DataTransSts sendDataToConsole_e(float temperatureVal_f, float socVal_f)
{
  printf("%f %f\n", temperatureVal_f,socVal_f);
}

/* EOF*/
