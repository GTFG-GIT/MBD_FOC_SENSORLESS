/*
 * File: MBD_FOC_SENSORLESS_MODEL.c
 *
 * Code generated for Simulink model 'MBD_FOC_SENSORLESS_MODEL'.
 *
 * Model version                  : 8.394
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 17 20:55:33 2023
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

/* Named constants for Chart: '<S4>/Chart' */
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
 *    '<S46>/If Action Subsystem'
 *    '<S72>/If Action Subsystem'
 */
void MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem(int16_T rtu_In1, int16_T
  *rty_Out1)
{
  /* Sum: '<S48>/Sum' incorporates:
   *  DataTypeConversion: '<S48>/Convert_back'
   *  DataTypeConversion: '<S48>/Convert_uint16'
   */
  *rty_Out1 = (int16_T)(rtu_In1 - ((rtu_In1 >> 14) << 14));
}

/*
 * Output and update for action system:
 *    '<S46>/If Action Subsystem1'
 *    '<S72>/If Action Subsystem1'
 */
void MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem1(int16_T rtu_In1, int16_T
  *rty_Out1)
{
  /* Sum: '<S49>/Sum' incorporates:
   *  DataTypeConversion: '<S49>/Convert_back'
   *  DataTypeConversion: '<S49>/Convert_uint16'
   */
  *rty_Out1 = (int16_T)(rtu_In1 - ((rtu_In1 >> 14) << 14));
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

/* Model step function */
void MbdFocSensorlessCurrentCtrl(void)
{
  int16_T rtb_Add6;
  int16_T rtb_Add8;
  int16_T rtb_DataTypeConversion1;
  int16_T rtb_DataTypeConversion3;
  int16_T rtb_DataTypeConversion3_m;
  int16_T rtb_Gain9;
  int16_T rtb_Product_g;
  int16_T rtb_Sum1;
  int16_T rtb_Sum4_fv;
  int16_T rtb_Sum5;
  int16_T rtb_Sum6;
  int16_T rtb_Switch2_k3;
  int16_T rtb_Switch2_o;
  int16_T rtb_Switch_g0_idx_1;
  int16_T rtb_ToPerUnit_idx_0;
  uint16_T rtb_Get_Integer;
  uint16_T rtb_Saturationlowsideturnon_idx_1;
  uint16_T rtb_Saturationlowsideturnon_idx_2;
  uint16_T y;
  boolean_T rtb_NOT;

  /* Gain: '<S58>/Ls1_PU' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S58>/Gain8'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = (2787 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1]) >> 15;

  /* Sum: '<S58>/Add3' incorporates:
   *  Gain: '<S58>/Ls1_PU'
   *  Product: '<S71>/Product'
   *  UnitDelay: '<S58>/Unit Delay1'
   */
  rtb_Product_g = (int16_T)(MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay1_DSTATE -
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4);

  /* Gain: '<S58>/Ls_PU' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S58>/L_PU'
   */
  MBD_FOC_SENSORLESS_MODEL_B.rtb_Sum5_tmp = (2787 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0]) >> 15;

  /* Sum: '<S58>/Add2' incorporates:
   *  Gain: '<S58>/Ls_PU'
   *  Sum: '<S71>/Sum5'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  rtb_Sum5 = (int16_T)(MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_l -
                       MBD_FOC_SENSORLESS_MODEL_B.rtb_Sum5_tmp);

  /* Math: '<S58>/Square1' incorporates:
   *  Sum: '<S71>/Sum5'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (rtb_Sum5 * rtb_Sum5) >> 14;
  if (MBD_FOC_SENSORLESS_MODEL_B.u0 > 32767) {
    MBD_FOC_SENSORLESS_MODEL_B.u0 = 32767;
  } else if (MBD_FOC_SENSORLESS_MODEL_B.u0 < -32768) {
    MBD_FOC_SENSORLESS_MODEL_B.u0 = -32768;
  }

  /* Math: '<S58>/Square2' incorporates:
   *  Product: '<S71>/Product'
   */
  MBD_FOC_SENSORLESS_MODEL_B.i = (rtb_Product_g * rtb_Product_g) >> 14;
  if (MBD_FOC_SENSORLESS_MODEL_B.i > 32767) {
    MBD_FOC_SENSORLESS_MODEL_B.i = 32767;
  } else if (MBD_FOC_SENSORLESS_MODEL_B.i < -32768) {
    MBD_FOC_SENSORLESS_MODEL_B.i = -32768;
  }

  /* Sum: '<S58>/Add4' incorporates:
   *  Math: '<S58>/Square'
   *  Math: '<S58>/Square1'
   *  Math: '<S58>/Square2'
   *  Switch: '<S38>/Switch2'
   */
  rtb_DataTypeConversion3 = (int16_T)((MBD_FOC_SENSORLESS_MODEL_ConstB.Square -
    MBD_FOC_SENSORLESS_MODEL_B.u0) - MBD_FOC_SENSORLESS_MODEL_B.i);

  /* Sum: '<S58>/Add8' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S58>/Gain4'
   *  Gain: '<S58>/Rs_PU1'
   *  Product: '<S58>/Product1'
   *  Product: '<S71>/Product'
   *  Sum: '<S58>/Add1'
   *  Sum: '<S58>/Add7'
   *  Switch: '<S38>/Switch2'
   *  UnitDelay: '<S58>/Unit Delay3'
   */
  rtb_Add8 = (int16_T)((((int16_T)((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[3] - ((4405 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1]) >> 16)) + (int16_T)
    ((rtb_Product_g * rtb_DataTypeConversion3) >> 14)) * 16471) >> 18) +
                       MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE);

  /* Sum: '<S58>/x2-ib*L' incorporates:
   *  Product: '<S71>/Product'
   *  Sum: '<S58>/Add8'
   */
  rtb_Product_g = (int16_T)(rtb_Add8 -
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4);

  /* Sum: '<S58>/Add6' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S58>/Gain6'
   *  Gain: '<S58>/Rs_PU'
   *  Product: '<S58>/Product'
   *  Sum: '<S58>/Add'
   *  Sum: '<S58>/Add5'
   *  Sum: '<S71>/Sum5'
   *  Switch: '<S38>/Switch2'
   *  UnitDelay: '<S58>/Unit Delay2'
   */
  rtb_Add6 = (int16_T)((((int16_T)((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[2] - ((4405 *
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0]) >> 16)) + (int16_T)((rtb_Sum5 *
    rtb_DataTypeConversion3) >> 14)) * 16471) >> 18) +
                       MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay2_DSTATE);

  /* Sum: '<S58>/x1-ia*L' incorporates:
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Sum: '<S58>/Add6'
   */
  rtb_DataTypeConversion3_m = (int16_T)(rtb_Add6 -
    MBD_FOC_SENSORLESS_MODEL_B.rtb_Sum5_tmp);

  /* DataTypeConversion: '<S64>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S58>/Data Type Conversion'
   *  DataTypeConversion: '<S58>/Data Type Conversion2'
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Product: '<S71>/Product'
   *  Trigonometry: '<S64>/Trigonometric Function'
   */
  rtb_DataTypeConversion3 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_rt_atan2_Us16En12_Ys16En13_f_pw_cordic11((int16_T)
      (rtb_Product_g >> 2), (int16_T)(rtb_DataTypeConversion3_m >> 2)) >> 1);

  /* Switch: '<S77>/Switch2' incorporates:
   *  Constant: '<S77>/2pi'
   *  DataTypeConversion: '<S64>/Data Type Conversion3'
   *  Sum: '<S77>/Sum'
   *  Switch: '<S38>/Switch2'
   */
  if (rtb_DataTypeConversion3 <= 0) {
    rtb_DataTypeConversion3 = (int16_T)(rtb_DataTypeConversion3 + 25736);
  }

  /* End of Switch: '<S77>/Switch2' */

  /* Math: '<S78>/Math Function' incorporates:
   *  DataTypeConversion: '<S64>/Data Type Conversion4'
   *  Switch: '<S38>/Switch2'
   */
  y = (uint16_T)((uint16_T)rtb_DataTypeConversion3 % 25736);

  /* Gain: '<S58>/Inverting OpAmp5' incorporates:
   *  DataStoreRead: '<S12>/Data Store Read5'
   */
  MBD_FOC_SENSORLESS_MODEL_B.Add1_m = 2400.0F *
    MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef * 4.0F;
  if (MBD_FOC_SENSORLESS_MODEL_B.Add1_m < 0.0F) {
    MBD_FOC_SENSORLESS_MODEL_B.Sum_c = (real32_T)ceil
      (MBD_FOC_SENSORLESS_MODEL_B.Add1_m);
  } else {
    MBD_FOC_SENSORLESS_MODEL_B.Sum_c = (real32_T)floor
      (MBD_FOC_SENSORLESS_MODEL_B.Add1_m);
  }

  if (rtIsNaNF(MBD_FOC_SENSORLESS_MODEL_B.Sum_c) || rtIsInfF
      (MBD_FOC_SENSORLESS_MODEL_B.Sum_c)) {
    MBD_FOC_SENSORLESS_MODEL_B.Sum_c = 0.0F;
  } else {
    MBD_FOC_SENSORLESS_MODEL_B.Sum_c = (real32_T)fmod
      (MBD_FOC_SENSORLESS_MODEL_B.Sum_c, 65536.0);
  }

  /* Sum: '<S63>/Sum2' incorporates:
   *  Gain: '<S64>/Gain2'
   *  UnitDelay: '<S63>/Unit Delay3'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (int16_T)((int16_T)y -
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE_c) << 12;

  /* Bias: '<S76>/Bias' incorporates:
   *  Math: '<S76>/Math Function1'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = (MBD_FOC_SENSORLESS_MODEL_B.u0 - div_s32_floor
    (MBD_FOC_SENSORLESS_MODEL_B.u0, 105414357) * 105414357) + 52707179;

  /* DiscreteIntegrator: '<S63>/Discrete-Time Integrator4' incorporates:
   *  Bias: '<S76>/Bias1'
   *  Delay: '<S63>/Delay1'
   *  Gain: '<S58>/Gain10'
   *  Gain: '<S58>/Inverting OpAmp5'
   *  Gain: '<S63>/Gain1'
   *  Gain: '<S63>/Gain3'
   *  Math: '<S76>/Math Function'
   *  Product: '<S63>/Product1'
   *  Sum: '<S63>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 = mul_s32_hiSR(439804651,
    ((int16_T)(((int16_T)(((((MBD_FOC_SENSORLESS_MODEL_B.u0 - div_s32_floor
    (MBD_FOC_SENSORLESS_MODEL_B.u0, 105414357) * 105414357) + -52707179) >> 12) *
    625) >> 4) - (MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE << 1)) >> 1) *
     (int16_T)(((MBD_FOC_SENSORLESS_MODEL_B.Sum_c < 0.0F ? (int32_T)(int16_T)
                 -(int16_T)(uint16_T)-MBD_FOC_SENSORLESS_MODEL_B.Sum_c :
                 (int32_T)(int16_T)(uint16_T)MBD_FOC_SENSORLESS_MODEL_B.Sum_c) *
                17157) >> 14)) << 3, 11U) +
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE;

  /* DataTypeConversion: '<S63>/Data Type Conversion1' incorporates:
   *  DiscreteIntegrator: '<S63>/Discrete-Time Integrator4'
   */
  rtb_DataTypeConversion1 = (int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4 >> 6);

  /* Gain: '<S58>/Gain9' incorporates:
   *  DataTypeConversion: '<S63>/Data Type Conversion1'
   */
  rtb_Gain9 = (int16_T)((13351 * rtb_DataTypeConversion1) >> 12);

  /* Chart: '<S4>/Chart' incorporates:
   *  DataStoreRead: '<S4>/Data Store Read5'
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  DataStoreWrite: '<S4>/Data Store Write1'
   *  DataStoreWrite: '<S4>/Data Store Write3'
   *  Gain: '<S58>/Gain9'
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
          (rtb_Gain9 >= 1775)) {
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

  /* End of Chart: '<S4>/Chart' */

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  /* UnitDelay: '<S1>/Output' incorporates:
   *  Constant: '<S85>/Constant'
   */
  if ((MBD_FOC_SENSORLESS_MODEL_DW.Output_DSTATE == 0) &&
      (MBD_FOC_SENSORLESS_MODEL_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
       ZERO_ZCSIG)) {
    /* Logic: '<S83>/NOT' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion4'
     */
    rtb_NOT = (MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl == 0);

    /* DiscreteIntegrator: '<S94>/Discrete-Time Integrator' */
    if (rtb_NOT ||
        (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_PrevResetState != 0))
    {
      MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE =
        MBD_FOC_SENSORLESS_MODEL_ConstB.Constant2;
    }

    /* Switch: '<S84>/Switch' incorporates:
     *  Constant: '<S84>/Constant'
     *  DataStoreRead: '<S84>/Data Store Read1'
     *  DataStoreWrite: '<S5>/Data Store Write'
     */
    if (MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC) {
      /* Saturate: '<S5>/Saturation' incorporates:
       *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator'
       */
      if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE > 1.0F) {
        MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef = 1.0F;
      } else if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE <
                 0.0416666679F) {
        MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef = 0.0416666679F;
      } else {
        MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef =
          MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE;
      }

      /* End of Saturate: '<S5>/Saturation' */
    } else {
      MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef = 0.0F;
    }

    /* End of Switch: '<S84>/Switch' */

    /* Sum: '<S91>/Add1' incorporates:
     *  Constant: '<S91>/Filter_Constant'
     *  Constant: '<S91>/One'
     *  DataStoreWrite: '<S5>/Data Store Write'
     *  Product: '<S91>/Product'
     *  Product: '<S91>/Product1'
     *  UnitDelay: '<S91>/Unit Delay'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1_m = MBD_FOC_SENSORLESS_MODEL_DW.SpeedRef *
      0.03F + 0.97F * MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE;

    /* Product: '<S88>/Up' incorporates:
     *  Constant: '<S82>/Kp1'
     *  Gain: '<S58>/Gain9'
     *  Sum: '<S88>/Add'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Sum_c = (real32_T)floor
      ((MBD_FOC_SENSORLESS_MODEL_B.Add1_m - (real32_T)rtb_Gain9 * 6.10351562E-5F)
       * 0.650024414F * 16384.0F);
    if (rtIsNaNF(MBD_FOC_SENSORLESS_MODEL_B.Sum_c) || rtIsInfF
        (MBD_FOC_SENSORLESS_MODEL_B.Sum_c)) {
      MBD_FOC_SENSORLESS_MODEL_B.Sum_c = 0.0F;
    } else {
      MBD_FOC_SENSORLESS_MODEL_B.Sum_c = (real32_T)fmod
        (MBD_FOC_SENSORLESS_MODEL_B.Sum_c, 65536.0);
    }

    rtb_DataTypeConversion3 = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.Sum_c < 0.0F ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-MBD_FOC_SENSORLESS_MODEL_B.Sum_c :
      (int32_T)(int16_T)(uint16_T)MBD_FOC_SENSORLESS_MODEL_B.Sum_c);

    /* End of Product: '<S88>/Up' */

    /* Sum: '<S88>/Add2' incorporates:
     *  Product: '<S88>/Product1'
     *  Product: '<S88>/Up'
     *  UnitDelay: '<S88>/Unit Delay'
     */
    rtb_Gain9 = (int16_T)(((rtb_DataTypeConversion3 * 19) >> 11) +
                          MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_n);

    /* Switch: '<S92>/Switch2' incorporates:
     *  Constant: '<S82>/Ki3'
     *  RelationalOperator: '<S92>/LowerRelop1'
     *  RelationalOperator: '<S92>/UpperRelop'
     *  Sum: '<S88>/Add2'
     *  Switch: '<S92>/Switch'
     */
    if (rtb_Gain9 > 13107) {
      rtb_Gain9 = 13107;
    } else if (rtb_Gain9 < -13107) {
      /* Switch: '<S92>/Switch' incorporates:
       *  Constant: '<S82>/Ki4'
       *  Switch: '<S92>/Switch2'
       */
      rtb_Gain9 = -13107;
    }

    /* End of Switch: '<S92>/Switch2' */

    /* Sum: '<S94>/Sum' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read2'
     *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator'
     *  Gain: '<S5>/Gain'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Sum_c = 0.000416666677F * VelRef -
      MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE;

    /* Switch: '<S95>/Switch2' incorporates:
     *  RelationalOperator: '<S95>/LowerRelop1'
     *  RelationalOperator: '<S95>/UpperRelop'
     *  Switch: '<S95>/Switch'
     */
    if (MBD_FOC_SENSORLESS_MODEL_B.Sum_c >
        MBD_FOC_SENSORLESS_MODEL_ConstB.Product) {
      MBD_FOC_SENSORLESS_MODEL_B.Sum_c = MBD_FOC_SENSORLESS_MODEL_ConstB.Product;
    } else if (MBD_FOC_SENSORLESS_MODEL_B.Sum_c <
               MBD_FOC_SENSORLESS_MODEL_ConstB.Gain) {
      /* Switch: '<S95>/Switch' */
      MBD_FOC_SENSORLESS_MODEL_B.Sum_c = MBD_FOC_SENSORLESS_MODEL_ConstB.Gain;
    }

    /* End of Switch: '<S95>/Switch2' */

    /* Switch: '<S5>/Switch2' incorporates:
     *  DataStoreRead: '<S5>/Data Store Read5'
     */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/Iq_ref_openloop'
       *  DataTypeConversion: '<S4>/Data Type Conversion4'
       *  Switch: '<S5>/Switch1'
       */
      if (MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl != 0) {
        /* Sum: '<S88>/Add1' incorporates:
         *  Product: '<S88>/Up'
         *  Switch: '<S92>/Switch2'
         */
        rtb_DataTypeConversion3 += rtb_Gain9;

        /* Switch: '<S93>/Switch2' incorporates:
         *  RelationalOperator: '<S93>/LowerRelop1'
         *  RelationalOperator: '<S93>/UpperRelop'
         *  Sum: '<S88>/Add1'
         *  Switch: '<S93>/Switch'
         */
        if (rtb_DataTypeConversion3 > 16384) {
          /* Switch: '<S5>/Switch' incorporates:
           *  Constant: '<S82>/Ki5'
           */
          rtb_DataTypeConversion3 = 16384;
        } else if (rtb_DataTypeConversion3 < -16384) {
          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S82>/Ki6'
           *  Switch: '<S5>/Switch'
           */
          rtb_DataTypeConversion3 = -16384;
        }

        /* End of Switch: '<S93>/Switch2' */

        /* Switch: '<S5>/Switch2' incorporates:
         *  Constant: '<S5>/Id_ref1'
         */
        MBD_FOC_SENSORLESS_MODEL_B.Switch2[0] = 0;
      } else {
        rtb_DataTypeConversion3 = 0;

        /* Switch: '<S5>/Switch2' incorporates:
         *  Constant: '<S5>/Id_ref'
         *  Constant: '<S5>/Iq_ref_openloop'
         *  Switch: '<S5>/Switch'
         */
        MBD_FOC_SENSORLESS_MODEL_B.Switch2[0] = 13107;
      }

      /* End of Switch: '<S5>/Switch' */

      /* Switch: '<S5>/Switch2' */
      MBD_FOC_SENSORLESS_MODEL_B.Switch2[1] = rtb_DataTypeConversion3;
    } else {
      /* Switch: '<S5>/Switch2' incorporates:
       *  Constant: '<S5>/Id_ref2'
       *  Constant: '<S5>/Iq_ref3'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Switch2[0] = 0;
      MBD_FOC_SENSORLESS_MODEL_B.Switch2[1] = 0;
    }

    /* End of Switch: '<S5>/Switch2' */

    /* Outputs for Triggered SubSystem: '<S85>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S86>/Trigger'
     */
    MBD_FOC_SENSORLESS_MODEL_PrevZCX.TriggeredSubsystem_Trig_ZCE_c = 1U;

    /* End of Outputs for SubSystem: '<S85>/Triggered Subsystem' */

    /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S85>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE +=
      MBD_FOC_SENSORLESS_MODEL_B.Sum_c;
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_PrevResetState = (int8_T)
      rtb_NOT;

    /* Update for UnitDelay: '<S91>/Unit Delay' */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE =
      MBD_FOC_SENSORLESS_MODEL_B.Add1_m;

    /* Switch: '<S88>/Switch2' incorporates:
     *  DataStoreRead: '<S82>/Data Store Read2'
     *  DataTypeConversion: '<S4>/Data Type Conversion4'
     *  Logic: '<S82>/AND'
     */
    if ((MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl != 0) &&
        MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
      /* Update for UnitDelay: '<S88>/Unit Delay' incorporates:
       *  Switch: '<S92>/Switch2'
       */
      MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_n = rtb_Gain9;
    } else {
      /* Update for UnitDelay: '<S88>/Unit Delay' incorporates:
       *  Constant: '<S88>/Constant'
       */
      MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_n = 0;
    }

    /* End of Switch: '<S88>/Switch2' */
  }

  MBD_FOC_SENSORLESS_MODEL_PrevZCX.TriggeredSubsystem_Trig_ZCE = (ZCSigState)
    (MBD_FOC_SENSORLESS_MODEL_DW.Output_DSTATE > 0);

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */

  /* Outputs for Enabled SubSystem: '<S10>/Offset1' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  /* DataStoreRead: '<S10>/Data Store Read' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset) {
    /* SignalConversion generated from: '<S56>/Iab' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read1'
     *  DataStoreRead: '<S10>/Data Store Read2'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Iab[0] = MBD_FOC_SENSORLESS_MODEL_DW.ADC_IA;
    MBD_FOC_SENSORLESS_MODEL_B.Iab[1] = MBD_FOC_SENSORLESS_MODEL_DW.ADC_IB;
  }

  /* End of DataStoreRead: '<S10>/Data Store Read' */
  /* End of Outputs for SubSystem: '<S10>/Offset1' */

  /* Gain: '<S10>/To Per-Unit' incorporates:
   *  DataStoreRead: '<S10>/Data Store Read1'
   *  DataStoreRead: '<S10>/Data Store Read2'
   *  Sum: '<S10>/Add2'
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

  /* Outputs for Atomic SubSystem: '<S8>/Clarke Transform' */
  /* Gain: '<S13>/one_by_sqrt3' incorporates:
   *  Sum: '<S13>/a_plus_2b'
   *  Sum: '<S15>/sum_beta'
   */
  rtb_Gain9 = (int16_T)(((int16_T)((int16_T)(rtb_ToPerUnit_idx_0 +
    rtb_DataTypeConversion3) + rtb_DataTypeConversion3) * 18919) >> 15);

  /* End of Outputs for SubSystem: '<S8>/Clarke Transform' */

  /* Gain: '<S58>/Gain7' incorporates:
   *  DataStoreWrite: '<S12>/Data Store Write'
   *  Gain: '<S64>/Gain2'
   */
  smoAnglePU = (int16_T)((20861 * (int16_T)y) >> 15);

  /* Outputs for Resettable SubSystem: '<S12>/AngleGen Pos_PU' incorporates:
   *  ResetPort: '<S57>/Reset'
   */
  /* DataStoreRead: '<S12>/Data Store Read2' */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable &&
      (MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE != POS_ZCSIG))
  {
    /* Disable for Enabled SubSystem: '<S59>/Accumulate' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
      /* Disable for Sum: '<S60>/Add1' incorporates:
       *  Outport: '<S60>/theta_e'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Add1 = 0;
      MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
    }

    /* End of Disable for SubSystem: '<S59>/Accumulate' */

    /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l = 0;

    /* InitializeConditions for UnitDelay: '<S59>/Unit Delay' */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_nq = 0;
  }

  MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE =
    MBD_FOC_SENSORLESS_MODEL_DW.Enable;

  /* End of DataStoreRead: '<S12>/Data Store Read2' */

  /* Outputs for Enabled SubSystem: '<S59>/Accumulate' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_ConstB.NOT) {
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = true;

    /* Outputs for Enabled SubSystem: '<S60>/Subsystem' incorporates:
     *  EnablePort: '<S61>/Enable'
     */
    /* Delay: '<S60>/Delay' */
    if (MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k) {
      /* SignalConversion generated from: '<S61>/Input' incorporates:
       *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
       *  Gain: '<S57>/Gain'
       */
      MBD_FOC_SENSORLESS_MODEL_B.Input = (int16_T)mul_s32_loSR(5243,
        MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l, 25U);
    }

    /* End of Delay: '<S60>/Delay' */
    /* End of Outputs for SubSystem: '<S60>/Subsystem' */

    /* Sum: '<S60>/Add' incorporates:
     *  SignalConversion generated from: '<S61>/Input'
     *  Switch: '<S41>/Switch2'
     *  UnitDelay: '<S59>/Unit Delay'
     */
    rtb_Switch2_k3 = (int16_T)(MBD_FOC_SENSORLESS_MODEL_B.Input +
      MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_nq);

    /* Sum: '<S60>/Add1' incorporates:
     *  DataTypeConversion: '<S60>/Data Type Conversion'
     *  DataTypeConversion: '<S60>/Data Type Conversion1'
     *  Switch: '<S41>/Switch2'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = (int16_T)(rtb_Switch2_k3 -
      ((rtb_Switch2_k3 >> 14) << 14));

    /* Update for Delay: '<S60>/Delay' incorporates:
     *  Constant: '<S60>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE_k = true;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE) {
    /* Disable for Sum: '<S60>/Add1' incorporates:
     *  Outport: '<S60>/theta_e'
     */
    MBD_FOC_SENSORLESS_MODEL_B.Add1 = 0;
    MBD_FOC_SENSORLESS_MODEL_DW.Accumulate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S59>/Accumulate' */

  /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S57>/Data Type Conversion'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l += mul_s32_hiSR
    (824633721, MBD_FOC_SENSORLESS_MODEL_ConstB.DataTypeConversion, 5U);
  if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l >= 218453) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l = 218453;
  } else if (MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l <= 0) {
    MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S59>/Unit Delay' incorporates:
   *  Sum: '<S60>/Add1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_nq =
    MBD_FOC_SENSORLESS_MODEL_B.Add1;

  /* End of Outputs for SubSystem: '<S12>/AngleGen Pos_PU' */

  /* Switch: '<S12>/Switch' incorporates:
   *  DataStoreWrite: '<S12>/Data Store Write'
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   *  Gain: '<S58>/Gain7'
   *  Gain: '<S59>/scaleOut'
   *  Sum: '<S60>/Add1'
   *  Switch: '<S38>/Switch2'
   */
  if (MBD_FOC_SENSORLESS_MODEL_B.SpeedCtrl != 0) {
    rtb_DataTypeConversion3 = smoAnglePU;
  } else {
    /* Outputs for Resettable SubSystem: '<S12>/AngleGen Pos_PU' incorporates:
     *  ResetPort: '<S57>/Reset'
     */
    rtb_DataTypeConversion3 = MBD_FOC_SENSORLESS_MODEL_B.Add1;

    /* End of Outputs for SubSystem: '<S12>/AngleGen Pos_PU' */
  }

  /* End of Switch: '<S12>/Switch' */

  /* If: '<S46>/If' incorporates:
   *  Gain: '<S46>/convert_pu'
   *  RelationalOperator: '<S47>/Compare'
   *  Switch: '<S38>/Switch2'
   */
  if (rtb_DataTypeConversion3 < 0) {
    /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem(rtb_DataTypeConversion3,
      &rtb_DataTypeConversion3);

    /* End of Outputs for SubSystem: '<S46>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem1(rtb_DataTypeConversion3,
      &rtb_DataTypeConversion3);

    /* End of Outputs for SubSystem: '<S46>/If Action Subsystem1' */
  }

  /* End of If: '<S46>/If' */

  /* Gain: '<S17>/indexing' incorporates:
   *  Sum: '<S71>/Sum5'
   *  Switch: '<S38>/Switch2'
   */
  rtb_Sum5 = (int16_T)((25 * rtb_DataTypeConversion3) >> 4);

  /* DataTypeConversion: '<S17>/Get_Integer' incorporates:
   *  Sum: '<S71>/Sum5'
   */
  rtb_Get_Integer = (uint16_T)(rtb_Sum5 >> 5);

  /* DataTypeConversion: '<S17>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   *  Sum: '<S17>/Sum2'
   *  Sum: '<S71>/Sum5'
   */
  rtb_Sum5 = (int16_T)((int16_T)(rtb_Sum5 - (int16_T)((int16_T)rtb_Get_Integer <<
    5)) << 9);

  /* Sum: '<S45>/Sum3' incorporates:
   *  Constant: '<S17>/sine_table_values'
   *  Selector: '<S17>/Lookup'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S45>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12[rtb_Get_Integer];

  /* Sum: '<S45>/Sum4' incorporates:
   *  Constant: '<S17>/offset'
   *  Constant: '<S17>/sine_table_values'
   *  Product: '<S45>/Product'
   *  Selector: '<S17>/Lookup'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S45>/Sum3'
   *  Sum: '<S71>/Sum5'
   */
  rtb_Sum4_fv = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12[(int32_T)(rtb_Get_Integer + 1U)] -
     MBD_FOC_SENSORLESS_MODEL_B.u0) * rtb_Sum5) >> 14) +
    MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Sum: '<S45>/Sum5' incorporates:
   *  Constant: '<S17>/offset'
   *  Constant: '<S17>/sine_table_values'
   *  Selector: '<S17>/Lookup'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S45>/Sum6'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12
    [(int32_T)(rtb_Get_Integer + 200U)];

  /* Sum: '<S45>/Sum6' incorporates:
   *  Constant: '<S17>/offset'
   *  Constant: '<S17>/sine_table_values'
   *  Product: '<S45>/Product1'
   *  Selector: '<S17>/Lookup'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S45>/Sum5'
   *  Sum: '<S71>/Sum5'
   */
  rtb_Sum6 = (int16_T)((int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12[(int32_T)(rtb_Get_Integer + 201U)]
     - MBD_FOC_SENSORLESS_MODEL_B.u0) * rtb_Sum5) >> 14) +
                       MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Outputs for Atomic SubSystem: '<S8>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S8>/Clarke Transform' */
  /* Product: '<S40>/Up' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   *  Product: '<S16>/asin'
   *  Product: '<S16>/bcos'
   *  Sum: '<S15>/sum_beta'
   *  Sum: '<S16>/sum_Qs'
   *  Sum: '<S40>/Add'
   *  Sum: '<S45>/Sum4'
   *  Sum: '<S45>/Sum6'
   *  Switch: '<S38>/Switch2'
   */
  rtb_DataTypeConversion3 = (int16_T)(((int16_T)
    (MBD_FOC_SENSORLESS_MODEL_B.Switch2[1] - (int16_T)((int16_T)((rtb_Gain9 *
    rtb_Sum6) >> 14) - (int16_T)((rtb_ToPerUnit_idx_0 * rtb_Sum4_fv) >> 14))) *
    2787) >> 13);

  /* End of Outputs for SubSystem: '<S8>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S8>/Park Transform' */

  /* Sum: '<S40>/Add2' incorporates:
   *  Product: '<S40>/Product1'
   *  Switch: '<S38>/Switch2'
   *  UnitDelay: '<S40>/Unit Delay'
   */
  rtb_Switch2_k3 = (int16_T)(((rtb_DataTypeConversion3 * 407) >> 13) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_c);

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S21>/Ki1'
   *  RelationalOperator: '<S41>/LowerRelop1'
   *  RelationalOperator: '<S41>/UpperRelop'
   *  Sum: '<S40>/Add2'
   *  Switch: '<S41>/Switch'
   */
  if (rtb_Switch2_k3 > 13107) {
    rtb_Switch2_k3 = 13107;
  } else if (rtb_Switch2_k3 < -13107) {
    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S21>/Ki2'
     *  Switch: '<S41>/Switch2'
     */
    rtb_Switch2_k3 = -13107;
  }

  /* End of Switch: '<S41>/Switch2' */

  /* Sum: '<S40>/Add1' incorporates:
   *  Switch: '<S38>/Switch2'
   *  Switch: '<S41>/Switch2'
   */
  rtb_DataTypeConversion3 += rtb_Switch2_k3;

  /* Switch: '<S42>/Switch2' incorporates:
   *  Constant: '<S21>/Ki4'
   *  RelationalOperator: '<S42>/LowerRelop1'
   *  RelationalOperator: '<S42>/UpperRelop'
   *  Sum: '<S40>/Add1'
   *  Switch: '<S42>/Switch'
   */
  if (rtb_DataTypeConversion3 > 15565) {
    rtb_Switch2_o = 15565;
  } else if (rtb_DataTypeConversion3 < -15565) {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S21>/Ki3'
     *  Switch: '<S42>/Switch2'
     */
    rtb_Switch2_o = -15565;
  } else {
    rtb_Switch2_o = rtb_DataTypeConversion3;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S8>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S8>/Clarke Transform' */
  /* Product: '<S37>/Up' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   *  Product: '<S16>/acos'
   *  Product: '<S16>/bsin'
   *  Sum: '<S15>/sum_beta'
   *  Sum: '<S16>/sum_Ds'
   *  Sum: '<S37>/Add'
   *  Sum: '<S45>/Sum4'
   *  Sum: '<S45>/Sum6'
   *  Sum: '<S71>/Sum5'
   */
  rtb_Sum5 = (int16_T)(((int16_T)(MBD_FOC_SENSORLESS_MODEL_B.Switch2[0] -
    (int16_T)((int16_T)((rtb_ToPerUnit_idx_0 * rtb_Sum6) >> 14) + (int16_T)
              ((rtb_Gain9 * rtb_Sum4_fv) >> 14))) * 2787) >> 13);

  /* End of Outputs for SubSystem: '<S8>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S8>/Park Transform' */

  /* Sum: '<S37>/Add2' incorporates:
   *  Product: '<S37>/Product1'
   *  Sum: '<S71>/Sum5'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  rtb_DataTypeConversion3 = (int16_T)(((rtb_Sum5 * 407) >> 13) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_lr);

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S20>/Ki1'
   *  RelationalOperator: '<S38>/LowerRelop1'
   *  RelationalOperator: '<S38>/UpperRelop'
   *  Sum: '<S37>/Add2'
   *  Switch: '<S38>/Switch'
   */
  if (rtb_DataTypeConversion3 > 13107) {
    rtb_DataTypeConversion3 = 13107;
  } else if (rtb_DataTypeConversion3 < -13107) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S20>/Ki2'
     *  Switch: '<S38>/Switch2'
     */
    rtb_DataTypeConversion3 = -13107;
  }

  /* End of Switch: '<S38>/Switch2' */

  /* Sum: '<S37>/Add1' incorporates:
   *  Sum: '<S71>/Sum5'
   *  Switch: '<S38>/Switch2'
   */
  rtb_Sum5 += rtb_DataTypeConversion3;

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S20>/Ki4'
   *  RelationalOperator: '<S39>/LowerRelop1'
   *  RelationalOperator: '<S39>/UpperRelop'
   *  Sum: '<S37>/Add1'
   *  Switch: '<S39>/Switch'
   */
  if (rtb_Sum5 > 15565) {
    rtb_Sum5 = 15565;
  } else if (rtb_Sum5 < -15565) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S20>/Ki3'
     *  Switch: '<S39>/Switch2'
     */
    rtb_Sum5 = -15565;
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Sum: '<S25>/Sum1' incorporates:
   *  Product: '<S25>/Product'
   *  Product: '<S25>/Product1'
   *  Switch: '<S39>/Switch2'
   *  Switch: '<S42>/Switch2'
   */
  rtb_Sum1 = (int16_T)(((rtb_Sum5 * rtb_Sum5) >> 14) + ((rtb_Switch2_o *
    rtb_Switch2_o) >> 14));

  /* Outputs for IfAction SubSystem: '<S19>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S22>/Action Port'
   */
  /* If: '<S22>/If' incorporates:
   *  If: '<S19>/If'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  Sum: '<S25>/Sum1'
   */
  if (rtb_Sum1 >= 14786) {
    /* Outputs for IfAction SubSystem: '<S22>/Limiter' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Sqrt: '<S26>/Square Root' incorporates:
     *  Switch: '<S26>/Switch'
     */
    rtb_Sum1 = rt_sqrt_Us16En14_Ys16En14_Is32En28_s_s(rtb_Sum1);

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/Constant'
     */
    if (rtb_Sum1 == 0) {
      rtb_Sum1 = 16384;
    }

    /* Product: '<S26>/Reciprocal' incorporates:
     *  Switch: '<S26>/Switch'
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

    /* Product: '<S26>/Product1' incorporates:
     *  Constant: '<S24>/Constant3'
     *  Merge: '<S19>/Merge'
     *  Product: '<S26>/Product'
     *  Product: '<S26>/Reciprocal'
     *  Switch: '<S24>/Switch'
     */
    rtb_Sum5 = (int16_T)((((rtb_Sum5 * 15565) >> 14) * (int16_T)
                          MBD_FOC_SENSORLESS_MODEL_B.u0) >> 14);
    rtb_Switch2_o = (int16_T)((((rtb_Switch2_o * 15565) >> 14) * (int16_T)
      MBD_FOC_SENSORLESS_MODEL_B.u0) >> 14);

    /* End of Outputs for SubSystem: '<S22>/Limiter' */
  }

  /* End of If: '<S22>/If' */
  /* End of Outputs for SubSystem: '<S19>/D-Q Equivalence' */

  /* Outputs for Atomic SubSystem: '<S8>/Inverse Park Transform' */
  /* Switch: '<S43>/Switch' incorporates:
   *  Product: '<S15>/dcos'
   *  Product: '<S15>/dsin'
   *  Product: '<S15>/qcos'
   *  Product: '<S15>/qsin'
   *  Sum: '<S15>/sum_alpha'
   *  Sum: '<S15>/sum_beta'
   *  Sum: '<S45>/Sum4'
   *  Sum: '<S45>/Sum6'
   */
  rtb_Sum1 = (int16_T)((int16_T)((rtb_Sum5 * rtb_Sum6) >> 14) - (int16_T)
                       ((rtb_Switch2_o * rtb_Sum4_fv) >> 14));
  rtb_Switch_g0_idx_1 = (int16_T)((int16_T)((rtb_Switch2_o * rtb_Sum6) >> 14) +
    (int16_T)((rtb_Sum5 * rtb_Sum4_fv) >> 14));

  /* End of Outputs for SubSystem: '<S8>/Inverse Park Transform' */

  /* Switch: '<S11>/Enable motor control' incorporates:
   *  Constant: '<S11>/Constant2'
   *  DataStoreRead: '<S11>/Enable'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Switch: '<S11>/Switch for Current offset calibration' incorporates:
     *  Constant: '<S11>/Constant2'
     *  DataStoreRead: '<S11>/Data Store Read'
     *  DataStoreRead: '<S11>/Data Store Read1'
     *  Switch: '<S11>/Switch for rotor alignment'
     */
    if (MBD_FOC_SENSORLESS_MODEL_DW.EnCurOffset) {
      rtb_Get_Integer = 0U;
      rtb_Saturationlowsideturnon_idx_1 = 0U;
      rtb_Saturationlowsideturnon_idx_2 = 0U;
    } else if (MBD_FOC_SENSORLESS_MODEL_DW.EnPosOffset) {
      /* Switch: '<S11>/Switch for rotor alignment' incorporates:
       *  Constant: '<S11>/Constant3'
       *  Constant: '<S11>/Constant4'
       */
      rtb_Get_Integer = 532U;
      rtb_Saturationlowsideturnon_idx_1 = 343U;
      rtb_Saturationlowsideturnon_idx_2 = 343U;
    } else {
      /* Outputs for Atomic SubSystem: '<S8>/Inverse Park Transform' */
      /* Gain: '<S55>/sqrt3_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
       *  MinMax: '<S53>/Max'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      rtb_Switch2_o = (int16_T)((14189 * rtb_Switch_g0_idx_1) >> 14);

      /* Gain: '<S55>/one_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
       *  Gain: '<S53>/one_by_two'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      rtb_Sum4_fv = (int16_T)(rtb_Sum1 >> 1);

      /* End of Outputs for SubSystem: '<S8>/Inverse Park Transform' */

      /* Sum: '<S55>/add_c' incorporates:
       *  Gain: '<S53>/one_by_two'
       *  MinMax: '<S53>/Max'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      rtb_Sum6 = (int16_T)(-rtb_Sum4_fv - rtb_Switch2_o);

      /* Sum: '<S55>/add_b' incorporates:
       *  Gain: '<S53>/one_by_two'
       *  MinMax: '<S53>/Max'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      rtb_Switch2_o -= rtb_Sum4_fv;

      /* Outputs for Atomic SubSystem: '<S8>/Inverse Park Transform' */
      /* MinMax: '<S53>/Min' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
       *  Sum: '<S55>/add_b'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      if (rtb_Sum1 <= rtb_Switch2_o) {
        rtb_Sum5 = rtb_Sum1;
      } else {
        rtb_Sum5 = rtb_Switch2_o;
      }

      /* MinMax: '<S53>/Max' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
       *  Sum: '<S55>/add_b'
       *  Sum: '<S55>/add_c'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      if (rtb_Sum1 >= rtb_Switch2_o) {
        rtb_Sum4_fv = rtb_Sum1;
      } else {
        rtb_Sum4_fv = rtb_Switch2_o;
      }

      /* End of Outputs for SubSystem: '<S8>/Inverse Park Transform' */
      if (rtb_Sum4_fv < rtb_Sum6) {
        rtb_Sum4_fv = rtb_Sum6;
      }

      /* MinMax: '<S53>/Min' incorporates:
       *  Sum: '<S55>/add_c'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      if (rtb_Sum5 > rtb_Sum6) {
        rtb_Sum5 = rtb_Sum6;
      }

      /* Gain: '<S53>/one_by_two' incorporates:
       *  MinMax: '<S53>/Max'
       *  MinMax: '<S53>/Min'
       *  Sum: '<S53>/Add'
       *  Switch: '<S11>/Switch for rotor alignment'
       */
      rtb_Sum4_fv = (int16_T)(-(int16_T)(rtb_Sum4_fv + rtb_Sum5) >> 1);

      /* Outputs for Atomic SubSystem: '<S8>/Inverse Park Transform' */
      /* Switch: '<S11>/Switch for rotor alignment' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
       *  Constant: '<S11>/Constant'
       *  Gain: '<S11>/One_by_Two'
       *  Gain: '<S11>/Scale_to_PWM_Counter_PRD'
       *  Gain: '<S52>/Gain'
       *  Gain: '<S53>/one_by_two'
       *  Sum: '<S11>/Sum'
       *  Sum: '<S52>/Add1'
       *  Sum: '<S52>/Add2'
       *  Sum: '<S52>/Add3'
       *  Sum: '<S55>/add_b'
       *  Sum: '<S55>/add_c'
       */
      rtb_Get_Integer = (uint16_T)(((((int16_T)(((int16_T)(rtb_Sum1 +
        rtb_Sum4_fv) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);

      /* End of Outputs for SubSystem: '<S8>/Inverse Park Transform' */
      rtb_Saturationlowsideturnon_idx_1 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Switch2_o + rtb_Sum4_fv) * 18919) >> 14) >> 1) + 8192) * 1601) >>
        14);
      rtb_Saturationlowsideturnon_idx_2 = (uint16_T)(((((int16_T)(((int16_T)
        (rtb_Sum4_fv + rtb_Sum6) * 18919) >> 14) >> 1) + 8192) * 1601) >> 14);
    }

    /* End of Switch: '<S11>/Switch for Current offset calibration' */
  } else {
    rtb_Get_Integer = 0U;
    rtb_Saturationlowsideturnon_idx_1 = 0U;
    rtb_Saturationlowsideturnon_idx_2 = 0U;
  }

  /* End of Switch: '<S11>/Enable motor control' */

  /* Saturate: '<S9>/Saturation low side turn  on' incorporates:
   *  Bias: '<S9>/Dead time Compensation'
   */
  if ((uint16_T)(rtb_Get_Integer + 51U) > 1600) {
    /* DataStoreWrite: '<S2>/Data Store Write' */
    Pwm1Duty = 1600U;
  } else if ((uint16_T)(rtb_Get_Integer + 51U) < 102) {
    /* DataStoreWrite: '<S2>/Data Store Write' */
    Pwm1Duty = 102U;
  } else {
    /* DataStoreWrite: '<S2>/Data Store Write' */
    Pwm1Duty = (uint16_T)(rtb_Get_Integer + 51U);
  }

  if ((uint16_T)(rtb_Saturationlowsideturnon_idx_1 + 51U) > 1600) {
    /* DataStoreWrite: '<S2>/Data Store Write1' */
    Pwm2Duty = 1600U;
  } else if ((uint16_T)(rtb_Saturationlowsideturnon_idx_1 + 51U) < 102) {
    /* DataStoreWrite: '<S2>/Data Store Write1' */
    Pwm2Duty = 102U;
  } else {
    /* DataStoreWrite: '<S2>/Data Store Write1' */
    Pwm2Duty = (uint16_T)(rtb_Saturationlowsideturnon_idx_1 + 51U);
  }

  if ((uint16_T)(rtb_Saturationlowsideturnon_idx_2 + 51U) > 1600) {
    /* DataStoreWrite: '<S2>/Data Store Write2' */
    Pwm3Duty = 1600U;
  } else if ((uint16_T)(rtb_Saturationlowsideturnon_idx_2 + 51U) < 102) {
    /* DataStoreWrite: '<S2>/Data Store Write2' */
    Pwm3Duty = 102U;
  } else {
    /* DataStoreWrite: '<S2>/Data Store Write2' */
    Pwm3Duty = (uint16_T)(rtb_Saturationlowsideturnon_idx_2 + 51U);
  }

  /* End of Saturate: '<S9>/Saturation low side turn  on' */

  /* Product: '<S69>/Up' incorporates:
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Memory: '<S62>/Memory'
   *  Memory: '<S62>/Memory1'
   *  Product: '<S62>/Product2'
   *  Product: '<S62>/Product3'
   *  Product: '<S71>/Product'
   *  Sum: '<S69>/Add'
   */
  rtb_DataTypeConversion3_m = (int16_T)(((int16_T)((int16_T)
    ((MBD_FOC_SENSORLESS_MODEL_DW.Memory1_PreviousInput * rtb_Product_g) >> 14)
    - (int16_T)((rtb_DataTypeConversion3_m *
                 MBD_FOC_SENSORLESS_MODEL_DW.Memory_PreviousInput) >> 14)) * 41)
    >> 11);

  /* Sum: '<S69>/Add2' incorporates:
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Product: '<S69>/Product1'
   *  UnitDelay: '<S69>/Unit Delay'
   */
  rtb_Product_g = (int16_T)((rtb_DataTypeConversion3_m >> 13) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_o);

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S65>/Ki3'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Sum: '<S69>/Add2'
   *  Sum: '<S71>/Sum5'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_Product_g > 16384) {
    rtb_Sum5 = 16384;
  } else if (rtb_Product_g < -16384) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S65>/Ki4'
     *  Sum: '<S71>/Sum5'
     */
    rtb_Sum5 = -16384;
  } else {
    rtb_Sum5 = rtb_Product_g;
  }

  /* End of Switch: '<S70>/Switch2' */

  /* Sum: '<S62>/PLL_preAng' incorporates:
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Sum: '<S69>/Add1'
   *  Sum: '<S71>/Sum5'
   *  UnitDelay: '<S62>/Unit Delay4'
   */
  rtb_Product_g = (int16_T)((rtb_DataTypeConversion3_m + rtb_Sum5) +
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay4_DSTATE);

  /* DataTypeConversion: '<S62>/Data Type Conversion3' incorporates:
   *  Sum: '<S62>/PLL_preAng'
   */
  rtb_DataTypeConversion3_m = (int16_T)(rtb_Product_g >> 2);

  /* Switch: '<S67>/Switch2' incorporates:
   *  Constant: '<S67>/2pi'
   *  DataTypeConversion: '<S62>/Data Type Conversion3'
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Sum: '<S67>/Sum'
   */
  if (rtb_DataTypeConversion3_m <= 0) {
    rtb_DataTypeConversion3_m = (int16_T)(rtb_DataTypeConversion3_m + 16384);
  }

  /* End of Switch: '<S67>/Switch2' */

  /* Switch: '<S69>/Switch2' incorporates:
   *  DataStoreRead: '<S65>/Data Store Read1'
   *  DataStoreRead: '<S65>/Data Store Read2'
   *  Logic: '<S65>/AND'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC &&
      MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Update for UnitDelay: '<S69>/Unit Delay' incorporates:
     *  Sum: '<S71>/Sum5'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_o = rtb_Sum5;
  } else {
    /* Update for UnitDelay: '<S69>/Unit Delay' incorporates:
     *  Constant: '<S69>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_o = 0;
  }

  /* End of Switch: '<S69>/Switch2' */

  /* Gain: '<S62>/ThetaPll' incorporates:
   *  DataTypeConversion: '<S62>/Data Type Conversion1'
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Math: '<S68>/Math Function'
   */
  rtb_DataTypeConversion3_m = (int16_T)((uint16_T)((uint16_T)
    rtb_DataTypeConversion3_m % 4096) << 2);

  /* Outputs for IfAction SubSystem: '<S72>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S75>/Action Port'
   */
  /* If: '<S72>/If' incorporates:
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Gain: '<S72>/convert_pu'
   */
  MBD_FOC_SENSORLESS_MODEL_IfActionSubsystem1(rtb_DataTypeConversion3_m,
    &rtb_DataTypeConversion3_m);

  /* End of Outputs for SubSystem: '<S72>/If Action Subsystem1' */

  /* Gain: '<S66>/indexing' incorporates:
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Sum: '<S71>/Sum5'
   */
  rtb_Sum5 = (int16_T)((25 * rtb_DataTypeConversion3_m) >> 4);

  /* DataTypeConversion: '<S66>/Get_Integer' incorporates:
   *  Sum: '<S71>/Sum5'
   */
  rtb_Get_Integer = (uint16_T)(rtb_Sum5 >> 5);

  /* DataTypeConversion: '<S66>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S66>/Data Type Conversion1'
   *  Sum: '<S66>/Sum2'
   *  Sum: '<S71>/Sum5'
   */
  rtb_DataTypeConversion3_m = (int16_T)((int16_T)(rtb_Sum5 - (int16_T)((int16_T)
    rtb_Get_Integer << 5)) << 9);

  /* Update for UnitDelay: '<S58>/Unit Delay1' incorporates:
   *  Sum: '<S58>/Add8'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay1_DSTATE = rtb_Add8;

  /* Outputs for Atomic SubSystem: '<S8>/Clarke Transform' */
  /* Update for Delay: '<S2>/Delay' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   *  Sum: '<S15>/sum_beta'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[0] = rtb_ToPerUnit_idx_0;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[1] = rtb_Gain9;

  /* End of Outputs for SubSystem: '<S8>/Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S8>/Inverse Park Transform' */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[2] = rtb_Sum1;
  MBD_FOC_SENSORLESS_MODEL_DW.Delay_DSTATE[3] = rtb_Switch_g0_idx_1;

  /* End of Outputs for SubSystem: '<S8>/Inverse Park Transform' */

  /* Update for UnitDelay: '<S58>/Unit Delay' incorporates:
   *  Sum: '<S58>/Add6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_l = rtb_Add6;

  /* Update for UnitDelay: '<S58>/Unit Delay3' incorporates:
   *  Sum: '<S58>/Add8'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE = rtb_Add8;

  /* Update for UnitDelay: '<S58>/Unit Delay2' incorporates:
   *  Sum: '<S58>/Add6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay2_DSTATE = rtb_Add6;

  /* Update for UnitDelay: '<S63>/Unit Delay3' incorporates:
   *  Gain: '<S64>/Gain2'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay3_DSTATE_c = (int16_T)y;

  /* Update for Delay: '<S63>/Delay1' incorporates:
   *  DataTypeConversion: '<S63>/Data Type Conversion1'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Delay1_DSTATE = rtb_DataTypeConversion1;

  /* Update for DiscreteIntegrator: '<S63>/Discrete-Time Integrator4' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator4_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_B.DiscreteTimeIntegrator4;

  /* Switch: '<S7>/FixPt Switch' incorporates:
   *  Constant: '<S6>/FixPt Constant'
   *  Sum: '<S6>/FixPt Sum1'
   *  UnitDelay: '<S1>/Output'
   */
  if ((uint8_T)(MBD_FOC_SENSORLESS_MODEL_DW.Output_DSTATE + 1U) > 30) {
    /* Update for UnitDelay: '<S1>/Output' incorporates:
     *  Constant: '<S7>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S1>/Output' */
    MBD_FOC_SENSORLESS_MODEL_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S7>/FixPt Switch' */

  /* Switch: '<S40>/Switch2' incorporates:
   *  DataStoreRead: '<S21>/Data Store Read'
   *  DataStoreRead: '<S21>/Data Store Read1'
   *  Logic: '<S21>/AND'
   *  Switch: '<S37>/Switch2'
   */
  if (MBD_FOC_SENSORLESS_MODEL_DW.EnableFOC &&
      MBD_FOC_SENSORLESS_MODEL_DW.Enable) {
    /* Update for UnitDelay: '<S40>/Unit Delay' incorporates:
     *  Switch: '<S41>/Switch2'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_c = rtb_Switch2_k3;

    /* Update for UnitDelay: '<S37>/Unit Delay' incorporates:
     *  Switch: '<S38>/Switch2'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_lr = rtb_DataTypeConversion3;
  } else {
    /* Update for UnitDelay: '<S40>/Unit Delay' incorporates:
     *  Constant: '<S40>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_c = 0;

    /* Update for UnitDelay: '<S37>/Unit Delay' incorporates:
     *  Constant: '<S37>/Constant'
     */
    MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay_DSTATE_lr = 0;
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Sum: '<S71>/Sum5' incorporates:
   *  Constant: '<S66>/offset'
   *  Constant: '<S66>/sine_table_values'
   *  Selector: '<S66>/Lookup'
   *  Sum: '<S66>/Sum'
   *  Sum: '<S71>/Sum6'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 = MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12
    [(int32_T)(rtb_Get_Integer + 200U)];

  /* Update for Memory: '<S62>/Memory1' incorporates:
   *  Constant: '<S66>/offset'
   *  Constant: '<S66>/sine_table_values'
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Product: '<S71>/Product1'
   *  Selector: '<S66>/Lookup'
   *  Sum: '<S66>/Sum'
   *  Sum: '<S71>/Sum5'
   *  Sum: '<S71>/Sum6'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Memory1_PreviousInput = (int16_T)((int16_T)
    (((int16_T)(MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12[(int32_T)
                (rtb_Get_Integer + 201U)] - MBD_FOC_SENSORLESS_MODEL_B.u0) *
      rtb_DataTypeConversion3_m) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Sum: '<S71>/Sum3' incorporates:
   *  Constant: '<S66>/sine_table_values'
   *  Selector: '<S66>/Lookup'
   *  Sum: '<S66>/Sum'
   *  Sum: '<S71>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_B.u0 =
    MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12[rtb_Get_Integer];

  /* Update for Memory: '<S62>/Memory' incorporates:
   *  Constant: '<S66>/offset'
   *  Constant: '<S66>/sine_table_values'
   *  DataTypeConversion: '<S66>/Get_FractionVal'
   *  Product: '<S71>/Product'
   *  Selector: '<S66>/Lookup'
   *  Sum: '<S66>/Sum'
   *  Sum: '<S71>/Sum3'
   *  Sum: '<S71>/Sum4'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.Memory_PreviousInput = (int16_T)((int16_T)
    (((int16_T)(MBD_FOC_SENSORLESS_MODEL_ConstP.pooled12[(int32_T)
                (rtb_Get_Integer + 1U)] - MBD_FOC_SENSORLESS_MODEL_B.u0) *
      rtb_DataTypeConversion3_m) >> 14) + MBD_FOC_SENSORLESS_MODEL_B.u0);

  /* Update for UnitDelay: '<S62>/Unit Delay4' incorporates:
   *  Sum: '<S62>/PLL_preAng'
   */
  MBD_FOC_SENSORLESS_MODEL_DW.UnitDelay4_DSTATE = rtb_Product_g;
}

/* Model initialize function */
void MbdFocSensorlessInit(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  MBD_FOC_SENSORLESS_MODEL_PrevZCX.AngleGenPos_PU_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Triggered Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' */
  MBD_FOC_SENSORLESS_MODEL_DW.DiscreteTimeIntegrator_DSTATE =
    MBD_FOC_SENSORLESS_MODEL_ConstB.Constant2;

  /* End of SystemInitialize for SubSystem: '<Root>/Triggered Subsystem' */
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
