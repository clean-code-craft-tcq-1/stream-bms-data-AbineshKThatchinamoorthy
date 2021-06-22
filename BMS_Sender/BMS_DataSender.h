/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-IS - All Rights Reserved     *****
******************************************************************************/
/*!
***     \file        BMS_DataSender.h
***
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***
\par    File_description
***                  Header for the BMS data streaming source file
*\n*/
/*********************************************************************************/

/* Inclusions */
#include <stdio.h>

/* Type definitions */
/* Enum for Operational Status */
typedef enum
{
   OP_MODE_STATUS_INIT,
   OP_MODE_STATUS_FAILED,
   OP_MODE_STATUS_SUCCESSFUL
}BmsTransOpMdSts_t;

/*Structure which contains the result of the operation */
typedef struct
{
   BmsTransOpMdSts_t readSts_e;
   BmsTransOpMdSts_t streamSts_e;
   int streamedDataLen_i;
}StreamOpSts_t;



/* Function declarations */
StreamOpSts_t initiateStream_e(bool streamDataReq_b);
StreamOpSts_t readFileData_e(char const* filePath_p);
BmsTransOpMdSts_t sendDataToConsole_e(float temperatureVal_f, float socVal_f);
