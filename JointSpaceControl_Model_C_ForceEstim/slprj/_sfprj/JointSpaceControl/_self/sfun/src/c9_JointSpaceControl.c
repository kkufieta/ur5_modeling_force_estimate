/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_sfun.h"
#include "c9_JointSpaceControl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[12] = { "theta_1", "theta_2",
  "theta_3", "theta_4", "theta_5", "theta_6", "J", "nargin", "nargout", "q",
  "dq", "tcp_speed" };

/* Function Declarations */
static void initialize_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance);
static void initialize_params_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance);
static void enable_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance);
static void disable_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance);
static void set_sim_state_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance);
static void sf_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance);
static void c9_chartstep_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance);
static void initSimStructsc9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance);
static void registerMessagesc9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_tcp_speed, const char_T *c9_identifier,
  real_T c9_y[6]);
static void c9_b_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[36]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[17]);
static void c9_eml_scalar_eg(SFc9_JointSpaceControlInstanceStruct *chartInstance);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_e_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_f_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_JointSpaceControl, const
  char_T *c9_identifier);
static uint8_T c9_g_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_JointSpaceControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_JointSpaceControl = 0U;
}

static void initialize_params_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void enable_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[6];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_tcp_speed)[6];
  c9_tcp_speed = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  for (c9_i0 = 0; c9_i0 < 6; c9_i0++) {
    c9_u[c9_i0] = (*c9_tcp_speed)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_JointSpaceControl;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[6];
  int32_T c9_i1;
  real_T (*c9_tcp_speed)[6];
  c9_tcp_speed = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
                      "tcp_speed", c9_dv0);
  for (c9_i1 = 0; c9_i1 < 6; c9_i1++) {
    (*c9_tcp_speed)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_JointSpaceControl = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
     "is_active_c9_JointSpaceControl");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_JointSpaceControl(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance)
{
}

static void sf_c9_JointSpaceControl(SFc9_JointSpaceControlInstanceStruct
  *chartInstance)
{
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  real_T (*c9_dq)[6];
  real_T (*c9_q)[6];
  real_T (*c9_tcp_speed)[6];
  c9_dq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c9_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c9_tcp_speed = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 6; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*c9_tcp_speed)[c9_i2], 0U);
  }

  for (c9_i3 = 0; c9_i3 < 6; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*c9_q)[c9_i3], 1U);
  }

  for (c9_i4 = 0; c9_i4 < 6; c9_i4++) {
    _SFD_DATA_RANGE_CHECK((*c9_dq)[c9_i4], 2U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_JointSpaceControl(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
  int32_T c9_i5;
  real_T c9_q[6];
  int32_T c9_i6;
  real_T c9_dq[6];
  uint32_T c9_debug_family_var_map[12];
  real_T c9_theta_1;
  real_T c9_theta_2;
  real_T c9_theta_3;
  real_T c9_theta_4;
  real_T c9_theta_5;
  real_T c9_theta_6;
  real_T c9_J[36];
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  real_T c9_tcp_speed[6];
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_b;
  real_T c9_y;
  real_T c9_A;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_b_y;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_b_b;
  real_T c9_c_y;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_a;
  real_T c9_c_b;
  real_T c9_d_y;
  real_T c9_b_A;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_e_y;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_d_b;
  real_T c9_f_y;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_b_a;
  real_T c9_e_b;
  real_T c9_g_y;
  real_T c9_c_A;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_h_y;
  real_T c9_q_x;
  real_T c9_r_x;
  real_T c9_f_b;
  real_T c9_i_y;
  real_T c9_s_x;
  real_T c9_t_x;
  real_T c9_u_x;
  real_T c9_v_x;
  real_T c9_c_a;
  real_T c9_g_b;
  real_T c9_j_y;
  real_T c9_w_x;
  real_T c9_x_x;
  real_T c9_d_a;
  real_T c9_h_b;
  real_T c9_k_y;
  real_T c9_y_x;
  real_T c9_ab_x;
  real_T c9_bb_x;
  real_T c9_cb_x;
  real_T c9_e_a;
  real_T c9_i_b;
  real_T c9_l_y;
  real_T c9_db_x;
  real_T c9_eb_x;
  real_T c9_f_a;
  real_T c9_j_b;
  real_T c9_m_y;
  real_T c9_g_a;
  real_T c9_k_b;
  real_T c9_n_y;
  real_T c9_d_A;
  real_T c9_fb_x;
  real_T c9_gb_x;
  real_T c9_o_y;
  real_T c9_hb_x;
  real_T c9_ib_x;
  real_T c9_l_b;
  real_T c9_p_y;
  real_T c9_jb_x;
  real_T c9_kb_x;
  real_T c9_lb_x;
  real_T c9_mb_x;
  real_T c9_h_a;
  real_T c9_m_b;
  real_T c9_q_y;
  real_T c9_nb_x;
  real_T c9_ob_x;
  real_T c9_i_a;
  real_T c9_n_b;
  real_T c9_r_y;
  real_T c9_pb_x;
  real_T c9_qb_x;
  real_T c9_rb_x;
  real_T c9_sb_x;
  real_T c9_j_a;
  real_T c9_o_b;
  real_T c9_s_y;
  real_T c9_tb_x;
  real_T c9_ub_x;
  real_T c9_k_a;
  real_T c9_p_b;
  real_T c9_t_y;
  real_T c9_l_a;
  real_T c9_q_b;
  real_T c9_u_y;
  real_T c9_e_A;
  real_T c9_vb_x;
  real_T c9_wb_x;
  real_T c9_v_y;
  real_T c9_xb_x;
  real_T c9_yb_x;
  real_T c9_r_b;
  real_T c9_w_y;
  real_T c9_ac_x;
  real_T c9_bc_x;
  real_T c9_cc_x;
  real_T c9_dc_x;
  real_T c9_ec_x;
  real_T c9_fc_x;
  real_T c9_m_a;
  real_T c9_s_b;
  real_T c9_x_y;
  real_T c9_gc_x;
  real_T c9_hc_x;
  real_T c9_n_a;
  real_T c9_t_b;
  real_T c9_y_y;
  real_T c9_ic_x;
  real_T c9_jc_x;
  real_T c9_kc_x;
  real_T c9_lc_x;
  real_T c9_o_a;
  real_T c9_u_b;
  real_T c9_ab_y;
  real_T c9_mc_x;
  real_T c9_nc_x;
  real_T c9_p_a;
  real_T c9_v_b;
  real_T c9_bb_y;
  real_T c9_q_a;
  real_T c9_w_b;
  real_T c9_cb_y;
  real_T c9_oc_x;
  real_T c9_pc_x;
  real_T c9_qc_x;
  real_T c9_rc_x;
  real_T c9_sc_x;
  real_T c9_tc_x;
  real_T c9_r_a;
  real_T c9_x_b;
  real_T c9_db_y;
  real_T c9_uc_x;
  real_T c9_vc_x;
  real_T c9_s_a;
  real_T c9_y_b;
  real_T c9_eb_y;
  real_T c9_wc_x;
  real_T c9_xc_x;
  real_T c9_yc_x;
  real_T c9_ad_x;
  real_T c9_t_a;
  real_T c9_ab_b;
  real_T c9_fb_y;
  real_T c9_bd_x;
  real_T c9_cd_x;
  real_T c9_u_a;
  real_T c9_bb_b;
  real_T c9_gb_y;
  real_T c9_v_a;
  real_T c9_cb_b;
  real_T c9_hb_y;
  real_T c9_w_a;
  real_T c9_db_b;
  real_T c9_ib_y;
  real_T c9_f_A;
  real_T c9_dd_x;
  real_T c9_ed_x;
  real_T c9_jb_y;
  real_T c9_fd_x;
  real_T c9_gd_x;
  real_T c9_eb_b;
  real_T c9_kb_y;
  real_T c9_hd_x;
  real_T c9_id_x;
  real_T c9_x_a;
  real_T c9_fb_b;
  real_T c9_lb_y;
  real_T c9_jd_x;
  real_T c9_kd_x;
  real_T c9_y_a;
  real_T c9_gb_b;
  real_T c9_mb_y;
  real_T c9_g_A;
  real_T c9_ld_x;
  real_T c9_md_x;
  real_T c9_nb_y;
  real_T c9_nd_x;
  real_T c9_od_x;
  real_T c9_hb_b;
  real_T c9_ob_y;
  real_T c9_pd_x;
  real_T c9_qd_x;
  real_T c9_ab_a;
  real_T c9_ib_b;
  real_T c9_pb_y;
  real_T c9_rd_x;
  real_T c9_sd_x;
  real_T c9_bb_a;
  real_T c9_jb_b;
  real_T c9_qb_y;
  real_T c9_h_A;
  real_T c9_td_x;
  real_T c9_ud_x;
  real_T c9_rb_y;
  real_T c9_vd_x;
  real_T c9_wd_x;
  real_T c9_kb_b;
  real_T c9_sb_y;
  real_T c9_xd_x;
  real_T c9_yd_x;
  real_T c9_cb_a;
  real_T c9_lb_b;
  real_T c9_tb_y;
  real_T c9_i_A;
  real_T c9_ae_x;
  real_T c9_be_x;
  real_T c9_ub_y;
  real_T c9_ce_x;
  real_T c9_de_x;
  real_T c9_mb_b;
  real_T c9_vb_y;
  real_T c9_ee_x;
  real_T c9_fe_x;
  real_T c9_ge_x;
  real_T c9_he_x;
  real_T c9_db_a;
  real_T c9_nb_b;
  real_T c9_wb_y;
  real_T c9_ie_x;
  real_T c9_je_x;
  real_T c9_eb_a;
  real_T c9_ob_b;
  real_T c9_xb_y;
  real_T c9_ke_x;
  real_T c9_le_x;
  real_T c9_me_x;
  real_T c9_ne_x;
  real_T c9_fb_a;
  real_T c9_pb_b;
  real_T c9_yb_y;
  real_T c9_oe_x;
  real_T c9_pe_x;
  real_T c9_gb_a;
  real_T c9_qb_b;
  real_T c9_ac_y;
  real_T c9_hb_a;
  real_T c9_rb_b;
  real_T c9_bc_y;
  real_T c9_j_A;
  real_T c9_qe_x;
  real_T c9_re_x;
  real_T c9_cc_y;
  real_T c9_se_x;
  real_T c9_te_x;
  real_T c9_sb_b;
  real_T c9_dc_y;
  real_T c9_ue_x;
  real_T c9_ve_x;
  real_T c9_we_x;
  real_T c9_xe_x;
  real_T c9_ib_a;
  real_T c9_tb_b;
  real_T c9_ec_y;
  real_T c9_ye_x;
  real_T c9_af_x;
  real_T c9_jb_a;
  real_T c9_ub_b;
  real_T c9_fc_y;
  real_T c9_bf_x;
  real_T c9_cf_x;
  real_T c9_df_x;
  real_T c9_ef_x;
  real_T c9_kb_a;
  real_T c9_vb_b;
  real_T c9_gc_y;
  real_T c9_ff_x;
  real_T c9_gf_x;
  real_T c9_lb_a;
  real_T c9_wb_b;
  real_T c9_hc_y;
  real_T c9_mb_a;
  real_T c9_xb_b;
  real_T c9_ic_y;
  real_T c9_k_A;
  real_T c9_hf_x;
  real_T c9_if_x;
  real_T c9_jc_y;
  real_T c9_jf_x;
  real_T c9_kf_x;
  real_T c9_yb_b;
  real_T c9_kc_y;
  real_T c9_lf_x;
  real_T c9_mf_x;
  real_T c9_nf_x;
  real_T c9_of_x;
  real_T c9_pf_x;
  real_T c9_qf_x;
  real_T c9_nb_a;
  real_T c9_ac_b;
  real_T c9_lc_y;
  real_T c9_rf_x;
  real_T c9_sf_x;
  real_T c9_ob_a;
  real_T c9_bc_b;
  real_T c9_mc_y;
  real_T c9_tf_x;
  real_T c9_uf_x;
  real_T c9_vf_x;
  real_T c9_wf_x;
  real_T c9_pb_a;
  real_T c9_cc_b;
  real_T c9_nc_y;
  real_T c9_xf_x;
  real_T c9_yf_x;
  real_T c9_qb_a;
  real_T c9_dc_b;
  real_T c9_oc_y;
  real_T c9_rb_a;
  real_T c9_ec_b;
  real_T c9_pc_y;
  real_T c9_ag_x;
  real_T c9_bg_x;
  real_T c9_cg_x;
  real_T c9_dg_x;
  real_T c9_eg_x;
  real_T c9_fg_x;
  real_T c9_sb_a;
  real_T c9_fc_b;
  real_T c9_qc_y;
  real_T c9_gg_x;
  real_T c9_hg_x;
  real_T c9_tb_a;
  real_T c9_gc_b;
  real_T c9_rc_y;
  real_T c9_ig_x;
  real_T c9_jg_x;
  real_T c9_kg_x;
  real_T c9_lg_x;
  real_T c9_ub_a;
  real_T c9_hc_b;
  real_T c9_sc_y;
  real_T c9_mg_x;
  real_T c9_ng_x;
  real_T c9_vb_a;
  real_T c9_ic_b;
  real_T c9_tc_y;
  real_T c9_wb_a;
  real_T c9_jc_b;
  real_T c9_uc_y;
  real_T c9_xb_a;
  real_T c9_kc_b;
  real_T c9_vc_y;
  real_T c9_l_A;
  real_T c9_og_x;
  real_T c9_pg_x;
  real_T c9_wc_y;
  real_T c9_qg_x;
  real_T c9_rg_x;
  real_T c9_lc_b;
  real_T c9_xc_y;
  real_T c9_sg_x;
  real_T c9_tg_x;
  real_T c9_yb_a;
  real_T c9_mc_b;
  real_T c9_yc_y;
  real_T c9_ug_x;
  real_T c9_vg_x;
  real_T c9_ac_a;
  real_T c9_nc_b;
  real_T c9_ad_y;
  real_T c9_m_A;
  real_T c9_wg_x;
  real_T c9_xg_x;
  real_T c9_bd_y;
  real_T c9_yg_x;
  real_T c9_ah_x;
  real_T c9_oc_b;
  real_T c9_cd_y;
  real_T c9_bh_x;
  real_T c9_ch_x;
  real_T c9_bc_a;
  real_T c9_pc_b;
  real_T c9_dd_y;
  real_T c9_dh_x;
  real_T c9_eh_x;
  real_T c9_cc_a;
  real_T c9_qc_b;
  real_T c9_ed_y;
  real_T c9_n_A;
  real_T c9_fh_x;
  real_T c9_gh_x;
  real_T c9_fd_y;
  real_T c9_hh_x;
  real_T c9_ih_x;
  real_T c9_rc_b;
  real_T c9_gd_y;
  real_T c9_jh_x;
  real_T c9_kh_x;
  real_T c9_lh_x;
  real_T c9_mh_x;
  real_T c9_nh_x;
  real_T c9_oh_x;
  real_T c9_dc_a;
  real_T c9_sc_b;
  real_T c9_hd_y;
  real_T c9_ph_x;
  real_T c9_qh_x;
  real_T c9_ec_a;
  real_T c9_tc_b;
  real_T c9_id_y;
  real_T c9_rh_x;
  real_T c9_sh_x;
  real_T c9_th_x;
  real_T c9_uh_x;
  real_T c9_fc_a;
  real_T c9_uc_b;
  real_T c9_jd_y;
  real_T c9_vh_x;
  real_T c9_wh_x;
  real_T c9_gc_a;
  real_T c9_vc_b;
  real_T c9_kd_y;
  real_T c9_hc_a;
  real_T c9_wc_b;
  real_T c9_ld_y;
  real_T c9_xh_x;
  real_T c9_yh_x;
  real_T c9_ai_x;
  real_T c9_bi_x;
  real_T c9_ci_x;
  real_T c9_di_x;
  real_T c9_ic_a;
  real_T c9_xc_b;
  real_T c9_md_y;
  real_T c9_ei_x;
  real_T c9_fi_x;
  real_T c9_jc_a;
  real_T c9_yc_b;
  real_T c9_nd_y;
  real_T c9_gi_x;
  real_T c9_hi_x;
  real_T c9_ii_x;
  real_T c9_ji_x;
  real_T c9_kc_a;
  real_T c9_ad_b;
  real_T c9_od_y;
  real_T c9_ki_x;
  real_T c9_li_x;
  real_T c9_lc_a;
  real_T c9_bd_b;
  real_T c9_pd_y;
  real_T c9_mc_a;
  real_T c9_cd_b;
  real_T c9_qd_y;
  real_T c9_nc_a;
  real_T c9_dd_b;
  real_T c9_rd_y;
  real_T c9_o_A;
  real_T c9_mi_x;
  real_T c9_ni_x;
  real_T c9_sd_y;
  real_T c9_oi_x;
  real_T c9_pi_x;
  real_T c9_ed_b;
  real_T c9_td_y;
  real_T c9_qi_x;
  real_T c9_ri_x;
  real_T c9_si_x;
  real_T c9_ti_x;
  real_T c9_oc_a;
  real_T c9_fd_b;
  real_T c9_ud_y;
  real_T c9_ui_x;
  real_T c9_vi_x;
  real_T c9_pc_a;
  real_T c9_gd_b;
  real_T c9_vd_y;
  real_T c9_wi_x;
  real_T c9_xi_x;
  real_T c9_yi_x;
  real_T c9_aj_x;
  real_T c9_qc_a;
  real_T c9_hd_b;
  real_T c9_wd_y;
  real_T c9_bj_x;
  real_T c9_cj_x;
  real_T c9_rc_a;
  real_T c9_id_b;
  real_T c9_xd_y;
  real_T c9_sc_a;
  real_T c9_jd_b;
  real_T c9_yd_y;
  real_T c9_p_A;
  real_T c9_dj_x;
  real_T c9_ej_x;
  real_T c9_ae_y;
  real_T c9_fj_x;
  real_T c9_gj_x;
  real_T c9_kd_b;
  real_T c9_be_y;
  real_T c9_hj_x;
  real_T c9_ij_x;
  real_T c9_jj_x;
  real_T c9_kj_x;
  real_T c9_tc_a;
  real_T c9_ld_b;
  real_T c9_ce_y;
  real_T c9_lj_x;
  real_T c9_mj_x;
  real_T c9_uc_a;
  real_T c9_md_b;
  real_T c9_de_y;
  real_T c9_nj_x;
  real_T c9_oj_x;
  real_T c9_pj_x;
  real_T c9_qj_x;
  real_T c9_vc_a;
  real_T c9_nd_b;
  real_T c9_ee_y;
  real_T c9_rj_x;
  real_T c9_sj_x;
  real_T c9_wc_a;
  real_T c9_od_b;
  real_T c9_fe_y;
  real_T c9_xc_a;
  real_T c9_pd_b;
  real_T c9_ge_y;
  real_T c9_q_A;
  real_T c9_tj_x;
  real_T c9_uj_x;
  real_T c9_he_y;
  real_T c9_vj_x;
  real_T c9_wj_x;
  real_T c9_qd_b;
  real_T c9_ie_y;
  real_T c9_xj_x;
  real_T c9_yj_x;
  real_T c9_yc_a;
  real_T c9_rd_b;
  real_T c9_je_y;
  real_T c9_ak_x;
  real_T c9_bk_x;
  real_T c9_ad_a;
  real_T c9_sd_b;
  real_T c9_ke_y;
  real_T c9_r_A;
  real_T c9_ck_x;
  real_T c9_dk_x;
  real_T c9_le_y;
  real_T c9_ek_x;
  real_T c9_fk_x;
  real_T c9_td_b;
  real_T c9_me_y;
  real_T c9_gk_x;
  real_T c9_hk_x;
  real_T c9_bd_a;
  real_T c9_ud_b;
  real_T c9_ne_y;
  real_T c9_ik_x;
  real_T c9_jk_x;
  real_T c9_cd_a;
  real_T c9_vd_b;
  real_T c9_oe_y;
  real_T c9_s_A;
  real_T c9_kk_x;
  real_T c9_lk_x;
  real_T c9_pe_y;
  real_T c9_mk_x;
  real_T c9_nk_x;
  real_T c9_wd_b;
  real_T c9_qe_y;
  real_T c9_ok_x;
  real_T c9_pk_x;
  real_T c9_qk_x;
  real_T c9_rk_x;
  real_T c9_sk_x;
  real_T c9_tk_x;
  real_T c9_dd_a;
  real_T c9_xd_b;
  real_T c9_re_y;
  real_T c9_uk_x;
  real_T c9_vk_x;
  real_T c9_ed_a;
  real_T c9_yd_b;
  real_T c9_se_y;
  real_T c9_wk_x;
  real_T c9_xk_x;
  real_T c9_yk_x;
  real_T c9_al_x;
  real_T c9_fd_a;
  real_T c9_ae_b;
  real_T c9_te_y;
  real_T c9_bl_x;
  real_T c9_cl_x;
  real_T c9_gd_a;
  real_T c9_be_b;
  real_T c9_ue_y;
  real_T c9_hd_a;
  real_T c9_ce_b;
  real_T c9_ve_y;
  real_T c9_dl_x;
  real_T c9_el_x;
  real_T c9_fl_x;
  real_T c9_gl_x;
  real_T c9_hl_x;
  real_T c9_il_x;
  real_T c9_id_a;
  real_T c9_de_b;
  real_T c9_we_y;
  real_T c9_jl_x;
  real_T c9_kl_x;
  real_T c9_jd_a;
  real_T c9_ee_b;
  real_T c9_xe_y;
  real_T c9_ll_x;
  real_T c9_ml_x;
  real_T c9_nl_x;
  real_T c9_ol_x;
  real_T c9_kd_a;
  real_T c9_fe_b;
  real_T c9_ye_y;
  real_T c9_pl_x;
  real_T c9_ql_x;
  real_T c9_ld_a;
  real_T c9_ge_b;
  real_T c9_af_y;
  real_T c9_md_a;
  real_T c9_he_b;
  real_T c9_bf_y;
  real_T c9_nd_a;
  real_T c9_ie_b;
  real_T c9_cf_y;
  real_T c9_t_A;
  real_T c9_rl_x;
  real_T c9_sl_x;
  real_T c9_df_y;
  real_T c9_tl_x;
  real_T c9_ul_x;
  real_T c9_je_b;
  real_T c9_ef_y;
  real_T c9_vl_x;
  real_T c9_wl_x;
  real_T c9_xl_x;
  real_T c9_yl_x;
  real_T c9_od_a;
  real_T c9_ke_b;
  real_T c9_ff_y;
  real_T c9_am_x;
  real_T c9_bm_x;
  real_T c9_pd_a;
  real_T c9_le_b;
  real_T c9_gf_y;
  real_T c9_cm_x;
  real_T c9_dm_x;
  real_T c9_em_x;
  real_T c9_fm_x;
  real_T c9_qd_a;
  real_T c9_me_b;
  real_T c9_hf_y;
  real_T c9_gm_x;
  real_T c9_hm_x;
  real_T c9_rd_a;
  real_T c9_ne_b;
  real_T c9_if_y;
  real_T c9_sd_a;
  real_T c9_oe_b;
  real_T c9_jf_y;
  real_T c9_u_A;
  real_T c9_im_x;
  real_T c9_jm_x;
  real_T c9_kf_y;
  real_T c9_km_x;
  real_T c9_lm_x;
  real_T c9_pe_b;
  real_T c9_lf_y;
  real_T c9_mm_x;
  real_T c9_nm_x;
  real_T c9_om_x;
  real_T c9_pm_x;
  real_T c9_td_a;
  real_T c9_qe_b;
  real_T c9_mf_y;
  real_T c9_qm_x;
  real_T c9_rm_x;
  real_T c9_ud_a;
  real_T c9_re_b;
  real_T c9_nf_y;
  real_T c9_sm_x;
  real_T c9_tm_x;
  real_T c9_um_x;
  real_T c9_vm_x;
  real_T c9_vd_a;
  real_T c9_se_b;
  real_T c9_of_y;
  real_T c9_wm_x;
  real_T c9_xm_x;
  real_T c9_wd_a;
  real_T c9_te_b;
  real_T c9_pf_y;
  real_T c9_xd_a;
  real_T c9_ue_b;
  real_T c9_qf_y;
  real_T c9_v_A;
  real_T c9_ym_x;
  real_T c9_an_x;
  real_T c9_rf_y;
  real_T c9_bn_x;
  real_T c9_cn_x;
  real_T c9_ve_b;
  real_T c9_sf_y;
  real_T c9_dn_x;
  real_T c9_en_x;
  real_T c9_fn_x;
  real_T c9_gn_x;
  real_T c9_hn_x;
  real_T c9_in_x;
  real_T c9_yd_a;
  real_T c9_we_b;
  real_T c9_tf_y;
  real_T c9_jn_x;
  real_T c9_kn_x;
  real_T c9_ae_a;
  real_T c9_xe_b;
  real_T c9_uf_y;
  real_T c9_ln_x;
  real_T c9_mn_x;
  real_T c9_nn_x;
  real_T c9_on_x;
  real_T c9_be_a;
  real_T c9_ye_b;
  real_T c9_vf_y;
  real_T c9_pn_x;
  real_T c9_qn_x;
  real_T c9_ce_a;
  real_T c9_af_b;
  real_T c9_wf_y;
  real_T c9_de_a;
  real_T c9_bf_b;
  real_T c9_xf_y;
  real_T c9_rn_x;
  real_T c9_sn_x;
  real_T c9_tn_x;
  real_T c9_un_x;
  real_T c9_vn_x;
  real_T c9_wn_x;
  real_T c9_ee_a;
  real_T c9_cf_b;
  real_T c9_yf_y;
  real_T c9_xn_x;
  real_T c9_yn_x;
  real_T c9_fe_a;
  real_T c9_df_b;
  real_T c9_ag_y;
  real_T c9_ao_x;
  real_T c9_bo_x;
  real_T c9_co_x;
  real_T c9_do_x;
  real_T c9_ge_a;
  real_T c9_ef_b;
  real_T c9_bg_y;
  real_T c9_eo_x;
  real_T c9_fo_x;
  real_T c9_he_a;
  real_T c9_ff_b;
  real_T c9_cg_y;
  real_T c9_ie_a;
  real_T c9_gf_b;
  real_T c9_dg_y;
  real_T c9_je_a;
  real_T c9_hf_b;
  real_T c9_eg_y;
  real_T c9_w_A;
  real_T c9_go_x;
  real_T c9_ho_x;
  real_T c9_fg_y;
  real_T c9_io_x;
  real_T c9_jo_x;
  real_T c9_if_b;
  real_T c9_gg_y;
  real_T c9_ko_x;
  real_T c9_lo_x;
  real_T c9_ke_a;
  real_T c9_jf_b;
  real_T c9_hg_y;
  real_T c9_x_A;
  real_T c9_mo_x;
  real_T c9_no_x;
  real_T c9_ig_y;
  real_T c9_oo_x;
  real_T c9_po_x;
  real_T c9_kf_b;
  real_T c9_jg_y;
  real_T c9_y_A;
  real_T c9_qo_x;
  real_T c9_ro_x;
  real_T c9_kg_y;
  real_T c9_so_x;
  real_T c9_to_x;
  real_T c9_lf_b;
  real_T c9_lg_y;
  real_T c9_uo_x;
  real_T c9_vo_x;
  real_T c9_le_a;
  real_T c9_mf_b;
  real_T c9_mg_y;
  real_T c9_ab_A;
  real_T c9_wo_x;
  real_T c9_xo_x;
  real_T c9_ng_y;
  real_T c9_yo_x;
  real_T c9_ap_x;
  real_T c9_nf_b;
  real_T c9_og_y;
  real_T c9_bp_x;
  real_T c9_cp_x;
  real_T c9_me_a;
  real_T c9_of_b;
  real_T c9_pg_y;
  real_T c9_bb_A;
  real_T c9_dp_x;
  real_T c9_ep_x;
  real_T c9_qg_y;
  real_T c9_fp_x;
  real_T c9_gp_x;
  real_T c9_pf_b;
  real_T c9_rg_y;
  real_T c9_hp_x;
  real_T c9_ip_x;
  real_T c9_jp_x;
  real_T c9_kp_x;
  real_T c9_ne_a;
  real_T c9_qf_b;
  real_T c9_sg_y;
  real_T c9_lp_x;
  real_T c9_mp_x;
  real_T c9_oe_a;
  real_T c9_rf_b;
  real_T c9_tg_y;
  real_T c9_np_x;
  real_T c9_op_x;
  real_T c9_pp_x;
  real_T c9_qp_x;
  real_T c9_pe_a;
  real_T c9_sf_b;
  real_T c9_ug_y;
  real_T c9_rp_x;
  real_T c9_sp_x;
  real_T c9_qe_a;
  real_T c9_tf_b;
  real_T c9_vg_y;
  real_T c9_re_a;
  real_T c9_uf_b;
  real_T c9_wg_y;
  real_T c9_cb_A;
  real_T c9_tp_x;
  real_T c9_up_x;
  real_T c9_xg_y;
  real_T c9_vp_x;
  real_T c9_wp_x;
  real_T c9_vf_b;
  real_T c9_yg_y;
  real_T c9_xp_x;
  real_T c9_yp_x;
  real_T c9_aq_x;
  real_T c9_bq_x;
  real_T c9_se_a;
  real_T c9_wf_b;
  real_T c9_ah_y;
  real_T c9_cq_x;
  real_T c9_dq_x;
  real_T c9_te_a;
  real_T c9_xf_b;
  real_T c9_bh_y;
  real_T c9_eq_x;
  real_T c9_fq_x;
  real_T c9_gq_x;
  real_T c9_hq_x;
  real_T c9_ue_a;
  real_T c9_yf_b;
  real_T c9_ch_y;
  real_T c9_iq_x;
  real_T c9_jq_x;
  real_T c9_ve_a;
  real_T c9_ag_b;
  real_T c9_dh_y;
  real_T c9_we_a;
  real_T c9_bg_b;
  real_T c9_eh_y;
  real_T c9_db_A;
  real_T c9_kq_x;
  real_T c9_lq_x;
  real_T c9_fh_y;
  real_T c9_mq_x;
  real_T c9_nq_x;
  real_T c9_cg_b;
  real_T c9_gh_y;
  real_T c9_oq_x;
  real_T c9_pq_x;
  real_T c9_qq_x;
  real_T c9_rq_x;
  real_T c9_sq_x;
  real_T c9_tq_x;
  real_T c9_xe_a;
  real_T c9_dg_b;
  real_T c9_hh_y;
  real_T c9_uq_x;
  real_T c9_vq_x;
  real_T c9_ye_a;
  real_T c9_eg_b;
  real_T c9_ih_y;
  real_T c9_wq_x;
  real_T c9_xq_x;
  real_T c9_yq_x;
  real_T c9_ar_x;
  real_T c9_af_a;
  real_T c9_fg_b;
  real_T c9_jh_y;
  real_T c9_br_x;
  real_T c9_cr_x;
  real_T c9_bf_a;
  real_T c9_gg_b;
  real_T c9_kh_y;
  real_T c9_cf_a;
  real_T c9_hg_b;
  real_T c9_lh_y;
  real_T c9_dr_x;
  real_T c9_er_x;
  real_T c9_fr_x;
  real_T c9_gr_x;
  real_T c9_hr_x;
  real_T c9_ir_x;
  real_T c9_df_a;
  real_T c9_ig_b;
  real_T c9_mh_y;
  real_T c9_jr_x;
  real_T c9_kr_x;
  real_T c9_ef_a;
  real_T c9_jg_b;
  real_T c9_nh_y;
  real_T c9_lr_x;
  real_T c9_mr_x;
  real_T c9_nr_x;
  real_T c9_or_x;
  real_T c9_ff_a;
  real_T c9_kg_b;
  real_T c9_oh_y;
  real_T c9_pr_x;
  real_T c9_qr_x;
  real_T c9_gf_a;
  real_T c9_lg_b;
  real_T c9_ph_y;
  real_T c9_hf_a;
  real_T c9_mg_b;
  real_T c9_qh_y;
  real_T c9_if_a;
  real_T c9_ng_b;
  real_T c9_rh_y;
  real_T c9_eb_A;
  real_T c9_rr_x;
  real_T c9_sr_x;
  real_T c9_sh_y;
  real_T c9_tr_x;
  real_T c9_ur_x;
  real_T c9_og_b;
  real_T c9_th_y;
  real_T c9_vr_x;
  real_T c9_wr_x;
  real_T c9_jf_a;
  real_T c9_pg_b;
  real_T c9_uh_y;
  real_T c9_xr_x;
  real_T c9_yr_x;
  real_T c9_kf_a;
  real_T c9_qg_b;
  real_T c9_vh_y;
  real_T c9_fb_A;
  real_T c9_as_x;
  real_T c9_bs_x;
  real_T c9_wh_y;
  real_T c9_cs_x;
  real_T c9_ds_x;
  real_T c9_rg_b;
  real_T c9_xh_y;
  real_T c9_es_x;
  real_T c9_fs_x;
  real_T c9_lf_a;
  real_T c9_sg_b;
  real_T c9_yh_y;
  real_T c9_gs_x;
  real_T c9_hs_x;
  real_T c9_mf_a;
  real_T c9_tg_b;
  real_T c9_ai_y;
  real_T c9_gb_A;
  real_T c9_is_x;
  real_T c9_js_x;
  real_T c9_bi_y;
  real_T c9_ks_x;
  real_T c9_ls_x;
  real_T c9_ug_b;
  real_T c9_ci_y;
  real_T c9_ms_x;
  real_T c9_ns_x;
  real_T c9_nf_a;
  real_T c9_vg_b;
  real_T c9_di_y;
  real_T c9_hb_A;
  real_T c9_os_x;
  real_T c9_ps_x;
  real_T c9_ei_y;
  real_T c9_qs_x;
  real_T c9_rs_x;
  real_T c9_wg_b;
  real_T c9_fi_y;
  real_T c9_ss_x;
  real_T c9_ts_x;
  real_T c9_us_x;
  real_T c9_vs_x;
  real_T c9_of_a;
  real_T c9_xg_b;
  real_T c9_gi_y;
  real_T c9_ws_x;
  real_T c9_xs_x;
  real_T c9_pf_a;
  real_T c9_yg_b;
  real_T c9_hi_y;
  real_T c9_ys_x;
  real_T c9_at_x;
  real_T c9_bt_x;
  real_T c9_ct_x;
  real_T c9_qf_a;
  real_T c9_ah_b;
  real_T c9_ii_y;
  real_T c9_dt_x;
  real_T c9_et_x;
  real_T c9_rf_a;
  real_T c9_bh_b;
  real_T c9_ji_y;
  real_T c9_sf_a;
  real_T c9_ch_b;
  real_T c9_ki_y;
  real_T c9_ib_A;
  real_T c9_ft_x;
  real_T c9_gt_x;
  real_T c9_li_y;
  real_T c9_ht_x;
  real_T c9_it_x;
  real_T c9_dh_b;
  real_T c9_mi_y;
  real_T c9_jt_x;
  real_T c9_kt_x;
  real_T c9_lt_x;
  real_T c9_mt_x;
  real_T c9_tf_a;
  real_T c9_eh_b;
  real_T c9_ni_y;
  real_T c9_nt_x;
  real_T c9_ot_x;
  real_T c9_uf_a;
  real_T c9_fh_b;
  real_T c9_oi_y;
  real_T c9_pt_x;
  real_T c9_qt_x;
  real_T c9_rt_x;
  real_T c9_st_x;
  real_T c9_vf_a;
  real_T c9_gh_b;
  real_T c9_pi_y;
  real_T c9_tt_x;
  real_T c9_ut_x;
  real_T c9_wf_a;
  real_T c9_hh_b;
  real_T c9_qi_y;
  real_T c9_xf_a;
  real_T c9_ih_b;
  real_T c9_ri_y;
  real_T c9_jb_A;
  real_T c9_vt_x;
  real_T c9_wt_x;
  real_T c9_si_y;
  real_T c9_xt_x;
  real_T c9_yt_x;
  real_T c9_jh_b;
  real_T c9_ti_y;
  real_T c9_au_x;
  real_T c9_bu_x;
  real_T c9_cu_x;
  real_T c9_du_x;
  real_T c9_eu_x;
  real_T c9_fu_x;
  real_T c9_yf_a;
  real_T c9_kh_b;
  real_T c9_ui_y;
  real_T c9_gu_x;
  real_T c9_hu_x;
  real_T c9_ag_a;
  real_T c9_lh_b;
  real_T c9_vi_y;
  real_T c9_iu_x;
  real_T c9_ju_x;
  real_T c9_ku_x;
  real_T c9_lu_x;
  real_T c9_bg_a;
  real_T c9_mh_b;
  real_T c9_wi_y;
  real_T c9_mu_x;
  real_T c9_nu_x;
  real_T c9_cg_a;
  real_T c9_nh_b;
  real_T c9_xi_y;
  real_T c9_dg_a;
  real_T c9_oh_b;
  real_T c9_yi_y;
  real_T c9_ou_x;
  real_T c9_pu_x;
  real_T c9_qu_x;
  real_T c9_ru_x;
  real_T c9_su_x;
  real_T c9_tu_x;
  real_T c9_eg_a;
  real_T c9_ph_b;
  real_T c9_aj_y;
  real_T c9_uu_x;
  real_T c9_vu_x;
  real_T c9_fg_a;
  real_T c9_qh_b;
  real_T c9_bj_y;
  real_T c9_wu_x;
  real_T c9_xu_x;
  real_T c9_yu_x;
  real_T c9_av_x;
  real_T c9_gg_a;
  real_T c9_rh_b;
  real_T c9_cj_y;
  real_T c9_bv_x;
  real_T c9_cv_x;
  real_T c9_hg_a;
  real_T c9_sh_b;
  real_T c9_dj_y;
  real_T c9_ig_a;
  real_T c9_th_b;
  real_T c9_ej_y;
  real_T c9_jg_a;
  real_T c9_uh_b;
  real_T c9_fj_y;
  real_T c9_kb_A;
  real_T c9_dv_x;
  real_T c9_ev_x;
  real_T c9_gj_y;
  real_T c9_fv_x;
  real_T c9_gv_x;
  real_T c9_vh_b;
  real_T c9_hj_y;
  real_T c9_hv_x;
  real_T c9_iv_x;
  real_T c9_kg_a;
  real_T c9_wh_b;
  real_T c9_ij_y;
  real_T c9_jv_x;
  real_T c9_kv_x;
  real_T c9_lg_a;
  real_T c9_xh_b;
  real_T c9_jj_y;
  real_T c9_lb_A;
  real_T c9_lv_x;
  real_T c9_mv_x;
  real_T c9_kj_y;
  real_T c9_nv_x;
  real_T c9_ov_x;
  real_T c9_yh_b;
  real_T c9_lj_y;
  real_T c9_pv_x;
  real_T c9_qv_x;
  real_T c9_mg_a;
  real_T c9_ai_b;
  real_T c9_mj_y;
  real_T c9_rv_x;
  real_T c9_sv_x;
  real_T c9_ng_a;
  real_T c9_bi_b;
  real_T c9_nj_y;
  real_T c9_mb_A;
  real_T c9_tv_x;
  real_T c9_uv_x;
  real_T c9_oj_y;
  real_T c9_vv_x;
  real_T c9_wv_x;
  real_T c9_ci_b;
  real_T c9_pj_y;
  real_T c9_xv_x;
  real_T c9_yv_x;
  real_T c9_aw_x;
  real_T c9_bw_x;
  real_T c9_cw_x;
  real_T c9_dw_x;
  real_T c9_og_a;
  real_T c9_di_b;
  real_T c9_qj_y;
  real_T c9_ew_x;
  real_T c9_fw_x;
  real_T c9_pg_a;
  real_T c9_ei_b;
  real_T c9_rj_y;
  real_T c9_gw_x;
  real_T c9_hw_x;
  real_T c9_iw_x;
  real_T c9_jw_x;
  real_T c9_qg_a;
  real_T c9_fi_b;
  real_T c9_sj_y;
  real_T c9_kw_x;
  real_T c9_lw_x;
  real_T c9_rg_a;
  real_T c9_gi_b;
  real_T c9_tj_y;
  real_T c9_sg_a;
  real_T c9_hi_b;
  real_T c9_uj_y;
  real_T c9_mw_x;
  real_T c9_nw_x;
  real_T c9_ow_x;
  real_T c9_pw_x;
  real_T c9_qw_x;
  real_T c9_rw_x;
  real_T c9_tg_a;
  real_T c9_ii_b;
  real_T c9_vj_y;
  real_T c9_sw_x;
  real_T c9_tw_x;
  real_T c9_ug_a;
  real_T c9_ji_b;
  real_T c9_wj_y;
  real_T c9_uw_x;
  real_T c9_vw_x;
  real_T c9_ww_x;
  real_T c9_xw_x;
  real_T c9_vg_a;
  real_T c9_ki_b;
  real_T c9_xj_y;
  real_T c9_yw_x;
  real_T c9_ax_x;
  real_T c9_wg_a;
  real_T c9_li_b;
  real_T c9_yj_y;
  real_T c9_xg_a;
  real_T c9_mi_b;
  real_T c9_ak_y;
  real_T c9_yg_a;
  real_T c9_ni_b;
  real_T c9_bk_y;
  real_T c9_nb_A;
  real_T c9_bx_x;
  real_T c9_cx_x;
  real_T c9_ck_y;
  real_T c9_dx_x;
  real_T c9_ex_x;
  real_T c9_oi_b;
  real_T c9_dk_y;
  real_T c9_fx_x;
  real_T c9_gx_x;
  real_T c9_hx_x;
  real_T c9_ix_x;
  real_T c9_ah_a;
  real_T c9_pi_b;
  real_T c9_ek_y;
  real_T c9_jx_x;
  real_T c9_kx_x;
  real_T c9_bh_a;
  real_T c9_qi_b;
  real_T c9_fk_y;
  real_T c9_lx_x;
  real_T c9_mx_x;
  real_T c9_nx_x;
  real_T c9_ox_x;
  real_T c9_ch_a;
  real_T c9_ri_b;
  real_T c9_gk_y;
  real_T c9_px_x;
  real_T c9_qx_x;
  real_T c9_dh_a;
  real_T c9_si_b;
  real_T c9_hk_y;
  real_T c9_eh_a;
  real_T c9_ti_b;
  real_T c9_ik_y;
  real_T c9_ob_A;
  real_T c9_rx_x;
  real_T c9_sx_x;
  real_T c9_jk_y;
  real_T c9_tx_x;
  real_T c9_ux_x;
  real_T c9_ui_b;
  real_T c9_kk_y;
  real_T c9_vx_x;
  real_T c9_wx_x;
  real_T c9_xx_x;
  real_T c9_yx_x;
  real_T c9_fh_a;
  real_T c9_vi_b;
  real_T c9_lk_y;
  real_T c9_ay_x;
  real_T c9_by_x;
  real_T c9_gh_a;
  real_T c9_wi_b;
  real_T c9_mk_y;
  real_T c9_cy_x;
  real_T c9_dy_x;
  real_T c9_ey_x;
  real_T c9_fy_x;
  real_T c9_hh_a;
  real_T c9_xi_b;
  real_T c9_nk_y;
  real_T c9_gy_x;
  real_T c9_hy_x;
  real_T c9_ih_a;
  real_T c9_yi_b;
  real_T c9_ok_y;
  real_T c9_jh_a;
  real_T c9_aj_b;
  real_T c9_pk_y;
  real_T c9_pb_A;
  real_T c9_iy_x;
  real_T c9_jy_x;
  real_T c9_qk_y;
  real_T c9_ky_x;
  real_T c9_ly_x;
  real_T c9_bj_b;
  real_T c9_rk_y;
  real_T c9_my_x;
  real_T c9_ny_x;
  real_T c9_kh_a;
  real_T c9_cj_b;
  real_T c9_sk_y;
  real_T c9_oy_x;
  real_T c9_py_x;
  real_T c9_lh_a;
  real_T c9_dj_b;
  real_T c9_tk_y;
  real_T c9_qb_A;
  real_T c9_qy_x;
  real_T c9_ry_x;
  real_T c9_uk_y;
  real_T c9_sy_x;
  real_T c9_ty_x;
  real_T c9_ej_b;
  real_T c9_vk_y;
  real_T c9_uy_x;
  real_T c9_vy_x;
  real_T c9_mh_a;
  real_T c9_fj_b;
  real_T c9_wk_y;
  real_T c9_wy_x;
  real_T c9_xy_x;
  real_T c9_nh_a;
  real_T c9_gj_b;
  real_T c9_xk_y;
  real_T c9_rb_A;
  real_T c9_yy_x;
  real_T c9_aab_x;
  real_T c9_yk_y;
  real_T c9_bab_x;
  real_T c9_cab_x;
  real_T c9_hj_b;
  real_T c9_al_y;
  real_T c9_dab_x;
  real_T c9_eab_x;
  real_T c9_fab_x;
  real_T c9_gab_x;
  real_T c9_hab_x;
  real_T c9_iab_x;
  real_T c9_oh_a;
  real_T c9_ij_b;
  real_T c9_bl_y;
  real_T c9_jab_x;
  real_T c9_kab_x;
  real_T c9_ph_a;
  real_T c9_jj_b;
  real_T c9_cl_y;
  real_T c9_lab_x;
  real_T c9_mab_x;
  real_T c9_nab_x;
  real_T c9_oab_x;
  real_T c9_qh_a;
  real_T c9_kj_b;
  real_T c9_dl_y;
  real_T c9_pab_x;
  real_T c9_qab_x;
  real_T c9_rh_a;
  real_T c9_lj_b;
  real_T c9_el_y;
  real_T c9_sh_a;
  real_T c9_mj_b;
  real_T c9_fl_y;
  real_T c9_rab_x;
  real_T c9_sab_x;
  real_T c9_tab_x;
  real_T c9_uab_x;
  real_T c9_vab_x;
  real_T c9_wab_x;
  real_T c9_th_a;
  real_T c9_nj_b;
  real_T c9_gl_y;
  real_T c9_xab_x;
  real_T c9_yab_x;
  real_T c9_uh_a;
  real_T c9_oj_b;
  real_T c9_hl_y;
  real_T c9_abb_x;
  real_T c9_bbb_x;
  real_T c9_cbb_x;
  real_T c9_dbb_x;
  real_T c9_vh_a;
  real_T c9_pj_b;
  real_T c9_il_y;
  real_T c9_ebb_x;
  real_T c9_fbb_x;
  real_T c9_wh_a;
  real_T c9_qj_b;
  real_T c9_jl_y;
  real_T c9_xh_a;
  real_T c9_rj_b;
  real_T c9_kl_y;
  real_T c9_yh_a;
  real_T c9_sj_b;
  real_T c9_ll_y;
  real_T c9_sb_A;
  real_T c9_gbb_x;
  real_T c9_hbb_x;
  real_T c9_ml_y;
  real_T c9_ibb_x;
  real_T c9_jbb_x;
  real_T c9_tj_b;
  real_T c9_nl_y;
  real_T c9_kbb_x;
  real_T c9_lbb_x;
  real_T c9_mbb_x;
  real_T c9_nbb_x;
  real_T c9_ai_a;
  real_T c9_uj_b;
  real_T c9_ol_y;
  real_T c9_obb_x;
  real_T c9_pbb_x;
  real_T c9_bi_a;
  real_T c9_vj_b;
  real_T c9_pl_y;
  real_T c9_qbb_x;
  real_T c9_rbb_x;
  real_T c9_sbb_x;
  real_T c9_tbb_x;
  real_T c9_ci_a;
  real_T c9_wj_b;
  real_T c9_ql_y;
  real_T c9_ubb_x;
  real_T c9_vbb_x;
  real_T c9_di_a;
  real_T c9_xj_b;
  real_T c9_rl_y;
  real_T c9_ei_a;
  real_T c9_yj_b;
  real_T c9_sl_y;
  real_T c9_tb_A;
  real_T c9_wbb_x;
  real_T c9_xbb_x;
  real_T c9_tl_y;
  real_T c9_ybb_x;
  real_T c9_acb_x;
  real_T c9_ak_b;
  real_T c9_ul_y;
  real_T c9_bcb_x;
  real_T c9_ccb_x;
  real_T c9_dcb_x;
  real_T c9_ecb_x;
  real_T c9_fi_a;
  real_T c9_bk_b;
  real_T c9_vl_y;
  real_T c9_fcb_x;
  real_T c9_gcb_x;
  real_T c9_gi_a;
  real_T c9_ck_b;
  real_T c9_wl_y;
  real_T c9_hcb_x;
  real_T c9_icb_x;
  real_T c9_jcb_x;
  real_T c9_kcb_x;
  real_T c9_hi_a;
  real_T c9_dk_b;
  real_T c9_xl_y;
  real_T c9_lcb_x;
  real_T c9_mcb_x;
  real_T c9_ii_a;
  real_T c9_ek_b;
  real_T c9_yl_y;
  real_T c9_ji_a;
  real_T c9_fk_b;
  real_T c9_am_y;
  real_T c9_ub_A;
  real_T c9_ncb_x;
  real_T c9_ocb_x;
  real_T c9_bm_y;
  real_T c9_pcb_x;
  real_T c9_qcb_x;
  real_T c9_gk_b;
  real_T c9_cm_y;
  real_T c9_rcb_x;
  real_T c9_scb_x;
  real_T c9_ki_a;
  real_T c9_hk_b;
  real_T c9_dm_y;
  real_T c9_vb_A;
  real_T c9_tcb_x;
  real_T c9_ucb_x;
  real_T c9_em_y;
  real_T c9_vcb_x;
  real_T c9_wcb_x;
  real_T c9_ik_b;
  real_T c9_fm_y;
  real_T c9_xcb_x;
  real_T c9_ycb_x;
  real_T c9_adb_x;
  real_T c9_bdb_x;
  real_T c9_cdb_x;
  real_T c9_ddb_x;
  real_T c9_li_a;
  real_T c9_jk_b;
  real_T c9_gm_y;
  real_T c9_edb_x;
  real_T c9_fdb_x;
  real_T c9_mi_a;
  real_T c9_kk_b;
  real_T c9_hm_y;
  real_T c9_gdb_x;
  real_T c9_hdb_x;
  real_T c9_idb_x;
  real_T c9_jdb_x;
  real_T c9_ni_a;
  real_T c9_lk_b;
  real_T c9_im_y;
  real_T c9_kdb_x;
  real_T c9_ldb_x;
  real_T c9_oi_a;
  real_T c9_mk_b;
  real_T c9_jm_y;
  real_T c9_pi_a;
  real_T c9_nk_b;
  real_T c9_km_y;
  real_T c9_mdb_x;
  real_T c9_ndb_x;
  real_T c9_odb_x;
  real_T c9_pdb_x;
  real_T c9_qdb_x;
  real_T c9_rdb_x;
  real_T c9_qi_a;
  real_T c9_ok_b;
  real_T c9_lm_y;
  real_T c9_sdb_x;
  real_T c9_tdb_x;
  real_T c9_ri_a;
  real_T c9_pk_b;
  real_T c9_mm_y;
  real_T c9_udb_x;
  real_T c9_vdb_x;
  real_T c9_wdb_x;
  real_T c9_xdb_x;
  real_T c9_si_a;
  real_T c9_qk_b;
  real_T c9_nm_y;
  real_T c9_ydb_x;
  real_T c9_aeb_x;
  real_T c9_ti_a;
  real_T c9_rk_b;
  real_T c9_om_y;
  real_T c9_ui_a;
  real_T c9_sk_b;
  real_T c9_pm_y;
  real_T c9_vi_a;
  real_T c9_tk_b;
  real_T c9_qm_y;
  real_T c9_wb_A;
  real_T c9_beb_x;
  real_T c9_ceb_x;
  real_T c9_rm_y;
  real_T c9_deb_x;
  real_T c9_eeb_x;
  real_T c9_uk_b;
  real_T c9_sm_y;
  real_T c9_feb_x;
  real_T c9_geb_x;
  real_T c9_wi_a;
  real_T c9_vk_b;
  real_T c9_tm_y;
  real_T c9_xb_A;
  real_T c9_heb_x;
  real_T c9_ieb_x;
  real_T c9_um_y;
  real_T c9_jeb_x;
  real_T c9_keb_x;
  real_T c9_wk_b;
  real_T c9_vm_y;
  real_T c9_leb_x;
  real_T c9_meb_x;
  real_T c9_xi_a;
  real_T c9_xk_b;
  real_T c9_wm_y;
  real_T c9_yb_A;
  real_T c9_neb_x;
  real_T c9_oeb_x;
  real_T c9_xm_y;
  real_T c9_peb_x;
  real_T c9_qeb_x;
  real_T c9_yk_b;
  real_T c9_ym_y;
  real_T c9_ac_A;
  real_T c9_reb_x;
  real_T c9_seb_x;
  real_T c9_an_y;
  real_T c9_teb_x;
  real_T c9_ueb_x;
  real_T c9_al_b;
  real_T c9_bn_y;
  real_T c9_veb_x;
  real_T c9_web_x;
  real_T c9_xeb_x;
  real_T c9_yeb_x;
  real_T c9_afb_x;
  real_T c9_bfb_x;
  real_T c9_yi_a;
  real_T c9_bl_b;
  real_T c9_cn_y;
  real_T c9_cfb_x;
  real_T c9_dfb_x;
  real_T c9_efb_x;
  real_T c9_ffb_x;
  real_T c9_aj_a;
  real_T c9_cl_b;
  real_T c9_dn_y;
  real_T c9_bj_a;
  real_T c9_dl_b;
  real_T c9_en_y;
  real_T c9_gfb_x;
  real_T c9_hfb_x;
  real_T c9_ifb_x;
  real_T c9_jfb_x;
  real_T c9_kfb_x;
  real_T c9_lfb_x;
  real_T c9_cj_a;
  real_T c9_el_b;
  real_T c9_fn_y;
  real_T c9_mfb_x;
  real_T c9_nfb_x;
  real_T c9_ofb_x;
  real_T c9_pfb_x;
  real_T c9_dj_a;
  real_T c9_fl_b;
  real_T c9_gn_y;
  real_T c9_ej_a;
  real_T c9_gl_b;
  real_T c9_hn_y;
  real_T c9_fj_a;
  real_T c9_hl_b;
  real_T c9_in_y;
  real_T c9_bc_A;
  real_T c9_qfb_x;
  real_T c9_rfb_x;
  real_T c9_jn_y;
  real_T c9_sfb_x;
  real_T c9_tfb_x;
  real_T c9_il_b;
  real_T c9_kn_y;
  real_T c9_ufb_x;
  real_T c9_vfb_x;
  real_T c9_wfb_x;
  real_T c9_xfb_x;
  real_T c9_gj_a;
  real_T c9_jl_b;
  real_T c9_ln_y;
  real_T c9_yfb_x;
  real_T c9_agb_x;
  real_T c9_bgb_x;
  real_T c9_cgb_x;
  real_T c9_hj_a;
  real_T c9_kl_b;
  real_T c9_mn_y;
  real_T c9_ij_a;
  real_T c9_ll_b;
  real_T c9_nn_y;
  real_T c9_cc_A;
  real_T c9_dgb_x;
  real_T c9_egb_x;
  real_T c9_on_y;
  real_T c9_fgb_x;
  real_T c9_ggb_x;
  real_T c9_ml_b;
  real_T c9_pn_y;
  real_T c9_hgb_x;
  real_T c9_igb_x;
  real_T c9_jgb_x;
  real_T c9_kgb_x;
  real_T c9_jj_a;
  real_T c9_nl_b;
  real_T c9_qn_y;
  real_T c9_lgb_x;
  real_T c9_mgb_x;
  real_T c9_ngb_x;
  real_T c9_ogb_x;
  real_T c9_kj_a;
  real_T c9_ol_b;
  real_T c9_rn_y;
  real_T c9_lj_a;
  real_T c9_pl_b;
  real_T c9_sn_y;
  real_T c9_dc_A;
  real_T c9_pgb_x;
  real_T c9_qgb_x;
  real_T c9_tn_y;
  real_T c9_rgb_x;
  real_T c9_sgb_x;
  real_T c9_ql_b;
  real_T c9_un_y;
  real_T c9_tgb_x;
  real_T c9_ugb_x;
  real_T c9_mj_a;
  real_T c9_rl_b;
  real_T c9_vn_y;
  real_T c9_ec_A;
  real_T c9_vgb_x;
  real_T c9_wgb_x;
  real_T c9_wn_y;
  real_T c9_xgb_x;
  real_T c9_ygb_x;
  real_T c9_sl_b;
  real_T c9_xn_y;
  real_T c9_ahb_x;
  real_T c9_bhb_x;
  real_T c9_nj_a;
  real_T c9_tl_b;
  real_T c9_yn_y;
  real_T c9_fc_A;
  real_T c9_chb_x;
  real_T c9_dhb_x;
  real_T c9_ao_y;
  real_T c9_ehb_x;
  real_T c9_fhb_x;
  real_T c9_ul_b;
  real_T c9_bo_y;
  real_T c9_ghb_x;
  real_T c9_hhb_x;
  real_T c9_ihb_x;
  real_T c9_jhb_x;
  real_T c9_khb_x;
  real_T c9_lhb_x;
  real_T c9_oj_a;
  real_T c9_vl_b;
  real_T c9_co_y;
  real_T c9_mhb_x;
  real_T c9_nhb_x;
  real_T c9_ohb_x;
  real_T c9_phb_x;
  real_T c9_pj_a;
  real_T c9_wl_b;
  real_T c9_do_y;
  real_T c9_qj_a;
  real_T c9_xl_b;
  real_T c9_eo_y;
  real_T c9_qhb_x;
  real_T c9_rhb_x;
  real_T c9_shb_x;
  real_T c9_thb_x;
  real_T c9_uhb_x;
  real_T c9_vhb_x;
  real_T c9_rj_a;
  real_T c9_yl_b;
  real_T c9_fo_y;
  real_T c9_whb_x;
  real_T c9_xhb_x;
  real_T c9_yhb_x;
  real_T c9_aib_x;
  real_T c9_sj_a;
  real_T c9_am_b;
  real_T c9_go_y;
  real_T c9_tj_a;
  real_T c9_bm_b;
  real_T c9_ho_y;
  real_T c9_uj_a;
  real_T c9_cm_b;
  real_T c9_io_y;
  real_T c9_gc_A;
  real_T c9_bib_x;
  real_T c9_cib_x;
  real_T c9_jo_y;
  real_T c9_dib_x;
  real_T c9_eib_x;
  real_T c9_dm_b;
  real_T c9_ko_y;
  real_T c9_fib_x;
  real_T c9_gib_x;
  real_T c9_hib_x;
  real_T c9_iib_x;
  real_T c9_vj_a;
  real_T c9_em_b;
  real_T c9_lo_y;
  real_T c9_jib_x;
  real_T c9_kib_x;
  real_T c9_lib_x;
  real_T c9_mib_x;
  real_T c9_wj_a;
  real_T c9_fm_b;
  real_T c9_mo_y;
  real_T c9_xj_a;
  real_T c9_gm_b;
  real_T c9_no_y;
  real_T c9_hc_A;
  real_T c9_nib_x;
  real_T c9_oib_x;
  real_T c9_oo_y;
  real_T c9_pib_x;
  real_T c9_qib_x;
  real_T c9_hm_b;
  real_T c9_po_y;
  real_T c9_rib_x;
  real_T c9_sib_x;
  real_T c9_tib_x;
  real_T c9_uib_x;
  real_T c9_yj_a;
  real_T c9_im_b;
  real_T c9_qo_y;
  real_T c9_vib_x;
  real_T c9_wib_x;
  real_T c9_xib_x;
  real_T c9_yib_x;
  real_T c9_ak_a;
  real_T c9_jm_b;
  real_T c9_ro_y;
  real_T c9_bk_a;
  real_T c9_km_b;
  real_T c9_so_y;
  real_T c9_ic_A;
  real_T c9_ajb_x;
  real_T c9_bjb_x;
  real_T c9_to_y;
  real_T c9_cjb_x;
  real_T c9_djb_x;
  real_T c9_lm_b;
  real_T c9_uo_y;
  real_T c9_ejb_x;
  real_T c9_fjb_x;
  real_T c9_gjb_x;
  real_T c9_hjb_x;
  real_T c9_ck_a;
  real_T c9_mm_b;
  real_T c9_vo_y;
  real_T c9_ijb_x;
  real_T c9_jjb_x;
  real_T c9_kjb_x;
  real_T c9_ljb_x;
  real_T c9_dk_a;
  real_T c9_nm_b;
  real_T c9_wo_y;
  real_T c9_ek_a;
  real_T c9_om_b;
  real_T c9_xo_y;
  real_T c9_jc_A;
  real_T c9_mjb_x;
  real_T c9_njb_x;
  real_T c9_yo_y;
  real_T c9_ojb_x;
  real_T c9_pjb_x;
  real_T c9_pm_b;
  real_T c9_ap_y;
  real_T c9_qjb_x;
  real_T c9_rjb_x;
  real_T c9_sjb_x;
  real_T c9_tjb_x;
  real_T c9_ujb_x;
  real_T c9_vjb_x;
  real_T c9_fk_a;
  real_T c9_qm_b;
  real_T c9_bp_y;
  real_T c9_wjb_x;
  real_T c9_xjb_x;
  real_T c9_yjb_x;
  real_T c9_akb_x;
  real_T c9_gk_a;
  real_T c9_rm_b;
  real_T c9_cp_y;
  real_T c9_hk_a;
  real_T c9_sm_b;
  real_T c9_dp_y;
  real_T c9_bkb_x;
  real_T c9_ckb_x;
  real_T c9_dkb_x;
  real_T c9_ekb_x;
  real_T c9_fkb_x;
  real_T c9_gkb_x;
  real_T c9_ik_a;
  real_T c9_tm_b;
  real_T c9_ep_y;
  real_T c9_hkb_x;
  real_T c9_ikb_x;
  real_T c9_jkb_x;
  real_T c9_kkb_x;
  real_T c9_jk_a;
  real_T c9_um_b;
  real_T c9_fp_y;
  real_T c9_kk_a;
  real_T c9_vm_b;
  real_T c9_gp_y;
  real_T c9_lk_a;
  real_T c9_wm_b;
  real_T c9_hp_y;
  real_T c9_kc_A;
  real_T c9_lkb_x;
  real_T c9_mkb_x;
  real_T c9_ip_y;
  real_T c9_nkb_x;
  real_T c9_okb_x;
  real_T c9_xm_b;
  real_T c9_jp_y;
  real_T c9_pkb_x;
  real_T c9_qkb_x;
  real_T c9_rkb_x;
  real_T c9_skb_x;
  real_T c9_mk_a;
  real_T c9_ym_b;
  real_T c9_kp_y;
  real_T c9_tkb_x;
  real_T c9_ukb_x;
  real_T c9_vkb_x;
  real_T c9_wkb_x;
  real_T c9_nk_a;
  real_T c9_an_b;
  real_T c9_lp_y;
  real_T c9_ok_a;
  real_T c9_bn_b;
  real_T c9_mp_y;
  real_T c9_lc_A;
  real_T c9_xkb_x;
  real_T c9_ykb_x;
  real_T c9_np_y;
  real_T c9_alb_x;
  real_T c9_blb_x;
  real_T c9_cn_b;
  real_T c9_op_y;
  real_T c9_clb_x;
  real_T c9_dlb_x;
  real_T c9_elb_x;
  real_T c9_flb_x;
  real_T c9_glb_x;
  real_T c9_hlb_x;
  real_T c9_pk_a;
  real_T c9_dn_b;
  real_T c9_pp_y;
  real_T c9_ilb_x;
  real_T c9_jlb_x;
  real_T c9_klb_x;
  real_T c9_llb_x;
  real_T c9_qk_a;
  real_T c9_en_b;
  real_T c9_qp_y;
  real_T c9_rk_a;
  real_T c9_fn_b;
  real_T c9_rp_y;
  real_T c9_mlb_x;
  real_T c9_nlb_x;
  real_T c9_olb_x;
  real_T c9_plb_x;
  real_T c9_qlb_x;
  real_T c9_rlb_x;
  real_T c9_sk_a;
  real_T c9_gn_b;
  real_T c9_sp_y;
  real_T c9_slb_x;
  real_T c9_tlb_x;
  real_T c9_ulb_x;
  real_T c9_vlb_x;
  real_T c9_tk_a;
  real_T c9_hn_b;
  real_T c9_tp_y;
  real_T c9_uk_a;
  real_T c9_in_b;
  real_T c9_up_y;
  real_T c9_vk_a;
  real_T c9_jn_b;
  real_T c9_vp_y;
  real_T c9_mc_A;
  real_T c9_wlb_x;
  real_T c9_xlb_x;
  real_T c9_wp_y;
  real_T c9_ylb_x;
  real_T c9_amb_x;
  real_T c9_bmb_x;
  real_T c9_cmb_x;
  real_T c9_dmb_x;
  real_T c9_emb_x;
  real_T c9_fmb_x;
  real_T c9_gmb_x;
  real_T c9_hmb_x;
  real_T c9_imb_x;
  real_T c9_jmb_x;
  real_T c9_kmb_x;
  real_T c9_wk_a;
  real_T c9_kn_b;
  real_T c9_xp_y;
  real_T c9_lmb_x;
  real_T c9_mmb_x;
  real_T c9_xk_a;
  real_T c9_ln_b;
  real_T c9_yp_y;
  real_T c9_nmb_x;
  real_T c9_omb_x;
  real_T c9_pmb_x;
  real_T c9_qmb_x;
  real_T c9_yk_a;
  real_T c9_mn_b;
  real_T c9_aq_y;
  real_T c9_rmb_x;
  real_T c9_smb_x;
  real_T c9_al_a;
  real_T c9_nn_b;
  real_T c9_bq_y;
  real_T c9_bl_a;
  real_T c9_on_b;
  real_T c9_cq_y;
  real_T c9_tmb_x;
  real_T c9_umb_x;
  real_T c9_vmb_x;
  real_T c9_wmb_x;
  real_T c9_xmb_x;
  real_T c9_ymb_x;
  real_T c9_cl_a;
  real_T c9_pn_b;
  real_T c9_dq_y;
  real_T c9_anb_x;
  real_T c9_bnb_x;
  real_T c9_dl_a;
  real_T c9_qn_b;
  real_T c9_eq_y;
  real_T c9_cnb_x;
  real_T c9_dnb_x;
  real_T c9_enb_x;
  real_T c9_fnb_x;
  real_T c9_el_a;
  real_T c9_rn_b;
  real_T c9_fq_y;
  real_T c9_gnb_x;
  real_T c9_hnb_x;
  real_T c9_fl_a;
  real_T c9_sn_b;
  real_T c9_gq_y;
  real_T c9_gl_a;
  real_T c9_tn_b;
  real_T c9_hq_y;
  real_T c9_inb_x;
  real_T c9_jnb_x;
  real_T c9_knb_x;
  real_T c9_lnb_x;
  real_T c9_hl_a;
  real_T c9_un_b;
  real_T c9_iq_y;
  real_T c9_mnb_x;
  real_T c9_nnb_x;
  real_T c9_onb_x;
  real_T c9_pnb_x;
  real_T c9_qnb_x;
  real_T c9_rnb_x;
  real_T c9_snb_x;
  real_T c9_tnb_x;
  real_T c9_il_a;
  real_T c9_vn_b;
  real_T c9_jq_y;
  real_T c9_unb_x;
  real_T c9_vnb_x;
  real_T c9_jl_a;
  real_T c9_wn_b;
  real_T c9_kq_y;
  real_T c9_wnb_x;
  real_T c9_xnb_x;
  real_T c9_ynb_x;
  real_T c9_aob_x;
  real_T c9_kl_a;
  real_T c9_xn_b;
  real_T c9_lq_y;
  real_T c9_bob_x;
  real_T c9_cob_x;
  real_T c9_ll_a;
  real_T c9_yn_b;
  real_T c9_mq_y;
  real_T c9_ml_a;
  real_T c9_ao_b;
  real_T c9_nq_y;
  real_T c9_dob_x;
  real_T c9_eob_x;
  real_T c9_fob_x;
  real_T c9_gob_x;
  real_T c9_hob_x;
  real_T c9_iob_x;
  real_T c9_nl_a;
  real_T c9_bo_b;
  real_T c9_oq_y;
  real_T c9_job_x;
  real_T c9_kob_x;
  real_T c9_ol_a;
  real_T c9_co_b;
  real_T c9_pq_y;
  real_T c9_lob_x;
  real_T c9_mob_x;
  real_T c9_nob_x;
  real_T c9_oob_x;
  real_T c9_pl_a;
  real_T c9_do_b;
  real_T c9_qq_y;
  real_T c9_pob_x;
  real_T c9_qob_x;
  real_T c9_ql_a;
  real_T c9_eo_b;
  real_T c9_rq_y;
  real_T c9_rl_a;
  real_T c9_fo_b;
  real_T c9_sq_y;
  real_T c9_sl_a;
  real_T c9_go_b;
  real_T c9_tq_y;
  real_T c9_rob_x;
  real_T c9_sob_x;
  real_T c9_tob_x;
  real_T c9_uob_x;
  real_T c9_vob_x;
  real_T c9_wob_x;
  real_T c9_xob_x;
  real_T c9_yob_x;
  real_T c9_apb_x;
  real_T c9_bpb_x;
  real_T c9_cpb_x;
  real_T c9_dpb_x;
  real_T c9_tl_a;
  real_T c9_ho_b;
  real_T c9_uq_y;
  real_T c9_epb_x;
  real_T c9_fpb_x;
  real_T c9_ul_a;
  real_T c9_io_b;
  real_T c9_vq_y;
  real_T c9_gpb_x;
  real_T c9_hpb_x;
  real_T c9_ipb_x;
  real_T c9_jpb_x;
  real_T c9_vl_a;
  real_T c9_jo_b;
  real_T c9_wq_y;
  real_T c9_kpb_x;
  real_T c9_lpb_x;
  real_T c9_wl_a;
  real_T c9_ko_b;
  real_T c9_xq_y;
  real_T c9_xl_a;
  real_T c9_lo_b;
  real_T c9_yq_y;
  real_T c9_mpb_x;
  real_T c9_npb_x;
  real_T c9_opb_x;
  real_T c9_ppb_x;
  real_T c9_qpb_x;
  real_T c9_rpb_x;
  real_T c9_yl_a;
  real_T c9_mo_b;
  real_T c9_ar_y;
  real_T c9_spb_x;
  real_T c9_tpb_x;
  real_T c9_am_a;
  real_T c9_no_b;
  real_T c9_br_y;
  real_T c9_upb_x;
  real_T c9_vpb_x;
  real_T c9_wpb_x;
  real_T c9_xpb_x;
  real_T c9_bm_a;
  real_T c9_oo_b;
  real_T c9_cr_y;
  real_T c9_ypb_x;
  real_T c9_aqb_x;
  real_T c9_cm_a;
  real_T c9_po_b;
  real_T c9_dr_y;
  real_T c9_dm_a;
  real_T c9_qo_b;
  real_T c9_er_y;
  real_T c9_bqb_x;
  real_T c9_cqb_x;
  real_T c9_dqb_x;
  real_T c9_eqb_x;
  real_T c9_fqb_x;
  real_T c9_gqb_x;
  real_T c9_hqb_x;
  real_T c9_iqb_x;
  real_T c9_em_a;
  real_T c9_ro_b;
  real_T c9_fr_y;
  real_T c9_jqb_x;
  real_T c9_kqb_x;
  real_T c9_fm_a;
  real_T c9_so_b;
  real_T c9_gr_y;
  real_T c9_lqb_x;
  real_T c9_mqb_x;
  real_T c9_nqb_x;
  real_T c9_oqb_x;
  real_T c9_gm_a;
  real_T c9_to_b;
  real_T c9_hr_y;
  real_T c9_pqb_x;
  real_T c9_qqb_x;
  real_T c9_hm_a;
  real_T c9_uo_b;
  real_T c9_ir_y;
  real_T c9_im_a;
  real_T c9_vo_b;
  real_T c9_jr_y;
  real_T c9_rqb_x;
  real_T c9_sqb_x;
  real_T c9_tqb_x;
  real_T c9_uqb_x;
  real_T c9_vqb_x;
  real_T c9_wqb_x;
  real_T c9_jm_a;
  real_T c9_wo_b;
  real_T c9_kr_y;
  real_T c9_xqb_x;
  real_T c9_yqb_x;
  real_T c9_km_a;
  real_T c9_xo_b;
  real_T c9_lr_y;
  real_T c9_arb_x;
  real_T c9_brb_x;
  real_T c9_crb_x;
  real_T c9_drb_x;
  real_T c9_lm_a;
  real_T c9_yo_b;
  real_T c9_mr_y;
  real_T c9_erb_x;
  real_T c9_frb_x;
  real_T c9_mm_a;
  real_T c9_ap_b;
  real_T c9_nr_y;
  real_T c9_nm_a;
  real_T c9_bp_b;
  real_T c9_or_y;
  real_T c9_om_a;
  real_T c9_cp_b;
  real_T c9_pr_y;
  real_T c9_grb_x;
  real_T c9_hrb_x;
  real_T c9_irb_x;
  real_T c9_jrb_x;
  real_T c9_pm_a;
  real_T c9_dp_b;
  real_T c9_qr_y;
  real_T c9_krb_x;
  real_T c9_lrb_x;
  real_T c9_mrb_x;
  real_T c9_nrb_x;
  real_T c9_orb_x;
  real_T c9_prb_x;
  real_T c9_qm_a;
  real_T c9_ep_b;
  real_T c9_rr_y;
  real_T c9_qrb_x;
  real_T c9_rrb_x;
  real_T c9_srb_x;
  real_T c9_trb_x;
  real_T c9_rm_a;
  real_T c9_fp_b;
  real_T c9_sr_y;
  real_T c9_sm_a;
  real_T c9_gp_b;
  real_T c9_tr_y;
  real_T c9_urb_x;
  real_T c9_vrb_x;
  real_T c9_wrb_x;
  real_T c9_xrb_x;
  real_T c9_yrb_x;
  real_T c9_asb_x;
  real_T c9_tm_a;
  real_T c9_hp_b;
  real_T c9_ur_y;
  real_T c9_bsb_x;
  real_T c9_csb_x;
  real_T c9_dsb_x;
  real_T c9_esb_x;
  real_T c9_um_a;
  real_T c9_ip_b;
  real_T c9_vr_y;
  real_T c9_vm_a;
  real_T c9_jp_b;
  real_T c9_wr_y;
  real_T c9_fsb_x;
  real_T c9_gsb_x;
  real_T c9_hsb_x;
  real_T c9_isb_x;
  real_T c9_jsb_x;
  real_T c9_ksb_x;
  real_T c9_lsb_x;
  real_T c9_msb_x;
  real_T c9_wm_a;
  real_T c9_kp_b;
  real_T c9_xr_y;
  real_T c9_nsb_x;
  real_T c9_osb_x;
  real_T c9_psb_x;
  real_T c9_qsb_x;
  real_T c9_xm_a;
  real_T c9_lp_b;
  real_T c9_yr_y;
  real_T c9_ym_a;
  real_T c9_mp_b;
  real_T c9_as_y;
  real_T c9_rsb_x;
  real_T c9_ssb_x;
  real_T c9_tsb_x;
  real_T c9_usb_x;
  real_T c9_vsb_x;
  real_T c9_wsb_x;
  real_T c9_an_a;
  real_T c9_np_b;
  real_T c9_bs_y;
  real_T c9_xsb_x;
  real_T c9_ysb_x;
  real_T c9_atb_x;
  real_T c9_btb_x;
  real_T c9_bn_a;
  real_T c9_op_b;
  real_T c9_cs_y;
  real_T c9_cn_a;
  real_T c9_pp_b;
  real_T c9_ds_y;
  real_T c9_dn_a;
  real_T c9_qp_b;
  real_T c9_es_y;
  int32_T c9_i7;
  real_T c9_en_a[36];
  int32_T c9_i8;
  real_T c9_rp_b[6];
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  real_T c9_C[6];
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  real_T (*c9_b_tcp_speed)[6];
  real_T (*c9_b_dq)[6];
  real_T (*c9_b_q)[6];
  c9_b_dq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c9_b_tcp_speed = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  for (c9_i5 = 0; c9_i5 < 6; c9_i5++) {
    c9_q[c9_i5] = (*c9_b_q)[c9_i5];
  }

  for (c9_i6 = 0; c9_i6 < 6; c9_i6++) {
    c9_dq[c9_i6] = (*c9_b_dq)[c9_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_theta_1, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_theta_2, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_theta_3, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_theta_4, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_theta_5, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_theta_6, 5U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_J, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_q, 9U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_dq, 10U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tcp_speed, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_theta_1 = c9_q[0];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_theta_2 = c9_q[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_theta_3 = c9_q[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_theta_4 = c9_q[3];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_theta_5 = c9_q[4];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_theta_6 = c9_q[5];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_x = c9_theta_1;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarCos(c9_b_x);
  c9_b = c9_b_x;
  c9_y = 109.0 * c9_b;
  c9_A = c9_y;
  c9_c_x = c9_A;
  c9_d_x = c9_c_x;
  c9_b_y = c9_d_x / 1000.0;
  c9_e_x = c9_theta_1;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarCos(c9_f_x);
  c9_b_b = c9_f_x;
  c9_c_y = 41.0 * c9_b_b;
  c9_g_x = c9_theta_5;
  c9_h_x = c9_g_x;
  c9_h_x = muDoubleScalarCos(c9_h_x);
  c9_a = c9_c_y;
  c9_c_b = c9_h_x;
  c9_d_y = c9_a * c9_c_b;
  c9_b_A = c9_d_y;
  c9_i_x = c9_b_A;
  c9_j_x = c9_i_x;
  c9_e_y = c9_j_x / 500.0;
  c9_k_x = c9_theta_2;
  c9_l_x = c9_k_x;
  c9_l_x = muDoubleScalarCos(c9_l_x);
  c9_d_b = c9_l_x;
  c9_f_y = 17.0 * c9_d_b;
  c9_m_x = c9_theta_1;
  c9_n_x = c9_m_x;
  c9_n_x = muDoubleScalarSin(c9_n_x);
  c9_b_a = c9_f_y;
  c9_e_b = c9_n_x;
  c9_g_y = c9_b_a * c9_e_b;
  c9_c_A = c9_g_y;
  c9_o_x = c9_c_A;
  c9_p_x = c9_o_x;
  c9_h_y = c9_p_x / 40.0;
  c9_q_x = c9_theta_4;
  c9_r_x = c9_q_x;
  c9_r_x = muDoubleScalarCos(c9_r_x);
  c9_f_b = c9_r_x;
  c9_i_y = 93.0 * c9_f_b;
  c9_s_x = c9_theta_2;
  c9_t_x = c9_s_x;
  c9_t_x = muDoubleScalarCos(c9_t_x);
  c9_u_x = c9_theta_1;
  c9_v_x = c9_u_x;
  c9_v_x = muDoubleScalarSin(c9_v_x);
  c9_c_a = c9_t_x;
  c9_g_b = c9_v_x;
  c9_j_y = c9_c_a * c9_g_b;
  c9_w_x = c9_theta_3;
  c9_x_x = c9_w_x;
  c9_x_x = muDoubleScalarSin(c9_x_x);
  c9_d_a = c9_j_y;
  c9_h_b = c9_x_x;
  c9_k_y = c9_d_a * c9_h_b;
  c9_y_x = c9_theta_3;
  c9_ab_x = c9_y_x;
  c9_ab_x = muDoubleScalarCos(c9_ab_x);
  c9_bb_x = c9_theta_1;
  c9_cb_x = c9_bb_x;
  c9_cb_x = muDoubleScalarSin(c9_cb_x);
  c9_e_a = c9_ab_x;
  c9_i_b = c9_cb_x;
  c9_l_y = c9_e_a * c9_i_b;
  c9_db_x = c9_theta_2;
  c9_eb_x = c9_db_x;
  c9_eb_x = muDoubleScalarSin(c9_eb_x);
  c9_f_a = c9_l_y;
  c9_j_b = c9_eb_x;
  c9_m_y = c9_f_a * c9_j_b;
  c9_g_a = c9_i_y;
  c9_k_b = c9_k_y + c9_m_y;
  c9_n_y = c9_g_a * c9_k_b;
  c9_d_A = c9_n_y;
  c9_fb_x = c9_d_A;
  c9_gb_x = c9_fb_x;
  c9_o_y = c9_gb_x / 1000.0;
  c9_hb_x = c9_theta_4;
  c9_ib_x = c9_hb_x;
  c9_ib_x = muDoubleScalarSin(c9_ib_x);
  c9_l_b = c9_ib_x;
  c9_p_y = 93.0 * c9_l_b;
  c9_jb_x = c9_theta_1;
  c9_kb_x = c9_jb_x;
  c9_kb_x = muDoubleScalarSin(c9_kb_x);
  c9_lb_x = c9_theta_2;
  c9_mb_x = c9_lb_x;
  c9_mb_x = muDoubleScalarSin(c9_mb_x);
  c9_h_a = c9_kb_x;
  c9_m_b = c9_mb_x;
  c9_q_y = c9_h_a * c9_m_b;
  c9_nb_x = c9_theta_3;
  c9_ob_x = c9_nb_x;
  c9_ob_x = muDoubleScalarSin(c9_ob_x);
  c9_i_a = c9_q_y;
  c9_n_b = c9_ob_x;
  c9_r_y = c9_i_a * c9_n_b;
  c9_pb_x = c9_theta_2;
  c9_qb_x = c9_pb_x;
  c9_qb_x = muDoubleScalarCos(c9_qb_x);
  c9_rb_x = c9_theta_3;
  c9_sb_x = c9_rb_x;
  c9_sb_x = muDoubleScalarCos(c9_sb_x);
  c9_j_a = c9_qb_x;
  c9_o_b = c9_sb_x;
  c9_s_y = c9_j_a * c9_o_b;
  c9_tb_x = c9_theta_1;
  c9_ub_x = c9_tb_x;
  c9_ub_x = muDoubleScalarSin(c9_ub_x);
  c9_k_a = c9_s_y;
  c9_p_b = c9_ub_x;
  c9_t_y = c9_k_a * c9_p_b;
  c9_l_a = c9_p_y;
  c9_q_b = c9_r_y - c9_t_y;
  c9_u_y = c9_l_a * c9_q_b;
  c9_e_A = c9_u_y;
  c9_vb_x = c9_e_A;
  c9_wb_x = c9_vb_x;
  c9_v_y = c9_wb_x / 1000.0;
  c9_xb_x = c9_theta_5;
  c9_yb_x = c9_xb_x;
  c9_yb_x = muDoubleScalarSin(c9_yb_x);
  c9_r_b = c9_yb_x;
  c9_w_y = 41.0 * c9_r_b;
  c9_ac_x = c9_theta_4;
  c9_bc_x = c9_ac_x;
  c9_bc_x = muDoubleScalarCos(c9_bc_x);
  c9_cc_x = c9_theta_1;
  c9_dc_x = c9_cc_x;
  c9_dc_x = muDoubleScalarSin(c9_dc_x);
  c9_ec_x = c9_theta_2;
  c9_fc_x = c9_ec_x;
  c9_fc_x = muDoubleScalarSin(c9_fc_x);
  c9_m_a = c9_dc_x;
  c9_s_b = c9_fc_x;
  c9_x_y = c9_m_a * c9_s_b;
  c9_gc_x = c9_theta_3;
  c9_hc_x = c9_gc_x;
  c9_hc_x = muDoubleScalarSin(c9_hc_x);
  c9_n_a = c9_x_y;
  c9_t_b = c9_hc_x;
  c9_y_y = c9_n_a * c9_t_b;
  c9_ic_x = c9_theta_2;
  c9_jc_x = c9_ic_x;
  c9_jc_x = muDoubleScalarCos(c9_jc_x);
  c9_kc_x = c9_theta_3;
  c9_lc_x = c9_kc_x;
  c9_lc_x = muDoubleScalarCos(c9_lc_x);
  c9_o_a = c9_jc_x;
  c9_u_b = c9_lc_x;
  c9_ab_y = c9_o_a * c9_u_b;
  c9_mc_x = c9_theta_1;
  c9_nc_x = c9_mc_x;
  c9_nc_x = muDoubleScalarSin(c9_nc_x);
  c9_p_a = c9_ab_y;
  c9_v_b = c9_nc_x;
  c9_bb_y = c9_p_a * c9_v_b;
  c9_q_a = c9_bc_x;
  c9_w_b = c9_y_y - c9_bb_y;
  c9_cb_y = c9_q_a * c9_w_b;
  c9_oc_x = c9_theta_4;
  c9_pc_x = c9_oc_x;
  c9_pc_x = muDoubleScalarSin(c9_pc_x);
  c9_qc_x = c9_theta_2;
  c9_rc_x = c9_qc_x;
  c9_rc_x = muDoubleScalarCos(c9_rc_x);
  c9_sc_x = c9_theta_1;
  c9_tc_x = c9_sc_x;
  c9_tc_x = muDoubleScalarSin(c9_tc_x);
  c9_r_a = c9_rc_x;
  c9_x_b = c9_tc_x;
  c9_db_y = c9_r_a * c9_x_b;
  c9_uc_x = c9_theta_3;
  c9_vc_x = c9_uc_x;
  c9_vc_x = muDoubleScalarSin(c9_vc_x);
  c9_s_a = c9_db_y;
  c9_y_b = c9_vc_x;
  c9_eb_y = c9_s_a * c9_y_b;
  c9_wc_x = c9_theta_3;
  c9_xc_x = c9_wc_x;
  c9_xc_x = muDoubleScalarCos(c9_xc_x);
  c9_yc_x = c9_theta_1;
  c9_ad_x = c9_yc_x;
  c9_ad_x = muDoubleScalarSin(c9_ad_x);
  c9_t_a = c9_xc_x;
  c9_ab_b = c9_ad_x;
  c9_fb_y = c9_t_a * c9_ab_b;
  c9_bd_x = c9_theta_2;
  c9_cd_x = c9_bd_x;
  c9_cd_x = muDoubleScalarSin(c9_cd_x);
  c9_u_a = c9_fb_y;
  c9_bb_b = c9_cd_x;
  c9_gb_y = c9_u_a * c9_bb_b;
  c9_v_a = c9_pc_x;
  c9_cb_b = c9_eb_y + c9_gb_y;
  c9_hb_y = c9_v_a * c9_cb_b;
  c9_w_a = c9_w_y;
  c9_db_b = c9_cb_y + c9_hb_y;
  c9_ib_y = c9_w_a * c9_db_b;
  c9_f_A = c9_ib_y;
  c9_dd_x = c9_f_A;
  c9_ed_x = c9_dd_x;
  c9_jb_y = c9_ed_x / 500.0;
  c9_fd_x = c9_theta_1;
  c9_gd_x = c9_fd_x;
  c9_gd_x = muDoubleScalarSin(c9_gd_x);
  c9_eb_b = c9_gd_x;
  c9_kb_y = 39243.0 * c9_eb_b;
  c9_hd_x = c9_theta_2;
  c9_id_x = c9_hd_x;
  c9_id_x = muDoubleScalarSin(c9_id_x);
  c9_x_a = c9_kb_y;
  c9_fb_b = c9_id_x;
  c9_lb_y = c9_x_a * c9_fb_b;
  c9_jd_x = c9_theta_3;
  c9_kd_x = c9_jd_x;
  c9_kd_x = muDoubleScalarSin(c9_kd_x);
  c9_y_a = c9_lb_y;
  c9_gb_b = c9_kd_x;
  c9_mb_y = c9_y_a * c9_gb_b;
  c9_g_A = c9_mb_y;
  c9_ld_x = c9_g_A;
  c9_md_x = c9_ld_x;
  c9_nb_y = c9_md_x / 100000.0;
  c9_nd_x = c9_theta_2;
  c9_od_x = c9_nd_x;
  c9_od_x = muDoubleScalarCos(c9_od_x);
  c9_hb_b = c9_od_x;
  c9_ob_y = 39243.0 * c9_hb_b;
  c9_pd_x = c9_theta_3;
  c9_qd_x = c9_pd_x;
  c9_qd_x = muDoubleScalarCos(c9_qd_x);
  c9_ab_a = c9_ob_y;
  c9_ib_b = c9_qd_x;
  c9_pb_y = c9_ab_a * c9_ib_b;
  c9_rd_x = c9_theta_1;
  c9_sd_x = c9_rd_x;
  c9_sd_x = muDoubleScalarSin(c9_sd_x);
  c9_bb_a = c9_pb_y;
  c9_jb_b = c9_sd_x;
  c9_qb_y = c9_bb_a * c9_jb_b;
  c9_h_A = c9_qb_y;
  c9_td_x = c9_h_A;
  c9_ud_x = c9_td_x;
  c9_rb_y = c9_ud_x / 100000.0;
  c9_vd_x = c9_theta_1;
  c9_wd_x = c9_vd_x;
  c9_wd_x = muDoubleScalarCos(c9_wd_x);
  c9_kb_b = c9_wd_x;
  c9_sb_y = 17.0 * c9_kb_b;
  c9_xd_x = c9_theta_2;
  c9_yd_x = c9_xd_x;
  c9_yd_x = muDoubleScalarSin(c9_yd_x);
  c9_cb_a = c9_sb_y;
  c9_lb_b = c9_yd_x;
  c9_tb_y = c9_cb_a * c9_lb_b;
  c9_i_A = c9_tb_y;
  c9_ae_x = c9_i_A;
  c9_be_x = c9_ae_x;
  c9_ub_y = c9_be_x / 40.0;
  c9_ce_x = c9_theta_4;
  c9_de_x = c9_ce_x;
  c9_de_x = muDoubleScalarCos(c9_de_x);
  c9_mb_b = c9_de_x;
  c9_vb_y = 93.0 * c9_mb_b;
  c9_ee_x = c9_theta_1;
  c9_fe_x = c9_ee_x;
  c9_fe_x = muDoubleScalarCos(c9_fe_x);
  c9_ge_x = c9_theta_2;
  c9_he_x = c9_ge_x;
  c9_he_x = muDoubleScalarSin(c9_he_x);
  c9_db_a = c9_fe_x;
  c9_nb_b = c9_he_x;
  c9_wb_y = c9_db_a * c9_nb_b;
  c9_ie_x = c9_theta_3;
  c9_je_x = c9_ie_x;
  c9_je_x = muDoubleScalarSin(c9_je_x);
  c9_eb_a = c9_wb_y;
  c9_ob_b = c9_je_x;
  c9_xb_y = c9_eb_a * c9_ob_b;
  c9_ke_x = c9_theta_1;
  c9_le_x = c9_ke_x;
  c9_le_x = muDoubleScalarCos(c9_le_x);
  c9_me_x = c9_theta_2;
  c9_ne_x = c9_me_x;
  c9_ne_x = muDoubleScalarCos(c9_ne_x);
  c9_fb_a = c9_le_x;
  c9_pb_b = c9_ne_x;
  c9_yb_y = c9_fb_a * c9_pb_b;
  c9_oe_x = c9_theta_3;
  c9_pe_x = c9_oe_x;
  c9_pe_x = muDoubleScalarCos(c9_pe_x);
  c9_gb_a = c9_yb_y;
  c9_qb_b = c9_pe_x;
  c9_ac_y = c9_gb_a * c9_qb_b;
  c9_hb_a = c9_vb_y;
  c9_rb_b = c9_xb_y - c9_ac_y;
  c9_bc_y = c9_hb_a * c9_rb_b;
  c9_j_A = c9_bc_y;
  c9_qe_x = c9_j_A;
  c9_re_x = c9_qe_x;
  c9_cc_y = c9_re_x / 1000.0;
  c9_se_x = c9_theta_4;
  c9_te_x = c9_se_x;
  c9_te_x = muDoubleScalarSin(c9_te_x);
  c9_sb_b = c9_te_x;
  c9_dc_y = 93.0 * c9_sb_b;
  c9_ue_x = c9_theta_1;
  c9_ve_x = c9_ue_x;
  c9_ve_x = muDoubleScalarCos(c9_ve_x);
  c9_we_x = c9_theta_2;
  c9_xe_x = c9_we_x;
  c9_xe_x = muDoubleScalarCos(c9_xe_x);
  c9_ib_a = c9_ve_x;
  c9_tb_b = c9_xe_x;
  c9_ec_y = c9_ib_a * c9_tb_b;
  c9_ye_x = c9_theta_3;
  c9_af_x = c9_ye_x;
  c9_af_x = muDoubleScalarSin(c9_af_x);
  c9_jb_a = c9_ec_y;
  c9_ub_b = c9_af_x;
  c9_fc_y = c9_jb_a * c9_ub_b;
  c9_bf_x = c9_theta_1;
  c9_cf_x = c9_bf_x;
  c9_cf_x = muDoubleScalarCos(c9_cf_x);
  c9_df_x = c9_theta_3;
  c9_ef_x = c9_df_x;
  c9_ef_x = muDoubleScalarCos(c9_ef_x);
  c9_kb_a = c9_cf_x;
  c9_vb_b = c9_ef_x;
  c9_gc_y = c9_kb_a * c9_vb_b;
  c9_ff_x = c9_theta_2;
  c9_gf_x = c9_ff_x;
  c9_gf_x = muDoubleScalarSin(c9_gf_x);
  c9_lb_a = c9_gc_y;
  c9_wb_b = c9_gf_x;
  c9_hc_y = c9_lb_a * c9_wb_b;
  c9_mb_a = c9_dc_y;
  c9_xb_b = c9_fc_y + c9_hc_y;
  c9_ic_y = c9_mb_a * c9_xb_b;
  c9_k_A = c9_ic_y;
  c9_hf_x = c9_k_A;
  c9_if_x = c9_hf_x;
  c9_jc_y = c9_if_x / 1000.0;
  c9_jf_x = c9_theta_5;
  c9_kf_x = c9_jf_x;
  c9_kf_x = muDoubleScalarSin(c9_kf_x);
  c9_yb_b = c9_kf_x;
  c9_kc_y = 41.0 * c9_yb_b;
  c9_lf_x = c9_theta_4;
  c9_mf_x = c9_lf_x;
  c9_mf_x = muDoubleScalarCos(c9_mf_x);
  c9_nf_x = c9_theta_1;
  c9_of_x = c9_nf_x;
  c9_of_x = muDoubleScalarCos(c9_of_x);
  c9_pf_x = c9_theta_2;
  c9_qf_x = c9_pf_x;
  c9_qf_x = muDoubleScalarCos(c9_qf_x);
  c9_nb_a = c9_of_x;
  c9_ac_b = c9_qf_x;
  c9_lc_y = c9_nb_a * c9_ac_b;
  c9_rf_x = c9_theta_3;
  c9_sf_x = c9_rf_x;
  c9_sf_x = muDoubleScalarSin(c9_sf_x);
  c9_ob_a = c9_lc_y;
  c9_bc_b = c9_sf_x;
  c9_mc_y = c9_ob_a * c9_bc_b;
  c9_tf_x = c9_theta_1;
  c9_uf_x = c9_tf_x;
  c9_uf_x = muDoubleScalarCos(c9_uf_x);
  c9_vf_x = c9_theta_3;
  c9_wf_x = c9_vf_x;
  c9_wf_x = muDoubleScalarCos(c9_wf_x);
  c9_pb_a = c9_uf_x;
  c9_cc_b = c9_wf_x;
  c9_nc_y = c9_pb_a * c9_cc_b;
  c9_xf_x = c9_theta_2;
  c9_yf_x = c9_xf_x;
  c9_yf_x = muDoubleScalarSin(c9_yf_x);
  c9_qb_a = c9_nc_y;
  c9_dc_b = c9_yf_x;
  c9_oc_y = c9_qb_a * c9_dc_b;
  c9_rb_a = c9_mf_x;
  c9_ec_b = c9_mc_y + c9_oc_y;
  c9_pc_y = c9_rb_a * c9_ec_b;
  c9_ag_x = c9_theta_4;
  c9_bg_x = c9_ag_x;
  c9_bg_x = muDoubleScalarSin(c9_bg_x);
  c9_cg_x = c9_theta_1;
  c9_dg_x = c9_cg_x;
  c9_dg_x = muDoubleScalarCos(c9_dg_x);
  c9_eg_x = c9_theta_2;
  c9_fg_x = c9_eg_x;
  c9_fg_x = muDoubleScalarSin(c9_fg_x);
  c9_sb_a = c9_dg_x;
  c9_fc_b = c9_fg_x;
  c9_qc_y = c9_sb_a * c9_fc_b;
  c9_gg_x = c9_theta_3;
  c9_hg_x = c9_gg_x;
  c9_hg_x = muDoubleScalarSin(c9_hg_x);
  c9_tb_a = c9_qc_y;
  c9_gc_b = c9_hg_x;
  c9_rc_y = c9_tb_a * c9_gc_b;
  c9_ig_x = c9_theta_1;
  c9_jg_x = c9_ig_x;
  c9_jg_x = muDoubleScalarCos(c9_jg_x);
  c9_kg_x = c9_theta_2;
  c9_lg_x = c9_kg_x;
  c9_lg_x = muDoubleScalarCos(c9_lg_x);
  c9_ub_a = c9_jg_x;
  c9_hc_b = c9_lg_x;
  c9_sc_y = c9_ub_a * c9_hc_b;
  c9_mg_x = c9_theta_3;
  c9_ng_x = c9_mg_x;
  c9_ng_x = muDoubleScalarCos(c9_ng_x);
  c9_vb_a = c9_sc_y;
  c9_ic_b = c9_ng_x;
  c9_tc_y = c9_vb_a * c9_ic_b;
  c9_wb_a = c9_bg_x;
  c9_jc_b = c9_rc_y - c9_tc_y;
  c9_uc_y = c9_wb_a * c9_jc_b;
  c9_xb_a = c9_kc_y;
  c9_kc_b = c9_pc_y - c9_uc_y;
  c9_vc_y = c9_xb_a * c9_kc_b;
  c9_l_A = c9_vc_y;
  c9_og_x = c9_l_A;
  c9_pg_x = c9_og_x;
  c9_wc_y = c9_pg_x / 500.0;
  c9_qg_x = c9_theta_1;
  c9_rg_x = c9_qg_x;
  c9_rg_x = muDoubleScalarCos(c9_rg_x);
  c9_lc_b = c9_rg_x;
  c9_xc_y = 39243.0 * c9_lc_b;
  c9_sg_x = c9_theta_2;
  c9_tg_x = c9_sg_x;
  c9_tg_x = muDoubleScalarCos(c9_tg_x);
  c9_yb_a = c9_xc_y;
  c9_mc_b = c9_tg_x;
  c9_yc_y = c9_yb_a * c9_mc_b;
  c9_ug_x = c9_theta_3;
  c9_vg_x = c9_ug_x;
  c9_vg_x = muDoubleScalarSin(c9_vg_x);
  c9_ac_a = c9_yc_y;
  c9_nc_b = c9_vg_x;
  c9_ad_y = c9_ac_a * c9_nc_b;
  c9_m_A = c9_ad_y;
  c9_wg_x = c9_m_A;
  c9_xg_x = c9_wg_x;
  c9_bd_y = c9_xg_x / 100000.0;
  c9_yg_x = c9_theta_1;
  c9_ah_x = c9_yg_x;
  c9_ah_x = muDoubleScalarCos(c9_ah_x);
  c9_oc_b = c9_ah_x;
  c9_cd_y = 39243.0 * c9_oc_b;
  c9_bh_x = c9_theta_3;
  c9_ch_x = c9_bh_x;
  c9_ch_x = muDoubleScalarCos(c9_ch_x);
  c9_bc_a = c9_cd_y;
  c9_pc_b = c9_ch_x;
  c9_dd_y = c9_bc_a * c9_pc_b;
  c9_dh_x = c9_theta_2;
  c9_eh_x = c9_dh_x;
  c9_eh_x = muDoubleScalarSin(c9_eh_x);
  c9_cc_a = c9_dd_y;
  c9_qc_b = c9_eh_x;
  c9_ed_y = c9_cc_a * c9_qc_b;
  c9_n_A = c9_ed_y;
  c9_fh_x = c9_n_A;
  c9_gh_x = c9_fh_x;
  c9_fd_y = c9_gh_x / 100000.0;
  c9_hh_x = c9_theta_5;
  c9_ih_x = c9_hh_x;
  c9_ih_x = muDoubleScalarSin(c9_ih_x);
  c9_rc_b = c9_ih_x;
  c9_gd_y = 41.0 * c9_rc_b;
  c9_jh_x = c9_theta_4;
  c9_kh_x = c9_jh_x;
  c9_kh_x = muDoubleScalarCos(c9_kh_x);
  c9_lh_x = c9_theta_1;
  c9_mh_x = c9_lh_x;
  c9_mh_x = muDoubleScalarCos(c9_mh_x);
  c9_nh_x = c9_theta_2;
  c9_oh_x = c9_nh_x;
  c9_oh_x = muDoubleScalarCos(c9_oh_x);
  c9_dc_a = c9_mh_x;
  c9_sc_b = c9_oh_x;
  c9_hd_y = c9_dc_a * c9_sc_b;
  c9_ph_x = c9_theta_3;
  c9_qh_x = c9_ph_x;
  c9_qh_x = muDoubleScalarSin(c9_qh_x);
  c9_ec_a = c9_hd_y;
  c9_tc_b = c9_qh_x;
  c9_id_y = c9_ec_a * c9_tc_b;
  c9_rh_x = c9_theta_1;
  c9_sh_x = c9_rh_x;
  c9_sh_x = muDoubleScalarCos(c9_sh_x);
  c9_th_x = c9_theta_3;
  c9_uh_x = c9_th_x;
  c9_uh_x = muDoubleScalarCos(c9_uh_x);
  c9_fc_a = c9_sh_x;
  c9_uc_b = c9_uh_x;
  c9_jd_y = c9_fc_a * c9_uc_b;
  c9_vh_x = c9_theta_2;
  c9_wh_x = c9_vh_x;
  c9_wh_x = muDoubleScalarSin(c9_wh_x);
  c9_gc_a = c9_jd_y;
  c9_vc_b = c9_wh_x;
  c9_kd_y = c9_gc_a * c9_vc_b;
  c9_hc_a = c9_kh_x;
  c9_wc_b = c9_id_y + c9_kd_y;
  c9_ld_y = c9_hc_a * c9_wc_b;
  c9_xh_x = c9_theta_4;
  c9_yh_x = c9_xh_x;
  c9_yh_x = muDoubleScalarSin(c9_yh_x);
  c9_ai_x = c9_theta_1;
  c9_bi_x = c9_ai_x;
  c9_bi_x = muDoubleScalarCos(c9_bi_x);
  c9_ci_x = c9_theta_2;
  c9_di_x = c9_ci_x;
  c9_di_x = muDoubleScalarSin(c9_di_x);
  c9_ic_a = c9_bi_x;
  c9_xc_b = c9_di_x;
  c9_md_y = c9_ic_a * c9_xc_b;
  c9_ei_x = c9_theta_3;
  c9_fi_x = c9_ei_x;
  c9_fi_x = muDoubleScalarSin(c9_fi_x);
  c9_jc_a = c9_md_y;
  c9_yc_b = c9_fi_x;
  c9_nd_y = c9_jc_a * c9_yc_b;
  c9_gi_x = c9_theta_1;
  c9_hi_x = c9_gi_x;
  c9_hi_x = muDoubleScalarCos(c9_hi_x);
  c9_ii_x = c9_theta_2;
  c9_ji_x = c9_ii_x;
  c9_ji_x = muDoubleScalarCos(c9_ji_x);
  c9_kc_a = c9_hi_x;
  c9_ad_b = c9_ji_x;
  c9_od_y = c9_kc_a * c9_ad_b;
  c9_ki_x = c9_theta_3;
  c9_li_x = c9_ki_x;
  c9_li_x = muDoubleScalarCos(c9_li_x);
  c9_lc_a = c9_od_y;
  c9_bd_b = c9_li_x;
  c9_pd_y = c9_lc_a * c9_bd_b;
  c9_mc_a = c9_yh_x;
  c9_cd_b = c9_nd_y - c9_pd_y;
  c9_qd_y = c9_mc_a * c9_cd_b;
  c9_nc_a = c9_gd_y;
  c9_dd_b = c9_ld_y - c9_qd_y;
  c9_rd_y = c9_nc_a * c9_dd_b;
  c9_o_A = c9_rd_y;
  c9_mi_x = c9_o_A;
  c9_ni_x = c9_mi_x;
  c9_sd_y = c9_ni_x / 500.0;
  c9_oi_x = c9_theta_4;
  c9_pi_x = c9_oi_x;
  c9_pi_x = muDoubleScalarSin(c9_pi_x);
  c9_ed_b = c9_pi_x;
  c9_td_y = 93.0 * c9_ed_b;
  c9_qi_x = c9_theta_1;
  c9_ri_x = c9_qi_x;
  c9_ri_x = muDoubleScalarCos(c9_ri_x);
  c9_si_x = c9_theta_2;
  c9_ti_x = c9_si_x;
  c9_ti_x = muDoubleScalarCos(c9_ti_x);
  c9_oc_a = c9_ri_x;
  c9_fd_b = c9_ti_x;
  c9_ud_y = c9_oc_a * c9_fd_b;
  c9_ui_x = c9_theta_3;
  c9_vi_x = c9_ui_x;
  c9_vi_x = muDoubleScalarSin(c9_vi_x);
  c9_pc_a = c9_ud_y;
  c9_gd_b = c9_vi_x;
  c9_vd_y = c9_pc_a * c9_gd_b;
  c9_wi_x = c9_theta_1;
  c9_xi_x = c9_wi_x;
  c9_xi_x = muDoubleScalarCos(c9_xi_x);
  c9_yi_x = c9_theta_3;
  c9_aj_x = c9_yi_x;
  c9_aj_x = muDoubleScalarCos(c9_aj_x);
  c9_qc_a = c9_xi_x;
  c9_hd_b = c9_aj_x;
  c9_wd_y = c9_qc_a * c9_hd_b;
  c9_bj_x = c9_theta_2;
  c9_cj_x = c9_bj_x;
  c9_cj_x = muDoubleScalarSin(c9_cj_x);
  c9_rc_a = c9_wd_y;
  c9_id_b = c9_cj_x;
  c9_xd_y = c9_rc_a * c9_id_b;
  c9_sc_a = c9_td_y;
  c9_jd_b = c9_vd_y + c9_xd_y;
  c9_yd_y = c9_sc_a * c9_jd_b;
  c9_p_A = c9_yd_y;
  c9_dj_x = c9_p_A;
  c9_ej_x = c9_dj_x;
  c9_ae_y = c9_ej_x / 1000.0;
  c9_fj_x = c9_theta_4;
  c9_gj_x = c9_fj_x;
  c9_gj_x = muDoubleScalarCos(c9_gj_x);
  c9_kd_b = c9_gj_x;
  c9_be_y = 93.0 * c9_kd_b;
  c9_hj_x = c9_theta_1;
  c9_ij_x = c9_hj_x;
  c9_ij_x = muDoubleScalarCos(c9_ij_x);
  c9_jj_x = c9_theta_2;
  c9_kj_x = c9_jj_x;
  c9_kj_x = muDoubleScalarSin(c9_kj_x);
  c9_tc_a = c9_ij_x;
  c9_ld_b = c9_kj_x;
  c9_ce_y = c9_tc_a * c9_ld_b;
  c9_lj_x = c9_theta_3;
  c9_mj_x = c9_lj_x;
  c9_mj_x = muDoubleScalarSin(c9_mj_x);
  c9_uc_a = c9_ce_y;
  c9_md_b = c9_mj_x;
  c9_de_y = c9_uc_a * c9_md_b;
  c9_nj_x = c9_theta_1;
  c9_oj_x = c9_nj_x;
  c9_oj_x = muDoubleScalarCos(c9_oj_x);
  c9_pj_x = c9_theta_2;
  c9_qj_x = c9_pj_x;
  c9_qj_x = muDoubleScalarCos(c9_qj_x);
  c9_vc_a = c9_oj_x;
  c9_nd_b = c9_qj_x;
  c9_ee_y = c9_vc_a * c9_nd_b;
  c9_rj_x = c9_theta_3;
  c9_sj_x = c9_rj_x;
  c9_sj_x = muDoubleScalarCos(c9_sj_x);
  c9_wc_a = c9_ee_y;
  c9_od_b = c9_sj_x;
  c9_fe_y = c9_wc_a * c9_od_b;
  c9_xc_a = c9_be_y;
  c9_pd_b = c9_de_y - c9_fe_y;
  c9_ge_y = c9_xc_a * c9_pd_b;
  c9_q_A = c9_ge_y;
  c9_tj_x = c9_q_A;
  c9_uj_x = c9_tj_x;
  c9_he_y = c9_uj_x / 1000.0;
  c9_vj_x = c9_theta_1;
  c9_wj_x = c9_vj_x;
  c9_wj_x = muDoubleScalarCos(c9_wj_x);
  c9_qd_b = c9_wj_x;
  c9_ie_y = 39243.0 * c9_qd_b;
  c9_xj_x = c9_theta_2;
  c9_yj_x = c9_xj_x;
  c9_yj_x = muDoubleScalarCos(c9_yj_x);
  c9_yc_a = c9_ie_y;
  c9_rd_b = c9_yj_x;
  c9_je_y = c9_yc_a * c9_rd_b;
  c9_ak_x = c9_theta_3;
  c9_bk_x = c9_ak_x;
  c9_bk_x = muDoubleScalarSin(c9_bk_x);
  c9_ad_a = c9_je_y;
  c9_sd_b = c9_bk_x;
  c9_ke_y = c9_ad_a * c9_sd_b;
  c9_r_A = c9_ke_y;
  c9_ck_x = c9_r_A;
  c9_dk_x = c9_ck_x;
  c9_le_y = c9_dk_x / 100000.0;
  c9_ek_x = c9_theta_1;
  c9_fk_x = c9_ek_x;
  c9_fk_x = muDoubleScalarCos(c9_fk_x);
  c9_td_b = c9_fk_x;
  c9_me_y = 39243.0 * c9_td_b;
  c9_gk_x = c9_theta_3;
  c9_hk_x = c9_gk_x;
  c9_hk_x = muDoubleScalarCos(c9_hk_x);
  c9_bd_a = c9_me_y;
  c9_ud_b = c9_hk_x;
  c9_ne_y = c9_bd_a * c9_ud_b;
  c9_ik_x = c9_theta_2;
  c9_jk_x = c9_ik_x;
  c9_jk_x = muDoubleScalarSin(c9_jk_x);
  c9_cd_a = c9_ne_y;
  c9_vd_b = c9_jk_x;
  c9_oe_y = c9_cd_a * c9_vd_b;
  c9_s_A = c9_oe_y;
  c9_kk_x = c9_s_A;
  c9_lk_x = c9_kk_x;
  c9_pe_y = c9_lk_x / 100000.0;
  c9_mk_x = c9_theta_5;
  c9_nk_x = c9_mk_x;
  c9_nk_x = muDoubleScalarSin(c9_nk_x);
  c9_wd_b = c9_nk_x;
  c9_qe_y = 41.0 * c9_wd_b;
  c9_ok_x = c9_theta_4;
  c9_pk_x = c9_ok_x;
  c9_pk_x = muDoubleScalarCos(c9_pk_x);
  c9_qk_x = c9_theta_1;
  c9_rk_x = c9_qk_x;
  c9_rk_x = muDoubleScalarCos(c9_rk_x);
  c9_sk_x = c9_theta_2;
  c9_tk_x = c9_sk_x;
  c9_tk_x = muDoubleScalarCos(c9_tk_x);
  c9_dd_a = c9_rk_x;
  c9_xd_b = c9_tk_x;
  c9_re_y = c9_dd_a * c9_xd_b;
  c9_uk_x = c9_theta_3;
  c9_vk_x = c9_uk_x;
  c9_vk_x = muDoubleScalarSin(c9_vk_x);
  c9_ed_a = c9_re_y;
  c9_yd_b = c9_vk_x;
  c9_se_y = c9_ed_a * c9_yd_b;
  c9_wk_x = c9_theta_1;
  c9_xk_x = c9_wk_x;
  c9_xk_x = muDoubleScalarCos(c9_xk_x);
  c9_yk_x = c9_theta_3;
  c9_al_x = c9_yk_x;
  c9_al_x = muDoubleScalarCos(c9_al_x);
  c9_fd_a = c9_xk_x;
  c9_ae_b = c9_al_x;
  c9_te_y = c9_fd_a * c9_ae_b;
  c9_bl_x = c9_theta_2;
  c9_cl_x = c9_bl_x;
  c9_cl_x = muDoubleScalarSin(c9_cl_x);
  c9_gd_a = c9_te_y;
  c9_be_b = c9_cl_x;
  c9_ue_y = c9_gd_a * c9_be_b;
  c9_hd_a = c9_pk_x;
  c9_ce_b = c9_se_y + c9_ue_y;
  c9_ve_y = c9_hd_a * c9_ce_b;
  c9_dl_x = c9_theta_4;
  c9_el_x = c9_dl_x;
  c9_el_x = muDoubleScalarSin(c9_el_x);
  c9_fl_x = c9_theta_1;
  c9_gl_x = c9_fl_x;
  c9_gl_x = muDoubleScalarCos(c9_gl_x);
  c9_hl_x = c9_theta_2;
  c9_il_x = c9_hl_x;
  c9_il_x = muDoubleScalarSin(c9_il_x);
  c9_id_a = c9_gl_x;
  c9_de_b = c9_il_x;
  c9_we_y = c9_id_a * c9_de_b;
  c9_jl_x = c9_theta_3;
  c9_kl_x = c9_jl_x;
  c9_kl_x = muDoubleScalarSin(c9_kl_x);
  c9_jd_a = c9_we_y;
  c9_ee_b = c9_kl_x;
  c9_xe_y = c9_jd_a * c9_ee_b;
  c9_ll_x = c9_theta_1;
  c9_ml_x = c9_ll_x;
  c9_ml_x = muDoubleScalarCos(c9_ml_x);
  c9_nl_x = c9_theta_2;
  c9_ol_x = c9_nl_x;
  c9_ol_x = muDoubleScalarCos(c9_ol_x);
  c9_kd_a = c9_ml_x;
  c9_fe_b = c9_ol_x;
  c9_ye_y = c9_kd_a * c9_fe_b;
  c9_pl_x = c9_theta_3;
  c9_ql_x = c9_pl_x;
  c9_ql_x = muDoubleScalarCos(c9_ql_x);
  c9_ld_a = c9_ye_y;
  c9_ge_b = c9_ql_x;
  c9_af_y = c9_ld_a * c9_ge_b;
  c9_md_a = c9_el_x;
  c9_he_b = c9_xe_y - c9_af_y;
  c9_bf_y = c9_md_a * c9_he_b;
  c9_nd_a = c9_qe_y;
  c9_ie_b = c9_ve_y - c9_bf_y;
  c9_cf_y = c9_nd_a * c9_ie_b;
  c9_t_A = c9_cf_y;
  c9_rl_x = c9_t_A;
  c9_sl_x = c9_rl_x;
  c9_df_y = c9_sl_x / 500.0;
  c9_tl_x = c9_theta_4;
  c9_ul_x = c9_tl_x;
  c9_ul_x = muDoubleScalarSin(c9_ul_x);
  c9_je_b = c9_ul_x;
  c9_ef_y = 93.0 * c9_je_b;
  c9_vl_x = c9_theta_1;
  c9_wl_x = c9_vl_x;
  c9_wl_x = muDoubleScalarCos(c9_wl_x);
  c9_xl_x = c9_theta_2;
  c9_yl_x = c9_xl_x;
  c9_yl_x = muDoubleScalarCos(c9_yl_x);
  c9_od_a = c9_wl_x;
  c9_ke_b = c9_yl_x;
  c9_ff_y = c9_od_a * c9_ke_b;
  c9_am_x = c9_theta_3;
  c9_bm_x = c9_am_x;
  c9_bm_x = muDoubleScalarSin(c9_bm_x);
  c9_pd_a = c9_ff_y;
  c9_le_b = c9_bm_x;
  c9_gf_y = c9_pd_a * c9_le_b;
  c9_cm_x = c9_theta_1;
  c9_dm_x = c9_cm_x;
  c9_dm_x = muDoubleScalarCos(c9_dm_x);
  c9_em_x = c9_theta_3;
  c9_fm_x = c9_em_x;
  c9_fm_x = muDoubleScalarCos(c9_fm_x);
  c9_qd_a = c9_dm_x;
  c9_me_b = c9_fm_x;
  c9_hf_y = c9_qd_a * c9_me_b;
  c9_gm_x = c9_theta_2;
  c9_hm_x = c9_gm_x;
  c9_hm_x = muDoubleScalarSin(c9_hm_x);
  c9_rd_a = c9_hf_y;
  c9_ne_b = c9_hm_x;
  c9_if_y = c9_rd_a * c9_ne_b;
  c9_sd_a = c9_ef_y;
  c9_oe_b = c9_gf_y + c9_if_y;
  c9_jf_y = c9_sd_a * c9_oe_b;
  c9_u_A = c9_jf_y;
  c9_im_x = c9_u_A;
  c9_jm_x = c9_im_x;
  c9_kf_y = c9_jm_x / 1000.0;
  c9_km_x = c9_theta_4;
  c9_lm_x = c9_km_x;
  c9_lm_x = muDoubleScalarCos(c9_lm_x);
  c9_pe_b = c9_lm_x;
  c9_lf_y = 93.0 * c9_pe_b;
  c9_mm_x = c9_theta_1;
  c9_nm_x = c9_mm_x;
  c9_nm_x = muDoubleScalarCos(c9_nm_x);
  c9_om_x = c9_theta_2;
  c9_pm_x = c9_om_x;
  c9_pm_x = muDoubleScalarSin(c9_pm_x);
  c9_td_a = c9_nm_x;
  c9_qe_b = c9_pm_x;
  c9_mf_y = c9_td_a * c9_qe_b;
  c9_qm_x = c9_theta_3;
  c9_rm_x = c9_qm_x;
  c9_rm_x = muDoubleScalarSin(c9_rm_x);
  c9_ud_a = c9_mf_y;
  c9_re_b = c9_rm_x;
  c9_nf_y = c9_ud_a * c9_re_b;
  c9_sm_x = c9_theta_1;
  c9_tm_x = c9_sm_x;
  c9_tm_x = muDoubleScalarCos(c9_tm_x);
  c9_um_x = c9_theta_2;
  c9_vm_x = c9_um_x;
  c9_vm_x = muDoubleScalarCos(c9_vm_x);
  c9_vd_a = c9_tm_x;
  c9_se_b = c9_vm_x;
  c9_of_y = c9_vd_a * c9_se_b;
  c9_wm_x = c9_theta_3;
  c9_xm_x = c9_wm_x;
  c9_xm_x = muDoubleScalarCos(c9_xm_x);
  c9_wd_a = c9_of_y;
  c9_te_b = c9_xm_x;
  c9_pf_y = c9_wd_a * c9_te_b;
  c9_xd_a = c9_lf_y;
  c9_ue_b = c9_nf_y - c9_pf_y;
  c9_qf_y = c9_xd_a * c9_ue_b;
  c9_v_A = c9_qf_y;
  c9_ym_x = c9_v_A;
  c9_an_x = c9_ym_x;
  c9_rf_y = c9_an_x / 1000.0;
  c9_bn_x = c9_theta_5;
  c9_cn_x = c9_bn_x;
  c9_cn_x = muDoubleScalarCos(c9_cn_x);
  c9_ve_b = c9_cn_x;
  c9_sf_y = 41.0 * c9_ve_b;
  c9_dn_x = c9_theta_4;
  c9_en_x = c9_dn_x;
  c9_en_x = muDoubleScalarCos(c9_en_x);
  c9_fn_x = c9_theta_1;
  c9_gn_x = c9_fn_x;
  c9_gn_x = muDoubleScalarCos(c9_gn_x);
  c9_hn_x = c9_theta_2;
  c9_in_x = c9_hn_x;
  c9_in_x = muDoubleScalarSin(c9_in_x);
  c9_yd_a = c9_gn_x;
  c9_we_b = c9_in_x;
  c9_tf_y = c9_yd_a * c9_we_b;
  c9_jn_x = c9_theta_3;
  c9_kn_x = c9_jn_x;
  c9_kn_x = muDoubleScalarSin(c9_kn_x);
  c9_ae_a = c9_tf_y;
  c9_xe_b = c9_kn_x;
  c9_uf_y = c9_ae_a * c9_xe_b;
  c9_ln_x = c9_theta_1;
  c9_mn_x = c9_ln_x;
  c9_mn_x = muDoubleScalarCos(c9_mn_x);
  c9_nn_x = c9_theta_2;
  c9_on_x = c9_nn_x;
  c9_on_x = muDoubleScalarCos(c9_on_x);
  c9_be_a = c9_mn_x;
  c9_ye_b = c9_on_x;
  c9_vf_y = c9_be_a * c9_ye_b;
  c9_pn_x = c9_theta_3;
  c9_qn_x = c9_pn_x;
  c9_qn_x = muDoubleScalarCos(c9_qn_x);
  c9_ce_a = c9_vf_y;
  c9_af_b = c9_qn_x;
  c9_wf_y = c9_ce_a * c9_af_b;
  c9_de_a = c9_en_x;
  c9_bf_b = c9_uf_y - c9_wf_y;
  c9_xf_y = c9_de_a * c9_bf_b;
  c9_rn_x = c9_theta_4;
  c9_sn_x = c9_rn_x;
  c9_sn_x = muDoubleScalarSin(c9_sn_x);
  c9_tn_x = c9_theta_1;
  c9_un_x = c9_tn_x;
  c9_un_x = muDoubleScalarCos(c9_un_x);
  c9_vn_x = c9_theta_2;
  c9_wn_x = c9_vn_x;
  c9_wn_x = muDoubleScalarCos(c9_wn_x);
  c9_ee_a = c9_un_x;
  c9_cf_b = c9_wn_x;
  c9_yf_y = c9_ee_a * c9_cf_b;
  c9_xn_x = c9_theta_3;
  c9_yn_x = c9_xn_x;
  c9_yn_x = muDoubleScalarSin(c9_yn_x);
  c9_fe_a = c9_yf_y;
  c9_df_b = c9_yn_x;
  c9_ag_y = c9_fe_a * c9_df_b;
  c9_ao_x = c9_theta_1;
  c9_bo_x = c9_ao_x;
  c9_bo_x = muDoubleScalarCos(c9_bo_x);
  c9_co_x = c9_theta_3;
  c9_do_x = c9_co_x;
  c9_do_x = muDoubleScalarCos(c9_do_x);
  c9_ge_a = c9_bo_x;
  c9_ef_b = c9_do_x;
  c9_bg_y = c9_ge_a * c9_ef_b;
  c9_eo_x = c9_theta_2;
  c9_fo_x = c9_eo_x;
  c9_fo_x = muDoubleScalarSin(c9_fo_x);
  c9_he_a = c9_bg_y;
  c9_ff_b = c9_fo_x;
  c9_cg_y = c9_he_a * c9_ff_b;
  c9_ie_a = c9_sn_x;
  c9_gf_b = c9_ag_y + c9_cg_y;
  c9_dg_y = c9_ie_a * c9_gf_b;
  c9_je_a = c9_sf_y;
  c9_hf_b = c9_xf_y + c9_dg_y;
  c9_eg_y = c9_je_a * c9_hf_b;
  c9_w_A = c9_eg_y;
  c9_go_x = c9_w_A;
  c9_ho_x = c9_go_x;
  c9_fg_y = c9_ho_x / 500.0;
  c9_io_x = c9_theta_1;
  c9_jo_x = c9_io_x;
  c9_jo_x = muDoubleScalarSin(c9_jo_x);
  c9_if_b = c9_jo_x;
  c9_gg_y = 41.0 * c9_if_b;
  c9_ko_x = c9_theta_5;
  c9_lo_x = c9_ko_x;
  c9_lo_x = muDoubleScalarSin(c9_lo_x);
  c9_ke_a = c9_gg_y;
  c9_jf_b = c9_lo_x;
  c9_hg_y = c9_ke_a * c9_jf_b;
  c9_x_A = c9_hg_y;
  c9_mo_x = c9_x_A;
  c9_no_x = c9_mo_x;
  c9_ig_y = c9_no_x / 500.0;
  c9_oo_x = c9_theta_1;
  c9_po_x = c9_oo_x;
  c9_po_x = muDoubleScalarSin(c9_po_x);
  c9_kf_b = c9_po_x;
  c9_jg_y = 109.0 * c9_kf_b;
  c9_y_A = c9_jg_y;
  c9_qo_x = c9_y_A;
  c9_ro_x = c9_qo_x;
  c9_kg_y = c9_ro_x / 1000.0;
  c9_so_x = c9_theta_1;
  c9_to_x = c9_so_x;
  c9_to_x = muDoubleScalarCos(c9_to_x);
  c9_lf_b = c9_to_x;
  c9_lg_y = 17.0 * c9_lf_b;
  c9_uo_x = c9_theta_2;
  c9_vo_x = c9_uo_x;
  c9_vo_x = muDoubleScalarCos(c9_vo_x);
  c9_le_a = c9_lg_y;
  c9_mf_b = c9_vo_x;
  c9_mg_y = c9_le_a * c9_mf_b;
  c9_ab_A = c9_mg_y;
  c9_wo_x = c9_ab_A;
  c9_xo_x = c9_wo_x;
  c9_ng_y = c9_xo_x / 40.0;
  c9_yo_x = c9_theta_5;
  c9_ap_x = c9_yo_x;
  c9_ap_x = muDoubleScalarCos(c9_ap_x);
  c9_nf_b = c9_ap_x;
  c9_og_y = 41.0 * c9_nf_b;
  c9_bp_x = c9_theta_1;
  c9_cp_x = c9_bp_x;
  c9_cp_x = muDoubleScalarSin(c9_cp_x);
  c9_me_a = c9_og_y;
  c9_of_b = c9_cp_x;
  c9_pg_y = c9_me_a * c9_of_b;
  c9_bb_A = c9_pg_y;
  c9_dp_x = c9_bb_A;
  c9_ep_x = c9_dp_x;
  c9_qg_y = c9_ep_x / 500.0;
  c9_fp_x = c9_theta_4;
  c9_gp_x = c9_fp_x;
  c9_gp_x = muDoubleScalarCos(c9_gp_x);
  c9_pf_b = c9_gp_x;
  c9_rg_y = 93.0 * c9_pf_b;
  c9_hp_x = c9_theta_1;
  c9_ip_x = c9_hp_x;
  c9_ip_x = muDoubleScalarCos(c9_ip_x);
  c9_jp_x = c9_theta_2;
  c9_kp_x = c9_jp_x;
  c9_kp_x = muDoubleScalarCos(c9_kp_x);
  c9_ne_a = c9_ip_x;
  c9_qf_b = c9_kp_x;
  c9_sg_y = c9_ne_a * c9_qf_b;
  c9_lp_x = c9_theta_3;
  c9_mp_x = c9_lp_x;
  c9_mp_x = muDoubleScalarSin(c9_mp_x);
  c9_oe_a = c9_sg_y;
  c9_rf_b = c9_mp_x;
  c9_tg_y = c9_oe_a * c9_rf_b;
  c9_np_x = c9_theta_1;
  c9_op_x = c9_np_x;
  c9_op_x = muDoubleScalarCos(c9_op_x);
  c9_pp_x = c9_theta_3;
  c9_qp_x = c9_pp_x;
  c9_qp_x = muDoubleScalarCos(c9_qp_x);
  c9_pe_a = c9_op_x;
  c9_sf_b = c9_qp_x;
  c9_ug_y = c9_pe_a * c9_sf_b;
  c9_rp_x = c9_theta_2;
  c9_sp_x = c9_rp_x;
  c9_sp_x = muDoubleScalarSin(c9_sp_x);
  c9_qe_a = c9_ug_y;
  c9_tf_b = c9_sp_x;
  c9_vg_y = c9_qe_a * c9_tf_b;
  c9_re_a = c9_rg_y;
  c9_uf_b = c9_tg_y + c9_vg_y;
  c9_wg_y = c9_re_a * c9_uf_b;
  c9_cb_A = c9_wg_y;
  c9_tp_x = c9_cb_A;
  c9_up_x = c9_tp_x;
  c9_xg_y = c9_up_x / 1000.0;
  c9_vp_x = c9_theta_4;
  c9_wp_x = c9_vp_x;
  c9_wp_x = muDoubleScalarSin(c9_wp_x);
  c9_vf_b = c9_wp_x;
  c9_yg_y = 93.0 * c9_vf_b;
  c9_xp_x = c9_theta_1;
  c9_yp_x = c9_xp_x;
  c9_yp_x = muDoubleScalarCos(c9_yp_x);
  c9_aq_x = c9_theta_2;
  c9_bq_x = c9_aq_x;
  c9_bq_x = muDoubleScalarSin(c9_bq_x);
  c9_se_a = c9_yp_x;
  c9_wf_b = c9_bq_x;
  c9_ah_y = c9_se_a * c9_wf_b;
  c9_cq_x = c9_theta_3;
  c9_dq_x = c9_cq_x;
  c9_dq_x = muDoubleScalarSin(c9_dq_x);
  c9_te_a = c9_ah_y;
  c9_xf_b = c9_dq_x;
  c9_bh_y = c9_te_a * c9_xf_b;
  c9_eq_x = c9_theta_1;
  c9_fq_x = c9_eq_x;
  c9_fq_x = muDoubleScalarCos(c9_fq_x);
  c9_gq_x = c9_theta_2;
  c9_hq_x = c9_gq_x;
  c9_hq_x = muDoubleScalarCos(c9_hq_x);
  c9_ue_a = c9_fq_x;
  c9_yf_b = c9_hq_x;
  c9_ch_y = c9_ue_a * c9_yf_b;
  c9_iq_x = c9_theta_3;
  c9_jq_x = c9_iq_x;
  c9_jq_x = muDoubleScalarCos(c9_jq_x);
  c9_ve_a = c9_ch_y;
  c9_ag_b = c9_jq_x;
  c9_dh_y = c9_ve_a * c9_ag_b;
  c9_we_a = c9_yg_y;
  c9_bg_b = c9_bh_y - c9_dh_y;
  c9_eh_y = c9_we_a * c9_bg_b;
  c9_db_A = c9_eh_y;
  c9_kq_x = c9_db_A;
  c9_lq_x = c9_kq_x;
  c9_fh_y = c9_lq_x / 1000.0;
  c9_mq_x = c9_theta_5;
  c9_nq_x = c9_mq_x;
  c9_nq_x = muDoubleScalarSin(c9_nq_x);
  c9_cg_b = c9_nq_x;
  c9_gh_y = 41.0 * c9_cg_b;
  c9_oq_x = c9_theta_4;
  c9_pq_x = c9_oq_x;
  c9_pq_x = muDoubleScalarCos(c9_pq_x);
  c9_qq_x = c9_theta_1;
  c9_rq_x = c9_qq_x;
  c9_rq_x = muDoubleScalarCos(c9_rq_x);
  c9_sq_x = c9_theta_2;
  c9_tq_x = c9_sq_x;
  c9_tq_x = muDoubleScalarSin(c9_tq_x);
  c9_xe_a = c9_rq_x;
  c9_dg_b = c9_tq_x;
  c9_hh_y = c9_xe_a * c9_dg_b;
  c9_uq_x = c9_theta_3;
  c9_vq_x = c9_uq_x;
  c9_vq_x = muDoubleScalarSin(c9_vq_x);
  c9_ye_a = c9_hh_y;
  c9_eg_b = c9_vq_x;
  c9_ih_y = c9_ye_a * c9_eg_b;
  c9_wq_x = c9_theta_1;
  c9_xq_x = c9_wq_x;
  c9_xq_x = muDoubleScalarCos(c9_xq_x);
  c9_yq_x = c9_theta_2;
  c9_ar_x = c9_yq_x;
  c9_ar_x = muDoubleScalarCos(c9_ar_x);
  c9_af_a = c9_xq_x;
  c9_fg_b = c9_ar_x;
  c9_jh_y = c9_af_a * c9_fg_b;
  c9_br_x = c9_theta_3;
  c9_cr_x = c9_br_x;
  c9_cr_x = muDoubleScalarCos(c9_cr_x);
  c9_bf_a = c9_jh_y;
  c9_gg_b = c9_cr_x;
  c9_kh_y = c9_bf_a * c9_gg_b;
  c9_cf_a = c9_pq_x;
  c9_hg_b = c9_ih_y - c9_kh_y;
  c9_lh_y = c9_cf_a * c9_hg_b;
  c9_dr_x = c9_theta_4;
  c9_er_x = c9_dr_x;
  c9_er_x = muDoubleScalarSin(c9_er_x);
  c9_fr_x = c9_theta_1;
  c9_gr_x = c9_fr_x;
  c9_gr_x = muDoubleScalarCos(c9_gr_x);
  c9_hr_x = c9_theta_2;
  c9_ir_x = c9_hr_x;
  c9_ir_x = muDoubleScalarCos(c9_ir_x);
  c9_df_a = c9_gr_x;
  c9_ig_b = c9_ir_x;
  c9_mh_y = c9_df_a * c9_ig_b;
  c9_jr_x = c9_theta_3;
  c9_kr_x = c9_jr_x;
  c9_kr_x = muDoubleScalarSin(c9_kr_x);
  c9_ef_a = c9_mh_y;
  c9_jg_b = c9_kr_x;
  c9_nh_y = c9_ef_a * c9_jg_b;
  c9_lr_x = c9_theta_1;
  c9_mr_x = c9_lr_x;
  c9_mr_x = muDoubleScalarCos(c9_mr_x);
  c9_nr_x = c9_theta_3;
  c9_or_x = c9_nr_x;
  c9_or_x = muDoubleScalarCos(c9_or_x);
  c9_ff_a = c9_mr_x;
  c9_kg_b = c9_or_x;
  c9_oh_y = c9_ff_a * c9_kg_b;
  c9_pr_x = c9_theta_2;
  c9_qr_x = c9_pr_x;
  c9_qr_x = muDoubleScalarSin(c9_qr_x);
  c9_gf_a = c9_oh_y;
  c9_lg_b = c9_qr_x;
  c9_ph_y = c9_gf_a * c9_lg_b;
  c9_hf_a = c9_er_x;
  c9_mg_b = c9_nh_y + c9_ph_y;
  c9_qh_y = c9_hf_a * c9_mg_b;
  c9_if_a = c9_gh_y;
  c9_ng_b = c9_lh_y + c9_qh_y;
  c9_rh_y = c9_if_a * c9_ng_b;
  c9_eb_A = c9_rh_y;
  c9_rr_x = c9_eb_A;
  c9_sr_x = c9_rr_x;
  c9_sh_y = c9_sr_x / 500.0;
  c9_tr_x = c9_theta_1;
  c9_ur_x = c9_tr_x;
  c9_ur_x = muDoubleScalarCos(c9_ur_x);
  c9_og_b = c9_ur_x;
  c9_th_y = 39243.0 * c9_og_b;
  c9_vr_x = c9_theta_2;
  c9_wr_x = c9_vr_x;
  c9_wr_x = muDoubleScalarSin(c9_wr_x);
  c9_jf_a = c9_th_y;
  c9_pg_b = c9_wr_x;
  c9_uh_y = c9_jf_a * c9_pg_b;
  c9_xr_x = c9_theta_3;
  c9_yr_x = c9_xr_x;
  c9_yr_x = muDoubleScalarSin(c9_yr_x);
  c9_kf_a = c9_uh_y;
  c9_qg_b = c9_yr_x;
  c9_vh_y = c9_kf_a * c9_qg_b;
  c9_fb_A = c9_vh_y;
  c9_as_x = c9_fb_A;
  c9_bs_x = c9_as_x;
  c9_wh_y = c9_bs_x / 100000.0;
  c9_cs_x = c9_theta_1;
  c9_ds_x = c9_cs_x;
  c9_ds_x = muDoubleScalarCos(c9_ds_x);
  c9_rg_b = c9_ds_x;
  c9_xh_y = 39243.0 * c9_rg_b;
  c9_es_x = c9_theta_2;
  c9_fs_x = c9_es_x;
  c9_fs_x = muDoubleScalarCos(c9_fs_x);
  c9_lf_a = c9_xh_y;
  c9_sg_b = c9_fs_x;
  c9_yh_y = c9_lf_a * c9_sg_b;
  c9_gs_x = c9_theta_3;
  c9_hs_x = c9_gs_x;
  c9_hs_x = muDoubleScalarCos(c9_hs_x);
  c9_mf_a = c9_yh_y;
  c9_tg_b = c9_hs_x;
  c9_ai_y = c9_mf_a * c9_tg_b;
  c9_gb_A = c9_ai_y;
  c9_is_x = c9_gb_A;
  c9_js_x = c9_is_x;
  c9_bi_y = c9_js_x / 100000.0;
  c9_ks_x = c9_theta_1;
  c9_ls_x = c9_ks_x;
  c9_ls_x = muDoubleScalarSin(c9_ls_x);
  c9_ug_b = c9_ls_x;
  c9_ci_y = 17.0 * c9_ug_b;
  c9_ms_x = c9_theta_2;
  c9_ns_x = c9_ms_x;
  c9_ns_x = muDoubleScalarSin(c9_ns_x);
  c9_nf_a = c9_ci_y;
  c9_vg_b = c9_ns_x;
  c9_di_y = c9_nf_a * c9_vg_b;
  c9_hb_A = c9_di_y;
  c9_os_x = c9_hb_A;
  c9_ps_x = c9_os_x;
  c9_ei_y = c9_ps_x / 40.0;
  c9_qs_x = c9_theta_4;
  c9_rs_x = c9_qs_x;
  c9_rs_x = muDoubleScalarCos(c9_rs_x);
  c9_wg_b = c9_rs_x;
  c9_fi_y = 93.0 * c9_wg_b;
  c9_ss_x = c9_theta_1;
  c9_ts_x = c9_ss_x;
  c9_ts_x = muDoubleScalarSin(c9_ts_x);
  c9_us_x = c9_theta_2;
  c9_vs_x = c9_us_x;
  c9_vs_x = muDoubleScalarSin(c9_vs_x);
  c9_of_a = c9_ts_x;
  c9_xg_b = c9_vs_x;
  c9_gi_y = c9_of_a * c9_xg_b;
  c9_ws_x = c9_theta_3;
  c9_xs_x = c9_ws_x;
  c9_xs_x = muDoubleScalarSin(c9_xs_x);
  c9_pf_a = c9_gi_y;
  c9_yg_b = c9_xs_x;
  c9_hi_y = c9_pf_a * c9_yg_b;
  c9_ys_x = c9_theta_2;
  c9_at_x = c9_ys_x;
  c9_at_x = muDoubleScalarCos(c9_at_x);
  c9_bt_x = c9_theta_3;
  c9_ct_x = c9_bt_x;
  c9_ct_x = muDoubleScalarCos(c9_ct_x);
  c9_qf_a = c9_at_x;
  c9_ah_b = c9_ct_x;
  c9_ii_y = c9_qf_a * c9_ah_b;
  c9_dt_x = c9_theta_1;
  c9_et_x = c9_dt_x;
  c9_et_x = muDoubleScalarSin(c9_et_x);
  c9_rf_a = c9_ii_y;
  c9_bh_b = c9_et_x;
  c9_ji_y = c9_rf_a * c9_bh_b;
  c9_sf_a = c9_fi_y;
  c9_ch_b = c9_hi_y - c9_ji_y;
  c9_ki_y = c9_sf_a * c9_ch_b;
  c9_ib_A = c9_ki_y;
  c9_ft_x = c9_ib_A;
  c9_gt_x = c9_ft_x;
  c9_li_y = c9_gt_x / 1000.0;
  c9_ht_x = c9_theta_4;
  c9_it_x = c9_ht_x;
  c9_it_x = muDoubleScalarSin(c9_it_x);
  c9_dh_b = c9_it_x;
  c9_mi_y = 93.0 * c9_dh_b;
  c9_jt_x = c9_theta_2;
  c9_kt_x = c9_jt_x;
  c9_kt_x = muDoubleScalarCos(c9_kt_x);
  c9_lt_x = c9_theta_1;
  c9_mt_x = c9_lt_x;
  c9_mt_x = muDoubleScalarSin(c9_mt_x);
  c9_tf_a = c9_kt_x;
  c9_eh_b = c9_mt_x;
  c9_ni_y = c9_tf_a * c9_eh_b;
  c9_nt_x = c9_theta_3;
  c9_ot_x = c9_nt_x;
  c9_ot_x = muDoubleScalarSin(c9_ot_x);
  c9_uf_a = c9_ni_y;
  c9_fh_b = c9_ot_x;
  c9_oi_y = c9_uf_a * c9_fh_b;
  c9_pt_x = c9_theta_3;
  c9_qt_x = c9_pt_x;
  c9_qt_x = muDoubleScalarCos(c9_qt_x);
  c9_rt_x = c9_theta_1;
  c9_st_x = c9_rt_x;
  c9_st_x = muDoubleScalarSin(c9_st_x);
  c9_vf_a = c9_qt_x;
  c9_gh_b = c9_st_x;
  c9_pi_y = c9_vf_a * c9_gh_b;
  c9_tt_x = c9_theta_2;
  c9_ut_x = c9_tt_x;
  c9_ut_x = muDoubleScalarSin(c9_ut_x);
  c9_wf_a = c9_pi_y;
  c9_hh_b = c9_ut_x;
  c9_qi_y = c9_wf_a * c9_hh_b;
  c9_xf_a = c9_mi_y;
  c9_ih_b = c9_oi_y + c9_qi_y;
  c9_ri_y = c9_xf_a * c9_ih_b;
  c9_jb_A = c9_ri_y;
  c9_vt_x = c9_jb_A;
  c9_wt_x = c9_vt_x;
  c9_si_y = c9_wt_x / 1000.0;
  c9_xt_x = c9_theta_5;
  c9_yt_x = c9_xt_x;
  c9_yt_x = muDoubleScalarSin(c9_yt_x);
  c9_jh_b = c9_yt_x;
  c9_ti_y = 41.0 * c9_jh_b;
  c9_au_x = c9_theta_4;
  c9_bu_x = c9_au_x;
  c9_bu_x = muDoubleScalarCos(c9_bu_x);
  c9_cu_x = c9_theta_2;
  c9_du_x = c9_cu_x;
  c9_du_x = muDoubleScalarCos(c9_du_x);
  c9_eu_x = c9_theta_1;
  c9_fu_x = c9_eu_x;
  c9_fu_x = muDoubleScalarSin(c9_fu_x);
  c9_yf_a = c9_du_x;
  c9_kh_b = c9_fu_x;
  c9_ui_y = c9_yf_a * c9_kh_b;
  c9_gu_x = c9_theta_3;
  c9_hu_x = c9_gu_x;
  c9_hu_x = muDoubleScalarSin(c9_hu_x);
  c9_ag_a = c9_ui_y;
  c9_lh_b = c9_hu_x;
  c9_vi_y = c9_ag_a * c9_lh_b;
  c9_iu_x = c9_theta_3;
  c9_ju_x = c9_iu_x;
  c9_ju_x = muDoubleScalarCos(c9_ju_x);
  c9_ku_x = c9_theta_1;
  c9_lu_x = c9_ku_x;
  c9_lu_x = muDoubleScalarSin(c9_lu_x);
  c9_bg_a = c9_ju_x;
  c9_mh_b = c9_lu_x;
  c9_wi_y = c9_bg_a * c9_mh_b;
  c9_mu_x = c9_theta_2;
  c9_nu_x = c9_mu_x;
  c9_nu_x = muDoubleScalarSin(c9_nu_x);
  c9_cg_a = c9_wi_y;
  c9_nh_b = c9_nu_x;
  c9_xi_y = c9_cg_a * c9_nh_b;
  c9_dg_a = c9_bu_x;
  c9_oh_b = c9_vi_y + c9_xi_y;
  c9_yi_y = c9_dg_a * c9_oh_b;
  c9_ou_x = c9_theta_4;
  c9_pu_x = c9_ou_x;
  c9_pu_x = muDoubleScalarSin(c9_pu_x);
  c9_qu_x = c9_theta_1;
  c9_ru_x = c9_qu_x;
  c9_ru_x = muDoubleScalarSin(c9_ru_x);
  c9_su_x = c9_theta_2;
  c9_tu_x = c9_su_x;
  c9_tu_x = muDoubleScalarSin(c9_tu_x);
  c9_eg_a = c9_ru_x;
  c9_ph_b = c9_tu_x;
  c9_aj_y = c9_eg_a * c9_ph_b;
  c9_uu_x = c9_theta_3;
  c9_vu_x = c9_uu_x;
  c9_vu_x = muDoubleScalarSin(c9_vu_x);
  c9_fg_a = c9_aj_y;
  c9_qh_b = c9_vu_x;
  c9_bj_y = c9_fg_a * c9_qh_b;
  c9_wu_x = c9_theta_2;
  c9_xu_x = c9_wu_x;
  c9_xu_x = muDoubleScalarCos(c9_xu_x);
  c9_yu_x = c9_theta_3;
  c9_av_x = c9_yu_x;
  c9_av_x = muDoubleScalarCos(c9_av_x);
  c9_gg_a = c9_xu_x;
  c9_rh_b = c9_av_x;
  c9_cj_y = c9_gg_a * c9_rh_b;
  c9_bv_x = c9_theta_1;
  c9_cv_x = c9_bv_x;
  c9_cv_x = muDoubleScalarSin(c9_cv_x);
  c9_hg_a = c9_cj_y;
  c9_sh_b = c9_cv_x;
  c9_dj_y = c9_hg_a * c9_sh_b;
  c9_ig_a = c9_pu_x;
  c9_th_b = c9_bj_y - c9_dj_y;
  c9_ej_y = c9_ig_a * c9_th_b;
  c9_jg_a = c9_ti_y;
  c9_uh_b = c9_yi_y - c9_ej_y;
  c9_fj_y = c9_jg_a * c9_uh_b;
  c9_kb_A = c9_fj_y;
  c9_dv_x = c9_kb_A;
  c9_ev_x = c9_dv_x;
  c9_gj_y = c9_ev_x / 500.0;
  c9_fv_x = c9_theta_2;
  c9_gv_x = c9_fv_x;
  c9_gv_x = muDoubleScalarCos(c9_gv_x);
  c9_vh_b = c9_gv_x;
  c9_hj_y = 39243.0 * c9_vh_b;
  c9_hv_x = c9_theta_1;
  c9_iv_x = c9_hv_x;
  c9_iv_x = muDoubleScalarSin(c9_iv_x);
  c9_kg_a = c9_hj_y;
  c9_wh_b = c9_iv_x;
  c9_ij_y = c9_kg_a * c9_wh_b;
  c9_jv_x = c9_theta_3;
  c9_kv_x = c9_jv_x;
  c9_kv_x = muDoubleScalarSin(c9_kv_x);
  c9_lg_a = c9_ij_y;
  c9_xh_b = c9_kv_x;
  c9_jj_y = c9_lg_a * c9_xh_b;
  c9_lb_A = c9_jj_y;
  c9_lv_x = c9_lb_A;
  c9_mv_x = c9_lv_x;
  c9_kj_y = c9_mv_x / 100000.0;
  c9_nv_x = c9_theta_3;
  c9_ov_x = c9_nv_x;
  c9_ov_x = muDoubleScalarCos(c9_ov_x);
  c9_yh_b = c9_ov_x;
  c9_lj_y = 39243.0 * c9_yh_b;
  c9_pv_x = c9_theta_1;
  c9_qv_x = c9_pv_x;
  c9_qv_x = muDoubleScalarSin(c9_qv_x);
  c9_mg_a = c9_lj_y;
  c9_ai_b = c9_qv_x;
  c9_mj_y = c9_mg_a * c9_ai_b;
  c9_rv_x = c9_theta_2;
  c9_sv_x = c9_rv_x;
  c9_sv_x = muDoubleScalarSin(c9_sv_x);
  c9_ng_a = c9_mj_y;
  c9_bi_b = c9_sv_x;
  c9_nj_y = c9_ng_a * c9_bi_b;
  c9_mb_A = c9_nj_y;
  c9_tv_x = c9_mb_A;
  c9_uv_x = c9_tv_x;
  c9_oj_y = c9_uv_x / 100000.0;
  c9_vv_x = c9_theta_5;
  c9_wv_x = c9_vv_x;
  c9_wv_x = muDoubleScalarSin(c9_wv_x);
  c9_ci_b = c9_wv_x;
  c9_pj_y = 41.0 * c9_ci_b;
  c9_xv_x = c9_theta_4;
  c9_yv_x = c9_xv_x;
  c9_yv_x = muDoubleScalarCos(c9_yv_x);
  c9_aw_x = c9_theta_2;
  c9_bw_x = c9_aw_x;
  c9_bw_x = muDoubleScalarCos(c9_bw_x);
  c9_cw_x = c9_theta_1;
  c9_dw_x = c9_cw_x;
  c9_dw_x = muDoubleScalarSin(c9_dw_x);
  c9_og_a = c9_bw_x;
  c9_di_b = c9_dw_x;
  c9_qj_y = c9_og_a * c9_di_b;
  c9_ew_x = c9_theta_3;
  c9_fw_x = c9_ew_x;
  c9_fw_x = muDoubleScalarSin(c9_fw_x);
  c9_pg_a = c9_qj_y;
  c9_ei_b = c9_fw_x;
  c9_rj_y = c9_pg_a * c9_ei_b;
  c9_gw_x = c9_theta_3;
  c9_hw_x = c9_gw_x;
  c9_hw_x = muDoubleScalarCos(c9_hw_x);
  c9_iw_x = c9_theta_1;
  c9_jw_x = c9_iw_x;
  c9_jw_x = muDoubleScalarSin(c9_jw_x);
  c9_qg_a = c9_hw_x;
  c9_fi_b = c9_jw_x;
  c9_sj_y = c9_qg_a * c9_fi_b;
  c9_kw_x = c9_theta_2;
  c9_lw_x = c9_kw_x;
  c9_lw_x = muDoubleScalarSin(c9_lw_x);
  c9_rg_a = c9_sj_y;
  c9_gi_b = c9_lw_x;
  c9_tj_y = c9_rg_a * c9_gi_b;
  c9_sg_a = c9_yv_x;
  c9_hi_b = c9_rj_y + c9_tj_y;
  c9_uj_y = c9_sg_a * c9_hi_b;
  c9_mw_x = c9_theta_4;
  c9_nw_x = c9_mw_x;
  c9_nw_x = muDoubleScalarSin(c9_nw_x);
  c9_ow_x = c9_theta_1;
  c9_pw_x = c9_ow_x;
  c9_pw_x = muDoubleScalarSin(c9_pw_x);
  c9_qw_x = c9_theta_2;
  c9_rw_x = c9_qw_x;
  c9_rw_x = muDoubleScalarSin(c9_rw_x);
  c9_tg_a = c9_pw_x;
  c9_ii_b = c9_rw_x;
  c9_vj_y = c9_tg_a * c9_ii_b;
  c9_sw_x = c9_theta_3;
  c9_tw_x = c9_sw_x;
  c9_tw_x = muDoubleScalarSin(c9_tw_x);
  c9_ug_a = c9_vj_y;
  c9_ji_b = c9_tw_x;
  c9_wj_y = c9_ug_a * c9_ji_b;
  c9_uw_x = c9_theta_2;
  c9_vw_x = c9_uw_x;
  c9_vw_x = muDoubleScalarCos(c9_vw_x);
  c9_ww_x = c9_theta_3;
  c9_xw_x = c9_ww_x;
  c9_xw_x = muDoubleScalarCos(c9_xw_x);
  c9_vg_a = c9_vw_x;
  c9_ki_b = c9_xw_x;
  c9_xj_y = c9_vg_a * c9_ki_b;
  c9_yw_x = c9_theta_1;
  c9_ax_x = c9_yw_x;
  c9_ax_x = muDoubleScalarSin(c9_ax_x);
  c9_wg_a = c9_xj_y;
  c9_li_b = c9_ax_x;
  c9_yj_y = c9_wg_a * c9_li_b;
  c9_xg_a = c9_nw_x;
  c9_mi_b = c9_wj_y - c9_yj_y;
  c9_ak_y = c9_xg_a * c9_mi_b;
  c9_yg_a = c9_pj_y;
  c9_ni_b = c9_uj_y - c9_ak_y;
  c9_bk_y = c9_yg_a * c9_ni_b;
  c9_nb_A = c9_bk_y;
  c9_bx_x = c9_nb_A;
  c9_cx_x = c9_bx_x;
  c9_ck_y = c9_cx_x / 500.0;
  c9_dx_x = c9_theta_4;
  c9_ex_x = c9_dx_x;
  c9_ex_x = muDoubleScalarSin(c9_ex_x);
  c9_oi_b = c9_ex_x;
  c9_dk_y = 93.0 * c9_oi_b;
  c9_fx_x = c9_theta_2;
  c9_gx_x = c9_fx_x;
  c9_gx_x = muDoubleScalarCos(c9_gx_x);
  c9_hx_x = c9_theta_1;
  c9_ix_x = c9_hx_x;
  c9_ix_x = muDoubleScalarSin(c9_ix_x);
  c9_ah_a = c9_gx_x;
  c9_pi_b = c9_ix_x;
  c9_ek_y = c9_ah_a * c9_pi_b;
  c9_jx_x = c9_theta_3;
  c9_kx_x = c9_jx_x;
  c9_kx_x = muDoubleScalarSin(c9_kx_x);
  c9_bh_a = c9_ek_y;
  c9_qi_b = c9_kx_x;
  c9_fk_y = c9_bh_a * c9_qi_b;
  c9_lx_x = c9_theta_3;
  c9_mx_x = c9_lx_x;
  c9_mx_x = muDoubleScalarCos(c9_mx_x);
  c9_nx_x = c9_theta_1;
  c9_ox_x = c9_nx_x;
  c9_ox_x = muDoubleScalarSin(c9_ox_x);
  c9_ch_a = c9_mx_x;
  c9_ri_b = c9_ox_x;
  c9_gk_y = c9_ch_a * c9_ri_b;
  c9_px_x = c9_theta_2;
  c9_qx_x = c9_px_x;
  c9_qx_x = muDoubleScalarSin(c9_qx_x);
  c9_dh_a = c9_gk_y;
  c9_si_b = c9_qx_x;
  c9_hk_y = c9_dh_a * c9_si_b;
  c9_eh_a = c9_dk_y;
  c9_ti_b = c9_fk_y + c9_hk_y;
  c9_ik_y = c9_eh_a * c9_ti_b;
  c9_ob_A = c9_ik_y;
  c9_rx_x = c9_ob_A;
  c9_sx_x = c9_rx_x;
  c9_jk_y = c9_sx_x / 1000.0;
  c9_tx_x = c9_theta_4;
  c9_ux_x = c9_tx_x;
  c9_ux_x = muDoubleScalarCos(c9_ux_x);
  c9_ui_b = c9_ux_x;
  c9_kk_y = 93.0 * c9_ui_b;
  c9_vx_x = c9_theta_1;
  c9_wx_x = c9_vx_x;
  c9_wx_x = muDoubleScalarSin(c9_wx_x);
  c9_xx_x = c9_theta_2;
  c9_yx_x = c9_xx_x;
  c9_yx_x = muDoubleScalarSin(c9_yx_x);
  c9_fh_a = c9_wx_x;
  c9_vi_b = c9_yx_x;
  c9_lk_y = c9_fh_a * c9_vi_b;
  c9_ay_x = c9_theta_3;
  c9_by_x = c9_ay_x;
  c9_by_x = muDoubleScalarSin(c9_by_x);
  c9_gh_a = c9_lk_y;
  c9_wi_b = c9_by_x;
  c9_mk_y = c9_gh_a * c9_wi_b;
  c9_cy_x = c9_theta_2;
  c9_dy_x = c9_cy_x;
  c9_dy_x = muDoubleScalarCos(c9_dy_x);
  c9_ey_x = c9_theta_3;
  c9_fy_x = c9_ey_x;
  c9_fy_x = muDoubleScalarCos(c9_fy_x);
  c9_hh_a = c9_dy_x;
  c9_xi_b = c9_fy_x;
  c9_nk_y = c9_hh_a * c9_xi_b;
  c9_gy_x = c9_theta_1;
  c9_hy_x = c9_gy_x;
  c9_hy_x = muDoubleScalarSin(c9_hy_x);
  c9_ih_a = c9_nk_y;
  c9_yi_b = c9_hy_x;
  c9_ok_y = c9_ih_a * c9_yi_b;
  c9_jh_a = c9_kk_y;
  c9_aj_b = c9_mk_y - c9_ok_y;
  c9_pk_y = c9_jh_a * c9_aj_b;
  c9_pb_A = c9_pk_y;
  c9_iy_x = c9_pb_A;
  c9_jy_x = c9_iy_x;
  c9_qk_y = c9_jy_x / 1000.0;
  c9_ky_x = c9_theta_2;
  c9_ly_x = c9_ky_x;
  c9_ly_x = muDoubleScalarCos(c9_ly_x);
  c9_bj_b = c9_ly_x;
  c9_rk_y = 39243.0 * c9_bj_b;
  c9_my_x = c9_theta_1;
  c9_ny_x = c9_my_x;
  c9_ny_x = muDoubleScalarSin(c9_ny_x);
  c9_kh_a = c9_rk_y;
  c9_cj_b = c9_ny_x;
  c9_sk_y = c9_kh_a * c9_cj_b;
  c9_oy_x = c9_theta_3;
  c9_py_x = c9_oy_x;
  c9_py_x = muDoubleScalarSin(c9_py_x);
  c9_lh_a = c9_sk_y;
  c9_dj_b = c9_py_x;
  c9_tk_y = c9_lh_a * c9_dj_b;
  c9_qb_A = c9_tk_y;
  c9_qy_x = c9_qb_A;
  c9_ry_x = c9_qy_x;
  c9_uk_y = c9_ry_x / 100000.0;
  c9_sy_x = c9_theta_3;
  c9_ty_x = c9_sy_x;
  c9_ty_x = muDoubleScalarCos(c9_ty_x);
  c9_ej_b = c9_ty_x;
  c9_vk_y = 39243.0 * c9_ej_b;
  c9_uy_x = c9_theta_1;
  c9_vy_x = c9_uy_x;
  c9_vy_x = muDoubleScalarSin(c9_vy_x);
  c9_mh_a = c9_vk_y;
  c9_fj_b = c9_vy_x;
  c9_wk_y = c9_mh_a * c9_fj_b;
  c9_wy_x = c9_theta_2;
  c9_xy_x = c9_wy_x;
  c9_xy_x = muDoubleScalarSin(c9_xy_x);
  c9_nh_a = c9_wk_y;
  c9_gj_b = c9_xy_x;
  c9_xk_y = c9_nh_a * c9_gj_b;
  c9_rb_A = c9_xk_y;
  c9_yy_x = c9_rb_A;
  c9_aab_x = c9_yy_x;
  c9_yk_y = c9_aab_x / 100000.0;
  c9_bab_x = c9_theta_5;
  c9_cab_x = c9_bab_x;
  c9_cab_x = muDoubleScalarSin(c9_cab_x);
  c9_hj_b = c9_cab_x;
  c9_al_y = 41.0 * c9_hj_b;
  c9_dab_x = c9_theta_4;
  c9_eab_x = c9_dab_x;
  c9_eab_x = muDoubleScalarCos(c9_eab_x);
  c9_fab_x = c9_theta_2;
  c9_gab_x = c9_fab_x;
  c9_gab_x = muDoubleScalarCos(c9_gab_x);
  c9_hab_x = c9_theta_1;
  c9_iab_x = c9_hab_x;
  c9_iab_x = muDoubleScalarSin(c9_iab_x);
  c9_oh_a = c9_gab_x;
  c9_ij_b = c9_iab_x;
  c9_bl_y = c9_oh_a * c9_ij_b;
  c9_jab_x = c9_theta_3;
  c9_kab_x = c9_jab_x;
  c9_kab_x = muDoubleScalarSin(c9_kab_x);
  c9_ph_a = c9_bl_y;
  c9_jj_b = c9_kab_x;
  c9_cl_y = c9_ph_a * c9_jj_b;
  c9_lab_x = c9_theta_3;
  c9_mab_x = c9_lab_x;
  c9_mab_x = muDoubleScalarCos(c9_mab_x);
  c9_nab_x = c9_theta_1;
  c9_oab_x = c9_nab_x;
  c9_oab_x = muDoubleScalarSin(c9_oab_x);
  c9_qh_a = c9_mab_x;
  c9_kj_b = c9_oab_x;
  c9_dl_y = c9_qh_a * c9_kj_b;
  c9_pab_x = c9_theta_2;
  c9_qab_x = c9_pab_x;
  c9_qab_x = muDoubleScalarSin(c9_qab_x);
  c9_rh_a = c9_dl_y;
  c9_lj_b = c9_qab_x;
  c9_el_y = c9_rh_a * c9_lj_b;
  c9_sh_a = c9_eab_x;
  c9_mj_b = c9_cl_y + c9_el_y;
  c9_fl_y = c9_sh_a * c9_mj_b;
  c9_rab_x = c9_theta_4;
  c9_sab_x = c9_rab_x;
  c9_sab_x = muDoubleScalarSin(c9_sab_x);
  c9_tab_x = c9_theta_1;
  c9_uab_x = c9_tab_x;
  c9_uab_x = muDoubleScalarSin(c9_uab_x);
  c9_vab_x = c9_theta_2;
  c9_wab_x = c9_vab_x;
  c9_wab_x = muDoubleScalarSin(c9_wab_x);
  c9_th_a = c9_uab_x;
  c9_nj_b = c9_wab_x;
  c9_gl_y = c9_th_a * c9_nj_b;
  c9_xab_x = c9_theta_3;
  c9_yab_x = c9_xab_x;
  c9_yab_x = muDoubleScalarSin(c9_yab_x);
  c9_uh_a = c9_gl_y;
  c9_oj_b = c9_yab_x;
  c9_hl_y = c9_uh_a * c9_oj_b;
  c9_abb_x = c9_theta_2;
  c9_bbb_x = c9_abb_x;
  c9_bbb_x = muDoubleScalarCos(c9_bbb_x);
  c9_cbb_x = c9_theta_3;
  c9_dbb_x = c9_cbb_x;
  c9_dbb_x = muDoubleScalarCos(c9_dbb_x);
  c9_vh_a = c9_bbb_x;
  c9_pj_b = c9_dbb_x;
  c9_il_y = c9_vh_a * c9_pj_b;
  c9_ebb_x = c9_theta_1;
  c9_fbb_x = c9_ebb_x;
  c9_fbb_x = muDoubleScalarSin(c9_fbb_x);
  c9_wh_a = c9_il_y;
  c9_qj_b = c9_fbb_x;
  c9_jl_y = c9_wh_a * c9_qj_b;
  c9_xh_a = c9_sab_x;
  c9_rj_b = c9_hl_y - c9_jl_y;
  c9_kl_y = c9_xh_a * c9_rj_b;
  c9_yh_a = c9_al_y;
  c9_sj_b = c9_fl_y - c9_kl_y;
  c9_ll_y = c9_yh_a * c9_sj_b;
  c9_sb_A = c9_ll_y;
  c9_gbb_x = c9_sb_A;
  c9_hbb_x = c9_gbb_x;
  c9_ml_y = c9_hbb_x / 500.0;
  c9_ibb_x = c9_theta_4;
  c9_jbb_x = c9_ibb_x;
  c9_jbb_x = muDoubleScalarSin(c9_jbb_x);
  c9_tj_b = c9_jbb_x;
  c9_nl_y = 93.0 * c9_tj_b;
  c9_kbb_x = c9_theta_2;
  c9_lbb_x = c9_kbb_x;
  c9_lbb_x = muDoubleScalarCos(c9_lbb_x);
  c9_mbb_x = c9_theta_1;
  c9_nbb_x = c9_mbb_x;
  c9_nbb_x = muDoubleScalarSin(c9_nbb_x);
  c9_ai_a = c9_lbb_x;
  c9_uj_b = c9_nbb_x;
  c9_ol_y = c9_ai_a * c9_uj_b;
  c9_obb_x = c9_theta_3;
  c9_pbb_x = c9_obb_x;
  c9_pbb_x = muDoubleScalarSin(c9_pbb_x);
  c9_bi_a = c9_ol_y;
  c9_vj_b = c9_pbb_x;
  c9_pl_y = c9_bi_a * c9_vj_b;
  c9_qbb_x = c9_theta_3;
  c9_rbb_x = c9_qbb_x;
  c9_rbb_x = muDoubleScalarCos(c9_rbb_x);
  c9_sbb_x = c9_theta_1;
  c9_tbb_x = c9_sbb_x;
  c9_tbb_x = muDoubleScalarSin(c9_tbb_x);
  c9_ci_a = c9_rbb_x;
  c9_wj_b = c9_tbb_x;
  c9_ql_y = c9_ci_a * c9_wj_b;
  c9_ubb_x = c9_theta_2;
  c9_vbb_x = c9_ubb_x;
  c9_vbb_x = muDoubleScalarSin(c9_vbb_x);
  c9_di_a = c9_ql_y;
  c9_xj_b = c9_vbb_x;
  c9_rl_y = c9_di_a * c9_xj_b;
  c9_ei_a = c9_nl_y;
  c9_yj_b = c9_pl_y + c9_rl_y;
  c9_sl_y = c9_ei_a * c9_yj_b;
  c9_tb_A = c9_sl_y;
  c9_wbb_x = c9_tb_A;
  c9_xbb_x = c9_wbb_x;
  c9_tl_y = c9_xbb_x / 1000.0;
  c9_ybb_x = c9_theta_4;
  c9_acb_x = c9_ybb_x;
  c9_acb_x = muDoubleScalarCos(c9_acb_x);
  c9_ak_b = c9_acb_x;
  c9_ul_y = 93.0 * c9_ak_b;
  c9_bcb_x = c9_theta_1;
  c9_ccb_x = c9_bcb_x;
  c9_ccb_x = muDoubleScalarSin(c9_ccb_x);
  c9_dcb_x = c9_theta_2;
  c9_ecb_x = c9_dcb_x;
  c9_ecb_x = muDoubleScalarSin(c9_ecb_x);
  c9_fi_a = c9_ccb_x;
  c9_bk_b = c9_ecb_x;
  c9_vl_y = c9_fi_a * c9_bk_b;
  c9_fcb_x = c9_theta_3;
  c9_gcb_x = c9_fcb_x;
  c9_gcb_x = muDoubleScalarSin(c9_gcb_x);
  c9_gi_a = c9_vl_y;
  c9_ck_b = c9_gcb_x;
  c9_wl_y = c9_gi_a * c9_ck_b;
  c9_hcb_x = c9_theta_2;
  c9_icb_x = c9_hcb_x;
  c9_icb_x = muDoubleScalarCos(c9_icb_x);
  c9_jcb_x = c9_theta_3;
  c9_kcb_x = c9_jcb_x;
  c9_kcb_x = muDoubleScalarCos(c9_kcb_x);
  c9_hi_a = c9_icb_x;
  c9_dk_b = c9_kcb_x;
  c9_xl_y = c9_hi_a * c9_dk_b;
  c9_lcb_x = c9_theta_1;
  c9_mcb_x = c9_lcb_x;
  c9_mcb_x = muDoubleScalarSin(c9_mcb_x);
  c9_ii_a = c9_xl_y;
  c9_ek_b = c9_mcb_x;
  c9_yl_y = c9_ii_a * c9_ek_b;
  c9_ji_a = c9_ul_y;
  c9_fk_b = c9_wl_y - c9_yl_y;
  c9_am_y = c9_ji_a * c9_fk_b;
  c9_ub_A = c9_am_y;
  c9_ncb_x = c9_ub_A;
  c9_ocb_x = c9_ncb_x;
  c9_bm_y = c9_ocb_x / 1000.0;
  c9_pcb_x = c9_theta_1;
  c9_qcb_x = c9_pcb_x;
  c9_qcb_x = muDoubleScalarCos(c9_qcb_x);
  c9_gk_b = c9_qcb_x;
  c9_cm_y = 41.0 * c9_gk_b;
  c9_rcb_x = c9_theta_5;
  c9_scb_x = c9_rcb_x;
  c9_scb_x = muDoubleScalarSin(c9_scb_x);
  c9_ki_a = c9_cm_y;
  c9_hk_b = c9_scb_x;
  c9_dm_y = c9_ki_a * c9_hk_b;
  c9_vb_A = c9_dm_y;
  c9_tcb_x = c9_vb_A;
  c9_ucb_x = c9_tcb_x;
  c9_em_y = c9_ucb_x / 500.0;
  c9_vcb_x = c9_theta_5;
  c9_wcb_x = c9_vcb_x;
  c9_wcb_x = muDoubleScalarCos(c9_wcb_x);
  c9_ik_b = c9_wcb_x;
  c9_fm_y = 41.0 * c9_ik_b;
  c9_xcb_x = c9_theta_4;
  c9_ycb_x = c9_xcb_x;
  c9_ycb_x = muDoubleScalarCos(c9_ycb_x);
  c9_adb_x = c9_theta_1;
  c9_bdb_x = c9_adb_x;
  c9_bdb_x = muDoubleScalarSin(c9_bdb_x);
  c9_cdb_x = c9_theta_2;
  c9_ddb_x = c9_cdb_x;
  c9_ddb_x = muDoubleScalarSin(c9_ddb_x);
  c9_li_a = c9_bdb_x;
  c9_jk_b = c9_ddb_x;
  c9_gm_y = c9_li_a * c9_jk_b;
  c9_edb_x = c9_theta_3;
  c9_fdb_x = c9_edb_x;
  c9_fdb_x = muDoubleScalarSin(c9_fdb_x);
  c9_mi_a = c9_gm_y;
  c9_kk_b = c9_fdb_x;
  c9_hm_y = c9_mi_a * c9_kk_b;
  c9_gdb_x = c9_theta_2;
  c9_hdb_x = c9_gdb_x;
  c9_hdb_x = muDoubleScalarCos(c9_hdb_x);
  c9_idb_x = c9_theta_3;
  c9_jdb_x = c9_idb_x;
  c9_jdb_x = muDoubleScalarCos(c9_jdb_x);
  c9_ni_a = c9_hdb_x;
  c9_lk_b = c9_jdb_x;
  c9_im_y = c9_ni_a * c9_lk_b;
  c9_kdb_x = c9_theta_1;
  c9_ldb_x = c9_kdb_x;
  c9_ldb_x = muDoubleScalarSin(c9_ldb_x);
  c9_oi_a = c9_im_y;
  c9_mk_b = c9_ldb_x;
  c9_jm_y = c9_oi_a * c9_mk_b;
  c9_pi_a = c9_ycb_x;
  c9_nk_b = c9_hm_y - c9_jm_y;
  c9_km_y = c9_pi_a * c9_nk_b;
  c9_mdb_x = c9_theta_4;
  c9_ndb_x = c9_mdb_x;
  c9_ndb_x = muDoubleScalarSin(c9_ndb_x);
  c9_odb_x = c9_theta_2;
  c9_pdb_x = c9_odb_x;
  c9_pdb_x = muDoubleScalarCos(c9_pdb_x);
  c9_qdb_x = c9_theta_1;
  c9_rdb_x = c9_qdb_x;
  c9_rdb_x = muDoubleScalarSin(c9_rdb_x);
  c9_qi_a = c9_pdb_x;
  c9_ok_b = c9_rdb_x;
  c9_lm_y = c9_qi_a * c9_ok_b;
  c9_sdb_x = c9_theta_3;
  c9_tdb_x = c9_sdb_x;
  c9_tdb_x = muDoubleScalarSin(c9_tdb_x);
  c9_ri_a = c9_lm_y;
  c9_pk_b = c9_tdb_x;
  c9_mm_y = c9_ri_a * c9_pk_b;
  c9_udb_x = c9_theta_3;
  c9_vdb_x = c9_udb_x;
  c9_vdb_x = muDoubleScalarCos(c9_vdb_x);
  c9_wdb_x = c9_theta_1;
  c9_xdb_x = c9_wdb_x;
  c9_xdb_x = muDoubleScalarSin(c9_xdb_x);
  c9_si_a = c9_vdb_x;
  c9_qk_b = c9_xdb_x;
  c9_nm_y = c9_si_a * c9_qk_b;
  c9_ydb_x = c9_theta_2;
  c9_aeb_x = c9_ydb_x;
  c9_aeb_x = muDoubleScalarSin(c9_aeb_x);
  c9_ti_a = c9_nm_y;
  c9_rk_b = c9_aeb_x;
  c9_om_y = c9_ti_a * c9_rk_b;
  c9_ui_a = c9_ndb_x;
  c9_sk_b = c9_mm_y + c9_om_y;
  c9_pm_y = c9_ui_a * c9_sk_b;
  c9_vi_a = c9_fm_y;
  c9_tk_b = c9_km_y + c9_pm_y;
  c9_qm_y = c9_vi_a * c9_tk_b;
  c9_wb_A = c9_qm_y;
  c9_beb_x = c9_wb_A;
  c9_ceb_x = c9_beb_x;
  c9_rm_y = c9_ceb_x / 500.0;
  c9_deb_x = c9_theta_2;
  c9_eeb_x = c9_deb_x;
  c9_eeb_x = muDoubleScalarSin(c9_eeb_x);
  c9_uk_b = c9_eeb_x;
  c9_sm_y = 39243.0 * c9_uk_b;
  c9_feb_x = c9_theta_3;
  c9_geb_x = c9_feb_x;
  c9_geb_x = muDoubleScalarSin(c9_geb_x);
  c9_wi_a = c9_sm_y;
  c9_vk_b = c9_geb_x;
  c9_tm_y = c9_wi_a * c9_vk_b;
  c9_xb_A = c9_tm_y;
  c9_heb_x = c9_xb_A;
  c9_ieb_x = c9_heb_x;
  c9_um_y = c9_ieb_x / 100000.0;
  c9_jeb_x = c9_theta_2;
  c9_keb_x = c9_jeb_x;
  c9_keb_x = muDoubleScalarCos(c9_keb_x);
  c9_wk_b = c9_keb_x;
  c9_vm_y = 39243.0 * c9_wk_b;
  c9_leb_x = c9_theta_3;
  c9_meb_x = c9_leb_x;
  c9_meb_x = muDoubleScalarCos(c9_meb_x);
  c9_xi_a = c9_vm_y;
  c9_xk_b = c9_meb_x;
  c9_wm_y = c9_xi_a * c9_xk_b;
  c9_yb_A = c9_wm_y;
  c9_neb_x = c9_yb_A;
  c9_oeb_x = c9_neb_x;
  c9_xm_y = c9_oeb_x / 100000.0;
  c9_peb_x = c9_theta_2;
  c9_qeb_x = c9_peb_x;
  c9_qeb_x = muDoubleScalarCos(c9_qeb_x);
  c9_yk_b = c9_qeb_x;
  c9_ym_y = 17.0 * c9_yk_b;
  c9_ac_A = c9_ym_y;
  c9_reb_x = c9_ac_A;
  c9_seb_x = c9_reb_x;
  c9_an_y = c9_seb_x / 40.0;
  c9_teb_x = c9_theta_5;
  c9_ueb_x = c9_teb_x;
  c9_ueb_x = muDoubleScalarSin(c9_ueb_x);
  c9_al_b = c9_ueb_x;
  c9_bn_y = 41.0 * c9_al_b;
  c9_veb_x = c9_theta_4;
  c9_web_x = c9_veb_x;
  c9_web_x = muDoubleScalarCos(c9_web_x);
  c9_xeb_x = c9_theta_2;
  c9_yeb_x = c9_xeb_x;
  c9_yeb_x = muDoubleScalarCos(c9_yeb_x);
  c9_afb_x = c9_theta_3;
  c9_bfb_x = c9_afb_x;
  c9_bfb_x = muDoubleScalarCos(c9_bfb_x);
  c9_yi_a = c9_yeb_x;
  c9_bl_b = c9_bfb_x;
  c9_cn_y = c9_yi_a * c9_bl_b;
  c9_cfb_x = c9_theta_2;
  c9_dfb_x = c9_cfb_x;
  c9_dfb_x = muDoubleScalarSin(c9_dfb_x);
  c9_efb_x = c9_theta_3;
  c9_ffb_x = c9_efb_x;
  c9_ffb_x = muDoubleScalarSin(c9_ffb_x);
  c9_aj_a = c9_dfb_x;
  c9_cl_b = c9_ffb_x;
  c9_dn_y = c9_aj_a * c9_cl_b;
  c9_bj_a = c9_web_x;
  c9_dl_b = c9_cn_y - c9_dn_y;
  c9_en_y = c9_bj_a * c9_dl_b;
  c9_gfb_x = c9_theta_4;
  c9_hfb_x = c9_gfb_x;
  c9_hfb_x = muDoubleScalarSin(c9_hfb_x);
  c9_ifb_x = c9_theta_2;
  c9_jfb_x = c9_ifb_x;
  c9_jfb_x = muDoubleScalarCos(c9_jfb_x);
  c9_kfb_x = c9_theta_3;
  c9_lfb_x = c9_kfb_x;
  c9_lfb_x = muDoubleScalarSin(c9_lfb_x);
  c9_cj_a = c9_jfb_x;
  c9_el_b = c9_lfb_x;
  c9_fn_y = c9_cj_a * c9_el_b;
  c9_mfb_x = c9_theta_3;
  c9_nfb_x = c9_mfb_x;
  c9_nfb_x = muDoubleScalarCos(c9_nfb_x);
  c9_ofb_x = c9_theta_2;
  c9_pfb_x = c9_ofb_x;
  c9_pfb_x = muDoubleScalarSin(c9_pfb_x);
  c9_dj_a = c9_nfb_x;
  c9_fl_b = c9_pfb_x;
  c9_gn_y = c9_dj_a * c9_fl_b;
  c9_ej_a = c9_hfb_x;
  c9_gl_b = c9_fn_y + c9_gn_y;
  c9_hn_y = c9_ej_a * c9_gl_b;
  c9_fj_a = c9_bn_y;
  c9_hl_b = c9_en_y - c9_hn_y;
  c9_in_y = c9_fj_a * c9_hl_b;
  c9_bc_A = c9_in_y;
  c9_qfb_x = c9_bc_A;
  c9_rfb_x = c9_qfb_x;
  c9_jn_y = c9_rfb_x / 500.0;
  c9_sfb_x = c9_theta_4;
  c9_tfb_x = c9_sfb_x;
  c9_tfb_x = muDoubleScalarCos(c9_tfb_x);
  c9_il_b = c9_tfb_x;
  c9_kn_y = 93.0 * c9_il_b;
  c9_ufb_x = c9_theta_2;
  c9_vfb_x = c9_ufb_x;
  c9_vfb_x = muDoubleScalarCos(c9_vfb_x);
  c9_wfb_x = c9_theta_3;
  c9_xfb_x = c9_wfb_x;
  c9_xfb_x = muDoubleScalarSin(c9_xfb_x);
  c9_gj_a = c9_vfb_x;
  c9_jl_b = c9_xfb_x;
  c9_ln_y = c9_gj_a * c9_jl_b;
  c9_yfb_x = c9_theta_3;
  c9_agb_x = c9_yfb_x;
  c9_agb_x = muDoubleScalarCos(c9_agb_x);
  c9_bgb_x = c9_theta_2;
  c9_cgb_x = c9_bgb_x;
  c9_cgb_x = muDoubleScalarSin(c9_cgb_x);
  c9_hj_a = c9_agb_x;
  c9_kl_b = c9_cgb_x;
  c9_mn_y = c9_hj_a * c9_kl_b;
  c9_ij_a = c9_kn_y;
  c9_ll_b = c9_ln_y + c9_mn_y;
  c9_nn_y = c9_ij_a * c9_ll_b;
  c9_cc_A = c9_nn_y;
  c9_dgb_x = c9_cc_A;
  c9_egb_x = c9_dgb_x;
  c9_on_y = c9_egb_x / 1000.0;
  c9_fgb_x = c9_theta_4;
  c9_ggb_x = c9_fgb_x;
  c9_ggb_x = muDoubleScalarSin(c9_ggb_x);
  c9_ml_b = c9_ggb_x;
  c9_pn_y = 93.0 * c9_ml_b;
  c9_hgb_x = c9_theta_2;
  c9_igb_x = c9_hgb_x;
  c9_igb_x = muDoubleScalarCos(c9_igb_x);
  c9_jgb_x = c9_theta_3;
  c9_kgb_x = c9_jgb_x;
  c9_kgb_x = muDoubleScalarCos(c9_kgb_x);
  c9_jj_a = c9_igb_x;
  c9_nl_b = c9_kgb_x;
  c9_qn_y = c9_jj_a * c9_nl_b;
  c9_lgb_x = c9_theta_2;
  c9_mgb_x = c9_lgb_x;
  c9_mgb_x = muDoubleScalarSin(c9_mgb_x);
  c9_ngb_x = c9_theta_3;
  c9_ogb_x = c9_ngb_x;
  c9_ogb_x = muDoubleScalarSin(c9_ogb_x);
  c9_kj_a = c9_mgb_x;
  c9_ol_b = c9_ogb_x;
  c9_rn_y = c9_kj_a * c9_ol_b;
  c9_lj_a = c9_pn_y;
  c9_pl_b = c9_qn_y - c9_rn_y;
  c9_sn_y = c9_lj_a * c9_pl_b;
  c9_dc_A = c9_sn_y;
  c9_pgb_x = c9_dc_A;
  c9_qgb_x = c9_pgb_x;
  c9_tn_y = c9_qgb_x / 1000.0;
  c9_rgb_x = c9_theta_2;
  c9_sgb_x = c9_rgb_x;
  c9_sgb_x = muDoubleScalarSin(c9_sgb_x);
  c9_ql_b = c9_sgb_x;
  c9_un_y = 39243.0 * c9_ql_b;
  c9_tgb_x = c9_theta_3;
  c9_ugb_x = c9_tgb_x;
  c9_ugb_x = muDoubleScalarSin(c9_ugb_x);
  c9_mj_a = c9_un_y;
  c9_rl_b = c9_ugb_x;
  c9_vn_y = c9_mj_a * c9_rl_b;
  c9_ec_A = c9_vn_y;
  c9_vgb_x = c9_ec_A;
  c9_wgb_x = c9_vgb_x;
  c9_wn_y = c9_wgb_x / 100000.0;
  c9_xgb_x = c9_theta_2;
  c9_ygb_x = c9_xgb_x;
  c9_ygb_x = muDoubleScalarCos(c9_ygb_x);
  c9_sl_b = c9_ygb_x;
  c9_xn_y = 39243.0 * c9_sl_b;
  c9_ahb_x = c9_theta_3;
  c9_bhb_x = c9_ahb_x;
  c9_bhb_x = muDoubleScalarCos(c9_bhb_x);
  c9_nj_a = c9_xn_y;
  c9_tl_b = c9_bhb_x;
  c9_yn_y = c9_nj_a * c9_tl_b;
  c9_fc_A = c9_yn_y;
  c9_chb_x = c9_fc_A;
  c9_dhb_x = c9_chb_x;
  c9_ao_y = c9_dhb_x / 100000.0;
  c9_ehb_x = c9_theta_5;
  c9_fhb_x = c9_ehb_x;
  c9_fhb_x = muDoubleScalarSin(c9_fhb_x);
  c9_ul_b = c9_fhb_x;
  c9_bo_y = 41.0 * c9_ul_b;
  c9_ghb_x = c9_theta_4;
  c9_hhb_x = c9_ghb_x;
  c9_hhb_x = muDoubleScalarCos(c9_hhb_x);
  c9_ihb_x = c9_theta_2;
  c9_jhb_x = c9_ihb_x;
  c9_jhb_x = muDoubleScalarCos(c9_jhb_x);
  c9_khb_x = c9_theta_3;
  c9_lhb_x = c9_khb_x;
  c9_lhb_x = muDoubleScalarCos(c9_lhb_x);
  c9_oj_a = c9_jhb_x;
  c9_vl_b = c9_lhb_x;
  c9_co_y = c9_oj_a * c9_vl_b;
  c9_mhb_x = c9_theta_2;
  c9_nhb_x = c9_mhb_x;
  c9_nhb_x = muDoubleScalarSin(c9_nhb_x);
  c9_ohb_x = c9_theta_3;
  c9_phb_x = c9_ohb_x;
  c9_phb_x = muDoubleScalarSin(c9_phb_x);
  c9_pj_a = c9_nhb_x;
  c9_wl_b = c9_phb_x;
  c9_do_y = c9_pj_a * c9_wl_b;
  c9_qj_a = c9_hhb_x;
  c9_xl_b = c9_co_y - c9_do_y;
  c9_eo_y = c9_qj_a * c9_xl_b;
  c9_qhb_x = c9_theta_4;
  c9_rhb_x = c9_qhb_x;
  c9_rhb_x = muDoubleScalarSin(c9_rhb_x);
  c9_shb_x = c9_theta_2;
  c9_thb_x = c9_shb_x;
  c9_thb_x = muDoubleScalarCos(c9_thb_x);
  c9_uhb_x = c9_theta_3;
  c9_vhb_x = c9_uhb_x;
  c9_vhb_x = muDoubleScalarSin(c9_vhb_x);
  c9_rj_a = c9_thb_x;
  c9_yl_b = c9_vhb_x;
  c9_fo_y = c9_rj_a * c9_yl_b;
  c9_whb_x = c9_theta_3;
  c9_xhb_x = c9_whb_x;
  c9_xhb_x = muDoubleScalarCos(c9_xhb_x);
  c9_yhb_x = c9_theta_2;
  c9_aib_x = c9_yhb_x;
  c9_aib_x = muDoubleScalarSin(c9_aib_x);
  c9_sj_a = c9_xhb_x;
  c9_am_b = c9_aib_x;
  c9_go_y = c9_sj_a * c9_am_b;
  c9_tj_a = c9_rhb_x;
  c9_bm_b = c9_fo_y + c9_go_y;
  c9_ho_y = c9_tj_a * c9_bm_b;
  c9_uj_a = c9_bo_y;
  c9_cm_b = c9_eo_y - c9_ho_y;
  c9_io_y = c9_uj_a * c9_cm_b;
  c9_gc_A = c9_io_y;
  c9_bib_x = c9_gc_A;
  c9_cib_x = c9_bib_x;
  c9_jo_y = c9_cib_x / 500.0;
  c9_dib_x = c9_theta_4;
  c9_eib_x = c9_dib_x;
  c9_eib_x = muDoubleScalarCos(c9_eib_x);
  c9_dm_b = c9_eib_x;
  c9_ko_y = 93.0 * c9_dm_b;
  c9_fib_x = c9_theta_2;
  c9_gib_x = c9_fib_x;
  c9_gib_x = muDoubleScalarCos(c9_gib_x);
  c9_hib_x = c9_theta_3;
  c9_iib_x = c9_hib_x;
  c9_iib_x = muDoubleScalarSin(c9_iib_x);
  c9_vj_a = c9_gib_x;
  c9_em_b = c9_iib_x;
  c9_lo_y = c9_vj_a * c9_em_b;
  c9_jib_x = c9_theta_3;
  c9_kib_x = c9_jib_x;
  c9_kib_x = muDoubleScalarCos(c9_kib_x);
  c9_lib_x = c9_theta_2;
  c9_mib_x = c9_lib_x;
  c9_mib_x = muDoubleScalarSin(c9_mib_x);
  c9_wj_a = c9_kib_x;
  c9_fm_b = c9_mib_x;
  c9_mo_y = c9_wj_a * c9_fm_b;
  c9_xj_a = c9_ko_y;
  c9_gm_b = c9_lo_y + c9_mo_y;
  c9_no_y = c9_xj_a * c9_gm_b;
  c9_hc_A = c9_no_y;
  c9_nib_x = c9_hc_A;
  c9_oib_x = c9_nib_x;
  c9_oo_y = c9_oib_x / 1000.0;
  c9_pib_x = c9_theta_4;
  c9_qib_x = c9_pib_x;
  c9_qib_x = muDoubleScalarSin(c9_qib_x);
  c9_hm_b = c9_qib_x;
  c9_po_y = 93.0 * c9_hm_b;
  c9_rib_x = c9_theta_2;
  c9_sib_x = c9_rib_x;
  c9_sib_x = muDoubleScalarCos(c9_sib_x);
  c9_tib_x = c9_theta_3;
  c9_uib_x = c9_tib_x;
  c9_uib_x = muDoubleScalarCos(c9_uib_x);
  c9_yj_a = c9_sib_x;
  c9_im_b = c9_uib_x;
  c9_qo_y = c9_yj_a * c9_im_b;
  c9_vib_x = c9_theta_2;
  c9_wib_x = c9_vib_x;
  c9_wib_x = muDoubleScalarSin(c9_wib_x);
  c9_xib_x = c9_theta_3;
  c9_yib_x = c9_xib_x;
  c9_yib_x = muDoubleScalarSin(c9_yib_x);
  c9_ak_a = c9_wib_x;
  c9_jm_b = c9_yib_x;
  c9_ro_y = c9_ak_a * c9_jm_b;
  c9_bk_a = c9_po_y;
  c9_km_b = c9_qo_y - c9_ro_y;
  c9_so_y = c9_bk_a * c9_km_b;
  c9_ic_A = c9_so_y;
  c9_ajb_x = c9_ic_A;
  c9_bjb_x = c9_ajb_x;
  c9_to_y = c9_bjb_x / 1000.0;
  c9_cjb_x = c9_theta_4;
  c9_djb_x = c9_cjb_x;
  c9_djb_x = muDoubleScalarCos(c9_djb_x);
  c9_lm_b = c9_djb_x;
  c9_uo_y = 93.0 * c9_lm_b;
  c9_ejb_x = c9_theta_2;
  c9_fjb_x = c9_ejb_x;
  c9_fjb_x = muDoubleScalarCos(c9_fjb_x);
  c9_gjb_x = c9_theta_3;
  c9_hjb_x = c9_gjb_x;
  c9_hjb_x = muDoubleScalarSin(c9_hjb_x);
  c9_ck_a = c9_fjb_x;
  c9_mm_b = c9_hjb_x;
  c9_vo_y = c9_ck_a * c9_mm_b;
  c9_ijb_x = c9_theta_3;
  c9_jjb_x = c9_ijb_x;
  c9_jjb_x = muDoubleScalarCos(c9_jjb_x);
  c9_kjb_x = c9_theta_2;
  c9_ljb_x = c9_kjb_x;
  c9_ljb_x = muDoubleScalarSin(c9_ljb_x);
  c9_dk_a = c9_jjb_x;
  c9_nm_b = c9_ljb_x;
  c9_wo_y = c9_dk_a * c9_nm_b;
  c9_ek_a = c9_uo_y;
  c9_om_b = c9_vo_y + c9_wo_y;
  c9_xo_y = c9_ek_a * c9_om_b;
  c9_jc_A = c9_xo_y;
  c9_mjb_x = c9_jc_A;
  c9_njb_x = c9_mjb_x;
  c9_yo_y = c9_njb_x / 1000.0;
  c9_ojb_x = c9_theta_5;
  c9_pjb_x = c9_ojb_x;
  c9_pjb_x = muDoubleScalarSin(c9_pjb_x);
  c9_pm_b = c9_pjb_x;
  c9_ap_y = 41.0 * c9_pm_b;
  c9_qjb_x = c9_theta_4;
  c9_rjb_x = c9_qjb_x;
  c9_rjb_x = muDoubleScalarCos(c9_rjb_x);
  c9_sjb_x = c9_theta_2;
  c9_tjb_x = c9_sjb_x;
  c9_tjb_x = muDoubleScalarCos(c9_tjb_x);
  c9_ujb_x = c9_theta_3;
  c9_vjb_x = c9_ujb_x;
  c9_vjb_x = muDoubleScalarCos(c9_vjb_x);
  c9_fk_a = c9_tjb_x;
  c9_qm_b = c9_vjb_x;
  c9_bp_y = c9_fk_a * c9_qm_b;
  c9_wjb_x = c9_theta_2;
  c9_xjb_x = c9_wjb_x;
  c9_xjb_x = muDoubleScalarSin(c9_xjb_x);
  c9_yjb_x = c9_theta_3;
  c9_akb_x = c9_yjb_x;
  c9_akb_x = muDoubleScalarSin(c9_akb_x);
  c9_gk_a = c9_xjb_x;
  c9_rm_b = c9_akb_x;
  c9_cp_y = c9_gk_a * c9_rm_b;
  c9_hk_a = c9_rjb_x;
  c9_sm_b = c9_bp_y - c9_cp_y;
  c9_dp_y = c9_hk_a * c9_sm_b;
  c9_bkb_x = c9_theta_4;
  c9_ckb_x = c9_bkb_x;
  c9_ckb_x = muDoubleScalarSin(c9_ckb_x);
  c9_dkb_x = c9_theta_2;
  c9_ekb_x = c9_dkb_x;
  c9_ekb_x = muDoubleScalarCos(c9_ekb_x);
  c9_fkb_x = c9_theta_3;
  c9_gkb_x = c9_fkb_x;
  c9_gkb_x = muDoubleScalarSin(c9_gkb_x);
  c9_ik_a = c9_ekb_x;
  c9_tm_b = c9_gkb_x;
  c9_ep_y = c9_ik_a * c9_tm_b;
  c9_hkb_x = c9_theta_3;
  c9_ikb_x = c9_hkb_x;
  c9_ikb_x = muDoubleScalarCos(c9_ikb_x);
  c9_jkb_x = c9_theta_2;
  c9_kkb_x = c9_jkb_x;
  c9_kkb_x = muDoubleScalarSin(c9_kkb_x);
  c9_jk_a = c9_ikb_x;
  c9_um_b = c9_kkb_x;
  c9_fp_y = c9_jk_a * c9_um_b;
  c9_kk_a = c9_ckb_x;
  c9_vm_b = c9_ep_y + c9_fp_y;
  c9_gp_y = c9_kk_a * c9_vm_b;
  c9_lk_a = c9_ap_y;
  c9_wm_b = c9_dp_y - c9_gp_y;
  c9_hp_y = c9_lk_a * c9_wm_b;
  c9_kc_A = c9_hp_y;
  c9_lkb_x = c9_kc_A;
  c9_mkb_x = c9_lkb_x;
  c9_ip_y = c9_mkb_x / 500.0;
  c9_nkb_x = c9_theta_4;
  c9_okb_x = c9_nkb_x;
  c9_okb_x = muDoubleScalarSin(c9_okb_x);
  c9_xm_b = c9_okb_x;
  c9_jp_y = 93.0 * c9_xm_b;
  c9_pkb_x = c9_theta_2;
  c9_qkb_x = c9_pkb_x;
  c9_qkb_x = muDoubleScalarCos(c9_qkb_x);
  c9_rkb_x = c9_theta_3;
  c9_skb_x = c9_rkb_x;
  c9_skb_x = muDoubleScalarCos(c9_skb_x);
  c9_mk_a = c9_qkb_x;
  c9_ym_b = c9_skb_x;
  c9_kp_y = c9_mk_a * c9_ym_b;
  c9_tkb_x = c9_theta_2;
  c9_ukb_x = c9_tkb_x;
  c9_ukb_x = muDoubleScalarSin(c9_ukb_x);
  c9_vkb_x = c9_theta_3;
  c9_wkb_x = c9_vkb_x;
  c9_wkb_x = muDoubleScalarSin(c9_wkb_x);
  c9_nk_a = c9_ukb_x;
  c9_an_b = c9_wkb_x;
  c9_lp_y = c9_nk_a * c9_an_b;
  c9_ok_a = c9_jp_y;
  c9_bn_b = c9_kp_y - c9_lp_y;
  c9_mp_y = c9_ok_a * c9_bn_b;
  c9_lc_A = c9_mp_y;
  c9_xkb_x = c9_lc_A;
  c9_ykb_x = c9_xkb_x;
  c9_np_y = c9_ykb_x / 1000.0;
  c9_alb_x = c9_theta_5;
  c9_blb_x = c9_alb_x;
  c9_blb_x = muDoubleScalarCos(c9_blb_x);
  c9_cn_b = c9_blb_x;
  c9_op_y = 41.0 * c9_cn_b;
  c9_clb_x = c9_theta_4;
  c9_dlb_x = c9_clb_x;
  c9_dlb_x = muDoubleScalarCos(c9_dlb_x);
  c9_elb_x = c9_theta_2;
  c9_flb_x = c9_elb_x;
  c9_flb_x = muDoubleScalarCos(c9_flb_x);
  c9_glb_x = c9_theta_3;
  c9_hlb_x = c9_glb_x;
  c9_hlb_x = muDoubleScalarSin(c9_hlb_x);
  c9_pk_a = c9_flb_x;
  c9_dn_b = c9_hlb_x;
  c9_pp_y = c9_pk_a * c9_dn_b;
  c9_ilb_x = c9_theta_3;
  c9_jlb_x = c9_ilb_x;
  c9_jlb_x = muDoubleScalarCos(c9_jlb_x);
  c9_klb_x = c9_theta_2;
  c9_llb_x = c9_klb_x;
  c9_llb_x = muDoubleScalarSin(c9_llb_x);
  c9_qk_a = c9_jlb_x;
  c9_en_b = c9_llb_x;
  c9_qp_y = c9_qk_a * c9_en_b;
  c9_rk_a = c9_dlb_x;
  c9_fn_b = c9_pp_y + c9_qp_y;
  c9_rp_y = c9_rk_a * c9_fn_b;
  c9_mlb_x = c9_theta_4;
  c9_nlb_x = c9_mlb_x;
  c9_nlb_x = muDoubleScalarSin(c9_nlb_x);
  c9_olb_x = c9_theta_2;
  c9_plb_x = c9_olb_x;
  c9_plb_x = muDoubleScalarCos(c9_plb_x);
  c9_qlb_x = c9_theta_3;
  c9_rlb_x = c9_qlb_x;
  c9_rlb_x = muDoubleScalarCos(c9_rlb_x);
  c9_sk_a = c9_plb_x;
  c9_gn_b = c9_rlb_x;
  c9_sp_y = c9_sk_a * c9_gn_b;
  c9_slb_x = c9_theta_2;
  c9_tlb_x = c9_slb_x;
  c9_tlb_x = muDoubleScalarSin(c9_tlb_x);
  c9_ulb_x = c9_theta_3;
  c9_vlb_x = c9_ulb_x;
  c9_vlb_x = muDoubleScalarSin(c9_vlb_x);
  c9_tk_a = c9_tlb_x;
  c9_hn_b = c9_vlb_x;
  c9_tp_y = c9_tk_a * c9_hn_b;
  c9_uk_a = c9_nlb_x;
  c9_in_b = c9_sp_y - c9_tp_y;
  c9_up_y = c9_uk_a * c9_in_b;
  c9_vk_a = c9_op_y;
  c9_jn_b = c9_rp_y + c9_up_y;
  c9_vp_y = c9_vk_a * c9_jn_b;
  c9_mc_A = -c9_vp_y;
  c9_wlb_x = c9_mc_A;
  c9_xlb_x = c9_wlb_x;
  c9_wp_y = c9_xlb_x / 500.0;
  c9_ylb_x = c9_theta_1;
  c9_amb_x = c9_ylb_x;
  c9_amb_x = muDoubleScalarSin(c9_amb_x);
  c9_bmb_x = c9_theta_1;
  c9_cmb_x = c9_bmb_x;
  c9_cmb_x = muDoubleScalarSin(c9_cmb_x);
  c9_dmb_x = c9_theta_1;
  c9_emb_x = c9_dmb_x;
  c9_emb_x = muDoubleScalarSin(c9_emb_x);
  c9_fmb_x = c9_theta_4;
  c9_gmb_x = c9_fmb_x;
  c9_gmb_x = muDoubleScalarCos(c9_gmb_x);
  c9_hmb_x = c9_theta_1;
  c9_imb_x = c9_hmb_x;
  c9_imb_x = muDoubleScalarCos(c9_imb_x);
  c9_jmb_x = c9_theta_2;
  c9_kmb_x = c9_jmb_x;
  c9_kmb_x = muDoubleScalarCos(c9_kmb_x);
  c9_wk_a = c9_imb_x;
  c9_kn_b = c9_kmb_x;
  c9_xp_y = c9_wk_a * c9_kn_b;
  c9_lmb_x = c9_theta_3;
  c9_mmb_x = c9_lmb_x;
  c9_mmb_x = muDoubleScalarSin(c9_mmb_x);
  c9_xk_a = c9_xp_y;
  c9_ln_b = c9_mmb_x;
  c9_yp_y = c9_xk_a * c9_ln_b;
  c9_nmb_x = c9_theta_1;
  c9_omb_x = c9_nmb_x;
  c9_omb_x = muDoubleScalarCos(c9_omb_x);
  c9_pmb_x = c9_theta_3;
  c9_qmb_x = c9_pmb_x;
  c9_qmb_x = muDoubleScalarCos(c9_qmb_x);
  c9_yk_a = c9_omb_x;
  c9_mn_b = c9_qmb_x;
  c9_aq_y = c9_yk_a * c9_mn_b;
  c9_rmb_x = c9_theta_2;
  c9_smb_x = c9_rmb_x;
  c9_smb_x = muDoubleScalarSin(c9_smb_x);
  c9_al_a = c9_aq_y;
  c9_nn_b = c9_smb_x;
  c9_bq_y = c9_al_a * c9_nn_b;
  c9_bl_a = c9_gmb_x;
  c9_on_b = c9_yp_y + c9_bq_y;
  c9_cq_y = c9_bl_a * c9_on_b;
  c9_tmb_x = c9_theta_4;
  c9_umb_x = c9_tmb_x;
  c9_umb_x = muDoubleScalarSin(c9_umb_x);
  c9_vmb_x = c9_theta_1;
  c9_wmb_x = c9_vmb_x;
  c9_wmb_x = muDoubleScalarCos(c9_wmb_x);
  c9_xmb_x = c9_theta_2;
  c9_ymb_x = c9_xmb_x;
  c9_ymb_x = muDoubleScalarSin(c9_ymb_x);
  c9_cl_a = c9_wmb_x;
  c9_pn_b = c9_ymb_x;
  c9_dq_y = c9_cl_a * c9_pn_b;
  c9_anb_x = c9_theta_3;
  c9_bnb_x = c9_anb_x;
  c9_bnb_x = muDoubleScalarSin(c9_bnb_x);
  c9_dl_a = c9_dq_y;
  c9_qn_b = c9_bnb_x;
  c9_eq_y = c9_dl_a * c9_qn_b;
  c9_cnb_x = c9_theta_1;
  c9_dnb_x = c9_cnb_x;
  c9_dnb_x = muDoubleScalarCos(c9_dnb_x);
  c9_enb_x = c9_theta_2;
  c9_fnb_x = c9_enb_x;
  c9_fnb_x = muDoubleScalarCos(c9_fnb_x);
  c9_el_a = c9_dnb_x;
  c9_rn_b = c9_fnb_x;
  c9_fq_y = c9_el_a * c9_rn_b;
  c9_gnb_x = c9_theta_3;
  c9_hnb_x = c9_gnb_x;
  c9_hnb_x = muDoubleScalarCos(c9_hnb_x);
  c9_fl_a = c9_fq_y;
  c9_sn_b = c9_hnb_x;
  c9_gq_y = c9_fl_a * c9_sn_b;
  c9_gl_a = c9_umb_x;
  c9_tn_b = c9_eq_y - c9_gq_y;
  c9_hq_y = c9_gl_a * c9_tn_b;
  c9_inb_x = c9_theta_5;
  c9_jnb_x = c9_inb_x;
  c9_jnb_x = muDoubleScalarCos(c9_jnb_x);
  c9_knb_x = c9_theta_1;
  c9_lnb_x = c9_knb_x;
  c9_lnb_x = muDoubleScalarSin(c9_lnb_x);
  c9_hl_a = c9_jnb_x;
  c9_un_b = c9_lnb_x;
  c9_iq_y = c9_hl_a * c9_un_b;
  c9_mnb_x = c9_theta_5;
  c9_nnb_x = c9_mnb_x;
  c9_nnb_x = muDoubleScalarSin(c9_nnb_x);
  c9_onb_x = c9_theta_4;
  c9_pnb_x = c9_onb_x;
  c9_pnb_x = muDoubleScalarCos(c9_pnb_x);
  c9_qnb_x = c9_theta_1;
  c9_rnb_x = c9_qnb_x;
  c9_rnb_x = muDoubleScalarCos(c9_rnb_x);
  c9_snb_x = c9_theta_2;
  c9_tnb_x = c9_snb_x;
  c9_tnb_x = muDoubleScalarSin(c9_tnb_x);
  c9_il_a = c9_rnb_x;
  c9_vn_b = c9_tnb_x;
  c9_jq_y = c9_il_a * c9_vn_b;
  c9_unb_x = c9_theta_3;
  c9_vnb_x = c9_unb_x;
  c9_vnb_x = muDoubleScalarSin(c9_vnb_x);
  c9_jl_a = c9_jq_y;
  c9_wn_b = c9_vnb_x;
  c9_kq_y = c9_jl_a * c9_wn_b;
  c9_wnb_x = c9_theta_1;
  c9_xnb_x = c9_wnb_x;
  c9_xnb_x = muDoubleScalarCos(c9_xnb_x);
  c9_ynb_x = c9_theta_2;
  c9_aob_x = c9_ynb_x;
  c9_aob_x = muDoubleScalarCos(c9_aob_x);
  c9_kl_a = c9_xnb_x;
  c9_xn_b = c9_aob_x;
  c9_lq_y = c9_kl_a * c9_xn_b;
  c9_bob_x = c9_theta_3;
  c9_cob_x = c9_bob_x;
  c9_cob_x = muDoubleScalarCos(c9_cob_x);
  c9_ll_a = c9_lq_y;
  c9_yn_b = c9_cob_x;
  c9_mq_y = c9_ll_a * c9_yn_b;
  c9_ml_a = c9_pnb_x;
  c9_ao_b = c9_kq_y - c9_mq_y;
  c9_nq_y = c9_ml_a * c9_ao_b;
  c9_dob_x = c9_theta_4;
  c9_eob_x = c9_dob_x;
  c9_eob_x = muDoubleScalarSin(c9_eob_x);
  c9_fob_x = c9_theta_1;
  c9_gob_x = c9_fob_x;
  c9_gob_x = muDoubleScalarCos(c9_gob_x);
  c9_hob_x = c9_theta_2;
  c9_iob_x = c9_hob_x;
  c9_iob_x = muDoubleScalarCos(c9_iob_x);
  c9_nl_a = c9_gob_x;
  c9_bo_b = c9_iob_x;
  c9_oq_y = c9_nl_a * c9_bo_b;
  c9_job_x = c9_theta_3;
  c9_kob_x = c9_job_x;
  c9_kob_x = muDoubleScalarSin(c9_kob_x);
  c9_ol_a = c9_oq_y;
  c9_co_b = c9_kob_x;
  c9_pq_y = c9_ol_a * c9_co_b;
  c9_lob_x = c9_theta_1;
  c9_mob_x = c9_lob_x;
  c9_mob_x = muDoubleScalarCos(c9_mob_x);
  c9_nob_x = c9_theta_3;
  c9_oob_x = c9_nob_x;
  c9_oob_x = muDoubleScalarCos(c9_oob_x);
  c9_pl_a = c9_mob_x;
  c9_do_b = c9_oob_x;
  c9_qq_y = c9_pl_a * c9_do_b;
  c9_pob_x = c9_theta_2;
  c9_qob_x = c9_pob_x;
  c9_qob_x = muDoubleScalarSin(c9_qob_x);
  c9_ql_a = c9_qq_y;
  c9_eo_b = c9_qob_x;
  c9_rq_y = c9_ql_a * c9_eo_b;
  c9_rl_a = c9_eob_x;
  c9_fo_b = c9_pq_y + c9_rq_y;
  c9_sq_y = c9_rl_a * c9_fo_b;
  c9_sl_a = c9_nnb_x;
  c9_go_b = c9_nq_y + c9_sq_y;
  c9_tq_y = c9_sl_a * c9_go_b;
  c9_rob_x = c9_theta_1;
  c9_sob_x = c9_rob_x;
  c9_sob_x = muDoubleScalarCos(c9_sob_x);
  c9_tob_x = c9_theta_1;
  c9_uob_x = c9_tob_x;
  c9_uob_x = muDoubleScalarCos(c9_uob_x);
  c9_vob_x = c9_theta_1;
  c9_wob_x = c9_vob_x;
  c9_wob_x = muDoubleScalarCos(c9_wob_x);
  c9_xob_x = c9_theta_4;
  c9_yob_x = c9_xob_x;
  c9_yob_x = muDoubleScalarCos(c9_yob_x);
  c9_apb_x = c9_theta_2;
  c9_bpb_x = c9_apb_x;
  c9_bpb_x = muDoubleScalarCos(c9_bpb_x);
  c9_cpb_x = c9_theta_1;
  c9_dpb_x = c9_cpb_x;
  c9_dpb_x = muDoubleScalarSin(c9_dpb_x);
  c9_tl_a = c9_bpb_x;
  c9_ho_b = c9_dpb_x;
  c9_uq_y = c9_tl_a * c9_ho_b;
  c9_epb_x = c9_theta_3;
  c9_fpb_x = c9_epb_x;
  c9_fpb_x = muDoubleScalarSin(c9_fpb_x);
  c9_ul_a = c9_uq_y;
  c9_io_b = c9_fpb_x;
  c9_vq_y = c9_ul_a * c9_io_b;
  c9_gpb_x = c9_theta_3;
  c9_hpb_x = c9_gpb_x;
  c9_hpb_x = muDoubleScalarCos(c9_hpb_x);
  c9_ipb_x = c9_theta_1;
  c9_jpb_x = c9_ipb_x;
  c9_jpb_x = muDoubleScalarSin(c9_jpb_x);
  c9_vl_a = c9_hpb_x;
  c9_jo_b = c9_jpb_x;
  c9_wq_y = c9_vl_a * c9_jo_b;
  c9_kpb_x = c9_theta_2;
  c9_lpb_x = c9_kpb_x;
  c9_lpb_x = muDoubleScalarSin(c9_lpb_x);
  c9_wl_a = c9_wq_y;
  c9_ko_b = c9_lpb_x;
  c9_xq_y = c9_wl_a * c9_ko_b;
  c9_xl_a = c9_yob_x;
  c9_lo_b = c9_vq_y + c9_xq_y;
  c9_yq_y = c9_xl_a * c9_lo_b;
  c9_mpb_x = c9_theta_4;
  c9_npb_x = c9_mpb_x;
  c9_npb_x = muDoubleScalarSin(c9_npb_x);
  c9_opb_x = c9_theta_1;
  c9_ppb_x = c9_opb_x;
  c9_ppb_x = muDoubleScalarSin(c9_ppb_x);
  c9_qpb_x = c9_theta_2;
  c9_rpb_x = c9_qpb_x;
  c9_rpb_x = muDoubleScalarSin(c9_rpb_x);
  c9_yl_a = c9_ppb_x;
  c9_mo_b = c9_rpb_x;
  c9_ar_y = c9_yl_a * c9_mo_b;
  c9_spb_x = c9_theta_3;
  c9_tpb_x = c9_spb_x;
  c9_tpb_x = muDoubleScalarSin(c9_tpb_x);
  c9_am_a = c9_ar_y;
  c9_no_b = c9_tpb_x;
  c9_br_y = c9_am_a * c9_no_b;
  c9_upb_x = c9_theta_2;
  c9_vpb_x = c9_upb_x;
  c9_vpb_x = muDoubleScalarCos(c9_vpb_x);
  c9_wpb_x = c9_theta_3;
  c9_xpb_x = c9_wpb_x;
  c9_xpb_x = muDoubleScalarCos(c9_xpb_x);
  c9_bm_a = c9_vpb_x;
  c9_oo_b = c9_xpb_x;
  c9_cr_y = c9_bm_a * c9_oo_b;
  c9_ypb_x = c9_theta_1;
  c9_aqb_x = c9_ypb_x;
  c9_aqb_x = muDoubleScalarSin(c9_aqb_x);
  c9_cm_a = c9_cr_y;
  c9_po_b = c9_aqb_x;
  c9_dr_y = c9_cm_a * c9_po_b;
  c9_dm_a = c9_npb_x;
  c9_qo_b = c9_br_y - c9_dr_y;
  c9_er_y = c9_dm_a * c9_qo_b;
  c9_bqb_x = c9_theta_5;
  c9_cqb_x = c9_bqb_x;
  c9_cqb_x = muDoubleScalarSin(c9_cqb_x);
  c9_dqb_x = c9_theta_4;
  c9_eqb_x = c9_dqb_x;
  c9_eqb_x = muDoubleScalarCos(c9_eqb_x);
  c9_fqb_x = c9_theta_1;
  c9_gqb_x = c9_fqb_x;
  c9_gqb_x = muDoubleScalarSin(c9_gqb_x);
  c9_hqb_x = c9_theta_2;
  c9_iqb_x = c9_hqb_x;
  c9_iqb_x = muDoubleScalarSin(c9_iqb_x);
  c9_em_a = c9_gqb_x;
  c9_ro_b = c9_iqb_x;
  c9_fr_y = c9_em_a * c9_ro_b;
  c9_jqb_x = c9_theta_3;
  c9_kqb_x = c9_jqb_x;
  c9_kqb_x = muDoubleScalarSin(c9_kqb_x);
  c9_fm_a = c9_fr_y;
  c9_so_b = c9_kqb_x;
  c9_gr_y = c9_fm_a * c9_so_b;
  c9_lqb_x = c9_theta_2;
  c9_mqb_x = c9_lqb_x;
  c9_mqb_x = muDoubleScalarCos(c9_mqb_x);
  c9_nqb_x = c9_theta_3;
  c9_oqb_x = c9_nqb_x;
  c9_oqb_x = muDoubleScalarCos(c9_oqb_x);
  c9_gm_a = c9_mqb_x;
  c9_to_b = c9_oqb_x;
  c9_hr_y = c9_gm_a * c9_to_b;
  c9_pqb_x = c9_theta_1;
  c9_qqb_x = c9_pqb_x;
  c9_qqb_x = muDoubleScalarSin(c9_qqb_x);
  c9_hm_a = c9_hr_y;
  c9_uo_b = c9_qqb_x;
  c9_ir_y = c9_hm_a * c9_uo_b;
  c9_im_a = c9_eqb_x;
  c9_vo_b = c9_gr_y - c9_ir_y;
  c9_jr_y = c9_im_a * c9_vo_b;
  c9_rqb_x = c9_theta_4;
  c9_sqb_x = c9_rqb_x;
  c9_sqb_x = muDoubleScalarSin(c9_sqb_x);
  c9_tqb_x = c9_theta_2;
  c9_uqb_x = c9_tqb_x;
  c9_uqb_x = muDoubleScalarCos(c9_uqb_x);
  c9_vqb_x = c9_theta_1;
  c9_wqb_x = c9_vqb_x;
  c9_wqb_x = muDoubleScalarSin(c9_wqb_x);
  c9_jm_a = c9_uqb_x;
  c9_wo_b = c9_wqb_x;
  c9_kr_y = c9_jm_a * c9_wo_b;
  c9_xqb_x = c9_theta_3;
  c9_yqb_x = c9_xqb_x;
  c9_yqb_x = muDoubleScalarSin(c9_yqb_x);
  c9_km_a = c9_kr_y;
  c9_xo_b = c9_yqb_x;
  c9_lr_y = c9_km_a * c9_xo_b;
  c9_arb_x = c9_theta_3;
  c9_brb_x = c9_arb_x;
  c9_brb_x = muDoubleScalarCos(c9_brb_x);
  c9_crb_x = c9_theta_1;
  c9_drb_x = c9_crb_x;
  c9_drb_x = muDoubleScalarSin(c9_drb_x);
  c9_lm_a = c9_brb_x;
  c9_yo_b = c9_drb_x;
  c9_mr_y = c9_lm_a * c9_yo_b;
  c9_erb_x = c9_theta_2;
  c9_frb_x = c9_erb_x;
  c9_frb_x = muDoubleScalarSin(c9_frb_x);
  c9_mm_a = c9_mr_y;
  c9_ap_b = c9_frb_x;
  c9_nr_y = c9_mm_a * c9_ap_b;
  c9_nm_a = c9_sqb_x;
  c9_bp_b = c9_lr_y + c9_nr_y;
  c9_or_y = c9_nm_a * c9_bp_b;
  c9_om_a = c9_cqb_x;
  c9_cp_b = c9_jr_y + c9_or_y;
  c9_pr_y = c9_om_a * c9_cp_b;
  c9_grb_x = c9_theta_1;
  c9_hrb_x = c9_grb_x;
  c9_hrb_x = muDoubleScalarCos(c9_hrb_x);
  c9_irb_x = c9_theta_5;
  c9_jrb_x = c9_irb_x;
  c9_jrb_x = muDoubleScalarCos(c9_jrb_x);
  c9_pm_a = c9_hrb_x;
  c9_dp_b = c9_jrb_x;
  c9_qr_y = c9_pm_a * c9_dp_b;
  c9_krb_x = c9_theta_4;
  c9_lrb_x = c9_krb_x;
  c9_lrb_x = muDoubleScalarSin(c9_lrb_x);
  c9_mrb_x = c9_theta_2;
  c9_nrb_x = c9_mrb_x;
  c9_nrb_x = muDoubleScalarCos(c9_nrb_x);
  c9_orb_x = c9_theta_3;
  c9_prb_x = c9_orb_x;
  c9_prb_x = muDoubleScalarSin(c9_prb_x);
  c9_qm_a = c9_nrb_x;
  c9_ep_b = c9_prb_x;
  c9_rr_y = c9_qm_a * c9_ep_b;
  c9_qrb_x = c9_theta_3;
  c9_rrb_x = c9_qrb_x;
  c9_rrb_x = muDoubleScalarCos(c9_rrb_x);
  c9_srb_x = c9_theta_2;
  c9_trb_x = c9_srb_x;
  c9_trb_x = muDoubleScalarSin(c9_trb_x);
  c9_rm_a = c9_rrb_x;
  c9_fp_b = c9_trb_x;
  c9_sr_y = c9_rm_a * c9_fp_b;
  c9_sm_a = c9_lrb_x;
  c9_gp_b = c9_rr_y + c9_sr_y;
  c9_tr_y = c9_sm_a * c9_gp_b;
  c9_urb_x = c9_theta_4;
  c9_vrb_x = c9_urb_x;
  c9_vrb_x = muDoubleScalarCos(c9_vrb_x);
  c9_wrb_x = c9_theta_2;
  c9_xrb_x = c9_wrb_x;
  c9_xrb_x = muDoubleScalarCos(c9_xrb_x);
  c9_yrb_x = c9_theta_3;
  c9_asb_x = c9_yrb_x;
  c9_asb_x = muDoubleScalarCos(c9_asb_x);
  c9_tm_a = c9_xrb_x;
  c9_hp_b = c9_asb_x;
  c9_ur_y = c9_tm_a * c9_hp_b;
  c9_bsb_x = c9_theta_2;
  c9_csb_x = c9_bsb_x;
  c9_csb_x = muDoubleScalarSin(c9_csb_x);
  c9_dsb_x = c9_theta_3;
  c9_esb_x = c9_dsb_x;
  c9_esb_x = muDoubleScalarSin(c9_esb_x);
  c9_um_a = c9_csb_x;
  c9_ip_b = c9_esb_x;
  c9_vr_y = c9_um_a * c9_ip_b;
  c9_vm_a = c9_vrb_x;
  c9_jp_b = c9_ur_y - c9_vr_y;
  c9_wr_y = c9_vm_a * c9_jp_b;
  c9_fsb_x = c9_theta_5;
  c9_gsb_x = c9_fsb_x;
  c9_gsb_x = muDoubleScalarSin(c9_gsb_x);
  c9_hsb_x = c9_theta_4;
  c9_isb_x = c9_hsb_x;
  c9_isb_x = muDoubleScalarCos(c9_isb_x);
  c9_jsb_x = c9_theta_2;
  c9_ksb_x = c9_jsb_x;
  c9_ksb_x = muDoubleScalarCos(c9_ksb_x);
  c9_lsb_x = c9_theta_3;
  c9_msb_x = c9_lsb_x;
  c9_msb_x = muDoubleScalarSin(c9_msb_x);
  c9_wm_a = c9_ksb_x;
  c9_kp_b = c9_msb_x;
  c9_xr_y = c9_wm_a * c9_kp_b;
  c9_nsb_x = c9_theta_3;
  c9_osb_x = c9_nsb_x;
  c9_osb_x = muDoubleScalarCos(c9_osb_x);
  c9_psb_x = c9_theta_2;
  c9_qsb_x = c9_psb_x;
  c9_qsb_x = muDoubleScalarSin(c9_qsb_x);
  c9_xm_a = c9_osb_x;
  c9_lp_b = c9_qsb_x;
  c9_yr_y = c9_xm_a * c9_lp_b;
  c9_ym_a = c9_isb_x;
  c9_mp_b = c9_xr_y + c9_yr_y;
  c9_as_y = c9_ym_a * c9_mp_b;
  c9_rsb_x = c9_theta_4;
  c9_ssb_x = c9_rsb_x;
  c9_ssb_x = muDoubleScalarSin(c9_ssb_x);
  c9_tsb_x = c9_theta_2;
  c9_usb_x = c9_tsb_x;
  c9_usb_x = muDoubleScalarCos(c9_usb_x);
  c9_vsb_x = c9_theta_3;
  c9_wsb_x = c9_vsb_x;
  c9_wsb_x = muDoubleScalarCos(c9_wsb_x);
  c9_an_a = c9_usb_x;
  c9_np_b = c9_wsb_x;
  c9_bs_y = c9_an_a * c9_np_b;
  c9_xsb_x = c9_theta_2;
  c9_ysb_x = c9_xsb_x;
  c9_ysb_x = muDoubleScalarSin(c9_ysb_x);
  c9_atb_x = c9_theta_3;
  c9_btb_x = c9_atb_x;
  c9_btb_x = muDoubleScalarSin(c9_btb_x);
  c9_bn_a = c9_ysb_x;
  c9_op_b = c9_btb_x;
  c9_cs_y = c9_bn_a * c9_op_b;
  c9_cn_a = c9_ssb_x;
  c9_pp_b = c9_bs_y - c9_cs_y;
  c9_ds_y = c9_cn_a * c9_pp_b;
  c9_dn_a = -c9_gsb_x;
  c9_qp_b = c9_as_y + c9_ds_y;
  c9_es_y = c9_dn_a * c9_qp_b;
  c9_J[0] = ((((((c9_b_y + c9_e_y) + c9_h_y) - c9_o_y) + c9_v_y) - c9_jb_y) -
             c9_nb_y) + c9_rb_y;
  c9_J[6] = ((((c9_ub_y - c9_cc_y) - c9_jc_y) + c9_wc_y) + c9_bd_y) + c9_fd_y;
  c9_J[12] = (((c9_sd_y - c9_ae_y) - c9_he_y) + c9_le_y) + c9_pe_y;
  c9_J[18] = (c9_df_y - c9_kf_y) - c9_rf_y;
  c9_J[24] = c9_fg_y - c9_ig_y;
  c9_J[30] = 0.0;
  c9_J[1] = ((((((c9_kg_y - c9_ng_y) + c9_qg_y) + c9_xg_y) - c9_fh_y) + c9_sh_y)
             + c9_wh_y) - c9_bi_y;
  c9_J[7] = ((((c9_ei_y - c9_li_y) - c9_si_y) + c9_gj_y) + c9_kj_y) + c9_oj_y;
  c9_J[13] = (((c9_ck_y - c9_jk_y) - c9_qk_y) + c9_uk_y) + c9_yk_y;
  c9_J[19] = (c9_ml_y - c9_tl_y) - c9_bm_y;
  c9_J[25] = c9_em_y + c9_rm_y;
  c9_J[31] = 0.0;
  c9_J[2] = 0.0;
  c9_J[8] = ((((c9_um_y - c9_xm_y) - c9_an_y) - c9_jn_y) + c9_on_y) + c9_tn_y;
  c9_J[14] = (((c9_wn_y - c9_ao_y) - c9_jo_y) + c9_oo_y) + c9_to_y;
  c9_J[20] = (c9_yo_y - c9_ip_y) + c9_np_y;
  c9_J[26] = c9_wp_y;
  c9_J[32] = 0.0;
  c9_J[3] = 0.0;
  c9_J[9] = c9_amb_x;
  c9_J[15] = c9_cmb_x;
  c9_J[21] = c9_emb_x;
  c9_J[27] = c9_cq_y - c9_hq_y;
  c9_J[33] = c9_iq_y + c9_tq_y;
  c9_J[4] = 0.0;
  c9_J[10] = -c9_sob_x;
  c9_J[16] = -c9_uob_x;
  c9_J[22] = -c9_wob_x;
  c9_J[28] = c9_yq_y - c9_er_y;
  c9_J[34] = c9_pr_y - c9_qr_y;
  c9_J[5] = 1.0;
  c9_J[11] = 0.0;
  c9_J[17] = 0.0;
  c9_J[23] = 0.0;
  c9_J[29] = c9_tr_y - c9_wr_y;
  c9_J[35] = c9_es_y;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 199U);
  for (c9_i7 = 0; c9_i7 < 36; c9_i7++) {
    c9_en_a[c9_i7] = c9_J[c9_i7];
  }

  for (c9_i8 = 0; c9_i8 < 6; c9_i8++) {
    c9_rp_b[c9_i8] = c9_dq[c9_i8];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i9 = 0; c9_i9 < 6; c9_i9++) {
    c9_tcp_speed[c9_i9] = 0.0;
  }

  for (c9_i10 = 0; c9_i10 < 6; c9_i10++) {
    c9_tcp_speed[c9_i10] = 0.0;
  }

  for (c9_i11 = 0; c9_i11 < 6; c9_i11++) {
    c9_C[c9_i11] = c9_tcp_speed[c9_i11];
  }

  for (c9_i12 = 0; c9_i12 < 6; c9_i12++) {
    c9_tcp_speed[c9_i12] = c9_C[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 6; c9_i13++) {
    c9_C[c9_i13] = c9_tcp_speed[c9_i13];
  }

  for (c9_i14 = 0; c9_i14 < 6; c9_i14++) {
    c9_tcp_speed[c9_i14] = c9_C[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 6; c9_i15++) {
    c9_tcp_speed[c9_i15] = 0.0;
    c9_i16 = 0;
    for (c9_i17 = 0; c9_i17 < 6; c9_i17++) {
      c9_tcp_speed[c9_i15] += c9_en_a[c9_i16 + c9_i15] * c9_rp_b[c9_i17];
      c9_i16 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -199);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i18 = 0; c9_i18 < 6; c9_i18++) {
    (*c9_b_tcp_speed)[c9_i18] = c9_tcp_speed[c9_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void registerMessagesc9_JointSpaceControl
  (SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i19;
  real_T c9_b_inData[6];
  int32_T c9_i20;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i19 = 0; c9_i19 < 6; c9_i19++) {
    c9_b_inData[c9_i19] = (*(real_T (*)[6])c9_inData)[c9_i19];
  }

  for (c9_i20 = 0; c9_i20 < 6; c9_i20++) {
    c9_u[c9_i20] = c9_b_inData[c9_i20];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_tcp_speed, const char_T *c9_identifier,
  real_T c9_y[6])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_tcp_speed), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_tcp_speed);
}

static void c9_b_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6])
{
  real_T c9_dv1[6];
  int32_T c9_i21;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c9_i21 = 0; c9_i21 < 6; c9_i21++) {
    c9_y[c9_i21] = c9_dv1[c9_i21];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_tcp_speed;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[6];
  int32_T c9_i22;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_tcp_speed = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_tcp_speed), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_tcp_speed);
  for (c9_i22 = 0; c9_i22 < 6; c9_i22++) {
    (*(real_T (*)[6])c9_outData)[c9_i22] = c9_y[c9_i22];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  real_T c9_b_inData[36];
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  real_T c9_u[36];
  const mxArray *c9_y = NULL;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i23 = 0;
  for (c9_i24 = 0; c9_i24 < 6; c9_i24++) {
    for (c9_i25 = 0; c9_i25 < 6; c9_i25++) {
      c9_b_inData[c9_i25 + c9_i23] = (*(real_T (*)[36])c9_inData)[c9_i25 +
        c9_i23];
    }

    c9_i23 += 6;
  }

  c9_i26 = 0;
  for (c9_i27 = 0; c9_i27 < 6; c9_i27++) {
    for (c9_i28 = 0; c9_i28 < 6; c9_i28++) {
      c9_u[c9_i28 + c9_i26] = c9_b_inData[c9_i28 + c9_i26];
    }

    c9_i26 += 6;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[36])
{
  real_T c9_dv2[36];
  int32_T c9_i29;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv2, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c9_i29 = 0; c9_i29 < 36; c9_i29++) {
    c9_y[c9_i29] = c9_dv2[c9_i29];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_J;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[36];
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_J = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_J), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_J);
  c9_i30 = 0;
  for (c9_i31 = 0; c9_i31 < 6; c9_i31++) {
    for (c9_i32 = 0; c9_i32 < 6; c9_i32++) {
      (*(real_T (*)[36])c9_outData)[c9_i32 + c9_i30] = c9_y[c9_i32 + c9_i30];
    }

    c9_i30 += 6;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_JointSpaceControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[17];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i33;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17), FALSE);
  for (c9_i33 = 0; c9_i33 < 17; c9_i33++) {
    c9_r0 = &c9_info[c9_i33];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i33);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i33);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[17])
{
  c9_info[0].context = "";
  c9_info[0].name = "cos";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[0].fileTimeLo = 1343851972U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[1].name = "eml_scalar_cos";
  c9_info[1].dominantType = "double";
  c9_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c9_info[1].fileTimeLo = 1286840322U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context = "";
  c9_info[2].name = "mtimes";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[2].fileTimeLo = 1289541292U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context = "";
  c9_info[3].name = "mrdivide";
  c9_info[3].dominantType = "double";
  c9_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c9_info[3].fileTimeLo = 1357973148U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 1319751566U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c9_info[4].name = "rdivide";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[4].fileTimeLo = 1346531988U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[5].name = "eml_scalexp_compatible";
  c9_info[5].dominantType = "double";
  c9_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c9_info[5].fileTimeLo = 1286840396U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[6].name = "eml_div";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[6].fileTimeLo = 1313369410U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context = "";
  c9_info[7].name = "sin";
  c9_info[7].dominantType = "double";
  c9_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[7].fileTimeLo = 1343851986U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[8].name = "eml_scalar_sin";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c9_info[8].fileTimeLo = 1286840336U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[9].name = "eml_index_class";
  c9_info[9].dominantType = "";
  c9_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[9].fileTimeLo = 1323192178U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[10].name = "eml_scalar_eg";
  c9_info[10].dominantType = "double";
  c9_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[10].fileTimeLo = 1286840396U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[11].name = "eml_xgemm";
  c9_info[11].dominantType = "char";
  c9_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[11].fileTimeLo = 1299098372U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[12].name = "eml_blas_inline";
  c9_info[12].dominantType = "";
  c9_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[12].fileTimeLo = 1299098368U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
  c9_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c9_info[13].name = "mtimes";
  c9_info[13].dominantType = "double";
  c9_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[13].fileTimeLo = 1289541292U;
  c9_info[13].fileTimeHi = 0U;
  c9_info[13].mFileTimeLo = 0U;
  c9_info[13].mFileTimeHi = 0U;
  c9_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[14].name = "eml_index_class";
  c9_info[14].dominantType = "";
  c9_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[14].fileTimeLo = 1323192178U;
  c9_info[14].fileTimeHi = 0U;
  c9_info[14].mFileTimeLo = 0U;
  c9_info[14].mFileTimeHi = 0U;
  c9_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[15].name = "eml_scalar_eg";
  c9_info[15].dominantType = "double";
  c9_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[15].fileTimeLo = 1286840396U;
  c9_info[15].fileTimeHi = 0U;
  c9_info[15].mFileTimeLo = 0U;
  c9_info[15].mFileTimeHi = 0U;
  c9_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[16].name = "eml_refblas_xgemm";
  c9_info[16].dominantType = "char";
  c9_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[16].fileTimeLo = 1299098374U;
  c9_info[16].fileTimeHi = 0U;
  c9_info[16].mFileTimeLo = 0U;
  c9_info[16].mFileTimeHi = 0U;
}

static void c9_eml_scalar_eg(SFc9_JointSpaceControlInstanceStruct *chartInstance)
{
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_e_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i34;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i34, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i34;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_JointSpaceControl, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_JointSpaceControl), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_JointSpaceControl);
  return c9_y;
}

static uint8_T c9_g_emlrt_marshallIn(SFc9_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_JointSpaceControlInstanceStruct
  *chartInstance)
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

void sf_c9_JointSpaceControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1568555601U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(944266597U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2406014U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(831672702U);
}

mxArray *sf_c9_JointSpaceControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("I2i2uFpperEyStY4qjbKVF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c9_JointSpaceControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c9_JointSpaceControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"tcp_speed\",},{M[8],M[0],T\"is_active_c9_JointSpaceControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_JointSpaceControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_JointSpaceControlInstanceStruct *chartInstance;
    chartInstance = (SFc9_JointSpaceControlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControlMachineNumber_,
           9,
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
          init_script_number_translation(_JointSpaceControlMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_JointSpaceControlMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControlMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"tcp_speed");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dq");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,10057);
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
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c9_tcp_speed)[6];
          real_T (*c9_q)[6];
          real_T (*c9_dq)[6];
          c9_dq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c9_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c9_tcp_speed = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
            1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_tcp_speed);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_q);
          _SFD_SET_DATA_VALUE_PTR(2U, *c9_dq);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControlMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "8Q6SSJtq4GzM10QwY833oF";
}

static void sf_opaque_initialize_c9_JointSpaceControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
  initialize_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_JointSpaceControl(void *chartInstanceVar)
{
  enable_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_JointSpaceControl(void *chartInstanceVar)
{
  disable_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_JointSpaceControl(void *chartInstanceVar)
{
  sf_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_JointSpaceControl(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_JointSpaceControl
    ((SFc9_JointSpaceControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_JointSpaceControl();/* state var info */
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

extern void sf_internal_set_sim_state_c9_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_JointSpaceControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_JointSpaceControl(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_JointSpaceControl(S);
}

static void sf_opaque_set_sim_state_c9_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_JointSpaceControl(S, st);
}

static void sf_opaque_terminate_c9_JointSpaceControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_JointSpaceControlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_optimization_info();
    }

    finalize_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_JointSpaceControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_JointSpaceControl((SFc9_JointSpaceControlInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(467862386U));
  ssSetChecksum1(S,(636699249U));
  ssSetChecksum2(S,(2684652542U));
  ssSetChecksum3(S,(2927430391U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_JointSpaceControl(SimStruct *S)
{
  SFc9_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_JointSpaceControlInstanceStruct *)utMalloc(sizeof
    (SFc9_JointSpaceControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_JointSpaceControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_JointSpaceControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_JointSpaceControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_JointSpaceControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_JointSpaceControl;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_JointSpaceControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_JointSpaceControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_JointSpaceControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_JointSpaceControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_JointSpaceControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_JointSpaceControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_JointSpaceControl;
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

void c9_JointSpaceControl_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_JointSpaceControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_JointSpaceControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
