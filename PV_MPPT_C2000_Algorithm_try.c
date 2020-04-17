/*
 * File: PV_MPPT_C2000_Algorithm_try.c
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

#include "PV_MPPT_C2000_Algorithm_try.h"
#include "PV_MPPT_C2000_Algorithm_try_private.h"

/* Named constants for Chart: '<S5>/Perturb and Observe MPPT' */
#define PV_MPPT_C2000_Algorithm_VrefMax (10.0F)
#define PV_MPPT_C2000_Algorithm_VrefMin (2.0F)
#define PV_MPPT_C2000_Al_IN_DisableMPPT (1U)
#define PV_MPPT_C2000_Alg_IN_EnableMPPT (2U)
#define PV_MPPT_C2000_IN_Decrement_Vref (5U)
#define PV_MPPT_C2000_IN_Increment_Vref (6U)
#define PV_MPPT_C2000__IN_Clamp_VrefMax (2U)
#define PV_MPPT_C2000__IN_Clamp_VrefMin (3U)
#define PV_MPPT_C2000__IN_Compute_Power (4U)
#define PV_MPPT_C200_IN_NO_ACTIVE_CHILD (0U)
#define PV_MPPT_IN_Calculate_Difference (1U)
#define PV_MPPT__IN_Save_PreviousValues (7U)

/* Block signals (default storage) */
BlockIO_PV_MPPT_C2000_Algorithm PV_MPPT_C2000_Algorithm_try_B;

/* Block states (default storage) */
D_Work_PV_MPPT_C2000_Algorithm_ PV_MPPT_C2000_Algorithm_t_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_PV_MPPT_C2000_A PV_MPPT_C2000_Al_PrevZCSigState;

/* Real-time model */
RT_MODEL_PV_MPPT_C2000_Algorith PV_MPPT_C2000_Algorithm_try_M_;
RT_MODEL_PV_MPPT_C2000_Algorith *const PV_MPPT_C2000_Algorithm_try_M =
  &PV_MPPT_C2000_Algorithm_try_M_;

/* Forward declaration for local functions */
static void PV_MPPT_C200_SystemCore_release(const
  codertarget_tic2000_blocks_SPIW *obj);
static void PV_MPPT_C2000_SystemCore_delete(const
  codertarget_tic2000_blocks_SPIW *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_tic2000_blocks_SPIW *obj);
static void rate_monotonic_scheduler(void);
static uint16_T adcInitFlag = 0;

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void PV_MPPT_C2000_Algorithm_try_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PV_MPPT_C2000_Algorithm_try_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  PV_MPPT_C2000_Algorithm_try_M->Timing.RateInteraction.TID0_1 =
    (PV_MPPT_C2000_Algorithm_try_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PV_MPPT_C2000_Algorithm_try_M->Timing.TaskCounters.TID[1])++;
  if ((PV_MPPT_C2000_Algorithm_try_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.05s, 0.0s] */
    PV_MPPT_C2000_Algorithm_try_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void PV_MPPT_C200_SystemCore_release(const
  codertarget_tic2000_blocks_SPIW *obj)
{
  uint32_T PinNameLoc;
  uint32_T SPIPinsLoc;
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    PinNameLoc = MW_UNDEFINED_VALUE;
    SPIPinsLoc = MW_UNDEFINED_VALUE;
    MW_SPI_Close(obj->MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc, SPIPinsLoc,
                 PinNameLoc);
  }
}

static void PV_MPPT_C2000_SystemCore_delete(const
  codertarget_tic2000_blocks_SPIW *obj)
{
  PV_MPPT_C200_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_tic2000_blocks_SPIW *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PV_MPPT_C2000_SystemCore_delete(obj);
  }
}

/* Model step function for TID0 */
void PV_MPPT_C2000_Algorithm_try_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  /* local block i/o variables */
  uint16_T rtb_Gain2;
  real32_T rtb_ADCtoVpv;
  boolean_T rtb_RelationalOperator1;
  boolean_T rtb_Compare;
  real32_T rtb_IntegralGain;
  real32_T rtb_SignPreSat;
  real32_T rtb_Uint16tosingle3;
  real32_T rtb_IntegralGain_m;
  real32_T rtb_DiscreteTimeIntegrator_i;
  boolean_T rtb_NotEqual_e;
  uint16_T rtb_FixPtSum1;
  int16_T tmp;
  int16_T tmp_0;
  real32_T u;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S5>/Rate Transition6' */
  if (PV_MPPT_C2000_Algorithm_try_M->Timing.RateInteraction.TID0_1) {
    PV_MPPT_C2000_Algorithm_try_B.RateTransition6 =
      PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer0;

    /* RateTransition: '<S5>/Rate Transition7' */
    PV_MPPT_C2000_Algorithm_try_B.RateTransition7 =
      PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer0;

    /* RateTransition: '<S5>/Rate Transition1' */
    PV_MPPT_C2000_Algorithm_try_B.RateTransition1 =
      PV_MPPT_C2000_Algorithm_t_DWork.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<S5>/Rate Transition6' */

  /* RelationalOperator: '<S59>/Relational Operator1' incorporates:
   *  Constant: '<S59>/Constant1'
   */
  rtb_RelationalOperator1 =
    (PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_g >
     PV_MPPT_C2000_Algorithm_try_P.Constant1_Value);

  /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
  if (rtb_RelationalOperator1 &&
      (PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_g =
      PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_IC_k;
  }

  /* RelationalOperator: '<S106>/Compare' incorporates:
   *  Constant: '<S106>/Constant'
   *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
   */
  rtb_Compare = (PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_g
                 >= PV_MPPT_C2000_Algorithm_try_P.DigitalPulse_Duty);

  /* Chart: '<S5>/Perturb and Observe MPPT' incorporates:
   *  TriggerPort: '<S61>/event'
   */
  if (rtb_Compare &&
      (PV_MPPT_C2000_Al_PrevZCSigState.PerturbandObserveMPPT_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Gateway: MPPT and DC-DC
       Boost Controllers/Perturb and Observe
       MPPT */
    /* Event: '<S61>:100' */
    /* During: MPPT and DC-DC
       Boost Controllers/Perturb and Observe
       MPPT */
    if (PV_MPPT_C2000_Algorithm_t_DWork.is_active_c1_PV_MPPT_C2000_Algo == 0U) {
      /* Entry: MPPT and DC-DC
         Boost Controllers/Perturb and Observe
         MPPT */
      PV_MPPT_C2000_Algorithm_t_DWork.is_active_c1_PV_MPPT_C2000_Algo = 1U;

      /* Entry Internal: MPPT and DC-DC
         Boost Controllers/Perturb and Observe
         MPPT */
      /* Transition: '<S61>:94' */
      PV_MPPT_C2000_Algorithm_t_DWork.is_c1_PV_MPPT_C2000_Algorithm_t =
        PV_MPPT_C2000_Al_IN_DisableMPPT;

      /* Entry 'DisableMPPT': '<S61>:89' */
    } else if (PV_MPPT_C2000_Algorithm_t_DWork.is_c1_PV_MPPT_C2000_Algorithm_t ==
               1U) {
      /* During 'DisableMPPT': '<S61>:89' */
      if (PV_MPPT_C2000_Algorithm_try_B.RateTransition7 == 1.0F) {
        /* Transition: '<S61>:90' */
        PV_MPPT_C2000_Algorithm_t_DWork.is_c1_PV_MPPT_C2000_Algorithm_t =
          PV_MPPT_C2000_Alg_IN_EnableMPPT;

        /* Entry Internal 'EnableMPPT': '<S61>:88' */
        /* Transition: '<S61>:68' */
        PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
          PV_MPPT_C2000__IN_Compute_Power;

        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
         *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
         */
        /* Entry 'Compute_Power': '<S61>:1' */
        PV_MPPT_C2000_Algorithm_t_DWork.P =
          PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE *
          PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h;
      } else {
        PV_MPPT_C2000_Algorithm_try_B.Vref =
          PV_MPPT_C2000_Algorithm_try_B.RateTransition6;
        PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev =
          PV_MPPT_C2000_Algorithm_try_B.RateTransition6;
      }
    } else {
      /* During 'EnableMPPT': '<S61>:88' */
      if (PV_MPPT_C2000_Algorithm_try_B.RateTransition7 != 1.0F) {
        /* Transition: '<S61>:92' */
        /* Transition: '<S61>:93' */
        /* Exit Internal 'EnableMPPT': '<S61>:88' */
        PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
          PV_MPPT_C200_IN_NO_ACTIVE_CHILD;
        PV_MPPT_C2000_Algorithm_t_DWork.is_c1_PV_MPPT_C2000_Algorithm_t =
          PV_MPPT_C2000_Al_IN_DisableMPPT;

        /* Entry 'DisableMPPT': '<S61>:89' */
      } else {
        guard1 = false;
        guard2 = false;
        guard3 = false;
        switch (PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT) {
         case PV_MPPT_IN_Calculate_Difference:
          /* During 'Calculate_Difference': '<S61>:6' */
          if (PV_MPPT_C2000_Algorithm_t_DWork.deltaP < 0.0F) {
            /* Transition: '<S61>:15' */
            if (PV_MPPT_C2000_Algorithm_t_DWork.deltaV >= 0.0F) {
              /* Transition: '<S61>:17' */
              guard1 = true;
            } else if (PV_MPPT_C2000_Algorithm_t_DWork.deltaV < 0.0F) {
              /* Transition: '<S61>:20' */
              guard2 = true;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
          break;

         case PV_MPPT_C2000__IN_Clamp_VrefMax:
          /* During 'Clamp_VrefMax': '<S61>:45' */
          /* Transition: '<S61>:71' */
          /* Transition: '<S61>:72' */
          /* Transition: '<S61>:74' */
          /* Transition: '<S61>:75' */
          /* Transition: '<S61>:39' */
          PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev =
            PV_MPPT_C2000_Algorithm_try_B.Vref;

          /* Transition: '<S61>:77' */
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT_C2000__IN_Compute_Power;

          /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
           *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
           */
          /* Entry 'Compute_Power': '<S61>:1' */
          PV_MPPT_C2000_Algorithm_t_DWork.P =
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE *
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h;
          break;

         case PV_MPPT_C2000__IN_Clamp_VrefMin:
          /* During 'Clamp_VrefMin': '<S61>:47' */
          /* Transition: '<S61>:51' */
          /* Transition: '<S61>:74' */
          /* Transition: '<S61>:75' */
          /* Transition: '<S61>:39' */
          PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev =
            PV_MPPT_C2000_Algorithm_try_B.Vref;

          /* Transition: '<S61>:77' */
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT_C2000__IN_Compute_Power;

          /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
           *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
           */
          /* Entry 'Compute_Power': '<S61>:1' */
          PV_MPPT_C2000_Algorithm_t_DWork.P =
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE *
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h;
          break;

         case PV_MPPT_C2000__IN_Compute_Power:
          /* During 'Compute_Power': '<S61>:1' */
          /* Transition: '<S61>:7' */
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT_IN_Calculate_Difference;

          /* Entry 'Calculate_Difference': '<S61>:6' */
          PV_MPPT_C2000_Algorithm_t_DWork.deltaP =
            PV_MPPT_C2000_Algorithm_t_DWork.P -
            PV_MPPT_C2000_Algorithm_t_DWork.Pprev;

          /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
          PV_MPPT_C2000_Algorithm_t_DWork.deltaV =
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE -
            PV_MPPT_C2000_Algorithm_t_DWork.Vprev;
          break;

         case PV_MPPT_C2000_IN_Decrement_Vref:
          /* During 'Decrement_Vref': '<S61>:9' */
          /* Transition: '<S61>:21' */
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT__IN_Save_PreviousValues;

          /* Entry 'Save_PreviousValues': '<S61>:8' */
          PV_MPPT_C2000_Algorithm_t_DWork.Pprev =
            PV_MPPT_C2000_Algorithm_t_DWork.P;

          /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
          PV_MPPT_C2000_Algorithm_t_DWork.Vprev =
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE;
          break;

         case PV_MPPT_C2000_IN_Increment_Vref:
          /* During 'Increment_Vref': '<S61>:10' */
          /* Transition: '<S61>:22' */
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT__IN_Save_PreviousValues;

          /* Entry 'Save_PreviousValues': '<S61>:8' */
          PV_MPPT_C2000_Algorithm_t_DWork.Pprev =
            PV_MPPT_C2000_Algorithm_t_DWork.P;

          /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
          PV_MPPT_C2000_Algorithm_t_DWork.Vprev =
            PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE;
          break;

         default:
          /* During 'Save_PreviousValues': '<S61>:8' */
          if (PV_MPPT_C2000_Algorithm_try_B.Vref >=
              PV_MPPT_C2000_Algorithm_VrefMax) {
            /* Transition: '<S61>:48' */
            PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
              PV_MPPT_C2000__IN_Clamp_VrefMax;

            /* Entry 'Clamp_VrefMax': '<S61>:45' */
            PV_MPPT_C2000_Algorithm_try_B.Vref = PV_MPPT_C2000_Algorithm_VrefMax;
          } else if (PV_MPPT_C2000_Algorithm_try_B.Vref <=
                     PV_MPPT_C2000_Algorithm_VrefMin) {
            /* Transition: '<S61>:49' */
            PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
              PV_MPPT_C2000__IN_Clamp_VrefMin;

            /* Entry 'Clamp_VrefMin': '<S61>:47' */
            PV_MPPT_C2000_Algorithm_try_B.Vref = PV_MPPT_C2000_Algorithm_VrefMin;
          } else {
            /* Transition: '<S61>:54' */
            /* Transition: '<S61>:39' */
            PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev =
              PV_MPPT_C2000_Algorithm_try_B.Vref;

            /* Transition: '<S61>:77' */
            PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
              PV_MPPT_C2000__IN_Compute_Power;

            /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
             *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
             */
            /* Entry 'Compute_Power': '<S61>:1' */
            PV_MPPT_C2000_Algorithm_t_DWork.P =
              PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE *
              PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h;
          }
          break;
        }

        if (guard3) {
          if (PV_MPPT_C2000_Algorithm_t_DWork.deltaP >= 0.0F) {
            /* Transition: '<S61>:16' */
            if (PV_MPPT_C2000_Algorithm_t_DWork.deltaV <= 0.0F) {
              /* Transition: '<S61>:18' */
              guard1 = true;
            } else {
              if (PV_MPPT_C2000_Algorithm_t_DWork.deltaV > 0.0F) {
                /* Transition: '<S61>:19' */
                guard2 = true;
              }
            }
          }
        }

        if (guard2) {
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT_C2000_IN_Increment_Vref;

          /* Entry 'Increment_Vref': '<S61>:10' */
          PV_MPPT_C2000_Algorithm_try_B.Vref =
            PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev +
            PV_MPPT_C2000_Algorithm_try_B.RateTransition1;
        }

        if (guard1) {
          PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
            PV_MPPT_C2000_IN_Decrement_Vref;

          /* Entry 'Decrement_Vref': '<S61>:9' */
          PV_MPPT_C2000_Algorithm_try_B.Vref =
            PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev -
            PV_MPPT_C2000_Algorithm_try_B.RateTransition1;
        }
      }
    }
  }

  PV_MPPT_C2000_Al_PrevZCSigState.PerturbandObserveMPPT_Trig_ZCE = rtb_Compare;

  /* Sum: '<S5>/Sum' incorporates:
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   */
  rtb_IntegralGain =
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE -
    PV_MPPT_C2000_Algorithm_try_B.Vref;

  /* Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S91>/Integrator'
   *  Gain: '<S96>/Proportional Gain'
   */
  rtb_SignPreSat = PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_P *
    rtb_IntegralGain + PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE;

  /* Saturate: '<S98>/Saturation' */
  if (rtb_SignPreSat >
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Uppe) {
    rtb_IntegralGain_m =
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Uppe;
  } else if (rtb_SignPreSat <
             PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Lowe) {
    rtb_IntegralGain_m =
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Lowe;
  } else {
    rtb_IntegralGain_m = rtb_SignPreSat;
  }

  /* End of Saturate: '<S98>/Saturation' */

  /* Gain: '<S5>/Gain' incorporates:
   *  Bias: '<S60>/Bias'
   *  Gain: '<S60>/Negate'
   */
  u = (rtb_IntegralGain_m + PV_MPPT_C2000_Algorithm_try_P.Bias_Bias) *
    PV_MPPT_C2000_Algorithm_try_P.Negate_Gain *
    PV_MPPT_C2000_Algorithm_try_P.Gain_Gain;
  if (u < 0.0F) {
    u = (real32_T)ceil(u);
  } else {
    u = (real32_T)floor(u);
  }

  u = (real32_T)fmod(u, 65536.0);
  rtb_Gain2 = u < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-u : (uint16_T)u;

  /* End of Gain: '<S5>/Gain' */

  /* S-Function (c280xpwm): '<Root>/ePWM' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.half.CMPA = (uint16_T)(rtb_Gain2);
  }

  /* S-Function (c280xadc): '<Root>/ADC5' */
  {
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;  /* Reset SEQ1 module*/
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;/*clear INT sequencer*/
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  /* Software Trigger*/
    while (AdcRegs.ADCST.bit.INT_SEQ1 == 0) {
    }                                  /*Wait for Sequencer INT bit to clear */

    asm(" RPT #11 || NOP");
    PV_MPPT_C2000_Algorithm_try_B.Vpv = (AdcRegs.ADCRESULT0) >> 4;
    PV_MPPT_C2000_Algorithm_try_B.Ipv = (AdcRegs.ADCRESULT1) >> 4;
    PV_MPPT_C2000_Algorithm_try_B.Vboost = (AdcRegs.ADCRESULT2) >> 4;
    PV_MPPT_C2000_Algorithm_try_B.Iboost = (AdcRegs.ADCRESULT3) >> 4;
    PV_MPPT_C2000_Algorithm_try_B.Vac = (AdcRegs.ADCRESULT4) >> 4;
  }

  /* Gain: '<Root>/Uint16 to single3' */
  rtb_Uint16tosingle3 = (real32_T)
    PV_MPPT_C2000_Algorithm_try_P.Uint16tosingle3_Gain * 2.38418579E-7F *
    (real32_T)PV_MPPT_C2000_Algorithm_try_B.Vboost;

  /* Gain: '<S3>/Normalize Boost Voltage' incorporates:
   *  Constant: '<S3>/Vboost_Ref'
   *  Sum: '<S3>/Sum3'
   */
  rtb_IntegralGain_m = (rtb_Uint16tosingle3 -
                        PV_MPPT_C2000_Algorithm_try_P.Vboost_Ref_Value) *
    PV_MPPT_C2000_Algorithm_try_P.NormalizeBoostVoltage_Gain;

  /* Sum: '<S52>/Sum' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Gain: '<S48>/Proportional Gain'
   */
  rtb_DiscreteTimeIntegrator_i =
    PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_P * rtb_IntegralGain_m
    + PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE_d;

  /* Switch: '<S3>/Switch' incorporates:
   *  Saturate: '<S50>/Saturation'
   */
  if (PV_MPPT_C2000_Algorithm_try_B.InvSaturation >
      PV_MPPT_C2000_Algorithm_try_P.Switch_Threshold) {
    u = PV_MPPT_C2000_Algorithm_try_B.InvSaturation;
  } else if (rtb_DiscreteTimeIntegrator_i >
             PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_UpperSat) {
    /* Saturate: '<S50>/Saturation' */
    u = PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_UpperSat;
  } else if (rtb_DiscreteTimeIntegrator_i <
             PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_LowerSat) {
    /* Saturate: '<S50>/Saturation' */
    u = PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_LowerSat;
  } else {
    /* Saturate: '<S50>/Saturation' */
    u = rtb_DiscreteTimeIntegrator_i;
  }

  /* End of Switch: '<S3>/Switch' */

  /* LookupNDDirect: '<S1>/Sine Lookup' incorporates:
   *  UnitDelay: '<S10>/Output'
   *
   * About '<S1>/Sine Lookup':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (PV_MPPT_C2000_Algorithm_t_DWork.Output_DSTATE < 200U) {
    rtb_FixPtSum1 = PV_MPPT_C2000_Algorithm_t_DWork.Output_DSTATE;
  } else {
    rtb_FixPtSum1 = 200U;
  }

  /* Product: '<S1>/Product' incorporates:
   *  LookupNDDirect: '<S1>/Sine Lookup'
   *
   * About '<S1>/Sine Lookup':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_ADCtoVpv = PV_MPPT_C2000_Algorithm_try_P.SineLookup_table[(int16_T)
    rtb_FixPtSum1] * u;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Bias: '<S1>/Bias'
   *  Gain: '<S1>/Scale to Uint3'
   */
  u = (rtb_ADCtoVpv + PV_MPPT_C2000_Algorithm_try_P.Bias_Bias_m) *
    PV_MPPT_C2000_Algorithm_try_P.ScaletoUint3_Gain * (real32_T)
    PV_MPPT_C2000_Algorithm_try_P.Gain1_Gain;
  if (u < 0.0F) {
    u = (real32_T)ceil(u);
  } else {
    u = (real32_T)floor(u);
  }

  u = (real32_T)fmod(u, 65536.0);
  rtb_Gain2 = u < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-u : (uint16_T)u;

  /* End of Gain: '<S1>/Gain1' */

  /* S-Function (c280xpwm): '<Root>/ePWM1' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_Gain2);
  }

  /* Gain: '<S1>/Gain2' incorporates:
   *  Bias: '<S1>/Bias1'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Scale to Uint4'
   */
  u = (PV_MPPT_C2000_Algorithm_try_P.Gain3_Gain * rtb_ADCtoVpv +
       PV_MPPT_C2000_Algorithm_try_P.Bias1_Bias) *
    PV_MPPT_C2000_Algorithm_try_P.ScaletoUint4_Gain * (real32_T)
    PV_MPPT_C2000_Algorithm_try_P.Gain2_Gain;
  if (u < 0.0F) {
    u = (real32_T)ceil(u);
  } else {
    u = (real32_T)floor(u);
  }

  u = (real32_T)fmod(u, 65536.0);
  rtb_Gain2 = u < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-u : (uint16_T)u;

  /* End of Gain: '<S1>/Gain2' */

  /* S-Function (c280xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_Gain2);
  }

  /* Sum: '<S11>/FixPt Sum1' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  UnitDelay: '<S10>/Output'
   */
  rtb_FixPtSum1 = (PV_MPPT_C2000_Algorithm_t_DWork.Output_DSTATE +
                   PV_MPPT_C2000_Algorithm_try_P.FixPtConstant_Value) & 255U;

  /* Gain: '<S36>/ZeroGain' */
  rtb_ADCtoVpv = PV_MPPT_C2000_Algorithm_try_P.ZeroGain_Gain *
    rtb_DiscreteTimeIntegrator_i;

  /* DeadZone: '<S36>/DeadZone' */
  if (rtb_DiscreteTimeIntegrator_i >
      PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_UpperSat) {
    rtb_DiscreteTimeIntegrator_i -=
      PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_UpperSat;
  } else if (rtb_DiscreteTimeIntegrator_i >=
             PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_LowerSat) {
    rtb_DiscreteTimeIntegrator_i = 0.0F;
  } else {
    rtb_DiscreteTimeIntegrator_i -=
      PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_LowerSat;
  }

  /* End of DeadZone: '<S36>/DeadZone' */

  /* RelationalOperator: '<S36>/NotEqual' */
  rtb_Compare = (rtb_ADCtoVpv != rtb_DiscreteTimeIntegrator_i);

  /* Signum: '<S36>/SignPreSat' */
  if (rtb_DiscreteTimeIntegrator_i < 0.0F) {
    rtb_DiscreteTimeIntegrator_i = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator_i > 0.0F) {
      rtb_DiscreteTimeIntegrator_i = 1.0F;
    }
  }

  /* End of Signum: '<S36>/SignPreSat' */

  /* Gain: '<S40>/Integral Gain' */
  rtb_IntegralGain_m *= PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_I;

  /* Gain: '<S84>/ZeroGain' */
  rtb_ADCtoVpv = PV_MPPT_C2000_Algorithm_try_P.ZeroGain_Gain_p * rtb_SignPreSat;

  /* DeadZone: '<S84>/DeadZone' */
  if (rtb_SignPreSat >
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Uppe) {
    rtb_SignPreSat -=
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Uppe;
  } else if (rtb_SignPreSat >=
             PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Lowe) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat -=
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Lowe;
  }

  /* End of DeadZone: '<S84>/DeadZone' */

  /* RelationalOperator: '<S84>/NotEqual' */
  rtb_NotEqual_e = (rtb_ADCtoVpv != rtb_SignPreSat);

  /* Signum: '<S84>/SignPreSat' */
  if (rtb_SignPreSat < 0.0F) {
    rtb_SignPreSat = -1.0F;
  } else {
    if (rtb_SignPreSat > 0.0F) {
      rtb_SignPreSat = 1.0F;
    }
  }

  /* End of Signum: '<S84>/SignPreSat' */

  /* Gain: '<S88>/Integral Gain' */
  rtb_IntegralGain *= PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_I;

  /* RateTransition: '<S5>/Rate Transition5' */
  if (PV_MPPT_C2000_Algorithm_try_M->Timing.RateInteraction.TID0_1) {
    PV_MPPT_C2000_Algorithm_try_B.RateTransition5 =
      PV_MPPT_C2000_Algorithm_t_DWork.RateTransition5_Buffer0;

    /* RateTransition: '<S7>/Rate Transition10' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition10_Buffer =
      PV_MPPT_C2000_Algorithm_try_B.Vref;

    /* RateTransition: '<S7>/Rate Transition3' incorporates:
     *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
     */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition3_Buffer =
      PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTAT_gp;

    /* RateTransition: '<S7>/Rate Transition5' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition5_Buffer =
      PV_MPPT_C2000_Algorithm_try_B.Vac;

    /* RateTransition: '<S7>/Rate Transition6' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer = rtb_Uint16tosingle3;

    /* RateTransition: '<S7>/Rate Transition7' incorporates:
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer =
      PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h;

    /* RateTransition: '<S7>/Rate Transition8' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
     */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition8_Buffer =
      PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of RateTransition: '<S5>/Rate Transition5' */

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/ADC to Vpv'
   *  Gain: '<S9>/1//T6'
   *  Sum: '<S9>/Sum1'
   */
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE += ((real32_T)
    PV_MPPT_C2000_Algorithm_try_P.ADCtoVpv_Gain * 2.38418579E-7F * (real32_T)
    PV_MPPT_C2000_Algorithm_try_B.Vpv -
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE) *
    PV_MPPT_C2000_Algorithm_try_P.uT6_Gain_d *
    PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/ADC to Ipv'
   *  Gain: '<S2>/1//T6'
   *  Sum: '<S2>/Sum1'
   */
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h += ((real32_T)
    PV_MPPT_C2000_Algorithm_try_P.ADCtoIpv_Gain * 2.98023224E-8F * (real32_T)
    PV_MPPT_C2000_Algorithm_try_B.Ipv -
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h) *
    PV_MPPT_C2000_Algorithm_try_P.uT6_Gain *
    PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_gainva_h;

  /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_g +=
    PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_gainva_a *
    PV_MPPT_C2000_Algorithm_try_B.RateTransition5;
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_PrevRese = (int16_T)
    rtb_RelationalOperator1;

  /* DataTypeConversion: '<S84>/DataTypeConv1' */
  tmp = (int16_T)(real32_T)fmod(rtb_SignPreSat, 256.0);

  /* Signum: '<S84>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0F) {
    rtb_SignPreSat = -1.0F;
  } else if (rtb_IntegralGain > 0.0F) {
    rtb_SignPreSat = 1.0F;
  } else {
    rtb_SignPreSat = rtb_IntegralGain;
  }

  /* End of Signum: '<S84>/SignPreIntegrator' */

  /* DataTypeConversion: '<S84>/DataTypeConv2' */
  tmp_0 = (int16_T)(real32_T)fmod(rtb_SignPreSat, 256.0);

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S84>/Constant1'
   *  DataTypeConversion: '<S84>/DataTypeConv1'
   *  DataTypeConversion: '<S84>/DataTypeConv2'
   *  Logic: '<S84>/AND3'
   *  RelationalOperator: '<S84>/Equal1'
   */
  if (rtb_NotEqual_e && (((tmp & 128U) != 0U ? tmp | -128 : tmp & 127) ==
                         ((tmp_0 & 128U) != 0U ? tmp_0 | -128 : tmp_0 & 127))) {
    rtb_IntegralGain = PV_MPPT_C2000_Algorithm_try_P.Constant1_Value_l;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Update for DiscreteIntegrator: '<S91>/Integrator' */
  PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE +=
    PV_MPPT_C2000_Algorithm_try_P.Integrator_gainval * rtb_IntegralGain;

  /* Switch: '<S12>/FixPt Switch' */
  if (rtb_FixPtSum1 > PV_MPPT_C2000_Algorithm_try_P.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S10>/Output' incorporates:
     *  Constant: '<S12>/Constant'
     */
    PV_MPPT_C2000_Algorithm_t_DWork.Output_DSTATE =
      PV_MPPT_C2000_Algorithm_try_P.Constant_Value_n;
  } else {
    /* Update for UnitDelay: '<S10>/Output' */
    PV_MPPT_C2000_Algorithm_t_DWork.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S12>/FixPt Switch' */

  /* DataTypeConversion: '<S36>/DataTypeConv1' */
  tmp = (int16_T)(real32_T)fmod(rtb_DiscreteTimeIntegrator_i, 256.0);

  /* Signum: '<S36>/SignPreIntegrator' */
  if (rtb_IntegralGain_m < 0.0F) {
    rtb_IntegralGain = -1.0F;
  } else if (rtb_IntegralGain_m > 0.0F) {
    rtb_IntegralGain = 1.0F;
  } else {
    rtb_IntegralGain = rtb_IntegralGain_m;
  }

  /* End of Signum: '<S36>/SignPreIntegrator' */

  /* DataTypeConversion: '<S36>/DataTypeConv2' */
  tmp_0 = (int16_T)(real32_T)fmod(rtb_IntegralGain, 256.0);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Constant1'
   *  DataTypeConversion: '<S36>/DataTypeConv1'
   *  DataTypeConversion: '<S36>/DataTypeConv2'
   *  Logic: '<S36>/AND3'
   *  RelationalOperator: '<S36>/Equal1'
   */
  if (rtb_Compare && (((tmp & 128U) != 0U ? tmp | -128 : tmp & 127) == ((tmp_0 &
         128U) != 0U ? tmp_0 | -128 : tmp_0 & 127))) {
    rtb_IntegralGain_m = PV_MPPT_C2000_Algorithm_try_P.Constant1_Value_h;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Update for DiscreteIntegrator: '<S43>/Integrator' */
  PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE_d +=
    PV_MPPT_C2000_Algorithm_try_P.Integrator_gainval_p * rtb_IntegralGain_m;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/Uint16 to single4'
   *  Gain: '<S4>/1//T6'
   *  Sum: '<S4>/Sum1'
   */
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTAT_gp += ((real32_T)
    PV_MPPT_C2000_Algorithm_try_P.Uint16tosingle4_Gain * 2.98023224E-8F *
    (real32_T)PV_MPPT_C2000_Algorithm_try_B.Iboost -
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTAT_gp) *
    PV_MPPT_C2000_Algorithm_try_P.uT6_Gain_a *
    PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_gainva_f;
}

/* Model step function for TID1 */
void PV_MPPT_C2000_Algorithm_try_step1(void) /* Sample time: [0.05s, 0.0s] */
{
  MW_SPI_Mode_type ClockModeValue;
  MW_SPI_FirstBitTransfer_Type MsbFirstTransferLoc;
  uint16_T rtb_TmpSignalConversionAtSPITra[2];
  uint16_T rtb_DataTypeConversion;
  real32_T rtb_DutySaturation;

  /* S-Function (c28xsci_rx): '<Root>/SCI Receive' */
  {
    int i;
    int errFlg = NOERROR;
    unsigned int recbuff[6];
    for (i = 0; i < 6; i++)
      recbuff[i] = 0;

    /* Getting Data Head */
    {
      unsigned int recHead;
      int cnt = 0;
      int i = 0;
      char *expHead = "B";
      while (i < 1) {
        scia_rcv(&recHead, 1, SHORTLOOP, 1);
        if (recHead == expHead[i]) {
          i++;
        } else {
          i = 0;
        }

        if (cnt++ > 16) {
          errFlg = TIMEOUT;
          goto RXERRA;
        }
      }
    }

    /* End of Getting Data Head */

    /* Receiving data */
    errFlg = scia_rcv(recbuff, 12, LONGLOOP, 2);
    if (errFlg != NOERROR)
      goto RXERRA;

    /* Getting Data Tail */
    {
      int i;
      char *expTail = "T";
      unsigned int recTail[1];
      scia_rcv(recTail, 1, LONGLOOP, 1);
      for (i = 0; i< 1; i++) {
        if (expTail[i] != recTail[i]) {
          errFlg = DATAERR;
          goto RXERRA;
        }
      }
    }

    /* End of Getting Data Tail */
    memcpy( &PV_MPPT_C2000_Algorithm_try_B.SCIReceive[0], recbuff, 6);
   RXERRA:
    asm(" NOP");
  }

  /* Gain: '<S108>/Remove IQ13 Scaling Uint' incorporates:
   *  DataTypeConversion: '<S108>/Data Type Conversion1'
   */
  rtb_DutySaturation = PV_MPPT_C2000_Algorithm_try_P.RemoveIQ13ScalingUint_Gain *
    (real32_T)PV_MPPT_C2000_Algorithm_try_B.SCIReceive[0];

  /* Saturate: '<S8>/Irradiance Saturation' */
  if (rtb_DutySaturation >
      PV_MPPT_C2000_Algorithm_try_P.IrradianceSaturation_UpperSat) {
    rtb_DutySaturation =
      PV_MPPT_C2000_Algorithm_try_P.IrradianceSaturation_UpperSat;
  } else {
    if (rtb_DutySaturation <
        PV_MPPT_C2000_Algorithm_try_P.IrradianceSaturation_LowerSat) {
      rtb_DutySaturation =
        PV_MPPT_C2000_Algorithm_try_P.IrradianceSaturation_LowerSat;
    }
  }

  /* End of Saturate: '<S8>/Irradiance Saturation' */

  /* DataTypeConversion: '<S112>/Data Type Conversion' incorporates:
   *  Gain: '<S112>/Scale to Uint16'
   */
  rtb_DutySaturation = (real32_T)fmod((real32_T)floor
    (PV_MPPT_C2000_Algorithm_try_P.IQ13 * rtb_DutySaturation), 65536.0);
  rtb_DataTypeConversion = rtb_DutySaturation < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_DutySaturation : (uint16_T)rtb_DutySaturation;

  /* SignalConversion generated from: '<Root>/SCI Transmit' */
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[0] =
    rtb_DataTypeConversion;

  /* Gain: '<S7>/Sig to Vpv1' incorporates:
   *  RateTransition: '<S7>/Rate Transition8'
   */
  rtb_DutySaturation = (real32_T)fmod((real32_T)floor
    (PV_MPPT_C2000_Algorithm_try_P.SigtoVpv1_Gain *
     PV_MPPT_C2000_Algorithm_t_DWork.RateTransition8_Buffer), 65536.0);

  /* SignalConversion generated from: '<Root>/SCI Transmit' incorporates:
   *  Gain: '<S7>/Sig to Vpv1'
   */
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[1] =
    rtb_DutySaturation < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_DutySaturation : (uint16_T)rtb_DutySaturation;

  /* Gain: '<S7>/Uint16 to single2' incorporates:
   *  RateTransition: '<S7>/Rate Transition7'
   */
  rtb_DutySaturation = (real32_T)fmod((real32_T)floor
    (PV_MPPT_C2000_Algorithm_try_P.Uint16tosingle2_Gain *
     PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer), 65536.0);

  /* SignalConversion generated from: '<Root>/SCI Transmit' incorporates:
   *  Gain: '<S7>/Uint16 to single2'
   */
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[2] =
    rtb_DutySaturation < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_DutySaturation : (uint16_T)rtb_DutySaturation;

  /* Gain: '<S7>/Uint16 to single5' incorporates:
   *  RateTransition: '<S7>/Rate Transition6'
   */
  rtb_DutySaturation = (real32_T)fmod((real32_T)floor
    (PV_MPPT_C2000_Algorithm_try_P.Uint16tosingle5_Gain *
     PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer), 65536.0);

  /* SignalConversion generated from: '<Root>/SCI Transmit' incorporates:
   *  Gain: '<S7>/Uint16 to single5'
   */
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[3] =
    rtb_DutySaturation < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_DutySaturation : (uint16_T)rtb_DutySaturation;

  /* Gain: '<S7>/Uint16 to single6' incorporates:
   *  RateTransition: '<S7>/Rate Transition3'
   */
  rtb_DutySaturation = (real32_T)fmod((real32_T)floor
    (PV_MPPT_C2000_Algorithm_try_P.Uint16tosingle6_Gain *
     PV_MPPT_C2000_Algorithm_t_DWork.RateTransition3_Buffer), 65536.0);

  /* SignalConversion generated from: '<Root>/SCI Transmit' incorporates:
   *  Gain: '<S7>/Uint16 to single6'
   *  RateTransition: '<S7>/Rate Transition5'
   */
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[4] =
    rtb_DutySaturation < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_DutySaturation : (uint16_T)rtb_DutySaturation;
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[5] =
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition5_Buffer;

  /* DataTypeConversion: '<S107>/Data Type Conversion' incorporates:
   *  Gain: '<S107>/Scale to Uint16'
   *  RateTransition: '<S7>/Rate Transition10'
   */
  rtb_DutySaturation = (real32_T)fmod((real32_T)floor
    (PV_MPPT_C2000_Algorithm_try_P.IQ8 *
     PV_MPPT_C2000_Algorithm_t_DWork.RateTransition10_Buffer), 65536.0);

  /* SignalConversion generated from: '<Root>/SCI Transmit' incorporates:
   *  DataTypeConversion: '<S107>/Data Type Conversion'
   */
  PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[6] =
    rtb_DutySaturation < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_DutySaturation : (uint16_T)rtb_DutySaturation;

  /* S-Function (c28xsci_tx): '<Root>/SCI Transmit' */
  {
    /* Send additional data header */
    {
      char *String = "S";
      scia_xmit(String, 1, 1);
    }

    scia_xmit((char*)
              &PV_MPPT_C2000_Algorithm_try_B.TmpSignalConversionAtSCITransmi[0],
              14, 2);

    /* Send additional data terminator */
    {
      char *String = "E";
      scia_xmit(String, 1, 1);
    }
  }

  /* Gain: '<S111>/Scale to Uint2' */
  rtb_DutySaturation = (real32_T)PV_MPPT_C2000_Algorithm_try_P.ScaletoUint2_Gain
    * 3.7252903E-9F * (real32_T)PV_MPPT_C2000_Algorithm_try_B.SCIReceive[1];

  /* Saturate: '<S111>/Duty Saturation' */
  if (rtb_DutySaturation > PV_MPPT_C2000_Algorithm_try_P.DutySaturation_UpperSat)
  {
    rtb_DutySaturation = PV_MPPT_C2000_Algorithm_try_P.DutySaturation_UpperSat;
  } else {
    if (rtb_DutySaturation <
        PV_MPPT_C2000_Algorithm_try_P.DutySaturation_LowerSat) {
      rtb_DutySaturation = PV_MPPT_C2000_Algorithm_try_P.DutySaturation_LowerSat;
    }
  }

  /* End of Saturate: '<S111>/Duty Saturation' */

  /* RateTransition: '<S5>/Rate Transition1' */
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition1_Buffer0 = rtb_DutySaturation;

  /* Gain: '<S110>/Remove IQ8 Scaling Uint' incorporates:
   *  DataTypeConversion: '<S110>/Data Type Conversion1'
   */
  rtb_DutySaturation = PV_MPPT_C2000_Algorithm_try_P.RemoveIQ8ScalingUint_Gain *
    (real32_T)PV_MPPT_C2000_Algorithm_try_B.SCIReceive[2];

  /* RateTransition: '<S5>/Rate Transition5' */
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition5_Buffer0 = rtb_DutySaturation;

  /* Gain: '<S109>/Remove IQ8 Scaling Uint' incorporates:
   *  DataTypeConversion: '<S109>/Data Type Conversion1'
   */
  rtb_DutySaturation = PV_MPPT_C2000_Algorithm_try_P.RemoveIQ8ScalingUint_Gain_p
    * (real32_T)PV_MPPT_C2000_Algorithm_try_B.SCIReceive[5];

  /* RateTransition: '<S5>/Rate Transition6' */
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer0 = rtb_DutySaturation;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  rtb_DutySaturation = PV_MPPT_C2000_Algorithm_try_B.SCIReceive[4];

  /* RateTransition: '<S5>/Rate Transition7' */
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer0 = rtb_DutySaturation;

  /* SignalConversion generated from: '<S6>/SPI Transmit' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_TmpSignalConversionAtSPITra[0] =
    PV_MPPT_C2000_Algorithm_try_P.Constant_Value;
  rtb_TmpSignalConversionAtSPITra[1] = rtb_DataTypeConversion;

  /* MATLABSystem: '<S6>/SPI Transmit' */
  MW_SPI_SetSlaveSelect(PV_MPPT_C2000_Algorithm_t_DWork.obj.MW_SPI_HANDLE, 0U,
                        true);
  ClockModeValue = MW_SPI_MODE_0;
  MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  rtb_DataTypeConversion = MW_SPI_SetFormat
    (PV_MPPT_C2000_Algorithm_t_DWork.obj.MW_SPI_HANDLE, 16U, ClockModeValue,
     MsbFirstTransferLoc);
  if (rtb_DataTypeConversion == 0U) {
    MW_SPI_Write_16bits(PV_MPPT_C2000_Algorithm_t_DWork.obj.MW_SPI_HANDLE,
                        rtb_TmpSignalConversionAtSPITra, 2UL, 0U);
  }

  /* End of MATLABSystem: '<S6>/SPI Transmit' */

  /* Gain: '<S8>/Scale to Uit7' */
  rtb_DutySaturation = (real32_T)PV_MPPT_C2000_Algorithm_try_P.ScaletoUit7_Gain *
    3.7252903E-9F * (real32_T)PV_MPPT_C2000_Algorithm_try_B.SCIReceive[3];

  /* Saturate: '<S8>/Inv Saturation' */
  if (rtb_DutySaturation > PV_MPPT_C2000_Algorithm_try_P.InvSaturation_UpperSat)
  {
    PV_MPPT_C2000_Algorithm_try_B.InvSaturation =
      PV_MPPT_C2000_Algorithm_try_P.InvSaturation_UpperSat;
  } else if (rtb_DutySaturation <
             PV_MPPT_C2000_Algorithm_try_P.InvSaturation_LowerSat) {
    PV_MPPT_C2000_Algorithm_try_B.InvSaturation =
      PV_MPPT_C2000_Algorithm_try_P.InvSaturation_LowerSat;
  } else {
    PV_MPPT_C2000_Algorithm_try_B.InvSaturation = rtb_DutySaturation;
  }

  /* End of Saturate: '<S8>/Inv Saturation' */
}

/* Model initialize function */
void PV_MPPT_C2000_Algorithm_try_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PV_MPPT_C2000_Algorithm_try_M, 0,
                sizeof(RT_MODEL_PV_MPPT_C2000_Algorith));

  /* block I/O */
  (void) memset(((void *) &PV_MPPT_C2000_Algorithm_try_B), 0,
                sizeof(BlockIO_PV_MPPT_C2000_Algorithm));

  {
    PV_MPPT_C2000_Algorithm_try_B.RateTransition6 = 0.0F;
    PV_MPPT_C2000_Algorithm_try_B.RateTransition7 = 0.0F;
    PV_MPPT_C2000_Algorithm_try_B.RateTransition1 = 0.0F;
    PV_MPPT_C2000_Algorithm_try_B.RateTransition5 = 0.0F;
    PV_MPPT_C2000_Algorithm_try_B.InvSaturation = 0.0F;
    PV_MPPT_C2000_Algorithm_try_B.Vref = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&PV_MPPT_C2000_Algorithm_t_DWork, 0,
                sizeof(D_Work_PV_MPPT_C2000_Algorithm_));
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_g = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE_d = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTAT_gp = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer0 = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer0 = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition1_Buffer0 = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition5_Buffer0 = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition10_Buffer = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition3_Buffer = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.RateTransition8_Buffer = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.P = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.deltaP = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.Pprev = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.Vprev = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.deltaV = 0.0F;
  PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev = 0.0F;

  {
    codertarget_tic2000_blocks_SPIW *obj;
    uint32_T SSPinNameLoc;
    uint32_T SPIPinsLoc;

    /* Start for RateTransition: '<S5>/Rate Transition6' */
    PV_MPPT_C2000_Algorithm_try_B.RateTransition6 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition6_InitialConditio;

    /* Start for RateTransition: '<S5>/Rate Transition7' */
    PV_MPPT_C2000_Algorithm_try_B.RateTransition7 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition7_InitialConditio;

    /* Start for RateTransition: '<S5>/Rate Transition1' */
    PV_MPPT_C2000_Algorithm_try_B.RateTransition1 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition1_InitialConditio;

    /* Start for S-Function (c280xpwm): '<Root>/ePWM' */

    /*** Initialize ePWM3 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm3Regs.TBPRD = 1500;

      /* // Time-Base Control Register
         EPwm3Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
         EPwm3Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
         EPwm3Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm3Regs.TBCTL.bit.PHSEN      = 1;          // Phase load enable
         EPwm3Regs.TBCTL.bit.PHSDIR     = 1;          // Phase Direction
         EPwm3Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm3Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FBF) | 0x2036;

      /* // Time-Base Phase Register
         EPwm3Regs.TBPHS.half.TBPHS     = 4;          // Phase offset register
       */
      EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000) | 0x40000;
      EPwm3Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm3Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm3Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm3Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm3Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm3Regs.CMPA.half.CMPA = 0;
      EPwm3Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm3Regs.AQCTLA.all = 96;
      EPwm3Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm3Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm3Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm3Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm3Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
         EPwm3Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
         EPwm3Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
       */
      EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x3F) | 0x3;
      EPwm3Regs.DBRED = 0;
      EPwm3Regs.DBFED = 30;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm3Regs.ETSEL.bit.SOCAEN     = 1;          // Start of conversion A Enable
         EPwm3Regs.ETSEL.bit.SOCASEL    = 6;          // Start of conversion A Select
         EPwm3Regs.ETPS.bit.SOCAPRD     = 2;          // EPWM3SOCA Period Select
         EPwm3Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm3Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm3Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM3SOCB Period Select
         EPwm3Regs.ETSEL.bit.INTEN      = 1;          // EPWM3INTn Enable
         EPwm3Regs.ETSEL.bit.INTSEL     = 2;          // EPWM3INTn Select
         EPwm3Regs.ETPS.bit.INTPRD      = 2;          // EPWM3INTn Period Select
       */
      EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1E0A;
      EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303) | 0x1202;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm3Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm3Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm3Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm3Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm3Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm3Regs.TZCTL.bit.TZA        = 2;          // TZ1 to TZ6 Trip Action On EPWM3A
         EPwm3Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM3B
       */
      EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xF) | 0xE;

      /* // Trip-Zone Enable Interrupt Register
         EPwm3Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm3Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for S-Function (c280xadc): '<Root>/ADC5' */
    if (adcInitFlag == 0) {
      InitAdc();
      adcInitFlag = 1;
    }

    config_ADC_A (4U, 12817U, 4U, 0U, 0U);

    /* Start for S-Function (c280xpwm): '<Root>/ePWM1' */

    /*** Initialize ePWM1 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm1Regs.TBPRD = 1500;

      /* // Time-Base Control Register
         EPwm1Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
         EPwm1Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
         EPwm1Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm1Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
         EPwm1Regs.TBCTL.bit.PHSDIR     = 1;          // Phase Direction
         EPwm1Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm1Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FBF) | 0x2012;

      /* // Time-Base Phase Register
         EPwm1Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
       */
      EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
      EPwm1Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm1Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm1Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm1Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm1Regs.CMPA.half.CMPA = 750;
      EPwm1Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm1Regs.AQCTLA.all = 144;
      EPwm1Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm1Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm1Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm1Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm1Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
         EPwm1Regs.DBCTL.bit.IN_MODE    = 2;          // Dead Band Input Select Mode Control
         EPwm1Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
       */
      EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x3F) | 0x2B;
      EPwm1Regs.DBRED = 20;
      EPwm1Regs.DBFED = 20;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm1Regs.ETSEL.bit.SOCAEN     = 1;          // Start of conversion A Enable
         EPwm1Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm1Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM1SOCA Period Select
         EPwm1Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm1Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm1Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM1SOCB Period Select
         EPwm1Regs.ETSEL.bit.INTEN      = 0;          // EPWM1INTn Enable
         EPwm1Regs.ETSEL.bit.INTSEL     = 2;          // EPWM1INTn Select
         EPwm1Regs.ETPS.bit.INTPRD      = 2;          // EPWM1INTn Period Select
       */
      EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1902;
      EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1102;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm1Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm1Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm1Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm1Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm1Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm1Regs.TZCTL.bit.TZA        = 2;          // TZ1 to TZ6 Trip Action On EPWM1A
         EPwm1Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
       */
      EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xF) | 0xE;

      /* // Trip-Zone Enable Interrupt Register
         EPwm1Regs.TZEINT.bit.OST       = 1;          // Trip Zones One Shot Int Enable
         EPwm1Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x6) | 0x4;
      EDIS;
    }

    /* Start for S-Function (c280xpwm): '<Root>/ePWM2' */

    /*** Initialize ePWM2 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm2Regs.TBPRD = 1500;

      /* // Time-Base Control Register
         EPwm2Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
         EPwm2Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
         EPwm2Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm2Regs.TBCTL.bit.PHSEN      = 1;          // Phase load enable
         EPwm2Regs.TBCTL.bit.PHSDIR     = 1;          // Phase Direction
         EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FBF) | 0x2016;

      /* // Time-Base Phase Register
         EPwm2Regs.TBPHS.half.TBPHS     = 2;          // Phase offset register
       */
      EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x20000;
      EPwm2Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm2Regs.CMPCTL.bit.LOADAMODE = 1;          // Active compare A
         EPwm2Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x1;
      EPwm2Regs.CMPA.half.CMPA = 750;
      EPwm2Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm2Regs.AQCTLA.all = 144;
      EPwm2Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm2Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm2Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm2Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm2Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
         EPwm2Regs.DBCTL.bit.IN_MODE    = 2;          // Dead Band Input Select Mode Control
         EPwm2Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
       */
      EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0x2B;
      EPwm2Regs.DBRED = 20;
      EPwm2Regs.DBFED = 20;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm2Regs.ETSEL.bit.SOCAEN     = 1;          // Start of conversion A Enable
         EPwm2Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
         EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
         EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
         EPwm2Regs.ETSEL.bit.INTSEL     = 2;          // EPWM2INTn Select
         EPwm2Regs.ETPS.bit.INTPRD      = 2;          // EPWM2INTn Period Select
       */
      EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1902;
      EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1102;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm2Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm2Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm2Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm2Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm2Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm2Regs.TZCTL.bit.TZA        = 2;          // TZ1 to TZ6 Trip Action On EPWM2A
         EPwm2Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
       */
      EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xF) | 0xE;

      /* // Trip-Zone Enable Interrupt Register
         EPwm2Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm2Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for RateTransition: '<S5>/Rate Transition5' */
    PV_MPPT_C2000_Algorithm_try_B.RateTransition5 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition5_InitialConditio;

    /* Start for S-Function (c28xsci_rx): '<Root>/SCI Receive' */

    /* Initialize PV_MPPT_C2000_Algorithm_try_B.SCIReceive[0] */
    {
      PV_MPPT_C2000_Algorithm_try_B.SCIReceive[0] = (uint16_T)819.2;
      PV_MPPT_C2000_Algorithm_try_B.SCIReceive[1] = (uint16_T)819.2;
      PV_MPPT_C2000_Algorithm_try_B.SCIReceive[2] = (uint16_T)6400.0;
      PV_MPPT_C2000_Algorithm_try_B.SCIReceive[3] = (uint16_T)819.2;
      PV_MPPT_C2000_Algorithm_try_B.SCIReceive[4] = (uint16_T)0.0;
      PV_MPPT_C2000_Algorithm_try_B.SCIReceive[5] = (uint16_T)768.0;
    }

    /* Start for MATLABSystem: '<S6>/SPI Transmit' */
    PV_MPPT_C2000_Algorithm_t_DWork.obj.matlabCodegenIsDeleted = true;
    PV_MPPT_C2000_Algorithm_t_DWork.obj.isInitialized = 0L;
    PV_MPPT_C2000_Algorithm_t_DWork.obj.matlabCodegenIsDeleted = false;
    obj = &PV_MPPT_C2000_Algorithm_t_DWork.obj;
    PV_MPPT_C2000_Algorithm_t_DWork.obj.isSetupComplete = false;
    PV_MPPT_C2000_Algorithm_t_DWork.obj.isInitialized = 1L;
    SSPinNameLoc = MW_UNDEFINED_VALUE;
    SPIPinsLoc = MW_UNDEFINED_VALUE;
    obj->MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc, SPIPinsLoc,
      SSPinNameLoc, true, 0U);
    PV_MPPT_C2000_Algorithm_t_DWork.obj.isSetupComplete = true;
    PV_MPPT_C2000_Al_PrevZCSigState.PerturbandObserveMPPT_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE =
      PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_h =
      PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition6' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition6_Buffer0 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition6_InitialConditio;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition7' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition7_Buffer0 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition7_InitialConditio;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition1' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition1_Buffer0 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition1_InitialConditio;

    /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTATE_g =
      PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_IC_k;
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
    PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE =
      PV_MPPT_C2000_Algorithm_try_P.DCDCBoostVoltageController_Init;

    /* InitializeConditions for UnitDelay: '<S10>/Output' */
    PV_MPPT_C2000_Algorithm_t_DWork.Output_DSTATE =
      PV_MPPT_C2000_Algorithm_try_P.Output_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
    PV_MPPT_C2000_Algorithm_t_DWork.Integrator_DSTATE_d =
      PV_MPPT_C2000_Algorithm_try_P.BoostVoltageController_InitialC;

    /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    PV_MPPT_C2000_Algorithm_t_DWork.DiscreteTimeIntegrator_DSTAT_gp =
      PV_MPPT_C2000_Algorithm_try_P.DiscreteTimeIntegrator_IC_h;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition5' */
    PV_MPPT_C2000_Algorithm_t_DWork.RateTransition5_Buffer0 =
      PV_MPPT_C2000_Algorithm_try_P.RateTransition5_InitialConditio;

    /* SystemInitialize for Chart: '<S5>/Perturb and Observe MPPT' */
    PV_MPPT_C2000_Algorithm_t_DWork.is_EnableMPPT =
      PV_MPPT_C200_IN_NO_ACTIVE_CHILD;
    PV_MPPT_C2000_Algorithm_t_DWork.is_active_c1_PV_MPPT_C2000_Algo = 0U;
    PV_MPPT_C2000_Algorithm_t_DWork.is_c1_PV_MPPT_C2000_Algorithm_t =
      PV_MPPT_C200_IN_NO_ACTIVE_CHILD;
    PV_MPPT_C2000_Algorithm_t_DWork.P = 0.0F;
    PV_MPPT_C2000_Algorithm_t_DWork.deltaP = 0.0F;
    PV_MPPT_C2000_Algorithm_t_DWork.Pprev = 0.0F;
    PV_MPPT_C2000_Algorithm_t_DWork.Vprev = 0.0F;
    PV_MPPT_C2000_Algorithm_t_DWork.deltaV = 0.0F;
    PV_MPPT_C2000_Algorithm_t_DWork.Vref_prev = 5.0F;
    PV_MPPT_C2000_Algorithm_try_B.Vref = 5.0F;
  }
}

/* Model terminate function */
void PV_MPPT_C2000_Algorithm_try_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/SPI Transmit' */
  matlabCodegenHandle_matlabCodeg(&PV_MPPT_C2000_Algorithm_t_DWork.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
