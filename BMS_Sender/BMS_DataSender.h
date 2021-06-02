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


/* MACROS */


/* Type definitions */
typedef enum
{
	STATUS_FAILED,
	STARUS_SUCCESSFUL
}Bms_DataTransSts;

typedef struct {
    float bmsTempVal_f[];  
    float bmsSOCVal_f[];
}BMSParams_t;

Bms_DataTransSts readSensorData_e(void);
