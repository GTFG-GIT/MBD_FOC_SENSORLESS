/*
 * File: MBD_FOC_SENSORLESS_MODEL.h
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

/* Block signals (default storage) */
typedef struct {
  int16_T u3[11];
  real32_T Add1_m;                     /* '<S91>/Add1' */
  real32_T Sum_c;                      /* '<S94>/Sum' */
  int32_T DiscreteTimeIntegrator4;
  int32_T i;
  int32_T u0;
  int32_T rtb_Sum5_tmp;
  uint16_T SpeedCtrl;                  /* '<S4>/Chart' */
  uint16_T Iab[2];                     /* '<S56>/Iab' */
  int16_T Switch2[2];                  /* '<S5>/Switch2' */
  int16_T Add1;                        /* '<S60>/Add1' */
  int16_T Input;                       /* '<S61>/Input' */
} B_MBD_FOC_SENSORLESS_MODEL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S94>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S91>/Unit Delay' */
  int32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S57>/Discrete-Time Integrator' */
  int32_T DiscreteTimeIntegrator4_DSTATE;/* '<S63>/Discrete-Time Integrator4' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory4' */
  int16_T UnitDelay1_DSTATE;           /* '<S58>/Unit Delay1' */
  int16_T Delay_DSTATE[4];             /* '<S2>/Delay' */
  int16_T UnitDelay_DSTATE_l;          /* '<S58>/Unit Delay' */
  int16_T UnitDelay3_DSTATE;           /* '<S58>/Unit Delay3' */
  int16_T UnitDelay2_DSTATE;           /* '<S58>/Unit Delay2' */
  int16_T UnitDelay_DSTATE_c;          /* '<S40>/Unit Delay' */
  int16_T UnitDelay_DSTATE_lr;         /* '<S37>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S69>/Unit Delay' */
  int16_T UnitDelay4_DSTATE;           /* '<S62>/Unit Delay4' */
  int16_T UnitDelay_DSTATE_n;          /* '<S88>/Unit Delay' */
  int16_T UnitDelay_DSTATE_nq;         /* '<S59>/Unit Delay' */
  int16_T UnitDelay3_DSTATE_c;         /* '<S63>/Unit Delay3' */
  int16_T Delay1_DSTATE;               /* '<S63>/Delay1' */
  uint16_T ADC_IA;                     /* '<Root>/Data Store Memory' */
  uint16_T ADC_IB;                     /* '<Root>/Data Store Memory2' */
  uint16_T temporalCounter_i1;         /* '<S4>/Chart' */
  int16_T Memory1_PreviousInput;       /* '<S62>/Memory1' */
  int16_T Memory_PreviousInput;        /* '<S62>/Memory' */
  uint8_T Output_DSTATE;               /* '<S1>/Output' */
  boolean_T Delay_DSTATE_k;            /* '<S60>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S94>/Discrete-Time Integrator' */
  uint8_T is_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S4>/Chart' */
  uint8_T is_active_c3_MBD_FOC_SENSORLESS_MODEL;/* '<S4>/Chart' */
  boolean_T EnCurOffset;               /* '<Root>/Data Store Memory1' */
  boolean_T EnPosOffset;               /* '<Root>/Data Store Memory10' */
  boolean_T EnableFOC;                 /* '<Root>/Data Store Memory29' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory3' */
  boolean_T Accumulate_MODE;           /* '<S59>/Accumulate' */
} DW_MBD_FOC_SENSORLESS_MODEL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_c;/* '<S85>/Triggered Subsystem' */
  ZCSigState AngleGenPos_PU_Reset_ZCE; /* '<S12>/AngleGen Pos_PU' */
} PrevZCX_MBD_FOC_SENSORLESS_MODEL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant2;            /* '<S83>/Constant2' */
  const real32_T Product;              /* '<S94>/Product' */
  const real32_T Gain;                 /* '<S94>/Gain' */
  const int32_T DataTypeConversion;    /* '<S57>/Data Type Conversion' */
  const int16_T Square;                /* '<S58>/Square' */
  const boolean_T NOT;                 /* '<S59>/NOT' */
} ConstB_MBD_FOC_SENSORLESS_MODEL_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S17>/sine_table_values'
   *   '<S66>/sine_table_values'
   */
  int16_T pooled12[1002];
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
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Propagation' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S25>/Sqrt' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Propagation' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Vc' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S62>/Gain1' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Mod' : Unused code path elimination
 * Block '<S4>/Data Type Conversion' : Unused code path elimination
 * Block '<S4>/Enable Closed Loop' : Unused code path elimination
 * Block '<S4>/Open Loop Start-up' : Unused code path elimination
 * Block '<S4>/Switch2' : Unused code path elimination
 * Block '<S82>/Ki2' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Propagation' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Propagation' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/int to uint' : Eliminate redundant data type conversion
 * Block '<S10>/Scale Ia Ib to (A)' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/enableInportSatLim' : Unused code path elimination
 * Block '<S24>/enableInportSatMethod' : Unused code path elimination
 * Block '<S19>/ReplaceInport_satLim' : Unused code path elimination
 * Block '<S19>/ReplaceInport_satMethod' : Unused code path elimination
 * Block '<S43>/Offset' : Unused code path elimination
 * Block '<S43>/Unary_Minus' : Unused code path elimination
 * Block '<S44>/Offset' : Unused code path elimination
 * Block '<S44>/Unary_Minus' : Unused code path elimination
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
 * '<S1>'   : 'MBD_FOC_SENSORLESS_MODEL/Counter Limited'
 * '<S2>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control'
 * '<S3>'   : 'MBD_FOC_SENSORLESS_MODEL/Inverter and Motor'
 * '<S4>'   : 'MBD_FOC_SENSORLESS_MODEL/OpentoClosed'
 * '<S5>'   : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem'
 * '<S6>'   : 'MBD_FOC_SENSORLESS_MODEL/Counter Limited/Increment Real World'
 * '<S7>'   : 'MBD_FOC_SENSORLESS_MODEL/Counter Limited/Wrap To Zero'
 * '<S8>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control'
 * '<S9>'   : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR Cmd'
 * '<S10>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor'
 * '<S11>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Output Scaling'
 * '<S12>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation'
 * '<S13>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Clarke Transform'
 * '<S14>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers'
 * '<S15>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform'
 * '<S16>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform'
 * '<S17>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup'
 * '<S18>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator'
 * '<S19>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S20>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S21>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S22>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S23>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S24>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S25>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S26>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S27>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S28>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S29>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S30>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S31>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S32>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S33>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S34>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S35>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S36>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2/Compare To Zero'
 * '<S37>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/serialPI'
 * '<S38>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/serialPI/Saturation Dynamic'
 * '<S39>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/serialPI/Saturation Dynamic1'
 * '<S40>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/serialPI'
 * '<S41>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/serialPI/Saturation Dynamic'
 * '<S42>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/serialPI/Saturation Dynamic1'
 * '<S43>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Inverse Park Transform/Switch_Axis'
 * '<S44>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Park Transform/Switch_Axis'
 * '<S45>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/Interpolation'
 * '<S46>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp'
 * '<S47>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S48>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S49>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S50>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S51>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S52>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S53>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S54>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S55>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S56>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/MOTOR - Board Sensor/Offset1'
 * '<S57>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU'
 * '<S58>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer'
 * '<S59>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator'
 * '<S60>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator/Accumulate'
 * '<S61>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/AngleGen Pos_PU/Position Generator/Accumulate/Subsystem'
 * '<S62>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL'
 * '<S63>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/Subsystem'
 * '<S64>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/atan2'
 * '<S65>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/PLL_pi'
 * '<S66>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup'
 * '<S67>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Subsystem2'
 * '<S68>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Wrap_to_pi2'
 * '<S69>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/PLL_pi/serialPI'
 * '<S70>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/PLL_pi/serialPI/Saturation Dynamic'
 * '<S71>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/Interpolation'
 * '<S72>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp'
 * '<S73>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S74>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S75>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/PLL/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S76>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/Subsystem/Wrap_to_pi2'
 * '<S77>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/atan2/Subsystem1'
 * '<S78>'  : 'MBD_FOC_SENSORLESS_MODEL/Current Control/Position and Speed Estimation/Flux  Observer/atan2/Wrap_to_pi1'
 * '<S79>'  : 'MBD_FOC_SENSORLESS_MODEL/Inverter and Motor/Codegeneration'
 * '<S80>'  : 'MBD_FOC_SENSORLESS_MODEL/OpentoClosed/Chart'
 * '<S81>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/Enable Switch'
 * '<S82>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed'
 * '<S83>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/RateLimiter1'
 * '<S84>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/Speed_Ref_Selector'
 * '<S85>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/Enable Switch/Codegen'
 * '<S86>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/Enable Switch/Codegen/Triggered Subsystem'
 * '<S87>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/Zero_Cancellation'
 * '<S88>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/serialPI'
 * '<S89>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S90>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S91>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S92>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/serialPI/Saturation Dynamic'
 * '<S93>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/PI_Controller_Speed/serialPI/Saturation Dynamic1'
 * '<S94>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/RateLimiter1/Subsystem'
 * '<S95>'  : 'MBD_FOC_SENSORLESS_MODEL/Triggered Subsystem/RateLimiter1/Subsystem/Saturation Dynamic'
 */
#endif                              /* RTW_HEADER_MBD_FOC_SENSORLESS_MODEL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
