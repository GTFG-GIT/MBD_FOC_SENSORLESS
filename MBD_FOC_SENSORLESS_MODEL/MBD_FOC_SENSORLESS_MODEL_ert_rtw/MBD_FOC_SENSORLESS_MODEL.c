/*
 * File: MBD_FOC_SENSORLESS_MODEL.c
 *
 * Code generated for Simulink model 'MBD_FOC_SENSORLESS_MODEL'.
 *
 * Model version                  : 8.386
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Apr 16 21:56:11 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MBD_FOC_SENSORLESS_MODEL.h"
#include "rtwtypes.h"
#include "MBD_FOC_SENSORLESS_MODEL_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S3>/Chart' */
#define MBD_FOC_SENSORLESS_MODEL_IN_Align ((uint8_T)1U)
#define MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoop ((uint8_T)2U)
#define MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoopFilter ((uint8_T)3U)
#define MBD_FOC_SENSORLESS_MODEL_IN_Init ((uint8_T)4U)
#define MBD_FOC_SENSORLESS_MODEL_IN_OpenLoop ((uint8_T)5U)

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile uint16_T Pwm1Duty;            /* '<Root>/Data Store Memory5' */
volatile uint16_T Pwm2Duty;            /* '<Root>/Data Store Memory7' */
volatile uint16_T Pwm3Duty;            /* '<Root>/Data Store Memory8' */
volatile real32_T VelRef;              /* '<Root>/Data Store Memory11' */
volatile int16_T smoAnglePU;           /* '<Root>/Data Store Memory9' */

/* Block signals (default storage) */
B_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_B;

/* Block states (default storage) */
DW_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_PrevZCX;

/* Real-time model */
static RT_MODEL_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_M_;
RT_MODEL_MBD_FOC_SENSORLESS_MODEL_T *const MBD_FOC_SENSORLESS_MODEL_M =
  &MBD_FOC_SENSORLESS_MODEL_M_;

/* Forward declaration for local functions */
static int16_T MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En12_Ys16En13_f_pw_cordic11
  (int16_T u0, int16_T u1);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi >> aShift;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

/*
 * Output and update for action system:
 *    '<S43>/If Action Subsystem'
 *    '<S69>/If Action Subsystem'
 */
void MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem(int16_T rtu_In1, int16_T
  *rty_Out1)
{
  /* Sum: '<S45>/Sum' incorporates:
   *  DataTypeConversion: '<S45>/Convert_back'
   *  DataTypeConversion: '<S45>/Convert_uint16'
   */
  *rty_Out1 = (int16_T)(rtu_In1 - ((rtu_In1 >> 14) << 14));
}

/*
 * Output and update for action system:
 *    '<S43>/If Action Subsystem1'
 *    '<S69>/If Action Subsystem1'
 */
void MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem1(int16_T rtu_In1, int16_T
  *rty_Out1)
{
  /* Sum: '<S46>/Sum' incorporates:
   *  DataTypeConversion: '<S46>/Convert_back'
   *  DataTypeConversion: '<S46>/Convert_uint16'
   */
  *rty_Out1 = (int16_T)(rtu_In1 - ((rtu_In1 >> 14) << 14));
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void MBD_FOC_SENSORLESS_MODEL_SpeedControl(real32_T rtu_Speed_Ref_PU, int16_T
  rtu_Speed_Meas_PU, int16_T rty_IdqRef_PU[2], const boolean_T *rtd_Enable,
  const boolean_T *rtd_EnableClosedLoop, const boolean_T *rtd_EnableFOC,
  real32_T *rtd_SpeedRef, DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localDW,
  ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localZCE)
{
  real32_T rtb_Add1_j;
  real32_T tmp;
  int16_T rtb_Add2_p;
  int16_T rtb_Up;

  /* Switch: '<S80>/Switch' incorporates:
   *  Constant: '<S80>/Constant'
   *  DataStoreRead: '<S80>/Data Store Read1'
   *  DataStoreWrite: '<S4>/Data Store Write'
   */
  if (*rtd_EnableFOC) {
    /* Saturate: '<S4>/Saturation' incorporates:
     *  DataStoreWrite: '<S4>/Data Store Write'
     */
    if (rtu_Speed_Ref_PU > 1.0F) {
      *rtd_SpeedRef = 1.0F;
    } else if (rtu_Speed_Ref_PU < 0.208333328F) {
      *rtd_SpeedRef = 0.208333328F;
    } else {
      *rtd_SpeedRef = rtu_Speed_Ref_PU;
    }

    /* End of Saturate: '<S4>/Saturation' */
  } else {
    *rtd_SpeedRef = 0.0F;
  }

  /* End of Switch: '<S80>/Switch' */

  /* Sum: '<S87>/Add1' incorporates:
   *  Constant: '<S87>/Filter_Constant'
   *  Constant: '<S87>/One'
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  Product: '<S87>/Product'
   *  Product: '<S87>/Product1'
   *  UnitDelay: '<S87>/Unit Delay'
   */
  rtb_Add1_j = *rtd_SpeedRef * 0.03F + 0.97F * localDW->UnitDelay_DSTATE;

  /* Product: '<S84>/Up' incorporates:
   *  Constant: '<S79>/Kp1'
   *  Sum: '<S84>/Add'
   */
  tmp = (real32_T)floor((rtb_Add1_j - (real32_T)rtu_Speed_Meas_PU *
    6.10351562E-5F) * 0.650024414F * 16384.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_Up = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp :
                     (int32_T)(int16_T)(uint16_T)tmp);

  /* End of Product: '<S84>/Up' */

  /* Sum: '<S84>/Add2' incorporates:
   *  Product: '<S84>/Product1'
   *  Product: '<S84>/Up'
   *  UnitDelay: '<S84>/Unit Delay'
   */
  rtb_Add2_p = (int16_T)(((rtb_Up * 19) >> 11) + localDW->UnitDelay_DSTATE_f);

  /* Switch: '<S88>/Switch2' incorporates:
   *  Constant: '<S79>/Ki3'
   *  RelationalOperator: '<S88>/LowerRelop1'
   *  RelationalOperator: '<S88>/UpperRelop'
   *  Sum: '<S84>/Add2'
   *  Switch: '<S88>/Switch'
   */
  if (rtb_Add2_p > 13107) {
    rtb_Add2_p = 13107;
  } else if (rtb_Add2_p < -13107) {
    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S79>/Ki4'
     *  Switch: '<S88>/Switch2'
     */
    rtb_Add2_p = -13107;
  }

  /* End of Switch: '<S88>/Switch2' */

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/Id_ref2'
   *  Constant: '<S4>/Iq_ref3'
   *  DataStoreRead: '<S4>/Data Store Read5'
   */
  if (*rtd_Enable) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Id_ref'
     *  Constant: '<S4>/Id_ref1'
     *  Constant: '<S4>/Iq_ref_openloop'
     *  Switch: '<S4>/Switch1'
     */
    if (*rtd_EnableClosedLoop) {
      /* Sum: '<S84>/Add1' incorporates:
       *  Product: '<S84>/Up'
       *  Switch: '<S88>/Switch2'
       */
      rtb_Up += rtb_Add2_p;

      /* Switch: '<S89>/Switch2' incorporates:
       *  RelationalOperator: '<S89>/LowerRelop1'
       *  RelationalOperator: '<S89>/UpperRelop'
       *  Sum: '<S84>/Add1'
       *  Switch: '<S89>/Switch'
       */
      if (rtb_Up > 16384) {
        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S79>/Ki5'
         */
        rtb_Up = 16384;
      } else if (rtb_Up < -16384) {
        /* Switch: '<S89>/Switch' incorporates:
         *  Constant: '<S79>/Ki6'
         *  Switch: '<S4>/Switch'
         */
        rtb_Up = -16384;
      }

      /* End of Switch: '<S89>/Switch2' */
      rty_IdqRef_PU[0] = 0;
    } else {
      rtb_Up = 0;
      rty_IdqRef_PU[0] = 13107;
    }

    /* End of Switch: '<S4>/Switch' */
    rty_IdqRef_PU[1] = rtb_Up;
  } else {
    rty_IdqRef_PU[0] = 0;
    rty_IdqRef_PU[1] = 0;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Outputs for Triggered SubSystem: '<S81>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S82>/Trigger'
   */
  /* Constant: '<S81>/Constant' */
  localZCE->TriggeredSubsystem_Trig_ZCE = 1U;

  /* End of Outputs for SubSystem: '<S81>/Triggered Subsystem' */

  /* Update for UnitDelay: '<S87>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtb_Add1_j;

  /* Switch: '<S84>/Switch2' incorporates:
   *  DataStoreRead: '<S79>/Data Store Read1'
   *  DataStoreRead: '<S79>/Data Store Read2'
   *  Logic: '<S79>/AND'
   */
  if ((*rtd_EnableClosedLoop) && (*rtd_Enable)) {
    /* Update for UnitDelay: '<S84>/Unit Delay' incorporates:
     *  Switch: '<S88>/Switch2'
     */
    localDW->UnitDelay_DSTATE_f = rtb_Add2_p;
  } else {
    /* Update for UnitDelay: '<S84>/Unit Delay' incorporates:
     *  Constant: '<S84>/Constant'
     */
    localDW->UnitDelay_DSTATE_f = 0;
  }

  /* End of Switch: '<S84>/Switch2' */
}

static int16_T MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En12_Ys16En13_f_pw_cordic11
  (int16_T u0, int16_T u1)
{
  int32_T idx;
  int32_T xAcc;
  int32_T xtmp;
  int32_T yAcc;
  int32_T ytmp;
  int16_T y;
  boolean_T x_quad_adjust;
  boolean_T y_nonzero;
  boolean_T y_quad_adjust;
  static const int16_T atan2_cordicLUT_n11_s16En13[11] = { 6434, 3798, 2007,
    1019, 511, 256, 128, 64, 32, 16, 8 };

  for (ytmp = 0; ytmp < 11; ytmp++) {
    MBD_FOC_SENSORLESS_MODEL_B.u3[ytmp] = atan2_cordicLUT_n11_s16En13[ytmp];
  }

  if (u0 < 0) {
    yAcc = -u0;
    y_quad_adjust = true;
    y_nonzero = true;
  } else {
    yAcc = u0;
    y_quad_adjust = false;
    y_nonzero = (u0 > 0);
  }

  if (u1 < 0) {
    xAcc = -u1;
    x_quad_adjust = true;
  } else {
    xAcc = u1;
    x_quad_adjust = false;
  }

  y = 0;
  xtmp = xAcc;
  ytmp = yAcc;
  for (idx = 0; idx < 11; idx++) {
    if (yAcc < 0) {
      ytmp = xAcc - ytmp;
      xAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp | -131072 : ytmp & 131071;
      ytmp = yAcc + xtmp;
      yAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp | -131072 : ytmp & 131071;
      y -= MBD_FOC_SENSORLESS_MODEL_B.u3[(int16_T)(idx + 1) - 1];
    } else {
      ytmp += xAcc;
      xAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp | -131072 : ytmp & 131071;
      ytmp = yAcc - xtmp;
      yAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp | -131072 : ytmp & 131071;
      y += MBD_FOC_SENSORLESS_MODEL_B.u3[(int16_T)(idx + 1) - 1];
    }

    xtmp = xAcc >> (int16_T)(idx + 1);
    ytmp = yAcc >> (int16_T)(idx + 1);
  }

  if (y_nonzero) {
    if (x_quad_adjust) {
      if (y_quad_adjust) {
        ytmp = y - 25736;
        if (y - 25736 < -32768) {
          ytmp = -32768;
        }

        y = (int16_T)ytmp;
      } else {
        ytmp = 25736 - y;
        if (25736 - y > 32767) {
          ytmp = 32767;
        }

        y = (int16_T)ytmp;
      }
    } else if (y_quad_adjust) {
      ytmp = -y;
      if (-y > 32767) {
        ytmp = 32767;
      }

      y = (int16_T)ytmp;
    }
  } else if (x_quad_adjust) {
    y = 25736;
  } else {
    y = 0;
  }

  return y;
}

int16_T rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s(int16_T u)
{
  int32_T iBit;
  int32_T tmp03_u;
  int16_T shiftMask;
  int16_T tmp01_y;
  int16_T y;

  /* Fixed-Point Sqrt Computation by the bisection method. */
  if (u > 0) {
    y = 0;
    shiftMask = 16384;
    tmp03_u = u << 14;
    for (iBit = 0; iBit < 15; iBit++) {
      tmp01_y = (int16_T)(y | shiftMask);
      if (tmp01_y * tmp01_y <= tmp03_u) {
        y = tmp01_y;
      }

      shiftMask = (int16_T)((uint32_T)shiftMask >> 1U);
    }
  } else {
    y = 0;
  }

  return y;
}

/* Model step function for TID0 */
void MbdFocSensorlessCurrentCtrl(void) /* Sample time: [5.0E-5s, 0.0s] */
{
  int16_T rtb_Add6;
  int16_T rtb_Add8;
  int16_T rtb_DataTypeConversion1;
  int16_T rtb_DataTypeConversion3;
  int16_T rtb_DataTypeConversion3_m;
  int16_T rtb_Product_g;
  int16_T rtb_Sum1;
  int16_T rtb_Sum4_fv;
  int16_T rtb_Sum5;
  int16_T rtb_Sum6;
  int16_T rtb_Switch2;
  int16_T rtb_Switch2_hf;
  int16_T rtb_Switch_g0_idx_1;
  int16_T rtb_ToPerUnit_idx_0;
  int16_T rtb_sum_beta;
  uint16_T rtb_Get_Integer;
  uint16_T rtb_Saturationlowsideturnon_idx_1;
  uint16_T rtb_Saturationlowsideturnon_idx_2;
  uint16_T y;

  /* Gain: '<S55>/Ls1_PU' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S55>/Gain8'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = (2787 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1]) >> 15;

  /* Sum: '<S55>/Add3' incorporates:
   *  Gain: '<S55>/Ls1_PU'
   *  Product: '<S68>/Product'
   *  UnitDelay: '<S55>/Unit Delay1'
   */
  rtb_Product_g = (int16_T)(MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay1_DSTATE -
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4);

  /* Gain: '<S55>/Ls_PU' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S55>/L_PU'
   */
  MBD_FOC_SENSORLESS_MODEL_B.rtb_Sum5_tmp = (2787 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0]) >> 15;

  /* Sum: '<S55>/Add2' incorporates:
   *  Gain: '<S55>/Ls_PU'
   *  Sum: '<S68>/Sum5'
   *  UnitDelay: '<S55>/Unit Delay'
   */
  rtb_Sum5 = (int16_T)(MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE -
                       MBD_FOC_SENSORLESS_MODEL_B.rtb_Sum5_tmp);

  /* Math: '<S55>/Square1' incorporates:
   *  Sum: '<S68>/Sum5'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (rtb_Sum5 * rtb_Sum5) >> 14;
  if (MBD_FOC_SENSORLESS_MODEL_B.u0 > 32767) {
    MBD_FOC_SENSORLESS_MODEL_B.u0 = 32767;
  } else if (MBD_FOC_SENSORLESS_MODEL_B.u0 < -32768) {
    MBD_FOC_SENSORLESS_MODEL_B.u0 = -32768;
  }

  /* Math: '<S55>/Square2' incorporates:
   *  Product: '<S68>/Product'
   */
  MBD_FOC_SENSORLESS_MODEL_B.i = (rtb_Product_g * rtb_Product_g) >> 14;
  if (MBD_FOC_SENSORLESS_MODEL_B.i > 32767) {
    MBD_FOC_SENSORLESS_MODEL_B.i = 32767;
  } else if (MBD_FOC_SENSORLESS_MODEL_B.i < -32768) {
    MBD_FOC_SENSORLESS_MODEL_B.i = -32768;
  }

  /* Sum: '<S55>/Add4' incorporates:
   *  Math: '<S55>/Square'
   *  Math: '<S55>/Square1'
   *  Math: '<S55>/Square2'
   *  Switch: '<S35>/Switch2'
   */
  rtb_DataTypeConversion3 = (int16_T)((MBD_FOC_SENSORLESS_MODEL_ConstB.Square -
    MBD_FOC_SENSORLESS_MODEL_B.u0) - MBD_FOC_SENSORLESS_MODEL_B.i);

  /* Sum: '<S55>/Add8' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S55>/Gain4'
   *  Gain: '<S55>/Rs_PU1'
   *  Product: '<S55>/Product1'
   *  Product: '<S68>/Product'
   *  Sum: '<S55>/Add1'
   *  Sum: '<S55>/Add7'
   *  Switch: '<S35>/Switch2'
   *  UnitDelay: '<S55>/Unit Delay3'
   */
  rtb_Add8 = (int16_T)((((int16_T)((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[3] - ((4405 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1]) >> 16)) + (int16_T)
    ((rtb_Product_g * rtb_DataTypeConversion3) >> 14)) * 16471) >> 18) +
                       MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE);

  /* Sum: '<S55>/x2-ib*L' incorporates:
   *  Product: '<S68>/Product'
   *  Sum: '<S55>/Add8'
   */
  rtb_Product_g = (int16_T)(rtb_Add8 -
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4);

  /* Sum: '<S55>/Add6' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S55>/Gain6'
   *  Gain: '<S55>/Rs_PU'
   *  Product: '<S55>/Product'
   *  Sum: '<S55>/Add'
   *  Sum: '<S55>/Add5'
   *  Sum: '<S68>/Sum5'
   *  Switch: '<S35>/Switch2'
   *  UnitDelay: '<S55>/Unit Delay2'
   */
  rtb_Add6 = (int16_T)((((int16_T)((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[2] - ((4405 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0]) >> 16)) + (int16_T)((rtb_Sum5 *
    rtb_DataTypeConversion3) >> 14)) * 16471) >> 18) +
                       MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay2_DSTATE);

  /* Sum: '<S55>/x1-ia*L' incorporates:
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Sum: '<S55>/Add6'
   */
  rtb_DataTypeConversion3_m = (int16_T)(rtb_Add6 -
    MBD_FOC_SENSORLESS_MODEL_B.rtb_Sum5_tmp);

  /* DataTypeConversion: '<S61>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S55>/Data Type Conversion'
   *  DataTypeConversion: '<S55>/Data Type Conversion2'
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Product: '<S68>/Product'
   *  Trigonometry: '<S61>/Trigonometric Function'
   */
  rtb_DataTypeConversion3 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En12_Ys16En13_f_pw_cordic11((int16_T)
      (rtb_Product_g >> 2), (int16_T)(rtb_DataTypeConversion3_m >> 2)) >> 1);

  /* Switch: '<S74>/Switch2' incorporates:
   *  Constant: '<S74>/2pi'
   *  DataTypeConversion: '<S61>/Data Type Conversion3'
   *  Sum: '<S74>/Sum'
   *  Switch: '<S35>/Switch2'
   */
  if (rtb_DataTypeConversion3 <= 0) {
    rtb_DataTypeConversion3 = (int16_T)(rtb_DataTypeConversion3 + 25736);
  }

  /* End of Switch: '<S74>/Switch2' */

  /* Math: '<S75>/Math Function' incorporates:
   *  DataTypeConversion: '<S61>/Data Type Conversion4'
   *  Switch: '<S35>/Switch2'
   */
  y = (uint16_T)((uint16_T)rtb_DataTypeConversion3 % 25736);

  /* Gain: '<S55>/Inverting OpAmp5' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read5'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u = 2400.0F * MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef *
    4.0F;
  if (MBD_FOC_SENSORLESS_MODEL_B.u < 0.0F) {
    MBD_FOC_SENSORLESS_MODEL_B.u = (real32_T)ceil(MBD_FOC_SENSORLESS_MODEL_B.u);
  } else {
    MBD_FOC_SENSORLESS_MODEL_B.u = (real32_T)floor(MBD_FOC_SENSORLESS_MODEL_B.u);
  }

  if (rtIsNaNF(MBD_FOC_SENSORLESS_MODEL_B.u) || rtIsInfF
      (MBD_FOC_SENSORLESS_MODEL_B.u)) {
    MBD_FOC_SENSORLESS_MODEL_B.u = 0.0F;
  } else {
    MBD_FOC_SENSORLESS_MODEL_B.u = (real32_T)fmod(MBD_FOC_SENSORLESS_MODEL_B.u,
      65536.0);
  }

  /* Sum: '<S60>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S60>/Unit Delay3'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (int16_T)((int16_T)y -
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE_c) << 12;

  /* Bias: '<S73>/Bias' incorporates:
   *  Math: '<S73>/Math Function1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (MBD_FOC_SENSORLESS_MODEL_B.u0 - div_s32_floor
    (MBD_FOC_SENSORLESS_MODEL_B.u0, 105414357) * 105414357) + 52707179;

  /* DiscreteIntegrator: '<S60>/Discrete-Time Integrator4' incorporates:
   *  Bias: '<S73>/Bias1'
   *  Delay: '<S60>/Delay1'
   *  Gain: '<S55>/Gain10'
   *  Gain: '<S55>/Inverting OpAmp5'
   *  Gain: '<S60>/Gain1'
   *  Gain: '<S60>/Gain3'
   *  Math: '<S73>/Math Function'
   *  Product: '<S60>/Product1'
   *  Sum: '<S60>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = mul_s32_hiSR(439804651,
    ((int16_T)(((int16_T)(((((MBD_FOC_SENSORLESS_MODEL_B.u0 - div_s32_floor
    (MBD_FOC_SENSORLESS_MODEL_B.u0, 105414357) * 105414357) + -52707179) >> 12) *
    625) >> 4) - (MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE << 1)) >> 1) *
     (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.u < 0.0F ? (int32_T)(int16_T)
                 -(int16_T)(uint16_T)-MBD_FOC_SENSORLESS_MODEL_B.u : (int32_T)
                 (int16_T)(uint16_T)MBD_FOC_SENSORLESS_MODEL_B.u) * 17157) >> 14))
    << 3, 11U) + MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE;

  /* DataTypeConversion: '<S60>/Data Type Conversion1' incorporates:
   *  DiscreteIntegrator: '<S60>/Discrete-Time Integrator4'
   */
  rtb_DataTypeConversion1 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 >> 6);

  /* Gain: '<S55>/Gain9' incorporates:
   *  DataTypeConversion: '<S60>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain9 = (int16_T)((13351 * rtb_DataTypeConversion1)
    >> 12);

  /* Chart: '<S3>/Chart' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read5'
   *  DataStoreWrite: '<S3>/Data Store Write'
   *  DataStoreWrite: '<S3>/Data Store Write1'
   *  DataStoreWrite: '<S3>/Data Store Write3'
   *  Gain: '<S55>/Gain9'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 < 32767U) {
    MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1++;
  }

  if (MBD_FOC_SENSORLESS_MODEL_DW.is_active_c3_MBD_FOC_SENSORLESS_MODEL == 0U) {
    MBD_FOC_SENSORLESS_MODEL_DW.is_active_c3_MBD_FOC_SENSORLESS_MODEL = 1U;
    MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
      MBD_FOC_SENSORLESS_MODEL_IN_Init;
    MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
  } else {
    switch (MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL) {
     case MBD_FOC_SENSORLESS_MODEL_IN_Align:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 4000U) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_OpenLoop;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl = 0U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = true;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = false;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoop:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 2000U) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoopFilter;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl = 1U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = true;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoopFilter:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl = 1U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = true;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_Init:
      if ((MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 1000U) &&
          MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Align;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl = 0U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = true;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = false;
      }
      break;

     default:
      /* case IN_OpenLoop: */
      if ((MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 20000U) &&
          (MBD_FOC_SENSORLESS_MODEL_B.Gain9 >= 1775)) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoop;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl = 1U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = true;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write4'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop =
    (MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl != 0);

  /* RateTransition: '<Root>/Rate Transition5' */
  MBD_FOC_SENSORLESS_MODEL_B.u0 =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx << 1;
  MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[MBD_FOC_SENSORLESS_MODEL_B.u0];
  MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[MBD_FOC_SENSORLESS_MODEL_B.u0
    + 1];

  /* Outputs for Enabled SubSystem: '<S7>/Offset1' incorporates:
   *  EnablePort: '<S53>/Enable'
   */
  /* DataStoreRead: '<S7>/Data Store Read' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset) {
    /* SignalConversion generated from: '<S53>/Iab' incorporates:
     *  DataStoreRead: '<S7>/Data Store Read1'
     *  DataStoreRead: '<S7>/Data Store Read2'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Iab[0] = MBD_FOC_SENSORLESS_MODEL_DW.ADC_IA;
    MBD_FOC_SENSORLESS_MODEL_B.Iab[1] = MBD_FOC_SENSORLESS_MODEL_DW.ADC_IB;
  }

  /* End of DataStoreRead: '<S7>/Data Store Read' */
  /* End of Outputs for SubSystem: '<S7>/Offset1' */

  /* Gain: '<S7>/To Per-Unit' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read1'
   *  DataStoreRead: '<S7>/Data Store Read2'
   *  Sum: '<S7>/Add2'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (int16_T)((int16_T)
    MBD_FOC_SENSORLESS_MODEL_DW.ADC_IA - (int16_T)
    MBD_FOC_SENSORLESS_MODEL_B.Iab[0]) * -10027;
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.u0 < 0 ?
    2047 : 0) + MBD_FOC_SENSORLESS_MODEL_B.u0) >> 11) * 13405;
  rtb_ToPerUnit_idx_0 = (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.u0 < 0 ? 8191 : 0)
    + MBD_FOC_SENSORLESS_MODEL_B.u0) >> 13);
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (int16_T)((int16_T)
    MBD_FOC_SENSORLESS_MODEL_DW.ADC_IB - (int16_T)
    MBD_FOC_SENSORLESS_MODEL_B.Iab[1]) * -10027;
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.u0 < 0 ?
    2047 : 0) + MBD_FOC_SENSORLESS_MODEL_B.u0) >> 11) * 13405;
  rtb_DataTypeConversion3 = (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.u0 < 0 ? 8191
    : 0) + MBD_FOC_SENSORLESS_MODEL_B.u0) >> 13);

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Gain: '<S10>/one_by_sqrt3' incorporates:
   *  Sum: '<S10>/a_plus_2b'
   *  Sum: '<S12>/sum_beta'
   */
  rtb_sum_beta = (int16_T)(((int16_T)((int16_T)(rtb_ToPerUnit_idx_0 +
    rtb_DataTypeConversion3) + rtb_DataTypeConversion3) * 18919) >> 15);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */

  /* Gain: '<S55>/Gain7' incorporates:
   *  DataStoreWrite: '<S9>/Data Store Write'
   *  Gain: '<S61>/Gain2'
   */
  smoAnglePU = (int16_T)((20861 * (int16_T)y) >> 15);

  /* Outputs for Resettable SubSystem: '<S9>/AngleGen Pos_PU' incorporates:
   *  ResetPort: '<S54>/Reset'
   */
  /* DataStoreRead: '<S9>/Data Store Read2' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable &&
      (MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE != POS_ZCSIG))
  {
    /* Disable for Enabled SubSystem: '<S56>/Accumulate' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
      /* Disable for Sum: '<S57>/Add1' incorporates:
       *  Outport: '<S57>/theta_e'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Add1 = 0;
      MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
    }

    /* End of Disable for SubSystem: '<S56>/Accumulate' */

    /* InitializeConditions for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 0;

    /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_n = 0;
  }

  MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE =
    MBD_FOC_SENSORLESS_MODEL_DW.Enable;

  /* End of DataStoreRead: '<S9>/Data Store Read2' */

  /* Outputs for Enabled SubSystem: '<S56>/Accumulate' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_ConstB.NOT) {
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = true;

    /* Outputs for Enabled SubSystem: '<S57>/Subsystem' incorporates:
     *  EnablePort: '<S58>/Enable'
     */
    /* Delay: '<S57>/Delay' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k) {
      /* SignalConversion generated from: '<S58>/Input' incorporates:
       *  DiscreteIntegrator: '<S54>/Discrete-Time Integrator'
       *  Gain: '<S54>/Gain'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Input = (int16_T)mul_s32_loSR(5243,
        MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE, 25U);
    }

    /* End of Delay: '<S57>/Delay' */
    /* End of Outputs for SubSystem: '<S57>/Subsystem' */

    /* Sum: '<S57>/Add' incorporates:
     *  SignalConversion generated from: '<S58>/Input'
     *  Switch: '<S38>/Switch2'
     *  UnitDelay: '<S56>/Unit Delay'
     */
    rtb_Switch2 = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.Input +
      MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_n);

    /* Sum: '<S57>/Add1' incorporates:
     *  DataTypeConversion: '<S57>/Data Type Conversion'
     *  DataTypeConversion: '<S57>/Data Type Conversion1'
     *  Switch: '<S38>/Switch2'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = (int16_T)(rtb_Switch2 - ((rtb_Switch2 >>
      14) << 14));

    /* Update for Delay: '<S57>/Delay' incorporates:
     *  Constant: '<S57>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k = true;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
    /* Disable for Sum: '<S57>/Add1' incorporates:
     *  Outport: '<S57>/theta_e'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = 0;
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S56>/Accumulate' */

  /* Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S54>/Data Type Conversion'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE += mul_s32_hiSR
    (824633721, MBD_FOC_SENSORLESS_MODEL_ConstB.DataTypeConversion, 5U);
  if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE >= 218453) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 218453;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE <= 0) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S56>/Unit Delay' incorporates:
   *  Sum: '<S57>/Add1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_n =
    MBD_FOC_SENSORLESS_MODEL_B.Add1;

  /* End of Outputs for SubSystem: '<S9>/AngleGen Pos_PU' */

  /* Switch: '<S9>/Switch' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read3'
   *  DataStoreWrite: '<S9>/Data Store Write'
   *  Gain: '<S55>/Gain7'
   *  Gain: '<S56>/scaleOut'
   *  Sum: '<S57>/Add1'
   *  Switch: '<S35>/Switch2'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop) {
    rtb_DataTypeConversion3 = smoAnglePU;
  } else {
    /* Outputs for Resettable SubSystem: '<S9>/AngleGen Pos_PU' incorporates:
     *  ResetPort: '<S54>/Reset'
     */
    rtb_DataTypeConversion3 = MBD_FOC_SENSORLESS_MODEL_B.Add1;

    /* End of Outputs for SubSystem: '<S9>/AngleGen Pos_PU' */
  }

  /* End of Switch: '<S9>/Switch' */

  /* If: '<S43>/If' incorporates:
   *  Gain: '<S43>/convert_pu'
   *  RelationalOperator: '<S44>/Compare'
   *  Switch: '<S35>/Switch2'
   */
  if (rtb_DataTypeConversion3 < 0) {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem(rtb_DataTypeConversion3,
      &rtb_DataTypeConversion3);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem1(rtb_DataTypeConversion3,
      &rtb_DataTypeConversion3);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem1' */
  }

  /* End of If: '<S43>/If' */

  /* Gain: '<S14>/indexing' incorporates:
   *  Sum: '<S68>/Sum5'
   *  Switch: '<S35>/Switch2'
   */
  rtb_Sum5 = (int16_T)((25 * rtb_DataTypeConversion3) >> 4);

  /* DataTypeConversion: '<S14>/Get_Integer' incorporates:
   *  Sum: '<S68>/Sum5'
   */
  rtb_Get_Integer = (uint16_T)(rtb_Sum5 >> 5);

  /* DataTypeConversion: '<S14>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  Sum: '<S14>/Sum2'
   *  Sum: '<S68>/Sum5'
   */
  rtb_Sum5 = (int16_T)((int16_T)(rtb_Sum5 - (int16_T)((int16_T)rtb_Get_Integer <<
    5)) << 9);

  /* Sum: '<S42>/Sum3' incorporates:
   *  Constant: '<S14>/sine_table_values'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S42>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11[rtb_Get_Integer];

  /* Sum: '<S42>/Sum4' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  Product: '<S42>/Product'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S42>/Sum3'
   *  Sum: '<S68>/Sum5'
   */
  rtb_Sum4_fv = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11[(int32_T)(rtb_Get_Integer + 1U)] -
     MBD_FOC_SENSORLESS_MODEL_B.u0) * rtb_Sum5) >> 14) +
    MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Sum: '<S42>/Sum5' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S42>/Sum6'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11
    [(int32_T)(rtb_Get_Integer + 200U)];

  /* Sum: '<S42>/Sum6' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  Product: '<S42>/Product1'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S42>/Sum5'
   *  Sum: '<S68>/Sum5'
   */
  rtb_Sum6 = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11[(int32_T)(rtb_Get_Integer + 201U)]
     - MBD_FOC_SENSORLESS_MODEL_B.u0) * rtb_Sum5) >> 14) +
                       MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Product: '<S37>/Up' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Product: '<S13>/asin'
   *  Product: '<S13>/bcos'
   *  Sum: '<S12>/sum_beta'
   *  Sum: '<S13>/sum_Qs'
   *  Sum: '<S37>/Add'
   *  Sum: '<S42>/Sum4'
   *  Sum: '<S42>/Sum6'
   *  Switch: '<S35>/Switch2'
   */
  rtb_DataTypeConversion3 = (int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] - (int16_T)((int16_T)
    ((rtb_sum_beta * rtb_Sum6) >> 14) - (int16_T)((rtb_ToPerUnit_idx_0 *
    rtb_Sum4_fv) >> 14))) * 2787) >> 13);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* Sum: '<S37>/Add2' incorporates:
   *  Product: '<S37>/Product1'
   *  Switch: '<S35>/Switch2'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  rtb_Switch2 = (int16_T)(((rtb_DataTypeConversion3 * 407) >> 13) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_c);

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S18>/Ki1'
   *  RelationalOperator: '<S38>/LowerRelop1'
   *  RelationalOperator: '<S38>/UpperRelop'
   *  Sum: '<S37>/Add2'
   *  Switch: '<S38>/Switch'
   */
  if (rtb_Switch2 > 13107) {
    rtb_Switch2 = 13107;
  } else if (rtb_Switch2 < -13107) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S18>/Ki2'
     *  Switch: '<S38>/Switch2'
     */
    rtb_Switch2 = -13107;
  }

  /* End of Switch: '<S38>/Switch2' */

  /* Sum: '<S37>/Add1' incorporates:
   *  Switch: '<S35>/Switch2'
   *  Switch: '<S38>/Switch2'
   */
  rtb_DataTypeConversion3 += rtb_Switch2;

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S18>/Ki4'
   *  RelationalOperator: '<S39>/LowerRelop1'
   *  RelationalOperator: '<S39>/UpperRelop'
   *  Sum: '<S37>/Add1'
   *  Switch: '<S39>/Switch'
   */
  if (rtb_DataTypeConversion3 > 15565) {
    rtb_Switch2_hf = 15565;
  } else if (rtb_DataTypeConversion3 < -15565) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S18>/Ki3'
     *  Switch: '<S39>/Switch2'
     */
    rtb_Switch2_hf = -15565;
  } else {
    rtb_Switch2_hf = rtb_DataTypeConversion3;
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Product: '<S34>/Up' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Product: '<S13>/acos'
   *  Product: '<S13>/bsin'
   *  Sum: '<S12>/sum_beta'
   *  Sum: '<S13>/sum_Ds'
   *  Sum: '<S34>/Add'
   *  Sum: '<S42>/Sum4'
   *  Sum: '<S42>/Sum6'
   *  Sum: '<S68>/Sum5'
   */
  rtb_Sum5 = (int16_T)(((int16_T)(MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0]
    - (int16_T)((int16_T)((rtb_ToPerUnit_idx_0 * rtb_Sum6) >> 14) + (int16_T)
                ((rtb_sum_beta * rtb_Sum4_fv) >> 14))) * 2787) >> 13);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* Sum: '<S34>/Add2' incorporates:
   *  Product: '<S34>/Product1'
   *  Sum: '<S68>/Sum5'
   *  UnitDelay: '<S34>/Unit Delay'
   */
  rtb_DataTypeConversion3 = (int16_T)(((rtb_Sum5 * 407) >> 13) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_l);

  /* Switch: '<S35>/Switch2' incorporates:
   *  Constant: '<S17>/Ki1'
   *  RelationalOperator: '<S35>/LowerRelop1'
   *  RelationalOperator: '<S35>/UpperRelop'
   *  Sum: '<S34>/Add2'
   *  Switch: '<S35>/Switch'
   */
  if (rtb_DataTypeConversion3 > 13107) {
    rtb_DataTypeConversion3 = 13107;
  } else if (rtb_DataTypeConversion3 < -13107) {
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S17>/Ki2'
     *  Switch: '<S35>/Switch2'
     */
    rtb_DataTypeConversion3 = -13107;
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Sum: '<S34>/Add1' incorporates:
   *  Sum: '<S68>/Sum5'
   *  Switch: '<S35>/Switch2'
   */
  rtb_Sum5 += rtb_DataTypeConversion3;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S17>/Ki4'
   *  RelationalOperator: '<S36>/LowerRelop1'
   *  RelationalOperator: '<S36>/UpperRelop'
   *  Sum: '<S34>/Add1'
   *  Switch: '<S36>/Switch'
   */
  if (rtb_Sum5 > 15565) {
    rtb_Sum5 = 15565;
  } else if (rtb_Sum5 < -15565) {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S17>/Ki3'
     *  Switch: '<S36>/Switch2'
     */
    rtb_Sum5 = -15565;
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Sum: '<S22>/Sum1' incorporates:
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  Switch: '<S36>/Switch2'
   *  Switch: '<S39>/Switch2'
   */
  rtb_Sum1 = (int16_T)(((rtb_Sum5 * rtb_Sum5) >> 14) + ((rtb_Switch2_hf *
    rtb_Switch2_hf) >> 14));

  /* Outputs for IfAction SubSystem: '<S16>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S19>/Action Port'
   */
  /* If: '<S19>/If' incorporates:
   *  If: '<S16>/If'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Sum: '<S22>/Sum1'
   */
  if (rtb_Sum1 >= 14786) {
    /* Outputs for IfAction SubSystem: '<S19>/Limiter' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Sqrt: '<S23>/Square Root' incorporates:
     *  Switch: '<S23>/Switch'
     */
    rtb_Sum1 = rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s(rtb_Sum1);

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/Constant'
     */
    if (rtb_Sum1 == 0) {
      rtb_Sum1 = 16384;
    }

    /* Product: '<S23>/Reciprocal' incorporates:
     *  Switch: '<S23>/Switch'
     */
    if (rtb_Sum1 == 0) {
      MBD_FOC_SENSORLESS_MODEL_B.u0 = MAX_int32_T;

      /* Divide by zero handler */
    } else {
      MBD_FOC_SENSORLESS_MODEL_B.u0 = 268435456 / rtb_Sum1;
    }

    if (MBD_FOC_SENSORLESS_MODEL_B.u0 > 32767) {
      MBD_FOC_SENSORLESS_MODEL_B.u0 = 32767;
    } else if (MBD_FOC_SENSORLESS_MODEL_B.u0 < -32768) {
      MBD_FOC_SENSORLESS_MODEL_B.u0 = -32768;
    }

    /* Product: '<S23>/Product1' incorporates:
     *  Constant: '<S21>/Constant3'
     *  Merge: '<S16>/Merge'
     *  Product: '<S23>/Product'
     *  Product: '<S23>/Reciprocal'
     *  Switch: '<S21>/Switch'
     */
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] = (int16_T)((((rtb_Sum5 *
      15565) >> 14) * (int16_T)MBD_FOC_SENSORLESS_MODEL_B.u0) >> 14);
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] = (int16_T)((((rtb_Switch2_hf *
      15565) >> 14) * (int16_T)MBD_FOC_SENSORLESS_MODEL_B.u0) >> 14);

    /* End of Outputs for SubSystem: '<S19>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S19>/Passthrough' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SignalConversion generated from: '<S24>/dqRef' incorporates:
     *  Merge: '<S16>/Merge'
     */
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] = rtb_Sum5;
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] = rtb_Switch2_hf;

    /* End of Outputs for SubSystem: '<S19>/Passthrough' */
  }

  /* End of If: '<S19>/If' */
  /* End of Outputs for SubSystem: '<S16>/D-Q Equivalence' */

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
  /* Switch: '<S40>/Switch' incorporates:
   *  Product: '<S12>/dcos'
   *  Product: '<S12>/dsin'
   *  Product: '<S12>/qcos'
   *  Product: '<S12>/qsin'
   *  Sum: '<S12>/sum_alpha'
   *  Sum: '<S12>/sum_beta'
   *  Sum: '<S42>/Sum4'
   *  Sum: '<S42>/Sum6'
   */
  rtb_Sum1 = (int16_T)((int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] *
    rtb_Sum6) >> 14) - (int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] *
    rtb_Sum4_fv) >> 14));
  rtb_Switch_g0_idx_1 = (int16_T)((int16_T)
    ((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] * rtb_Sum6) >> 14) +
    (int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] * rtb_Sum4_fv) >>
              14));

  /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

  /* Switch: '<S8>/Enable motor control' incorporates:
   *  Constant: '<S8>/Constant2'
   *  DataStoreRead: '<S8>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Switch: '<S8>/Switch for Current offset calibration' incorporates:
     *  Constant: '<S8>/Constant2'
     *  DataStoreRead: '<S8>/Data Store Read'
     *  DataStoreRead: '<S8>/Data Store Read1'
     *  Switch: '<S8>/Switch for rotor alignment'
     */
    if (MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset) {
      rtb_Get_Integer = 0U;
      rtb_Saturationlowsideturnon_idx_1 = 0U;
      rtb_Saturationlowsideturnon_idx_2 = 0U;
    } else if (MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset) {
      /* Switch: '<S8>/Switch for rotor alignment' incorporates:
       *  Constant: '<S8>/Constant3'
       *  Constant: '<S8>/Constant4'
       */
      rtb_Get_Integer = 532U;
      rtb_Saturationlowsideturnon_idx_1 = 343U;
      rtb_Saturationlowsideturnon_idx_2 = 343U;
    } else {
      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* Gain: '<S52>/sqrt3_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  MinMax: '<S50>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Switch2_hf = (int16_T)((14189 * rtb_Switch_g0_idx_1) >> 14);

      /* Gain: '<S52>/one_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Gain: '<S50>/one_by_two'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum4_fv = (int16_T)(rtb_Sum1 >> 1);

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

      /* Sum: '<S52>/add_c' incorporates:
       *  Gain: '<S50>/one_by_two'
       *  MinMax: '<S50>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum6 = (int16_T)(-rtb_Sum4_fv - rtb_Switch2_hf);

      /* Sum: '<S52>/add_b' incorporates:
       *  Gain: '<S50>/one_by_two'
       *  MinMax: '<S50>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Switch2_hf -= rtb_Sum4_fv;

      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* MinMax: '<S50>/Min' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Sum: '<S52>/add_b'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Sum1 <= rtb_Switch2_hf) {
        rtb_Sum5 = rtb_Sum1;
      } else {
        rtb_Sum5 = rtb_Switch2_hf;
      }

      /* MinMax: '<S50>/Max' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Sum: '<S52>/add_b'
       *  Sum: '<S52>/add_c'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Sum1 >= rtb_Switch2_hf) {
        rtb_Sum4_fv = rtb_Sum1;
      } else {
        rtb_Sum4_fv = rtb_Switch2_hf;
      }

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */
      if (rtb_Sum4_fv < rtb_Sum6) {
        rtb_Sum4_fv = rtb_Sum6;
      }

      /* MinMax: '<S50>/Min' incorporates:
       *  Sum: '<S52>/add_c'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Sum5 > rtb_Sum6) {
        rtb_Sum5 = rtb_Sum6;
      }

      /* Gain: '<S50>/one_by_two' incorporates:
       *  MinMax: '<S50>/Max'
       *  MinMax: '<S50>/Min'
       *  Sum: '<S50>/Add'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum4_fv = (int16_T)(-(int16_T)(rtb_Sum4_fv + rtb_Sum5) >> 1);

      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* Switch: '<S8>/Switch for rotor alignment' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Constant: '<S8>/Constant'
       *  Gain: '<S49>/Gain'
       *  Gain: '<S50>/one_by_two'
       *  Gain: '<S8>/One_by_Two'
       *  Gain: '<S8>/Scale_to_PWM_Counter_PRD'
       *  Sum: '<S49>/Add1'
       *  Sum: '<S49>/Add2'
       *  Sum: '<S49>/Add3'
       *  Sum: '<S52>/add_b'
       *  Sum: '<S52>/add_c'
       *  Sum: '<S8>/Sum'
       */
      rtb_Get_Integer = (uint16_T)(((((int16_T)(((int16_T)(rtb_Sum1 +
        rtb_Sum4_fv) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */
      rtb_Saturationlowsideturnon_idx_1 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Switch2_hf + rtb_Sum4_fv) * 18919) >> 14) >> 1) + 8192) * 1601) >>
        14);
      rtb_Saturationlowsideturnon_idx_2 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Sum4_fv + rtb_Sum6) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);
    }

    /* End of Switch: '<S8>/Switch for Current offset calibration' */
  } else {
    rtb_Get_Integer = 0U;
    rtb_Saturationlowsideturnon_idx_1 = 0U;
    rtb_Saturationlowsideturnon_idx_2 = 0U;
  }

  /* End of Switch: '<S8>/Enable motor control' */

  /* Saturate: '<S6>/Saturation low side turn  on' incorporates:
   *  Bias: '<S6>/Dead time Compensation'
   */
  if ((uint16_T)(rtb_Get_Integer + 51U) > 1600) {
    /* DataStoreWrite: '<S1>/Data Store Write' */
    Pwm1Duty = 1600U;
  } else if ((uint16_T)(rtb_Get_Integer + 51U) < 102) {
    /* DataStoreWrite: '<S1>/Data Store Write' */
    Pwm1Duty = 102U;
  } else {
    /* DataStoreWrite: '<S1>/Data Store Write' */
    Pwm1Duty = (uint16_T)(rtb_Get_Integer + 51U);
  }

  if ((uint16_T)(rtb_Saturationlowsideturnon_idx_1 + 51U) > 1600) {
    /* DataStoreWrite: '<S1>/Data Store Write1' */
    Pwm2Duty = 1600U;
  } else if ((uint16_T)(rtb_Saturationlowsideturnon_idx_1 + 51U) < 102) {
    /* DataStoreWrite: '<S1>/Data Store Write1' */
    Pwm2Duty = 102U;
  } else {
    /* DataStoreWrite: '<S1>/Data Store Write1' */
    Pwm2Duty = (uint16_T)(rtb_Saturationlowsideturnon_idx_1 + 51U);
  }

  if ((uint16_T)(rtb_Saturationlowsideturnon_idx_2 + 51U) > 1600) {
    /* DataStoreWrite: '<S1>/Data Store Write2' */
    Pwm3Duty = 1600U;
  } else if ((uint16_T)(rtb_Saturationlowsideturnon_idx_2 + 51U) < 102) {
    /* DataStoreWrite: '<S1>/Data Store Write2' */
    Pwm3Duty = 102U;
  } else {
    /* DataStoreWrite: '<S1>/Data Store Write2' */
    Pwm3Duty = (uint16_T)(rtb_Saturationlowsideturnon_idx_2 + 51U);
  }

  /* End of Saturate: '<S6>/Saturation low side turn  on' */

  /* Product: '<S66>/Up' incorporates:
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Memory: '<S59>/Memory'
   *  Memory: '<S59>/Memory1'
   *  Product: '<S59>/Product2'
   *  Product: '<S59>/Product3'
   *  Product: '<S68>/Product'
   *  Sum: '<S66>/Add'
   */
  rtb_DataTypeConversion3_m = (int16_T)(((int16_T)((int16_T)
    ((MBD_FOC_SENSORLESS_MODEL_DW.Memory1_PreviousInput * rtb_Product_g) >> 14)
    - (int16_T)((rtb_DataTypeConversion3_m *
                 MBD_FOC_SENSORLESS_MODEL_DW.Memory_PreviousInput) >> 14)) * 41)
    >> 11);

  /* Sum: '<S66>/Add2' incorporates:
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Product: '<S66>/Product1'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  rtb_Product_g = (int16_T)((rtb_DataTypeConversion3_m >> 13) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_o);

  /* Switch: '<S67>/Switch2' incorporates:
   *  Constant: '<S62>/Ki3'
   *  RelationalOperator: '<S67>/LowerRelop1'
   *  RelationalOperator: '<S67>/UpperRelop'
   *  Sum: '<S66>/Add2'
   *  Sum: '<S68>/Sum5'
   *  Switch: '<S67>/Switch'
   */
  if (rtb_Product_g > 16384) {
    rtb_Sum5 = 16384;
  } else if (rtb_Product_g < -16384) {
    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S62>/Ki4'
     *  Sum: '<S68>/Sum5'
     */
    rtb_Sum5 = -16384;
  } else {
    rtb_Sum5 = rtb_Product_g;
  }

  /* End of Switch: '<S67>/Switch2' */

  /* Sum: '<S59>/PLL_preAng' incorporates:
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Sum: '<S66>/Add1'
   *  Sum: '<S68>/Sum5'
   *  UnitDelay: '<S59>/Unit Delay4'
   */
  rtb_Product_g = (int16_T)((rtb_DataTypeConversion3_m + rtb_Sum5) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay4_DSTATE);

  /* DataTypeConversion: '<S59>/Data Type Conversion3' incorporates:
   *  Sum: '<S59>/PLL_preAng'
   */
  rtb_DataTypeConversion3_m = (int16_T)(rtb_Product_g >> 2);

  /* Switch: '<S64>/Switch2' incorporates:
   *  Constant: '<S64>/2pi'
   *  DataTypeConversion: '<S59>/Data Type Conversion3'
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Sum: '<S64>/Sum'
   */
  if (rtb_DataTypeConversion3_m <= 0) {
    rtb_DataTypeConversion3_m = (int16_T)(rtb_DataTypeConversion3_m + 16384);
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Switch: '<S66>/Switch2' incorporates:
   *  DataStoreRead: '<S62>/Data Store Read1'
   *  DataStoreRead: '<S62>/Data Store Read2'
   *  Logic: '<S62>/AND'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC &&
      MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Update for UnitDelay: '<S66>/Unit Delay' incorporates:
     *  Sum: '<S68>/Sum5'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_o = rtb_Sum5;
  } else {
    /* Update for UnitDelay: '<S66>/Unit Delay' incorporates:
     *  Constant: '<S66>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_o = 0;
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Gain: '<S59>/ThetaPll' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion1'
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Math: '<S65>/Math Function'
   */
  rtb_DataTypeConversion3_m = (int16_T)((uint16_T)((uint16_T)
    rtb_DataTypeConversion3_m % 4096) << 2);

  /* Outputs for IfAction SubSystem: '<S69>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S72>/Action Port'
   */
  /* If: '<S69>/If' incorporates:
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Gain: '<S69>/convert_pu'
   */
  MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem1(rtb_DataTypeConversion3_m,
    &rtb_DataTypeConversion3_m);

  /* End of Outputs for SubSystem: '<S69>/If Action Subsystem1' */

  /* Gain: '<S63>/indexing' incorporates:
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Sum: '<S68>/Sum5'
   */
  rtb_Sum5 = (int16_T)((25 * rtb_DataTypeConversion3_m) >> 4);

  /* DataTypeConversion: '<S63>/Get_Integer' incorporates:
   *  Sum: '<S68>/Sum5'
   */
  rtb_Get_Integer = (uint16_T)(rtb_Sum5 >> 5);

  /* DataTypeConversion: '<S63>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S63>/Data Type Conversion1'
   *  Sum: '<S63>/Sum2'
   *  Sum: '<S68>/Sum5'
   */
  rtb_DataTypeConversion3_m = (int16_T)((int16_T)(rtb_Sum5 - (int16_T)((int16_T)
    rtb_Get_Integer << 5)) << 9);

  /* Update for UnitDelay: '<S55>/Unit Delay1' incorporates:
   *  Sum: '<S55>/Add8'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay1_DSTATE = rtb_Add8;

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Update for Delay: '<S1>/Delay' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Sum: '<S12>/sum_beta'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0] = rtb_ToPerUnit_idx_0;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1] = rtb_sum_beta;

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[2] = rtb_Sum1;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[3] = rtb_Switch_g0_idx_1;

  /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

  /* Update for UnitDelay: '<S55>/Unit Delay' incorporates:
   *  Sum: '<S55>/Add6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE = rtb_Add6;

  /* Update for UnitDelay: '<S55>/Unit Delay3' incorporates:
   *  Sum: '<S55>/Add8'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE = rtb_Add8;

  /* Update for UnitDelay: '<S55>/Unit Delay2' incorporates:
   *  Sum: '<S55>/Add6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay2_DSTATE = rtb_Add6;

  /* Update for UnitDelay: '<S60>/Unit Delay3' incorporates:
   *  Gain: '<S61>/Gain2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE_c = (int16_T)y;

  /* Update for Delay: '<S60>/Delay1' incorporates:
   *  DataTypeConversion: '<S60>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE = rtb_DataTypeConversion1;

  /* Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator4' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4;

  /* Switch: '<S37>/Switch2' incorporates:
   *  DataStoreRead: '<S18>/Data Store Read'
   *  DataStoreRead: '<S18>/Data Store Read1'
   *  Logic: '<S18>/AND'
   *  Switch: '<S34>/Switch2'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC &&
      MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Update for UnitDelay: '<S37>/Unit Delay' incorporates:
     *  Switch: '<S38>/Switch2'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_c = rtb_Switch2;

    /* Update for UnitDelay: '<S34>/Unit Delay' incorporates:
     *  Switch: '<S35>/Switch2'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_l = rtb_DataTypeConversion3;
  } else {
    /* Update for UnitDelay: '<S37>/Unit Delay' incorporates:
     *  Constant: '<S37>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_c = 0;

    /* Update for UnitDelay: '<S34>/Unit Delay' incorporates:
     *  Constant: '<S34>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_l = 0;
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Sum: '<S68>/Sum5' incorporates:
   *  Constant: '<S63>/offset'
   *  Constant: '<S63>/sine_table_values'
   *  Selector: '<S63>/Lookup'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S68>/Sum6'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11
    [(int32_T)(rtb_Get_Integer + 200U)];

  /* Update for Memory: '<S59>/Memory1' incorporates:
   *  Constant: '<S63>/offset'
   *  Constant: '<S63>/sine_table_values'
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Product: '<S68>/Product1'
   *  Selector: '<S63>/Lookup'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S68>/Sum5'
   *  Sum: '<S68>/Sum6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Memory1_PreviousInput = (int16_T)((int16_T)
    (((int16_T)(MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11[(int32_T)
                (rtb_Get_Integer + 201U)] - MBD_FOC_SENSORLESS_MODEL_B.u0) *
      rtb_DataTypeConversion3_m) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Sum: '<S68>/Sum3' incorporates:
   *  Constant: '<S63>/sine_table_values'
   *  Selector: '<S63>/Lookup'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S68>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11[rtb_Get_Integer];

  /* Update for Memory: '<S59>/Memory' incorporates:
   *  Constant: '<S63>/offset'
   *  Constant: '<S63>/sine_table_values'
   *  DataTypeConversion: '<S63>/Get_FractionVal'
   *  Product: '<S68>/Product'
   *  Selector: '<S63>/Lookup'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S68>/Sum3'
   *  Sum: '<S68>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Memory_PreviousInput = (int16_T)((int16_T)
    (((int16_T)(MBD_FOC_SENSORLESS_MODEL_ConstP.pooled11[(int32_T)
                (rtb_Get_Integer + 1U)] - MBD_FOC_SENSORLESS_MODEL_B.u0) *
      rtb_DataTypeConversion3_m) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Update for UnitDelay: '<S59>/Unit Delay4' incorporates:
   *  Sum: '<S59>/PLL_preAng'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay4_DSTATE = rtb_Product_g;
}

/* Model step function for TID1 */
void MBD_FOC_SENSORLESS_MODEL_step1(void) /* Sample time: [0.0015s, 0.0s] */
{
  real32_T rtb_RateTransition6;
  int16_T rtb_Switch2[2];
  int16_T rtb_RateTransition7;

  /* RateTransition: '<Root>/Rate Transition6' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  rtb_RateTransition6 = VelRef;

  /* RateTransition: '<Root>/Rate Transition7' incorporates:
   *  Gain: '<S55>/Gain9'
   */
  rtb_RateTransition7 = MBD_FOC_SENSORLESS_MODEL_B.Gain9;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  MBD_FOC_SENSORLESS_MODEL_SpeedControl(rtb_RateTransition6, rtb_RateTransition7,
    rtb_Switch2, &MBD_FOC_SENSORLESS_MODEL_DW.Enable,
    &MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop,
    &MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC,
    &MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef,
    &MBD_FOC_SENSORLESS_MODEL_DW.SpeedControl,
    &MBD_FOC_SENSORLESS_MODEL_PrevZCX.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* Update for RateTransition: '<Root>/Rate Transition5' incorporates:
   *  Switch: '<S4>/Switch2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer
    [(MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx == 0) << 1] =
    rtb_Switch2[0];
  MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[1 +
    ((MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx == 0) << 1)] =
    rtb_Switch2[1];
  MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx = (int8_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx == 0);
}

/* Model initialize function */
void MbdFocSensorlessInit(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE = POS_ZCSIG;
}

/* Model terminate function */
void MBD_FOC_SENSORLESS_MODEL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
