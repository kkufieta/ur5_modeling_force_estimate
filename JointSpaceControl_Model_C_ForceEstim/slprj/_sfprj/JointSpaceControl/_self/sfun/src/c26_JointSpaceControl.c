/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_sfun.h"
#include "c26_JointSpaceControl.h"
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
static const char * c26_debug_family_names[16] = { "theta_1", "theta_2",
  "theta_3", "theta_4", "theta_5", "theta_6", "m_1", "m_2", "m_3", "m_4", "m_5",
  "m_6", "nargin", "nargout", "q", "P" };

/* Function Declarations */
static void initialize_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static void initialize_params_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static void enable_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct
  *chartInstance);
static void disable_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct *
  chartInstance);
static void c26_update_debugger_state_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static void set_sim_state_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c26_st);
static void finalize_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct
  *chartInstance);
static void sf_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct
  *chartInstance);
static void c26_chartstep_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static void initSimStructsc26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static void registerMessagesc26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static real_T c26_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_P, const char_T *c26_identifier);
static real_T c26_b_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_c_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static uint8_T c26_d_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_JointSpaceControl, const
  char_T *c26_identifier);
static uint8_T c26_e_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void init_dsm_address_info(SFc26_JointSpaceControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
  chartInstance->c26_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c26_is_active_c26_JointSpaceControl = 0U;
}

static void initialize_params_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void enable_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c26_update_debugger_state_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
  const mxArray *c26_st;
  const mxArray *c26_y = NULL;
  real_T c26_hoistedGlobal;
  real_T c26_u;
  const mxArray *c26_b_y = NULL;
  uint8_T c26_b_hoistedGlobal;
  uint8_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  real_T *c26_P;
  c26_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellarray(2), FALSE);
  c26_hoistedGlobal = *c26_P;
  c26_u = c26_hoistedGlobal;
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_b_hoistedGlobal = chartInstance->c26_is_active_c26_JointSpaceControl;
  c26_b_u = c26_b_hoistedGlobal;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 1, c26_c_y);
  sf_mex_assign(&c26_st, c26_y, FALSE);
  return c26_st;
}

static void set_sim_state_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c26_st)
{
  const mxArray *c26_u;
  real_T *c26_P;
  c26_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c26_doneDoubleBufferReInit = TRUE;
  c26_u = sf_mex_dup(c26_st);
  *c26_P = c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c26_u,
    0)), "P");
  chartInstance->c26_is_active_c26_JointSpaceControl = c26_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 1)),
     "is_active_c26_JointSpaceControl");
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_JointSpaceControl(chartInstance);
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct
  *chartInstance)
{
}

static void sf_c26_JointSpaceControl(SFc26_JointSpaceControlInstanceStruct
  *chartInstance)
{
  int32_T c26_i0;
  real_T *c26_P;
  real_T (*c26_q)[6];
  c26_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 23U, chartInstance->c26_sfEvent);
  for (c26_i0 = 0; c26_i0 < 6; c26_i0++) {
    _SFD_DATA_RANGE_CHECK((*c26_q)[c26_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c26_P, 1U);
  chartInstance->c26_sfEvent = CALL_EVENT;
  c26_chartstep_c26_JointSpaceControl(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c26_chartstep_c26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
  int32_T c26_i1;
  real_T c26_q[6];
  uint32_T c26_debug_family_var_map[16];
  real_T c26_theta_1;
  real_T c26_theta_2;
  real_T c26_theta_3;
  real_T c26_theta_4;
  real_T c26_theta_5;
  real_T c26_theta_6;
  real_T c26_m_1;
  real_T c26_m_2;
  real_T c26_m_3;
  real_T c26_m_4;
  real_T c26_m_5;
  real_T c26_m_6;
  real_T c26_nargin = 1.0;
  real_T c26_nargout = 1.0;
  real_T c26_P;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_b;
  real_T c26_y;
  real_T c26_A;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_b_y;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_b_b;
  real_T c26_c_y;
  real_T c26_g_x;
  real_T c26_h_x;
  real_T c26_a;
  real_T c26_c_b;
  real_T c26_d_y;
  real_T c26_b_A;
  real_T c26_i_x;
  real_T c26_j_x;
  real_T c26_e_y;
  real_T c26_k_x;
  real_T c26_l_x;
  real_T c26_d_b;
  real_T c26_f_y;
  real_T c26_m_x;
  real_T c26_n_x;
  real_T c26_b_a;
  real_T c26_e_b;
  real_T c26_g_y;
  real_T c26_c_A;
  real_T c26_o_x;
  real_T c26_p_x;
  real_T c26_h_y;
  real_T c26_q_x;
  real_T c26_r_x;
  real_T c26_f_b;
  real_T c26_i_y;
  real_T c26_s_x;
  real_T c26_t_x;
  real_T c26_u_x;
  real_T c26_v_x;
  real_T c26_w_x;
  real_T c26_x_x;
  real_T c26_c_a;
  real_T c26_g_b;
  real_T c26_j_y;
  real_T c26_y_x;
  real_T c26_ab_x;
  real_T c26_bb_x;
  real_T c26_cb_x;
  real_T c26_d_a;
  real_T c26_h_b;
  real_T c26_k_y;
  real_T c26_e_a;
  real_T c26_i_b;
  real_T c26_l_y;
  real_T c26_db_x;
  real_T c26_eb_x;
  real_T c26_fb_x;
  real_T c26_gb_x;
  real_T c26_hb_x;
  real_T c26_ib_x;
  real_T c26_f_a;
  real_T c26_j_b;
  real_T c26_m_y;
  real_T c26_jb_x;
  real_T c26_kb_x;
  real_T c26_lb_x;
  real_T c26_mb_x;
  real_T c26_g_a;
  real_T c26_k_b;
  real_T c26_n_y;
  real_T c26_h_a;
  real_T c26_l_b;
  real_T c26_o_y;
  real_T c26_i_a;
  real_T c26_m_b;
  real_T c26_p_y;
  real_T c26_d_A;
  real_T c26_nb_x;
  real_T c26_ob_x;
  real_T c26_q_y;
  real_T c26_pb_x;
  real_T c26_qb_x;
  real_T c26_n_b;
  real_T c26_r_y;
  real_T c26_rb_x;
  real_T c26_sb_x;
  real_T c26_tb_x;
  real_T c26_ub_x;
  real_T c26_j_a;
  real_T c26_o_b;
  real_T c26_s_y;
  real_T c26_vb_x;
  real_T c26_wb_x;
  real_T c26_xb_x;
  real_T c26_yb_x;
  real_T c26_k_a;
  real_T c26_p_b;
  real_T c26_t_y;
  real_T c26_l_a;
  real_T c26_q_b;
  real_T c26_u_y;
  real_T c26_e_A;
  real_T c26_ac_x;
  real_T c26_bc_x;
  real_T c26_v_y;
  real_T c26_cc_x;
  real_T c26_dc_x;
  real_T c26_r_b;
  real_T c26_w_y;
  real_T c26_ec_x;
  real_T c26_fc_x;
  real_T c26_gc_x;
  real_T c26_hc_x;
  real_T c26_m_a;
  real_T c26_s_b;
  real_T c26_x_y;
  real_T c26_ic_x;
  real_T c26_jc_x;
  real_T c26_kc_x;
  real_T c26_lc_x;
  real_T c26_n_a;
  real_T c26_t_b;
  real_T c26_y_y;
  real_T c26_o_a;
  real_T c26_u_b;
  real_T c26_ab_y;
  real_T c26_f_A;
  real_T c26_mc_x;
  real_T c26_nc_x;
  real_T c26_bb_y;
  real_T c26_v_b;
  real_T c26_cb_y;
  real_T c26_g_A;
  real_T c26_oc_x;
  real_T c26_pc_x;
  real_T c26_db_y;
  real_T c26_qc_x;
  real_T c26_rc_x;
  real_T c26_w_b;
  real_T c26_eb_y;
  real_T c26_h_A;
  real_T c26_sc_x;
  real_T c26_tc_x;
  real_T c26_fb_y;
  real_T c26_uc_x;
  real_T c26_vc_x;
  real_T c26_x_b;
  real_T c26_gb_y;
  real_T c26_wc_x;
  real_T c26_xc_x;
  real_T c26_p_a;
  real_T c26_y_b;
  real_T c26_hb_y;
  real_T c26_i_A;
  real_T c26_yc_x;
  real_T c26_ad_x;
  real_T c26_ib_y;
  real_T c26_bd_x;
  real_T c26_cd_x;
  real_T c26_ab_b;
  real_T c26_jb_y;
  real_T c26_dd_x;
  real_T c26_ed_x;
  real_T c26_q_a;
  real_T c26_bb_b;
  real_T c26_kb_y;
  real_T c26_j_A;
  real_T c26_fd_x;
  real_T c26_gd_x;
  real_T c26_lb_y;
  real_T c26_hd_x;
  real_T c26_id_x;
  real_T c26_cb_b;
  real_T c26_mb_y;
  real_T c26_jd_x;
  real_T c26_kd_x;
  real_T c26_ld_x;
  real_T c26_md_x;
  real_T c26_r_a;
  real_T c26_db_b;
  real_T c26_nb_y;
  real_T c26_nd_x;
  real_T c26_od_x;
  real_T c26_pd_x;
  real_T c26_qd_x;
  real_T c26_s_a;
  real_T c26_eb_b;
  real_T c26_ob_y;
  real_T c26_t_a;
  real_T c26_fb_b;
  real_T c26_pb_y;
  real_T c26_k_A;
  real_T c26_rd_x;
  real_T c26_sd_x;
  real_T c26_qb_y;
  real_T c26_td_x;
  real_T c26_ud_x;
  real_T c26_gb_b;
  real_T c26_rb_y;
  real_T c26_vd_x;
  real_T c26_wd_x;
  real_T c26_xd_x;
  real_T c26_yd_x;
  real_T c26_u_a;
  real_T c26_hb_b;
  real_T c26_sb_y;
  real_T c26_ae_x;
  real_T c26_be_x;
  real_T c26_ce_x;
  real_T c26_de_x;
  real_T c26_v_a;
  real_T c26_ib_b;
  real_T c26_tb_y;
  real_T c26_w_a;
  real_T c26_jb_b;
  real_T c26_ub_y;
  real_T c26_l_A;
  real_T c26_ee_x;
  real_T c26_fe_x;
  real_T c26_vb_y;
  real_T c26_kb_b;
  real_T c26_wb_y;
  real_T c26_m_A;
  real_T c26_ge_x;
  real_T c26_he_x;
  real_T c26_xb_y;
  real_T c26_ie_x;
  real_T c26_je_x;
  real_T c26_lb_b;
  real_T c26_yb_y;
  real_T c26_n_A;
  real_T c26_ke_x;
  real_T c26_le_x;
  real_T c26_ac_y;
  real_T c26_mb_b;
  real_T c26_bc_y;
  real_T c26_o_A;
  real_T c26_me_x;
  real_T c26_ne_x;
  real_T c26_cc_y;
  real_T c26_oe_x;
  real_T c26_pe_x;
  real_T c26_nb_b;
  real_T c26_dc_y;
  real_T c26_p_A;
  real_T c26_qe_x;
  real_T c26_re_x;
  real_T c26_ec_y;
  real_T c26_se_x;
  real_T c26_te_x;
  real_T c26_ob_b;
  real_T c26_fc_y;
  real_T c26_ue_x;
  real_T c26_ve_x;
  real_T c26_x_a;
  real_T c26_pb_b;
  real_T c26_gc_y;
  real_T c26_q_A;
  real_T c26_we_x;
  real_T c26_xe_x;
  real_T c26_hc_y;
  real_T c26_ye_x;
  real_T c26_af_x;
  real_T c26_qb_b;
  real_T c26_ic_y;
  real_T c26_bf_x;
  real_T c26_cf_x;
  real_T c26_y_a;
  real_T c26_rb_b;
  real_T c26_jc_y;
  real_T c26_r_A;
  real_T c26_df_x;
  real_T c26_ef_x;
  real_T c26_kc_y;
  real_T c26_sb_b;
  real_T c26_lc_y;
  real_T c26_s_A;
  real_T c26_ff_x;
  real_T c26_gf_x;
  real_T c26_mc_y;
  real_T c26_hf_x;
  real_T c26_if_x;
  real_T c26_tb_b;
  real_T c26_nc_y;
  real_T c26_t_A;
  real_T c26_jf_x;
  real_T c26_kf_x;
  real_T c26_oc_y;
  real_T c26_lf_x;
  real_T c26_mf_x;
  real_T c26_ub_b;
  real_T c26_pc_y;
  real_T c26_nf_x;
  real_T c26_of_x;
  real_T c26_ab_a;
  real_T c26_vb_b;
  real_T c26_qc_y;
  real_T c26_u_A;
  real_T c26_pf_x;
  real_T c26_qf_x;
  real_T c26_rc_y;
  real_T c26_rf_x;
  real_T c26_sf_x;
  real_T c26_wb_b;
  real_T c26_sc_y;
  real_T c26_tf_x;
  real_T c26_uf_x;
  real_T c26_bb_a;
  real_T c26_xb_b;
  real_T c26_tc_y;
  real_T c26_v_A;
  real_T c26_vf_x;
  real_T c26_wf_x;
  real_T c26_uc_y;
  real_T c26_xf_x;
  real_T c26_yf_x;
  real_T c26_yb_b;
  real_T c26_vc_y;
  real_T c26_ag_x;
  real_T c26_bg_x;
  real_T c26_cg_x;
  real_T c26_dg_x;
  real_T c26_eg_x;
  real_T c26_fg_x;
  real_T c26_cb_a;
  real_T c26_ac_b;
  real_T c26_wc_y;
  real_T c26_gg_x;
  real_T c26_hg_x;
  real_T c26_ig_x;
  real_T c26_jg_x;
  real_T c26_db_a;
  real_T c26_bc_b;
  real_T c26_xc_y;
  real_T c26_eb_a;
  real_T c26_cc_b;
  real_T c26_yc_y;
  real_T c26_kg_x;
  real_T c26_lg_x;
  real_T c26_mg_x;
  real_T c26_ng_x;
  real_T c26_og_x;
  real_T c26_pg_x;
  real_T c26_fb_a;
  real_T c26_dc_b;
  real_T c26_ad_y;
  real_T c26_qg_x;
  real_T c26_rg_x;
  real_T c26_sg_x;
  real_T c26_tg_x;
  real_T c26_gb_a;
  real_T c26_ec_b;
  real_T c26_bd_y;
  real_T c26_hb_a;
  real_T c26_fc_b;
  real_T c26_cd_y;
  real_T c26_ib_a;
  real_T c26_gc_b;
  real_T c26_dd_y;
  real_T c26_w_A;
  real_T c26_ug_x;
  real_T c26_vg_x;
  real_T c26_ed_y;
  real_T c26_wg_x;
  real_T c26_xg_x;
  real_T c26_hc_b;
  real_T c26_fd_y;
  real_T c26_yg_x;
  real_T c26_ah_x;
  real_T c26_bh_x;
  real_T c26_ch_x;
  real_T c26_jb_a;
  real_T c26_ic_b;
  real_T c26_gd_y;
  real_T c26_dh_x;
  real_T c26_eh_x;
  real_T c26_fh_x;
  real_T c26_gh_x;
  real_T c26_kb_a;
  real_T c26_jc_b;
  real_T c26_hd_y;
  real_T c26_lb_a;
  real_T c26_kc_b;
  real_T c26_id_y;
  real_T c26_x_A;
  real_T c26_hh_x;
  real_T c26_ih_x;
  real_T c26_jd_y;
  real_T c26_jh_x;
  real_T c26_kh_x;
  real_T c26_lc_b;
  real_T c26_kd_y;
  real_T c26_lh_x;
  real_T c26_mh_x;
  real_T c26_nh_x;
  real_T c26_oh_x;
  real_T c26_mb_a;
  real_T c26_mc_b;
  real_T c26_ld_y;
  real_T c26_ph_x;
  real_T c26_qh_x;
  real_T c26_rh_x;
  real_T c26_sh_x;
  real_T c26_nb_a;
  real_T c26_nc_b;
  real_T c26_md_y;
  real_T c26_ob_a;
  real_T c26_oc_b;
  real_T c26_nd_y;
  real_T c26_y_A;
  real_T c26_th_x;
  real_T c26_uh_x;
  real_T c26_od_y;
  real_T c26_pc_b;
  real_T c26_pd_y;
  real_T c26_ab_A;
  real_T c26_vh_x;
  real_T c26_wh_x;
  real_T c26_qd_y;
  real_T *c26_b_P;
  real_T (*c26_b_q)[6];
  c26_b_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c26_sfEvent);
  for (c26_i1 = 0; c26_i1 < 6; c26_i1++) {
    c26_q[c26_i1] = (*c26_b_q)[c26_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c26_debug_family_names,
    c26_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_theta_1, 0U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_theta_2, 1U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_theta_3, 2U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_theta_4, 3U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_theta_5, 4U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_theta_6, 5U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_m_1, 6U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_m_2, 7U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_m_3, 8U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_m_4, 9U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_m_5, 10U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_m_6, 11U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargin, 12U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargout, 13U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_q, 14U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_P, 15U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 5);
  c26_theta_1 = c26_q[0];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 6);
  c26_theta_2 = c26_q[1];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 7);
  c26_theta_3 = c26_q[2];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 8);
  c26_theta_4 = c26_q[3];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 9);
  c26_theta_5 = c26_q[4];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 10);
  c26_theta_6 = c26_q[5];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 12);
  c26_m_1 = 3.7;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 13);
  c26_m_2 = 8.393;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 14);
  c26_m_3 = 2.275;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 15);
  c26_m_4 = 1.219;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 16);
  c26_m_5 = 1.219;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 17);
  c26_m_6 = 0.1879;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 20);
  c26_x = c26_theta_2;
  c26_b_x = c26_x;
  c26_b_x = muDoubleScalarSin(c26_b_x);
  c26_b = c26_b_x;
  c26_y = 17.0 * c26_b;
  c26_A = c26_y;
  c26_c_x = c26_A;
  c26_d_x = c26_c_x;
  c26_b_y = c26_d_x / 40.0;
  c26_e_x = c26_theta_2;
  c26_f_x = c26_e_x;
  c26_f_x = muDoubleScalarCos(c26_f_x);
  c26_b_b = c26_f_x;
  c26_c_y = 39243.0 * c26_b_b;
  c26_g_x = c26_theta_3;
  c26_h_x = c26_g_x;
  c26_h_x = muDoubleScalarSin(c26_h_x);
  c26_a = c26_c_y;
  c26_c_b = c26_h_x;
  c26_d_y = c26_a * c26_c_b;
  c26_b_A = c26_d_y;
  c26_i_x = c26_b_A;
  c26_j_x = c26_i_x;
  c26_e_y = c26_j_x / 100000.0;
  c26_k_x = c26_theta_3;
  c26_l_x = c26_k_x;
  c26_l_x = muDoubleScalarCos(c26_l_x);
  c26_d_b = c26_l_x;
  c26_f_y = 39243.0 * c26_d_b;
  c26_m_x = c26_theta_2;
  c26_n_x = c26_m_x;
  c26_n_x = muDoubleScalarSin(c26_n_x);
  c26_b_a = c26_f_y;
  c26_e_b = c26_n_x;
  c26_g_y = c26_b_a * c26_e_b;
  c26_c_A = c26_g_y;
  c26_o_x = c26_c_A;
  c26_p_x = c26_o_x;
  c26_h_y = c26_p_x / 100000.0;
  c26_q_x = c26_theta_5;
  c26_r_x = c26_q_x;
  c26_r_x = muDoubleScalarSin(c26_r_x);
  c26_f_b = c26_r_x;
  c26_i_y = 4.6601663676961055E+19 * c26_f_b;
  c26_s_x = c26_theta_4;
  c26_t_x = c26_s_x;
  c26_t_x = muDoubleScalarCos(c26_t_x);
  c26_u_x = c26_theta_2;
  c26_v_x = c26_u_x;
  c26_v_x = muDoubleScalarCos(c26_v_x);
  c26_w_x = c26_theta_3;
  c26_x_x = c26_w_x;
  c26_x_x = muDoubleScalarSin(c26_x_x);
  c26_c_a = c26_v_x;
  c26_g_b = c26_x_x;
  c26_j_y = c26_c_a * c26_g_b;
  c26_y_x = c26_theta_3;
  c26_ab_x = c26_y_x;
  c26_ab_x = muDoubleScalarCos(c26_ab_x);
  c26_bb_x = c26_theta_2;
  c26_cb_x = c26_bb_x;
  c26_cb_x = muDoubleScalarSin(c26_cb_x);
  c26_d_a = c26_ab_x;
  c26_h_b = c26_cb_x;
  c26_k_y = c26_d_a * c26_h_b;
  c26_e_a = c26_t_x;
  c26_i_b = c26_j_y + c26_k_y;
  c26_l_y = c26_e_a * c26_i_b;
  c26_db_x = c26_theta_4;
  c26_eb_x = c26_db_x;
  c26_eb_x = muDoubleScalarSin(c26_eb_x);
  c26_fb_x = c26_theta_2;
  c26_gb_x = c26_fb_x;
  c26_gb_x = muDoubleScalarCos(c26_gb_x);
  c26_hb_x = c26_theta_3;
  c26_ib_x = c26_hb_x;
  c26_ib_x = muDoubleScalarCos(c26_ib_x);
  c26_f_a = c26_gb_x;
  c26_j_b = c26_ib_x;
  c26_m_y = c26_f_a * c26_j_b;
  c26_jb_x = c26_theta_2;
  c26_kb_x = c26_jb_x;
  c26_kb_x = muDoubleScalarSin(c26_kb_x);
  c26_lb_x = c26_theta_3;
  c26_mb_x = c26_lb_x;
  c26_mb_x = muDoubleScalarSin(c26_mb_x);
  c26_g_a = c26_kb_x;
  c26_k_b = c26_mb_x;
  c26_n_y = c26_g_a * c26_k_b;
  c26_h_a = c26_eb_x;
  c26_l_b = c26_m_y - c26_n_y;
  c26_o_y = c26_h_a * c26_l_b;
  c26_i_a = c26_i_y;
  c26_m_b = c26_l_y + c26_o_y;
  c26_p_y = c26_i_a * c26_m_b;
  c26_d_A = c26_p_y;
  c26_nb_x = c26_d_A;
  c26_ob_x = c26_nb_x;
  c26_q_y = c26_ob_x / 5.7646075230342349E+20;
  c26_pb_x = c26_theta_4;
  c26_qb_x = c26_pb_x;
  c26_qb_x = muDoubleScalarCos(c26_qb_x);
  c26_n_b = c26_qb_x;
  c26_r_y = 93.0 * c26_n_b;
  c26_rb_x = c26_theta_2;
  c26_sb_x = c26_rb_x;
  c26_sb_x = muDoubleScalarCos(c26_sb_x);
  c26_tb_x = c26_theta_3;
  c26_ub_x = c26_tb_x;
  c26_ub_x = muDoubleScalarCos(c26_ub_x);
  c26_j_a = c26_sb_x;
  c26_o_b = c26_ub_x;
  c26_s_y = c26_j_a * c26_o_b;
  c26_vb_x = c26_theta_2;
  c26_wb_x = c26_vb_x;
  c26_wb_x = muDoubleScalarSin(c26_wb_x);
  c26_xb_x = c26_theta_3;
  c26_yb_x = c26_xb_x;
  c26_yb_x = muDoubleScalarSin(c26_yb_x);
  c26_k_a = c26_wb_x;
  c26_p_b = c26_yb_x;
  c26_t_y = c26_k_a * c26_p_b;
  c26_l_a = c26_r_y;
  c26_q_b = c26_s_y - c26_t_y;
  c26_u_y = c26_l_a * c26_q_b;
  c26_e_A = c26_u_y;
  c26_ac_x = c26_e_A;
  c26_bc_x = c26_ac_x;
  c26_v_y = c26_bc_x / 1000.0;
  c26_cc_x = c26_theta_4;
  c26_dc_x = c26_cc_x;
  c26_dc_x = muDoubleScalarSin(c26_dc_x);
  c26_r_b = c26_dc_x;
  c26_w_y = 93.0 * c26_r_b;
  c26_ec_x = c26_theta_2;
  c26_fc_x = c26_ec_x;
  c26_fc_x = muDoubleScalarCos(c26_fc_x);
  c26_gc_x = c26_theta_3;
  c26_hc_x = c26_gc_x;
  c26_hc_x = muDoubleScalarSin(c26_hc_x);
  c26_m_a = c26_fc_x;
  c26_s_b = c26_hc_x;
  c26_x_y = c26_m_a * c26_s_b;
  c26_ic_x = c26_theta_3;
  c26_jc_x = c26_ic_x;
  c26_jc_x = muDoubleScalarCos(c26_jc_x);
  c26_kc_x = c26_theta_2;
  c26_lc_x = c26_kc_x;
  c26_lc_x = muDoubleScalarSin(c26_lc_x);
  c26_n_a = c26_jc_x;
  c26_t_b = c26_lc_x;
  c26_y_y = c26_n_a * c26_t_b;
  c26_o_a = c26_w_y;
  c26_u_b = c26_x_y + c26_y_y;
  c26_ab_y = c26_o_a * c26_u_b;
  c26_f_A = c26_ab_y;
  c26_mc_x = c26_f_A;
  c26_nc_x = c26_mc_x;
  c26_bb_y = c26_nc_x / 1000.0;
  c26_v_b = (((((c26_b_y + c26_e_y) + c26_h_y) + c26_q_y) + c26_v_y) - c26_bb_y)
    - 0.0892;
  c26_cb_y = 184.3299 * c26_v_b;
  c26_g_A = c26_cb_y;
  c26_oc_x = c26_g_A;
  c26_pc_x = c26_oc_x;
  c26_db_y = c26_pc_x / 100.0;
  c26_qc_x = c26_theta_2;
  c26_rc_x = c26_qc_x;
  c26_rc_x = muDoubleScalarSin(c26_rc_x);
  c26_w_b = c26_rc_x;
  c26_eb_y = 17.0 * c26_w_b;
  c26_h_A = c26_eb_y;
  c26_sc_x = c26_h_A;
  c26_tc_x = c26_sc_x;
  c26_fb_y = c26_tc_x / 40.0;
  c26_uc_x = c26_theta_2;
  c26_vc_x = c26_uc_x;
  c26_vc_x = muDoubleScalarCos(c26_vc_x);
  c26_x_b = c26_vc_x;
  c26_gb_y = 39243.0 * c26_x_b;
  c26_wc_x = c26_theta_3;
  c26_xc_x = c26_wc_x;
  c26_xc_x = muDoubleScalarSin(c26_xc_x);
  c26_p_a = c26_gb_y;
  c26_y_b = c26_xc_x;
  c26_hb_y = c26_p_a * c26_y_b;
  c26_i_A = c26_hb_y;
  c26_yc_x = c26_i_A;
  c26_ad_x = c26_yc_x;
  c26_ib_y = c26_ad_x / 100000.0;
  c26_bd_x = c26_theta_3;
  c26_cd_x = c26_bd_x;
  c26_cd_x = muDoubleScalarCos(c26_cd_x);
  c26_ab_b = c26_cd_x;
  c26_jb_y = 39243.0 * c26_ab_b;
  c26_dd_x = c26_theta_2;
  c26_ed_x = c26_dd_x;
  c26_ed_x = muDoubleScalarSin(c26_ed_x);
  c26_q_a = c26_jb_y;
  c26_bb_b = c26_ed_x;
  c26_kb_y = c26_q_a * c26_bb_b;
  c26_j_A = c26_kb_y;
  c26_fd_x = c26_j_A;
  c26_gd_x = c26_fd_x;
  c26_lb_y = c26_gd_x / 100000.0;
  c26_hd_x = c26_theta_4;
  c26_id_x = c26_hd_x;
  c26_id_x = muDoubleScalarCos(c26_id_x);
  c26_cb_b = c26_id_x;
  c26_mb_y = 817.0 * c26_cb_b;
  c26_jd_x = c26_theta_2;
  c26_kd_x = c26_jd_x;
  c26_kd_x = muDoubleScalarCos(c26_kd_x);
  c26_ld_x = c26_theta_3;
  c26_md_x = c26_ld_x;
  c26_md_x = muDoubleScalarCos(c26_md_x);
  c26_r_a = c26_kd_x;
  c26_db_b = c26_md_x;
  c26_nb_y = c26_r_a * c26_db_b;
  c26_nd_x = c26_theta_2;
  c26_od_x = c26_nd_x;
  c26_od_x = muDoubleScalarSin(c26_od_x);
  c26_pd_x = c26_theta_3;
  c26_qd_x = c26_pd_x;
  c26_qd_x = muDoubleScalarSin(c26_qd_x);
  c26_s_a = c26_od_x;
  c26_eb_b = c26_qd_x;
  c26_ob_y = c26_s_a * c26_eb_b;
  c26_t_a = c26_mb_y;
  c26_fb_b = c26_nb_y - c26_ob_y;
  c26_pb_y = c26_t_a * c26_fb_b;
  c26_k_A = c26_pb_y;
  c26_rd_x = c26_k_A;
  c26_sd_x = c26_rd_x;
  c26_qb_y = c26_sd_x / 50000.0;
  c26_td_x = c26_theta_4;
  c26_ud_x = c26_td_x;
  c26_ud_x = muDoubleScalarSin(c26_ud_x);
  c26_gb_b = c26_ud_x;
  c26_rb_y = 817.0 * c26_gb_b;
  c26_vd_x = c26_theta_2;
  c26_wd_x = c26_vd_x;
  c26_wd_x = muDoubleScalarCos(c26_wd_x);
  c26_xd_x = c26_theta_3;
  c26_yd_x = c26_xd_x;
  c26_yd_x = muDoubleScalarSin(c26_yd_x);
  c26_u_a = c26_wd_x;
  c26_hb_b = c26_yd_x;
  c26_sb_y = c26_u_a * c26_hb_b;
  c26_ae_x = c26_theta_3;
  c26_be_x = c26_ae_x;
  c26_be_x = muDoubleScalarCos(c26_be_x);
  c26_ce_x = c26_theta_2;
  c26_de_x = c26_ce_x;
  c26_de_x = muDoubleScalarSin(c26_de_x);
  c26_v_a = c26_be_x;
  c26_ib_b = c26_de_x;
  c26_tb_y = c26_v_a * c26_ib_b;
  c26_w_a = c26_rb_y;
  c26_jb_b = c26_sb_y + c26_tb_y;
  c26_ub_y = c26_w_a * c26_jb_b;
  c26_l_A = c26_ub_y;
  c26_ee_x = c26_l_A;
  c26_fe_x = c26_ee_x;
  c26_vb_y = c26_fe_x / 50000.0;
  c26_kb_b = ((((c26_fb_y + c26_ib_y) + c26_lb_y) + c26_qb_y) - c26_vb_y) -
    0.0892;
  c26_wb_y = 1195.8390000000002 * c26_kb_b;
  c26_m_A = c26_wb_y;
  c26_ge_x = c26_m_A;
  c26_he_x = c26_ge_x;
  c26_xb_y = c26_he_x / 100.0;
  c26_ie_x = c26_theta_2;
  c26_je_x = c26_ie_x;
  c26_je_x = muDoubleScalarSin(c26_je_x);
  c26_lb_b = c26_je_x;
  c26_yb_y = 17.0 * c26_lb_b;
  c26_n_A = c26_yb_y;
  c26_ke_x = c26_n_A;
  c26_le_x = c26_ke_x;
  c26_ac_y = c26_le_x / 80.0;
  c26_mb_b = c26_ac_y - 0.0892;
  c26_bc_y = 8233.5330000000013 * c26_mb_b;
  c26_o_A = c26_bc_y;
  c26_me_x = c26_o_A;
  c26_ne_x = c26_me_x;
  c26_cc_y = c26_ne_x / 100.0;
  c26_oe_x = c26_theta_2;
  c26_pe_x = c26_oe_x;
  c26_pe_x = muDoubleScalarSin(c26_pe_x);
  c26_nb_b = c26_pe_x;
  c26_dc_y = 17.0 * c26_nb_b;
  c26_p_A = c26_dc_y;
  c26_qe_x = c26_p_A;
  c26_re_x = c26_qe_x;
  c26_ec_y = c26_re_x / 40.0;
  c26_se_x = c26_theta_2;
  c26_te_x = c26_se_x;
  c26_te_x = muDoubleScalarCos(c26_te_x);
  c26_ob_b = c26_te_x;
  c26_fc_y = 109.0 * c26_ob_b;
  c26_ue_x = c26_theta_3;
  c26_ve_x = c26_ue_x;
  c26_ve_x = muDoubleScalarSin(c26_ve_x);
  c26_x_a = c26_fc_y;
  c26_pb_b = c26_ve_x;
  c26_gc_y = c26_x_a * c26_pb_b;
  c26_q_A = c26_gc_y;
  c26_we_x = c26_q_A;
  c26_xe_x = c26_we_x;
  c26_hc_y = c26_xe_x / 400.0;
  c26_ye_x = c26_theta_3;
  c26_af_x = c26_ye_x;
  c26_af_x = muDoubleScalarCos(c26_af_x);
  c26_qb_b = c26_af_x;
  c26_ic_y = 109.0 * c26_qb_b;
  c26_bf_x = c26_theta_2;
  c26_cf_x = c26_bf_x;
  c26_cf_x = muDoubleScalarSin(c26_cf_x);
  c26_y_a = c26_ic_y;
  c26_rb_b = c26_cf_x;
  c26_jc_y = c26_y_a * c26_rb_b;
  c26_r_A = c26_jc_y;
  c26_df_x = c26_r_A;
  c26_ef_x = c26_df_x;
  c26_kc_y = c26_ef_x / 400.0;
  c26_sb_b = ((c26_ec_y + c26_hc_y) + c26_kc_y) - 0.0892;
  c26_lc_y = 2231.775 * c26_sb_b;
  c26_s_A = c26_lc_y;
  c26_ff_x = c26_s_A;
  c26_gf_x = c26_ff_x;
  c26_mc_y = c26_gf_x / 100.0;
  c26_hf_x = c26_theta_2;
  c26_if_x = c26_hf_x;
  c26_if_x = muDoubleScalarSin(c26_if_x);
  c26_tb_b = c26_if_x;
  c26_nc_y = 17.0 * c26_tb_b;
  c26_t_A = c26_nc_y;
  c26_jf_x = c26_t_A;
  c26_kf_x = c26_jf_x;
  c26_oc_y = c26_kf_x / 40.0;
  c26_lf_x = c26_theta_2;
  c26_mf_x = c26_lf_x;
  c26_mf_x = muDoubleScalarCos(c26_mf_x);
  c26_ub_b = c26_mf_x;
  c26_pc_y = 39243.0 * c26_ub_b;
  c26_nf_x = c26_theta_3;
  c26_of_x = c26_nf_x;
  c26_of_x = muDoubleScalarSin(c26_of_x);
  c26_ab_a = c26_pc_y;
  c26_vb_b = c26_of_x;
  c26_qc_y = c26_ab_a * c26_vb_b;
  c26_u_A = c26_qc_y;
  c26_pf_x = c26_u_A;
  c26_qf_x = c26_pf_x;
  c26_rc_y = c26_qf_x / 100000.0;
  c26_rf_x = c26_theta_3;
  c26_sf_x = c26_rf_x;
  c26_sf_x = muDoubleScalarCos(c26_sf_x);
  c26_wb_b = c26_sf_x;
  c26_sc_y = 39243.0 * c26_wb_b;
  c26_tf_x = c26_theta_2;
  c26_uf_x = c26_tf_x;
  c26_uf_x = muDoubleScalarSin(c26_uf_x);
  c26_bb_a = c26_sc_y;
  c26_xb_b = c26_uf_x;
  c26_tc_y = c26_bb_a * c26_xb_b;
  c26_v_A = c26_tc_y;
  c26_vf_x = c26_v_A;
  c26_wf_x = c26_vf_x;
  c26_uc_y = c26_wf_x / 100000.0;
  c26_xf_x = c26_theta_5;
  c26_yf_x = c26_xf_x;
  c26_yf_x = muDoubleScalarSin(c26_yf_x);
  c26_yb_b = c26_yf_x;
  c26_vc_y = 817.0 * c26_yb_b;
  c26_ag_x = c26_theta_4;
  c26_bg_x = c26_ag_x;
  c26_bg_x = muDoubleScalarCos(c26_bg_x);
  c26_cg_x = c26_theta_2;
  c26_dg_x = c26_cg_x;
  c26_dg_x = muDoubleScalarCos(c26_dg_x);
  c26_eg_x = c26_theta_3;
  c26_fg_x = c26_eg_x;
  c26_fg_x = muDoubleScalarSin(c26_fg_x);
  c26_cb_a = c26_dg_x;
  c26_ac_b = c26_fg_x;
  c26_wc_y = c26_cb_a * c26_ac_b;
  c26_gg_x = c26_theta_3;
  c26_hg_x = c26_gg_x;
  c26_hg_x = muDoubleScalarCos(c26_hg_x);
  c26_ig_x = c26_theta_2;
  c26_jg_x = c26_ig_x;
  c26_jg_x = muDoubleScalarSin(c26_jg_x);
  c26_db_a = c26_hg_x;
  c26_bc_b = c26_jg_x;
  c26_xc_y = c26_db_a * c26_bc_b;
  c26_eb_a = c26_bg_x;
  c26_cc_b = c26_wc_y + c26_xc_y;
  c26_yc_y = c26_eb_a * c26_cc_b;
  c26_kg_x = c26_theta_4;
  c26_lg_x = c26_kg_x;
  c26_lg_x = muDoubleScalarSin(c26_lg_x);
  c26_mg_x = c26_theta_2;
  c26_ng_x = c26_mg_x;
  c26_ng_x = muDoubleScalarCos(c26_ng_x);
  c26_og_x = c26_theta_3;
  c26_pg_x = c26_og_x;
  c26_pg_x = muDoubleScalarCos(c26_pg_x);
  c26_fb_a = c26_ng_x;
  c26_dc_b = c26_pg_x;
  c26_ad_y = c26_fb_a * c26_dc_b;
  c26_qg_x = c26_theta_2;
  c26_rg_x = c26_qg_x;
  c26_rg_x = muDoubleScalarSin(c26_rg_x);
  c26_sg_x = c26_theta_3;
  c26_tg_x = c26_sg_x;
  c26_tg_x = muDoubleScalarSin(c26_tg_x);
  c26_gb_a = c26_rg_x;
  c26_ec_b = c26_tg_x;
  c26_bd_y = c26_gb_a * c26_ec_b;
  c26_hb_a = c26_lg_x;
  c26_fc_b = c26_ad_y - c26_bd_y;
  c26_cd_y = c26_hb_a * c26_fc_b;
  c26_ib_a = c26_vc_y;
  c26_gc_b = c26_yc_y + c26_cd_y;
  c26_dd_y = c26_ib_a * c26_gc_b;
  c26_w_A = c26_dd_y;
  c26_ug_x = c26_w_A;
  c26_vg_x = c26_ug_x;
  c26_ed_y = c26_vg_x / 50000.0;
  c26_wg_x = c26_theta_4;
  c26_xg_x = c26_wg_x;
  c26_xg_x = muDoubleScalarCos(c26_xg_x);
  c26_hc_b = c26_xg_x;
  c26_fd_y = 57.0 * c26_hc_b;
  c26_yg_x = c26_theta_2;
  c26_ah_x = c26_yg_x;
  c26_ah_x = muDoubleScalarCos(c26_ah_x);
  c26_bh_x = c26_theta_3;
  c26_ch_x = c26_bh_x;
  c26_ch_x = muDoubleScalarCos(c26_ch_x);
  c26_jb_a = c26_ah_x;
  c26_ic_b = c26_ch_x;
  c26_gd_y = c26_jb_a * c26_ic_b;
  c26_dh_x = c26_theta_2;
  c26_eh_x = c26_dh_x;
  c26_eh_x = muDoubleScalarSin(c26_eh_x);
  c26_fh_x = c26_theta_3;
  c26_gh_x = c26_fh_x;
  c26_gh_x = muDoubleScalarSin(c26_gh_x);
  c26_kb_a = c26_eh_x;
  c26_jc_b = c26_gh_x;
  c26_hd_y = c26_kb_a * c26_jc_b;
  c26_lb_a = c26_fd_y;
  c26_kc_b = c26_gd_y - c26_hd_y;
  c26_id_y = c26_lb_a * c26_kc_b;
  c26_x_A = c26_id_y;
  c26_hh_x = c26_x_A;
  c26_ih_x = c26_hh_x;
  c26_jd_y = c26_ih_x / 625.0;
  c26_jh_x = c26_theta_4;
  c26_kh_x = c26_jh_x;
  c26_kh_x = muDoubleScalarSin(c26_kh_x);
  c26_lc_b = c26_kh_x;
  c26_kd_y = 57.0 * c26_lc_b;
  c26_lh_x = c26_theta_2;
  c26_mh_x = c26_lh_x;
  c26_mh_x = muDoubleScalarCos(c26_mh_x);
  c26_nh_x = c26_theta_3;
  c26_oh_x = c26_nh_x;
  c26_oh_x = muDoubleScalarSin(c26_oh_x);
  c26_mb_a = c26_mh_x;
  c26_mc_b = c26_oh_x;
  c26_ld_y = c26_mb_a * c26_mc_b;
  c26_ph_x = c26_theta_3;
  c26_qh_x = c26_ph_x;
  c26_qh_x = muDoubleScalarCos(c26_qh_x);
  c26_rh_x = c26_theta_2;
  c26_sh_x = c26_rh_x;
  c26_sh_x = muDoubleScalarSin(c26_sh_x);
  c26_nb_a = c26_qh_x;
  c26_nc_b = c26_sh_x;
  c26_md_y = c26_nb_a * c26_nc_b;
  c26_ob_a = c26_kd_y;
  c26_oc_b = c26_ld_y + c26_md_y;
  c26_nd_y = c26_ob_a * c26_oc_b;
  c26_y_A = c26_nd_y;
  c26_th_x = c26_y_A;
  c26_uh_x = c26_th_x;
  c26_od_y = c26_uh_x / 625.0;
  c26_pc_b = (((((c26_oc_y + c26_rc_y) + c26_uc_y) + c26_ed_y) + c26_jd_y) -
              c26_od_y) - 0.0892;
  c26_pd_y = 1195.8390000000002 * c26_pc_b;
  c26_ab_A = c26_pd_y;
  c26_vh_x = c26_ab_A;
  c26_wh_x = c26_vh_x;
  c26_qd_y = c26_wh_x / 100.0;
  c26_P = ((((2.30812623 - c26_db_y) - c26_xb_y) - c26_cc_y) - c26_mc_y) -
    c26_qd_y;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *c26_b_P = c26_P;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c26_sfEvent);
}

static void initSimStructsc26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void registerMessagesc26_JointSpaceControl
  (SFc26_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber)
{
}

static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  real_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc26_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(real_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static real_T c26_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_P, const char_T *c26_identifier)
{
  real_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_P), &c26_thisId);
  sf_mex_destroy(&c26_P);
  return c26_y;
}

static real_T c26_b_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d0, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_P;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc26_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c26_P = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_P), &c26_thisId);
  sf_mex_destroy(&c26_P);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i2;
  real_T c26_b_inData[6];
  int32_T c26_i3;
  real_T c26_u[6];
  const mxArray *c26_y = NULL;
  SFc26_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc26_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i2 = 0; c26_i2 < 6; c26_i2++) {
    c26_b_inData[c26_i2] = (*(real_T (*)[6])c26_inData)[c26_i2];
  }

  for (c26_i3 = 0; c26_i3 < 6; c26_i3++) {
    c26_u[c26_i3] = c26_b_inData[c26_i3];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

const mxArray *sf_c26_JointSpaceControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo;
  c26_ResolvedFunctionInfo c26_info[9];
  c26_ResolvedFunctionInfo (*c26_b_info)[9];
  const mxArray *c26_m0 = NULL;
  int32_T c26_i4;
  c26_ResolvedFunctionInfo *c26_r0;
  c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  c26_b_info = (c26_ResolvedFunctionInfo (*)[9])c26_info;
  (*c26_b_info)[0].context = "";
  (*c26_b_info)[0].name = "mtimes";
  (*c26_b_info)[0].dominantType = "double";
  (*c26_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c26_b_info)[0].fileTimeLo = 1289541292U;
  (*c26_b_info)[0].fileTimeHi = 0U;
  (*c26_b_info)[0].mFileTimeLo = 0U;
  (*c26_b_info)[0].mFileTimeHi = 0U;
  (*c26_b_info)[1].context = "";
  (*c26_b_info)[1].name = "mrdivide";
  (*c26_b_info)[1].dominantType = "double";
  (*c26_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c26_b_info)[1].fileTimeLo = 1357973148U;
  (*c26_b_info)[1].fileTimeHi = 0U;
  (*c26_b_info)[1].mFileTimeLo = 1319751566U;
  (*c26_b_info)[1].mFileTimeHi = 0U;
  (*c26_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c26_b_info)[2].name = "rdivide";
  (*c26_b_info)[2].dominantType = "double";
  (*c26_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c26_b_info)[2].fileTimeLo = 1346531988U;
  (*c26_b_info)[2].fileTimeHi = 0U;
  (*c26_b_info)[2].mFileTimeLo = 0U;
  (*c26_b_info)[2].mFileTimeHi = 0U;
  (*c26_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c26_b_info)[3].name = "eml_scalexp_compatible";
  (*c26_b_info)[3].dominantType = "double";
  (*c26_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c26_b_info)[3].fileTimeLo = 1286840396U;
  (*c26_b_info)[3].fileTimeHi = 0U;
  (*c26_b_info)[3].mFileTimeLo = 0U;
  (*c26_b_info)[3].mFileTimeHi = 0U;
  (*c26_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c26_b_info)[4].name = "eml_div";
  (*c26_b_info)[4].dominantType = "double";
  (*c26_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c26_b_info)[4].fileTimeLo = 1313369410U;
  (*c26_b_info)[4].fileTimeHi = 0U;
  (*c26_b_info)[4].mFileTimeLo = 0U;
  (*c26_b_info)[4].mFileTimeHi = 0U;
  (*c26_b_info)[5].context = "";
  (*c26_b_info)[5].name = "sin";
  (*c26_b_info)[5].dominantType = "double";
  (*c26_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c26_b_info)[5].fileTimeLo = 1343851986U;
  (*c26_b_info)[5].fileTimeHi = 0U;
  (*c26_b_info)[5].mFileTimeLo = 0U;
  (*c26_b_info)[5].mFileTimeHi = 0U;
  (*c26_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c26_b_info)[6].name = "eml_scalar_sin";
  (*c26_b_info)[6].dominantType = "double";
  (*c26_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c26_b_info)[6].fileTimeLo = 1286840336U;
  (*c26_b_info)[6].fileTimeHi = 0U;
  (*c26_b_info)[6].mFileTimeLo = 0U;
  (*c26_b_info)[6].mFileTimeHi = 0U;
  (*c26_b_info)[7].context = "";
  (*c26_b_info)[7].name = "cos";
  (*c26_b_info)[7].dominantType = "double";
  (*c26_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c26_b_info)[7].fileTimeLo = 1343851972U;
  (*c26_b_info)[7].fileTimeHi = 0U;
  (*c26_b_info)[7].mFileTimeLo = 0U;
  (*c26_b_info)[7].mFileTimeHi = 0U;
  (*c26_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c26_b_info)[8].name = "eml_scalar_cos";
  (*c26_b_info)[8].dominantType = "double";
  (*c26_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c26_b_info)[8].fileTimeLo = 1286840322U;
  (*c26_b_info)[8].fileTimeHi = 0U;
  (*c26_b_info)[8].mFileTimeLo = 0U;
  (*c26_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c26_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c26_i4 = 0; c26_i4 < 9; c26_i4++) {
    c26_r0 = &c26_info[c26_i4];
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c26_r0->context)), "context", "nameCaptureInfo",
                    c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c26_r0->name)), "name", "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      c26_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c26_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c26_r0->resolved)), "resolved",
                    "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      &c26_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      &c26_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c26_i4);
  }

  sf_mex_assign(&c26_nameCaptureInfo, c26_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c26_nameCaptureInfo);
  return c26_nameCaptureInfo;
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc26_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(int32_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static int32_T c26_c_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i5;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i5, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i5;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_sfEvent;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  int32_T c26_y;
  SFc26_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc26_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c26_b_sfEvent = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_b_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static uint8_T c26_d_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_JointSpaceControl, const
  char_T *c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_b_is_active_c26_JointSpaceControl), &c26_thisId);
  sf_mex_destroy(&c26_b_is_active_c26_JointSpaceControl);
  return c26_y;
}

static uint8_T c26_e_emlrt_marshallIn(SFc26_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  uint8_T c26_y;
  uint8_T c26_u0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_u0, 1, 3, 0U, 0, 0U, 0);
  c26_y = c26_u0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void init_dsm_address_info(SFc26_JointSpaceControlInstanceStruct
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

void sf_c26_JointSpaceControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(921880979U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3264952448U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1181437144U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3233231369U);
}

mxArray *sf_c26_JointSpaceControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("pQkNNYZwl8uiVb1rhJX2hF");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c26_JointSpaceControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c26_JointSpaceControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"P\",},{M[8],M[0],T\"is_active_c26_JointSpaceControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_JointSpaceControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc26_JointSpaceControlInstanceStruct *chartInstance;
    chartInstance = (SFc26_JointSpaceControlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControlMachineNumber_,
           26,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"P");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1751);
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
            1.0,0,0,(MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)c26_sf_marshallIn);

        {
          real_T *c26_P;
          real_T (*c26_q)[6];
          c26_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c26_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c26_q);
          _SFD_SET_DATA_VALUE_PTR(1U, c26_P);
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
  return "wpQtyoGNmYXDKDfGpQsiVG";
}

static void sf_opaque_initialize_c26_JointSpaceControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
  initialize_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c26_JointSpaceControl(void *chartInstanceVar)
{
  enable_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c26_JointSpaceControl(void *chartInstanceVar)
{
  disable_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c26_JointSpaceControl(void *chartInstanceVar)
{
  sf_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c26_JointSpaceControl(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c26_JointSpaceControl
    ((SFc26_JointSpaceControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_JointSpaceControl();/* state var info */
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

extern void sf_internal_set_sim_state_c26_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_JointSpaceControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c26_JointSpaceControl(SimStruct* S)
{
  return sf_internal_get_sim_state_c26_JointSpaceControl(S);
}

static void sf_opaque_set_sim_state_c26_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c26_JointSpaceControl(S, st);
}

static void sf_opaque_terminate_c26_JointSpaceControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc26_JointSpaceControlInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_optimization_info();
    }

    finalize_c26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc26_JointSpaceControl((SFc26_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_JointSpaceControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c26_JointSpaceControl
      ((SFc26_JointSpaceControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c26_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,26,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,26);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,26,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,26,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(626842348U));
  ssSetChecksum1(S,(2346571891U));
  ssSetChecksum2(S,(1649037504U));
  ssSetChecksum3(S,(936397691U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c26_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_JointSpaceControl(SimStruct *S)
{
  SFc26_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc26_JointSpaceControlInstanceStruct *)utMalloc(sizeof
    (SFc26_JointSpaceControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc26_JointSpaceControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c26_JointSpaceControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c26_JointSpaceControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c26_JointSpaceControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c26_JointSpaceControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c26_JointSpaceControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c26_JointSpaceControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c26_JointSpaceControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c26_JointSpaceControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c26_JointSpaceControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c26_JointSpaceControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c26_JointSpaceControl;
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

void c26_JointSpaceControl_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_JointSpaceControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_JointSpaceControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
