/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectFalseCombo_sfun.h"
#include "c21_JointSpaceControl_CorrectFalseCombo.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_CorrectFalseCombo_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c21_debug_family_names[5] = { "nargin", "nargout", "J_a",
  "dX", "dq" };

/* Function Declarations */
static void initialize_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initialize_params_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void enable_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void disable_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c21_update_debugger_state_c21_JointSpaceControl_CorrectFalseComb
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void set_sim_state_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_st);
static void finalize_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void sf_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c21_chartstep_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initSimStructsc21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void registerMessagesc21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_dq, const char_T *c21_identifier, real_T c21_y[6]);
static void c21_b_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, real_T c21_y[6]);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_c_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[130]);
static void c21_b_info_helper(c21_ResolvedFunctionInfo c21_info[130]);
static void c21_c_info_helper(c21_ResolvedFunctionInfo c21_info[130]);
static void c21_invNxN(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, real_T c21_x[36], real_T c21_y[36]);
static void c21_realmin(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *
  chartInstance);
static void c21_eps(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
                    *chartInstance);
static void c21_eml_matlab_zgetrf
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], real_T c21_b_A[36], int32_T c21_ipiv[6], int32_T *c21_info);
static void c21_check_forloop_overflow_error
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   boolean_T c21_overflow);
static void c21_eml_xger(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, int32_T c21_m, int32_T c21_n, real_T c21_alpha1, int32_T
  c21_ix0, int32_T c21_iy0, real_T c21_A[36], int32_T c21_ia0, real_T c21_b_A[36]);
static void c21_eml_xtrsm
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], real_T c21_B[36], real_T c21_b_B[36]);
static real_T c21_norm(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, real_T c21_x[36]);
static void c21_eml_warning
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c21_b_eml_warning
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   char_T c21_varargin_2[14]);
static void c21_eml_scalar_eg
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c21_d_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_sprintf, const char_T *c21_identifier, char_T c21_y[14]);
static void c21_e_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, char_T c21_y[14]);
static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_f_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_g_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_b_is_active_c21_JointSpaceControl_CorrectFalseCombo, const
   char_T *c21_identifier);
static uint8_T c21_h_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_eml_matlab_zgetrf
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], int32_T c21_ipiv[6], int32_T *c21_info);
static void c21_b_eml_xger
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   int32_T c21_m, int32_T c21_n, real_T c21_alpha1, int32_T c21_ix0, int32_T
   c21_iy0, real_T c21_A[36], int32_T c21_ia0);
static void c21_b_eml_xtrsm
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], real_T c21_B[36]);
static void init_dsm_address_info
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c21_is_active_c21_JointSpaceControl_CorrectFalseCombo = 0U;
}

static void initialize_params_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void enable_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c21_update_debugger_state_c21_JointSpaceControl_CorrectFalseComb
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  int32_T c21_i0;
  real_T c21_u[6];
  const mxArray *c21_b_y = NULL;
  uint8_T c21_hoistedGlobal;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  real_T (*c21_dq)[6];
  c21_dq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellarray(2), FALSE);
  for (c21_i0 = 0; c21_i0 < 6; c21_i0++) {
    c21_u[c21_i0] = (*c21_dq)[c21_i0];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_hoistedGlobal =
    chartInstance->c21_is_active_c21_JointSpaceControl_CorrectFalseCombo;
  c21_b_u = c21_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y, FALSE);
  return c21_st;
}

static void set_sim_state_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv0[6];
  int32_T c21_i1;
  real_T (*c21_dq)[6];
  c21_dq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c21_doneDoubleBufferReInit = TRUE;
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)), "dq",
                       c21_dv0);
  for (c21_i1 = 0; c21_i1 < 6; c21_i1++) {
    (*c21_dq)[c21_i1] = c21_dv0[c21_i1];
  }

  chartInstance->c21_is_active_c21_JointSpaceControl_CorrectFalseCombo =
    c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
    "is_active_c21_JointSpaceControl_CorrectFalseCombo");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_JointSpaceControl_CorrectFalseComb(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void sf_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c21_i2;
  int32_T c21_i3;
  int32_T c21_i4;
  real_T (*c21_dX)[6];
  real_T (*c21_dq)[6];
  real_T (*c21_J_a)[36];
  c21_dX = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c21_dq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_J_a = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
  for (c21_i2 = 0; c21_i2 < 36; c21_i2++) {
    _SFD_DATA_RANGE_CHECK((*c21_J_a)[c21_i2], 0U);
  }

  for (c21_i3 = 0; c21_i3 < 6; c21_i3++) {
    _SFD_DATA_RANGE_CHECK((*c21_dq)[c21_i3], 1U);
  }

  for (c21_i4 = 0; c21_i4 < 6; c21_i4++) {
    _SFD_DATA_RANGE_CHECK((*c21_dX)[c21_i4], 2U);
  }

  chartInstance->c21_sfEvent = CALL_EVENT;
  c21_chartstep_c21_JointSpaceControl_CorrectFalseCombo(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectFalseComboMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c21_chartstep_c21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c21_i5;
  real_T c21_J_a[36];
  int32_T c21_i6;
  real_T c21_dX[6];
  uint32_T c21_debug_family_var_map[5];
  real_T c21_nargin = 2.0;
  real_T c21_nargout = 1.0;
  real_T c21_dq[6];
  int32_T c21_i7;
  real_T c21_x[36];
  int32_T c21_i8;
  real_T c21_b_x[36];
  real_T c21_y[36];
  int32_T c21_i9;
  real_T c21_c_x[36];
  real_T c21_n1x;
  int32_T c21_i10;
  real_T c21_b_y[36];
  real_T c21_n1xinv;
  real_T c21_a;
  real_T c21_b;
  real_T c21_c_y;
  real_T c21_rc;
  real_T c21_d_x;
  boolean_T c21_b_b;
  real_T c21_e_x;
  int32_T c21_i11;
  static char_T c21_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c21_u[8];
  const mxArray *c21_d_y = NULL;
  real_T c21_b_u;
  const mxArray *c21_e_y = NULL;
  real_T c21_c_u;
  const mxArray *c21_f_y = NULL;
  real_T c21_d_u;
  const mxArray *c21_g_y = NULL;
  char_T c21_str[14];
  int32_T c21_i12;
  char_T c21_b_str[14];
  int32_T c21_i13;
  real_T c21_c_b[6];
  int32_T c21_i14;
  int32_T c21_i15;
  int32_T c21_i16;
  real_T c21_C[6];
  int32_T c21_i17;
  int32_T c21_i18;
  int32_T c21_i19;
  int32_T c21_i20;
  int32_T c21_i21;
  int32_T c21_i22;
  int32_T c21_i23;
  real_T (*c21_b_dq)[6];
  real_T (*c21_b_dX)[6];
  real_T (*c21_b_J_a)[36];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c21_b_dX = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c21_b_dq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_b_J_a = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
  for (c21_i5 = 0; c21_i5 < 36; c21_i5++) {
    c21_J_a[c21_i5] = (*c21_b_J_a)[c21_i5];
  }

  for (c21_i6 = 0; c21_i6 < 6; c21_i6++) {
    c21_dX[c21_i6] = (*c21_b_dX)[c21_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 0U, c21_c_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 1U, c21_c_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_J_a, 2U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_dX, 3U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_dq, 4U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 6);
  for (c21_i7 = 0; c21_i7 < 36; c21_i7++) {
    c21_x[c21_i7] = c21_J_a[c21_i7];
  }

  for (c21_i8 = 0; c21_i8 < 36; c21_i8++) {
    c21_b_x[c21_i8] = c21_x[c21_i8];
  }

  c21_invNxN(chartInstance, c21_b_x, c21_y);
  for (c21_i9 = 0; c21_i9 < 36; c21_i9++) {
    c21_c_x[c21_i9] = c21_x[c21_i9];
  }

  c21_n1x = c21_norm(chartInstance, c21_c_x);
  for (c21_i10 = 0; c21_i10 < 36; c21_i10++) {
    c21_b_y[c21_i10] = c21_y[c21_i10];
  }

  c21_n1xinv = c21_norm(chartInstance, c21_b_y);
  c21_a = c21_n1x;
  c21_b = c21_n1xinv;
  c21_c_y = c21_a * c21_b;
  c21_rc = 1.0 / c21_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c21_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c21_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c21_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c21_d_x = c21_rc;
    c21_b_b = muDoubleScalarIsNaN(c21_d_x);
    guard3 = FALSE;
    if (c21_b_b) {
      guard3 = TRUE;
    } else {
      c21_eps(chartInstance);
      if (c21_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c21_e_x = c21_rc;
      for (c21_i11 = 0; c21_i11 < 8; c21_i11++) {
        c21_u[c21_i11] = c21_cv0[c21_i11];
      }

      c21_d_y = NULL;
      sf_mex_assign(&c21_d_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c21_b_u = 14.0;
      c21_e_y = NULL;
      sf_mex_assign(&c21_e_y, sf_mex_create("y", &c21_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c21_c_u = 6.0;
      c21_f_y = NULL;
      sf_mex_assign(&c21_f_y, sf_mex_create("y", &c21_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c21_d_u = c21_e_x;
      c21_g_y = NULL;
      sf_mex_assign(&c21_g_y, sf_mex_create("y", &c21_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c21_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c21_d_y, 14, c21_e_y, 14,
        c21_f_y), 14, c21_g_y), "sprintf", c21_str);
      for (c21_i12 = 0; c21_i12 < 14; c21_i12++) {
        c21_b_str[c21_i12] = c21_str[c21_i12];
      }

      c21_b_eml_warning(chartInstance, c21_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c21_eml_warning(chartInstance);
  }

  for (c21_i13 = 0; c21_i13 < 6; c21_i13++) {
    c21_c_b[c21_i13] = c21_dX[c21_i13];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i14 = 0; c21_i14 < 6; c21_i14++) {
    c21_dq[c21_i14] = 0.0;
  }

  for (c21_i15 = 0; c21_i15 < 6; c21_i15++) {
    c21_dq[c21_i15] = 0.0;
  }

  for (c21_i16 = 0; c21_i16 < 6; c21_i16++) {
    c21_C[c21_i16] = c21_dq[c21_i16];
  }

  for (c21_i17 = 0; c21_i17 < 6; c21_i17++) {
    c21_dq[c21_i17] = c21_C[c21_i17];
  }

  for (c21_i18 = 0; c21_i18 < 6; c21_i18++) {
    c21_C[c21_i18] = c21_dq[c21_i18];
  }

  for (c21_i19 = 0; c21_i19 < 6; c21_i19++) {
    c21_dq[c21_i19] = c21_C[c21_i19];
  }

  for (c21_i20 = 0; c21_i20 < 6; c21_i20++) {
    c21_dq[c21_i20] = 0.0;
    c21_i21 = 0;
    for (c21_i22 = 0; c21_i22 < 6; c21_i22++) {
      c21_dq[c21_i20] += c21_y[c21_i21 + c21_i20] * c21_c_b[c21_i22];
      c21_i21 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c21_i23 = 0; c21_i23 < 6; c21_i23++) {
    (*c21_b_dq)[c21_i23] = c21_dq[c21_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
}

static void initSimStructsc21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void registerMessagesc21_JointSpaceControl_CorrectFalseCombo
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber)
{
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i24;
  real_T c21_b_inData[6];
  int32_T c21_i25;
  real_T c21_u[6];
  const mxArray *c21_y = NULL;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i24 = 0; c21_i24 < 6; c21_i24++) {
    c21_b_inData[c21_i24] = (*(real_T (*)[6])c21_inData)[c21_i24];
  }

  for (c21_i25 = 0; c21_i25 < 6; c21_i25++) {
    c21_u[c21_i25] = c21_b_inData[c21_i25];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static void c21_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_dq, const char_T *c21_identifier, real_T c21_y[6])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_dq), &c21_thisId, c21_y);
  sf_mex_destroy(&c21_dq);
}

static void c21_b_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, real_T c21_y[6])
{
  real_T c21_dv1[6];
  int32_T c21_i26;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c21_i26 = 0; c21_i26 < 6; c21_i26++) {
    c21_y[c21_i26] = c21_dv1[c21_i26];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_dq;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[6];
  int32_T c21_i27;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_dq = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_dq), &c21_thisId, c21_y);
  sf_mex_destroy(&c21_dq);
  for (c21_i27 = 0; c21_i27 < 6; c21_i27++) {
    (*(real_T (*)[6])c21_outData)[c21_i27] = c21_y[c21_i27];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i28;
  int32_T c21_i29;
  int32_T c21_i30;
  real_T c21_b_inData[36];
  int32_T c21_i31;
  int32_T c21_i32;
  int32_T c21_i33;
  real_T c21_u[36];
  const mxArray *c21_y = NULL;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_i28 = 0;
  for (c21_i29 = 0; c21_i29 < 6; c21_i29++) {
    for (c21_i30 = 0; c21_i30 < 6; c21_i30++) {
      c21_b_inData[c21_i30 + c21_i28] = (*(real_T (*)[36])c21_inData)[c21_i30 +
        c21_i28];
    }

    c21_i28 += 6;
  }

  c21_i31 = 0;
  for (c21_i32 = 0; c21_i32 < 6; c21_i32++) {
    for (c21_i33 = 0; c21_i33 < 6; c21_i33++) {
      c21_u[c21_i33 + c21_i31] = c21_b_inData[c21_i33 + c21_i31];
    }

    c21_i31 += 6;
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static real_T c21_c_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d0;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_nargout;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_nargout = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_nargout),
    &c21_thisId);
  sf_mex_destroy(&c21_nargout);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

const mxArray
  *sf_c21_JointSpaceControl_CorrectFalseCombo_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c21_nameCaptureInfo;
  c21_ResolvedFunctionInfo c21_info[130];
  const mxArray *c21_m0 = NULL;
  int32_T c21_i34;
  c21_ResolvedFunctionInfo *c21_r0;
  c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  c21_info_helper(c21_info);
  c21_b_info_helper(c21_info);
  c21_c_info_helper(c21_info);
  sf_mex_assign(&c21_m0, sf_mex_createstruct("nameCaptureInfo", 1, 130), FALSE);
  for (c21_i34 = 0; c21_i34 < 130; c21_i34++) {
    c21_r0 = &c21_info[c21_i34];
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->context)), "context", "nameCaptureInfo",
                    c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->name)), "name", "nameCaptureInfo",
                    c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      c21_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->resolved)), "resolved",
                    "nameCaptureInfo", c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      &c21_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c21_i34);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      &c21_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c21_i34);
  }

  sf_mex_assign(&c21_nameCaptureInfo, c21_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[130])
{
  c21_info[0].context = "";
  c21_info[0].name = "inv";
  c21_info[0].dominantType = "double";
  c21_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c21_info[0].fileTimeLo = 1305339600U;
  c21_info[0].fileTimeHi = 0U;
  c21_info[0].mFileTimeLo = 0U;
  c21_info[0].mFileTimeHi = 0U;
  c21_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[1].name = "eml_index_class";
  c21_info[1].dominantType = "";
  c21_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[1].fileTimeLo = 1323192178U;
  c21_info[1].fileTimeHi = 0U;
  c21_info[1].mFileTimeLo = 0U;
  c21_info[1].mFileTimeHi = 0U;
  c21_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[2].name = "eml_xgetrf";
  c21_info[2].dominantType = "double";
  c21_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c21_info[2].fileTimeLo = 1286840406U;
  c21_info[2].fileTimeHi = 0U;
  c21_info[2].mFileTimeLo = 0U;
  c21_info[2].mFileTimeHi = 0U;
  c21_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c21_info[3].name = "eml_lapack_xgetrf";
  c21_info[3].dominantType = "double";
  c21_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c21_info[3].fileTimeLo = 1286840410U;
  c21_info[3].fileTimeHi = 0U;
  c21_info[3].mFileTimeLo = 0U;
  c21_info[3].mFileTimeHi = 0U;
  c21_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c21_info[4].name = "eml_matlab_zgetrf";
  c21_info[4].dominantType = "double";
  c21_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[4].fileTimeLo = 1302710594U;
  c21_info[4].fileTimeHi = 0U;
  c21_info[4].mFileTimeLo = 0U;
  c21_info[4].mFileTimeHi = 0U;
  c21_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[5].name = "realmin";
  c21_info[5].dominantType = "char";
  c21_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c21_info[5].fileTimeLo = 1307672842U;
  c21_info[5].fileTimeHi = 0U;
  c21_info[5].mFileTimeLo = 0U;
  c21_info[5].mFileTimeHi = 0U;
  c21_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c21_info[6].name = "eml_realmin";
  c21_info[6].dominantType = "char";
  c21_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c21_info[6].fileTimeLo = 1307672844U;
  c21_info[6].fileTimeHi = 0U;
  c21_info[6].mFileTimeLo = 0U;
  c21_info[6].mFileTimeHi = 0U;
  c21_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c21_info[7].name = "eml_float_model";
  c21_info[7].dominantType = "char";
  c21_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c21_info[7].fileTimeLo = 1326749596U;
  c21_info[7].fileTimeHi = 0U;
  c21_info[7].mFileTimeLo = 0U;
  c21_info[7].mFileTimeHi = 0U;
  c21_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[8].name = "eps";
  c21_info[8].dominantType = "char";
  c21_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c21_info[8].fileTimeLo = 1326749596U;
  c21_info[8].fileTimeHi = 0U;
  c21_info[8].mFileTimeLo = 0U;
  c21_info[8].mFileTimeHi = 0U;
  c21_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c21_info[9].name = "eml_is_float_class";
  c21_info[9].dominantType = "char";
  c21_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c21_info[9].fileTimeLo = 1286840382U;
  c21_info[9].fileTimeHi = 0U;
  c21_info[9].mFileTimeLo = 0U;
  c21_info[9].mFileTimeHi = 0U;
  c21_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c21_info[10].name = "eml_eps";
  c21_info[10].dominantType = "char";
  c21_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c21_info[10].fileTimeLo = 1326749596U;
  c21_info[10].fileTimeHi = 0U;
  c21_info[10].mFileTimeLo = 0U;
  c21_info[10].mFileTimeHi = 0U;
  c21_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c21_info[11].name = "eml_float_model";
  c21_info[11].dominantType = "char";
  c21_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c21_info[11].fileTimeLo = 1326749596U;
  c21_info[11].fileTimeHi = 0U;
  c21_info[11].mFileTimeLo = 0U;
  c21_info[11].mFileTimeHi = 0U;
  c21_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[12].name = "min";
  c21_info[12].dominantType = "coder.internal.indexInt";
  c21_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c21_info[12].fileTimeLo = 1311276918U;
  c21_info[12].fileTimeHi = 0U;
  c21_info[12].mFileTimeLo = 0U;
  c21_info[12].mFileTimeHi = 0U;
  c21_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c21_info[13].name = "eml_min_or_max";
  c21_info[13].dominantType = "char";
  c21_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c21_info[13].fileTimeLo = 1334093090U;
  c21_info[13].fileTimeHi = 0U;
  c21_info[13].mFileTimeLo = 0U;
  c21_info[13].mFileTimeHi = 0U;
  c21_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[14].name = "eml_scalar_eg";
  c21_info[14].dominantType = "coder.internal.indexInt";
  c21_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[14].fileTimeLo = 1286840396U;
  c21_info[14].fileTimeHi = 0U;
  c21_info[14].mFileTimeLo = 0U;
  c21_info[14].mFileTimeHi = 0U;
  c21_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[15].name = "eml_scalexp_alloc";
  c21_info[15].dominantType = "coder.internal.indexInt";
  c21_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c21_info[15].fileTimeLo = 1352446460U;
  c21_info[15].fileTimeHi = 0U;
  c21_info[15].mFileTimeLo = 0U;
  c21_info[15].mFileTimeHi = 0U;
  c21_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[16].name = "eml_index_class";
  c21_info[16].dominantType = "";
  c21_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[16].fileTimeLo = 1323192178U;
  c21_info[16].fileTimeHi = 0U;
  c21_info[16].mFileTimeLo = 0U;
  c21_info[16].mFileTimeHi = 0U;
  c21_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c21_info[17].name = "eml_scalar_eg";
  c21_info[17].dominantType = "coder.internal.indexInt";
  c21_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[17].fileTimeLo = 1286840396U;
  c21_info[17].fileTimeHi = 0U;
  c21_info[17].mFileTimeLo = 0U;
  c21_info[17].mFileTimeHi = 0U;
  c21_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[18].name = "colon";
  c21_info[18].dominantType = "double";
  c21_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c21_info[18].fileTimeLo = 1348213528U;
  c21_info[18].fileTimeHi = 0U;
  c21_info[18].mFileTimeLo = 0U;
  c21_info[18].mFileTimeHi = 0U;
  c21_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c21_info[19].name = "colon";
  c21_info[19].dominantType = "double";
  c21_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c21_info[19].fileTimeLo = 1348213528U;
  c21_info[19].fileTimeHi = 0U;
  c21_info[19].mFileTimeLo = 0U;
  c21_info[19].mFileTimeHi = 0U;
  c21_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c21_info[20].name = "floor";
  c21_info[20].dominantType = "double";
  c21_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c21_info[20].fileTimeLo = 1343851980U;
  c21_info[20].fileTimeHi = 0U;
  c21_info[20].mFileTimeLo = 0U;
  c21_info[20].mFileTimeHi = 0U;
  c21_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c21_info[21].name = "eml_scalar_floor";
  c21_info[21].dominantType = "double";
  c21_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c21_info[21].fileTimeLo = 1286840326U;
  c21_info[21].fileTimeHi = 0U;
  c21_info[21].mFileTimeLo = 0U;
  c21_info[21].mFileTimeHi = 0U;
  c21_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c21_info[22].name = "intmin";
  c21_info[22].dominantType = "char";
  c21_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c21_info[22].fileTimeLo = 1311276918U;
  c21_info[22].fileTimeHi = 0U;
  c21_info[22].mFileTimeLo = 0U;
  c21_info[22].mFileTimeHi = 0U;
  c21_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c21_info[23].name = "intmax";
  c21_info[23].dominantType = "char";
  c21_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[23].fileTimeLo = 1311276916U;
  c21_info[23].fileTimeHi = 0U;
  c21_info[23].mFileTimeLo = 0U;
  c21_info[23].mFileTimeHi = 0U;
  c21_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c21_info[24].name = "intmin";
  c21_info[24].dominantType = "char";
  c21_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c21_info[24].fileTimeLo = 1311276918U;
  c21_info[24].fileTimeHi = 0U;
  c21_info[24].mFileTimeLo = 0U;
  c21_info[24].mFileTimeHi = 0U;
  c21_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c21_info[25].name = "intmax";
  c21_info[25].dominantType = "char";
  c21_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[25].fileTimeLo = 1311276916U;
  c21_info[25].fileTimeHi = 0U;
  c21_info[25].mFileTimeLo = 0U;
  c21_info[25].mFileTimeHi = 0U;
  c21_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c21_info[26].name = "eml_isa_uint";
  c21_info[26].dominantType = "coder.internal.indexInt";
  c21_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c21_info[26].fileTimeLo = 1286840384U;
  c21_info[26].fileTimeHi = 0U;
  c21_info[26].mFileTimeLo = 0U;
  c21_info[26].mFileTimeHi = 0U;
  c21_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c21_info[27].name = "eml_unsigned_class";
  c21_info[27].dominantType = "char";
  c21_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c21_info[27].fileTimeLo = 1323192180U;
  c21_info[27].fileTimeHi = 0U;
  c21_info[27].mFileTimeLo = 0U;
  c21_info[27].mFileTimeHi = 0U;
  c21_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c21_info[28].name = "eml_index_class";
  c21_info[28].dominantType = "";
  c21_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[28].fileTimeLo = 1323192178U;
  c21_info[28].fileTimeHi = 0U;
  c21_info[28].mFileTimeLo = 0U;
  c21_info[28].mFileTimeHi = 0U;
  c21_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c21_info[29].name = "eml_index_class";
  c21_info[29].dominantType = "";
  c21_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[29].fileTimeLo = 1323192178U;
  c21_info[29].fileTimeHi = 0U;
  c21_info[29].mFileTimeLo = 0U;
  c21_info[29].mFileTimeHi = 0U;
  c21_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c21_info[30].name = "intmax";
  c21_info[30].dominantType = "char";
  c21_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[30].fileTimeLo = 1311276916U;
  c21_info[30].fileTimeHi = 0U;
  c21_info[30].mFileTimeLo = 0U;
  c21_info[30].mFileTimeHi = 0U;
  c21_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c21_info[31].name = "eml_isa_uint";
  c21_info[31].dominantType = "coder.internal.indexInt";
  c21_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c21_info[31].fileTimeLo = 1286840384U;
  c21_info[31].fileTimeHi = 0U;
  c21_info[31].mFileTimeLo = 0U;
  c21_info[31].mFileTimeHi = 0U;
  c21_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c21_info[32].name = "eml_index_plus";
  c21_info[32].dominantType = "double";
  c21_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[32].fileTimeLo = 1286840378U;
  c21_info[32].fileTimeHi = 0U;
  c21_info[32].mFileTimeLo = 0U;
  c21_info[32].mFileTimeHi = 0U;
  c21_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[33].name = "eml_index_class";
  c21_info[33].dominantType = "";
  c21_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[33].fileTimeLo = 1323192178U;
  c21_info[33].fileTimeHi = 0U;
  c21_info[33].mFileTimeLo = 0U;
  c21_info[33].mFileTimeHi = 0U;
  c21_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c21_info[34].name = "eml_int_forloop_overflow_check";
  c21_info[34].dominantType = "";
  c21_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[34].fileTimeLo = 1346531940U;
  c21_info[34].fileTimeHi = 0U;
  c21_info[34].mFileTimeLo = 0U;
  c21_info[34].mFileTimeHi = 0U;
  c21_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c21_info[35].name = "intmax";
  c21_info[35].dominantType = "char";
  c21_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[35].fileTimeLo = 1311276916U;
  c21_info[35].fileTimeHi = 0U;
  c21_info[35].mFileTimeLo = 0U;
  c21_info[35].mFileTimeHi = 0U;
  c21_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[36].name = "eml_index_class";
  c21_info[36].dominantType = "";
  c21_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[36].fileTimeLo = 1323192178U;
  c21_info[36].fileTimeHi = 0U;
  c21_info[36].mFileTimeLo = 0U;
  c21_info[36].mFileTimeHi = 0U;
  c21_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[37].name = "eml_index_plus";
  c21_info[37].dominantType = "double";
  c21_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[37].fileTimeLo = 1286840378U;
  c21_info[37].fileTimeHi = 0U;
  c21_info[37].mFileTimeLo = 0U;
  c21_info[37].mFileTimeHi = 0U;
  c21_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[38].name = "eml_int_forloop_overflow_check";
  c21_info[38].dominantType = "";
  c21_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[38].fileTimeLo = 1346531940U;
  c21_info[38].fileTimeHi = 0U;
  c21_info[38].mFileTimeLo = 0U;
  c21_info[38].mFileTimeHi = 0U;
  c21_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[39].name = "eml_index_minus";
  c21_info[39].dominantType = "double";
  c21_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[39].fileTimeLo = 1286840378U;
  c21_info[39].fileTimeHi = 0U;
  c21_info[39].mFileTimeLo = 0U;
  c21_info[39].mFileTimeHi = 0U;
  c21_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[40].name = "eml_index_class";
  c21_info[40].dominantType = "";
  c21_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[40].fileTimeLo = 1323192178U;
  c21_info[40].fileTimeHi = 0U;
  c21_info[40].mFileTimeLo = 0U;
  c21_info[40].mFileTimeHi = 0U;
  c21_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[41].name = "eml_index_minus";
  c21_info[41].dominantType = "coder.internal.indexInt";
  c21_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[41].fileTimeLo = 1286840378U;
  c21_info[41].fileTimeHi = 0U;
  c21_info[41].mFileTimeLo = 0U;
  c21_info[41].mFileTimeHi = 0U;
  c21_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[42].name = "eml_index_times";
  c21_info[42].dominantType = "coder.internal.indexInt";
  c21_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c21_info[42].fileTimeLo = 1286840380U;
  c21_info[42].fileTimeHi = 0U;
  c21_info[42].mFileTimeLo = 0U;
  c21_info[42].mFileTimeHi = 0U;
  c21_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c21_info[43].name = "eml_index_class";
  c21_info[43].dominantType = "";
  c21_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[43].fileTimeLo = 1323192178U;
  c21_info[43].fileTimeHi = 0U;
  c21_info[43].mFileTimeLo = 0U;
  c21_info[43].mFileTimeHi = 0U;
  c21_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[44].name = "eml_index_plus";
  c21_info[44].dominantType = "coder.internal.indexInt";
  c21_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[44].fileTimeLo = 1286840378U;
  c21_info[44].fileTimeHi = 0U;
  c21_info[44].mFileTimeLo = 0U;
  c21_info[44].mFileTimeHi = 0U;
  c21_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[45].name = "eml_ixamax";
  c21_info[45].dominantType = "double";
  c21_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c21_info[45].fileTimeLo = 1299098370U;
  c21_info[45].fileTimeHi = 0U;
  c21_info[45].mFileTimeLo = 0U;
  c21_info[45].mFileTimeHi = 0U;
  c21_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c21_info[46].name = "eml_blas_inline";
  c21_info[46].dominantType = "";
  c21_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c21_info[46].fileTimeLo = 1299098368U;
  c21_info[46].fileTimeHi = 0U;
  c21_info[46].mFileTimeLo = 0U;
  c21_info[46].mFileTimeHi = 0U;
  c21_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c21_info[47].name = "length";
  c21_info[47].dominantType = "double";
  c21_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c21_info[47].fileTimeLo = 1303167806U;
  c21_info[47].fileTimeHi = 0U;
  c21_info[47].mFileTimeLo = 0U;
  c21_info[47].mFileTimeHi = 0U;
  c21_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c21_info[48].name = "eml_index_class";
  c21_info[48].dominantType = "";
  c21_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[48].fileTimeLo = 1323192178U;
  c21_info[48].fileTimeHi = 0U;
  c21_info[48].mFileTimeLo = 0U;
  c21_info[48].mFileTimeHi = 0U;
  c21_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c21_info[49].name = "eml_index_class";
  c21_info[49].dominantType = "";
  c21_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[49].fileTimeLo = 1323192178U;
  c21_info[49].fileTimeHi = 0U;
  c21_info[49].mFileTimeLo = 0U;
  c21_info[49].mFileTimeHi = 0U;
  c21_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c21_info[50].name = "eml_refblas_ixamax";
  c21_info[50].dominantType = "double";
  c21_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c21_info[50].fileTimeLo = 1299098370U;
  c21_info[50].fileTimeHi = 0U;
  c21_info[50].mFileTimeLo = 0U;
  c21_info[50].mFileTimeHi = 0U;
  c21_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c21_info[51].name = "eml_index_class";
  c21_info[51].dominantType = "";
  c21_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[51].fileTimeLo = 1323192178U;
  c21_info[51].fileTimeHi = 0U;
  c21_info[51].mFileTimeLo = 0U;
  c21_info[51].mFileTimeHi = 0U;
  c21_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c21_info[52].name = "eml_xcabs1";
  c21_info[52].dominantType = "double";
  c21_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c21_info[52].fileTimeLo = 1286840306U;
  c21_info[52].fileTimeHi = 0U;
  c21_info[52].mFileTimeLo = 0U;
  c21_info[52].mFileTimeHi = 0U;
  c21_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c21_info[53].name = "abs";
  c21_info[53].dominantType = "double";
  c21_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[53].fileTimeLo = 1343851966U;
  c21_info[53].fileTimeHi = 0U;
  c21_info[53].mFileTimeLo = 0U;
  c21_info[53].mFileTimeHi = 0U;
  c21_info[54].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[54].name = "eml_scalar_abs";
  c21_info[54].dominantType = "double";
  c21_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c21_info[54].fileTimeLo = 1286840312U;
  c21_info[54].fileTimeHi = 0U;
  c21_info[54].mFileTimeLo = 0U;
  c21_info[54].mFileTimeHi = 0U;
  c21_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c21_info[55].name = "eml_int_forloop_overflow_check";
  c21_info[55].dominantType = "";
  c21_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[55].fileTimeLo = 1346531940U;
  c21_info[55].fileTimeHi = 0U;
  c21_info[55].mFileTimeLo = 0U;
  c21_info[55].mFileTimeHi = 0U;
  c21_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c21_info[56].name = "eml_index_plus";
  c21_info[56].dominantType = "coder.internal.indexInt";
  c21_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[56].fileTimeLo = 1286840378U;
  c21_info[56].fileTimeHi = 0U;
  c21_info[56].mFileTimeLo = 0U;
  c21_info[56].mFileTimeHi = 0U;
  c21_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[57].name = "eml_xswap";
  c21_info[57].dominantType = "double";
  c21_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c21_info[57].fileTimeLo = 1299098378U;
  c21_info[57].fileTimeHi = 0U;
  c21_info[57].mFileTimeLo = 0U;
  c21_info[57].mFileTimeHi = 0U;
  c21_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c21_info[58].name = "eml_blas_inline";
  c21_info[58].dominantType = "";
  c21_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c21_info[58].fileTimeLo = 1299098368U;
  c21_info[58].fileTimeHi = 0U;
  c21_info[58].mFileTimeLo = 0U;
  c21_info[58].mFileTimeHi = 0U;
  c21_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c21_info[59].name = "eml_index_class";
  c21_info[59].dominantType = "";
  c21_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[59].fileTimeLo = 1323192178U;
  c21_info[59].fileTimeHi = 0U;
  c21_info[59].mFileTimeLo = 0U;
  c21_info[59].mFileTimeHi = 0U;
  c21_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c21_info[60].name = "eml_refblas_xswap";
  c21_info[60].dominantType = "double";
  c21_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c21_info[60].fileTimeLo = 1299098386U;
  c21_info[60].fileTimeHi = 0U;
  c21_info[60].mFileTimeLo = 0U;
  c21_info[60].mFileTimeHi = 0U;
  c21_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c21_info[61].name = "eml_index_class";
  c21_info[61].dominantType = "";
  c21_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[61].fileTimeLo = 1323192178U;
  c21_info[61].fileTimeHi = 0U;
  c21_info[61].mFileTimeLo = 0U;
  c21_info[61].mFileTimeHi = 0U;
  c21_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c21_info[62].name = "abs";
  c21_info[62].dominantType = "coder.internal.indexInt";
  c21_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[62].fileTimeLo = 1343851966U;
  c21_info[62].fileTimeHi = 0U;
  c21_info[62].mFileTimeLo = 0U;
  c21_info[62].mFileTimeHi = 0U;
  c21_info[63].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[63].name = "eml_scalar_abs";
  c21_info[63].dominantType = "coder.internal.indexInt";
  c21_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c21_info[63].fileTimeLo = 1286840312U;
  c21_info[63].fileTimeHi = 0U;
  c21_info[63].mFileTimeLo = 0U;
  c21_info[63].mFileTimeHi = 0U;
}

static void c21_b_info_helper(c21_ResolvedFunctionInfo c21_info[130])
{
  c21_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c21_info[64].name = "eml_int_forloop_overflow_check";
  c21_info[64].dominantType = "";
  c21_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[64].fileTimeLo = 1346531940U;
  c21_info[64].fileTimeHi = 0U;
  c21_info[64].mFileTimeLo = 0U;
  c21_info[64].mFileTimeHi = 0U;
  c21_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c21_info[65].name = "eml_index_plus";
  c21_info[65].dominantType = "coder.internal.indexInt";
  c21_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[65].fileTimeLo = 1286840378U;
  c21_info[65].fileTimeHi = 0U;
  c21_info[65].mFileTimeLo = 0U;
  c21_info[65].mFileTimeHi = 0U;
  c21_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[66].name = "eml_div";
  c21_info[66].dominantType = "double";
  c21_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[66].fileTimeLo = 1313369410U;
  c21_info[66].fileTimeHi = 0U;
  c21_info[66].mFileTimeLo = 0U;
  c21_info[66].mFileTimeHi = 0U;
  c21_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c21_info[67].name = "eml_xgeru";
  c21_info[67].dominantType = "double";
  c21_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c21_info[67].fileTimeLo = 1299098374U;
  c21_info[67].fileTimeHi = 0U;
  c21_info[67].mFileTimeLo = 0U;
  c21_info[67].mFileTimeHi = 0U;
  c21_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c21_info[68].name = "eml_blas_inline";
  c21_info[68].dominantType = "";
  c21_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c21_info[68].fileTimeLo = 1299098368U;
  c21_info[68].fileTimeHi = 0U;
  c21_info[68].mFileTimeLo = 0U;
  c21_info[68].mFileTimeHi = 0U;
  c21_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c21_info[69].name = "eml_xger";
  c21_info[69].dominantType = "double";
  c21_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c21_info[69].fileTimeLo = 1299098374U;
  c21_info[69].fileTimeHi = 0U;
  c21_info[69].mFileTimeLo = 0U;
  c21_info[69].mFileTimeHi = 0U;
  c21_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c21_info[70].name = "eml_blas_inline";
  c21_info[70].dominantType = "";
  c21_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c21_info[70].fileTimeLo = 1299098368U;
  c21_info[70].fileTimeHi = 0U;
  c21_info[70].mFileTimeLo = 0U;
  c21_info[70].mFileTimeHi = 0U;
  c21_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c21_info[71].name = "intmax";
  c21_info[71].dominantType = "char";
  c21_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[71].fileTimeLo = 1311276916U;
  c21_info[71].fileTimeHi = 0U;
  c21_info[71].mFileTimeLo = 0U;
  c21_info[71].mFileTimeHi = 0U;
  c21_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c21_info[72].name = "min";
  c21_info[72].dominantType = "double";
  c21_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c21_info[72].fileTimeLo = 1311276918U;
  c21_info[72].fileTimeHi = 0U;
  c21_info[72].mFileTimeLo = 0U;
  c21_info[72].mFileTimeHi = 0U;
  c21_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[73].name = "eml_scalar_eg";
  c21_info[73].dominantType = "double";
  c21_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[73].fileTimeLo = 1286840396U;
  c21_info[73].fileTimeHi = 0U;
  c21_info[73].mFileTimeLo = 0U;
  c21_info[73].mFileTimeHi = 0U;
  c21_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[74].name = "eml_scalexp_alloc";
  c21_info[74].dominantType = "double";
  c21_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c21_info[74].fileTimeLo = 1352446460U;
  c21_info[74].fileTimeHi = 0U;
  c21_info[74].mFileTimeLo = 0U;
  c21_info[74].mFileTimeHi = 0U;
  c21_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c21_info[75].name = "eml_scalar_eg";
  c21_info[75].dominantType = "double";
  c21_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[75].fileTimeLo = 1286840396U;
  c21_info[75].fileTimeHi = 0U;
  c21_info[75].mFileTimeLo = 0U;
  c21_info[75].mFileTimeHi = 0U;
  c21_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c21_info[76].name = "mtimes";
  c21_info[76].dominantType = "double";
  c21_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[76].fileTimeLo = 1289541292U;
  c21_info[76].fileTimeHi = 0U;
  c21_info[76].mFileTimeLo = 0U;
  c21_info[76].mFileTimeHi = 0U;
  c21_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c21_info[77].name = "eml_index_class";
  c21_info[77].dominantType = "";
  c21_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[77].fileTimeLo = 1323192178U;
  c21_info[77].fileTimeHi = 0U;
  c21_info[77].mFileTimeLo = 0U;
  c21_info[77].mFileTimeHi = 0U;
  c21_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c21_info[78].name = "eml_refblas_xger";
  c21_info[78].dominantType = "double";
  c21_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c21_info[78].fileTimeLo = 1299098376U;
  c21_info[78].fileTimeHi = 0U;
  c21_info[78].mFileTimeLo = 0U;
  c21_info[78].mFileTimeHi = 0U;
  c21_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c21_info[79].name = "eml_refblas_xgerx";
  c21_info[79].dominantType = "char";
  c21_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[79].fileTimeLo = 1299098378U;
  c21_info[79].fileTimeHi = 0U;
  c21_info[79].mFileTimeLo = 0U;
  c21_info[79].mFileTimeHi = 0U;
  c21_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[80].name = "eml_index_class";
  c21_info[80].dominantType = "";
  c21_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[80].fileTimeLo = 1323192178U;
  c21_info[80].fileTimeHi = 0U;
  c21_info[80].mFileTimeLo = 0U;
  c21_info[80].mFileTimeHi = 0U;
  c21_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[81].name = "abs";
  c21_info[81].dominantType = "coder.internal.indexInt";
  c21_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[81].fileTimeLo = 1343851966U;
  c21_info[81].fileTimeHi = 0U;
  c21_info[81].mFileTimeLo = 0U;
  c21_info[81].mFileTimeHi = 0U;
  c21_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[82].name = "eml_index_minus";
  c21_info[82].dominantType = "double";
  c21_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[82].fileTimeLo = 1286840378U;
  c21_info[82].fileTimeHi = 0U;
  c21_info[82].mFileTimeLo = 0U;
  c21_info[82].mFileTimeHi = 0U;
  c21_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[83].name = "eml_int_forloop_overflow_check";
  c21_info[83].dominantType = "";
  c21_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[83].fileTimeLo = 1346531940U;
  c21_info[83].fileTimeHi = 0U;
  c21_info[83].mFileTimeLo = 0U;
  c21_info[83].mFileTimeHi = 0U;
  c21_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[84].name = "eml_index_plus";
  c21_info[84].dominantType = "double";
  c21_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[84].fileTimeLo = 1286840378U;
  c21_info[84].fileTimeHi = 0U;
  c21_info[84].mFileTimeLo = 0U;
  c21_info[84].mFileTimeHi = 0U;
  c21_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c21_info[85].name = "eml_index_plus";
  c21_info[85].dominantType = "coder.internal.indexInt";
  c21_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[85].fileTimeLo = 1286840378U;
  c21_info[85].fileTimeHi = 0U;
  c21_info[85].mFileTimeLo = 0U;
  c21_info[85].mFileTimeHi = 0U;
  c21_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[86].name = "eml_ipiv2perm";
  c21_info[86].dominantType = "coder.internal.indexInt";
  c21_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c21_info[86].fileTimeLo = 1286840382U;
  c21_info[86].fileTimeHi = 0U;
  c21_info[86].mFileTimeLo = 0U;
  c21_info[86].mFileTimeHi = 0U;
  c21_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c21_info[87].name = "colon";
  c21_info[87].dominantType = "double";
  c21_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c21_info[87].fileTimeLo = 1348213528U;
  c21_info[87].fileTimeHi = 0U;
  c21_info[87].mFileTimeLo = 0U;
  c21_info[87].mFileTimeHi = 0U;
  c21_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c21_info[88].name = "eml_index_class";
  c21_info[88].dominantType = "";
  c21_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[88].fileTimeLo = 1323192178U;
  c21_info[88].fileTimeHi = 0U;
  c21_info[88].mFileTimeLo = 0U;
  c21_info[88].mFileTimeHi = 0U;
  c21_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c21_info[89].name = "coder.internal.indexIntRelop";
  c21_info[89].dominantType = "";
  c21_info[89].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c21_info[89].fileTimeLo = 1326749922U;
  c21_info[89].fileTimeHi = 0U;
  c21_info[89].mFileTimeLo = 0U;
  c21_info[89].mFileTimeHi = 0U;
  c21_info[90].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c21_info[90].name = "eml_float_model";
  c21_info[90].dominantType = "char";
  c21_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c21_info[90].fileTimeLo = 1326749596U;
  c21_info[90].fileTimeHi = 0U;
  c21_info[90].mFileTimeLo = 0U;
  c21_info[90].mFileTimeHi = 0U;
  c21_info[91].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c21_info[91].name = "intmin";
  c21_info[91].dominantType = "char";
  c21_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c21_info[91].fileTimeLo = 1311276918U;
  c21_info[91].fileTimeHi = 0U;
  c21_info[91].mFileTimeLo = 0U;
  c21_info[91].mFileTimeHi = 0U;
  c21_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[92].name = "eml_int_forloop_overflow_check";
  c21_info[92].dominantType = "";
  c21_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[92].fileTimeLo = 1346531940U;
  c21_info[92].fileTimeHi = 0U;
  c21_info[92].mFileTimeLo = 0U;
  c21_info[92].mFileTimeHi = 0U;
  c21_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[93].name = "eml_index_plus";
  c21_info[93].dominantType = "double";
  c21_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[93].fileTimeLo = 1286840378U;
  c21_info[93].fileTimeHi = 0U;
  c21_info[93].mFileTimeLo = 0U;
  c21_info[93].mFileTimeHi = 0U;
  c21_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[94].name = "mtimes";
  c21_info[94].dominantType = "double";
  c21_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[94].fileTimeLo = 1289541292U;
  c21_info[94].fileTimeHi = 0U;
  c21_info[94].mFileTimeLo = 0U;
  c21_info[94].mFileTimeHi = 0U;
  c21_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[95].name = "eml_scalar_eg";
  c21_info[95].dominantType = "double";
  c21_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[95].fileTimeLo = 1286840396U;
  c21_info[95].fileTimeHi = 0U;
  c21_info[95].mFileTimeLo = 0U;
  c21_info[95].mFileTimeHi = 0U;
  c21_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c21_info[96].name = "eml_xtrsm";
  c21_info[96].dominantType = "char";
  c21_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c21_info[96].fileTimeLo = 1299098378U;
  c21_info[96].fileTimeHi = 0U;
  c21_info[96].mFileTimeLo = 0U;
  c21_info[96].mFileTimeHi = 0U;
  c21_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c21_info[97].name = "eml_blas_inline";
  c21_info[97].dominantType = "";
  c21_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c21_info[97].fileTimeLo = 1299098368U;
  c21_info[97].fileTimeHi = 0U;
  c21_info[97].mFileTimeLo = 0U;
  c21_info[97].mFileTimeHi = 0U;
  c21_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c21_info[98].name = "mtimes";
  c21_info[98].dominantType = "double";
  c21_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[98].fileTimeLo = 1289541292U;
  c21_info[98].fileTimeHi = 0U;
  c21_info[98].mFileTimeLo = 0U;
  c21_info[98].mFileTimeHi = 0U;
  c21_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c21_info[99].name = "eml_index_class";
  c21_info[99].dominantType = "";
  c21_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[99].fileTimeLo = 1323192178U;
  c21_info[99].fileTimeHi = 0U;
  c21_info[99].mFileTimeLo = 0U;
  c21_info[99].mFileTimeHi = 0U;
  c21_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c21_info[100].name = "eml_scalar_eg";
  c21_info[100].dominantType = "double";
  c21_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[100].fileTimeLo = 1286840396U;
  c21_info[100].fileTimeHi = 0U;
  c21_info[100].mFileTimeLo = 0U;
  c21_info[100].mFileTimeHi = 0U;
  c21_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c21_info[101].name = "eml_refblas_xtrsm";
  c21_info[101].dominantType = "char";
  c21_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[101].fileTimeLo = 1299098386U;
  c21_info[101].fileTimeHi = 0U;
  c21_info[101].mFileTimeLo = 0U;
  c21_info[101].mFileTimeHi = 0U;
  c21_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[102].name = "eml_scalar_eg";
  c21_info[102].dominantType = "double";
  c21_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[102].fileTimeLo = 1286840396U;
  c21_info[102].fileTimeHi = 0U;
  c21_info[102].mFileTimeLo = 0U;
  c21_info[102].mFileTimeHi = 0U;
  c21_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[103].name = "eml_index_minus";
  c21_info[103].dominantType = "double";
  c21_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[103].fileTimeLo = 1286840378U;
  c21_info[103].fileTimeHi = 0U;
  c21_info[103].mFileTimeLo = 0U;
  c21_info[103].mFileTimeHi = 0U;
  c21_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[104].name = "eml_index_class";
  c21_info[104].dominantType = "";
  c21_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[104].fileTimeLo = 1323192178U;
  c21_info[104].fileTimeHi = 0U;
  c21_info[104].mFileTimeLo = 0U;
  c21_info[104].mFileTimeHi = 0U;
  c21_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[105].name = "eml_int_forloop_overflow_check";
  c21_info[105].dominantType = "";
  c21_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c21_info[105].fileTimeLo = 1346531940U;
  c21_info[105].fileTimeHi = 0U;
  c21_info[105].mFileTimeLo = 0U;
  c21_info[105].mFileTimeHi = 0U;
  c21_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[106].name = "eml_index_times";
  c21_info[106].dominantType = "coder.internal.indexInt";
  c21_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c21_info[106].fileTimeLo = 1286840380U;
  c21_info[106].fileTimeHi = 0U;
  c21_info[106].mFileTimeLo = 0U;
  c21_info[106].mFileTimeHi = 0U;
  c21_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[107].name = "eml_index_plus";
  c21_info[107].dominantType = "coder.internal.indexInt";
  c21_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[107].fileTimeLo = 1286840378U;
  c21_info[107].fileTimeHi = 0U;
  c21_info[107].mFileTimeLo = 0U;
  c21_info[107].mFileTimeHi = 0U;
  c21_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c21_info[108].name = "intmin";
  c21_info[108].dominantType = "char";
  c21_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c21_info[108].fileTimeLo = 1311276918U;
  c21_info[108].fileTimeHi = 0U;
  c21_info[108].mFileTimeLo = 0U;
  c21_info[108].mFileTimeHi = 0U;
  c21_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c21_info[109].name = "eml_div";
  c21_info[109].dominantType = "double";
  c21_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[109].fileTimeLo = 1313369410U;
  c21_info[109].fileTimeHi = 0U;
  c21_info[109].mFileTimeLo = 0U;
  c21_info[109].mFileTimeHi = 0U;
  c21_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c21_info[110].name = "norm";
  c21_info[110].dominantType = "double";
  c21_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[110].fileTimeLo = 1336543694U;
  c21_info[110].fileTimeHi = 0U;
  c21_info[110].mFileTimeLo = 0U;
  c21_info[110].mFileTimeHi = 0U;
  c21_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c21_info[111].name = "abs";
  c21_info[111].dominantType = "double";
  c21_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[111].fileTimeLo = 1343851966U;
  c21_info[111].fileTimeHi = 0U;
  c21_info[111].mFileTimeLo = 0U;
  c21_info[111].mFileTimeHi = 0U;
  c21_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c21_info[112].name = "isnan";
  c21_info[112].dominantType = "double";
  c21_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c21_info[112].fileTimeLo = 1286840360U;
  c21_info[112].fileTimeHi = 0U;
  c21_info[112].mFileTimeLo = 0U;
  c21_info[112].mFileTimeHi = 0U;
  c21_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c21_info[113].name = "eml_guarded_nan";
  c21_info[113].dominantType = "char";
  c21_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c21_info[113].fileTimeLo = 1286840376U;
  c21_info[113].fileTimeHi = 0U;
  c21_info[113].mFileTimeLo = 0U;
  c21_info[113].mFileTimeHi = 0U;
  c21_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c21_info[114].name = "eml_is_float_class";
  c21_info[114].dominantType = "char";
  c21_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c21_info[114].fileTimeLo = 1286840382U;
  c21_info[114].fileTimeHi = 0U;
  c21_info[114].mFileTimeLo = 0U;
  c21_info[114].mFileTimeHi = 0U;
  c21_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c21_info[115].name = "mtimes";
  c21_info[115].dominantType = "double";
  c21_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[115].fileTimeLo = 1289541292U;
  c21_info[115].fileTimeHi = 0U;
  c21_info[115].mFileTimeLo = 0U;
  c21_info[115].mFileTimeHi = 0U;
  c21_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c21_info[116].name = "eml_warning";
  c21_info[116].dominantType = "char";
  c21_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c21_info[116].fileTimeLo = 1286840402U;
  c21_info[116].fileTimeHi = 0U;
  c21_info[116].mFileTimeLo = 0U;
  c21_info[116].mFileTimeHi = 0U;
  c21_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c21_info[117].name = "isnan";
  c21_info[117].dominantType = "double";
  c21_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c21_info[117].fileTimeLo = 1286840360U;
  c21_info[117].fileTimeHi = 0U;
  c21_info[117].mFileTimeLo = 0U;
  c21_info[117].mFileTimeHi = 0U;
  c21_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c21_info[118].name = "eps";
  c21_info[118].dominantType = "char";
  c21_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c21_info[118].fileTimeLo = 1326749596U;
  c21_info[118].fileTimeHi = 0U;
  c21_info[118].mFileTimeLo = 0U;
  c21_info[118].mFileTimeHi = 0U;
  c21_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c21_info[119].name = "eml_flt2str";
  c21_info[119].dominantType = "double";
  c21_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c21_info[119].fileTimeLo = 1309472796U;
  c21_info[119].fileTimeHi = 0U;
  c21_info[119].mFileTimeLo = 0U;
  c21_info[119].mFileTimeHi = 0U;
  c21_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c21_info[120].name = "char";
  c21_info[120].dominantType = "double";
  c21_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c21_info[120].fileTimeLo = 1319751568U;
  c21_info[120].fileTimeHi = 0U;
  c21_info[120].mFileTimeLo = 0U;
  c21_info[120].mFileTimeHi = 0U;
  c21_info[121].context = "";
  c21_info[121].name = "mtimes";
  c21_info[121].dominantType = "double";
  c21_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[121].fileTimeLo = 1289541292U;
  c21_info[121].fileTimeHi = 0U;
  c21_info[121].mFileTimeLo = 0U;
  c21_info[121].mFileTimeHi = 0U;
  c21_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[122].name = "eml_index_class";
  c21_info[122].dominantType = "";
  c21_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[122].fileTimeLo = 1323192178U;
  c21_info[122].fileTimeHi = 0U;
  c21_info[122].mFileTimeLo = 0U;
  c21_info[122].mFileTimeHi = 0U;
  c21_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[123].name = "eml_scalar_eg";
  c21_info[123].dominantType = "double";
  c21_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[123].fileTimeLo = 1286840396U;
  c21_info[123].fileTimeHi = 0U;
  c21_info[123].mFileTimeLo = 0U;
  c21_info[123].mFileTimeHi = 0U;
  c21_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[124].name = "eml_xgemm";
  c21_info[124].dominantType = "char";
  c21_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c21_info[124].fileTimeLo = 1299098372U;
  c21_info[124].fileTimeHi = 0U;
  c21_info[124].mFileTimeLo = 0U;
  c21_info[124].mFileTimeHi = 0U;
  c21_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c21_info[125].name = "eml_blas_inline";
  c21_info[125].dominantType = "";
  c21_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c21_info[125].fileTimeLo = 1299098368U;
  c21_info[125].fileTimeHi = 0U;
  c21_info[125].mFileTimeLo = 0U;
  c21_info[125].mFileTimeHi = 0U;
  c21_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c21_info[126].name = "mtimes";
  c21_info[126].dominantType = "double";
  c21_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[126].fileTimeLo = 1289541292U;
  c21_info[126].fileTimeHi = 0U;
  c21_info[126].mFileTimeLo = 0U;
  c21_info[126].mFileTimeHi = 0U;
  c21_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c21_info[127].name = "eml_index_class";
  c21_info[127].dominantType = "";
  c21_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[127].fileTimeLo = 1323192178U;
  c21_info[127].fileTimeHi = 0U;
  c21_info[127].mFileTimeLo = 0U;
  c21_info[127].mFileTimeHi = 0U;
}

static void c21_c_info_helper(c21_ResolvedFunctionInfo c21_info[130])
{
  c21_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c21_info[128].name = "eml_scalar_eg";
  c21_info[128].dominantType = "double";
  c21_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[128].fileTimeLo = 1286840396U;
  c21_info[128].fileTimeHi = 0U;
  c21_info[128].mFileTimeLo = 0U;
  c21_info[128].mFileTimeHi = 0U;
  c21_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c21_info[129].name = "eml_refblas_xgemm";
  c21_info[129].dominantType = "char";
  c21_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c21_info[129].fileTimeLo = 1299098374U;
  c21_info[129].fileTimeHi = 0U;
  c21_info[129].mFileTimeLo = 0U;
  c21_info[129].mFileTimeHi = 0U;
}

static void c21_invNxN(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, real_T c21_x[36], real_T c21_y[36])
{
  int32_T c21_i35;
  int32_T c21_info;
  int32_T c21_ipiv[6];
  int32_T c21_i36;
  int32_T c21_p[6];
  int32_T c21_k;
  real_T c21_b_k;
  int32_T c21_ipk;
  int32_T c21_a;
  real_T c21_b;
  int32_T c21_b_a;
  real_T c21_b_b;
  int32_T c21_idx;
  real_T c21_flt;
  boolean_T c21_b_p;
  int32_T c21_pipk;
  int32_T c21_c_k;
  int32_T c21_d_k;
  int32_T c21_c;
  int32_T c21_e_k;
  boolean_T c21_overflow;
  int32_T c21_j;
  int32_T c21_b_j;
  int32_T c21_c_a;
  int32_T c21_i37;
  boolean_T c21_b_overflow;
  int32_T c21_i;
  int32_T c21_b_i;
  real_T c21_d_a;
  real_T c21_c_b;
  real_T c21_b_y;
  int32_T c21_i38;
  real_T c21_b_x[36];
  for (c21_i35 = 0; c21_i35 < 36; c21_i35++) {
    c21_y[c21_i35] = 0.0;
  }

  c21_b_eml_matlab_zgetrf(chartInstance, c21_x, c21_ipiv, &c21_info);
  for (c21_i36 = 0; c21_i36 < 6; c21_i36++) {
    c21_p[c21_i36] = 1 + c21_i36;
  }

  for (c21_k = 0; c21_k < 5; c21_k++) {
    c21_b_k = 1.0 + (real_T)c21_k;
    c21_ipk = c21_ipiv[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c21_b_k), 1, 6, 1, 0) - 1];
    c21_a = c21_ipk;
    c21_b = c21_b_k;
    c21_b_a = c21_a;
    c21_b_b = c21_b;
    c21_idx = c21_b_a;
    c21_flt = c21_b_b;
    c21_b_p = ((real_T)c21_idx > c21_flt);
    if (c21_b_p) {
      c21_pipk = c21_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c21_ipk), 1, 6, 1, 0) - 1];
      c21_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c21_ipk), 1, 6, 1, 0) - 1] = c21_p[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c21_b_k),
        1, 6, 1, 0) - 1];
      c21_p[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c21_b_k), 1, 6, 1, 0) - 1] = c21_pipk;
    }
  }

  for (c21_c_k = 1; c21_c_k < 7; c21_c_k++) {
    c21_d_k = c21_c_k;
    c21_c = c21_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c21_d_k), 1, 6, 1, 0) - 1];
    c21_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c21_d_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_c), 1, 6, 2, 0) - 1)) -
      1] = 1.0;
    c21_e_k = c21_d_k;
    c21_overflow = FALSE;
    if (c21_overflow) {
      c21_check_forloop_overflow_error(chartInstance, c21_overflow);
    }

    for (c21_j = c21_e_k; c21_j < 7; c21_j++) {
      c21_b_j = c21_j;
      if (c21_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c21_b_j), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_c), 1, 6, 2, 0) - 1)) -
          1] != 0.0) {
        c21_c_a = c21_b_j;
        c21_i37 = c21_c_a;
        c21_b_overflow = FALSE;
        if (c21_b_overflow) {
          c21_check_forloop_overflow_error(chartInstance, c21_b_overflow);
        }

        for (c21_i = c21_i37 + 1; c21_i < 7; c21_i++) {
          c21_b_i = c21_i;
          c21_d_a = c21_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c21_b_j), 1, 6, 1, 0) + 6 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c21_c), 1, 6, 2, 0) - 1)) - 1];
          c21_c_b = c21_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c21_b_i), 1, 6, 1, 0) + 6 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c21_b_j), 1, 6, 2, 0) - 1)) - 1];
          c21_b_y = c21_d_a * c21_c_b;
          c21_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c21_b_i), 1, 6, 1, 0) + 6 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c21_c), 1, 6, 2, 0) - 1)) - 1] = c21_y
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c21_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_c), 1, 6, 2, 0)
               - 1)) - 1] - c21_b_y;
        }
      }
    }
  }

  for (c21_i38 = 0; c21_i38 < 36; c21_i38++) {
    c21_b_x[c21_i38] = c21_x[c21_i38];
  }

  c21_b_eml_xtrsm(chartInstance, c21_b_x, c21_y);
}

static void c21_realmin(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *
  chartInstance)
{
}

static void c21_eps(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
                    *chartInstance)
{
}

static void c21_eml_matlab_zgetrf
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], real_T c21_b_A[36], int32_T c21_ipiv[6], int32_T *c21_info)
{
  int32_T c21_i39;
  for (c21_i39 = 0; c21_i39 < 36; c21_i39++) {
    c21_b_A[c21_i39] = c21_A[c21_i39];
  }

  c21_b_eml_matlab_zgetrf(chartInstance, c21_b_A, c21_ipiv, c21_info);
}

static void c21_check_forloop_overflow_error
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   boolean_T c21_overflow)
{
  int32_T c21_i40;
  static char_T c21_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c21_u[34];
  const mxArray *c21_y = NULL;
  int32_T c21_i41;
  static char_T c21_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c21_b_u[23];
  const mxArray *c21_b_y = NULL;
  if (!c21_overflow) {
  } else {
    for (c21_i40 = 0; c21_i40 < 34; c21_i40++) {
      c21_u[c21_i40] = c21_cv1[c21_i40];
    }

    c21_y = NULL;
    sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c21_i41 = 0; c21_i41 < 23; c21_i41++) {
      c21_b_u[c21_i41] = c21_cv2[c21_i41];
    }

    c21_b_y = NULL;
    sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c21_y, 14, c21_b_y));
  }
}

static void c21_eml_xger(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, int32_T c21_m, int32_T c21_n, real_T c21_alpha1, int32_T
  c21_ix0, int32_T c21_iy0, real_T c21_A[36], int32_T c21_ia0, real_T c21_b_A[36])
{
  int32_T c21_i42;
  for (c21_i42 = 0; c21_i42 < 36; c21_i42++) {
    c21_b_A[c21_i42] = c21_A[c21_i42];
  }

  c21_b_eml_xger(chartInstance, c21_m, c21_n, c21_alpha1, c21_ix0, c21_iy0,
                 c21_b_A, c21_ia0);
}

static void c21_eml_xtrsm
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], real_T c21_B[36], real_T c21_b_B[36])
{
  int32_T c21_i43;
  int32_T c21_i44;
  real_T c21_b_A[36];
  for (c21_i43 = 0; c21_i43 < 36; c21_i43++) {
    c21_b_B[c21_i43] = c21_B[c21_i43];
  }

  for (c21_i44 = 0; c21_i44 < 36; c21_i44++) {
    c21_b_A[c21_i44] = c21_A[c21_i44];
  }

  c21_b_eml_xtrsm(chartInstance, c21_b_A, c21_b_B);
}

static real_T c21_norm(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, real_T c21_x[36])
{
  real_T c21_y;
  int32_T c21_j;
  real_T c21_b_j;
  real_T c21_s;
  int32_T c21_i;
  real_T c21_b_i;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_b_y;
  real_T c21_d_x;
  boolean_T c21_b;
  boolean_T exitg1;
  c21_y = 0.0;
  c21_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c21_j < 6)) {
    c21_b_j = 1.0 + (real_T)c21_j;
    c21_s = 0.0;
    for (c21_i = 0; c21_i < 6; c21_i++) {
      c21_b_i = 1.0 + (real_T)c21_i;
      c21_b_x = c21_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c21_b_i), 1, 6, 1, 0) + 6 * ((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c21_b_j),
        1, 6, 2, 0) - 1)) - 1];
      c21_c_x = c21_b_x;
      c21_b_y = muDoubleScalarAbs(c21_c_x);
      c21_s += c21_b_y;
    }

    c21_d_x = c21_s;
    c21_b = muDoubleScalarIsNaN(c21_d_x);
    if (c21_b) {
      c21_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c21_s > c21_y) {
        c21_y = c21_s;
      }

      c21_j++;
    }
  }

  return c21_y;
}

static void c21_eml_warning
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c21_i45;
  static char_T c21_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c21_u[27];
  const mxArray *c21_y = NULL;
  for (c21_i45 = 0; c21_i45 < 27; c21_i45++) {
    c21_u[c21_i45] = c21_varargin_1[c21_i45];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c21_y));
}

static void c21_b_eml_warning
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   char_T c21_varargin_2[14])
{
  int32_T c21_i46;
  static char_T c21_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c21_u[33];
  const mxArray *c21_y = NULL;
  int32_T c21_i47;
  char_T c21_b_u[14];
  const mxArray *c21_b_y = NULL;
  for (c21_i46 = 0; c21_i46 < 33; c21_i46++) {
    c21_u[c21_i46] = c21_varargin_1[c21_i46];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  for (c21_i47 = 0; c21_i47 < 14; c21_i47++) {
    c21_b_u[c21_i47] = c21_varargin_2[c21_i47];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c21_y, 14, c21_b_y));
}

static void c21_eml_scalar_eg
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void c21_d_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_sprintf, const char_T *c21_identifier, char_T c21_y[14])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_sprintf), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_sprintf);
}

static void c21_e_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, char_T c21_y[14])
{
  char_T c21_cv3[14];
  int32_T c21_i48;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c21_i48 = 0; c21_i48 < 14; c21_i48++) {
    c21_y[c21_i48] = c21_cv3[c21_i48];
  }

  sf_mex_destroy(&c21_u);
}

static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static int32_T c21_f_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i49;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i49, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i49;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_g_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_b_is_active_c21_JointSpaceControl_CorrectFalseCombo, const
   char_T *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_JointSpaceControl_CorrectFalseCombo), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_JointSpaceControl_CorrectFalseCombo);
  return c21_y;
}

static uint8_T c21_h_emlrt_marshallIn
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_eml_matlab_zgetrf
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], int32_T c21_ipiv[6], int32_T *c21_info)
{
  int32_T c21_i50;
  int32_T c21_j;
  int32_T c21_b_j;
  int32_T c21_a;
  int32_T c21_jm1;
  int32_T c21_b;
  int32_T c21_mmj;
  int32_T c21_b_a;
  int32_T c21_c;
  int32_T c21_b_b;
  int32_T c21_jj;
  int32_T c21_c_a;
  int32_T c21_jp1j;
  int32_T c21_d_a;
  int32_T c21_b_c;
  int32_T c21_n;
  int32_T c21_ix0;
  int32_T c21_b_n;
  int32_T c21_b_ix0;
  int32_T c21_c_n;
  int32_T c21_c_ix0;
  int32_T c21_idxmax;
  int32_T c21_ix;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_y;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_b_y;
  real_T c21_smax;
  int32_T c21_d_n;
  int32_T c21_c_b;
  int32_T c21_d_b;
  boolean_T c21_overflow;
  int32_T c21_k;
  int32_T c21_b_k;
  int32_T c21_e_a;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_c_y;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_d_y;
  real_T c21_s;
  int32_T c21_f_a;
  int32_T c21_jpiv_offset;
  int32_T c21_g_a;
  int32_T c21_e_b;
  int32_T c21_jpiv;
  int32_T c21_h_a;
  int32_T c21_f_b;
  int32_T c21_c_c;
  int32_T c21_g_b;
  int32_T c21_jrow;
  int32_T c21_i_a;
  int32_T c21_h_b;
  int32_T c21_jprow;
  int32_T c21_d_ix0;
  int32_T c21_iy0;
  int32_T c21_e_ix0;
  int32_T c21_b_iy0;
  int32_T c21_f_ix0;
  int32_T c21_c_iy0;
  int32_T c21_b_ix;
  int32_T c21_iy;
  int32_T c21_c_k;
  real_T c21_temp;
  int32_T c21_j_a;
  int32_T c21_k_a;
  int32_T c21_b_jp1j;
  int32_T c21_l_a;
  int32_T c21_d_c;
  int32_T c21_m_a;
  int32_T c21_i_b;
  int32_T c21_i51;
  int32_T c21_n_a;
  int32_T c21_j_b;
  int32_T c21_o_a;
  int32_T c21_k_b;
  boolean_T c21_b_overflow;
  int32_T c21_i;
  int32_T c21_b_i;
  real_T c21_k_x;
  real_T c21_e_y;
  real_T c21_z;
  int32_T c21_l_b;
  int32_T c21_e_c;
  int32_T c21_p_a;
  int32_T c21_f_c;
  int32_T c21_q_a;
  int32_T c21_g_c;
  int32_T c21_m;
  int32_T c21_e_n;
  int32_T c21_g_ix0;
  int32_T c21_d_iy0;
  int32_T c21_ia0;
  real_T c21_d1;
  c21_realmin(chartInstance);
  c21_eps(chartInstance);
  for (c21_i50 = 0; c21_i50 < 6; c21_i50++) {
    c21_ipiv[c21_i50] = 1 + c21_i50;
  }

  *c21_info = 0;
  for (c21_j = 1; c21_j < 6; c21_j++) {
    c21_b_j = c21_j;
    c21_a = c21_b_j - 1;
    c21_jm1 = c21_a;
    c21_b = c21_b_j;
    c21_mmj = 6 - c21_b;
    c21_b_a = c21_jm1;
    c21_c = c21_b_a * 7;
    c21_b_b = c21_c + 1;
    c21_jj = c21_b_b;
    c21_c_a = c21_jj + 1;
    c21_jp1j = c21_c_a;
    c21_d_a = c21_mmj;
    c21_b_c = c21_d_a;
    c21_n = c21_b_c + 1;
    c21_ix0 = c21_jj;
    c21_b_n = c21_n;
    c21_b_ix0 = c21_ix0;
    c21_c_n = c21_b_n;
    c21_c_ix0 = c21_b_ix0;
    if (c21_c_n < 1) {
      c21_idxmax = 0;
    } else {
      c21_idxmax = 1;
      if (c21_c_n > 1) {
        c21_ix = c21_c_ix0;
        c21_x = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c21_ix), 1, 36, 1, 0) - 1];
        c21_b_x = c21_x;
        c21_c_x = c21_b_x;
        c21_y = muDoubleScalarAbs(c21_c_x);
        c21_d_x = 0.0;
        c21_e_x = c21_d_x;
        c21_b_y = muDoubleScalarAbs(c21_e_x);
        c21_smax = c21_y + c21_b_y;
        c21_d_n = c21_c_n;
        c21_c_b = c21_d_n;
        c21_d_b = c21_c_b;
        if (2 > c21_d_b) {
          c21_overflow = FALSE;
        } else {
          c21_overflow = (c21_d_b > 2147483646);
        }

        if (c21_overflow) {
          c21_check_forloop_overflow_error(chartInstance, c21_overflow);
        }

        for (c21_k = 2; c21_k <= c21_d_n; c21_k++) {
          c21_b_k = c21_k;
          c21_e_a = c21_ix + 1;
          c21_ix = c21_e_a;
          c21_f_x = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c21_ix), 1, 36, 1, 0) - 1];
          c21_g_x = c21_f_x;
          c21_h_x = c21_g_x;
          c21_c_y = muDoubleScalarAbs(c21_h_x);
          c21_i_x = 0.0;
          c21_j_x = c21_i_x;
          c21_d_y = muDoubleScalarAbs(c21_j_x);
          c21_s = c21_c_y + c21_d_y;
          if (c21_s > c21_smax) {
            c21_idxmax = c21_b_k;
            c21_smax = c21_s;
          }
        }
      }
    }

    c21_f_a = c21_idxmax - 1;
    c21_jpiv_offset = c21_f_a;
    c21_g_a = c21_jj;
    c21_e_b = c21_jpiv_offset;
    c21_jpiv = c21_g_a + c21_e_b;
    if (c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c21_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c21_jpiv_offset != 0) {
        c21_h_a = c21_b_j;
        c21_f_b = c21_jpiv_offset;
        c21_c_c = c21_h_a + c21_f_b;
        c21_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c21_b_j), 1, 6, 1, 0) - 1] = c21_c_c;
        c21_g_b = c21_jm1 + 1;
        c21_jrow = c21_g_b;
        c21_i_a = c21_jrow;
        c21_h_b = c21_jpiv_offset;
        c21_jprow = c21_i_a + c21_h_b;
        c21_d_ix0 = c21_jrow;
        c21_iy0 = c21_jprow;
        c21_e_ix0 = c21_d_ix0;
        c21_b_iy0 = c21_iy0;
        c21_f_ix0 = c21_e_ix0;
        c21_c_iy0 = c21_b_iy0;
        c21_b_ix = c21_f_ix0;
        c21_iy = c21_c_iy0;
        for (c21_c_k = 1; c21_c_k < 7; c21_c_k++) {
          c21_temp = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c21_b_ix), 1, 36, 1, 0) - 1];
          c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_b_ix), 1, 36, 1, 0) - 1] =
            c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_iy), 1, 36, 1, 0) - 1];
          c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_iy), 1, 36, 1, 0) - 1] = c21_temp;
          c21_j_a = c21_b_ix + 6;
          c21_b_ix = c21_j_a;
          c21_k_a = c21_iy + 6;
          c21_iy = c21_k_a;
        }
      }

      c21_b_jp1j = c21_jp1j;
      c21_l_a = c21_mmj;
      c21_d_c = c21_l_a;
      c21_m_a = c21_jp1j;
      c21_i_b = c21_d_c - 1;
      c21_i51 = c21_m_a + c21_i_b;
      c21_n_a = c21_b_jp1j;
      c21_j_b = c21_i51;
      c21_o_a = c21_n_a;
      c21_k_b = c21_j_b;
      if (c21_o_a > c21_k_b) {
        c21_b_overflow = FALSE;
      } else {
        c21_b_overflow = (c21_k_b > 2147483646);
      }

      if (c21_b_overflow) {
        c21_check_forloop_overflow_error(chartInstance, c21_b_overflow);
      }

      for (c21_i = c21_b_jp1j; c21_i <= c21_i51; c21_i++) {
        c21_b_i = c21_i;
        c21_k_x = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c21_b_i), 1, 36, 1, 0) - 1];
        c21_e_y = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c21_jj), 1, 36, 1, 0) - 1];
        c21_z = c21_k_x / c21_e_y;
        c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c21_b_i), 1, 36, 1, 0) - 1] = c21_z;
      }
    } else {
      *c21_info = c21_b_j;
    }

    c21_l_b = c21_b_j;
    c21_e_c = 6 - c21_l_b;
    c21_p_a = c21_jj;
    c21_f_c = c21_p_a;
    c21_q_a = c21_jj;
    c21_g_c = c21_q_a;
    c21_m = c21_mmj;
    c21_e_n = c21_e_c;
    c21_g_ix0 = c21_jp1j;
    c21_d_iy0 = c21_f_c + 6;
    c21_ia0 = c21_g_c + 7;
    c21_d1 = -1.0;
    c21_b_eml_xger(chartInstance, c21_m, c21_e_n, c21_d1, c21_g_ix0, c21_d_iy0,
                   c21_A, c21_ia0);
  }

  if (*c21_info == 0) {
    if (!(c21_A[35] != 0.0)) {
      *c21_info = 6;
    }
  }
}

static void c21_b_eml_xger
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   int32_T c21_m, int32_T c21_n, real_T c21_alpha1, int32_T c21_ix0, int32_T
   c21_iy0, real_T c21_A[36], int32_T c21_ia0)
{
  int32_T c21_b_m;
  int32_T c21_b_n;
  real_T c21_b_alpha1;
  int32_T c21_b_ix0;
  int32_T c21_b_iy0;
  int32_T c21_b_ia0;
  int32_T c21_c_m;
  int32_T c21_c_n;
  real_T c21_c_alpha1;
  int32_T c21_c_ix0;
  int32_T c21_c_iy0;
  int32_T c21_c_ia0;
  int32_T c21_d_m;
  int32_T c21_d_n;
  real_T c21_d_alpha1;
  int32_T c21_d_ix0;
  int32_T c21_d_iy0;
  int32_T c21_d_ia0;
  int32_T c21_ixstart;
  int32_T c21_a;
  int32_T c21_jA;
  int32_T c21_jy;
  int32_T c21_e_n;
  int32_T c21_b;
  int32_T c21_b_b;
  boolean_T c21_overflow;
  int32_T c21_j;
  real_T c21_yjy;
  real_T c21_temp;
  int32_T c21_ix;
  int32_T c21_c_b;
  int32_T c21_i52;
  int32_T c21_b_a;
  int32_T c21_d_b;
  int32_T c21_i53;
  int32_T c21_c_a;
  int32_T c21_e_b;
  int32_T c21_d_a;
  int32_T c21_f_b;
  boolean_T c21_b_overflow;
  int32_T c21_ijA;
  int32_T c21_b_ijA;
  int32_T c21_e_a;
  int32_T c21_f_a;
  int32_T c21_g_a;
  c21_b_m = c21_m;
  c21_b_n = c21_n;
  c21_b_alpha1 = c21_alpha1;
  c21_b_ix0 = c21_ix0;
  c21_b_iy0 = c21_iy0;
  c21_b_ia0 = c21_ia0;
  c21_c_m = c21_b_m;
  c21_c_n = c21_b_n;
  c21_c_alpha1 = c21_b_alpha1;
  c21_c_ix0 = c21_b_ix0;
  c21_c_iy0 = c21_b_iy0;
  c21_c_ia0 = c21_b_ia0;
  c21_d_m = c21_c_m;
  c21_d_n = c21_c_n;
  c21_d_alpha1 = c21_c_alpha1;
  c21_d_ix0 = c21_c_ix0;
  c21_d_iy0 = c21_c_iy0;
  c21_d_ia0 = c21_c_ia0;
  if (c21_d_alpha1 == 0.0) {
  } else {
    c21_ixstart = c21_d_ix0;
    c21_a = c21_d_ia0 - 1;
    c21_jA = c21_a;
    c21_jy = c21_d_iy0;
    c21_e_n = c21_d_n;
    c21_b = c21_e_n;
    c21_b_b = c21_b;
    if (1 > c21_b_b) {
      c21_overflow = FALSE;
    } else {
      c21_overflow = (c21_b_b > 2147483646);
    }

    if (c21_overflow) {
      c21_check_forloop_overflow_error(chartInstance, c21_overflow);
    }

    for (c21_j = 1; c21_j <= c21_e_n; c21_j++) {
      c21_yjy = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c21_jy), 1, 36, 1, 0) - 1];
      if (c21_yjy != 0.0) {
        c21_temp = c21_yjy * c21_d_alpha1;
        c21_ix = c21_ixstart;
        c21_c_b = c21_jA + 1;
        c21_i52 = c21_c_b;
        c21_b_a = c21_d_m;
        c21_d_b = c21_jA;
        c21_i53 = c21_b_a + c21_d_b;
        c21_c_a = c21_i52;
        c21_e_b = c21_i53;
        c21_d_a = c21_c_a;
        c21_f_b = c21_e_b;
        if (c21_d_a > c21_f_b) {
          c21_b_overflow = FALSE;
        } else {
          c21_b_overflow = (c21_f_b > 2147483646);
        }

        if (c21_b_overflow) {
          c21_check_forloop_overflow_error(chartInstance, c21_b_overflow);
        }

        for (c21_ijA = c21_i52; c21_ijA <= c21_i53; c21_ijA++) {
          c21_b_ijA = c21_ijA;
          c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_b_ijA), 1, 36, 1, 0) - 1] =
            c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_b_ijA), 1, 36, 1, 0) - 1] +
            c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_ix), 1, 36, 1, 0) - 1] * c21_temp;
          c21_e_a = c21_ix + 1;
          c21_ix = c21_e_a;
        }
      }

      c21_f_a = c21_jy + 6;
      c21_jy = c21_f_a;
      c21_g_a = c21_jA + 6;
      c21_jA = c21_g_a;
    }
  }
}

static void c21_b_eml_xtrsm
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance,
   real_T c21_A[36], real_T c21_B[36])
{
  int32_T c21_j;
  int32_T c21_b_j;
  int32_T c21_a;
  int32_T c21_c;
  int32_T c21_b;
  int32_T c21_b_c;
  int32_T c21_b_b;
  int32_T c21_jBcol;
  int32_T c21_k;
  int32_T c21_b_k;
  int32_T c21_b_a;
  int32_T c21_c_c;
  int32_T c21_c_b;
  int32_T c21_d_c;
  int32_T c21_d_b;
  int32_T c21_kAcol;
  int32_T c21_c_a;
  int32_T c21_e_b;
  int32_T c21_e_c;
  int32_T c21_d_a;
  int32_T c21_f_b;
  int32_T c21_f_c;
  int32_T c21_e_a;
  int32_T c21_g_b;
  int32_T c21_g_c;
  int32_T c21_f_a;
  int32_T c21_h_b;
  int32_T c21_h_c;
  real_T c21_x;
  real_T c21_y;
  real_T c21_z;
  int32_T c21_g_a;
  int32_T c21_i54;
  int32_T c21_i_b;
  int32_T c21_j_b;
  boolean_T c21_overflow;
  int32_T c21_i;
  int32_T c21_b_i;
  int32_T c21_h_a;
  int32_T c21_k_b;
  int32_T c21_i_c;
  int32_T c21_i_a;
  int32_T c21_l_b;
  int32_T c21_j_c;
  int32_T c21_j_a;
  int32_T c21_m_b;
  int32_T c21_k_c;
  int32_T c21_k_a;
  int32_T c21_n_b;
  int32_T c21_l_c;
  for (c21_j = 1; c21_j < 7; c21_j++) {
    c21_b_j = c21_j;
    c21_a = c21_b_j;
    c21_c = c21_a;
    c21_b = c21_c - 1;
    c21_b_c = 6 * c21_b;
    c21_b_b = c21_b_c;
    c21_jBcol = c21_b_b;
    for (c21_k = 6; c21_k > 0; c21_k--) {
      c21_b_k = c21_k;
      c21_b_a = c21_b_k;
      c21_c_c = c21_b_a;
      c21_c_b = c21_c_c - 1;
      c21_d_c = 6 * c21_c_b;
      c21_d_b = c21_d_c;
      c21_kAcol = c21_d_b;
      c21_c_a = c21_b_k;
      c21_e_b = c21_jBcol;
      c21_e_c = c21_c_a + c21_e_b;
      if (c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_e_c), 1, 36, 1, 0) - 1] != 0.0) {
        c21_d_a = c21_b_k;
        c21_f_b = c21_jBcol;
        c21_f_c = c21_d_a + c21_f_b;
        c21_e_a = c21_b_k;
        c21_g_b = c21_jBcol;
        c21_g_c = c21_e_a + c21_g_b;
        c21_f_a = c21_b_k;
        c21_h_b = c21_kAcol;
        c21_h_c = c21_f_a + c21_h_b;
        c21_x = c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c21_g_c), 1, 36, 1, 0) - 1];
        c21_y = c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c21_h_c), 1, 36, 1, 0) - 1];
        c21_z = c21_x / c21_y;
        c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c21_f_c), 1, 36, 1, 0) - 1] = c21_z;
        c21_g_a = c21_b_k - 1;
        c21_i54 = c21_g_a;
        c21_i_b = c21_i54;
        c21_j_b = c21_i_b;
        if (1 > c21_j_b) {
          c21_overflow = FALSE;
        } else {
          c21_overflow = (c21_j_b > 2147483646);
        }

        if (c21_overflow) {
          c21_check_forloop_overflow_error(chartInstance, c21_overflow);
        }

        for (c21_i = 1; c21_i <= c21_i54; c21_i++) {
          c21_b_i = c21_i;
          c21_h_a = c21_b_i;
          c21_k_b = c21_jBcol;
          c21_i_c = c21_h_a + c21_k_b;
          c21_i_a = c21_b_i;
          c21_l_b = c21_jBcol;
          c21_j_c = c21_i_a + c21_l_b;
          c21_j_a = c21_b_k;
          c21_m_b = c21_jBcol;
          c21_k_c = c21_j_a + c21_m_b;
          c21_k_a = c21_b_i;
          c21_n_b = c21_kAcol;
          c21_l_c = c21_k_a + c21_n_b;
          c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_i_c), 1, 36, 1, 0) - 1] =
            c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_j_c), 1, 36, 1, 0) - 1] -
            c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_k_c), 1, 36, 1, 0) - 1] *
            c21_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c21_l_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info
  (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
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

void sf_c21_JointSpaceControl_CorrectFalseCombo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3615960916U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2647697163U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(75126957U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(571541602U);
}

mxArray *sf_c21_JointSpaceControl_CorrectFalseCombo_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EP25PSj0Mu2BF7JxkWiFCB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(6);
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
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c21_JointSpaceControl_CorrectFalseCombo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c21_JointSpaceControl_CorrectFalseCombo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"dq\",},{M[8],M[0],T\"is_active_c21_JointSpaceControl_CorrectFalseCombo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_JointSpaceControl_CorrectFalseCombo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
    chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectFalseComboMachineNumber_,
           21,
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
            (_JointSpaceControl_CorrectFalseComboMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_CorrectFalseComboMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_CorrectFalseComboMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"J_a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dq");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dX");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,198);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)
            c21_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c21_J_a)[36];
          real_T (*c21_dq)[6];
          real_T (*c21_dX)[6];
          c21_dX = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c21_dq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c21_J_a = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c21_J_a);
          _SFD_SET_DATA_VALUE_PTR(1U, *c21_dq);
          _SFD_SET_DATA_VALUE_PTR(2U, *c21_dX);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_CorrectFalseComboMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "0vOWprsEaZVE9kKbXu9tCG";
}

static void sf_opaque_initialize_c21_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
  initialize_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c21_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  enable_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c21_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  disable_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c21_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  sf_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c21_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c21_JointSpaceControl_CorrectFalseCombo();/* state var info */
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

extern void sf_internal_set_sim_state_c21_JointSpaceControl_CorrectFalseCombo
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c21_JointSpaceControl_CorrectFalseCombo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c21_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  return sf_internal_get_sim_state_c21_JointSpaceControl_CorrectFalseCombo(S);
}

static void sf_opaque_set_sim_state_c21_JointSpaceControl_CorrectFalseCombo
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c21_JointSpaceControl_CorrectFalseCombo(S, st);
}

static void sf_opaque_terminate_c21_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectFalseCombo_optimization_info();
    }

    finalize_c21_JointSpaceControl_CorrectFalseCombo
      ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_JointSpaceControl_CorrectFalseCombo
    ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_JointSpaceControl_CorrectFalseCombo
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_JointSpaceControl_CorrectFalseCombo
      ((SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_JointSpaceControl_CorrectFalseCombo(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectFalseCombo_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,21,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3577215140U));
  ssSetChecksum1(S,(896820752U));
  ssSetChecksum2(S,(2517811983U));
  ssSetChecksum3(S,(259155089U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    utMalloc(sizeof(SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc21_JointSpaceControl_CorrectFalseComboInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c21_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_JointSpaceControl_CorrectFalseCombo;
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

void c21_JointSpaceControl_CorrectFalseCombo_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_JointSpaceControl_CorrectFalseCombo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_JointSpaceControl_CorrectFalseCombo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
