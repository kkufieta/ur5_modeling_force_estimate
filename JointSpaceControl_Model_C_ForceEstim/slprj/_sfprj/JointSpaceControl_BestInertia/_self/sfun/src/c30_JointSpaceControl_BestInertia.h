#ifndef __c30_JointSpaceControl_BestInertia_h__
#define __c30_JointSpaceControl_BestInertia_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c30_ResolvedFunctionInfo
#define typedef_c30_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c30_ResolvedFunctionInfo;

#endif                                 /*typedef_c30_ResolvedFunctionInfo*/

#ifndef typedef_SFc30_JointSpaceControl_BestInertiaInstanceStruct
#define typedef_SFc30_JointSpaceControl_BestInertiaInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_JointSpaceControl_BestInertia;
} SFc30_JointSpaceControl_BestInertiaInstanceStruct;

#endif                                 /*typedef_SFc30_JointSpaceControl_BestInertiaInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c30_JointSpaceControl_BestInertia_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c30_JointSpaceControl_BestInertia_get_check_sum(mxArray *plhs[]);
extern void c30_JointSpaceControl_BestInertia_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
