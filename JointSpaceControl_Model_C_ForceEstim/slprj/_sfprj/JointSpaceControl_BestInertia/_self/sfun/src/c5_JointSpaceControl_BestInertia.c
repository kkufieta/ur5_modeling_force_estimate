/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_BestInertia_sfun.h"
#include "c5_JointSpaceControl_BestInertia.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_BestInertia_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[15] = { "r_11", "r_12", "r_13", "r_21",
  "r_22", "r_23", "r_31", "r_32", "r_33", "nargin", "nargout", "R", "theta",
  "phi", "psi" };

/* Function Declarations */
static void initialize_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initialize_params_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void enable_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void disable_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void set_sim_state_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_st);
static void finalize_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void sf_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initSimStructsc5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void registerMessagesc5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_psi, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[16]);
static real_T c5_mpower(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c5_a);
static void c5_eml_scalar_eg(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance);
static void c5_eml_error(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance);
static real_T c5_atan2(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c5_y, real_T c5_x);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_b_is_active_c5_JointSpaceControl_BestInertia, const char_T
   *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_JointSpaceControl_BestInertia = 0U;
}

static void initialize_params_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void enable_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  uint8_T c5_d_hoistedGlobal;
  uint8_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T *c5_phi;
  real_T *c5_psi;
  real_T *c5_theta;
  c5_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_phi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(4), FALSE);
  c5_hoistedGlobal = *c5_phi;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_psi;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_theta;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal =
    chartInstance->c5_is_active_c5_JointSpaceControl_BestInertia;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_phi;
  real_T *c5_psi;
  real_T *c5_theta;
  c5_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_phi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_phi = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "phi");
  *c5_psi = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "psi");
  *c5_theta = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    2)), "theta");
  chartInstance->c5_is_active_c5_JointSpaceControl_BestInertia =
    c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 3)),
    "is_active_c5_JointSpaceControl_BestInertia");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_JointSpaceControl_BestInertia(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void sf_c5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c5_i0;
  int32_T c5_i1;
  real_T c5_R[9];
  uint32_T c5_debug_family_var_map[15];
  real_T c5_r_11;
  real_T c5_r_12;
  real_T c5_r_13;
  real_T c5_r_21;
  real_T c5_r_22;
  real_T c5_r_23;
  real_T c5_r_31;
  real_T c5_r_32;
  real_T c5_r_33;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 3.0;
  real_T c5_theta;
  real_T c5_phi;
  real_T c5_psi;
  real_T c5_x;
  real_T c5_b_x;
  int32_T c5_i2;
  static char_T c5_varargin_1[21] = { 'r', '_', '3', '3', ' ', 'm', 'u', 's',
    't', ' ', 'b', 'e', ' ', '+', '1', ' ', 'o', 'r', ' ', '-', '1' };

  char_T c5_u[21];
  const mxArray *c5_y = NULL;
  int32_T c5_i3;
  static char_T c5_b_varargin_1[47] = { 'M', 'a', 'k', 'e', ' ', 's', 'u', 'r',
    'e', ' ', 't', 'h', 'a', 't', ' ', 't', 'h', 'e', ' ', 'v', 'a', 'l', 'u',
    'e', 's', ' ', 'a', 'r', 'e', ' ', 'a', 'l', 'm', 'o', 's', 't', ' ', 'e',
    'q', 'u', 'a', 'l', ' ', 'z', 'e', 'r', 'o' };

  char_T c5_b_u[47];
  const mxArray *c5_b_y = NULL;
  real_T *c5_b_theta;
  real_T *c5_b_phi;
  real_T *c5_b_psi;
  real_T (*c5_b_R)[9];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c5_b_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_phi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_theta, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_phi, 1U);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_R)[c5_i0], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_psi, 3U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    c5_R[c5_i1] = (*c5_b_R)[c5_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_11, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_12, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_13, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_21, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_22, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_23, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_31, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_32, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r_33, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_R, 11U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_theta, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_phi, 13U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_psi, 14U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_r_11 = c5_R[0];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_r_12 = c5_R[3];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_r_13 = c5_R[6];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_r_21 = c5_R[1];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_r_22 = c5_R[4];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_r_23 = c5_R[7];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_r_31 = c5_R[2];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_r_32 = c5_R[5];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_r_33 = c5_R[8];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c5_r_13 != 0.0)) {
    guard1 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, c5_r_23 != 0.0)) {
    guard1 = TRUE;
  } else {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
    guard2 = FALSE;
    if (CV_EML_COND(0, 1, 2, c5_r_13 == 0.0)) {
      if (CV_EML_COND(0, 1, 3, c5_r_23 == 0.0)) {
        CV_EML_MCDC(0, 1, 1, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
        if (CV_EML_IF(0, 1, 2, c5_r_33 == 1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
          c5_theta = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
          c5_phi = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
          c5_psi = c5_atan2(chartInstance, c5_r_11, c5_r_21) - c5_phi;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
          if (CV_EML_IF(0, 1, 3, c5_r_33 == -1.0)) {
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
            c5_theta = 3.1415926535897931;
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
            c5_phi = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
            c5_psi = -(c5_atan2(chartInstance, -c5_r_11, -c5_r_12) - c5_phi);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
            for (c5_i2 = 0; c5_i2 < 21; c5_i2++) {
              c5_u[c5_i2] = c5_varargin_1[c5_i2];
            }

            c5_y = NULL;
            sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1,
              21), FALSE);
            sf_mex_call_debug("error", 0U, 1U, 14, c5_y);
          }
        }
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 1, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
      for (c5_i3 = 0; c5_i3 < 47; c5_i3++) {
        c5_b_u[c5_i3] = c5_b_varargin_1[c5_i3];
      }

      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 47),
                    FALSE);
      sf_mex_call_debug("error", 0U, 1U, 14, c5_b_y);
    }
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
    c5_x = c5_mpower(chartInstance, c5_r_13) + c5_mpower(chartInstance, c5_r_23);
    c5_b_x = c5_x;
    if (c5_b_x < 0.0) {
      c5_eml_error(chartInstance);
    }

    c5_b_x = muDoubleScalarSqrt(c5_b_x);
    c5_theta = c5_atan2(chartInstance, c5_b_x, c5_r_33);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
    c5_phi = c5_atan2(chartInstance, c5_r_23, c5_r_13);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
    c5_psi = c5_atan2(chartInstance, c5_r_32, -c5_r_31);
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  *c5_b_theta = c5_theta;
  *c5_b_phi = c5_phi;
  *c5_b_psi = c5_psi;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_BestInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc5_JointSpaceControl_BestInertia
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_psi, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_psi), &c5_thisId);
  sf_mex_destroy(&c5_psi);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_psi;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c5_psi = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_psi), &c5_thisId);
  sf_mex_destroy(&c5_psi);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  real_T c5_b_inData[9];
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i4 = 0;
  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
      c5_b_inData[c5_i6 + c5_i4] = (*(real_T (*)[9])c5_inData)[c5_i6 + c5_i4];
    }

    c5_i4 += 3;
  }

  c5_i7 = 0;
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
      c5_u[c5_i9 + c5_i7] = c5_b_inData[c5_i9 + c5_i7];
    }

    c5_i7 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

const mxArray
  *sf_c5_JointSpaceControl_BestInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[16];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i10;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16), FALSE);
  for (c5_i10 = 0; c5_i10 < 16; c5_i10++) {
    c5_r0 = &c5_info[c5_i10];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i10);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i10);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[16])
{
  c5_info[0].context = "";
  c5_info[0].name = "mpower";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[0].fileTimeLo = 1286840442U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[1].name = "power";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[1].fileTimeLo = 1348213530U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[2].name = "eml_scalar_eg";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[2].fileTimeLo = 1286840396U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[3].name = "eml_scalexp_alloc";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[3].fileTimeLo = 1352446460U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[4].name = "floor";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[4].fileTimeLo = 1343851980U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[5].name = "eml_scalar_floor";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[5].fileTimeLo = 1286840326U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c5_info[6].name = "eml_scalar_eg";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[6].fileTimeLo = 1286840396U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c5_info[7].name = "mtimes";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[7].fileTimeLo = 1289541292U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context = "";
  c5_info[8].name = "sqrt";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[8].fileTimeLo = 1343851986U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[9].name = "eml_error";
  c5_info[9].dominantType = "char";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[9].fileTimeLo = 1343851958U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[10].name = "eml_scalar_sqrt";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c5_info[10].fileTimeLo = 1286840338U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context = "";
  c5_info[11].name = "atan2";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c5_info[11].fileTimeLo = 1343851972U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c5_info[12].name = "eml_scalar_eg";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[12].fileTimeLo = 1286840396U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c5_info[13].name = "eml_scalexp_alloc";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[13].fileTimeLo = 1352446460U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c5_info[14].name = "eml_scalar_atan2";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c5_info[14].fileTimeLo = 1286840320U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context = "";
  c5_info[15].name = "error";
  c5_info[15].dominantType = "char";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/error.m";
  c5_info[15].fileTimeLo = 1319751566U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
}

static real_T c5_mpower(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  real_T c5_d_a;
  real_T c5_e_a;
  real_T c5_b;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  c5_d_a = c5_ak;
  c5_eml_scalar_eg(chartInstance);
  c5_e_a = c5_d_a;
  c5_b = c5_d_a;
  return c5_e_a * c5_b;
}

static void c5_eml_scalar_eg(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance)
{
}

static void c5_eml_error(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance)
{
  int32_T c5_i11;
  static char_T c5_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[30];
  const mxArray *c5_y = NULL;
  int32_T c5_i12;
  static char_T c5_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c5_b_u[4];
  const mxArray *c5_b_y = NULL;
  for (c5_i11 = 0; c5_i11 < 30; c5_i11++) {
    c5_u[c5_i11] = c5_cv0[c5_i11];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c5_i12 = 0; c5_i12 < 4; c5_i12++) {
    c5_b_u[c5_i12] = c5_cv1[c5_i12];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c5_y, 14, c5_b_y));
}

static real_T c5_atan2(SFc5_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c5_y, real_T c5_x)
{
  real_T c5_b_y;
  real_T c5_b_x;
  c5_eml_scalar_eg(chartInstance);
  c5_b_y = c5_y;
  c5_b_x = c5_x;
  return muDoubleScalarAtan2(c5_b_y, c5_b_x);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i13;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i13, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i13;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_b_is_active_c5_JointSpaceControl_BestInertia, const char_T
   *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_JointSpaceControl_BestInertia), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_JointSpaceControl_BestInertia);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info
  (SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
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

void sf_c5_JointSpaceControl_BestInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1335705280U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3737228961U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1232991836U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3467364222U);
}

mxArray *sf_c5_JointSpaceControl_BestInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1p0p4Eb7X58iHa19kcFWWE");
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_JointSpaceControl_BestInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_JointSpaceControl_BestInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[6],T\"phi\",},{M[1],M[10],T\"psi\",},{M[1],M[9],T\"theta\",},{M[8],M[0],T\"is_active_c5_JointSpaceControl_BestInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_JointSpaceControl_BestInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_BestInertiaMachineNumber_,
           5,
           1,
           1,
           4,
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
            (_JointSpaceControl_BestInertiaMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_BestInertiaMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_BestInertiaMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"theta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"phi");
          _SFD_SET_DATA_PROPS(2,1,1,0,"R");
          _SFD_SET_DATA_PROPS(3,2,0,1,"psi");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,828);
        _SFD_CV_INIT_EML_IF(0,1,0,332,361,466,824);
        _SFD_CV_INIT_EML_IF(0,1,1,466,499,755,824);
        _SFD_CV_INIT_EML_IF(0,1,2,504,518,598,754);
        _SFD_CV_INIT_EML_IF(0,1,3,598,617,703,754);

        {
          static int condStart[] = { 336, 351 };

          static int condEnd[] = { 345, 360 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,335,361,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 474, 489 };

          static int condEnd[] = { 483, 498 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,473,499,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          real_T *c5_theta;
          real_T *c5_phi;
          real_T *c5_psi;
          real_T (*c5_R)[9];
          c5_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c5_phi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_theta);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_phi);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_R);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_psi);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_BestInertiaMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ABlhaC34JPN3XLi7nEwKB";
}

static void sf_opaque_initialize_c5_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_JointSpaceControl_BestInertiaInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
  initialize_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  enable_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  disable_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  sf_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_JointSpaceControl_BestInertia();/* state var info */
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

extern void sf_internal_set_sim_state_c5_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_JointSpaceControl_BestInertia();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c5_JointSpaceControl_BestInertia(S);
}

static void sf_opaque_set_sim_state_c5_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_JointSpaceControl_BestInertia(S, st);
}

static void sf_opaque_terminate_c5_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_BestInertia_optimization_info();
    }

    finalize_c5_JointSpaceControl_BestInertia
      ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_JointSpaceControl_BestInertia
    ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_JointSpaceControl_BestInertia(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_JointSpaceControl_BestInertia
      ((SFc5_JointSpaceControl_BestInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_BestInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4269235943U));
  ssSetChecksum1(S,(611276444U));
  ssSetChecksum2(S,(1750009705U));
  ssSetChecksum3(S,(4226135732U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_JointSpaceControl_BestInertia(SimStruct *S)
{
  SFc5_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc5_JointSpaceControl_BestInertiaInstanceStruct *)utMalloc
    (sizeof(SFc5_JointSpaceControl_BestInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc5_JointSpaceControl_BestInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_JointSpaceControl_BestInertia;
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

void c5_JointSpaceControl_BestInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_JointSpaceControl_BestInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_JointSpaceControl_BestInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
