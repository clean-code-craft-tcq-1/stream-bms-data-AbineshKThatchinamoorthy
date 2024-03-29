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
 
/*---------------------------------------------------------------------------*/
/*     FUNCTION: readFileData_e()
 */
/*!    \brief    Reads & Stores the BMS sensor data from SensorData.txt file
 *
 *     \param    NIL
 *
 *     \returns  BmsTransOpMdSts - Status of the Read Operation
 *//*------------------------------------------------------------------------*/
StreamOpSts_t readFileData_e(char const* filePath_p)
{
  float socVal_f;
  float temperatureVal_f;
  StreamOpSts_t streamOpSts_s;
 
  FILE * sensorIpFile_p = fopen(filePath_p,"r");  
 
  streamOpSts_s.readSts_e   = OP_MODE_STATUS_INIT;
  streamOpSts_s.streamSts_e = OP_MODE_STATUS_INIT;
  streamOpSts_s.streamedDataLen_i  = 0;
  
  if (NULL != sensorIpFile_p) {
    printf("File Open is SUCCESSFUL !!!\n");
    for(streamOpSts_s.streamedDataLen_i  = 0;fscanf(sensorIpFile_p, "%f\t\t%f\n", &temperatureVal_f,&socVal_f)!=EOF ;streamOpSts_s.streamedDataLen_i ++)
    {
        streamOpSts_s.streamSts_e = sendDataToConsole_e(temperatureVal_f, socVal_f);
    }
    streamOpSts_s.readSts_e   = OP_MODE_STATUS_SUCCESSFUL;
   }
  else {
    printf("File Open is FAILED !!!\n Please check the validity of the PATH or FILE.\n");
    streamOpSts_s.readSts_e = OP_MODE_STATUS_FAILED;
  }
  
  return streamOpSts_s;
}/* EO readFileData_e */

/*---------------------------------------------------------------------------*/
/*     FUNCTION: sendDataToConsole_e()
 */
/*!    \brief    Sends the BMS data(read from SensorData.txt) to console
 *
 *     \param    NIL
 *
 *     \returns  BmsTransOpMdSts_t - Status of the Stream Operation
 *//*------------------------------------------------------------------------*/
BmsTransOpMdSts_t sendDataToConsole_e(float temperatureVal_f, float socVal_f)
{
  BmsTransOpMdSts_t streamSts_e;
 
  printf("%f %f\n", temperatureVal_f,socVal_f);
  streamSts_e = OP_MODE_STATUS_SUCCESSFUL;/* There could be no failure when sending to console */
 
  return streamSts_e;
}/* EO sendDataToConsole_e */

/*---------------------------------------------------------------------------*/
/*     FUNCTION: initiateStream_e()
 */
/*!    \brief    Initiate the Stream operation is user request is active
 *
 *     \param    boolean streamDataReq_b - Stream request from User
 *                       0 - Not requested
 *                       1 - Stream requested
 *     \returns  StreamOpSts_t - Final Status of Stream Operation
 *//*------------------------------------------------------------------------*/
StreamOpSts_t initiateStream_e(bool streamDataReq_b)
{
 StreamOpSts_t streamOpSts_s;
 char filePath[100] = "./BMS_Sender/SensorData.txt";
  
  streamOpSts_s.readSts_e   = OP_MODE_STATUS_INIT;
  streamOpSts_s.streamSts_e = OP_MODE_STATUS_INIT;
  streamOpSts_s.streamedDataLen_i = 0;
 
 if(streamDataReq_b)
 {
   streamOpSts_s = readFileData_e(filePath);
 }
 return streamOpSts_s;
} /* EO initiateStream_e */

/* EOF*/
