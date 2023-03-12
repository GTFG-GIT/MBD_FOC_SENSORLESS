/*
 * File: MBD_FOC_SENSORLESS_MODEL.h
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
  real32_T PrevY;                      /* '<S4>/Rate Limiter2' */
  int16_T UnitDelay_DSTATE;            /* '<S224>/Unit Delay' */
  int16_T Integrator_DSTATE;           /* '<S205>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S205>/Integrator' */
} DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state for system '<Root>/Speed Control' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S168>/Triggered Subsystem' */
} ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T;

/* Block signals (default storage) */
typedef struct {
  int16_T u3[11];
  int32_T Gain2;                       /* '<S155>/Gain2' */
  int32_T DiscreteTimeIntegrator;
  int32_T DiscreteTimeIntegrator2;
  int32_T DiscreteTimeIntegrator1;
  int32_T DiscreteTimeIntegrator3;
  int32_T DiscreteTimeIntegrator4;
  int32_T xAcc;
  int32_T yAcc;
  int32_T xtmp;
  int32_T tmp03_u;
  int16_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint16_T Mode;                       /* '<S3>/Chart' */
  uint16_T Iab[2];                     /* '<S149>/Iab' */
  int16_T Gain;                        /* '<S155>/Gain' */
  int16_T Add1;                        /* '<S153>/Add1' */
  int16_T Input;                       /* '<S154>/Input' */
} B_MBD_FOC_SENSORLESS_MODEL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S150>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator1_DSTATE;/* '<S155>/Discrete-Time Integrator1' */
  int32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S157>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator2_DSTATE;/* '<S157>/Discrete-Time Integrator2' */
  int32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S155>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator1_DSTATE_i;/* '<S157>/Discrete-Time Integrator1' */
  int32_T DiscreteTimeIntegrator3_DSTATE;/* '<S157>/Discrete-Time Integrator3' */
  int32_T DiscreteTimeIntegrator4_DSTATE;/* '<S158>/Discrete-Time Integrator4' */
  int16_T Delay_DSTATE[4];             /* '<S1>/Delay' */
  int16_T Integrator_DSTATE;           /* '<S119>/Integrator' */
  int16_T Integrator_DSTATE_d;         /* '<S68>/Integrator' */
  int16_T UnitDelay_DSTATE;            /* '<S152>/Unit Delay' */
  int16_T UnitDelay3_DSTATE;           /* '<S158>/Unit Delay3' */
  int16_T Delay_DSTATE_j;              /* '<S157>/Delay' */
  int16_T Delay3_DSTATE;               /* '<S157>/Delay3' */
  int16_T Delay1_DSTATE;               /* '<S157>/Delay1' */
  int16_T Delay2_DSTATE;               /* '<S157>/Delay2' */
  int16_T Delay1_DSTATE_i;             /* '<S158>/Delay1' */
  uint16_T ADC_IA;                     /* '<Root>/Data Store Memory' */
  uint16_T ADC_IB;                     /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S3>/Chart' */
  volatile int16_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  int16_T SpeedRef;                    /* '<Root>/Data Store Memory4' */
  boolean_T Delay_DSTATE_k;            /* '<S153>/Delay' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  int8_T Integrator_PrevResetState;    /* '<S119>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S68>/Integrator' */
  uint8_T is_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S3>/Chart' */
  uint8_T is_active_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S3>/Chart' */
  boolean_T EnCurOffset;               /* '<Root>/Data Store Memory1' */
  boolean_T EnPosOffset;               /* '<Root>/Data Store Memory10' */
  boolean_T EnableFOC;                 /* '<Root>/Data Store Memory29' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory3' */
  boolean_T EnableClosedLoop;          /* '<Root>/Data Store Memory6' */
  boolean_T Accumulate_MODE;           /* '<S152>/Accumulate' */
  DW_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T SpeedControl;/* '<Root>/Speed Control' */
} DW_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_SpeedControl_MBD_FOC_SENSORLESS_MODEL_T SpeedControl;/* '<Root>/Speed Control' */
  ZCSigState AngleGenPos_PU_Reset_ZCE; /* '<S9>/AngleGen Pos_PU' */
} PrevZCX_MBD_FOC_SENSORLESS_MODEL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const int32_T DataTypeConversion;    /* '<S150>/Data Type Conversion' */
  const boolean_T NOT;                 /* '<S152>/NOT' */
} ConstB_MBD_FOC_SENSORLESS_MODEL_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S14>/sine_table_values'
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
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/Sqrt' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Vc' : Unused code path elimination
 * Block '<S148>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate' : Unused code path elimination
 * Block '<S152>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/int to uint' : Eliminate redundant data type conversion
 * Block '<S7>/Scale Ia Ib to (A)' : Eliminate redundant data type conversion
 * Block '<S152>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S157>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S155>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S158>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S158>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S21>/enableInportSatLim' : Unused code path elimination
 * Block '<S21>/enableInportSatMethod' : Unused code path elimination
 * Block '<S16>/ReplaceInport_satLim' : Unused code path elimination
 * Block '<S16>/ReplaceInport_satMethod' : Unused code path elimination
 * Block '<S136>/Offset' : Unused code path elimination
 * Block '<S136>/Unary_Minus' : Unused code path elimination
 * Block '<S137>/Offset' : Unused code path elimination
 * Block '<S137>/Unary_Minus' : Unused code path elimination
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
 * '<S34>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S35>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S36>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S37>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S38>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S39>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S40>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S41>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S42>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S43>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S44>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S45>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S46>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S47>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S48>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S49>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S50>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S51>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S52>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S53>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S54>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S55>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S56>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S57>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S58>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S59>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S60>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S61>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S62>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S63>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S64>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S65>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S66>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S67>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S68>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S69>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S70>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S71>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S72>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S73>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S74>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S75>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S76>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S77>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S78>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S79>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S80>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S81>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S82>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S83>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S84>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S85>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S86>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S87>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S88>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S89>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S90>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S91>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S92>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S93>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S94>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S95>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S96>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S97>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S98>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S99>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S100>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S101>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S102>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S103>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S104>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S105>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S106>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S107>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S108>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S109>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S110>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S111>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S112>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S113>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S114>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S115>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S116>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S117>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S118>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S119>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S120>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S121>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S122>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S123>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S124>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S125>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S126>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S127>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S128>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S129>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S130>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S131>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S132>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S133>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S134>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S135>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S136>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform/Switch_Axis'
 * '<S137>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform/Switch_Axis'
 * '<S138>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/Interpolation'
 * '<S139>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp'
 * '<S140>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S141>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S142>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S143>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S144>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S145>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S146>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S147>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S148>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S149>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor/Offset1'
 * '<S150>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU'
 * '<S151>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer'
 * '<S152>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator'
 * '<S153>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator/Accumulate'
 * '<S154>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator/Accumulate/Subsystem'
 * '<S155>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation'
 * '<S156>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/Scaling'
 * '<S157>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/Adaptive Filter1'
 * '<S158>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/Subsystem'
 * '<S159>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/atan2'
 * '<S160>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/Subsystem/Wrap_to_pi2'
 * '<S161>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/atan2/Subsystem1'
 * '<S162>' : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Sliding Mode Observer/SMO Implemetation/atan2/Wrap_to_pi1'
 * '<S163>' : 'MBD_FOC_SENSORLESS_MODEL/Inverter and Motor/Codegeneration'
 * '<S164>' : 'MBD_FOC_SENSORLESS_MODEL/OpentoClosed/Chart'
 * '<S165>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch'
 * '<S166>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed'
 * '<S167>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Speed_Ref_Selector'
 * '<S168>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch/Codegen'
 * '<S169>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/Enable Switch/Codegen/Triggered Subsystem'
 * '<S170>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S171>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S172>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S173>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S174>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S175>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S176>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S177>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S178>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S179>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S180>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S181>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S182>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S183>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S184>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S185>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S186>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S187>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S188>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S189>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S190>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S191>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S192>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S193>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S194>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S195>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S196>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S197>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S198>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S199>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S200>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S201>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S202>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S203>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S204>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S205>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S206>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S207>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S208>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S209>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S210>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S211>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S212>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S213>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S214>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S215>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S216>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S217>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S218>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S219>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S220>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S221>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S222>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S223>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S224>' : 'MBD_FOC_SENSORLESS_MODEL/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                              /* RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
