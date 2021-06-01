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


/* Enums */
typedef enum
{
	STATUS_FAILED,
	STARUS_SUCCESSFUL
}Bms_DataTransSts;

Bms_DataTransSts readSensorData_e(void);
