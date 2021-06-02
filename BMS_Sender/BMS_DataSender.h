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
typedef enum
{
   OP_MODE_STATUS_INIT,
   OP_MODE_STATUS_FAILED,
   OP_MODE_STATUS_SUCCESSFUL
}BmsTransOpMdSts_t;

typedef struct
{
   BmsTransOpMdSts readSts_e,
   BmsTransOpMdSts streamSts_e
}StreamOpSts_t;



/* Function declarations */
void initiateStream_v(bool streamDataReq_b);
BmsTransOpMdSts readFileData_e(void);
void sendDataToConsole_v(float temperatureVal_f, float socVal_f);
