/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectFalseCombo_sfun.h"
#include "c28_JointSpaceControl_CorrectFalseCombo.h"
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
static const char * c28_debug_family_names[4] = { "nargin", "nargout", "q",
  "G_Version1" };

/* Function Declarations */
static void initialize_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initialize_params_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void enable_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void disable_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c28_update_debugger_state_c28_JointSpaceControl_CorrectFalseComb
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void set_sim_state_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_st);
static void finalize_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void sf_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void c28_chartstep_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void initSimStructsc28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void registerMessagesc28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber);
static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static void c28_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_G_Version1, const char_T *c28_identifier, real_T c28_y[6]);
static void c28_b_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId, real_T c28_y[6]);
static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static real_T c28_c_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static int32_T c28_d_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static uint8_T c28_e_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_b_is_active_c28_JointSpaceControl_CorrectFalseCombo, const
   char_T *c28_identifier);
static uint8_T c28_f_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void init_dsm_address_info
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  chartInstance->c28_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c28_is_active_c28_JointSpaceControl_CorrectFalseCombo = 0U;
}

static void initialize_params_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void enable_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c28_update_debugger_state_c28_JointSpaceControl_CorrectFalseComb
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  const mxArray *c28_st;
  const mxArray *c28_y = NULL;
  int32_T c28_i0;
  real_T c28_u[6];
  const mxArray *c28_b_y = NULL;
  uint8_T c28_hoistedGlobal;
  uint8_T c28_b_u;
  const mxArray *c28_c_y = NULL;
  real_T (*c28_G_Version1)[6];
  c28_G_Version1 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c28_st = NULL;
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellarray(2), FALSE);
  for (c28_i0 = 0; c28_i0 < 6; c28_i0++) {
    c28_u[c28_i0] = (*c28_G_Version1)[c28_i0];
  }

  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_hoistedGlobal =
    chartInstance->c28_is_active_c28_JointSpaceControl_CorrectFalseCombo;
  c28_b_u = c28_hoistedGlobal;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c28_y, 1, c28_c_y);
  sf_mex_assign(&c28_st, c28_y, FALSE);
  return c28_st;
}

static void set_sim_state_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_st)
{
  const mxArray *c28_u;
  real_T c28_dv0[6];
  int32_T c28_i1;
  real_T (*c28_G_Version1)[6];
  c28_G_Version1 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c28_doneDoubleBufferReInit = TRUE;
  c28_u = sf_mex_dup(c28_st);
  c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 0)),
                       "G_Version1", c28_dv0);
  for (c28_i1 = 0; c28_i1 < 6; c28_i1++) {
    (*c28_G_Version1)[c28_i1] = c28_dv0[c28_i1];
  }

  chartInstance->c28_is_active_c28_JointSpaceControl_CorrectFalseCombo =
    c28_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 1)),
    "is_active_c28_JointSpaceControl_CorrectFalseCombo");
  sf_mex_destroy(&c28_u);
  c28_update_debugger_state_c28_JointSpaceControl_CorrectFalseComb(chartInstance);
  sf_mex_destroy(&c28_st);
}

static void finalize_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void sf_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c28_i2;
  int32_T c28_i3;
  real_T (*c28_G_Version1)[6];
  real_T (*c28_q)[6];
  c28_G_Version1 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c28_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c28_sfEvent);
  for (c28_i2 = 0; c28_i2 < 6; c28_i2++) {
    _SFD_DATA_RANGE_CHECK((*c28_q)[c28_i2], 0U);
  }

  for (c28_i3 = 0; c28_i3 < 6; c28_i3++) {
    _SFD_DATA_RANGE_CHECK((*c28_G_Version1)[c28_i3], 1U);
  }

  chartInstance->c28_sfEvent = CALL_EVENT;
  c28_chartstep_c28_JointSpaceControl_CorrectFalseCombo(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectFalseComboMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c28_chartstep_c28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
  int32_T c28_i4;
  real_T c28_q[6];
  uint32_T c28_debug_family_var_map[4];
  real_T c28_nargin = 1.0;
  real_T c28_nargout = 1.0;
  real_T c28_G_Version1[6];
  real_T c28_x;
  real_T c28_b_x;
  real_T c28_b;
  real_T c28_y;
  real_T c28_c_x;
  real_T c28_d_x;
  real_T c28_b_b;
  real_T c28_b_y;
  real_T c28_e_x;
  real_T c28_f_x;
  real_T c28_a;
  real_T c28_c_b;
  real_T c28_c_y;
  real_T c28_g_x;
  real_T c28_h_x;
  real_T c28_d_b;
  real_T c28_d_y;
  real_T c28_i_x;
  real_T c28_j_x;
  real_T c28_b_a;
  real_T c28_e_b;
  real_T c28_e_y;
  real_T c28_k_x;
  real_T c28_l_x;
  real_T c28_f_b;
  real_T c28_f_y;
  real_T c28_g_b;
  real_T c28_g_y;
  real_T c28_m_x;
  real_T c28_n_x;
  real_T c28_c_a;
  real_T c28_h_b;
  real_T c28_h_y;
  real_T c28_o_x;
  real_T c28_p_x;
  real_T c28_q_x;
  real_T c28_r_x;
  real_T c28_d_a;
  real_T c28_i_b;
  real_T c28_i_y;
  real_T c28_s_x;
  real_T c28_t_x;
  real_T c28_u_x;
  real_T c28_v_x;
  real_T c28_e_a;
  real_T c28_j_b;
  real_T c28_j_y;
  real_T c28_k_b;
  real_T c28_k_y;
  real_T c28_w_x;
  real_T c28_x_x;
  real_T c28_f_a;
  real_T c28_l_b;
  real_T c28_l_y;
  real_T c28_y_x;
  real_T c28_ab_x;
  real_T c28_m_b;
  real_T c28_m_y;
  real_T c28_bb_x;
  real_T c28_cb_x;
  real_T c28_db_x;
  real_T c28_eb_x;
  real_T c28_g_a;
  real_T c28_n_b;
  real_T c28_n_y;
  real_T c28_fb_x;
  real_T c28_gb_x;
  real_T c28_hb_x;
  real_T c28_ib_x;
  real_T c28_h_a;
  real_T c28_o_b;
  real_T c28_o_y;
  real_T c28_i_a;
  real_T c28_p_b;
  real_T c28_p_y;
  real_T c28_jb_x;
  real_T c28_kb_x;
  real_T c28_q_b;
  real_T c28_q_y;
  real_T c28_lb_x;
  real_T c28_mb_x;
  real_T c28_nb_x;
  real_T c28_ob_x;
  real_T c28_j_a;
  real_T c28_r_b;
  real_T c28_r_y;
  real_T c28_pb_x;
  real_T c28_qb_x;
  real_T c28_rb_x;
  real_T c28_sb_x;
  real_T c28_k_a;
  real_T c28_s_b;
  real_T c28_s_y;
  real_T c28_l_a;
  real_T c28_t_b;
  real_T c28_t_y;
  real_T c28_tb_x;
  real_T c28_ub_x;
  real_T c28_u_b;
  real_T c28_u_y;
  real_T c28_vb_x;
  real_T c28_wb_x;
  real_T c28_xb_x;
  real_T c28_yb_x;
  real_T c28_ac_x;
  real_T c28_bc_x;
  real_T c28_m_a;
  real_T c28_v_b;
  real_T c28_v_y;
  real_T c28_cc_x;
  real_T c28_dc_x;
  real_T c28_ec_x;
  real_T c28_fc_x;
  real_T c28_n_a;
  real_T c28_w_b;
  real_T c28_w_y;
  real_T c28_o_a;
  real_T c28_x_b;
  real_T c28_x_y;
  real_T c28_gc_x;
  real_T c28_hc_x;
  real_T c28_ic_x;
  real_T c28_jc_x;
  real_T c28_kc_x;
  real_T c28_lc_x;
  real_T c28_p_a;
  real_T c28_y_b;
  real_T c28_y_y;
  real_T c28_mc_x;
  real_T c28_nc_x;
  real_T c28_oc_x;
  real_T c28_pc_x;
  real_T c28_q_a;
  real_T c28_ab_b;
  real_T c28_ab_y;
  real_T c28_r_a;
  real_T c28_bb_b;
  real_T c28_bb_y;
  real_T c28_s_a;
  real_T c28_cb_b;
  real_T c28_cb_y;
  real_T c28_qc_x;
  real_T c28_rc_x;
  real_T c28_db_b;
  real_T c28_db_y;
  real_T c28_sc_x;
  real_T c28_tc_x;
  real_T c28_t_a;
  real_T c28_eb_b;
  real_T c28_eb_y;
  real_T c28_uc_x;
  real_T c28_vc_x;
  real_T c28_fb_b;
  real_T c28_fb_y;
  real_T c28_wc_x;
  real_T c28_xc_x;
  real_T c28_u_a;
  real_T c28_gb_b;
  real_T c28_gb_y;
  real_T c28_hb_b;
  real_T c28_hb_y;
  real_T c28_yc_x;
  real_T c28_ad_x;
  real_T c28_v_a;
  real_T c28_ib_b;
  real_T c28_ib_y;
  real_T c28_bd_x;
  real_T c28_cd_x;
  real_T c28_jb_b;
  real_T c28_jb_y;
  real_T c28_dd_x;
  real_T c28_ed_x;
  real_T c28_w_a;
  real_T c28_kb_b;
  real_T c28_kb_y;
  real_T c28_fd_x;
  real_T c28_gd_x;
  real_T c28_x_a;
  real_T c28_lb_b;
  real_T c28_lb_y;
  real_T c28_hd_x;
  real_T c28_id_x;
  real_T c28_mb_b;
  real_T c28_mb_y;
  real_T c28_nb_b;
  real_T c28_nb_y;
  real_T c28_jd_x;
  real_T c28_kd_x;
  real_T c28_y_a;
  real_T c28_ob_b;
  real_T c28_ob_y;
  real_T c28_ld_x;
  real_T c28_md_x;
  real_T c28_ab_a;
  real_T c28_pb_b;
  real_T c28_pb_y;
  real_T c28_nd_x;
  real_T c28_od_x;
  real_T c28_qb_b;
  real_T c28_qb_y;
  real_T c28_pd_x;
  real_T c28_qd_x;
  real_T c28_bb_a;
  real_T c28_rb_b;
  real_T c28_rb_y;
  real_T c28_rd_x;
  real_T c28_sd_x;
  real_T c28_sb_b;
  real_T c28_sb_y;
  real_T c28_td_x;
  real_T c28_ud_x;
  real_T c28_cb_a;
  real_T c28_tb_b;
  real_T c28_tb_y;
  real_T c28_vd_x;
  real_T c28_wd_x;
  real_T c28_ub_b;
  real_T c28_ub_y;
  real_T c28_xd_x;
  real_T c28_yd_x;
  real_T c28_db_a;
  real_T c28_vb_b;
  real_T c28_vb_y;
  real_T c28_ae_x;
  real_T c28_be_x;
  real_T c28_wb_b;
  real_T c28_wb_y;
  real_T c28_ce_x;
  real_T c28_de_x;
  real_T c28_eb_a;
  real_T c28_xb_b;
  real_T c28_xb_y;
  real_T c28_yb_b;
  real_T c28_yb_y;
  real_T c28_ee_x;
  real_T c28_fe_x;
  real_T c28_fb_a;
  real_T c28_ac_b;
  real_T c28_ac_y;
  real_T c28_ge_x;
  real_T c28_he_x;
  real_T c28_bc_b;
  real_T c28_bc_y;
  real_T c28_ie_x;
  real_T c28_je_x;
  real_T c28_gb_a;
  real_T c28_cc_b;
  real_T c28_cc_y;
  real_T c28_ke_x;
  real_T c28_le_x;
  real_T c28_dc_b;
  real_T c28_dc_y;
  real_T c28_ec_b;
  real_T c28_ec_y;
  real_T c28_me_x;
  real_T c28_ne_x;
  real_T c28_hb_a;
  real_T c28_fc_b;
  real_T c28_fc_y;
  real_T c28_oe_x;
  real_T c28_pe_x;
  real_T c28_ib_a;
  real_T c28_gc_b;
  real_T c28_gc_y;
  real_T c28_qe_x;
  real_T c28_re_x;
  real_T c28_hc_b;
  real_T c28_hc_y;
  real_T c28_se_x;
  real_T c28_te_x;
  real_T c28_jb_a;
  real_T c28_ic_b;
  real_T c28_ic_y;
  real_T c28_ue_x;
  real_T c28_ve_x;
  real_T c28_jc_b;
  real_T c28_jc_y;
  real_T c28_kc_b;
  real_T c28_kc_y;
  real_T c28_we_x;
  real_T c28_xe_x;
  real_T c28_kb_a;
  real_T c28_lc_b;
  real_T c28_lc_y;
  real_T c28_ye_x;
  real_T c28_af_x;
  real_T c28_lb_a;
  real_T c28_mc_b;
  real_T c28_mc_y;
  real_T c28_bf_x;
  real_T c28_cf_x;
  real_T c28_nc_b;
  real_T c28_nc_y;
  real_T c28_df_x;
  real_T c28_ef_x;
  real_T c28_mb_a;
  real_T c28_oc_b;
  real_T c28_oc_y;
  real_T c28_ff_x;
  real_T c28_gf_x;
  real_T c28_pc_b;
  real_T c28_pc_y;
  real_T c28_hf_x;
  real_T c28_if_x;
  real_T c28_nb_a;
  real_T c28_qc_b;
  real_T c28_qc_y;
  real_T c28_jf_x;
  real_T c28_kf_x;
  real_T c28_lf_x;
  real_T c28_mf_x;
  real_T c28_ob_a;
  real_T c28_rc_b;
  real_T c28_rc_y;
  real_T c28_nf_x;
  real_T c28_of_x;
  real_T c28_pf_x;
  real_T c28_qf_x;
  real_T c28_pb_a;
  real_T c28_sc_b;
  real_T c28_sc_y;
  real_T c28_tc_b;
  real_T c28_tc_y;
  real_T c28_rf_x;
  real_T c28_sf_x;
  real_T c28_qb_a;
  real_T c28_uc_b;
  real_T c28_uc_y;
  real_T c28_tf_x;
  real_T c28_uf_x;
  real_T c28_vc_b;
  real_T c28_vc_y;
  real_T c28_vf_x;
  real_T c28_wf_x;
  real_T c28_xf_x;
  real_T c28_yf_x;
  real_T c28_rb_a;
  real_T c28_wc_b;
  real_T c28_wc_y;
  real_T c28_ag_x;
  real_T c28_bg_x;
  real_T c28_cg_x;
  real_T c28_dg_x;
  real_T c28_sb_a;
  real_T c28_xc_b;
  real_T c28_xc_y;
  real_T c28_tb_a;
  real_T c28_yc_b;
  real_T c28_yc_y;
  real_T c28_eg_x;
  real_T c28_fg_x;
  real_T c28_ad_b;
  real_T c28_ad_y;
  real_T c28_gg_x;
  real_T c28_hg_x;
  real_T c28_ig_x;
  real_T c28_jg_x;
  real_T c28_ub_a;
  real_T c28_bd_b;
  real_T c28_bd_y;
  real_T c28_kg_x;
  real_T c28_lg_x;
  real_T c28_mg_x;
  real_T c28_ng_x;
  real_T c28_vb_a;
  real_T c28_cd_b;
  real_T c28_cd_y;
  real_T c28_wb_a;
  real_T c28_dd_b;
  real_T c28_dd_y;
  real_T c28_og_x;
  real_T c28_pg_x;
  real_T c28_ed_b;
  real_T c28_ed_y;
  real_T c28_qg_x;
  real_T c28_rg_x;
  real_T c28_sg_x;
  real_T c28_tg_x;
  real_T c28_ug_x;
  real_T c28_vg_x;
  real_T c28_xb_a;
  real_T c28_fd_b;
  real_T c28_fd_y;
  real_T c28_wg_x;
  real_T c28_xg_x;
  real_T c28_yg_x;
  real_T c28_ah_x;
  real_T c28_yb_a;
  real_T c28_gd_b;
  real_T c28_gd_y;
  real_T c28_ac_a;
  real_T c28_hd_b;
  real_T c28_hd_y;
  real_T c28_bh_x;
  real_T c28_ch_x;
  real_T c28_dh_x;
  real_T c28_eh_x;
  real_T c28_fh_x;
  real_T c28_gh_x;
  real_T c28_bc_a;
  real_T c28_id_b;
  real_T c28_id_y;
  real_T c28_hh_x;
  real_T c28_ih_x;
  real_T c28_jh_x;
  real_T c28_kh_x;
  real_T c28_cc_a;
  real_T c28_jd_b;
  real_T c28_jd_y;
  real_T c28_dc_a;
  real_T c28_kd_b;
  real_T c28_kd_y;
  real_T c28_ec_a;
  real_T c28_ld_b;
  real_T c28_ld_y;
  real_T c28_lh_x;
  real_T c28_mh_x;
  real_T c28_md_b;
  real_T c28_md_y;
  real_T c28_nh_x;
  real_T c28_oh_x;
  real_T c28_fc_a;
  real_T c28_nd_b;
  real_T c28_nd_y;
  real_T c28_ph_x;
  real_T c28_qh_x;
  real_T c28_od_b;
  real_T c28_od_y;
  real_T c28_rh_x;
  real_T c28_sh_x;
  real_T c28_gc_a;
  real_T c28_pd_b;
  real_T c28_pd_y;
  real_T c28_qd_b;
  real_T c28_qd_y;
  real_T c28_th_x;
  real_T c28_uh_x;
  real_T c28_hc_a;
  real_T c28_rd_b;
  real_T c28_rd_y;
  real_T c28_vh_x;
  real_T c28_wh_x;
  real_T c28_sd_b;
  real_T c28_sd_y;
  real_T c28_xh_x;
  real_T c28_yh_x;
  real_T c28_ic_a;
  real_T c28_td_b;
  real_T c28_td_y;
  real_T c28_ai_x;
  real_T c28_bi_x;
  real_T c28_jc_a;
  real_T c28_ud_b;
  real_T c28_ud_y;
  real_T c28_ci_x;
  real_T c28_di_x;
  real_T c28_vd_b;
  real_T c28_vd_y;
  real_T c28_wd_b;
  real_T c28_wd_y;
  real_T c28_ei_x;
  real_T c28_fi_x;
  real_T c28_kc_a;
  real_T c28_xd_b;
  real_T c28_xd_y;
  real_T c28_gi_x;
  real_T c28_hi_x;
  real_T c28_lc_a;
  real_T c28_yd_b;
  real_T c28_yd_y;
  real_T c28_ii_x;
  real_T c28_ji_x;
  real_T c28_ae_b;
  real_T c28_ae_y;
  real_T c28_ki_x;
  real_T c28_li_x;
  real_T c28_mc_a;
  real_T c28_be_b;
  real_T c28_be_y;
  real_T c28_mi_x;
  real_T c28_ni_x;
  real_T c28_ce_b;
  real_T c28_ce_y;
  real_T c28_oi_x;
  real_T c28_pi_x;
  real_T c28_nc_a;
  real_T c28_de_b;
  real_T c28_de_y;
  real_T c28_qi_x;
  real_T c28_ri_x;
  real_T c28_ee_b;
  real_T c28_ee_y;
  real_T c28_si_x;
  real_T c28_ti_x;
  real_T c28_oc_a;
  real_T c28_fe_b;
  real_T c28_fe_y;
  real_T c28_ui_x;
  real_T c28_vi_x;
  real_T c28_ge_b;
  real_T c28_ge_y;
  real_T c28_wi_x;
  real_T c28_xi_x;
  real_T c28_pc_a;
  real_T c28_he_b;
  real_T c28_he_y;
  real_T c28_ie_b;
  real_T c28_ie_y;
  real_T c28_yi_x;
  real_T c28_aj_x;
  real_T c28_qc_a;
  real_T c28_je_b;
  real_T c28_je_y;
  real_T c28_bj_x;
  real_T c28_cj_x;
  real_T c28_ke_b;
  real_T c28_ke_y;
  real_T c28_dj_x;
  real_T c28_ej_x;
  real_T c28_rc_a;
  real_T c28_le_b;
  real_T c28_le_y;
  real_T c28_fj_x;
  real_T c28_gj_x;
  real_T c28_me_b;
  real_T c28_me_y;
  real_T c28_ne_b;
  real_T c28_ne_y;
  real_T c28_hj_x;
  real_T c28_ij_x;
  real_T c28_sc_a;
  real_T c28_oe_b;
  real_T c28_oe_y;
  real_T c28_jj_x;
  real_T c28_kj_x;
  real_T c28_tc_a;
  real_T c28_pe_b;
  real_T c28_pe_y;
  real_T c28_lj_x;
  real_T c28_mj_x;
  real_T c28_qe_b;
  real_T c28_qe_y;
  real_T c28_nj_x;
  real_T c28_oj_x;
  real_T c28_uc_a;
  real_T c28_re_b;
  real_T c28_re_y;
  real_T c28_pj_x;
  real_T c28_qj_x;
  real_T c28_se_b;
  real_T c28_se_y;
  real_T c28_te_b;
  real_T c28_te_y;
  real_T c28_rj_x;
  real_T c28_sj_x;
  real_T c28_vc_a;
  real_T c28_ue_b;
  real_T c28_ue_y;
  real_T c28_tj_x;
  real_T c28_uj_x;
  real_T c28_wc_a;
  real_T c28_ve_b;
  real_T c28_ve_y;
  real_T c28_vj_x;
  real_T c28_wj_x;
  real_T c28_we_b;
  real_T c28_we_y;
  real_T c28_xj_x;
  real_T c28_yj_x;
  real_T c28_ak_x;
  real_T c28_bk_x;
  real_T c28_xc_a;
  real_T c28_xe_b;
  real_T c28_xe_y;
  real_T c28_ck_x;
  real_T c28_dk_x;
  real_T c28_ek_x;
  real_T c28_fk_x;
  real_T c28_yc_a;
  real_T c28_ye_b;
  real_T c28_ye_y;
  real_T c28_ad_a;
  real_T c28_af_b;
  real_T c28_af_y;
  real_T c28_gk_x;
  real_T c28_hk_x;
  real_T c28_bf_b;
  real_T c28_bf_y;
  real_T c28_ik_x;
  real_T c28_jk_x;
  real_T c28_kk_x;
  real_T c28_lk_x;
  real_T c28_bd_a;
  real_T c28_cf_b;
  real_T c28_cf_y;
  real_T c28_mk_x;
  real_T c28_nk_x;
  real_T c28_ok_x;
  real_T c28_pk_x;
  real_T c28_cd_a;
  real_T c28_df_b;
  real_T c28_df_y;
  real_T c28_dd_a;
  real_T c28_ef_b;
  real_T c28_ef_y;
  real_T c28_qk_x;
  real_T c28_rk_x;
  real_T c28_sk_x;
  real_T c28_tk_x;
  real_T c28_ed_a;
  real_T c28_ff_b;
  real_T c28_ff_y;
  real_T c28_uk_x;
  real_T c28_vk_x;
  real_T c28_wk_x;
  real_T c28_xk_x;
  real_T c28_fd_a;
  real_T c28_gf_b;
  real_T c28_gf_y;
  real_T c28_hf_b;
  real_T c28_hf_y;
  real_T c28_yk_x;
  real_T c28_al_x;
  real_T c28_gd_a;
  real_T c28_if_b;
  real_T c28_if_y;
  real_T c28_bl_x;
  real_T c28_cl_x;
  real_T c28_jf_b;
  real_T c28_jf_y;
  real_T c28_dl_x;
  real_T c28_el_x;
  real_T c28_fl_x;
  real_T c28_gl_x;
  real_T c28_hd_a;
  real_T c28_kf_b;
  real_T c28_kf_y;
  real_T c28_hl_x;
  real_T c28_il_x;
  real_T c28_jl_x;
  real_T c28_kl_x;
  real_T c28_id_a;
  real_T c28_lf_b;
  real_T c28_lf_y;
  real_T c28_ll_x;
  real_T c28_ml_x;
  real_T c28_jd_a;
  real_T c28_mf_b;
  real_T c28_mf_y;
  real_T c28_nl_x;
  real_T c28_ol_x;
  real_T c28_pl_x;
  real_T c28_ql_x;
  real_T c28_rl_x;
  real_T c28_sl_x;
  real_T c28_kd_a;
  real_T c28_nf_b;
  real_T c28_nf_y;
  real_T c28_tl_x;
  real_T c28_ul_x;
  real_T c28_vl_x;
  real_T c28_wl_x;
  real_T c28_ld_a;
  real_T c28_of_b;
  real_T c28_of_y;
  real_T c28_md_a;
  real_T c28_pf_b;
  real_T c28_pf_y;
  real_T c28_nd_a;
  real_T c28_qf_b;
  real_T c28_qf_y;
  real_T c28_xl_x;
  real_T c28_yl_x;
  real_T c28_rf_b;
  real_T c28_rf_y;
  real_T c28_am_x;
  real_T c28_bm_x;
  real_T c28_od_a;
  real_T c28_sf_b;
  real_T c28_sf_y;
  real_T c28_cm_x;
  real_T c28_dm_x;
  real_T c28_tf_b;
  real_T c28_tf_y;
  real_T c28_em_x;
  real_T c28_fm_x;
  real_T c28_pd_a;
  real_T c28_uf_b;
  real_T c28_uf_y;
  real_T c28_vf_b;
  real_T c28_vf_y;
  real_T c28_gm_x;
  real_T c28_hm_x;
  real_T c28_qd_a;
  real_T c28_wf_b;
  real_T c28_wf_y;
  real_T c28_im_x;
  real_T c28_jm_x;
  real_T c28_xf_b;
  real_T c28_xf_y;
  real_T c28_km_x;
  real_T c28_lm_x;
  real_T c28_rd_a;
  real_T c28_yf_b;
  real_T c28_yf_y;
  real_T c28_mm_x;
  real_T c28_nm_x;
  real_T c28_sd_a;
  real_T c28_ag_b;
  real_T c28_ag_y;
  real_T c28_om_x;
  real_T c28_pm_x;
  real_T c28_bg_b;
  real_T c28_bg_y;
  real_T c28_qm_x;
  real_T c28_rm_x;
  real_T c28_td_a;
  real_T c28_cg_b;
  real_T c28_cg_y;
  real_T c28_sm_x;
  real_T c28_tm_x;
  real_T c28_ud_a;
  real_T c28_dg_b;
  real_T c28_dg_y;
  real_T c28_um_x;
  real_T c28_vm_x;
  real_T c28_eg_b;
  real_T c28_eg_y;
  real_T c28_wm_x;
  real_T c28_xm_x;
  real_T c28_vd_a;
  real_T c28_fg_b;
  real_T c28_fg_y;
  real_T c28_ym_x;
  real_T c28_an_x;
  real_T c28_gg_b;
  real_T c28_gg_y;
  real_T c28_bn_x;
  real_T c28_cn_x;
  real_T c28_wd_a;
  real_T c28_hg_b;
  real_T c28_hg_y;
  real_T c28_dn_x;
  real_T c28_en_x;
  real_T c28_ig_b;
  real_T c28_ig_y;
  real_T c28_fn_x;
  real_T c28_gn_x;
  real_T c28_xd_a;
  real_T c28_jg_b;
  real_T c28_jg_y;
  real_T c28_hn_x;
  real_T c28_in_x;
  real_T c28_kg_b;
  real_T c28_kg_y;
  real_T c28_jn_x;
  real_T c28_kn_x;
  real_T c28_yd_a;
  real_T c28_lg_b;
  real_T c28_lg_y;
  real_T c28_mg_b;
  real_T c28_mg_y;
  real_T c28_ln_x;
  real_T c28_mn_x;
  real_T c28_ae_a;
  real_T c28_ng_b;
  real_T c28_ng_y;
  real_T c28_nn_x;
  real_T c28_on_x;
  real_T c28_og_b;
  real_T c28_og_y;
  real_T c28_pn_x;
  real_T c28_qn_x;
  real_T c28_be_a;
  real_T c28_pg_b;
  real_T c28_pg_y;
  real_T c28_rn_x;
  real_T c28_sn_x;
  real_T c28_qg_b;
  real_T c28_qg_y;
  real_T c28_rg_b;
  real_T c28_rg_y;
  real_T c28_tn_x;
  real_T c28_un_x;
  real_T c28_ce_a;
  real_T c28_sg_b;
  real_T c28_sg_y;
  real_T c28_vn_x;
  real_T c28_wn_x;
  real_T c28_de_a;
  real_T c28_tg_b;
  real_T c28_tg_y;
  real_T c28_xn_x;
  real_T c28_yn_x;
  real_T c28_ug_b;
  real_T c28_ug_y;
  real_T c28_ao_x;
  real_T c28_bo_x;
  real_T c28_ee_a;
  real_T c28_vg_b;
  real_T c28_vg_y;
  real_T c28_co_x;
  real_T c28_do_x;
  real_T c28_wg_b;
  real_T c28_wg_y;
  real_T c28_xg_b;
  real_T c28_xg_y;
  real_T c28_eo_x;
  real_T c28_fo_x;
  real_T c28_fe_a;
  real_T c28_yg_b;
  real_T c28_yg_y;
  real_T c28_go_x;
  real_T c28_ho_x;
  real_T c28_ge_a;
  real_T c28_ah_b;
  real_T c28_ah_y;
  real_T c28_io_x;
  real_T c28_jo_x;
  real_T c28_ko_x;
  real_T c28_lo_x;
  real_T c28_he_a;
  real_T c28_bh_b;
  real_T c28_bh_y;
  real_T c28_mo_x;
  real_T c28_no_x;
  real_T c28_oo_x;
  real_T c28_po_x;
  real_T c28_ie_a;
  real_T c28_ch_b;
  real_T c28_ch_y;
  real_T c28_qo_x;
  real_T c28_ro_x;
  real_T c28_je_a;
  real_T c28_dh_b;
  real_T c28_dh_y;
  real_T c28_so_x;
  real_T c28_to_x;
  real_T c28_uo_x;
  real_T c28_vo_x;
  real_T c28_wo_x;
  real_T c28_xo_x;
  real_T c28_ke_a;
  real_T c28_eh_b;
  real_T c28_eh_y;
  real_T c28_yo_x;
  real_T c28_ap_x;
  real_T c28_bp_x;
  real_T c28_cp_x;
  real_T c28_le_a;
  real_T c28_fh_b;
  real_T c28_fh_y;
  real_T c28_me_a;
  real_T c28_gh_b;
  real_T c28_gh_y;
  real_T c28_hh_b;
  real_T c28_hh_y;
  real_T c28_dp_x;
  real_T c28_ep_x;
  real_T c28_ne_a;
  real_T c28_ih_b;
  real_T c28_ih_y;
  real_T c28_fp_x;
  real_T c28_gp_x;
  real_T c28_jh_b;
  real_T c28_jh_y;
  real_T c28_hp_x;
  real_T c28_ip_x;
  real_T c28_oe_a;
  real_T c28_kh_b;
  real_T c28_kh_y;
  real_T c28_jp_x;
  real_T c28_kp_x;
  real_T c28_pe_a;
  real_T c28_lh_b;
  real_T c28_lh_y;
  real_T c28_lp_x;
  real_T c28_mp_x;
  real_T c28_mh_b;
  real_T c28_mh_y;
  real_T c28_np_x;
  real_T c28_op_x;
  real_T c28_qe_a;
  real_T c28_nh_b;
  real_T c28_nh_y;
  real_T c28_pp_x;
  real_T c28_qp_x;
  real_T c28_re_a;
  real_T c28_oh_b;
  real_T c28_oh_y;
  real_T c28_ph_b;
  real_T c28_ph_y;
  real_T c28_rp_x;
  real_T c28_sp_x;
  real_T c28_se_a;
  real_T c28_qh_b;
  real_T c28_qh_y;
  real_T c28_tp_x;
  real_T c28_up_x;
  real_T c28_rh_b;
  real_T c28_rh_y;
  real_T c28_vp_x;
  real_T c28_wp_x;
  real_T c28_te_a;
  real_T c28_sh_b;
  real_T c28_sh_y;
  real_T c28_xp_x;
  real_T c28_yp_x;
  real_T c28_ue_a;
  real_T c28_th_b;
  real_T c28_th_y;
  real_T c28_aq_x;
  real_T c28_bq_x;
  real_T c28_ve_a;
  real_T c28_uh_b;
  real_T c28_uh_y;
  real_T c28_cq_x;
  real_T c28_dq_x;
  real_T c28_vh_b;
  real_T c28_vh_y;
  real_T c28_eq_x;
  real_T c28_fq_x;
  real_T c28_we_a;
  real_T c28_wh_b;
  real_T c28_wh_y;
  real_T c28_gq_x;
  real_T c28_hq_x;
  real_T c28_xe_a;
  real_T c28_xh_b;
  real_T c28_xh_y;
  real_T c28_iq_x;
  real_T c28_jq_x;
  real_T c28_ye_a;
  real_T c28_yh_b;
  real_T c28_yh_y;
  int32_T c28_i5;
  real_T (*c28_b_G_Version1)[6];
  real_T (*c28_b_q)[6];
  c28_b_G_Version1 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c28_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c28_sfEvent);
  for (c28_i4 = 0; c28_i4 < 6; c28_i4++) {
    c28_q[c28_i4] = (*c28_b_q)[c28_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c28_debug_family_names,
    c28_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargin, 0U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargout, 1U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c28_q, 2U, c28_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_G_Version1, 3U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 6);
  c28_x = c28_q[1];
  c28_b_x = c28_x;
  c28_b_x = muDoubleScalarSin(c28_b_x);
  c28_b = c28_b_x;
  c28_y = -17.49625762 * c28_b;
  c28_c_x = c28_q[1];
  c28_d_x = c28_c_x;
  c28_d_x = muDoubleScalarSin(c28_d_x);
  c28_b_b = c28_d_x;
  c28_b_y = 2.676567758 * c28_b_b;
  c28_e_x = c28_q[2];
  c28_f_x = c28_e_x;
  c28_f_x = muDoubleScalarCos(c28_f_x);
  c28_a = c28_b_y;
  c28_c_b = c28_f_x;
  c28_c_y = c28_a * c28_c_b;
  c28_g_x = c28_q[1];
  c28_h_x = c28_g_x;
  c28_h_x = muDoubleScalarCos(c28_h_x);
  c28_d_b = c28_h_x;
  c28_d_y = 10.76824816 * c28_d_b;
  c28_i_x = c28_q[2];
  c28_j_x = c28_i_x;
  c28_j_x = muDoubleScalarSin(c28_j_x);
  c28_b_a = c28_d_y;
  c28_e_b = c28_j_x;
  c28_e_y = c28_b_a * c28_e_b;
  c28_k_x = c28_q[2];
  c28_l_x = c28_k_x;
  c28_l_x = muDoubleScalarCos(c28_l_x);
  c28_f_b = c28_l_x;
  c28_f_y = 0.39225 * c28_f_b;
  c28_g_b = c28_f_y + 0.425;
  c28_g_y = 34.27614 * c28_g_b;
  c28_m_x = c28_q[1];
  c28_n_x = c28_m_x;
  c28_n_x = muDoubleScalarSin(c28_n_x);
  c28_c_a = c28_g_y;
  c28_h_b = c28_n_x;
  c28_h_y = c28_c_a * c28_h_b;
  c28_o_x = c28_q[1];
  c28_p_x = c28_o_x;
  c28_p_x = muDoubleScalarCos(c28_p_x);
  c28_q_x = c28_q[2];
  c28_r_x = c28_q_x;
  c28_r_x = muDoubleScalarCos(c28_r_x);
  c28_d_a = -c28_p_x;
  c28_i_b = c28_r_x;
  c28_i_y = c28_d_a * c28_i_b;
  c28_s_x = c28_q[1];
  c28_t_x = c28_s_x;
  c28_t_x = muDoubleScalarSin(c28_t_x);
  c28_u_x = c28_q[2];
  c28_v_x = c28_u_x;
  c28_v_x = muDoubleScalarSin(c28_v_x);
  c28_e_a = c28_t_x;
  c28_j_b = c28_v_x;
  c28_j_y = c28_e_a * c28_j_b;
  c28_k_b = c28_i_y + c28_j_y;
  c28_k_y = 0.1954000926 * c28_k_b;
  c28_w_x = c28_q[3];
  c28_x_x = c28_w_x;
  c28_x_x = muDoubleScalarSin(c28_x_x);
  c28_f_a = c28_k_y;
  c28_l_b = c28_x_x;
  c28_l_y = c28_f_a * c28_l_b;
  c28_y_x = c28_q[3];
  c28_ab_x = c28_y_x;
  c28_ab_x = muDoubleScalarCos(c28_ab_x);
  c28_m_b = c28_ab_x;
  c28_m_y = 0.1738749906 * c28_m_b;
  c28_bb_x = c28_q[1];
  c28_cb_x = c28_bb_x;
  c28_cb_x = muDoubleScalarSin(c28_cb_x);
  c28_db_x = c28_q[2];
  c28_eb_x = c28_db_x;
  c28_eb_x = muDoubleScalarCos(c28_eb_x);
  c28_g_a = -c28_cb_x;
  c28_n_b = c28_eb_x;
  c28_n_y = c28_g_a * c28_n_b;
  c28_fb_x = c28_q[1];
  c28_gb_x = c28_fb_x;
  c28_gb_x = muDoubleScalarCos(c28_gb_x);
  c28_hb_x = c28_q[2];
  c28_ib_x = c28_hb_x;
  c28_ib_x = muDoubleScalarSin(c28_ib_x);
  c28_h_a = c28_gb_x;
  c28_o_b = c28_ib_x;
  c28_o_y = c28_h_a * c28_o_b;
  c28_i_a = c28_m_y;
  c28_p_b = c28_n_y - c28_o_y;
  c28_p_y = c28_i_a * c28_p_b;
  c28_jb_x = c28_q[3];
  c28_kb_x = c28_jb_x;
  c28_kb_x = muDoubleScalarSin(c28_kb_x);
  c28_q_b = c28_kb_x;
  c28_q_y = 0.021525102 * c28_q_b;
  c28_lb_x = c28_q[1];
  c28_mb_x = c28_lb_x;
  c28_mb_x = muDoubleScalarSin(c28_mb_x);
  c28_nb_x = c28_q[2];
  c28_ob_x = c28_nb_x;
  c28_ob_x = muDoubleScalarSin(c28_ob_x);
  c28_j_a = -c28_mb_x;
  c28_r_b = c28_ob_x;
  c28_r_y = c28_j_a * c28_r_b;
  c28_pb_x = c28_q[1];
  c28_qb_x = c28_pb_x;
  c28_qb_x = muDoubleScalarCos(c28_qb_x);
  c28_rb_x = c28_q[2];
  c28_sb_x = c28_rb_x;
  c28_sb_x = muDoubleScalarCos(c28_sb_x);
  c28_k_a = c28_qb_x;
  c28_s_b = c28_sb_x;
  c28_s_y = c28_k_a * c28_s_b;
  c28_l_a = c28_q_y;
  c28_t_b = c28_r_y + c28_s_y;
  c28_t_y = c28_l_a * c28_t_b;
  c28_tb_x = c28_q[4];
  c28_ub_x = c28_tb_x;
  c28_ub_x = muDoubleScalarSin(c28_ub_x);
  c28_u_b = c28_ub_x;
  c28_u_y = 0.1932637091 * c28_u_b;
  c28_vb_x = c28_q[3];
  c28_wb_x = c28_vb_x;
  c28_wb_x = muDoubleScalarSin(c28_wb_x);
  c28_xb_x = c28_q[1];
  c28_yb_x = c28_xb_x;
  c28_yb_x = muDoubleScalarSin(c28_yb_x);
  c28_ac_x = c28_q[2];
  c28_bc_x = c28_ac_x;
  c28_bc_x = muDoubleScalarCos(c28_bc_x);
  c28_m_a = -c28_yb_x;
  c28_v_b = c28_bc_x;
  c28_v_y = c28_m_a * c28_v_b;
  c28_cc_x = c28_q[1];
  c28_dc_x = c28_cc_x;
  c28_dc_x = muDoubleScalarCos(c28_dc_x);
  c28_ec_x = c28_q[2];
  c28_fc_x = c28_ec_x;
  c28_fc_x = muDoubleScalarSin(c28_fc_x);
  c28_n_a = c28_dc_x;
  c28_w_b = c28_fc_x;
  c28_w_y = c28_n_a * c28_w_b;
  c28_o_a = c28_wb_x;
  c28_x_b = c28_v_y - c28_w_y;
  c28_x_y = c28_o_a * c28_x_b;
  c28_gc_x = c28_q[3];
  c28_hc_x = c28_gc_x;
  c28_hc_x = muDoubleScalarCos(c28_hc_x);
  c28_ic_x = c28_q[1];
  c28_jc_x = c28_ic_x;
  c28_jc_x = muDoubleScalarSin(c28_jc_x);
  c28_kc_x = c28_q[2];
  c28_lc_x = c28_kc_x;
  c28_lc_x = muDoubleScalarSin(c28_lc_x);
  c28_p_a = -c28_jc_x;
  c28_y_b = c28_lc_x;
  c28_y_y = c28_p_a * c28_y_b;
  c28_mc_x = c28_q[1];
  c28_nc_x = c28_mc_x;
  c28_nc_x = muDoubleScalarCos(c28_nc_x);
  c28_oc_x = c28_q[2];
  c28_pc_x = c28_oc_x;
  c28_pc_x = muDoubleScalarCos(c28_pc_x);
  c28_q_a = c28_nc_x;
  c28_ab_b = c28_pc_x;
  c28_ab_y = c28_q_a * c28_ab_b;
  c28_r_a = c28_hc_x;
  c28_bb_b = c28_y_y + c28_ab_y;
  c28_bb_y = c28_r_a * c28_bb_b;
  c28_s_a = c28_u_y;
  c28_cb_b = c28_x_y + c28_bb_y;
  c28_cb_y = c28_s_a * c28_cb_b;
  c28_qc_x = c28_q[3];
  c28_rc_x = c28_qc_x;
  c28_rc_x = muDoubleScalarCos(c28_rc_x);
  c28_db_b = c28_rc_x;
  c28_db_y = 0.09465 * c28_db_b;
  c28_sc_x = c28_q[2];
  c28_tc_x = c28_sc_x;
  c28_tc_x = muDoubleScalarCos(c28_tc_x);
  c28_t_a = c28_db_y + 0.39225;
  c28_eb_b = c28_tc_x;
  c28_eb_y = c28_t_a * c28_eb_b;
  c28_uc_x = c28_q[3];
  c28_vc_x = c28_uc_x;
  c28_vc_x = muDoubleScalarSin(c28_vc_x);
  c28_fb_b = c28_vc_x;
  c28_fb_y = 0.09465 * c28_fb_b;
  c28_wc_x = c28_q[2];
  c28_xc_x = c28_wc_x;
  c28_xc_x = muDoubleScalarSin(c28_xc_x);
  c28_u_a = c28_fb_y;
  c28_gb_b = c28_xc_x;
  c28_gb_y = c28_u_a * c28_gb_b;
  c28_hb_b = (c28_eb_y - c28_gb_y) + 0.425;
  c28_hb_y = 11.95839 * c28_hb_b;
  c28_yc_x = c28_q[1];
  c28_ad_x = c28_yc_x;
  c28_ad_x = muDoubleScalarSin(c28_ad_x);
  c28_v_a = c28_hb_y;
  c28_ib_b = c28_ad_x;
  c28_ib_y = c28_v_a * c28_ib_b;
  c28_bd_x = c28_q[3];
  c28_cd_x = c28_bd_x;
  c28_cd_x = muDoubleScalarSin(c28_cd_x);
  c28_jb_b = c28_cd_x;
  c28_jb_y = 1.131861614 * c28_jb_b;
  c28_dd_x = c28_q[1];
  c28_ed_x = c28_dd_x;
  c28_ed_x = muDoubleScalarCos(c28_ed_x);
  c28_w_a = c28_jb_y;
  c28_kb_b = c28_ed_x;
  c28_kb_y = c28_w_a * c28_kb_b;
  c28_fd_x = c28_q[2];
  c28_gd_x = c28_fd_x;
  c28_gd_x = muDoubleScalarCos(c28_gd_x);
  c28_x_a = c28_kb_y;
  c28_lb_b = c28_gd_x;
  c28_lb_y = c28_x_a * c28_lb_b;
  c28_hd_x = c28_q[3];
  c28_id_x = c28_hd_x;
  c28_id_x = muDoubleScalarCos(c28_id_x);
  c28_mb_b = c28_id_x;
  c28_mb_y = -0.09465 * c28_mb_b;
  c28_nb_b = c28_mb_y - 0.39225;
  c28_nb_y = 11.95839 * c28_nb_b;
  c28_jd_x = c28_q[2];
  c28_kd_x = c28_jd_x;
  c28_kd_x = muDoubleScalarSin(c28_kd_x);
  c28_y_a = c28_nb_y;
  c28_ob_b = c28_kd_x;
  c28_ob_y = c28_y_a * c28_ob_b;
  c28_ld_x = c28_q[1];
  c28_md_x = c28_ld_x;
  c28_md_x = muDoubleScalarCos(c28_md_x);
  c28_ab_a = c28_ob_y;
  c28_pb_b = c28_md_x;
  c28_pb_y = c28_ab_a * c28_pb_b;
  c28_nd_x = c28_q[4];
  c28_od_x = c28_nd_x;
  c28_od_x = muDoubleScalarSin(c28_od_x);
  c28_qb_b = c28_od_x;
  c28_qb_y = 0.0823 * c28_qb_b;
  c28_pd_x = c28_q[3];
  c28_qd_x = c28_pd_x;
  c28_qd_x = muDoubleScalarSin(c28_qd_x);
  c28_bb_a = c28_qb_y;
  c28_rb_b = c28_qd_x;
  c28_rb_y = c28_bb_a * c28_rb_b;
  c28_rd_x = c28_q[3];
  c28_sd_x = c28_rd_x;
  c28_sd_x = muDoubleScalarCos(c28_sd_x);
  c28_sb_b = c28_sd_x;
  c28_sb_y = 0.09465 * c28_sb_b;
  c28_td_x = c28_q[2];
  c28_ud_x = c28_td_x;
  c28_ud_x = muDoubleScalarCos(c28_ud_x);
  c28_cb_a = (c28_rb_y + c28_sb_y) + 0.39225;
  c28_tb_b = c28_ud_x;
  c28_tb_y = c28_cb_a * c28_tb_b;
  c28_vd_x = c28_q[4];
  c28_wd_x = c28_vd_x;
  c28_wd_x = muDoubleScalarSin(c28_wd_x);
  c28_ub_b = c28_wd_x;
  c28_ub_y = 0.0823 * c28_ub_b;
  c28_xd_x = c28_q[3];
  c28_yd_x = c28_xd_x;
  c28_yd_x = muDoubleScalarCos(c28_yd_x);
  c28_db_a = c28_ub_y;
  c28_vb_b = c28_yd_x;
  c28_vb_y = c28_db_a * c28_vb_b;
  c28_ae_x = c28_q[3];
  c28_be_x = c28_ae_x;
  c28_be_x = muDoubleScalarSin(c28_be_x);
  c28_wb_b = c28_be_x;
  c28_wb_y = 0.09465 * c28_wb_b;
  c28_ce_x = c28_q[2];
  c28_de_x = c28_ce_x;
  c28_de_x = muDoubleScalarSin(c28_de_x);
  c28_eb_a = c28_vb_y - c28_wb_y;
  c28_xb_b = c28_de_x;
  c28_xb_y = c28_eb_a * c28_xb_b;
  c28_yb_b = (c28_tb_y + 0.425) + c28_xb_y;
  c28_yb_y = 1.843299 * c28_yb_b;
  c28_ee_x = c28_q[1];
  c28_fe_x = c28_ee_x;
  c28_fe_x = muDoubleScalarSin(c28_fe_x);
  c28_fb_a = c28_yb_y;
  c28_ac_b = c28_fe_x;
  c28_ac_y = c28_fb_a * c28_ac_b;
  c28_ge_x = c28_q[4];
  c28_he_x = c28_ge_x;
  c28_he_x = muDoubleScalarSin(c28_he_x);
  c28_bc_b = c28_he_x;
  c28_bc_y = 0.0823 * c28_bc_b;
  c28_ie_x = c28_q[3];
  c28_je_x = c28_ie_x;
  c28_je_x = muDoubleScalarCos(c28_je_x);
  c28_gb_a = c28_bc_y;
  c28_cc_b = c28_je_x;
  c28_cc_y = c28_gb_a * c28_cc_b;
  c28_ke_x = c28_q[3];
  c28_le_x = c28_ke_x;
  c28_le_x = muDoubleScalarSin(c28_le_x);
  c28_dc_b = c28_le_x;
  c28_dc_y = 0.09465 * c28_dc_b;
  c28_ec_b = c28_cc_y - c28_dc_y;
  c28_ec_y = 1.843299 * c28_ec_b;
  c28_me_x = c28_q[1];
  c28_ne_x = c28_me_x;
  c28_ne_x = muDoubleScalarCos(c28_ne_x);
  c28_hb_a = c28_ec_y;
  c28_fc_b = c28_ne_x;
  c28_fc_y = c28_hb_a * c28_fc_b;
  c28_oe_x = c28_q[2];
  c28_pe_x = c28_oe_x;
  c28_pe_x = muDoubleScalarCos(c28_pe_x);
  c28_ib_a = c28_fc_y;
  c28_gc_b = c28_pe_x;
  c28_gc_y = c28_ib_a * c28_gc_b;
  c28_qe_x = c28_q[4];
  c28_re_x = c28_qe_x;
  c28_re_x = muDoubleScalarSin(c28_re_x);
  c28_hc_b = c28_re_x;
  c28_hc_y = 0.0823 * c28_hc_b;
  c28_se_x = c28_q[3];
  c28_te_x = c28_se_x;
  c28_te_x = muDoubleScalarSin(c28_te_x);
  c28_jb_a = c28_hc_y;
  c28_ic_b = c28_te_x;
  c28_ic_y = c28_jb_a * c28_ic_b;
  c28_ue_x = c28_q[3];
  c28_ve_x = c28_ue_x;
  c28_ve_x = muDoubleScalarCos(c28_ve_x);
  c28_jc_b = c28_ve_x;
  c28_jc_y = 0.09465 * c28_jc_b;
  c28_kc_b = (-0.39225 - c28_ic_y) - c28_jc_y;
  c28_kc_y = 1.843299 * c28_kc_b;
  c28_we_x = c28_q[2];
  c28_xe_x = c28_we_x;
  c28_xe_x = muDoubleScalarSin(c28_xe_x);
  c28_kb_a = c28_kc_y;
  c28_lc_b = c28_xe_x;
  c28_lc_y = c28_kb_a * c28_lc_b;
  c28_ye_x = c28_q[1];
  c28_af_x = c28_ye_x;
  c28_af_x = muDoubleScalarCos(c28_af_x);
  c28_lb_a = c28_lc_y;
  c28_mc_b = c28_af_x;
  c28_mc_y = c28_lb_a * c28_mc_b;
  c28_bf_x = c28_q[1];
  c28_cf_x = c28_bf_x;
  c28_cf_x = muDoubleScalarCos(c28_cf_x);
  c28_nc_b = c28_cf_x;
  c28_nc_y = -10.76824816 * c28_nc_b;
  c28_df_x = c28_q[2];
  c28_ef_x = c28_df_x;
  c28_ef_x = muDoubleScalarSin(c28_ef_x);
  c28_mb_a = c28_nc_y;
  c28_oc_b = c28_ef_x;
  c28_oc_y = c28_mb_a * c28_oc_b;
  c28_ff_x = c28_q[1];
  c28_gf_x = c28_ff_x;
  c28_gf_x = muDoubleScalarSin(c28_gf_x);
  c28_pc_b = c28_gf_x;
  c28_pc_y = 10.76824816 * c28_pc_b;
  c28_hf_x = c28_q[2];
  c28_if_x = c28_hf_x;
  c28_if_x = muDoubleScalarCos(c28_if_x);
  c28_nb_a = c28_pc_y;
  c28_qc_b = c28_if_x;
  c28_qc_y = c28_nb_a * c28_qc_b;
  c28_jf_x = c28_q[1];
  c28_kf_x = c28_jf_x;
  c28_kf_x = muDoubleScalarCos(c28_kf_x);
  c28_lf_x = c28_q[2];
  c28_mf_x = c28_lf_x;
  c28_mf_x = muDoubleScalarCos(c28_mf_x);
  c28_ob_a = -c28_kf_x;
  c28_rc_b = c28_mf_x;
  c28_rc_y = c28_ob_a * c28_rc_b;
  c28_nf_x = c28_q[1];
  c28_of_x = c28_nf_x;
  c28_of_x = muDoubleScalarSin(c28_of_x);
  c28_pf_x = c28_q[2];
  c28_qf_x = c28_pf_x;
  c28_qf_x = muDoubleScalarSin(c28_qf_x);
  c28_pb_a = c28_of_x;
  c28_sc_b = c28_qf_x;
  c28_sc_y = c28_pb_a * c28_sc_b;
  c28_tc_b = c28_rc_y + c28_sc_y;
  c28_tc_y = 0.1954000926 * c28_tc_b;
  c28_rf_x = c28_q[3];
  c28_sf_x = c28_rf_x;
  c28_sf_x = muDoubleScalarSin(c28_sf_x);
  c28_qb_a = c28_tc_y;
  c28_uc_b = c28_sf_x;
  c28_uc_y = c28_qb_a * c28_uc_b;
  c28_tf_x = c28_q[3];
  c28_uf_x = c28_tf_x;
  c28_uf_x = muDoubleScalarCos(c28_uf_x);
  c28_vc_b = c28_uf_x;
  c28_vc_y = 0.1738749906 * c28_vc_b;
  c28_vf_x = c28_q[1];
  c28_wf_x = c28_vf_x;
  c28_wf_x = muDoubleScalarSin(c28_wf_x);
  c28_xf_x = c28_q[2];
  c28_yf_x = c28_xf_x;
  c28_yf_x = muDoubleScalarCos(c28_yf_x);
  c28_rb_a = -c28_wf_x;
  c28_wc_b = c28_yf_x;
  c28_wc_y = c28_rb_a * c28_wc_b;
  c28_ag_x = c28_q[1];
  c28_bg_x = c28_ag_x;
  c28_bg_x = muDoubleScalarCos(c28_bg_x);
  c28_cg_x = c28_q[2];
  c28_dg_x = c28_cg_x;
  c28_dg_x = muDoubleScalarSin(c28_dg_x);
  c28_sb_a = c28_bg_x;
  c28_xc_b = c28_dg_x;
  c28_xc_y = c28_sb_a * c28_xc_b;
  c28_tb_a = c28_vc_y;
  c28_yc_b = c28_wc_y - c28_xc_y;
  c28_yc_y = c28_tb_a * c28_yc_b;
  c28_eg_x = c28_q[3];
  c28_fg_x = c28_eg_x;
  c28_fg_x = muDoubleScalarSin(c28_fg_x);
  c28_ad_b = c28_fg_x;
  c28_ad_y = 0.021525102 * c28_ad_b;
  c28_gg_x = c28_q[1];
  c28_hg_x = c28_gg_x;
  c28_hg_x = muDoubleScalarSin(c28_hg_x);
  c28_ig_x = c28_q[2];
  c28_jg_x = c28_ig_x;
  c28_jg_x = muDoubleScalarSin(c28_jg_x);
  c28_ub_a = -c28_hg_x;
  c28_bd_b = c28_jg_x;
  c28_bd_y = c28_ub_a * c28_bd_b;
  c28_kg_x = c28_q[1];
  c28_lg_x = c28_kg_x;
  c28_lg_x = muDoubleScalarCos(c28_lg_x);
  c28_mg_x = c28_q[2];
  c28_ng_x = c28_mg_x;
  c28_ng_x = muDoubleScalarCos(c28_ng_x);
  c28_vb_a = c28_lg_x;
  c28_cd_b = c28_ng_x;
  c28_cd_y = c28_vb_a * c28_cd_b;
  c28_wb_a = c28_ad_y;
  c28_dd_b = c28_bd_y + c28_cd_y;
  c28_dd_y = c28_wb_a * c28_dd_b;
  c28_og_x = c28_q[4];
  c28_pg_x = c28_og_x;
  c28_pg_x = muDoubleScalarSin(c28_pg_x);
  c28_ed_b = c28_pg_x;
  c28_ed_y = 0.1932637091 * c28_ed_b;
  c28_qg_x = c28_q[3];
  c28_rg_x = c28_qg_x;
  c28_rg_x = muDoubleScalarSin(c28_rg_x);
  c28_sg_x = c28_q[1];
  c28_tg_x = c28_sg_x;
  c28_tg_x = muDoubleScalarSin(c28_tg_x);
  c28_ug_x = c28_q[2];
  c28_vg_x = c28_ug_x;
  c28_vg_x = muDoubleScalarCos(c28_vg_x);
  c28_xb_a = -c28_tg_x;
  c28_fd_b = c28_vg_x;
  c28_fd_y = c28_xb_a * c28_fd_b;
  c28_wg_x = c28_q[1];
  c28_xg_x = c28_wg_x;
  c28_xg_x = muDoubleScalarCos(c28_xg_x);
  c28_yg_x = c28_q[2];
  c28_ah_x = c28_yg_x;
  c28_ah_x = muDoubleScalarSin(c28_ah_x);
  c28_yb_a = c28_xg_x;
  c28_gd_b = c28_ah_x;
  c28_gd_y = c28_yb_a * c28_gd_b;
  c28_ac_a = c28_rg_x;
  c28_hd_b = c28_fd_y - c28_gd_y;
  c28_hd_y = c28_ac_a * c28_hd_b;
  c28_bh_x = c28_q[3];
  c28_ch_x = c28_bh_x;
  c28_ch_x = muDoubleScalarCos(c28_ch_x);
  c28_dh_x = c28_q[1];
  c28_eh_x = c28_dh_x;
  c28_eh_x = muDoubleScalarSin(c28_eh_x);
  c28_fh_x = c28_q[2];
  c28_gh_x = c28_fh_x;
  c28_gh_x = muDoubleScalarSin(c28_gh_x);
  c28_bc_a = -c28_eh_x;
  c28_id_b = c28_gh_x;
  c28_id_y = c28_bc_a * c28_id_b;
  c28_hh_x = c28_q[1];
  c28_ih_x = c28_hh_x;
  c28_ih_x = muDoubleScalarCos(c28_ih_x);
  c28_jh_x = c28_q[2];
  c28_kh_x = c28_jh_x;
  c28_kh_x = muDoubleScalarCos(c28_kh_x);
  c28_cc_a = c28_ih_x;
  c28_jd_b = c28_kh_x;
  c28_jd_y = c28_cc_a * c28_jd_b;
  c28_dc_a = c28_ch_x;
  c28_kd_b = c28_id_y + c28_jd_y;
  c28_kd_y = c28_dc_a * c28_kd_b;
  c28_ec_a = c28_ed_y;
  c28_ld_b = c28_hd_y + c28_kd_y;
  c28_ld_y = c28_ec_a * c28_ld_b;
  c28_lh_x = c28_q[3];
  c28_mh_x = c28_lh_x;
  c28_mh_x = muDoubleScalarCos(c28_mh_x);
  c28_md_b = c28_mh_x;
  c28_md_y = 0.09465 * c28_md_b;
  c28_nh_x = c28_q[2];
  c28_oh_x = c28_nh_x;
  c28_oh_x = muDoubleScalarSin(c28_oh_x);
  c28_fc_a = -(c28_md_y + 0.39225);
  c28_nd_b = c28_oh_x;
  c28_nd_y = c28_fc_a * c28_nd_b;
  c28_ph_x = c28_q[3];
  c28_qh_x = c28_ph_x;
  c28_qh_x = muDoubleScalarSin(c28_qh_x);
  c28_od_b = c28_qh_x;
  c28_od_y = 0.09465 * c28_od_b;
  c28_rh_x = c28_q[2];
  c28_sh_x = c28_rh_x;
  c28_sh_x = muDoubleScalarCos(c28_sh_x);
  c28_gc_a = c28_od_y;
  c28_pd_b = c28_sh_x;
  c28_pd_y = c28_gc_a * c28_pd_b;
  c28_qd_b = c28_nd_y - c28_pd_y;
  c28_qd_y = 11.95839 * c28_qd_b;
  c28_th_x = c28_q[1];
  c28_uh_x = c28_th_x;
  c28_uh_x = muDoubleScalarCos(c28_uh_x);
  c28_hc_a = c28_qd_y;
  c28_rd_b = c28_uh_x;
  c28_rd_y = c28_hc_a * c28_rd_b;
  c28_vh_x = c28_q[3];
  c28_wh_x = c28_vh_x;
  c28_wh_x = muDoubleScalarSin(c28_wh_x);
  c28_sd_b = c28_wh_x;
  c28_sd_y = 1.131861614 * c28_sd_b;
  c28_xh_x = c28_q[1];
  c28_yh_x = c28_xh_x;
  c28_yh_x = muDoubleScalarSin(c28_yh_x);
  c28_ic_a = c28_sd_y;
  c28_td_b = c28_yh_x;
  c28_td_y = c28_ic_a * c28_td_b;
  c28_ai_x = c28_q[2];
  c28_bi_x = c28_ai_x;
  c28_bi_x = muDoubleScalarSin(c28_bi_x);
  c28_jc_a = c28_td_y;
  c28_ud_b = c28_bi_x;
  c28_ud_y = c28_jc_a * c28_ud_b;
  c28_ci_x = c28_q[3];
  c28_di_x = c28_ci_x;
  c28_di_x = muDoubleScalarCos(c28_di_x);
  c28_vd_b = c28_di_x;
  c28_vd_y = -0.09465 * c28_vd_b;
  c28_wd_b = c28_vd_y - 0.39225;
  c28_wd_y = 11.95839 * c28_wd_b;
  c28_ei_x = c28_q[2];
  c28_fi_x = c28_ei_x;
  c28_fi_x = muDoubleScalarCos(c28_fi_x);
  c28_kc_a = c28_wd_y;
  c28_xd_b = c28_fi_x;
  c28_xd_y = c28_kc_a * c28_xd_b;
  c28_gi_x = c28_q[1];
  c28_hi_x = c28_gi_x;
  c28_hi_x = muDoubleScalarSin(c28_hi_x);
  c28_lc_a = c28_xd_y;
  c28_yd_b = c28_hi_x;
  c28_yd_y = c28_lc_a * c28_yd_b;
  c28_ii_x = c28_q[4];
  c28_ji_x = c28_ii_x;
  c28_ji_x = muDoubleScalarSin(c28_ji_x);
  c28_ae_b = c28_ji_x;
  c28_ae_y = 0.0823 * c28_ae_b;
  c28_ki_x = c28_q[3];
  c28_li_x = c28_ki_x;
  c28_li_x = muDoubleScalarSin(c28_li_x);
  c28_mc_a = c28_ae_y;
  c28_be_b = c28_li_x;
  c28_be_y = c28_mc_a * c28_be_b;
  c28_mi_x = c28_q[3];
  c28_ni_x = c28_mi_x;
  c28_ni_x = muDoubleScalarCos(c28_ni_x);
  c28_ce_b = c28_ni_x;
  c28_ce_y = 0.09465 * c28_ce_b;
  c28_oi_x = c28_q[2];
  c28_pi_x = c28_oi_x;
  c28_pi_x = muDoubleScalarSin(c28_pi_x);
  c28_nc_a = -((c28_be_y + c28_ce_y) + 0.39225);
  c28_de_b = c28_pi_x;
  c28_de_y = c28_nc_a * c28_de_b;
  c28_qi_x = c28_q[4];
  c28_ri_x = c28_qi_x;
  c28_ri_x = muDoubleScalarSin(c28_ri_x);
  c28_ee_b = c28_ri_x;
  c28_ee_y = 0.0823 * c28_ee_b;
  c28_si_x = c28_q[3];
  c28_ti_x = c28_si_x;
  c28_ti_x = muDoubleScalarCos(c28_ti_x);
  c28_oc_a = c28_ee_y;
  c28_fe_b = c28_ti_x;
  c28_fe_y = c28_oc_a * c28_fe_b;
  c28_ui_x = c28_q[3];
  c28_vi_x = c28_ui_x;
  c28_vi_x = muDoubleScalarSin(c28_vi_x);
  c28_ge_b = c28_vi_x;
  c28_ge_y = 0.09465 * c28_ge_b;
  c28_wi_x = c28_q[2];
  c28_xi_x = c28_wi_x;
  c28_xi_x = muDoubleScalarCos(c28_xi_x);
  c28_pc_a = c28_fe_y - c28_ge_y;
  c28_he_b = c28_xi_x;
  c28_he_y = c28_pc_a * c28_he_b;
  c28_ie_b = c28_de_y + c28_he_y;
  c28_ie_y = 1.843299 * c28_ie_b;
  c28_yi_x = c28_q[1];
  c28_aj_x = c28_yi_x;
  c28_aj_x = muDoubleScalarCos(c28_aj_x);
  c28_qc_a = c28_ie_y;
  c28_je_b = c28_aj_x;
  c28_je_y = c28_qc_a * c28_je_b;
  c28_bj_x = c28_q[4];
  c28_cj_x = c28_bj_x;
  c28_cj_x = muDoubleScalarSin(c28_cj_x);
  c28_ke_b = c28_cj_x;
  c28_ke_y = 0.0823 * c28_ke_b;
  c28_dj_x = c28_q[3];
  c28_ej_x = c28_dj_x;
  c28_ej_x = muDoubleScalarCos(c28_ej_x);
  c28_rc_a = c28_ke_y;
  c28_le_b = c28_ej_x;
  c28_le_y = c28_rc_a * c28_le_b;
  c28_fj_x = c28_q[3];
  c28_gj_x = c28_fj_x;
  c28_gj_x = muDoubleScalarSin(c28_gj_x);
  c28_me_b = c28_gj_x;
  c28_me_y = 0.09465 * c28_me_b;
  c28_ne_b = c28_le_y - c28_me_y;
  c28_ne_y = 1.843299 * c28_ne_b;
  c28_hj_x = c28_q[1];
  c28_ij_x = c28_hj_x;
  c28_ij_x = muDoubleScalarSin(c28_ij_x);
  c28_sc_a = c28_ne_y;
  c28_oe_b = c28_ij_x;
  c28_oe_y = c28_sc_a * c28_oe_b;
  c28_jj_x = c28_q[2];
  c28_kj_x = c28_jj_x;
  c28_kj_x = muDoubleScalarSin(c28_kj_x);
  c28_tc_a = c28_oe_y;
  c28_pe_b = c28_kj_x;
  c28_pe_y = c28_tc_a * c28_pe_b;
  c28_lj_x = c28_q[4];
  c28_mj_x = c28_lj_x;
  c28_mj_x = muDoubleScalarSin(c28_mj_x);
  c28_qe_b = c28_mj_x;
  c28_qe_y = 0.0823 * c28_qe_b;
  c28_nj_x = c28_q[3];
  c28_oj_x = c28_nj_x;
  c28_oj_x = muDoubleScalarSin(c28_oj_x);
  c28_uc_a = c28_qe_y;
  c28_re_b = c28_oj_x;
  c28_re_y = c28_uc_a * c28_re_b;
  c28_pj_x = c28_q[3];
  c28_qj_x = c28_pj_x;
  c28_qj_x = muDoubleScalarCos(c28_qj_x);
  c28_se_b = c28_qj_x;
  c28_se_y = 0.09465 * c28_se_b;
  c28_te_b = (-0.39225 - c28_re_y) - c28_se_y;
  c28_te_y = 1.843299 * c28_te_b;
  c28_rj_x = c28_q[2];
  c28_sj_x = c28_rj_x;
  c28_sj_x = muDoubleScalarCos(c28_sj_x);
  c28_vc_a = c28_te_y;
  c28_ue_b = c28_sj_x;
  c28_ue_y = c28_vc_a * c28_ue_b;
  c28_tj_x = c28_q[1];
  c28_uj_x = c28_tj_x;
  c28_uj_x = muDoubleScalarSin(c28_uj_x);
  c28_wc_a = c28_ue_y;
  c28_ve_b = c28_uj_x;
  c28_ve_y = c28_wc_a * c28_ve_b;
  c28_vj_x = c28_q[3];
  c28_wj_x = c28_vj_x;
  c28_wj_x = muDoubleScalarCos(c28_wj_x);
  c28_we_b = c28_wj_x;
  c28_we_y = 0.1954000926 * c28_we_b;
  c28_xj_x = c28_q[1];
  c28_yj_x = c28_xj_x;
  c28_yj_x = muDoubleScalarSin(c28_yj_x);
  c28_ak_x = c28_q[2];
  c28_bk_x = c28_ak_x;
  c28_bk_x = muDoubleScalarCos(c28_bk_x);
  c28_xc_a = -c28_yj_x;
  c28_xe_b = c28_bk_x;
  c28_xe_y = c28_xc_a * c28_xe_b;
  c28_ck_x = c28_q[1];
  c28_dk_x = c28_ck_x;
  c28_dk_x = muDoubleScalarCos(c28_dk_x);
  c28_ek_x = c28_q[2];
  c28_fk_x = c28_ek_x;
  c28_fk_x = muDoubleScalarSin(c28_fk_x);
  c28_yc_a = c28_dk_x;
  c28_ye_b = c28_fk_x;
  c28_ye_y = c28_yc_a * c28_ye_b;
  c28_ad_a = c28_we_y;
  c28_af_b = c28_xe_y - c28_ye_y;
  c28_af_y = c28_ad_a * c28_af_b;
  c28_gk_x = c28_q[3];
  c28_hk_x = c28_gk_x;
  c28_hk_x = muDoubleScalarSin(c28_hk_x);
  c28_bf_b = c28_hk_x;
  c28_bf_y = 0.1738749906 * c28_bf_b;
  c28_ik_x = c28_q[1];
  c28_jk_x = c28_ik_x;
  c28_jk_x = muDoubleScalarSin(c28_jk_x);
  c28_kk_x = c28_q[2];
  c28_lk_x = c28_kk_x;
  c28_lk_x = muDoubleScalarSin(c28_lk_x);
  c28_bd_a = -c28_jk_x;
  c28_cf_b = c28_lk_x;
  c28_cf_y = c28_bd_a * c28_cf_b;
  c28_mk_x = c28_q[1];
  c28_nk_x = c28_mk_x;
  c28_nk_x = muDoubleScalarCos(c28_nk_x);
  c28_ok_x = c28_q[2];
  c28_pk_x = c28_ok_x;
  c28_pk_x = muDoubleScalarCos(c28_pk_x);
  c28_cd_a = c28_nk_x;
  c28_df_b = c28_pk_x;
  c28_df_y = c28_cd_a * c28_df_b;
  c28_dd_a = c28_bf_y;
  c28_ef_b = c28_cf_y + c28_df_y;
  c28_ef_y = c28_dd_a * c28_ef_b;
  c28_qk_x = c28_q[1];
  c28_rk_x = c28_qk_x;
  c28_rk_x = muDoubleScalarCos(c28_rk_x);
  c28_sk_x = c28_q[2];
  c28_tk_x = c28_sk_x;
  c28_tk_x = muDoubleScalarSin(c28_tk_x);
  c28_ed_a = c28_rk_x;
  c28_ff_b = c28_tk_x;
  c28_ff_y = c28_ed_a * c28_ff_b;
  c28_uk_x = c28_q[1];
  c28_vk_x = c28_uk_x;
  c28_vk_x = muDoubleScalarSin(c28_vk_x);
  c28_wk_x = c28_q[2];
  c28_xk_x = c28_wk_x;
  c28_xk_x = muDoubleScalarCos(c28_xk_x);
  c28_fd_a = c28_vk_x;
  c28_gf_b = c28_xk_x;
  c28_gf_y = c28_fd_a * c28_gf_b;
  c28_hf_b = c28_ff_y + c28_gf_y;
  c28_hf_y = 0.021525102 * c28_hf_b;
  c28_yk_x = c28_q[3];
  c28_al_x = c28_yk_x;
  c28_al_x = muDoubleScalarCos(c28_al_x);
  c28_gd_a = c28_hf_y;
  c28_if_b = c28_al_x;
  c28_if_y = c28_gd_a * c28_if_b;
  c28_bl_x = c28_q[4];
  c28_cl_x = c28_bl_x;
  c28_cl_x = muDoubleScalarSin(c28_cl_x);
  c28_jf_b = c28_cl_x;
  c28_jf_y = 0.1932637091 * c28_jf_b;
  c28_dl_x = c28_q[1];
  c28_el_x = c28_dl_x;
  c28_el_x = muDoubleScalarCos(c28_el_x);
  c28_fl_x = c28_q[2];
  c28_gl_x = c28_fl_x;
  c28_gl_x = muDoubleScalarSin(c28_gl_x);
  c28_hd_a = c28_el_x;
  c28_kf_b = c28_gl_x;
  c28_kf_y = c28_hd_a * c28_kf_b;
  c28_hl_x = c28_q[1];
  c28_il_x = c28_hl_x;
  c28_il_x = muDoubleScalarSin(c28_il_x);
  c28_jl_x = c28_q[2];
  c28_kl_x = c28_jl_x;
  c28_kl_x = muDoubleScalarCos(c28_kl_x);
  c28_id_a = c28_il_x;
  c28_lf_b = c28_kl_x;
  c28_lf_y = c28_id_a * c28_lf_b;
  c28_ll_x = c28_q[3];
  c28_ml_x = c28_ll_x;
  c28_ml_x = muDoubleScalarSin(c28_ml_x);
  c28_jd_a = -(c28_kf_y + c28_lf_y);
  c28_mf_b = c28_ml_x;
  c28_mf_y = c28_jd_a * c28_mf_b;
  c28_nl_x = c28_q[3];
  c28_ol_x = c28_nl_x;
  c28_ol_x = muDoubleScalarCos(c28_ol_x);
  c28_pl_x = c28_q[1];
  c28_ql_x = c28_pl_x;
  c28_ql_x = muDoubleScalarSin(c28_ql_x);
  c28_rl_x = c28_q[2];
  c28_sl_x = c28_rl_x;
  c28_sl_x = muDoubleScalarSin(c28_sl_x);
  c28_kd_a = -c28_ql_x;
  c28_nf_b = c28_sl_x;
  c28_nf_y = c28_kd_a * c28_nf_b;
  c28_tl_x = c28_q[1];
  c28_ul_x = c28_tl_x;
  c28_ul_x = muDoubleScalarCos(c28_ul_x);
  c28_vl_x = c28_q[2];
  c28_wl_x = c28_vl_x;
  c28_wl_x = muDoubleScalarCos(c28_wl_x);
  c28_ld_a = c28_ul_x;
  c28_of_b = c28_wl_x;
  c28_of_y = c28_ld_a * c28_of_b;
  c28_md_a = c28_ol_x;
  c28_pf_b = c28_nf_y + c28_of_y;
  c28_pf_y = c28_md_a * c28_pf_b;
  c28_nd_a = c28_jf_y;
  c28_qf_b = c28_mf_y + c28_pf_y;
  c28_qf_y = c28_nd_a * c28_qf_b;
  c28_xl_x = c28_q[3];
  c28_yl_x = c28_xl_x;
  c28_yl_x = muDoubleScalarSin(c28_yl_x);
  c28_rf_b = c28_yl_x;
  c28_rf_y = -0.09465 * c28_rf_b;
  c28_am_x = c28_q[2];
  c28_bm_x = c28_am_x;
  c28_bm_x = muDoubleScalarCos(c28_bm_x);
  c28_od_a = c28_rf_y;
  c28_sf_b = c28_bm_x;
  c28_sf_y = c28_od_a * c28_sf_b;
  c28_cm_x = c28_q[3];
  c28_dm_x = c28_cm_x;
  c28_dm_x = muDoubleScalarCos(c28_dm_x);
  c28_tf_b = c28_dm_x;
  c28_tf_y = 0.09465 * c28_tf_b;
  c28_em_x = c28_q[2];
  c28_fm_x = c28_em_x;
  c28_fm_x = muDoubleScalarSin(c28_fm_x);
  c28_pd_a = c28_tf_y;
  c28_uf_b = c28_fm_x;
  c28_uf_y = c28_pd_a * c28_uf_b;
  c28_vf_b = c28_sf_y - c28_uf_y;
  c28_vf_y = 11.95839 * c28_vf_b;
  c28_gm_x = c28_q[1];
  c28_hm_x = c28_gm_x;
  c28_hm_x = muDoubleScalarCos(c28_hm_x);
  c28_qd_a = c28_vf_y;
  c28_wf_b = c28_hm_x;
  c28_wf_y = c28_qd_a * c28_wf_b;
  c28_im_x = c28_q[3];
  c28_jm_x = c28_im_x;
  c28_jm_x = muDoubleScalarCos(c28_jm_x);
  c28_xf_b = c28_jm_x;
  c28_xf_y = 1.131861614 * c28_xf_b;
  c28_km_x = c28_q[1];
  c28_lm_x = c28_km_x;
  c28_lm_x = muDoubleScalarSin(c28_lm_x);
  c28_rd_a = c28_xf_y;
  c28_yf_b = c28_lm_x;
  c28_yf_y = c28_rd_a * c28_yf_b;
  c28_mm_x = c28_q[2];
  c28_nm_x = c28_mm_x;
  c28_nm_x = muDoubleScalarCos(c28_nm_x);
  c28_sd_a = c28_yf_y;
  c28_ag_b = c28_nm_x;
  c28_ag_y = c28_sd_a * c28_ag_b;
  c28_om_x = c28_q[3];
  c28_pm_x = c28_om_x;
  c28_pm_x = muDoubleScalarSin(c28_pm_x);
  c28_bg_b = c28_pm_x;
  c28_bg_y = 1.131861614 * c28_bg_b;
  c28_qm_x = c28_q[1];
  c28_rm_x = c28_qm_x;
  c28_rm_x = muDoubleScalarSin(c28_rm_x);
  c28_td_a = c28_bg_y;
  c28_cg_b = c28_rm_x;
  c28_cg_y = c28_td_a * c28_cg_b;
  c28_sm_x = c28_q[2];
  c28_tm_x = c28_sm_x;
  c28_tm_x = muDoubleScalarSin(c28_tm_x);
  c28_ud_a = c28_cg_y;
  c28_dg_b = c28_tm_x;
  c28_dg_y = c28_ud_a * c28_dg_b;
  c28_um_x = c28_q[4];
  c28_vm_x = c28_um_x;
  c28_vm_x = muDoubleScalarSin(c28_vm_x);
  c28_eg_b = c28_vm_x;
  c28_eg_y = 0.0823 * c28_eg_b;
  c28_wm_x = c28_q[3];
  c28_xm_x = c28_wm_x;
  c28_xm_x = muDoubleScalarCos(c28_xm_x);
  c28_vd_a = c28_eg_y;
  c28_fg_b = c28_xm_x;
  c28_fg_y = c28_vd_a * c28_fg_b;
  c28_ym_x = c28_q[3];
  c28_an_x = c28_ym_x;
  c28_an_x = muDoubleScalarSin(c28_an_x);
  c28_gg_b = c28_an_x;
  c28_gg_y = 0.09465 * c28_gg_b;
  c28_bn_x = c28_q[2];
  c28_cn_x = c28_bn_x;
  c28_cn_x = muDoubleScalarCos(c28_cn_x);
  c28_wd_a = c28_fg_y - c28_gg_y;
  c28_hg_b = c28_cn_x;
  c28_hg_y = c28_wd_a * c28_hg_b;
  c28_dn_x = c28_q[4];
  c28_en_x = c28_dn_x;
  c28_en_x = muDoubleScalarSin(c28_en_x);
  c28_ig_b = c28_en_x;
  c28_ig_y = -0.0823 * c28_ig_b;
  c28_fn_x = c28_q[3];
  c28_gn_x = c28_fn_x;
  c28_gn_x = muDoubleScalarSin(c28_gn_x);
  c28_xd_a = c28_ig_y;
  c28_jg_b = c28_gn_x;
  c28_jg_y = c28_xd_a * c28_jg_b;
  c28_hn_x = c28_q[3];
  c28_in_x = c28_hn_x;
  c28_in_x = muDoubleScalarCos(c28_in_x);
  c28_kg_b = c28_in_x;
  c28_kg_y = 0.09465 * c28_kg_b;
  c28_jn_x = c28_q[2];
  c28_kn_x = c28_jn_x;
  c28_kn_x = muDoubleScalarSin(c28_kn_x);
  c28_yd_a = c28_jg_y - c28_kg_y;
  c28_lg_b = c28_kn_x;
  c28_lg_y = c28_yd_a * c28_lg_b;
  c28_mg_b = c28_hg_y + c28_lg_y;
  c28_mg_y = 1.843299 * c28_mg_b;
  c28_ln_x = c28_q[1];
  c28_mn_x = c28_ln_x;
  c28_mn_x = muDoubleScalarCos(c28_mn_x);
  c28_ae_a = c28_mg_y;
  c28_ng_b = c28_mn_x;
  c28_ng_y = c28_ae_a * c28_ng_b;
  c28_nn_x = c28_q[4];
  c28_on_x = c28_nn_x;
  c28_on_x = muDoubleScalarSin(c28_on_x);
  c28_og_b = c28_on_x;
  c28_og_y = -0.0823 * c28_og_b;
  c28_pn_x = c28_q[3];
  c28_qn_x = c28_pn_x;
  c28_qn_x = muDoubleScalarSin(c28_qn_x);
  c28_be_a = c28_og_y;
  c28_pg_b = c28_qn_x;
  c28_pg_y = c28_be_a * c28_pg_b;
  c28_rn_x = c28_q[3];
  c28_sn_x = c28_rn_x;
  c28_sn_x = muDoubleScalarCos(c28_sn_x);
  c28_qg_b = c28_sn_x;
  c28_qg_y = 0.09465 * c28_qg_b;
  c28_rg_b = c28_pg_y - c28_qg_y;
  c28_rg_y = 1.843299 * c28_rg_b;
  c28_tn_x = c28_q[1];
  c28_un_x = c28_tn_x;
  c28_un_x = muDoubleScalarSin(c28_un_x);
  c28_ce_a = c28_rg_y;
  c28_sg_b = c28_un_x;
  c28_sg_y = c28_ce_a * c28_sg_b;
  c28_vn_x = c28_q[2];
  c28_wn_x = c28_vn_x;
  c28_wn_x = muDoubleScalarCos(c28_wn_x);
  c28_de_a = c28_sg_y;
  c28_tg_b = c28_wn_x;
  c28_tg_y = c28_de_a * c28_tg_b;
  c28_xn_x = c28_q[4];
  c28_yn_x = c28_xn_x;
  c28_yn_x = muDoubleScalarSin(c28_yn_x);
  c28_ug_b = c28_yn_x;
  c28_ug_y = -0.0823 * c28_ug_b;
  c28_ao_x = c28_q[3];
  c28_bo_x = c28_ao_x;
  c28_bo_x = muDoubleScalarCos(c28_bo_x);
  c28_ee_a = c28_ug_y;
  c28_vg_b = c28_bo_x;
  c28_vg_y = c28_ee_a * c28_vg_b;
  c28_co_x = c28_q[3];
  c28_do_x = c28_co_x;
  c28_do_x = muDoubleScalarSin(c28_do_x);
  c28_wg_b = c28_do_x;
  c28_wg_y = 0.09465 * c28_wg_b;
  c28_xg_b = c28_vg_y + c28_wg_y;
  c28_xg_y = 1.843299 * c28_xg_b;
  c28_eo_x = c28_q[2];
  c28_fo_x = c28_eo_x;
  c28_fo_x = muDoubleScalarSin(c28_fo_x);
  c28_fe_a = c28_xg_y;
  c28_yg_b = c28_fo_x;
  c28_yg_y = c28_fe_a * c28_yg_b;
  c28_go_x = c28_q[1];
  c28_ho_x = c28_go_x;
  c28_ho_x = muDoubleScalarSin(c28_ho_x);
  c28_ge_a = c28_yg_y;
  c28_ah_b = c28_ho_x;
  c28_ah_y = c28_ge_a * c28_ah_b;
  c28_io_x = c28_q[1];
  c28_jo_x = c28_io_x;
  c28_jo_x = muDoubleScalarCos(c28_jo_x);
  c28_ko_x = c28_q[2];
  c28_lo_x = c28_ko_x;
  c28_lo_x = muDoubleScalarSin(c28_lo_x);
  c28_he_a = c28_jo_x;
  c28_bh_b = c28_lo_x;
  c28_bh_y = c28_he_a * c28_bh_b;
  c28_mo_x = c28_q[1];
  c28_no_x = c28_mo_x;
  c28_no_x = muDoubleScalarSin(c28_no_x);
  c28_oo_x = c28_q[2];
  c28_po_x = c28_oo_x;
  c28_po_x = muDoubleScalarCos(c28_po_x);
  c28_ie_a = c28_no_x;
  c28_ch_b = c28_po_x;
  c28_ch_y = c28_ie_a * c28_ch_b;
  c28_qo_x = c28_q[3];
  c28_ro_x = c28_qo_x;
  c28_ro_x = muDoubleScalarCos(c28_ro_x);
  c28_je_a = c28_bh_y + c28_ch_y;
  c28_dh_b = c28_ro_x;
  c28_dh_y = c28_je_a * c28_dh_b;
  c28_so_x = c28_q[3];
  c28_to_x = c28_so_x;
  c28_to_x = muDoubleScalarSin(c28_to_x);
  c28_uo_x = c28_q[1];
  c28_vo_x = c28_uo_x;
  c28_vo_x = muDoubleScalarSin(c28_vo_x);
  c28_wo_x = c28_q[2];
  c28_xo_x = c28_wo_x;
  c28_xo_x = muDoubleScalarSin(c28_xo_x);
  c28_ke_a = -c28_vo_x;
  c28_eh_b = c28_xo_x;
  c28_eh_y = c28_ke_a * c28_eh_b;
  c28_yo_x = c28_q[1];
  c28_ap_x = c28_yo_x;
  c28_ap_x = muDoubleScalarCos(c28_ap_x);
  c28_bp_x = c28_q[2];
  c28_cp_x = c28_bp_x;
  c28_cp_x = muDoubleScalarCos(c28_cp_x);
  c28_le_a = c28_ap_x;
  c28_fh_b = c28_cp_x;
  c28_fh_y = c28_le_a * c28_fh_b;
  c28_me_a = c28_to_x;
  c28_gh_b = c28_eh_y + c28_fh_y;
  c28_gh_y = c28_me_a * c28_gh_b;
  c28_hh_b = c28_dh_y + c28_gh_y;
  c28_hh_y = 0.1932637091 * c28_hh_b;
  c28_dp_x = c28_q[4];
  c28_ep_x = c28_dp_x;
  c28_ep_x = muDoubleScalarCos(c28_ep_x);
  c28_ne_a = c28_hh_y;
  c28_ih_b = c28_ep_x;
  c28_ih_y = c28_ne_a * c28_ih_b;
  c28_fp_x = c28_q[4];
  c28_gp_x = c28_fp_x;
  c28_gp_x = muDoubleScalarCos(c28_gp_x);
  c28_jh_b = c28_gp_x;
  c28_jh_y = 0.0823 * c28_jh_b;
  c28_hp_x = c28_q[3];
  c28_ip_x = c28_hp_x;
  c28_ip_x = muDoubleScalarSin(c28_ip_x);
  c28_oe_a = c28_jh_y;
  c28_kh_b = c28_ip_x;
  c28_kh_y = c28_oe_a * c28_kh_b;
  c28_jp_x = c28_q[2];
  c28_kp_x = c28_jp_x;
  c28_kp_x = muDoubleScalarCos(c28_kp_x);
  c28_pe_a = c28_kh_y;
  c28_lh_b = c28_kp_x;
  c28_lh_y = c28_pe_a * c28_lh_b;
  c28_lp_x = c28_q[4];
  c28_mp_x = c28_lp_x;
  c28_mp_x = muDoubleScalarCos(c28_mp_x);
  c28_mh_b = c28_mp_x;
  c28_mh_y = 0.0823 * c28_mh_b;
  c28_np_x = c28_q[3];
  c28_op_x = c28_np_x;
  c28_op_x = muDoubleScalarCos(c28_op_x);
  c28_qe_a = c28_mh_y;
  c28_nh_b = c28_op_x;
  c28_nh_y = c28_qe_a * c28_nh_b;
  c28_pp_x = c28_q[2];
  c28_qp_x = c28_pp_x;
  c28_qp_x = muDoubleScalarSin(c28_qp_x);
  c28_re_a = c28_nh_y;
  c28_oh_b = c28_qp_x;
  c28_oh_y = c28_re_a * c28_oh_b;
  c28_ph_b = c28_lh_y + c28_oh_y;
  c28_ph_y = 1.843299 * c28_ph_b;
  c28_rp_x = c28_q[1];
  c28_sp_x = c28_rp_x;
  c28_sp_x = muDoubleScalarCos(c28_sp_x);
  c28_se_a = c28_ph_y;
  c28_qh_b = c28_sp_x;
  c28_qh_y = c28_se_a * c28_qh_b;
  c28_tp_x = c28_q[4];
  c28_up_x = c28_tp_x;
  c28_up_x = muDoubleScalarCos(c28_up_x);
  c28_rh_b = c28_up_x;
  c28_rh_y = 0.1517035077 * c28_rh_b;
  c28_vp_x = c28_q[3];
  c28_wp_x = c28_vp_x;
  c28_wp_x = muDoubleScalarCos(c28_wp_x);
  c28_te_a = c28_rh_y;
  c28_sh_b = c28_wp_x;
  c28_sh_y = c28_te_a * c28_sh_b;
  c28_xp_x = c28_q[1];
  c28_yp_x = c28_xp_x;
  c28_yp_x = muDoubleScalarSin(c28_yp_x);
  c28_ue_a = c28_sh_y;
  c28_th_b = c28_yp_x;
  c28_th_y = c28_ue_a * c28_th_b;
  c28_aq_x = c28_q[2];
  c28_bq_x = c28_aq_x;
  c28_bq_x = muDoubleScalarCos(c28_bq_x);
  c28_ve_a = c28_th_y;
  c28_uh_b = c28_bq_x;
  c28_uh_y = c28_ve_a * c28_uh_b;
  c28_cq_x = c28_q[4];
  c28_dq_x = c28_cq_x;
  c28_dq_x = muDoubleScalarCos(c28_dq_x);
  c28_vh_b = c28_dq_x;
  c28_vh_y = 0.1517035077 * c28_vh_b;
  c28_eq_x = c28_q[3];
  c28_fq_x = c28_eq_x;
  c28_fq_x = muDoubleScalarSin(c28_fq_x);
  c28_we_a = c28_vh_y;
  c28_wh_b = c28_fq_x;
  c28_wh_y = c28_we_a * c28_wh_b;
  c28_gq_x = c28_q[2];
  c28_hq_x = c28_gq_x;
  c28_hq_x = muDoubleScalarSin(c28_hq_x);
  c28_xe_a = c28_wh_y;
  c28_xh_b = c28_hq_x;
  c28_xh_y = c28_xe_a * c28_xh_b;
  c28_iq_x = c28_q[1];
  c28_jq_x = c28_iq_x;
  c28_jq_x = muDoubleScalarSin(c28_jq_x);
  c28_ye_a = c28_xh_y;
  c28_yh_b = c28_jq_x;
  c28_yh_y = c28_ye_a * c28_yh_b;
  c28_G_Version1[0] = 0.0;
  c28_G_Version1[1] = ((((((((((((c28_y + c28_c_y) - c28_e_y) - c28_h_y) +
    c28_l_y) + c28_p_y) + c28_t_y) + c28_cb_y) - c28_ib_y) - c28_lb_y) +
    c28_pb_y) - c28_ac_y) + c28_gc_y) + c28_mc_y;
  c28_G_Version1[2] = ((((((((((c28_oc_y - c28_qc_y) + c28_uc_y) + c28_yc_y) +
    c28_dd_y) + c28_ld_y) + c28_rd_y) + c28_ud_y) + c28_yd_y) + c28_je_y) -
                       c28_pe_y) + c28_ve_y;
  c28_G_Version1[3] = ((((((((c28_af_y - c28_ef_y) + c28_if_y) + c28_qf_y) +
    c28_wf_y) - c28_ag_y) + c28_dg_y) + c28_ng_y) + c28_tg_y) + c28_ah_y;
  c28_G_Version1[4] = ((c28_ih_y + c28_qh_y) + c28_uh_y) - c28_yh_y;
  c28_G_Version1[5] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c28_i5 = 0; c28_i5 < 6; c28_i5++) {
    (*c28_b_G_Version1)[c28_i5] = c28_G_Version1[c28_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c28_sfEvent);
}

static void initSimStructsc28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void registerMessagesc28_JointSpaceControl_CorrectFalseCombo
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber)
{
}

static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i6;
  real_T c28_b_inData[6];
  int32_T c28_i7;
  real_T c28_u[6];
  const mxArray *c28_y = NULL;
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  for (c28_i6 = 0; c28_i6 < 6; c28_i6++) {
    c28_b_inData[c28_i6] = (*(real_T (*)[6])c28_inData)[c28_i6];
  }

  for (c28_i7 = 0; c28_i7 < 6; c28_i7++) {
    c28_u[c28_i7] = c28_b_inData[c28_i7];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, FALSE);
  return c28_mxArrayOutData;
}

static void c28_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_G_Version1, const char_T *c28_identifier, real_T c28_y[6])
{
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_G_Version1), &c28_thisId,
    c28_y);
  sf_mex_destroy(&c28_G_Version1);
}

static void c28_b_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId, real_T c28_y[6])
{
  real_T c28_dv1[6];
  int32_T c28_i8;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), c28_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c28_i8 = 0; c28_i8 < 6; c28_i8++) {
    c28_y[c28_i8] = c28_dv1[c28_i8];
  }

  sf_mex_destroy(&c28_u);
}

static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_G_Version1;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y[6];
  int32_T c28_i9;
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c28_G_Version1 = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_G_Version1), &c28_thisId,
    c28_y);
  sf_mex_destroy(&c28_G_Version1);
  for (c28_i9 = 0; c28_i9 < 6; c28_i9++) {
    (*(real_T (*)[6])c28_outData)[c28_i9] = c28_y[c28_i9];
  }

  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  real_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(real_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, FALSE);
  return c28_mxArrayOutData;
}

static real_T c28_c_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  real_T c28_y;
  real_T c28_d0;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_d0, 1, 0, 0U, 0, 0U, 0);
  c28_y = c28_d0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_nargout;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y;
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c28_nargout = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_nargout),
    &c28_thisId);
  sf_mex_destroy(&c28_nargout);
  *(real_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

const mxArray
  *sf_c28_JointSpaceControl_CorrectFalseCombo_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c28_nameCaptureInfo;
  c28_ResolvedFunctionInfo c28_info[5];
  c28_ResolvedFunctionInfo (*c28_b_info)[5];
  const mxArray *c28_m0 = NULL;
  int32_T c28_i10;
  c28_ResolvedFunctionInfo *c28_r0;
  c28_nameCaptureInfo = NULL;
  c28_nameCaptureInfo = NULL;
  c28_b_info = (c28_ResolvedFunctionInfo (*)[5])c28_info;
  (*c28_b_info)[0].context = "";
  (*c28_b_info)[0].name = "sin";
  (*c28_b_info)[0].dominantType = "double";
  (*c28_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c28_b_info)[0].fileTimeLo = 1343851986U;
  (*c28_b_info)[0].fileTimeHi = 0U;
  (*c28_b_info)[0].mFileTimeLo = 0U;
  (*c28_b_info)[0].mFileTimeHi = 0U;
  (*c28_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c28_b_info)[1].name = "eml_scalar_sin";
  (*c28_b_info)[1].dominantType = "double";
  (*c28_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c28_b_info)[1].fileTimeLo = 1286840336U;
  (*c28_b_info)[1].fileTimeHi = 0U;
  (*c28_b_info)[1].mFileTimeLo = 0U;
  (*c28_b_info)[1].mFileTimeHi = 0U;
  (*c28_b_info)[2].context = "";
  (*c28_b_info)[2].name = "mtimes";
  (*c28_b_info)[2].dominantType = "double";
  (*c28_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c28_b_info)[2].fileTimeLo = 1289541292U;
  (*c28_b_info)[2].fileTimeHi = 0U;
  (*c28_b_info)[2].mFileTimeLo = 0U;
  (*c28_b_info)[2].mFileTimeHi = 0U;
  (*c28_b_info)[3].context = "";
  (*c28_b_info)[3].name = "cos";
  (*c28_b_info)[3].dominantType = "double";
  (*c28_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c28_b_info)[3].fileTimeLo = 1343851972U;
  (*c28_b_info)[3].fileTimeHi = 0U;
  (*c28_b_info)[3].mFileTimeLo = 0U;
  (*c28_b_info)[3].mFileTimeHi = 0U;
  (*c28_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c28_b_info)[4].name = "eml_scalar_cos";
  (*c28_b_info)[4].dominantType = "double";
  (*c28_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c28_b_info)[4].fileTimeLo = 1286840322U;
  (*c28_b_info)[4].fileTimeHi = 0U;
  (*c28_b_info)[4].mFileTimeLo = 0U;
  (*c28_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c28_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c28_i10 = 0; c28_i10 < 5; c28_i10++) {
    c28_r0 = &c28_info[c28_i10];
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c28_r0->context)), "context", "nameCaptureInfo",
                    c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c28_r0->name)), "name", "nameCaptureInfo",
                    c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      c28_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c28_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c28_r0->resolved)), "resolved",
                    "nameCaptureInfo", c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      &c28_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c28_i10);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      &c28_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c28_i10);
  }

  sf_mex_assign(&c28_nameCaptureInfo, c28_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c28_nameCaptureInfo);
  return c28_nameCaptureInfo;
}

static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(int32_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, FALSE);
  return c28_mxArrayOutData;
}

static int32_T c28_d_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  int32_T c28_y;
  int32_T c28_i11;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_i11, 1, 6, 0U, 0, 0U, 0);
  c28_y = c28_i11;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_sfEvent;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  int32_T c28_y;
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    chartInstanceVoid;
  c28_b_sfEvent = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_sfEvent),
    &c28_thisId);
  sf_mex_destroy(&c28_b_sfEvent);
  *(int32_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static uint8_T c28_e_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_b_is_active_c28_JointSpaceControl_CorrectFalseCombo, const
   char_T *c28_identifier)
{
  uint8_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c28_b_is_active_c28_JointSpaceControl_CorrectFalseCombo), &c28_thisId);
  sf_mex_destroy(&c28_b_is_active_c28_JointSpaceControl_CorrectFalseCombo);
  return c28_y;
}

static uint8_T c28_f_emlrt_marshallIn
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance, const
   mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  uint8_T c28_y;
  uint8_T c28_u0;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_u0, 1, 3, 0U, 0, 0U, 0);
  c28_y = c28_u0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void init_dsm_address_info
  (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance)
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

void sf_c28_JointSpaceControl_CorrectFalseCombo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1086608617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3319495565U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3638291949U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2256848197U);
}

mxArray *sf_c28_JointSpaceControl_CorrectFalseCombo_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PSQRYTN2t68uVgNIyv7CFD");
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

mxArray *sf_c28_JointSpaceControl_CorrectFalseCombo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c28_JointSpaceControl_CorrectFalseCombo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"G_Version1\",},{M[8],M[0],T\"is_active_c28_JointSpaceControl_CorrectFalseCombo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_JointSpaceControl_CorrectFalseCombo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
    chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectFalseComboMachineNumber_,
           28,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"G_Version1");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4325);
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
            1.0,0,0,(MexFcnForType)c28_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_sf_marshallOut,(MexInFcnForType)
            c28_sf_marshallIn);
        }

        {
          real_T (*c28_q)[6];
          real_T (*c28_G_Version1)[6];
          c28_G_Version1 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
            1);
          c28_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c28_q);
          _SFD_SET_DATA_VALUE_PTR(1U, *c28_G_Version1);
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
  return "0anGOUp7atEuWIRYZkXU3C";
}

static void sf_opaque_initialize_c28_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
  initialize_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c28_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  enable_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c28_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  disable_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c28_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  sf_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c28_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c28_JointSpaceControl_CorrectFalseCombo();/* state var info */
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

extern void sf_internal_set_sim_state_c28_JointSpaceControl_CorrectFalseCombo
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
    sf_get_sim_state_info_c28_JointSpaceControl_CorrectFalseCombo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c28_JointSpaceControl_CorrectFalseCombo(SimStruct* S)
{
  return sf_internal_get_sim_state_c28_JointSpaceControl_CorrectFalseCombo(S);
}

static void sf_opaque_set_sim_state_c28_JointSpaceControl_CorrectFalseCombo
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c28_JointSpaceControl_CorrectFalseCombo(S, st);
}

static void sf_opaque_terminate_c28_JointSpaceControl_CorrectFalseCombo(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectFalseCombo_optimization_info();
    }

    finalize_c28_JointSpaceControl_CorrectFalseCombo
      ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc28_JointSpaceControl_CorrectFalseCombo
    ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_JointSpaceControl_CorrectFalseCombo
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c28_JointSpaceControl_CorrectFalseCombo
      ((SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c28_JointSpaceControl_CorrectFalseCombo(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectFalseCombo_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      28);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,28,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,28,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,28);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,28,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,28,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,28);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(963215349U));
  ssSetChecksum1(S,(3055082698U));
  ssSetChecksum2(S,(1952856677U));
  ssSetChecksum3(S,(746012009U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c28_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c28_JointSpaceControl_CorrectFalseCombo(SimStruct *S)
{
  SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *chartInstance;
  chartInstance = (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct *)
    utMalloc(sizeof(SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc28_JointSpaceControl_CorrectFalseComboInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c28_JointSpaceControl_CorrectFalseCombo;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c28_JointSpaceControl_CorrectFalseCombo;
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

void c28_JointSpaceControl_CorrectFalseCombo_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_JointSpaceControl_CorrectFalseCombo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_JointSpaceControl_CorrectFalseCombo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_JointSpaceControl_CorrectFalseCombo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
