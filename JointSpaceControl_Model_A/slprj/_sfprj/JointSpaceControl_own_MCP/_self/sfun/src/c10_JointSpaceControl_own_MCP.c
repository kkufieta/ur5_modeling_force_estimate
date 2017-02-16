/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_own_MCP_sfun.h"
#include "c10_JointSpaceControl_own_MCP.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_own_MCP_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[12] = { "theta_1", "theta_2",
  "theta_3", "theta_4", "theta_5", "theta_6", "nargin", "nargout", "q", "J",
  "J1", "J2" };

/* Function Declarations */
static void initialize_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void initialize_params_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void enable_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void disable_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void set_sim_state_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_st);
static void finalize_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void sf_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void c10_chartstep_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void initSimStructsc10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void registerMessagesc10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_J2, const char_T *c10_identifier, real_T
  c10_y[18]);
static void c10_b_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[18]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_J, const char_T *c10_identifier, real_T
  c10_y[36]);
static void c10_d_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[36]);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_e_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_f_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_g_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_b_is_active_c10_JointSpaceControl_own_MCP, const char_T *c10_identifier);
static uint8_T c10_h_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_JointSpaceControl_own_MCPInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_JointSpaceControl_own_MCP = 0U;
}

static void initialize_params_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
}

static void enable_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_u[36];
  const mxArray *c10_b_y = NULL;
  int32_T c10_i1;
  real_T c10_b_u[18];
  const mxArray *c10_c_y = NULL;
  int32_T c10_i2;
  real_T c10_c_u[18];
  const mxArray *c10_d_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_d_u;
  const mxArray *c10_e_y = NULL;
  real_T (*c10_J2)[18];
  real_T (*c10_J1)[18];
  real_T (*c10_J)[36];
  c10_J2 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_J1 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(4), FALSE);
  for (c10_i0 = 0; c10_i0 < 36; c10_i0++) {
    c10_u[c10_i0] = (*c10_J)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 6, 6),
                FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  for (c10_i1 = 0; c10_i1 < 18; c10_i1++) {
    c10_b_u[c10_i1] = (*c10_J1)[c10_i1];
  }

  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 2, 6, 3),
                FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  for (c10_i2 = 0; c10_i2 < 18; c10_i2++) {
    c10_c_u[c10_i2] = (*c10_J2)[c10_i2];
  }

  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 2, 6, 3),
                FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  c10_hoistedGlobal = chartInstance->c10_is_active_c10_JointSpaceControl_own_MCP;
  c10_d_u = c10_hoistedGlobal;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv0[36];
  int32_T c10_i3;
  real_T c10_dv1[18];
  int32_T c10_i4;
  real_T c10_dv2[18];
  int32_T c10_i5;
  real_T (*c10_J)[36];
  real_T (*c10_J1)[18];
  real_T (*c10_J2)[18];
  c10_J2 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_J1 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
    "J", c10_dv0);
  for (c10_i3 = 0; c10_i3 < 36; c10_i3++) {
    (*c10_J)[c10_i3] = c10_dv0[c10_i3];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)), "J1",
                       c10_dv1);
  for (c10_i4 = 0; c10_i4 < 18; c10_i4++) {
    (*c10_J1)[c10_i4] = c10_dv1[c10_i4];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)), "J2",
                       c10_dv2);
  for (c10_i5 = 0; c10_i5 < 18; c10_i5++) {
    (*c10_J2)[c10_i5] = c10_dv2[c10_i5];
  }

  chartInstance->c10_is_active_c10_JointSpaceControl_own_MCP =
    c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 3)),
    "is_active_c10_JointSpaceControl_own_MCP");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_JointSpaceControl_own_MCP(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
}

static void sf_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
  int32_T c10_i6;
  int32_T c10_i7;
  int32_T c10_i8;
  int32_T c10_i9;
  real_T (*c10_J2)[18];
  real_T (*c10_J1)[18];
  real_T (*c10_q)[6];
  real_T (*c10_J)[36];
  c10_J2 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_J1 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c10_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  for (c10_i6 = 0; c10_i6 < 36; c10_i6++) {
    _SFD_DATA_RANGE_CHECK((*c10_J)[c10_i6], 0U);
  }

  for (c10_i7 = 0; c10_i7 < 6; c10_i7++) {
    _SFD_DATA_RANGE_CHECK((*c10_q)[c10_i7], 1U);
  }

  for (c10_i8 = 0; c10_i8 < 18; c10_i8++) {
    _SFD_DATA_RANGE_CHECK((*c10_J1)[c10_i8], 2U);
  }

  for (c10_i9 = 0; c10_i9 < 18; c10_i9++) {
    _SFD_DATA_RANGE_CHECK((*c10_J2)[c10_i9], 3U);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_JointSpaceControl_own_MCP(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControl_own_MCPMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_chartstep_c10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
  int32_T c10_i10;
  real_T c10_q[6];
  uint32_T c10_debug_family_var_map[12];
  real_T c10_theta_1;
  real_T c10_theta_2;
  real_T c10_theta_3;
  real_T c10_theta_4;
  real_T c10_theta_5;
  real_T c10_theta_6;
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 3.0;
  real_T c10_J[36];
  real_T c10_J1[18];
  real_T c10_J2[18];
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_b;
  real_T c10_y;
  real_T c10_A;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_b_y;
  real_T c10_e_x;
  real_T c10_f_x;
  real_T c10_b_b;
  real_T c10_c_y;
  real_T c10_g_x;
  real_T c10_h_x;
  real_T c10_a;
  real_T c10_c_b;
  real_T c10_d_y;
  real_T c10_b_A;
  real_T c10_i_x;
  real_T c10_j_x;
  real_T c10_e_y;
  real_T c10_k_x;
  real_T c10_l_x;
  real_T c10_d_b;
  real_T c10_f_y;
  real_T c10_m_x;
  real_T c10_n_x;
  real_T c10_b_a;
  real_T c10_e_b;
  real_T c10_g_y;
  real_T c10_c_A;
  real_T c10_o_x;
  real_T c10_p_x;
  real_T c10_h_y;
  real_T c10_q_x;
  real_T c10_r_x;
  real_T c10_f_b;
  real_T c10_i_y;
  real_T c10_s_x;
  real_T c10_t_x;
  real_T c10_u_x;
  real_T c10_v_x;
  real_T c10_c_a;
  real_T c10_g_b;
  real_T c10_j_y;
  real_T c10_w_x;
  real_T c10_x_x;
  real_T c10_d_a;
  real_T c10_h_b;
  real_T c10_k_y;
  real_T c10_y_x;
  real_T c10_ab_x;
  real_T c10_bb_x;
  real_T c10_cb_x;
  real_T c10_e_a;
  real_T c10_i_b;
  real_T c10_l_y;
  real_T c10_db_x;
  real_T c10_eb_x;
  real_T c10_f_a;
  real_T c10_j_b;
  real_T c10_m_y;
  real_T c10_g_a;
  real_T c10_k_b;
  real_T c10_n_y;
  real_T c10_d_A;
  real_T c10_fb_x;
  real_T c10_gb_x;
  real_T c10_o_y;
  real_T c10_hb_x;
  real_T c10_ib_x;
  real_T c10_l_b;
  real_T c10_p_y;
  real_T c10_jb_x;
  real_T c10_kb_x;
  real_T c10_lb_x;
  real_T c10_mb_x;
  real_T c10_h_a;
  real_T c10_m_b;
  real_T c10_q_y;
  real_T c10_nb_x;
  real_T c10_ob_x;
  real_T c10_i_a;
  real_T c10_n_b;
  real_T c10_r_y;
  real_T c10_pb_x;
  real_T c10_qb_x;
  real_T c10_rb_x;
  real_T c10_sb_x;
  real_T c10_j_a;
  real_T c10_o_b;
  real_T c10_s_y;
  real_T c10_tb_x;
  real_T c10_ub_x;
  real_T c10_k_a;
  real_T c10_p_b;
  real_T c10_t_y;
  real_T c10_l_a;
  real_T c10_q_b;
  real_T c10_u_y;
  real_T c10_e_A;
  real_T c10_vb_x;
  real_T c10_wb_x;
  real_T c10_v_y;
  real_T c10_xb_x;
  real_T c10_yb_x;
  real_T c10_r_b;
  real_T c10_w_y;
  real_T c10_ac_x;
  real_T c10_bc_x;
  real_T c10_cc_x;
  real_T c10_dc_x;
  real_T c10_ec_x;
  real_T c10_fc_x;
  real_T c10_m_a;
  real_T c10_s_b;
  real_T c10_x_y;
  real_T c10_gc_x;
  real_T c10_hc_x;
  real_T c10_n_a;
  real_T c10_t_b;
  real_T c10_y_y;
  real_T c10_ic_x;
  real_T c10_jc_x;
  real_T c10_kc_x;
  real_T c10_lc_x;
  real_T c10_o_a;
  real_T c10_u_b;
  real_T c10_ab_y;
  real_T c10_mc_x;
  real_T c10_nc_x;
  real_T c10_p_a;
  real_T c10_v_b;
  real_T c10_bb_y;
  real_T c10_q_a;
  real_T c10_w_b;
  real_T c10_cb_y;
  real_T c10_oc_x;
  real_T c10_pc_x;
  real_T c10_qc_x;
  real_T c10_rc_x;
  real_T c10_sc_x;
  real_T c10_tc_x;
  real_T c10_r_a;
  real_T c10_x_b;
  real_T c10_db_y;
  real_T c10_uc_x;
  real_T c10_vc_x;
  real_T c10_s_a;
  real_T c10_y_b;
  real_T c10_eb_y;
  real_T c10_wc_x;
  real_T c10_xc_x;
  real_T c10_yc_x;
  real_T c10_ad_x;
  real_T c10_t_a;
  real_T c10_ab_b;
  real_T c10_fb_y;
  real_T c10_bd_x;
  real_T c10_cd_x;
  real_T c10_u_a;
  real_T c10_bb_b;
  real_T c10_gb_y;
  real_T c10_v_a;
  real_T c10_cb_b;
  real_T c10_hb_y;
  real_T c10_w_a;
  real_T c10_db_b;
  real_T c10_ib_y;
  real_T c10_f_A;
  real_T c10_dd_x;
  real_T c10_ed_x;
  real_T c10_jb_y;
  real_T c10_fd_x;
  real_T c10_gd_x;
  real_T c10_eb_b;
  real_T c10_kb_y;
  real_T c10_hd_x;
  real_T c10_id_x;
  real_T c10_x_a;
  real_T c10_fb_b;
  real_T c10_lb_y;
  real_T c10_jd_x;
  real_T c10_kd_x;
  real_T c10_y_a;
  real_T c10_gb_b;
  real_T c10_mb_y;
  real_T c10_g_A;
  real_T c10_ld_x;
  real_T c10_md_x;
  real_T c10_nb_y;
  real_T c10_nd_x;
  real_T c10_od_x;
  real_T c10_hb_b;
  real_T c10_ob_y;
  real_T c10_pd_x;
  real_T c10_qd_x;
  real_T c10_ab_a;
  real_T c10_ib_b;
  real_T c10_pb_y;
  real_T c10_rd_x;
  real_T c10_sd_x;
  real_T c10_bb_a;
  real_T c10_jb_b;
  real_T c10_qb_y;
  real_T c10_h_A;
  real_T c10_td_x;
  real_T c10_ud_x;
  real_T c10_rb_y;
  real_T c10_vd_x;
  real_T c10_wd_x;
  real_T c10_kb_b;
  real_T c10_sb_y;
  real_T c10_xd_x;
  real_T c10_yd_x;
  real_T c10_cb_a;
  real_T c10_lb_b;
  real_T c10_tb_y;
  real_T c10_i_A;
  real_T c10_ae_x;
  real_T c10_be_x;
  real_T c10_ub_y;
  real_T c10_ce_x;
  real_T c10_de_x;
  real_T c10_mb_b;
  real_T c10_vb_y;
  real_T c10_ee_x;
  real_T c10_fe_x;
  real_T c10_ge_x;
  real_T c10_he_x;
  real_T c10_db_a;
  real_T c10_nb_b;
  real_T c10_wb_y;
  real_T c10_ie_x;
  real_T c10_je_x;
  real_T c10_eb_a;
  real_T c10_ob_b;
  real_T c10_xb_y;
  real_T c10_ke_x;
  real_T c10_le_x;
  real_T c10_me_x;
  real_T c10_ne_x;
  real_T c10_fb_a;
  real_T c10_pb_b;
  real_T c10_yb_y;
  real_T c10_oe_x;
  real_T c10_pe_x;
  real_T c10_gb_a;
  real_T c10_qb_b;
  real_T c10_ac_y;
  real_T c10_hb_a;
  real_T c10_rb_b;
  real_T c10_bc_y;
  real_T c10_j_A;
  real_T c10_qe_x;
  real_T c10_re_x;
  real_T c10_cc_y;
  real_T c10_se_x;
  real_T c10_te_x;
  real_T c10_sb_b;
  real_T c10_dc_y;
  real_T c10_ue_x;
  real_T c10_ve_x;
  real_T c10_we_x;
  real_T c10_xe_x;
  real_T c10_ib_a;
  real_T c10_tb_b;
  real_T c10_ec_y;
  real_T c10_ye_x;
  real_T c10_af_x;
  real_T c10_jb_a;
  real_T c10_ub_b;
  real_T c10_fc_y;
  real_T c10_bf_x;
  real_T c10_cf_x;
  real_T c10_df_x;
  real_T c10_ef_x;
  real_T c10_kb_a;
  real_T c10_vb_b;
  real_T c10_gc_y;
  real_T c10_ff_x;
  real_T c10_gf_x;
  real_T c10_lb_a;
  real_T c10_wb_b;
  real_T c10_hc_y;
  real_T c10_mb_a;
  real_T c10_xb_b;
  real_T c10_ic_y;
  real_T c10_k_A;
  real_T c10_hf_x;
  real_T c10_if_x;
  real_T c10_jc_y;
  real_T c10_jf_x;
  real_T c10_kf_x;
  real_T c10_yb_b;
  real_T c10_kc_y;
  real_T c10_lf_x;
  real_T c10_mf_x;
  real_T c10_nf_x;
  real_T c10_of_x;
  real_T c10_pf_x;
  real_T c10_qf_x;
  real_T c10_nb_a;
  real_T c10_ac_b;
  real_T c10_lc_y;
  real_T c10_rf_x;
  real_T c10_sf_x;
  real_T c10_ob_a;
  real_T c10_bc_b;
  real_T c10_mc_y;
  real_T c10_tf_x;
  real_T c10_uf_x;
  real_T c10_vf_x;
  real_T c10_wf_x;
  real_T c10_pb_a;
  real_T c10_cc_b;
  real_T c10_nc_y;
  real_T c10_xf_x;
  real_T c10_yf_x;
  real_T c10_qb_a;
  real_T c10_dc_b;
  real_T c10_oc_y;
  real_T c10_rb_a;
  real_T c10_ec_b;
  real_T c10_pc_y;
  real_T c10_ag_x;
  real_T c10_bg_x;
  real_T c10_cg_x;
  real_T c10_dg_x;
  real_T c10_eg_x;
  real_T c10_fg_x;
  real_T c10_sb_a;
  real_T c10_fc_b;
  real_T c10_qc_y;
  real_T c10_gg_x;
  real_T c10_hg_x;
  real_T c10_tb_a;
  real_T c10_gc_b;
  real_T c10_rc_y;
  real_T c10_ig_x;
  real_T c10_jg_x;
  real_T c10_kg_x;
  real_T c10_lg_x;
  real_T c10_ub_a;
  real_T c10_hc_b;
  real_T c10_sc_y;
  real_T c10_mg_x;
  real_T c10_ng_x;
  real_T c10_vb_a;
  real_T c10_ic_b;
  real_T c10_tc_y;
  real_T c10_wb_a;
  real_T c10_jc_b;
  real_T c10_uc_y;
  real_T c10_xb_a;
  real_T c10_kc_b;
  real_T c10_vc_y;
  real_T c10_l_A;
  real_T c10_og_x;
  real_T c10_pg_x;
  real_T c10_wc_y;
  real_T c10_qg_x;
  real_T c10_rg_x;
  real_T c10_lc_b;
  real_T c10_xc_y;
  real_T c10_sg_x;
  real_T c10_tg_x;
  real_T c10_yb_a;
  real_T c10_mc_b;
  real_T c10_yc_y;
  real_T c10_ug_x;
  real_T c10_vg_x;
  real_T c10_ac_a;
  real_T c10_nc_b;
  real_T c10_ad_y;
  real_T c10_m_A;
  real_T c10_wg_x;
  real_T c10_xg_x;
  real_T c10_bd_y;
  real_T c10_yg_x;
  real_T c10_ah_x;
  real_T c10_oc_b;
  real_T c10_cd_y;
  real_T c10_bh_x;
  real_T c10_ch_x;
  real_T c10_bc_a;
  real_T c10_pc_b;
  real_T c10_dd_y;
  real_T c10_dh_x;
  real_T c10_eh_x;
  real_T c10_cc_a;
  real_T c10_qc_b;
  real_T c10_ed_y;
  real_T c10_n_A;
  real_T c10_fh_x;
  real_T c10_gh_x;
  real_T c10_fd_y;
  real_T c10_hh_x;
  real_T c10_ih_x;
  real_T c10_rc_b;
  real_T c10_gd_y;
  real_T c10_jh_x;
  real_T c10_kh_x;
  real_T c10_lh_x;
  real_T c10_mh_x;
  real_T c10_nh_x;
  real_T c10_oh_x;
  real_T c10_dc_a;
  real_T c10_sc_b;
  real_T c10_hd_y;
  real_T c10_ph_x;
  real_T c10_qh_x;
  real_T c10_ec_a;
  real_T c10_tc_b;
  real_T c10_id_y;
  real_T c10_rh_x;
  real_T c10_sh_x;
  real_T c10_th_x;
  real_T c10_uh_x;
  real_T c10_fc_a;
  real_T c10_uc_b;
  real_T c10_jd_y;
  real_T c10_vh_x;
  real_T c10_wh_x;
  real_T c10_gc_a;
  real_T c10_vc_b;
  real_T c10_kd_y;
  real_T c10_hc_a;
  real_T c10_wc_b;
  real_T c10_ld_y;
  real_T c10_xh_x;
  real_T c10_yh_x;
  real_T c10_ai_x;
  real_T c10_bi_x;
  real_T c10_ci_x;
  real_T c10_di_x;
  real_T c10_ic_a;
  real_T c10_xc_b;
  real_T c10_md_y;
  real_T c10_ei_x;
  real_T c10_fi_x;
  real_T c10_jc_a;
  real_T c10_yc_b;
  real_T c10_nd_y;
  real_T c10_gi_x;
  real_T c10_hi_x;
  real_T c10_ii_x;
  real_T c10_ji_x;
  real_T c10_kc_a;
  real_T c10_ad_b;
  real_T c10_od_y;
  real_T c10_ki_x;
  real_T c10_li_x;
  real_T c10_lc_a;
  real_T c10_bd_b;
  real_T c10_pd_y;
  real_T c10_mc_a;
  real_T c10_cd_b;
  real_T c10_qd_y;
  real_T c10_nc_a;
  real_T c10_dd_b;
  real_T c10_rd_y;
  real_T c10_o_A;
  real_T c10_mi_x;
  real_T c10_ni_x;
  real_T c10_sd_y;
  real_T c10_oi_x;
  real_T c10_pi_x;
  real_T c10_ed_b;
  real_T c10_td_y;
  real_T c10_qi_x;
  real_T c10_ri_x;
  real_T c10_si_x;
  real_T c10_ti_x;
  real_T c10_oc_a;
  real_T c10_fd_b;
  real_T c10_ud_y;
  real_T c10_ui_x;
  real_T c10_vi_x;
  real_T c10_pc_a;
  real_T c10_gd_b;
  real_T c10_vd_y;
  real_T c10_wi_x;
  real_T c10_xi_x;
  real_T c10_yi_x;
  real_T c10_aj_x;
  real_T c10_qc_a;
  real_T c10_hd_b;
  real_T c10_wd_y;
  real_T c10_bj_x;
  real_T c10_cj_x;
  real_T c10_rc_a;
  real_T c10_id_b;
  real_T c10_xd_y;
  real_T c10_sc_a;
  real_T c10_jd_b;
  real_T c10_yd_y;
  real_T c10_p_A;
  real_T c10_dj_x;
  real_T c10_ej_x;
  real_T c10_ae_y;
  real_T c10_fj_x;
  real_T c10_gj_x;
  real_T c10_kd_b;
  real_T c10_be_y;
  real_T c10_hj_x;
  real_T c10_ij_x;
  real_T c10_jj_x;
  real_T c10_kj_x;
  real_T c10_tc_a;
  real_T c10_ld_b;
  real_T c10_ce_y;
  real_T c10_lj_x;
  real_T c10_mj_x;
  real_T c10_uc_a;
  real_T c10_md_b;
  real_T c10_de_y;
  real_T c10_nj_x;
  real_T c10_oj_x;
  real_T c10_pj_x;
  real_T c10_qj_x;
  real_T c10_vc_a;
  real_T c10_nd_b;
  real_T c10_ee_y;
  real_T c10_rj_x;
  real_T c10_sj_x;
  real_T c10_wc_a;
  real_T c10_od_b;
  real_T c10_fe_y;
  real_T c10_xc_a;
  real_T c10_pd_b;
  real_T c10_ge_y;
  real_T c10_q_A;
  real_T c10_tj_x;
  real_T c10_uj_x;
  real_T c10_he_y;
  real_T c10_vj_x;
  real_T c10_wj_x;
  real_T c10_qd_b;
  real_T c10_ie_y;
  real_T c10_xj_x;
  real_T c10_yj_x;
  real_T c10_yc_a;
  real_T c10_rd_b;
  real_T c10_je_y;
  real_T c10_ak_x;
  real_T c10_bk_x;
  real_T c10_ad_a;
  real_T c10_sd_b;
  real_T c10_ke_y;
  real_T c10_r_A;
  real_T c10_ck_x;
  real_T c10_dk_x;
  real_T c10_le_y;
  real_T c10_ek_x;
  real_T c10_fk_x;
  real_T c10_td_b;
  real_T c10_me_y;
  real_T c10_gk_x;
  real_T c10_hk_x;
  real_T c10_bd_a;
  real_T c10_ud_b;
  real_T c10_ne_y;
  real_T c10_ik_x;
  real_T c10_jk_x;
  real_T c10_cd_a;
  real_T c10_vd_b;
  real_T c10_oe_y;
  real_T c10_s_A;
  real_T c10_kk_x;
  real_T c10_lk_x;
  real_T c10_pe_y;
  real_T c10_mk_x;
  real_T c10_nk_x;
  real_T c10_wd_b;
  real_T c10_qe_y;
  real_T c10_ok_x;
  real_T c10_pk_x;
  real_T c10_qk_x;
  real_T c10_rk_x;
  real_T c10_sk_x;
  real_T c10_tk_x;
  real_T c10_dd_a;
  real_T c10_xd_b;
  real_T c10_re_y;
  real_T c10_uk_x;
  real_T c10_vk_x;
  real_T c10_ed_a;
  real_T c10_yd_b;
  real_T c10_se_y;
  real_T c10_wk_x;
  real_T c10_xk_x;
  real_T c10_yk_x;
  real_T c10_al_x;
  real_T c10_fd_a;
  real_T c10_ae_b;
  real_T c10_te_y;
  real_T c10_bl_x;
  real_T c10_cl_x;
  real_T c10_gd_a;
  real_T c10_be_b;
  real_T c10_ue_y;
  real_T c10_hd_a;
  real_T c10_ce_b;
  real_T c10_ve_y;
  real_T c10_dl_x;
  real_T c10_el_x;
  real_T c10_fl_x;
  real_T c10_gl_x;
  real_T c10_hl_x;
  real_T c10_il_x;
  real_T c10_id_a;
  real_T c10_de_b;
  real_T c10_we_y;
  real_T c10_jl_x;
  real_T c10_kl_x;
  real_T c10_jd_a;
  real_T c10_ee_b;
  real_T c10_xe_y;
  real_T c10_ll_x;
  real_T c10_ml_x;
  real_T c10_nl_x;
  real_T c10_ol_x;
  real_T c10_kd_a;
  real_T c10_fe_b;
  real_T c10_ye_y;
  real_T c10_pl_x;
  real_T c10_ql_x;
  real_T c10_ld_a;
  real_T c10_ge_b;
  real_T c10_af_y;
  real_T c10_md_a;
  real_T c10_he_b;
  real_T c10_bf_y;
  real_T c10_nd_a;
  real_T c10_ie_b;
  real_T c10_cf_y;
  real_T c10_t_A;
  real_T c10_rl_x;
  real_T c10_sl_x;
  real_T c10_df_y;
  real_T c10_tl_x;
  real_T c10_ul_x;
  real_T c10_je_b;
  real_T c10_ef_y;
  real_T c10_vl_x;
  real_T c10_wl_x;
  real_T c10_xl_x;
  real_T c10_yl_x;
  real_T c10_od_a;
  real_T c10_ke_b;
  real_T c10_ff_y;
  real_T c10_am_x;
  real_T c10_bm_x;
  real_T c10_pd_a;
  real_T c10_le_b;
  real_T c10_gf_y;
  real_T c10_cm_x;
  real_T c10_dm_x;
  real_T c10_em_x;
  real_T c10_fm_x;
  real_T c10_qd_a;
  real_T c10_me_b;
  real_T c10_hf_y;
  real_T c10_gm_x;
  real_T c10_hm_x;
  real_T c10_rd_a;
  real_T c10_ne_b;
  real_T c10_if_y;
  real_T c10_sd_a;
  real_T c10_oe_b;
  real_T c10_jf_y;
  real_T c10_u_A;
  real_T c10_im_x;
  real_T c10_jm_x;
  real_T c10_kf_y;
  real_T c10_km_x;
  real_T c10_lm_x;
  real_T c10_pe_b;
  real_T c10_lf_y;
  real_T c10_mm_x;
  real_T c10_nm_x;
  real_T c10_om_x;
  real_T c10_pm_x;
  real_T c10_td_a;
  real_T c10_qe_b;
  real_T c10_mf_y;
  real_T c10_qm_x;
  real_T c10_rm_x;
  real_T c10_ud_a;
  real_T c10_re_b;
  real_T c10_nf_y;
  real_T c10_sm_x;
  real_T c10_tm_x;
  real_T c10_um_x;
  real_T c10_vm_x;
  real_T c10_vd_a;
  real_T c10_se_b;
  real_T c10_of_y;
  real_T c10_wm_x;
  real_T c10_xm_x;
  real_T c10_wd_a;
  real_T c10_te_b;
  real_T c10_pf_y;
  real_T c10_xd_a;
  real_T c10_ue_b;
  real_T c10_qf_y;
  real_T c10_v_A;
  real_T c10_ym_x;
  real_T c10_an_x;
  real_T c10_rf_y;
  real_T c10_bn_x;
  real_T c10_cn_x;
  real_T c10_ve_b;
  real_T c10_sf_y;
  real_T c10_dn_x;
  real_T c10_en_x;
  real_T c10_fn_x;
  real_T c10_gn_x;
  real_T c10_hn_x;
  real_T c10_in_x;
  real_T c10_yd_a;
  real_T c10_we_b;
  real_T c10_tf_y;
  real_T c10_jn_x;
  real_T c10_kn_x;
  real_T c10_ae_a;
  real_T c10_xe_b;
  real_T c10_uf_y;
  real_T c10_ln_x;
  real_T c10_mn_x;
  real_T c10_nn_x;
  real_T c10_on_x;
  real_T c10_be_a;
  real_T c10_ye_b;
  real_T c10_vf_y;
  real_T c10_pn_x;
  real_T c10_qn_x;
  real_T c10_ce_a;
  real_T c10_af_b;
  real_T c10_wf_y;
  real_T c10_de_a;
  real_T c10_bf_b;
  real_T c10_xf_y;
  real_T c10_rn_x;
  real_T c10_sn_x;
  real_T c10_tn_x;
  real_T c10_un_x;
  real_T c10_vn_x;
  real_T c10_wn_x;
  real_T c10_ee_a;
  real_T c10_cf_b;
  real_T c10_yf_y;
  real_T c10_xn_x;
  real_T c10_yn_x;
  real_T c10_fe_a;
  real_T c10_df_b;
  real_T c10_ag_y;
  real_T c10_ao_x;
  real_T c10_bo_x;
  real_T c10_co_x;
  real_T c10_do_x;
  real_T c10_ge_a;
  real_T c10_ef_b;
  real_T c10_bg_y;
  real_T c10_eo_x;
  real_T c10_fo_x;
  real_T c10_he_a;
  real_T c10_ff_b;
  real_T c10_cg_y;
  real_T c10_ie_a;
  real_T c10_gf_b;
  real_T c10_dg_y;
  real_T c10_je_a;
  real_T c10_hf_b;
  real_T c10_eg_y;
  real_T c10_w_A;
  real_T c10_go_x;
  real_T c10_ho_x;
  real_T c10_fg_y;
  real_T c10_io_x;
  real_T c10_jo_x;
  real_T c10_if_b;
  real_T c10_gg_y;
  real_T c10_ko_x;
  real_T c10_lo_x;
  real_T c10_ke_a;
  real_T c10_jf_b;
  real_T c10_hg_y;
  real_T c10_x_A;
  real_T c10_mo_x;
  real_T c10_no_x;
  real_T c10_ig_y;
  real_T c10_oo_x;
  real_T c10_po_x;
  real_T c10_kf_b;
  real_T c10_jg_y;
  real_T c10_y_A;
  real_T c10_qo_x;
  real_T c10_ro_x;
  real_T c10_kg_y;
  real_T c10_so_x;
  real_T c10_to_x;
  real_T c10_lf_b;
  real_T c10_lg_y;
  real_T c10_uo_x;
  real_T c10_vo_x;
  real_T c10_le_a;
  real_T c10_mf_b;
  real_T c10_mg_y;
  real_T c10_ab_A;
  real_T c10_wo_x;
  real_T c10_xo_x;
  real_T c10_ng_y;
  real_T c10_yo_x;
  real_T c10_ap_x;
  real_T c10_nf_b;
  real_T c10_og_y;
  real_T c10_bp_x;
  real_T c10_cp_x;
  real_T c10_me_a;
  real_T c10_of_b;
  real_T c10_pg_y;
  real_T c10_bb_A;
  real_T c10_dp_x;
  real_T c10_ep_x;
  real_T c10_qg_y;
  real_T c10_fp_x;
  real_T c10_gp_x;
  real_T c10_pf_b;
  real_T c10_rg_y;
  real_T c10_hp_x;
  real_T c10_ip_x;
  real_T c10_jp_x;
  real_T c10_kp_x;
  real_T c10_ne_a;
  real_T c10_qf_b;
  real_T c10_sg_y;
  real_T c10_lp_x;
  real_T c10_mp_x;
  real_T c10_oe_a;
  real_T c10_rf_b;
  real_T c10_tg_y;
  real_T c10_np_x;
  real_T c10_op_x;
  real_T c10_pp_x;
  real_T c10_qp_x;
  real_T c10_pe_a;
  real_T c10_sf_b;
  real_T c10_ug_y;
  real_T c10_rp_x;
  real_T c10_sp_x;
  real_T c10_qe_a;
  real_T c10_tf_b;
  real_T c10_vg_y;
  real_T c10_re_a;
  real_T c10_uf_b;
  real_T c10_wg_y;
  real_T c10_cb_A;
  real_T c10_tp_x;
  real_T c10_up_x;
  real_T c10_xg_y;
  real_T c10_vp_x;
  real_T c10_wp_x;
  real_T c10_vf_b;
  real_T c10_yg_y;
  real_T c10_xp_x;
  real_T c10_yp_x;
  real_T c10_aq_x;
  real_T c10_bq_x;
  real_T c10_se_a;
  real_T c10_wf_b;
  real_T c10_ah_y;
  real_T c10_cq_x;
  real_T c10_dq_x;
  real_T c10_te_a;
  real_T c10_xf_b;
  real_T c10_bh_y;
  real_T c10_eq_x;
  real_T c10_fq_x;
  real_T c10_gq_x;
  real_T c10_hq_x;
  real_T c10_ue_a;
  real_T c10_yf_b;
  real_T c10_ch_y;
  real_T c10_iq_x;
  real_T c10_jq_x;
  real_T c10_ve_a;
  real_T c10_ag_b;
  real_T c10_dh_y;
  real_T c10_we_a;
  real_T c10_bg_b;
  real_T c10_eh_y;
  real_T c10_db_A;
  real_T c10_kq_x;
  real_T c10_lq_x;
  real_T c10_fh_y;
  real_T c10_mq_x;
  real_T c10_nq_x;
  real_T c10_cg_b;
  real_T c10_gh_y;
  real_T c10_oq_x;
  real_T c10_pq_x;
  real_T c10_qq_x;
  real_T c10_rq_x;
  real_T c10_sq_x;
  real_T c10_tq_x;
  real_T c10_xe_a;
  real_T c10_dg_b;
  real_T c10_hh_y;
  real_T c10_uq_x;
  real_T c10_vq_x;
  real_T c10_ye_a;
  real_T c10_eg_b;
  real_T c10_ih_y;
  real_T c10_wq_x;
  real_T c10_xq_x;
  real_T c10_yq_x;
  real_T c10_ar_x;
  real_T c10_af_a;
  real_T c10_fg_b;
  real_T c10_jh_y;
  real_T c10_br_x;
  real_T c10_cr_x;
  real_T c10_bf_a;
  real_T c10_gg_b;
  real_T c10_kh_y;
  real_T c10_cf_a;
  real_T c10_hg_b;
  real_T c10_lh_y;
  real_T c10_dr_x;
  real_T c10_er_x;
  real_T c10_fr_x;
  real_T c10_gr_x;
  real_T c10_hr_x;
  real_T c10_ir_x;
  real_T c10_df_a;
  real_T c10_ig_b;
  real_T c10_mh_y;
  real_T c10_jr_x;
  real_T c10_kr_x;
  real_T c10_ef_a;
  real_T c10_jg_b;
  real_T c10_nh_y;
  real_T c10_lr_x;
  real_T c10_mr_x;
  real_T c10_nr_x;
  real_T c10_or_x;
  real_T c10_ff_a;
  real_T c10_kg_b;
  real_T c10_oh_y;
  real_T c10_pr_x;
  real_T c10_qr_x;
  real_T c10_gf_a;
  real_T c10_lg_b;
  real_T c10_ph_y;
  real_T c10_hf_a;
  real_T c10_mg_b;
  real_T c10_qh_y;
  real_T c10_if_a;
  real_T c10_ng_b;
  real_T c10_rh_y;
  real_T c10_eb_A;
  real_T c10_rr_x;
  real_T c10_sr_x;
  real_T c10_sh_y;
  real_T c10_tr_x;
  real_T c10_ur_x;
  real_T c10_og_b;
  real_T c10_th_y;
  real_T c10_vr_x;
  real_T c10_wr_x;
  real_T c10_jf_a;
  real_T c10_pg_b;
  real_T c10_uh_y;
  real_T c10_xr_x;
  real_T c10_yr_x;
  real_T c10_kf_a;
  real_T c10_qg_b;
  real_T c10_vh_y;
  real_T c10_fb_A;
  real_T c10_as_x;
  real_T c10_bs_x;
  real_T c10_wh_y;
  real_T c10_cs_x;
  real_T c10_ds_x;
  real_T c10_rg_b;
  real_T c10_xh_y;
  real_T c10_es_x;
  real_T c10_fs_x;
  real_T c10_lf_a;
  real_T c10_sg_b;
  real_T c10_yh_y;
  real_T c10_gs_x;
  real_T c10_hs_x;
  real_T c10_mf_a;
  real_T c10_tg_b;
  real_T c10_ai_y;
  real_T c10_gb_A;
  real_T c10_is_x;
  real_T c10_js_x;
  real_T c10_bi_y;
  real_T c10_ks_x;
  real_T c10_ls_x;
  real_T c10_ug_b;
  real_T c10_ci_y;
  real_T c10_ms_x;
  real_T c10_ns_x;
  real_T c10_nf_a;
  real_T c10_vg_b;
  real_T c10_di_y;
  real_T c10_hb_A;
  real_T c10_os_x;
  real_T c10_ps_x;
  real_T c10_ei_y;
  real_T c10_qs_x;
  real_T c10_rs_x;
  real_T c10_wg_b;
  real_T c10_fi_y;
  real_T c10_ss_x;
  real_T c10_ts_x;
  real_T c10_us_x;
  real_T c10_vs_x;
  real_T c10_of_a;
  real_T c10_xg_b;
  real_T c10_gi_y;
  real_T c10_ws_x;
  real_T c10_xs_x;
  real_T c10_pf_a;
  real_T c10_yg_b;
  real_T c10_hi_y;
  real_T c10_ys_x;
  real_T c10_at_x;
  real_T c10_bt_x;
  real_T c10_ct_x;
  real_T c10_qf_a;
  real_T c10_ah_b;
  real_T c10_ii_y;
  real_T c10_dt_x;
  real_T c10_et_x;
  real_T c10_rf_a;
  real_T c10_bh_b;
  real_T c10_ji_y;
  real_T c10_sf_a;
  real_T c10_ch_b;
  real_T c10_ki_y;
  real_T c10_ib_A;
  real_T c10_ft_x;
  real_T c10_gt_x;
  real_T c10_li_y;
  real_T c10_ht_x;
  real_T c10_it_x;
  real_T c10_dh_b;
  real_T c10_mi_y;
  real_T c10_jt_x;
  real_T c10_kt_x;
  real_T c10_lt_x;
  real_T c10_mt_x;
  real_T c10_tf_a;
  real_T c10_eh_b;
  real_T c10_ni_y;
  real_T c10_nt_x;
  real_T c10_ot_x;
  real_T c10_uf_a;
  real_T c10_fh_b;
  real_T c10_oi_y;
  real_T c10_pt_x;
  real_T c10_qt_x;
  real_T c10_rt_x;
  real_T c10_st_x;
  real_T c10_vf_a;
  real_T c10_gh_b;
  real_T c10_pi_y;
  real_T c10_tt_x;
  real_T c10_ut_x;
  real_T c10_wf_a;
  real_T c10_hh_b;
  real_T c10_qi_y;
  real_T c10_xf_a;
  real_T c10_ih_b;
  real_T c10_ri_y;
  real_T c10_jb_A;
  real_T c10_vt_x;
  real_T c10_wt_x;
  real_T c10_si_y;
  real_T c10_xt_x;
  real_T c10_yt_x;
  real_T c10_jh_b;
  real_T c10_ti_y;
  real_T c10_au_x;
  real_T c10_bu_x;
  real_T c10_cu_x;
  real_T c10_du_x;
  real_T c10_eu_x;
  real_T c10_fu_x;
  real_T c10_yf_a;
  real_T c10_kh_b;
  real_T c10_ui_y;
  real_T c10_gu_x;
  real_T c10_hu_x;
  real_T c10_ag_a;
  real_T c10_lh_b;
  real_T c10_vi_y;
  real_T c10_iu_x;
  real_T c10_ju_x;
  real_T c10_ku_x;
  real_T c10_lu_x;
  real_T c10_bg_a;
  real_T c10_mh_b;
  real_T c10_wi_y;
  real_T c10_mu_x;
  real_T c10_nu_x;
  real_T c10_cg_a;
  real_T c10_nh_b;
  real_T c10_xi_y;
  real_T c10_dg_a;
  real_T c10_oh_b;
  real_T c10_yi_y;
  real_T c10_ou_x;
  real_T c10_pu_x;
  real_T c10_qu_x;
  real_T c10_ru_x;
  real_T c10_su_x;
  real_T c10_tu_x;
  real_T c10_eg_a;
  real_T c10_ph_b;
  real_T c10_aj_y;
  real_T c10_uu_x;
  real_T c10_vu_x;
  real_T c10_fg_a;
  real_T c10_qh_b;
  real_T c10_bj_y;
  real_T c10_wu_x;
  real_T c10_xu_x;
  real_T c10_yu_x;
  real_T c10_av_x;
  real_T c10_gg_a;
  real_T c10_rh_b;
  real_T c10_cj_y;
  real_T c10_bv_x;
  real_T c10_cv_x;
  real_T c10_hg_a;
  real_T c10_sh_b;
  real_T c10_dj_y;
  real_T c10_ig_a;
  real_T c10_th_b;
  real_T c10_ej_y;
  real_T c10_jg_a;
  real_T c10_uh_b;
  real_T c10_fj_y;
  real_T c10_kb_A;
  real_T c10_dv_x;
  real_T c10_ev_x;
  real_T c10_gj_y;
  real_T c10_fv_x;
  real_T c10_gv_x;
  real_T c10_vh_b;
  real_T c10_hj_y;
  real_T c10_hv_x;
  real_T c10_iv_x;
  real_T c10_kg_a;
  real_T c10_wh_b;
  real_T c10_ij_y;
  real_T c10_jv_x;
  real_T c10_kv_x;
  real_T c10_lg_a;
  real_T c10_xh_b;
  real_T c10_jj_y;
  real_T c10_lb_A;
  real_T c10_lv_x;
  real_T c10_mv_x;
  real_T c10_kj_y;
  real_T c10_nv_x;
  real_T c10_ov_x;
  real_T c10_yh_b;
  real_T c10_lj_y;
  real_T c10_pv_x;
  real_T c10_qv_x;
  real_T c10_mg_a;
  real_T c10_ai_b;
  real_T c10_mj_y;
  real_T c10_rv_x;
  real_T c10_sv_x;
  real_T c10_ng_a;
  real_T c10_bi_b;
  real_T c10_nj_y;
  real_T c10_mb_A;
  real_T c10_tv_x;
  real_T c10_uv_x;
  real_T c10_oj_y;
  real_T c10_vv_x;
  real_T c10_wv_x;
  real_T c10_ci_b;
  real_T c10_pj_y;
  real_T c10_xv_x;
  real_T c10_yv_x;
  real_T c10_aw_x;
  real_T c10_bw_x;
  real_T c10_cw_x;
  real_T c10_dw_x;
  real_T c10_og_a;
  real_T c10_di_b;
  real_T c10_qj_y;
  real_T c10_ew_x;
  real_T c10_fw_x;
  real_T c10_pg_a;
  real_T c10_ei_b;
  real_T c10_rj_y;
  real_T c10_gw_x;
  real_T c10_hw_x;
  real_T c10_iw_x;
  real_T c10_jw_x;
  real_T c10_qg_a;
  real_T c10_fi_b;
  real_T c10_sj_y;
  real_T c10_kw_x;
  real_T c10_lw_x;
  real_T c10_rg_a;
  real_T c10_gi_b;
  real_T c10_tj_y;
  real_T c10_sg_a;
  real_T c10_hi_b;
  real_T c10_uj_y;
  real_T c10_mw_x;
  real_T c10_nw_x;
  real_T c10_ow_x;
  real_T c10_pw_x;
  real_T c10_qw_x;
  real_T c10_rw_x;
  real_T c10_tg_a;
  real_T c10_ii_b;
  real_T c10_vj_y;
  real_T c10_sw_x;
  real_T c10_tw_x;
  real_T c10_ug_a;
  real_T c10_ji_b;
  real_T c10_wj_y;
  real_T c10_uw_x;
  real_T c10_vw_x;
  real_T c10_ww_x;
  real_T c10_xw_x;
  real_T c10_vg_a;
  real_T c10_ki_b;
  real_T c10_xj_y;
  real_T c10_yw_x;
  real_T c10_ax_x;
  real_T c10_wg_a;
  real_T c10_li_b;
  real_T c10_yj_y;
  real_T c10_xg_a;
  real_T c10_mi_b;
  real_T c10_ak_y;
  real_T c10_yg_a;
  real_T c10_ni_b;
  real_T c10_bk_y;
  real_T c10_nb_A;
  real_T c10_bx_x;
  real_T c10_cx_x;
  real_T c10_ck_y;
  real_T c10_dx_x;
  real_T c10_ex_x;
  real_T c10_oi_b;
  real_T c10_dk_y;
  real_T c10_fx_x;
  real_T c10_gx_x;
  real_T c10_hx_x;
  real_T c10_ix_x;
  real_T c10_ah_a;
  real_T c10_pi_b;
  real_T c10_ek_y;
  real_T c10_jx_x;
  real_T c10_kx_x;
  real_T c10_bh_a;
  real_T c10_qi_b;
  real_T c10_fk_y;
  real_T c10_lx_x;
  real_T c10_mx_x;
  real_T c10_nx_x;
  real_T c10_ox_x;
  real_T c10_ch_a;
  real_T c10_ri_b;
  real_T c10_gk_y;
  real_T c10_px_x;
  real_T c10_qx_x;
  real_T c10_dh_a;
  real_T c10_si_b;
  real_T c10_hk_y;
  real_T c10_eh_a;
  real_T c10_ti_b;
  real_T c10_ik_y;
  real_T c10_ob_A;
  real_T c10_rx_x;
  real_T c10_sx_x;
  real_T c10_jk_y;
  real_T c10_tx_x;
  real_T c10_ux_x;
  real_T c10_ui_b;
  real_T c10_kk_y;
  real_T c10_vx_x;
  real_T c10_wx_x;
  real_T c10_xx_x;
  real_T c10_yx_x;
  real_T c10_fh_a;
  real_T c10_vi_b;
  real_T c10_lk_y;
  real_T c10_ay_x;
  real_T c10_by_x;
  real_T c10_gh_a;
  real_T c10_wi_b;
  real_T c10_mk_y;
  real_T c10_cy_x;
  real_T c10_dy_x;
  real_T c10_ey_x;
  real_T c10_fy_x;
  real_T c10_hh_a;
  real_T c10_xi_b;
  real_T c10_nk_y;
  real_T c10_gy_x;
  real_T c10_hy_x;
  real_T c10_ih_a;
  real_T c10_yi_b;
  real_T c10_ok_y;
  real_T c10_jh_a;
  real_T c10_aj_b;
  real_T c10_pk_y;
  real_T c10_pb_A;
  real_T c10_iy_x;
  real_T c10_jy_x;
  real_T c10_qk_y;
  real_T c10_ky_x;
  real_T c10_ly_x;
  real_T c10_bj_b;
  real_T c10_rk_y;
  real_T c10_my_x;
  real_T c10_ny_x;
  real_T c10_kh_a;
  real_T c10_cj_b;
  real_T c10_sk_y;
  real_T c10_oy_x;
  real_T c10_py_x;
  real_T c10_lh_a;
  real_T c10_dj_b;
  real_T c10_tk_y;
  real_T c10_qb_A;
  real_T c10_qy_x;
  real_T c10_ry_x;
  real_T c10_uk_y;
  real_T c10_sy_x;
  real_T c10_ty_x;
  real_T c10_ej_b;
  real_T c10_vk_y;
  real_T c10_uy_x;
  real_T c10_vy_x;
  real_T c10_mh_a;
  real_T c10_fj_b;
  real_T c10_wk_y;
  real_T c10_wy_x;
  real_T c10_xy_x;
  real_T c10_nh_a;
  real_T c10_gj_b;
  real_T c10_xk_y;
  real_T c10_rb_A;
  real_T c10_yy_x;
  real_T c10_aab_x;
  real_T c10_yk_y;
  real_T c10_bab_x;
  real_T c10_cab_x;
  real_T c10_hj_b;
  real_T c10_al_y;
  real_T c10_dab_x;
  real_T c10_eab_x;
  real_T c10_fab_x;
  real_T c10_gab_x;
  real_T c10_hab_x;
  real_T c10_iab_x;
  real_T c10_oh_a;
  real_T c10_ij_b;
  real_T c10_bl_y;
  real_T c10_jab_x;
  real_T c10_kab_x;
  real_T c10_ph_a;
  real_T c10_jj_b;
  real_T c10_cl_y;
  real_T c10_lab_x;
  real_T c10_mab_x;
  real_T c10_nab_x;
  real_T c10_oab_x;
  real_T c10_qh_a;
  real_T c10_kj_b;
  real_T c10_dl_y;
  real_T c10_pab_x;
  real_T c10_qab_x;
  real_T c10_rh_a;
  real_T c10_lj_b;
  real_T c10_el_y;
  real_T c10_sh_a;
  real_T c10_mj_b;
  real_T c10_fl_y;
  real_T c10_rab_x;
  real_T c10_sab_x;
  real_T c10_tab_x;
  real_T c10_uab_x;
  real_T c10_vab_x;
  real_T c10_wab_x;
  real_T c10_th_a;
  real_T c10_nj_b;
  real_T c10_gl_y;
  real_T c10_xab_x;
  real_T c10_yab_x;
  real_T c10_uh_a;
  real_T c10_oj_b;
  real_T c10_hl_y;
  real_T c10_abb_x;
  real_T c10_bbb_x;
  real_T c10_cbb_x;
  real_T c10_dbb_x;
  real_T c10_vh_a;
  real_T c10_pj_b;
  real_T c10_il_y;
  real_T c10_ebb_x;
  real_T c10_fbb_x;
  real_T c10_wh_a;
  real_T c10_qj_b;
  real_T c10_jl_y;
  real_T c10_xh_a;
  real_T c10_rj_b;
  real_T c10_kl_y;
  real_T c10_yh_a;
  real_T c10_sj_b;
  real_T c10_ll_y;
  real_T c10_sb_A;
  real_T c10_gbb_x;
  real_T c10_hbb_x;
  real_T c10_ml_y;
  real_T c10_ibb_x;
  real_T c10_jbb_x;
  real_T c10_tj_b;
  real_T c10_nl_y;
  real_T c10_kbb_x;
  real_T c10_lbb_x;
  real_T c10_mbb_x;
  real_T c10_nbb_x;
  real_T c10_ai_a;
  real_T c10_uj_b;
  real_T c10_ol_y;
  real_T c10_obb_x;
  real_T c10_pbb_x;
  real_T c10_bi_a;
  real_T c10_vj_b;
  real_T c10_pl_y;
  real_T c10_qbb_x;
  real_T c10_rbb_x;
  real_T c10_sbb_x;
  real_T c10_tbb_x;
  real_T c10_ci_a;
  real_T c10_wj_b;
  real_T c10_ql_y;
  real_T c10_ubb_x;
  real_T c10_vbb_x;
  real_T c10_di_a;
  real_T c10_xj_b;
  real_T c10_rl_y;
  real_T c10_ei_a;
  real_T c10_yj_b;
  real_T c10_sl_y;
  real_T c10_tb_A;
  real_T c10_wbb_x;
  real_T c10_xbb_x;
  real_T c10_tl_y;
  real_T c10_ybb_x;
  real_T c10_acb_x;
  real_T c10_ak_b;
  real_T c10_ul_y;
  real_T c10_bcb_x;
  real_T c10_ccb_x;
  real_T c10_dcb_x;
  real_T c10_ecb_x;
  real_T c10_fi_a;
  real_T c10_bk_b;
  real_T c10_vl_y;
  real_T c10_fcb_x;
  real_T c10_gcb_x;
  real_T c10_gi_a;
  real_T c10_ck_b;
  real_T c10_wl_y;
  real_T c10_hcb_x;
  real_T c10_icb_x;
  real_T c10_jcb_x;
  real_T c10_kcb_x;
  real_T c10_hi_a;
  real_T c10_dk_b;
  real_T c10_xl_y;
  real_T c10_lcb_x;
  real_T c10_mcb_x;
  real_T c10_ii_a;
  real_T c10_ek_b;
  real_T c10_yl_y;
  real_T c10_ji_a;
  real_T c10_fk_b;
  real_T c10_am_y;
  real_T c10_ub_A;
  real_T c10_ncb_x;
  real_T c10_ocb_x;
  real_T c10_bm_y;
  real_T c10_pcb_x;
  real_T c10_qcb_x;
  real_T c10_gk_b;
  real_T c10_cm_y;
  real_T c10_rcb_x;
  real_T c10_scb_x;
  real_T c10_ki_a;
  real_T c10_hk_b;
  real_T c10_dm_y;
  real_T c10_vb_A;
  real_T c10_tcb_x;
  real_T c10_ucb_x;
  real_T c10_em_y;
  real_T c10_vcb_x;
  real_T c10_wcb_x;
  real_T c10_ik_b;
  real_T c10_fm_y;
  real_T c10_xcb_x;
  real_T c10_ycb_x;
  real_T c10_adb_x;
  real_T c10_bdb_x;
  real_T c10_cdb_x;
  real_T c10_ddb_x;
  real_T c10_li_a;
  real_T c10_jk_b;
  real_T c10_gm_y;
  real_T c10_edb_x;
  real_T c10_fdb_x;
  real_T c10_mi_a;
  real_T c10_kk_b;
  real_T c10_hm_y;
  real_T c10_gdb_x;
  real_T c10_hdb_x;
  real_T c10_idb_x;
  real_T c10_jdb_x;
  real_T c10_ni_a;
  real_T c10_lk_b;
  real_T c10_im_y;
  real_T c10_kdb_x;
  real_T c10_ldb_x;
  real_T c10_oi_a;
  real_T c10_mk_b;
  real_T c10_jm_y;
  real_T c10_pi_a;
  real_T c10_nk_b;
  real_T c10_km_y;
  real_T c10_mdb_x;
  real_T c10_ndb_x;
  real_T c10_odb_x;
  real_T c10_pdb_x;
  real_T c10_qdb_x;
  real_T c10_rdb_x;
  real_T c10_qi_a;
  real_T c10_ok_b;
  real_T c10_lm_y;
  real_T c10_sdb_x;
  real_T c10_tdb_x;
  real_T c10_ri_a;
  real_T c10_pk_b;
  real_T c10_mm_y;
  real_T c10_udb_x;
  real_T c10_vdb_x;
  real_T c10_wdb_x;
  real_T c10_xdb_x;
  real_T c10_si_a;
  real_T c10_qk_b;
  real_T c10_nm_y;
  real_T c10_ydb_x;
  real_T c10_aeb_x;
  real_T c10_ti_a;
  real_T c10_rk_b;
  real_T c10_om_y;
  real_T c10_ui_a;
  real_T c10_sk_b;
  real_T c10_pm_y;
  real_T c10_vi_a;
  real_T c10_tk_b;
  real_T c10_qm_y;
  real_T c10_wb_A;
  real_T c10_beb_x;
  real_T c10_ceb_x;
  real_T c10_rm_y;
  real_T c10_deb_x;
  real_T c10_eeb_x;
  real_T c10_uk_b;
  real_T c10_sm_y;
  real_T c10_feb_x;
  real_T c10_geb_x;
  real_T c10_wi_a;
  real_T c10_vk_b;
  real_T c10_tm_y;
  real_T c10_xb_A;
  real_T c10_heb_x;
  real_T c10_ieb_x;
  real_T c10_um_y;
  real_T c10_jeb_x;
  real_T c10_keb_x;
  real_T c10_wk_b;
  real_T c10_vm_y;
  real_T c10_leb_x;
  real_T c10_meb_x;
  real_T c10_xi_a;
  real_T c10_xk_b;
  real_T c10_wm_y;
  real_T c10_yb_A;
  real_T c10_neb_x;
  real_T c10_oeb_x;
  real_T c10_xm_y;
  real_T c10_peb_x;
  real_T c10_qeb_x;
  real_T c10_yk_b;
  real_T c10_ym_y;
  real_T c10_ac_A;
  real_T c10_reb_x;
  real_T c10_seb_x;
  real_T c10_an_y;
  real_T c10_teb_x;
  real_T c10_ueb_x;
  real_T c10_al_b;
  real_T c10_bn_y;
  real_T c10_veb_x;
  real_T c10_web_x;
  real_T c10_xeb_x;
  real_T c10_yeb_x;
  real_T c10_afb_x;
  real_T c10_bfb_x;
  real_T c10_yi_a;
  real_T c10_bl_b;
  real_T c10_cn_y;
  real_T c10_cfb_x;
  real_T c10_dfb_x;
  real_T c10_efb_x;
  real_T c10_ffb_x;
  real_T c10_aj_a;
  real_T c10_cl_b;
  real_T c10_dn_y;
  real_T c10_bj_a;
  real_T c10_dl_b;
  real_T c10_en_y;
  real_T c10_gfb_x;
  real_T c10_hfb_x;
  real_T c10_ifb_x;
  real_T c10_jfb_x;
  real_T c10_kfb_x;
  real_T c10_lfb_x;
  real_T c10_cj_a;
  real_T c10_el_b;
  real_T c10_fn_y;
  real_T c10_mfb_x;
  real_T c10_nfb_x;
  real_T c10_ofb_x;
  real_T c10_pfb_x;
  real_T c10_dj_a;
  real_T c10_fl_b;
  real_T c10_gn_y;
  real_T c10_ej_a;
  real_T c10_gl_b;
  real_T c10_hn_y;
  real_T c10_fj_a;
  real_T c10_hl_b;
  real_T c10_in_y;
  real_T c10_bc_A;
  real_T c10_qfb_x;
  real_T c10_rfb_x;
  real_T c10_jn_y;
  real_T c10_sfb_x;
  real_T c10_tfb_x;
  real_T c10_il_b;
  real_T c10_kn_y;
  real_T c10_ufb_x;
  real_T c10_vfb_x;
  real_T c10_wfb_x;
  real_T c10_xfb_x;
  real_T c10_gj_a;
  real_T c10_jl_b;
  real_T c10_ln_y;
  real_T c10_yfb_x;
  real_T c10_agb_x;
  real_T c10_bgb_x;
  real_T c10_cgb_x;
  real_T c10_hj_a;
  real_T c10_kl_b;
  real_T c10_mn_y;
  real_T c10_ij_a;
  real_T c10_ll_b;
  real_T c10_nn_y;
  real_T c10_cc_A;
  real_T c10_dgb_x;
  real_T c10_egb_x;
  real_T c10_on_y;
  real_T c10_fgb_x;
  real_T c10_ggb_x;
  real_T c10_ml_b;
  real_T c10_pn_y;
  real_T c10_hgb_x;
  real_T c10_igb_x;
  real_T c10_jgb_x;
  real_T c10_kgb_x;
  real_T c10_jj_a;
  real_T c10_nl_b;
  real_T c10_qn_y;
  real_T c10_lgb_x;
  real_T c10_mgb_x;
  real_T c10_ngb_x;
  real_T c10_ogb_x;
  real_T c10_kj_a;
  real_T c10_ol_b;
  real_T c10_rn_y;
  real_T c10_lj_a;
  real_T c10_pl_b;
  real_T c10_sn_y;
  real_T c10_dc_A;
  real_T c10_pgb_x;
  real_T c10_qgb_x;
  real_T c10_tn_y;
  real_T c10_rgb_x;
  real_T c10_sgb_x;
  real_T c10_ql_b;
  real_T c10_un_y;
  real_T c10_tgb_x;
  real_T c10_ugb_x;
  real_T c10_mj_a;
  real_T c10_rl_b;
  real_T c10_vn_y;
  real_T c10_ec_A;
  real_T c10_vgb_x;
  real_T c10_wgb_x;
  real_T c10_wn_y;
  real_T c10_xgb_x;
  real_T c10_ygb_x;
  real_T c10_sl_b;
  real_T c10_xn_y;
  real_T c10_ahb_x;
  real_T c10_bhb_x;
  real_T c10_nj_a;
  real_T c10_tl_b;
  real_T c10_yn_y;
  real_T c10_fc_A;
  real_T c10_chb_x;
  real_T c10_dhb_x;
  real_T c10_ao_y;
  real_T c10_ehb_x;
  real_T c10_fhb_x;
  real_T c10_ul_b;
  real_T c10_bo_y;
  real_T c10_ghb_x;
  real_T c10_hhb_x;
  real_T c10_ihb_x;
  real_T c10_jhb_x;
  real_T c10_khb_x;
  real_T c10_lhb_x;
  real_T c10_oj_a;
  real_T c10_vl_b;
  real_T c10_co_y;
  real_T c10_mhb_x;
  real_T c10_nhb_x;
  real_T c10_ohb_x;
  real_T c10_phb_x;
  real_T c10_pj_a;
  real_T c10_wl_b;
  real_T c10_do_y;
  real_T c10_qj_a;
  real_T c10_xl_b;
  real_T c10_eo_y;
  real_T c10_qhb_x;
  real_T c10_rhb_x;
  real_T c10_shb_x;
  real_T c10_thb_x;
  real_T c10_uhb_x;
  real_T c10_vhb_x;
  real_T c10_rj_a;
  real_T c10_yl_b;
  real_T c10_fo_y;
  real_T c10_whb_x;
  real_T c10_xhb_x;
  real_T c10_yhb_x;
  real_T c10_aib_x;
  real_T c10_sj_a;
  real_T c10_am_b;
  real_T c10_go_y;
  real_T c10_tj_a;
  real_T c10_bm_b;
  real_T c10_ho_y;
  real_T c10_uj_a;
  real_T c10_cm_b;
  real_T c10_io_y;
  real_T c10_gc_A;
  real_T c10_bib_x;
  real_T c10_cib_x;
  real_T c10_jo_y;
  real_T c10_dib_x;
  real_T c10_eib_x;
  real_T c10_dm_b;
  real_T c10_ko_y;
  real_T c10_fib_x;
  real_T c10_gib_x;
  real_T c10_hib_x;
  real_T c10_iib_x;
  real_T c10_vj_a;
  real_T c10_em_b;
  real_T c10_lo_y;
  real_T c10_jib_x;
  real_T c10_kib_x;
  real_T c10_lib_x;
  real_T c10_mib_x;
  real_T c10_wj_a;
  real_T c10_fm_b;
  real_T c10_mo_y;
  real_T c10_xj_a;
  real_T c10_gm_b;
  real_T c10_no_y;
  real_T c10_hc_A;
  real_T c10_nib_x;
  real_T c10_oib_x;
  real_T c10_oo_y;
  real_T c10_pib_x;
  real_T c10_qib_x;
  real_T c10_hm_b;
  real_T c10_po_y;
  real_T c10_rib_x;
  real_T c10_sib_x;
  real_T c10_tib_x;
  real_T c10_uib_x;
  real_T c10_yj_a;
  real_T c10_im_b;
  real_T c10_qo_y;
  real_T c10_vib_x;
  real_T c10_wib_x;
  real_T c10_xib_x;
  real_T c10_yib_x;
  real_T c10_ak_a;
  real_T c10_jm_b;
  real_T c10_ro_y;
  real_T c10_bk_a;
  real_T c10_km_b;
  real_T c10_so_y;
  real_T c10_ic_A;
  real_T c10_ajb_x;
  real_T c10_bjb_x;
  real_T c10_to_y;
  real_T c10_cjb_x;
  real_T c10_djb_x;
  real_T c10_lm_b;
  real_T c10_uo_y;
  real_T c10_ejb_x;
  real_T c10_fjb_x;
  real_T c10_gjb_x;
  real_T c10_hjb_x;
  real_T c10_ck_a;
  real_T c10_mm_b;
  real_T c10_vo_y;
  real_T c10_ijb_x;
  real_T c10_jjb_x;
  real_T c10_kjb_x;
  real_T c10_ljb_x;
  real_T c10_dk_a;
  real_T c10_nm_b;
  real_T c10_wo_y;
  real_T c10_ek_a;
  real_T c10_om_b;
  real_T c10_xo_y;
  real_T c10_jc_A;
  real_T c10_mjb_x;
  real_T c10_njb_x;
  real_T c10_yo_y;
  real_T c10_ojb_x;
  real_T c10_pjb_x;
  real_T c10_pm_b;
  real_T c10_ap_y;
  real_T c10_qjb_x;
  real_T c10_rjb_x;
  real_T c10_sjb_x;
  real_T c10_tjb_x;
  real_T c10_ujb_x;
  real_T c10_vjb_x;
  real_T c10_fk_a;
  real_T c10_qm_b;
  real_T c10_bp_y;
  real_T c10_wjb_x;
  real_T c10_xjb_x;
  real_T c10_yjb_x;
  real_T c10_akb_x;
  real_T c10_gk_a;
  real_T c10_rm_b;
  real_T c10_cp_y;
  real_T c10_hk_a;
  real_T c10_sm_b;
  real_T c10_dp_y;
  real_T c10_bkb_x;
  real_T c10_ckb_x;
  real_T c10_dkb_x;
  real_T c10_ekb_x;
  real_T c10_fkb_x;
  real_T c10_gkb_x;
  real_T c10_ik_a;
  real_T c10_tm_b;
  real_T c10_ep_y;
  real_T c10_hkb_x;
  real_T c10_ikb_x;
  real_T c10_jkb_x;
  real_T c10_kkb_x;
  real_T c10_jk_a;
  real_T c10_um_b;
  real_T c10_fp_y;
  real_T c10_kk_a;
  real_T c10_vm_b;
  real_T c10_gp_y;
  real_T c10_lk_a;
  real_T c10_wm_b;
  real_T c10_hp_y;
  real_T c10_kc_A;
  real_T c10_lkb_x;
  real_T c10_mkb_x;
  real_T c10_ip_y;
  real_T c10_nkb_x;
  real_T c10_okb_x;
  real_T c10_xm_b;
  real_T c10_jp_y;
  real_T c10_pkb_x;
  real_T c10_qkb_x;
  real_T c10_rkb_x;
  real_T c10_skb_x;
  real_T c10_mk_a;
  real_T c10_ym_b;
  real_T c10_kp_y;
  real_T c10_tkb_x;
  real_T c10_ukb_x;
  real_T c10_vkb_x;
  real_T c10_wkb_x;
  real_T c10_nk_a;
  real_T c10_an_b;
  real_T c10_lp_y;
  real_T c10_ok_a;
  real_T c10_bn_b;
  real_T c10_mp_y;
  real_T c10_lc_A;
  real_T c10_xkb_x;
  real_T c10_ykb_x;
  real_T c10_np_y;
  real_T c10_alb_x;
  real_T c10_blb_x;
  real_T c10_cn_b;
  real_T c10_op_y;
  real_T c10_clb_x;
  real_T c10_dlb_x;
  real_T c10_elb_x;
  real_T c10_flb_x;
  real_T c10_glb_x;
  real_T c10_hlb_x;
  real_T c10_pk_a;
  real_T c10_dn_b;
  real_T c10_pp_y;
  real_T c10_ilb_x;
  real_T c10_jlb_x;
  real_T c10_klb_x;
  real_T c10_llb_x;
  real_T c10_qk_a;
  real_T c10_en_b;
  real_T c10_qp_y;
  real_T c10_rk_a;
  real_T c10_fn_b;
  real_T c10_rp_y;
  real_T c10_mlb_x;
  real_T c10_nlb_x;
  real_T c10_olb_x;
  real_T c10_plb_x;
  real_T c10_qlb_x;
  real_T c10_rlb_x;
  real_T c10_sk_a;
  real_T c10_gn_b;
  real_T c10_sp_y;
  real_T c10_slb_x;
  real_T c10_tlb_x;
  real_T c10_ulb_x;
  real_T c10_vlb_x;
  real_T c10_tk_a;
  real_T c10_hn_b;
  real_T c10_tp_y;
  real_T c10_uk_a;
  real_T c10_in_b;
  real_T c10_up_y;
  real_T c10_vk_a;
  real_T c10_jn_b;
  real_T c10_vp_y;
  real_T c10_mc_A;
  real_T c10_wlb_x;
  real_T c10_xlb_x;
  real_T c10_wp_y;
  real_T c10_ylb_x;
  real_T c10_amb_x;
  real_T c10_bmb_x;
  real_T c10_cmb_x;
  real_T c10_dmb_x;
  real_T c10_emb_x;
  real_T c10_fmb_x;
  real_T c10_gmb_x;
  real_T c10_hmb_x;
  real_T c10_imb_x;
  real_T c10_jmb_x;
  real_T c10_kmb_x;
  real_T c10_wk_a;
  real_T c10_kn_b;
  real_T c10_xp_y;
  real_T c10_lmb_x;
  real_T c10_mmb_x;
  real_T c10_xk_a;
  real_T c10_ln_b;
  real_T c10_yp_y;
  real_T c10_nmb_x;
  real_T c10_omb_x;
  real_T c10_pmb_x;
  real_T c10_qmb_x;
  real_T c10_yk_a;
  real_T c10_mn_b;
  real_T c10_aq_y;
  real_T c10_rmb_x;
  real_T c10_smb_x;
  real_T c10_al_a;
  real_T c10_nn_b;
  real_T c10_bq_y;
  real_T c10_bl_a;
  real_T c10_on_b;
  real_T c10_cq_y;
  real_T c10_tmb_x;
  real_T c10_umb_x;
  real_T c10_vmb_x;
  real_T c10_wmb_x;
  real_T c10_xmb_x;
  real_T c10_ymb_x;
  real_T c10_cl_a;
  real_T c10_pn_b;
  real_T c10_dq_y;
  real_T c10_anb_x;
  real_T c10_bnb_x;
  real_T c10_dl_a;
  real_T c10_qn_b;
  real_T c10_eq_y;
  real_T c10_cnb_x;
  real_T c10_dnb_x;
  real_T c10_enb_x;
  real_T c10_fnb_x;
  real_T c10_el_a;
  real_T c10_rn_b;
  real_T c10_fq_y;
  real_T c10_gnb_x;
  real_T c10_hnb_x;
  real_T c10_fl_a;
  real_T c10_sn_b;
  real_T c10_gq_y;
  real_T c10_gl_a;
  real_T c10_tn_b;
  real_T c10_hq_y;
  real_T c10_inb_x;
  real_T c10_jnb_x;
  real_T c10_knb_x;
  real_T c10_lnb_x;
  real_T c10_hl_a;
  real_T c10_un_b;
  real_T c10_iq_y;
  real_T c10_mnb_x;
  real_T c10_nnb_x;
  real_T c10_onb_x;
  real_T c10_pnb_x;
  real_T c10_qnb_x;
  real_T c10_rnb_x;
  real_T c10_snb_x;
  real_T c10_tnb_x;
  real_T c10_il_a;
  real_T c10_vn_b;
  real_T c10_jq_y;
  real_T c10_unb_x;
  real_T c10_vnb_x;
  real_T c10_jl_a;
  real_T c10_wn_b;
  real_T c10_kq_y;
  real_T c10_wnb_x;
  real_T c10_xnb_x;
  real_T c10_ynb_x;
  real_T c10_aob_x;
  real_T c10_kl_a;
  real_T c10_xn_b;
  real_T c10_lq_y;
  real_T c10_bob_x;
  real_T c10_cob_x;
  real_T c10_ll_a;
  real_T c10_yn_b;
  real_T c10_mq_y;
  real_T c10_ml_a;
  real_T c10_ao_b;
  real_T c10_nq_y;
  real_T c10_dob_x;
  real_T c10_eob_x;
  real_T c10_fob_x;
  real_T c10_gob_x;
  real_T c10_hob_x;
  real_T c10_iob_x;
  real_T c10_nl_a;
  real_T c10_bo_b;
  real_T c10_oq_y;
  real_T c10_job_x;
  real_T c10_kob_x;
  real_T c10_ol_a;
  real_T c10_co_b;
  real_T c10_pq_y;
  real_T c10_lob_x;
  real_T c10_mob_x;
  real_T c10_nob_x;
  real_T c10_oob_x;
  real_T c10_pl_a;
  real_T c10_do_b;
  real_T c10_qq_y;
  real_T c10_pob_x;
  real_T c10_qob_x;
  real_T c10_ql_a;
  real_T c10_eo_b;
  real_T c10_rq_y;
  real_T c10_rl_a;
  real_T c10_fo_b;
  real_T c10_sq_y;
  real_T c10_sl_a;
  real_T c10_go_b;
  real_T c10_tq_y;
  real_T c10_rob_x;
  real_T c10_sob_x;
  real_T c10_tob_x;
  real_T c10_uob_x;
  real_T c10_vob_x;
  real_T c10_wob_x;
  real_T c10_xob_x;
  real_T c10_yob_x;
  real_T c10_apb_x;
  real_T c10_bpb_x;
  real_T c10_cpb_x;
  real_T c10_dpb_x;
  real_T c10_tl_a;
  real_T c10_ho_b;
  real_T c10_uq_y;
  real_T c10_epb_x;
  real_T c10_fpb_x;
  real_T c10_ul_a;
  real_T c10_io_b;
  real_T c10_vq_y;
  real_T c10_gpb_x;
  real_T c10_hpb_x;
  real_T c10_ipb_x;
  real_T c10_jpb_x;
  real_T c10_vl_a;
  real_T c10_jo_b;
  real_T c10_wq_y;
  real_T c10_kpb_x;
  real_T c10_lpb_x;
  real_T c10_wl_a;
  real_T c10_ko_b;
  real_T c10_xq_y;
  real_T c10_xl_a;
  real_T c10_lo_b;
  real_T c10_yq_y;
  real_T c10_mpb_x;
  real_T c10_npb_x;
  real_T c10_opb_x;
  real_T c10_ppb_x;
  real_T c10_qpb_x;
  real_T c10_rpb_x;
  real_T c10_yl_a;
  real_T c10_mo_b;
  real_T c10_ar_y;
  real_T c10_spb_x;
  real_T c10_tpb_x;
  real_T c10_am_a;
  real_T c10_no_b;
  real_T c10_br_y;
  real_T c10_upb_x;
  real_T c10_vpb_x;
  real_T c10_wpb_x;
  real_T c10_xpb_x;
  real_T c10_bm_a;
  real_T c10_oo_b;
  real_T c10_cr_y;
  real_T c10_ypb_x;
  real_T c10_aqb_x;
  real_T c10_cm_a;
  real_T c10_po_b;
  real_T c10_dr_y;
  real_T c10_dm_a;
  real_T c10_qo_b;
  real_T c10_er_y;
  real_T c10_bqb_x;
  real_T c10_cqb_x;
  real_T c10_dqb_x;
  real_T c10_eqb_x;
  real_T c10_fqb_x;
  real_T c10_gqb_x;
  real_T c10_hqb_x;
  real_T c10_iqb_x;
  real_T c10_em_a;
  real_T c10_ro_b;
  real_T c10_fr_y;
  real_T c10_jqb_x;
  real_T c10_kqb_x;
  real_T c10_fm_a;
  real_T c10_so_b;
  real_T c10_gr_y;
  real_T c10_lqb_x;
  real_T c10_mqb_x;
  real_T c10_nqb_x;
  real_T c10_oqb_x;
  real_T c10_gm_a;
  real_T c10_to_b;
  real_T c10_hr_y;
  real_T c10_pqb_x;
  real_T c10_qqb_x;
  real_T c10_hm_a;
  real_T c10_uo_b;
  real_T c10_ir_y;
  real_T c10_im_a;
  real_T c10_vo_b;
  real_T c10_jr_y;
  real_T c10_rqb_x;
  real_T c10_sqb_x;
  real_T c10_tqb_x;
  real_T c10_uqb_x;
  real_T c10_vqb_x;
  real_T c10_wqb_x;
  real_T c10_jm_a;
  real_T c10_wo_b;
  real_T c10_kr_y;
  real_T c10_xqb_x;
  real_T c10_yqb_x;
  real_T c10_km_a;
  real_T c10_xo_b;
  real_T c10_lr_y;
  real_T c10_arb_x;
  real_T c10_brb_x;
  real_T c10_crb_x;
  real_T c10_drb_x;
  real_T c10_lm_a;
  real_T c10_yo_b;
  real_T c10_mr_y;
  real_T c10_erb_x;
  real_T c10_frb_x;
  real_T c10_mm_a;
  real_T c10_ap_b;
  real_T c10_nr_y;
  real_T c10_nm_a;
  real_T c10_bp_b;
  real_T c10_or_y;
  real_T c10_om_a;
  real_T c10_cp_b;
  real_T c10_pr_y;
  real_T c10_grb_x;
  real_T c10_hrb_x;
  real_T c10_irb_x;
  real_T c10_jrb_x;
  real_T c10_pm_a;
  real_T c10_dp_b;
  real_T c10_qr_y;
  real_T c10_krb_x;
  real_T c10_lrb_x;
  real_T c10_mrb_x;
  real_T c10_nrb_x;
  real_T c10_orb_x;
  real_T c10_prb_x;
  real_T c10_qm_a;
  real_T c10_ep_b;
  real_T c10_rr_y;
  real_T c10_qrb_x;
  real_T c10_rrb_x;
  real_T c10_srb_x;
  real_T c10_trb_x;
  real_T c10_rm_a;
  real_T c10_fp_b;
  real_T c10_sr_y;
  real_T c10_sm_a;
  real_T c10_gp_b;
  real_T c10_tr_y;
  real_T c10_urb_x;
  real_T c10_vrb_x;
  real_T c10_wrb_x;
  real_T c10_xrb_x;
  real_T c10_yrb_x;
  real_T c10_asb_x;
  real_T c10_tm_a;
  real_T c10_hp_b;
  real_T c10_ur_y;
  real_T c10_bsb_x;
  real_T c10_csb_x;
  real_T c10_dsb_x;
  real_T c10_esb_x;
  real_T c10_um_a;
  real_T c10_ip_b;
  real_T c10_vr_y;
  real_T c10_vm_a;
  real_T c10_jp_b;
  real_T c10_wr_y;
  real_T c10_fsb_x;
  real_T c10_gsb_x;
  real_T c10_hsb_x;
  real_T c10_isb_x;
  real_T c10_jsb_x;
  real_T c10_ksb_x;
  real_T c10_lsb_x;
  real_T c10_msb_x;
  real_T c10_wm_a;
  real_T c10_kp_b;
  real_T c10_xr_y;
  real_T c10_nsb_x;
  real_T c10_osb_x;
  real_T c10_psb_x;
  real_T c10_qsb_x;
  real_T c10_xm_a;
  real_T c10_lp_b;
  real_T c10_yr_y;
  real_T c10_ym_a;
  real_T c10_mp_b;
  real_T c10_as_y;
  real_T c10_rsb_x;
  real_T c10_ssb_x;
  real_T c10_tsb_x;
  real_T c10_usb_x;
  real_T c10_vsb_x;
  real_T c10_wsb_x;
  real_T c10_an_a;
  real_T c10_np_b;
  real_T c10_bs_y;
  real_T c10_xsb_x;
  real_T c10_ysb_x;
  real_T c10_atb_x;
  real_T c10_btb_x;
  real_T c10_bn_a;
  real_T c10_op_b;
  real_T c10_cs_y;
  real_T c10_cn_a;
  real_T c10_pp_b;
  real_T c10_ds_y;
  real_T c10_dn_a;
  real_T c10_qp_b;
  real_T c10_es_y;
  int32_T c10_i11;
  int32_T c10_i12;
  int32_T c10_i13;
  int32_T c10_i14;
  int32_T c10_i15;
  int32_T c10_i16;
  int32_T c10_i17;
  int32_T c10_i18;
  int32_T c10_i19;
  real_T (*c10_b_J)[36];
  real_T (*c10_b_J1)[18];
  real_T (*c10_b_J2)[18];
  real_T (*c10_b_q)[6];
  c10_b_J2 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_b_J1 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c10_b_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  for (c10_i10 = 0; c10_i10 < 6; c10_i10++) {
    c10_q[c10_i10] = (*c10_b_q)[c10_i10];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_theta_1, 0U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_theta_2, 1U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_theta_3, 2U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_theta_4, 3U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_theta_5, 4U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_theta_6, 5U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_q, 8U, c10_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_J, 9U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_J1, 10U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_J2, 11U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_theta_1 = c10_q[0];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_theta_2 = c10_q[1];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 9);
  c10_theta_3 = c10_q[2];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  c10_theta_4 = c10_q[3];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 11);
  c10_theta_5 = c10_q[4];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  c10_theta_6 = c10_q[5];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
  c10_x = c10_theta_1;
  c10_b_x = c10_x;
  c10_b_x = muDoubleScalarCos(c10_b_x);
  c10_b = c10_b_x;
  c10_y = 109.0 * c10_b;
  c10_A = c10_y;
  c10_c_x = c10_A;
  c10_d_x = c10_c_x;
  c10_b_y = c10_d_x / 1000.0;
  c10_e_x = c10_theta_1;
  c10_f_x = c10_e_x;
  c10_f_x = muDoubleScalarCos(c10_f_x);
  c10_b_b = c10_f_x;
  c10_c_y = 41.0 * c10_b_b;
  c10_g_x = c10_theta_5;
  c10_h_x = c10_g_x;
  c10_h_x = muDoubleScalarCos(c10_h_x);
  c10_a = c10_c_y;
  c10_c_b = c10_h_x;
  c10_d_y = c10_a * c10_c_b;
  c10_b_A = c10_d_y;
  c10_i_x = c10_b_A;
  c10_j_x = c10_i_x;
  c10_e_y = c10_j_x / 500.0;
  c10_k_x = c10_theta_2;
  c10_l_x = c10_k_x;
  c10_l_x = muDoubleScalarCos(c10_l_x);
  c10_d_b = c10_l_x;
  c10_f_y = 17.0 * c10_d_b;
  c10_m_x = c10_theta_1;
  c10_n_x = c10_m_x;
  c10_n_x = muDoubleScalarSin(c10_n_x);
  c10_b_a = c10_f_y;
  c10_e_b = c10_n_x;
  c10_g_y = c10_b_a * c10_e_b;
  c10_c_A = c10_g_y;
  c10_o_x = c10_c_A;
  c10_p_x = c10_o_x;
  c10_h_y = c10_p_x / 40.0;
  c10_q_x = c10_theta_4;
  c10_r_x = c10_q_x;
  c10_r_x = muDoubleScalarCos(c10_r_x);
  c10_f_b = c10_r_x;
  c10_i_y = 93.0 * c10_f_b;
  c10_s_x = c10_theta_2;
  c10_t_x = c10_s_x;
  c10_t_x = muDoubleScalarCos(c10_t_x);
  c10_u_x = c10_theta_1;
  c10_v_x = c10_u_x;
  c10_v_x = muDoubleScalarSin(c10_v_x);
  c10_c_a = c10_t_x;
  c10_g_b = c10_v_x;
  c10_j_y = c10_c_a * c10_g_b;
  c10_w_x = c10_theta_3;
  c10_x_x = c10_w_x;
  c10_x_x = muDoubleScalarSin(c10_x_x);
  c10_d_a = c10_j_y;
  c10_h_b = c10_x_x;
  c10_k_y = c10_d_a * c10_h_b;
  c10_y_x = c10_theta_3;
  c10_ab_x = c10_y_x;
  c10_ab_x = muDoubleScalarCos(c10_ab_x);
  c10_bb_x = c10_theta_1;
  c10_cb_x = c10_bb_x;
  c10_cb_x = muDoubleScalarSin(c10_cb_x);
  c10_e_a = c10_ab_x;
  c10_i_b = c10_cb_x;
  c10_l_y = c10_e_a * c10_i_b;
  c10_db_x = c10_theta_2;
  c10_eb_x = c10_db_x;
  c10_eb_x = muDoubleScalarSin(c10_eb_x);
  c10_f_a = c10_l_y;
  c10_j_b = c10_eb_x;
  c10_m_y = c10_f_a * c10_j_b;
  c10_g_a = c10_i_y;
  c10_k_b = c10_k_y + c10_m_y;
  c10_n_y = c10_g_a * c10_k_b;
  c10_d_A = c10_n_y;
  c10_fb_x = c10_d_A;
  c10_gb_x = c10_fb_x;
  c10_o_y = c10_gb_x / 1000.0;
  c10_hb_x = c10_theta_4;
  c10_ib_x = c10_hb_x;
  c10_ib_x = muDoubleScalarSin(c10_ib_x);
  c10_l_b = c10_ib_x;
  c10_p_y = 93.0 * c10_l_b;
  c10_jb_x = c10_theta_1;
  c10_kb_x = c10_jb_x;
  c10_kb_x = muDoubleScalarSin(c10_kb_x);
  c10_lb_x = c10_theta_2;
  c10_mb_x = c10_lb_x;
  c10_mb_x = muDoubleScalarSin(c10_mb_x);
  c10_h_a = c10_kb_x;
  c10_m_b = c10_mb_x;
  c10_q_y = c10_h_a * c10_m_b;
  c10_nb_x = c10_theta_3;
  c10_ob_x = c10_nb_x;
  c10_ob_x = muDoubleScalarSin(c10_ob_x);
  c10_i_a = c10_q_y;
  c10_n_b = c10_ob_x;
  c10_r_y = c10_i_a * c10_n_b;
  c10_pb_x = c10_theta_2;
  c10_qb_x = c10_pb_x;
  c10_qb_x = muDoubleScalarCos(c10_qb_x);
  c10_rb_x = c10_theta_3;
  c10_sb_x = c10_rb_x;
  c10_sb_x = muDoubleScalarCos(c10_sb_x);
  c10_j_a = c10_qb_x;
  c10_o_b = c10_sb_x;
  c10_s_y = c10_j_a * c10_o_b;
  c10_tb_x = c10_theta_1;
  c10_ub_x = c10_tb_x;
  c10_ub_x = muDoubleScalarSin(c10_ub_x);
  c10_k_a = c10_s_y;
  c10_p_b = c10_ub_x;
  c10_t_y = c10_k_a * c10_p_b;
  c10_l_a = c10_p_y;
  c10_q_b = c10_r_y - c10_t_y;
  c10_u_y = c10_l_a * c10_q_b;
  c10_e_A = c10_u_y;
  c10_vb_x = c10_e_A;
  c10_wb_x = c10_vb_x;
  c10_v_y = c10_wb_x / 1000.0;
  c10_xb_x = c10_theta_5;
  c10_yb_x = c10_xb_x;
  c10_yb_x = muDoubleScalarSin(c10_yb_x);
  c10_r_b = c10_yb_x;
  c10_w_y = 41.0 * c10_r_b;
  c10_ac_x = c10_theta_4;
  c10_bc_x = c10_ac_x;
  c10_bc_x = muDoubleScalarCos(c10_bc_x);
  c10_cc_x = c10_theta_1;
  c10_dc_x = c10_cc_x;
  c10_dc_x = muDoubleScalarSin(c10_dc_x);
  c10_ec_x = c10_theta_2;
  c10_fc_x = c10_ec_x;
  c10_fc_x = muDoubleScalarSin(c10_fc_x);
  c10_m_a = c10_dc_x;
  c10_s_b = c10_fc_x;
  c10_x_y = c10_m_a * c10_s_b;
  c10_gc_x = c10_theta_3;
  c10_hc_x = c10_gc_x;
  c10_hc_x = muDoubleScalarSin(c10_hc_x);
  c10_n_a = c10_x_y;
  c10_t_b = c10_hc_x;
  c10_y_y = c10_n_a * c10_t_b;
  c10_ic_x = c10_theta_2;
  c10_jc_x = c10_ic_x;
  c10_jc_x = muDoubleScalarCos(c10_jc_x);
  c10_kc_x = c10_theta_3;
  c10_lc_x = c10_kc_x;
  c10_lc_x = muDoubleScalarCos(c10_lc_x);
  c10_o_a = c10_jc_x;
  c10_u_b = c10_lc_x;
  c10_ab_y = c10_o_a * c10_u_b;
  c10_mc_x = c10_theta_1;
  c10_nc_x = c10_mc_x;
  c10_nc_x = muDoubleScalarSin(c10_nc_x);
  c10_p_a = c10_ab_y;
  c10_v_b = c10_nc_x;
  c10_bb_y = c10_p_a * c10_v_b;
  c10_q_a = c10_bc_x;
  c10_w_b = c10_y_y - c10_bb_y;
  c10_cb_y = c10_q_a * c10_w_b;
  c10_oc_x = c10_theta_4;
  c10_pc_x = c10_oc_x;
  c10_pc_x = muDoubleScalarSin(c10_pc_x);
  c10_qc_x = c10_theta_2;
  c10_rc_x = c10_qc_x;
  c10_rc_x = muDoubleScalarCos(c10_rc_x);
  c10_sc_x = c10_theta_1;
  c10_tc_x = c10_sc_x;
  c10_tc_x = muDoubleScalarSin(c10_tc_x);
  c10_r_a = c10_rc_x;
  c10_x_b = c10_tc_x;
  c10_db_y = c10_r_a * c10_x_b;
  c10_uc_x = c10_theta_3;
  c10_vc_x = c10_uc_x;
  c10_vc_x = muDoubleScalarSin(c10_vc_x);
  c10_s_a = c10_db_y;
  c10_y_b = c10_vc_x;
  c10_eb_y = c10_s_a * c10_y_b;
  c10_wc_x = c10_theta_3;
  c10_xc_x = c10_wc_x;
  c10_xc_x = muDoubleScalarCos(c10_xc_x);
  c10_yc_x = c10_theta_1;
  c10_ad_x = c10_yc_x;
  c10_ad_x = muDoubleScalarSin(c10_ad_x);
  c10_t_a = c10_xc_x;
  c10_ab_b = c10_ad_x;
  c10_fb_y = c10_t_a * c10_ab_b;
  c10_bd_x = c10_theta_2;
  c10_cd_x = c10_bd_x;
  c10_cd_x = muDoubleScalarSin(c10_cd_x);
  c10_u_a = c10_fb_y;
  c10_bb_b = c10_cd_x;
  c10_gb_y = c10_u_a * c10_bb_b;
  c10_v_a = c10_pc_x;
  c10_cb_b = c10_eb_y + c10_gb_y;
  c10_hb_y = c10_v_a * c10_cb_b;
  c10_w_a = c10_w_y;
  c10_db_b = c10_cb_y + c10_hb_y;
  c10_ib_y = c10_w_a * c10_db_b;
  c10_f_A = c10_ib_y;
  c10_dd_x = c10_f_A;
  c10_ed_x = c10_dd_x;
  c10_jb_y = c10_ed_x / 500.0;
  c10_fd_x = c10_theta_1;
  c10_gd_x = c10_fd_x;
  c10_gd_x = muDoubleScalarSin(c10_gd_x);
  c10_eb_b = c10_gd_x;
  c10_kb_y = 39243.0 * c10_eb_b;
  c10_hd_x = c10_theta_2;
  c10_id_x = c10_hd_x;
  c10_id_x = muDoubleScalarSin(c10_id_x);
  c10_x_a = c10_kb_y;
  c10_fb_b = c10_id_x;
  c10_lb_y = c10_x_a * c10_fb_b;
  c10_jd_x = c10_theta_3;
  c10_kd_x = c10_jd_x;
  c10_kd_x = muDoubleScalarSin(c10_kd_x);
  c10_y_a = c10_lb_y;
  c10_gb_b = c10_kd_x;
  c10_mb_y = c10_y_a * c10_gb_b;
  c10_g_A = c10_mb_y;
  c10_ld_x = c10_g_A;
  c10_md_x = c10_ld_x;
  c10_nb_y = c10_md_x / 100000.0;
  c10_nd_x = c10_theta_2;
  c10_od_x = c10_nd_x;
  c10_od_x = muDoubleScalarCos(c10_od_x);
  c10_hb_b = c10_od_x;
  c10_ob_y = 39243.0 * c10_hb_b;
  c10_pd_x = c10_theta_3;
  c10_qd_x = c10_pd_x;
  c10_qd_x = muDoubleScalarCos(c10_qd_x);
  c10_ab_a = c10_ob_y;
  c10_ib_b = c10_qd_x;
  c10_pb_y = c10_ab_a * c10_ib_b;
  c10_rd_x = c10_theta_1;
  c10_sd_x = c10_rd_x;
  c10_sd_x = muDoubleScalarSin(c10_sd_x);
  c10_bb_a = c10_pb_y;
  c10_jb_b = c10_sd_x;
  c10_qb_y = c10_bb_a * c10_jb_b;
  c10_h_A = c10_qb_y;
  c10_td_x = c10_h_A;
  c10_ud_x = c10_td_x;
  c10_rb_y = c10_ud_x / 100000.0;
  c10_vd_x = c10_theta_1;
  c10_wd_x = c10_vd_x;
  c10_wd_x = muDoubleScalarCos(c10_wd_x);
  c10_kb_b = c10_wd_x;
  c10_sb_y = 17.0 * c10_kb_b;
  c10_xd_x = c10_theta_2;
  c10_yd_x = c10_xd_x;
  c10_yd_x = muDoubleScalarSin(c10_yd_x);
  c10_cb_a = c10_sb_y;
  c10_lb_b = c10_yd_x;
  c10_tb_y = c10_cb_a * c10_lb_b;
  c10_i_A = c10_tb_y;
  c10_ae_x = c10_i_A;
  c10_be_x = c10_ae_x;
  c10_ub_y = c10_be_x / 40.0;
  c10_ce_x = c10_theta_4;
  c10_de_x = c10_ce_x;
  c10_de_x = muDoubleScalarCos(c10_de_x);
  c10_mb_b = c10_de_x;
  c10_vb_y = 93.0 * c10_mb_b;
  c10_ee_x = c10_theta_1;
  c10_fe_x = c10_ee_x;
  c10_fe_x = muDoubleScalarCos(c10_fe_x);
  c10_ge_x = c10_theta_2;
  c10_he_x = c10_ge_x;
  c10_he_x = muDoubleScalarSin(c10_he_x);
  c10_db_a = c10_fe_x;
  c10_nb_b = c10_he_x;
  c10_wb_y = c10_db_a * c10_nb_b;
  c10_ie_x = c10_theta_3;
  c10_je_x = c10_ie_x;
  c10_je_x = muDoubleScalarSin(c10_je_x);
  c10_eb_a = c10_wb_y;
  c10_ob_b = c10_je_x;
  c10_xb_y = c10_eb_a * c10_ob_b;
  c10_ke_x = c10_theta_1;
  c10_le_x = c10_ke_x;
  c10_le_x = muDoubleScalarCos(c10_le_x);
  c10_me_x = c10_theta_2;
  c10_ne_x = c10_me_x;
  c10_ne_x = muDoubleScalarCos(c10_ne_x);
  c10_fb_a = c10_le_x;
  c10_pb_b = c10_ne_x;
  c10_yb_y = c10_fb_a * c10_pb_b;
  c10_oe_x = c10_theta_3;
  c10_pe_x = c10_oe_x;
  c10_pe_x = muDoubleScalarCos(c10_pe_x);
  c10_gb_a = c10_yb_y;
  c10_qb_b = c10_pe_x;
  c10_ac_y = c10_gb_a * c10_qb_b;
  c10_hb_a = c10_vb_y;
  c10_rb_b = c10_xb_y - c10_ac_y;
  c10_bc_y = c10_hb_a * c10_rb_b;
  c10_j_A = c10_bc_y;
  c10_qe_x = c10_j_A;
  c10_re_x = c10_qe_x;
  c10_cc_y = c10_re_x / 1000.0;
  c10_se_x = c10_theta_4;
  c10_te_x = c10_se_x;
  c10_te_x = muDoubleScalarSin(c10_te_x);
  c10_sb_b = c10_te_x;
  c10_dc_y = 93.0 * c10_sb_b;
  c10_ue_x = c10_theta_1;
  c10_ve_x = c10_ue_x;
  c10_ve_x = muDoubleScalarCos(c10_ve_x);
  c10_we_x = c10_theta_2;
  c10_xe_x = c10_we_x;
  c10_xe_x = muDoubleScalarCos(c10_xe_x);
  c10_ib_a = c10_ve_x;
  c10_tb_b = c10_xe_x;
  c10_ec_y = c10_ib_a * c10_tb_b;
  c10_ye_x = c10_theta_3;
  c10_af_x = c10_ye_x;
  c10_af_x = muDoubleScalarSin(c10_af_x);
  c10_jb_a = c10_ec_y;
  c10_ub_b = c10_af_x;
  c10_fc_y = c10_jb_a * c10_ub_b;
  c10_bf_x = c10_theta_1;
  c10_cf_x = c10_bf_x;
  c10_cf_x = muDoubleScalarCos(c10_cf_x);
  c10_df_x = c10_theta_3;
  c10_ef_x = c10_df_x;
  c10_ef_x = muDoubleScalarCos(c10_ef_x);
  c10_kb_a = c10_cf_x;
  c10_vb_b = c10_ef_x;
  c10_gc_y = c10_kb_a * c10_vb_b;
  c10_ff_x = c10_theta_2;
  c10_gf_x = c10_ff_x;
  c10_gf_x = muDoubleScalarSin(c10_gf_x);
  c10_lb_a = c10_gc_y;
  c10_wb_b = c10_gf_x;
  c10_hc_y = c10_lb_a * c10_wb_b;
  c10_mb_a = c10_dc_y;
  c10_xb_b = c10_fc_y + c10_hc_y;
  c10_ic_y = c10_mb_a * c10_xb_b;
  c10_k_A = c10_ic_y;
  c10_hf_x = c10_k_A;
  c10_if_x = c10_hf_x;
  c10_jc_y = c10_if_x / 1000.0;
  c10_jf_x = c10_theta_5;
  c10_kf_x = c10_jf_x;
  c10_kf_x = muDoubleScalarSin(c10_kf_x);
  c10_yb_b = c10_kf_x;
  c10_kc_y = 41.0 * c10_yb_b;
  c10_lf_x = c10_theta_4;
  c10_mf_x = c10_lf_x;
  c10_mf_x = muDoubleScalarCos(c10_mf_x);
  c10_nf_x = c10_theta_1;
  c10_of_x = c10_nf_x;
  c10_of_x = muDoubleScalarCos(c10_of_x);
  c10_pf_x = c10_theta_2;
  c10_qf_x = c10_pf_x;
  c10_qf_x = muDoubleScalarCos(c10_qf_x);
  c10_nb_a = c10_of_x;
  c10_ac_b = c10_qf_x;
  c10_lc_y = c10_nb_a * c10_ac_b;
  c10_rf_x = c10_theta_3;
  c10_sf_x = c10_rf_x;
  c10_sf_x = muDoubleScalarSin(c10_sf_x);
  c10_ob_a = c10_lc_y;
  c10_bc_b = c10_sf_x;
  c10_mc_y = c10_ob_a * c10_bc_b;
  c10_tf_x = c10_theta_1;
  c10_uf_x = c10_tf_x;
  c10_uf_x = muDoubleScalarCos(c10_uf_x);
  c10_vf_x = c10_theta_3;
  c10_wf_x = c10_vf_x;
  c10_wf_x = muDoubleScalarCos(c10_wf_x);
  c10_pb_a = c10_uf_x;
  c10_cc_b = c10_wf_x;
  c10_nc_y = c10_pb_a * c10_cc_b;
  c10_xf_x = c10_theta_2;
  c10_yf_x = c10_xf_x;
  c10_yf_x = muDoubleScalarSin(c10_yf_x);
  c10_qb_a = c10_nc_y;
  c10_dc_b = c10_yf_x;
  c10_oc_y = c10_qb_a * c10_dc_b;
  c10_rb_a = c10_mf_x;
  c10_ec_b = c10_mc_y + c10_oc_y;
  c10_pc_y = c10_rb_a * c10_ec_b;
  c10_ag_x = c10_theta_4;
  c10_bg_x = c10_ag_x;
  c10_bg_x = muDoubleScalarSin(c10_bg_x);
  c10_cg_x = c10_theta_1;
  c10_dg_x = c10_cg_x;
  c10_dg_x = muDoubleScalarCos(c10_dg_x);
  c10_eg_x = c10_theta_2;
  c10_fg_x = c10_eg_x;
  c10_fg_x = muDoubleScalarSin(c10_fg_x);
  c10_sb_a = c10_dg_x;
  c10_fc_b = c10_fg_x;
  c10_qc_y = c10_sb_a * c10_fc_b;
  c10_gg_x = c10_theta_3;
  c10_hg_x = c10_gg_x;
  c10_hg_x = muDoubleScalarSin(c10_hg_x);
  c10_tb_a = c10_qc_y;
  c10_gc_b = c10_hg_x;
  c10_rc_y = c10_tb_a * c10_gc_b;
  c10_ig_x = c10_theta_1;
  c10_jg_x = c10_ig_x;
  c10_jg_x = muDoubleScalarCos(c10_jg_x);
  c10_kg_x = c10_theta_2;
  c10_lg_x = c10_kg_x;
  c10_lg_x = muDoubleScalarCos(c10_lg_x);
  c10_ub_a = c10_jg_x;
  c10_hc_b = c10_lg_x;
  c10_sc_y = c10_ub_a * c10_hc_b;
  c10_mg_x = c10_theta_3;
  c10_ng_x = c10_mg_x;
  c10_ng_x = muDoubleScalarCos(c10_ng_x);
  c10_vb_a = c10_sc_y;
  c10_ic_b = c10_ng_x;
  c10_tc_y = c10_vb_a * c10_ic_b;
  c10_wb_a = c10_bg_x;
  c10_jc_b = c10_rc_y - c10_tc_y;
  c10_uc_y = c10_wb_a * c10_jc_b;
  c10_xb_a = c10_kc_y;
  c10_kc_b = c10_pc_y - c10_uc_y;
  c10_vc_y = c10_xb_a * c10_kc_b;
  c10_l_A = c10_vc_y;
  c10_og_x = c10_l_A;
  c10_pg_x = c10_og_x;
  c10_wc_y = c10_pg_x / 500.0;
  c10_qg_x = c10_theta_1;
  c10_rg_x = c10_qg_x;
  c10_rg_x = muDoubleScalarCos(c10_rg_x);
  c10_lc_b = c10_rg_x;
  c10_xc_y = 39243.0 * c10_lc_b;
  c10_sg_x = c10_theta_2;
  c10_tg_x = c10_sg_x;
  c10_tg_x = muDoubleScalarCos(c10_tg_x);
  c10_yb_a = c10_xc_y;
  c10_mc_b = c10_tg_x;
  c10_yc_y = c10_yb_a * c10_mc_b;
  c10_ug_x = c10_theta_3;
  c10_vg_x = c10_ug_x;
  c10_vg_x = muDoubleScalarSin(c10_vg_x);
  c10_ac_a = c10_yc_y;
  c10_nc_b = c10_vg_x;
  c10_ad_y = c10_ac_a * c10_nc_b;
  c10_m_A = c10_ad_y;
  c10_wg_x = c10_m_A;
  c10_xg_x = c10_wg_x;
  c10_bd_y = c10_xg_x / 100000.0;
  c10_yg_x = c10_theta_1;
  c10_ah_x = c10_yg_x;
  c10_ah_x = muDoubleScalarCos(c10_ah_x);
  c10_oc_b = c10_ah_x;
  c10_cd_y = 39243.0 * c10_oc_b;
  c10_bh_x = c10_theta_3;
  c10_ch_x = c10_bh_x;
  c10_ch_x = muDoubleScalarCos(c10_ch_x);
  c10_bc_a = c10_cd_y;
  c10_pc_b = c10_ch_x;
  c10_dd_y = c10_bc_a * c10_pc_b;
  c10_dh_x = c10_theta_2;
  c10_eh_x = c10_dh_x;
  c10_eh_x = muDoubleScalarSin(c10_eh_x);
  c10_cc_a = c10_dd_y;
  c10_qc_b = c10_eh_x;
  c10_ed_y = c10_cc_a * c10_qc_b;
  c10_n_A = c10_ed_y;
  c10_fh_x = c10_n_A;
  c10_gh_x = c10_fh_x;
  c10_fd_y = c10_gh_x / 100000.0;
  c10_hh_x = c10_theta_5;
  c10_ih_x = c10_hh_x;
  c10_ih_x = muDoubleScalarSin(c10_ih_x);
  c10_rc_b = c10_ih_x;
  c10_gd_y = 41.0 * c10_rc_b;
  c10_jh_x = c10_theta_4;
  c10_kh_x = c10_jh_x;
  c10_kh_x = muDoubleScalarCos(c10_kh_x);
  c10_lh_x = c10_theta_1;
  c10_mh_x = c10_lh_x;
  c10_mh_x = muDoubleScalarCos(c10_mh_x);
  c10_nh_x = c10_theta_2;
  c10_oh_x = c10_nh_x;
  c10_oh_x = muDoubleScalarCos(c10_oh_x);
  c10_dc_a = c10_mh_x;
  c10_sc_b = c10_oh_x;
  c10_hd_y = c10_dc_a * c10_sc_b;
  c10_ph_x = c10_theta_3;
  c10_qh_x = c10_ph_x;
  c10_qh_x = muDoubleScalarSin(c10_qh_x);
  c10_ec_a = c10_hd_y;
  c10_tc_b = c10_qh_x;
  c10_id_y = c10_ec_a * c10_tc_b;
  c10_rh_x = c10_theta_1;
  c10_sh_x = c10_rh_x;
  c10_sh_x = muDoubleScalarCos(c10_sh_x);
  c10_th_x = c10_theta_3;
  c10_uh_x = c10_th_x;
  c10_uh_x = muDoubleScalarCos(c10_uh_x);
  c10_fc_a = c10_sh_x;
  c10_uc_b = c10_uh_x;
  c10_jd_y = c10_fc_a * c10_uc_b;
  c10_vh_x = c10_theta_2;
  c10_wh_x = c10_vh_x;
  c10_wh_x = muDoubleScalarSin(c10_wh_x);
  c10_gc_a = c10_jd_y;
  c10_vc_b = c10_wh_x;
  c10_kd_y = c10_gc_a * c10_vc_b;
  c10_hc_a = c10_kh_x;
  c10_wc_b = c10_id_y + c10_kd_y;
  c10_ld_y = c10_hc_a * c10_wc_b;
  c10_xh_x = c10_theta_4;
  c10_yh_x = c10_xh_x;
  c10_yh_x = muDoubleScalarSin(c10_yh_x);
  c10_ai_x = c10_theta_1;
  c10_bi_x = c10_ai_x;
  c10_bi_x = muDoubleScalarCos(c10_bi_x);
  c10_ci_x = c10_theta_2;
  c10_di_x = c10_ci_x;
  c10_di_x = muDoubleScalarSin(c10_di_x);
  c10_ic_a = c10_bi_x;
  c10_xc_b = c10_di_x;
  c10_md_y = c10_ic_a * c10_xc_b;
  c10_ei_x = c10_theta_3;
  c10_fi_x = c10_ei_x;
  c10_fi_x = muDoubleScalarSin(c10_fi_x);
  c10_jc_a = c10_md_y;
  c10_yc_b = c10_fi_x;
  c10_nd_y = c10_jc_a * c10_yc_b;
  c10_gi_x = c10_theta_1;
  c10_hi_x = c10_gi_x;
  c10_hi_x = muDoubleScalarCos(c10_hi_x);
  c10_ii_x = c10_theta_2;
  c10_ji_x = c10_ii_x;
  c10_ji_x = muDoubleScalarCos(c10_ji_x);
  c10_kc_a = c10_hi_x;
  c10_ad_b = c10_ji_x;
  c10_od_y = c10_kc_a * c10_ad_b;
  c10_ki_x = c10_theta_3;
  c10_li_x = c10_ki_x;
  c10_li_x = muDoubleScalarCos(c10_li_x);
  c10_lc_a = c10_od_y;
  c10_bd_b = c10_li_x;
  c10_pd_y = c10_lc_a * c10_bd_b;
  c10_mc_a = c10_yh_x;
  c10_cd_b = c10_nd_y - c10_pd_y;
  c10_qd_y = c10_mc_a * c10_cd_b;
  c10_nc_a = c10_gd_y;
  c10_dd_b = c10_ld_y - c10_qd_y;
  c10_rd_y = c10_nc_a * c10_dd_b;
  c10_o_A = c10_rd_y;
  c10_mi_x = c10_o_A;
  c10_ni_x = c10_mi_x;
  c10_sd_y = c10_ni_x / 500.0;
  c10_oi_x = c10_theta_4;
  c10_pi_x = c10_oi_x;
  c10_pi_x = muDoubleScalarSin(c10_pi_x);
  c10_ed_b = c10_pi_x;
  c10_td_y = 93.0 * c10_ed_b;
  c10_qi_x = c10_theta_1;
  c10_ri_x = c10_qi_x;
  c10_ri_x = muDoubleScalarCos(c10_ri_x);
  c10_si_x = c10_theta_2;
  c10_ti_x = c10_si_x;
  c10_ti_x = muDoubleScalarCos(c10_ti_x);
  c10_oc_a = c10_ri_x;
  c10_fd_b = c10_ti_x;
  c10_ud_y = c10_oc_a * c10_fd_b;
  c10_ui_x = c10_theta_3;
  c10_vi_x = c10_ui_x;
  c10_vi_x = muDoubleScalarSin(c10_vi_x);
  c10_pc_a = c10_ud_y;
  c10_gd_b = c10_vi_x;
  c10_vd_y = c10_pc_a * c10_gd_b;
  c10_wi_x = c10_theta_1;
  c10_xi_x = c10_wi_x;
  c10_xi_x = muDoubleScalarCos(c10_xi_x);
  c10_yi_x = c10_theta_3;
  c10_aj_x = c10_yi_x;
  c10_aj_x = muDoubleScalarCos(c10_aj_x);
  c10_qc_a = c10_xi_x;
  c10_hd_b = c10_aj_x;
  c10_wd_y = c10_qc_a * c10_hd_b;
  c10_bj_x = c10_theta_2;
  c10_cj_x = c10_bj_x;
  c10_cj_x = muDoubleScalarSin(c10_cj_x);
  c10_rc_a = c10_wd_y;
  c10_id_b = c10_cj_x;
  c10_xd_y = c10_rc_a * c10_id_b;
  c10_sc_a = c10_td_y;
  c10_jd_b = c10_vd_y + c10_xd_y;
  c10_yd_y = c10_sc_a * c10_jd_b;
  c10_p_A = c10_yd_y;
  c10_dj_x = c10_p_A;
  c10_ej_x = c10_dj_x;
  c10_ae_y = c10_ej_x / 1000.0;
  c10_fj_x = c10_theta_4;
  c10_gj_x = c10_fj_x;
  c10_gj_x = muDoubleScalarCos(c10_gj_x);
  c10_kd_b = c10_gj_x;
  c10_be_y = 93.0 * c10_kd_b;
  c10_hj_x = c10_theta_1;
  c10_ij_x = c10_hj_x;
  c10_ij_x = muDoubleScalarCos(c10_ij_x);
  c10_jj_x = c10_theta_2;
  c10_kj_x = c10_jj_x;
  c10_kj_x = muDoubleScalarSin(c10_kj_x);
  c10_tc_a = c10_ij_x;
  c10_ld_b = c10_kj_x;
  c10_ce_y = c10_tc_a * c10_ld_b;
  c10_lj_x = c10_theta_3;
  c10_mj_x = c10_lj_x;
  c10_mj_x = muDoubleScalarSin(c10_mj_x);
  c10_uc_a = c10_ce_y;
  c10_md_b = c10_mj_x;
  c10_de_y = c10_uc_a * c10_md_b;
  c10_nj_x = c10_theta_1;
  c10_oj_x = c10_nj_x;
  c10_oj_x = muDoubleScalarCos(c10_oj_x);
  c10_pj_x = c10_theta_2;
  c10_qj_x = c10_pj_x;
  c10_qj_x = muDoubleScalarCos(c10_qj_x);
  c10_vc_a = c10_oj_x;
  c10_nd_b = c10_qj_x;
  c10_ee_y = c10_vc_a * c10_nd_b;
  c10_rj_x = c10_theta_3;
  c10_sj_x = c10_rj_x;
  c10_sj_x = muDoubleScalarCos(c10_sj_x);
  c10_wc_a = c10_ee_y;
  c10_od_b = c10_sj_x;
  c10_fe_y = c10_wc_a * c10_od_b;
  c10_xc_a = c10_be_y;
  c10_pd_b = c10_de_y - c10_fe_y;
  c10_ge_y = c10_xc_a * c10_pd_b;
  c10_q_A = c10_ge_y;
  c10_tj_x = c10_q_A;
  c10_uj_x = c10_tj_x;
  c10_he_y = c10_uj_x / 1000.0;
  c10_vj_x = c10_theta_1;
  c10_wj_x = c10_vj_x;
  c10_wj_x = muDoubleScalarCos(c10_wj_x);
  c10_qd_b = c10_wj_x;
  c10_ie_y = 39243.0 * c10_qd_b;
  c10_xj_x = c10_theta_2;
  c10_yj_x = c10_xj_x;
  c10_yj_x = muDoubleScalarCos(c10_yj_x);
  c10_yc_a = c10_ie_y;
  c10_rd_b = c10_yj_x;
  c10_je_y = c10_yc_a * c10_rd_b;
  c10_ak_x = c10_theta_3;
  c10_bk_x = c10_ak_x;
  c10_bk_x = muDoubleScalarSin(c10_bk_x);
  c10_ad_a = c10_je_y;
  c10_sd_b = c10_bk_x;
  c10_ke_y = c10_ad_a * c10_sd_b;
  c10_r_A = c10_ke_y;
  c10_ck_x = c10_r_A;
  c10_dk_x = c10_ck_x;
  c10_le_y = c10_dk_x / 100000.0;
  c10_ek_x = c10_theta_1;
  c10_fk_x = c10_ek_x;
  c10_fk_x = muDoubleScalarCos(c10_fk_x);
  c10_td_b = c10_fk_x;
  c10_me_y = 39243.0 * c10_td_b;
  c10_gk_x = c10_theta_3;
  c10_hk_x = c10_gk_x;
  c10_hk_x = muDoubleScalarCos(c10_hk_x);
  c10_bd_a = c10_me_y;
  c10_ud_b = c10_hk_x;
  c10_ne_y = c10_bd_a * c10_ud_b;
  c10_ik_x = c10_theta_2;
  c10_jk_x = c10_ik_x;
  c10_jk_x = muDoubleScalarSin(c10_jk_x);
  c10_cd_a = c10_ne_y;
  c10_vd_b = c10_jk_x;
  c10_oe_y = c10_cd_a * c10_vd_b;
  c10_s_A = c10_oe_y;
  c10_kk_x = c10_s_A;
  c10_lk_x = c10_kk_x;
  c10_pe_y = c10_lk_x / 100000.0;
  c10_mk_x = c10_theta_5;
  c10_nk_x = c10_mk_x;
  c10_nk_x = muDoubleScalarSin(c10_nk_x);
  c10_wd_b = c10_nk_x;
  c10_qe_y = 41.0 * c10_wd_b;
  c10_ok_x = c10_theta_4;
  c10_pk_x = c10_ok_x;
  c10_pk_x = muDoubleScalarCos(c10_pk_x);
  c10_qk_x = c10_theta_1;
  c10_rk_x = c10_qk_x;
  c10_rk_x = muDoubleScalarCos(c10_rk_x);
  c10_sk_x = c10_theta_2;
  c10_tk_x = c10_sk_x;
  c10_tk_x = muDoubleScalarCos(c10_tk_x);
  c10_dd_a = c10_rk_x;
  c10_xd_b = c10_tk_x;
  c10_re_y = c10_dd_a * c10_xd_b;
  c10_uk_x = c10_theta_3;
  c10_vk_x = c10_uk_x;
  c10_vk_x = muDoubleScalarSin(c10_vk_x);
  c10_ed_a = c10_re_y;
  c10_yd_b = c10_vk_x;
  c10_se_y = c10_ed_a * c10_yd_b;
  c10_wk_x = c10_theta_1;
  c10_xk_x = c10_wk_x;
  c10_xk_x = muDoubleScalarCos(c10_xk_x);
  c10_yk_x = c10_theta_3;
  c10_al_x = c10_yk_x;
  c10_al_x = muDoubleScalarCos(c10_al_x);
  c10_fd_a = c10_xk_x;
  c10_ae_b = c10_al_x;
  c10_te_y = c10_fd_a * c10_ae_b;
  c10_bl_x = c10_theta_2;
  c10_cl_x = c10_bl_x;
  c10_cl_x = muDoubleScalarSin(c10_cl_x);
  c10_gd_a = c10_te_y;
  c10_be_b = c10_cl_x;
  c10_ue_y = c10_gd_a * c10_be_b;
  c10_hd_a = c10_pk_x;
  c10_ce_b = c10_se_y + c10_ue_y;
  c10_ve_y = c10_hd_a * c10_ce_b;
  c10_dl_x = c10_theta_4;
  c10_el_x = c10_dl_x;
  c10_el_x = muDoubleScalarSin(c10_el_x);
  c10_fl_x = c10_theta_1;
  c10_gl_x = c10_fl_x;
  c10_gl_x = muDoubleScalarCos(c10_gl_x);
  c10_hl_x = c10_theta_2;
  c10_il_x = c10_hl_x;
  c10_il_x = muDoubleScalarSin(c10_il_x);
  c10_id_a = c10_gl_x;
  c10_de_b = c10_il_x;
  c10_we_y = c10_id_a * c10_de_b;
  c10_jl_x = c10_theta_3;
  c10_kl_x = c10_jl_x;
  c10_kl_x = muDoubleScalarSin(c10_kl_x);
  c10_jd_a = c10_we_y;
  c10_ee_b = c10_kl_x;
  c10_xe_y = c10_jd_a * c10_ee_b;
  c10_ll_x = c10_theta_1;
  c10_ml_x = c10_ll_x;
  c10_ml_x = muDoubleScalarCos(c10_ml_x);
  c10_nl_x = c10_theta_2;
  c10_ol_x = c10_nl_x;
  c10_ol_x = muDoubleScalarCos(c10_ol_x);
  c10_kd_a = c10_ml_x;
  c10_fe_b = c10_ol_x;
  c10_ye_y = c10_kd_a * c10_fe_b;
  c10_pl_x = c10_theta_3;
  c10_ql_x = c10_pl_x;
  c10_ql_x = muDoubleScalarCos(c10_ql_x);
  c10_ld_a = c10_ye_y;
  c10_ge_b = c10_ql_x;
  c10_af_y = c10_ld_a * c10_ge_b;
  c10_md_a = c10_el_x;
  c10_he_b = c10_xe_y - c10_af_y;
  c10_bf_y = c10_md_a * c10_he_b;
  c10_nd_a = c10_qe_y;
  c10_ie_b = c10_ve_y - c10_bf_y;
  c10_cf_y = c10_nd_a * c10_ie_b;
  c10_t_A = c10_cf_y;
  c10_rl_x = c10_t_A;
  c10_sl_x = c10_rl_x;
  c10_df_y = c10_sl_x / 500.0;
  c10_tl_x = c10_theta_4;
  c10_ul_x = c10_tl_x;
  c10_ul_x = muDoubleScalarSin(c10_ul_x);
  c10_je_b = c10_ul_x;
  c10_ef_y = 93.0 * c10_je_b;
  c10_vl_x = c10_theta_1;
  c10_wl_x = c10_vl_x;
  c10_wl_x = muDoubleScalarCos(c10_wl_x);
  c10_xl_x = c10_theta_2;
  c10_yl_x = c10_xl_x;
  c10_yl_x = muDoubleScalarCos(c10_yl_x);
  c10_od_a = c10_wl_x;
  c10_ke_b = c10_yl_x;
  c10_ff_y = c10_od_a * c10_ke_b;
  c10_am_x = c10_theta_3;
  c10_bm_x = c10_am_x;
  c10_bm_x = muDoubleScalarSin(c10_bm_x);
  c10_pd_a = c10_ff_y;
  c10_le_b = c10_bm_x;
  c10_gf_y = c10_pd_a * c10_le_b;
  c10_cm_x = c10_theta_1;
  c10_dm_x = c10_cm_x;
  c10_dm_x = muDoubleScalarCos(c10_dm_x);
  c10_em_x = c10_theta_3;
  c10_fm_x = c10_em_x;
  c10_fm_x = muDoubleScalarCos(c10_fm_x);
  c10_qd_a = c10_dm_x;
  c10_me_b = c10_fm_x;
  c10_hf_y = c10_qd_a * c10_me_b;
  c10_gm_x = c10_theta_2;
  c10_hm_x = c10_gm_x;
  c10_hm_x = muDoubleScalarSin(c10_hm_x);
  c10_rd_a = c10_hf_y;
  c10_ne_b = c10_hm_x;
  c10_if_y = c10_rd_a * c10_ne_b;
  c10_sd_a = c10_ef_y;
  c10_oe_b = c10_gf_y + c10_if_y;
  c10_jf_y = c10_sd_a * c10_oe_b;
  c10_u_A = c10_jf_y;
  c10_im_x = c10_u_A;
  c10_jm_x = c10_im_x;
  c10_kf_y = c10_jm_x / 1000.0;
  c10_km_x = c10_theta_4;
  c10_lm_x = c10_km_x;
  c10_lm_x = muDoubleScalarCos(c10_lm_x);
  c10_pe_b = c10_lm_x;
  c10_lf_y = 93.0 * c10_pe_b;
  c10_mm_x = c10_theta_1;
  c10_nm_x = c10_mm_x;
  c10_nm_x = muDoubleScalarCos(c10_nm_x);
  c10_om_x = c10_theta_2;
  c10_pm_x = c10_om_x;
  c10_pm_x = muDoubleScalarSin(c10_pm_x);
  c10_td_a = c10_nm_x;
  c10_qe_b = c10_pm_x;
  c10_mf_y = c10_td_a * c10_qe_b;
  c10_qm_x = c10_theta_3;
  c10_rm_x = c10_qm_x;
  c10_rm_x = muDoubleScalarSin(c10_rm_x);
  c10_ud_a = c10_mf_y;
  c10_re_b = c10_rm_x;
  c10_nf_y = c10_ud_a * c10_re_b;
  c10_sm_x = c10_theta_1;
  c10_tm_x = c10_sm_x;
  c10_tm_x = muDoubleScalarCos(c10_tm_x);
  c10_um_x = c10_theta_2;
  c10_vm_x = c10_um_x;
  c10_vm_x = muDoubleScalarCos(c10_vm_x);
  c10_vd_a = c10_tm_x;
  c10_se_b = c10_vm_x;
  c10_of_y = c10_vd_a * c10_se_b;
  c10_wm_x = c10_theta_3;
  c10_xm_x = c10_wm_x;
  c10_xm_x = muDoubleScalarCos(c10_xm_x);
  c10_wd_a = c10_of_y;
  c10_te_b = c10_xm_x;
  c10_pf_y = c10_wd_a * c10_te_b;
  c10_xd_a = c10_lf_y;
  c10_ue_b = c10_nf_y - c10_pf_y;
  c10_qf_y = c10_xd_a * c10_ue_b;
  c10_v_A = c10_qf_y;
  c10_ym_x = c10_v_A;
  c10_an_x = c10_ym_x;
  c10_rf_y = c10_an_x / 1000.0;
  c10_bn_x = c10_theta_5;
  c10_cn_x = c10_bn_x;
  c10_cn_x = muDoubleScalarCos(c10_cn_x);
  c10_ve_b = c10_cn_x;
  c10_sf_y = 41.0 * c10_ve_b;
  c10_dn_x = c10_theta_4;
  c10_en_x = c10_dn_x;
  c10_en_x = muDoubleScalarCos(c10_en_x);
  c10_fn_x = c10_theta_1;
  c10_gn_x = c10_fn_x;
  c10_gn_x = muDoubleScalarCos(c10_gn_x);
  c10_hn_x = c10_theta_2;
  c10_in_x = c10_hn_x;
  c10_in_x = muDoubleScalarSin(c10_in_x);
  c10_yd_a = c10_gn_x;
  c10_we_b = c10_in_x;
  c10_tf_y = c10_yd_a * c10_we_b;
  c10_jn_x = c10_theta_3;
  c10_kn_x = c10_jn_x;
  c10_kn_x = muDoubleScalarSin(c10_kn_x);
  c10_ae_a = c10_tf_y;
  c10_xe_b = c10_kn_x;
  c10_uf_y = c10_ae_a * c10_xe_b;
  c10_ln_x = c10_theta_1;
  c10_mn_x = c10_ln_x;
  c10_mn_x = muDoubleScalarCos(c10_mn_x);
  c10_nn_x = c10_theta_2;
  c10_on_x = c10_nn_x;
  c10_on_x = muDoubleScalarCos(c10_on_x);
  c10_be_a = c10_mn_x;
  c10_ye_b = c10_on_x;
  c10_vf_y = c10_be_a * c10_ye_b;
  c10_pn_x = c10_theta_3;
  c10_qn_x = c10_pn_x;
  c10_qn_x = muDoubleScalarCos(c10_qn_x);
  c10_ce_a = c10_vf_y;
  c10_af_b = c10_qn_x;
  c10_wf_y = c10_ce_a * c10_af_b;
  c10_de_a = c10_en_x;
  c10_bf_b = c10_uf_y - c10_wf_y;
  c10_xf_y = c10_de_a * c10_bf_b;
  c10_rn_x = c10_theta_4;
  c10_sn_x = c10_rn_x;
  c10_sn_x = muDoubleScalarSin(c10_sn_x);
  c10_tn_x = c10_theta_1;
  c10_un_x = c10_tn_x;
  c10_un_x = muDoubleScalarCos(c10_un_x);
  c10_vn_x = c10_theta_2;
  c10_wn_x = c10_vn_x;
  c10_wn_x = muDoubleScalarCos(c10_wn_x);
  c10_ee_a = c10_un_x;
  c10_cf_b = c10_wn_x;
  c10_yf_y = c10_ee_a * c10_cf_b;
  c10_xn_x = c10_theta_3;
  c10_yn_x = c10_xn_x;
  c10_yn_x = muDoubleScalarSin(c10_yn_x);
  c10_fe_a = c10_yf_y;
  c10_df_b = c10_yn_x;
  c10_ag_y = c10_fe_a * c10_df_b;
  c10_ao_x = c10_theta_1;
  c10_bo_x = c10_ao_x;
  c10_bo_x = muDoubleScalarCos(c10_bo_x);
  c10_co_x = c10_theta_3;
  c10_do_x = c10_co_x;
  c10_do_x = muDoubleScalarCos(c10_do_x);
  c10_ge_a = c10_bo_x;
  c10_ef_b = c10_do_x;
  c10_bg_y = c10_ge_a * c10_ef_b;
  c10_eo_x = c10_theta_2;
  c10_fo_x = c10_eo_x;
  c10_fo_x = muDoubleScalarSin(c10_fo_x);
  c10_he_a = c10_bg_y;
  c10_ff_b = c10_fo_x;
  c10_cg_y = c10_he_a * c10_ff_b;
  c10_ie_a = c10_sn_x;
  c10_gf_b = c10_ag_y + c10_cg_y;
  c10_dg_y = c10_ie_a * c10_gf_b;
  c10_je_a = c10_sf_y;
  c10_hf_b = c10_xf_y + c10_dg_y;
  c10_eg_y = c10_je_a * c10_hf_b;
  c10_w_A = c10_eg_y;
  c10_go_x = c10_w_A;
  c10_ho_x = c10_go_x;
  c10_fg_y = c10_ho_x / 500.0;
  c10_io_x = c10_theta_1;
  c10_jo_x = c10_io_x;
  c10_jo_x = muDoubleScalarSin(c10_jo_x);
  c10_if_b = c10_jo_x;
  c10_gg_y = 41.0 * c10_if_b;
  c10_ko_x = c10_theta_5;
  c10_lo_x = c10_ko_x;
  c10_lo_x = muDoubleScalarSin(c10_lo_x);
  c10_ke_a = c10_gg_y;
  c10_jf_b = c10_lo_x;
  c10_hg_y = c10_ke_a * c10_jf_b;
  c10_x_A = c10_hg_y;
  c10_mo_x = c10_x_A;
  c10_no_x = c10_mo_x;
  c10_ig_y = c10_no_x / 500.0;
  c10_oo_x = c10_theta_1;
  c10_po_x = c10_oo_x;
  c10_po_x = muDoubleScalarSin(c10_po_x);
  c10_kf_b = c10_po_x;
  c10_jg_y = 109.0 * c10_kf_b;
  c10_y_A = c10_jg_y;
  c10_qo_x = c10_y_A;
  c10_ro_x = c10_qo_x;
  c10_kg_y = c10_ro_x / 1000.0;
  c10_so_x = c10_theta_1;
  c10_to_x = c10_so_x;
  c10_to_x = muDoubleScalarCos(c10_to_x);
  c10_lf_b = c10_to_x;
  c10_lg_y = 17.0 * c10_lf_b;
  c10_uo_x = c10_theta_2;
  c10_vo_x = c10_uo_x;
  c10_vo_x = muDoubleScalarCos(c10_vo_x);
  c10_le_a = c10_lg_y;
  c10_mf_b = c10_vo_x;
  c10_mg_y = c10_le_a * c10_mf_b;
  c10_ab_A = c10_mg_y;
  c10_wo_x = c10_ab_A;
  c10_xo_x = c10_wo_x;
  c10_ng_y = c10_xo_x / 40.0;
  c10_yo_x = c10_theta_5;
  c10_ap_x = c10_yo_x;
  c10_ap_x = muDoubleScalarCos(c10_ap_x);
  c10_nf_b = c10_ap_x;
  c10_og_y = 41.0 * c10_nf_b;
  c10_bp_x = c10_theta_1;
  c10_cp_x = c10_bp_x;
  c10_cp_x = muDoubleScalarSin(c10_cp_x);
  c10_me_a = c10_og_y;
  c10_of_b = c10_cp_x;
  c10_pg_y = c10_me_a * c10_of_b;
  c10_bb_A = c10_pg_y;
  c10_dp_x = c10_bb_A;
  c10_ep_x = c10_dp_x;
  c10_qg_y = c10_ep_x / 500.0;
  c10_fp_x = c10_theta_4;
  c10_gp_x = c10_fp_x;
  c10_gp_x = muDoubleScalarCos(c10_gp_x);
  c10_pf_b = c10_gp_x;
  c10_rg_y = 93.0 * c10_pf_b;
  c10_hp_x = c10_theta_1;
  c10_ip_x = c10_hp_x;
  c10_ip_x = muDoubleScalarCos(c10_ip_x);
  c10_jp_x = c10_theta_2;
  c10_kp_x = c10_jp_x;
  c10_kp_x = muDoubleScalarCos(c10_kp_x);
  c10_ne_a = c10_ip_x;
  c10_qf_b = c10_kp_x;
  c10_sg_y = c10_ne_a * c10_qf_b;
  c10_lp_x = c10_theta_3;
  c10_mp_x = c10_lp_x;
  c10_mp_x = muDoubleScalarSin(c10_mp_x);
  c10_oe_a = c10_sg_y;
  c10_rf_b = c10_mp_x;
  c10_tg_y = c10_oe_a * c10_rf_b;
  c10_np_x = c10_theta_1;
  c10_op_x = c10_np_x;
  c10_op_x = muDoubleScalarCos(c10_op_x);
  c10_pp_x = c10_theta_3;
  c10_qp_x = c10_pp_x;
  c10_qp_x = muDoubleScalarCos(c10_qp_x);
  c10_pe_a = c10_op_x;
  c10_sf_b = c10_qp_x;
  c10_ug_y = c10_pe_a * c10_sf_b;
  c10_rp_x = c10_theta_2;
  c10_sp_x = c10_rp_x;
  c10_sp_x = muDoubleScalarSin(c10_sp_x);
  c10_qe_a = c10_ug_y;
  c10_tf_b = c10_sp_x;
  c10_vg_y = c10_qe_a * c10_tf_b;
  c10_re_a = c10_rg_y;
  c10_uf_b = c10_tg_y + c10_vg_y;
  c10_wg_y = c10_re_a * c10_uf_b;
  c10_cb_A = c10_wg_y;
  c10_tp_x = c10_cb_A;
  c10_up_x = c10_tp_x;
  c10_xg_y = c10_up_x / 1000.0;
  c10_vp_x = c10_theta_4;
  c10_wp_x = c10_vp_x;
  c10_wp_x = muDoubleScalarSin(c10_wp_x);
  c10_vf_b = c10_wp_x;
  c10_yg_y = 93.0 * c10_vf_b;
  c10_xp_x = c10_theta_1;
  c10_yp_x = c10_xp_x;
  c10_yp_x = muDoubleScalarCos(c10_yp_x);
  c10_aq_x = c10_theta_2;
  c10_bq_x = c10_aq_x;
  c10_bq_x = muDoubleScalarSin(c10_bq_x);
  c10_se_a = c10_yp_x;
  c10_wf_b = c10_bq_x;
  c10_ah_y = c10_se_a * c10_wf_b;
  c10_cq_x = c10_theta_3;
  c10_dq_x = c10_cq_x;
  c10_dq_x = muDoubleScalarSin(c10_dq_x);
  c10_te_a = c10_ah_y;
  c10_xf_b = c10_dq_x;
  c10_bh_y = c10_te_a * c10_xf_b;
  c10_eq_x = c10_theta_1;
  c10_fq_x = c10_eq_x;
  c10_fq_x = muDoubleScalarCos(c10_fq_x);
  c10_gq_x = c10_theta_2;
  c10_hq_x = c10_gq_x;
  c10_hq_x = muDoubleScalarCos(c10_hq_x);
  c10_ue_a = c10_fq_x;
  c10_yf_b = c10_hq_x;
  c10_ch_y = c10_ue_a * c10_yf_b;
  c10_iq_x = c10_theta_3;
  c10_jq_x = c10_iq_x;
  c10_jq_x = muDoubleScalarCos(c10_jq_x);
  c10_ve_a = c10_ch_y;
  c10_ag_b = c10_jq_x;
  c10_dh_y = c10_ve_a * c10_ag_b;
  c10_we_a = c10_yg_y;
  c10_bg_b = c10_bh_y - c10_dh_y;
  c10_eh_y = c10_we_a * c10_bg_b;
  c10_db_A = c10_eh_y;
  c10_kq_x = c10_db_A;
  c10_lq_x = c10_kq_x;
  c10_fh_y = c10_lq_x / 1000.0;
  c10_mq_x = c10_theta_5;
  c10_nq_x = c10_mq_x;
  c10_nq_x = muDoubleScalarSin(c10_nq_x);
  c10_cg_b = c10_nq_x;
  c10_gh_y = 41.0 * c10_cg_b;
  c10_oq_x = c10_theta_4;
  c10_pq_x = c10_oq_x;
  c10_pq_x = muDoubleScalarCos(c10_pq_x);
  c10_qq_x = c10_theta_1;
  c10_rq_x = c10_qq_x;
  c10_rq_x = muDoubleScalarCos(c10_rq_x);
  c10_sq_x = c10_theta_2;
  c10_tq_x = c10_sq_x;
  c10_tq_x = muDoubleScalarSin(c10_tq_x);
  c10_xe_a = c10_rq_x;
  c10_dg_b = c10_tq_x;
  c10_hh_y = c10_xe_a * c10_dg_b;
  c10_uq_x = c10_theta_3;
  c10_vq_x = c10_uq_x;
  c10_vq_x = muDoubleScalarSin(c10_vq_x);
  c10_ye_a = c10_hh_y;
  c10_eg_b = c10_vq_x;
  c10_ih_y = c10_ye_a * c10_eg_b;
  c10_wq_x = c10_theta_1;
  c10_xq_x = c10_wq_x;
  c10_xq_x = muDoubleScalarCos(c10_xq_x);
  c10_yq_x = c10_theta_2;
  c10_ar_x = c10_yq_x;
  c10_ar_x = muDoubleScalarCos(c10_ar_x);
  c10_af_a = c10_xq_x;
  c10_fg_b = c10_ar_x;
  c10_jh_y = c10_af_a * c10_fg_b;
  c10_br_x = c10_theta_3;
  c10_cr_x = c10_br_x;
  c10_cr_x = muDoubleScalarCos(c10_cr_x);
  c10_bf_a = c10_jh_y;
  c10_gg_b = c10_cr_x;
  c10_kh_y = c10_bf_a * c10_gg_b;
  c10_cf_a = c10_pq_x;
  c10_hg_b = c10_ih_y - c10_kh_y;
  c10_lh_y = c10_cf_a * c10_hg_b;
  c10_dr_x = c10_theta_4;
  c10_er_x = c10_dr_x;
  c10_er_x = muDoubleScalarSin(c10_er_x);
  c10_fr_x = c10_theta_1;
  c10_gr_x = c10_fr_x;
  c10_gr_x = muDoubleScalarCos(c10_gr_x);
  c10_hr_x = c10_theta_2;
  c10_ir_x = c10_hr_x;
  c10_ir_x = muDoubleScalarCos(c10_ir_x);
  c10_df_a = c10_gr_x;
  c10_ig_b = c10_ir_x;
  c10_mh_y = c10_df_a * c10_ig_b;
  c10_jr_x = c10_theta_3;
  c10_kr_x = c10_jr_x;
  c10_kr_x = muDoubleScalarSin(c10_kr_x);
  c10_ef_a = c10_mh_y;
  c10_jg_b = c10_kr_x;
  c10_nh_y = c10_ef_a * c10_jg_b;
  c10_lr_x = c10_theta_1;
  c10_mr_x = c10_lr_x;
  c10_mr_x = muDoubleScalarCos(c10_mr_x);
  c10_nr_x = c10_theta_3;
  c10_or_x = c10_nr_x;
  c10_or_x = muDoubleScalarCos(c10_or_x);
  c10_ff_a = c10_mr_x;
  c10_kg_b = c10_or_x;
  c10_oh_y = c10_ff_a * c10_kg_b;
  c10_pr_x = c10_theta_2;
  c10_qr_x = c10_pr_x;
  c10_qr_x = muDoubleScalarSin(c10_qr_x);
  c10_gf_a = c10_oh_y;
  c10_lg_b = c10_qr_x;
  c10_ph_y = c10_gf_a * c10_lg_b;
  c10_hf_a = c10_er_x;
  c10_mg_b = c10_nh_y + c10_ph_y;
  c10_qh_y = c10_hf_a * c10_mg_b;
  c10_if_a = c10_gh_y;
  c10_ng_b = c10_lh_y + c10_qh_y;
  c10_rh_y = c10_if_a * c10_ng_b;
  c10_eb_A = c10_rh_y;
  c10_rr_x = c10_eb_A;
  c10_sr_x = c10_rr_x;
  c10_sh_y = c10_sr_x / 500.0;
  c10_tr_x = c10_theta_1;
  c10_ur_x = c10_tr_x;
  c10_ur_x = muDoubleScalarCos(c10_ur_x);
  c10_og_b = c10_ur_x;
  c10_th_y = 39243.0 * c10_og_b;
  c10_vr_x = c10_theta_2;
  c10_wr_x = c10_vr_x;
  c10_wr_x = muDoubleScalarSin(c10_wr_x);
  c10_jf_a = c10_th_y;
  c10_pg_b = c10_wr_x;
  c10_uh_y = c10_jf_a * c10_pg_b;
  c10_xr_x = c10_theta_3;
  c10_yr_x = c10_xr_x;
  c10_yr_x = muDoubleScalarSin(c10_yr_x);
  c10_kf_a = c10_uh_y;
  c10_qg_b = c10_yr_x;
  c10_vh_y = c10_kf_a * c10_qg_b;
  c10_fb_A = c10_vh_y;
  c10_as_x = c10_fb_A;
  c10_bs_x = c10_as_x;
  c10_wh_y = c10_bs_x / 100000.0;
  c10_cs_x = c10_theta_1;
  c10_ds_x = c10_cs_x;
  c10_ds_x = muDoubleScalarCos(c10_ds_x);
  c10_rg_b = c10_ds_x;
  c10_xh_y = 39243.0 * c10_rg_b;
  c10_es_x = c10_theta_2;
  c10_fs_x = c10_es_x;
  c10_fs_x = muDoubleScalarCos(c10_fs_x);
  c10_lf_a = c10_xh_y;
  c10_sg_b = c10_fs_x;
  c10_yh_y = c10_lf_a * c10_sg_b;
  c10_gs_x = c10_theta_3;
  c10_hs_x = c10_gs_x;
  c10_hs_x = muDoubleScalarCos(c10_hs_x);
  c10_mf_a = c10_yh_y;
  c10_tg_b = c10_hs_x;
  c10_ai_y = c10_mf_a * c10_tg_b;
  c10_gb_A = c10_ai_y;
  c10_is_x = c10_gb_A;
  c10_js_x = c10_is_x;
  c10_bi_y = c10_js_x / 100000.0;
  c10_ks_x = c10_theta_1;
  c10_ls_x = c10_ks_x;
  c10_ls_x = muDoubleScalarSin(c10_ls_x);
  c10_ug_b = c10_ls_x;
  c10_ci_y = 17.0 * c10_ug_b;
  c10_ms_x = c10_theta_2;
  c10_ns_x = c10_ms_x;
  c10_ns_x = muDoubleScalarSin(c10_ns_x);
  c10_nf_a = c10_ci_y;
  c10_vg_b = c10_ns_x;
  c10_di_y = c10_nf_a * c10_vg_b;
  c10_hb_A = c10_di_y;
  c10_os_x = c10_hb_A;
  c10_ps_x = c10_os_x;
  c10_ei_y = c10_ps_x / 40.0;
  c10_qs_x = c10_theta_4;
  c10_rs_x = c10_qs_x;
  c10_rs_x = muDoubleScalarCos(c10_rs_x);
  c10_wg_b = c10_rs_x;
  c10_fi_y = 93.0 * c10_wg_b;
  c10_ss_x = c10_theta_1;
  c10_ts_x = c10_ss_x;
  c10_ts_x = muDoubleScalarSin(c10_ts_x);
  c10_us_x = c10_theta_2;
  c10_vs_x = c10_us_x;
  c10_vs_x = muDoubleScalarSin(c10_vs_x);
  c10_of_a = c10_ts_x;
  c10_xg_b = c10_vs_x;
  c10_gi_y = c10_of_a * c10_xg_b;
  c10_ws_x = c10_theta_3;
  c10_xs_x = c10_ws_x;
  c10_xs_x = muDoubleScalarSin(c10_xs_x);
  c10_pf_a = c10_gi_y;
  c10_yg_b = c10_xs_x;
  c10_hi_y = c10_pf_a * c10_yg_b;
  c10_ys_x = c10_theta_2;
  c10_at_x = c10_ys_x;
  c10_at_x = muDoubleScalarCos(c10_at_x);
  c10_bt_x = c10_theta_3;
  c10_ct_x = c10_bt_x;
  c10_ct_x = muDoubleScalarCos(c10_ct_x);
  c10_qf_a = c10_at_x;
  c10_ah_b = c10_ct_x;
  c10_ii_y = c10_qf_a * c10_ah_b;
  c10_dt_x = c10_theta_1;
  c10_et_x = c10_dt_x;
  c10_et_x = muDoubleScalarSin(c10_et_x);
  c10_rf_a = c10_ii_y;
  c10_bh_b = c10_et_x;
  c10_ji_y = c10_rf_a * c10_bh_b;
  c10_sf_a = c10_fi_y;
  c10_ch_b = c10_hi_y - c10_ji_y;
  c10_ki_y = c10_sf_a * c10_ch_b;
  c10_ib_A = c10_ki_y;
  c10_ft_x = c10_ib_A;
  c10_gt_x = c10_ft_x;
  c10_li_y = c10_gt_x / 1000.0;
  c10_ht_x = c10_theta_4;
  c10_it_x = c10_ht_x;
  c10_it_x = muDoubleScalarSin(c10_it_x);
  c10_dh_b = c10_it_x;
  c10_mi_y = 93.0 * c10_dh_b;
  c10_jt_x = c10_theta_2;
  c10_kt_x = c10_jt_x;
  c10_kt_x = muDoubleScalarCos(c10_kt_x);
  c10_lt_x = c10_theta_1;
  c10_mt_x = c10_lt_x;
  c10_mt_x = muDoubleScalarSin(c10_mt_x);
  c10_tf_a = c10_kt_x;
  c10_eh_b = c10_mt_x;
  c10_ni_y = c10_tf_a * c10_eh_b;
  c10_nt_x = c10_theta_3;
  c10_ot_x = c10_nt_x;
  c10_ot_x = muDoubleScalarSin(c10_ot_x);
  c10_uf_a = c10_ni_y;
  c10_fh_b = c10_ot_x;
  c10_oi_y = c10_uf_a * c10_fh_b;
  c10_pt_x = c10_theta_3;
  c10_qt_x = c10_pt_x;
  c10_qt_x = muDoubleScalarCos(c10_qt_x);
  c10_rt_x = c10_theta_1;
  c10_st_x = c10_rt_x;
  c10_st_x = muDoubleScalarSin(c10_st_x);
  c10_vf_a = c10_qt_x;
  c10_gh_b = c10_st_x;
  c10_pi_y = c10_vf_a * c10_gh_b;
  c10_tt_x = c10_theta_2;
  c10_ut_x = c10_tt_x;
  c10_ut_x = muDoubleScalarSin(c10_ut_x);
  c10_wf_a = c10_pi_y;
  c10_hh_b = c10_ut_x;
  c10_qi_y = c10_wf_a * c10_hh_b;
  c10_xf_a = c10_mi_y;
  c10_ih_b = c10_oi_y + c10_qi_y;
  c10_ri_y = c10_xf_a * c10_ih_b;
  c10_jb_A = c10_ri_y;
  c10_vt_x = c10_jb_A;
  c10_wt_x = c10_vt_x;
  c10_si_y = c10_wt_x / 1000.0;
  c10_xt_x = c10_theta_5;
  c10_yt_x = c10_xt_x;
  c10_yt_x = muDoubleScalarSin(c10_yt_x);
  c10_jh_b = c10_yt_x;
  c10_ti_y = 41.0 * c10_jh_b;
  c10_au_x = c10_theta_4;
  c10_bu_x = c10_au_x;
  c10_bu_x = muDoubleScalarCos(c10_bu_x);
  c10_cu_x = c10_theta_2;
  c10_du_x = c10_cu_x;
  c10_du_x = muDoubleScalarCos(c10_du_x);
  c10_eu_x = c10_theta_1;
  c10_fu_x = c10_eu_x;
  c10_fu_x = muDoubleScalarSin(c10_fu_x);
  c10_yf_a = c10_du_x;
  c10_kh_b = c10_fu_x;
  c10_ui_y = c10_yf_a * c10_kh_b;
  c10_gu_x = c10_theta_3;
  c10_hu_x = c10_gu_x;
  c10_hu_x = muDoubleScalarSin(c10_hu_x);
  c10_ag_a = c10_ui_y;
  c10_lh_b = c10_hu_x;
  c10_vi_y = c10_ag_a * c10_lh_b;
  c10_iu_x = c10_theta_3;
  c10_ju_x = c10_iu_x;
  c10_ju_x = muDoubleScalarCos(c10_ju_x);
  c10_ku_x = c10_theta_1;
  c10_lu_x = c10_ku_x;
  c10_lu_x = muDoubleScalarSin(c10_lu_x);
  c10_bg_a = c10_ju_x;
  c10_mh_b = c10_lu_x;
  c10_wi_y = c10_bg_a * c10_mh_b;
  c10_mu_x = c10_theta_2;
  c10_nu_x = c10_mu_x;
  c10_nu_x = muDoubleScalarSin(c10_nu_x);
  c10_cg_a = c10_wi_y;
  c10_nh_b = c10_nu_x;
  c10_xi_y = c10_cg_a * c10_nh_b;
  c10_dg_a = c10_bu_x;
  c10_oh_b = c10_vi_y + c10_xi_y;
  c10_yi_y = c10_dg_a * c10_oh_b;
  c10_ou_x = c10_theta_4;
  c10_pu_x = c10_ou_x;
  c10_pu_x = muDoubleScalarSin(c10_pu_x);
  c10_qu_x = c10_theta_1;
  c10_ru_x = c10_qu_x;
  c10_ru_x = muDoubleScalarSin(c10_ru_x);
  c10_su_x = c10_theta_2;
  c10_tu_x = c10_su_x;
  c10_tu_x = muDoubleScalarSin(c10_tu_x);
  c10_eg_a = c10_ru_x;
  c10_ph_b = c10_tu_x;
  c10_aj_y = c10_eg_a * c10_ph_b;
  c10_uu_x = c10_theta_3;
  c10_vu_x = c10_uu_x;
  c10_vu_x = muDoubleScalarSin(c10_vu_x);
  c10_fg_a = c10_aj_y;
  c10_qh_b = c10_vu_x;
  c10_bj_y = c10_fg_a * c10_qh_b;
  c10_wu_x = c10_theta_2;
  c10_xu_x = c10_wu_x;
  c10_xu_x = muDoubleScalarCos(c10_xu_x);
  c10_yu_x = c10_theta_3;
  c10_av_x = c10_yu_x;
  c10_av_x = muDoubleScalarCos(c10_av_x);
  c10_gg_a = c10_xu_x;
  c10_rh_b = c10_av_x;
  c10_cj_y = c10_gg_a * c10_rh_b;
  c10_bv_x = c10_theta_1;
  c10_cv_x = c10_bv_x;
  c10_cv_x = muDoubleScalarSin(c10_cv_x);
  c10_hg_a = c10_cj_y;
  c10_sh_b = c10_cv_x;
  c10_dj_y = c10_hg_a * c10_sh_b;
  c10_ig_a = c10_pu_x;
  c10_th_b = c10_bj_y - c10_dj_y;
  c10_ej_y = c10_ig_a * c10_th_b;
  c10_jg_a = c10_ti_y;
  c10_uh_b = c10_yi_y - c10_ej_y;
  c10_fj_y = c10_jg_a * c10_uh_b;
  c10_kb_A = c10_fj_y;
  c10_dv_x = c10_kb_A;
  c10_ev_x = c10_dv_x;
  c10_gj_y = c10_ev_x / 500.0;
  c10_fv_x = c10_theta_2;
  c10_gv_x = c10_fv_x;
  c10_gv_x = muDoubleScalarCos(c10_gv_x);
  c10_vh_b = c10_gv_x;
  c10_hj_y = 39243.0 * c10_vh_b;
  c10_hv_x = c10_theta_1;
  c10_iv_x = c10_hv_x;
  c10_iv_x = muDoubleScalarSin(c10_iv_x);
  c10_kg_a = c10_hj_y;
  c10_wh_b = c10_iv_x;
  c10_ij_y = c10_kg_a * c10_wh_b;
  c10_jv_x = c10_theta_3;
  c10_kv_x = c10_jv_x;
  c10_kv_x = muDoubleScalarSin(c10_kv_x);
  c10_lg_a = c10_ij_y;
  c10_xh_b = c10_kv_x;
  c10_jj_y = c10_lg_a * c10_xh_b;
  c10_lb_A = c10_jj_y;
  c10_lv_x = c10_lb_A;
  c10_mv_x = c10_lv_x;
  c10_kj_y = c10_mv_x / 100000.0;
  c10_nv_x = c10_theta_3;
  c10_ov_x = c10_nv_x;
  c10_ov_x = muDoubleScalarCos(c10_ov_x);
  c10_yh_b = c10_ov_x;
  c10_lj_y = 39243.0 * c10_yh_b;
  c10_pv_x = c10_theta_1;
  c10_qv_x = c10_pv_x;
  c10_qv_x = muDoubleScalarSin(c10_qv_x);
  c10_mg_a = c10_lj_y;
  c10_ai_b = c10_qv_x;
  c10_mj_y = c10_mg_a * c10_ai_b;
  c10_rv_x = c10_theta_2;
  c10_sv_x = c10_rv_x;
  c10_sv_x = muDoubleScalarSin(c10_sv_x);
  c10_ng_a = c10_mj_y;
  c10_bi_b = c10_sv_x;
  c10_nj_y = c10_ng_a * c10_bi_b;
  c10_mb_A = c10_nj_y;
  c10_tv_x = c10_mb_A;
  c10_uv_x = c10_tv_x;
  c10_oj_y = c10_uv_x / 100000.0;
  c10_vv_x = c10_theta_5;
  c10_wv_x = c10_vv_x;
  c10_wv_x = muDoubleScalarSin(c10_wv_x);
  c10_ci_b = c10_wv_x;
  c10_pj_y = 41.0 * c10_ci_b;
  c10_xv_x = c10_theta_4;
  c10_yv_x = c10_xv_x;
  c10_yv_x = muDoubleScalarCos(c10_yv_x);
  c10_aw_x = c10_theta_2;
  c10_bw_x = c10_aw_x;
  c10_bw_x = muDoubleScalarCos(c10_bw_x);
  c10_cw_x = c10_theta_1;
  c10_dw_x = c10_cw_x;
  c10_dw_x = muDoubleScalarSin(c10_dw_x);
  c10_og_a = c10_bw_x;
  c10_di_b = c10_dw_x;
  c10_qj_y = c10_og_a * c10_di_b;
  c10_ew_x = c10_theta_3;
  c10_fw_x = c10_ew_x;
  c10_fw_x = muDoubleScalarSin(c10_fw_x);
  c10_pg_a = c10_qj_y;
  c10_ei_b = c10_fw_x;
  c10_rj_y = c10_pg_a * c10_ei_b;
  c10_gw_x = c10_theta_3;
  c10_hw_x = c10_gw_x;
  c10_hw_x = muDoubleScalarCos(c10_hw_x);
  c10_iw_x = c10_theta_1;
  c10_jw_x = c10_iw_x;
  c10_jw_x = muDoubleScalarSin(c10_jw_x);
  c10_qg_a = c10_hw_x;
  c10_fi_b = c10_jw_x;
  c10_sj_y = c10_qg_a * c10_fi_b;
  c10_kw_x = c10_theta_2;
  c10_lw_x = c10_kw_x;
  c10_lw_x = muDoubleScalarSin(c10_lw_x);
  c10_rg_a = c10_sj_y;
  c10_gi_b = c10_lw_x;
  c10_tj_y = c10_rg_a * c10_gi_b;
  c10_sg_a = c10_yv_x;
  c10_hi_b = c10_rj_y + c10_tj_y;
  c10_uj_y = c10_sg_a * c10_hi_b;
  c10_mw_x = c10_theta_4;
  c10_nw_x = c10_mw_x;
  c10_nw_x = muDoubleScalarSin(c10_nw_x);
  c10_ow_x = c10_theta_1;
  c10_pw_x = c10_ow_x;
  c10_pw_x = muDoubleScalarSin(c10_pw_x);
  c10_qw_x = c10_theta_2;
  c10_rw_x = c10_qw_x;
  c10_rw_x = muDoubleScalarSin(c10_rw_x);
  c10_tg_a = c10_pw_x;
  c10_ii_b = c10_rw_x;
  c10_vj_y = c10_tg_a * c10_ii_b;
  c10_sw_x = c10_theta_3;
  c10_tw_x = c10_sw_x;
  c10_tw_x = muDoubleScalarSin(c10_tw_x);
  c10_ug_a = c10_vj_y;
  c10_ji_b = c10_tw_x;
  c10_wj_y = c10_ug_a * c10_ji_b;
  c10_uw_x = c10_theta_2;
  c10_vw_x = c10_uw_x;
  c10_vw_x = muDoubleScalarCos(c10_vw_x);
  c10_ww_x = c10_theta_3;
  c10_xw_x = c10_ww_x;
  c10_xw_x = muDoubleScalarCos(c10_xw_x);
  c10_vg_a = c10_vw_x;
  c10_ki_b = c10_xw_x;
  c10_xj_y = c10_vg_a * c10_ki_b;
  c10_yw_x = c10_theta_1;
  c10_ax_x = c10_yw_x;
  c10_ax_x = muDoubleScalarSin(c10_ax_x);
  c10_wg_a = c10_xj_y;
  c10_li_b = c10_ax_x;
  c10_yj_y = c10_wg_a * c10_li_b;
  c10_xg_a = c10_nw_x;
  c10_mi_b = c10_wj_y - c10_yj_y;
  c10_ak_y = c10_xg_a * c10_mi_b;
  c10_yg_a = c10_pj_y;
  c10_ni_b = c10_uj_y - c10_ak_y;
  c10_bk_y = c10_yg_a * c10_ni_b;
  c10_nb_A = c10_bk_y;
  c10_bx_x = c10_nb_A;
  c10_cx_x = c10_bx_x;
  c10_ck_y = c10_cx_x / 500.0;
  c10_dx_x = c10_theta_4;
  c10_ex_x = c10_dx_x;
  c10_ex_x = muDoubleScalarSin(c10_ex_x);
  c10_oi_b = c10_ex_x;
  c10_dk_y = 93.0 * c10_oi_b;
  c10_fx_x = c10_theta_2;
  c10_gx_x = c10_fx_x;
  c10_gx_x = muDoubleScalarCos(c10_gx_x);
  c10_hx_x = c10_theta_1;
  c10_ix_x = c10_hx_x;
  c10_ix_x = muDoubleScalarSin(c10_ix_x);
  c10_ah_a = c10_gx_x;
  c10_pi_b = c10_ix_x;
  c10_ek_y = c10_ah_a * c10_pi_b;
  c10_jx_x = c10_theta_3;
  c10_kx_x = c10_jx_x;
  c10_kx_x = muDoubleScalarSin(c10_kx_x);
  c10_bh_a = c10_ek_y;
  c10_qi_b = c10_kx_x;
  c10_fk_y = c10_bh_a * c10_qi_b;
  c10_lx_x = c10_theta_3;
  c10_mx_x = c10_lx_x;
  c10_mx_x = muDoubleScalarCos(c10_mx_x);
  c10_nx_x = c10_theta_1;
  c10_ox_x = c10_nx_x;
  c10_ox_x = muDoubleScalarSin(c10_ox_x);
  c10_ch_a = c10_mx_x;
  c10_ri_b = c10_ox_x;
  c10_gk_y = c10_ch_a * c10_ri_b;
  c10_px_x = c10_theta_2;
  c10_qx_x = c10_px_x;
  c10_qx_x = muDoubleScalarSin(c10_qx_x);
  c10_dh_a = c10_gk_y;
  c10_si_b = c10_qx_x;
  c10_hk_y = c10_dh_a * c10_si_b;
  c10_eh_a = c10_dk_y;
  c10_ti_b = c10_fk_y + c10_hk_y;
  c10_ik_y = c10_eh_a * c10_ti_b;
  c10_ob_A = c10_ik_y;
  c10_rx_x = c10_ob_A;
  c10_sx_x = c10_rx_x;
  c10_jk_y = c10_sx_x / 1000.0;
  c10_tx_x = c10_theta_4;
  c10_ux_x = c10_tx_x;
  c10_ux_x = muDoubleScalarCos(c10_ux_x);
  c10_ui_b = c10_ux_x;
  c10_kk_y = 93.0 * c10_ui_b;
  c10_vx_x = c10_theta_1;
  c10_wx_x = c10_vx_x;
  c10_wx_x = muDoubleScalarSin(c10_wx_x);
  c10_xx_x = c10_theta_2;
  c10_yx_x = c10_xx_x;
  c10_yx_x = muDoubleScalarSin(c10_yx_x);
  c10_fh_a = c10_wx_x;
  c10_vi_b = c10_yx_x;
  c10_lk_y = c10_fh_a * c10_vi_b;
  c10_ay_x = c10_theta_3;
  c10_by_x = c10_ay_x;
  c10_by_x = muDoubleScalarSin(c10_by_x);
  c10_gh_a = c10_lk_y;
  c10_wi_b = c10_by_x;
  c10_mk_y = c10_gh_a * c10_wi_b;
  c10_cy_x = c10_theta_2;
  c10_dy_x = c10_cy_x;
  c10_dy_x = muDoubleScalarCos(c10_dy_x);
  c10_ey_x = c10_theta_3;
  c10_fy_x = c10_ey_x;
  c10_fy_x = muDoubleScalarCos(c10_fy_x);
  c10_hh_a = c10_dy_x;
  c10_xi_b = c10_fy_x;
  c10_nk_y = c10_hh_a * c10_xi_b;
  c10_gy_x = c10_theta_1;
  c10_hy_x = c10_gy_x;
  c10_hy_x = muDoubleScalarSin(c10_hy_x);
  c10_ih_a = c10_nk_y;
  c10_yi_b = c10_hy_x;
  c10_ok_y = c10_ih_a * c10_yi_b;
  c10_jh_a = c10_kk_y;
  c10_aj_b = c10_mk_y - c10_ok_y;
  c10_pk_y = c10_jh_a * c10_aj_b;
  c10_pb_A = c10_pk_y;
  c10_iy_x = c10_pb_A;
  c10_jy_x = c10_iy_x;
  c10_qk_y = c10_jy_x / 1000.0;
  c10_ky_x = c10_theta_2;
  c10_ly_x = c10_ky_x;
  c10_ly_x = muDoubleScalarCos(c10_ly_x);
  c10_bj_b = c10_ly_x;
  c10_rk_y = 39243.0 * c10_bj_b;
  c10_my_x = c10_theta_1;
  c10_ny_x = c10_my_x;
  c10_ny_x = muDoubleScalarSin(c10_ny_x);
  c10_kh_a = c10_rk_y;
  c10_cj_b = c10_ny_x;
  c10_sk_y = c10_kh_a * c10_cj_b;
  c10_oy_x = c10_theta_3;
  c10_py_x = c10_oy_x;
  c10_py_x = muDoubleScalarSin(c10_py_x);
  c10_lh_a = c10_sk_y;
  c10_dj_b = c10_py_x;
  c10_tk_y = c10_lh_a * c10_dj_b;
  c10_qb_A = c10_tk_y;
  c10_qy_x = c10_qb_A;
  c10_ry_x = c10_qy_x;
  c10_uk_y = c10_ry_x / 100000.0;
  c10_sy_x = c10_theta_3;
  c10_ty_x = c10_sy_x;
  c10_ty_x = muDoubleScalarCos(c10_ty_x);
  c10_ej_b = c10_ty_x;
  c10_vk_y = 39243.0 * c10_ej_b;
  c10_uy_x = c10_theta_1;
  c10_vy_x = c10_uy_x;
  c10_vy_x = muDoubleScalarSin(c10_vy_x);
  c10_mh_a = c10_vk_y;
  c10_fj_b = c10_vy_x;
  c10_wk_y = c10_mh_a * c10_fj_b;
  c10_wy_x = c10_theta_2;
  c10_xy_x = c10_wy_x;
  c10_xy_x = muDoubleScalarSin(c10_xy_x);
  c10_nh_a = c10_wk_y;
  c10_gj_b = c10_xy_x;
  c10_xk_y = c10_nh_a * c10_gj_b;
  c10_rb_A = c10_xk_y;
  c10_yy_x = c10_rb_A;
  c10_aab_x = c10_yy_x;
  c10_yk_y = c10_aab_x / 100000.0;
  c10_bab_x = c10_theta_5;
  c10_cab_x = c10_bab_x;
  c10_cab_x = muDoubleScalarSin(c10_cab_x);
  c10_hj_b = c10_cab_x;
  c10_al_y = 41.0 * c10_hj_b;
  c10_dab_x = c10_theta_4;
  c10_eab_x = c10_dab_x;
  c10_eab_x = muDoubleScalarCos(c10_eab_x);
  c10_fab_x = c10_theta_2;
  c10_gab_x = c10_fab_x;
  c10_gab_x = muDoubleScalarCos(c10_gab_x);
  c10_hab_x = c10_theta_1;
  c10_iab_x = c10_hab_x;
  c10_iab_x = muDoubleScalarSin(c10_iab_x);
  c10_oh_a = c10_gab_x;
  c10_ij_b = c10_iab_x;
  c10_bl_y = c10_oh_a * c10_ij_b;
  c10_jab_x = c10_theta_3;
  c10_kab_x = c10_jab_x;
  c10_kab_x = muDoubleScalarSin(c10_kab_x);
  c10_ph_a = c10_bl_y;
  c10_jj_b = c10_kab_x;
  c10_cl_y = c10_ph_a * c10_jj_b;
  c10_lab_x = c10_theta_3;
  c10_mab_x = c10_lab_x;
  c10_mab_x = muDoubleScalarCos(c10_mab_x);
  c10_nab_x = c10_theta_1;
  c10_oab_x = c10_nab_x;
  c10_oab_x = muDoubleScalarSin(c10_oab_x);
  c10_qh_a = c10_mab_x;
  c10_kj_b = c10_oab_x;
  c10_dl_y = c10_qh_a * c10_kj_b;
  c10_pab_x = c10_theta_2;
  c10_qab_x = c10_pab_x;
  c10_qab_x = muDoubleScalarSin(c10_qab_x);
  c10_rh_a = c10_dl_y;
  c10_lj_b = c10_qab_x;
  c10_el_y = c10_rh_a * c10_lj_b;
  c10_sh_a = c10_eab_x;
  c10_mj_b = c10_cl_y + c10_el_y;
  c10_fl_y = c10_sh_a * c10_mj_b;
  c10_rab_x = c10_theta_4;
  c10_sab_x = c10_rab_x;
  c10_sab_x = muDoubleScalarSin(c10_sab_x);
  c10_tab_x = c10_theta_1;
  c10_uab_x = c10_tab_x;
  c10_uab_x = muDoubleScalarSin(c10_uab_x);
  c10_vab_x = c10_theta_2;
  c10_wab_x = c10_vab_x;
  c10_wab_x = muDoubleScalarSin(c10_wab_x);
  c10_th_a = c10_uab_x;
  c10_nj_b = c10_wab_x;
  c10_gl_y = c10_th_a * c10_nj_b;
  c10_xab_x = c10_theta_3;
  c10_yab_x = c10_xab_x;
  c10_yab_x = muDoubleScalarSin(c10_yab_x);
  c10_uh_a = c10_gl_y;
  c10_oj_b = c10_yab_x;
  c10_hl_y = c10_uh_a * c10_oj_b;
  c10_abb_x = c10_theta_2;
  c10_bbb_x = c10_abb_x;
  c10_bbb_x = muDoubleScalarCos(c10_bbb_x);
  c10_cbb_x = c10_theta_3;
  c10_dbb_x = c10_cbb_x;
  c10_dbb_x = muDoubleScalarCos(c10_dbb_x);
  c10_vh_a = c10_bbb_x;
  c10_pj_b = c10_dbb_x;
  c10_il_y = c10_vh_a * c10_pj_b;
  c10_ebb_x = c10_theta_1;
  c10_fbb_x = c10_ebb_x;
  c10_fbb_x = muDoubleScalarSin(c10_fbb_x);
  c10_wh_a = c10_il_y;
  c10_qj_b = c10_fbb_x;
  c10_jl_y = c10_wh_a * c10_qj_b;
  c10_xh_a = c10_sab_x;
  c10_rj_b = c10_hl_y - c10_jl_y;
  c10_kl_y = c10_xh_a * c10_rj_b;
  c10_yh_a = c10_al_y;
  c10_sj_b = c10_fl_y - c10_kl_y;
  c10_ll_y = c10_yh_a * c10_sj_b;
  c10_sb_A = c10_ll_y;
  c10_gbb_x = c10_sb_A;
  c10_hbb_x = c10_gbb_x;
  c10_ml_y = c10_hbb_x / 500.0;
  c10_ibb_x = c10_theta_4;
  c10_jbb_x = c10_ibb_x;
  c10_jbb_x = muDoubleScalarSin(c10_jbb_x);
  c10_tj_b = c10_jbb_x;
  c10_nl_y = 93.0 * c10_tj_b;
  c10_kbb_x = c10_theta_2;
  c10_lbb_x = c10_kbb_x;
  c10_lbb_x = muDoubleScalarCos(c10_lbb_x);
  c10_mbb_x = c10_theta_1;
  c10_nbb_x = c10_mbb_x;
  c10_nbb_x = muDoubleScalarSin(c10_nbb_x);
  c10_ai_a = c10_lbb_x;
  c10_uj_b = c10_nbb_x;
  c10_ol_y = c10_ai_a * c10_uj_b;
  c10_obb_x = c10_theta_3;
  c10_pbb_x = c10_obb_x;
  c10_pbb_x = muDoubleScalarSin(c10_pbb_x);
  c10_bi_a = c10_ol_y;
  c10_vj_b = c10_pbb_x;
  c10_pl_y = c10_bi_a * c10_vj_b;
  c10_qbb_x = c10_theta_3;
  c10_rbb_x = c10_qbb_x;
  c10_rbb_x = muDoubleScalarCos(c10_rbb_x);
  c10_sbb_x = c10_theta_1;
  c10_tbb_x = c10_sbb_x;
  c10_tbb_x = muDoubleScalarSin(c10_tbb_x);
  c10_ci_a = c10_rbb_x;
  c10_wj_b = c10_tbb_x;
  c10_ql_y = c10_ci_a * c10_wj_b;
  c10_ubb_x = c10_theta_2;
  c10_vbb_x = c10_ubb_x;
  c10_vbb_x = muDoubleScalarSin(c10_vbb_x);
  c10_di_a = c10_ql_y;
  c10_xj_b = c10_vbb_x;
  c10_rl_y = c10_di_a * c10_xj_b;
  c10_ei_a = c10_nl_y;
  c10_yj_b = c10_pl_y + c10_rl_y;
  c10_sl_y = c10_ei_a * c10_yj_b;
  c10_tb_A = c10_sl_y;
  c10_wbb_x = c10_tb_A;
  c10_xbb_x = c10_wbb_x;
  c10_tl_y = c10_xbb_x / 1000.0;
  c10_ybb_x = c10_theta_4;
  c10_acb_x = c10_ybb_x;
  c10_acb_x = muDoubleScalarCos(c10_acb_x);
  c10_ak_b = c10_acb_x;
  c10_ul_y = 93.0 * c10_ak_b;
  c10_bcb_x = c10_theta_1;
  c10_ccb_x = c10_bcb_x;
  c10_ccb_x = muDoubleScalarSin(c10_ccb_x);
  c10_dcb_x = c10_theta_2;
  c10_ecb_x = c10_dcb_x;
  c10_ecb_x = muDoubleScalarSin(c10_ecb_x);
  c10_fi_a = c10_ccb_x;
  c10_bk_b = c10_ecb_x;
  c10_vl_y = c10_fi_a * c10_bk_b;
  c10_fcb_x = c10_theta_3;
  c10_gcb_x = c10_fcb_x;
  c10_gcb_x = muDoubleScalarSin(c10_gcb_x);
  c10_gi_a = c10_vl_y;
  c10_ck_b = c10_gcb_x;
  c10_wl_y = c10_gi_a * c10_ck_b;
  c10_hcb_x = c10_theta_2;
  c10_icb_x = c10_hcb_x;
  c10_icb_x = muDoubleScalarCos(c10_icb_x);
  c10_jcb_x = c10_theta_3;
  c10_kcb_x = c10_jcb_x;
  c10_kcb_x = muDoubleScalarCos(c10_kcb_x);
  c10_hi_a = c10_icb_x;
  c10_dk_b = c10_kcb_x;
  c10_xl_y = c10_hi_a * c10_dk_b;
  c10_lcb_x = c10_theta_1;
  c10_mcb_x = c10_lcb_x;
  c10_mcb_x = muDoubleScalarSin(c10_mcb_x);
  c10_ii_a = c10_xl_y;
  c10_ek_b = c10_mcb_x;
  c10_yl_y = c10_ii_a * c10_ek_b;
  c10_ji_a = c10_ul_y;
  c10_fk_b = c10_wl_y - c10_yl_y;
  c10_am_y = c10_ji_a * c10_fk_b;
  c10_ub_A = c10_am_y;
  c10_ncb_x = c10_ub_A;
  c10_ocb_x = c10_ncb_x;
  c10_bm_y = c10_ocb_x / 1000.0;
  c10_pcb_x = c10_theta_1;
  c10_qcb_x = c10_pcb_x;
  c10_qcb_x = muDoubleScalarCos(c10_qcb_x);
  c10_gk_b = c10_qcb_x;
  c10_cm_y = 41.0 * c10_gk_b;
  c10_rcb_x = c10_theta_5;
  c10_scb_x = c10_rcb_x;
  c10_scb_x = muDoubleScalarSin(c10_scb_x);
  c10_ki_a = c10_cm_y;
  c10_hk_b = c10_scb_x;
  c10_dm_y = c10_ki_a * c10_hk_b;
  c10_vb_A = c10_dm_y;
  c10_tcb_x = c10_vb_A;
  c10_ucb_x = c10_tcb_x;
  c10_em_y = c10_ucb_x / 500.0;
  c10_vcb_x = c10_theta_5;
  c10_wcb_x = c10_vcb_x;
  c10_wcb_x = muDoubleScalarCos(c10_wcb_x);
  c10_ik_b = c10_wcb_x;
  c10_fm_y = 41.0 * c10_ik_b;
  c10_xcb_x = c10_theta_4;
  c10_ycb_x = c10_xcb_x;
  c10_ycb_x = muDoubleScalarCos(c10_ycb_x);
  c10_adb_x = c10_theta_1;
  c10_bdb_x = c10_adb_x;
  c10_bdb_x = muDoubleScalarSin(c10_bdb_x);
  c10_cdb_x = c10_theta_2;
  c10_ddb_x = c10_cdb_x;
  c10_ddb_x = muDoubleScalarSin(c10_ddb_x);
  c10_li_a = c10_bdb_x;
  c10_jk_b = c10_ddb_x;
  c10_gm_y = c10_li_a * c10_jk_b;
  c10_edb_x = c10_theta_3;
  c10_fdb_x = c10_edb_x;
  c10_fdb_x = muDoubleScalarSin(c10_fdb_x);
  c10_mi_a = c10_gm_y;
  c10_kk_b = c10_fdb_x;
  c10_hm_y = c10_mi_a * c10_kk_b;
  c10_gdb_x = c10_theta_2;
  c10_hdb_x = c10_gdb_x;
  c10_hdb_x = muDoubleScalarCos(c10_hdb_x);
  c10_idb_x = c10_theta_3;
  c10_jdb_x = c10_idb_x;
  c10_jdb_x = muDoubleScalarCos(c10_jdb_x);
  c10_ni_a = c10_hdb_x;
  c10_lk_b = c10_jdb_x;
  c10_im_y = c10_ni_a * c10_lk_b;
  c10_kdb_x = c10_theta_1;
  c10_ldb_x = c10_kdb_x;
  c10_ldb_x = muDoubleScalarSin(c10_ldb_x);
  c10_oi_a = c10_im_y;
  c10_mk_b = c10_ldb_x;
  c10_jm_y = c10_oi_a * c10_mk_b;
  c10_pi_a = c10_ycb_x;
  c10_nk_b = c10_hm_y - c10_jm_y;
  c10_km_y = c10_pi_a * c10_nk_b;
  c10_mdb_x = c10_theta_4;
  c10_ndb_x = c10_mdb_x;
  c10_ndb_x = muDoubleScalarSin(c10_ndb_x);
  c10_odb_x = c10_theta_2;
  c10_pdb_x = c10_odb_x;
  c10_pdb_x = muDoubleScalarCos(c10_pdb_x);
  c10_qdb_x = c10_theta_1;
  c10_rdb_x = c10_qdb_x;
  c10_rdb_x = muDoubleScalarSin(c10_rdb_x);
  c10_qi_a = c10_pdb_x;
  c10_ok_b = c10_rdb_x;
  c10_lm_y = c10_qi_a * c10_ok_b;
  c10_sdb_x = c10_theta_3;
  c10_tdb_x = c10_sdb_x;
  c10_tdb_x = muDoubleScalarSin(c10_tdb_x);
  c10_ri_a = c10_lm_y;
  c10_pk_b = c10_tdb_x;
  c10_mm_y = c10_ri_a * c10_pk_b;
  c10_udb_x = c10_theta_3;
  c10_vdb_x = c10_udb_x;
  c10_vdb_x = muDoubleScalarCos(c10_vdb_x);
  c10_wdb_x = c10_theta_1;
  c10_xdb_x = c10_wdb_x;
  c10_xdb_x = muDoubleScalarSin(c10_xdb_x);
  c10_si_a = c10_vdb_x;
  c10_qk_b = c10_xdb_x;
  c10_nm_y = c10_si_a * c10_qk_b;
  c10_ydb_x = c10_theta_2;
  c10_aeb_x = c10_ydb_x;
  c10_aeb_x = muDoubleScalarSin(c10_aeb_x);
  c10_ti_a = c10_nm_y;
  c10_rk_b = c10_aeb_x;
  c10_om_y = c10_ti_a * c10_rk_b;
  c10_ui_a = c10_ndb_x;
  c10_sk_b = c10_mm_y + c10_om_y;
  c10_pm_y = c10_ui_a * c10_sk_b;
  c10_vi_a = c10_fm_y;
  c10_tk_b = c10_km_y + c10_pm_y;
  c10_qm_y = c10_vi_a * c10_tk_b;
  c10_wb_A = c10_qm_y;
  c10_beb_x = c10_wb_A;
  c10_ceb_x = c10_beb_x;
  c10_rm_y = c10_ceb_x / 500.0;
  c10_deb_x = c10_theta_2;
  c10_eeb_x = c10_deb_x;
  c10_eeb_x = muDoubleScalarSin(c10_eeb_x);
  c10_uk_b = c10_eeb_x;
  c10_sm_y = 39243.0 * c10_uk_b;
  c10_feb_x = c10_theta_3;
  c10_geb_x = c10_feb_x;
  c10_geb_x = muDoubleScalarSin(c10_geb_x);
  c10_wi_a = c10_sm_y;
  c10_vk_b = c10_geb_x;
  c10_tm_y = c10_wi_a * c10_vk_b;
  c10_xb_A = c10_tm_y;
  c10_heb_x = c10_xb_A;
  c10_ieb_x = c10_heb_x;
  c10_um_y = c10_ieb_x / 100000.0;
  c10_jeb_x = c10_theta_2;
  c10_keb_x = c10_jeb_x;
  c10_keb_x = muDoubleScalarCos(c10_keb_x);
  c10_wk_b = c10_keb_x;
  c10_vm_y = 39243.0 * c10_wk_b;
  c10_leb_x = c10_theta_3;
  c10_meb_x = c10_leb_x;
  c10_meb_x = muDoubleScalarCos(c10_meb_x);
  c10_xi_a = c10_vm_y;
  c10_xk_b = c10_meb_x;
  c10_wm_y = c10_xi_a * c10_xk_b;
  c10_yb_A = c10_wm_y;
  c10_neb_x = c10_yb_A;
  c10_oeb_x = c10_neb_x;
  c10_xm_y = c10_oeb_x / 100000.0;
  c10_peb_x = c10_theta_2;
  c10_qeb_x = c10_peb_x;
  c10_qeb_x = muDoubleScalarCos(c10_qeb_x);
  c10_yk_b = c10_qeb_x;
  c10_ym_y = 17.0 * c10_yk_b;
  c10_ac_A = c10_ym_y;
  c10_reb_x = c10_ac_A;
  c10_seb_x = c10_reb_x;
  c10_an_y = c10_seb_x / 40.0;
  c10_teb_x = c10_theta_5;
  c10_ueb_x = c10_teb_x;
  c10_ueb_x = muDoubleScalarSin(c10_ueb_x);
  c10_al_b = c10_ueb_x;
  c10_bn_y = 41.0 * c10_al_b;
  c10_veb_x = c10_theta_4;
  c10_web_x = c10_veb_x;
  c10_web_x = muDoubleScalarCos(c10_web_x);
  c10_xeb_x = c10_theta_2;
  c10_yeb_x = c10_xeb_x;
  c10_yeb_x = muDoubleScalarCos(c10_yeb_x);
  c10_afb_x = c10_theta_3;
  c10_bfb_x = c10_afb_x;
  c10_bfb_x = muDoubleScalarCos(c10_bfb_x);
  c10_yi_a = c10_yeb_x;
  c10_bl_b = c10_bfb_x;
  c10_cn_y = c10_yi_a * c10_bl_b;
  c10_cfb_x = c10_theta_2;
  c10_dfb_x = c10_cfb_x;
  c10_dfb_x = muDoubleScalarSin(c10_dfb_x);
  c10_efb_x = c10_theta_3;
  c10_ffb_x = c10_efb_x;
  c10_ffb_x = muDoubleScalarSin(c10_ffb_x);
  c10_aj_a = c10_dfb_x;
  c10_cl_b = c10_ffb_x;
  c10_dn_y = c10_aj_a * c10_cl_b;
  c10_bj_a = c10_web_x;
  c10_dl_b = c10_cn_y - c10_dn_y;
  c10_en_y = c10_bj_a * c10_dl_b;
  c10_gfb_x = c10_theta_4;
  c10_hfb_x = c10_gfb_x;
  c10_hfb_x = muDoubleScalarSin(c10_hfb_x);
  c10_ifb_x = c10_theta_2;
  c10_jfb_x = c10_ifb_x;
  c10_jfb_x = muDoubleScalarCos(c10_jfb_x);
  c10_kfb_x = c10_theta_3;
  c10_lfb_x = c10_kfb_x;
  c10_lfb_x = muDoubleScalarSin(c10_lfb_x);
  c10_cj_a = c10_jfb_x;
  c10_el_b = c10_lfb_x;
  c10_fn_y = c10_cj_a * c10_el_b;
  c10_mfb_x = c10_theta_3;
  c10_nfb_x = c10_mfb_x;
  c10_nfb_x = muDoubleScalarCos(c10_nfb_x);
  c10_ofb_x = c10_theta_2;
  c10_pfb_x = c10_ofb_x;
  c10_pfb_x = muDoubleScalarSin(c10_pfb_x);
  c10_dj_a = c10_nfb_x;
  c10_fl_b = c10_pfb_x;
  c10_gn_y = c10_dj_a * c10_fl_b;
  c10_ej_a = c10_hfb_x;
  c10_gl_b = c10_fn_y + c10_gn_y;
  c10_hn_y = c10_ej_a * c10_gl_b;
  c10_fj_a = c10_bn_y;
  c10_hl_b = c10_en_y - c10_hn_y;
  c10_in_y = c10_fj_a * c10_hl_b;
  c10_bc_A = c10_in_y;
  c10_qfb_x = c10_bc_A;
  c10_rfb_x = c10_qfb_x;
  c10_jn_y = c10_rfb_x / 500.0;
  c10_sfb_x = c10_theta_4;
  c10_tfb_x = c10_sfb_x;
  c10_tfb_x = muDoubleScalarCos(c10_tfb_x);
  c10_il_b = c10_tfb_x;
  c10_kn_y = 93.0 * c10_il_b;
  c10_ufb_x = c10_theta_2;
  c10_vfb_x = c10_ufb_x;
  c10_vfb_x = muDoubleScalarCos(c10_vfb_x);
  c10_wfb_x = c10_theta_3;
  c10_xfb_x = c10_wfb_x;
  c10_xfb_x = muDoubleScalarSin(c10_xfb_x);
  c10_gj_a = c10_vfb_x;
  c10_jl_b = c10_xfb_x;
  c10_ln_y = c10_gj_a * c10_jl_b;
  c10_yfb_x = c10_theta_3;
  c10_agb_x = c10_yfb_x;
  c10_agb_x = muDoubleScalarCos(c10_agb_x);
  c10_bgb_x = c10_theta_2;
  c10_cgb_x = c10_bgb_x;
  c10_cgb_x = muDoubleScalarSin(c10_cgb_x);
  c10_hj_a = c10_agb_x;
  c10_kl_b = c10_cgb_x;
  c10_mn_y = c10_hj_a * c10_kl_b;
  c10_ij_a = c10_kn_y;
  c10_ll_b = c10_ln_y + c10_mn_y;
  c10_nn_y = c10_ij_a * c10_ll_b;
  c10_cc_A = c10_nn_y;
  c10_dgb_x = c10_cc_A;
  c10_egb_x = c10_dgb_x;
  c10_on_y = c10_egb_x / 1000.0;
  c10_fgb_x = c10_theta_4;
  c10_ggb_x = c10_fgb_x;
  c10_ggb_x = muDoubleScalarSin(c10_ggb_x);
  c10_ml_b = c10_ggb_x;
  c10_pn_y = 93.0 * c10_ml_b;
  c10_hgb_x = c10_theta_2;
  c10_igb_x = c10_hgb_x;
  c10_igb_x = muDoubleScalarCos(c10_igb_x);
  c10_jgb_x = c10_theta_3;
  c10_kgb_x = c10_jgb_x;
  c10_kgb_x = muDoubleScalarCos(c10_kgb_x);
  c10_jj_a = c10_igb_x;
  c10_nl_b = c10_kgb_x;
  c10_qn_y = c10_jj_a * c10_nl_b;
  c10_lgb_x = c10_theta_2;
  c10_mgb_x = c10_lgb_x;
  c10_mgb_x = muDoubleScalarSin(c10_mgb_x);
  c10_ngb_x = c10_theta_3;
  c10_ogb_x = c10_ngb_x;
  c10_ogb_x = muDoubleScalarSin(c10_ogb_x);
  c10_kj_a = c10_mgb_x;
  c10_ol_b = c10_ogb_x;
  c10_rn_y = c10_kj_a * c10_ol_b;
  c10_lj_a = c10_pn_y;
  c10_pl_b = c10_qn_y - c10_rn_y;
  c10_sn_y = c10_lj_a * c10_pl_b;
  c10_dc_A = c10_sn_y;
  c10_pgb_x = c10_dc_A;
  c10_qgb_x = c10_pgb_x;
  c10_tn_y = c10_qgb_x / 1000.0;
  c10_rgb_x = c10_theta_2;
  c10_sgb_x = c10_rgb_x;
  c10_sgb_x = muDoubleScalarSin(c10_sgb_x);
  c10_ql_b = c10_sgb_x;
  c10_un_y = 39243.0 * c10_ql_b;
  c10_tgb_x = c10_theta_3;
  c10_ugb_x = c10_tgb_x;
  c10_ugb_x = muDoubleScalarSin(c10_ugb_x);
  c10_mj_a = c10_un_y;
  c10_rl_b = c10_ugb_x;
  c10_vn_y = c10_mj_a * c10_rl_b;
  c10_ec_A = c10_vn_y;
  c10_vgb_x = c10_ec_A;
  c10_wgb_x = c10_vgb_x;
  c10_wn_y = c10_wgb_x / 100000.0;
  c10_xgb_x = c10_theta_2;
  c10_ygb_x = c10_xgb_x;
  c10_ygb_x = muDoubleScalarCos(c10_ygb_x);
  c10_sl_b = c10_ygb_x;
  c10_xn_y = 39243.0 * c10_sl_b;
  c10_ahb_x = c10_theta_3;
  c10_bhb_x = c10_ahb_x;
  c10_bhb_x = muDoubleScalarCos(c10_bhb_x);
  c10_nj_a = c10_xn_y;
  c10_tl_b = c10_bhb_x;
  c10_yn_y = c10_nj_a * c10_tl_b;
  c10_fc_A = c10_yn_y;
  c10_chb_x = c10_fc_A;
  c10_dhb_x = c10_chb_x;
  c10_ao_y = c10_dhb_x / 100000.0;
  c10_ehb_x = c10_theta_5;
  c10_fhb_x = c10_ehb_x;
  c10_fhb_x = muDoubleScalarSin(c10_fhb_x);
  c10_ul_b = c10_fhb_x;
  c10_bo_y = 41.0 * c10_ul_b;
  c10_ghb_x = c10_theta_4;
  c10_hhb_x = c10_ghb_x;
  c10_hhb_x = muDoubleScalarCos(c10_hhb_x);
  c10_ihb_x = c10_theta_2;
  c10_jhb_x = c10_ihb_x;
  c10_jhb_x = muDoubleScalarCos(c10_jhb_x);
  c10_khb_x = c10_theta_3;
  c10_lhb_x = c10_khb_x;
  c10_lhb_x = muDoubleScalarCos(c10_lhb_x);
  c10_oj_a = c10_jhb_x;
  c10_vl_b = c10_lhb_x;
  c10_co_y = c10_oj_a * c10_vl_b;
  c10_mhb_x = c10_theta_2;
  c10_nhb_x = c10_mhb_x;
  c10_nhb_x = muDoubleScalarSin(c10_nhb_x);
  c10_ohb_x = c10_theta_3;
  c10_phb_x = c10_ohb_x;
  c10_phb_x = muDoubleScalarSin(c10_phb_x);
  c10_pj_a = c10_nhb_x;
  c10_wl_b = c10_phb_x;
  c10_do_y = c10_pj_a * c10_wl_b;
  c10_qj_a = c10_hhb_x;
  c10_xl_b = c10_co_y - c10_do_y;
  c10_eo_y = c10_qj_a * c10_xl_b;
  c10_qhb_x = c10_theta_4;
  c10_rhb_x = c10_qhb_x;
  c10_rhb_x = muDoubleScalarSin(c10_rhb_x);
  c10_shb_x = c10_theta_2;
  c10_thb_x = c10_shb_x;
  c10_thb_x = muDoubleScalarCos(c10_thb_x);
  c10_uhb_x = c10_theta_3;
  c10_vhb_x = c10_uhb_x;
  c10_vhb_x = muDoubleScalarSin(c10_vhb_x);
  c10_rj_a = c10_thb_x;
  c10_yl_b = c10_vhb_x;
  c10_fo_y = c10_rj_a * c10_yl_b;
  c10_whb_x = c10_theta_3;
  c10_xhb_x = c10_whb_x;
  c10_xhb_x = muDoubleScalarCos(c10_xhb_x);
  c10_yhb_x = c10_theta_2;
  c10_aib_x = c10_yhb_x;
  c10_aib_x = muDoubleScalarSin(c10_aib_x);
  c10_sj_a = c10_xhb_x;
  c10_am_b = c10_aib_x;
  c10_go_y = c10_sj_a * c10_am_b;
  c10_tj_a = c10_rhb_x;
  c10_bm_b = c10_fo_y + c10_go_y;
  c10_ho_y = c10_tj_a * c10_bm_b;
  c10_uj_a = c10_bo_y;
  c10_cm_b = c10_eo_y - c10_ho_y;
  c10_io_y = c10_uj_a * c10_cm_b;
  c10_gc_A = c10_io_y;
  c10_bib_x = c10_gc_A;
  c10_cib_x = c10_bib_x;
  c10_jo_y = c10_cib_x / 500.0;
  c10_dib_x = c10_theta_4;
  c10_eib_x = c10_dib_x;
  c10_eib_x = muDoubleScalarCos(c10_eib_x);
  c10_dm_b = c10_eib_x;
  c10_ko_y = 93.0 * c10_dm_b;
  c10_fib_x = c10_theta_2;
  c10_gib_x = c10_fib_x;
  c10_gib_x = muDoubleScalarCos(c10_gib_x);
  c10_hib_x = c10_theta_3;
  c10_iib_x = c10_hib_x;
  c10_iib_x = muDoubleScalarSin(c10_iib_x);
  c10_vj_a = c10_gib_x;
  c10_em_b = c10_iib_x;
  c10_lo_y = c10_vj_a * c10_em_b;
  c10_jib_x = c10_theta_3;
  c10_kib_x = c10_jib_x;
  c10_kib_x = muDoubleScalarCos(c10_kib_x);
  c10_lib_x = c10_theta_2;
  c10_mib_x = c10_lib_x;
  c10_mib_x = muDoubleScalarSin(c10_mib_x);
  c10_wj_a = c10_kib_x;
  c10_fm_b = c10_mib_x;
  c10_mo_y = c10_wj_a * c10_fm_b;
  c10_xj_a = c10_ko_y;
  c10_gm_b = c10_lo_y + c10_mo_y;
  c10_no_y = c10_xj_a * c10_gm_b;
  c10_hc_A = c10_no_y;
  c10_nib_x = c10_hc_A;
  c10_oib_x = c10_nib_x;
  c10_oo_y = c10_oib_x / 1000.0;
  c10_pib_x = c10_theta_4;
  c10_qib_x = c10_pib_x;
  c10_qib_x = muDoubleScalarSin(c10_qib_x);
  c10_hm_b = c10_qib_x;
  c10_po_y = 93.0 * c10_hm_b;
  c10_rib_x = c10_theta_2;
  c10_sib_x = c10_rib_x;
  c10_sib_x = muDoubleScalarCos(c10_sib_x);
  c10_tib_x = c10_theta_3;
  c10_uib_x = c10_tib_x;
  c10_uib_x = muDoubleScalarCos(c10_uib_x);
  c10_yj_a = c10_sib_x;
  c10_im_b = c10_uib_x;
  c10_qo_y = c10_yj_a * c10_im_b;
  c10_vib_x = c10_theta_2;
  c10_wib_x = c10_vib_x;
  c10_wib_x = muDoubleScalarSin(c10_wib_x);
  c10_xib_x = c10_theta_3;
  c10_yib_x = c10_xib_x;
  c10_yib_x = muDoubleScalarSin(c10_yib_x);
  c10_ak_a = c10_wib_x;
  c10_jm_b = c10_yib_x;
  c10_ro_y = c10_ak_a * c10_jm_b;
  c10_bk_a = c10_po_y;
  c10_km_b = c10_qo_y - c10_ro_y;
  c10_so_y = c10_bk_a * c10_km_b;
  c10_ic_A = c10_so_y;
  c10_ajb_x = c10_ic_A;
  c10_bjb_x = c10_ajb_x;
  c10_to_y = c10_bjb_x / 1000.0;
  c10_cjb_x = c10_theta_4;
  c10_djb_x = c10_cjb_x;
  c10_djb_x = muDoubleScalarCos(c10_djb_x);
  c10_lm_b = c10_djb_x;
  c10_uo_y = 93.0 * c10_lm_b;
  c10_ejb_x = c10_theta_2;
  c10_fjb_x = c10_ejb_x;
  c10_fjb_x = muDoubleScalarCos(c10_fjb_x);
  c10_gjb_x = c10_theta_3;
  c10_hjb_x = c10_gjb_x;
  c10_hjb_x = muDoubleScalarSin(c10_hjb_x);
  c10_ck_a = c10_fjb_x;
  c10_mm_b = c10_hjb_x;
  c10_vo_y = c10_ck_a * c10_mm_b;
  c10_ijb_x = c10_theta_3;
  c10_jjb_x = c10_ijb_x;
  c10_jjb_x = muDoubleScalarCos(c10_jjb_x);
  c10_kjb_x = c10_theta_2;
  c10_ljb_x = c10_kjb_x;
  c10_ljb_x = muDoubleScalarSin(c10_ljb_x);
  c10_dk_a = c10_jjb_x;
  c10_nm_b = c10_ljb_x;
  c10_wo_y = c10_dk_a * c10_nm_b;
  c10_ek_a = c10_uo_y;
  c10_om_b = c10_vo_y + c10_wo_y;
  c10_xo_y = c10_ek_a * c10_om_b;
  c10_jc_A = c10_xo_y;
  c10_mjb_x = c10_jc_A;
  c10_njb_x = c10_mjb_x;
  c10_yo_y = c10_njb_x / 1000.0;
  c10_ojb_x = c10_theta_5;
  c10_pjb_x = c10_ojb_x;
  c10_pjb_x = muDoubleScalarSin(c10_pjb_x);
  c10_pm_b = c10_pjb_x;
  c10_ap_y = 41.0 * c10_pm_b;
  c10_qjb_x = c10_theta_4;
  c10_rjb_x = c10_qjb_x;
  c10_rjb_x = muDoubleScalarCos(c10_rjb_x);
  c10_sjb_x = c10_theta_2;
  c10_tjb_x = c10_sjb_x;
  c10_tjb_x = muDoubleScalarCos(c10_tjb_x);
  c10_ujb_x = c10_theta_3;
  c10_vjb_x = c10_ujb_x;
  c10_vjb_x = muDoubleScalarCos(c10_vjb_x);
  c10_fk_a = c10_tjb_x;
  c10_qm_b = c10_vjb_x;
  c10_bp_y = c10_fk_a * c10_qm_b;
  c10_wjb_x = c10_theta_2;
  c10_xjb_x = c10_wjb_x;
  c10_xjb_x = muDoubleScalarSin(c10_xjb_x);
  c10_yjb_x = c10_theta_3;
  c10_akb_x = c10_yjb_x;
  c10_akb_x = muDoubleScalarSin(c10_akb_x);
  c10_gk_a = c10_xjb_x;
  c10_rm_b = c10_akb_x;
  c10_cp_y = c10_gk_a * c10_rm_b;
  c10_hk_a = c10_rjb_x;
  c10_sm_b = c10_bp_y - c10_cp_y;
  c10_dp_y = c10_hk_a * c10_sm_b;
  c10_bkb_x = c10_theta_4;
  c10_ckb_x = c10_bkb_x;
  c10_ckb_x = muDoubleScalarSin(c10_ckb_x);
  c10_dkb_x = c10_theta_2;
  c10_ekb_x = c10_dkb_x;
  c10_ekb_x = muDoubleScalarCos(c10_ekb_x);
  c10_fkb_x = c10_theta_3;
  c10_gkb_x = c10_fkb_x;
  c10_gkb_x = muDoubleScalarSin(c10_gkb_x);
  c10_ik_a = c10_ekb_x;
  c10_tm_b = c10_gkb_x;
  c10_ep_y = c10_ik_a * c10_tm_b;
  c10_hkb_x = c10_theta_3;
  c10_ikb_x = c10_hkb_x;
  c10_ikb_x = muDoubleScalarCos(c10_ikb_x);
  c10_jkb_x = c10_theta_2;
  c10_kkb_x = c10_jkb_x;
  c10_kkb_x = muDoubleScalarSin(c10_kkb_x);
  c10_jk_a = c10_ikb_x;
  c10_um_b = c10_kkb_x;
  c10_fp_y = c10_jk_a * c10_um_b;
  c10_kk_a = c10_ckb_x;
  c10_vm_b = c10_ep_y + c10_fp_y;
  c10_gp_y = c10_kk_a * c10_vm_b;
  c10_lk_a = c10_ap_y;
  c10_wm_b = c10_dp_y - c10_gp_y;
  c10_hp_y = c10_lk_a * c10_wm_b;
  c10_kc_A = c10_hp_y;
  c10_lkb_x = c10_kc_A;
  c10_mkb_x = c10_lkb_x;
  c10_ip_y = c10_mkb_x / 500.0;
  c10_nkb_x = c10_theta_4;
  c10_okb_x = c10_nkb_x;
  c10_okb_x = muDoubleScalarSin(c10_okb_x);
  c10_xm_b = c10_okb_x;
  c10_jp_y = 93.0 * c10_xm_b;
  c10_pkb_x = c10_theta_2;
  c10_qkb_x = c10_pkb_x;
  c10_qkb_x = muDoubleScalarCos(c10_qkb_x);
  c10_rkb_x = c10_theta_3;
  c10_skb_x = c10_rkb_x;
  c10_skb_x = muDoubleScalarCos(c10_skb_x);
  c10_mk_a = c10_qkb_x;
  c10_ym_b = c10_skb_x;
  c10_kp_y = c10_mk_a * c10_ym_b;
  c10_tkb_x = c10_theta_2;
  c10_ukb_x = c10_tkb_x;
  c10_ukb_x = muDoubleScalarSin(c10_ukb_x);
  c10_vkb_x = c10_theta_3;
  c10_wkb_x = c10_vkb_x;
  c10_wkb_x = muDoubleScalarSin(c10_wkb_x);
  c10_nk_a = c10_ukb_x;
  c10_an_b = c10_wkb_x;
  c10_lp_y = c10_nk_a * c10_an_b;
  c10_ok_a = c10_jp_y;
  c10_bn_b = c10_kp_y - c10_lp_y;
  c10_mp_y = c10_ok_a * c10_bn_b;
  c10_lc_A = c10_mp_y;
  c10_xkb_x = c10_lc_A;
  c10_ykb_x = c10_xkb_x;
  c10_np_y = c10_ykb_x / 1000.0;
  c10_alb_x = c10_theta_5;
  c10_blb_x = c10_alb_x;
  c10_blb_x = muDoubleScalarCos(c10_blb_x);
  c10_cn_b = c10_blb_x;
  c10_op_y = 41.0 * c10_cn_b;
  c10_clb_x = c10_theta_4;
  c10_dlb_x = c10_clb_x;
  c10_dlb_x = muDoubleScalarCos(c10_dlb_x);
  c10_elb_x = c10_theta_2;
  c10_flb_x = c10_elb_x;
  c10_flb_x = muDoubleScalarCos(c10_flb_x);
  c10_glb_x = c10_theta_3;
  c10_hlb_x = c10_glb_x;
  c10_hlb_x = muDoubleScalarSin(c10_hlb_x);
  c10_pk_a = c10_flb_x;
  c10_dn_b = c10_hlb_x;
  c10_pp_y = c10_pk_a * c10_dn_b;
  c10_ilb_x = c10_theta_3;
  c10_jlb_x = c10_ilb_x;
  c10_jlb_x = muDoubleScalarCos(c10_jlb_x);
  c10_klb_x = c10_theta_2;
  c10_llb_x = c10_klb_x;
  c10_llb_x = muDoubleScalarSin(c10_llb_x);
  c10_qk_a = c10_jlb_x;
  c10_en_b = c10_llb_x;
  c10_qp_y = c10_qk_a * c10_en_b;
  c10_rk_a = c10_dlb_x;
  c10_fn_b = c10_pp_y + c10_qp_y;
  c10_rp_y = c10_rk_a * c10_fn_b;
  c10_mlb_x = c10_theta_4;
  c10_nlb_x = c10_mlb_x;
  c10_nlb_x = muDoubleScalarSin(c10_nlb_x);
  c10_olb_x = c10_theta_2;
  c10_plb_x = c10_olb_x;
  c10_plb_x = muDoubleScalarCos(c10_plb_x);
  c10_qlb_x = c10_theta_3;
  c10_rlb_x = c10_qlb_x;
  c10_rlb_x = muDoubleScalarCos(c10_rlb_x);
  c10_sk_a = c10_plb_x;
  c10_gn_b = c10_rlb_x;
  c10_sp_y = c10_sk_a * c10_gn_b;
  c10_slb_x = c10_theta_2;
  c10_tlb_x = c10_slb_x;
  c10_tlb_x = muDoubleScalarSin(c10_tlb_x);
  c10_ulb_x = c10_theta_3;
  c10_vlb_x = c10_ulb_x;
  c10_vlb_x = muDoubleScalarSin(c10_vlb_x);
  c10_tk_a = c10_tlb_x;
  c10_hn_b = c10_vlb_x;
  c10_tp_y = c10_tk_a * c10_hn_b;
  c10_uk_a = c10_nlb_x;
  c10_in_b = c10_sp_y - c10_tp_y;
  c10_up_y = c10_uk_a * c10_in_b;
  c10_vk_a = c10_op_y;
  c10_jn_b = c10_rp_y + c10_up_y;
  c10_vp_y = c10_vk_a * c10_jn_b;
  c10_mc_A = -c10_vp_y;
  c10_wlb_x = c10_mc_A;
  c10_xlb_x = c10_wlb_x;
  c10_wp_y = c10_xlb_x / 500.0;
  c10_ylb_x = c10_theta_1;
  c10_amb_x = c10_ylb_x;
  c10_amb_x = muDoubleScalarSin(c10_amb_x);
  c10_bmb_x = c10_theta_1;
  c10_cmb_x = c10_bmb_x;
  c10_cmb_x = muDoubleScalarSin(c10_cmb_x);
  c10_dmb_x = c10_theta_1;
  c10_emb_x = c10_dmb_x;
  c10_emb_x = muDoubleScalarSin(c10_emb_x);
  c10_fmb_x = c10_theta_4;
  c10_gmb_x = c10_fmb_x;
  c10_gmb_x = muDoubleScalarCos(c10_gmb_x);
  c10_hmb_x = c10_theta_1;
  c10_imb_x = c10_hmb_x;
  c10_imb_x = muDoubleScalarCos(c10_imb_x);
  c10_jmb_x = c10_theta_2;
  c10_kmb_x = c10_jmb_x;
  c10_kmb_x = muDoubleScalarCos(c10_kmb_x);
  c10_wk_a = c10_imb_x;
  c10_kn_b = c10_kmb_x;
  c10_xp_y = c10_wk_a * c10_kn_b;
  c10_lmb_x = c10_theta_3;
  c10_mmb_x = c10_lmb_x;
  c10_mmb_x = muDoubleScalarSin(c10_mmb_x);
  c10_xk_a = c10_xp_y;
  c10_ln_b = c10_mmb_x;
  c10_yp_y = c10_xk_a * c10_ln_b;
  c10_nmb_x = c10_theta_1;
  c10_omb_x = c10_nmb_x;
  c10_omb_x = muDoubleScalarCos(c10_omb_x);
  c10_pmb_x = c10_theta_3;
  c10_qmb_x = c10_pmb_x;
  c10_qmb_x = muDoubleScalarCos(c10_qmb_x);
  c10_yk_a = c10_omb_x;
  c10_mn_b = c10_qmb_x;
  c10_aq_y = c10_yk_a * c10_mn_b;
  c10_rmb_x = c10_theta_2;
  c10_smb_x = c10_rmb_x;
  c10_smb_x = muDoubleScalarSin(c10_smb_x);
  c10_al_a = c10_aq_y;
  c10_nn_b = c10_smb_x;
  c10_bq_y = c10_al_a * c10_nn_b;
  c10_bl_a = c10_gmb_x;
  c10_on_b = c10_yp_y + c10_bq_y;
  c10_cq_y = c10_bl_a * c10_on_b;
  c10_tmb_x = c10_theta_4;
  c10_umb_x = c10_tmb_x;
  c10_umb_x = muDoubleScalarSin(c10_umb_x);
  c10_vmb_x = c10_theta_1;
  c10_wmb_x = c10_vmb_x;
  c10_wmb_x = muDoubleScalarCos(c10_wmb_x);
  c10_xmb_x = c10_theta_2;
  c10_ymb_x = c10_xmb_x;
  c10_ymb_x = muDoubleScalarSin(c10_ymb_x);
  c10_cl_a = c10_wmb_x;
  c10_pn_b = c10_ymb_x;
  c10_dq_y = c10_cl_a * c10_pn_b;
  c10_anb_x = c10_theta_3;
  c10_bnb_x = c10_anb_x;
  c10_bnb_x = muDoubleScalarSin(c10_bnb_x);
  c10_dl_a = c10_dq_y;
  c10_qn_b = c10_bnb_x;
  c10_eq_y = c10_dl_a * c10_qn_b;
  c10_cnb_x = c10_theta_1;
  c10_dnb_x = c10_cnb_x;
  c10_dnb_x = muDoubleScalarCos(c10_dnb_x);
  c10_enb_x = c10_theta_2;
  c10_fnb_x = c10_enb_x;
  c10_fnb_x = muDoubleScalarCos(c10_fnb_x);
  c10_el_a = c10_dnb_x;
  c10_rn_b = c10_fnb_x;
  c10_fq_y = c10_el_a * c10_rn_b;
  c10_gnb_x = c10_theta_3;
  c10_hnb_x = c10_gnb_x;
  c10_hnb_x = muDoubleScalarCos(c10_hnb_x);
  c10_fl_a = c10_fq_y;
  c10_sn_b = c10_hnb_x;
  c10_gq_y = c10_fl_a * c10_sn_b;
  c10_gl_a = c10_umb_x;
  c10_tn_b = c10_eq_y - c10_gq_y;
  c10_hq_y = c10_gl_a * c10_tn_b;
  c10_inb_x = c10_theta_5;
  c10_jnb_x = c10_inb_x;
  c10_jnb_x = muDoubleScalarCos(c10_jnb_x);
  c10_knb_x = c10_theta_1;
  c10_lnb_x = c10_knb_x;
  c10_lnb_x = muDoubleScalarSin(c10_lnb_x);
  c10_hl_a = c10_jnb_x;
  c10_un_b = c10_lnb_x;
  c10_iq_y = c10_hl_a * c10_un_b;
  c10_mnb_x = c10_theta_5;
  c10_nnb_x = c10_mnb_x;
  c10_nnb_x = muDoubleScalarSin(c10_nnb_x);
  c10_onb_x = c10_theta_4;
  c10_pnb_x = c10_onb_x;
  c10_pnb_x = muDoubleScalarCos(c10_pnb_x);
  c10_qnb_x = c10_theta_1;
  c10_rnb_x = c10_qnb_x;
  c10_rnb_x = muDoubleScalarCos(c10_rnb_x);
  c10_snb_x = c10_theta_2;
  c10_tnb_x = c10_snb_x;
  c10_tnb_x = muDoubleScalarSin(c10_tnb_x);
  c10_il_a = c10_rnb_x;
  c10_vn_b = c10_tnb_x;
  c10_jq_y = c10_il_a * c10_vn_b;
  c10_unb_x = c10_theta_3;
  c10_vnb_x = c10_unb_x;
  c10_vnb_x = muDoubleScalarSin(c10_vnb_x);
  c10_jl_a = c10_jq_y;
  c10_wn_b = c10_vnb_x;
  c10_kq_y = c10_jl_a * c10_wn_b;
  c10_wnb_x = c10_theta_1;
  c10_xnb_x = c10_wnb_x;
  c10_xnb_x = muDoubleScalarCos(c10_xnb_x);
  c10_ynb_x = c10_theta_2;
  c10_aob_x = c10_ynb_x;
  c10_aob_x = muDoubleScalarCos(c10_aob_x);
  c10_kl_a = c10_xnb_x;
  c10_xn_b = c10_aob_x;
  c10_lq_y = c10_kl_a * c10_xn_b;
  c10_bob_x = c10_theta_3;
  c10_cob_x = c10_bob_x;
  c10_cob_x = muDoubleScalarCos(c10_cob_x);
  c10_ll_a = c10_lq_y;
  c10_yn_b = c10_cob_x;
  c10_mq_y = c10_ll_a * c10_yn_b;
  c10_ml_a = c10_pnb_x;
  c10_ao_b = c10_kq_y - c10_mq_y;
  c10_nq_y = c10_ml_a * c10_ao_b;
  c10_dob_x = c10_theta_4;
  c10_eob_x = c10_dob_x;
  c10_eob_x = muDoubleScalarSin(c10_eob_x);
  c10_fob_x = c10_theta_1;
  c10_gob_x = c10_fob_x;
  c10_gob_x = muDoubleScalarCos(c10_gob_x);
  c10_hob_x = c10_theta_2;
  c10_iob_x = c10_hob_x;
  c10_iob_x = muDoubleScalarCos(c10_iob_x);
  c10_nl_a = c10_gob_x;
  c10_bo_b = c10_iob_x;
  c10_oq_y = c10_nl_a * c10_bo_b;
  c10_job_x = c10_theta_3;
  c10_kob_x = c10_job_x;
  c10_kob_x = muDoubleScalarSin(c10_kob_x);
  c10_ol_a = c10_oq_y;
  c10_co_b = c10_kob_x;
  c10_pq_y = c10_ol_a * c10_co_b;
  c10_lob_x = c10_theta_1;
  c10_mob_x = c10_lob_x;
  c10_mob_x = muDoubleScalarCos(c10_mob_x);
  c10_nob_x = c10_theta_3;
  c10_oob_x = c10_nob_x;
  c10_oob_x = muDoubleScalarCos(c10_oob_x);
  c10_pl_a = c10_mob_x;
  c10_do_b = c10_oob_x;
  c10_qq_y = c10_pl_a * c10_do_b;
  c10_pob_x = c10_theta_2;
  c10_qob_x = c10_pob_x;
  c10_qob_x = muDoubleScalarSin(c10_qob_x);
  c10_ql_a = c10_qq_y;
  c10_eo_b = c10_qob_x;
  c10_rq_y = c10_ql_a * c10_eo_b;
  c10_rl_a = c10_eob_x;
  c10_fo_b = c10_pq_y + c10_rq_y;
  c10_sq_y = c10_rl_a * c10_fo_b;
  c10_sl_a = c10_nnb_x;
  c10_go_b = c10_nq_y + c10_sq_y;
  c10_tq_y = c10_sl_a * c10_go_b;
  c10_rob_x = c10_theta_1;
  c10_sob_x = c10_rob_x;
  c10_sob_x = muDoubleScalarCos(c10_sob_x);
  c10_tob_x = c10_theta_1;
  c10_uob_x = c10_tob_x;
  c10_uob_x = muDoubleScalarCos(c10_uob_x);
  c10_vob_x = c10_theta_1;
  c10_wob_x = c10_vob_x;
  c10_wob_x = muDoubleScalarCos(c10_wob_x);
  c10_xob_x = c10_theta_4;
  c10_yob_x = c10_xob_x;
  c10_yob_x = muDoubleScalarCos(c10_yob_x);
  c10_apb_x = c10_theta_2;
  c10_bpb_x = c10_apb_x;
  c10_bpb_x = muDoubleScalarCos(c10_bpb_x);
  c10_cpb_x = c10_theta_1;
  c10_dpb_x = c10_cpb_x;
  c10_dpb_x = muDoubleScalarSin(c10_dpb_x);
  c10_tl_a = c10_bpb_x;
  c10_ho_b = c10_dpb_x;
  c10_uq_y = c10_tl_a * c10_ho_b;
  c10_epb_x = c10_theta_3;
  c10_fpb_x = c10_epb_x;
  c10_fpb_x = muDoubleScalarSin(c10_fpb_x);
  c10_ul_a = c10_uq_y;
  c10_io_b = c10_fpb_x;
  c10_vq_y = c10_ul_a * c10_io_b;
  c10_gpb_x = c10_theta_3;
  c10_hpb_x = c10_gpb_x;
  c10_hpb_x = muDoubleScalarCos(c10_hpb_x);
  c10_ipb_x = c10_theta_1;
  c10_jpb_x = c10_ipb_x;
  c10_jpb_x = muDoubleScalarSin(c10_jpb_x);
  c10_vl_a = c10_hpb_x;
  c10_jo_b = c10_jpb_x;
  c10_wq_y = c10_vl_a * c10_jo_b;
  c10_kpb_x = c10_theta_2;
  c10_lpb_x = c10_kpb_x;
  c10_lpb_x = muDoubleScalarSin(c10_lpb_x);
  c10_wl_a = c10_wq_y;
  c10_ko_b = c10_lpb_x;
  c10_xq_y = c10_wl_a * c10_ko_b;
  c10_xl_a = c10_yob_x;
  c10_lo_b = c10_vq_y + c10_xq_y;
  c10_yq_y = c10_xl_a * c10_lo_b;
  c10_mpb_x = c10_theta_4;
  c10_npb_x = c10_mpb_x;
  c10_npb_x = muDoubleScalarSin(c10_npb_x);
  c10_opb_x = c10_theta_1;
  c10_ppb_x = c10_opb_x;
  c10_ppb_x = muDoubleScalarSin(c10_ppb_x);
  c10_qpb_x = c10_theta_2;
  c10_rpb_x = c10_qpb_x;
  c10_rpb_x = muDoubleScalarSin(c10_rpb_x);
  c10_yl_a = c10_ppb_x;
  c10_mo_b = c10_rpb_x;
  c10_ar_y = c10_yl_a * c10_mo_b;
  c10_spb_x = c10_theta_3;
  c10_tpb_x = c10_spb_x;
  c10_tpb_x = muDoubleScalarSin(c10_tpb_x);
  c10_am_a = c10_ar_y;
  c10_no_b = c10_tpb_x;
  c10_br_y = c10_am_a * c10_no_b;
  c10_upb_x = c10_theta_2;
  c10_vpb_x = c10_upb_x;
  c10_vpb_x = muDoubleScalarCos(c10_vpb_x);
  c10_wpb_x = c10_theta_3;
  c10_xpb_x = c10_wpb_x;
  c10_xpb_x = muDoubleScalarCos(c10_xpb_x);
  c10_bm_a = c10_vpb_x;
  c10_oo_b = c10_xpb_x;
  c10_cr_y = c10_bm_a * c10_oo_b;
  c10_ypb_x = c10_theta_1;
  c10_aqb_x = c10_ypb_x;
  c10_aqb_x = muDoubleScalarSin(c10_aqb_x);
  c10_cm_a = c10_cr_y;
  c10_po_b = c10_aqb_x;
  c10_dr_y = c10_cm_a * c10_po_b;
  c10_dm_a = c10_npb_x;
  c10_qo_b = c10_br_y - c10_dr_y;
  c10_er_y = c10_dm_a * c10_qo_b;
  c10_bqb_x = c10_theta_5;
  c10_cqb_x = c10_bqb_x;
  c10_cqb_x = muDoubleScalarSin(c10_cqb_x);
  c10_dqb_x = c10_theta_4;
  c10_eqb_x = c10_dqb_x;
  c10_eqb_x = muDoubleScalarCos(c10_eqb_x);
  c10_fqb_x = c10_theta_1;
  c10_gqb_x = c10_fqb_x;
  c10_gqb_x = muDoubleScalarSin(c10_gqb_x);
  c10_hqb_x = c10_theta_2;
  c10_iqb_x = c10_hqb_x;
  c10_iqb_x = muDoubleScalarSin(c10_iqb_x);
  c10_em_a = c10_gqb_x;
  c10_ro_b = c10_iqb_x;
  c10_fr_y = c10_em_a * c10_ro_b;
  c10_jqb_x = c10_theta_3;
  c10_kqb_x = c10_jqb_x;
  c10_kqb_x = muDoubleScalarSin(c10_kqb_x);
  c10_fm_a = c10_fr_y;
  c10_so_b = c10_kqb_x;
  c10_gr_y = c10_fm_a * c10_so_b;
  c10_lqb_x = c10_theta_2;
  c10_mqb_x = c10_lqb_x;
  c10_mqb_x = muDoubleScalarCos(c10_mqb_x);
  c10_nqb_x = c10_theta_3;
  c10_oqb_x = c10_nqb_x;
  c10_oqb_x = muDoubleScalarCos(c10_oqb_x);
  c10_gm_a = c10_mqb_x;
  c10_to_b = c10_oqb_x;
  c10_hr_y = c10_gm_a * c10_to_b;
  c10_pqb_x = c10_theta_1;
  c10_qqb_x = c10_pqb_x;
  c10_qqb_x = muDoubleScalarSin(c10_qqb_x);
  c10_hm_a = c10_hr_y;
  c10_uo_b = c10_qqb_x;
  c10_ir_y = c10_hm_a * c10_uo_b;
  c10_im_a = c10_eqb_x;
  c10_vo_b = c10_gr_y - c10_ir_y;
  c10_jr_y = c10_im_a * c10_vo_b;
  c10_rqb_x = c10_theta_4;
  c10_sqb_x = c10_rqb_x;
  c10_sqb_x = muDoubleScalarSin(c10_sqb_x);
  c10_tqb_x = c10_theta_2;
  c10_uqb_x = c10_tqb_x;
  c10_uqb_x = muDoubleScalarCos(c10_uqb_x);
  c10_vqb_x = c10_theta_1;
  c10_wqb_x = c10_vqb_x;
  c10_wqb_x = muDoubleScalarSin(c10_wqb_x);
  c10_jm_a = c10_uqb_x;
  c10_wo_b = c10_wqb_x;
  c10_kr_y = c10_jm_a * c10_wo_b;
  c10_xqb_x = c10_theta_3;
  c10_yqb_x = c10_xqb_x;
  c10_yqb_x = muDoubleScalarSin(c10_yqb_x);
  c10_km_a = c10_kr_y;
  c10_xo_b = c10_yqb_x;
  c10_lr_y = c10_km_a * c10_xo_b;
  c10_arb_x = c10_theta_3;
  c10_brb_x = c10_arb_x;
  c10_brb_x = muDoubleScalarCos(c10_brb_x);
  c10_crb_x = c10_theta_1;
  c10_drb_x = c10_crb_x;
  c10_drb_x = muDoubleScalarSin(c10_drb_x);
  c10_lm_a = c10_brb_x;
  c10_yo_b = c10_drb_x;
  c10_mr_y = c10_lm_a * c10_yo_b;
  c10_erb_x = c10_theta_2;
  c10_frb_x = c10_erb_x;
  c10_frb_x = muDoubleScalarSin(c10_frb_x);
  c10_mm_a = c10_mr_y;
  c10_ap_b = c10_frb_x;
  c10_nr_y = c10_mm_a * c10_ap_b;
  c10_nm_a = c10_sqb_x;
  c10_bp_b = c10_lr_y + c10_nr_y;
  c10_or_y = c10_nm_a * c10_bp_b;
  c10_om_a = c10_cqb_x;
  c10_cp_b = c10_jr_y + c10_or_y;
  c10_pr_y = c10_om_a * c10_cp_b;
  c10_grb_x = c10_theta_1;
  c10_hrb_x = c10_grb_x;
  c10_hrb_x = muDoubleScalarCos(c10_hrb_x);
  c10_irb_x = c10_theta_5;
  c10_jrb_x = c10_irb_x;
  c10_jrb_x = muDoubleScalarCos(c10_jrb_x);
  c10_pm_a = c10_hrb_x;
  c10_dp_b = c10_jrb_x;
  c10_qr_y = c10_pm_a * c10_dp_b;
  c10_krb_x = c10_theta_4;
  c10_lrb_x = c10_krb_x;
  c10_lrb_x = muDoubleScalarSin(c10_lrb_x);
  c10_mrb_x = c10_theta_2;
  c10_nrb_x = c10_mrb_x;
  c10_nrb_x = muDoubleScalarCos(c10_nrb_x);
  c10_orb_x = c10_theta_3;
  c10_prb_x = c10_orb_x;
  c10_prb_x = muDoubleScalarSin(c10_prb_x);
  c10_qm_a = c10_nrb_x;
  c10_ep_b = c10_prb_x;
  c10_rr_y = c10_qm_a * c10_ep_b;
  c10_qrb_x = c10_theta_3;
  c10_rrb_x = c10_qrb_x;
  c10_rrb_x = muDoubleScalarCos(c10_rrb_x);
  c10_srb_x = c10_theta_2;
  c10_trb_x = c10_srb_x;
  c10_trb_x = muDoubleScalarSin(c10_trb_x);
  c10_rm_a = c10_rrb_x;
  c10_fp_b = c10_trb_x;
  c10_sr_y = c10_rm_a * c10_fp_b;
  c10_sm_a = c10_lrb_x;
  c10_gp_b = c10_rr_y + c10_sr_y;
  c10_tr_y = c10_sm_a * c10_gp_b;
  c10_urb_x = c10_theta_4;
  c10_vrb_x = c10_urb_x;
  c10_vrb_x = muDoubleScalarCos(c10_vrb_x);
  c10_wrb_x = c10_theta_2;
  c10_xrb_x = c10_wrb_x;
  c10_xrb_x = muDoubleScalarCos(c10_xrb_x);
  c10_yrb_x = c10_theta_3;
  c10_asb_x = c10_yrb_x;
  c10_asb_x = muDoubleScalarCos(c10_asb_x);
  c10_tm_a = c10_xrb_x;
  c10_hp_b = c10_asb_x;
  c10_ur_y = c10_tm_a * c10_hp_b;
  c10_bsb_x = c10_theta_2;
  c10_csb_x = c10_bsb_x;
  c10_csb_x = muDoubleScalarSin(c10_csb_x);
  c10_dsb_x = c10_theta_3;
  c10_esb_x = c10_dsb_x;
  c10_esb_x = muDoubleScalarSin(c10_esb_x);
  c10_um_a = c10_csb_x;
  c10_ip_b = c10_esb_x;
  c10_vr_y = c10_um_a * c10_ip_b;
  c10_vm_a = c10_vrb_x;
  c10_jp_b = c10_ur_y - c10_vr_y;
  c10_wr_y = c10_vm_a * c10_jp_b;
  c10_fsb_x = c10_theta_5;
  c10_gsb_x = c10_fsb_x;
  c10_gsb_x = muDoubleScalarSin(c10_gsb_x);
  c10_hsb_x = c10_theta_4;
  c10_isb_x = c10_hsb_x;
  c10_isb_x = muDoubleScalarCos(c10_isb_x);
  c10_jsb_x = c10_theta_2;
  c10_ksb_x = c10_jsb_x;
  c10_ksb_x = muDoubleScalarCos(c10_ksb_x);
  c10_lsb_x = c10_theta_3;
  c10_msb_x = c10_lsb_x;
  c10_msb_x = muDoubleScalarSin(c10_msb_x);
  c10_wm_a = c10_ksb_x;
  c10_kp_b = c10_msb_x;
  c10_xr_y = c10_wm_a * c10_kp_b;
  c10_nsb_x = c10_theta_3;
  c10_osb_x = c10_nsb_x;
  c10_osb_x = muDoubleScalarCos(c10_osb_x);
  c10_psb_x = c10_theta_2;
  c10_qsb_x = c10_psb_x;
  c10_qsb_x = muDoubleScalarSin(c10_qsb_x);
  c10_xm_a = c10_osb_x;
  c10_lp_b = c10_qsb_x;
  c10_yr_y = c10_xm_a * c10_lp_b;
  c10_ym_a = c10_isb_x;
  c10_mp_b = c10_xr_y + c10_yr_y;
  c10_as_y = c10_ym_a * c10_mp_b;
  c10_rsb_x = c10_theta_4;
  c10_ssb_x = c10_rsb_x;
  c10_ssb_x = muDoubleScalarSin(c10_ssb_x);
  c10_tsb_x = c10_theta_2;
  c10_usb_x = c10_tsb_x;
  c10_usb_x = muDoubleScalarCos(c10_usb_x);
  c10_vsb_x = c10_theta_3;
  c10_wsb_x = c10_vsb_x;
  c10_wsb_x = muDoubleScalarCos(c10_wsb_x);
  c10_an_a = c10_usb_x;
  c10_np_b = c10_wsb_x;
  c10_bs_y = c10_an_a * c10_np_b;
  c10_xsb_x = c10_theta_2;
  c10_ysb_x = c10_xsb_x;
  c10_ysb_x = muDoubleScalarSin(c10_ysb_x);
  c10_atb_x = c10_theta_3;
  c10_btb_x = c10_atb_x;
  c10_btb_x = muDoubleScalarSin(c10_btb_x);
  c10_bn_a = c10_ysb_x;
  c10_op_b = c10_btb_x;
  c10_cs_y = c10_bn_a * c10_op_b;
  c10_cn_a = c10_ssb_x;
  c10_pp_b = c10_bs_y - c10_cs_y;
  c10_ds_y = c10_cn_a * c10_pp_b;
  c10_dn_a = -c10_gsb_x;
  c10_qp_b = c10_as_y + c10_ds_y;
  c10_es_y = c10_dn_a * c10_qp_b;
  c10_J[0] = ((((((c10_b_y + c10_e_y) + c10_h_y) - c10_o_y) + c10_v_y) -
               c10_jb_y) - c10_nb_y) + c10_rb_y;
  c10_J[6] = ((((c10_ub_y - c10_cc_y) - c10_jc_y) + c10_wc_y) + c10_bd_y) +
    c10_fd_y;
  c10_J[12] = (((c10_sd_y - c10_ae_y) - c10_he_y) + c10_le_y) + c10_pe_y;
  c10_J[18] = (c10_df_y - c10_kf_y) - c10_rf_y;
  c10_J[24] = c10_fg_y - c10_ig_y;
  c10_J[30] = 0.0;
  c10_J[1] = ((((((c10_kg_y - c10_ng_y) + c10_qg_y) + c10_xg_y) - c10_fh_y) +
               c10_sh_y) + c10_wh_y) - c10_bi_y;
  c10_J[7] = ((((c10_ei_y - c10_li_y) - c10_si_y) + c10_gj_y) + c10_kj_y) +
    c10_oj_y;
  c10_J[13] = (((c10_ck_y - c10_jk_y) - c10_qk_y) + c10_uk_y) + c10_yk_y;
  c10_J[19] = (c10_ml_y - c10_tl_y) - c10_bm_y;
  c10_J[25] = c10_em_y + c10_rm_y;
  c10_J[31] = 0.0;
  c10_J[2] = 0.0;
  c10_J[8] = ((((c10_um_y - c10_xm_y) - c10_an_y) - c10_jn_y) + c10_on_y) +
    c10_tn_y;
  c10_J[14] = (((c10_wn_y - c10_ao_y) - c10_jo_y) + c10_oo_y) + c10_to_y;
  c10_J[20] = (c10_yo_y - c10_ip_y) + c10_np_y;
  c10_J[26] = c10_wp_y;
  c10_J[32] = 0.0;
  c10_J[3] = 0.0;
  c10_J[9] = c10_amb_x;
  c10_J[15] = c10_cmb_x;
  c10_J[21] = c10_emb_x;
  c10_J[27] = c10_cq_y - c10_hq_y;
  c10_J[33] = c10_iq_y + c10_tq_y;
  c10_J[4] = 0.0;
  c10_J[10] = -c10_sob_x;
  c10_J[16] = -c10_uob_x;
  c10_J[22] = -c10_wob_x;
  c10_J[28] = c10_yq_y - c10_er_y;
  c10_J[34] = c10_pr_y - c10_qr_y;
  c10_J[5] = 1.0;
  c10_J[11] = 0.0;
  c10_J[17] = 0.0;
  c10_J[23] = 0.0;
  c10_J[29] = c10_tr_y - c10_wr_y;
  c10_J[35] = c10_es_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 198U);
  c10_i11 = 0;
  for (c10_i12 = 0; c10_i12 < 3; c10_i12++) {
    for (c10_i13 = 0; c10_i13 < 6; c10_i13++) {
      c10_J1[c10_i13 + c10_i11] = c10_J[c10_i13 + c10_i11];
    }

    c10_i11 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 199U);
  c10_i14 = 0;
  for (c10_i15 = 0; c10_i15 < 3; c10_i15++) {
    for (c10_i16 = 0; c10_i16 < 6; c10_i16++) {
      c10_J2[c10_i16 + c10_i14] = c10_J[(c10_i16 + c10_i14) + 18];
    }

    c10_i14 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -199);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i17 = 0; c10_i17 < 36; c10_i17++) {
    (*c10_b_J)[c10_i17] = c10_J[c10_i17];
  }

  for (c10_i18 = 0; c10_i18 < 18; c10_i18++) {
    (*c10_b_J1)[c10_i18] = c10_J1[c10_i18];
  }

  for (c10_i19 = 0; c10_i19 < 18; c10_i19++) {
    (*c10_b_J2)[c10_i19] = c10_J2[c10_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
}

static void initSimStructsc10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
}

static void registerMessagesc10_JointSpaceControl_own_MCP
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i20;
  int32_T c10_i21;
  int32_T c10_i22;
  real_T c10_b_inData[18];
  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  real_T c10_u[18];
  const mxArray *c10_y = NULL;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i20 = 0;
  for (c10_i21 = 0; c10_i21 < 3; c10_i21++) {
    for (c10_i22 = 0; c10_i22 < 6; c10_i22++) {
      c10_b_inData[c10_i22 + c10_i20] = (*(real_T (*)[18])c10_inData)[c10_i22 +
        c10_i20];
    }

    c10_i20 += 6;
  }

  c10_i23 = 0;
  for (c10_i24 = 0; c10_i24 < 3; c10_i24++) {
    for (c10_i25 = 0; c10_i25 < 6; c10_i25++) {
      c10_u[c10_i25 + c10_i23] = c10_b_inData[c10_i25 + c10_i23];
    }

    c10_i23 += 6;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 6, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_J2, const char_T *c10_identifier, real_T
  c10_y[18])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_J2), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_J2);
}

static void c10_b_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[18])
{
  real_T c10_dv3[18];
  int32_T c10_i26;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv3, 1, 0, 0U, 1, 0U, 2, 6,
                3);
  for (c10_i26 = 0; c10_i26 < 18; c10_i26++) {
    c10_y[c10_i26] = c10_dv3[c10_i26];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_J2;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[18];
  int32_T c10_i27;
  int32_T c10_i28;
  int32_T c10_i29;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_J2 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_J2), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_J2);
  c10_i27 = 0;
  for (c10_i28 = 0; c10_i28 < 3; c10_i28++) {
    for (c10_i29 = 0; c10_i29 < 6; c10_i29++) {
      (*(real_T (*)[18])c10_outData)[c10_i29 + c10_i27] = c10_y[c10_i29 +
        c10_i27];
    }

    c10_i27 += 6;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i30;
  int32_T c10_i31;
  int32_T c10_i32;
  real_T c10_b_inData[36];
  int32_T c10_i33;
  int32_T c10_i34;
  int32_T c10_i35;
  real_T c10_u[36];
  const mxArray *c10_y = NULL;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i30 = 0;
  for (c10_i31 = 0; c10_i31 < 6; c10_i31++) {
    for (c10_i32 = 0; c10_i32 < 6; c10_i32++) {
      c10_b_inData[c10_i32 + c10_i30] = (*(real_T (*)[36])c10_inData)[c10_i32 +
        c10_i30];
    }

    c10_i30 += 6;
  }

  c10_i33 = 0;
  for (c10_i34 = 0; c10_i34 < 6; c10_i34++) {
    for (c10_i35 = 0; c10_i35 < 6; c10_i35++) {
      c10_u[c10_i35 + c10_i33] = c10_b_inData[c10_i35 + c10_i33];
    }

    c10_i33 += 6;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_c_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_J, const char_T *c10_identifier, real_T
  c10_y[36])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_J), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_J);
}

static void c10_d_emlrt_marshallIn(SFc10_JointSpaceControl_own_MCPInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[36])
{
  real_T c10_dv4[36];
  int32_T c10_i36;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv4, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c10_i36 = 0; c10_i36 < 36; c10_i36++) {
    c10_y[c10_i36] = c10_dv4[c10_i36];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_J;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[36];
  int32_T c10_i37;
  int32_T c10_i38;
  int32_T c10_i39;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_J = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_J), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_J);
  c10_i37 = 0;
  for (c10_i38 = 0; c10_i38 < 6; c10_i38++) {
    for (c10_i39 = 0; c10_i39 < 6; c10_i39++) {
      (*(real_T (*)[36])c10_outData)[c10_i39 + c10_i37] = c10_y[c10_i39 +
        c10_i37];
    }

    c10_i37 += 6;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i40;
  real_T c10_b_inData[6];
  int32_T c10_i41;
  real_T c10_u[6];
  const mxArray *c10_y = NULL;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i40 = 0; c10_i40 < 6; c10_i40++) {
    c10_b_inData[c10_i40] = (*(real_T (*)[6])c10_inData)[c10_i40];
  }

  for (c10_i41 = 0; c10_i41 < 6; c10_i41++) {
    c10_u[c10_i41] = c10_b_inData[c10_i41];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_e_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_JointSpaceControl_own_MCP_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[9];
  c10_ResolvedFunctionInfo (*c10_b_info)[9];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i42;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_b_info = (c10_ResolvedFunctionInfo (*)[9])c10_info;
  (*c10_b_info)[0].context = "";
  (*c10_b_info)[0].name = "cos";
  (*c10_b_info)[0].dominantType = "double";
  (*c10_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c10_b_info)[0].fileTimeLo = 1343851972U;
  (*c10_b_info)[0].fileTimeHi = 0U;
  (*c10_b_info)[0].mFileTimeLo = 0U;
  (*c10_b_info)[0].mFileTimeHi = 0U;
  (*c10_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c10_b_info)[1].name = "eml_scalar_cos";
  (*c10_b_info)[1].dominantType = "double";
  (*c10_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c10_b_info)[1].fileTimeLo = 1286840322U;
  (*c10_b_info)[1].fileTimeHi = 0U;
  (*c10_b_info)[1].mFileTimeLo = 0U;
  (*c10_b_info)[1].mFileTimeHi = 0U;
  (*c10_b_info)[2].context = "";
  (*c10_b_info)[2].name = "mtimes";
  (*c10_b_info)[2].dominantType = "double";
  (*c10_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[2].fileTimeLo = 1289541292U;
  (*c10_b_info)[2].fileTimeHi = 0U;
  (*c10_b_info)[2].mFileTimeLo = 0U;
  (*c10_b_info)[2].mFileTimeHi = 0U;
  (*c10_b_info)[3].context = "";
  (*c10_b_info)[3].name = "mrdivide";
  (*c10_b_info)[3].dominantType = "double";
  (*c10_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[3].fileTimeLo = 1357973148U;
  (*c10_b_info)[3].fileTimeHi = 0U;
  (*c10_b_info)[3].mFileTimeLo = 1319751566U;
  (*c10_b_info)[3].mFileTimeHi = 0U;
  (*c10_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[4].name = "rdivide";
  (*c10_b_info)[4].dominantType = "double";
  (*c10_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[4].fileTimeLo = 1346531988U;
  (*c10_b_info)[4].fileTimeHi = 0U;
  (*c10_b_info)[4].mFileTimeLo = 0U;
  (*c10_b_info)[4].mFileTimeHi = 0U;
  (*c10_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[5].name = "eml_scalexp_compatible";
  (*c10_b_info)[5].dominantType = "double";
  (*c10_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c10_b_info)[5].fileTimeLo = 1286840396U;
  (*c10_b_info)[5].fileTimeHi = 0U;
  (*c10_b_info)[5].mFileTimeLo = 0U;
  (*c10_b_info)[5].mFileTimeHi = 0U;
  (*c10_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[6].name = "eml_div";
  (*c10_b_info)[6].dominantType = "double";
  (*c10_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c10_b_info)[6].fileTimeLo = 1313369410U;
  (*c10_b_info)[6].fileTimeHi = 0U;
  (*c10_b_info)[6].mFileTimeLo = 0U;
  (*c10_b_info)[6].mFileTimeHi = 0U;
  (*c10_b_info)[7].context = "";
  (*c10_b_info)[7].name = "sin";
  (*c10_b_info)[7].dominantType = "double";
  (*c10_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c10_b_info)[7].fileTimeLo = 1343851986U;
  (*c10_b_info)[7].fileTimeHi = 0U;
  (*c10_b_info)[7].mFileTimeLo = 0U;
  (*c10_b_info)[7].mFileTimeHi = 0U;
  (*c10_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c10_b_info)[8].name = "eml_scalar_sin";
  (*c10_b_info)[8].dominantType = "double";
  (*c10_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c10_b_info)[8].fileTimeLo = 1286840336U;
  (*c10_b_info)[8].fileTimeHi = 0U;
  (*c10_b_info)[8].mFileTimeLo = 0U;
  (*c10_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c10_i42 = 0; c10_i42 < 9; c10_i42++) {
    c10_r0 = &c10_info[c10_i42];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo",
                    c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i42);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i42);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_f_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i43;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i43, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i43;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_g_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_b_is_active_c10_JointSpaceControl_own_MCP, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_JointSpaceControl_own_MCP), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_JointSpaceControl_own_MCP);
  return c10_y;
}

static uint8_T c10_h_emlrt_marshallIn
  (SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_JointSpaceControl_own_MCPInstanceStruct *
  chartInstance)
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

void sf_c10_JointSpaceControl_own_MCP_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4161801122U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(255163859U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(341685637U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2924249670U);
}

mxArray *sf_c10_JointSpaceControl_own_MCP_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3sn27IkPdn8XWlMAdcPMaD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[1] = (double)(3);
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
      pr[0] = (double)(6);
      pr[1] = (double)(3);
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

mxArray *sf_c10_JointSpaceControl_own_MCP_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c10_JointSpaceControl_own_MCP(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[6],T\"J\",},{M[1],M[7],T\"J1\",},{M[1],M[8],T\"J2\",},{M[8],M[0],T\"is_active_c10_JointSpaceControl_own_MCP\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_JointSpaceControl_own_MCP_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
    chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_own_MCPMachineNumber_,
           10,
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
            (_JointSpaceControl_own_MCPMachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_own_MCPMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_own_MCPMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"J");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q");
          _SFD_SET_DATA_PROPS(2,2,0,1,"J1");
          _SFD_SET_DATA_PROPS(3,2,0,1,"J2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,10069);
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
            1.0,0,0,(MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
            c10_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          real_T (*c10_J)[36];
          real_T (*c10_q)[6];
          real_T (*c10_J1)[18];
          real_T (*c10_J2)[18];
          c10_J2 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
          c10_J1 = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 2);
          c10_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c10_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c10_J);
          _SFD_SET_DATA_VALUE_PTR(1U, *c10_q);
          _SFD_SET_DATA_VALUE_PTR(2U, *c10_J1);
          _SFD_SET_DATA_VALUE_PTR(3U, *c10_J2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_own_MCPMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "FeGaVtpE6N0uwshQ5lBq0D";
}

static void sf_opaque_initialize_c10_JointSpaceControl_own_MCP(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_JointSpaceControl_own_MCPInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
  initialize_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_JointSpaceControl_own_MCP(void
  *chartInstanceVar)
{
  enable_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_JointSpaceControl_own_MCP(void
  *chartInstanceVar)
{
  disable_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_JointSpaceControl_own_MCP(void
  *chartInstanceVar)
{
  sf_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_JointSpaceControl_own_MCP
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_JointSpaceControl_own_MCP();/* state var info */
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

extern void sf_internal_set_sim_state_c10_JointSpaceControl_own_MCP(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_JointSpaceControl_own_MCP();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_JointSpaceControl_own_MCP
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c10_JointSpaceControl_own_MCP(S);
}

static void sf_opaque_set_sim_state_c10_JointSpaceControl_own_MCP(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c10_JointSpaceControl_own_MCP(S, st);
}

static void sf_opaque_terminate_c10_JointSpaceControl_own_MCP(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_JointSpaceControl_own_MCPInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_own_MCP_optimization_info();
    }

    finalize_c10_JointSpaceControl_own_MCP
      ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_JointSpaceControl_own_MCP
    ((SFc10_JointSpaceControl_own_MCPInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_JointSpaceControl_own_MCP(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_JointSpaceControl_own_MCP
      ((SFc10_JointSpaceControl_own_MCPInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_JointSpaceControl_own_MCP(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_own_MCP_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3330607589U));
  ssSetChecksum1(S,(1805533362U));
  ssSetChecksum2(S,(2273578477U));
  ssSetChecksum3(S,(305565251U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_JointSpaceControl_own_MCP(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_JointSpaceControl_own_MCP(SimStruct *S)
{
  SFc10_JointSpaceControl_own_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc10_JointSpaceControl_own_MCPInstanceStruct *)utMalloc
    (sizeof(SFc10_JointSpaceControl_own_MCPInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_JointSpaceControl_own_MCPInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_JointSpaceControl_own_MCP;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_JointSpaceControl_own_MCP;
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

void c10_JointSpaceControl_own_MCP_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_JointSpaceControl_own_MCP(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_JointSpaceControl_own_MCP(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_JointSpaceControl_own_MCP(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_JointSpaceControl_own_MCP_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
