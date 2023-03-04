/*
 * File: MBD_FOC_SENSORLESS_MODEL.c
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

#include "MBD_FOC_SENSORLESS_MODEL.h"
#include "rtwtypes.h"
#include "MBD_FOC_SENSORLESS_MODEL_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S157>/Chart' */
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
static int16_T MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En11_Ys16En13_f_pw_cordic11
  (int16_T u0, int16_T u1);
static int16_T MBD_FOC_SENSORLESS_MODEL_rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s
  (int16_T u);
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

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T in1Lo;
  uint32_T outBitsLo;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  return u32_chi >> aShift;
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

/* Output and update for atomic system: '<Root>/Speed Control' */
void MBD_FOC_SENSORLESS_MODEL_SpeedControl(real32_T rtu_Speed_Ref_PU, int16_T
  rtu_Speed_Meas_PU, int16_T *rty_IdqRef_PU, int16_T *rty_IdqRef_PU_k, const
  boolean_T *rtd_Enable, const boolean_T *rtd_EnableClosedLoop, const boolean_T *
  rtd_EnableFOC, int16_T *rtd_SpeedRef,
  DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localDW,
  ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localZCE)
{
  real32_T rtb_RateLimiter2;
  int16_T rtb_DataTypeConversion1_c;
  int16_T rtb_IProdOut_e;
  int16_T rtb_Sum_j;
  int16_T rtb_Sum_oz;
  int8_T rtb_Switch1_h;
  int8_T tmp;
  boolean_T rtb_LogicalOperator_d;
  boolean_T rtb_RelationalOperator_b;

  /* RateLimiter: '<S3>/Rate Limiter2' */
  rtb_RateLimiter2 = rtu_Speed_Ref_PU - localDW->PrevY;
  if (rtb_RateLimiter2 > 0.00075F) {
    rtb_RateLimiter2 = localDW->PrevY + 0.00075F;
  } else if (rtb_RateLimiter2 < -0.0003F) {
    rtb_RateLimiter2 = localDW->PrevY - 0.0003F;
  } else {
    rtb_RateLimiter2 = rtu_Speed_Ref_PU;
  }

  localDW->PrevY = rtb_RateLimiter2;

  /* End of RateLimiter: '<S3>/Rate Limiter2' */

  /* Switch: '<S174>/Switch' incorporates:
   *  Constant: '<S174>/Constant'
   *  DataStoreRead: '<S174>/Data Store Read1'
   *  DataStoreWrite: '<S3>/Data Store Write'
   */
  if (*rtd_EnableFOC) {
    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    rtb_RateLimiter2 = (real32_T)floor(rtb_RateLimiter2 * 16384.0F);
    if (rtIsNaNF(rtb_RateLimiter2) || rtIsInfF(rtb_RateLimiter2)) {
      rtb_RateLimiter2 = 0.0F;
    } else {
      rtb_RateLimiter2 = (real32_T)fmod(rtb_RateLimiter2, 65536.0);
    }

    rtb_DataTypeConversion1_c = (int16_T)(rtb_RateLimiter2 < 0.0F ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_RateLimiter2 : (int32_T)(int16_T)
      (uint16_T)rtb_RateLimiter2);

    /* End of DataTypeConversion: '<S3>/Data Type Conversion1' */

    /* Saturate: '<S3>/Saturation' incorporates:
     *  DataStoreWrite: '<S3>/Data Store Write'
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     *  Switch: '<S174>/Switch'
     */
    if (rtb_DataTypeConversion1_c > 11800) {
      *rtd_SpeedRef = 11800;
    } else if (rtb_DataTypeConversion1_c < 2950) {
      *rtd_SpeedRef = 2950;
    } else {
      *rtd_SpeedRef = rtb_DataTypeConversion1_c;
    }

    /* End of Saturate: '<S3>/Saturation' */
  } else {
    *rtd_SpeedRef = 0;
  }

  /* End of Switch: '<S174>/Switch' */

  /* Constant: '<S3>/Id_ref' */
  *rty_IdqRef_PU = 0;

  /* Sum: '<S231>/Add1' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write'
   *  Product: '<S231>/Product'
   *  Product: '<S231>/Product1'
   *  Switch: '<S174>/Switch'
   *  UnitDelay: '<S231>/Unit Delay'
   */
  rtb_DataTypeConversion1_c = (int16_T)(((*rtd_SpeedRef * 123) >> 12) + ((3973 *
    localDW->UnitDelay_DSTATE) >> 12));

  /* Sum: '<S173>/Sum' incorporates:
   *  Sum: '<S231>/Add1'
   */
  rtb_Sum_j = (int16_T)(rtb_DataTypeConversion1_c - rtu_Speed_Meas_PU);

  /* Logic: '<S173>/Logical Operator' incorporates:
   *  DataStoreRead: '<S173>/Data Store Read1'
   *  DataStoreRead: '<S173>/Data Store Read2'
   *  Logic: '<S173>/AND'
   */
  rtb_LogicalOperator_d = ((!*rtd_EnableClosedLoop) || (!*rtd_Enable));

  /* DiscreteIntegrator: '<S212>/Integrator' incorporates:
   *  Constant: '<S173>/Ki2'
   */
  if (rtb_LogicalOperator_d || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0;
  }

  /* Sum: '<S221>/Sum' incorporates:
   *  DiscreteIntegrator: '<S212>/Integrator'
   *  Product: '<S217>/PProd Out'
   *  Sum: '<S173>/Sum'
   */
  rtb_Sum_oz = (int16_T)(((rtb_Sum_j * 461) >> 10) + localDW->Integrator_DSTATE);

  /* DeadZone: '<S205>/DeadZone' incorporates:
   *  Product: '<S209>/IProd Out'
   *  Sum: '<S221>/Sum'
   */
  if (rtb_Sum_oz > 16384) {
    rtb_IProdOut_e = (int16_T)(rtb_Sum_oz - 16384);
  } else if (rtb_Sum_oz >= -16384) {
    rtb_IProdOut_e = 0;
  } else {
    rtb_IProdOut_e = (int16_T)(rtb_Sum_oz - -16384);
  }

  /* End of DeadZone: '<S205>/DeadZone' */

  /* RelationalOperator: '<S203>/Relational Operator' incorporates:
   *  Product: '<S209>/IProd Out'
   */
  rtb_RelationalOperator_b = (rtb_IProdOut_e != 0);

  /* Switch: '<S203>/Switch1' incorporates:
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant2'
   *  Product: '<S209>/IProd Out'
   *  RelationalOperator: '<S203>/fix for DT propagation issue'
   */
  if (rtb_IProdOut_e > 0) {
    rtb_Switch1_h = 1;
  } else {
    rtb_Switch1_h = -1;
  }

  /* End of Switch: '<S203>/Switch1' */

  /* Product: '<S209>/IProd Out' incorporates:
   *  Sum: '<S173>/Sum'
   */
  rtb_IProdOut_e = (int16_T)((rtb_Sum_j * 53) >> 12);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Iq_ref1'
   *  DataStoreRead: '<S3>/Data Store Read'
   *  Saturate: '<S219>/Saturation'
   */
  if (*rtd_EnableClosedLoop) {
    /* Saturate: '<S219>/Saturation' incorporates:
     *  Sum: '<S221>/Sum'
     */
    if (rtb_Sum_oz > 16384) {
      *rty_IdqRef_PU_k = 16384;
    } else if (rtb_Sum_oz < -16384) {
      *rty_IdqRef_PU_k = -16384;
    } else {
      *rty_IdqRef_PU_k = rtb_Sum_oz;
    }
  } else {
    *rty_IdqRef_PU_k = 2507;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Outputs for Triggered SubSystem: '<S175>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S176>/Trigger'
   */
  /* Constant: '<S175>/Constant' */
  localZCE->TriggeredSubsystem_Trig_ZCE = 1U;

  /* End of Outputs for SubSystem: '<S175>/Triggered Subsystem' */

  /* Update for UnitDelay: '<S231>/Unit Delay' incorporates:
   *  Sum: '<S231>/Add1'
   */
  localDW->UnitDelay_DSTATE = rtb_DataTypeConversion1_c;

  /* Switch: '<S203>/Switch2' incorporates:
   *  Constant: '<S203>/Constant3'
   *  Constant: '<S203>/Constant4'
   *  Product: '<S209>/IProd Out'
   *  RelationalOperator: '<S203>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_e > 0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S203>/Switch' incorporates:
   *  Constant: '<S203>/Constant1'
   *  Logic: '<S203>/AND3'
   *  RelationalOperator: '<S203>/Equal1'
   *  Switch: '<S203>/Switch2'
   */
  if (rtb_RelationalOperator_b && (rtb_Switch1_h == tmp)) {
    rtb_IProdOut_e = 0;
  }

  /* Update for DiscreteIntegrator: '<S212>/Integrator' incorporates:
   *  Switch: '<S203>/Switch'
   */
  localDW->Integrator_DSTATE += rtb_IProdOut_e;
  localDW->Integrator_PrevResetState = (int8_T)rtb_LogicalOperator_d;
}

static int16_T MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En11_Ys16En13_f_pw_cordic11
  (int16_T u0, int16_T u1)
{
  int32_T idx;
  int16_T y;
  boolean_T x_quad_adjust;
  boolean_T y_nonzero;
  boolean_T y_quad_adjust;
  static const int16_T atan2_cordicLUT_n11_s16En13[11] = { 6434, 3798, 2007,
    1019, 511, 256, 128, 64, 32, 16, 8 };

  for (MBD_FOC_SENSORLESS_MODEL_B.ytmp = 0; MBD_FOC_SENSORLESS_MODEL_B.ytmp < 11;
       MBD_FOC_SENSORLESS_MODEL_B.ytmp++) {
    MBD_FOC_SENSORLESS_MODEL_B.u3[MBD_FOC_SENSORLESS_MODEL_B.ytmp] =
      atan2_cordicLUT_n11_s16En13[MBD_FOC_SENSORLESS_MODEL_B.ytmp];
  }

  if (u0 < 0) {
    MBD_FOC_SENSORLESS_MODEL_B.yAcc = -u0;
    y_quad_adjust = true;
    y_nonzero = true;
  } else {
    MBD_FOC_SENSORLESS_MODEL_B.yAcc = u0;
    y_quad_adjust = false;
    y_nonzero = (u0 > 0);
  }

  if (u1 < 0) {
    MBD_FOC_SENSORLESS_MODEL_B.xAcc = -u1;
    x_quad_adjust = true;
  } else {
    MBD_FOC_SENSORLESS_MODEL_B.xAcc = u1;
    x_quad_adjust = false;
  }

  y = 0;
  MBD_FOC_SENSORLESS_MODEL_B.xtmp = MBD_FOC_SENSORLESS_MODEL_B.xAcc;
  MBD_FOC_SENSORLESS_MODEL_B.ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc;
  for (idx = 0; idx < 11; idx++) {
    if (MBD_FOC_SENSORLESS_MODEL_B.yAcc < 0) {
      MBD_FOC_SENSORLESS_MODEL_B.ytmp = MBD_FOC_SENSORLESS_MODEL_B.xAcc -
        MBD_FOC_SENSORLESS_MODEL_B.ytmp;
      MBD_FOC_SENSORLESS_MODEL_B.xAcc = ((uint32_T)
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131072U) != 0U ?
        MBD_FOC_SENSORLESS_MODEL_B.ytmp | -131072 :
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131071;
      MBD_FOC_SENSORLESS_MODEL_B.ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc +
        MBD_FOC_SENSORLESS_MODEL_B.xtmp;
      MBD_FOC_SENSORLESS_MODEL_B.yAcc = ((uint32_T)
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131072U) != 0U ?
        MBD_FOC_SENSORLESS_MODEL_B.ytmp | -131072 :
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131071;
      y -= MBD_FOC_SENSORLESS_MODEL_B.u3[(int16_T)(idx + 1) - 1];
    } else {
      MBD_FOC_SENSORLESS_MODEL_B.ytmp += MBD_FOC_SENSORLESS_MODEL_B.xAcc;
      MBD_FOC_SENSORLESS_MODEL_B.xAcc = ((uint32_T)
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131072U) != 0U ?
        MBD_FOC_SENSORLESS_MODEL_B.ytmp | -131072 :
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131071;
      MBD_FOC_SENSORLESS_MODEL_B.ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc -
        MBD_FOC_SENSORLESS_MODEL_B.xtmp;
      MBD_FOC_SENSORLESS_MODEL_B.yAcc = ((uint32_T)
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131072U) != 0U ?
        MBD_FOC_SENSORLESS_MODEL_B.ytmp | -131072 :
        MBD_FOC_SENSORLESS_MODEL_B.ytmp & 131071;
      y += MBD_FOC_SENSORLESS_MODEL_B.u3[(int16_T)(idx + 1) - 1];
    }

    MBD_FOC_SENSORLESS_MODEL_B.xtmp = MBD_FOC_SENSORLESS_MODEL_B.xAcc >>
      (int16_T)(idx + 1);
    MBD_FOC_SENSORLESS_MODEL_B.ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc >>
      (int16_T)(idx + 1);
  }

  if (y_nonzero) {
    if (x_quad_adjust) {
      if (y_quad_adjust) {
        MBD_FOC_SENSORLESS_MODEL_B.ytmp = y - 25736;
        if (y - 25736 < -32768) {
          MBD_FOC_SENSORLESS_MODEL_B.ytmp = -32768;
        }

        y = (int16_T)MBD_FOC_SENSORLESS_MODEL_B.ytmp;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.ytmp = 25736 - y;
        if (25736 - y > 32767) {
          MBD_FOC_SENSORLESS_MODEL_B.ytmp = 32767;
        }

        y = (int16_T)MBD_FOC_SENSORLESS_MODEL_B.ytmp;
      }
    } else if (y_quad_adjust) {
      MBD_FOC_SENSORLESS_MODEL_B.ytmp = -y;
      if (-y > 32767) {
        MBD_FOC_SENSORLESS_MODEL_B.ytmp = 32767;
      }

      y = (int16_T)MBD_FOC_SENSORLESS_MODEL_B.ytmp;
    }
  } else if (x_quad_adjust) {
    y = 25736;
  } else {
    y = 0;
  }

  return y;
}

static int16_T MBD_FOC_SENSORLESS_MODEL_rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s
  (int16_T u)
{
  int32_T iBit;
  int16_T shiftMask;
  int16_T tmp01_y;
  int16_T y;

  /* Fixed-Point Sqrt Computation by the bisection method. */
  if (u > 0) {
    y = 0;
    shiftMask = 16384;
    MBD_FOC_SENSORLESS_MODEL_B.tmp03_u = u << 14;
    for (iBit = 0; iBit < 15; iBit++) {
      tmp01_y = (int16_T)(y | shiftMask);
      if (tmp01_y * tmp01_y <= MBD_FOC_SENSORLESS_MODEL_B.tmp03_u) {
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
  int16_T maxV;
  int16_T rtb_DataTypeConversion1;
  int16_T rtb_DataTypeConversion2;
  int16_T rtb_DataTypeConversion3;
  int16_T rtb_DataTypeConversion3_d;
  int16_T rtb_DataTypeConversion3_g;
  int16_T rtb_DataTypeConversion4;
  int16_T rtb_DataTypeConversion5;
  int16_T rtb_DataTypeConversion6;
  int16_T rtb_DeadZone;
  int16_T rtb_DeadZone_j;
  int16_T rtb_Gain_d;
  int16_T rtb_IProdOut;
  int16_T rtb_Saturation;
  int16_T rtb_Saturation_i;
  int16_T rtb_Sum1;
  int16_T rtb_Sum4_f;
  int16_T rtb_Sum6;
  int16_T rtb_ToPerUnit_idx_0;
  int16_T rtb_ToPerUnit_idx_1;
  int16_T rtb_z;
  int16_T rtb_z_n;
  uint16_T rtb_Get_Integer;
  uint16_T rtb_Saturationlowsideturnon_idx_1;
  uint16_T rtb_Saturationlowsideturnon_idx_2;
  uint16_T y;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_Compare;
  boolean_T rtb_LogicalOperator_tmp;

  /* Outputs for Enabled SubSystem: '<S149>/Up Counter' incorporates:
   *  EnablePort: '<S151>/Enable'
   */
  /* Logic: '<S149>/NOT' incorporates:
   *  Delay: '<S149>/Delay'
   */
  if (!MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_n) {
    if (!MBD_FOC_SENSORLESS_MODEL_DW.UpCounter_MODE) {
      /* InitializeConditions for Delay: '<S151>/Delay' */
      MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE = 0U;
      MBD_FOC_SENSORLESS_MODEL_DW.UpCounter_MODE = true;
    }

    /* Sum: '<S151>/Add1' incorporates:
     *  Delay: '<S151>/Delay'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE +
      /*MW:OvSatOk*/ 1U;

    /* Sum: '<S151>/Add1' incorporates:
     *  Delay: '<S151>/Delay'
     */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE + 1U < 1U) {
      /* Sum: '<S151>/Add1' */
      MBD_FOC_SENSORLESS_MODEL_B.Add1 = MAX_uint32_T;
    }

    /* Update for Delay: '<S151>/Delay' */
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE = MBD_FOC_SENSORLESS_MODEL_B.Add1;
  } else {
    MBD_FOC_SENSORLESS_MODEL_DW.UpCounter_MODE = false;
  }

  /* End of Logic: '<S149>/NOT' */
  /* End of Outputs for SubSystem: '<S149>/Up Counter' */

  /* Gain: '<S150>/Gain' */
  rtb_Gain_d = (int16_T)mul_u32_hiSR(3518437209U,
    MBD_FOC_SENSORLESS_MODEL_B.Add1, 2U);

  /* RelationalOperator: '<S153>/Compare' incorporates:
   *  Gain: '<S150>/Gain'
   */
  rtb_Compare = (rtb_Gain_d < 4096);

  /* RateTransition: '<Root>/Rate Transition5' */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx << 1;
  MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[MBD_FOC_SENSORLESS_MODEL_B.Gain2];
  MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[MBD_FOC_SENSORLESS_MODEL_B.Gain2
    + 1];

  /* Outputs for Enabled SubSystem: '<S6>/Offset1' incorporates:
   *  EnablePort: '<S148>/Enable'
   */
  /* DataStoreRead: '<S6>/Data Store Read' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset) {
    /* SignalConversion generated from: '<S148>/Iab' incorporates:
     *  DataStoreRead: '<S6>/Data Store Read1'
     *  DataStoreRead: '<S6>/Data Store Read2'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Iab[0] = MBD_FOC_SENSORLESS_MODEL_DW.ADC_IA;
    MBD_FOC_SENSORLESS_MODEL_B.Iab[1] = MBD_FOC_SENSORLESS_MODEL_DW.ADC_IB;
  }

  /* End of DataStoreRead: '<S6>/Data Store Read' */
  /* End of Outputs for SubSystem: '<S6>/Offset1' */

  /* Gain: '<S6>/To Per-Unit' incorporates:
   *  DataStoreRead: '<S6>/Data Store Read1'
   *  DataStoreRead: '<S6>/Data Store Read2'
   *  Sum: '<S6>/Add2'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 = (int16_T)((int16_T)
    MBD_FOC_SENSORLESS_MODEL_DW.ADC_IA - (int16_T)
    MBD_FOC_SENSORLESS_MODEL_B.Iab[0]) * -10027;
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 = (int16_T)
    (((MBD_FOC_SENSORLESS_MODEL_B.Gain2 < 0 ? 2047 : 0) +
      MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 11) * 13405;
  rtb_ToPerUnit_idx_0 = (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.Gain2 < 0 ? 8191 :
    0) + MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 13);
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 = (int16_T)((int16_T)
    MBD_FOC_SENSORLESS_MODEL_DW.ADC_IB - (int16_T)
    MBD_FOC_SENSORLESS_MODEL_B.Iab[1]) * -10027;
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 = (int16_T)
    (((MBD_FOC_SENSORLESS_MODEL_B.Gain2 < 0 ? 2047 : 0) +
      MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 11) * 13405;
  rtb_ToPerUnit_idx_1 = (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.Gain2 < 0 ? 8191 :
    0) + MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 13);

  /* Outputs for Atomic SubSystem: '<S4>/Clarke Transform' */
  /* Gain: '<S9>/one_by_sqrt3' incorporates:
   *  Sum: '<S11>/sum_beta'
   *  Sum: '<S9>/a_plus_2b'
   */
  rtb_ToPerUnit_idx_1 = (int16_T)(((int16_T)((int16_T)(rtb_ToPerUnit_idx_0 +
    rtb_ToPerUnit_idx_1) + rtb_ToPerUnit_idx_1) * 18919) >> 15);

  /* End of Outputs for SubSystem: '<S4>/Clarke Transform' */

  /* Gain: '<S164>/Gain' incorporates:
   *  DataStoreRead: '<S8>/Data Store Read'
   *  DeadZone: '<S111>/DeadZone'
   *  Gain: '<S164>/Inverting OpAmp5'
   */
  rtb_DeadZone = (int16_T)((((2777 * MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef) >> 12)
    * 17157) >> 14);

  /* Abs: '<S163>/Abs' incorporates:
   *  DeadZone: '<S111>/DeadZone'
   */
  if (rtb_DeadZone < 0) {
    rtb_DeadZone = (int16_T)-rtb_DeadZone;
  }

  /* End of Abs: '<S163>/Abs' */

  /* DataTypeConversion: '<S163>/Data Type Conversion2' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator1'
   */
  rtb_DataTypeConversion2 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE >> 5);

  /* Sum: '<S163>/Sum' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion2'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S163>/Gain8'
   *  Gain: '<S164>/Inverting OpAmp1'
   */
  rtb_z_n = (int16_T)((rtb_DataTypeConversion2 >> 2) - ((26771 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[0]) >> 17));

  /* Saturate: '<S163>/Saturation' incorporates:
   *  Gain: '<S163>/Gain8'
   */
  if (rtb_z_n > 717) {
    rtb_z_n = 717;
  } else if (rtb_z_n < -717) {
    rtb_z_n = -717;
  }

  /* Gain: '<S163>/Gain10' incorporates:
   *  Saturate: '<S163>/Saturation'
   */
  rtb_z = (int16_T)((5 * rtb_z_n) >> 1);

  /* DiscreteIntegrator: '<S165>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion1'
   *  DeadZone: '<S111>/DeadZone'
   *  Delay: '<S165>/Delay'
   *  Gain: '<S163>/Gain10'
   *  Product: '<S165>/Product'
   *  Sum: '<S165>/Sum2'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator = mul_s32_hiSR(439804651,
    (int16_T)((rtb_z << 3) - MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_j) *
    rtb_DeadZone, 8U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_m;

  /* DataTypeConversion: '<S165>/Data Type Conversion3' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator'
   */
  rtb_DataTypeConversion3_g = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator >> 6);

  /* DiscreteIntegrator: '<S165>/Discrete-Time Integrator2' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion3'
   *  DeadZone: '<S111>/DeadZone'
   *  Delay: '<S165>/Delay3'
   *  Product: '<S165>/Product2'
   *  Sum: '<S165>/Sum3'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator2 = mul_s32_hiSR(439804651,
    (int16_T)(rtb_DataTypeConversion3_g -
              MBD_FOC_SENSORLESS_MODEL_DW.Delay3_DSTATE) * rtb_DeadZone, 8U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator2_DSTATE;

  /* DataTypeConversion: '<S165>/Data Type Conversion5' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator2'
   */
  rtb_DataTypeConversion5 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator2 >> 6);

  /* DataTypeConversion: '<S163>/Data Type Conversion3' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   */
  rtb_DataTypeConversion3_d = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_b >> 5);

  /* Sum: '<S163>/Sum2' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion3'
   *  Delay: '<S1>/Delay'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Gain: '<S164>/Inverting OpAmp2'
   */
  rtb_DataTypeConversion3 = (int16_T)((rtb_DataTypeConversion3_d >> 2) - ((26771
    * MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[1]) >> 17));

  /* Saturate: '<S163>/Saturation1' incorporates:
   *  DiscreteIntegrator: '<S118>/Integrator'
   */
  if (rtb_DataTypeConversion3 > 717) {
    rtb_DataTypeConversion3 = 717;
  } else if (rtb_DataTypeConversion3 < -717) {
    rtb_DataTypeConversion3 = -717;
  }

  /* Gain: '<S163>/Gain8' incorporates:
   *  Saturate: '<S163>/Saturation1'
   */
  rtb_z_n = (int16_T)((5 * rtb_DataTypeConversion3) >> 1);

  /* DiscreteIntegrator: '<S165>/Discrete-Time Integrator1' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion2'
   *  DeadZone: '<S111>/DeadZone'
   *  Delay: '<S165>/Delay1'
   *  Gain: '<S163>/Gain8'
   *  Product: '<S165>/Product1'
   *  Sum: '<S165>/Sum1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator1 = mul_s32_hiSR(439804651,
    ((int16_T)((rtb_z_n << 3) - MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE) *
     rtb_DeadZone) >> 3, 5U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE_i;

  /* DataTypeConversion: '<S165>/Data Type Conversion4' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator1'
   */
  rtb_DataTypeConversion4 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator1 >> 6);

  /* DiscreteIntegrator: '<S165>/Discrete-Time Integrator3' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion4'
   *  DeadZone: '<S111>/DeadZone'
   *  Delay: '<S165>/Delay2'
   *  Product: '<S165>/Product3'
   *  Sum: '<S165>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator3 = mul_s32_hiSR(439804651,
    (int16_T)(rtb_DataTypeConversion4 -
              MBD_FOC_SENSORLESS_MODEL_DW.Delay2_DSTATE) * rtb_DeadZone, 8U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator3_DSTATE;

  /* DataTypeConversion: '<S165>/Data Type Conversion6' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator3'
   */
  rtb_DataTypeConversion6 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator3 >> 6);

  /* DataTypeConversion: '<S167>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion5'
   *  DataTypeConversion: '<S165>/Data Type Conversion6'
   *  Gain: '<S167>/Gain3'
   *  Trigonometry: '<S167>/Trigonometric Function'
   */
  rtb_DataTypeConversion3 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En11_Ys16En13_f_pw_cordic11((int16_T)
      -rtb_DataTypeConversion5, rtb_DataTypeConversion6) >> 1);

  /* Switch: '<S169>/Switch2' incorporates:
   *  Constant: '<S169>/2pi'
   *  DataTypeConversion: '<S167>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Sum: '<S169>/Sum'
   */
  if (rtb_DataTypeConversion3 <= 0) {
    rtb_DataTypeConversion3 = (int16_T)(rtb_DataTypeConversion3 + 25736);
  }

  /* End of Switch: '<S169>/Switch2' */

  /* Math: '<S170>/Math Function' incorporates:
   *  Bias: '<S167>/Bias2'
   *  DiscreteIntegrator: '<S118>/Integrator'
   */
  y = (uint16_T)((uint16_T)(rtb_DataTypeConversion3 + 6434) % 25736);

  /* Gain: '<S163>/Gain3' incorporates:
   *  DataStoreWrite: '<S8>/Data Store Write'
   *  Gain: '<S167>/Gain2'
   */
  smoAnglePU = (int16_T)((20861 * (int16_T)y) >> 15);

  /* Sum: '<S166>/Sum2' incorporates:
   *  Gain: '<S167>/Gain2'
   *  UnitDelay: '<S166>/Unit Delay3'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = (int16_T)((int16_T)y -
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE) << 12;

  /* Bias: '<S168>/Bias' incorporates:
   *  Math: '<S168>/Math Function1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 =
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 - div_s32_floor
     (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4, 105414357) * 105414357)
    + 52707179;

  /* DiscreteIntegrator: '<S166>/Discrete-Time Integrator4' incorporates:
   *  Bias: '<S168>/Bias1'
   *  DeadZone: '<S111>/DeadZone'
   *  Delay: '<S166>/Delay1'
   *  Gain: '<S166>/Gain1'
   *  Gain: '<S166>/Gain3'
   *  Math: '<S168>/Math Function'
   *  Product: '<S166>/Product1'
   *  Sum: '<S166>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = mul_s32_hiSR(439804651,
    ((int16_T)(((int16_T)(((((MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4
    - div_s32_floor(MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4,
                    105414357) * 105414357) + -52707179) >> 12) * 625) >> 4) -
                (MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE_i << 1)) >> 1) *
     rtb_DeadZone) << 3, 11U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE;

  /* DataTypeConversion: '<S166>/Data Type Conversion1' incorporates:
   *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator4'
   */
  rtb_DataTypeConversion1 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 >> 6);

  /* Gain: '<S163>/Gain' incorporates:
   *  DataTypeConversion: '<S166>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain = (int16_T)((23077 * rtb_DataTypeConversion1) >>
    13);

  /* Chart: '<S157>/Chart' incorporates:
   *  DataStoreRead: '<S157>/Data Store Read5'
   *  Gain: '<S163>/Gain'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 < 65535U) {
    MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1++;
  }

  if (MBD_FOC_SENSORLESS_MODEL_DW.is_active_c3_MBD_FOC_SENSORLESS_MODEL == 0U) {
    MBD_FOC_SENSORLESS_MODEL_DW.is_active_c3_MBD_FOC_SENSORLESS_MODEL = 1U;
    MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
      MBD_FOC_SENSORLESS_MODEL_IN_Init;
  } else {
    switch (MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL) {
     case MBD_FOC_SENSORLESS_MODEL_IN_Align:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
      } else if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 10000U) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_OpenLoop;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 0U;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoop:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
      } else if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 2000U) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoopFilter;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 2U;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoopFilter:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 2U;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_Init:
      if (MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Align;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 0U;
      }
      break;

     default:
      /* case IN_OpenLoop: */
      if ((MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 40000U) &&
          (MBD_FOC_SENSORLESS_MODEL_B.Gain > 2950)) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoop;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S157>/Chart' */

  /* DataTypeConversion: '<S157>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S157>/Data Store Write2'
   *  Switch: '<S157>/Switch2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop =
    (MBD_FOC_SENSORLESS_MODEL_B.Mode > 1);

  /* Outputs for Resettable SubSystem: '<S8>/Openloop Pos_PU' incorporates:
   *  ResetPort: '<S156>/Reset'
   */
  /* DataStoreRead: '<S8>/Data Store Read2' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable &&
      (MBD_FOC_SENSORLESS_MODEL_PrevZCX.OpenloopPos_PU_Reset_ZCE != POS_ZCSIG))
  {
    /* Disable for Enabled SubSystem: '<S159>/Accumulate' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
      /* Disable for Sum: '<S160>/Add1' incorporates:
       *  Outport: '<S160>/theta_e'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Add1_k = 0;
      MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
    }

    /* End of Disable for SubSystem: '<S159>/Accumulate' */

    /* InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 0;

    /* InitializeConditions for UnitDelay: '<S159>/Unit Delay' */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE = 0;
  }

  MBD_FOC_SENSORLESS_MODEL_PrevZCX.OpenloopPos_PU_Reset_ZCE =
    MBD_FOC_SENSORLESS_MODEL_DW.Enable;

  /* End of DataStoreRead: '<S8>/Data Store Read2' */

  /* Outputs for Enabled SubSystem: '<S159>/Accumulate' incorporates:
   *  EnablePort: '<S160>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_ConstB.NOT) {
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = true;

    /* Outputs for Enabled SubSystem: '<S160>/Subsystem' incorporates:
     *  EnablePort: '<S161>/Enable'
     */
    /* Delay: '<S160>/Delay' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k) {
      /* SignalConversion generated from: '<S161>/Input' incorporates:
       *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
       *  Gain: '<S156>/Gain'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Input = (int16_T)mul_s32_loSR(12133,
        MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE, 26U);
    }

    /* End of Delay: '<S160>/Delay' */
    /* End of Outputs for SubSystem: '<S160>/Subsystem' */

    /* Sum: '<S160>/Add' incorporates:
     *  Product: '<S115>/IProd Out'
     *  SignalConversion generated from: '<S161>/Input'
     *  UnitDelay: '<S159>/Unit Delay'
     */
    rtb_IProdOut = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.Input +
      MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE);

    /* Sum: '<S160>/Add1' incorporates:
     *  DataTypeConversion: '<S160>/Data Type Conversion'
     *  DataTypeConversion: '<S160>/Data Type Conversion1'
     *  Product: '<S115>/IProd Out'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1_k = (int16_T)(rtb_IProdOut - ((rtb_IProdOut >>
      14) << 14));

    /* Update for Delay: '<S160>/Delay' incorporates:
     *  Constant: '<S160>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k = true;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
    /* Disable for Sum: '<S160>/Add1' incorporates:
     *  Outport: '<S160>/theta_e'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1_k = 0;
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S159>/Accumulate' */

  /* Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S156>/Data Type Conversion'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE += mul_s32_hiSR
    (274877907, MBD_FOC_SENSORLESS_MODEL_ConstB.DataTypeConversion, 5U);
  if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE >= 188797) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 188797;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE <= 0) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S159>/Unit Delay' incorporates:
   *  Sum: '<S160>/Add1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.Add1_k;

  /* End of Outputs for SubSystem: '<S8>/Openloop Pos_PU' */

  /* Switch: '<S8>/Switch' incorporates:
   *  DataStoreWrite: '<S157>/Data Store Write2'
   *  DataStoreWrite: '<S8>/Data Store Write'
   *  Gain: '<S159>/scaleOut'
   *  Gain: '<S163>/Gain3'
   *  Sum: '<S160>/Add1'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop) {
    rtb_DeadZone = smoAnglePU;
  } else {
    /* Outputs for Resettable SubSystem: '<S8>/Openloop Pos_PU' incorporates:
     *  ResetPort: '<S156>/Reset'
     */
    rtb_DeadZone = MBD_FOC_SENSORLESS_MODEL_B.Add1_k;

    /* End of Outputs for SubSystem: '<S8>/Openloop Pos_PU' */
  }

  /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem' incorporates:
   *  ActionPort: '<S140>/Action Port'
   */
  /* If: '<S138>/If' incorporates:
   *  DataTypeConversion: '<S140>/Convert_back'
   *  DataTypeConversion: '<S140>/Convert_uint16'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Gain: '<S13>/indexing'
   *  Sum: '<S140>/Sum'
   *  Switch: '<S8>/Switch'
   */
  rtb_DataTypeConversion3 = (int16_T)(((int16_T)(rtb_DeadZone - ((rtb_DeadZone >>
    14) << 14)) * 25) >> 4);

  /* End of Outputs for SubSystem: '<S138>/If Action Subsystem' */

  /* DataTypeConversion: '<S13>/Get_Integer' incorporates:
   *  DiscreteIntegrator: '<S118>/Integrator'
   */
  rtb_Get_Integer = (uint16_T)(rtb_DataTypeConversion3 >> 5);

  /* DataTypeConversion: '<S13>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Sum: '<S13>/Sum2'
   */
  rtb_DataTypeConversion3 = (int16_T)((int16_T)(rtb_DataTypeConversion3 -
    (int16_T)((int16_T)rtb_Get_Integer << 5)) << 9);

  /* Sum: '<S137>/Sum3' incorporates:
   *  Constant: '<S13>/sine_table_values'
   *  Selector: '<S13>/Lookup'
   *  Sum: '<S137>/Sum4'
   *  Sum: '<S13>/Sum'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[rtb_Get_Integer];

  /* Sum: '<S137>/Sum4' incorporates:
   *  Constant: '<S13>/offset'
   *  Constant: '<S13>/sine_table_values'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Product: '<S137>/Product'
   *  Selector: '<S13>/Lookup'
   *  Sum: '<S137>/Sum3'
   *  Sum: '<S13>/Sum'
   */
  rtb_Sum4_f = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[(int32_T)
     (rtb_Get_Integer + 1U)] - MBD_FOC_SENSORLESS_MODEL_B.Gain2) *
    rtb_DataTypeConversion3) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.Gain2);

  /* Sum: '<S137>/Sum5' incorporates:
   *  Constant: '<S13>/offset'
   *  Constant: '<S13>/sine_table_values'
   *  Selector: '<S13>/Lookup'
   *  Sum: '<S137>/Sum6'
   *  Sum: '<S13>/Sum'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[(int32_T)
    (rtb_Get_Integer + 200U)];

  /* Sum: '<S137>/Sum6' incorporates:
   *  Constant: '<S13>/offset'
   *  Constant: '<S13>/sine_table_values'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Product: '<S137>/Product1'
   *  Selector: '<S13>/Lookup'
   *  Sum: '<S137>/Sum5'
   *  Sum: '<S13>/Sum'
   */
  rtb_Sum6 = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[(int32_T)
     (rtb_Get_Integer + 201U)] - MBD_FOC_SENSORLESS_MODEL_B.Gain2) *
    rtb_DataTypeConversion3) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.Gain2);

  /* Outputs for Atomic SubSystem: '<S4>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S4>/Clarke Transform' */
  /* Sum: '<S17>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Product: '<S12>/asin'
   *  Product: '<S12>/bcos'
   *  Sum: '<S11>/sum_beta'
   *  Sum: '<S12>/sum_Qs'
   *  Sum: '<S137>/Sum4'
   *  Sum: '<S137>/Sum6'
   */
  rtb_DataTypeConversion3 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] - (int16_T)((int16_T)
      ((rtb_ToPerUnit_idx_1 * rtb_Sum6) >> 14) - (int16_T)((rtb_ToPerUnit_idx_0 *
        rtb_Sum4_f) >> 14)));

  /* End of Outputs for SubSystem: '<S4>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S4>/Park Transform' */

  /* Logic: '<S17>/Logical Operator' incorporates:
   *  DataStoreRead: '<S17>/Data Store Read'
   *  DataStoreRead: '<S17>/Data Store Read1'
   *  Logic: '<S16>/AND'
   *  Logic: '<S16>/Logical Operator'
   *  Logic: '<S17>/AND'
   */
  rtb_LogicalOperator_tmp = ((!MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC) ||
    (!MBD_FOC_SENSORLESS_MODEL_DW.Enable));

  /* DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Constant: '<S17>/Kp1'
   *  Logic: '<S17>/AND'
   *  Logic: '<S17>/Logical Operator'
   */
  if (rtb_LogicalOperator_tmp ||
      (MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState != 0)) {
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE = 0;
  }

  /* Sum: '<S127>/Sum' incorporates:
   *  DeadZone: '<S111>/DeadZone'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Product: '<S123>/PProd Out'
   *  Sum: '<S17>/Sum'
   */
  rtb_DeadZone = (int16_T)(((rtb_DataTypeConversion3 * 693) >> 11) +
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE);

  /* Saturate: '<S125>/Saturation' incorporates:
   *  DeadZone: '<S111>/DeadZone'
   */
  if (rtb_DeadZone > 16384) {
    rtb_Saturation = 16384;
  } else if (rtb_DeadZone < -16384) {
    rtb_Saturation = -16384;
  } else {
    rtb_Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S125>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S4>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S4>/Clarke Transform' */
  /* Sum: '<S16>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Product: '<S12>/acos'
   *  Product: '<S12>/bsin'
   *  Sum: '<S11>/sum_beta'
   *  Sum: '<S12>/sum_Ds'
   *  Sum: '<S137>/Sum4'
   *  Sum: '<S137>/Sum6'
   */
  rtb_IProdOut = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] -
    (int16_T)((int16_T)((rtb_ToPerUnit_idx_0 * rtb_Sum6) >> 14) + (int16_T)
              ((rtb_ToPerUnit_idx_1 * rtb_Sum4_f) >> 14)));

  /* End of Outputs for SubSystem: '<S4>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S4>/Park Transform' */

  /* DiscreteIntegrator: '<S67>/Integrator' incorporates:
   *  Constant: '<S16>/Ki1'
   */
  if (rtb_LogicalOperator_tmp ||
      (MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState_b != 0)) {
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE_d = 0;
  }

  /* Sum: '<S76>/Sum' incorporates:
   *  DeadZone: '<S60>/DeadZone'
   *  DiscreteIntegrator: '<S67>/Integrator'
   *  Product: '<S72>/PProd Out'
   *  Sum: '<S16>/Sum'
   */
  rtb_DeadZone_j = (int16_T)(((rtb_IProdOut * 693) >> 11) +
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE_d);

  /* Saturate: '<S74>/Saturation' incorporates:
   *  DeadZone: '<S60>/DeadZone'
   */
  if (rtb_DeadZone_j > 16384) {
    rtb_Saturation_i = 16384;
  } else if (rtb_DeadZone_j < -16384) {
    rtb_Saturation_i = -16384;
  } else {
    rtb_Saturation_i = rtb_DeadZone_j;
  }

  /* End of Saturate: '<S74>/Saturation' */

  /* Sum: '<S21>/Sum1' incorporates:
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   *  Saturate: '<S125>/Saturation'
   *  Saturate: '<S74>/Saturation'
   */
  rtb_Sum1 = (int16_T)(((rtb_Saturation_i * rtb_Saturation_i) >> 14) +
                       ((rtb_Saturation * rtb_Saturation) >> 14));

  /* Outputs for IfAction SubSystem: '<S15>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S18>/Action Port'
   */
  /* If: '<S18>/If' incorporates:
   *  If: '<S15>/If'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Sum: '<S21>/Sum1'
   */
  if (rtb_Sum1 >= 14786) {
    /* Outputs for IfAction SubSystem: '<S18>/Limiter' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* Sqrt: '<S22>/Square Root' incorporates:
     *  Switch: '<S22>/Switch'
     */
    rtb_Sum1 = MBD_FOC_SENSORLESS_MODEL_rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s
      (rtb_Sum1);

    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant'
     */
    if (rtb_Sum1 == 0) {
      rtb_Sum1 = 16384;
    }

    /* Product: '<S22>/Reciprocal' incorporates:
     *  Switch: '<S22>/Switch'
     */
    if (rtb_Sum1 == 0) {
      MBD_FOC_SENSORLESS_MODEL_B.Gain2 = MAX_int32_T;

      /* Divide by zero handler */
    } else {
      MBD_FOC_SENSORLESS_MODEL_B.Gain2 = 268435456 / rtb_Sum1;
    }

    if (MBD_FOC_SENSORLESS_MODEL_B.Gain2 > 32767) {
      MBD_FOC_SENSORLESS_MODEL_B.Gain2 = 32767;
    } else if (MBD_FOC_SENSORLESS_MODEL_B.Gain2 < -32768) {
      MBD_FOC_SENSORLESS_MODEL_B.Gain2 = -32768;
    }

    /* Product: '<S22>/Product1' incorporates:
     *  Constant: '<S20>/Constant3'
     *  Merge: '<S15>/Merge'
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Reciprocal'
     *  Switch: '<S20>/Switch'
     */
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] = (int16_T)
      ((((rtb_Saturation_i * 15565) >> 14) * (int16_T)
        MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 14);
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] = (int16_T)((((rtb_Saturation *
      15565) >> 14) * (int16_T)MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 14);

    /* End of Outputs for SubSystem: '<S18>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/Passthrough' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* SignalConversion generated from: '<S23>/dqRef' incorporates:
     *  Merge: '<S15>/Merge'
     */
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] = rtb_Saturation_i;
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] = rtb_Saturation;

    /* End of Outputs for SubSystem: '<S18>/Passthrough' */
  }

  /* End of If: '<S18>/If' */
  /* End of Outputs for SubSystem: '<S15>/D-Q Equivalence' */

  /* Outputs for Atomic SubSystem: '<S4>/Inverse Park Transform' */
  /* Switch: '<S135>/Switch' incorporates:
   *  Product: '<S11>/dcos'
   *  Product: '<S11>/dsin'
   *  Product: '<S11>/qcos'
   *  Product: '<S11>/qsin'
   *  Sum: '<S11>/sum_alpha'
   *  Sum: '<S11>/sum_beta'
   *  Sum: '<S137>/Sum4'
   *  Sum: '<S137>/Sum6'
   */
  rtb_Saturation_i = (int16_T)((int16_T)
    ((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] * rtb_Sum6) >> 14) -
    (int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] * rtb_Sum4_f) >> 14));
  rtb_Sum1 = (int16_T)((int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] *
    rtb_Sum6) >> 14) + (int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] *
    rtb_Sum4_f) >> 14));

  /* End of Outputs for SubSystem: '<S4>/Inverse Park Transform' */

  /* Switch: '<S7>/Enable motor control' incorporates:
   *  Constant: '<S7>/Constant2'
   *  DataStoreRead: '<S7>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Switch: '<S7>/Switch for Current offset calibration' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Gain: '<S150>/Gain'
     *  Logic: '<S150>/AND'
     *  RelationalOperator: '<S154>/Compare'
     *  RelationalOperator: '<S155>/Compare'
     *  Switch: '<S7>/Switch for rotor alignment'
     */
    if (rtb_Compare) {
      rtb_Get_Integer = 0U;
      rtb_Saturationlowsideturnon_idx_1 = 0U;
      rtb_Saturationlowsideturnon_idx_2 = 0U;
    } else if ((rtb_Gain_d > 4096) && (rtb_Gain_d < 8192)) {
      /* Switch: '<S7>/Switch for rotor alignment' incorporates:
       *  Constant: '<S7>/Constant3'
       *  Constant: '<S7>/Constant4'
       */
      rtb_Get_Integer = 532U;
      rtb_Saturationlowsideturnon_idx_1 = 343U;
      rtb_Saturationlowsideturnon_idx_2 = 343U;
    } else {
      /* Outputs for Atomic SubSystem: '<S4>/Inverse Park Transform' */
      /* Gain: '<S147>/sqrt3_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
       *  MinMax: '<S145>/Max'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      rtb_Saturation = (int16_T)((14189 * rtb_Sum1) >> 14);

      /* Gain: '<S147>/one_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
       *  Gain: '<S145>/one_by_two'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      rtb_Sum4_f = (int16_T)(rtb_Saturation_i >> 1);

      /* End of Outputs for SubSystem: '<S4>/Inverse Park Transform' */

      /* Sum: '<S147>/add_c' incorporates:
       *  Gain: '<S145>/one_by_two'
       *  MinMax: '<S145>/Max'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      rtb_Sum6 = (int16_T)(-rtb_Sum4_f - rtb_Saturation);

      /* Sum: '<S147>/add_b' incorporates:
       *  Gain: '<S145>/one_by_two'
       *  MinMax: '<S145>/Max'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      rtb_Saturation -= rtb_Sum4_f;

      /* Outputs for Atomic SubSystem: '<S4>/Inverse Park Transform' */
      /* MinMax: '<S145>/Min' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
       *  Sum: '<S147>/add_b'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      if (rtb_Saturation_i <= rtb_Saturation) {
        rtb_Sum4_f = rtb_Saturation_i;
      } else {
        rtb_Sum4_f = rtb_Saturation;
      }

      /* MinMax: '<S145>/Max' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
       *  Sum: '<S147>/add_b'
       *  Sum: '<S147>/add_c'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      if (rtb_Saturation_i >= rtb_Saturation) {
        maxV = rtb_Saturation_i;
      } else {
        maxV = rtb_Saturation;
      }

      /* End of Outputs for SubSystem: '<S4>/Inverse Park Transform' */
      if (maxV < rtb_Sum6) {
        maxV = rtb_Sum6;
      }

      /* MinMax: '<S145>/Min' incorporates:
       *  Sum: '<S147>/add_c'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      if (rtb_Sum4_f > rtb_Sum6) {
        rtb_Sum4_f = rtb_Sum6;
      }

      /* Gain: '<S145>/one_by_two' incorporates:
       *  MinMax: '<S145>/Max'
       *  MinMax: '<S145>/Min'
       *  Sum: '<S145>/Add'
       *  Switch: '<S7>/Switch for rotor alignment'
       */
      rtb_Sum4_f = (int16_T)(-(int16_T)(maxV + rtb_Sum4_f) >> 1);

      /* Outputs for Atomic SubSystem: '<S4>/Inverse Park Transform' */
      /* Switch: '<S7>/Switch for rotor alignment' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
       *  Constant: '<S7>/Constant'
       *  Gain: '<S144>/Gain'
       *  Gain: '<S145>/one_by_two'
       *  Gain: '<S7>/One_by_Two'
       *  Gain: '<S7>/Scale_to_PWM_Counter_PRD'
       *  Sum: '<S144>/Add1'
       *  Sum: '<S144>/Add2'
       *  Sum: '<S144>/Add3'
       *  Sum: '<S147>/add_b'
       *  Sum: '<S147>/add_c'
       *  Sum: '<S7>/Sum'
       */
      rtb_Get_Integer = (uint16_T)(((((int16_T)(((int16_T)(rtb_Saturation_i +
        rtb_Sum4_f) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);

      /* End of Outputs for SubSystem: '<S4>/Inverse Park Transform' */
      rtb_Saturationlowsideturnon_idx_1 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Saturation + rtb_Sum4_f) * 18919) >> 14) >> 1) + 8192) * 1601) >>
        14);
      rtb_Saturationlowsideturnon_idx_2 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Sum4_f + rtb_Sum6) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);
    }

    /* End of Switch: '<S7>/Switch for Current offset calibration' */
  } else {
    rtb_Get_Integer = 0U;
    rtb_Saturationlowsideturnon_idx_1 = 0U;
    rtb_Saturationlowsideturnon_idx_2 = 0U;
  }

  /* End of Switch: '<S7>/Enable motor control' */

  /* Saturate: '<S5>/Saturation low side turn  on' incorporates:
   *  Bias: '<S5>/Dead time Compensation'
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

  /* End of Saturate: '<S5>/Saturation low side turn  on' */

  /* DataStoreWrite: '<S150>/Data Store Write' */
  MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = rtb_Compare;

  /* RelationalOperator: '<S152>/Compare' incorporates:
   *  DataStoreWrite: '<S150>/Data Store Write1'
   *  Gain: '<S150>/Gain'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = (rtb_Gain_d >= 8192);

  /* Gain: '<S163>/Gain2' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion2'
   *  DataTypeConversion: '<S165>/Data Type Conversion3'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S163>/Gain1'
   *  Gain: '<S163>/Gain10'
   *  Gain: '<S164>/Inverting OpAmp3'
   *  Sum: '<S163>/Sum1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 = ((((((int16_T)((14189 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[2]) >> 13) >> 3) - ((9339 *
    rtb_DataTypeConversion2) >> 19)) - rtb_z) - (rtb_DataTypeConversion3_g >> 3))
    * 25342) << 3;

  /* Sum: '<S163>/Sum3' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion3'
   *  DataTypeConversion: '<S165>/Data Type Conversion4'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S163>/Gain6'
   *  Gain: '<S163>/Gain8'
   *  Gain: '<S164>/Inverting OpAmp4'
   */
  rtb_Gain_d = (int16_T)(((((int16_T)((14189 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[3]) >> 13) >> 3) - ((9339 *
    rtb_DataTypeConversion3_d) >> 19)) - rtb_z_n) - (rtb_DataTypeConversion4 >>
    3));

  /* DeadZone: '<S60>/DeadZone' */
  if (rtb_DeadZone_j > 16384) {
    rtb_DeadZone_j = (int16_T)(rtb_DeadZone_j - 16384);
  } else if (rtb_DeadZone_j >= -16384) {
    rtb_DeadZone_j = 0;
  } else {
    rtb_DeadZone_j = (int16_T)(rtb_DeadZone_j - -16384);
  }

  /* End of DeadZone: '<S60>/DeadZone' */

  /* Product: '<S64>/IProd Out' incorporates:
   *  Product: '<S115>/IProd Out'
   *  Sum: '<S16>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_IProdOut * 191) >> 13);

  /* Switch: '<S58>/Switch1' incorporates:
   *  Constant: '<S58>/Constant'
   *  Constant: '<S58>/Constant2'
   *  DeadZone: '<S60>/DeadZone'
   *  RelationalOperator: '<S58>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_j > 0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S58>/Switch2' incorporates:
   *  Constant: '<S58>/Constant3'
   *  Constant: '<S58>/Constant4'
   *  Product: '<S115>/IProd Out'
   *  RelationalOperator: '<S58>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Constant1'
   *  DeadZone: '<S60>/DeadZone'
   *  Logic: '<S58>/AND3'
   *  Product: '<S115>/IProd Out'
   *  RelationalOperator: '<S58>/Equal1'
   *  RelationalOperator: '<S58>/Relational Operator'
   *  Switch: '<S58>/Switch1'
   *  Switch: '<S58>/Switch2'
   */
  if ((rtb_DeadZone_j != 0) && (tmp == tmp_0)) {
    rtb_DataTypeConversion2 = 0;
  } else {
    rtb_DataTypeConversion2 = rtb_IProdOut;
  }

  /* End of Switch: '<S58>/Switch' */

  /* DeadZone: '<S111>/DeadZone' */
  if (rtb_DeadZone > 16384) {
    rtb_DeadZone = (int16_T)(rtb_DeadZone - 16384);
  } else if (rtb_DeadZone >= -16384) {
    rtb_DeadZone = 0;
  } else {
    rtb_DeadZone = (int16_T)(rtb_DeadZone - -16384);
  }

  /* End of DeadZone: '<S111>/DeadZone' */

  /* Product: '<S115>/IProd Out' incorporates:
   *  Sum: '<S17>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_DataTypeConversion3 * 191) >> 13);

  /* Update for Delay: '<S149>/Delay' incorporates:
   *  DataStoreWrite: '<S150>/Data Store Write1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_n =
    MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC;

  /* Outputs for Atomic SubSystem: '<S4>/Clarke Transform' */
  /* Update for Delay: '<S1>/Delay' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Sum: '<S11>/sum_beta'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[0] = rtb_ToPerUnit_idx_0;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[1] = rtb_ToPerUnit_idx_1;

  /* End of Outputs for SubSystem: '<S4>/Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S4>/Inverse Park Transform' */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[2] = rtb_Saturation_i;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_h[3] = rtb_Sum1;

  /* End of Outputs for SubSystem: '<S4>/Inverse Park Transform' */

  /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S163>/Gain2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE += mul_s32_hiSR
    (439804651, MBD_FOC_SENSORLESS_MODEL_B.Gain2, 8U);

  /* Update for Delay: '<S165>/Delay' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion3'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_j = rtb_DataTypeConversion3_g;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_m =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator;

  /* Update for Delay: '<S165>/Delay3' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion5'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay3_DSTATE = rtb_DataTypeConversion5;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator2' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator2_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator2;

  /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S163>/Gain5'
   *  Sum: '<S163>/Sum3'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_b += mul_s32_hiSR
    (439804651, (25342 * rtb_Gain_d) << 3, 8U);

  /* Update for Delay: '<S165>/Delay1' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion4'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE = rtb_DataTypeConversion4;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator1' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE_i =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator1;

  /* Update for Delay: '<S165>/Delay2' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay2_DSTATE = rtb_DataTypeConversion6;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator3' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator3_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator3;

  /* Update for UnitDelay: '<S166>/Unit Delay3' incorporates:
   *  Gain: '<S167>/Gain2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE = (int16_T)y;

  /* Update for Delay: '<S166>/Delay1' incorporates:
   *  DataTypeConversion: '<S166>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE_i = rtb_DataTypeConversion1;

  /* Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator4' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4;

  /* Switch: '<S109>/Switch1' incorporates:
   *  Constant: '<S109>/Constant'
   *  Constant: '<S109>/Constant2'
   *  DeadZone: '<S111>/DeadZone'
   *  RelationalOperator: '<S109>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S109>/Switch2' incorporates:
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S109>/Constant4'
   *  Product: '<S115>/IProd Out'
   *  RelationalOperator: '<S109>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DeadZone: '<S111>/DeadZone'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/Relational Operator'
   *  Switch: '<S109>/Switch1'
   *  Switch: '<S109>/Switch2'
   */
  if ((rtb_DeadZone != 0) && (tmp == tmp_0)) {
    rtb_IProdOut = 0;
  }

  /* Update for DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Logic: '<S17>/AND'
   *  Logic: '<S17>/Logical Operator'
   *  Switch: '<S109>/Switch'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE += rtb_IProdOut;
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState = (int8_T)
    rtb_LogicalOperator_tmp;

  /* Update for DiscreteIntegrator: '<S67>/Integrator' incorporates:
   *  Logic: '<S17>/AND'
   *  Logic: '<S17>/Logical Operator'
   *  Switch: '<S58>/Switch'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE_d += rtb_DataTypeConversion2;
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState_b = (int8_T)
    rtb_LogicalOperator_tmp;
}

/* Model step function for TID1 */
void MbdFocSpdCtrl(void)               /* Sample time: [0.0015s, 0.0s] */
{
  int16_T rtb_Id_ref;
  int16_T rtb_RateTransition7;
  int16_T rtb_Switch_m;

  /* RateTransition: '<Root>/Rate Transition7' incorporates:
   *  Gain: '<S163>/Gain'
   */
  rtb_RateTransition7 = MBD_FOC_SENSORLESS_MODEL_B.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  MBD_FOC_SENSORLESS_MODEL_SpeedControl(0.5F, rtb_RateTransition7, &rtb_Id_ref,
    &rtb_Switch_m, &MBD_FOC_SENSORLESS_MODEL_DW.Enable,
    &MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop,
    &MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC,
    &MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef,
    &MBD_FOC_SENSORLESS_MODEL_DW.SpeedControl,
    &MBD_FOC_SENSORLESS_MODEL_PrevZCX.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* Update for RateTransition: '<Root>/Rate Transition5' */
  MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer
    [(MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx == 0) << 1] =
    rtb_Id_ref;
  MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[1 +
    ((MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx == 0) << 1)] =
    rtb_Switch_m;
  MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx = (int8_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx == 0);
}

/* Model initialize function */
void MbdFocSensorlessInit(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  MBD_FOC_SENSORLESS_MODEL_PrevZCX.OpenloopPos_PU_Reset_ZCE = POS_ZCSIG;
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
