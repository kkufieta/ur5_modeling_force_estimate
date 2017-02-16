/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectInertia_sfun.h"
#include "c8_JointSpaceControl_CorrectInertia.h"
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
static const char * c8_debug_family_names[20] = { "kx", "ky", "kz", "v", "s",
  "c", "r11", "r12", "r13", "r21", "r22", "r23", "r31", "r32", "r33", "nargin",
  "nargout", "k", "theta", "R" };

/* Function Declarations */
static void initialize_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void initialize_params_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void enable_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void disable_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void set_sim_state_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_st);
static void finalize_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void sf_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void c8_chartstep_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void initSimStructsc8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void registerMessagesc8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_R, const char_T *c8_identifier, real_T c8_y[9]);
static void c8_b_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[9]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[13]);
static real_T c8_mpower(SFc8_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance, real_T c8_a);
static void c8_eml_scalar_eg(SFc8_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_d_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_e_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_JointSpaceControl_CorrectInertia, const char_T
   *c8_identifier);
static uint8_T c8_f_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_JointSpaceControl_CorrectInertia = 0U;
}

static void initialize_params_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void enable_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[9];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T (*c8_R)[9];
  c8_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2), FALSE);
  for (c8_i0 = 0; c8_i0 < 9; c8_i0++) {
    c8_u[c8_i0] = (*c8_R)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal =
    chartInstance->c8_is_active_c8_JointSpaceControl_CorrectInertia;
  c8_b_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[9];
  int32_T c8_i1;
  real_T (*c8_R)[9];
  c8_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)), "R",
                      c8_dv0);
  for (c8_i1 = 0; c8_i1 < 9; c8_i1++) {
    (*c8_R)[c8_i1] = c8_dv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_JointSpaceControl_CorrectInertia =
    c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
    "is_active_c8_JointSpaceControl_CorrectInertia");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_JointSpaceControl_CorrectInertia(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void sf_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  int32_T c8_i2;
  int32_T c8_i3;
  real_T *c8_theta;
  real_T (*c8_R)[9];
  real_T (*c8_k)[3];
  c8_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((*c8_k)[c8_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c8_theta, 1U);
  for (c8_i3 = 0; c8_i3 < 9; c8_i3++) {
    _SFD_DATA_RANGE_CHECK((*c8_R)[c8_i3], 2U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_JointSpaceControl_CorrectInertia(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c8_chartstep_c8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  int32_T c8_i4;
  real_T c8_k[3];
  real_T c8_theta;
  uint32_T c8_debug_family_var_map[20];
  real_T c8_kx;
  real_T c8_ky;
  real_T c8_kz;
  real_T c8_v;
  real_T c8_s;
  real_T c8_c;
  real_T c8_r11;
  real_T c8_r12;
  real_T c8_r13;
  real_T c8_r21;
  real_T c8_r22;
  real_T c8_r23;
  real_T c8_r31;
  real_T c8_r32;
  real_T c8_r33;
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  real_T c8_R[9];
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_a;
  real_T c8_b;
  real_T c8_y;
  real_T c8_b_a;
  real_T c8_b_b;
  real_T c8_b_y;
  real_T c8_c_a;
  real_T c8_c_b;
  real_T c8_c_y;
  real_T c8_d_a;
  real_T c8_d_b;
  real_T c8_d_y;
  real_T c8_e_a;
  real_T c8_e_b;
  real_T c8_e_y;
  real_T c8_f_a;
  real_T c8_f_b;
  real_T c8_f_y;
  real_T c8_g_a;
  real_T c8_g_b;
  real_T c8_g_y;
  real_T c8_h_a;
  real_T c8_h_b;
  real_T c8_h_y;
  real_T c8_i_a;
  real_T c8_i_b;
  real_T c8_i_y;
  real_T c8_j_a;
  real_T c8_j_b;
  real_T c8_j_y;
  real_T c8_k_a;
  real_T c8_k_b;
  real_T c8_k_y;
  real_T c8_l_a;
  real_T c8_l_b;
  real_T c8_l_y;
  real_T c8_m_a;
  real_T c8_m_b;
  real_T c8_m_y;
  real_T c8_n_a;
  real_T c8_n_b;
  real_T c8_n_y;
  real_T c8_o_a;
  real_T c8_o_b;
  real_T c8_o_y;
  real_T c8_p_a;
  real_T c8_p_b;
  real_T c8_p_y;
  real_T c8_q_a;
  real_T c8_q_b;
  real_T c8_q_y;
  real_T c8_r_a;
  real_T c8_r_b;
  real_T c8_r_y;
  real_T c8_s_a;
  real_T c8_s_b;
  real_T c8_s_y;
  real_T c8_t_a;
  real_T c8_t_b;
  real_T c8_t_y;
  real_T c8_u_a;
  real_T c8_u_b;
  real_T c8_u_y;
  int32_T c8_i5;
  real_T *c8_b_theta;
  real_T (*c8_b_R)[9];
  real_T (*c8_b_k)[3];
  c8_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_theta;
  for (c8_i4 = 0; c8_i4 < 3; c8_i4++) {
    c8_k[c8_i4] = (*c8_b_k)[c8_i4];
  }

  c8_theta = c8_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_kx, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_ky, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_kz, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_v, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_s, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r11, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r12, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r13, 8U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r21, 9U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r22, 10U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r23, 11U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r31, 12U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r32, 13U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_r33, 14U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 15U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 16U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_k, 17U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_theta, 18U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_R, 19U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_kx = c8_k[0];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  c8_ky = c8_k[1];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_kz = c8_k[2];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_x = c8_theta;
  c8_b_x = c8_x;
  c8_b_x = muDoubleScalarCos(c8_b_x);
  c8_v = 1.0 - c8_b_x;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  c8_c_x = c8_theta;
  c8_s = c8_c_x;
  c8_d_x = c8_s;
  c8_s = c8_d_x;
  c8_s = muDoubleScalarSin(c8_s);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_e_x = c8_theta;
  c8_c = c8_e_x;
  c8_f_x = c8_c;
  c8_c = c8_f_x;
  c8_c = muDoubleScalarCos(c8_c);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 12);
  c8_a = c8_mpower(chartInstance, c8_kx);
  c8_b = c8_v;
  c8_y = c8_a * c8_b;
  c8_r11 = c8_y + c8_c;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 13);
  c8_b_a = c8_kx;
  c8_b_b = c8_ky;
  c8_b_y = c8_b_a * c8_b_b;
  c8_c_a = c8_b_y;
  c8_c_b = c8_v;
  c8_c_y = c8_c_a * c8_c_b;
  c8_d_a = c8_kz;
  c8_d_b = c8_s;
  c8_d_y = c8_d_a * c8_d_b;
  c8_r12 = c8_c_y - c8_d_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
  c8_e_a = c8_kx;
  c8_e_b = c8_kz;
  c8_e_y = c8_e_a * c8_e_b;
  c8_f_a = c8_e_y;
  c8_f_b = c8_v;
  c8_f_y = c8_f_a * c8_f_b;
  c8_g_a = c8_ky;
  c8_g_b = c8_s;
  c8_g_y = c8_g_a * c8_g_b;
  c8_r13 = c8_f_y + c8_g_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 15);
  c8_h_a = c8_kx;
  c8_h_b = c8_ky;
  c8_h_y = c8_h_a * c8_h_b;
  c8_i_a = c8_h_y;
  c8_i_b = c8_v;
  c8_i_y = c8_i_a * c8_i_b;
  c8_j_a = c8_kz;
  c8_j_b = c8_s;
  c8_j_y = c8_j_a * c8_j_b;
  c8_r21 = c8_i_y + c8_j_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 16);
  c8_k_a = c8_mpower(chartInstance, c8_ky);
  c8_k_b = c8_v;
  c8_k_y = c8_k_a * c8_k_b;
  c8_r22 = c8_k_y + c8_c;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
  c8_l_a = c8_ky;
  c8_l_b = c8_kz;
  c8_l_y = c8_l_a * c8_l_b;
  c8_m_a = c8_l_y;
  c8_m_b = c8_v;
  c8_m_y = c8_m_a * c8_m_b;
  c8_n_a = c8_kx;
  c8_n_b = c8_s;
  c8_n_y = c8_n_a * c8_n_b;
  c8_r23 = c8_m_y - c8_n_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_o_a = c8_kx;
  c8_o_b = c8_kz;
  c8_o_y = c8_o_a * c8_o_b;
  c8_p_a = c8_o_y;
  c8_p_b = c8_v;
  c8_p_y = c8_p_a * c8_p_b;
  c8_q_a = c8_ky;
  c8_q_b = c8_s;
  c8_q_y = c8_q_a * c8_q_b;
  c8_r31 = c8_p_y - c8_q_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 19);
  c8_r_a = c8_ky;
  c8_r_b = c8_kz;
  c8_r_y = c8_r_a * c8_r_b;
  c8_s_a = c8_r_y;
  c8_s_b = c8_v;
  c8_s_y = c8_s_a * c8_s_b;
  c8_t_a = c8_kx;
  c8_t_b = c8_s;
  c8_t_y = c8_t_a * c8_t_b;
  c8_r32 = c8_s_y + c8_t_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 20);
  c8_u_a = c8_mpower(chartInstance, c8_kz);
  c8_u_b = c8_v;
  c8_u_y = c8_u_a * c8_u_b;
  c8_r33 = c8_u_y + c8_c;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 22);
  c8_R[0] = c8_r11;
  c8_R[3] = c8_r12;
  c8_R[6] = c8_r13;
  c8_R[1] = c8_r21;
  c8_R[4] = c8_r22;
  c8_R[7] = c8_r23;
  c8_R[2] = c8_r31;
  c8_R[5] = c8_r32;
  c8_R[8] = c8_r33;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_i5 = 0; c8_i5 < 9; c8_i5++) {
    (*c8_b_R)[c8_i5] = c8_R[c8_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc8_JointSpaceControl_CorrectInertia
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  real_T c8_b_inData[9];
  int32_T c8_i9;
  int32_T c8_i10;
  int32_T c8_i11;
  real_T c8_u[9];
  const mxArray *c8_y = NULL;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i6 = 0;
  for (c8_i7 = 0; c8_i7 < 3; c8_i7++) {
    for (c8_i8 = 0; c8_i8 < 3; c8_i8++) {
      c8_b_inData[c8_i8 + c8_i6] = (*(real_T (*)[9])c8_inData)[c8_i8 + c8_i6];
    }

    c8_i6 += 3;
  }

  c8_i9 = 0;
  for (c8_i10 = 0; c8_i10 < 3; c8_i10++) {
    for (c8_i11 = 0; c8_i11 < 3; c8_i11++) {
      c8_u[c8_i11 + c8_i9] = c8_b_inData[c8_i11 + c8_i9];
    }

    c8_i9 += 3;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_R, const char_T *c8_identifier, real_T c8_y[9])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_R), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_R);
}

static void c8_b_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[9])
{
  real_T c8_dv1[9];
  int32_T c8_i12;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c8_i12 = 0; c8_i12 < 9; c8_i12++) {
    c8_y[c8_i12] = c8_dv1[c8_i12];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_R;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[9];
  int32_T c8_i13;
  int32_T c8_i14;
  int32_T c8_i15;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_R = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_R), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_R);
  c8_i13 = 0;
  for (c8_i14 = 0; c8_i14 < 3; c8_i14++) {
    for (c8_i15 = 0; c8_i15 < 3; c8_i15++) {
      (*(real_T (*)[9])c8_outData)[c8_i15 + c8_i13] = c8_y[c8_i15 + c8_i13];
    }

    c8_i13 += 3;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i16;
  real_T c8_b_inData[3];
  int32_T c8_i17;
  real_T c8_u[3];
  const mxArray *c8_y = NULL;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i16 = 0; c8_i16 < 3; c8_i16++) {
    c8_b_inData[c8_i16] = (*(real_T (*)[3])c8_inData)[c8_i16];
  }

  for (c8_i17 = 0; c8_i17 < 3; c8_i17++) {
    c8_u[c8_i17] = c8_b_inData[c8_i17];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray
  *sf_c8_JointSpaceControl_CorrectInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[13];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i18;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c8_i18 = 0; c8_i18 < 13; c8_i18++) {
    c8_r0 = &c8_info[c8_i18];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i18);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i18);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[13])
{
  c8_info[0].context = "";
  c8_info[0].name = "cos";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[0].fileTimeLo = 1343851972U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[1].name = "eml_scalar_cos";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c8_info[1].fileTimeLo = 1286840322U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context = "";
  c8_info[2].name = "sin";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[2].fileTimeLo = 1343851986U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[3].name = "eml_scalar_sin";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c8_info[3].fileTimeLo = 1286840336U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context = "";
  c8_info[4].name = "mpower";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[4].fileTimeLo = 1286840442U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[5].name = "power";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[5].fileTimeLo = 1348213530U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[6].name = "eml_scalar_eg";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[6].fileTimeLo = 1286840396U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[7].name = "eml_scalexp_alloc";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[7].fileTimeLo = 1352446460U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[8].name = "floor";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[8].fileTimeLo = 1343851980U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[9].name = "eml_scalar_floor";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[9].fileTimeLo = 1286840326U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[10].name = "eml_scalar_eg";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[10].fileTimeLo = 1286840396U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[11].name = "mtimes";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[11].fileTimeLo = 1289541292U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context = "";
  c8_info[12].name = "mtimes";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[12].fileTimeLo = 1289541292U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
}

static real_T c8_mpower(SFc8_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance, real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_c_a;
  real_T c8_ak;
  real_T c8_d_a;
  real_T c8_e_a;
  real_T c8_b;
  c8_b_a = c8_a;
  c8_c_a = c8_b_a;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_c_a;
  c8_d_a = c8_ak;
  c8_eml_scalar_eg(chartInstance);
  c8_e_a = c8_d_a;
  c8_b = c8_d_a;
  return c8_e_a * c8_b;
}

static void c8_eml_scalar_eg(SFc8_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance)
{
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_d_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i19;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i19, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i19;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_e_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_JointSpaceControl_CorrectInertia, const char_T
   *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_JointSpaceControl_CorrectInertia), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_JointSpaceControl_CorrectInertia);
  return c8_y;
}

static uint8_T c8_f_emlrt_marshallIn
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info
  (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
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

void sf_c8_JointSpaceControl_CorrectInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(909815670U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2632275583U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2534646688U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(117899888U);
}

mxArray *sf_c8_JointSpaceControl_CorrectInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Akowil4FuPzP8AFYvcXM4B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_JointSpaceControl_CorrectInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c8_JointSpaceControl_CorrectInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"R\",},{M[8],M[0],T\"is_active_c8_JointSpaceControl_CorrectInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_JointSpaceControl_CorrectInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectInertiaMachineNumber_,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"k");
          _SFD_SET_DATA_PROPS(1,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(2,2,0,1,"R");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,456);
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
            1.0,0,0,(MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          real_T *c8_theta;
          real_T (*c8_k)[3];
          real_T (*c8_R)[9];
          c8_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c8_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_k);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_theta);
          _SFD_SET_DATA_VALUE_PTR(2U, *c8_R);
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
  return "Y4Jezfv6fKTJGiVFQdyn5B";
}

static void sf_opaque_initialize_c8_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
  initialize_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  enable_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  disable_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  sf_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c8_JointSpaceControl_CorrectInertia(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_JointSpaceControl_CorrectInertia
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

extern void sf_internal_set_sim_state_c8_JointSpaceControl_CorrectInertia
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_JointSpaceControl_CorrectInertia
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_JointSpaceControl_CorrectInertia(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_JointSpaceControl_CorrectInertia(S);
}

static void sf_opaque_set_sim_state_c8_JointSpaceControl_CorrectInertia
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_JointSpaceControl_CorrectInertia(S, st);
}

static void sf_opaque_terminate_c8_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectInertia_optimization_info();
    }

    finalize_c8_JointSpaceControl_CorrectInertia
      ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_JointSpaceControl_CorrectInertia
    ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_JointSpaceControl_CorrectInertia(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_JointSpaceControl_CorrectInertia
      ((SFc8_JointSpaceControl_CorrectInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2000719305U));
  ssSetChecksum1(S,(2302372531U));
  ssSetChecksum2(S,(1876035132U));
  ssSetChecksum3(S,(3355036561U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct *)
    utMalloc(sizeof(SFc8_JointSpaceControl_CorrectInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc8_JointSpaceControl_CorrectInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_JointSpaceControl_CorrectInertia;
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

void c8_JointSpaceControl_CorrectInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_JointSpaceControl_CorrectInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_JointSpaceControl_CorrectInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_JointSpaceControl_CorrectInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_JointSpaceControl_CorrectInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
