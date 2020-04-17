/*
 * File: PV_MPPT_C2000_Algorithm_try_types.h
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

#ifndef RTW_HEADER_PV_MPPT_C2000_Algorithm_try_types_h_
#define RTW_HEADER_PV_MPPT_C2000_Algorithm_try_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Custom Type definition for MATLABSystem: '<S6>/SPI Transmit' */
#include "MW_SVD.h"
#ifndef typedef_codertarget_tic2000_blocks_SPIW
#define typedef_codertarget_tic2000_blocks_SPIW

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
} codertarget_tic2000_blocks_SPIW;

#endif                               /*typedef_codertarget_tic2000_blocks_SPIW*/

/* Parameters (default storage) */
typedef struct Parameters_PV_MPPT_C2000_Algori_ Parameters_PV_MPPT_C2000_Algori;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PV_MPPT_C2000_Algorithm RT_MODEL_PV_MPPT_C2000_Algorith;

#endif                     /* RTW_HEADER_PV_MPPT_C2000_Algorithm_try_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
