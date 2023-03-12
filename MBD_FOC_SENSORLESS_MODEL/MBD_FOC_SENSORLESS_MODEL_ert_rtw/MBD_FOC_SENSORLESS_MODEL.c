/*
 * File: MBD_FOC_SENSORLESS_MODEL.c
 *
 * Code generated for Simulink model 'MBD_FOC_SENSORLESS_MODEL'.
 *
 * Model version                  : 8.114
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Mar 12 22:05:47 2023
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
  rtu_Speed_Meas_PU, int16_T rty_IdqRef_PU[2], const boolean_T *rtd_Enable,
  const boolean_T *rtd_EnableClosedLoop, const boolean_T *rtd_EnableFOC, int16_T
  *rtd_SpeedRef, DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T *localDW,
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

  /* RateLimiter: '<S4>/Rate Limiter2' */
  rtb_RateLimiter2 = rtu_Speed_Ref_PU - localDW->PrevY;
  if (rtb_RateLimiter2 > 0.00075F) {
    rtb_RateLimiter2 = localDW->PrevY + 0.00075F;
  } else if (rtb_RateLimiter2 < -0.0003F) {
    rtb_RateLimiter2 = localDW->PrevY - 0.0003F;
  } else {
    rtb_RateLimiter2 = rtu_Speed_Ref_PU;
  }

  localDW->PrevY = rtb_RateLimiter2;

  /* End of RateLimiter: '<S4>/Rate Limiter2' */

  /* Switch: '<S167>/Switch' incorporates:
   *  Constant: '<S167>/Constant'
   *  DataStoreRead: '<S167>/Data Store Read1'
   *  DataStoreWrite: '<S4>/Data Store Write'
   */
  if (*rtd_EnableFOC) {
    /* DataTypeConversion: '<S4>/Data Type Conversion1' */
    rtb_RateLimiter2 = (real32_T)floor(rtb_RateLimiter2 * 16384.0F);
    if (rtIsNaNF(rtb_RateLimiter2) || rtIsInfF(rtb_RateLimiter2)) {
      rtb_RateLimiter2 = 0.0F;
    } else {
      rtb_RateLimiter2 = (real32_T)fmod(rtb_RateLimiter2, 65536.0);
    }

    rtb_DataTypeConversion1_c = (int16_T)(rtb_RateLimiter2 < 0.0F ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_RateLimiter2 : (int32_T)(int16_T)
      (uint16_T)rtb_RateLimiter2);

    /* End of DataTypeConversion: '<S4>/Data Type Conversion1' */

    /* Saturate: '<S4>/Saturation' incorporates:
     *  DataStoreWrite: '<S4>/Data Store Write'
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     *  Switch: '<S167>/Switch'
     */
    if (rtb_DataTypeConversion1_c > 11800) {
      *rtd_SpeedRef = 11800;
    } else if (rtb_DataTypeConversion1_c < 2950) {
      *rtd_SpeedRef = 2950;
    } else {
      *rtd_SpeedRef = rtb_DataTypeConversion1_c;
    }

    /* End of Saturate: '<S4>/Saturation' */
  } else {
    *rtd_SpeedRef = 0;
  }

  /* End of Switch: '<S167>/Switch' */

  /* Sum: '<S224>/Add1' incorporates:
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  Product: '<S224>/Product'
   *  Product: '<S224>/Product1'
   *  Switch: '<S167>/Switch'
   *  UnitDelay: '<S224>/Unit Delay'
   */
  rtb_DataTypeConversion1_c = (int16_T)(((*rtd_SpeedRef * 123) >> 12) + ((3973 *
    localDW->UnitDelay_DSTATE) >> 12));

  /* Sum: '<S166>/Sum' incorporates:
   *  Sum: '<S224>/Add1'
   */
  rtb_Sum_j = (int16_T)(rtb_DataTypeConversion1_c - rtu_Speed_Meas_PU);

  /* Logic: '<S166>/Logical Operator' incorporates:
   *  DataStoreRead: '<S166>/Data Store Read1'
   *  DataStoreRead: '<S166>/Data Store Read2'
   *  Logic: '<S166>/AND'
   */
  rtb_LogicalOperator_d = ((!*rtd_EnableClosedLoop) || (!*rtd_Enable));

  /* DiscreteIntegrator: '<S205>/Integrator' incorporates:
   *  Constant: '<S166>/Ki2'
   */
  if (rtb_LogicalOperator_d || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0;
  }

  /* Sum: '<S214>/Sum' incorporates:
   *  DiscreteIntegrator: '<S205>/Integrator'
   *  Product: '<S210>/PProd Out'
   *  Sum: '<S166>/Sum'
   */
  rtb_Sum_oz = (int16_T)(((rtb_Sum_j * 461) >> 10) + localDW->Integrator_DSTATE);

  /* DeadZone: '<S198>/DeadZone' incorporates:
   *  Product: '<S202>/IProd Out'
   *  Sum: '<S214>/Sum'
   */
  if (rtb_Sum_oz > 16384) {
    rtb_IProdOut_e = (int16_T)(rtb_Sum_oz - 16384);
  } else if (rtb_Sum_oz >= -16384) {
    rtb_IProdOut_e = 0;
  } else {
    rtb_IProdOut_e = (int16_T)(rtb_Sum_oz - -16384);
  }

  /* End of DeadZone: '<S198>/DeadZone' */

  /* RelationalOperator: '<S196>/Relational Operator' incorporates:
   *  Product: '<S202>/IProd Out'
   */
  rtb_RelationalOperator_b = (rtb_IProdOut_e != 0);

  /* Switch: '<S196>/Switch1' incorporates:
   *  Constant: '<S196>/Constant'
   *  Constant: '<S196>/Constant2'
   *  Product: '<S202>/IProd Out'
   *  RelationalOperator: '<S196>/fix for DT propagation issue'
   */
  if (rtb_IProdOut_e > 0) {
    rtb_Switch1_h = 1;
  } else {
    rtb_Switch1_h = -1;
  }

  /* End of Switch: '<S196>/Switch1' */

  /* Product: '<S202>/IProd Out' incorporates:
   *  Sum: '<S166>/Sum'
   */
  rtb_IProdOut_e = (int16_T)((rtb_Sum_j * 53) >> 12);

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
      /* Saturate: '<S212>/Saturation' incorporates:
       *  Sum: '<S214>/Sum'
       *  Switch: '<S4>/Switch'
       */
      if (rtb_Sum_oz > 16384) {
        rtb_Sum_j = 16384;
      } else if (rtb_Sum_oz < -16384) {
        rtb_Sum_j = -16384;
      } else {
        rtb_Sum_j = rtb_Sum_oz;
      }

      /* End of Saturate: '<S212>/Saturation' */
      rty_IdqRef_PU[0] = 0;
    } else {
      rtb_Sum_j = 0;
      rty_IdqRef_PU[0] = 13107;
    }

    /* End of Switch: '<S4>/Switch' */
    rty_IdqRef_PU[1] = rtb_Sum_j;
  } else {
    rty_IdqRef_PU[0] = 0;
    rty_IdqRef_PU[1] = 0;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Outputs for Triggered SubSystem: '<S168>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S169>/Trigger'
   */
  /* Constant: '<S168>/Constant' */
  localZCE->TriggeredSubsystem_Trig_ZCE = 1U;

  /* End of Outputs for SubSystem: '<S168>/Triggered Subsystem' */

  /* Update for UnitDelay: '<S224>/Unit Delay' incorporates:
   *  Sum: '<S224>/Add1'
   */
  localDW->UnitDelay_DSTATE = rtb_DataTypeConversion1_c;

  /* Switch: '<S196>/Switch2' incorporates:
   *  Constant: '<S196>/Constant3'
   *  Constant: '<S196>/Constant4'
   *  Product: '<S202>/IProd Out'
   *  RelationalOperator: '<S196>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_e > 0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S196>/Switch' incorporates:
   *  Constant: '<S196>/Constant1'
   *  Logic: '<S196>/AND3'
   *  RelationalOperator: '<S196>/Equal1'
   *  Switch: '<S196>/Switch2'
   */
  if (rtb_RelationalOperator_b && (rtb_Switch1_h == tmp)) {
    rtb_IProdOut_e = 0;
  }

  /* Update for DiscreteIntegrator: '<S205>/Integrator' incorporates:
   *  Switch: '<S196>/Switch'
   */
  localDW->Integrator_DSTATE += rtb_IProdOut_e;
  localDW->Integrator_PrevResetState = (int8_T)rtb_LogicalOperator_d;
}

static int16_T MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En11_Ys16En13_f_pw_cordic11
  (int16_T u0, int16_T u1)
{
  int32_T idx;
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
  ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc;
  for (idx = 0; idx < 11; idx++) {
    if (MBD_FOC_SENSORLESS_MODEL_B.yAcc < 0) {
      ytmp = MBD_FOC_SENSORLESS_MODEL_B.xAcc - ytmp;
      MBD_FOC_SENSORLESS_MODEL_B.xAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp |
        -131072 : ytmp & 131071;
      ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc + MBD_FOC_SENSORLESS_MODEL_B.xtmp;
      MBD_FOC_SENSORLESS_MODEL_B.yAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp |
        -131072 : ytmp & 131071;
      y -= MBD_FOC_SENSORLESS_MODEL_B.u3[(int16_T)(idx + 1) - 1];
    } else {
      ytmp += MBD_FOC_SENSORLESS_MODEL_B.xAcc;
      MBD_FOC_SENSORLESS_MODEL_B.xAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp |
        -131072 : ytmp & 131071;
      ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc - MBD_FOC_SENSORLESS_MODEL_B.xtmp;
      MBD_FOC_SENSORLESS_MODEL_B.yAcc = ((uint32_T)ytmp & 131072U) != 0U ? ytmp |
        -131072 : ytmp & 131071;
      y += MBD_FOC_SENSORLESS_MODEL_B.u3[(int16_T)(idx + 1) - 1];
    }

    MBD_FOC_SENSORLESS_MODEL_B.xtmp = MBD_FOC_SENSORLESS_MODEL_B.xAcc >>
      (int16_T)(idx + 1);
    ytmp = MBD_FOC_SENSORLESS_MODEL_B.yAcc >> (int16_T)(idx + 1);
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
  boolean_T rtb_LogicalOperator_tmp;

  /* Gain: '<S156>/Gain' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read'
   *  DeadZone: '<S112>/DeadZone'
   *  Gain: '<S156>/Inverting OpAmp5'
   */
  rtb_DeadZone = (int16_T)((((2777 * MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef) >> 12)
    * 17157) >> 14);

  /* Abs: '<S155>/Abs' incorporates:
   *  DeadZone: '<S112>/DeadZone'
   */
  if (rtb_DeadZone < 0) {
    rtb_DeadZone = (int16_T)-rtb_DeadZone;
  }

  /* End of Abs: '<S155>/Abs' */

  /* DataTypeConversion: '<S155>/Data Type Conversion2' incorporates:
   *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator1'
   */
  rtb_DataTypeConversion2 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE >> 5);

  /* Sum: '<S155>/Sum' incorporates:
   *  DataTypeConversion: '<S155>/Data Type Conversion2'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S155>/Gain8'
   *  Gain: '<S156>/Inverting OpAmp1'
   */
  rtb_z_n = (int16_T)((rtb_DataTypeConversion2 >> 2) - ((26771 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0]) >> 17));

  /* Saturate: '<S155>/Saturation' incorporates:
   *  Gain: '<S155>/Gain8'
   */
  if (rtb_z_n > 717) {
    rtb_z_n = 717;
  } else if (rtb_z_n < -717) {
    rtb_z_n = -717;
  }

  /* Gain: '<S155>/Gain10' incorporates:
   *  Saturate: '<S155>/Saturation'
   */
  rtb_z = (int16_T)((5 * rtb_z_n) >> 1);

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion1'
   *  DeadZone: '<S112>/DeadZone'
   *  Delay: '<S157>/Delay'
   *  Gain: '<S155>/Gain10'
   *  Product: '<S157>/Product'
   *  Sum: '<S157>/Sum2'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator = mul_s32_hiSR(439804651,
    (int16_T)((rtb_z << 3) - MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_j) *
    rtb_DeadZone, 8U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_m;

  /* DataTypeConversion: '<S157>/Data Type Conversion3' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator'
   */
  rtb_DataTypeConversion3_g = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator >> 6);

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator2' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion3'
   *  DeadZone: '<S112>/DeadZone'
   *  Delay: '<S157>/Delay3'
   *  Product: '<S157>/Product2'
   *  Sum: '<S157>/Sum3'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator2 = mul_s32_hiSR(439804651,
    (int16_T)(rtb_DataTypeConversion3_g -
              MBD_FOC_SENSORLESS_MODEL_DW.Delay3_DSTATE) * rtb_DeadZone, 8U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator2_DSTATE;

  /* DataTypeConversion: '<S157>/Data Type Conversion5' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator2'
   */
  rtb_DataTypeConversion5 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator2 >> 6);

  /* DataTypeConversion: '<S155>/Data Type Conversion3' incorporates:
   *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator'
   */
  rtb_DataTypeConversion3_d = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_b >> 5);

  /* Sum: '<S155>/Sum2' incorporates:
   *  DataTypeConversion: '<S155>/Data Type Conversion3'
   *  Delay: '<S1>/Delay'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Gain: '<S156>/Inverting OpAmp2'
   */
  rtb_DataTypeConversion3 = (int16_T)((rtb_DataTypeConversion3_d >> 2) - ((26771
    * MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1]) >> 17));

  /* Saturate: '<S155>/Saturation1' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  if (rtb_DataTypeConversion3 > 717) {
    rtb_DataTypeConversion3 = 717;
  } else if (rtb_DataTypeConversion3 < -717) {
    rtb_DataTypeConversion3 = -717;
  }

  /* Gain: '<S155>/Gain8' incorporates:
   *  Saturate: '<S155>/Saturation1'
   */
  rtb_z_n = (int16_T)((5 * rtb_DataTypeConversion3) >> 1);

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator1' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion2'
   *  DeadZone: '<S112>/DeadZone'
   *  Delay: '<S157>/Delay1'
   *  Gain: '<S155>/Gain8'
   *  Product: '<S157>/Product1'
   *  Sum: '<S157>/Sum1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator1 = mul_s32_hiSR(439804651,
    ((int16_T)((rtb_z_n << 3) - MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE) *
     rtb_DeadZone) >> 3, 5U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE_i;

  /* DataTypeConversion: '<S157>/Data Type Conversion4' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator1'
   */
  rtb_DataTypeConversion4 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator1 >> 6);

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator3' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion4'
   *  DeadZone: '<S112>/DeadZone'
   *  Delay: '<S157>/Delay2'
   *  Product: '<S157>/Product3'
   *  Sum: '<S157>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator3 = mul_s32_hiSR(439804651,
    (int16_T)(rtb_DataTypeConversion4 -
              MBD_FOC_SENSORLESS_MODEL_DW.Delay2_DSTATE) * rtb_DeadZone, 8U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator3_DSTATE;

  /* DataTypeConversion: '<S157>/Data Type Conversion6' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator3'
   */
  rtb_DataTypeConversion6 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator3 >> 6);

  /* DataTypeConversion: '<S159>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion5'
   *  DataTypeConversion: '<S157>/Data Type Conversion6'
   *  Gain: '<S159>/Gain3'
   *  Trigonometry: '<S159>/Trigonometric Function'
   */
  rtb_DataTypeConversion3 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En11_Ys16En13_f_pw_cordic11((int16_T)
      -rtb_DataTypeConversion5, rtb_DataTypeConversion6) >> 1);

  /* Switch: '<S161>/Switch2' incorporates:
   *  Constant: '<S161>/2pi'
   *  DataTypeConversion: '<S159>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Sum: '<S161>/Sum'
   */
  if (rtb_DataTypeConversion3 <= 0) {
    rtb_DataTypeConversion3 = (int16_T)(rtb_DataTypeConversion3 + 25736);
  }

  /* End of Switch: '<S161>/Switch2' */

  /* Math: '<S162>/Math Function' incorporates:
   *  Bias: '<S159>/Bias2'
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  y = (uint16_T)((uint16_T)(rtb_DataTypeConversion3 + 6434) % 25736);

  /* Sum: '<S158>/Sum2' incorporates:
   *  Gain: '<S159>/Gain2'
   *  UnitDelay: '<S158>/Unit Delay3'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = (int16_T)((int16_T)y -
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE) << 12;

  /* Bias: '<S160>/Bias' incorporates:
   *  Math: '<S160>/Math Function1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 =
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 - div_s32_floor
     (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4, 105414357) * 105414357)
    + 52707179;

  /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator4' incorporates:
   *  Bias: '<S160>/Bias1'
   *  DeadZone: '<S112>/DeadZone'
   *  Delay: '<S158>/Delay1'
   *  Gain: '<S158>/Gain1'
   *  Gain: '<S158>/Gain3'
   *  Math: '<S160>/Math Function'
   *  Product: '<S158>/Product1'
   *  Sum: '<S158>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = mul_s32_hiSR(439804651,
    ((int16_T)(((int16_T)(((((MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4
    - div_s32_floor(MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4,
                    105414357) * 105414357) + -52707179) >> 12) * 625) >> 4) -
                (MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE_i << 1)) >> 1) *
     rtb_DeadZone) << 3, 11U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE;

  /* DataTypeConversion: '<S158>/Data Type Conversion1' incorporates:
   *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator4'
   */
  rtb_DataTypeConversion1 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 >> 6);

  /* Gain: '<S155>/Gain' incorporates:
   *  DataTypeConversion: '<S158>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain = (int16_T)((23077 * rtb_DataTypeConversion1) >>
    13);

  /* Chart: '<S3>/Chart' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read5'
   *  DataStoreWrite: '<S3>/Data Store Write'
   *  DataStoreWrite: '<S3>/Data Store Write1'
   *  DataStoreWrite: '<S3>/Data Store Write3'
   *  Gain: '<S155>/Gain'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 < 32767U) {
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
      } else if (MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 4000U) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_OpenLoop;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 0U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = true;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = false;
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
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = true;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoopFilter:
      if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 2U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = true;
      }
      break;

     case MBD_FOC_SENSORLESS_MODEL_IN_Init:
      if (MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Align;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 0U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = true;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = false;
      }
      break;

     default:
      /* case IN_OpenLoop: */
      if ((MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 >= 30000U) &&
          (MBD_FOC_SENSORLESS_MODEL_B.Gain > 2950)) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_ClosedLoop;
        MBD_FOC_SENSORLESS_MODEL_DW.temporalCounter_i1 = 0U;
      } else if (!MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
        MBD_FOC_SENSORLESS_MODEL_DW.is_c3_MBD_FOC_SENSORLESS_MODEL =
          MBD_FOC_SENSORLESS_MODEL_IN_Init;
      } else {
        MBD_FOC_SENSORLESS_MODEL_B.Mode = 1U;
        MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset = false;
        MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC = true;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write2'
   *  Switch: '<S3>/Switch2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop =
    (MBD_FOC_SENSORLESS_MODEL_B.Mode > 1);

  /* RateTransition: '<Root>/Rate Transition5' */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_ActiveBufIdx << 1;
  MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[MBD_FOC_SENSORLESS_MODEL_B.Gain2];
  MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] =
    MBD_FOC_SENSORLESS_MODEL_DW.RateTransition5_Buffer[MBD_FOC_SENSORLESS_MODEL_B.Gain2
    + 1];

  /* Outputs for Enabled SubSystem: '<S7>/Offset1' incorporates:
   *  EnablePort: '<S149>/Enable'
   */
  /* DataStoreRead: '<S7>/Data Store Read' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset) {
    /* SignalConversion generated from: '<S149>/Iab' incorporates:
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

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Gain: '<S10>/one_by_sqrt3' incorporates:
   *  Sum: '<S10>/a_plus_2b'
   *  Sum: '<S12>/sum_beta'
   */
  rtb_ToPerUnit_idx_1 = (int16_T)(((int16_T)((int16_T)(rtb_ToPerUnit_idx_0 +
    rtb_ToPerUnit_idx_1) + rtb_ToPerUnit_idx_1) * 18919) >> 15);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */

  /* Gain: '<S155>/Gain3' incorporates:
   *  DataStoreWrite: '<S9>/Data Store Write'
   *  Gain: '<S159>/Gain2'
   */
  smoAnglePU = (int16_T)((20861 * (int16_T)y) >> 15);

  /* Outputs for Resettable SubSystem: '<S9>/AngleGen Pos_PU' incorporates:
   *  ResetPort: '<S150>/Reset'
   */
  /* DataStoreRead: '<S9>/Data Store Read2' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable &&
      (MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE != POS_ZCSIG))
  {
    /* Disable for Enabled SubSystem: '<S152>/Accumulate' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
      /* Disable for Sum: '<S153>/Add1' incorporates:
       *  Outport: '<S153>/theta_e'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Add1 = 0;
      MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
    }

    /* End of Disable for SubSystem: '<S152>/Accumulate' */

    /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' */
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 0;

    /* InitializeConditions for UnitDelay: '<S152>/Unit Delay' */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE = 0;
  }

  MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE =
    MBD_FOC_SENSORLESS_MODEL_DW.Enable;

  /* End of DataStoreRead: '<S9>/Data Store Read2' */

  /* Outputs for Enabled SubSystem: '<S152>/Accumulate' incorporates:
   *  EnablePort: '<S153>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_ConstB.NOT) {
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = true;

    /* Outputs for Enabled SubSystem: '<S153>/Subsystem' incorporates:
     *  EnablePort: '<S154>/Enable'
     */
    /* Delay: '<S153>/Delay' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k) {
      /* SignalConversion generated from: '<S154>/Input' incorporates:
       *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator'
       *  Gain: '<S150>/Gain'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Input = (int16_T)mul_s32_loSR(12133,
        MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE, 26U);
    }

    /* End of Delay: '<S153>/Delay' */
    /* End of Outputs for SubSystem: '<S153>/Subsystem' */

    /* Sum: '<S153>/Add' incorporates:
     *  Product: '<S116>/IProd Out'
     *  SignalConversion generated from: '<S154>/Input'
     *  UnitDelay: '<S152>/Unit Delay'
     */
    rtb_IProdOut = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.Input +
      MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE);

    /* Sum: '<S153>/Add1' incorporates:
     *  DataTypeConversion: '<S153>/Data Type Conversion'
     *  DataTypeConversion: '<S153>/Data Type Conversion1'
     *  Product: '<S116>/IProd Out'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = (int16_T)(rtb_IProdOut - ((rtb_IProdOut >>
      14) << 14));

    /* Update for Delay: '<S153>/Delay' incorporates:
     *  Constant: '<S153>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k = true;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
    /* Disable for Sum: '<S153>/Add1' incorporates:
     *  Outport: '<S153>/theta_e'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = 0;
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S152>/Accumulate' */

  /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S150>/Data Type Conversion'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE += mul_s32_hiSR
    (824633721, MBD_FOC_SENSORLESS_MODEL_ConstB.DataTypeConversion, 5U);
  if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE >= 188797) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 188797;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE <= 0) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S152>/Unit Delay' incorporates:
   *  Sum: '<S153>/Add1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE = MBD_FOC_SENSORLESS_MODEL_B.Add1;

  /* End of Outputs for SubSystem: '<S9>/AngleGen Pos_PU' */

  /* Switch: '<S9>/Switch' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read3'
   *  DataStoreWrite: '<S9>/Data Store Write'
   *  Gain: '<S152>/scaleOut'
   *  Gain: '<S155>/Gain3'
   *  Sum: '<S153>/Add1'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableClosedLoop) {
    rtb_DeadZone = smoAnglePU;
  } else {
    /* Outputs for Resettable SubSystem: '<S9>/AngleGen Pos_PU' incorporates:
     *  ResetPort: '<S150>/Reset'
     */
    rtb_DeadZone = MBD_FOC_SENSORLESS_MODEL_B.Add1;

    /* End of Outputs for SubSystem: '<S9>/AngleGen Pos_PU' */
  }

  /* Outputs for IfAction SubSystem: '<S139>/If Action Subsystem' incorporates:
   *  ActionPort: '<S141>/Action Port'
   */
  /* If: '<S139>/If' incorporates:
   *  DataTypeConversion: '<S141>/Convert_back'
   *  DataTypeConversion: '<S141>/Convert_uint16'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Gain: '<S14>/indexing'
   *  Sum: '<S141>/Sum'
   *  Switch: '<S9>/Switch'
   */
  rtb_DataTypeConversion3 = (int16_T)(((int16_T)(rtb_DeadZone - ((rtb_DeadZone >>
    14) << 14)) * 25) >> 4);

  /* End of Outputs for SubSystem: '<S139>/If Action Subsystem' */

  /* DataTypeConversion: '<S14>/Get_Integer' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  rtb_Get_Integer = (uint16_T)(rtb_DataTypeConversion3 >> 5);

  /* DataTypeConversion: '<S14>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Sum: '<S14>/Sum2'
   */
  rtb_DataTypeConversion3 = (int16_T)((int16_T)(rtb_DataTypeConversion3 -
    (int16_T)((int16_T)rtb_Get_Integer << 5)) << 9);

  /* Sum: '<S138>/Sum3' incorporates:
   *  Constant: '<S14>/sine_table_values'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S138>/Sum4'
   *  Sum: '<S14>/Sum'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[rtb_Get_Integer];

  /* Sum: '<S138>/Sum4' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Product: '<S138>/Product'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S138>/Sum3'
   *  Sum: '<S14>/Sum'
   */
  rtb_Sum4_f = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[(int32_T)
     (rtb_Get_Integer + 1U)] - MBD_FOC_SENSORLESS_MODEL_B.Gain2) *
    rtb_DataTypeConversion3) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.Gain2);

  /* Sum: '<S138>/Sum5' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S138>/Sum6'
   *  Sum: '<S14>/Sum'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[(int32_T)
    (rtb_Get_Integer + 200U)];

  /* Sum: '<S138>/Sum6' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Product: '<S138>/Product1'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S138>/Sum5'
   *  Sum: '<S14>/Sum'
   */
  rtb_Sum6 = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.sine_table_values_Value[(int32_T)
     (rtb_Get_Integer + 201U)] - MBD_FOC_SENSORLESS_MODEL_B.Gain2) *
    rtb_DataTypeConversion3) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.Gain2);

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Sum: '<S18>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Product: '<S13>/asin'
   *  Product: '<S13>/bcos'
   *  Sum: '<S12>/sum_beta'
   *  Sum: '<S138>/Sum4'
   *  Sum: '<S138>/Sum6'
   *  Sum: '<S13>/sum_Qs'
   */
  rtb_DataTypeConversion3 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] - (int16_T)((int16_T)
      ((rtb_ToPerUnit_idx_1 * rtb_Sum6) >> 14) - (int16_T)((rtb_ToPerUnit_idx_0 *
        rtb_Sum4_f) >> 14)));

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* Logic: '<S18>/Logical Operator' incorporates:
   *  DataStoreRead: '<S18>/Data Store Read'
   *  DataStoreRead: '<S18>/Data Store Read1'
   *  Logic: '<S17>/AND'
   *  Logic: '<S17>/Logical Operator'
   *  Logic: '<S18>/AND'
   */
  rtb_LogicalOperator_tmp = ((!MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC) ||
    (!MBD_FOC_SENSORLESS_MODEL_DW.Enable));

  /* DiscreteIntegrator: '<S119>/Integrator' incorporates:
   *  Constant: '<S18>/Kp1'
   *  Logic: '<S18>/AND'
   *  Logic: '<S18>/Logical Operator'
   */
  if (rtb_LogicalOperator_tmp ||
      (MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState != 0)) {
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE = 0;
  }

  /* Sum: '<S128>/Sum' incorporates:
   *  DeadZone: '<S112>/DeadZone'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Product: '<S124>/PProd Out'
   *  Sum: '<S18>/Sum'
   */
  rtb_DeadZone = (int16_T)(((rtb_DataTypeConversion3 * 693) >> 11) +
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE);

  /* Saturate: '<S126>/Saturation' incorporates:
   *  DeadZone: '<S112>/DeadZone'
   */
  if (rtb_DeadZone > 16384) {
    rtb_Saturation = 16384;
  } else if (rtb_DeadZone < -16384) {
    rtb_Saturation = -16384;
  } else {
    rtb_Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S126>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Sum: '<S17>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Product: '<S13>/acos'
   *  Product: '<S13>/bsin'
   *  Sum: '<S12>/sum_beta'
   *  Sum: '<S138>/Sum4'
   *  Sum: '<S138>/Sum6'
   *  Sum: '<S13>/sum_Ds'
   */
  rtb_IProdOut = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] -
    (int16_T)((int16_T)((rtb_ToPerUnit_idx_0 * rtb_Sum6) >> 14) + (int16_T)
              ((rtb_ToPerUnit_idx_1 * rtb_Sum4_f) >> 14)));

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* DiscreteIntegrator: '<S68>/Integrator' incorporates:
   *  Constant: '<S17>/Ki1'
   */
  if (rtb_LogicalOperator_tmp ||
      (MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState_b != 0)) {
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE_d = 0;
  }

  /* Sum: '<S77>/Sum' incorporates:
   *  DeadZone: '<S61>/DeadZone'
   *  DiscreteIntegrator: '<S68>/Integrator'
   *  Product: '<S73>/PProd Out'
   *  Sum: '<S17>/Sum'
   */
  rtb_DeadZone_j = (int16_T)(((rtb_IProdOut * 693) >> 11) +
    MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE_d);

  /* Saturate: '<S75>/Saturation' incorporates:
   *  DeadZone: '<S61>/DeadZone'
   */
  if (rtb_DeadZone_j > 16384) {
    rtb_Saturation_i = 16384;
  } else if (rtb_DeadZone_j < -16384) {
    rtb_Saturation_i = -16384;
  } else {
    rtb_Saturation_i = rtb_DeadZone_j;
  }

  /* End of Saturate: '<S75>/Saturation' */

  /* Sum: '<S22>/Sum1' incorporates:
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  Saturate: '<S126>/Saturation'
   *  Saturate: '<S75>/Saturation'
   */
  rtb_Sum1 = (int16_T)(((rtb_Saturation_i * rtb_Saturation_i) >> 14) +
                       ((rtb_Saturation * rtb_Saturation) >> 14));

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
    rtb_Sum1 = MBD_FOC_SENSORLESS_MODEL_rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s
      (rtb_Sum1);

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

    /* Product: '<S23>/Product1' incorporates:
     *  Constant: '<S21>/Constant3'
     *  Merge: '<S16>/Merge'
     *  Product: '<S23>/Product'
     *  Product: '<S23>/Reciprocal'
     *  Switch: '<S21>/Switch'
     */
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] = (int16_T)
      ((((rtb_Saturation_i * 15565) >> 14) * (int16_T)
        MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 14);
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] = (int16_T)((((rtb_Saturation *
      15565) >> 14) * (int16_T)MBD_FOC_SENSORLESS_MODEL_B.Gain2) >> 14);

    /* End of Outputs for SubSystem: '<S19>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S19>/Passthrough' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SignalConversion generated from: '<S24>/dqRef' incorporates:
     *  Merge: '<S16>/Merge'
     */
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] = rtb_Saturation_i;
    MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] = rtb_Saturation;

    /* End of Outputs for SubSystem: '<S19>/Passthrough' */
  }

  /* End of If: '<S19>/If' */
  /* End of Outputs for SubSystem: '<S16>/D-Q Equivalence' */

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
  /* Switch: '<S136>/Switch' incorporates:
   *  Product: '<S12>/dcos'
   *  Product: '<S12>/dsin'
   *  Product: '<S12>/qcos'
   *  Product: '<S12>/qsin'
   *  Sum: '<S12>/sum_alpha'
   *  Sum: '<S12>/sum_beta'
   *  Sum: '<S138>/Sum4'
   *  Sum: '<S138>/Sum6'
   */
  rtb_Saturation_i = (int16_T)((int16_T)
    ((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] * rtb_Sum6) >> 14) -
    (int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] * rtb_Sum4_f) >> 14));
  rtb_Sum1 = (int16_T)((int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[1] *
    rtb_Sum6) >> 14) + (int16_T)((MBD_FOC_SENSORLESS_MODEL_B.RateTransition5[0] *
    rtb_Sum4_f) >> 14));

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
      /* Gain: '<S148>/sqrt3_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  MinMax: '<S146>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Saturation = (int16_T)((14189 * rtb_Sum1) >> 14);

      /* Gain: '<S148>/one_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Gain: '<S146>/one_by_two'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum4_f = (int16_T)(rtb_Saturation_i >> 1);

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

      /* Sum: '<S148>/add_c' incorporates:
       *  Gain: '<S146>/one_by_two'
       *  MinMax: '<S146>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum6 = (int16_T)(-rtb_Sum4_f - rtb_Saturation);

      /* Sum: '<S148>/add_b' incorporates:
       *  Gain: '<S146>/one_by_two'
       *  MinMax: '<S146>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Saturation -= rtb_Sum4_f;

      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* MinMax: '<S146>/Min' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Sum: '<S148>/add_b'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Saturation_i <= rtb_Saturation) {
        rtb_Sum4_f = rtb_Saturation_i;
      } else {
        rtb_Sum4_f = rtb_Saturation;
      }

      /* MinMax: '<S146>/Max' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Sum: '<S148>/add_b'
       *  Sum: '<S148>/add_c'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Saturation_i >= rtb_Saturation) {
        maxV = rtb_Saturation_i;
      } else {
        maxV = rtb_Saturation;
      }

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */
      if (maxV < rtb_Sum6) {
        maxV = rtb_Sum6;
      }

      /* MinMax: '<S146>/Min' incorporates:
       *  Sum: '<S148>/add_c'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Sum4_f > rtb_Sum6) {
        rtb_Sum4_f = rtb_Sum6;
      }

      /* Gain: '<S146>/one_by_two' incorporates:
       *  MinMax: '<S146>/Max'
       *  MinMax: '<S146>/Min'
       *  Sum: '<S146>/Add'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum4_f = (int16_T)(-(int16_T)(maxV + rtb_Sum4_f) >> 1);

      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* Switch: '<S8>/Switch for rotor alignment' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
       *  Constant: '<S8>/Constant'
       *  Gain: '<S145>/Gain'
       *  Gain: '<S146>/one_by_two'
       *  Gain: '<S8>/One_by_Two'
       *  Gain: '<S8>/Scale_to_PWM_Counter_PRD'
       *  Sum: '<S145>/Add1'
       *  Sum: '<S145>/Add2'
       *  Sum: '<S145>/Add3'
       *  Sum: '<S148>/add_b'
       *  Sum: '<S148>/add_c'
       *  Sum: '<S8>/Sum'
       */
      rtb_Get_Integer = (uint16_T)(((((int16_T)(((int16_T)(rtb_Saturation_i +
        rtb_Sum4_f) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */
      rtb_Saturationlowsideturnon_idx_1 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Saturation + rtb_Sum4_f) * 18919) >> 14) >> 1) + 8192) * 1601) >>
        14);
      rtb_Saturationlowsideturnon_idx_2 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Sum4_f + rtb_Sum6) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);
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

  /* Gain: '<S155>/Gain2' incorporates:
   *  DataTypeConversion: '<S155>/Data Type Conversion2'
   *  DataTypeConversion: '<S157>/Data Type Conversion3'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S155>/Gain1'
   *  Gain: '<S155>/Gain10'
   *  Gain: '<S156>/Inverting OpAmp3'
   *  Sum: '<S155>/Sum1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Gain2 = ((((((int16_T)((14189 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[2]) >> 13) >> 3) - ((9339 *
    rtb_DataTypeConversion2) >> 19)) - rtb_z) - (rtb_DataTypeConversion3_g >> 3))
    * 25342) << 3;

  /* Sum: '<S155>/Sum3' incorporates:
   *  DataTypeConversion: '<S155>/Data Type Conversion3'
   *  DataTypeConversion: '<S157>/Data Type Conversion4'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S155>/Gain6'
   *  Gain: '<S155>/Gain8'
   *  Gain: '<S156>/Inverting OpAmp4'
   */
  rtb_DataTypeConversion2 = (int16_T)(((((int16_T)((14189 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[3]) >> 13) >> 3) - ((9339 *
    rtb_DataTypeConversion3_d) >> 19)) - rtb_z_n) - (rtb_DataTypeConversion4 >>
    3));

  /* DeadZone: '<S61>/DeadZone' */
  if (rtb_DeadZone_j > 16384) {
    rtb_DeadZone_j = (int16_T)(rtb_DeadZone_j - 16384);
  } else if (rtb_DeadZone_j >= -16384) {
    rtb_DeadZone_j = 0;
  } else {
    rtb_DeadZone_j = (int16_T)(rtb_DeadZone_j - -16384);
  }

  /* End of DeadZone: '<S61>/DeadZone' */

  /* Product: '<S65>/IProd Out' incorporates:
   *  Product: '<S116>/IProd Out'
   *  Sum: '<S17>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_IProdOut * 191) >> 13);

  /* Switch: '<S59>/Switch1' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S59>/Constant2'
   *  DeadZone: '<S61>/DeadZone'
   *  RelationalOperator: '<S59>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_j > 0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S59>/Switch2' incorporates:
   *  Constant: '<S59>/Constant3'
   *  Constant: '<S59>/Constant4'
   *  Product: '<S116>/IProd Out'
   *  RelationalOperator: '<S59>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S59>/Constant1'
   *  DeadZone: '<S61>/DeadZone'
   *  Logic: '<S59>/AND3'
   *  Product: '<S116>/IProd Out'
   *  RelationalOperator: '<S59>/Equal1'
   *  RelationalOperator: '<S59>/Relational Operator'
   *  Switch: '<S59>/Switch1'
   *  Switch: '<S59>/Switch2'
   */
  if ((rtb_DeadZone_j != 0) && (tmp == tmp_0)) {
    rtb_z_n = 0;
  } else {
    rtb_z_n = rtb_IProdOut;
  }

  /* End of Switch: '<S59>/Switch' */

  /* DeadZone: '<S112>/DeadZone' */
  if (rtb_DeadZone > 16384) {
    rtb_DeadZone = (int16_T)(rtb_DeadZone - 16384);
  } else if (rtb_DeadZone >= -16384) {
    rtb_DeadZone = 0;
  } else {
    rtb_DeadZone = (int16_T)(rtb_DeadZone - -16384);
  }

  /* End of DeadZone: '<S112>/DeadZone' */

  /* Product: '<S116>/IProd Out' incorporates:
   *  Sum: '<S18>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_DataTypeConversion3 * 191) >> 13);

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Update for Delay: '<S1>/Delay' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Sum: '<S12>/sum_beta'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0] = rtb_ToPerUnit_idx_0;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1] = rtb_ToPerUnit_idx_1;

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[2] = rtb_Saturation_i;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[3] = rtb_Sum1;

  /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

  /* Update for DiscreteIntegrator: '<S155>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S155>/Gain2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE += mul_s32_hiSR
    (439804651, MBD_FOC_SENSORLESS_MODEL_B.Gain2, 8U);

  /* Update for Delay: '<S157>/Delay' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion3'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_j = rtb_DataTypeConversion3_g;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_m =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator;

  /* Update for Delay: '<S157>/Delay3' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion5'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay3_DSTATE = rtb_DataTypeConversion5;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator2' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator2_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator2;

  /* Update for DiscreteIntegrator: '<S155>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S155>/Gain5'
   *  Sum: '<S155>/Sum3'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_b += mul_s32_hiSR
    (439804651, (25342 * rtb_DataTypeConversion2) << 3, 8U);

  /* Update for Delay: '<S157>/Delay1' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion4'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE = rtb_DataTypeConversion4;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator1' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator1_DSTATE_i =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator1;

  /* Update for Delay: '<S157>/Delay2' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay2_DSTATE = rtb_DataTypeConversion6;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator3' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator3_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator3;

  /* Update for UnitDelay: '<S158>/Unit Delay3' incorporates:
   *  Gain: '<S159>/Gain2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE = (int16_T)y;

  /* Update for Delay: '<S158>/Delay1' incorporates:
   *  DataTypeConversion: '<S158>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE_i = rtb_DataTypeConversion1;

  /* Update for DiscreteIntegrator: '<S158>/Discrete-Time Integrator4' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4;

  /* Switch: '<S110>/Switch1' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S110>/Constant2'
   *  DeadZone: '<S112>/DeadZone'
   *  RelationalOperator: '<S110>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S110>/Switch2' incorporates:
   *  Constant: '<S110>/Constant3'
   *  Constant: '<S110>/Constant4'
   *  Product: '<S116>/IProd Out'
   *  RelationalOperator: '<S110>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S110>/Constant1'
   *  DeadZone: '<S112>/DeadZone'
   *  Logic: '<S110>/AND3'
   *  RelationalOperator: '<S110>/Equal1'
   *  RelationalOperator: '<S110>/Relational Operator'
   *  Switch: '<S110>/Switch1'
   *  Switch: '<S110>/Switch2'
   */
  if ((rtb_DeadZone != 0) && (tmp == tmp_0)) {
    rtb_IProdOut = 0;
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
   *  Logic: '<S18>/AND'
   *  Logic: '<S18>/Logical Operator'
   *  Switch: '<S110>/Switch'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE += rtb_IProdOut;
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState = (int8_T)
    rtb_LogicalOperator_tmp;

  /* Update for DiscreteIntegrator: '<S68>/Integrator' incorporates:
   *  Logic: '<S18>/AND'
   *  Logic: '<S18>/Logical Operator'
   *  Switch: '<S59>/Switch'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_DSTATE_d += rtb_z_n;
  MBD_FOC_SENSORLESS_MODEL_DW.Integrator_PrevResetState_b = (int8_T)
    rtb_LogicalOperator_tmp;
}

/* Model step function for TID1 */
void MbdFocSpdCtrl(void)               /* Sample time: [0.0015s, 0.0s] */
{
  int16_T rtb_Switch2[2];
  int16_T rtb_RateTransition7;

  /* RateTransition: '<Root>/Rate Transition7' incorporates:
   *  Gain: '<S155>/Gain'
   */
  rtb_RateTransition7 = MBD_FOC_SENSORLESS_MODEL_B.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  MBD_FOC_SENSORLESS_MODEL_SpeedControl(0.5F, rtb_RateTransition7, rtb_Switch2,
    &MBD_FOC_SENSORLESS_MODEL_DW.Enable,
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
