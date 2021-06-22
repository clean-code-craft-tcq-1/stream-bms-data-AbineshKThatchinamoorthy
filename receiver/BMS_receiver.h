#ifndef BMS_RECEIVER_H
#define BMS_RECEIVER_H

/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-IS - All Rights Reserved     *****
******************************************************************************/
/*!
***     \file        BMS_receiver.h
***
***     \author      Pratik Jaiswal
***
\par    File_description
***                  Header for the BMS data receiving source file
*\n*/
/*********************************************************************************/

/* ******************************Inclusions************************************ */
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define datalen 50
/* ******************************Macros************************************ */

#define TEMPMAX  45.0f
#define TEMPMIN  0.0f

#define SOCMAX  0.8f
#define SOCMIN  0.0f

/* ******************************Enumerations************************************ */

typedef enum Entity
{
  Temperature,
  SOC
}Entity;
/* ******************************Function Declarations************************************ */

void GetValue(char *_getvalue, float *Value_);
void FindMinVal(float *Val_rx, float *MinVal);
void FindMaxVal(float *Val_rx, float *MaxVal);
void _ReadReceiver();
bool ReadData(char *DatafromConsole);


#endif
