/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectInertia_sfun.h"
#include "c6_JointSpaceControl_CorrectInertia.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_CorrectInertia_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[5] = { "nargin", "nargout", "R", "k",
  "theta" };

/* Function Declarations */
static void initialize_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void initialize_params_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void enable_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void disable_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void set_sim_state_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_st);
static void finalize_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void sf_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void initSimStructsc6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void registerMessagesc6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_theta, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_k, const char_T *c6_identifier, real_T c6_y[3]);
static void c6_d_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_eml_error(SFc6_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_b_is_active_c6_JointSpaceControl_CorrectInertia, const char_T
   *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_JointSpaceControl_CorrectInertia = 0U;
}

static void initialize_params_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void enable_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[3];
  const mxArray *c6_b_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  real_T *c6_theta;
  real_T (*c6_k)[3];
  c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(3), FALSE);
  for (c6_i0 = 0; c6_i0 < 3; c6_i0++) {
    c6_u[c6_i0] = (*c6_k)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = *c6_theta;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_b_hoistedGlobal =
    chartInstance->c6_is_active_c6_JointSpaceControl_CorrectInertia;
  c6_c_u = c6_b_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[3];
  int32_T c6_i1;
  real_T *c6_theta;
  real_T (*c6_k)[3];
  c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "k",
                        c6_dv0);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    (*c6_k)[c6_i1] = c6_dv0[c6_i1];
  }

  *c6_theta = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    1)), "theta");
  chartInstance->c6_is_active_c6_JointSpaceControl_CorrectInertia =
    c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
    "is_active_c6_JointSpaceControl_CorrectInertia");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_JointSpaceControl_CorrectInertia(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void sf_c6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  real_T c6_R[9];
  uint32_T c6_debug_family_var_map[5];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 2.0;
  real_T c6_k[3];
  real_T c6_theta;
  real_T c6_A;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_y;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_b;
  real_T c6_b_y;
  real_T c6_B;
  real_T c6_c_y;
  real_T c6_d_y;
  real_T c6_e_y;
  real_T c6_a;
  real_T c6_b_b[3];
  int32_T c6_i5;
  int32_T c6_i6;
  real_T *c6_b_theta;
  real_T (*c6_b_k)[3];
  real_T (*c6_b_R)[9];
  boolean_T guard1 = FALSE;
  c6_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c6_b_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 3; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_k)[c6_i2], 0U);
  }

  for (c6_i3 = 0; c6_i3 < 9; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_R)[c6_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_b_theta, 2U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 9; c6_i4++) {
    c6_R[c6_i4] = (*c6_b_R)[c6_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_R, 2U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_k, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_theta, 4U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_A = ((c6_R[0] + c6_R[4]) + c6_R[8]) - 1.0;
  c6_x = c6_A;
  c6_b_x = c6_x;
  c6_y = c6_b_x / 2.0;
  c6_c_x = c6_y;
  c6_theta = c6_c_x;
  guard1 = FALSE;
  if (c6_theta < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < c6_theta) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c6_eml_error(chartInstance);
  }

  c6_d_x = c6_theta;
  c6_theta = c6_d_x;
  c6_theta = muDoubleScalarAcos(c6_theta);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_e_x = c6_theta;
  c6_f_x = c6_e_x;
  c6_f_x = muDoubleScalarSin(c6_f_x);
  c6_b = c6_f_x;
  c6_b_y = 2.0 * c6_b;
  c6_B = c6_b_y;
  c6_c_y = c6_B;
  c6_d_y = c6_c_y;
  c6_e_y = 1.0 / c6_d_y;
  c6_a = c6_e_y;
  c6_b_b[0] = c6_R[5] - c6_R[7];
  c6_b_b[1] = c6_R[6] - c6_R[2];
  c6_b_b[2] = c6_R[1] - c6_R[3];
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_k[c6_i5] = c6_a * c6_b_b[c6_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    (*c6_b_k)[c6_i6] = c6_k[c6_i6];
  }

  *c6_b_theta = c6_theta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc6_JointSpaceControl_CorrectInertia
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_theta, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_theta), &c6_thisId);
  sf_mex_destroy(&c6_theta);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_theta;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_theta = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_theta), &c6_thisId);
  sf_mex_destroy(&c6_theta);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i7;
  real_T c6_b_inData[3];
  int32_T c6_i8;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_b_inData[c6_i7] = (*(real_T (*)[3])c6_inData)[c6_i7];
  }

  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    c6_u[c6_i8] = c6_b_inData[c6_i8];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_k, const char_T *c6_identifier, real_T c6_y[3])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_k), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_k);
}

static void c6_d_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3])
{
  real_T c6_dv1[3];
  int32_T c6_i9;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    c6_y[c6_i9] = c6_dv1[c6_i9];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_k;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i10;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_k = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_k), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_k);
  for (c6_i10 = 0; c6_i10 < 3; c6_i10++) {
    (*(real_T (*)[3])c6_outData)[c6_i10] = c6_y[c6_i10];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  real_T c6_b_inData[9];
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i11 = 0;
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    for (c6_i13 = 0; c6_i13 < 3; c6_i13++) {
      c6_b_inData[c6_i13 + c6_i11] = (*(real_T (*)[9])c6_inData)[c6_i13 + c6_i11];
    }

    c6_i11 += 3;
  }

  c6_i14 = 0;
  for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
    for (c6_i16 = 0; c6_i16 < 3; c6_i16++) {
      c6_u[c6_i16 + c6_i14] = c6_b_inData[c6_i16 + c6_i14];
    }

    c6_i14 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

const mxArray
  *sf_c6_JointSpaceControl_CorrectInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[10];
  c6_ResolvedFunctionInfo (*c6_b_info)[10];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i17;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[10])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "mrdivide";
  (*c6_b_info)[0].dominantType = "double";
  (*c6_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c6_b_info)[0].fileTimeLo = 1357973148U;
  (*c6_b_info)[0].fileTimeHi = 0U;
  (*c6_b_info)[0].mFileTimeLo = 1319751566U;
  (*c6_b_info)[0].mFileTimeHi = 0U;
  (*c6_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c6_b_info)[1].name = "rdivide";
  (*c6_b_info)[1].dominantType = "double";
  (*c6_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[1].fileTimeLo = 1346531988U;
  (*c6_b_info)[1].fileTimeHi = 0U;
  (*c6_b_info)[1].mFileTimeLo = 0U;
  (*c6_b_info)[1].mFileTimeHi = 0U;
  (*c6_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[2].name = "eml_scalexp_compatible";
  (*c6_b_info)[2].dominantType = "double";
  (*c6_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c6_b_info)[2].fileTimeLo = 1286840396U;
  (*c6_b_info)[2].fileTimeHi = 0U;
  (*c6_b_info)[2].mFileTimeLo = 0U;
  (*c6_b_info)[2].mFileTimeHi = 0U;
  (*c6_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[3].name = "eml_div";
  (*c6_b_info)[3].dominantType = "double";
  (*c6_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c6_b_info)[3].fileTimeLo = 1313369410U;
  (*c6_b_info)[3].fileTimeHi = 0U;
  (*c6_b_info)[3].mFileTimeLo = 0U;
  (*c6_b_info)[3].mFileTimeHi = 0U;
  (*c6_b_info)[4].context = "";
  (*c6_b_info)[4].name = "acos";
  (*c6_b_info)[4].dominantType = "double";
  (*c6_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c6_b_info)[4].fileTimeLo = 1343851966U;
  (*c6_b_info)[4].fileTimeHi = 0U;
  (*c6_b_info)[4].mFileTimeLo = 0U;
  (*c6_b_info)[4].mFileTimeHi = 0U;
  (*c6_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c6_b_info)[5].name = "eml_error";
  (*c6_b_info)[5].dominantType = "char";
  (*c6_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c6_b_info)[5].fileTimeLo = 1343851958U;
  (*c6_b_info)[5].fileTimeHi = 0U;
  (*c6_b_info)[5].mFileTimeLo = 0U;
  (*c6_b_info)[5].mFileTimeHi = 0U;
  (*c6_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c6_b_info)[6].name = "eml_scalar_acos";
  (*c6_b_info)[6].dominantType = "double";
  (*c6_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  (*c6_b_info)[6].fileTimeLo = 1343851976U;
  (*c6_b_info)[6].fileTimeHi = 0U;
  (*c6_b_info)[6].mFileTimeLo = 0U;
  (*c6_b_info)[6].mFileTimeHi = 0U;
  (*c6_b_info)[7].context = "";
  (*c6_b_info)[7].name = "sin";
  (*c6_b_info)[7].dominantType = "double";
  (*c6_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c6_b_info)[7].fileTimeLo = 1343851986U;
  (*c6_b_info)[7].fileTimeHi = 0U;
  (*c6_b_info)[7].mFileTimeLo = 0U;
  (*c6_b_info)[7].mFileTimeHi = 0U;
  (*c6_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c6_b_info)[8].name = "eml_scalar_sin";
  (*c6_b_info)[8].dominantType = "double";
  (*c6_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c6_b_info)[8].fileTimeLo = 1286840336U;
  (*c6_b_info)[8].fileTimeHi = 0U;
  (*c6_b_info)[8].mFileTimeLo = 0U;
  (*c6_b_info)[8].mFileTimeHi = 0U;
  (*c6_b_info)[9].context = "";
  (*c6_b_info)[9].name = "mtimes";
  (*c6_b_info)[9].dominantType = "double";
  (*c6_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c6_b_info)[9].fileTimeLo = 1289541292U;
  (*c6_b_info)[9].fileTimeHi = 0U;
  (*c6_b_info)[9].mFileTimeLo = 0U;
  (*c6_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c6_i17 = 0; c6_i17 < 10; c6_i17++) {
    c6_r0 = &c6_info[c6_i17];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i17);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i17);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_eml_error(SFc6_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance)
{
  int32_T c6_i18;
  static char_T c6_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  int32_T c6_i19;
  static char_T c6_cv1[4] = { 'a', 'c', 'o', 's' };

  char_T c6_b_u[4];
  const mxArray *c6_b_y = NULL;
  for (c6_i18 = 0; c6_i18 < 30; c6_i18++) {
    c6_u[c6_i18] = c6_cv0[c6_i18];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c6_i19 = 0; c6_i19 < 4; c6_i19++) {
    c6_b_u[c6_i19] = c6_cv1[c6_i19];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c6_y, 14, c6_b_y));
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i20;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i20, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i20;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_b_is_active_c6_JointSpaceControl_CorrectInertia, const char_T
   *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_JointSpaceControl_CorrectInertia), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_JointSpaceControl_CorrectInertia);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info
  (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_JointSpaceControl_CorrectInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(623623964U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(577310426U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2325373300U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1501957450U);
}

mxArray *sf_c6_JointSpaceControl_CorrectInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nzAnFn5m1B8plInJg8y7xC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_JointSpaceControl_CorrectInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c6_JointSpaceControl_CorrectInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"k\",},{M[1],M[9],T\"theta\",},{M[8],M[0],T\"is_active_c6_JointSpaceControl_CorrectInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_JointSpaceControl_CorrectInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectInertiaMachineNumber_,
           6,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_JointSpaceControl_CorrectInertiaMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_CorrectInertiaMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_CorrectInertiaMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"k");
          _SFD_SET_DATA_PROPS(1,1,1,0,"R");
          _SFD_SET_DATA_PROPS(2,2,0,1,"theta");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,319);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_theta;
          real_T (*c6_k)[3];
          real_T (*c6_R)[9];
          c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c6_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_k);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_R);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_CorrectInertiaMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "353FCkjHQR42BbsOnvmFGC";
}

static void sf_opaque_initialize_c6_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
  initialize_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  enable_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  disable_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  sf_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c6_JointSpaceControl_CorrectInertia(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_JointSpaceControl_CorrectInertia
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c6_JointSpaceControl_CorrectInertia
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_JointSpaceControl_CorrectInertia
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c6_JointSpaceControl_CorrectInertia(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_JointSpaceControl_CorrectInertia(S);
}

static void sf_opaque_set_sim_state_c6_JointSpaceControl_CorrectInertia
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_JointSpaceControl_CorrectInertia(S, st);
}

static void sf_opaque_terminate_c6_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectInertia_optimization_info();
    }

    finalize_c6_JointSpaceControl_CorrectInertia
      ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_JointSpaceControl_CorrectInertia
    ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_JointSpaceControl_CorrectInertia(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_JointSpaceControl_CorrectInertia
      ((SFc6_JointSpaceControl_CorrectInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(462153305U));
  ssSetChecksum1(S,(1901596479U));
  ssSetChecksum2(S,(1052444977U));
  ssSetChecksum3(S,(2774610201U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct *)
    utMalloc(sizeof(SFc6_JointSpaceControl_CorrectInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc6_JointSpaceControl_CorrectInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c6_JointSpaceControl_CorrectInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_JointSpaceControl_CorrectInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_JointSpaceControl_CorrectInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_JointSpaceControl_CorrectInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_JointSpaceControl_CorrectInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
