/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectFalseCombo_sfun.h"
#include "c15_JointSpaceControl_CorrectFalseCombo.h"
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
static const char * c15_debug_family_names[20] = { "kx", "ky", "kz", "v", "s",
  "c", "r11", "r12", "r13", "r21", "r22", "r23", "r31", "r32", "r33", "nargin",
  "nargout", "k", "theta", "R" };

/* Function Declarations */
static void initialize_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initialize_params_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void enable_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void disable_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_JointSpaceControl_CorrectFalseComb
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void set_sim_state_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_st);
static void finalize_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void sf_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initSimStructsc15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void registerMessagesc15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_R, const char_T *c15_identifier, real_T c15_y[9]);
static void c15_b_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[9]);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_c_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static void c15_info_helper(c15_ResolvedFunctionInfo c15_info[13]);
static real_T c15_mpower(SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, real_T c15_a);
static void c15_eml_scalar_eg
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_d_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_e_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_b_is_active_c15_JointSpaceControl_CorrectFalseCombo, const
   char_T *c15_identifier);
static uint8_T c15_f_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_is_active_c15_JointSpaceControl_CorrectFalseCombo = 0U;
}

static void initialize_params_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void enable_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_JointSpaceControl_CorrectFalseComb
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[9];
  const mxArray *c15_b_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  real_T (*c15_R)[9];
  c15_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(2), FALSE);
  for (c15_i0 = 0; c15_i0 < 9; c15_i0++) {
    c15_u[c15_i0] = (*c15_R)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_hoistedGlobal =
    chartInstance->c15_is_active_c15_JointSpaceControl_CorrectFalseCombo;
  c15_b_u = c15_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y, FALSE);
  return c15_st;
}

static void set_sim_state_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[9];
  int32_T c15_i1;
  real_T (*c15_R)[9];
  c15_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)), "R",
                       c15_dv0);
  for (c15_i1 = 0; c15_i1 < 9; c15_i1++) {
    (*c15_R)[c15_i1] = c15_dv0[c15_i1];
  }

  chartInstance->c15_is_active_c15_JointSpaceControl_CorrectFalseCombo =
    c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
    "is_active_c15_JointSpaceControl_CorrectFalseCombo");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_JointSpaceControl_CorrectFalseComb(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void sf_c15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c15_i2;
  int32_T c15_i3;
  real_T c15_hoistedGlobal;
  int32_T c15_i4;
  real_T c15_k[3];
  real_T c15_theta;
  uint32_T c15_debug_family_var_map[20];
  real_T c15_kx;
  real_T c15_ky;
  real_T c15_kz;
  real_T c15_v;
  real_T c15_s;
  real_T c15_c;
  real_T c15_r11;
  real_T c15_r12;
  real_T c15_r13;
  real_T c15_r21;
  real_T c15_r22;
  real_T c15_r23;
  real_T c15_r31;
  real_T c15_r32;
  real_T c15_r33;
  real_T c15_nargin = 2.0;
  real_T c15_nargout = 1.0;
  real_T c15_R[9];
  real_T c15_x;
  real_T c15_b_x;
  real_T c15_c_x;
  real_T c15_d_x;
  real_T c15_e_x;
  real_T c15_f_x;
  real_T c15_a;
  real_T c15_b;
  real_T c15_y;
  real_T c15_b_a;
  real_T c15_b_b;
  real_T c15_b_y;
  real_T c15_c_a;
  real_T c15_c_b;
  real_T c15_c_y;
  real_T c15_d_a;
  real_T c15_d_b;
  real_T c15_d_y;
  real_T c15_e_a;
  real_T c15_e_b;
  real_T c15_e_y;
  real_T c15_f_a;
  real_T c15_f_b;
  real_T c15_f_y;
  real_T c15_g_a;
  real_T c15_g_b;
  real_T c15_g_y;
  real_T c15_h_a;
  real_T c15_h_b;
  real_T c15_h_y;
  real_T c15_i_a;
  real_T c15_i_b;
  real_T c15_i_y;
  real_T c15_j_a;
  real_T c15_j_b;
  real_T c15_j_y;
  real_T c15_k_a;
  real_T c15_k_b;
  real_T c15_k_y;
  real_T c15_l_a;
  real_T c15_l_b;
  real_T c15_l_y;
  real_T c15_m_a;
  real_T c15_m_b;
  real_T c15_m_y;
  real_T c15_n_a;
  real_T c15_n_b;
  real_T c15_n_y;
  real_T c15_o_a;
  real_T c15_o_b;
  real_T c15_o_y;
  real_T c15_p_a;
  real_T c15_p_b;
  real_T c15_p_y;
  real_T c15_q_a;
  real_T c15_q_b;
  real_T c15_q_y;
  real_T c15_r_a;
  real_T c15_r_b;
  real_T c15_r_y;
  real_T c15_s_a;
  real_T c15_s_b;
  real_T c15_s_y;
  real_T c15_t_a;
  real_T c15_t_b;
  real_T c15_t_y;
  real_T c15_u_a;
  real_T c15_u_b;
  real_T c15_u_y;
  int32_T c15_i5;
  real_T *c15_b_theta;
  real_T (*c15_b_R)[9];
  real_T (*c15_b_k)[3];
  c15_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c15_b_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c15_sfEvent);
  for (c15_i2 = 0; c15_i2 < 3; c15_i2++) {
    _SFD_DATA_RANGE_CHECK((*c15_b_k)[c15_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c15_b_theta, 1U);
  for (c15_i3 = 0; c15_i3 < 9; c15_i3++) {
    _SFD_DATA_RANGE_CHECK((*c15_b_R)[c15_i3], 2U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = *c15_b_theta;
  for (c15_i4 = 0; c15_i4 < 3; c15_i4++) {
    c15_k[c15_i4] = (*c15_b_k)[c15_i4];
  }

  c15_theta = c15_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_kx, 0U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_ky, 1U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_kz, 2U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_v, 3U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_s, 4U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_c, 5U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r11, 6U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r12, 7U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r13, 8U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r21, 9U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r22, 10U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r23, 11U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r31, 12U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r32, 13U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r33, 14U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 15U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 16U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_k, 17U, c15_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_theta, 18U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_R, 19U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 4);
  c15_kx = c15_k[0];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 5);
  c15_ky = c15_k[1];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 6);
  c15_kz = c15_k[2];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_x = c15_theta;
  c15_b_x = c15_x;
  c15_b_x = muDoubleScalarCos(c15_b_x);
  c15_v = 1.0 - c15_b_x;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
  c15_c_x = c15_theta;
  c15_s = c15_c_x;
  c15_d_x = c15_s;
  c15_s = c15_d_x;
  c15_s = muDoubleScalarSin(c15_s);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 10);
  c15_e_x = c15_theta;
  c15_c = c15_e_x;
  c15_f_x = c15_c;
  c15_c = c15_f_x;
  c15_c = muDoubleScalarCos(c15_c);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
  c15_a = c15_mpower(chartInstance, c15_kx);
  c15_b = c15_v;
  c15_y = c15_a * c15_b;
  c15_r11 = c15_y + c15_c;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
  c15_b_a = c15_kx;
  c15_b_b = c15_ky;
  c15_b_y = c15_b_a * c15_b_b;
  c15_c_a = c15_b_y;
  c15_c_b = c15_v;
  c15_c_y = c15_c_a * c15_c_b;
  c15_d_a = c15_kz;
  c15_d_b = c15_s;
  c15_d_y = c15_d_a * c15_d_b;
  c15_r12 = c15_c_y - c15_d_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
  c15_e_a = c15_kx;
  c15_e_b = c15_kz;
  c15_e_y = c15_e_a * c15_e_b;
  c15_f_a = c15_e_y;
  c15_f_b = c15_v;
  c15_f_y = c15_f_a * c15_f_b;
  c15_g_a = c15_ky;
  c15_g_b = c15_s;
  c15_g_y = c15_g_a * c15_g_b;
  c15_r13 = c15_f_y + c15_g_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  c15_h_a = c15_kx;
  c15_h_b = c15_ky;
  c15_h_y = c15_h_a * c15_h_b;
  c15_i_a = c15_h_y;
  c15_i_b = c15_v;
  c15_i_y = c15_i_a * c15_i_b;
  c15_j_a = c15_kz;
  c15_j_b = c15_s;
  c15_j_y = c15_j_a * c15_j_b;
  c15_r21 = c15_i_y + c15_j_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 16);
  c15_k_a = c15_mpower(chartInstance, c15_ky);
  c15_k_b = c15_v;
  c15_k_y = c15_k_a * c15_k_b;
  c15_r22 = c15_k_y + c15_c;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
  c15_l_a = c15_ky;
  c15_l_b = c15_kz;
  c15_l_y = c15_l_a * c15_l_b;
  c15_m_a = c15_l_y;
  c15_m_b = c15_v;
  c15_m_y = c15_m_a * c15_m_b;
  c15_n_a = c15_kx;
  c15_n_b = c15_s;
  c15_n_y = c15_n_a * c15_n_b;
  c15_r23 = c15_m_y - c15_n_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 18);
  c15_o_a = c15_kx;
  c15_o_b = c15_kz;
  c15_o_y = c15_o_a * c15_o_b;
  c15_p_a = c15_o_y;
  c15_p_b = c15_v;
  c15_p_y = c15_p_a * c15_p_b;
  c15_q_a = c15_ky;
  c15_q_b = c15_s;
  c15_q_y = c15_q_a * c15_q_b;
  c15_r31 = c15_p_y - c15_q_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 19);
  c15_r_a = c15_ky;
  c15_r_b = c15_kz;
  c15_r_y = c15_r_a * c15_r_b;
  c15_s_a = c15_r_y;
  c15_s_b = c15_v;
  c15_s_y = c15_s_a * c15_s_b;
  c15_t_a = c15_kx;
  c15_t_b = c15_s;
  c15_t_y = c15_t_a * c15_t_b;
  c15_r32 = c15_s_y + c15_t_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 20);
  c15_u_a = c15_mpower(chartInstance, c15_kz);
  c15_u_b = c15_v;
  c15_u_y = c15_u_a * c15_u_b;
  c15_r33 = c15_u_y + c15_c;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 22);
  c15_R[0] = c15_r11;
  c15_R[3] = c15_r12;
  c15_R[6] = c15_r13;
  c15_R[1] = c15_r21;
  c15_R[4] = c15_r22;
  c15_R[7] = c15_r23;
  c15_R[2] = c15_r31;
  c15_R[5] = c15_r32;
  c15_R[8] = c15_r33;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c15_i5 = 0; c15_i5 < 9; c15_i5++) {
    (*c15_b_R)[c15_i5] = c15_R[c15_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c15_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectFalseComboMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void registerMessagesc15_JointSpaceControl_CorrectFalseCombo
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_i8;
  real_T c15_b_inData[9];
  int32_T c15_i9;
  int32_T c15_i10;
  int32_T c15_i11;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_i6 = 0;
  for (c15_i7 = 0; c15_i7 < 3; c15_i7++) {
    for (c15_i8 = 0; c15_i8 < 3; c15_i8++) {
      c15_b_inData[c15_i8 + c15_i6] = (*(real_T (*)[9])c15_inData)[c15_i8 +
        c15_i6];
    }

    c15_i6 += 3;
  }

  c15_i9 = 0;
  for (c15_i10 = 0; c15_i10 < 3; c15_i10++) {
    for (c15_i11 = 0; c15_i11 < 3; c15_i11++) {
      c15_u[c15_i11 + c15_i9] = c15_b_inData[c15_i11 + c15_i9];
    }

    c15_i9 += 3;
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_R, const char_T *c15_identifier, real_T c15_y[9])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_R), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_R);
}

static void c15_b_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[9])
{
  real_T c15_dv1[9];
  int32_T c15_i12;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c15_i12 = 0; c15_i12 < 9; c15_i12++) {
    c15_y[c15_i12] = c15_dv1[c15_i12];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_R;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i13;
  int32_T c15_i14;
  int32_T c15_i15;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_R = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_R), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_R);
  c15_i13 = 0;
  for (c15_i14 = 0; c15_i14 < 3; c15_i14++) {
    for (c15_i15 = 0; c15_i15 < 3; c15_i15++) {
      (*(real_T (*)[9])c15_outData)[c15_i15 + c15_i13] = c15_y[c15_i15 + c15_i13];
    }

    c15_i13 += 3;
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i16;
  real_T c15_b_inData[3];
  int32_T c15_i17;
  real_T c15_u[3];
  const mxArray *c15_y = NULL;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i16 = 0; c15_i16 < 3; c15_i16++) {
    c15_b_inData[c15_i16] = (*(real_T (*)[3])c15_inData)[c15_i16];
  }

  for (c15_i17 = 0; c15_i17 < 3; c15_i17++) {
    c15_u[c15_i17] = c15_b_inData[c15_i17];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static real_T c15_c_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray
  *sf_c15_JointSpaceControl_CorrectFalseCombo_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c15_nameCaptureInfo;
  c15_ResolvedFunctionInfo c15_info[13];
  const mxArray *c15_m0 = NULL;
  int32_T c15_i18;
  c15_ResolvedFunctionInfo *c15_r0;
  c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  c15_info_helper(c15_info);
  sf_mex_assign(&c15_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c15_i18 = 0; c15_i18 < 13; c15_i18++) {
    c15_r0 = &c15_info[c15_i18];
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->context)), "context", "nameCaptureInfo",
                    c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->name)), "name", "nameCaptureInfo",
                    c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      c15_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->resolved)), "resolved",
                    "nameCaptureInfo", c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c15_i18);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c15_i18);
  }

  sf_mex_assign(&c15_nameCaptureInfo, c15_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(c15_ResolvedFunctionInfo c15_info[13])
{
  c15_info[0].context = "";
  c15_info[0].name = "cos";
  c15_info[0].dominantType = "double";
  c15_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c15_info[0].fileTimeLo = 1343851972U;
  c15_info[0].fileTimeHi = 0U;
  c15_info[0].mFileTimeLo = 0U;
  c15_info[0].mFileTimeHi = 0U;
  c15_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c15_info[1].name = "eml_scalar_cos";
  c15_info[1].dominantType = "double";
  c15_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c15_info[1].fileTimeLo = 1286840322U;
  c15_info[1].fileTimeHi = 0U;
  c15_info[1].mFileTimeLo = 0U;
  c15_info[1].mFileTimeHi = 0U;
  c15_info[2].context = "";
  c15_info[2].name = "sin";
  c15_info[2].dominantType = "double";
  c15_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c15_info[2].fileTimeLo = 1343851986U;
  c15_info[2].fileTimeHi = 0U;
  c15_info[2].mFileTimeLo = 0U;
  c15_info[2].mFileTimeHi = 0U;
  c15_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c15_info[3].name = "eml_scalar_sin";
  c15_info[3].dominantType = "double";
  c15_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c15_info[3].fileTimeLo = 1286840336U;
  c15_info[3].fileTimeHi = 0U;
  c15_info[3].mFileTimeLo = 0U;
  c15_info[3].mFileTimeHi = 0U;
  c15_info[4].context = "";
  c15_info[4].name = "mpower";
  c15_info[4].dominantType = "double";
  c15_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c15_info[4].fileTimeLo = 1286840442U;
  c15_info[4].fileTimeHi = 0U;
  c15_info[4].mFileTimeLo = 0U;
  c15_info[4].mFileTimeHi = 0U;
  c15_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c15_info[5].name = "power";
  c15_info[5].dominantType = "double";
  c15_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c15_info[5].fileTimeLo = 1348213530U;
  c15_info[5].fileTimeHi = 0U;
  c15_info[5].mFileTimeLo = 0U;
  c15_info[5].mFileTimeHi = 0U;
  c15_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c15_info[6].name = "eml_scalar_eg";
  c15_info[6].dominantType = "double";
  c15_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c15_info[6].fileTimeLo = 1286840396U;
  c15_info[6].fileTimeHi = 0U;
  c15_info[6].mFileTimeLo = 0U;
  c15_info[6].mFileTimeHi = 0U;
  c15_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c15_info[7].name = "eml_scalexp_alloc";
  c15_info[7].dominantType = "double";
  c15_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c15_info[7].fileTimeLo = 1352446460U;
  c15_info[7].fileTimeHi = 0U;
  c15_info[7].mFileTimeLo = 0U;
  c15_info[7].mFileTimeHi = 0U;
  c15_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c15_info[8].name = "floor";
  c15_info[8].dominantType = "double";
  c15_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c15_info[8].fileTimeLo = 1343851980U;
  c15_info[8].fileTimeHi = 0U;
  c15_info[8].mFileTimeLo = 0U;
  c15_info[8].mFileTimeHi = 0U;
  c15_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c15_info[9].name = "eml_scalar_floor";
  c15_info[9].dominantType = "double";
  c15_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c15_info[9].fileTimeLo = 1286840326U;
  c15_info[9].fileTimeHi = 0U;
  c15_info[9].mFileTimeLo = 0U;
  c15_info[9].mFileTimeHi = 0U;
  c15_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c15_info[10].name = "eml_scalar_eg";
  c15_info[10].dominantType = "double";
  c15_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c15_info[10].fileTimeLo = 1286840396U;
  c15_info[10].fileTimeHi = 0U;
  c15_info[10].mFileTimeLo = 0U;
  c15_info[10].mFileTimeHi = 0U;
  c15_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c15_info[11].name = "mtimes";
  c15_info[11].dominantType = "double";
  c15_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[11].fileTimeLo = 1289541292U;
  c15_info[11].fileTimeHi = 0U;
  c15_info[11].mFileTimeLo = 0U;
  c15_info[11].mFileTimeHi = 0U;
  c15_info[12].context = "";
  c15_info[12].name = "mtimes";
  c15_info[12].dominantType = "double";
  c15_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[12].fileTimeLo = 1289541292U;
  c15_info[12].fileTimeHi = 0U;
  c15_info[12].mFileTimeLo = 0U;
  c15_info[12].mFileTimeHi = 0U;
}

static real_T c15_mpower(SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct
  *chartInstance, real_T c15_a)
{
  real_T c15_b_a;
  real_T c15_c_a;
  real_T c15_ak;
  real_T c15_d_a;
  real_T c15_e_a;
  real_T c15_b;
  c15_b_a = c15_a;
  c15_c_a = c15_b_a;
  c15_eml_scalar_eg(chartInstance);
  c15_ak = c15_c_a;
  c15_d_a = c15_ak;
  c15_eml_scalar_eg(chartInstance);
  c15_e_a = c15_d_a;
  c15_b = c15_d_a;
  return c15_e_a * c15_b;
}

static void c15_eml_scalar_eg
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static int32_T c15_d_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i19;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i19, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i19;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_e_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_b_is_active_c15_JointSpaceControl_CorrectFalseCombo, const
   char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_JointSpaceControl_CorrectFalseCombo), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_JointSpaceControl_CorrectFalseCombo);
  return c15_y;
}

static uint8_T c15_f_emlrt_marshallIn
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info
  (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
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

void sf_c15_JointSpaceControl_CorrectFalseCombo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(909815670U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2632275583U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2534646688U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(117899888U);
}

mxArray *sf_c15_JointSpaceControl_CorrectFalseCombo_get_autoinheritance_info
  (void)
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

mxArray *sf_c15_JointSpaceControl_CorrectFalseCombo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c15_JointSpaceControl_CorrectFalseCombo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"R\",},{M[8],M[0],T\"is_active_c15_JointSpaceControl_CorrectFalseCombo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_JointSpaceControl_CorrectFalseCombo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
    chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectFalseComboMachineNumber_,
           15,
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
            1.0,0,0,(MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)
            c15_sf_marshallIn);
        }

        {
          real_T *c15_theta;
          real_T (*c15_k)[3];
          real_T (*c15_R)[9];
          c15_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c15_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c15_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_k);
          _SFD_SET_DATA_VALUE_PTR(1U, c15_theta);
          _SFD_SET_DATA_VALUE_PTR(2U, *c15_R);
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
  return "Y4Jezfv6fKTJGiVFQdyn5B";
}

static void sf_opaque_initialize_c15_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
  initialize_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  enable_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  disable_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c15_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  sf_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c15_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c15_JointSpaceControl_CorrectFalseCombo();/* state var info */
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

extern void sf_internal_set_sim_state_c15_JointSpaceControl_CorrectFalseCombo
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
    sf_get_sim_state_info_c15_JointSpaceControl_CorrectFalseCombo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c15_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  return sf_internal_get_sim_state_c15_JointSpaceControl_CorrectFalseCombo(S);
}

static void sf_opaque_set_sim_state_c15_JointSpaceControl_CorrectFalseCombo
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c15_JointSpaceControl_CorrectFalseCombo(S, st);
}

static void sf_opaque_terminate_c15_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectFalseCombo_optimization_info();
    }

    finalize_c15_JointSpaceControl_CorrectFalseCombo
      ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_JointSpaceControl_CorrectFalseCombo
    ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_JointSpaceControl_CorrectFalseCombo
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_JointSpaceControl_CorrectFalseCombo
      ((SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_JointSpaceControl_CorrectFalseCombo(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectFalseCombo_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,15,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
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

static void mdlRTW_c15_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    utMalloc(sizeof(SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc15_JointSpaceControl_CorrectFalseComboInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c15_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_JointSpaceControl_CorrectFalseCombo;
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

void c15_JointSpaceControl_CorrectFalseCombo_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_JointSpaceControl_CorrectFalseCombo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_JointSpaceControl_CorrectFalseCombo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
