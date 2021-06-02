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


/* Inclusions */
#include "BMS_DataSender.h"

/* Funcation declarations */
void sendDataToConsole_v(float temperatureVal_f, float socVal_f);
 
/*---------------------------------------------------------------------------*/
/*     FUNCTION: readFileData_e()
 */
/*!    \brief    Reads & Stores the BMS sensor data from SensorData.txt file
 *
 *     \param    NIL
 *
 *     \returns  BmsTransOpMdSts - Status of the Read Operation
 *//*------------------------------------------------------------------------*/
BmsTransOpMdSts readFileData_e()
{
  float socVal_f;
  float temperatureVal_f;
  BmsTransOpMdSts readSts_e   = OP_MODE_STATUS_INIT;
  BmsTransOpMdSts streamSts_e = OP_MODE_STATUS_INIT;
 
  FILE * sensorIpFile_p = fopen("./BMS_Sender/SensorData.txt","r");  
  
  if (NULL != sensorIpFile_p) {
    printf("File Open is SUCCESSFUL !!!\n");
    for(int cnt_i = 0;fscanf(sensorIpFile_p, "%f\t\t%f\n", &temperatureVal_f,&socVal_f)!=EOF ;cnt_i++)
    {
        sendDataToConsole_v(temperatureVal_f, socVal_f);
    }
    readSts_e   = OP_MODE_STATUS_SUCCESSFUL;
    streamSts_e = OP_MODE_STATUS_SUCCESSFUL;
   }
  else {
    printf("File Open is FAILED !!!\n Please check the validity of the PATH or FILE.\n");
    readSts_e = OP_MODE_STATUS_FAILED;
  }
  
  return readSts_e;
}/* EO readFileData_e */

/*---------------------------------------------------------------------------*/
/*     FUNCTION: sendDataToConsole_e()
 */
/*!    \brief    Sends the BMS data(read from SensorData.txt) to console
 *
 *     \param    NIL
 *
 *     \returns  Bms_DataTransSts - Status of the Stream Operation
 *//*------------------------------------------------------------------------*/
void sendDataToConsole_v(float temperatureVal_f, float socVal_f)
{
  printf("%f %f\n", temperatureVal_f,socVal_f);
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: initiateDataStream_v()
 */
/*!    \brief    Initiate the Stream operation is user request is active
 *
 *     \param    boolean streamDataReq_b - Stream request from User
 *                       0 - Not requested
 *                       1 - Stream requested
 *     \returns  void
 *//*------------------------------------------------------------------------*/
void initiateStream_v(boolean streamDataReq_b)
{
 if(streamDataReq_b)
 {
   readFileData_e();
 }
}

/* EOF*/
