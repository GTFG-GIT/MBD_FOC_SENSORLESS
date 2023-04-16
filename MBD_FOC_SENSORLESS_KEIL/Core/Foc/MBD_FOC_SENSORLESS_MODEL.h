/*
 * File: MBD_FOC_SENSORLESS_MODEL.h
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

#ifndef RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_h_
#define RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_h_
#ifndef MBD_FOC_SENSORLESS_MODEL_COMMON_INCLUDES_
#define MBD_FOC_SENSORLESS_MODEL_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                           /* MBD_FOC_SENSORLESS_MODEL_COMMON_INCLUDES_ */

#include <stddef.h>
#include "MBD_FOC_SENSORLESS_MODEL_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S87>/Unit Delay' */
  int16_T UnitDelay_DSTATE_f;          /* '<S84>/Unit Delay' */
} DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state for system '<Root>/Speed Control' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S81>/Triggered Subsystem' */
} ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T;

/* Block signals (default storage) */
typedef struct {
  int16_T u3[11];
  real32_T u;
  int32_T DiscreteTimeIntegrator4;
  int32_T i;
  int32_T u0;
  int32_T rtb_Sum5_tmp;
  int16_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint16_T SpeedCtrl;                  /* '<S3>/Chart' */
  uint16_T Iab[2];                     /* '<S53>/Iab' */
  int16_T Gain9;                       /* '<S55>/Gain9' */
  int16_T Add1;                        /* '<S57>/Add1' */
  int16_T Input;                       /* '<S58>/Input' */
} B_MBD_FOC_SENSORLESS_MODEL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S54>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator4_DSTATE;/* '<S60>/Discrete-Time Integrator4' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory4' */
  int16_T UnitDelay1_DSTATE;           /* '<S55>/Unit Delay1' */
  int16_T Delay_DSTATE[4];             /* '<S1>/Delay' */
  int16_T UnitDelay_DSTATE;            /* '<S55>/Unit Delay' */
  int16_T UnitDelay3_DSTATE;           /* '<S55>/Unit Delay3' */
  int16_T UnitDelay2_DSTATE;           /* '<S55>/Unit Delay2' */
  int16_T UnitDelay_DSTATE_c;          /* '<S37>/Unit Delay' */
  int16_T UnitDelay_DSTATE_l;          /* '<S34>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S66>/Unit Delay' */
  int16_T UnitDelay4_DSTATE;           /* '<S59>/Unit Delay4' */
  int16_T UnitDelay_DSTATE_n;          /* '<S56>/Unit Delay' */
  int16_T UnitDelay3_DSTATE_c;         /* '<S60>/Unit Delay3' */
  int16_T Delay1_DSTATE;               /* '<S60>/Delay1' */
  uint16_T ADC_IA;                     /* '<Root>/Data Store Memory' */
  uint16_T ADC_IB;                     /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S3>/Chart' */
  volatile int16_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  int16_T Memory1_PreviousInput;       /* '<S59>/Memory1' */
  int16_T Memory_PreviousInput;        /* '<S59>/Memory' */
  boolean_T Delay_DSTATE_k;            /* '<S57>/Delay' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  uint8_T is_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S3>/Chart' */
  uint8_T is_active_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S3>/Chart' */
  boolean_T EnCurOffset;               /* '<Root>/Data Store Memory1' */
  boolean_T EnPosOffset;               /* '<Root>/Data Store Memory10' */
  boolean_T EnableFOC;                 /* '<Root>/Data Store Memory29' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory3' */
  boolean_T EnableClosedLoop;          /* '<Root>/Data Store Memory6' */
  boolean_T Accumulate_MODE;           /* '<S56>/Accumulate' */
  DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T SpeedControl;/* '<Root>/Speed Control' */
} DW_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T SpeedControl;/* '<Root>/Speed Control' */
  ZCSigState AngleGenPos_PU_Reset_ZCE; /* '<S9>/AngleGen Pos_PU' */
} PrevZCX_MBD_FOC_SENSORLESS_MODEL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const int32_T DataTypeConversion;    /* '<S54>/Data Type Conversion' */
  const int16_T Square;                /* '<S55>/Square' */
  const boolean_T NOT;                 /* '<S56>/NOT' */
} ConstB_MBD_FOC_SENSORLESS_MODEL_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S14>/sine_table_values'
   *   '<S63>/sine_table_values'
   */
  int16_T pooled11[1002];
} ConstP_MBD_FOC_SENSORLESS_MODEL_T;

/* Real-time Model Data Structure */
struct tag_RTM_MBD_FOC_SENSORLESS_MODEL_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_B;

/* Block states (default storage) */
extern DW_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_PrevZCX;
extern const ConstB_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_MBD_FOC_SENSORLESS_MODEL_T MBD_FOC_SENSORLESS_MODEL_ConstP;

/* Model entry point functions */
extern void MbdFocSensorlessInit(void);
extern void MbdFocSensorlessCurrentCtrl(void);
extern void MBD_FOC_SENSORLESS_MODEL_step1(void);
extern void MBD_FOC_SENSORLESS_MODEL_terminate(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile uint16_T Pwm1Duty;     /* '<Root>/Data Store Memory5' */
extern volatile uint16_T Pwm2Duty;     /* '<Root>/Data Store Memory7' */
extern volatile uint16_T Pwm3Duty;     /* '<Root>/Data Store Memory8' */
extern volatile real32_T VelRef;       /* '<Root>/Data Store Memory11' */
extern volatile int16_T smoAnglePU;    /* '<Root>/Data Store Memory9' */

/* Real-time Model object */
extern RT_MODEL_MBD_FOC_SENSORLESS_MODEL_T *const MBD_FOC_SENSORLESS_MODEL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/Sqrt' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Propagation' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Vc' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S59>/Gain1' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Propagation' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Propagation' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Mod' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Unused code path elimination
 * Block '<S3>/Enable Closed Loop' : Unused code path elimination
 * Block '<S3>/Open Loop Start-up' : Unused code path elimination
 * Block '<S3>/Switch2' : Unused code path elimination
 * Block '<S79>/Ki2' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Propagation' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/int to uint' : Eliminate redundant data type conversion
 * Block '<S7>/Scale Ia Ib to (A)' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/enableInportSatLim' : Unused code path elimination
 * Block '<S21>/enableInportSatMethod' : Unused code path elimination
 * Block '<S16>/ReplaceInport_satLim' : Unused code path elimination
 * Block '<S16>/ReplaceInport_satMethod' : Unused code path elimination
 * Block '<S40>/Offset' : Unused code path elimination
 * Block '<S40>/Unary_Minus' : Unused code path elimination
 * Block '<S41>/Offset' : Unused code path elimination
 * Block '<S41>/Unary_Minus' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MBD_FOC_SENSORLESS_MODEL'
 * '<S1>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control'
 * '<S2>'   : 'MBD_FOC_SENSORLESS_MODEL/Inverter and Motor'
 * '<S3>'   : 'MBD_FOC_SENSORLESS_MODEL/OpentoClosed'
 * '<S4>'   : 'MBD_FOC_SENSORLESS_MODEL/Speed Control'
 * '<S5>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control'
 * '<S6>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR Cmd'
 * '<S7>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor'
 * '<S8>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling'
 * '<S9>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation'
 * '<S10>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Clarke Transform'
 * '<S11>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers'
 * '<S12>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform'
 * '<S13>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform'
 * '<S14>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup'
 * '<S15>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator'
 * '<S16>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S17>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S18>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S19>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S20>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S21>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S22>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S23>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S24>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S25>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S26>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S27>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S28>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S29>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S30>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S31>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S32>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S33>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2/Compare To Zero'
 * '<S34>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/serialPI'
 * '<S35>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/serialPI/Saturation Dynamic'
 * '<S36>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/serialPI/Saturation Dynamic1'
 * '<S37>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/serialPI'
 * '<S38>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/serialPI/Saturation Dynamic'
 * '<S39>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/serialPI/Saturation Dynamic1'
 * '<S40>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform/Switch_Axis'
 * '<S41>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform/Switch_Axis'
 * '<S42>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/Interpolation'
 * '<S43>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp'
 * '<S44>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S45>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S46>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S47>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S48>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S49>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S50>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S51>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S52>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S53>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor/Offset1'
 * '<S54>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU'
 * '<S55>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer'
 * '<S56>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator'
 * '<S57>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator/Accumulate'
 * '<S58>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator/Accumulate/Subsystem'
 * '<S59>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL'
 * '<S60>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/Subsystem'
 * '<S61>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/atan2'
 * '<S62>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/PLL_pi'
 * '<S63>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup'
 * '<S64>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Subsystem2'
 * '<S65>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Wrap_to_pi2'
 * '<S66>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/PLL_pi/serialPI'
 * '<S67>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/PLL_pi/serialPI/Saturation Dynamic'
 * '<S68>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/Interpolation'
 * '<S69>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp'
 * '<S70>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S71>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S72>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S73>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/Subsystem/Wrap_to_pi2'
 * '<S74>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/atan2/Subsystem1'
 * '<S75>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/atan2/Wrap_to_pi1'
 * '<S76>'  : 'MBD_FOC_SENSORLESS_MODEL/Inverter and Motor/Codegeneration'
 * '<S77>'  : 'MBD_FOC_SENSORLESS_MODEL/OpentoClosed/Chart'
 * '<S78>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch'
 * '<S79>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed'
 * '<S80>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Speed_Ref_Selector'
 * '<S81>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch/Codegen'
 * '<S82>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch/Codegen/Triggered Subsystem'
 * '<S83>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S84>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/serialPI'
 * '<S85>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S86>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S87>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S88>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/serialPI/Saturation Dynamic'
 * '<S89>'  : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/serialPI/Saturation Dynamic1'
 */
#endif                              /* RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
