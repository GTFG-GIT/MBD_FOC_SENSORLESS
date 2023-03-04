/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'MBD_FOC_SENSORLESS_MODEL'.
 *
 * Model version                  : 8.67
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar  4 11:06:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "MBD_FOC_SENSORLESS_MODEL.h"  /* Model header file */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlags[2] = { 0, 0 };

  static boolean_T eventFlags[2] = { 0, 0 };/* Model has 2 rates */

  static int_T taskCounter[2] = { 0, 0 };

  /* Disable interrupts here */

  /* Check base rate for overrun */
  if (OverrunFlags[0]) {
    rtmSetErrorStatus(MBD_FOC_SENSORLESS_MODEL_M, "Overrun");
    return;
  }

  OverrunFlags[0] = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  if (taskCounter[1] == 0) {
    if (eventFlags[1]) {
      OverrunFlags[0] = false;
      OverrunFlags[1] = true;

      /* Sampling too fast */
      rtmSetErrorStatus(MBD_FOC_SENSORLESS_MODEL_M, "Overrun");
      return;
    }

    eventFlags[1] = true;
  }

  taskCounter[1]++;
  if (taskCounter[1] == 30) {
    taskCounter[1]= 0;
  }

  /* Set model inputs associated with base rate here */

  /* Step the model for base rate */
  MbdFocSensorlessCurrentCtrl();

  /* Get model outputs here */

  /* Indicate task for base rate complete */
  OverrunFlags[0] = false;

  /* If task 1 is running, do not run any lower priority task */
  if (OverrunFlags[1]) {
    return;
  }

  /* Step the model for subrate */
  if (eventFlags[1]) {
    OverrunFlags[1] = true;

    /* Set model inputs associated with subrates here */

    /* Step the model for subrate 1 */
    MbdFocSpdCtrl();

    /* Get model outputs here */

    /* Indicate task complete for subrate */
    OverrunFlags[1] = false;
    eventFlags[1] = false;
  }

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  MbdFocSensorlessInit();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 5.0E-5 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(MBD_FOC_SENSORLESS_MODEL_M) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Terminate model */
  MBD_FOC_SENSORLESS_MODEL_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
