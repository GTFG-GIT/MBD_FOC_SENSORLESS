/*
 * File: MBD_FOC_SENSORLESS_MODEL.h
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
  real32_T PrevY;                      /* '<S3>/Rate Limiter2' */
  int16_T UnitDelay_DSTATE;            /* '<S231>/Unit Delay' */
  int16_T Integrator_DSTATE;           /* '<S212>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S212>/Integrator' */
} DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state for system '<Root>/Speed Control' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S175>/Triggered Subsystem' */
} ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T;

/* Block signals (default storage) */
typedef struct {
  int16_T u3[11];
  int32_T Gain2;                       /* '<S163>/Gain2' */
  int32_T DiscreteTimeIntegrator;
  int32_T DiscreteTimeIntegrator2;
  int32_T DiscreteTimeIntegrator1;
  int32_T DiscreteTimeIntegrator3;
  int32_T DiscreteTimeIntegrator4;
  int32_T xAcc;
  int32_T yAcc;
  int32_T xtmp;
  int32_T ytmp;
  int32_T tmp03_u;
  uint32_T Add1;                       /* '<S151>/Add1' */
  int16_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint16_T Mode;                       /* '<S157>/Chart' */
  uint16_T Iab[2];                     /* '<S148>/Iab' */
  int16_T Gain;                        /* '<S163>/Gain' */
  int16_T Add1_k;                      /* '<S160>/Add1' */
  int16_T Input;                       /* '<S161>/Input' */
} B_MBD_FOC_SENSORLESS_MODEL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T Delay_DSTATE;               /* '<S151>/Delay' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S156>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator1_DSTATE;/* '<S163>/Discrete-Time Integrator1' */
  int32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S165>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator2_DSTATE;/* '<S165>/Discrete-Time Integrator2' */
  int32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S163>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator1_DSTATE_i;/* '<S165>/Discrete-Time Integrator1' */
  int32_T DiscreteTimeIntegrator3_DSTATE;/* '<S165>/Discrete-Time Integrator3' */
  int32_T DiscreteTimeIntegrator4_DSTATE;/* '<S166>/Discrete-Time Integrator4' */
  int16_T Delay_DSTATE_h[4];           /* '<S1>/Delay' */
  int16_T Integrator_DSTATE;           /* '<S118>/Integrator' */
  int16_T Integrator_DSTATE_d;         /* '<S67>/Integrator' */
  int16_T UnitDelay_DSTATE;            /* '<S159>/Unit Delay' */
  int16_T UnitDelay3_DSTATE;           /* '<S166>/Unit Delay3' */
  int16_T Delay_DSTATE_j;              /* '<S165>/Delay' */
  int16_T Delay3_DSTATE;               /* '<S165>/Delay3' */
  int16_T Delay1_DSTATE;               /* '<S165>/Delay1' */
  int16_T Delay2_DSTATE;               /* '<S165>/Delay2' */
  int16_T Delay1_DSTATE_i;             /* '<S166>/Delay1' */
  uint16_T ADC_IA;                     /* '<Root>/Data Store Memory' */
  uint16_T ADC_IB;                     /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S157>/Chart' */
  volatile int16_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  int16_T SpeedRef;                    /* '<Root>/Data Store Memory4' */
  boolean_T Delay_DSTATE_n;            /* '<S149>/Delay' */
  boolean_T Delay_DSTATE_k;            /* '<S160>/Delay' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  int8_T Integrator_PrevResetState;    /* '<S118>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S67>/Integrator' */
  uint8_T is_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S157>/Chart' */
  uint8_T is_active_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S157>/Chart' */
  boolean_T EnCurOffset;               /* '<Root>/Data Store Memory1' */
  boolean_T EnableFOC;                 /* '<Root>/Data Store Memory29' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory3' */
  boolean_T EnableClosedLoop;          /* '<Root>/Data Store Memory6' */
  boolean_T Accumulate_MODE;           /* '<S159>/Accumulate' */
  boolean_T UpCounter_MODE;            /* '<S149>/Up Counter' */
  DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T SpeedControl;/* '<Root>/Speed Control' */
} DW_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T SpeedControl;/* '<Root>/Speed Control' */
  ZCSigState OpenloopPos_PU_Reset_ZCE; /* '<S8>/Openloop Pos_PU' */
} PrevZCX_MBD_FOC_SENSORLESS_MODEL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const int32_T DataTypeConversion;    /* '<S156>/Data Type Conversion' */
  const boolean_T NOT;                 /* '<S159>/NOT' */
} ConstB_MBD_FOC_SENSORLESS_MODEL_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S13>/sine_table_values'
   */
  int16_T sine_table_values_Value[1002];
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
extern void MbdFocSpdCtrl(void);
extern void MBD_FOC_SENSORLESS_MODEL_terminate(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile uint16_T Pwm1Duty;     /* '<Root>/Data Store Memory5' */
extern volatile uint16_T Pwm2Duty;     /* '<Root>/Data Store Memory7' */
extern volatile uint16_T Pwm3Duty;     /* '<Root>/Data Store Memory8' */
extern volatile int16_T smoAnglePU;    /* '<Root>/Data Store Memory9' */

/* Real-time Model object */
extern RT_MODEL_MBD_FOC_SENSORLESS_MODEL_T *const MBD_FOC_SENSORLESS_MODEL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S21>/Sqrt' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Vc' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/int to uint' : Eliminate redundant data type conversion
 * Block '<S6>/Scale Ia Ib to (A)' : Eliminate redundant data type conversion
 * Block '<S159>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S165>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S163>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S166>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S166>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S20>/enableInportSatLim' : Unused code path elimination
 * Block '<S20>/enableInportSatMethod' : Unused code path elimination
 * Block '<S15>/ReplaceInport_satLim' : Unused code path elimination
 * Block '<S15>/ReplaceInport_satMethod' : Unused code path elimination
 * Block '<S135>/Offset' : Unused code path elimination
 * Block '<S135>/Unary_Minus' : Unused code path elimination
 * Block '<S136>/Offset' : Unused code path elimination
 * Block '<S136>/Unary_Minus' : Unused code path elimination
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
 * '<S3>'   : 'MBD_FOC_SENSORLESS_MODEL/Speed Control'
 * '<S4>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control'
 * '<S5>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR Cmd'
 * '<S6>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor'
 * '<S7>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling'
 * '<S8>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation'
 * '<S9>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Clarke Transform'
 * '<S10>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers'
 * '<S11>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform'
 * '<S12>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform'
 * '<S13>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup'
 * '<S14>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator'
 * '<S15>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S16>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S17>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S18>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S19>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S20>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S21>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S22>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S23>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S24>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S25>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S26>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S27>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S28>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S29>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S30>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S31>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S32>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2/Compare To Zero'
 * '<S33>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S34>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S35>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S36>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S37>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S38>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S39>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S40>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S41>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S42>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S43>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S44>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S45>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S46>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S47>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S48>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S49>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S50>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S51>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S52>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S53>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S54>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S55>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S56>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S57>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S58>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S59>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S60>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S61>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S62>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S63>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S64>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S65>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S66>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S67>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S68>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S69>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S70>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S71>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S72>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S73>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S74>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S75>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S76>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S77>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S78>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S79>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S80>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S81>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S82>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S83>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S84>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S85>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S86>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S87>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S88>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S89>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S90>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S91>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S92>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S93>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S94>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S95>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S96>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S97>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S98>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S99>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S100>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S101>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S102>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S103>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S104>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S105>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S106>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S107>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S108>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S109>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S110>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S111>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S112>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S113>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S114>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S115>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S116>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S117>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S118>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S119>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S120>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S121>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S122>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S123>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S124>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S125>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S126>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S127>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S128>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S129>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S130>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S131>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S132>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S133>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S134>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S135>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform/Switch_Axis'
 * '<S136>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform/Switch_Axis'
 * '<S137>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/Interpolation'
 * '<S138>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp'
 * '<S139>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S140>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S141>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S142>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S143>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S144>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S145>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S146>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S147>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S148>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor/Offset1'
 * '<S149>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector'
 * '<S150>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector/Subsystem1'
 * '<S151>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector/Up Counter'
 * '<S152>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant'
 * '<S153>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant1'
 * '<S154>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant2'
 * '<S155>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant3'
 * '<S156>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Openloop Pos_PU'
 * '<S157>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/OpentoClosed'
 * '<S158>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer'
 * '<S159>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Openloop Pos_PU/Position Generator'
 * '<S160>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Openloop Pos_PU/Position Generator/Accumulate'
 * '<S161>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Openloop Pos_PU/Position Generator/Accumulate/Subsystem'
 * '<S162>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/OpentoClosed/Chart'
 * '<S163>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation'
 * '<S164>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/Scaling'
 * '<S165>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/Adaptive Filter1'
 * '<S166>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/Subsystem'
 * '<S167>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/atan2'
 * '<S168>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/Subsystem/Wrap_to_pi2'
 * '<S169>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/atan2/Subsystem1'
 * '<S170>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/atan2/Wrap_to_pi1'
 * '<S171>' : 'MBD_FOC_SENSORLESS_MODEL/Inverter and Motor/Codegeneration'
 * '<S172>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch'
 * '<S173>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed'
 * '<S174>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Speed_Ref_Selector'
 * '<S175>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch/Codegen'
 * '<S176>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch/Codegen/Triggered Subsystem'
 * '<S177>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S178>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S179>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S180>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S181>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S182>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S183>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S184>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S185>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S186>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S187>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S188>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S189>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S190>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S191>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S192>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S193>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S194>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S195>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S196>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S197>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S198>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S199>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S200>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S201>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S202>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S203>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S204>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S205>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S206>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S207>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S208>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S209>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S210>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S211>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S212>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S213>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S214>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S215>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S216>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S217>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S218>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S219>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S220>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S221>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S222>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S223>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S224>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S225>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S226>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S227>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S228>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S229>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S230>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S231>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                              /* RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
