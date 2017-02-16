/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectFalseCombo_sfun.h"
#include "c18_JointSpaceControl_CorrectFalseCombo.h"
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
static const char * c18_debug_family_names[15] = { "r_11", "r_12", "r_13",
  "r_21", "r_22", "r_23", "r_31", "r_32", "r_33", "nargin", "nargout", "theta",
  "phi", "psi", "R" };

/* Function Declarations */
static void initialize_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initialize_params_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void enable_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void disable_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_JointSpaceControl_CorrectFalseComb
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void set_sim_state_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_st);
static void finalize_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void sf_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initSimStructsc18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void registerMessagesc18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_R, const char_T *c18_identifier, real_T c18_y[9]);
static void c18_b_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[9]);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_c_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_d_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_e_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_b_is_active_c18_JointSpaceControl_CorrectFalseCombo, const
   char_T *c18_identifier);
static uint8_T c18_f_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c18_is_active_c18_JointSpaceControl_CorrectFalseCombo = 0U;
}

static void initialize_params_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void enable_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c18_update_debugger_state_c18_JointSpaceControl_CorrectFalseComb
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  real_T c18_u[9];
  const mxArray *c18_b_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  real_T (*c18_R)[9];
  c18_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellarray(2), FALSE);
  for (c18_i0 = 0; c18_i0 < 9; c18_i0++) {
    c18_u[c18_i0] = (*c18_R)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_hoistedGlobal =
    chartInstance->c18_is_active_c18_JointSpaceControl_CorrectFalseCombo;
  c18_b_u = c18_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, FALSE);
  return c18_st;
}

static void set_sim_state_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T c18_dv0[9];
  int32_T c18_i1;
  real_T (*c18_R)[9];
  c18_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c18_doneDoubleBufferReInit = TRUE;
  c18_u = sf_mex_dup(c18_st);
  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)), "R",
                       c18_dv0);
  for (c18_i1 = 0; c18_i1 < 9; c18_i1++) {
    (*c18_R)[c18_i1] = c18_dv0[c18_i1];
  }

  chartInstance->c18_is_active_c18_JointSpaceControl_CorrectFalseCombo =
    c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
    "is_active_c18_JointSpaceControl_CorrectFalseCombo");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_JointSpaceControl_CorrectFalseComb(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void sf_c18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c18_i2;
  real_T c18_hoistedGlobal;
  real_T c18_b_hoistedGlobal;
  real_T c18_c_hoistedGlobal;
  real_T c18_theta;
  real_T c18_phi;
  real_T c18_psi;
  uint32_T c18_debug_family_var_map[15];
  real_T c18_r_11;
  real_T c18_r_12;
  real_T c18_r_13;
  real_T c18_r_21;
  real_T c18_r_22;
  real_T c18_r_23;
  real_T c18_r_31;
  real_T c18_r_32;
  real_T c18_r_33;
  real_T c18_nargin = 3.0;
  real_T c18_nargout = 1.0;
  real_T c18_R[9];
  real_T c18_x;
  real_T c18_b_x;
  real_T c18_c_x;
  real_T c18_d_x;
  real_T c18_a;
  real_T c18_b;
  real_T c18_y;
  real_T c18_e_x;
  real_T c18_f_x;
  real_T c18_b_a;
  real_T c18_b_b;
  real_T c18_b_y;
  real_T c18_g_x;
  real_T c18_h_x;
  real_T c18_i_x;
  real_T c18_j_x;
  real_T c18_c_a;
  real_T c18_c_b;
  real_T c18_c_y;
  real_T c18_k_x;
  real_T c18_l_x;
  real_T c18_m_x;
  real_T c18_n_x;
  real_T c18_d_a;
  real_T c18_d_b;
  real_T c18_d_y;
  real_T c18_o_x;
  real_T c18_p_x;
  real_T c18_e_a;
  real_T c18_e_b;
  real_T c18_e_y;
  real_T c18_q_x;
  real_T c18_r_x;
  real_T c18_s_x;
  real_T c18_t_x;
  real_T c18_f_a;
  real_T c18_f_b;
  real_T c18_f_y;
  real_T c18_u_x;
  real_T c18_v_x;
  real_T c18_w_x;
  real_T c18_x_x;
  real_T c18_g_a;
  real_T c18_g_b;
  real_T c18_y_x;
  real_T c18_ab_x;
  real_T c18_bb_x;
  real_T c18_cb_x;
  real_T c18_h_a;
  real_T c18_h_b;
  real_T c18_g_y;
  real_T c18_db_x;
  real_T c18_eb_x;
  real_T c18_i_a;
  real_T c18_i_b;
  real_T c18_h_y;
  real_T c18_fb_x;
  real_T c18_gb_x;
  real_T c18_hb_x;
  real_T c18_ib_x;
  real_T c18_j_a;
  real_T c18_j_b;
  real_T c18_i_y;
  real_T c18_jb_x;
  real_T c18_kb_x;
  real_T c18_lb_x;
  real_T c18_mb_x;
  real_T c18_k_a;
  real_T c18_k_b;
  real_T c18_j_y;
  real_T c18_nb_x;
  real_T c18_ob_x;
  real_T c18_l_a;
  real_T c18_l_b;
  real_T c18_k_y;
  real_T c18_pb_x;
  real_T c18_qb_x;
  real_T c18_rb_x;
  real_T c18_sb_x;
  real_T c18_m_a;
  real_T c18_m_b;
  real_T c18_l_y;
  real_T c18_tb_x;
  real_T c18_ub_x;
  real_T c18_vb_x;
  real_T c18_wb_x;
  real_T c18_n_a;
  real_T c18_n_b;
  real_T c18_xb_x;
  real_T c18_yb_x;
  real_T c18_ac_x;
  real_T c18_bc_x;
  real_T c18_o_a;
  real_T c18_o_b;
  real_T c18_cc_x;
  real_T c18_dc_x;
  real_T c18_ec_x;
  real_T c18_fc_x;
  real_T c18_p_a;
  real_T c18_p_b;
  real_T c18_gc_x;
  real_T c18_hc_x;
  int32_T c18_i3;
  real_T *c18_b_theta;
  real_T *c18_b_phi;
  real_T *c18_b_psi;
  real_T (*c18_b_R)[9];
  c18_b_psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c18_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_b_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c18_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c18_b_theta, 0U);
  _SFD_DATA_RANGE_CHECK(*c18_b_phi, 1U);
  for (c18_i2 = 0; c18_i2 < 9; c18_i2++) {
    _SFD_DATA_RANGE_CHECK((*c18_b_R)[c18_i2], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c18_b_psi, 3U);
  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  c18_hoistedGlobal = *c18_b_theta;
  c18_b_hoistedGlobal = *c18_b_phi;
  c18_c_hoistedGlobal = *c18_b_psi;
  c18_theta = c18_hoistedGlobal;
  c18_phi = c18_b_hoistedGlobal;
  c18_psi = c18_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_11, 0U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_12, 1U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_13, 2U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_21, 3U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_22, 4U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_23, 5U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_31, 6U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_32, 7U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_r_33, 8U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 9U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 10U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_theta, 11U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_phi, 12U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_psi, 13U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_R, 14U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 5);
  c18_x = c18_phi;
  c18_b_x = c18_x;
  c18_b_x = muDoubleScalarCos(c18_b_x);
  c18_c_x = c18_theta;
  c18_d_x = c18_c_x;
  c18_d_x = muDoubleScalarCos(c18_d_x);
  c18_a = c18_b_x;
  c18_b = c18_d_x;
  c18_y = c18_a * c18_b;
  c18_e_x = c18_psi;
  c18_f_x = c18_e_x;
  c18_f_x = muDoubleScalarCos(c18_f_x);
  c18_b_a = c18_y;
  c18_b_b = c18_f_x;
  c18_b_y = c18_b_a * c18_b_b;
  c18_g_x = c18_phi;
  c18_h_x = c18_g_x;
  c18_h_x = muDoubleScalarSin(c18_h_x);
  c18_i_x = c18_psi;
  c18_j_x = c18_i_x;
  c18_j_x = muDoubleScalarSin(c18_j_x);
  c18_c_a = c18_h_x;
  c18_c_b = c18_j_x;
  c18_c_y = c18_c_a * c18_c_b;
  c18_r_11 = c18_b_y - c18_c_y;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 6);
  c18_k_x = c18_phi;
  c18_l_x = c18_k_x;
  c18_l_x = muDoubleScalarCos(c18_l_x);
  c18_m_x = c18_theta;
  c18_n_x = c18_m_x;
  c18_n_x = muDoubleScalarCos(c18_n_x);
  c18_d_a = -c18_l_x;
  c18_d_b = c18_n_x;
  c18_d_y = c18_d_a * c18_d_b;
  c18_o_x = c18_psi;
  c18_p_x = c18_o_x;
  c18_p_x = muDoubleScalarSin(c18_p_x);
  c18_e_a = c18_d_y;
  c18_e_b = c18_p_x;
  c18_e_y = c18_e_a * c18_e_b;
  c18_q_x = c18_phi;
  c18_r_x = c18_q_x;
  c18_r_x = muDoubleScalarSin(c18_r_x);
  c18_s_x = c18_psi;
  c18_t_x = c18_s_x;
  c18_t_x = muDoubleScalarCos(c18_t_x);
  c18_f_a = c18_r_x;
  c18_f_b = c18_t_x;
  c18_f_y = c18_f_a * c18_f_b;
  c18_r_12 = c18_e_y - c18_f_y;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 7);
  c18_u_x = c18_phi;
  c18_v_x = c18_u_x;
  c18_v_x = muDoubleScalarCos(c18_v_x);
  c18_w_x = c18_theta;
  c18_x_x = c18_w_x;
  c18_x_x = muDoubleScalarSin(c18_x_x);
  c18_g_a = c18_v_x;
  c18_g_b = c18_x_x;
  c18_r_13 = c18_g_a * c18_g_b;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 9);
  c18_y_x = c18_phi;
  c18_ab_x = c18_y_x;
  c18_ab_x = muDoubleScalarSin(c18_ab_x);
  c18_bb_x = c18_theta;
  c18_cb_x = c18_bb_x;
  c18_cb_x = muDoubleScalarCos(c18_cb_x);
  c18_h_a = c18_ab_x;
  c18_h_b = c18_cb_x;
  c18_g_y = c18_h_a * c18_h_b;
  c18_db_x = c18_psi;
  c18_eb_x = c18_db_x;
  c18_eb_x = muDoubleScalarCos(c18_eb_x);
  c18_i_a = c18_g_y;
  c18_i_b = c18_eb_x;
  c18_h_y = c18_i_a * c18_i_b;
  c18_fb_x = c18_phi;
  c18_gb_x = c18_fb_x;
  c18_gb_x = muDoubleScalarCos(c18_gb_x);
  c18_hb_x = c18_psi;
  c18_ib_x = c18_hb_x;
  c18_ib_x = muDoubleScalarSin(c18_ib_x);
  c18_j_a = c18_gb_x;
  c18_j_b = c18_ib_x;
  c18_i_y = c18_j_a * c18_j_b;
  c18_r_21 = c18_h_y + c18_i_y;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 10);
  c18_jb_x = c18_phi;
  c18_kb_x = c18_jb_x;
  c18_kb_x = muDoubleScalarSin(c18_kb_x);
  c18_lb_x = c18_theta;
  c18_mb_x = c18_lb_x;
  c18_mb_x = muDoubleScalarCos(c18_mb_x);
  c18_k_a = -c18_kb_x;
  c18_k_b = c18_mb_x;
  c18_j_y = c18_k_a * c18_k_b;
  c18_nb_x = c18_psi;
  c18_ob_x = c18_nb_x;
  c18_ob_x = muDoubleScalarSin(c18_ob_x);
  c18_l_a = c18_j_y;
  c18_l_b = c18_ob_x;
  c18_k_y = c18_l_a * c18_l_b;
  c18_pb_x = c18_phi;
  c18_qb_x = c18_pb_x;
  c18_qb_x = muDoubleScalarCos(c18_qb_x);
  c18_rb_x = c18_psi;
  c18_sb_x = c18_rb_x;
  c18_sb_x = muDoubleScalarCos(c18_sb_x);
  c18_m_a = c18_qb_x;
  c18_m_b = c18_sb_x;
  c18_l_y = c18_m_a * c18_m_b;
  c18_r_22 = c18_k_y + c18_l_y;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 11);
  c18_tb_x = c18_phi;
  c18_ub_x = c18_tb_x;
  c18_ub_x = muDoubleScalarSin(c18_ub_x);
  c18_vb_x = c18_theta;
  c18_wb_x = c18_vb_x;
  c18_wb_x = muDoubleScalarSin(c18_wb_x);
  c18_n_a = c18_ub_x;
  c18_n_b = c18_wb_x;
  c18_r_23 = c18_n_a * c18_n_b;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 13);
  c18_xb_x = c18_theta;
  c18_yb_x = c18_xb_x;
  c18_yb_x = muDoubleScalarSin(c18_yb_x);
  c18_ac_x = c18_psi;
  c18_bc_x = c18_ac_x;
  c18_bc_x = muDoubleScalarCos(c18_bc_x);
  c18_o_a = -c18_yb_x;
  c18_o_b = c18_bc_x;
  c18_r_31 = c18_o_a * c18_o_b;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 14);
  c18_cc_x = c18_theta;
  c18_dc_x = c18_cc_x;
  c18_dc_x = muDoubleScalarSin(c18_dc_x);
  c18_ec_x = c18_psi;
  c18_fc_x = c18_ec_x;
  c18_fc_x = muDoubleScalarSin(c18_fc_x);
  c18_p_a = c18_dc_x;
  c18_p_b = c18_fc_x;
  c18_r_32 = c18_p_a * c18_p_b;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 15);
  c18_gc_x = c18_theta;
  c18_r_33 = c18_gc_x;
  c18_hc_x = c18_r_33;
  c18_r_33 = c18_hc_x;
  c18_r_33 = muDoubleScalarCos(c18_r_33);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 17);
  c18_R[0] = c18_r_11;
  c18_R[3] = c18_r_12;
  c18_R[6] = c18_r_13;
  c18_R[1] = c18_r_21;
  c18_R[4] = c18_r_22;
  c18_R[7] = c18_r_23;
  c18_R[2] = c18_r_31;
  c18_R[5] = c18_r_32;
  c18_R[8] = c18_r_33;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  for (c18_i3 = 0; c18_i3 < 9; c18_i3++) {
    (*c18_b_R)[c18_i3] = c18_R[c18_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectFalseComboMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void registerMessagesc18_JointSpaceControl_CorrectFalseCombo
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber)
{
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i4;
  int32_T c18_i5;
  int32_T c18_i6;
  real_T c18_b_inData[9];
  int32_T c18_i7;
  int32_T c18_i8;
  int32_T c18_i9;
  real_T c18_u[9];
  const mxArray *c18_y = NULL;
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i4 = 0;
  for (c18_i5 = 0; c18_i5 < 3; c18_i5++) {
    for (c18_i6 = 0; c18_i6 < 3; c18_i6++) {
      c18_b_inData[c18_i6 + c18_i4] = (*(real_T (*)[9])c18_inData)[c18_i6 +
        c18_i4];
    }

    c18_i4 += 3;
  }

  c18_i7 = 0;
  for (c18_i8 = 0; c18_i8 < 3; c18_i8++) {
    for (c18_i9 = 0; c18_i9 < 3; c18_i9++) {
      c18_u[c18_i9 + c18_i7] = c18_b_inData[c18_i9 + c18_i7];
    }

    c18_i7 += 3;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static void c18_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_R, const char_T *c18_identifier, real_T c18_y[9])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_R), &c18_thisId, c18_y);
  sf_mex_destroy(&c18_R);
}

static void c18_b_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[9])
{
  real_T c18_dv1[9];
  int32_T c18_i10;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c18_i10 = 0; c18_i10 < 9; c18_i10++) {
    c18_y[c18_i10] = c18_dv1[c18_i10];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_R;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[9];
  int32_T c18_i11;
  int32_T c18_i12;
  int32_T c18_i13;
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c18_R = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_R), &c18_thisId, c18_y);
  sf_mex_destroy(&c18_R);
  c18_i11 = 0;
  for (c18_i12 = 0; c18_i12 < 3; c18_i12++) {
    for (c18_i13 = 0; c18_i13 < 3; c18_i13++) {
      (*(real_T (*)[9])c18_outData)[c18_i13 + c18_i11] = c18_y[c18_i13 + c18_i11];
    }

    c18_i11 += 3;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static real_T c18_c_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nargout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c18_nargout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_nargout),
    &c18_thisId);
  sf_mex_destroy(&c18_nargout);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray
  *sf_c18_JointSpaceControl_CorrectFalseCombo_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c18_nameCaptureInfo;
  c18_ResolvedFunctionInfo c18_info[5];
  c18_ResolvedFunctionInfo (*c18_b_info)[5];
  const mxArray *c18_m0 = NULL;
  int32_T c18_i14;
  c18_ResolvedFunctionInfo *c18_r0;
  c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  c18_b_info = (c18_ResolvedFunctionInfo (*)[5])c18_info;
  (*c18_b_info)[0].context = "";
  (*c18_b_info)[0].name = "cos";
  (*c18_b_info)[0].dominantType = "double";
  (*c18_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c18_b_info)[0].fileTimeLo = 1343851972U;
  (*c18_b_info)[0].fileTimeHi = 0U;
  (*c18_b_info)[0].mFileTimeLo = 0U;
  (*c18_b_info)[0].mFileTimeHi = 0U;
  (*c18_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c18_b_info)[1].name = "eml_scalar_cos";
  (*c18_b_info)[1].dominantType = "double";
  (*c18_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c18_b_info)[1].fileTimeLo = 1286840322U;
  (*c18_b_info)[1].fileTimeHi = 0U;
  (*c18_b_info)[1].mFileTimeLo = 0U;
  (*c18_b_info)[1].mFileTimeHi = 0U;
  (*c18_b_info)[2].context = "";
  (*c18_b_info)[2].name = "mtimes";
  (*c18_b_info)[2].dominantType = "double";
  (*c18_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c18_b_info)[2].fileTimeLo = 1289541292U;
  (*c18_b_info)[2].fileTimeHi = 0U;
  (*c18_b_info)[2].mFileTimeLo = 0U;
  (*c18_b_info)[2].mFileTimeHi = 0U;
  (*c18_b_info)[3].context = "";
  (*c18_b_info)[3].name = "sin";
  (*c18_b_info)[3].dominantType = "double";
  (*c18_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c18_b_info)[3].fileTimeLo = 1343851986U;
  (*c18_b_info)[3].fileTimeHi = 0U;
  (*c18_b_info)[3].mFileTimeLo = 0U;
  (*c18_b_info)[3].mFileTimeHi = 0U;
  (*c18_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c18_b_info)[4].name = "eml_scalar_sin";
  (*c18_b_info)[4].dominantType = "double";
  (*c18_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c18_b_info)[4].fileTimeLo = 1286840336U;
  (*c18_b_info)[4].fileTimeHi = 0U;
  (*c18_b_info)[4].mFileTimeLo = 0U;
  (*c18_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c18_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c18_i14 = 0; c18_i14 < 5; c18_i14++) {
    c18_r0 = &c18_info[c18_i14];
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c18_r0->context)), "context", "nameCaptureInfo",
                    c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c18_r0->name)), "name", "nameCaptureInfo",
                    c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      c18_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c18_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c18_r0->resolved)), "resolved",
                    "nameCaptureInfo", c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      &c18_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c18_i14);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      &c18_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c18_i14);
  }

  sf_mex_assign(&c18_nameCaptureInfo, c18_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c18_nameCaptureInfo);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static int32_T c18_d_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i15;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i15, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i15;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_e_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_b_is_active_c18_JointSpaceControl_CorrectFalseCombo, const
   char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_JointSpaceControl_CorrectFalseCombo), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_JointSpaceControl_CorrectFalseCombo);
  return c18_y;
}

static uint8_T c18_f_emlrt_marshallIn
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info
  (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
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

void sf_c18_JointSpaceControl_CorrectFalseCombo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3323127116U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1478523500U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1156016235U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(834670359U);
}

mxArray *sf_c18_JointSpaceControl_CorrectFalseCombo_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("CBbrtpYuqffcJZVXnlTmjE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray *sf_c18_JointSpaceControl_CorrectFalseCombo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c18_JointSpaceControl_CorrectFalseCombo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"R\",},{M[8],M[0],T\"is_active_c18_JointSpaceControl_CorrectFalseCombo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_JointSpaceControl_CorrectFalseCombo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
    chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectFalseComboMachineNumber_,
           18,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(1,1,1,0,"phi");
          _SFD_SET_DATA_PROPS(2,2,0,1,"R");
          _SFD_SET_DATA_PROPS(3,1,1,0,"psi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,636);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)
            c18_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c18_theta;
          real_T *c18_phi;
          real_T *c18_psi;
          real_T (*c18_R)[9];
          c18_psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c18_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c18_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c18_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c18_theta);
          _SFD_SET_DATA_VALUE_PTR(1U, c18_phi);
          _SFD_SET_DATA_VALUE_PTR(2U, *c18_R);
          _SFD_SET_DATA_VALUE_PTR(3U, c18_psi);
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
  return "VFn9SBrwufpJ57VFiLH7c";
}

static void sf_opaque_initialize_c18_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
  initialize_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  enable_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  disable_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  sf_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c18_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c18_JointSpaceControl_CorrectFalseCombo();/* state var info */
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

extern void sf_internal_set_sim_state_c18_JointSpaceControl_CorrectFalseCombo
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
    sf_get_sim_state_info_c18_JointSpaceControl_CorrectFalseCombo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c18_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  return sf_internal_get_sim_state_c18_JointSpaceControl_CorrectFalseCombo(S);
}

static void sf_opaque_set_sim_state_c18_JointSpaceControl_CorrectFalseCombo
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c18_JointSpaceControl_CorrectFalseCombo(S, st);
}

static void sf_opaque_terminate_c18_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectFalseCombo_optimization_info();
    }

    finalize_c18_JointSpaceControl_CorrectFalseCombo
      ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_JointSpaceControl_CorrectFalseCombo
    ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_JointSpaceControl_CorrectFalseCombo
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c18_JointSpaceControl_CorrectFalseCombo
      ((SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_JointSpaceControl_CorrectFalseCombo(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectFalseCombo_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,18,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3458785644U));
  ssSetChecksum1(S,(559870660U));
  ssSetChecksum2(S,(3299085565U));
  ssSetChecksum3(S,(775181338U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    utMalloc(sizeof(SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc18_JointSpaceControl_CorrectFalseComboInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c18_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_JointSpaceControl_CorrectFalseCombo;
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

void c18_JointSpaceControl_CorrectFalseCombo_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_JointSpaceControl_CorrectFalseCombo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_JointSpaceControl_CorrectFalseCombo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
