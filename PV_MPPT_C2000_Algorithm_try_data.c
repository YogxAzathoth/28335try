/*
 * File: PV_MPPT_C2000_Algorithm_try_data.c
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

/* Block parameters (default storage) */
Parameters_PV_MPPT_C2000_Algori PV_MPPT_C2000_Algorithm_try_P = {
  /* Variable: IQ13
   * Referenced by: '<S112>/Scale to Uint16'
   */
  8192.0F,

  /* Variable: IQ8
   * Referenced by: '<S107>/Scale to Uint16'
   */
  256.0F,

  /* Mask Parameter: DigitalPulse_Duty
   * Referenced by: '<S106>/Constant'
   */
  0.5F,

  /* Mask Parameter: BoostVoltageController_I
   * Referenced by: '<S40>/Integral Gain'
   */
  250.0F,

  /* Mask Parameter: DCDCBoostVoltageController_I
   * Referenced by: '<S88>/Integral Gain'
   */
  2.5F,

  /* Mask Parameter: DCDCBoostVoltageController_Init
   * Referenced by: '<S91>/Integrator'
   */
  0.0F,

  /* Mask Parameter: BoostVoltageController_InitialC
   * Referenced by: '<S43>/Integrator'
   */
  1.0F,

  /* Mask Parameter: DCDCBoostVoltageController_Lowe
   * Referenced by:
   *   '<S84>/DeadZone'
   *   '<S98>/Saturation'
   */
  0.0F,

  /* Mask Parameter: BoostVoltageController_LowerSat
   * Referenced by:
   *   '<S36>/DeadZone'
   *   '<S50>/Saturation'
   */
  0.0F,

  /* Mask Parameter: DCDCBoostVoltageController_P
   * Referenced by: '<S96>/Proportional Gain'
   */
  0.015F,

  /* Mask Parameter: BoostVoltageController_P
   * Referenced by: '<S48>/Proportional Gain'
   */
  3.0F,

  /* Mask Parameter: DCDCBoostVoltageController_Uppe
   * Referenced by:
   *   '<S84>/DeadZone'
   *   '<S98>/Saturation'
   */
  0.9F,

  /* Mask Parameter: BoostVoltageController_UpperSat
   * Referenced by:
   *   '<S36>/DeadZone'
   *   '<S50>/Saturation'
   */
  1.0F,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S12>/FixPt Switch'
   */
  200U,

  /* Expression: 1
   * Referenced by: '<S59>/Constant1'
   */
  1.0,

  /* Computed Parameter: Constant1_Value_h
   * Referenced by: '<S36>/Constant1'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_l
   * Referenced by: '<S84>/Constant1'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  0.0001F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0001F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_n
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0F,

  /* Expression: single(3)
   * Referenced by: '<S5>/Rate Transition6'
   */
  3.0F,

  /* Expression: single(0)
   * Referenced by: '<S5>/Rate Transition7'
   */
  0.0F,

  /* Expression: single(0.1)
   * Referenced by: '<S5>/Rate Transition1'
   */
  0.1F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
   * Referenced by: '<S59>/Discrete-Time Integrator'
   */
  0.0001F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_k
   * Referenced by: '<S59>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S91>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S60>/Bias'
   */
  -1.0F,

  /* Computed Parameter: Negate_Gain
   * Referenced by: '<S60>/Negate'
   */
  -1.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S5>/Gain'
   */
  1500.0F,

  /* Computed Parameter: SineLookup_table
   * Referenced by: '<S1>/Sine Lookup'
   */
  { 0.47942555F, 0.506754518F, 0.533583343F, 0.559885621F, 0.585635364F,
    0.61080718F, 0.635376155F, 0.659318149F, 0.682609439F, 0.705227F,
    0.727148712F, 0.748352766F, 0.768818259F, 0.788525045F, 0.807453692F,
    0.825585425F, 0.842902422F, 0.859387577F, 0.875024617F, 0.889798105F,
    0.903693497F, 0.916697F, 0.928795934F, 0.939978182F, 0.950232804F,
    0.959549606F, 0.967919528F, 0.975334167F, 0.981786311F, 0.98726958F,
    0.991778493F, 0.995308638F, 0.997856498F, 0.99941963F, 0.999996483F,
    0.999586403F, 0.998189926F, 0.995808303F, 0.992443919F, 0.988100171F,
    0.982781231F, 0.976492465F, 0.96923995F, 0.96103096F, 0.951873541F,
    0.941776752F, 0.930750489F, 0.918805718F, 0.905954242F, 0.892208636F,
    0.87758255F, 0.862090409F, 0.845747471F, 0.828569889F, 0.810574591F,
    0.791779399F, 0.77220279F, 0.751864076F, 0.730783403F, 0.708981514F,
    0.68648F, 0.663300931F, 0.639467299F, 0.615002632F, 0.589930952F,
    0.564277172F, 0.538066447F, 0.511324763F, 0.484078407F, 0.45635435F,
    0.42817995F, 0.399582952F, 0.37059164F, 0.341234595F, 0.311540782F,
    0.28153953F, 0.25126043F, 0.220733359F, 0.189988449F, 0.159056053F,
    0.127966672F, 0.0967510194F, 0.0654398799F, 0.0340641588F, 0.00265482138F,
    -0.0287571363F, -0.060140714F, -0.0914649442F, -0.122698903F, -0.153811783F,
    -0.184772864F, -0.215551585F, -0.246117592F, -0.27644071F, -0.306491017F,
    -0.336238861F, -0.365654856F, -0.39471F, -0.423375636F, -0.45162344F,
    -0.47942555F, -0.506754518F, -0.533583343F, -0.559885621F, -0.585635364F,
    -0.61080718F, -0.635376155F, -0.659318149F, -0.682609439F, -0.705227F,
    -0.727148712F, -0.748352766F, -0.768818259F, -0.788525045F, -0.807453692F,
    -0.825585425F, -0.842902422F, -0.859387577F, -0.875024617F, -0.889798105F,
    -0.903693497F, -0.916697F, -0.928795934F, -0.939978182F, -0.950232804F,
    -0.959549606F, -0.967919528F, -0.975334167F, -0.981786311F, -0.98726958F,
    -0.991778493F, -0.995308638F, -0.997856498F, -0.99941963F, -0.999996483F,
    -0.999586403F, -0.998189926F, -0.995808303F, -0.992443919F, -0.988100171F,
    -0.982781231F, -0.976492465F, -0.96923995F, -0.96103096F, -0.951873541F,
    -0.941776752F, -0.930750489F, -0.918805718F, -0.905954242F, -0.892208636F,
    -0.87758255F, -0.862090409F, -0.845747471F, -0.828569889F, -0.810574591F,
    -0.791779399F, -0.77220279F, -0.751864076F, -0.730783403F, -0.708981514F,
    -0.68648F, -0.663300931F, -0.639467299F, -0.615002632F, -0.589930952F,
    -0.564277172F, -0.538066447F, -0.511324763F, -0.484078407F, -0.45635435F,
    -0.42817995F, -0.399582952F, -0.37059164F, -0.341234595F, -0.311540782F,
    -0.28153953F, -0.25126043F, -0.220733359F, -0.189988449F, -0.159056053F,
    -0.127966672F, -0.0967510194F, -0.0654398799F, -0.0340641588F,
    -0.00265482138F, 0.0287571363F, 0.060140714F, 0.0914649442F, 0.122698903F,
    0.153811783F, 0.184772864F, 0.215551585F, 0.246117592F, 0.27644071F,
    0.306491017F, 0.336238861F, 0.365654856F, 0.39471F, 0.423375636F,
    0.45162344F, 0.47942555F },

  /* Computed Parameter: Vboost_Ref_Value
   * Referenced by: '<S3>/Vboost_Ref'
   */
  30.0F,

  /* Computed Parameter: NormalizeBoostVoltage_Gain
   * Referenced by: '<S3>/Normalize Boost Voltage'
   */
  0.0333333351F,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S43>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S3>/Switch'
   */
  0.0F,

  /* Computed Parameter: Bias_Bias_m
   * Referenced by: '<S1>/Bias'
   */
  1.0F,

  /* Computed Parameter: ScaletoUint3_Gain
   * Referenced by: '<S1>/Scale to Uint3'
   */
  0.5F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S1>/Gain3'
   */
  -1.0F,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S1>/Bias1'
   */
  1.0F,

  /* Computed Parameter: ScaletoUint4_Gain
   * Referenced by: '<S1>/Scale to Uint4'
   */
  0.5F,

  /* Computed Parameter: uT6_Gain
   * Referenced by: '<S2>/1//T6'
   */
  100.0F,

  /* Computed Parameter: ZeroGain_Gain
   * Referenced by: '<S36>/ZeroGain'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0001F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_h
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: uT6_Gain_a
   * Referenced by: '<S4>/1//T6'
   */
  100.0F,

  /* Computed Parameter: ZeroGain_Gain_p
   * Referenced by: '<S84>/ZeroGain'
   */
  0.0F,

  /* Expression: single(25)
   * Referenced by: '<S5>/Rate Transition5'
   */
  25.0F,

  /* Computed Parameter: uT6_Gain_d
   * Referenced by: '<S9>/1//T6'
   */
  100.0F,

  /* Computed Parameter: RemoveIQ13ScalingUint_Gain
   * Referenced by: '<S108>/Remove IQ13 Scaling Uint'
   */
  0.000122070313F,

  /* Computed Parameter: IrradianceSaturation_UpperSat
   * Referenced by: '<S8>/Irradiance Saturation'
   */
  0.8F,

  /* Computed Parameter: IrradianceSaturation_LowerSat
   * Referenced by: '<S8>/Irradiance Saturation'
   */
  0.0F,

  /* Computed Parameter: SigtoVpv1_Gain
   * Referenced by: '<S7>/Sig to Vpv1'
   */
  125.449318F,

  /* Computed Parameter: Uint16tosingle2_Gain
   * Referenced by: '<S7>/Uint16 to single2'
   */
  1000.0F,

  /* Computed Parameter: Uint16tosingle5_Gain
   * Referenced by: '<S7>/Uint16 to single5'
   */
  105.0578F,

  /* Computed Parameter: Uint16tosingle6_Gain
   * Referenced by: '<S7>/Uint16 to single6'
   */
  1000.0F,

  /* Computed Parameter: DutySaturation_UpperSat
   * Referenced by: '<S111>/Duty Saturation'
   */
  0.9F,

  /* Computed Parameter: DutySaturation_LowerSat
   * Referenced by: '<S111>/Duty Saturation'
   */
  0.0F,

  /* Computed Parameter: RemoveIQ8ScalingUint_Gain
   * Referenced by: '<S110>/Remove IQ8 Scaling Uint'
   */
  0.00390625F,

  /* Computed Parameter: RemoveIQ8ScalingUint_Gain_p
   * Referenced by: '<S109>/Remove IQ8 Scaling Uint'
   */
  0.00390625F,

  /* Computed Parameter: InvSaturation_UpperSat
   * Referenced by: '<S8>/Inv Saturation'
   */
  0.8F,

  /* Computed Parameter: InvSaturation_LowerSat
   * Referenced by: '<S8>/Inv Saturation'
   */
  0.0F,

  /* Computed Parameter: Uint16tosingle3_Gain
   * Referenced by: '<Root>/Uint16 to single3'
   */
  39924U,

  /* Computed Parameter: ADCtoVpv_Gain
   * Referenced by: '<Root>/ADC to Vpv'
   */
  33434U,

  /* Computed Parameter: ADCtoIpv_Gain
   * Referenced by: '<Root>/ADC to Ipv'
   */
  33554U,

  /* Computed Parameter: Uint16tosingle4_Gain
   * Referenced by: '<Root>/Uint16 to single4'
   */
  33554U,

  /* Computed Parameter: ScaletoUint2_Gain
   * Referenced by: '<S111>/Scale to Uint2'
   */
  32768U,

  /* Computed Parameter: ScaletoUit7_Gain
   * Referenced by: '<S8>/Scale to Uit7'
   */
  32768U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S1>/Gain1'
   */
  1500U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S1>/Gain2'
   */
  1500U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S6>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S12>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S10>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S11>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
