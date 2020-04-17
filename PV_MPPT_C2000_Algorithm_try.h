/*
 * File: PV_MPPT_C2000_Algorithm_try.h
 *
 * Code generated for Simulink model 'PV_MPPT_C2000_Algorithm_try'.
 *
 * Model version                  : 1.382
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Apr 14 12:17:17 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PV_MPPT_C2000_Algorithm_try_h_
#define RTW_HEADER_PV_MPPT_C2000_Algorithm_try_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef PV_MPPT_C2000_Algorithm_try_COMMON_INCLUDES_
# define PV_MPPT_C2000_Algorithm_try_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#include "DSP28xx_SciUtil.h"
#include "MW_SPI.h"
#include "MW_c2000SPI.h"
#endif                        /* PV_MPPT_C2000_Algorithm_try_COMMON_INCLUDES_ */

#include "PV_MPPT_C2000_Algorithm_try_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition6;            /* '<S5>/Rate Transition6' */
  real32_T RateTransition7;            /* '<S5>/Rate Transition7' */
  real32_T RateTransition1;            /* '<S5>/Rate Transition1' */
  real32_T RateTransition5;            /* '<S5>/Rate Transition5' */
  real32_T InvSaturation;              /* '<S8>/Inv Saturation' */
  real32_T Vref;                       /* '<S5>/Perturb and Observe MPPT' */
  uint16_T Vpv;                        /* '<Root>/ADC5' */
  uint16_T Ipv;                        /* '<Root>/ADC5' */
  uint16_T Vboost;                     /* '<Root>/ADC5' */
  uint16_T Iboost;                     /* '<Root>/ADC5' */
  uint16_T Vac;                        /* '<Root>/ADC5' */
  uint16_T SCIReceive[6];              /* '<Root>/SCI Receive' */
  uint16_T TmpSignalConversionAtSCITransmi[7];
                                  /* '<Root>/Signal Packing for Host SCI XMT' */
} BlockIO_PV_MPPT_C2000_Algorithm;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_tic2000_blocks_SPIW obj; /* '<S6>/SPI Transmit' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S2>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S59>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE;          /* '<S91>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S43>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_gp;/* '<S4>/Discrete-Time Integrator' */
  real32_T RateTransition6_Buffer0;    /* '<S5>/Rate Transition6' */
  real32_T RateTransition7_Buffer0;    /* '<S5>/Rate Transition7' */
  real32_T RateTransition1_Buffer0;    /* '<S5>/Rate Transition1' */
  real32_T RateTransition5_Buffer0;    /* '<S5>/Rate Transition5' */
  real32_T RateTransition10_Buffer;    /* '<S7>/Rate Transition10' */
  real32_T RateTransition3_Buffer;     /* '<S7>/Rate Transition3' */
  real32_T RateTransition6_Buffer;     /* '<S7>/Rate Transition6' */
  real32_T RateTransition7_Buffer;     /* '<S7>/Rate Transition7' */
  real32_T RateTransition8_Buffer;     /* '<S7>/Rate Transition8' */
  real32_T P;                          /* '<S5>/Perturb and Observe MPPT' */
  real32_T deltaP;                     /* '<S5>/Perturb and Observe MPPT' */
  real32_T Pprev;                      /* '<S5>/Perturb and Observe MPPT' */
  real32_T Vprev;                      /* '<S5>/Perturb and Observe MPPT' */
  real32_T deltaV;                     /* '<S5>/Perturb and Observe MPPT' */
  real32_T Vref_prev;                  /* '<S5>/Perturb and Observe MPPT' */
  uint16_T RateTransition5_Buffer;     /* '<S7>/Rate Transition5' */
  uint16_T Output_DSTATE;              /* '<S10>/Output' */
  int16_T DiscreteTimeIntegrator_PrevRese;/* '<S59>/Discrete-Time Integrator' */
  uint16_T is_active_c1_PV_MPPT_C2000_Algo;/* '<S5>/Perturb and Observe MPPT' */
  uint16_T is_c1_PV_MPPT_C2000_Algorithm_t;/* '<S5>/Perturb and Observe MPPT' */
  uint16_T is_EnableMPPT;              /* '<S5>/Perturb and Observe MPPT' */
} D_Work_PV_MPPT_C2000_Algorithm_;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState PerturbandObserveMPPT_Trig_ZCE;/* '<S5>/Perturb and Observe MPPT' */
} PrevZCSigStates_PV_MPPT_C2000_A;

/* Parameters (default storage) */
struct Parameters_PV_MPPT_C2000_Algori_ {
  real32_T IQ13;                       /* Variable: IQ13
                                        * Referenced by: '<S112>/Scale to Uint16'
                                        */
  real32_T IQ8;                        /* Variable: IQ8
                                        * Referenced by: '<S107>/Scale to Uint16'
                                        */
  real32_T DigitalPulse_Duty;          /* Mask Parameter: DigitalPulse_Duty
                                        * Referenced by: '<S106>/Constant'
                                        */
  real32_T BoostVoltageController_I; /* Mask Parameter: BoostVoltageController_I
                                      * Referenced by: '<S40>/Integral Gain'
                                      */
  real32_T DCDCBoostVoltageController_I;
                                 /* Mask Parameter: DCDCBoostVoltageController_I
                                  * Referenced by: '<S88>/Integral Gain'
                                  */
  real32_T DCDCBoostVoltageController_Init;
                              /* Mask Parameter: DCDCBoostVoltageController_Init
                               * Referenced by: '<S91>/Integrator'
                               */
  real32_T BoostVoltageController_InitialC;
                              /* Mask Parameter: BoostVoltageController_InitialC
                               * Referenced by: '<S43>/Integrator'
                               */
  real32_T DCDCBoostVoltageController_Lowe;
                              /* Mask Parameter: DCDCBoostVoltageController_Lowe
                               * Referenced by:
                               *   '<S84>/DeadZone'
                               *   '<S98>/Saturation'
                               */
  real32_T BoostVoltageController_LowerSat;
                              /* Mask Parameter: BoostVoltageController_LowerSat
                               * Referenced by:
                               *   '<S36>/DeadZone'
                               *   '<S50>/Saturation'
                               */
  real32_T DCDCBoostVoltageController_P;
                                 /* Mask Parameter: DCDCBoostVoltageController_P
                                  * Referenced by: '<S96>/Proportional Gain'
                                  */
  real32_T BoostVoltageController_P; /* Mask Parameter: BoostVoltageController_P
                                      * Referenced by: '<S48>/Proportional Gain'
                                      */
  real32_T DCDCBoostVoltageController_Uppe;
                              /* Mask Parameter: DCDCBoostVoltageController_Uppe
                               * Referenced by:
                               *   '<S84>/DeadZone'
                               *   '<S98>/Saturation'
                               */
  real32_T BoostVoltageController_UpperSat;
                              /* Mask Parameter: BoostVoltageController_UpperSat
                               * Referenced by:
                               *   '<S36>/DeadZone'
                               *   '<S50>/Saturation'
                               */
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S12>/FixPt Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S59>/Constant1'
                                        */
  real32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real32_T Constant1_Value_l;          /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S84>/Constant1'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S9>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S9>/Discrete-Time Integrator'
                                 */
  real32_T DiscreteTimeIntegrator_gainva_h;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                           * Referenced by: '<S2>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_IC_n;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_n
                               * Referenced by: '<S2>/Discrete-Time Integrator'
                               */
  real32_T RateTransition6_InitialConditio;/* Expression: single(3)
                                            * Referenced by: '<S5>/Rate Transition6'
                                            */
  real32_T RateTransition7_InitialConditio;/* Expression: single(0)
                                            * Referenced by: '<S5>/Rate Transition7'
                                            */
  real32_T RateTransition1_InitialConditio;/* Expression: single(0.1)
                                            * Referenced by: '<S5>/Rate Transition1'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S59>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_IC_k;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_k
                               * Referenced by: '<S59>/Discrete-Time Integrator'
                               */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S91>/Integrator'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S60>/Bias'
                                        */
  real32_T Negate_Gain;                /* Computed Parameter: Negate_Gain
                                        * Referenced by: '<S60>/Negate'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S5>/Gain'
                                        */
  real32_T SineLookup_table[201];      /* Computed Parameter: SineLookup_table
                                        * Referenced by: '<S1>/Sine Lookup'
                                        */
  real32_T Vboost_Ref_Value;           /* Computed Parameter: Vboost_Ref_Value
                                        * Referenced by: '<S3>/Vboost_Ref'
                                        */
  real32_T NormalizeBoostVoltage_Gain;
                               /* Computed Parameter: NormalizeBoostVoltage_Gain
                                * Referenced by: '<S3>/Normalize Boost Voltage'
                                */
  real32_T Integrator_gainval_p;     /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S43>/Integrator'
                                      */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S3>/Switch'
                                        */
  real32_T Bias_Bias_m;                /* Computed Parameter: Bias_Bias_m
                                        * Referenced by: '<S1>/Bias'
                                        */
  real32_T ScaletoUint3_Gain;          /* Computed Parameter: ScaletoUint3_Gain
                                        * Referenced by: '<S1>/Scale to Uint3'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real32_T Bias1_Bias;                 /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S1>/Bias1'
                                        */
  real32_T ScaletoUint4_Gain;          /* Computed Parameter: ScaletoUint4_Gain
                                        * Referenced by: '<S1>/Scale to Uint4'
                                        */
  real32_T uT6_Gain;                   /* Computed Parameter: uT6_Gain
                                        * Referenced by: '<S2>/1//T6'
                                        */
  real32_T ZeroGain_Gain;              /* Computed Parameter: ZeroGain_Gain
                                        * Referenced by: '<S36>/ZeroGain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_f;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                           * Referenced by: '<S4>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_IC_h;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_h
                               * Referenced by: '<S4>/Discrete-Time Integrator'
                               */
  real32_T uT6_Gain_a;                 /* Computed Parameter: uT6_Gain_a
                                        * Referenced by: '<S4>/1//T6'
                                        */
  real32_T ZeroGain_Gain_p;            /* Computed Parameter: ZeroGain_Gain_p
                                        * Referenced by: '<S84>/ZeroGain'
                                        */
  real32_T RateTransition5_InitialConditio;/* Expression: single(25)
                                            * Referenced by: '<S5>/Rate Transition5'
                                            */
  real32_T uT6_Gain_d;                 /* Computed Parameter: uT6_Gain_d
                                        * Referenced by: '<S9>/1//T6'
                                        */
  real32_T RemoveIQ13ScalingUint_Gain;
                               /* Computed Parameter: RemoveIQ13ScalingUint_Gain
                                * Referenced by: '<S108>/Remove IQ13 Scaling Uint'
                                */
  real32_T IrradianceSaturation_UpperSat;
                            /* Computed Parameter: IrradianceSaturation_UpperSat
                             * Referenced by: '<S8>/Irradiance Saturation'
                             */
  real32_T IrradianceSaturation_LowerSat;
                            /* Computed Parameter: IrradianceSaturation_LowerSat
                             * Referenced by: '<S8>/Irradiance Saturation'
                             */
  real32_T SigtoVpv1_Gain;             /* Computed Parameter: SigtoVpv1_Gain
                                        * Referenced by: '<S7>/Sig to Vpv1'
                                        */
  real32_T Uint16tosingle2_Gain;     /* Computed Parameter: Uint16tosingle2_Gain
                                      * Referenced by: '<S7>/Uint16 to single2'
                                      */
  real32_T Uint16tosingle5_Gain;     /* Computed Parameter: Uint16tosingle5_Gain
                                      * Referenced by: '<S7>/Uint16 to single5'
                                      */
  real32_T Uint16tosingle6_Gain;     /* Computed Parameter: Uint16tosingle6_Gain
                                      * Referenced by: '<S7>/Uint16 to single6'
                                      */
  real32_T DutySaturation_UpperSat;
                                  /* Computed Parameter: DutySaturation_UpperSat
                                   * Referenced by: '<S111>/Duty Saturation'
                                   */
  real32_T DutySaturation_LowerSat;
                                  /* Computed Parameter: DutySaturation_LowerSat
                                   * Referenced by: '<S111>/Duty Saturation'
                                   */
  real32_T RemoveIQ8ScalingUint_Gain;
                                /* Computed Parameter: RemoveIQ8ScalingUint_Gain
                                 * Referenced by: '<S110>/Remove IQ8 Scaling Uint'
                                 */
  real32_T RemoveIQ8ScalingUint_Gain_p;
                              /* Computed Parameter: RemoveIQ8ScalingUint_Gain_p
                               * Referenced by: '<S109>/Remove IQ8 Scaling Uint'
                               */
  real32_T InvSaturation_UpperSat; /* Computed Parameter: InvSaturation_UpperSat
                                    * Referenced by: '<S8>/Inv Saturation'
                                    */
  real32_T InvSaturation_LowerSat; /* Computed Parameter: InvSaturation_LowerSat
                                    * Referenced by: '<S8>/Inv Saturation'
                                    */
  uint16_T Uint16tosingle3_Gain;     /* Computed Parameter: Uint16tosingle3_Gain
                                      * Referenced by: '<Root>/Uint16 to single3'
                                      */
  uint16_T ADCtoVpv_Gain;              /* Computed Parameter: ADCtoVpv_Gain
                                        * Referenced by: '<Root>/ADC to Vpv'
                                        */
  uint16_T ADCtoIpv_Gain;              /* Computed Parameter: ADCtoIpv_Gain
                                        * Referenced by: '<Root>/ADC to Ipv'
                                        */
  uint16_T Uint16tosingle4_Gain;     /* Computed Parameter: Uint16tosingle4_Gain
                                      * Referenced by: '<Root>/Uint16 to single4'
                                      */
  uint16_T ScaletoUint2_Gain;          /* Computed Parameter: ScaletoUint2_Gain
                                        * Referenced by: '<S111>/Scale to Uint2'
                                        */
  uint16_T ScaletoUit7_Gain;           /* Computed Parameter: ScaletoUit7_Gain
                                        * Referenced by: '<S8>/Scale to Uit7'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S6>/Constant'
                                        */
  uint16_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S10>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S11>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_PV_MPPT_C2000_Algorithm {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_PV_MPPT_C2000_Algori PV_MPPT_C2000_Algorithm_try_P;

/* Block signals (default storage) */
extern BlockIO_PV_MPPT_C2000_Algorithm PV_MPPT_C2000_Algorithm_try_B;

/* Block states (default storage) */
extern D_Work_PV_MPPT_C2000_Algorithm_ PV_MPPT_C2000_Algorithm_t_DWork;

/* External function called from main */
extern void PV_MPPT_C2000_Algorithm_try_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void PV_MPPT_C2000_Algorithm_try_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void PV_MPPT_C2000_Algorithm_try_initialize(void);
extern void PV_MPPT_C2000_Algorithm_try_step0(void);
extern void PV_MPPT_C2000_Algorithm_try_step1(void);
extern void PV_MPPT_C2000_Algorithm_try_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PV_MPPT_C2000_Algorith *const PV_MPPT_C2000_Algorithm_try_M;

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
 * '<Root>' : 'PV_MPPT_C2000_Algorithm_try'
 * '<S1>'   : 'PV_MPPT_C2000_Algorithm_try/Generated Sinewave  and PWM Duty Cycles'
 * '<S2>'   : 'PV_MPPT_C2000_Algorithm_try/Ifilter'
 * '<S3>'   : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller'
 * '<S4>'   : 'PV_MPPT_C2000_Algorithm_try/Low Pass'
 * '<S5>'   : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers'
 * '<S6>'   : 'PV_MPPT_C2000_Algorithm_try/SPI Transmit to PV Emulator'
 * '<S7>'   : 'PV_MPPT_C2000_Algorithm_try/Signal Packing for Host SCI XMT'
 * '<S8>'   : 'PV_MPPT_C2000_Algorithm_try/Signal Unpacking from Host SCI RCV'
 * '<S9>'   : 'PV_MPPT_C2000_Algorithm_try/Vfilter'
 * '<S10>'  : 'PV_MPPT_C2000_Algorithm_try/Generated Sinewave  and PWM Duty Cycles/Counter Limited'
 * '<S11>'  : 'PV_MPPT_C2000_Algorithm_try/Generated Sinewave  and PWM Duty Cycles/Counter Limited/Increment Real World'
 * '<S12>'  : 'PV_MPPT_C2000_Algorithm_try/Generated Sinewave  and PWM Duty Cycles/Counter Limited/Wrap To Zero'
 * '<S13>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller'
 * '<S14>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Anti-windup'
 * '<S15>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/D Gain'
 * '<S16>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Filter'
 * '<S17>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Filter ICs'
 * '<S18>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/I Gain'
 * '<S19>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Ideal P Gain'
 * '<S20>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Ideal P Gain Fdbk'
 * '<S21>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Integrator'
 * '<S22>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Integrator ICs'
 * '<S23>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/N Copy'
 * '<S24>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/N Gain'
 * '<S25>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/P Copy'
 * '<S26>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Parallel P Gain'
 * '<S27>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Reset Signal'
 * '<S28>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Saturation'
 * '<S29>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Saturation Fdbk'
 * '<S30>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Sum'
 * '<S31>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Sum Fdbk'
 * '<S32>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Tracking Mode'
 * '<S33>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Tracking Mode Sum'
 * '<S34>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/postSat Signal'
 * '<S35>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/preSat Signal'
 * '<S36>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S37>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/D Gain/Disabled'
 * '<S38>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Filter/Disabled'
 * '<S39>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Filter ICs/Disabled'
 * '<S40>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/I Gain/Internal Parameters'
 * '<S41>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Integrator/Discrete'
 * '<S44>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/N Copy/Disabled wSignal Specification'
 * '<S46>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/N Gain/Disabled'
 * '<S47>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/P Copy/Disabled'
 * '<S48>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Reset Signal/Disabled'
 * '<S50>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Saturation/Enabled'
 * '<S51>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Saturation Fdbk/Disabled'
 * '<S52>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Sum/Sum_PI'
 * '<S53>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Sum Fdbk/Disabled'
 * '<S54>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Tracking Mode/Disabled'
 * '<S55>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'PV_MPPT_C2000_Algorithm_try/Inverter Voltage Controller/Boost Voltage Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller'
 * '<S59>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/Digital Pulse'
 * '<S60>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/Invert Duty'
 * '<S61>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/Perturb and Observe MPPT'
 * '<S62>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Anti-windup'
 * '<S63>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/D Gain'
 * '<S64>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Filter'
 * '<S65>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Filter ICs'
 * '<S66>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/I Gain'
 * '<S67>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Ideal P Gain'
 * '<S68>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Ideal P Gain Fdbk'
 * '<S69>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Integrator'
 * '<S70>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Integrator ICs'
 * '<S71>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/N Copy'
 * '<S72>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/N Gain'
 * '<S73>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/P Copy'
 * '<S74>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Parallel P Gain'
 * '<S75>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Reset Signal'
 * '<S76>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Saturation'
 * '<S77>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Saturation Fdbk'
 * '<S78>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Sum'
 * '<S79>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Sum Fdbk'
 * '<S80>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Tracking Mode'
 * '<S81>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Tracking Mode Sum'
 * '<S82>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/postSat Signal'
 * '<S83>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/preSat Signal'
 * '<S84>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S85>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/D Gain/Disabled'
 * '<S86>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Filter/Disabled'
 * '<S87>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Filter ICs/Disabled'
 * '<S88>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/I Gain/Internal Parameters'
 * '<S89>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Ideal P Gain/Passthrough'
 * '<S90>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Integrator/Discrete'
 * '<S92>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Integrator ICs/Internal IC'
 * '<S93>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/N Copy/Disabled wSignal Specification'
 * '<S94>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/N Gain/Disabled'
 * '<S95>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/P Copy/Disabled'
 * '<S96>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Reset Signal/Disabled'
 * '<S98>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Saturation/Enabled'
 * '<S99>'  : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Saturation Fdbk/Disabled'
 * '<S100>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Sum/Sum_PI'
 * '<S101>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Sum Fdbk/Disabled'
 * '<S102>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Tracking Mode/Disabled'
 * '<S103>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/postSat Signal/Forward_Path'
 * '<S105>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/DC-DC Boost Voltage Controller/preSat Signal/Forward_Path'
 * '<S106>' : 'PV_MPPT_C2000_Algorithm_try/MPPT and DC-DC Boost Controllers/Digital Pulse/Compare To Constant'
 * '<S107>' : 'PV_MPPT_C2000_Algorithm_try/Signal Packing for Host SCI XMT/Single to IQ2'
 * '<S108>' : 'PV_MPPT_C2000_Algorithm_try/Signal Unpacking from Host SCI RCV/IQ13 to Single'
 * '<S109>' : 'PV_MPPT_C2000_Algorithm_try/Signal Unpacking from Host SCI RCV/IQ13 to Single1'
 * '<S110>' : 'PV_MPPT_C2000_Algorithm_try/Signal Unpacking from Host SCI RCV/IQ13 to Single2'
 * '<S111>' : 'PV_MPPT_C2000_Algorithm_try/Signal Unpacking from Host SCI RCV/Open-loop Boost Duty'
 * '<S112>' : 'PV_MPPT_C2000_Algorithm_try/Signal Unpacking from Host SCI RCV/Single to IQ13'
 */
#endif                           /* RTW_HEADER_PV_MPPT_C2000_Algorithm_try_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
