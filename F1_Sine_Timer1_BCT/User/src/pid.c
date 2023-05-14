// This file has been prepared for Doxygen automatic documentation generation.
/*! \file ********************************************************************
*
* Atmel Corporation
*
* - File              : pid.c
* - Compiler          : IAR EWAAVR 4.11A
*
* - Support mail      : avr@atmel.com
*
* - Supported devices : -
*
* - AppNote           : AVR221 - PID controller
*
* - Description       : General PID implementation for AVR
*
* $Revision: 1.2 $
* $Author: jtyssoe $, Atmel Corp.
* $Date: Thursday, November 10, 2005 10:10:48 UTC $
*****************************************************************************/

#include "pid.h"
#include "stdio.h"
/*! \brief Initialisation of PID controller parameters.
 *
 *  Initialise the variables used by the PID algorithm.
 *
 *  \param p_factor  Proportional term.
 *  \param i_factor  Integral term.
 *  \param d_factor  Derivate term.
 *  \param pid  Struct with PID status.
 */
void Init_PID(int p_factor, int i_factor, int d_factor, struct PID_DATA *pid)
// Set up PID controller parameters
{
  // Start values for PID controller
  pid->SUM_ERROR = 0;
  pid->LAST_PROCESS_VALUE = 0;
  // Tuning constants for PID loop
  pid->P_FACTOR = p_factor;
  pid->I_FACTOR = i_factor;
  pid->D_FACTOR = d_factor;
  // Limits to avoid overflow
  pid->MAX_ERROR = MAX_INT / (pid->P_FACTOR + 1 );
  pid->MAX_SUM_ERROR = MAX_INT / (pid->I_FACTOR + 1);
}


/*! \brief PID control algorithm.
 *
 *  Calculates output from setpoint, process value and PID status.
 *
 *  \param setPoint  Desired value.
 *  \param processValue  Measured value.
 *  \param pid_st  PID status struct.
 */
int PID(int setPoint, int processValue, struct PID_DATA *pid_st)
{
  int error, p_term, i_term, d_term;
  long ret, temp;

  error = setPoint - processValue;

  // Calculate Pterm and limit error overflow
  if(error > pid_st->MAX_ERROR)
    p_term = MAX_INT;
  else if(error < -pid_st->MAX_ERROR)
    p_term = -MAX_INT;
  else
    p_term = pid_st->P_FACTOR * error;

  // Calculate Iterm and limit integral runaway
  temp = (long)pid_st->SUM_ERROR + error;
  if(temp > pid_st->MAX_SUM_ERROR){
    i_term = MAX_INT;
    pid_st->SUM_ERROR = pid_st->MAX_SUM_ERROR;
  }
  else if(temp < -pid_st->MAX_SUM_ERROR){
    i_term = -MAX_INT;
    pid_st->SUM_ERROR = -pid_st->MAX_SUM_ERROR;
  }
  else
    pid_st->SUM_ERROR = temp;
    i_term = pid_st->I_FACTOR * pid_st->SUM_ERROR;

  // Calculate Dterm
  d_term = pid_st->D_FACTOR * (pid_st->LAST_PROCESS_VALUE - processValue);

  pid_st->LAST_PROCESS_VALUE = processValue;

  //ret = (((long)p_term + i_term + d_term))/128;
//  ret = (((long)p_term + i_term + d_term)) >> 7; // <--- scale back down (right shift seven bits = divide by 128)
  ret = (((long)p_term + i_term + d_term))/SCALING_FACTOR;
  if(ret > MAX_INT)
    ret = MAX_INT;
  else if(ret < -MAX_INT)
    ret = -MAX_INT;
  return((int)ret);
}

