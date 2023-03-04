/*
 * File: MBD_FOC_SENSORLESS_MODEL_private.h
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

#ifndef RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_private_h_
#define RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "MBD_FOC_SENSORLESS_MODEL.h"
#include "MBD_FOC_SENSORLESS_MODEL_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift);
extern int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift);
extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern void MBD_FOC_SENSORLESS_MODEL_SpeedControl(real32_T rtu_Speed_Ref_PU,
  int16_T rtu_Speed_Meas_PU, int16_T *rty_IdqRef_PU, int16_T *rty_IdqRef_PU_k,
  const boolean_T *rtd_Enable, const boolean_T *rtd_EnableClosedLoop, const
  boolean_T *rtd_EnableFOC, int16_T *rtd_SpeedRef,
  DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localDW,
  ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localZCE);

#endif                      /* RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
