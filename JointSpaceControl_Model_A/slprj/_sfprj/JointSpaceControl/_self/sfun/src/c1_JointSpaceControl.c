/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_sfun.h"
#include "c1_JointSpaceControl.h"
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
static const char * c1_debug_family_names[22] = { "theta_1", "theta_2",
  "theta_3", "theta_4", "theta_5", "theta_6", "m_1", "m_2", "m_3", "m_4", "m_5",
  "m_6", "g_1", "g_2", "g_3", "g_4", "g_5", "g_6", "nargin", "nargout", "q",
  "G_kathi" };

/* Function Declarations */
static void initialize_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance);
static void initialize_params_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance);
static void enable_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance);
static void disable_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance);
static void set_sim_state_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance);
static void sf_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance);
static void initSimStructsc1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance);
static void registerMessagesc1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_G_kathi, const char_T *c1_identifier, real_T
  c1_y[6]);
static void c1_b_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_JointSpaceControl, const
  char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_JointSpaceControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_JointSpaceControl = 0U;
}

static void initialize_params_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void enable_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[6];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_G_kathi)[6];
  c1_G_kathi = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 6; c1_i0++) {
    c1_u[c1_i0] = (*c1_G_kathi)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_JointSpaceControl;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[6];
  int32_T c1_i1;
  real_T (*c1_G_kathi)[6];
  c1_G_kathi = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "G_kathi", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 6; c1_i1++) {
    (*c1_G_kathi)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_JointSpaceControl = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_JointSpaceControl");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_JointSpaceControl(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance)
{
}

static void sf_c1_JointSpaceControl(SFc1_JointSpaceControlInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  real_T (*c1_G_kathi)[6];
  real_T (*c1_q)[6];
  c1_G_kathi = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 6; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_q)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 6; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_G_kathi)[c1_i3], 1U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_JointSpaceControl(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance)
{
  int32_T c1_i4;
  real_T c1_q[6];
  uint32_T c1_debug_family_var_map[22];
  real_T c1_theta_1;
  real_T c1_theta_2;
  real_T c1_theta_3;
  real_T c1_theta_4;
  real_T c1_theta_5;
  real_T c1_theta_6;
  real_T c1_m_1;
  real_T c1_m_2;
  real_T c1_m_3;
  real_T c1_m_4;
  real_T c1_m_5;
  real_T c1_m_6;
  real_T c1_g_1;
  real_T c1_g_2;
  real_T c1_g_3;
  real_T c1_g_4;
  real_T c1_g_5;
  real_T c1_g_6;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_G_kathi[6];
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b;
  real_T c1_y;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_a;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_b_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_f_b;
  real_T c1_f_y;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_c_a;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_h_b;
  real_T c1_h_y;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_d_a;
  real_T c1_i_b;
  real_T c1_i_y;
  real_T c1_e_a;
  real_T c1_j_b;
  real_T c1_j_y;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_k_b;
  real_T c1_k_y;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_f_a;
  real_T c1_l_b;
  real_T c1_l_y;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_g_a;
  real_T c1_m_b;
  real_T c1_m_y;
  real_T c1_h_a;
  real_T c1_n_b;
  real_T c1_n_y;
  real_T c1_o_b;
  real_T c1_o_y;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_p_b;
  real_T c1_p_y;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_q_b;
  real_T c1_q_y;
  real_T c1_jb_x;
  real_T c1_kb_x;
  real_T c1_i_a;
  real_T c1_r_b;
  real_T c1_r_y;
  real_T c1_lb_x;
  real_T c1_mb_x;
  real_T c1_s_b;
  real_T c1_s_y;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_j_a;
  real_T c1_t_b;
  real_T c1_t_y;
  real_T c1_u_b;
  real_T c1_u_y;
  real_T c1_pb_x;
  real_T c1_qb_x;
  real_T c1_v_b;
  real_T c1_v_y;
  real_T c1_rb_x;
  real_T c1_sb_x;
  real_T c1_w_b;
  real_T c1_w_y;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_x_b;
  real_T c1_x_y;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_k_a;
  real_T c1_y_b;
  real_T c1_y_y;
  real_T c1_xb_x;
  real_T c1_yb_x;
  real_T c1_ab_b;
  real_T c1_ab_y;
  real_T c1_ac_x;
  real_T c1_bc_x;
  real_T c1_l_a;
  real_T c1_bb_b;
  real_T c1_bb_y;
  real_T c1_cc_x;
  real_T c1_dc_x;
  real_T c1_cb_b;
  real_T c1_cb_y;
  real_T c1_ec_x;
  real_T c1_fc_x;
  real_T c1_gc_x;
  real_T c1_hc_x;
  real_T c1_m_a;
  real_T c1_db_b;
  real_T c1_db_y;
  real_T c1_ic_x;
  real_T c1_jc_x;
  real_T c1_eb_b;
  real_T c1_eb_y;
  real_T c1_kc_x;
  real_T c1_lc_x;
  real_T c1_n_a;
  real_T c1_fb_b;
  real_T c1_fb_y;
  real_T c1_o_a;
  real_T c1_gb_b;
  real_T c1_gb_y;
  real_T c1_mc_x;
  real_T c1_nc_x;
  real_T c1_hb_b;
  real_T c1_hb_y;
  real_T c1_oc_x;
  real_T c1_pc_x;
  real_T c1_qc_x;
  real_T c1_rc_x;
  real_T c1_p_a;
  real_T c1_ib_b;
  real_T c1_ib_y;
  real_T c1_sc_x;
  real_T c1_tc_x;
  real_T c1_uc_x;
  real_T c1_vc_x;
  real_T c1_q_a;
  real_T c1_jb_b;
  real_T c1_jb_y;
  real_T c1_r_a;
  real_T c1_kb_b;
  real_T c1_kb_y;
  real_T c1_wc_x;
  real_T c1_xc_x;
  real_T c1_lb_b;
  real_T c1_lb_y;
  real_T c1_yc_x;
  real_T c1_ad_x;
  real_T c1_bd_x;
  real_T c1_cd_x;
  real_T c1_dd_x;
  real_T c1_ed_x;
  real_T c1_s_a;
  real_T c1_mb_b;
  real_T c1_mb_y;
  real_T c1_fd_x;
  real_T c1_gd_x;
  real_T c1_nb_b;
  real_T c1_nb_y;
  real_T c1_hd_x;
  real_T c1_id_x;
  real_T c1_t_a;
  real_T c1_ob_b;
  real_T c1_ob_y;
  real_T c1_u_a;
  real_T c1_pb_b;
  real_T c1_pb_y;
  real_T c1_jd_x;
  real_T c1_kd_x;
  real_T c1_qb_b;
  real_T c1_qb_y;
  real_T c1_ld_x;
  real_T c1_md_x;
  real_T c1_nd_x;
  real_T c1_od_x;
  real_T c1_v_a;
  real_T c1_rb_b;
  real_T c1_rb_y;
  real_T c1_pd_x;
  real_T c1_qd_x;
  real_T c1_rd_x;
  real_T c1_sd_x;
  real_T c1_w_a;
  real_T c1_sb_b;
  real_T c1_sb_y;
  real_T c1_x_a;
  real_T c1_tb_b;
  real_T c1_tb_y;
  real_T c1_y_a;
  real_T c1_ub_b;
  real_T c1_ub_y;
  real_T c1_vb_b;
  real_T c1_vb_y;
  real_T c1_td_x;
  real_T c1_ud_x;
  real_T c1_wb_b;
  real_T c1_wb_y;
  real_T c1_vd_x;
  real_T c1_wd_x;
  real_T c1_xb_b;
  real_T c1_xb_y;
  real_T c1_xd_x;
  real_T c1_yd_x;
  real_T c1_ab_a;
  real_T c1_yb_b;
  real_T c1_yb_y;
  real_T c1_ae_x;
  real_T c1_be_x;
  real_T c1_ac_b;
  real_T c1_ac_y;
  real_T c1_ce_x;
  real_T c1_de_x;
  real_T c1_bb_a;
  real_T c1_bc_b;
  real_T c1_bc_y;
  real_T c1_ee_x;
  real_T c1_fe_x;
  real_T c1_cc_b;
  real_T c1_cc_y;
  real_T c1_ge_x;
  real_T c1_he_x;
  real_T c1_ie_x;
  real_T c1_je_x;
  real_T c1_cb_a;
  real_T c1_dc_b;
  real_T c1_dc_y;
  real_T c1_ke_x;
  real_T c1_le_x;
  real_T c1_ec_b;
  real_T c1_ec_y;
  real_T c1_me_x;
  real_T c1_ne_x;
  real_T c1_db_a;
  real_T c1_fc_b;
  real_T c1_fc_y;
  real_T c1_eb_a;
  real_T c1_gc_b;
  real_T c1_gc_y;
  real_T c1_oe_x;
  real_T c1_pe_x;
  real_T c1_hc_b;
  real_T c1_hc_y;
  real_T c1_qe_x;
  real_T c1_re_x;
  real_T c1_se_x;
  real_T c1_te_x;
  real_T c1_fb_a;
  real_T c1_ic_b;
  real_T c1_ic_y;
  real_T c1_ue_x;
  real_T c1_ve_x;
  real_T c1_we_x;
  real_T c1_xe_x;
  real_T c1_gb_a;
  real_T c1_jc_b;
  real_T c1_jc_y;
  real_T c1_hb_a;
  real_T c1_kc_b;
  real_T c1_kc_y;
  real_T c1_ye_x;
  real_T c1_af_x;
  real_T c1_lc_b;
  real_T c1_lc_y;
  real_T c1_bf_x;
  real_T c1_cf_x;
  real_T c1_df_x;
  real_T c1_ef_x;
  real_T c1_ff_x;
  real_T c1_gf_x;
  real_T c1_ib_a;
  real_T c1_mc_b;
  real_T c1_mc_y;
  real_T c1_hf_x;
  real_T c1_if_x;
  real_T c1_nc_b;
  real_T c1_nc_y;
  real_T c1_jf_x;
  real_T c1_kf_x;
  real_T c1_jb_a;
  real_T c1_oc_b;
  real_T c1_oc_y;
  real_T c1_kb_a;
  real_T c1_pc_b;
  real_T c1_pc_y;
  real_T c1_lf_x;
  real_T c1_mf_x;
  real_T c1_qc_b;
  real_T c1_qc_y;
  real_T c1_nf_x;
  real_T c1_of_x;
  real_T c1_pf_x;
  real_T c1_qf_x;
  real_T c1_lb_a;
  real_T c1_rc_b;
  real_T c1_rc_y;
  real_T c1_rf_x;
  real_T c1_sf_x;
  real_T c1_tf_x;
  real_T c1_uf_x;
  real_T c1_mb_a;
  real_T c1_sc_b;
  real_T c1_sc_y;
  real_T c1_nb_a;
  real_T c1_tc_b;
  real_T c1_tc_y;
  real_T c1_ob_a;
  real_T c1_uc_b;
  real_T c1_uc_y;
  real_T c1_vc_b;
  real_T c1_vc_y;
  real_T c1_vf_x;
  real_T c1_wf_x;
  real_T c1_wc_b;
  real_T c1_wc_y;
  real_T c1_xf_x;
  real_T c1_yf_x;
  real_T c1_pb_a;
  real_T c1_xc_b;
  real_T c1_xc_y;
  real_T c1_ag_x;
  real_T c1_bg_x;
  real_T c1_yc_b;
  real_T c1_yc_y;
  real_T c1_cg_x;
  real_T c1_dg_x;
  real_T c1_qb_a;
  real_T c1_ad_b;
  real_T c1_ad_y;
  real_T c1_eg_x;
  real_T c1_fg_x;
  real_T c1_bd_b;
  real_T c1_bd_y;
  real_T c1_gg_x;
  real_T c1_hg_x;
  real_T c1_ig_x;
  real_T c1_jg_x;
  real_T c1_rb_a;
  real_T c1_cd_b;
  real_T c1_cd_y;
  real_T c1_kg_x;
  real_T c1_lg_x;
  real_T c1_dd_b;
  real_T c1_dd_y;
  real_T c1_mg_x;
  real_T c1_ng_x;
  real_T c1_sb_a;
  real_T c1_ed_b;
  real_T c1_ed_y;
  real_T c1_tb_a;
  real_T c1_fd_b;
  real_T c1_fd_y;
  real_T c1_og_x;
  real_T c1_pg_x;
  real_T c1_gd_b;
  real_T c1_gd_y;
  real_T c1_qg_x;
  real_T c1_rg_x;
  real_T c1_sg_x;
  real_T c1_tg_x;
  real_T c1_ub_a;
  real_T c1_hd_b;
  real_T c1_hd_y;
  real_T c1_ug_x;
  real_T c1_vg_x;
  real_T c1_wg_x;
  real_T c1_xg_x;
  real_T c1_vb_a;
  real_T c1_id_b;
  real_T c1_id_y;
  real_T c1_wb_a;
  real_T c1_jd_b;
  real_T c1_jd_y;
  real_T c1_yg_x;
  real_T c1_ah_x;
  real_T c1_kd_b;
  real_T c1_kd_y;
  real_T c1_bh_x;
  real_T c1_ch_x;
  real_T c1_dh_x;
  real_T c1_eh_x;
  real_T c1_fh_x;
  real_T c1_gh_x;
  real_T c1_xb_a;
  real_T c1_ld_b;
  real_T c1_ld_y;
  real_T c1_hh_x;
  real_T c1_ih_x;
  real_T c1_md_b;
  real_T c1_md_y;
  real_T c1_jh_x;
  real_T c1_kh_x;
  real_T c1_yb_a;
  real_T c1_nd_b;
  real_T c1_nd_y;
  real_T c1_ac_a;
  real_T c1_od_b;
  real_T c1_od_y;
  real_T c1_lh_x;
  real_T c1_mh_x;
  real_T c1_pd_b;
  real_T c1_pd_y;
  real_T c1_nh_x;
  real_T c1_oh_x;
  real_T c1_ph_x;
  real_T c1_qh_x;
  real_T c1_bc_a;
  real_T c1_qd_b;
  real_T c1_qd_y;
  real_T c1_rh_x;
  real_T c1_sh_x;
  real_T c1_th_x;
  real_T c1_uh_x;
  real_T c1_cc_a;
  real_T c1_rd_b;
  real_T c1_rd_y;
  real_T c1_dc_a;
  real_T c1_sd_b;
  real_T c1_sd_y;
  real_T c1_ec_a;
  real_T c1_td_b;
  real_T c1_td_y;
  real_T c1_ud_b;
  real_T c1_ud_y;
  real_T c1_vh_x;
  real_T c1_wh_x;
  real_T c1_vd_b;
  real_T c1_vd_y;
  real_T c1_xh_x;
  real_T c1_yh_x;
  real_T c1_fc_a;
  real_T c1_wd_b;
  real_T c1_wd_y;
  real_T c1_ai_x;
  real_T c1_bi_x;
  real_T c1_xd_b;
  real_T c1_xd_y;
  real_T c1_ci_x;
  real_T c1_di_x;
  real_T c1_gc_a;
  real_T c1_yd_b;
  real_T c1_yd_y;
  real_T c1_ei_x;
  real_T c1_fi_x;
  real_T c1_ae_b;
  real_T c1_ae_y;
  real_T c1_gi_x;
  real_T c1_hi_x;
  real_T c1_ii_x;
  real_T c1_ji_x;
  real_T c1_hc_a;
  real_T c1_be_b;
  real_T c1_be_y;
  real_T c1_ki_x;
  real_T c1_li_x;
  real_T c1_ce_b;
  real_T c1_ce_y;
  real_T c1_mi_x;
  real_T c1_ni_x;
  real_T c1_ic_a;
  real_T c1_de_b;
  real_T c1_de_y;
  real_T c1_jc_a;
  real_T c1_ee_b;
  real_T c1_ee_y;
  real_T c1_oi_x;
  real_T c1_pi_x;
  real_T c1_fe_b;
  real_T c1_fe_y;
  real_T c1_qi_x;
  real_T c1_ri_x;
  real_T c1_si_x;
  real_T c1_ti_x;
  real_T c1_kc_a;
  real_T c1_ge_b;
  real_T c1_ge_y;
  real_T c1_ui_x;
  real_T c1_vi_x;
  real_T c1_wi_x;
  real_T c1_xi_x;
  real_T c1_lc_a;
  real_T c1_he_b;
  real_T c1_he_y;
  real_T c1_mc_a;
  real_T c1_ie_b;
  real_T c1_ie_y;
  real_T c1_yi_x;
  real_T c1_aj_x;
  real_T c1_je_b;
  real_T c1_je_y;
  real_T c1_bj_x;
  real_T c1_cj_x;
  real_T c1_dj_x;
  real_T c1_ej_x;
  real_T c1_fj_x;
  real_T c1_gj_x;
  real_T c1_nc_a;
  real_T c1_ke_b;
  real_T c1_ke_y;
  real_T c1_hj_x;
  real_T c1_ij_x;
  real_T c1_le_b;
  real_T c1_le_y;
  real_T c1_jj_x;
  real_T c1_kj_x;
  real_T c1_oc_a;
  real_T c1_me_b;
  real_T c1_me_y;
  real_T c1_pc_a;
  real_T c1_ne_b;
  real_T c1_ne_y;
  real_T c1_lj_x;
  real_T c1_mj_x;
  real_T c1_oe_b;
  real_T c1_oe_y;
  real_T c1_nj_x;
  real_T c1_oj_x;
  real_T c1_pj_x;
  real_T c1_qj_x;
  real_T c1_qc_a;
  real_T c1_pe_b;
  real_T c1_pe_y;
  real_T c1_rj_x;
  real_T c1_sj_x;
  real_T c1_tj_x;
  real_T c1_uj_x;
  real_T c1_rc_a;
  real_T c1_qe_b;
  real_T c1_qe_y;
  real_T c1_sc_a;
  real_T c1_re_b;
  real_T c1_re_y;
  real_T c1_tc_a;
  real_T c1_se_b;
  real_T c1_se_y;
  real_T c1_te_b;
  real_T c1_te_y;
  real_T c1_vj_x;
  real_T c1_wj_x;
  real_T c1_ue_b;
  real_T c1_ue_y;
  real_T c1_xj_x;
  real_T c1_yj_x;
  real_T c1_uc_a;
  real_T c1_ve_b;
  real_T c1_ve_y;
  real_T c1_ak_x;
  real_T c1_bk_x;
  real_T c1_we_b;
  real_T c1_we_y;
  real_T c1_ck_x;
  real_T c1_dk_x;
  real_T c1_vc_a;
  real_T c1_xe_b;
  real_T c1_xe_y;
  real_T c1_ek_x;
  real_T c1_fk_x;
  real_T c1_ye_b;
  real_T c1_ye_y;
  real_T c1_gk_x;
  real_T c1_hk_x;
  real_T c1_ik_x;
  real_T c1_jk_x;
  real_T c1_wc_a;
  real_T c1_af_b;
  real_T c1_af_y;
  real_T c1_kk_x;
  real_T c1_lk_x;
  real_T c1_bf_b;
  real_T c1_bf_y;
  real_T c1_mk_x;
  real_T c1_nk_x;
  real_T c1_xc_a;
  real_T c1_cf_b;
  real_T c1_cf_y;
  real_T c1_yc_a;
  real_T c1_df_b;
  real_T c1_df_y;
  real_T c1_ok_x;
  real_T c1_pk_x;
  real_T c1_ef_b;
  real_T c1_ef_y;
  real_T c1_qk_x;
  real_T c1_rk_x;
  real_T c1_sk_x;
  real_T c1_tk_x;
  real_T c1_ad_a;
  real_T c1_ff_b;
  real_T c1_ff_y;
  real_T c1_uk_x;
  real_T c1_vk_x;
  real_T c1_wk_x;
  real_T c1_xk_x;
  real_T c1_bd_a;
  real_T c1_gf_b;
  real_T c1_gf_y;
  real_T c1_cd_a;
  real_T c1_hf_b;
  real_T c1_hf_y;
  real_T c1_if_b;
  real_T c1_if_y;
  real_T c1_yk_x;
  real_T c1_al_x;
  real_T c1_jf_b;
  real_T c1_jf_y;
  real_T c1_bl_x;
  real_T c1_cl_x;
  real_T c1_dd_a;
  real_T c1_kf_b;
  real_T c1_kf_y;
  real_T c1_dl_x;
  real_T c1_el_x;
  real_T c1_lf_b;
  real_T c1_lf_y;
  real_T c1_fl_x;
  real_T c1_gl_x;
  real_T c1_ed_a;
  real_T c1_mf_b;
  real_T c1_mf_y;
  real_T c1_nf_b;
  real_T c1_nf_y;
  real_T c1_hl_x;
  real_T c1_il_x;
  real_T c1_of_b;
  real_T c1_of_y;
  real_T c1_jl_x;
  real_T c1_kl_x;
  real_T c1_ll_x;
  real_T c1_ml_x;
  real_T c1_fd_a;
  real_T c1_pf_b;
  real_T c1_pf_y;
  real_T c1_nl_x;
  real_T c1_ol_x;
  real_T c1_qf_b;
  real_T c1_qf_y;
  real_T c1_pl_x;
  real_T c1_ql_x;
  real_T c1_gd_a;
  real_T c1_rf_b;
  real_T c1_rf_y;
  real_T c1_hd_a;
  real_T c1_sf_b;
  real_T c1_sf_y;
  real_T c1_rl_x;
  real_T c1_sl_x;
  real_T c1_tf_b;
  real_T c1_tf_y;
  real_T c1_tl_x;
  real_T c1_ul_x;
  real_T c1_vl_x;
  real_T c1_wl_x;
  real_T c1_id_a;
  real_T c1_uf_b;
  real_T c1_uf_y;
  real_T c1_xl_x;
  real_T c1_yl_x;
  real_T c1_am_x;
  real_T c1_bm_x;
  real_T c1_jd_a;
  real_T c1_vf_b;
  real_T c1_vf_y;
  real_T c1_kd_a;
  real_T c1_wf_b;
  real_T c1_wf_y;
  real_T c1_xf_b;
  real_T c1_xf_y;
  real_T c1_cm_x;
  real_T c1_dm_x;
  real_T c1_yf_b;
  real_T c1_yf_y;
  real_T c1_em_x;
  real_T c1_fm_x;
  real_T c1_gm_x;
  real_T c1_hm_x;
  real_T c1_ld_a;
  real_T c1_ag_b;
  real_T c1_ag_y;
  real_T c1_im_x;
  real_T c1_jm_x;
  real_T c1_bg_b;
  real_T c1_bg_y;
  real_T c1_km_x;
  real_T c1_lm_x;
  real_T c1_md_a;
  real_T c1_cg_b;
  real_T c1_cg_y;
  real_T c1_nd_a;
  real_T c1_dg_b;
  real_T c1_dg_y;
  real_T c1_mm_x;
  real_T c1_nm_x;
  real_T c1_eg_b;
  real_T c1_eg_y;
  real_T c1_om_x;
  real_T c1_pm_x;
  real_T c1_qm_x;
  real_T c1_rm_x;
  real_T c1_od_a;
  real_T c1_fg_b;
  real_T c1_fg_y;
  real_T c1_sm_x;
  real_T c1_tm_x;
  real_T c1_um_x;
  real_T c1_vm_x;
  real_T c1_pd_a;
  real_T c1_gg_b;
  real_T c1_gg_y;
  real_T c1_qd_a;
  real_T c1_hg_b;
  real_T c1_hg_y;
  real_T c1_wm_x;
  real_T c1_xm_x;
  real_T c1_ig_b;
  real_T c1_ig_y;
  real_T c1_ym_x;
  real_T c1_an_x;
  real_T c1_bn_x;
  real_T c1_cn_x;
  real_T c1_dn_x;
  real_T c1_en_x;
  real_T c1_rd_a;
  real_T c1_jg_b;
  real_T c1_jg_y;
  real_T c1_fn_x;
  real_T c1_gn_x;
  real_T c1_kg_b;
  real_T c1_kg_y;
  real_T c1_hn_x;
  real_T c1_in_x;
  real_T c1_sd_a;
  real_T c1_lg_b;
  real_T c1_lg_y;
  real_T c1_td_a;
  real_T c1_mg_b;
  real_T c1_mg_y;
  real_T c1_jn_x;
  real_T c1_kn_x;
  real_T c1_ng_b;
  real_T c1_ng_y;
  real_T c1_ln_x;
  real_T c1_mn_x;
  real_T c1_nn_x;
  real_T c1_on_x;
  real_T c1_ud_a;
  real_T c1_og_b;
  real_T c1_og_y;
  real_T c1_pn_x;
  real_T c1_qn_x;
  real_T c1_rn_x;
  real_T c1_sn_x;
  real_T c1_vd_a;
  real_T c1_pg_b;
  real_T c1_pg_y;
  real_T c1_wd_a;
  real_T c1_qg_b;
  real_T c1_qg_y;
  real_T c1_xd_a;
  real_T c1_rg_b;
  real_T c1_rg_y;
  real_T c1_sg_b;
  real_T c1_sg_y;
  real_T c1_tn_x;
  real_T c1_un_x;
  real_T c1_tg_b;
  real_T c1_tg_y;
  real_T c1_vn_x;
  real_T c1_wn_x;
  real_T c1_xn_x;
  real_T c1_yn_x;
  real_T c1_yd_a;
  real_T c1_ug_b;
  real_T c1_ug_y;
  real_T c1_ao_x;
  real_T c1_bo_x;
  real_T c1_vg_b;
  real_T c1_vg_y;
  real_T c1_co_x;
  real_T c1_do_x;
  real_T c1_ae_a;
  real_T c1_wg_b;
  real_T c1_wg_y;
  real_T c1_be_a;
  real_T c1_xg_b;
  real_T c1_xg_y;
  real_T c1_eo_x;
  real_T c1_fo_x;
  real_T c1_yg_b;
  real_T c1_yg_y;
  real_T c1_go_x;
  real_T c1_ho_x;
  real_T c1_io_x;
  real_T c1_jo_x;
  real_T c1_ce_a;
  real_T c1_ah_b;
  real_T c1_ah_y;
  real_T c1_ko_x;
  real_T c1_lo_x;
  real_T c1_mo_x;
  real_T c1_no_x;
  real_T c1_de_a;
  real_T c1_bh_b;
  real_T c1_bh_y;
  real_T c1_ee_a;
  real_T c1_ch_b;
  real_T c1_ch_y;
  real_T c1_oo_x;
  real_T c1_po_x;
  real_T c1_dh_b;
  real_T c1_dh_y;
  real_T c1_qo_x;
  real_T c1_ro_x;
  real_T c1_so_x;
  real_T c1_to_x;
  real_T c1_uo_x;
  real_T c1_vo_x;
  real_T c1_fe_a;
  real_T c1_eh_b;
  real_T c1_eh_y;
  real_T c1_wo_x;
  real_T c1_xo_x;
  real_T c1_fh_b;
  real_T c1_fh_y;
  real_T c1_yo_x;
  real_T c1_ap_x;
  real_T c1_ge_a;
  real_T c1_gh_b;
  real_T c1_gh_y;
  real_T c1_he_a;
  real_T c1_hh_b;
  real_T c1_hh_y;
  real_T c1_bp_x;
  real_T c1_cp_x;
  real_T c1_ih_b;
  real_T c1_ih_y;
  real_T c1_dp_x;
  real_T c1_ep_x;
  real_T c1_fp_x;
  real_T c1_gp_x;
  real_T c1_ie_a;
  real_T c1_jh_b;
  real_T c1_jh_y;
  real_T c1_hp_x;
  real_T c1_ip_x;
  real_T c1_jp_x;
  real_T c1_kp_x;
  real_T c1_je_a;
  real_T c1_kh_b;
  real_T c1_kh_y;
  real_T c1_ke_a;
  real_T c1_lh_b;
  real_T c1_lh_y;
  real_T c1_le_a;
  real_T c1_mh_b;
  real_T c1_mh_y;
  real_T c1_nh_b;
  real_T c1_nh_y;
  real_T c1_lp_x;
  real_T c1_mp_x;
  real_T c1_oh_b;
  real_T c1_oh_y;
  real_T c1_np_x;
  real_T c1_op_x;
  real_T c1_pp_x;
  real_T c1_qp_x;
  real_T c1_rp_x;
  real_T c1_sp_x;
  real_T c1_me_a;
  real_T c1_ph_b;
  real_T c1_ph_y;
  real_T c1_tp_x;
  real_T c1_up_x;
  real_T c1_qh_b;
  real_T c1_qh_y;
  real_T c1_vp_x;
  real_T c1_wp_x;
  real_T c1_ne_a;
  real_T c1_rh_b;
  real_T c1_rh_y;
  real_T c1_oe_a;
  real_T c1_sh_b;
  real_T c1_sh_y;
  real_T c1_xp_x;
  real_T c1_yp_x;
  real_T c1_aq_x;
  real_T c1_bq_x;
  real_T c1_cq_x;
  real_T c1_dq_x;
  real_T c1_pe_a;
  real_T c1_th_b;
  real_T c1_th_y;
  real_T c1_eq_x;
  real_T c1_fq_x;
  real_T c1_gq_x;
  real_T c1_hq_x;
  real_T c1_qe_a;
  real_T c1_uh_b;
  real_T c1_uh_y;
  real_T c1_re_a;
  real_T c1_vh_b;
  real_T c1_vh_y;
  real_T c1_se_a;
  real_T c1_wh_b;
  real_T c1_wh_y;
  real_T c1_iq_x;
  real_T c1_jq_x;
  real_T c1_xh_b;
  real_T c1_xh_y;
  real_T c1_kq_x;
  real_T c1_lq_x;
  real_T c1_mq_x;
  real_T c1_nq_x;
  real_T c1_oq_x;
  real_T c1_pq_x;
  real_T c1_te_a;
  real_T c1_yh_b;
  real_T c1_yh_y;
  real_T c1_qq_x;
  real_T c1_rq_x;
  real_T c1_ai_b;
  real_T c1_ai_y;
  real_T c1_sq_x;
  real_T c1_tq_x;
  real_T c1_ue_a;
  real_T c1_bi_b;
  real_T c1_bi_y;
  real_T c1_ve_a;
  real_T c1_ci_b;
  real_T c1_ci_y;
  real_T c1_uq_x;
  real_T c1_vq_x;
  real_T c1_wq_x;
  real_T c1_xq_x;
  real_T c1_yq_x;
  real_T c1_ar_x;
  real_T c1_we_a;
  real_T c1_di_b;
  real_T c1_di_y;
  real_T c1_br_x;
  real_T c1_cr_x;
  real_T c1_dr_x;
  real_T c1_er_x;
  real_T c1_xe_a;
  real_T c1_ei_b;
  real_T c1_ei_y;
  real_T c1_ye_a;
  real_T c1_fi_b;
  real_T c1_fi_y;
  real_T c1_af_a;
  real_T c1_gi_b;
  real_T c1_gi_y;
  real_T c1_b_g_1[6];
  int32_T c1_i5;
  real_T c1_bf_a[6];
  int32_T c1_i6;
  int32_T c1_i7;
  real_T (*c1_b_G_kathi)[6];
  real_T (*c1_b_q)[6];
  c1_b_G_kathi = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 6; c1_i4++) {
    c1_q[c1_i4] = (*c1_b_q)[c1_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_theta_1, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_theta_2, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_theta_3, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_theta_4, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_theta_5, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_theta_6, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_1, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m_2, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m_3, 8U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m_4, 9U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m_5, 10U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m_6, 11U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_1, 12U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_2, 13U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_3, 14U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_4, 15U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_5, 16U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_6, 17U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 18U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 19U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_q, 20U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_G_kathi, 21U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_theta_1 = c1_q[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_theta_2 = c1_q[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_theta_3 = c1_q[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_theta_4 = c1_q[3];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_theta_5 = c1_q[4];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_theta_6 = c1_q[5];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_m_1 = 3.7;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_m_2 = 8.393;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_m_3 = 2.275;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_m_4 = 1.219;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_m_5 = 1.219;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_m_6 = 0.1879;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_g_1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_x = c1_theta_2;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarSin(c1_b_x);
  c1_b = c1_b_x;
  c1_y = 0.39243 * c1_b;
  c1_c_x = c1_theta_3;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_a = c1_y;
  c1_b_b = c1_d_x;
  c1_b_y = c1_a * c1_b_b;
  c1_e_x = c1_theta_2;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarCos(c1_f_x);
  c1_c_b = c1_f_x;
  c1_c_y = 0.39243 * c1_c_b;
  c1_g_x = c1_theta_3;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_b_a = c1_c_y;
  c1_d_b = c1_h_x;
  c1_d_y = c1_b_a * c1_d_b;
  c1_i_x = c1_theta_2;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_e_b = c1_j_x;
  c1_e_y = 0.425 * c1_e_b;
  c1_k_x = c1_theta_4;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarSin(c1_l_x);
  c1_f_b = c1_l_x;
  c1_f_y = 0.01634 * c1_f_b;
  c1_m_x = c1_theta_2;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarCos(c1_n_x);
  c1_o_x = c1_theta_3;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarCos(c1_p_x);
  c1_c_a = c1_n_x;
  c1_g_b = c1_p_x;
  c1_g_y = c1_c_a * c1_g_b;
  c1_q_x = c1_theta_2;
  c1_r_x = c1_q_x;
  c1_r_x = muDoubleScalarSin(c1_r_x);
  c1_h_b = c1_r_x;
  c1_h_y = c1_h_b;
  c1_s_x = c1_theta_3;
  c1_t_x = c1_s_x;
  c1_t_x = muDoubleScalarSin(c1_t_x);
  c1_d_a = c1_h_y;
  c1_i_b = c1_t_x;
  c1_i_y = c1_d_a * c1_i_b;
  c1_e_a = c1_f_y;
  c1_j_b = c1_g_y - c1_i_y;
  c1_j_y = c1_e_a * c1_j_b;
  c1_u_x = c1_theta_4;
  c1_v_x = c1_u_x;
  c1_v_x = muDoubleScalarCos(c1_v_x);
  c1_k_b = c1_v_x;
  c1_k_y = 0.01634 * c1_k_b;
  c1_w_x = c1_theta_2;
  c1_x_x = c1_w_x;
  c1_x_x = muDoubleScalarCos(c1_x_x);
  c1_y_x = c1_theta_3;
  c1_ab_x = c1_y_x;
  c1_ab_x = muDoubleScalarSin(c1_ab_x);
  c1_f_a = c1_x_x;
  c1_l_b = c1_ab_x;
  c1_l_y = c1_f_a * c1_l_b;
  c1_bb_x = c1_theta_3;
  c1_cb_x = c1_bb_x;
  c1_cb_x = muDoubleScalarCos(c1_cb_x);
  c1_db_x = c1_theta_2;
  c1_eb_x = c1_db_x;
  c1_eb_x = muDoubleScalarSin(c1_eb_x);
  c1_g_a = c1_cb_x;
  c1_m_b = c1_eb_x;
  c1_m_y = c1_g_a * c1_m_b;
  c1_h_a = c1_k_y;
  c1_n_b = c1_l_y + c1_m_y;
  c1_n_y = c1_h_a * c1_n_b;
  c1_o_b = (((c1_b_y - c1_d_y) - c1_e_y) + c1_j_y) + c1_n_y;
  c1_o_y = 11.958390000000001 * c1_o_b;
  c1_fb_x = c1_theta_2;
  c1_gb_x = c1_fb_x;
  c1_gb_x = muDoubleScalarCos(c1_gb_x);
  c1_p_b = c1_gb_x;
  c1_p_y = 0.425 * c1_p_b;
  c1_hb_x = c1_theta_2;
  c1_ib_x = c1_hb_x;
  c1_ib_x = muDoubleScalarCos(c1_ib_x);
  c1_q_b = c1_ib_x;
  c1_q_y = 0.2725 * c1_q_b;
  c1_jb_x = c1_theta_3;
  c1_kb_x = c1_jb_x;
  c1_kb_x = muDoubleScalarCos(c1_kb_x);
  c1_i_a = c1_q_y;
  c1_r_b = c1_kb_x;
  c1_r_y = c1_i_a * c1_r_b;
  c1_lb_x = c1_theta_2;
  c1_mb_x = c1_lb_x;
  c1_mb_x = muDoubleScalarSin(c1_mb_x);
  c1_s_b = c1_mb_x;
  c1_s_y = 0.2725 * c1_s_b;
  c1_nb_x = c1_theta_3;
  c1_ob_x = c1_nb_x;
  c1_ob_x = muDoubleScalarSin(c1_ob_x);
  c1_j_a = c1_s_y;
  c1_t_b = c1_ob_x;
  c1_t_y = c1_j_a * c1_t_b;
  c1_u_b = (c1_p_y + c1_r_y) - c1_t_y;
  c1_u_y = 22.31775 * c1_u_b;
  c1_pb_x = c1_theta_2;
  c1_qb_x = c1_pb_x;
  c1_qb_x = muDoubleScalarCos(c1_qb_x);
  c1_v_b = c1_qb_x;
  c1_v_y = 17.496257625000002 * c1_v_b;
  c1_rb_x = c1_theta_2;
  c1_sb_x = c1_rb_x;
  c1_sb_x = muDoubleScalarCos(c1_sb_x);
  c1_w_b = c1_sb_x;
  c1_w_y = 0.425 * c1_w_b;
  c1_tb_x = c1_theta_2;
  c1_ub_x = c1_tb_x;
  c1_ub_x = muDoubleScalarCos(c1_ub_x);
  c1_x_b = c1_ub_x;
  c1_x_y = 0.39243 * c1_x_b;
  c1_vb_x = c1_theta_3;
  c1_wb_x = c1_vb_x;
  c1_wb_x = muDoubleScalarCos(c1_wb_x);
  c1_k_a = c1_x_y;
  c1_y_b = c1_wb_x;
  c1_y_y = c1_k_a * c1_y_b;
  c1_xb_x = c1_theta_2;
  c1_yb_x = c1_xb_x;
  c1_yb_x = muDoubleScalarSin(c1_yb_x);
  c1_ab_b = c1_yb_x;
  c1_ab_y = 0.39243 * c1_ab_b;
  c1_ac_x = c1_theta_3;
  c1_bc_x = c1_ac_x;
  c1_bc_x = muDoubleScalarSin(c1_bc_x);
  c1_l_a = c1_ab_y;
  c1_bb_b = c1_bc_x;
  c1_bb_y = c1_l_a * c1_bb_b;
  c1_cc_x = c1_theta_4;
  c1_dc_x = c1_cc_x;
  c1_dc_x = muDoubleScalarSin(c1_dc_x);
  c1_cb_b = c1_dc_x;
  c1_cb_y = 0.0912 * c1_cb_b;
  c1_ec_x = c1_theta_2;
  c1_fc_x = c1_ec_x;
  c1_fc_x = muDoubleScalarCos(c1_fc_x);
  c1_gc_x = c1_theta_3;
  c1_hc_x = c1_gc_x;
  c1_hc_x = muDoubleScalarCos(c1_hc_x);
  c1_m_a = c1_fc_x;
  c1_db_b = c1_hc_x;
  c1_db_y = c1_m_a * c1_db_b;
  c1_ic_x = c1_theta_2;
  c1_jc_x = c1_ic_x;
  c1_jc_x = muDoubleScalarSin(c1_jc_x);
  c1_eb_b = c1_jc_x;
  c1_eb_y = c1_eb_b;
  c1_kc_x = c1_theta_3;
  c1_lc_x = c1_kc_x;
  c1_lc_x = muDoubleScalarSin(c1_lc_x);
  c1_n_a = c1_eb_y;
  c1_fb_b = c1_lc_x;
  c1_fb_y = c1_n_a * c1_fb_b;
  c1_o_a = c1_cb_y;
  c1_gb_b = c1_db_y - c1_fb_y;
  c1_gb_y = c1_o_a * c1_gb_b;
  c1_mc_x = c1_theta_4;
  c1_nc_x = c1_mc_x;
  c1_nc_x = muDoubleScalarCos(c1_nc_x);
  c1_hb_b = c1_nc_x;
  c1_hb_y = 0.0912 * c1_hb_b;
  c1_oc_x = c1_theta_2;
  c1_pc_x = c1_oc_x;
  c1_pc_x = muDoubleScalarCos(c1_pc_x);
  c1_qc_x = c1_theta_3;
  c1_rc_x = c1_qc_x;
  c1_rc_x = muDoubleScalarSin(c1_rc_x);
  c1_p_a = c1_pc_x;
  c1_ib_b = c1_rc_x;
  c1_ib_y = c1_p_a * c1_ib_b;
  c1_sc_x = c1_theta_3;
  c1_tc_x = c1_sc_x;
  c1_tc_x = muDoubleScalarCos(c1_tc_x);
  c1_uc_x = c1_theta_2;
  c1_vc_x = c1_uc_x;
  c1_vc_x = muDoubleScalarSin(c1_vc_x);
  c1_q_a = c1_tc_x;
  c1_jb_b = c1_vc_x;
  c1_jb_y = c1_q_a * c1_jb_b;
  c1_r_a = c1_hb_y;
  c1_kb_b = c1_ib_y + c1_jb_y;
  c1_kb_y = c1_r_a * c1_kb_b;
  c1_wc_x = c1_theta_5;
  c1_xc_x = c1_wc_x;
  c1_xc_x = muDoubleScalarSin(c1_xc_x);
  c1_lb_b = c1_xc_x;
  c1_lb_y = 0.01634 * c1_lb_b;
  c1_yc_x = c1_theta_4;
  c1_ad_x = c1_yc_x;
  c1_ad_x = muDoubleScalarCos(c1_ad_x);
  c1_bd_x = c1_theta_2;
  c1_cd_x = c1_bd_x;
  c1_cd_x = muDoubleScalarCos(c1_cd_x);
  c1_dd_x = c1_theta_3;
  c1_ed_x = c1_dd_x;
  c1_ed_x = muDoubleScalarCos(c1_ed_x);
  c1_s_a = c1_cd_x;
  c1_mb_b = c1_ed_x;
  c1_mb_y = c1_s_a * c1_mb_b;
  c1_fd_x = c1_theta_2;
  c1_gd_x = c1_fd_x;
  c1_gd_x = muDoubleScalarSin(c1_gd_x);
  c1_nb_b = c1_gd_x;
  c1_nb_y = c1_nb_b;
  c1_hd_x = c1_theta_3;
  c1_id_x = c1_hd_x;
  c1_id_x = muDoubleScalarSin(c1_id_x);
  c1_t_a = c1_nb_y;
  c1_ob_b = c1_id_x;
  c1_ob_y = c1_t_a * c1_ob_b;
  c1_u_a = c1_ad_x;
  c1_pb_b = c1_mb_y - c1_ob_y;
  c1_pb_y = c1_u_a * c1_pb_b;
  c1_jd_x = c1_theta_4;
  c1_kd_x = c1_jd_x;
  c1_kd_x = muDoubleScalarSin(c1_kd_x);
  c1_qb_b = c1_kd_x;
  c1_qb_y = c1_qb_b;
  c1_ld_x = c1_theta_2;
  c1_md_x = c1_ld_x;
  c1_md_x = muDoubleScalarCos(c1_md_x);
  c1_nd_x = c1_theta_3;
  c1_od_x = c1_nd_x;
  c1_od_x = muDoubleScalarSin(c1_od_x);
  c1_v_a = c1_md_x;
  c1_rb_b = c1_od_x;
  c1_rb_y = c1_v_a * c1_rb_b;
  c1_pd_x = c1_theta_3;
  c1_qd_x = c1_pd_x;
  c1_qd_x = muDoubleScalarCos(c1_qd_x);
  c1_rd_x = c1_theta_2;
  c1_sd_x = c1_rd_x;
  c1_sd_x = muDoubleScalarSin(c1_sd_x);
  c1_w_a = c1_qd_x;
  c1_sb_b = c1_sd_x;
  c1_sb_y = c1_w_a * c1_sb_b;
  c1_x_a = c1_qb_y;
  c1_tb_b = c1_rb_y + c1_sb_y;
  c1_tb_y = c1_x_a * c1_tb_b;
  c1_y_a = c1_lb_y;
  c1_ub_b = c1_pb_y - c1_tb_y;
  c1_ub_y = c1_y_a * c1_ub_b;
  c1_vb_b = ((((c1_w_y + c1_y_y) - c1_bb_y) - c1_gb_y) - c1_kb_y) + c1_ub_y;
  c1_vb_y = 11.958390000000001 * c1_vb_b;
  c1_td_x = c1_theta_2;
  c1_ud_x = c1_td_x;
  c1_ud_x = muDoubleScalarCos(c1_ud_x);
  c1_wb_b = c1_ud_x;
  c1_wb_y = 0.425 * c1_wb_b;
  c1_vd_x = c1_theta_2;
  c1_wd_x = c1_vd_x;
  c1_wd_x = muDoubleScalarCos(c1_wd_x);
  c1_xb_b = c1_wd_x;
  c1_xb_y = 0.39243 * c1_xb_b;
  c1_xd_x = c1_theta_3;
  c1_yd_x = c1_xd_x;
  c1_yd_x = muDoubleScalarCos(c1_yd_x);
  c1_ab_a = c1_xb_y;
  c1_yb_b = c1_yd_x;
  c1_yb_y = c1_ab_a * c1_yb_b;
  c1_ae_x = c1_theta_2;
  c1_be_x = c1_ae_x;
  c1_be_x = muDoubleScalarSin(c1_be_x);
  c1_ac_b = c1_be_x;
  c1_ac_y = 0.39243 * c1_ac_b;
  c1_ce_x = c1_theta_3;
  c1_de_x = c1_ce_x;
  c1_de_x = muDoubleScalarSin(c1_de_x);
  c1_bb_a = c1_ac_y;
  c1_bc_b = c1_de_x;
  c1_bc_y = c1_bb_a * c1_bc_b;
  c1_ee_x = c1_theta_4;
  c1_fe_x = c1_ee_x;
  c1_fe_x = muDoubleScalarSin(c1_fe_x);
  c1_cc_b = c1_fe_x;
  c1_cc_y = 0.093 * c1_cc_b;
  c1_ge_x = c1_theta_2;
  c1_he_x = c1_ge_x;
  c1_he_x = muDoubleScalarCos(c1_he_x);
  c1_ie_x = c1_theta_3;
  c1_je_x = c1_ie_x;
  c1_je_x = muDoubleScalarCos(c1_je_x);
  c1_cb_a = c1_he_x;
  c1_dc_b = c1_je_x;
  c1_dc_y = c1_cb_a * c1_dc_b;
  c1_ke_x = c1_theta_2;
  c1_le_x = c1_ke_x;
  c1_le_x = muDoubleScalarSin(c1_le_x);
  c1_ec_b = c1_le_x;
  c1_ec_y = c1_ec_b;
  c1_me_x = c1_theta_3;
  c1_ne_x = c1_me_x;
  c1_ne_x = muDoubleScalarSin(c1_ne_x);
  c1_db_a = c1_ec_y;
  c1_fc_b = c1_ne_x;
  c1_fc_y = c1_db_a * c1_fc_b;
  c1_eb_a = c1_cc_y;
  c1_gc_b = c1_dc_y - c1_fc_y;
  c1_gc_y = c1_eb_a * c1_gc_b;
  c1_oe_x = c1_theta_4;
  c1_pe_x = c1_oe_x;
  c1_pe_x = muDoubleScalarCos(c1_pe_x);
  c1_hc_b = c1_pe_x;
  c1_hc_y = 0.093 * c1_hc_b;
  c1_qe_x = c1_theta_2;
  c1_re_x = c1_qe_x;
  c1_re_x = muDoubleScalarCos(c1_re_x);
  c1_se_x = c1_theta_3;
  c1_te_x = c1_se_x;
  c1_te_x = muDoubleScalarSin(c1_te_x);
  c1_fb_a = c1_re_x;
  c1_ic_b = c1_te_x;
  c1_ic_y = c1_fb_a * c1_ic_b;
  c1_ue_x = c1_theta_3;
  c1_ve_x = c1_ue_x;
  c1_ve_x = muDoubleScalarCos(c1_ve_x);
  c1_we_x = c1_theta_2;
  c1_xe_x = c1_we_x;
  c1_xe_x = muDoubleScalarSin(c1_xe_x);
  c1_gb_a = c1_ve_x;
  c1_jc_b = c1_xe_x;
  c1_jc_y = c1_gb_a * c1_jc_b;
  c1_hb_a = c1_hc_y;
  c1_kc_b = c1_ic_y + c1_jc_y;
  c1_kc_y = c1_hb_a * c1_kc_b;
  c1_ye_x = c1_theta_5;
  c1_af_x = c1_ye_x;
  c1_af_x = muDoubleScalarSin(c1_af_x);
  c1_lc_b = c1_af_x;
  c1_lc_y = 0.080841 * c1_lc_b;
  c1_bf_x = c1_theta_4;
  c1_cf_x = c1_bf_x;
  c1_cf_x = muDoubleScalarCos(c1_cf_x);
  c1_df_x = c1_theta_2;
  c1_ef_x = c1_df_x;
  c1_ef_x = muDoubleScalarCos(c1_ef_x);
  c1_ff_x = c1_theta_3;
  c1_gf_x = c1_ff_x;
  c1_gf_x = muDoubleScalarCos(c1_gf_x);
  c1_ib_a = c1_ef_x;
  c1_mc_b = c1_gf_x;
  c1_mc_y = c1_ib_a * c1_mc_b;
  c1_hf_x = c1_theta_2;
  c1_if_x = c1_hf_x;
  c1_if_x = muDoubleScalarSin(c1_if_x);
  c1_nc_b = c1_if_x;
  c1_nc_y = c1_nc_b;
  c1_jf_x = c1_theta_3;
  c1_kf_x = c1_jf_x;
  c1_kf_x = muDoubleScalarSin(c1_kf_x);
  c1_jb_a = c1_nc_y;
  c1_oc_b = c1_kf_x;
  c1_oc_y = c1_jb_a * c1_oc_b;
  c1_kb_a = c1_cf_x;
  c1_pc_b = c1_mc_y - c1_oc_y;
  c1_pc_y = c1_kb_a * c1_pc_b;
  c1_lf_x = c1_theta_4;
  c1_mf_x = c1_lf_x;
  c1_mf_x = muDoubleScalarSin(c1_mf_x);
  c1_qc_b = c1_mf_x;
  c1_qc_y = c1_qc_b;
  c1_nf_x = c1_theta_2;
  c1_of_x = c1_nf_x;
  c1_of_x = muDoubleScalarCos(c1_of_x);
  c1_pf_x = c1_theta_3;
  c1_qf_x = c1_pf_x;
  c1_qf_x = muDoubleScalarSin(c1_qf_x);
  c1_lb_a = c1_of_x;
  c1_rc_b = c1_qf_x;
  c1_rc_y = c1_lb_a * c1_rc_b;
  c1_rf_x = c1_theta_3;
  c1_sf_x = c1_rf_x;
  c1_sf_x = muDoubleScalarCos(c1_sf_x);
  c1_tf_x = c1_theta_2;
  c1_uf_x = c1_tf_x;
  c1_uf_x = muDoubleScalarSin(c1_uf_x);
  c1_mb_a = c1_sf_x;
  c1_sc_b = c1_uf_x;
  c1_sc_y = c1_mb_a * c1_sc_b;
  c1_nb_a = c1_qc_y;
  c1_tc_b = c1_rc_y + c1_sc_y;
  c1_tc_y = c1_nb_a * c1_tc_b;
  c1_ob_a = c1_lc_y;
  c1_uc_b = c1_pc_y - c1_tc_y;
  c1_uc_y = c1_ob_a * c1_uc_b;
  c1_vc_b = ((((c1_wb_y + c1_yb_y) - c1_bc_y) - c1_gc_y) - c1_kc_y) + c1_uc_y;
  c1_vc_y = 1.8432990000000002 * c1_vc_b;
  c1_g_2 = (((c1_o_y - c1_u_y) - c1_v_y) - c1_vb_y) - c1_vc_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_vf_x = c1_theta_2;
  c1_wf_x = c1_vf_x;
  c1_wf_x = muDoubleScalarSin(c1_wf_x);
  c1_wc_b = c1_wf_x;
  c1_wc_y = 0.39243 * c1_wc_b;
  c1_xf_x = c1_theta_3;
  c1_yf_x = c1_xf_x;
  c1_yf_x = muDoubleScalarSin(c1_yf_x);
  c1_pb_a = c1_wc_y;
  c1_xc_b = c1_yf_x;
  c1_xc_y = c1_pb_a * c1_xc_b;
  c1_ag_x = c1_theta_2;
  c1_bg_x = c1_ag_x;
  c1_bg_x = muDoubleScalarCos(c1_bg_x);
  c1_yc_b = c1_bg_x;
  c1_yc_y = 0.39243 * c1_yc_b;
  c1_cg_x = c1_theta_3;
  c1_dg_x = c1_cg_x;
  c1_dg_x = muDoubleScalarCos(c1_dg_x);
  c1_qb_a = c1_yc_y;
  c1_ad_b = c1_dg_x;
  c1_ad_y = c1_qb_a * c1_ad_b;
  c1_eg_x = c1_theta_4;
  c1_fg_x = c1_eg_x;
  c1_fg_x = muDoubleScalarSin(c1_fg_x);
  c1_bd_b = c1_fg_x;
  c1_bd_y = 0.093 * c1_bd_b;
  c1_gg_x = c1_theta_2;
  c1_hg_x = c1_gg_x;
  c1_hg_x = muDoubleScalarCos(c1_hg_x);
  c1_ig_x = c1_theta_3;
  c1_jg_x = c1_ig_x;
  c1_jg_x = muDoubleScalarCos(c1_jg_x);
  c1_rb_a = c1_hg_x;
  c1_cd_b = c1_jg_x;
  c1_cd_y = c1_rb_a * c1_cd_b;
  c1_kg_x = c1_theta_2;
  c1_lg_x = c1_kg_x;
  c1_lg_x = muDoubleScalarSin(c1_lg_x);
  c1_dd_b = c1_lg_x;
  c1_dd_y = c1_dd_b;
  c1_mg_x = c1_theta_3;
  c1_ng_x = c1_mg_x;
  c1_ng_x = muDoubleScalarSin(c1_ng_x);
  c1_sb_a = c1_dd_y;
  c1_ed_b = c1_ng_x;
  c1_ed_y = c1_sb_a * c1_ed_b;
  c1_tb_a = c1_bd_y;
  c1_fd_b = c1_cd_y - c1_ed_y;
  c1_fd_y = c1_tb_a * c1_fd_b;
  c1_og_x = c1_theta_4;
  c1_pg_x = c1_og_x;
  c1_pg_x = muDoubleScalarCos(c1_pg_x);
  c1_gd_b = c1_pg_x;
  c1_gd_y = 0.093 * c1_gd_b;
  c1_qg_x = c1_theta_2;
  c1_rg_x = c1_qg_x;
  c1_rg_x = muDoubleScalarCos(c1_rg_x);
  c1_sg_x = c1_theta_3;
  c1_tg_x = c1_sg_x;
  c1_tg_x = muDoubleScalarSin(c1_tg_x);
  c1_ub_a = c1_rg_x;
  c1_hd_b = c1_tg_x;
  c1_hd_y = c1_ub_a * c1_hd_b;
  c1_ug_x = c1_theta_3;
  c1_vg_x = c1_ug_x;
  c1_vg_x = muDoubleScalarCos(c1_vg_x);
  c1_wg_x = c1_theta_2;
  c1_xg_x = c1_wg_x;
  c1_xg_x = muDoubleScalarSin(c1_xg_x);
  c1_vb_a = c1_vg_x;
  c1_id_b = c1_xg_x;
  c1_id_y = c1_vb_a * c1_id_b;
  c1_wb_a = c1_gd_y;
  c1_jd_b = c1_hd_y + c1_id_y;
  c1_jd_y = c1_wb_a * c1_jd_b;
  c1_yg_x = c1_theta_5;
  c1_ah_x = c1_yg_x;
  c1_ah_x = muDoubleScalarSin(c1_ah_x);
  c1_kd_b = c1_ah_x;
  c1_kd_y = 0.080841 * c1_kd_b;
  c1_bh_x = c1_theta_4;
  c1_ch_x = c1_bh_x;
  c1_ch_x = muDoubleScalarCos(c1_ch_x);
  c1_dh_x = c1_theta_2;
  c1_eh_x = c1_dh_x;
  c1_eh_x = muDoubleScalarCos(c1_eh_x);
  c1_fh_x = c1_theta_3;
  c1_gh_x = c1_fh_x;
  c1_gh_x = muDoubleScalarCos(c1_gh_x);
  c1_xb_a = c1_eh_x;
  c1_ld_b = c1_gh_x;
  c1_ld_y = c1_xb_a * c1_ld_b;
  c1_hh_x = c1_theta_2;
  c1_ih_x = c1_hh_x;
  c1_ih_x = muDoubleScalarSin(c1_ih_x);
  c1_md_b = c1_ih_x;
  c1_md_y = c1_md_b;
  c1_jh_x = c1_theta_3;
  c1_kh_x = c1_jh_x;
  c1_kh_x = muDoubleScalarSin(c1_kh_x);
  c1_yb_a = c1_md_y;
  c1_nd_b = c1_kh_x;
  c1_nd_y = c1_yb_a * c1_nd_b;
  c1_ac_a = c1_ch_x;
  c1_od_b = c1_ld_y - c1_nd_y;
  c1_od_y = c1_ac_a * c1_od_b;
  c1_lh_x = c1_theta_4;
  c1_mh_x = c1_lh_x;
  c1_mh_x = muDoubleScalarSin(c1_mh_x);
  c1_pd_b = c1_mh_x;
  c1_pd_y = c1_pd_b;
  c1_nh_x = c1_theta_2;
  c1_oh_x = c1_nh_x;
  c1_oh_x = muDoubleScalarCos(c1_oh_x);
  c1_ph_x = c1_theta_3;
  c1_qh_x = c1_ph_x;
  c1_qh_x = muDoubleScalarSin(c1_qh_x);
  c1_bc_a = c1_oh_x;
  c1_qd_b = c1_qh_x;
  c1_qd_y = c1_bc_a * c1_qd_b;
  c1_rh_x = c1_theta_3;
  c1_sh_x = c1_rh_x;
  c1_sh_x = muDoubleScalarCos(c1_sh_x);
  c1_th_x = c1_theta_2;
  c1_uh_x = c1_th_x;
  c1_uh_x = muDoubleScalarSin(c1_uh_x);
  c1_cc_a = c1_sh_x;
  c1_rd_b = c1_uh_x;
  c1_rd_y = c1_cc_a * c1_rd_b;
  c1_dc_a = c1_pd_y;
  c1_sd_b = c1_qd_y + c1_rd_y;
  c1_sd_y = c1_dc_a * c1_sd_b;
  c1_ec_a = c1_kd_y;
  c1_td_b = c1_od_y - c1_sd_y;
  c1_td_y = c1_ec_a * c1_td_b;
  c1_ud_b = (((c1_xc_y - c1_ad_y) + c1_fd_y) + c1_jd_y) - c1_td_y;
  c1_ud_y = 1.8432990000000002 * c1_ud_b;
  c1_vh_x = c1_theta_2;
  c1_wh_x = c1_vh_x;
  c1_wh_x = muDoubleScalarSin(c1_wh_x);
  c1_vd_b = c1_wh_x;
  c1_vd_y = 0.39243 * c1_vd_b;
  c1_xh_x = c1_theta_3;
  c1_yh_x = c1_xh_x;
  c1_yh_x = muDoubleScalarSin(c1_yh_x);
  c1_fc_a = c1_vd_y;
  c1_wd_b = c1_yh_x;
  c1_wd_y = c1_fc_a * c1_wd_b;
  c1_ai_x = c1_theta_2;
  c1_bi_x = c1_ai_x;
  c1_bi_x = muDoubleScalarCos(c1_bi_x);
  c1_xd_b = c1_bi_x;
  c1_xd_y = 0.39243 * c1_xd_b;
  c1_ci_x = c1_theta_3;
  c1_di_x = c1_ci_x;
  c1_di_x = muDoubleScalarCos(c1_di_x);
  c1_gc_a = c1_xd_y;
  c1_yd_b = c1_di_x;
  c1_yd_y = c1_gc_a * c1_yd_b;
  c1_ei_x = c1_theta_4;
  c1_fi_x = c1_ei_x;
  c1_fi_x = muDoubleScalarSin(c1_fi_x);
  c1_ae_b = c1_fi_x;
  c1_ae_y = 0.0912 * c1_ae_b;
  c1_gi_x = c1_theta_2;
  c1_hi_x = c1_gi_x;
  c1_hi_x = muDoubleScalarCos(c1_hi_x);
  c1_ii_x = c1_theta_3;
  c1_ji_x = c1_ii_x;
  c1_ji_x = muDoubleScalarCos(c1_ji_x);
  c1_hc_a = c1_hi_x;
  c1_be_b = c1_ji_x;
  c1_be_y = c1_hc_a * c1_be_b;
  c1_ki_x = c1_theta_2;
  c1_li_x = c1_ki_x;
  c1_li_x = muDoubleScalarSin(c1_li_x);
  c1_ce_b = c1_li_x;
  c1_ce_y = c1_ce_b;
  c1_mi_x = c1_theta_3;
  c1_ni_x = c1_mi_x;
  c1_ni_x = muDoubleScalarSin(c1_ni_x);
  c1_ic_a = c1_ce_y;
  c1_de_b = c1_ni_x;
  c1_de_y = c1_ic_a * c1_de_b;
  c1_jc_a = c1_ae_y;
  c1_ee_b = c1_be_y - c1_de_y;
  c1_ee_y = c1_jc_a * c1_ee_b;
  c1_oi_x = c1_theta_4;
  c1_pi_x = c1_oi_x;
  c1_pi_x = muDoubleScalarCos(c1_pi_x);
  c1_fe_b = c1_pi_x;
  c1_fe_y = 0.0912 * c1_fe_b;
  c1_qi_x = c1_theta_2;
  c1_ri_x = c1_qi_x;
  c1_ri_x = muDoubleScalarCos(c1_ri_x);
  c1_si_x = c1_theta_3;
  c1_ti_x = c1_si_x;
  c1_ti_x = muDoubleScalarSin(c1_ti_x);
  c1_kc_a = c1_ri_x;
  c1_ge_b = c1_ti_x;
  c1_ge_y = c1_kc_a * c1_ge_b;
  c1_ui_x = c1_theta_3;
  c1_vi_x = c1_ui_x;
  c1_vi_x = muDoubleScalarCos(c1_vi_x);
  c1_wi_x = c1_theta_2;
  c1_xi_x = c1_wi_x;
  c1_xi_x = muDoubleScalarSin(c1_xi_x);
  c1_lc_a = c1_vi_x;
  c1_he_b = c1_xi_x;
  c1_he_y = c1_lc_a * c1_he_b;
  c1_mc_a = c1_fe_y;
  c1_ie_b = c1_ge_y + c1_he_y;
  c1_ie_y = c1_mc_a * c1_ie_b;
  c1_yi_x = c1_theta_5;
  c1_aj_x = c1_yi_x;
  c1_aj_x = muDoubleScalarSin(c1_aj_x);
  c1_je_b = c1_aj_x;
  c1_je_y = 0.01634 * c1_je_b;
  c1_bj_x = c1_theta_4;
  c1_cj_x = c1_bj_x;
  c1_cj_x = muDoubleScalarCos(c1_cj_x);
  c1_dj_x = c1_theta_2;
  c1_ej_x = c1_dj_x;
  c1_ej_x = muDoubleScalarCos(c1_ej_x);
  c1_fj_x = c1_theta_3;
  c1_gj_x = c1_fj_x;
  c1_gj_x = muDoubleScalarCos(c1_gj_x);
  c1_nc_a = c1_ej_x;
  c1_ke_b = c1_gj_x;
  c1_ke_y = c1_nc_a * c1_ke_b;
  c1_hj_x = c1_theta_2;
  c1_ij_x = c1_hj_x;
  c1_ij_x = muDoubleScalarSin(c1_ij_x);
  c1_le_b = c1_ij_x;
  c1_le_y = c1_le_b;
  c1_jj_x = c1_theta_3;
  c1_kj_x = c1_jj_x;
  c1_kj_x = muDoubleScalarSin(c1_kj_x);
  c1_oc_a = c1_le_y;
  c1_me_b = c1_kj_x;
  c1_me_y = c1_oc_a * c1_me_b;
  c1_pc_a = c1_cj_x;
  c1_ne_b = c1_ke_y - c1_me_y;
  c1_ne_y = c1_pc_a * c1_ne_b;
  c1_lj_x = c1_theta_4;
  c1_mj_x = c1_lj_x;
  c1_mj_x = muDoubleScalarSin(c1_mj_x);
  c1_oe_b = c1_mj_x;
  c1_oe_y = c1_oe_b;
  c1_nj_x = c1_theta_2;
  c1_oj_x = c1_nj_x;
  c1_oj_x = muDoubleScalarCos(c1_oj_x);
  c1_pj_x = c1_theta_3;
  c1_qj_x = c1_pj_x;
  c1_qj_x = muDoubleScalarSin(c1_qj_x);
  c1_qc_a = c1_oj_x;
  c1_pe_b = c1_qj_x;
  c1_pe_y = c1_qc_a * c1_pe_b;
  c1_rj_x = c1_theta_3;
  c1_sj_x = c1_rj_x;
  c1_sj_x = muDoubleScalarCos(c1_sj_x);
  c1_tj_x = c1_theta_2;
  c1_uj_x = c1_tj_x;
  c1_uj_x = muDoubleScalarSin(c1_uj_x);
  c1_rc_a = c1_sj_x;
  c1_qe_b = c1_uj_x;
  c1_qe_y = c1_rc_a * c1_qe_b;
  c1_sc_a = c1_oe_y;
  c1_re_b = c1_pe_y + c1_qe_y;
  c1_re_y = c1_sc_a * c1_re_b;
  c1_tc_a = c1_je_y;
  c1_se_b = c1_ne_y - c1_re_y;
  c1_se_y = c1_tc_a * c1_se_b;
  c1_te_b = (((c1_wd_y - c1_yd_y) + c1_ee_y) + c1_ie_y) - c1_se_y;
  c1_te_y = 11.958390000000001 * c1_te_b;
  c1_vj_x = c1_theta_2;
  c1_wj_x = c1_vj_x;
  c1_wj_x = muDoubleScalarSin(c1_wj_x);
  c1_ue_b = c1_wj_x;
  c1_ue_y = 0.39243 * c1_ue_b;
  c1_xj_x = c1_theta_3;
  c1_yj_x = c1_xj_x;
  c1_yj_x = muDoubleScalarSin(c1_yj_x);
  c1_uc_a = c1_ue_y;
  c1_ve_b = c1_yj_x;
  c1_ve_y = c1_uc_a * c1_ve_b;
  c1_ak_x = c1_theta_2;
  c1_bk_x = c1_ak_x;
  c1_bk_x = muDoubleScalarCos(c1_bk_x);
  c1_we_b = c1_bk_x;
  c1_we_y = 0.39243 * c1_we_b;
  c1_ck_x = c1_theta_3;
  c1_dk_x = c1_ck_x;
  c1_dk_x = muDoubleScalarCos(c1_dk_x);
  c1_vc_a = c1_we_y;
  c1_xe_b = c1_dk_x;
  c1_xe_y = c1_vc_a * c1_xe_b;
  c1_ek_x = c1_theta_4;
  c1_fk_x = c1_ek_x;
  c1_fk_x = muDoubleScalarSin(c1_fk_x);
  c1_ye_b = c1_fk_x;
  c1_ye_y = 0.01634 * c1_ye_b;
  c1_gk_x = c1_theta_2;
  c1_hk_x = c1_gk_x;
  c1_hk_x = muDoubleScalarCos(c1_hk_x);
  c1_ik_x = c1_theta_3;
  c1_jk_x = c1_ik_x;
  c1_jk_x = muDoubleScalarCos(c1_jk_x);
  c1_wc_a = c1_hk_x;
  c1_af_b = c1_jk_x;
  c1_af_y = c1_wc_a * c1_af_b;
  c1_kk_x = c1_theta_2;
  c1_lk_x = c1_kk_x;
  c1_lk_x = muDoubleScalarSin(c1_lk_x);
  c1_bf_b = c1_lk_x;
  c1_bf_y = c1_bf_b;
  c1_mk_x = c1_theta_3;
  c1_nk_x = c1_mk_x;
  c1_nk_x = muDoubleScalarSin(c1_nk_x);
  c1_xc_a = c1_bf_y;
  c1_cf_b = c1_nk_x;
  c1_cf_y = c1_xc_a * c1_cf_b;
  c1_yc_a = c1_ye_y;
  c1_df_b = c1_af_y - c1_cf_y;
  c1_df_y = c1_yc_a * c1_df_b;
  c1_ok_x = c1_theta_4;
  c1_pk_x = c1_ok_x;
  c1_pk_x = muDoubleScalarCos(c1_pk_x);
  c1_ef_b = c1_pk_x;
  c1_ef_y = 0.01634 * c1_ef_b;
  c1_qk_x = c1_theta_2;
  c1_rk_x = c1_qk_x;
  c1_rk_x = muDoubleScalarCos(c1_rk_x);
  c1_sk_x = c1_theta_3;
  c1_tk_x = c1_sk_x;
  c1_tk_x = muDoubleScalarSin(c1_tk_x);
  c1_ad_a = c1_rk_x;
  c1_ff_b = c1_tk_x;
  c1_ff_y = c1_ad_a * c1_ff_b;
  c1_uk_x = c1_theta_3;
  c1_vk_x = c1_uk_x;
  c1_vk_x = muDoubleScalarCos(c1_vk_x);
  c1_wk_x = c1_theta_2;
  c1_xk_x = c1_wk_x;
  c1_xk_x = muDoubleScalarSin(c1_xk_x);
  c1_bd_a = c1_vk_x;
  c1_gf_b = c1_xk_x;
  c1_gf_y = c1_bd_a * c1_gf_b;
  c1_cd_a = c1_ef_y;
  c1_hf_b = c1_ff_y + c1_gf_y;
  c1_hf_y = c1_cd_a * c1_hf_b;
  c1_if_b = ((c1_ve_y - c1_xe_y) + c1_df_y) + c1_hf_y;
  c1_if_y = 11.958390000000001 * c1_if_b;
  c1_yk_x = c1_theta_2;
  c1_al_x = c1_yk_x;
  c1_al_x = muDoubleScalarCos(c1_al_x);
  c1_jf_b = c1_al_x;
  c1_jf_y = 0.2725 * c1_jf_b;
  c1_bl_x = c1_theta_3;
  c1_cl_x = c1_bl_x;
  c1_cl_x = muDoubleScalarCos(c1_cl_x);
  c1_dd_a = c1_jf_y;
  c1_kf_b = c1_cl_x;
  c1_kf_y = c1_dd_a * c1_kf_b;
  c1_dl_x = c1_theta_2;
  c1_el_x = c1_dl_x;
  c1_el_x = muDoubleScalarSin(c1_el_x);
  c1_lf_b = c1_el_x;
  c1_lf_y = 0.2725 * c1_lf_b;
  c1_fl_x = c1_theta_3;
  c1_gl_x = c1_fl_x;
  c1_gl_x = muDoubleScalarSin(c1_gl_x);
  c1_ed_a = c1_lf_y;
  c1_mf_b = c1_gl_x;
  c1_mf_y = c1_ed_a * c1_mf_b;
  c1_nf_b = c1_kf_y - c1_mf_y;
  c1_nf_y = 22.31775 * c1_nf_b;
  c1_g_3 = ((c1_ud_y + c1_te_y) + c1_if_y) - c1_nf_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_hl_x = c1_theta_4;
  c1_il_x = c1_hl_x;
  c1_il_x = muDoubleScalarSin(c1_il_x);
  c1_of_b = c1_il_x;
  c1_of_y = 0.01634 * c1_of_b;
  c1_jl_x = c1_theta_2;
  c1_kl_x = c1_jl_x;
  c1_kl_x = muDoubleScalarCos(c1_kl_x);
  c1_ll_x = c1_theta_3;
  c1_ml_x = c1_ll_x;
  c1_ml_x = muDoubleScalarCos(c1_ml_x);
  c1_fd_a = c1_kl_x;
  c1_pf_b = c1_ml_x;
  c1_pf_y = c1_fd_a * c1_pf_b;
  c1_nl_x = c1_theta_2;
  c1_ol_x = c1_nl_x;
  c1_ol_x = muDoubleScalarSin(c1_ol_x);
  c1_qf_b = c1_ol_x;
  c1_qf_y = c1_qf_b;
  c1_pl_x = c1_theta_3;
  c1_ql_x = c1_pl_x;
  c1_ql_x = muDoubleScalarSin(c1_ql_x);
  c1_gd_a = c1_qf_y;
  c1_rf_b = c1_ql_x;
  c1_rf_y = c1_gd_a * c1_rf_b;
  c1_hd_a = c1_of_y;
  c1_sf_b = c1_pf_y - c1_rf_y;
  c1_sf_y = c1_hd_a * c1_sf_b;
  c1_rl_x = c1_theta_4;
  c1_sl_x = c1_rl_x;
  c1_sl_x = muDoubleScalarCos(c1_sl_x);
  c1_tf_b = c1_sl_x;
  c1_tf_y = 0.01634 * c1_tf_b;
  c1_tl_x = c1_theta_2;
  c1_ul_x = c1_tl_x;
  c1_ul_x = muDoubleScalarCos(c1_ul_x);
  c1_vl_x = c1_theta_3;
  c1_wl_x = c1_vl_x;
  c1_wl_x = muDoubleScalarSin(c1_wl_x);
  c1_id_a = c1_ul_x;
  c1_uf_b = c1_wl_x;
  c1_uf_y = c1_id_a * c1_uf_b;
  c1_xl_x = c1_theta_3;
  c1_yl_x = c1_xl_x;
  c1_yl_x = muDoubleScalarCos(c1_yl_x);
  c1_am_x = c1_theta_2;
  c1_bm_x = c1_am_x;
  c1_bm_x = muDoubleScalarSin(c1_bm_x);
  c1_jd_a = c1_yl_x;
  c1_vf_b = c1_bm_x;
  c1_vf_y = c1_jd_a * c1_vf_b;
  c1_kd_a = c1_tf_y;
  c1_wf_b = c1_uf_y + c1_vf_y;
  c1_wf_y = c1_kd_a * c1_wf_b;
  c1_xf_b = c1_sf_y + c1_wf_y;
  c1_xf_y = 11.958390000000001 * c1_xf_b;
  c1_cm_x = c1_theta_4;
  c1_dm_x = c1_cm_x;
  c1_dm_x = muDoubleScalarSin(c1_dm_x);
  c1_yf_b = c1_dm_x;
  c1_yf_y = 0.093 * c1_yf_b;
  c1_em_x = c1_theta_2;
  c1_fm_x = c1_em_x;
  c1_fm_x = muDoubleScalarCos(c1_fm_x);
  c1_gm_x = c1_theta_3;
  c1_hm_x = c1_gm_x;
  c1_hm_x = muDoubleScalarCos(c1_hm_x);
  c1_ld_a = c1_fm_x;
  c1_ag_b = c1_hm_x;
  c1_ag_y = c1_ld_a * c1_ag_b;
  c1_im_x = c1_theta_2;
  c1_jm_x = c1_im_x;
  c1_jm_x = muDoubleScalarSin(c1_jm_x);
  c1_bg_b = c1_jm_x;
  c1_bg_y = c1_bg_b;
  c1_km_x = c1_theta_3;
  c1_lm_x = c1_km_x;
  c1_lm_x = muDoubleScalarSin(c1_lm_x);
  c1_md_a = c1_bg_y;
  c1_cg_b = c1_lm_x;
  c1_cg_y = c1_md_a * c1_cg_b;
  c1_nd_a = c1_yf_y;
  c1_dg_b = c1_ag_y - c1_cg_y;
  c1_dg_y = c1_nd_a * c1_dg_b;
  c1_mm_x = c1_theta_4;
  c1_nm_x = c1_mm_x;
  c1_nm_x = muDoubleScalarCos(c1_nm_x);
  c1_eg_b = c1_nm_x;
  c1_eg_y = 0.093 * c1_eg_b;
  c1_om_x = c1_theta_2;
  c1_pm_x = c1_om_x;
  c1_pm_x = muDoubleScalarCos(c1_pm_x);
  c1_qm_x = c1_theta_3;
  c1_rm_x = c1_qm_x;
  c1_rm_x = muDoubleScalarSin(c1_rm_x);
  c1_od_a = c1_pm_x;
  c1_fg_b = c1_rm_x;
  c1_fg_y = c1_od_a * c1_fg_b;
  c1_sm_x = c1_theta_3;
  c1_tm_x = c1_sm_x;
  c1_tm_x = muDoubleScalarCos(c1_tm_x);
  c1_um_x = c1_theta_2;
  c1_vm_x = c1_um_x;
  c1_vm_x = muDoubleScalarSin(c1_vm_x);
  c1_pd_a = c1_tm_x;
  c1_gg_b = c1_vm_x;
  c1_gg_y = c1_pd_a * c1_gg_b;
  c1_qd_a = c1_eg_y;
  c1_hg_b = c1_fg_y + c1_gg_y;
  c1_hg_y = c1_qd_a * c1_hg_b;
  c1_wm_x = c1_theta_5;
  c1_xm_x = c1_wm_x;
  c1_xm_x = muDoubleScalarSin(c1_xm_x);
  c1_ig_b = c1_xm_x;
  c1_ig_y = 0.080841 * c1_ig_b;
  c1_ym_x = c1_theta_4;
  c1_an_x = c1_ym_x;
  c1_an_x = muDoubleScalarCos(c1_an_x);
  c1_bn_x = c1_theta_2;
  c1_cn_x = c1_bn_x;
  c1_cn_x = muDoubleScalarCos(c1_cn_x);
  c1_dn_x = c1_theta_3;
  c1_en_x = c1_dn_x;
  c1_en_x = muDoubleScalarCos(c1_en_x);
  c1_rd_a = c1_cn_x;
  c1_jg_b = c1_en_x;
  c1_jg_y = c1_rd_a * c1_jg_b;
  c1_fn_x = c1_theta_2;
  c1_gn_x = c1_fn_x;
  c1_gn_x = muDoubleScalarSin(c1_gn_x);
  c1_kg_b = c1_gn_x;
  c1_kg_y = c1_kg_b;
  c1_hn_x = c1_theta_3;
  c1_in_x = c1_hn_x;
  c1_in_x = muDoubleScalarSin(c1_in_x);
  c1_sd_a = c1_kg_y;
  c1_lg_b = c1_in_x;
  c1_lg_y = c1_sd_a * c1_lg_b;
  c1_td_a = c1_an_x;
  c1_mg_b = c1_jg_y - c1_lg_y;
  c1_mg_y = c1_td_a * c1_mg_b;
  c1_jn_x = c1_theta_4;
  c1_kn_x = c1_jn_x;
  c1_kn_x = muDoubleScalarSin(c1_kn_x);
  c1_ng_b = c1_kn_x;
  c1_ng_y = c1_ng_b;
  c1_ln_x = c1_theta_2;
  c1_mn_x = c1_ln_x;
  c1_mn_x = muDoubleScalarCos(c1_mn_x);
  c1_nn_x = c1_theta_3;
  c1_on_x = c1_nn_x;
  c1_on_x = muDoubleScalarSin(c1_on_x);
  c1_ud_a = c1_mn_x;
  c1_og_b = c1_on_x;
  c1_og_y = c1_ud_a * c1_og_b;
  c1_pn_x = c1_theta_3;
  c1_qn_x = c1_pn_x;
  c1_qn_x = muDoubleScalarCos(c1_qn_x);
  c1_rn_x = c1_theta_2;
  c1_sn_x = c1_rn_x;
  c1_sn_x = muDoubleScalarSin(c1_sn_x);
  c1_vd_a = c1_qn_x;
  c1_pg_b = c1_sn_x;
  c1_pg_y = c1_vd_a * c1_pg_b;
  c1_wd_a = c1_ng_y;
  c1_qg_b = c1_og_y + c1_pg_y;
  c1_qg_y = c1_wd_a * c1_qg_b;
  c1_xd_a = c1_ig_y;
  c1_rg_b = c1_mg_y - c1_qg_y;
  c1_rg_y = c1_xd_a * c1_rg_b;
  c1_sg_b = (c1_dg_y + c1_hg_y) - c1_rg_y;
  c1_sg_y = 1.8432990000000002 * c1_sg_b;
  c1_tn_x = c1_theta_4;
  c1_un_x = c1_tn_x;
  c1_un_x = muDoubleScalarSin(c1_un_x);
  c1_tg_b = c1_un_x;
  c1_tg_y = 0.0912 * c1_tg_b;
  c1_vn_x = c1_theta_2;
  c1_wn_x = c1_vn_x;
  c1_wn_x = muDoubleScalarCos(c1_wn_x);
  c1_xn_x = c1_theta_3;
  c1_yn_x = c1_xn_x;
  c1_yn_x = muDoubleScalarCos(c1_yn_x);
  c1_yd_a = c1_wn_x;
  c1_ug_b = c1_yn_x;
  c1_ug_y = c1_yd_a * c1_ug_b;
  c1_ao_x = c1_theta_2;
  c1_bo_x = c1_ao_x;
  c1_bo_x = muDoubleScalarSin(c1_bo_x);
  c1_vg_b = c1_bo_x;
  c1_vg_y = c1_vg_b;
  c1_co_x = c1_theta_3;
  c1_do_x = c1_co_x;
  c1_do_x = muDoubleScalarSin(c1_do_x);
  c1_ae_a = c1_vg_y;
  c1_wg_b = c1_do_x;
  c1_wg_y = c1_ae_a * c1_wg_b;
  c1_be_a = c1_tg_y;
  c1_xg_b = c1_ug_y - c1_wg_y;
  c1_xg_y = c1_be_a * c1_xg_b;
  c1_eo_x = c1_theta_4;
  c1_fo_x = c1_eo_x;
  c1_fo_x = muDoubleScalarCos(c1_fo_x);
  c1_yg_b = c1_fo_x;
  c1_yg_y = 0.0912 * c1_yg_b;
  c1_go_x = c1_theta_2;
  c1_ho_x = c1_go_x;
  c1_ho_x = muDoubleScalarCos(c1_ho_x);
  c1_io_x = c1_theta_3;
  c1_jo_x = c1_io_x;
  c1_jo_x = muDoubleScalarSin(c1_jo_x);
  c1_ce_a = c1_ho_x;
  c1_ah_b = c1_jo_x;
  c1_ah_y = c1_ce_a * c1_ah_b;
  c1_ko_x = c1_theta_3;
  c1_lo_x = c1_ko_x;
  c1_lo_x = muDoubleScalarCos(c1_lo_x);
  c1_mo_x = c1_theta_2;
  c1_no_x = c1_mo_x;
  c1_no_x = muDoubleScalarSin(c1_no_x);
  c1_de_a = c1_lo_x;
  c1_bh_b = c1_no_x;
  c1_bh_y = c1_de_a * c1_bh_b;
  c1_ee_a = c1_yg_y;
  c1_ch_b = c1_ah_y + c1_bh_y;
  c1_ch_y = c1_ee_a * c1_ch_b;
  c1_oo_x = c1_theta_5;
  c1_po_x = c1_oo_x;
  c1_po_x = muDoubleScalarSin(c1_po_x);
  c1_dh_b = c1_po_x;
  c1_dh_y = 0.01634 * c1_dh_b;
  c1_qo_x = c1_theta_4;
  c1_ro_x = c1_qo_x;
  c1_ro_x = muDoubleScalarCos(c1_ro_x);
  c1_so_x = c1_theta_2;
  c1_to_x = c1_so_x;
  c1_to_x = muDoubleScalarCos(c1_to_x);
  c1_uo_x = c1_theta_3;
  c1_vo_x = c1_uo_x;
  c1_vo_x = muDoubleScalarCos(c1_vo_x);
  c1_fe_a = c1_to_x;
  c1_eh_b = c1_vo_x;
  c1_eh_y = c1_fe_a * c1_eh_b;
  c1_wo_x = c1_theta_2;
  c1_xo_x = c1_wo_x;
  c1_xo_x = muDoubleScalarSin(c1_xo_x);
  c1_fh_b = c1_xo_x;
  c1_fh_y = c1_fh_b;
  c1_yo_x = c1_theta_3;
  c1_ap_x = c1_yo_x;
  c1_ap_x = muDoubleScalarSin(c1_ap_x);
  c1_ge_a = c1_fh_y;
  c1_gh_b = c1_ap_x;
  c1_gh_y = c1_ge_a * c1_gh_b;
  c1_he_a = c1_ro_x;
  c1_hh_b = c1_eh_y - c1_gh_y;
  c1_hh_y = c1_he_a * c1_hh_b;
  c1_bp_x = c1_theta_4;
  c1_cp_x = c1_bp_x;
  c1_cp_x = muDoubleScalarSin(c1_cp_x);
  c1_ih_b = c1_cp_x;
  c1_ih_y = c1_ih_b;
  c1_dp_x = c1_theta_2;
  c1_ep_x = c1_dp_x;
  c1_ep_x = muDoubleScalarCos(c1_ep_x);
  c1_fp_x = c1_theta_3;
  c1_gp_x = c1_fp_x;
  c1_gp_x = muDoubleScalarSin(c1_gp_x);
  c1_ie_a = c1_ep_x;
  c1_jh_b = c1_gp_x;
  c1_jh_y = c1_ie_a * c1_jh_b;
  c1_hp_x = c1_theta_3;
  c1_ip_x = c1_hp_x;
  c1_ip_x = muDoubleScalarCos(c1_ip_x);
  c1_jp_x = c1_theta_2;
  c1_kp_x = c1_jp_x;
  c1_kp_x = muDoubleScalarSin(c1_kp_x);
  c1_je_a = c1_ip_x;
  c1_kh_b = c1_kp_x;
  c1_kh_y = c1_je_a * c1_kh_b;
  c1_ke_a = c1_ih_y;
  c1_lh_b = c1_jh_y + c1_kh_y;
  c1_lh_y = c1_ke_a * c1_lh_b;
  c1_le_a = c1_dh_y;
  c1_mh_b = c1_hh_y - c1_lh_y;
  c1_mh_y = c1_le_a * c1_mh_b;
  c1_nh_b = (c1_xg_y + c1_ch_y) - c1_mh_y;
  c1_nh_y = 11.958390000000001 * c1_nh_b;
  c1_g_4 = (c1_xf_y + c1_sg_y) + c1_nh_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_lp_x = c1_theta_5;
  c1_mp_x = c1_lp_x;
  c1_mp_x = muDoubleScalarCos(c1_mp_x);
  c1_oh_b = c1_mp_x;
  c1_oh_y = -0.19540009260000002 * c1_oh_b;
  c1_np_x = c1_theta_4;
  c1_op_x = c1_np_x;
  c1_op_x = muDoubleScalarSin(c1_op_x);
  c1_pp_x = c1_theta_2;
  c1_qp_x = c1_pp_x;
  c1_qp_x = muDoubleScalarCos(c1_qp_x);
  c1_rp_x = c1_theta_3;
  c1_sp_x = c1_rp_x;
  c1_sp_x = muDoubleScalarCos(c1_sp_x);
  c1_me_a = c1_qp_x;
  c1_ph_b = c1_sp_x;
  c1_ph_y = c1_me_a * c1_ph_b;
  c1_tp_x = c1_theta_2;
  c1_up_x = c1_tp_x;
  c1_up_x = muDoubleScalarSin(c1_up_x);
  c1_qh_b = c1_up_x;
  c1_qh_y = c1_qh_b;
  c1_vp_x = c1_theta_3;
  c1_wp_x = c1_vp_x;
  c1_wp_x = muDoubleScalarSin(c1_wp_x);
  c1_ne_a = c1_qh_y;
  c1_rh_b = c1_wp_x;
  c1_rh_y = c1_ne_a * c1_rh_b;
  c1_oe_a = c1_op_x;
  c1_sh_b = c1_ph_y - c1_rh_y;
  c1_sh_y = c1_oe_a * c1_sh_b;
  c1_xp_x = c1_theta_4;
  c1_yp_x = c1_xp_x;
  c1_yp_x = muDoubleScalarCos(c1_yp_x);
  c1_aq_x = c1_theta_2;
  c1_bq_x = c1_aq_x;
  c1_bq_x = muDoubleScalarCos(c1_bq_x);
  c1_cq_x = c1_theta_3;
  c1_dq_x = c1_cq_x;
  c1_dq_x = muDoubleScalarSin(c1_dq_x);
  c1_pe_a = c1_bq_x;
  c1_th_b = c1_dq_x;
  c1_th_y = c1_pe_a * c1_th_b;
  c1_eq_x = c1_theta_3;
  c1_fq_x = c1_eq_x;
  c1_fq_x = muDoubleScalarCos(c1_fq_x);
  c1_gq_x = c1_theta_2;
  c1_hq_x = c1_gq_x;
  c1_hq_x = muDoubleScalarSin(c1_hq_x);
  c1_qe_a = c1_fq_x;
  c1_uh_b = c1_hq_x;
  c1_uh_y = c1_qe_a * c1_uh_b;
  c1_re_a = c1_yp_x;
  c1_vh_b = c1_th_y + c1_uh_y;
  c1_vh_y = c1_re_a * c1_vh_b;
  c1_se_a = c1_oh_y;
  c1_wh_b = c1_sh_y + c1_vh_y;
  c1_wh_y = c1_se_a * c1_wh_b;
  c1_iq_x = c1_theta_5;
  c1_jq_x = c1_iq_x;
  c1_jq_x = muDoubleScalarCos(c1_jq_x);
  c1_xh_b = c1_jq_x;
  c1_xh_y = 0.149014134459 * c1_xh_b;
  c1_kq_x = c1_theta_4;
  c1_lq_x = c1_kq_x;
  c1_lq_x = muDoubleScalarSin(c1_lq_x);
  c1_mq_x = c1_theta_2;
  c1_nq_x = c1_mq_x;
  c1_nq_x = muDoubleScalarCos(c1_nq_x);
  c1_oq_x = c1_theta_3;
  c1_pq_x = c1_oq_x;
  c1_pq_x = muDoubleScalarCos(c1_pq_x);
  c1_te_a = c1_nq_x;
  c1_yh_b = c1_pq_x;
  c1_yh_y = c1_te_a * c1_yh_b;
  c1_qq_x = c1_theta_2;
  c1_rq_x = c1_qq_x;
  c1_rq_x = muDoubleScalarSin(c1_rq_x);
  c1_ai_b = c1_rq_x;
  c1_ai_y = c1_ai_b;
  c1_sq_x = c1_theta_3;
  c1_tq_x = c1_sq_x;
  c1_tq_x = muDoubleScalarSin(c1_tq_x);
  c1_ue_a = c1_ai_y;
  c1_bi_b = c1_tq_x;
  c1_bi_y = c1_ue_a * c1_bi_b;
  c1_ve_a = c1_lq_x;
  c1_ci_b = c1_yh_y - c1_bi_y;
  c1_ci_y = c1_ve_a * c1_ci_b;
  c1_uq_x = c1_theta_4;
  c1_vq_x = c1_uq_x;
  c1_vq_x = muDoubleScalarCos(c1_vq_x);
  c1_wq_x = c1_theta_2;
  c1_xq_x = c1_wq_x;
  c1_xq_x = muDoubleScalarCos(c1_xq_x);
  c1_yq_x = c1_theta_3;
  c1_ar_x = c1_yq_x;
  c1_ar_x = muDoubleScalarSin(c1_ar_x);
  c1_we_a = c1_xq_x;
  c1_di_b = c1_ar_x;
  c1_di_y = c1_we_a * c1_di_b;
  c1_br_x = c1_theta_3;
  c1_cr_x = c1_br_x;
  c1_cr_x = muDoubleScalarCos(c1_cr_x);
  c1_dr_x = c1_theta_2;
  c1_er_x = c1_dr_x;
  c1_er_x = muDoubleScalarSin(c1_er_x);
  c1_xe_a = c1_cr_x;
  c1_ei_b = c1_er_x;
  c1_ei_y = c1_xe_a * c1_ei_b;
  c1_ye_a = c1_vq_x;
  c1_fi_b = c1_di_y + c1_ei_y;
  c1_fi_y = c1_ye_a * c1_fi_b;
  c1_af_a = c1_xh_y;
  c1_gi_b = c1_ci_y + c1_fi_y;
  c1_gi_y = c1_af_a * c1_gi_b;
  c1_g_5 = c1_wh_y - c1_gi_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_g_6 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
  c1_b_g_1[0] = c1_g_1;
  c1_b_g_1[1] = c1_g_2;
  c1_b_g_1[2] = c1_g_3;
  c1_b_g_1[3] = c1_g_4;
  c1_b_g_1[4] = c1_g_5;
  c1_b_g_1[5] = c1_g_6;
  for (c1_i5 = 0; c1_i5 < 6; c1_i5++) {
    c1_bf_a[c1_i5] = c1_b_g_1[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 6; c1_i6++) {
    c1_G_kathi[c1_i6] = -c1_bf_a[c1_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i7 = 0; c1_i7 < 6; c1_i7++) {
    (*c1_b_G_kathi)[c1_i7] = c1_G_kathi[c1_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_JointSpaceControl
  (SFc1_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i8;
  real_T c1_b_inData[6];
  int32_T c1_i9;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i8 = 0; c1_i8 < 6; c1_i8++) {
    c1_b_inData[c1_i8] = (*(real_T (*)[6])c1_inData)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 6; c1_i9++) {
    c1_u[c1_i9] = c1_b_inData[c1_i9];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_G_kathi, const char_T *c1_identifier, real_T
  c1_y[6])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_G_kathi), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_G_kathi);
}

static void c1_b_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6])
{
  real_T c1_dv1[6];
  int32_T c1_i10;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c1_i10 = 0; c1_i10 < 6; c1_i10++) {
    c1_y[c1_i10] = c1_dv1[c1_i10];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_G_kathi;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i11;
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c1_G_kathi = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_G_kathi), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_G_kathi);
  for (c1_i11 = 0; c1_i11 < 6; c1_i11++) {
    (*(real_T (*)[6])c1_outData)[c1_i11] = c1_y[c1_i11];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_JointSpaceControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[5];
  c1_ResolvedFunctionInfo (*c1_b_info)[5];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i12;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[5])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289541292U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "sin";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[1].fileTimeLo = 1343851986U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[2].name = "eml_scalar_sin";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c1_b_info)[2].fileTimeLo = 1286840336U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "cos";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[3].fileTimeLo = 1343851972U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[4].name = "eml_scalar_cos";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c1_b_info)[4].fileTimeLo = 1286840322U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c1_i12 = 0; c1_i12 < 5; c1_i12++) {
    c1_r0 = &c1_info[c1_i12];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i12);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i13;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i13, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i13;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_JointSpaceControl, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_JointSpaceControl), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_JointSpaceControl);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_JointSpaceControlInstanceStruct
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

void sf_c1_JointSpaceControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4122631785U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(989625498U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(487477604U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(581372451U);
}

mxArray *sf_c1_JointSpaceControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4hvO4MJMLhBByurHC9NBoC");
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

mxArray *sf_c1_JointSpaceControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_JointSpaceControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"G_kathi\",},{M[8],M[0],T\"is_active_c1_JointSpaceControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_JointSpaceControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_JointSpaceControlInstanceStruct *chartInstance;
    chartInstance = (SFc1_JointSpaceControlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControlMachineNumber_,
           1,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"G_kathi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,6923);
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
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T (*c1_q)[6];
          real_T (*c1_G_kathi)[6];
          c1_G_kathi = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_q);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_G_kathi);
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
  return "RmygvV7o3EghyFcRG43pZG";
}

static void sf_opaque_initialize_c1_JointSpaceControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
  initialize_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_JointSpaceControl(void *chartInstanceVar)
{
  enable_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_JointSpaceControl(void *chartInstanceVar)
{
  disable_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_JointSpaceControl(void *chartInstanceVar)
{
  sf_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_JointSpaceControl(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_JointSpaceControl
    ((SFc1_JointSpaceControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_JointSpaceControl();/* state var info */
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

extern void sf_internal_set_sim_state_c1_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_JointSpaceControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_JointSpaceControl(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_JointSpaceControl(S);
}

static void sf_opaque_set_sim_state_c1_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_JointSpaceControl(S, st);
}

static void sf_opaque_terminate_c1_JointSpaceControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_JointSpaceControlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_optimization_info();
    }

    finalize_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_JointSpaceControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_JointSpaceControl((SFc1_JointSpaceControlInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1824272835U));
  ssSetChecksum1(S,(2268314673U));
  ssSetChecksum2(S,(471824355U));
  ssSetChecksum3(S,(2927898491U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_JointSpaceControl(SimStruct *S)
{
  SFc1_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc1_JointSpaceControlInstanceStruct *)utMalloc(sizeof
    (SFc1_JointSpaceControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_JointSpaceControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_JointSpaceControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_JointSpaceControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_JointSpaceControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_JointSpaceControl;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_JointSpaceControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_JointSpaceControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_JointSpaceControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_JointSpaceControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_JointSpaceControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_JointSpaceControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_JointSpaceControl;
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

void c1_JointSpaceControl_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_JointSpaceControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_JointSpaceControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
