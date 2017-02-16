/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_BestInertia_sfun.h"
#include "c4_JointSpaceControl_BestInertia.h"
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
static const char * c4_debug_family_names[18] = { "theta1", "theta2", "theta3",
  "theta4", "theta5", "theta6", "theta_1", "theta_2", "theta_3", "theta_4",
  "theta_5", "theta_6", "T", "nargin", "nargout", "q", "d", "R" };

/* Function Declarations */
static void initialize_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initialize_params_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void enable_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void disable_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void set_sim_state_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void sf_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c4_chartstep_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initSimStructsc4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void registerMessagesc4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, const mxArray *c4_R, const char_T *c4_identifier, real_T c4_y
  [9]);
static void c4_b_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_d, const char_T *c4_identifier, real_T c4_y[3]);
static void c4_d_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[16]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_g_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_h_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_JointSpaceControl_BestInertia, const char_T
   *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_JointSpaceControl_BestInertia = 0U;
}

static void initialize_params_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void enable_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[9];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[3];
  const mxArray *c4_c_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T (*c4_d)[3];
  real_T (*c4_R)[9];
  c4_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(3), FALSE);
  for (c4_i0 = 0; c4_i0 < 9; c4_i0++) {
    c4_u[c4_i0] = (*c4_R)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    c4_b_u[c4_i1] = (*c4_d)[c4_i1];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_hoistedGlobal =
    chartInstance->c4_is_active_c4_JointSpaceControl_BestInertia;
  c4_c_u = c4_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[9];
  int32_T c4_i2;
  real_T c4_dv1[3];
  int32_T c4_i3;
  real_T (*c4_R)[9];
  real_T (*c4_d)[3];
  c4_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "R",
                      c4_dv0);
  for (c4_i2 = 0; c4_i2 < 9; c4_i2++) {
    (*c4_R)[c4_i2] = c4_dv0[c4_i2];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "d",
                        c4_dv1);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    (*c4_d)[c4_i3] = c4_dv1[c4_i3];
  }

  chartInstance->c4_is_active_c4_JointSpaceControl_BestInertia =
    c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
    "is_active_c4_JointSpaceControl_BestInertia");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_JointSpaceControl_BestInertia(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void sf_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  real_T (*c4_R)[9];
  real_T (*c4_q)[6];
  real_T (*c4_d)[3];
  c4_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c4_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_d)[c4_i4], 0U);
  }

  for (c4_i5 = 0; c4_i5 < 6; c4_i5++) {
    _SFD_DATA_RANGE_CHECK((*c4_q)[c4_i5], 1U);
  }

  for (c4_i6 = 0; c4_i6 < 9; c4_i6++) {
    _SFD_DATA_RANGE_CHECK((*c4_R)[c4_i6], 2U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_JointSpaceControl_BestInertia(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_BestInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c4_chartstep_c4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c4_i7;
  real_T c4_q[6];
  uint32_T c4_debug_family_var_map[18];
  real_T c4_theta1;
  real_T c4_theta2;
  real_T c4_theta3;
  real_T c4_theta4;
  real_T c4_theta5;
  real_T c4_theta6;
  real_T c4_theta_1;
  real_T c4_theta_2;
  real_T c4_theta_3;
  real_T c4_theta_4;
  real_T c4_theta_5;
  real_T c4_theta_6;
  real_T c4_T[16];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_d[3];
  real_T c4_R[9];
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_a;
  real_T c4_b;
  real_T c4_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_b_y;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_c_y;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_d_y;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_e_y;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_f_y;
  real_T c4_w_x;
  real_T c4_x_x;
  real_T c4_y_x;
  real_T c4_ab_x;
  real_T c4_bb_x;
  real_T c4_cb_x;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_g_y;
  real_T c4_db_x;
  real_T c4_eb_x;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_h_y;
  real_T c4_fb_x;
  real_T c4_gb_x;
  real_T c4_hb_x;
  real_T c4_ib_x;
  real_T c4_i_a;
  real_T c4_i_b;
  real_T c4_i_y;
  real_T c4_jb_x;
  real_T c4_kb_x;
  real_T c4_j_a;
  real_T c4_j_b;
  real_T c4_j_y;
  real_T c4_k_a;
  real_T c4_k_b;
  real_T c4_k_y;
  real_T c4_l_a;
  real_T c4_l_b;
  real_T c4_l_y;
  real_T c4_m_a;
  real_T c4_m_b;
  real_T c4_m_y;
  real_T c4_lb_x;
  real_T c4_mb_x;
  real_T c4_nb_x;
  real_T c4_ob_x;
  real_T c4_pb_x;
  real_T c4_qb_x;
  real_T c4_rb_x;
  real_T c4_sb_x;
  real_T c4_n_a;
  real_T c4_n_b;
  real_T c4_n_y;
  real_T c4_tb_x;
  real_T c4_ub_x;
  real_T c4_o_a;
  real_T c4_o_b;
  real_T c4_o_y;
  real_T c4_vb_x;
  real_T c4_wb_x;
  real_T c4_xb_x;
  real_T c4_yb_x;
  real_T c4_p_a;
  real_T c4_p_b;
  real_T c4_p_y;
  real_T c4_ac_x;
  real_T c4_bc_x;
  real_T c4_q_a;
  real_T c4_q_b;
  real_T c4_q_y;
  real_T c4_r_a;
  real_T c4_r_b;
  real_T c4_r_y;
  real_T c4_cc_x;
  real_T c4_dc_x;
  real_T c4_ec_x;
  real_T c4_fc_x;
  real_T c4_gc_x;
  real_T c4_hc_x;
  real_T c4_s_a;
  real_T c4_s_b;
  real_T c4_s_y;
  real_T c4_ic_x;
  real_T c4_jc_x;
  real_T c4_t_a;
  real_T c4_t_b;
  real_T c4_t_y;
  real_T c4_kc_x;
  real_T c4_lc_x;
  real_T c4_mc_x;
  real_T c4_nc_x;
  real_T c4_u_a;
  real_T c4_u_b;
  real_T c4_u_y;
  real_T c4_oc_x;
  real_T c4_pc_x;
  real_T c4_v_a;
  real_T c4_v_b;
  real_T c4_v_y;
  real_T c4_w_a;
  real_T c4_w_b;
  real_T c4_w_y;
  real_T c4_x_a;
  real_T c4_x_b;
  real_T c4_x_y;
  real_T c4_qc_x;
  real_T c4_rc_x;
  real_T c4_sc_x;
  real_T c4_tc_x;
  real_T c4_uc_x;
  real_T c4_vc_x;
  real_T c4_y_a;
  real_T c4_y_b;
  real_T c4_y_y;
  real_T c4_wc_x;
  real_T c4_xc_x;
  real_T c4_yc_x;
  real_T c4_ad_x;
  real_T c4_bd_x;
  real_T c4_cd_x;
  real_T c4_dd_x;
  real_T c4_ed_x;
  real_T c4_ab_a;
  real_T c4_ab_b;
  real_T c4_ab_y;
  real_T c4_fd_x;
  real_T c4_gd_x;
  real_T c4_bb_a;
  real_T c4_bb_b;
  real_T c4_bb_y;
  real_T c4_hd_x;
  real_T c4_id_x;
  real_T c4_jd_x;
  real_T c4_kd_x;
  real_T c4_cb_a;
  real_T c4_cb_b;
  real_T c4_cb_y;
  real_T c4_ld_x;
  real_T c4_md_x;
  real_T c4_db_a;
  real_T c4_db_b;
  real_T c4_db_y;
  real_T c4_eb_a;
  real_T c4_eb_b;
  real_T c4_eb_y;
  real_T c4_nd_x;
  real_T c4_od_x;
  real_T c4_pd_x;
  real_T c4_qd_x;
  real_T c4_rd_x;
  real_T c4_sd_x;
  real_T c4_fb_a;
  real_T c4_fb_b;
  real_T c4_fb_y;
  real_T c4_td_x;
  real_T c4_ud_x;
  real_T c4_gb_a;
  real_T c4_gb_b;
  real_T c4_gb_y;
  real_T c4_vd_x;
  real_T c4_wd_x;
  real_T c4_xd_x;
  real_T c4_yd_x;
  real_T c4_hb_a;
  real_T c4_hb_b;
  real_T c4_hb_y;
  real_T c4_ae_x;
  real_T c4_be_x;
  real_T c4_ib_a;
  real_T c4_ib_b;
  real_T c4_ib_y;
  real_T c4_jb_a;
  real_T c4_jb_b;
  real_T c4_jb_y;
  real_T c4_kb_a;
  real_T c4_kb_b;
  real_T c4_kb_y;
  real_T c4_lb_a;
  real_T c4_lb_b;
  real_T c4_lb_y;
  real_T c4_ce_x;
  real_T c4_de_x;
  real_T c4_ee_x;
  real_T c4_fe_x;
  real_T c4_ge_x;
  real_T c4_he_x;
  real_T c4_ie_x;
  real_T c4_je_x;
  real_T c4_mb_a;
  real_T c4_mb_b;
  real_T c4_mb_y;
  real_T c4_ke_x;
  real_T c4_le_x;
  real_T c4_nb_a;
  real_T c4_nb_b;
  real_T c4_nb_y;
  real_T c4_me_x;
  real_T c4_ne_x;
  real_T c4_oe_x;
  real_T c4_pe_x;
  real_T c4_ob_a;
  real_T c4_ob_b;
  real_T c4_ob_y;
  real_T c4_qe_x;
  real_T c4_re_x;
  real_T c4_pb_a;
  real_T c4_pb_b;
  real_T c4_pb_y;
  real_T c4_qb_a;
  real_T c4_qb_b;
  real_T c4_qb_y;
  real_T c4_se_x;
  real_T c4_te_x;
  real_T c4_ue_x;
  real_T c4_ve_x;
  real_T c4_we_x;
  real_T c4_xe_x;
  real_T c4_rb_a;
  real_T c4_rb_b;
  real_T c4_rb_y;
  real_T c4_ye_x;
  real_T c4_af_x;
  real_T c4_sb_a;
  real_T c4_sb_b;
  real_T c4_sb_y;
  real_T c4_bf_x;
  real_T c4_cf_x;
  real_T c4_df_x;
  real_T c4_ef_x;
  real_T c4_tb_a;
  real_T c4_tb_b;
  real_T c4_tb_y;
  real_T c4_ff_x;
  real_T c4_gf_x;
  real_T c4_ub_a;
  real_T c4_ub_b;
  real_T c4_ub_y;
  real_T c4_vb_a;
  real_T c4_vb_b;
  real_T c4_vb_y;
  real_T c4_wb_a;
  real_T c4_wb_b;
  real_T c4_wb_y;
  real_T c4_hf_x;
  real_T c4_if_x;
  real_T c4_jf_x;
  real_T c4_kf_x;
  real_T c4_xb_a;
  real_T c4_xb_b;
  real_T c4_xb_y;
  real_T c4_lf_x;
  real_T c4_mf_x;
  real_T c4_nf_x;
  real_T c4_of_x;
  real_T c4_pf_x;
  real_T c4_qf_x;
  real_T c4_rf_x;
  real_T c4_sf_x;
  real_T c4_yb_a;
  real_T c4_yb_b;
  real_T c4_yb_y;
  real_T c4_tf_x;
  real_T c4_uf_x;
  real_T c4_ac_a;
  real_T c4_ac_b;
  real_T c4_ac_y;
  real_T c4_vf_x;
  real_T c4_wf_x;
  real_T c4_xf_x;
  real_T c4_yf_x;
  real_T c4_bc_a;
  real_T c4_bc_b;
  real_T c4_bc_y;
  real_T c4_ag_x;
  real_T c4_bg_x;
  real_T c4_cc_a;
  real_T c4_cc_b;
  real_T c4_cc_y;
  real_T c4_dc_a;
  real_T c4_dc_b;
  real_T c4_dc_y;
  real_T c4_cg_x;
  real_T c4_dg_x;
  real_T c4_eg_x;
  real_T c4_fg_x;
  real_T c4_gg_x;
  real_T c4_hg_x;
  real_T c4_ec_a;
  real_T c4_ec_b;
  real_T c4_ec_y;
  real_T c4_ig_x;
  real_T c4_jg_x;
  real_T c4_fc_a;
  real_T c4_fc_b;
  real_T c4_fc_y;
  real_T c4_kg_x;
  real_T c4_lg_x;
  real_T c4_mg_x;
  real_T c4_ng_x;
  real_T c4_gc_a;
  real_T c4_gc_b;
  real_T c4_gc_y;
  real_T c4_og_x;
  real_T c4_pg_x;
  real_T c4_hc_a;
  real_T c4_hc_b;
  real_T c4_hc_y;
  real_T c4_ic_a;
  real_T c4_ic_b;
  real_T c4_ic_y;
  real_T c4_jc_a;
  real_T c4_jc_b;
  real_T c4_jc_y;
  real_T c4_qg_x;
  real_T c4_rg_x;
  real_T c4_kc_b;
  real_T c4_kc_y;
  real_T c4_A;
  real_T c4_sg_x;
  real_T c4_tg_x;
  real_T c4_lc_y;
  real_T c4_ug_x;
  real_T c4_vg_x;
  real_T c4_lc_b;
  real_T c4_mc_y;
  real_T c4_wg_x;
  real_T c4_xg_x;
  real_T c4_kc_a;
  real_T c4_mc_b;
  real_T c4_nc_y;
  real_T c4_b_A;
  real_T c4_yg_x;
  real_T c4_ah_x;
  real_T c4_oc_y;
  real_T c4_bh_x;
  real_T c4_ch_x;
  real_T c4_nc_b;
  real_T c4_pc_y;
  real_T c4_dh_x;
  real_T c4_eh_x;
  real_T c4_lc_a;
  real_T c4_oc_b;
  real_T c4_qc_y;
  real_T c4_c_A;
  real_T c4_fh_x;
  real_T c4_gh_x;
  real_T c4_rc_y;
  real_T c4_hh_x;
  real_T c4_ih_x;
  real_T c4_pc_b;
  real_T c4_sc_y;
  real_T c4_jh_x;
  real_T c4_kh_x;
  real_T c4_lh_x;
  real_T c4_mh_x;
  real_T c4_mc_a;
  real_T c4_qc_b;
  real_T c4_tc_y;
  real_T c4_nh_x;
  real_T c4_oh_x;
  real_T c4_ph_x;
  real_T c4_qh_x;
  real_T c4_rh_x;
  real_T c4_sh_x;
  real_T c4_th_x;
  real_T c4_uh_x;
  real_T c4_nc_a;
  real_T c4_rc_b;
  real_T c4_uc_y;
  real_T c4_vh_x;
  real_T c4_wh_x;
  real_T c4_oc_a;
  real_T c4_sc_b;
  real_T c4_vc_y;
  real_T c4_xh_x;
  real_T c4_yh_x;
  real_T c4_ai_x;
  real_T c4_bi_x;
  real_T c4_pc_a;
  real_T c4_tc_b;
  real_T c4_wc_y;
  real_T c4_ci_x;
  real_T c4_di_x;
  real_T c4_qc_a;
  real_T c4_uc_b;
  real_T c4_xc_y;
  real_T c4_rc_a;
  real_T c4_vc_b;
  real_T c4_yc_y;
  real_T c4_ei_x;
  real_T c4_fi_x;
  real_T c4_gi_x;
  real_T c4_hi_x;
  real_T c4_ii_x;
  real_T c4_ji_x;
  real_T c4_sc_a;
  real_T c4_wc_b;
  real_T c4_ad_y;
  real_T c4_ki_x;
  real_T c4_li_x;
  real_T c4_tc_a;
  real_T c4_xc_b;
  real_T c4_bd_y;
  real_T c4_mi_x;
  real_T c4_ni_x;
  real_T c4_oi_x;
  real_T c4_pi_x;
  real_T c4_uc_a;
  real_T c4_yc_b;
  real_T c4_cd_y;
  real_T c4_qi_x;
  real_T c4_ri_x;
  real_T c4_vc_a;
  real_T c4_ad_b;
  real_T c4_dd_y;
  real_T c4_wc_a;
  real_T c4_bd_b;
  real_T c4_ed_y;
  real_T c4_xc_a;
  real_T c4_cd_b;
  real_T c4_fd_y;
  real_T c4_yc_a;
  real_T c4_dd_b;
  real_T c4_gd_y;
  real_T c4_d_A;
  real_T c4_si_x;
  real_T c4_ti_x;
  real_T c4_hd_y;
  real_T c4_ui_x;
  real_T c4_vi_x;
  real_T c4_ed_b;
  real_T c4_id_y;
  real_T c4_wi_x;
  real_T c4_xi_x;
  real_T c4_yi_x;
  real_T c4_aj_x;
  real_T c4_ad_a;
  real_T c4_fd_b;
  real_T c4_jd_y;
  real_T c4_bj_x;
  real_T c4_cj_x;
  real_T c4_bd_a;
  real_T c4_gd_b;
  real_T c4_kd_y;
  real_T c4_dj_x;
  real_T c4_ej_x;
  real_T c4_fj_x;
  real_T c4_gj_x;
  real_T c4_cd_a;
  real_T c4_hd_b;
  real_T c4_ld_y;
  real_T c4_hj_x;
  real_T c4_ij_x;
  real_T c4_dd_a;
  real_T c4_id_b;
  real_T c4_md_y;
  real_T c4_ed_a;
  real_T c4_jd_b;
  real_T c4_nd_y;
  real_T c4_e_A;
  real_T c4_jj_x;
  real_T c4_kj_x;
  real_T c4_od_y;
  real_T c4_lj_x;
  real_T c4_mj_x;
  real_T c4_kd_b;
  real_T c4_pd_y;
  real_T c4_nj_x;
  real_T c4_oj_x;
  real_T c4_pj_x;
  real_T c4_qj_x;
  real_T c4_fd_a;
  real_T c4_ld_b;
  real_T c4_qd_y;
  real_T c4_rj_x;
  real_T c4_sj_x;
  real_T c4_tj_x;
  real_T c4_uj_x;
  real_T c4_vj_x;
  real_T c4_wj_x;
  real_T c4_xj_x;
  real_T c4_yj_x;
  real_T c4_gd_a;
  real_T c4_md_b;
  real_T c4_rd_y;
  real_T c4_ak_x;
  real_T c4_bk_x;
  real_T c4_hd_a;
  real_T c4_nd_b;
  real_T c4_sd_y;
  real_T c4_ck_x;
  real_T c4_dk_x;
  real_T c4_ek_x;
  real_T c4_fk_x;
  real_T c4_id_a;
  real_T c4_od_b;
  real_T c4_td_y;
  real_T c4_gk_x;
  real_T c4_hk_x;
  real_T c4_jd_a;
  real_T c4_pd_b;
  real_T c4_ud_y;
  real_T c4_kd_a;
  real_T c4_qd_b;
  real_T c4_vd_y;
  real_T c4_ik_x;
  real_T c4_jk_x;
  real_T c4_kk_x;
  real_T c4_lk_x;
  real_T c4_mk_x;
  real_T c4_nk_x;
  real_T c4_ld_a;
  real_T c4_rd_b;
  real_T c4_wd_y;
  real_T c4_ok_x;
  real_T c4_pk_x;
  real_T c4_md_a;
  real_T c4_sd_b;
  real_T c4_xd_y;
  real_T c4_qk_x;
  real_T c4_rk_x;
  real_T c4_sk_x;
  real_T c4_tk_x;
  real_T c4_nd_a;
  real_T c4_td_b;
  real_T c4_yd_y;
  real_T c4_uk_x;
  real_T c4_vk_x;
  real_T c4_od_a;
  real_T c4_ud_b;
  real_T c4_ae_y;
  real_T c4_pd_a;
  real_T c4_vd_b;
  real_T c4_be_y;
  real_T c4_qd_a;
  real_T c4_wd_b;
  real_T c4_ce_y;
  real_T c4_rd_a;
  real_T c4_xd_b;
  real_T c4_de_y;
  real_T c4_f_A;
  real_T c4_wk_x;
  real_T c4_xk_x;
  real_T c4_ee_y;
  real_T c4_yk_x;
  real_T c4_al_x;
  real_T c4_yd_b;
  real_T c4_fe_y;
  real_T c4_bl_x;
  real_T c4_cl_x;
  real_T c4_dl_x;
  real_T c4_el_x;
  real_T c4_sd_a;
  real_T c4_ae_b;
  real_T c4_ge_y;
  real_T c4_fl_x;
  real_T c4_gl_x;
  real_T c4_td_a;
  real_T c4_be_b;
  real_T c4_he_y;
  real_T c4_hl_x;
  real_T c4_il_x;
  real_T c4_jl_x;
  real_T c4_kl_x;
  real_T c4_ud_a;
  real_T c4_ce_b;
  real_T c4_ie_y;
  real_T c4_ll_x;
  real_T c4_ml_x;
  real_T c4_vd_a;
  real_T c4_de_b;
  real_T c4_je_y;
  real_T c4_wd_a;
  real_T c4_ee_b;
  real_T c4_ke_y;
  real_T c4_g_A;
  real_T c4_nl_x;
  real_T c4_ol_x;
  real_T c4_le_y;
  real_T c4_pl_x;
  real_T c4_ql_x;
  real_T c4_fe_b;
  real_T c4_me_y;
  real_T c4_rl_x;
  real_T c4_sl_x;
  real_T c4_tl_x;
  real_T c4_ul_x;
  real_T c4_vl_x;
  real_T c4_wl_x;
  real_T c4_xd_a;
  real_T c4_ge_b;
  real_T c4_ne_y;
  real_T c4_xl_x;
  real_T c4_yl_x;
  real_T c4_yd_a;
  real_T c4_he_b;
  real_T c4_oe_y;
  real_T c4_am_x;
  real_T c4_bm_x;
  real_T c4_cm_x;
  real_T c4_dm_x;
  real_T c4_ae_a;
  real_T c4_ie_b;
  real_T c4_pe_y;
  real_T c4_em_x;
  real_T c4_fm_x;
  real_T c4_be_a;
  real_T c4_je_b;
  real_T c4_qe_y;
  real_T c4_ce_a;
  real_T c4_ke_b;
  real_T c4_re_y;
  real_T c4_gm_x;
  real_T c4_hm_x;
  real_T c4_im_x;
  real_T c4_jm_x;
  real_T c4_km_x;
  real_T c4_lm_x;
  real_T c4_de_a;
  real_T c4_le_b;
  real_T c4_se_y;
  real_T c4_mm_x;
  real_T c4_nm_x;
  real_T c4_ee_a;
  real_T c4_me_b;
  real_T c4_te_y;
  real_T c4_om_x;
  real_T c4_pm_x;
  real_T c4_qm_x;
  real_T c4_rm_x;
  real_T c4_fe_a;
  real_T c4_ne_b;
  real_T c4_ue_y;
  real_T c4_sm_x;
  real_T c4_tm_x;
  real_T c4_ge_a;
  real_T c4_oe_b;
  real_T c4_ve_y;
  real_T c4_he_a;
  real_T c4_pe_b;
  real_T c4_we_y;
  real_T c4_ie_a;
  real_T c4_qe_b;
  real_T c4_xe_y;
  real_T c4_h_A;
  real_T c4_um_x;
  real_T c4_vm_x;
  real_T c4_ye_y;
  real_T c4_wm_x;
  real_T c4_xm_x;
  real_T c4_re_b;
  real_T c4_af_y;
  real_T c4_ym_x;
  real_T c4_an_x;
  real_T c4_bn_x;
  real_T c4_cn_x;
  real_T c4_dn_x;
  real_T c4_en_x;
  real_T c4_je_a;
  real_T c4_se_b;
  real_T c4_bf_y;
  real_T c4_fn_x;
  real_T c4_gn_x;
  real_T c4_ke_a;
  real_T c4_te_b;
  real_T c4_cf_y;
  real_T c4_hn_x;
  real_T c4_in_x;
  real_T c4_jn_x;
  real_T c4_kn_x;
  real_T c4_le_a;
  real_T c4_ue_b;
  real_T c4_df_y;
  real_T c4_ln_x;
  real_T c4_mn_x;
  real_T c4_me_a;
  real_T c4_ve_b;
  real_T c4_ef_y;
  real_T c4_ne_a;
  real_T c4_we_b;
  real_T c4_ff_y;
  real_T c4_nn_x;
  real_T c4_on_x;
  real_T c4_pn_x;
  real_T c4_qn_x;
  real_T c4_rn_x;
  real_T c4_sn_x;
  real_T c4_oe_a;
  real_T c4_xe_b;
  real_T c4_gf_y;
  real_T c4_tn_x;
  real_T c4_un_x;
  real_T c4_pe_a;
  real_T c4_ye_b;
  real_T c4_hf_y;
  real_T c4_vn_x;
  real_T c4_wn_x;
  real_T c4_xn_x;
  real_T c4_yn_x;
  real_T c4_qe_a;
  real_T c4_af_b;
  real_T c4_if_y;
  real_T c4_ao_x;
  real_T c4_bo_x;
  real_T c4_re_a;
  real_T c4_bf_b;
  real_T c4_jf_y;
  real_T c4_se_a;
  real_T c4_cf_b;
  real_T c4_kf_y;
  real_T c4_te_a;
  real_T c4_df_b;
  real_T c4_lf_y;
  real_T c4_i_A;
  real_T c4_co_x;
  real_T c4_do_x;
  real_T c4_mf_y;
  real_T c4_eo_x;
  real_T c4_fo_x;
  real_T c4_ef_b;
  real_T c4_nf_y;
  real_T c4_go_x;
  real_T c4_ho_x;
  real_T c4_io_x;
  real_T c4_jo_x;
  real_T c4_ko_x;
  real_T c4_lo_x;
  real_T c4_ue_a;
  real_T c4_ff_b;
  real_T c4_of_y;
  real_T c4_mo_x;
  real_T c4_no_x;
  real_T c4_ve_a;
  real_T c4_gf_b;
  real_T c4_pf_y;
  real_T c4_oo_x;
  real_T c4_po_x;
  real_T c4_qo_x;
  real_T c4_ro_x;
  real_T c4_we_a;
  real_T c4_hf_b;
  real_T c4_qf_y;
  real_T c4_so_x;
  real_T c4_to_x;
  real_T c4_xe_a;
  real_T c4_if_b;
  real_T c4_rf_y;
  real_T c4_ye_a;
  real_T c4_jf_b;
  real_T c4_sf_y;
  real_T c4_uo_x;
  real_T c4_vo_x;
  real_T c4_wo_x;
  real_T c4_xo_x;
  real_T c4_yo_x;
  real_T c4_ap_x;
  real_T c4_af_a;
  real_T c4_kf_b;
  real_T c4_tf_y;
  real_T c4_bp_x;
  real_T c4_cp_x;
  real_T c4_bf_a;
  real_T c4_lf_b;
  real_T c4_uf_y;
  real_T c4_dp_x;
  real_T c4_ep_x;
  real_T c4_fp_x;
  real_T c4_gp_x;
  real_T c4_cf_a;
  real_T c4_mf_b;
  real_T c4_vf_y;
  real_T c4_hp_x;
  real_T c4_ip_x;
  real_T c4_df_a;
  real_T c4_nf_b;
  real_T c4_wf_y;
  real_T c4_ef_a;
  real_T c4_of_b;
  real_T c4_xf_y;
  real_T c4_ff_a;
  real_T c4_pf_b;
  real_T c4_yf_y;
  real_T c4_j_A;
  real_T c4_jp_x;
  real_T c4_kp_x;
  real_T c4_ag_y;
  real_T c4_lp_x;
  real_T c4_mp_x;
  real_T c4_qf_b;
  real_T c4_bg_y;
  real_T c4_np_x;
  real_T c4_op_x;
  real_T c4_gf_a;
  real_T c4_rf_b;
  real_T c4_cg_y;
  real_T c4_pp_x;
  real_T c4_qp_x;
  real_T c4_hf_a;
  real_T c4_sf_b;
  real_T c4_dg_y;
  real_T c4_k_A;
  real_T c4_rp_x;
  real_T c4_sp_x;
  real_T c4_eg_y;
  real_T c4_tp_x;
  real_T c4_up_x;
  real_T c4_tf_b;
  real_T c4_fg_y;
  real_T c4_vp_x;
  real_T c4_wp_x;
  real_T c4_if_a;
  real_T c4_uf_b;
  real_T c4_gg_y;
  real_T c4_xp_x;
  real_T c4_yp_x;
  real_T c4_jf_a;
  real_T c4_vf_b;
  real_T c4_hg_y;
  real_T c4_l_A;
  real_T c4_aq_x;
  real_T c4_bq_x;
  real_T c4_ig_y;
  real_T c4_cq_x;
  real_T c4_dq_x;
  real_T c4_eq_x;
  real_T c4_fq_x;
  real_T c4_gq_x;
  real_T c4_hq_x;
  real_T c4_kf_a;
  real_T c4_wf_b;
  real_T c4_jg_y;
  real_T c4_iq_x;
  real_T c4_jq_x;
  real_T c4_kq_x;
  real_T c4_lq_x;
  real_T c4_mq_x;
  real_T c4_nq_x;
  real_T c4_oq_x;
  real_T c4_pq_x;
  real_T c4_lf_a;
  real_T c4_xf_b;
  real_T c4_kg_y;
  real_T c4_qq_x;
  real_T c4_rq_x;
  real_T c4_mf_a;
  real_T c4_yf_b;
  real_T c4_lg_y;
  real_T c4_sq_x;
  real_T c4_tq_x;
  real_T c4_uq_x;
  real_T c4_vq_x;
  real_T c4_nf_a;
  real_T c4_ag_b;
  real_T c4_mg_y;
  real_T c4_wq_x;
  real_T c4_xq_x;
  real_T c4_of_a;
  real_T c4_bg_b;
  real_T c4_ng_y;
  real_T c4_pf_a;
  real_T c4_cg_b;
  real_T c4_og_y;
  real_T c4_yq_x;
  real_T c4_ar_x;
  real_T c4_br_x;
  real_T c4_cr_x;
  real_T c4_dr_x;
  real_T c4_er_x;
  real_T c4_qf_a;
  real_T c4_dg_b;
  real_T c4_pg_y;
  real_T c4_fr_x;
  real_T c4_gr_x;
  real_T c4_rf_a;
  real_T c4_eg_b;
  real_T c4_qg_y;
  real_T c4_hr_x;
  real_T c4_ir_x;
  real_T c4_jr_x;
  real_T c4_kr_x;
  real_T c4_sf_a;
  real_T c4_fg_b;
  real_T c4_rg_y;
  real_T c4_lr_x;
  real_T c4_mr_x;
  real_T c4_tf_a;
  real_T c4_gg_b;
  real_T c4_sg_y;
  real_T c4_uf_a;
  real_T c4_hg_b;
  real_T c4_tg_y;
  real_T c4_vf_a;
  real_T c4_ig_b;
  real_T c4_ug_y;
  real_T c4_wf_a;
  real_T c4_jg_b;
  real_T c4_vg_y;
  real_T c4_nr_x;
  real_T c4_or_x;
  real_T c4_pr_x;
  real_T c4_qr_x;
  real_T c4_rr_x;
  real_T c4_sr_x;
  real_T c4_tr_x;
  real_T c4_ur_x;
  real_T c4_xf_a;
  real_T c4_kg_b;
  real_T c4_wg_y;
  real_T c4_vr_x;
  real_T c4_wr_x;
  real_T c4_yf_a;
  real_T c4_lg_b;
  real_T c4_xg_y;
  real_T c4_xr_x;
  real_T c4_yr_x;
  real_T c4_as_x;
  real_T c4_bs_x;
  real_T c4_ag_a;
  real_T c4_mg_b;
  real_T c4_yg_y;
  real_T c4_cs_x;
  real_T c4_ds_x;
  real_T c4_bg_a;
  real_T c4_ng_b;
  real_T c4_ah_y;
  real_T c4_cg_a;
  real_T c4_og_b;
  real_T c4_bh_y;
  real_T c4_es_x;
  real_T c4_fs_x;
  real_T c4_gs_x;
  real_T c4_hs_x;
  real_T c4_is_x;
  real_T c4_js_x;
  real_T c4_dg_a;
  real_T c4_pg_b;
  real_T c4_ch_y;
  real_T c4_ks_x;
  real_T c4_ls_x;
  real_T c4_eg_a;
  real_T c4_qg_b;
  real_T c4_dh_y;
  real_T c4_ms_x;
  real_T c4_ns_x;
  real_T c4_os_x;
  real_T c4_ps_x;
  real_T c4_fg_a;
  real_T c4_rg_b;
  real_T c4_eh_y;
  real_T c4_qs_x;
  real_T c4_rs_x;
  real_T c4_gg_a;
  real_T c4_sg_b;
  real_T c4_fh_y;
  real_T c4_hg_a;
  real_T c4_tg_b;
  real_T c4_gh_y;
  real_T c4_ig_a;
  real_T c4_ug_b;
  real_T c4_hh_y;
  real_T c4_ss_x;
  real_T c4_ts_x;
  real_T c4_us_x;
  real_T c4_vs_x;
  real_T c4_ws_x;
  real_T c4_xs_x;
  real_T c4_jg_a;
  real_T c4_vg_b;
  real_T c4_ih_y;
  real_T c4_ys_x;
  real_T c4_at_x;
  real_T c4_bt_x;
  real_T c4_ct_x;
  real_T c4_dt_x;
  real_T c4_et_x;
  real_T c4_ft_x;
  real_T c4_gt_x;
  real_T c4_kg_a;
  real_T c4_wg_b;
  real_T c4_jh_y;
  real_T c4_ht_x;
  real_T c4_it_x;
  real_T c4_lg_a;
  real_T c4_xg_b;
  real_T c4_kh_y;
  real_T c4_jt_x;
  real_T c4_kt_x;
  real_T c4_lt_x;
  real_T c4_mt_x;
  real_T c4_mg_a;
  real_T c4_yg_b;
  real_T c4_lh_y;
  real_T c4_nt_x;
  real_T c4_ot_x;
  real_T c4_ng_a;
  real_T c4_ah_b;
  real_T c4_mh_y;
  real_T c4_og_a;
  real_T c4_bh_b;
  real_T c4_nh_y;
  real_T c4_pt_x;
  real_T c4_qt_x;
  real_T c4_rt_x;
  real_T c4_st_x;
  real_T c4_tt_x;
  real_T c4_ut_x;
  real_T c4_pg_a;
  real_T c4_ch_b;
  real_T c4_oh_y;
  real_T c4_vt_x;
  real_T c4_wt_x;
  real_T c4_qg_a;
  real_T c4_dh_b;
  real_T c4_ph_y;
  real_T c4_xt_x;
  real_T c4_yt_x;
  real_T c4_au_x;
  real_T c4_bu_x;
  real_T c4_rg_a;
  real_T c4_eh_b;
  real_T c4_qh_y;
  real_T c4_cu_x;
  real_T c4_du_x;
  real_T c4_sg_a;
  real_T c4_fh_b;
  real_T c4_rh_y;
  real_T c4_tg_a;
  real_T c4_gh_b;
  real_T c4_sh_y;
  real_T c4_ug_a;
  real_T c4_hh_b;
  real_T c4_th_y;
  real_T c4_vg_a;
  real_T c4_ih_b;
  real_T c4_uh_y;
  real_T c4_eu_x;
  real_T c4_fu_x;
  real_T c4_gu_x;
  real_T c4_hu_x;
  real_T c4_iu_x;
  real_T c4_ju_x;
  real_T c4_ku_x;
  real_T c4_lu_x;
  real_T c4_wg_a;
  real_T c4_jh_b;
  real_T c4_vh_y;
  real_T c4_mu_x;
  real_T c4_nu_x;
  real_T c4_xg_a;
  real_T c4_kh_b;
  real_T c4_wh_y;
  real_T c4_ou_x;
  real_T c4_pu_x;
  real_T c4_qu_x;
  real_T c4_ru_x;
  real_T c4_yg_a;
  real_T c4_lh_b;
  real_T c4_xh_y;
  real_T c4_su_x;
  real_T c4_tu_x;
  real_T c4_ah_a;
  real_T c4_mh_b;
  real_T c4_yh_y;
  real_T c4_bh_a;
  real_T c4_nh_b;
  real_T c4_ai_y;
  real_T c4_uu_x;
  real_T c4_vu_x;
  real_T c4_wu_x;
  real_T c4_xu_x;
  real_T c4_yu_x;
  real_T c4_av_x;
  real_T c4_ch_a;
  real_T c4_oh_b;
  real_T c4_bi_y;
  real_T c4_bv_x;
  real_T c4_cv_x;
  real_T c4_dh_a;
  real_T c4_ph_b;
  real_T c4_ci_y;
  real_T c4_dv_x;
  real_T c4_ev_x;
  real_T c4_fv_x;
  real_T c4_gv_x;
  real_T c4_eh_a;
  real_T c4_qh_b;
  real_T c4_di_y;
  real_T c4_hv_x;
  real_T c4_iv_x;
  real_T c4_fh_a;
  real_T c4_rh_b;
  real_T c4_ei_y;
  real_T c4_gh_a;
  real_T c4_sh_b;
  real_T c4_fi_y;
  real_T c4_hh_a;
  real_T c4_th_b;
  real_T c4_gi_y;
  real_T c4_jv_x;
  real_T c4_kv_x;
  real_T c4_lv_x;
  real_T c4_mv_x;
  real_T c4_nv_x;
  real_T c4_ov_x;
  real_T c4_pv_x;
  real_T c4_qv_x;
  real_T c4_ih_a;
  real_T c4_uh_b;
  real_T c4_hi_y;
  real_T c4_rv_x;
  real_T c4_sv_x;
  real_T c4_jh_a;
  real_T c4_vh_b;
  real_T c4_ii_y;
  real_T c4_tv_x;
  real_T c4_uv_x;
  real_T c4_vv_x;
  real_T c4_wv_x;
  real_T c4_kh_a;
  real_T c4_wh_b;
  real_T c4_ji_y;
  real_T c4_xv_x;
  real_T c4_yv_x;
  real_T c4_lh_a;
  real_T c4_xh_b;
  real_T c4_ki_y;
  real_T c4_mh_a;
  real_T c4_yh_b;
  real_T c4_li_y;
  real_T c4_aw_x;
  real_T c4_bw_x;
  real_T c4_cw_x;
  real_T c4_dw_x;
  real_T c4_ew_x;
  real_T c4_fw_x;
  real_T c4_nh_a;
  real_T c4_ai_b;
  real_T c4_mi_y;
  real_T c4_gw_x;
  real_T c4_hw_x;
  real_T c4_oh_a;
  real_T c4_bi_b;
  real_T c4_ni_y;
  real_T c4_iw_x;
  real_T c4_jw_x;
  real_T c4_kw_x;
  real_T c4_lw_x;
  real_T c4_ph_a;
  real_T c4_ci_b;
  real_T c4_oi_y;
  real_T c4_mw_x;
  real_T c4_nw_x;
  real_T c4_qh_a;
  real_T c4_di_b;
  real_T c4_pi_y;
  real_T c4_rh_a;
  real_T c4_ei_b;
  real_T c4_qi_y;
  real_T c4_sh_a;
  real_T c4_fi_b;
  real_T c4_ri_y;
  real_T c4_ow_x;
  real_T c4_pw_x;
  real_T c4_qw_x;
  real_T c4_rw_x;
  real_T c4_th_a;
  real_T c4_gi_b;
  real_T c4_si_y;
  real_T c4_sw_x;
  real_T c4_tw_x;
  real_T c4_hi_b;
  real_T c4_ti_y;
  real_T c4_uw_x;
  real_T c4_vw_x;
  real_T c4_ww_x;
  real_T c4_xw_x;
  real_T c4_uh_a;
  real_T c4_ii_b;
  real_T c4_ui_y;
  real_T c4_yw_x;
  real_T c4_ax_x;
  real_T c4_vh_a;
  real_T c4_ji_b;
  real_T c4_vi_y;
  real_T c4_bx_x;
  real_T c4_cx_x;
  real_T c4_dx_x;
  real_T c4_ex_x;
  real_T c4_wh_a;
  real_T c4_ki_b;
  real_T c4_wi_y;
  real_T c4_fx_x;
  real_T c4_gx_x;
  real_T c4_xh_a;
  real_T c4_li_b;
  real_T c4_xi_y;
  real_T c4_yh_a;
  real_T c4_mi_b;
  real_T c4_yi_y;
  real_T c4_m_A;
  real_T c4_hx_x;
  real_T c4_ix_x;
  real_T c4_aj_y;
  real_T c4_jx_x;
  real_T c4_kx_x;
  real_T c4_ni_b;
  real_T c4_bj_y;
  real_T c4_lx_x;
  real_T c4_mx_x;
  real_T c4_ai_a;
  real_T c4_oi_b;
  real_T c4_cj_y;
  real_T c4_n_A;
  real_T c4_nx_x;
  real_T c4_ox_x;
  real_T c4_dj_y;
  real_T c4_px_x;
  real_T c4_qx_x;
  real_T c4_pi_b;
  real_T c4_ej_y;
  real_T c4_rx_x;
  real_T c4_sx_x;
  real_T c4_bi_a;
  real_T c4_qi_b;
  real_T c4_fj_y;
  real_T c4_o_A;
  real_T c4_tx_x;
  real_T c4_ux_x;
  real_T c4_gj_y;
  real_T c4_vx_x;
  real_T c4_wx_x;
  real_T c4_ri_b;
  real_T c4_hj_y;
  real_T c4_p_A;
  real_T c4_xx_x;
  real_T c4_yx_x;
  real_T c4_ij_y;
  real_T c4_ay_x;
  real_T c4_by_x;
  real_T c4_si_b;
  real_T c4_jj_y;
  real_T c4_cy_x;
  real_T c4_dy_x;
  real_T c4_ey_x;
  real_T c4_fy_x;
  real_T c4_ci_a;
  real_T c4_ti_b;
  real_T c4_kj_y;
  real_T c4_gy_x;
  real_T c4_hy_x;
  real_T c4_iy_x;
  real_T c4_jy_x;
  real_T c4_ky_x;
  real_T c4_ly_x;
  real_T c4_my_x;
  real_T c4_ny_x;
  real_T c4_di_a;
  real_T c4_ui_b;
  real_T c4_lj_y;
  real_T c4_oy_x;
  real_T c4_py_x;
  real_T c4_ei_a;
  real_T c4_vi_b;
  real_T c4_mj_y;
  real_T c4_qy_x;
  real_T c4_ry_x;
  real_T c4_sy_x;
  real_T c4_ty_x;
  real_T c4_fi_a;
  real_T c4_wi_b;
  real_T c4_nj_y;
  real_T c4_uy_x;
  real_T c4_vy_x;
  real_T c4_gi_a;
  real_T c4_xi_b;
  real_T c4_oj_y;
  real_T c4_hi_a;
  real_T c4_yi_b;
  real_T c4_pj_y;
  real_T c4_wy_x;
  real_T c4_xy_x;
  real_T c4_yy_x;
  real_T c4_aab_x;
  real_T c4_bab_x;
  real_T c4_cab_x;
  real_T c4_ii_a;
  real_T c4_aj_b;
  real_T c4_qj_y;
  real_T c4_dab_x;
  real_T c4_eab_x;
  real_T c4_ji_a;
  real_T c4_bj_b;
  real_T c4_rj_y;
  real_T c4_fab_x;
  real_T c4_gab_x;
  real_T c4_hab_x;
  real_T c4_iab_x;
  real_T c4_ki_a;
  real_T c4_cj_b;
  real_T c4_sj_y;
  real_T c4_jab_x;
  real_T c4_kab_x;
  real_T c4_li_a;
  real_T c4_dj_b;
  real_T c4_tj_y;
  real_T c4_mi_a;
  real_T c4_ej_b;
  real_T c4_uj_y;
  real_T c4_ni_a;
  real_T c4_fj_b;
  real_T c4_vj_y;
  real_T c4_oi_a;
  real_T c4_gj_b;
  real_T c4_wj_y;
  real_T c4_q_A;
  real_T c4_lab_x;
  real_T c4_mab_x;
  real_T c4_xj_y;
  real_T c4_nab_x;
  real_T c4_oab_x;
  real_T c4_hj_b;
  real_T c4_yj_y;
  real_T c4_pab_x;
  real_T c4_qab_x;
  real_T c4_rab_x;
  real_T c4_sab_x;
  real_T c4_pi_a;
  real_T c4_ij_b;
  real_T c4_ak_y;
  real_T c4_tab_x;
  real_T c4_uab_x;
  real_T c4_qi_a;
  real_T c4_jj_b;
  real_T c4_bk_y;
  real_T c4_vab_x;
  real_T c4_wab_x;
  real_T c4_xab_x;
  real_T c4_yab_x;
  real_T c4_ri_a;
  real_T c4_kj_b;
  real_T c4_ck_y;
  real_T c4_abb_x;
  real_T c4_bbb_x;
  real_T c4_si_a;
  real_T c4_lj_b;
  real_T c4_dk_y;
  real_T c4_ti_a;
  real_T c4_mj_b;
  real_T c4_ek_y;
  real_T c4_r_A;
  real_T c4_cbb_x;
  real_T c4_dbb_x;
  real_T c4_fk_y;
  real_T c4_ebb_x;
  real_T c4_fbb_x;
  real_T c4_nj_b;
  real_T c4_gk_y;
  real_T c4_gbb_x;
  real_T c4_hbb_x;
  real_T c4_ibb_x;
  real_T c4_jbb_x;
  real_T c4_ui_a;
  real_T c4_oj_b;
  real_T c4_hk_y;
  real_T c4_kbb_x;
  real_T c4_lbb_x;
  real_T c4_mbb_x;
  real_T c4_nbb_x;
  real_T c4_obb_x;
  real_T c4_pbb_x;
  real_T c4_qbb_x;
  real_T c4_rbb_x;
  real_T c4_vi_a;
  real_T c4_pj_b;
  real_T c4_ik_y;
  real_T c4_sbb_x;
  real_T c4_tbb_x;
  real_T c4_wi_a;
  real_T c4_qj_b;
  real_T c4_jk_y;
  real_T c4_ubb_x;
  real_T c4_vbb_x;
  real_T c4_wbb_x;
  real_T c4_xbb_x;
  real_T c4_xi_a;
  real_T c4_rj_b;
  real_T c4_kk_y;
  real_T c4_ybb_x;
  real_T c4_acb_x;
  real_T c4_yi_a;
  real_T c4_sj_b;
  real_T c4_lk_y;
  real_T c4_aj_a;
  real_T c4_tj_b;
  real_T c4_mk_y;
  real_T c4_bcb_x;
  real_T c4_ccb_x;
  real_T c4_dcb_x;
  real_T c4_ecb_x;
  real_T c4_fcb_x;
  real_T c4_gcb_x;
  real_T c4_bj_a;
  real_T c4_uj_b;
  real_T c4_nk_y;
  real_T c4_hcb_x;
  real_T c4_icb_x;
  real_T c4_cj_a;
  real_T c4_vj_b;
  real_T c4_ok_y;
  real_T c4_jcb_x;
  real_T c4_kcb_x;
  real_T c4_lcb_x;
  real_T c4_mcb_x;
  real_T c4_dj_a;
  real_T c4_wj_b;
  real_T c4_pk_y;
  real_T c4_ncb_x;
  real_T c4_ocb_x;
  real_T c4_ej_a;
  real_T c4_xj_b;
  real_T c4_qk_y;
  real_T c4_fj_a;
  real_T c4_yj_b;
  real_T c4_rk_y;
  real_T c4_gj_a;
  real_T c4_ak_b;
  real_T c4_sk_y;
  real_T c4_hj_a;
  real_T c4_bk_b;
  real_T c4_tk_y;
  real_T c4_s_A;
  real_T c4_pcb_x;
  real_T c4_qcb_x;
  real_T c4_uk_y;
  real_T c4_rcb_x;
  real_T c4_scb_x;
  real_T c4_ck_b;
  real_T c4_vk_y;
  real_T c4_tcb_x;
  real_T c4_ucb_x;
  real_T c4_vcb_x;
  real_T c4_wcb_x;
  real_T c4_xcb_x;
  real_T c4_ycb_x;
  real_T c4_ij_a;
  real_T c4_dk_b;
  real_T c4_wk_y;
  real_T c4_adb_x;
  real_T c4_bdb_x;
  real_T c4_jj_a;
  real_T c4_ek_b;
  real_T c4_xk_y;
  real_T c4_cdb_x;
  real_T c4_ddb_x;
  real_T c4_edb_x;
  real_T c4_fdb_x;
  real_T c4_kj_a;
  real_T c4_fk_b;
  real_T c4_yk_y;
  real_T c4_gdb_x;
  real_T c4_hdb_x;
  real_T c4_lj_a;
  real_T c4_gk_b;
  real_T c4_al_y;
  real_T c4_mj_a;
  real_T c4_hk_b;
  real_T c4_bl_y;
  real_T c4_idb_x;
  real_T c4_jdb_x;
  real_T c4_kdb_x;
  real_T c4_ldb_x;
  real_T c4_mdb_x;
  real_T c4_ndb_x;
  real_T c4_nj_a;
  real_T c4_ik_b;
  real_T c4_cl_y;
  real_T c4_odb_x;
  real_T c4_pdb_x;
  real_T c4_oj_a;
  real_T c4_jk_b;
  real_T c4_dl_y;
  real_T c4_qdb_x;
  real_T c4_rdb_x;
  real_T c4_sdb_x;
  real_T c4_tdb_x;
  real_T c4_pj_a;
  real_T c4_kk_b;
  real_T c4_el_y;
  real_T c4_udb_x;
  real_T c4_vdb_x;
  real_T c4_qj_a;
  real_T c4_lk_b;
  real_T c4_fl_y;
  real_T c4_rj_a;
  real_T c4_mk_b;
  real_T c4_gl_y;
  real_T c4_sj_a;
  real_T c4_nk_b;
  real_T c4_hl_y;
  real_T c4_t_A;
  real_T c4_wdb_x;
  real_T c4_xdb_x;
  real_T c4_il_y;
  real_T c4_ydb_x;
  real_T c4_aeb_x;
  real_T c4_ok_b;
  real_T c4_jl_y;
  real_T c4_beb_x;
  real_T c4_ceb_x;
  real_T c4_deb_x;
  real_T c4_eeb_x;
  real_T c4_feb_x;
  real_T c4_geb_x;
  real_T c4_tj_a;
  real_T c4_pk_b;
  real_T c4_kl_y;
  real_T c4_heb_x;
  real_T c4_ieb_x;
  real_T c4_uj_a;
  real_T c4_qk_b;
  real_T c4_ll_y;
  real_T c4_jeb_x;
  real_T c4_keb_x;
  real_T c4_leb_x;
  real_T c4_meb_x;
  real_T c4_vj_a;
  real_T c4_rk_b;
  real_T c4_ml_y;
  real_T c4_neb_x;
  real_T c4_oeb_x;
  real_T c4_wj_a;
  real_T c4_sk_b;
  real_T c4_nl_y;
  real_T c4_xj_a;
  real_T c4_tk_b;
  real_T c4_ol_y;
  real_T c4_peb_x;
  real_T c4_qeb_x;
  real_T c4_reb_x;
  real_T c4_seb_x;
  real_T c4_teb_x;
  real_T c4_ueb_x;
  real_T c4_yj_a;
  real_T c4_uk_b;
  real_T c4_pl_y;
  real_T c4_veb_x;
  real_T c4_web_x;
  real_T c4_ak_a;
  real_T c4_vk_b;
  real_T c4_ql_y;
  real_T c4_xeb_x;
  real_T c4_yeb_x;
  real_T c4_afb_x;
  real_T c4_bfb_x;
  real_T c4_bk_a;
  real_T c4_wk_b;
  real_T c4_rl_y;
  real_T c4_cfb_x;
  real_T c4_dfb_x;
  real_T c4_ck_a;
  real_T c4_xk_b;
  real_T c4_sl_y;
  real_T c4_dk_a;
  real_T c4_yk_b;
  real_T c4_tl_y;
  real_T c4_ek_a;
  real_T c4_al_b;
  real_T c4_ul_y;
  real_T c4_u_A;
  real_T c4_efb_x;
  real_T c4_ffb_x;
  real_T c4_vl_y;
  real_T c4_gfb_x;
  real_T c4_hfb_x;
  real_T c4_bl_b;
  real_T c4_wl_y;
  real_T c4_ifb_x;
  real_T c4_jfb_x;
  real_T c4_kfb_x;
  real_T c4_lfb_x;
  real_T c4_mfb_x;
  real_T c4_nfb_x;
  real_T c4_fk_a;
  real_T c4_cl_b;
  real_T c4_xl_y;
  real_T c4_ofb_x;
  real_T c4_pfb_x;
  real_T c4_gk_a;
  real_T c4_dl_b;
  real_T c4_yl_y;
  real_T c4_qfb_x;
  real_T c4_rfb_x;
  real_T c4_sfb_x;
  real_T c4_tfb_x;
  real_T c4_hk_a;
  real_T c4_el_b;
  real_T c4_am_y;
  real_T c4_ufb_x;
  real_T c4_vfb_x;
  real_T c4_ik_a;
  real_T c4_fl_b;
  real_T c4_bm_y;
  real_T c4_jk_a;
  real_T c4_gl_b;
  real_T c4_cm_y;
  real_T c4_wfb_x;
  real_T c4_xfb_x;
  real_T c4_yfb_x;
  real_T c4_agb_x;
  real_T c4_bgb_x;
  real_T c4_cgb_x;
  real_T c4_kk_a;
  real_T c4_hl_b;
  real_T c4_dm_y;
  real_T c4_dgb_x;
  real_T c4_egb_x;
  real_T c4_lk_a;
  real_T c4_il_b;
  real_T c4_em_y;
  real_T c4_fgb_x;
  real_T c4_ggb_x;
  real_T c4_hgb_x;
  real_T c4_igb_x;
  real_T c4_mk_a;
  real_T c4_jl_b;
  real_T c4_fm_y;
  real_T c4_jgb_x;
  real_T c4_kgb_x;
  real_T c4_nk_a;
  real_T c4_kl_b;
  real_T c4_gm_y;
  real_T c4_ok_a;
  real_T c4_ll_b;
  real_T c4_hm_y;
  real_T c4_pk_a;
  real_T c4_ml_b;
  real_T c4_im_y;
  real_T c4_v_A;
  real_T c4_lgb_x;
  real_T c4_mgb_x;
  real_T c4_jm_y;
  real_T c4_ngb_x;
  real_T c4_ogb_x;
  real_T c4_nl_b;
  real_T c4_km_y;
  real_T c4_pgb_x;
  real_T c4_qgb_x;
  real_T c4_qk_a;
  real_T c4_ol_b;
  real_T c4_lm_y;
  real_T c4_rgb_x;
  real_T c4_sgb_x;
  real_T c4_rk_a;
  real_T c4_pl_b;
  real_T c4_mm_y;
  real_T c4_w_A;
  real_T c4_tgb_x;
  real_T c4_ugb_x;
  real_T c4_nm_y;
  real_T c4_vgb_x;
  real_T c4_wgb_x;
  real_T c4_ql_b;
  real_T c4_om_y;
  real_T c4_xgb_x;
  real_T c4_ygb_x;
  real_T c4_sk_a;
  real_T c4_rl_b;
  real_T c4_pm_y;
  real_T c4_ahb_x;
  real_T c4_bhb_x;
  real_T c4_tk_a;
  real_T c4_sl_b;
  real_T c4_qm_y;
  real_T c4_x_A;
  real_T c4_chb_x;
  real_T c4_dhb_x;
  real_T c4_rm_y;
  real_T c4_ehb_x;
  real_T c4_fhb_x;
  real_T c4_ghb_x;
  real_T c4_hhb_x;
  real_T c4_ihb_x;
  real_T c4_jhb_x;
  real_T c4_khb_x;
  real_T c4_lhb_x;
  real_T c4_uk_a;
  real_T c4_tl_b;
  real_T c4_sm_y;
  real_T c4_mhb_x;
  real_T c4_nhb_x;
  real_T c4_ohb_x;
  real_T c4_phb_x;
  real_T c4_vk_a;
  real_T c4_ul_b;
  real_T c4_tm_y;
  real_T c4_wk_a;
  real_T c4_vl_b;
  real_T c4_um_y;
  real_T c4_qhb_x;
  real_T c4_rhb_x;
  real_T c4_shb_x;
  real_T c4_thb_x;
  real_T c4_uhb_x;
  real_T c4_vhb_x;
  real_T c4_xk_a;
  real_T c4_wl_b;
  real_T c4_vm_y;
  real_T c4_whb_x;
  real_T c4_xhb_x;
  real_T c4_yhb_x;
  real_T c4_aib_x;
  real_T c4_yk_a;
  real_T c4_xl_b;
  real_T c4_wm_y;
  real_T c4_al_a;
  real_T c4_yl_b;
  real_T c4_xm_y;
  real_T c4_bl_a;
  real_T c4_am_b;
  real_T c4_ym_y;
  real_T c4_bib_x;
  real_T c4_cib_x;
  real_T c4_dib_x;
  real_T c4_eib_x;
  real_T c4_cl_a;
  real_T c4_bm_b;
  real_T c4_an_y;
  real_T c4_fib_x;
  real_T c4_gib_x;
  real_T c4_hib_x;
  real_T c4_iib_x;
  real_T c4_jib_x;
  real_T c4_kib_x;
  real_T c4_dl_a;
  real_T c4_cm_b;
  real_T c4_bn_y;
  real_T c4_lib_x;
  real_T c4_mib_x;
  real_T c4_nib_x;
  real_T c4_oib_x;
  real_T c4_el_a;
  real_T c4_dm_b;
  real_T c4_cn_y;
  real_T c4_fl_a;
  real_T c4_em_b;
  real_T c4_dn_y;
  real_T c4_pib_x;
  real_T c4_qib_x;
  real_T c4_rib_x;
  real_T c4_sib_x;
  real_T c4_tib_x;
  real_T c4_uib_x;
  real_T c4_gl_a;
  real_T c4_fm_b;
  real_T c4_en_y;
  real_T c4_vib_x;
  real_T c4_wib_x;
  real_T c4_xib_x;
  real_T c4_yib_x;
  real_T c4_hl_a;
  real_T c4_gm_b;
  real_T c4_fn_y;
  real_T c4_il_a;
  real_T c4_hm_b;
  real_T c4_gn_y;
  real_T c4_jl_a;
  real_T c4_im_b;
  real_T c4_hn_y;
  real_T c4_ajb_x;
  real_T c4_bjb_x;
  real_T c4_cjb_x;
  real_T c4_djb_x;
  real_T c4_ejb_x;
  real_T c4_fjb_x;
  real_T c4_gjb_x;
  real_T c4_hjb_x;
  real_T c4_kl_a;
  real_T c4_jm_b;
  real_T c4_in_y;
  real_T c4_ijb_x;
  real_T c4_jjb_x;
  real_T c4_kjb_x;
  real_T c4_ljb_x;
  real_T c4_ll_a;
  real_T c4_km_b;
  real_T c4_jn_y;
  real_T c4_ml_a;
  real_T c4_lm_b;
  real_T c4_kn_y;
  real_T c4_mjb_x;
  real_T c4_njb_x;
  real_T c4_ojb_x;
  real_T c4_pjb_x;
  real_T c4_qjb_x;
  real_T c4_rjb_x;
  real_T c4_nl_a;
  real_T c4_mm_b;
  real_T c4_ln_y;
  real_T c4_sjb_x;
  real_T c4_tjb_x;
  real_T c4_ujb_x;
  real_T c4_vjb_x;
  real_T c4_ol_a;
  real_T c4_nm_b;
  real_T c4_mn_y;
  real_T c4_pl_a;
  real_T c4_om_b;
  real_T c4_nn_y;
  real_T c4_ql_a;
  real_T c4_pm_b;
  real_T c4_on_y;
  real_T c4_wjb_x;
  real_T c4_xjb_x;
  real_T c4_yjb_x;
  real_T c4_akb_x;
  real_T c4_rl_a;
  real_T c4_qm_b;
  real_T c4_pn_y;
  real_T c4_bkb_x;
  real_T c4_ckb_x;
  real_T c4_dkb_x;
  real_T c4_ekb_x;
  real_T c4_fkb_x;
  real_T c4_gkb_x;
  real_T c4_sl_a;
  real_T c4_rm_b;
  real_T c4_qn_y;
  real_T c4_hkb_x;
  real_T c4_ikb_x;
  real_T c4_jkb_x;
  real_T c4_kkb_x;
  real_T c4_tl_a;
  real_T c4_sm_b;
  real_T c4_rn_y;
  real_T c4_ul_a;
  real_T c4_tm_b;
  real_T c4_sn_y;
  real_T c4_lkb_x;
  real_T c4_mkb_x;
  real_T c4_nkb_x;
  real_T c4_okb_x;
  real_T c4_pkb_x;
  real_T c4_qkb_x;
  real_T c4_vl_a;
  real_T c4_um_b;
  real_T c4_tn_y;
  real_T c4_rkb_x;
  real_T c4_skb_x;
  real_T c4_tkb_x;
  real_T c4_ukb_x;
  real_T c4_wl_a;
  real_T c4_vm_b;
  real_T c4_un_y;
  real_T c4_xl_a;
  real_T c4_wm_b;
  real_T c4_vn_y;
  real_T c4_yl_a;
  real_T c4_xm_b;
  real_T c4_wn_y;
  real_T c4_vkb_x;
  real_T c4_wkb_x;
  real_T c4_xkb_x;
  real_T c4_ykb_x;
  real_T c4_alb_x;
  real_T c4_blb_x;
  real_T c4_clb_x;
  real_T c4_dlb_x;
  real_T c4_am_a;
  real_T c4_ym_b;
  real_T c4_xn_y;
  real_T c4_elb_x;
  real_T c4_flb_x;
  real_T c4_glb_x;
  real_T c4_hlb_x;
  real_T c4_bm_a;
  real_T c4_an_b;
  real_T c4_yn_y;
  real_T c4_cm_a;
  real_T c4_bn_b;
  real_T c4_ao_y;
  real_T c4_ilb_x;
  real_T c4_jlb_x;
  real_T c4_klb_x;
  real_T c4_llb_x;
  real_T c4_mlb_x;
  real_T c4_nlb_x;
  real_T c4_dm_a;
  real_T c4_cn_b;
  real_T c4_bo_y;
  real_T c4_olb_x;
  real_T c4_plb_x;
  real_T c4_qlb_x;
  real_T c4_rlb_x;
  real_T c4_em_a;
  real_T c4_dn_b;
  real_T c4_co_y;
  real_T c4_fm_a;
  real_T c4_en_b;
  real_T c4_do_y;
  real_T c4_gm_a;
  real_T c4_fn_b;
  real_T c4_eo_y;
  real_T c4_slb_x;
  real_T c4_tlb_x;
  real_T c4_gn_b;
  real_T c4_fo_y;
  real_T c4_ulb_x;
  real_T c4_vlb_x;
  real_T c4_wlb_x;
  real_T c4_xlb_x;
  real_T c4_ylb_x;
  real_T c4_amb_x;
  real_T c4_hm_a;
  real_T c4_hn_b;
  real_T c4_go_y;
  real_T c4_bmb_x;
  real_T c4_cmb_x;
  real_T c4_dmb_x;
  real_T c4_emb_x;
  real_T c4_im_a;
  real_T c4_in_b;
  real_T c4_ho_y;
  real_T c4_jm_a;
  real_T c4_jn_b;
  real_T c4_io_y;
  real_T c4_fmb_x;
  real_T c4_gmb_x;
  real_T c4_hmb_x;
  real_T c4_imb_x;
  real_T c4_jmb_x;
  real_T c4_kmb_x;
  real_T c4_km_a;
  real_T c4_kn_b;
  real_T c4_jo_y;
  real_T c4_lmb_x;
  real_T c4_mmb_x;
  real_T c4_nmb_x;
  real_T c4_omb_x;
  real_T c4_lm_a;
  real_T c4_ln_b;
  real_T c4_ko_y;
  real_T c4_mm_a;
  real_T c4_mn_b;
  real_T c4_lo_y;
  real_T c4_nm_a;
  real_T c4_nn_b;
  real_T c4_mo_y;
  real_T c4_y_A;
  real_T c4_pmb_x;
  real_T c4_qmb_x;
  real_T c4_no_y;
  real_T c4_rmb_x;
  real_T c4_smb_x;
  real_T c4_on_b;
  real_T c4_oo_y;
  real_T c4_tmb_x;
  real_T c4_umb_x;
  real_T c4_om_a;
  real_T c4_pn_b;
  real_T c4_po_y;
  real_T c4_ab_A;
  real_T c4_vmb_x;
  real_T c4_wmb_x;
  real_T c4_qo_y;
  real_T c4_xmb_x;
  real_T c4_ymb_x;
  real_T c4_qn_b;
  real_T c4_ro_y;
  real_T c4_anb_x;
  real_T c4_bnb_x;
  real_T c4_pm_a;
  real_T c4_rn_b;
  real_T c4_so_y;
  real_T c4_bb_A;
  real_T c4_cnb_x;
  real_T c4_dnb_x;
  real_T c4_to_y;
  real_T c4_enb_x;
  real_T c4_fnb_x;
  real_T c4_sn_b;
  real_T c4_uo_y;
  real_T c4_cb_A;
  real_T c4_gnb_x;
  real_T c4_hnb_x;
  real_T c4_vo_y;
  real_T c4_inb_x;
  real_T c4_jnb_x;
  real_T c4_tn_b;
  real_T c4_wo_y;
  real_T c4_knb_x;
  real_T c4_lnb_x;
  real_T c4_mnb_x;
  real_T c4_nnb_x;
  real_T c4_onb_x;
  real_T c4_pnb_x;
  real_T c4_qm_a;
  real_T c4_un_b;
  real_T c4_xo_y;
  real_T c4_qnb_x;
  real_T c4_rnb_x;
  real_T c4_snb_x;
  real_T c4_tnb_x;
  real_T c4_rm_a;
  real_T c4_vn_b;
  real_T c4_yo_y;
  real_T c4_sm_a;
  real_T c4_wn_b;
  real_T c4_ap_y;
  real_T c4_unb_x;
  real_T c4_vnb_x;
  real_T c4_wnb_x;
  real_T c4_xnb_x;
  real_T c4_ynb_x;
  real_T c4_aob_x;
  real_T c4_tm_a;
  real_T c4_xn_b;
  real_T c4_bp_y;
  real_T c4_bob_x;
  real_T c4_cob_x;
  real_T c4_dob_x;
  real_T c4_eob_x;
  real_T c4_um_a;
  real_T c4_yn_b;
  real_T c4_cp_y;
  real_T c4_vm_a;
  real_T c4_ao_b;
  real_T c4_dp_y;
  real_T c4_wm_a;
  real_T c4_bo_b;
  real_T c4_ep_y;
  real_T c4_db_A;
  real_T c4_fob_x;
  real_T c4_gob_x;
  real_T c4_fp_y;
  real_T c4_hob_x;
  real_T c4_iob_x;
  real_T c4_co_b;
  real_T c4_gp_y;
  real_T c4_job_x;
  real_T c4_kob_x;
  real_T c4_lob_x;
  real_T c4_mob_x;
  real_T c4_nob_x;
  real_T c4_oob_x;
  real_T c4_xm_a;
  real_T c4_do_b;
  real_T c4_hp_y;
  real_T c4_pob_x;
  real_T c4_qob_x;
  real_T c4_rob_x;
  real_T c4_sob_x;
  real_T c4_ym_a;
  real_T c4_eo_b;
  real_T c4_ip_y;
  real_T c4_an_a;
  real_T c4_fo_b;
  real_T c4_jp_y;
  real_T c4_tob_x;
  real_T c4_uob_x;
  real_T c4_vob_x;
  real_T c4_wob_x;
  real_T c4_xob_x;
  real_T c4_yob_x;
  real_T c4_bn_a;
  real_T c4_go_b;
  real_T c4_kp_y;
  real_T c4_apb_x;
  real_T c4_bpb_x;
  real_T c4_cpb_x;
  real_T c4_dpb_x;
  real_T c4_cn_a;
  real_T c4_ho_b;
  real_T c4_lp_y;
  real_T c4_dn_a;
  real_T c4_io_b;
  real_T c4_mp_y;
  real_T c4_en_a;
  real_T c4_jo_b;
  real_T c4_np_y;
  real_T c4_eb_A;
  real_T c4_epb_x;
  real_T c4_fpb_x;
  real_T c4_op_y;
  real_T c4_gpb_x;
  real_T c4_hpb_x;
  real_T c4_ko_b;
  real_T c4_pp_y;
  real_T c4_ipb_x;
  real_T c4_jpb_x;
  real_T c4_kpb_x;
  real_T c4_lpb_x;
  real_T c4_fn_a;
  real_T c4_lo_b;
  real_T c4_qp_y;
  real_T c4_mpb_x;
  real_T c4_npb_x;
  real_T c4_opb_x;
  real_T c4_ppb_x;
  real_T c4_gn_a;
  real_T c4_mo_b;
  real_T c4_rp_y;
  real_T c4_hn_a;
  real_T c4_no_b;
  real_T c4_sp_y;
  real_T c4_fb_A;
  real_T c4_qpb_x;
  real_T c4_rpb_x;
  real_T c4_tp_y;
  real_T c4_spb_x;
  real_T c4_tpb_x;
  real_T c4_oo_b;
  real_T c4_up_y;
  real_T c4_upb_x;
  real_T c4_vpb_x;
  real_T c4_wpb_x;
  real_T c4_xpb_x;
  real_T c4_in_a;
  real_T c4_po_b;
  real_T c4_vp_y;
  real_T c4_ypb_x;
  real_T c4_aqb_x;
  real_T c4_bqb_x;
  real_T c4_cqb_x;
  real_T c4_jn_a;
  real_T c4_qo_b;
  real_T c4_wp_y;
  real_T c4_kn_a;
  real_T c4_ro_b;
  real_T c4_xp_y;
  real_T c4_gb_A;
  real_T c4_dqb_x;
  real_T c4_eqb_x;
  real_T c4_yp_y;
  real_T c4_fqb_x;
  real_T c4_gqb_x;
  real_T c4_so_b;
  real_T c4_aq_y;
  real_T c4_hqb_x;
  real_T c4_iqb_x;
  real_T c4_ln_a;
  real_T c4_to_b;
  real_T c4_bq_y;
  real_T c4_jqb_x;
  real_T c4_kqb_x;
  real_T c4_lqb_x;
  real_T c4_mqb_x;
  real_T c4_nqb_x;
  real_T c4_oqb_x;
  real_T c4_mn_a;
  real_T c4_uo_b;
  real_T c4_cq_y;
  real_T c4_pqb_x;
  real_T c4_qqb_x;
  real_T c4_rqb_x;
  real_T c4_sqb_x;
  real_T c4_nn_a;
  real_T c4_vo_b;
  real_T c4_dq_y;
  real_T c4_on_a;
  real_T c4_wo_b;
  real_T c4_eq_y;
  real_T c4_tqb_x;
  real_T c4_uqb_x;
  real_T c4_vqb_x;
  real_T c4_wqb_x;
  real_T c4_xqb_x;
  real_T c4_yqb_x;
  real_T c4_pn_a;
  real_T c4_xo_b;
  real_T c4_fq_y;
  real_T c4_arb_x;
  real_T c4_brb_x;
  real_T c4_crb_x;
  real_T c4_drb_x;
  real_T c4_qn_a;
  real_T c4_yo_b;
  real_T c4_gq_y;
  real_T c4_rn_a;
  real_T c4_ap_b;
  real_T c4_hq_y;
  real_T c4_sn_a;
  real_T c4_bp_b;
  real_T c4_iq_y;
  real_T c4_hb_A;
  real_T c4_erb_x;
  real_T c4_frb_x;
  real_T c4_jq_y;
  real_T c4_grb_x;
  real_T c4_hrb_x;
  real_T c4_cp_b;
  real_T c4_kq_y;
  real_T c4_irb_x;
  real_T c4_jrb_x;
  real_T c4_tn_a;
  real_T c4_dp_b;
  real_T c4_lq_y;
  real_T c4_krb_x;
  real_T c4_lrb_x;
  real_T c4_mrb_x;
  real_T c4_nrb_x;
  real_T c4_orb_x;
  real_T c4_prb_x;
  real_T c4_un_a;
  real_T c4_ep_b;
  real_T c4_mq_y;
  real_T c4_qrb_x;
  real_T c4_rrb_x;
  real_T c4_srb_x;
  real_T c4_trb_x;
  real_T c4_vn_a;
  real_T c4_fp_b;
  real_T c4_nq_y;
  real_T c4_wn_a;
  real_T c4_gp_b;
  real_T c4_oq_y;
  real_T c4_urb_x;
  real_T c4_vrb_x;
  real_T c4_wrb_x;
  real_T c4_xrb_x;
  real_T c4_yrb_x;
  real_T c4_asb_x;
  real_T c4_xn_a;
  real_T c4_hp_b;
  real_T c4_pq_y;
  real_T c4_bsb_x;
  real_T c4_csb_x;
  real_T c4_dsb_x;
  real_T c4_esb_x;
  real_T c4_yn_a;
  real_T c4_ip_b;
  real_T c4_qq_y;
  real_T c4_ao_a;
  real_T c4_jp_b;
  real_T c4_rq_y;
  real_T c4_bo_a;
  real_T c4_kp_b;
  real_T c4_sq_y;
  real_T c4_ib_A;
  real_T c4_fsb_x;
  real_T c4_gsb_x;
  real_T c4_tq_y;
  int32_T c4_i8;
  int32_T c4_i9;
  static real_T c4_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  real_T (*c4_b_d)[3];
  real_T (*c4_b_R)[9];
  real_T (*c4_b_q)[6];
  c4_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c4_b_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i7 = 0; c4_i7 < 6; c4_i7++) {
    c4_q[c4_i7] = (*c4_b_q)[c4_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta1, 0U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta2, 1U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta3, 2U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta4, 3U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta5, 4U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta6, 5U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta_1, 6U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta_2, 7U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta_3, 8U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta_4, 9U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta_5, 10U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta_6, 11U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_T, 12U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 13U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 14U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_q, 15U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_d, 16U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_R, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_theta1 = c4_q[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_theta2 = c4_q[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_theta3 = c4_q[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_theta4 = c4_q[3];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_theta5 = c4_q[4];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_theta6 = c4_q[5];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_theta_1 = c4_theta1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_theta_2 = c4_theta2;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_theta_3 = c4_theta3;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_theta_4 = c4_theta4;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_theta_5 = c4_theta5;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_theta_6 = c4_theta6;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  c4_x = c4_theta_6;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarCos(c4_b_x);
  c4_c_x = c4_theta_1;
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarSin(c4_d_x);
  c4_e_x = c4_theta_5;
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarSin(c4_f_x);
  c4_a = c4_d_x;
  c4_b = c4_f_x;
  c4_y = c4_a * c4_b;
  c4_g_x = c4_theta_5;
  c4_h_x = c4_g_x;
  c4_h_x = muDoubleScalarCos(c4_h_x);
  c4_i_x = c4_theta_4;
  c4_j_x = c4_i_x;
  c4_j_x = muDoubleScalarCos(c4_j_x);
  c4_k_x = c4_theta_1;
  c4_l_x = c4_k_x;
  c4_l_x = muDoubleScalarCos(c4_l_x);
  c4_m_x = c4_theta_2;
  c4_n_x = c4_m_x;
  c4_n_x = muDoubleScalarSin(c4_n_x);
  c4_b_a = c4_l_x;
  c4_b_b = c4_n_x;
  c4_b_y = c4_b_a * c4_b_b;
  c4_o_x = c4_theta_3;
  c4_p_x = c4_o_x;
  c4_p_x = muDoubleScalarSin(c4_p_x);
  c4_c_a = c4_b_y;
  c4_c_b = c4_p_x;
  c4_c_y = c4_c_a * c4_c_b;
  c4_q_x = c4_theta_1;
  c4_r_x = c4_q_x;
  c4_r_x = muDoubleScalarCos(c4_r_x);
  c4_s_x = c4_theta_2;
  c4_t_x = c4_s_x;
  c4_t_x = muDoubleScalarCos(c4_t_x);
  c4_d_a = c4_r_x;
  c4_d_b = c4_t_x;
  c4_d_y = c4_d_a * c4_d_b;
  c4_u_x = c4_theta_3;
  c4_v_x = c4_u_x;
  c4_v_x = muDoubleScalarCos(c4_v_x);
  c4_e_a = c4_d_y;
  c4_e_b = c4_v_x;
  c4_e_y = c4_e_a * c4_e_b;
  c4_f_a = c4_j_x;
  c4_f_b = c4_c_y - c4_e_y;
  c4_f_y = c4_f_a * c4_f_b;
  c4_w_x = c4_theta_4;
  c4_x_x = c4_w_x;
  c4_x_x = muDoubleScalarSin(c4_x_x);
  c4_y_x = c4_theta_1;
  c4_ab_x = c4_y_x;
  c4_ab_x = muDoubleScalarCos(c4_ab_x);
  c4_bb_x = c4_theta_2;
  c4_cb_x = c4_bb_x;
  c4_cb_x = muDoubleScalarCos(c4_cb_x);
  c4_g_a = c4_ab_x;
  c4_g_b = c4_cb_x;
  c4_g_y = c4_g_a * c4_g_b;
  c4_db_x = c4_theta_3;
  c4_eb_x = c4_db_x;
  c4_eb_x = muDoubleScalarSin(c4_eb_x);
  c4_h_a = c4_g_y;
  c4_h_b = c4_eb_x;
  c4_h_y = c4_h_a * c4_h_b;
  c4_fb_x = c4_theta_1;
  c4_gb_x = c4_fb_x;
  c4_gb_x = muDoubleScalarCos(c4_gb_x);
  c4_hb_x = c4_theta_3;
  c4_ib_x = c4_hb_x;
  c4_ib_x = muDoubleScalarCos(c4_ib_x);
  c4_i_a = c4_gb_x;
  c4_i_b = c4_ib_x;
  c4_i_y = c4_i_a * c4_i_b;
  c4_jb_x = c4_theta_2;
  c4_kb_x = c4_jb_x;
  c4_kb_x = muDoubleScalarSin(c4_kb_x);
  c4_j_a = c4_i_y;
  c4_j_b = c4_kb_x;
  c4_j_y = c4_j_a * c4_j_b;
  c4_k_a = c4_x_x;
  c4_k_b = c4_h_y + c4_j_y;
  c4_k_y = c4_k_a * c4_k_b;
  c4_l_a = c4_h_x;
  c4_l_b = c4_f_y + c4_k_y;
  c4_l_y = c4_l_a * c4_l_b;
  c4_m_a = c4_b_x;
  c4_m_b = c4_y - c4_l_y;
  c4_m_y = c4_m_a * c4_m_b;
  c4_lb_x = c4_theta_6;
  c4_mb_x = c4_lb_x;
  c4_mb_x = muDoubleScalarSin(c4_mb_x);
  c4_nb_x = c4_theta_4;
  c4_ob_x = c4_nb_x;
  c4_ob_x = muDoubleScalarCos(c4_ob_x);
  c4_pb_x = c4_theta_1;
  c4_qb_x = c4_pb_x;
  c4_qb_x = muDoubleScalarCos(c4_qb_x);
  c4_rb_x = c4_theta_2;
  c4_sb_x = c4_rb_x;
  c4_sb_x = muDoubleScalarCos(c4_sb_x);
  c4_n_a = c4_qb_x;
  c4_n_b = c4_sb_x;
  c4_n_y = c4_n_a * c4_n_b;
  c4_tb_x = c4_theta_3;
  c4_ub_x = c4_tb_x;
  c4_ub_x = muDoubleScalarSin(c4_ub_x);
  c4_o_a = c4_n_y;
  c4_o_b = c4_ub_x;
  c4_o_y = c4_o_a * c4_o_b;
  c4_vb_x = c4_theta_1;
  c4_wb_x = c4_vb_x;
  c4_wb_x = muDoubleScalarCos(c4_wb_x);
  c4_xb_x = c4_theta_3;
  c4_yb_x = c4_xb_x;
  c4_yb_x = muDoubleScalarCos(c4_yb_x);
  c4_p_a = c4_wb_x;
  c4_p_b = c4_yb_x;
  c4_p_y = c4_p_a * c4_p_b;
  c4_ac_x = c4_theta_2;
  c4_bc_x = c4_ac_x;
  c4_bc_x = muDoubleScalarSin(c4_bc_x);
  c4_q_a = c4_p_y;
  c4_q_b = c4_bc_x;
  c4_q_y = c4_q_a * c4_q_b;
  c4_r_a = c4_ob_x;
  c4_r_b = c4_o_y + c4_q_y;
  c4_r_y = c4_r_a * c4_r_b;
  c4_cc_x = c4_theta_4;
  c4_dc_x = c4_cc_x;
  c4_dc_x = muDoubleScalarSin(c4_dc_x);
  c4_ec_x = c4_theta_1;
  c4_fc_x = c4_ec_x;
  c4_fc_x = muDoubleScalarCos(c4_fc_x);
  c4_gc_x = c4_theta_2;
  c4_hc_x = c4_gc_x;
  c4_hc_x = muDoubleScalarSin(c4_hc_x);
  c4_s_a = c4_fc_x;
  c4_s_b = c4_hc_x;
  c4_s_y = c4_s_a * c4_s_b;
  c4_ic_x = c4_theta_3;
  c4_jc_x = c4_ic_x;
  c4_jc_x = muDoubleScalarSin(c4_jc_x);
  c4_t_a = c4_s_y;
  c4_t_b = c4_jc_x;
  c4_t_y = c4_t_a * c4_t_b;
  c4_kc_x = c4_theta_1;
  c4_lc_x = c4_kc_x;
  c4_lc_x = muDoubleScalarCos(c4_lc_x);
  c4_mc_x = c4_theta_2;
  c4_nc_x = c4_mc_x;
  c4_nc_x = muDoubleScalarCos(c4_nc_x);
  c4_u_a = c4_lc_x;
  c4_u_b = c4_nc_x;
  c4_u_y = c4_u_a * c4_u_b;
  c4_oc_x = c4_theta_3;
  c4_pc_x = c4_oc_x;
  c4_pc_x = muDoubleScalarCos(c4_pc_x);
  c4_v_a = c4_u_y;
  c4_v_b = c4_pc_x;
  c4_v_y = c4_v_a * c4_v_b;
  c4_w_a = c4_dc_x;
  c4_w_b = c4_t_y - c4_v_y;
  c4_w_y = c4_w_a * c4_w_b;
  c4_x_a = c4_mb_x;
  c4_x_b = c4_r_y - c4_w_y;
  c4_x_y = c4_x_a * c4_x_b;
  c4_qc_x = c4_theta_6;
  c4_rc_x = c4_qc_x;
  c4_rc_x = muDoubleScalarSin(c4_rc_x);
  c4_sc_x = c4_theta_1;
  c4_tc_x = c4_sc_x;
  c4_tc_x = muDoubleScalarSin(c4_tc_x);
  c4_uc_x = c4_theta_5;
  c4_vc_x = c4_uc_x;
  c4_vc_x = muDoubleScalarSin(c4_vc_x);
  c4_y_a = c4_tc_x;
  c4_y_b = c4_vc_x;
  c4_y_y = c4_y_a * c4_y_b;
  c4_wc_x = c4_theta_5;
  c4_xc_x = c4_wc_x;
  c4_xc_x = muDoubleScalarCos(c4_xc_x);
  c4_yc_x = c4_theta_4;
  c4_ad_x = c4_yc_x;
  c4_ad_x = muDoubleScalarCos(c4_ad_x);
  c4_bd_x = c4_theta_1;
  c4_cd_x = c4_bd_x;
  c4_cd_x = muDoubleScalarCos(c4_cd_x);
  c4_dd_x = c4_theta_2;
  c4_ed_x = c4_dd_x;
  c4_ed_x = muDoubleScalarSin(c4_ed_x);
  c4_ab_a = c4_cd_x;
  c4_ab_b = c4_ed_x;
  c4_ab_y = c4_ab_a * c4_ab_b;
  c4_fd_x = c4_theta_3;
  c4_gd_x = c4_fd_x;
  c4_gd_x = muDoubleScalarSin(c4_gd_x);
  c4_bb_a = c4_ab_y;
  c4_bb_b = c4_gd_x;
  c4_bb_y = c4_bb_a * c4_bb_b;
  c4_hd_x = c4_theta_1;
  c4_id_x = c4_hd_x;
  c4_id_x = muDoubleScalarCos(c4_id_x);
  c4_jd_x = c4_theta_2;
  c4_kd_x = c4_jd_x;
  c4_kd_x = muDoubleScalarCos(c4_kd_x);
  c4_cb_a = c4_id_x;
  c4_cb_b = c4_kd_x;
  c4_cb_y = c4_cb_a * c4_cb_b;
  c4_ld_x = c4_theta_3;
  c4_md_x = c4_ld_x;
  c4_md_x = muDoubleScalarCos(c4_md_x);
  c4_db_a = c4_cb_y;
  c4_db_b = c4_md_x;
  c4_db_y = c4_db_a * c4_db_b;
  c4_eb_a = c4_ad_x;
  c4_eb_b = c4_bb_y - c4_db_y;
  c4_eb_y = c4_eb_a * c4_eb_b;
  c4_nd_x = c4_theta_4;
  c4_od_x = c4_nd_x;
  c4_od_x = muDoubleScalarSin(c4_od_x);
  c4_pd_x = c4_theta_1;
  c4_qd_x = c4_pd_x;
  c4_qd_x = muDoubleScalarCos(c4_qd_x);
  c4_rd_x = c4_theta_2;
  c4_sd_x = c4_rd_x;
  c4_sd_x = muDoubleScalarCos(c4_sd_x);
  c4_fb_a = c4_qd_x;
  c4_fb_b = c4_sd_x;
  c4_fb_y = c4_fb_a * c4_fb_b;
  c4_td_x = c4_theta_3;
  c4_ud_x = c4_td_x;
  c4_ud_x = muDoubleScalarSin(c4_ud_x);
  c4_gb_a = c4_fb_y;
  c4_gb_b = c4_ud_x;
  c4_gb_y = c4_gb_a * c4_gb_b;
  c4_vd_x = c4_theta_1;
  c4_wd_x = c4_vd_x;
  c4_wd_x = muDoubleScalarCos(c4_wd_x);
  c4_xd_x = c4_theta_3;
  c4_yd_x = c4_xd_x;
  c4_yd_x = muDoubleScalarCos(c4_yd_x);
  c4_hb_a = c4_wd_x;
  c4_hb_b = c4_yd_x;
  c4_hb_y = c4_hb_a * c4_hb_b;
  c4_ae_x = c4_theta_2;
  c4_be_x = c4_ae_x;
  c4_be_x = muDoubleScalarSin(c4_be_x);
  c4_ib_a = c4_hb_y;
  c4_ib_b = c4_be_x;
  c4_ib_y = c4_ib_a * c4_ib_b;
  c4_jb_a = c4_od_x;
  c4_jb_b = c4_gb_y + c4_ib_y;
  c4_jb_y = c4_jb_a * c4_jb_b;
  c4_kb_a = c4_xc_x;
  c4_kb_b = c4_eb_y + c4_jb_y;
  c4_kb_y = c4_kb_a * c4_kb_b;
  c4_lb_a = -c4_rc_x;
  c4_lb_b = c4_y_y - c4_kb_y;
  c4_lb_y = c4_lb_a * c4_lb_b;
  c4_ce_x = c4_theta_6;
  c4_de_x = c4_ce_x;
  c4_de_x = muDoubleScalarCos(c4_de_x);
  c4_ee_x = c4_theta_4;
  c4_fe_x = c4_ee_x;
  c4_fe_x = muDoubleScalarCos(c4_fe_x);
  c4_ge_x = c4_theta_1;
  c4_he_x = c4_ge_x;
  c4_he_x = muDoubleScalarCos(c4_he_x);
  c4_ie_x = c4_theta_2;
  c4_je_x = c4_ie_x;
  c4_je_x = muDoubleScalarCos(c4_je_x);
  c4_mb_a = c4_he_x;
  c4_mb_b = c4_je_x;
  c4_mb_y = c4_mb_a * c4_mb_b;
  c4_ke_x = c4_theta_3;
  c4_le_x = c4_ke_x;
  c4_le_x = muDoubleScalarSin(c4_le_x);
  c4_nb_a = c4_mb_y;
  c4_nb_b = c4_le_x;
  c4_nb_y = c4_nb_a * c4_nb_b;
  c4_me_x = c4_theta_1;
  c4_ne_x = c4_me_x;
  c4_ne_x = muDoubleScalarCos(c4_ne_x);
  c4_oe_x = c4_theta_3;
  c4_pe_x = c4_oe_x;
  c4_pe_x = muDoubleScalarCos(c4_pe_x);
  c4_ob_a = c4_ne_x;
  c4_ob_b = c4_pe_x;
  c4_ob_y = c4_ob_a * c4_ob_b;
  c4_qe_x = c4_theta_2;
  c4_re_x = c4_qe_x;
  c4_re_x = muDoubleScalarSin(c4_re_x);
  c4_pb_a = c4_ob_y;
  c4_pb_b = c4_re_x;
  c4_pb_y = c4_pb_a * c4_pb_b;
  c4_qb_a = c4_fe_x;
  c4_qb_b = c4_nb_y + c4_pb_y;
  c4_qb_y = c4_qb_a * c4_qb_b;
  c4_se_x = c4_theta_4;
  c4_te_x = c4_se_x;
  c4_te_x = muDoubleScalarSin(c4_te_x);
  c4_ue_x = c4_theta_1;
  c4_ve_x = c4_ue_x;
  c4_ve_x = muDoubleScalarCos(c4_ve_x);
  c4_we_x = c4_theta_2;
  c4_xe_x = c4_we_x;
  c4_xe_x = muDoubleScalarSin(c4_xe_x);
  c4_rb_a = c4_ve_x;
  c4_rb_b = c4_xe_x;
  c4_rb_y = c4_rb_a * c4_rb_b;
  c4_ye_x = c4_theta_3;
  c4_af_x = c4_ye_x;
  c4_af_x = muDoubleScalarSin(c4_af_x);
  c4_sb_a = c4_rb_y;
  c4_sb_b = c4_af_x;
  c4_sb_y = c4_sb_a * c4_sb_b;
  c4_bf_x = c4_theta_1;
  c4_cf_x = c4_bf_x;
  c4_cf_x = muDoubleScalarCos(c4_cf_x);
  c4_df_x = c4_theta_2;
  c4_ef_x = c4_df_x;
  c4_ef_x = muDoubleScalarCos(c4_ef_x);
  c4_tb_a = c4_cf_x;
  c4_tb_b = c4_ef_x;
  c4_tb_y = c4_tb_a * c4_tb_b;
  c4_ff_x = c4_theta_3;
  c4_gf_x = c4_ff_x;
  c4_gf_x = muDoubleScalarCos(c4_gf_x);
  c4_ub_a = c4_tb_y;
  c4_ub_b = c4_gf_x;
  c4_ub_y = c4_ub_a * c4_ub_b;
  c4_vb_a = c4_te_x;
  c4_vb_b = c4_sb_y - c4_ub_y;
  c4_vb_y = c4_vb_a * c4_vb_b;
  c4_wb_a = c4_de_x;
  c4_wb_b = c4_qb_y - c4_vb_y;
  c4_wb_y = c4_wb_a * c4_wb_b;
  c4_hf_x = c4_theta_5;
  c4_if_x = c4_hf_x;
  c4_if_x = muDoubleScalarCos(c4_if_x);
  c4_jf_x = c4_theta_1;
  c4_kf_x = c4_jf_x;
  c4_kf_x = muDoubleScalarSin(c4_kf_x);
  c4_xb_a = c4_if_x;
  c4_xb_b = c4_kf_x;
  c4_xb_y = c4_xb_a * c4_xb_b;
  c4_lf_x = c4_theta_5;
  c4_mf_x = c4_lf_x;
  c4_mf_x = muDoubleScalarSin(c4_mf_x);
  c4_nf_x = c4_theta_4;
  c4_of_x = c4_nf_x;
  c4_of_x = muDoubleScalarCos(c4_of_x);
  c4_pf_x = c4_theta_1;
  c4_qf_x = c4_pf_x;
  c4_qf_x = muDoubleScalarCos(c4_qf_x);
  c4_rf_x = c4_theta_2;
  c4_sf_x = c4_rf_x;
  c4_sf_x = muDoubleScalarSin(c4_sf_x);
  c4_yb_a = c4_qf_x;
  c4_yb_b = c4_sf_x;
  c4_yb_y = c4_yb_a * c4_yb_b;
  c4_tf_x = c4_theta_3;
  c4_uf_x = c4_tf_x;
  c4_uf_x = muDoubleScalarSin(c4_uf_x);
  c4_ac_a = c4_yb_y;
  c4_ac_b = c4_uf_x;
  c4_ac_y = c4_ac_a * c4_ac_b;
  c4_vf_x = c4_theta_1;
  c4_wf_x = c4_vf_x;
  c4_wf_x = muDoubleScalarCos(c4_wf_x);
  c4_xf_x = c4_theta_2;
  c4_yf_x = c4_xf_x;
  c4_yf_x = muDoubleScalarCos(c4_yf_x);
  c4_bc_a = c4_wf_x;
  c4_bc_b = c4_yf_x;
  c4_bc_y = c4_bc_a * c4_bc_b;
  c4_ag_x = c4_theta_3;
  c4_bg_x = c4_ag_x;
  c4_bg_x = muDoubleScalarCos(c4_bg_x);
  c4_cc_a = c4_bc_y;
  c4_cc_b = c4_bg_x;
  c4_cc_y = c4_cc_a * c4_cc_b;
  c4_dc_a = c4_of_x;
  c4_dc_b = c4_ac_y - c4_cc_y;
  c4_dc_y = c4_dc_a * c4_dc_b;
  c4_cg_x = c4_theta_4;
  c4_dg_x = c4_cg_x;
  c4_dg_x = muDoubleScalarSin(c4_dg_x);
  c4_eg_x = c4_theta_1;
  c4_fg_x = c4_eg_x;
  c4_fg_x = muDoubleScalarCos(c4_fg_x);
  c4_gg_x = c4_theta_2;
  c4_hg_x = c4_gg_x;
  c4_hg_x = muDoubleScalarCos(c4_hg_x);
  c4_ec_a = c4_fg_x;
  c4_ec_b = c4_hg_x;
  c4_ec_y = c4_ec_a * c4_ec_b;
  c4_ig_x = c4_theta_3;
  c4_jg_x = c4_ig_x;
  c4_jg_x = muDoubleScalarSin(c4_jg_x);
  c4_fc_a = c4_ec_y;
  c4_fc_b = c4_jg_x;
  c4_fc_y = c4_fc_a * c4_fc_b;
  c4_kg_x = c4_theta_1;
  c4_lg_x = c4_kg_x;
  c4_lg_x = muDoubleScalarCos(c4_lg_x);
  c4_mg_x = c4_theta_3;
  c4_ng_x = c4_mg_x;
  c4_ng_x = muDoubleScalarCos(c4_ng_x);
  c4_gc_a = c4_lg_x;
  c4_gc_b = c4_ng_x;
  c4_gc_y = c4_gc_a * c4_gc_b;
  c4_og_x = c4_theta_2;
  c4_pg_x = c4_og_x;
  c4_pg_x = muDoubleScalarSin(c4_pg_x);
  c4_hc_a = c4_gc_y;
  c4_hc_b = c4_pg_x;
  c4_hc_y = c4_hc_a * c4_hc_b;
  c4_ic_a = c4_dg_x;
  c4_ic_b = c4_fc_y + c4_hc_y;
  c4_ic_y = c4_ic_a * c4_ic_b;
  c4_jc_a = c4_mf_x;
  c4_jc_b = c4_dc_y + c4_ic_y;
  c4_jc_y = c4_jc_a * c4_jc_b;
  c4_qg_x = c4_theta_1;
  c4_rg_x = c4_qg_x;
  c4_rg_x = muDoubleScalarSin(c4_rg_x);
  c4_kc_b = c4_rg_x;
  c4_kc_y = 109.0 * c4_kc_b;
  c4_A = c4_kc_y;
  c4_sg_x = c4_A;
  c4_tg_x = c4_sg_x;
  c4_lc_y = c4_tg_x / 1000.0;
  c4_ug_x = c4_theta_1;
  c4_vg_x = c4_ug_x;
  c4_vg_x = muDoubleScalarCos(c4_vg_x);
  c4_lc_b = c4_vg_x;
  c4_mc_y = 17.0 * c4_lc_b;
  c4_wg_x = c4_theta_2;
  c4_xg_x = c4_wg_x;
  c4_xg_x = muDoubleScalarCos(c4_xg_x);
  c4_kc_a = c4_mc_y;
  c4_mc_b = c4_xg_x;
  c4_nc_y = c4_kc_a * c4_mc_b;
  c4_b_A = c4_nc_y;
  c4_yg_x = c4_b_A;
  c4_ah_x = c4_yg_x;
  c4_oc_y = c4_ah_x / 40.0;
  c4_bh_x = c4_theta_5;
  c4_ch_x = c4_bh_x;
  c4_ch_x = muDoubleScalarCos(c4_ch_x);
  c4_nc_b = c4_ch_x;
  c4_pc_y = 183.0 * c4_nc_b;
  c4_dh_x = c4_theta_1;
  c4_eh_x = c4_dh_x;
  c4_eh_x = muDoubleScalarSin(c4_eh_x);
  c4_lc_a = c4_pc_y;
  c4_oc_b = c4_eh_x;
  c4_qc_y = c4_lc_a * c4_oc_b;
  c4_c_A = c4_qc_y;
  c4_fh_x = c4_c_A;
  c4_gh_x = c4_fh_x;
  c4_rc_y = c4_gh_x / 2000.0;
  c4_hh_x = c4_theta_6;
  c4_ih_x = c4_hh_x;
  c4_ih_x = muDoubleScalarCos(c4_ih_x);
  c4_pc_b = c4_ih_x;
  c4_sc_y = 347.0 * c4_pc_b;
  c4_jh_x = c4_theta_1;
  c4_kh_x = c4_jh_x;
  c4_kh_x = muDoubleScalarSin(c4_kh_x);
  c4_lh_x = c4_theta_5;
  c4_mh_x = c4_lh_x;
  c4_mh_x = muDoubleScalarSin(c4_mh_x);
  c4_mc_a = c4_kh_x;
  c4_qc_b = c4_mh_x;
  c4_tc_y = c4_mc_a * c4_qc_b;
  c4_nh_x = c4_theta_5;
  c4_oh_x = c4_nh_x;
  c4_oh_x = muDoubleScalarCos(c4_oh_x);
  c4_ph_x = c4_theta_4;
  c4_qh_x = c4_ph_x;
  c4_qh_x = muDoubleScalarCos(c4_qh_x);
  c4_rh_x = c4_theta_1;
  c4_sh_x = c4_rh_x;
  c4_sh_x = muDoubleScalarCos(c4_sh_x);
  c4_th_x = c4_theta_2;
  c4_uh_x = c4_th_x;
  c4_uh_x = muDoubleScalarSin(c4_uh_x);
  c4_nc_a = c4_sh_x;
  c4_rc_b = c4_uh_x;
  c4_uc_y = c4_nc_a * c4_rc_b;
  c4_vh_x = c4_theta_3;
  c4_wh_x = c4_vh_x;
  c4_wh_x = muDoubleScalarSin(c4_wh_x);
  c4_oc_a = c4_uc_y;
  c4_sc_b = c4_wh_x;
  c4_vc_y = c4_oc_a * c4_sc_b;
  c4_xh_x = c4_theta_1;
  c4_yh_x = c4_xh_x;
  c4_yh_x = muDoubleScalarCos(c4_yh_x);
  c4_ai_x = c4_theta_2;
  c4_bi_x = c4_ai_x;
  c4_bi_x = muDoubleScalarCos(c4_bi_x);
  c4_pc_a = c4_yh_x;
  c4_tc_b = c4_bi_x;
  c4_wc_y = c4_pc_a * c4_tc_b;
  c4_ci_x = c4_theta_3;
  c4_di_x = c4_ci_x;
  c4_di_x = muDoubleScalarCos(c4_di_x);
  c4_qc_a = c4_wc_y;
  c4_uc_b = c4_di_x;
  c4_xc_y = c4_qc_a * c4_uc_b;
  c4_rc_a = c4_qh_x;
  c4_vc_b = c4_vc_y - c4_xc_y;
  c4_yc_y = c4_rc_a * c4_vc_b;
  c4_ei_x = c4_theta_4;
  c4_fi_x = c4_ei_x;
  c4_fi_x = muDoubleScalarSin(c4_fi_x);
  c4_gi_x = c4_theta_1;
  c4_hi_x = c4_gi_x;
  c4_hi_x = muDoubleScalarCos(c4_hi_x);
  c4_ii_x = c4_theta_2;
  c4_ji_x = c4_ii_x;
  c4_ji_x = muDoubleScalarCos(c4_ji_x);
  c4_sc_a = c4_hi_x;
  c4_wc_b = c4_ji_x;
  c4_ad_y = c4_sc_a * c4_wc_b;
  c4_ki_x = c4_theta_3;
  c4_li_x = c4_ki_x;
  c4_li_x = muDoubleScalarSin(c4_li_x);
  c4_tc_a = c4_ad_y;
  c4_xc_b = c4_li_x;
  c4_bd_y = c4_tc_a * c4_xc_b;
  c4_mi_x = c4_theta_1;
  c4_ni_x = c4_mi_x;
  c4_ni_x = muDoubleScalarCos(c4_ni_x);
  c4_oi_x = c4_theta_3;
  c4_pi_x = c4_oi_x;
  c4_pi_x = muDoubleScalarCos(c4_pi_x);
  c4_uc_a = c4_ni_x;
  c4_yc_b = c4_pi_x;
  c4_cd_y = c4_uc_a * c4_yc_b;
  c4_qi_x = c4_theta_2;
  c4_ri_x = c4_qi_x;
  c4_ri_x = muDoubleScalarSin(c4_ri_x);
  c4_vc_a = c4_cd_y;
  c4_ad_b = c4_ri_x;
  c4_dd_y = c4_vc_a * c4_ad_b;
  c4_wc_a = c4_fi_x;
  c4_bd_b = c4_bd_y + c4_dd_y;
  c4_ed_y = c4_wc_a * c4_bd_b;
  c4_xc_a = c4_oh_x;
  c4_cd_b = c4_yc_y + c4_ed_y;
  c4_fd_y = c4_xc_a * c4_cd_b;
  c4_yc_a = c4_sc_y;
  c4_dd_b = c4_tc_y - c4_fd_y;
  c4_gd_y = c4_yc_a * c4_dd_b;
  c4_d_A = c4_gd_y;
  c4_si_x = c4_d_A;
  c4_ti_x = c4_si_x;
  c4_hd_y = c4_ti_x / 20000.0;
  c4_ui_x = c4_theta_4;
  c4_vi_x = c4_ui_x;
  c4_vi_x = muDoubleScalarCos(c4_vi_x);
  c4_ed_b = c4_vi_x;
  c4_id_y = 93.0 * c4_ed_b;
  c4_wi_x = c4_theta_1;
  c4_xi_x = c4_wi_x;
  c4_xi_x = muDoubleScalarCos(c4_xi_x);
  c4_yi_x = c4_theta_2;
  c4_aj_x = c4_yi_x;
  c4_aj_x = muDoubleScalarCos(c4_aj_x);
  c4_ad_a = c4_xi_x;
  c4_fd_b = c4_aj_x;
  c4_jd_y = c4_ad_a * c4_fd_b;
  c4_bj_x = c4_theta_3;
  c4_cj_x = c4_bj_x;
  c4_cj_x = muDoubleScalarSin(c4_cj_x);
  c4_bd_a = c4_jd_y;
  c4_gd_b = c4_cj_x;
  c4_kd_y = c4_bd_a * c4_gd_b;
  c4_dj_x = c4_theta_1;
  c4_ej_x = c4_dj_x;
  c4_ej_x = muDoubleScalarCos(c4_ej_x);
  c4_fj_x = c4_theta_3;
  c4_gj_x = c4_fj_x;
  c4_gj_x = muDoubleScalarCos(c4_gj_x);
  c4_cd_a = c4_ej_x;
  c4_hd_b = c4_gj_x;
  c4_ld_y = c4_cd_a * c4_hd_b;
  c4_hj_x = c4_theta_2;
  c4_ij_x = c4_hj_x;
  c4_ij_x = muDoubleScalarSin(c4_ij_x);
  c4_dd_a = c4_ld_y;
  c4_id_b = c4_ij_x;
  c4_md_y = c4_dd_a * c4_id_b;
  c4_ed_a = c4_id_y;
  c4_jd_b = c4_kd_y + c4_md_y;
  c4_nd_y = c4_ed_a * c4_jd_b;
  c4_e_A = c4_nd_y;
  c4_jj_x = c4_e_A;
  c4_kj_x = c4_jj_x;
  c4_od_y = c4_kj_x / 1000.0;
  c4_lj_x = c4_theta_6;
  c4_mj_x = c4_lj_x;
  c4_mj_x = muDoubleScalarSin(c4_mj_x);
  c4_kd_b = c4_mj_x;
  c4_pd_y = 121.0 * c4_kd_b;
  c4_nj_x = c4_theta_1;
  c4_oj_x = c4_nj_x;
  c4_oj_x = muDoubleScalarSin(c4_oj_x);
  c4_pj_x = c4_theta_5;
  c4_qj_x = c4_pj_x;
  c4_qj_x = muDoubleScalarSin(c4_qj_x);
  c4_fd_a = c4_oj_x;
  c4_ld_b = c4_qj_x;
  c4_qd_y = c4_fd_a * c4_ld_b;
  c4_rj_x = c4_theta_5;
  c4_sj_x = c4_rj_x;
  c4_sj_x = muDoubleScalarCos(c4_sj_x);
  c4_tj_x = c4_theta_4;
  c4_uj_x = c4_tj_x;
  c4_uj_x = muDoubleScalarCos(c4_uj_x);
  c4_vj_x = c4_theta_1;
  c4_wj_x = c4_vj_x;
  c4_wj_x = muDoubleScalarCos(c4_wj_x);
  c4_xj_x = c4_theta_2;
  c4_yj_x = c4_xj_x;
  c4_yj_x = muDoubleScalarSin(c4_yj_x);
  c4_gd_a = c4_wj_x;
  c4_md_b = c4_yj_x;
  c4_rd_y = c4_gd_a * c4_md_b;
  c4_ak_x = c4_theta_3;
  c4_bk_x = c4_ak_x;
  c4_bk_x = muDoubleScalarSin(c4_bk_x);
  c4_hd_a = c4_rd_y;
  c4_nd_b = c4_bk_x;
  c4_sd_y = c4_hd_a * c4_nd_b;
  c4_ck_x = c4_theta_1;
  c4_dk_x = c4_ck_x;
  c4_dk_x = muDoubleScalarCos(c4_dk_x);
  c4_ek_x = c4_theta_2;
  c4_fk_x = c4_ek_x;
  c4_fk_x = muDoubleScalarCos(c4_fk_x);
  c4_id_a = c4_dk_x;
  c4_od_b = c4_fk_x;
  c4_td_y = c4_id_a * c4_od_b;
  c4_gk_x = c4_theta_3;
  c4_hk_x = c4_gk_x;
  c4_hk_x = muDoubleScalarCos(c4_hk_x);
  c4_jd_a = c4_td_y;
  c4_pd_b = c4_hk_x;
  c4_ud_y = c4_jd_a * c4_pd_b;
  c4_kd_a = c4_uj_x;
  c4_qd_b = c4_sd_y - c4_ud_y;
  c4_vd_y = c4_kd_a * c4_qd_b;
  c4_ik_x = c4_theta_4;
  c4_jk_x = c4_ik_x;
  c4_jk_x = muDoubleScalarSin(c4_jk_x);
  c4_kk_x = c4_theta_1;
  c4_lk_x = c4_kk_x;
  c4_lk_x = muDoubleScalarCos(c4_lk_x);
  c4_mk_x = c4_theta_2;
  c4_nk_x = c4_mk_x;
  c4_nk_x = muDoubleScalarCos(c4_nk_x);
  c4_ld_a = c4_lk_x;
  c4_rd_b = c4_nk_x;
  c4_wd_y = c4_ld_a * c4_rd_b;
  c4_ok_x = c4_theta_3;
  c4_pk_x = c4_ok_x;
  c4_pk_x = muDoubleScalarSin(c4_pk_x);
  c4_md_a = c4_wd_y;
  c4_sd_b = c4_pk_x;
  c4_xd_y = c4_md_a * c4_sd_b;
  c4_qk_x = c4_theta_1;
  c4_rk_x = c4_qk_x;
  c4_rk_x = muDoubleScalarCos(c4_rk_x);
  c4_sk_x = c4_theta_3;
  c4_tk_x = c4_sk_x;
  c4_tk_x = muDoubleScalarCos(c4_tk_x);
  c4_nd_a = c4_rk_x;
  c4_td_b = c4_tk_x;
  c4_yd_y = c4_nd_a * c4_td_b;
  c4_uk_x = c4_theta_2;
  c4_vk_x = c4_uk_x;
  c4_vk_x = muDoubleScalarSin(c4_vk_x);
  c4_od_a = c4_yd_y;
  c4_ud_b = c4_vk_x;
  c4_ae_y = c4_od_a * c4_ud_b;
  c4_pd_a = c4_jk_x;
  c4_vd_b = c4_xd_y + c4_ae_y;
  c4_be_y = c4_pd_a * c4_vd_b;
  c4_qd_a = c4_sj_x;
  c4_wd_b = c4_vd_y + c4_be_y;
  c4_ce_y = c4_qd_a * c4_wd_b;
  c4_rd_a = c4_pd_y;
  c4_xd_b = c4_qd_y - c4_ce_y;
  c4_de_y = c4_rd_a * c4_xd_b;
  c4_f_A = c4_de_y;
  c4_wk_x = c4_f_A;
  c4_xk_x = c4_wk_x;
  c4_ee_y = c4_xk_x / 20000.0;
  c4_yk_x = c4_theta_4;
  c4_al_x = c4_yk_x;
  c4_al_x = muDoubleScalarSin(c4_al_x);
  c4_yd_b = c4_al_x;
  c4_fe_y = 93.0 * c4_yd_b;
  c4_bl_x = c4_theta_1;
  c4_cl_x = c4_bl_x;
  c4_cl_x = muDoubleScalarCos(c4_cl_x);
  c4_dl_x = c4_theta_2;
  c4_el_x = c4_dl_x;
  c4_el_x = muDoubleScalarSin(c4_el_x);
  c4_sd_a = c4_cl_x;
  c4_ae_b = c4_el_x;
  c4_ge_y = c4_sd_a * c4_ae_b;
  c4_fl_x = c4_theta_3;
  c4_gl_x = c4_fl_x;
  c4_gl_x = muDoubleScalarSin(c4_gl_x);
  c4_td_a = c4_ge_y;
  c4_be_b = c4_gl_x;
  c4_he_y = c4_td_a * c4_be_b;
  c4_hl_x = c4_theta_1;
  c4_il_x = c4_hl_x;
  c4_il_x = muDoubleScalarCos(c4_il_x);
  c4_jl_x = c4_theta_2;
  c4_kl_x = c4_jl_x;
  c4_kl_x = muDoubleScalarCos(c4_kl_x);
  c4_ud_a = c4_il_x;
  c4_ce_b = c4_kl_x;
  c4_ie_y = c4_ud_a * c4_ce_b;
  c4_ll_x = c4_theta_3;
  c4_ml_x = c4_ll_x;
  c4_ml_x = muDoubleScalarCos(c4_ml_x);
  c4_vd_a = c4_ie_y;
  c4_de_b = c4_ml_x;
  c4_je_y = c4_vd_a * c4_de_b;
  c4_wd_a = c4_fe_y;
  c4_ee_b = c4_he_y - c4_je_y;
  c4_ke_y = c4_wd_a * c4_ee_b;
  c4_g_A = c4_ke_y;
  c4_nl_x = c4_g_A;
  c4_ol_x = c4_nl_x;
  c4_le_y = c4_ol_x / 1000.0;
  c4_pl_x = c4_theta_6;
  c4_ql_x = c4_pl_x;
  c4_ql_x = muDoubleScalarCos(c4_ql_x);
  c4_fe_b = c4_ql_x;
  c4_me_y = 121.0 * c4_fe_b;
  c4_rl_x = c4_theta_4;
  c4_sl_x = c4_rl_x;
  c4_sl_x = muDoubleScalarCos(c4_sl_x);
  c4_tl_x = c4_theta_1;
  c4_ul_x = c4_tl_x;
  c4_ul_x = muDoubleScalarCos(c4_ul_x);
  c4_vl_x = c4_theta_2;
  c4_wl_x = c4_vl_x;
  c4_wl_x = muDoubleScalarCos(c4_wl_x);
  c4_xd_a = c4_ul_x;
  c4_ge_b = c4_wl_x;
  c4_ne_y = c4_xd_a * c4_ge_b;
  c4_xl_x = c4_theta_3;
  c4_yl_x = c4_xl_x;
  c4_yl_x = muDoubleScalarSin(c4_yl_x);
  c4_yd_a = c4_ne_y;
  c4_he_b = c4_yl_x;
  c4_oe_y = c4_yd_a * c4_he_b;
  c4_am_x = c4_theta_1;
  c4_bm_x = c4_am_x;
  c4_bm_x = muDoubleScalarCos(c4_bm_x);
  c4_cm_x = c4_theta_3;
  c4_dm_x = c4_cm_x;
  c4_dm_x = muDoubleScalarCos(c4_dm_x);
  c4_ae_a = c4_bm_x;
  c4_ie_b = c4_dm_x;
  c4_pe_y = c4_ae_a * c4_ie_b;
  c4_em_x = c4_theta_2;
  c4_fm_x = c4_em_x;
  c4_fm_x = muDoubleScalarSin(c4_fm_x);
  c4_be_a = c4_pe_y;
  c4_je_b = c4_fm_x;
  c4_qe_y = c4_be_a * c4_je_b;
  c4_ce_a = c4_sl_x;
  c4_ke_b = c4_oe_y + c4_qe_y;
  c4_re_y = c4_ce_a * c4_ke_b;
  c4_gm_x = c4_theta_4;
  c4_hm_x = c4_gm_x;
  c4_hm_x = muDoubleScalarSin(c4_hm_x);
  c4_im_x = c4_theta_1;
  c4_jm_x = c4_im_x;
  c4_jm_x = muDoubleScalarCos(c4_jm_x);
  c4_km_x = c4_theta_2;
  c4_lm_x = c4_km_x;
  c4_lm_x = muDoubleScalarSin(c4_lm_x);
  c4_de_a = c4_jm_x;
  c4_le_b = c4_lm_x;
  c4_se_y = c4_de_a * c4_le_b;
  c4_mm_x = c4_theta_3;
  c4_nm_x = c4_mm_x;
  c4_nm_x = muDoubleScalarSin(c4_nm_x);
  c4_ee_a = c4_se_y;
  c4_me_b = c4_nm_x;
  c4_te_y = c4_ee_a * c4_me_b;
  c4_om_x = c4_theta_1;
  c4_pm_x = c4_om_x;
  c4_pm_x = muDoubleScalarCos(c4_pm_x);
  c4_qm_x = c4_theta_2;
  c4_rm_x = c4_qm_x;
  c4_rm_x = muDoubleScalarCos(c4_rm_x);
  c4_fe_a = c4_pm_x;
  c4_ne_b = c4_rm_x;
  c4_ue_y = c4_fe_a * c4_ne_b;
  c4_sm_x = c4_theta_3;
  c4_tm_x = c4_sm_x;
  c4_tm_x = muDoubleScalarCos(c4_tm_x);
  c4_ge_a = c4_ue_y;
  c4_oe_b = c4_tm_x;
  c4_ve_y = c4_ge_a * c4_oe_b;
  c4_he_a = c4_hm_x;
  c4_pe_b = c4_te_y - c4_ve_y;
  c4_we_y = c4_he_a * c4_pe_b;
  c4_ie_a = c4_me_y;
  c4_qe_b = c4_re_y - c4_we_y;
  c4_xe_y = c4_ie_a * c4_qe_b;
  c4_h_A = c4_xe_y;
  c4_um_x = c4_h_A;
  c4_vm_x = c4_um_x;
  c4_ye_y = c4_vm_x / 20000.0;
  c4_wm_x = c4_theta_5;
  c4_xm_x = c4_wm_x;
  c4_xm_x = muDoubleScalarSin(c4_xm_x);
  c4_re_b = c4_xm_x;
  c4_af_y = 183.0 * c4_re_b;
  c4_ym_x = c4_theta_4;
  c4_an_x = c4_ym_x;
  c4_an_x = muDoubleScalarCos(c4_an_x);
  c4_bn_x = c4_theta_1;
  c4_cn_x = c4_bn_x;
  c4_cn_x = muDoubleScalarCos(c4_cn_x);
  c4_dn_x = c4_theta_2;
  c4_en_x = c4_dn_x;
  c4_en_x = muDoubleScalarSin(c4_en_x);
  c4_je_a = c4_cn_x;
  c4_se_b = c4_en_x;
  c4_bf_y = c4_je_a * c4_se_b;
  c4_fn_x = c4_theta_3;
  c4_gn_x = c4_fn_x;
  c4_gn_x = muDoubleScalarSin(c4_gn_x);
  c4_ke_a = c4_bf_y;
  c4_te_b = c4_gn_x;
  c4_cf_y = c4_ke_a * c4_te_b;
  c4_hn_x = c4_theta_1;
  c4_in_x = c4_hn_x;
  c4_in_x = muDoubleScalarCos(c4_in_x);
  c4_jn_x = c4_theta_2;
  c4_kn_x = c4_jn_x;
  c4_kn_x = muDoubleScalarCos(c4_kn_x);
  c4_le_a = c4_in_x;
  c4_ue_b = c4_kn_x;
  c4_df_y = c4_le_a * c4_ue_b;
  c4_ln_x = c4_theta_3;
  c4_mn_x = c4_ln_x;
  c4_mn_x = muDoubleScalarCos(c4_mn_x);
  c4_me_a = c4_df_y;
  c4_ve_b = c4_mn_x;
  c4_ef_y = c4_me_a * c4_ve_b;
  c4_ne_a = c4_an_x;
  c4_we_b = c4_cf_y - c4_ef_y;
  c4_ff_y = c4_ne_a * c4_we_b;
  c4_nn_x = c4_theta_4;
  c4_on_x = c4_nn_x;
  c4_on_x = muDoubleScalarSin(c4_on_x);
  c4_pn_x = c4_theta_1;
  c4_qn_x = c4_pn_x;
  c4_qn_x = muDoubleScalarCos(c4_qn_x);
  c4_rn_x = c4_theta_2;
  c4_sn_x = c4_rn_x;
  c4_sn_x = muDoubleScalarCos(c4_sn_x);
  c4_oe_a = c4_qn_x;
  c4_xe_b = c4_sn_x;
  c4_gf_y = c4_oe_a * c4_xe_b;
  c4_tn_x = c4_theta_3;
  c4_un_x = c4_tn_x;
  c4_un_x = muDoubleScalarSin(c4_un_x);
  c4_pe_a = c4_gf_y;
  c4_ye_b = c4_un_x;
  c4_hf_y = c4_pe_a * c4_ye_b;
  c4_vn_x = c4_theta_1;
  c4_wn_x = c4_vn_x;
  c4_wn_x = muDoubleScalarCos(c4_wn_x);
  c4_xn_x = c4_theta_3;
  c4_yn_x = c4_xn_x;
  c4_yn_x = muDoubleScalarCos(c4_yn_x);
  c4_qe_a = c4_wn_x;
  c4_af_b = c4_yn_x;
  c4_if_y = c4_qe_a * c4_af_b;
  c4_ao_x = c4_theta_2;
  c4_bo_x = c4_ao_x;
  c4_bo_x = muDoubleScalarSin(c4_bo_x);
  c4_re_a = c4_if_y;
  c4_bf_b = c4_bo_x;
  c4_jf_y = c4_re_a * c4_bf_b;
  c4_se_a = c4_on_x;
  c4_cf_b = c4_hf_y + c4_jf_y;
  c4_kf_y = c4_se_a * c4_cf_b;
  c4_te_a = c4_af_y;
  c4_df_b = c4_ff_y + c4_kf_y;
  c4_lf_y = c4_te_a * c4_df_b;
  c4_i_A = c4_lf_y;
  c4_co_x = c4_i_A;
  c4_do_x = c4_co_x;
  c4_mf_y = c4_do_x / 2000.0;
  c4_eo_x = c4_theta_6;
  c4_fo_x = c4_eo_x;
  c4_fo_x = muDoubleScalarSin(c4_fo_x);
  c4_ef_b = c4_fo_x;
  c4_nf_y = 347.0 * c4_ef_b;
  c4_go_x = c4_theta_4;
  c4_ho_x = c4_go_x;
  c4_ho_x = muDoubleScalarCos(c4_ho_x);
  c4_io_x = c4_theta_1;
  c4_jo_x = c4_io_x;
  c4_jo_x = muDoubleScalarCos(c4_jo_x);
  c4_ko_x = c4_theta_2;
  c4_lo_x = c4_ko_x;
  c4_lo_x = muDoubleScalarCos(c4_lo_x);
  c4_ue_a = c4_jo_x;
  c4_ff_b = c4_lo_x;
  c4_of_y = c4_ue_a * c4_ff_b;
  c4_mo_x = c4_theta_3;
  c4_no_x = c4_mo_x;
  c4_no_x = muDoubleScalarSin(c4_no_x);
  c4_ve_a = c4_of_y;
  c4_gf_b = c4_no_x;
  c4_pf_y = c4_ve_a * c4_gf_b;
  c4_oo_x = c4_theta_1;
  c4_po_x = c4_oo_x;
  c4_po_x = muDoubleScalarCos(c4_po_x);
  c4_qo_x = c4_theta_3;
  c4_ro_x = c4_qo_x;
  c4_ro_x = muDoubleScalarCos(c4_ro_x);
  c4_we_a = c4_po_x;
  c4_hf_b = c4_ro_x;
  c4_qf_y = c4_we_a * c4_hf_b;
  c4_so_x = c4_theta_2;
  c4_to_x = c4_so_x;
  c4_to_x = muDoubleScalarSin(c4_to_x);
  c4_xe_a = c4_qf_y;
  c4_if_b = c4_to_x;
  c4_rf_y = c4_xe_a * c4_if_b;
  c4_ye_a = c4_ho_x;
  c4_jf_b = c4_pf_y + c4_rf_y;
  c4_sf_y = c4_ye_a * c4_jf_b;
  c4_uo_x = c4_theta_4;
  c4_vo_x = c4_uo_x;
  c4_vo_x = muDoubleScalarSin(c4_vo_x);
  c4_wo_x = c4_theta_1;
  c4_xo_x = c4_wo_x;
  c4_xo_x = muDoubleScalarCos(c4_xo_x);
  c4_yo_x = c4_theta_2;
  c4_ap_x = c4_yo_x;
  c4_ap_x = muDoubleScalarSin(c4_ap_x);
  c4_af_a = c4_xo_x;
  c4_kf_b = c4_ap_x;
  c4_tf_y = c4_af_a * c4_kf_b;
  c4_bp_x = c4_theta_3;
  c4_cp_x = c4_bp_x;
  c4_cp_x = muDoubleScalarSin(c4_cp_x);
  c4_bf_a = c4_tf_y;
  c4_lf_b = c4_cp_x;
  c4_uf_y = c4_bf_a * c4_lf_b;
  c4_dp_x = c4_theta_1;
  c4_ep_x = c4_dp_x;
  c4_ep_x = muDoubleScalarCos(c4_ep_x);
  c4_fp_x = c4_theta_2;
  c4_gp_x = c4_fp_x;
  c4_gp_x = muDoubleScalarCos(c4_gp_x);
  c4_cf_a = c4_ep_x;
  c4_mf_b = c4_gp_x;
  c4_vf_y = c4_cf_a * c4_mf_b;
  c4_hp_x = c4_theta_3;
  c4_ip_x = c4_hp_x;
  c4_ip_x = muDoubleScalarCos(c4_ip_x);
  c4_df_a = c4_vf_y;
  c4_nf_b = c4_ip_x;
  c4_wf_y = c4_df_a * c4_nf_b;
  c4_ef_a = c4_vo_x;
  c4_of_b = c4_uf_y - c4_wf_y;
  c4_xf_y = c4_ef_a * c4_of_b;
  c4_ff_a = c4_nf_y;
  c4_pf_b = c4_sf_y - c4_xf_y;
  c4_yf_y = c4_ff_a * c4_pf_b;
  c4_j_A = c4_yf_y;
  c4_jp_x = c4_j_A;
  c4_kp_x = c4_jp_x;
  c4_ag_y = c4_kp_x / 20000.0;
  c4_lp_x = c4_theta_1;
  c4_mp_x = c4_lp_x;
  c4_mp_x = muDoubleScalarCos(c4_mp_x);
  c4_qf_b = c4_mp_x;
  c4_bg_y = 39243.0 * c4_qf_b;
  c4_np_x = c4_theta_2;
  c4_op_x = c4_np_x;
  c4_op_x = muDoubleScalarSin(c4_op_x);
  c4_gf_a = c4_bg_y;
  c4_rf_b = c4_op_x;
  c4_cg_y = c4_gf_a * c4_rf_b;
  c4_pp_x = c4_theta_3;
  c4_qp_x = c4_pp_x;
  c4_qp_x = muDoubleScalarSin(c4_qp_x);
  c4_hf_a = c4_cg_y;
  c4_sf_b = c4_qp_x;
  c4_dg_y = c4_hf_a * c4_sf_b;
  c4_k_A = c4_dg_y;
  c4_rp_x = c4_k_A;
  c4_sp_x = c4_rp_x;
  c4_eg_y = c4_sp_x / 100000.0;
  c4_tp_x = c4_theta_1;
  c4_up_x = c4_tp_x;
  c4_up_x = muDoubleScalarCos(c4_up_x);
  c4_tf_b = c4_up_x;
  c4_fg_y = 39243.0 * c4_tf_b;
  c4_vp_x = c4_theta_2;
  c4_wp_x = c4_vp_x;
  c4_wp_x = muDoubleScalarCos(c4_wp_x);
  c4_if_a = c4_fg_y;
  c4_uf_b = c4_wp_x;
  c4_gg_y = c4_if_a * c4_uf_b;
  c4_xp_x = c4_theta_3;
  c4_yp_x = c4_xp_x;
  c4_yp_x = muDoubleScalarCos(c4_yp_x);
  c4_jf_a = c4_gg_y;
  c4_vf_b = c4_yp_x;
  c4_hg_y = c4_jf_a * c4_vf_b;
  c4_l_A = c4_hg_y;
  c4_aq_x = c4_l_A;
  c4_bq_x = c4_aq_x;
  c4_ig_y = c4_bq_x / 100000.0;
  c4_cq_x = c4_theta_6;
  c4_dq_x = c4_cq_x;
  c4_dq_x = muDoubleScalarCos(c4_dq_x);
  c4_eq_x = c4_theta_1;
  c4_fq_x = c4_eq_x;
  c4_fq_x = muDoubleScalarCos(c4_fq_x);
  c4_gq_x = c4_theta_5;
  c4_hq_x = c4_gq_x;
  c4_hq_x = muDoubleScalarSin(c4_hq_x);
  c4_kf_a = c4_fq_x;
  c4_wf_b = c4_hq_x;
  c4_jg_y = c4_kf_a * c4_wf_b;
  c4_iq_x = c4_theta_5;
  c4_jq_x = c4_iq_x;
  c4_jq_x = muDoubleScalarCos(c4_jq_x);
  c4_kq_x = c4_theta_4;
  c4_lq_x = c4_kq_x;
  c4_lq_x = muDoubleScalarCos(c4_lq_x);
  c4_mq_x = c4_theta_1;
  c4_nq_x = c4_mq_x;
  c4_nq_x = muDoubleScalarSin(c4_nq_x);
  c4_oq_x = c4_theta_2;
  c4_pq_x = c4_oq_x;
  c4_pq_x = muDoubleScalarSin(c4_pq_x);
  c4_lf_a = c4_nq_x;
  c4_xf_b = c4_pq_x;
  c4_kg_y = c4_lf_a * c4_xf_b;
  c4_qq_x = c4_theta_3;
  c4_rq_x = c4_qq_x;
  c4_rq_x = muDoubleScalarSin(c4_rq_x);
  c4_mf_a = c4_kg_y;
  c4_yf_b = c4_rq_x;
  c4_lg_y = c4_mf_a * c4_yf_b;
  c4_sq_x = c4_theta_2;
  c4_tq_x = c4_sq_x;
  c4_tq_x = muDoubleScalarCos(c4_tq_x);
  c4_uq_x = c4_theta_3;
  c4_vq_x = c4_uq_x;
  c4_vq_x = muDoubleScalarCos(c4_vq_x);
  c4_nf_a = c4_tq_x;
  c4_ag_b = c4_vq_x;
  c4_mg_y = c4_nf_a * c4_ag_b;
  c4_wq_x = c4_theta_1;
  c4_xq_x = c4_wq_x;
  c4_xq_x = muDoubleScalarSin(c4_xq_x);
  c4_of_a = c4_mg_y;
  c4_bg_b = c4_xq_x;
  c4_ng_y = c4_of_a * c4_bg_b;
  c4_pf_a = c4_lq_x;
  c4_cg_b = c4_lg_y - c4_ng_y;
  c4_og_y = c4_pf_a * c4_cg_b;
  c4_yq_x = c4_theta_4;
  c4_ar_x = c4_yq_x;
  c4_ar_x = muDoubleScalarSin(c4_ar_x);
  c4_br_x = c4_theta_2;
  c4_cr_x = c4_br_x;
  c4_cr_x = muDoubleScalarCos(c4_cr_x);
  c4_dr_x = c4_theta_1;
  c4_er_x = c4_dr_x;
  c4_er_x = muDoubleScalarSin(c4_er_x);
  c4_qf_a = c4_cr_x;
  c4_dg_b = c4_er_x;
  c4_pg_y = c4_qf_a * c4_dg_b;
  c4_fr_x = c4_theta_3;
  c4_gr_x = c4_fr_x;
  c4_gr_x = muDoubleScalarSin(c4_gr_x);
  c4_rf_a = c4_pg_y;
  c4_eg_b = c4_gr_x;
  c4_qg_y = c4_rf_a * c4_eg_b;
  c4_hr_x = c4_theta_3;
  c4_ir_x = c4_hr_x;
  c4_ir_x = muDoubleScalarCos(c4_ir_x);
  c4_jr_x = c4_theta_1;
  c4_kr_x = c4_jr_x;
  c4_kr_x = muDoubleScalarSin(c4_kr_x);
  c4_sf_a = c4_ir_x;
  c4_fg_b = c4_kr_x;
  c4_rg_y = c4_sf_a * c4_fg_b;
  c4_lr_x = c4_theta_2;
  c4_mr_x = c4_lr_x;
  c4_mr_x = muDoubleScalarSin(c4_mr_x);
  c4_tf_a = c4_rg_y;
  c4_gg_b = c4_mr_x;
  c4_sg_y = c4_tf_a * c4_gg_b;
  c4_uf_a = c4_ar_x;
  c4_hg_b = c4_qg_y + c4_sg_y;
  c4_tg_y = c4_uf_a * c4_hg_b;
  c4_vf_a = c4_jq_x;
  c4_ig_b = c4_og_y + c4_tg_y;
  c4_ug_y = c4_vf_a * c4_ig_b;
  c4_wf_a = -c4_dq_x;
  c4_jg_b = c4_jg_y + c4_ug_y;
  c4_vg_y = c4_wf_a * c4_jg_b;
  c4_nr_x = c4_theta_6;
  c4_or_x = c4_nr_x;
  c4_or_x = muDoubleScalarSin(c4_or_x);
  c4_pr_x = c4_theta_4;
  c4_qr_x = c4_pr_x;
  c4_qr_x = muDoubleScalarCos(c4_qr_x);
  c4_rr_x = c4_theta_2;
  c4_sr_x = c4_rr_x;
  c4_sr_x = muDoubleScalarCos(c4_sr_x);
  c4_tr_x = c4_theta_1;
  c4_ur_x = c4_tr_x;
  c4_ur_x = muDoubleScalarSin(c4_ur_x);
  c4_xf_a = c4_sr_x;
  c4_kg_b = c4_ur_x;
  c4_wg_y = c4_xf_a * c4_kg_b;
  c4_vr_x = c4_theta_3;
  c4_wr_x = c4_vr_x;
  c4_wr_x = muDoubleScalarSin(c4_wr_x);
  c4_yf_a = c4_wg_y;
  c4_lg_b = c4_wr_x;
  c4_xg_y = c4_yf_a * c4_lg_b;
  c4_xr_x = c4_theta_3;
  c4_yr_x = c4_xr_x;
  c4_yr_x = muDoubleScalarCos(c4_yr_x);
  c4_as_x = c4_theta_1;
  c4_bs_x = c4_as_x;
  c4_bs_x = muDoubleScalarSin(c4_bs_x);
  c4_ag_a = c4_yr_x;
  c4_mg_b = c4_bs_x;
  c4_yg_y = c4_ag_a * c4_mg_b;
  c4_cs_x = c4_theta_2;
  c4_ds_x = c4_cs_x;
  c4_ds_x = muDoubleScalarSin(c4_ds_x);
  c4_bg_a = c4_yg_y;
  c4_ng_b = c4_ds_x;
  c4_ah_y = c4_bg_a * c4_ng_b;
  c4_cg_a = c4_qr_x;
  c4_og_b = c4_xg_y + c4_ah_y;
  c4_bh_y = c4_cg_a * c4_og_b;
  c4_es_x = c4_theta_4;
  c4_fs_x = c4_es_x;
  c4_fs_x = muDoubleScalarSin(c4_fs_x);
  c4_gs_x = c4_theta_1;
  c4_hs_x = c4_gs_x;
  c4_hs_x = muDoubleScalarSin(c4_hs_x);
  c4_is_x = c4_theta_2;
  c4_js_x = c4_is_x;
  c4_js_x = muDoubleScalarSin(c4_js_x);
  c4_dg_a = c4_hs_x;
  c4_pg_b = c4_js_x;
  c4_ch_y = c4_dg_a * c4_pg_b;
  c4_ks_x = c4_theta_3;
  c4_ls_x = c4_ks_x;
  c4_ls_x = muDoubleScalarSin(c4_ls_x);
  c4_eg_a = c4_ch_y;
  c4_qg_b = c4_ls_x;
  c4_dh_y = c4_eg_a * c4_qg_b;
  c4_ms_x = c4_theta_2;
  c4_ns_x = c4_ms_x;
  c4_ns_x = muDoubleScalarCos(c4_ns_x);
  c4_os_x = c4_theta_3;
  c4_ps_x = c4_os_x;
  c4_ps_x = muDoubleScalarCos(c4_ps_x);
  c4_fg_a = c4_ns_x;
  c4_rg_b = c4_ps_x;
  c4_eh_y = c4_fg_a * c4_rg_b;
  c4_qs_x = c4_theta_1;
  c4_rs_x = c4_qs_x;
  c4_rs_x = muDoubleScalarSin(c4_rs_x);
  c4_gg_a = c4_eh_y;
  c4_sg_b = c4_rs_x;
  c4_fh_y = c4_gg_a * c4_sg_b;
  c4_hg_a = c4_fs_x;
  c4_tg_b = c4_dh_y - c4_fh_y;
  c4_gh_y = c4_hg_a * c4_tg_b;
  c4_ig_a = c4_or_x;
  c4_ug_b = c4_bh_y - c4_gh_y;
  c4_hh_y = c4_ig_a * c4_ug_b;
  c4_ss_x = c4_theta_6;
  c4_ts_x = c4_ss_x;
  c4_ts_x = muDoubleScalarSin(c4_ts_x);
  c4_us_x = c4_theta_1;
  c4_vs_x = c4_us_x;
  c4_vs_x = muDoubleScalarCos(c4_vs_x);
  c4_ws_x = c4_theta_5;
  c4_xs_x = c4_ws_x;
  c4_xs_x = muDoubleScalarSin(c4_xs_x);
  c4_jg_a = c4_vs_x;
  c4_vg_b = c4_xs_x;
  c4_ih_y = c4_jg_a * c4_vg_b;
  c4_ys_x = c4_theta_5;
  c4_at_x = c4_ys_x;
  c4_at_x = muDoubleScalarCos(c4_at_x);
  c4_bt_x = c4_theta_4;
  c4_ct_x = c4_bt_x;
  c4_ct_x = muDoubleScalarCos(c4_ct_x);
  c4_dt_x = c4_theta_1;
  c4_et_x = c4_dt_x;
  c4_et_x = muDoubleScalarSin(c4_et_x);
  c4_ft_x = c4_theta_2;
  c4_gt_x = c4_ft_x;
  c4_gt_x = muDoubleScalarSin(c4_gt_x);
  c4_kg_a = c4_et_x;
  c4_wg_b = c4_gt_x;
  c4_jh_y = c4_kg_a * c4_wg_b;
  c4_ht_x = c4_theta_3;
  c4_it_x = c4_ht_x;
  c4_it_x = muDoubleScalarSin(c4_it_x);
  c4_lg_a = c4_jh_y;
  c4_xg_b = c4_it_x;
  c4_kh_y = c4_lg_a * c4_xg_b;
  c4_jt_x = c4_theta_2;
  c4_kt_x = c4_jt_x;
  c4_kt_x = muDoubleScalarCos(c4_kt_x);
  c4_lt_x = c4_theta_3;
  c4_mt_x = c4_lt_x;
  c4_mt_x = muDoubleScalarCos(c4_mt_x);
  c4_mg_a = c4_kt_x;
  c4_yg_b = c4_mt_x;
  c4_lh_y = c4_mg_a * c4_yg_b;
  c4_nt_x = c4_theta_1;
  c4_ot_x = c4_nt_x;
  c4_ot_x = muDoubleScalarSin(c4_ot_x);
  c4_ng_a = c4_lh_y;
  c4_ah_b = c4_ot_x;
  c4_mh_y = c4_ng_a * c4_ah_b;
  c4_og_a = c4_ct_x;
  c4_bh_b = c4_kh_y - c4_mh_y;
  c4_nh_y = c4_og_a * c4_bh_b;
  c4_pt_x = c4_theta_4;
  c4_qt_x = c4_pt_x;
  c4_qt_x = muDoubleScalarSin(c4_qt_x);
  c4_rt_x = c4_theta_2;
  c4_st_x = c4_rt_x;
  c4_st_x = muDoubleScalarCos(c4_st_x);
  c4_tt_x = c4_theta_1;
  c4_ut_x = c4_tt_x;
  c4_ut_x = muDoubleScalarSin(c4_ut_x);
  c4_pg_a = c4_st_x;
  c4_ch_b = c4_ut_x;
  c4_oh_y = c4_pg_a * c4_ch_b;
  c4_vt_x = c4_theta_3;
  c4_wt_x = c4_vt_x;
  c4_wt_x = muDoubleScalarSin(c4_wt_x);
  c4_qg_a = c4_oh_y;
  c4_dh_b = c4_wt_x;
  c4_ph_y = c4_qg_a * c4_dh_b;
  c4_xt_x = c4_theta_3;
  c4_yt_x = c4_xt_x;
  c4_yt_x = muDoubleScalarCos(c4_yt_x);
  c4_au_x = c4_theta_1;
  c4_bu_x = c4_au_x;
  c4_bu_x = muDoubleScalarSin(c4_bu_x);
  c4_rg_a = c4_yt_x;
  c4_eh_b = c4_bu_x;
  c4_qh_y = c4_rg_a * c4_eh_b;
  c4_cu_x = c4_theta_2;
  c4_du_x = c4_cu_x;
  c4_du_x = muDoubleScalarSin(c4_du_x);
  c4_sg_a = c4_qh_y;
  c4_fh_b = c4_du_x;
  c4_rh_y = c4_sg_a * c4_fh_b;
  c4_tg_a = c4_qt_x;
  c4_gh_b = c4_ph_y + c4_rh_y;
  c4_sh_y = c4_tg_a * c4_gh_b;
  c4_ug_a = c4_at_x;
  c4_hh_b = c4_nh_y + c4_sh_y;
  c4_th_y = c4_ug_a * c4_hh_b;
  c4_vg_a = c4_ts_x;
  c4_ih_b = c4_ih_y + c4_th_y;
  c4_uh_y = c4_vg_a * c4_ih_b;
  c4_eu_x = c4_theta_6;
  c4_fu_x = c4_eu_x;
  c4_fu_x = muDoubleScalarCos(c4_fu_x);
  c4_gu_x = c4_theta_4;
  c4_hu_x = c4_gu_x;
  c4_hu_x = muDoubleScalarCos(c4_hu_x);
  c4_iu_x = c4_theta_2;
  c4_ju_x = c4_iu_x;
  c4_ju_x = muDoubleScalarCos(c4_ju_x);
  c4_ku_x = c4_theta_1;
  c4_lu_x = c4_ku_x;
  c4_lu_x = muDoubleScalarSin(c4_lu_x);
  c4_wg_a = c4_ju_x;
  c4_jh_b = c4_lu_x;
  c4_vh_y = c4_wg_a * c4_jh_b;
  c4_mu_x = c4_theta_3;
  c4_nu_x = c4_mu_x;
  c4_nu_x = muDoubleScalarSin(c4_nu_x);
  c4_xg_a = c4_vh_y;
  c4_kh_b = c4_nu_x;
  c4_wh_y = c4_xg_a * c4_kh_b;
  c4_ou_x = c4_theta_3;
  c4_pu_x = c4_ou_x;
  c4_pu_x = muDoubleScalarCos(c4_pu_x);
  c4_qu_x = c4_theta_1;
  c4_ru_x = c4_qu_x;
  c4_ru_x = muDoubleScalarSin(c4_ru_x);
  c4_yg_a = c4_pu_x;
  c4_lh_b = c4_ru_x;
  c4_xh_y = c4_yg_a * c4_lh_b;
  c4_su_x = c4_theta_2;
  c4_tu_x = c4_su_x;
  c4_tu_x = muDoubleScalarSin(c4_tu_x);
  c4_ah_a = c4_xh_y;
  c4_mh_b = c4_tu_x;
  c4_yh_y = c4_ah_a * c4_mh_b;
  c4_bh_a = c4_hu_x;
  c4_nh_b = c4_wh_y + c4_yh_y;
  c4_ai_y = c4_bh_a * c4_nh_b;
  c4_uu_x = c4_theta_4;
  c4_vu_x = c4_uu_x;
  c4_vu_x = muDoubleScalarSin(c4_vu_x);
  c4_wu_x = c4_theta_1;
  c4_xu_x = c4_wu_x;
  c4_xu_x = muDoubleScalarSin(c4_xu_x);
  c4_yu_x = c4_theta_2;
  c4_av_x = c4_yu_x;
  c4_av_x = muDoubleScalarSin(c4_av_x);
  c4_ch_a = c4_xu_x;
  c4_oh_b = c4_av_x;
  c4_bi_y = c4_ch_a * c4_oh_b;
  c4_bv_x = c4_theta_3;
  c4_cv_x = c4_bv_x;
  c4_cv_x = muDoubleScalarSin(c4_cv_x);
  c4_dh_a = c4_bi_y;
  c4_ph_b = c4_cv_x;
  c4_ci_y = c4_dh_a * c4_ph_b;
  c4_dv_x = c4_theta_2;
  c4_ev_x = c4_dv_x;
  c4_ev_x = muDoubleScalarCos(c4_ev_x);
  c4_fv_x = c4_theta_3;
  c4_gv_x = c4_fv_x;
  c4_gv_x = muDoubleScalarCos(c4_gv_x);
  c4_eh_a = c4_ev_x;
  c4_qh_b = c4_gv_x;
  c4_di_y = c4_eh_a * c4_qh_b;
  c4_hv_x = c4_theta_1;
  c4_iv_x = c4_hv_x;
  c4_iv_x = muDoubleScalarSin(c4_iv_x);
  c4_fh_a = c4_di_y;
  c4_rh_b = c4_iv_x;
  c4_ei_y = c4_fh_a * c4_rh_b;
  c4_gh_a = c4_vu_x;
  c4_sh_b = c4_ci_y - c4_ei_y;
  c4_fi_y = c4_gh_a * c4_sh_b;
  c4_hh_a = c4_fu_x;
  c4_th_b = c4_ai_y - c4_fi_y;
  c4_gi_y = c4_hh_a * c4_th_b;
  c4_jv_x = c4_theta_5;
  c4_kv_x = c4_jv_x;
  c4_kv_x = muDoubleScalarSin(c4_kv_x);
  c4_lv_x = c4_theta_4;
  c4_mv_x = c4_lv_x;
  c4_mv_x = muDoubleScalarCos(c4_mv_x);
  c4_nv_x = c4_theta_1;
  c4_ov_x = c4_nv_x;
  c4_ov_x = muDoubleScalarSin(c4_ov_x);
  c4_pv_x = c4_theta_2;
  c4_qv_x = c4_pv_x;
  c4_qv_x = muDoubleScalarSin(c4_qv_x);
  c4_ih_a = c4_ov_x;
  c4_uh_b = c4_qv_x;
  c4_hi_y = c4_ih_a * c4_uh_b;
  c4_rv_x = c4_theta_3;
  c4_sv_x = c4_rv_x;
  c4_sv_x = muDoubleScalarSin(c4_sv_x);
  c4_jh_a = c4_hi_y;
  c4_vh_b = c4_sv_x;
  c4_ii_y = c4_jh_a * c4_vh_b;
  c4_tv_x = c4_theta_2;
  c4_uv_x = c4_tv_x;
  c4_uv_x = muDoubleScalarCos(c4_uv_x);
  c4_vv_x = c4_theta_3;
  c4_wv_x = c4_vv_x;
  c4_wv_x = muDoubleScalarCos(c4_wv_x);
  c4_kh_a = c4_uv_x;
  c4_wh_b = c4_wv_x;
  c4_ji_y = c4_kh_a * c4_wh_b;
  c4_xv_x = c4_theta_1;
  c4_yv_x = c4_xv_x;
  c4_yv_x = muDoubleScalarSin(c4_yv_x);
  c4_lh_a = c4_ji_y;
  c4_xh_b = c4_yv_x;
  c4_ki_y = c4_lh_a * c4_xh_b;
  c4_mh_a = c4_mv_x;
  c4_yh_b = c4_ii_y - c4_ki_y;
  c4_li_y = c4_mh_a * c4_yh_b;
  c4_aw_x = c4_theta_4;
  c4_bw_x = c4_aw_x;
  c4_bw_x = muDoubleScalarSin(c4_bw_x);
  c4_cw_x = c4_theta_2;
  c4_dw_x = c4_cw_x;
  c4_dw_x = muDoubleScalarCos(c4_dw_x);
  c4_ew_x = c4_theta_1;
  c4_fw_x = c4_ew_x;
  c4_fw_x = muDoubleScalarSin(c4_fw_x);
  c4_nh_a = c4_dw_x;
  c4_ai_b = c4_fw_x;
  c4_mi_y = c4_nh_a * c4_ai_b;
  c4_gw_x = c4_theta_3;
  c4_hw_x = c4_gw_x;
  c4_hw_x = muDoubleScalarSin(c4_hw_x);
  c4_oh_a = c4_mi_y;
  c4_bi_b = c4_hw_x;
  c4_ni_y = c4_oh_a * c4_bi_b;
  c4_iw_x = c4_theta_3;
  c4_jw_x = c4_iw_x;
  c4_jw_x = muDoubleScalarCos(c4_jw_x);
  c4_kw_x = c4_theta_1;
  c4_lw_x = c4_kw_x;
  c4_lw_x = muDoubleScalarSin(c4_lw_x);
  c4_ph_a = c4_jw_x;
  c4_ci_b = c4_lw_x;
  c4_oi_y = c4_ph_a * c4_ci_b;
  c4_mw_x = c4_theta_2;
  c4_nw_x = c4_mw_x;
  c4_nw_x = muDoubleScalarSin(c4_nw_x);
  c4_qh_a = c4_oi_y;
  c4_di_b = c4_nw_x;
  c4_pi_y = c4_qh_a * c4_di_b;
  c4_rh_a = c4_bw_x;
  c4_ei_b = c4_ni_y + c4_pi_y;
  c4_qi_y = c4_rh_a * c4_ei_b;
  c4_sh_a = c4_kv_x;
  c4_fi_b = c4_li_y + c4_qi_y;
  c4_ri_y = c4_sh_a * c4_fi_b;
  c4_ow_x = c4_theta_1;
  c4_pw_x = c4_ow_x;
  c4_pw_x = muDoubleScalarCos(c4_pw_x);
  c4_qw_x = c4_theta_5;
  c4_rw_x = c4_qw_x;
  c4_rw_x = muDoubleScalarCos(c4_rw_x);
  c4_th_a = c4_pw_x;
  c4_gi_b = c4_rw_x;
  c4_si_y = c4_th_a * c4_gi_b;
  c4_sw_x = c4_theta_4;
  c4_tw_x = c4_sw_x;
  c4_tw_x = muDoubleScalarCos(c4_tw_x);
  c4_hi_b = c4_tw_x;
  c4_ti_y = 93.0 * c4_hi_b;
  c4_uw_x = c4_theta_2;
  c4_vw_x = c4_uw_x;
  c4_vw_x = muDoubleScalarCos(c4_vw_x);
  c4_ww_x = c4_theta_1;
  c4_xw_x = c4_ww_x;
  c4_xw_x = muDoubleScalarSin(c4_xw_x);
  c4_uh_a = c4_vw_x;
  c4_ii_b = c4_xw_x;
  c4_ui_y = c4_uh_a * c4_ii_b;
  c4_yw_x = c4_theta_3;
  c4_ax_x = c4_yw_x;
  c4_ax_x = muDoubleScalarSin(c4_ax_x);
  c4_vh_a = c4_ui_y;
  c4_ji_b = c4_ax_x;
  c4_vi_y = c4_vh_a * c4_ji_b;
  c4_bx_x = c4_theta_3;
  c4_cx_x = c4_bx_x;
  c4_cx_x = muDoubleScalarCos(c4_cx_x);
  c4_dx_x = c4_theta_1;
  c4_ex_x = c4_dx_x;
  c4_ex_x = muDoubleScalarSin(c4_ex_x);
  c4_wh_a = c4_cx_x;
  c4_ki_b = c4_ex_x;
  c4_wi_y = c4_wh_a * c4_ki_b;
  c4_fx_x = c4_theta_2;
  c4_gx_x = c4_fx_x;
  c4_gx_x = muDoubleScalarSin(c4_gx_x);
  c4_xh_a = c4_wi_y;
  c4_li_b = c4_gx_x;
  c4_xi_y = c4_xh_a * c4_li_b;
  c4_yh_a = c4_ti_y;
  c4_mi_b = c4_vi_y + c4_xi_y;
  c4_yi_y = c4_yh_a * c4_mi_b;
  c4_m_A = c4_yi_y;
  c4_hx_x = c4_m_A;
  c4_ix_x = c4_hx_x;
  c4_aj_y = c4_ix_x / 1000.0;
  c4_jx_x = c4_theta_1;
  c4_kx_x = c4_jx_x;
  c4_kx_x = muDoubleScalarCos(c4_kx_x);
  c4_ni_b = c4_kx_x;
  c4_bj_y = 183.0 * c4_ni_b;
  c4_lx_x = c4_theta_5;
  c4_mx_x = c4_lx_x;
  c4_mx_x = muDoubleScalarCos(c4_mx_x);
  c4_ai_a = c4_bj_y;
  c4_oi_b = c4_mx_x;
  c4_cj_y = c4_ai_a * c4_oi_b;
  c4_n_A = c4_cj_y;
  c4_nx_x = c4_n_A;
  c4_ox_x = c4_nx_x;
  c4_dj_y = c4_ox_x / 2000.0;
  c4_px_x = c4_theta_2;
  c4_qx_x = c4_px_x;
  c4_qx_x = muDoubleScalarCos(c4_qx_x);
  c4_pi_b = c4_qx_x;
  c4_ej_y = 17.0 * c4_pi_b;
  c4_rx_x = c4_theta_1;
  c4_sx_x = c4_rx_x;
  c4_sx_x = muDoubleScalarSin(c4_sx_x);
  c4_bi_a = c4_ej_y;
  c4_qi_b = c4_sx_x;
  c4_fj_y = c4_bi_a * c4_qi_b;
  c4_o_A = c4_fj_y;
  c4_tx_x = c4_o_A;
  c4_ux_x = c4_tx_x;
  c4_gj_y = c4_ux_x / 40.0;
  c4_vx_x = c4_theta_1;
  c4_wx_x = c4_vx_x;
  c4_wx_x = muDoubleScalarCos(c4_wx_x);
  c4_ri_b = c4_wx_x;
  c4_hj_y = 109.0 * c4_ri_b;
  c4_p_A = c4_hj_y;
  c4_xx_x = c4_p_A;
  c4_yx_x = c4_xx_x;
  c4_ij_y = c4_yx_x / 1000.0;
  c4_ay_x = c4_theta_6;
  c4_by_x = c4_ay_x;
  c4_by_x = muDoubleScalarCos(c4_by_x);
  c4_si_b = c4_by_x;
  c4_jj_y = 347.0 * c4_si_b;
  c4_cy_x = c4_theta_1;
  c4_dy_x = c4_cy_x;
  c4_dy_x = muDoubleScalarCos(c4_dy_x);
  c4_ey_x = c4_theta_5;
  c4_fy_x = c4_ey_x;
  c4_fy_x = muDoubleScalarSin(c4_fy_x);
  c4_ci_a = c4_dy_x;
  c4_ti_b = c4_fy_x;
  c4_kj_y = c4_ci_a * c4_ti_b;
  c4_gy_x = c4_theta_5;
  c4_hy_x = c4_gy_x;
  c4_hy_x = muDoubleScalarCos(c4_hy_x);
  c4_iy_x = c4_theta_4;
  c4_jy_x = c4_iy_x;
  c4_jy_x = muDoubleScalarCos(c4_jy_x);
  c4_ky_x = c4_theta_1;
  c4_ly_x = c4_ky_x;
  c4_ly_x = muDoubleScalarSin(c4_ly_x);
  c4_my_x = c4_theta_2;
  c4_ny_x = c4_my_x;
  c4_ny_x = muDoubleScalarSin(c4_ny_x);
  c4_di_a = c4_ly_x;
  c4_ui_b = c4_ny_x;
  c4_lj_y = c4_di_a * c4_ui_b;
  c4_oy_x = c4_theta_3;
  c4_py_x = c4_oy_x;
  c4_py_x = muDoubleScalarSin(c4_py_x);
  c4_ei_a = c4_lj_y;
  c4_vi_b = c4_py_x;
  c4_mj_y = c4_ei_a * c4_vi_b;
  c4_qy_x = c4_theta_2;
  c4_ry_x = c4_qy_x;
  c4_ry_x = muDoubleScalarCos(c4_ry_x);
  c4_sy_x = c4_theta_3;
  c4_ty_x = c4_sy_x;
  c4_ty_x = muDoubleScalarCos(c4_ty_x);
  c4_fi_a = c4_ry_x;
  c4_wi_b = c4_ty_x;
  c4_nj_y = c4_fi_a * c4_wi_b;
  c4_uy_x = c4_theta_1;
  c4_vy_x = c4_uy_x;
  c4_vy_x = muDoubleScalarSin(c4_vy_x);
  c4_gi_a = c4_nj_y;
  c4_xi_b = c4_vy_x;
  c4_oj_y = c4_gi_a * c4_xi_b;
  c4_hi_a = c4_jy_x;
  c4_yi_b = c4_mj_y - c4_oj_y;
  c4_pj_y = c4_hi_a * c4_yi_b;
  c4_wy_x = c4_theta_4;
  c4_xy_x = c4_wy_x;
  c4_xy_x = muDoubleScalarSin(c4_xy_x);
  c4_yy_x = c4_theta_2;
  c4_aab_x = c4_yy_x;
  c4_aab_x = muDoubleScalarCos(c4_aab_x);
  c4_bab_x = c4_theta_1;
  c4_cab_x = c4_bab_x;
  c4_cab_x = muDoubleScalarSin(c4_cab_x);
  c4_ii_a = c4_aab_x;
  c4_aj_b = c4_cab_x;
  c4_qj_y = c4_ii_a * c4_aj_b;
  c4_dab_x = c4_theta_3;
  c4_eab_x = c4_dab_x;
  c4_eab_x = muDoubleScalarSin(c4_eab_x);
  c4_ji_a = c4_qj_y;
  c4_bj_b = c4_eab_x;
  c4_rj_y = c4_ji_a * c4_bj_b;
  c4_fab_x = c4_theta_3;
  c4_gab_x = c4_fab_x;
  c4_gab_x = muDoubleScalarCos(c4_gab_x);
  c4_hab_x = c4_theta_1;
  c4_iab_x = c4_hab_x;
  c4_iab_x = muDoubleScalarSin(c4_iab_x);
  c4_ki_a = c4_gab_x;
  c4_cj_b = c4_iab_x;
  c4_sj_y = c4_ki_a * c4_cj_b;
  c4_jab_x = c4_theta_2;
  c4_kab_x = c4_jab_x;
  c4_kab_x = muDoubleScalarSin(c4_kab_x);
  c4_li_a = c4_sj_y;
  c4_dj_b = c4_kab_x;
  c4_tj_y = c4_li_a * c4_dj_b;
  c4_mi_a = c4_xy_x;
  c4_ej_b = c4_rj_y + c4_tj_y;
  c4_uj_y = c4_mi_a * c4_ej_b;
  c4_ni_a = c4_hy_x;
  c4_fj_b = c4_pj_y + c4_uj_y;
  c4_vj_y = c4_ni_a * c4_fj_b;
  c4_oi_a = c4_jj_y;
  c4_gj_b = c4_kj_y + c4_vj_y;
  c4_wj_y = c4_oi_a * c4_gj_b;
  c4_q_A = c4_wj_y;
  c4_lab_x = c4_q_A;
  c4_mab_x = c4_lab_x;
  c4_xj_y = c4_mab_x / 20000.0;
  c4_nab_x = c4_theta_4;
  c4_oab_x = c4_nab_x;
  c4_oab_x = muDoubleScalarSin(c4_oab_x);
  c4_hj_b = c4_oab_x;
  c4_yj_y = 93.0 * c4_hj_b;
  c4_pab_x = c4_theta_1;
  c4_qab_x = c4_pab_x;
  c4_qab_x = muDoubleScalarSin(c4_qab_x);
  c4_rab_x = c4_theta_2;
  c4_sab_x = c4_rab_x;
  c4_sab_x = muDoubleScalarSin(c4_sab_x);
  c4_pi_a = c4_qab_x;
  c4_ij_b = c4_sab_x;
  c4_ak_y = c4_pi_a * c4_ij_b;
  c4_tab_x = c4_theta_3;
  c4_uab_x = c4_tab_x;
  c4_uab_x = muDoubleScalarSin(c4_uab_x);
  c4_qi_a = c4_ak_y;
  c4_jj_b = c4_uab_x;
  c4_bk_y = c4_qi_a * c4_jj_b;
  c4_vab_x = c4_theta_2;
  c4_wab_x = c4_vab_x;
  c4_wab_x = muDoubleScalarCos(c4_wab_x);
  c4_xab_x = c4_theta_3;
  c4_yab_x = c4_xab_x;
  c4_yab_x = muDoubleScalarCos(c4_yab_x);
  c4_ri_a = c4_wab_x;
  c4_kj_b = c4_yab_x;
  c4_ck_y = c4_ri_a * c4_kj_b;
  c4_abb_x = c4_theta_1;
  c4_bbb_x = c4_abb_x;
  c4_bbb_x = muDoubleScalarSin(c4_bbb_x);
  c4_si_a = c4_ck_y;
  c4_lj_b = c4_bbb_x;
  c4_dk_y = c4_si_a * c4_lj_b;
  c4_ti_a = c4_yj_y;
  c4_mj_b = c4_bk_y - c4_dk_y;
  c4_ek_y = c4_ti_a * c4_mj_b;
  c4_r_A = c4_ek_y;
  c4_cbb_x = c4_r_A;
  c4_dbb_x = c4_cbb_x;
  c4_fk_y = c4_dbb_x / 1000.0;
  c4_ebb_x = c4_theta_6;
  c4_fbb_x = c4_ebb_x;
  c4_fbb_x = muDoubleScalarSin(c4_fbb_x);
  c4_nj_b = c4_fbb_x;
  c4_gk_y = 121.0 * c4_nj_b;
  c4_gbb_x = c4_theta_1;
  c4_hbb_x = c4_gbb_x;
  c4_hbb_x = muDoubleScalarCos(c4_hbb_x);
  c4_ibb_x = c4_theta_5;
  c4_jbb_x = c4_ibb_x;
  c4_jbb_x = muDoubleScalarSin(c4_jbb_x);
  c4_ui_a = c4_hbb_x;
  c4_oj_b = c4_jbb_x;
  c4_hk_y = c4_ui_a * c4_oj_b;
  c4_kbb_x = c4_theta_5;
  c4_lbb_x = c4_kbb_x;
  c4_lbb_x = muDoubleScalarCos(c4_lbb_x);
  c4_mbb_x = c4_theta_4;
  c4_nbb_x = c4_mbb_x;
  c4_nbb_x = muDoubleScalarCos(c4_nbb_x);
  c4_obb_x = c4_theta_1;
  c4_pbb_x = c4_obb_x;
  c4_pbb_x = muDoubleScalarSin(c4_pbb_x);
  c4_qbb_x = c4_theta_2;
  c4_rbb_x = c4_qbb_x;
  c4_rbb_x = muDoubleScalarSin(c4_rbb_x);
  c4_vi_a = c4_pbb_x;
  c4_pj_b = c4_rbb_x;
  c4_ik_y = c4_vi_a * c4_pj_b;
  c4_sbb_x = c4_theta_3;
  c4_tbb_x = c4_sbb_x;
  c4_tbb_x = muDoubleScalarSin(c4_tbb_x);
  c4_wi_a = c4_ik_y;
  c4_qj_b = c4_tbb_x;
  c4_jk_y = c4_wi_a * c4_qj_b;
  c4_ubb_x = c4_theta_2;
  c4_vbb_x = c4_ubb_x;
  c4_vbb_x = muDoubleScalarCos(c4_vbb_x);
  c4_wbb_x = c4_theta_3;
  c4_xbb_x = c4_wbb_x;
  c4_xbb_x = muDoubleScalarCos(c4_xbb_x);
  c4_xi_a = c4_vbb_x;
  c4_rj_b = c4_xbb_x;
  c4_kk_y = c4_xi_a * c4_rj_b;
  c4_ybb_x = c4_theta_1;
  c4_acb_x = c4_ybb_x;
  c4_acb_x = muDoubleScalarSin(c4_acb_x);
  c4_yi_a = c4_kk_y;
  c4_sj_b = c4_acb_x;
  c4_lk_y = c4_yi_a * c4_sj_b;
  c4_aj_a = c4_nbb_x;
  c4_tj_b = c4_jk_y - c4_lk_y;
  c4_mk_y = c4_aj_a * c4_tj_b;
  c4_bcb_x = c4_theta_4;
  c4_ccb_x = c4_bcb_x;
  c4_ccb_x = muDoubleScalarSin(c4_ccb_x);
  c4_dcb_x = c4_theta_2;
  c4_ecb_x = c4_dcb_x;
  c4_ecb_x = muDoubleScalarCos(c4_ecb_x);
  c4_fcb_x = c4_theta_1;
  c4_gcb_x = c4_fcb_x;
  c4_gcb_x = muDoubleScalarSin(c4_gcb_x);
  c4_bj_a = c4_ecb_x;
  c4_uj_b = c4_gcb_x;
  c4_nk_y = c4_bj_a * c4_uj_b;
  c4_hcb_x = c4_theta_3;
  c4_icb_x = c4_hcb_x;
  c4_icb_x = muDoubleScalarSin(c4_icb_x);
  c4_cj_a = c4_nk_y;
  c4_vj_b = c4_icb_x;
  c4_ok_y = c4_cj_a * c4_vj_b;
  c4_jcb_x = c4_theta_3;
  c4_kcb_x = c4_jcb_x;
  c4_kcb_x = muDoubleScalarCos(c4_kcb_x);
  c4_lcb_x = c4_theta_1;
  c4_mcb_x = c4_lcb_x;
  c4_mcb_x = muDoubleScalarSin(c4_mcb_x);
  c4_dj_a = c4_kcb_x;
  c4_wj_b = c4_mcb_x;
  c4_pk_y = c4_dj_a * c4_wj_b;
  c4_ncb_x = c4_theta_2;
  c4_ocb_x = c4_ncb_x;
  c4_ocb_x = muDoubleScalarSin(c4_ocb_x);
  c4_ej_a = c4_pk_y;
  c4_xj_b = c4_ocb_x;
  c4_qk_y = c4_ej_a * c4_xj_b;
  c4_fj_a = c4_ccb_x;
  c4_yj_b = c4_ok_y + c4_qk_y;
  c4_rk_y = c4_fj_a * c4_yj_b;
  c4_gj_a = c4_lbb_x;
  c4_ak_b = c4_mk_y + c4_rk_y;
  c4_sk_y = c4_gj_a * c4_ak_b;
  c4_hj_a = c4_gk_y;
  c4_bk_b = c4_hk_y + c4_sk_y;
  c4_tk_y = c4_hj_a * c4_bk_b;
  c4_s_A = c4_tk_y;
  c4_pcb_x = c4_s_A;
  c4_qcb_x = c4_pcb_x;
  c4_uk_y = c4_qcb_x / 20000.0;
  c4_rcb_x = c4_theta_6;
  c4_scb_x = c4_rcb_x;
  c4_scb_x = muDoubleScalarCos(c4_scb_x);
  c4_ck_b = c4_scb_x;
  c4_vk_y = 121.0 * c4_ck_b;
  c4_tcb_x = c4_theta_4;
  c4_ucb_x = c4_tcb_x;
  c4_ucb_x = muDoubleScalarCos(c4_ucb_x);
  c4_vcb_x = c4_theta_2;
  c4_wcb_x = c4_vcb_x;
  c4_wcb_x = muDoubleScalarCos(c4_wcb_x);
  c4_xcb_x = c4_theta_1;
  c4_ycb_x = c4_xcb_x;
  c4_ycb_x = muDoubleScalarSin(c4_ycb_x);
  c4_ij_a = c4_wcb_x;
  c4_dk_b = c4_ycb_x;
  c4_wk_y = c4_ij_a * c4_dk_b;
  c4_adb_x = c4_theta_3;
  c4_bdb_x = c4_adb_x;
  c4_bdb_x = muDoubleScalarSin(c4_bdb_x);
  c4_jj_a = c4_wk_y;
  c4_ek_b = c4_bdb_x;
  c4_xk_y = c4_jj_a * c4_ek_b;
  c4_cdb_x = c4_theta_3;
  c4_ddb_x = c4_cdb_x;
  c4_ddb_x = muDoubleScalarCos(c4_ddb_x);
  c4_edb_x = c4_theta_1;
  c4_fdb_x = c4_edb_x;
  c4_fdb_x = muDoubleScalarSin(c4_fdb_x);
  c4_kj_a = c4_ddb_x;
  c4_fk_b = c4_fdb_x;
  c4_yk_y = c4_kj_a * c4_fk_b;
  c4_gdb_x = c4_theta_2;
  c4_hdb_x = c4_gdb_x;
  c4_hdb_x = muDoubleScalarSin(c4_hdb_x);
  c4_lj_a = c4_yk_y;
  c4_gk_b = c4_hdb_x;
  c4_al_y = c4_lj_a * c4_gk_b;
  c4_mj_a = c4_ucb_x;
  c4_hk_b = c4_xk_y + c4_al_y;
  c4_bl_y = c4_mj_a * c4_hk_b;
  c4_idb_x = c4_theta_4;
  c4_jdb_x = c4_idb_x;
  c4_jdb_x = muDoubleScalarSin(c4_jdb_x);
  c4_kdb_x = c4_theta_1;
  c4_ldb_x = c4_kdb_x;
  c4_ldb_x = muDoubleScalarSin(c4_ldb_x);
  c4_mdb_x = c4_theta_2;
  c4_ndb_x = c4_mdb_x;
  c4_ndb_x = muDoubleScalarSin(c4_ndb_x);
  c4_nj_a = c4_ldb_x;
  c4_ik_b = c4_ndb_x;
  c4_cl_y = c4_nj_a * c4_ik_b;
  c4_odb_x = c4_theta_3;
  c4_pdb_x = c4_odb_x;
  c4_pdb_x = muDoubleScalarSin(c4_pdb_x);
  c4_oj_a = c4_cl_y;
  c4_jk_b = c4_pdb_x;
  c4_dl_y = c4_oj_a * c4_jk_b;
  c4_qdb_x = c4_theta_2;
  c4_rdb_x = c4_qdb_x;
  c4_rdb_x = muDoubleScalarCos(c4_rdb_x);
  c4_sdb_x = c4_theta_3;
  c4_tdb_x = c4_sdb_x;
  c4_tdb_x = muDoubleScalarCos(c4_tdb_x);
  c4_pj_a = c4_rdb_x;
  c4_kk_b = c4_tdb_x;
  c4_el_y = c4_pj_a * c4_kk_b;
  c4_udb_x = c4_theta_1;
  c4_vdb_x = c4_udb_x;
  c4_vdb_x = muDoubleScalarSin(c4_vdb_x);
  c4_qj_a = c4_el_y;
  c4_lk_b = c4_vdb_x;
  c4_fl_y = c4_qj_a * c4_lk_b;
  c4_rj_a = c4_jdb_x;
  c4_mk_b = c4_dl_y - c4_fl_y;
  c4_gl_y = c4_rj_a * c4_mk_b;
  c4_sj_a = c4_vk_y;
  c4_nk_b = c4_bl_y - c4_gl_y;
  c4_hl_y = c4_sj_a * c4_nk_b;
  c4_t_A = c4_hl_y;
  c4_wdb_x = c4_t_A;
  c4_xdb_x = c4_wdb_x;
  c4_il_y = c4_xdb_x / 20000.0;
  c4_ydb_x = c4_theta_5;
  c4_aeb_x = c4_ydb_x;
  c4_aeb_x = muDoubleScalarSin(c4_aeb_x);
  c4_ok_b = c4_aeb_x;
  c4_jl_y = 183.0 * c4_ok_b;
  c4_beb_x = c4_theta_4;
  c4_ceb_x = c4_beb_x;
  c4_ceb_x = muDoubleScalarCos(c4_ceb_x);
  c4_deb_x = c4_theta_1;
  c4_eeb_x = c4_deb_x;
  c4_eeb_x = muDoubleScalarSin(c4_eeb_x);
  c4_feb_x = c4_theta_2;
  c4_geb_x = c4_feb_x;
  c4_geb_x = muDoubleScalarSin(c4_geb_x);
  c4_tj_a = c4_eeb_x;
  c4_pk_b = c4_geb_x;
  c4_kl_y = c4_tj_a * c4_pk_b;
  c4_heb_x = c4_theta_3;
  c4_ieb_x = c4_heb_x;
  c4_ieb_x = muDoubleScalarSin(c4_ieb_x);
  c4_uj_a = c4_kl_y;
  c4_qk_b = c4_ieb_x;
  c4_ll_y = c4_uj_a * c4_qk_b;
  c4_jeb_x = c4_theta_2;
  c4_keb_x = c4_jeb_x;
  c4_keb_x = muDoubleScalarCos(c4_keb_x);
  c4_leb_x = c4_theta_3;
  c4_meb_x = c4_leb_x;
  c4_meb_x = muDoubleScalarCos(c4_meb_x);
  c4_vj_a = c4_keb_x;
  c4_rk_b = c4_meb_x;
  c4_ml_y = c4_vj_a * c4_rk_b;
  c4_neb_x = c4_theta_1;
  c4_oeb_x = c4_neb_x;
  c4_oeb_x = muDoubleScalarSin(c4_oeb_x);
  c4_wj_a = c4_ml_y;
  c4_sk_b = c4_oeb_x;
  c4_nl_y = c4_wj_a * c4_sk_b;
  c4_xj_a = c4_ceb_x;
  c4_tk_b = c4_ll_y - c4_nl_y;
  c4_ol_y = c4_xj_a * c4_tk_b;
  c4_peb_x = c4_theta_4;
  c4_qeb_x = c4_peb_x;
  c4_qeb_x = muDoubleScalarSin(c4_qeb_x);
  c4_reb_x = c4_theta_2;
  c4_seb_x = c4_reb_x;
  c4_seb_x = muDoubleScalarCos(c4_seb_x);
  c4_teb_x = c4_theta_1;
  c4_ueb_x = c4_teb_x;
  c4_ueb_x = muDoubleScalarSin(c4_ueb_x);
  c4_yj_a = c4_seb_x;
  c4_uk_b = c4_ueb_x;
  c4_pl_y = c4_yj_a * c4_uk_b;
  c4_veb_x = c4_theta_3;
  c4_web_x = c4_veb_x;
  c4_web_x = muDoubleScalarSin(c4_web_x);
  c4_ak_a = c4_pl_y;
  c4_vk_b = c4_web_x;
  c4_ql_y = c4_ak_a * c4_vk_b;
  c4_xeb_x = c4_theta_3;
  c4_yeb_x = c4_xeb_x;
  c4_yeb_x = muDoubleScalarCos(c4_yeb_x);
  c4_afb_x = c4_theta_1;
  c4_bfb_x = c4_afb_x;
  c4_bfb_x = muDoubleScalarSin(c4_bfb_x);
  c4_bk_a = c4_yeb_x;
  c4_wk_b = c4_bfb_x;
  c4_rl_y = c4_bk_a * c4_wk_b;
  c4_cfb_x = c4_theta_2;
  c4_dfb_x = c4_cfb_x;
  c4_dfb_x = muDoubleScalarSin(c4_dfb_x);
  c4_ck_a = c4_rl_y;
  c4_xk_b = c4_dfb_x;
  c4_sl_y = c4_ck_a * c4_xk_b;
  c4_dk_a = c4_qeb_x;
  c4_yk_b = c4_ql_y + c4_sl_y;
  c4_tl_y = c4_dk_a * c4_yk_b;
  c4_ek_a = c4_jl_y;
  c4_al_b = c4_ol_y + c4_tl_y;
  c4_ul_y = c4_ek_a * c4_al_b;
  c4_u_A = c4_ul_y;
  c4_efb_x = c4_u_A;
  c4_ffb_x = c4_efb_x;
  c4_vl_y = c4_ffb_x / 2000.0;
  c4_gfb_x = c4_theta_6;
  c4_hfb_x = c4_gfb_x;
  c4_hfb_x = muDoubleScalarSin(c4_hfb_x);
  c4_bl_b = c4_hfb_x;
  c4_wl_y = 347.0 * c4_bl_b;
  c4_ifb_x = c4_theta_4;
  c4_jfb_x = c4_ifb_x;
  c4_jfb_x = muDoubleScalarCos(c4_jfb_x);
  c4_kfb_x = c4_theta_2;
  c4_lfb_x = c4_kfb_x;
  c4_lfb_x = muDoubleScalarCos(c4_lfb_x);
  c4_mfb_x = c4_theta_1;
  c4_nfb_x = c4_mfb_x;
  c4_nfb_x = muDoubleScalarSin(c4_nfb_x);
  c4_fk_a = c4_lfb_x;
  c4_cl_b = c4_nfb_x;
  c4_xl_y = c4_fk_a * c4_cl_b;
  c4_ofb_x = c4_theta_3;
  c4_pfb_x = c4_ofb_x;
  c4_pfb_x = muDoubleScalarSin(c4_pfb_x);
  c4_gk_a = c4_xl_y;
  c4_dl_b = c4_pfb_x;
  c4_yl_y = c4_gk_a * c4_dl_b;
  c4_qfb_x = c4_theta_3;
  c4_rfb_x = c4_qfb_x;
  c4_rfb_x = muDoubleScalarCos(c4_rfb_x);
  c4_sfb_x = c4_theta_1;
  c4_tfb_x = c4_sfb_x;
  c4_tfb_x = muDoubleScalarSin(c4_tfb_x);
  c4_hk_a = c4_rfb_x;
  c4_el_b = c4_tfb_x;
  c4_am_y = c4_hk_a * c4_el_b;
  c4_ufb_x = c4_theta_2;
  c4_vfb_x = c4_ufb_x;
  c4_vfb_x = muDoubleScalarSin(c4_vfb_x);
  c4_ik_a = c4_am_y;
  c4_fl_b = c4_vfb_x;
  c4_bm_y = c4_ik_a * c4_fl_b;
  c4_jk_a = c4_jfb_x;
  c4_gl_b = c4_yl_y + c4_bm_y;
  c4_cm_y = c4_jk_a * c4_gl_b;
  c4_wfb_x = c4_theta_4;
  c4_xfb_x = c4_wfb_x;
  c4_xfb_x = muDoubleScalarSin(c4_xfb_x);
  c4_yfb_x = c4_theta_1;
  c4_agb_x = c4_yfb_x;
  c4_agb_x = muDoubleScalarSin(c4_agb_x);
  c4_bgb_x = c4_theta_2;
  c4_cgb_x = c4_bgb_x;
  c4_cgb_x = muDoubleScalarSin(c4_cgb_x);
  c4_kk_a = c4_agb_x;
  c4_hl_b = c4_cgb_x;
  c4_dm_y = c4_kk_a * c4_hl_b;
  c4_dgb_x = c4_theta_3;
  c4_egb_x = c4_dgb_x;
  c4_egb_x = muDoubleScalarSin(c4_egb_x);
  c4_lk_a = c4_dm_y;
  c4_il_b = c4_egb_x;
  c4_em_y = c4_lk_a * c4_il_b;
  c4_fgb_x = c4_theta_2;
  c4_ggb_x = c4_fgb_x;
  c4_ggb_x = muDoubleScalarCos(c4_ggb_x);
  c4_hgb_x = c4_theta_3;
  c4_igb_x = c4_hgb_x;
  c4_igb_x = muDoubleScalarCos(c4_igb_x);
  c4_mk_a = c4_ggb_x;
  c4_jl_b = c4_igb_x;
  c4_fm_y = c4_mk_a * c4_jl_b;
  c4_jgb_x = c4_theta_1;
  c4_kgb_x = c4_jgb_x;
  c4_kgb_x = muDoubleScalarSin(c4_kgb_x);
  c4_nk_a = c4_fm_y;
  c4_kl_b = c4_kgb_x;
  c4_gm_y = c4_nk_a * c4_kl_b;
  c4_ok_a = c4_xfb_x;
  c4_ll_b = c4_em_y - c4_gm_y;
  c4_hm_y = c4_ok_a * c4_ll_b;
  c4_pk_a = c4_wl_y;
  c4_ml_b = c4_cm_y - c4_hm_y;
  c4_im_y = c4_pk_a * c4_ml_b;
  c4_v_A = c4_im_y;
  c4_lgb_x = c4_v_A;
  c4_mgb_x = c4_lgb_x;
  c4_jm_y = c4_mgb_x / 20000.0;
  c4_ngb_x = c4_theta_1;
  c4_ogb_x = c4_ngb_x;
  c4_ogb_x = muDoubleScalarSin(c4_ogb_x);
  c4_nl_b = c4_ogb_x;
  c4_km_y = 39243.0 * c4_nl_b;
  c4_pgb_x = c4_theta_2;
  c4_qgb_x = c4_pgb_x;
  c4_qgb_x = muDoubleScalarSin(c4_qgb_x);
  c4_qk_a = c4_km_y;
  c4_ol_b = c4_qgb_x;
  c4_lm_y = c4_qk_a * c4_ol_b;
  c4_rgb_x = c4_theta_3;
  c4_sgb_x = c4_rgb_x;
  c4_sgb_x = muDoubleScalarSin(c4_sgb_x);
  c4_rk_a = c4_lm_y;
  c4_pl_b = c4_sgb_x;
  c4_mm_y = c4_rk_a * c4_pl_b;
  c4_w_A = c4_mm_y;
  c4_tgb_x = c4_w_A;
  c4_ugb_x = c4_tgb_x;
  c4_nm_y = c4_ugb_x / 100000.0;
  c4_vgb_x = c4_theta_2;
  c4_wgb_x = c4_vgb_x;
  c4_wgb_x = muDoubleScalarCos(c4_wgb_x);
  c4_ql_b = c4_wgb_x;
  c4_om_y = 39243.0 * c4_ql_b;
  c4_xgb_x = c4_theta_3;
  c4_ygb_x = c4_xgb_x;
  c4_ygb_x = muDoubleScalarCos(c4_ygb_x);
  c4_sk_a = c4_om_y;
  c4_rl_b = c4_ygb_x;
  c4_pm_y = c4_sk_a * c4_rl_b;
  c4_ahb_x = c4_theta_1;
  c4_bhb_x = c4_ahb_x;
  c4_bhb_x = muDoubleScalarSin(c4_bhb_x);
  c4_tk_a = c4_pm_y;
  c4_sl_b = c4_bhb_x;
  c4_qm_y = c4_tk_a * c4_sl_b;
  c4_x_A = c4_qm_y;
  c4_chb_x = c4_x_A;
  c4_dhb_x = c4_chb_x;
  c4_rm_y = c4_dhb_x / 100000.0;
  c4_ehb_x = c4_theta_6;
  c4_fhb_x = c4_ehb_x;
  c4_fhb_x = muDoubleScalarSin(c4_fhb_x);
  c4_ghb_x = c4_theta_4;
  c4_hhb_x = c4_ghb_x;
  c4_hhb_x = muDoubleScalarCos(c4_hhb_x);
  c4_ihb_x = c4_theta_2;
  c4_jhb_x = c4_ihb_x;
  c4_jhb_x = muDoubleScalarCos(c4_jhb_x);
  c4_khb_x = c4_theta_3;
  c4_lhb_x = c4_khb_x;
  c4_lhb_x = muDoubleScalarCos(c4_lhb_x);
  c4_uk_a = c4_jhb_x;
  c4_tl_b = c4_lhb_x;
  c4_sm_y = c4_uk_a * c4_tl_b;
  c4_mhb_x = c4_theta_2;
  c4_nhb_x = c4_mhb_x;
  c4_nhb_x = muDoubleScalarSin(c4_nhb_x);
  c4_ohb_x = c4_theta_3;
  c4_phb_x = c4_ohb_x;
  c4_phb_x = muDoubleScalarSin(c4_phb_x);
  c4_vk_a = c4_nhb_x;
  c4_ul_b = c4_phb_x;
  c4_tm_y = c4_vk_a * c4_ul_b;
  c4_wk_a = c4_hhb_x;
  c4_vl_b = c4_sm_y - c4_tm_y;
  c4_um_y = c4_wk_a * c4_vl_b;
  c4_qhb_x = c4_theta_4;
  c4_rhb_x = c4_qhb_x;
  c4_rhb_x = muDoubleScalarSin(c4_rhb_x);
  c4_shb_x = c4_theta_2;
  c4_thb_x = c4_shb_x;
  c4_thb_x = muDoubleScalarCos(c4_thb_x);
  c4_uhb_x = c4_theta_3;
  c4_vhb_x = c4_uhb_x;
  c4_vhb_x = muDoubleScalarSin(c4_vhb_x);
  c4_xk_a = c4_thb_x;
  c4_wl_b = c4_vhb_x;
  c4_vm_y = c4_xk_a * c4_wl_b;
  c4_whb_x = c4_theta_3;
  c4_xhb_x = c4_whb_x;
  c4_xhb_x = muDoubleScalarCos(c4_xhb_x);
  c4_yhb_x = c4_theta_2;
  c4_aib_x = c4_yhb_x;
  c4_aib_x = muDoubleScalarSin(c4_aib_x);
  c4_yk_a = c4_xhb_x;
  c4_xl_b = c4_aib_x;
  c4_wm_y = c4_yk_a * c4_xl_b;
  c4_al_a = c4_rhb_x;
  c4_yl_b = c4_vm_y + c4_wm_y;
  c4_xm_y = c4_al_a * c4_yl_b;
  c4_bl_a = c4_fhb_x;
  c4_am_b = c4_um_y - c4_xm_y;
  c4_ym_y = c4_bl_a * c4_am_b;
  c4_bib_x = c4_theta_5;
  c4_cib_x = c4_bib_x;
  c4_cib_x = muDoubleScalarCos(c4_cib_x);
  c4_dib_x = c4_theta_6;
  c4_eib_x = c4_dib_x;
  c4_eib_x = muDoubleScalarCos(c4_eib_x);
  c4_cl_a = c4_cib_x;
  c4_bm_b = c4_eib_x;
  c4_an_y = c4_cl_a * c4_bm_b;
  c4_fib_x = c4_theta_4;
  c4_gib_x = c4_fib_x;
  c4_gib_x = muDoubleScalarCos(c4_gib_x);
  c4_hib_x = c4_theta_2;
  c4_iib_x = c4_hib_x;
  c4_iib_x = muDoubleScalarCos(c4_iib_x);
  c4_jib_x = c4_theta_3;
  c4_kib_x = c4_jib_x;
  c4_kib_x = muDoubleScalarSin(c4_kib_x);
  c4_dl_a = c4_iib_x;
  c4_cm_b = c4_kib_x;
  c4_bn_y = c4_dl_a * c4_cm_b;
  c4_lib_x = c4_theta_3;
  c4_mib_x = c4_lib_x;
  c4_mib_x = muDoubleScalarCos(c4_mib_x);
  c4_nib_x = c4_theta_2;
  c4_oib_x = c4_nib_x;
  c4_oib_x = muDoubleScalarSin(c4_oib_x);
  c4_el_a = c4_mib_x;
  c4_dm_b = c4_oib_x;
  c4_cn_y = c4_el_a * c4_dm_b;
  c4_fl_a = c4_gib_x;
  c4_em_b = c4_bn_y + c4_cn_y;
  c4_dn_y = c4_fl_a * c4_em_b;
  c4_pib_x = c4_theta_4;
  c4_qib_x = c4_pib_x;
  c4_qib_x = muDoubleScalarSin(c4_qib_x);
  c4_rib_x = c4_theta_2;
  c4_sib_x = c4_rib_x;
  c4_sib_x = muDoubleScalarCos(c4_sib_x);
  c4_tib_x = c4_theta_3;
  c4_uib_x = c4_tib_x;
  c4_uib_x = muDoubleScalarCos(c4_uib_x);
  c4_gl_a = c4_sib_x;
  c4_fm_b = c4_uib_x;
  c4_en_y = c4_gl_a * c4_fm_b;
  c4_vib_x = c4_theta_2;
  c4_wib_x = c4_vib_x;
  c4_wib_x = muDoubleScalarSin(c4_wib_x);
  c4_xib_x = c4_theta_3;
  c4_yib_x = c4_xib_x;
  c4_yib_x = muDoubleScalarSin(c4_yib_x);
  c4_hl_a = c4_wib_x;
  c4_gm_b = c4_yib_x;
  c4_fn_y = c4_hl_a * c4_gm_b;
  c4_il_a = c4_qib_x;
  c4_hm_b = c4_en_y - c4_fn_y;
  c4_gn_y = c4_il_a * c4_hm_b;
  c4_jl_a = c4_an_y;
  c4_im_b = c4_dn_y + c4_gn_y;
  c4_hn_y = c4_jl_a * c4_im_b;
  c4_ajb_x = c4_theta_6;
  c4_bjb_x = c4_ajb_x;
  c4_bjb_x = muDoubleScalarCos(c4_bjb_x);
  c4_cjb_x = c4_theta_4;
  c4_djb_x = c4_cjb_x;
  c4_djb_x = muDoubleScalarCos(c4_djb_x);
  c4_ejb_x = c4_theta_2;
  c4_fjb_x = c4_ejb_x;
  c4_fjb_x = muDoubleScalarCos(c4_fjb_x);
  c4_gjb_x = c4_theta_3;
  c4_hjb_x = c4_gjb_x;
  c4_hjb_x = muDoubleScalarCos(c4_hjb_x);
  c4_kl_a = c4_fjb_x;
  c4_jm_b = c4_hjb_x;
  c4_in_y = c4_kl_a * c4_jm_b;
  c4_ijb_x = c4_theta_2;
  c4_jjb_x = c4_ijb_x;
  c4_jjb_x = muDoubleScalarSin(c4_jjb_x);
  c4_kjb_x = c4_theta_3;
  c4_ljb_x = c4_kjb_x;
  c4_ljb_x = muDoubleScalarSin(c4_ljb_x);
  c4_ll_a = c4_jjb_x;
  c4_km_b = c4_ljb_x;
  c4_jn_y = c4_ll_a * c4_km_b;
  c4_ml_a = c4_djb_x;
  c4_lm_b = c4_in_y - c4_jn_y;
  c4_kn_y = c4_ml_a * c4_lm_b;
  c4_mjb_x = c4_theta_4;
  c4_njb_x = c4_mjb_x;
  c4_njb_x = muDoubleScalarSin(c4_njb_x);
  c4_ojb_x = c4_theta_2;
  c4_pjb_x = c4_ojb_x;
  c4_pjb_x = muDoubleScalarCos(c4_pjb_x);
  c4_qjb_x = c4_theta_3;
  c4_rjb_x = c4_qjb_x;
  c4_rjb_x = muDoubleScalarSin(c4_rjb_x);
  c4_nl_a = c4_pjb_x;
  c4_mm_b = c4_rjb_x;
  c4_ln_y = c4_nl_a * c4_mm_b;
  c4_sjb_x = c4_theta_3;
  c4_tjb_x = c4_sjb_x;
  c4_tjb_x = muDoubleScalarCos(c4_tjb_x);
  c4_ujb_x = c4_theta_2;
  c4_vjb_x = c4_ujb_x;
  c4_vjb_x = muDoubleScalarSin(c4_vjb_x);
  c4_ol_a = c4_tjb_x;
  c4_nm_b = c4_vjb_x;
  c4_mn_y = c4_ol_a * c4_nm_b;
  c4_pl_a = c4_njb_x;
  c4_om_b = c4_ln_y + c4_mn_y;
  c4_nn_y = c4_pl_a * c4_om_b;
  c4_ql_a = c4_bjb_x;
  c4_pm_b = c4_kn_y - c4_nn_y;
  c4_on_y = c4_ql_a * c4_pm_b;
  c4_wjb_x = c4_theta_5;
  c4_xjb_x = c4_wjb_x;
  c4_xjb_x = muDoubleScalarCos(c4_xjb_x);
  c4_yjb_x = c4_theta_6;
  c4_akb_x = c4_yjb_x;
  c4_akb_x = muDoubleScalarSin(c4_akb_x);
  c4_rl_a = c4_xjb_x;
  c4_qm_b = c4_akb_x;
  c4_pn_y = c4_rl_a * c4_qm_b;
  c4_bkb_x = c4_theta_4;
  c4_ckb_x = c4_bkb_x;
  c4_ckb_x = muDoubleScalarCos(c4_ckb_x);
  c4_dkb_x = c4_theta_2;
  c4_ekb_x = c4_dkb_x;
  c4_ekb_x = muDoubleScalarCos(c4_ekb_x);
  c4_fkb_x = c4_theta_3;
  c4_gkb_x = c4_fkb_x;
  c4_gkb_x = muDoubleScalarSin(c4_gkb_x);
  c4_sl_a = c4_ekb_x;
  c4_rm_b = c4_gkb_x;
  c4_qn_y = c4_sl_a * c4_rm_b;
  c4_hkb_x = c4_theta_3;
  c4_ikb_x = c4_hkb_x;
  c4_ikb_x = muDoubleScalarCos(c4_ikb_x);
  c4_jkb_x = c4_theta_2;
  c4_kkb_x = c4_jkb_x;
  c4_kkb_x = muDoubleScalarSin(c4_kkb_x);
  c4_tl_a = c4_ikb_x;
  c4_sm_b = c4_kkb_x;
  c4_rn_y = c4_tl_a * c4_sm_b;
  c4_ul_a = c4_ckb_x;
  c4_tm_b = c4_qn_y + c4_rn_y;
  c4_sn_y = c4_ul_a * c4_tm_b;
  c4_lkb_x = c4_theta_4;
  c4_mkb_x = c4_lkb_x;
  c4_mkb_x = muDoubleScalarSin(c4_mkb_x);
  c4_nkb_x = c4_theta_2;
  c4_okb_x = c4_nkb_x;
  c4_okb_x = muDoubleScalarCos(c4_okb_x);
  c4_pkb_x = c4_theta_3;
  c4_qkb_x = c4_pkb_x;
  c4_qkb_x = muDoubleScalarCos(c4_qkb_x);
  c4_vl_a = c4_okb_x;
  c4_um_b = c4_qkb_x;
  c4_tn_y = c4_vl_a * c4_um_b;
  c4_rkb_x = c4_theta_2;
  c4_skb_x = c4_rkb_x;
  c4_skb_x = muDoubleScalarSin(c4_skb_x);
  c4_tkb_x = c4_theta_3;
  c4_ukb_x = c4_tkb_x;
  c4_ukb_x = muDoubleScalarSin(c4_ukb_x);
  c4_wl_a = c4_skb_x;
  c4_vm_b = c4_ukb_x;
  c4_un_y = c4_wl_a * c4_vm_b;
  c4_xl_a = c4_mkb_x;
  c4_wm_b = c4_tn_y - c4_un_y;
  c4_vn_y = c4_xl_a * c4_wm_b;
  c4_yl_a = c4_pn_y;
  c4_xm_b = c4_sn_y + c4_vn_y;
  c4_wn_y = c4_yl_a * c4_xm_b;
  c4_vkb_x = c4_theta_5;
  c4_wkb_x = c4_vkb_x;
  c4_wkb_x = muDoubleScalarSin(c4_wkb_x);
  c4_xkb_x = c4_theta_4;
  c4_ykb_x = c4_xkb_x;
  c4_ykb_x = muDoubleScalarCos(c4_ykb_x);
  c4_alb_x = c4_theta_2;
  c4_blb_x = c4_alb_x;
  c4_blb_x = muDoubleScalarCos(c4_blb_x);
  c4_clb_x = c4_theta_3;
  c4_dlb_x = c4_clb_x;
  c4_dlb_x = muDoubleScalarSin(c4_dlb_x);
  c4_am_a = c4_blb_x;
  c4_ym_b = c4_dlb_x;
  c4_xn_y = c4_am_a * c4_ym_b;
  c4_elb_x = c4_theta_3;
  c4_flb_x = c4_elb_x;
  c4_flb_x = muDoubleScalarCos(c4_flb_x);
  c4_glb_x = c4_theta_2;
  c4_hlb_x = c4_glb_x;
  c4_hlb_x = muDoubleScalarSin(c4_hlb_x);
  c4_bm_a = c4_flb_x;
  c4_an_b = c4_hlb_x;
  c4_yn_y = c4_bm_a * c4_an_b;
  c4_cm_a = c4_ykb_x;
  c4_bn_b = c4_xn_y + c4_yn_y;
  c4_ao_y = c4_cm_a * c4_bn_b;
  c4_ilb_x = c4_theta_4;
  c4_jlb_x = c4_ilb_x;
  c4_jlb_x = muDoubleScalarSin(c4_jlb_x);
  c4_klb_x = c4_theta_2;
  c4_llb_x = c4_klb_x;
  c4_llb_x = muDoubleScalarCos(c4_llb_x);
  c4_mlb_x = c4_theta_3;
  c4_nlb_x = c4_mlb_x;
  c4_nlb_x = muDoubleScalarCos(c4_nlb_x);
  c4_dm_a = c4_llb_x;
  c4_cn_b = c4_nlb_x;
  c4_bo_y = c4_dm_a * c4_cn_b;
  c4_olb_x = c4_theta_2;
  c4_plb_x = c4_olb_x;
  c4_plb_x = muDoubleScalarSin(c4_plb_x);
  c4_qlb_x = c4_theta_3;
  c4_rlb_x = c4_qlb_x;
  c4_rlb_x = muDoubleScalarSin(c4_rlb_x);
  c4_em_a = c4_plb_x;
  c4_dn_b = c4_rlb_x;
  c4_co_y = c4_em_a * c4_dn_b;
  c4_fm_a = c4_jlb_x;
  c4_en_b = c4_bo_y - c4_co_y;
  c4_do_y = c4_fm_a * c4_en_b;
  c4_gm_a = -c4_wkb_x;
  c4_fn_b = c4_ao_y + c4_do_y;
  c4_eo_y = c4_gm_a * c4_fn_b;
  c4_slb_x = c4_theta_6;
  c4_tlb_x = c4_slb_x;
  c4_tlb_x = muDoubleScalarCos(c4_tlb_x);
  c4_gn_b = c4_tlb_x;
  c4_fo_y = 121.0 * c4_gn_b;
  c4_ulb_x = c4_theta_4;
  c4_vlb_x = c4_ulb_x;
  c4_vlb_x = muDoubleScalarCos(c4_vlb_x);
  c4_wlb_x = c4_theta_2;
  c4_xlb_x = c4_wlb_x;
  c4_xlb_x = muDoubleScalarCos(c4_xlb_x);
  c4_ylb_x = c4_theta_3;
  c4_amb_x = c4_ylb_x;
  c4_amb_x = muDoubleScalarCos(c4_amb_x);
  c4_hm_a = c4_xlb_x;
  c4_hn_b = c4_amb_x;
  c4_go_y = c4_hm_a * c4_hn_b;
  c4_bmb_x = c4_theta_2;
  c4_cmb_x = c4_bmb_x;
  c4_cmb_x = muDoubleScalarSin(c4_cmb_x);
  c4_dmb_x = c4_theta_3;
  c4_emb_x = c4_dmb_x;
  c4_emb_x = muDoubleScalarSin(c4_emb_x);
  c4_im_a = c4_cmb_x;
  c4_in_b = c4_emb_x;
  c4_ho_y = c4_im_a * c4_in_b;
  c4_jm_a = c4_vlb_x;
  c4_jn_b = c4_go_y - c4_ho_y;
  c4_io_y = c4_jm_a * c4_jn_b;
  c4_fmb_x = c4_theta_4;
  c4_gmb_x = c4_fmb_x;
  c4_gmb_x = muDoubleScalarSin(c4_gmb_x);
  c4_hmb_x = c4_theta_2;
  c4_imb_x = c4_hmb_x;
  c4_imb_x = muDoubleScalarCos(c4_imb_x);
  c4_jmb_x = c4_theta_3;
  c4_kmb_x = c4_jmb_x;
  c4_kmb_x = muDoubleScalarSin(c4_kmb_x);
  c4_km_a = c4_imb_x;
  c4_kn_b = c4_kmb_x;
  c4_jo_y = c4_km_a * c4_kn_b;
  c4_lmb_x = c4_theta_3;
  c4_mmb_x = c4_lmb_x;
  c4_mmb_x = muDoubleScalarCos(c4_mmb_x);
  c4_nmb_x = c4_theta_2;
  c4_omb_x = c4_nmb_x;
  c4_omb_x = muDoubleScalarSin(c4_omb_x);
  c4_lm_a = c4_mmb_x;
  c4_ln_b = c4_omb_x;
  c4_ko_y = c4_lm_a * c4_ln_b;
  c4_mm_a = c4_gmb_x;
  c4_mn_b = c4_jo_y + c4_ko_y;
  c4_lo_y = c4_mm_a * c4_mn_b;
  c4_nm_a = c4_fo_y;
  c4_nn_b = c4_io_y - c4_lo_y;
  c4_mo_y = c4_nm_a * c4_nn_b;
  c4_y_A = c4_mo_y;
  c4_pmb_x = c4_y_A;
  c4_qmb_x = c4_pmb_x;
  c4_no_y = c4_qmb_x / 20000.0;
  c4_rmb_x = c4_theta_2;
  c4_smb_x = c4_rmb_x;
  c4_smb_x = muDoubleScalarCos(c4_smb_x);
  c4_on_b = c4_smb_x;
  c4_oo_y = 39243.0 * c4_on_b;
  c4_tmb_x = c4_theta_3;
  c4_umb_x = c4_tmb_x;
  c4_umb_x = muDoubleScalarSin(c4_umb_x);
  c4_om_a = c4_oo_y;
  c4_pn_b = c4_umb_x;
  c4_po_y = c4_om_a * c4_pn_b;
  c4_ab_A = c4_po_y;
  c4_vmb_x = c4_ab_A;
  c4_wmb_x = c4_vmb_x;
  c4_qo_y = c4_wmb_x / 100000.0;
  c4_xmb_x = c4_theta_3;
  c4_ymb_x = c4_xmb_x;
  c4_ymb_x = muDoubleScalarCos(c4_ymb_x);
  c4_qn_b = c4_ymb_x;
  c4_ro_y = 39243.0 * c4_qn_b;
  c4_anb_x = c4_theta_2;
  c4_bnb_x = c4_anb_x;
  c4_bnb_x = muDoubleScalarSin(c4_bnb_x);
  c4_pm_a = c4_ro_y;
  c4_rn_b = c4_bnb_x;
  c4_so_y = c4_pm_a * c4_rn_b;
  c4_bb_A = c4_so_y;
  c4_cnb_x = c4_bb_A;
  c4_dnb_x = c4_cnb_x;
  c4_to_y = c4_dnb_x / 100000.0;
  c4_enb_x = c4_theta_2;
  c4_fnb_x = c4_enb_x;
  c4_fnb_x = muDoubleScalarSin(c4_fnb_x);
  c4_sn_b = c4_fnb_x;
  c4_uo_y = 17.0 * c4_sn_b;
  c4_cb_A = c4_uo_y;
  c4_gnb_x = c4_cb_A;
  c4_hnb_x = c4_gnb_x;
  c4_vo_y = c4_hnb_x / 40.0;
  c4_inb_x = c4_theta_5;
  c4_jnb_x = c4_inb_x;
  c4_jnb_x = muDoubleScalarSin(c4_jnb_x);
  c4_tn_b = c4_jnb_x;
  c4_wo_y = 183.0 * c4_tn_b;
  c4_knb_x = c4_theta_4;
  c4_lnb_x = c4_knb_x;
  c4_lnb_x = muDoubleScalarCos(c4_lnb_x);
  c4_mnb_x = c4_theta_2;
  c4_nnb_x = c4_mnb_x;
  c4_nnb_x = muDoubleScalarCos(c4_nnb_x);
  c4_onb_x = c4_theta_3;
  c4_pnb_x = c4_onb_x;
  c4_pnb_x = muDoubleScalarSin(c4_pnb_x);
  c4_qm_a = c4_nnb_x;
  c4_un_b = c4_pnb_x;
  c4_xo_y = c4_qm_a * c4_un_b;
  c4_qnb_x = c4_theta_3;
  c4_rnb_x = c4_qnb_x;
  c4_rnb_x = muDoubleScalarCos(c4_rnb_x);
  c4_snb_x = c4_theta_2;
  c4_tnb_x = c4_snb_x;
  c4_tnb_x = muDoubleScalarSin(c4_tnb_x);
  c4_rm_a = c4_rnb_x;
  c4_vn_b = c4_tnb_x;
  c4_yo_y = c4_rm_a * c4_vn_b;
  c4_sm_a = c4_lnb_x;
  c4_wn_b = c4_xo_y + c4_yo_y;
  c4_ap_y = c4_sm_a * c4_wn_b;
  c4_unb_x = c4_theta_4;
  c4_vnb_x = c4_unb_x;
  c4_vnb_x = muDoubleScalarSin(c4_vnb_x);
  c4_wnb_x = c4_theta_2;
  c4_xnb_x = c4_wnb_x;
  c4_xnb_x = muDoubleScalarCos(c4_xnb_x);
  c4_ynb_x = c4_theta_3;
  c4_aob_x = c4_ynb_x;
  c4_aob_x = muDoubleScalarCos(c4_aob_x);
  c4_tm_a = c4_xnb_x;
  c4_xn_b = c4_aob_x;
  c4_bp_y = c4_tm_a * c4_xn_b;
  c4_bob_x = c4_theta_2;
  c4_cob_x = c4_bob_x;
  c4_cob_x = muDoubleScalarSin(c4_cob_x);
  c4_dob_x = c4_theta_3;
  c4_eob_x = c4_dob_x;
  c4_eob_x = muDoubleScalarSin(c4_eob_x);
  c4_um_a = c4_cob_x;
  c4_yn_b = c4_eob_x;
  c4_cp_y = c4_um_a * c4_yn_b;
  c4_vm_a = c4_vnb_x;
  c4_ao_b = c4_bp_y - c4_cp_y;
  c4_dp_y = c4_vm_a * c4_ao_b;
  c4_wm_a = c4_wo_y;
  c4_bo_b = c4_ap_y + c4_dp_y;
  c4_ep_y = c4_wm_a * c4_bo_b;
  c4_db_A = c4_ep_y;
  c4_fob_x = c4_db_A;
  c4_gob_x = c4_fob_x;
  c4_fp_y = c4_gob_x / 2000.0;
  c4_hob_x = c4_theta_6;
  c4_iob_x = c4_hob_x;
  c4_iob_x = muDoubleScalarSin(c4_iob_x);
  c4_co_b = c4_iob_x;
  c4_gp_y = 347.0 * c4_co_b;
  c4_job_x = c4_theta_4;
  c4_kob_x = c4_job_x;
  c4_kob_x = muDoubleScalarCos(c4_kob_x);
  c4_lob_x = c4_theta_2;
  c4_mob_x = c4_lob_x;
  c4_mob_x = muDoubleScalarCos(c4_mob_x);
  c4_nob_x = c4_theta_3;
  c4_oob_x = c4_nob_x;
  c4_oob_x = muDoubleScalarCos(c4_oob_x);
  c4_xm_a = c4_mob_x;
  c4_do_b = c4_oob_x;
  c4_hp_y = c4_xm_a * c4_do_b;
  c4_pob_x = c4_theta_2;
  c4_qob_x = c4_pob_x;
  c4_qob_x = muDoubleScalarSin(c4_qob_x);
  c4_rob_x = c4_theta_3;
  c4_sob_x = c4_rob_x;
  c4_sob_x = muDoubleScalarSin(c4_sob_x);
  c4_ym_a = c4_qob_x;
  c4_eo_b = c4_sob_x;
  c4_ip_y = c4_ym_a * c4_eo_b;
  c4_an_a = c4_kob_x;
  c4_fo_b = c4_hp_y - c4_ip_y;
  c4_jp_y = c4_an_a * c4_fo_b;
  c4_tob_x = c4_theta_4;
  c4_uob_x = c4_tob_x;
  c4_uob_x = muDoubleScalarSin(c4_uob_x);
  c4_vob_x = c4_theta_2;
  c4_wob_x = c4_vob_x;
  c4_wob_x = muDoubleScalarCos(c4_wob_x);
  c4_xob_x = c4_theta_3;
  c4_yob_x = c4_xob_x;
  c4_yob_x = muDoubleScalarSin(c4_yob_x);
  c4_bn_a = c4_wob_x;
  c4_go_b = c4_yob_x;
  c4_kp_y = c4_bn_a * c4_go_b;
  c4_apb_x = c4_theta_3;
  c4_bpb_x = c4_apb_x;
  c4_bpb_x = muDoubleScalarCos(c4_bpb_x);
  c4_cpb_x = c4_theta_2;
  c4_dpb_x = c4_cpb_x;
  c4_dpb_x = muDoubleScalarSin(c4_dpb_x);
  c4_cn_a = c4_bpb_x;
  c4_ho_b = c4_dpb_x;
  c4_lp_y = c4_cn_a * c4_ho_b;
  c4_dn_a = c4_uob_x;
  c4_io_b = c4_kp_y + c4_lp_y;
  c4_mp_y = c4_dn_a * c4_io_b;
  c4_en_a = c4_gp_y;
  c4_jo_b = c4_jp_y - c4_mp_y;
  c4_np_y = c4_en_a * c4_jo_b;
  c4_eb_A = c4_np_y;
  c4_epb_x = c4_eb_A;
  c4_fpb_x = c4_epb_x;
  c4_op_y = c4_fpb_x / 20000.0;
  c4_gpb_x = c4_theta_4;
  c4_hpb_x = c4_gpb_x;
  c4_hpb_x = muDoubleScalarCos(c4_hpb_x);
  c4_ko_b = c4_hpb_x;
  c4_pp_y = 93.0 * c4_ko_b;
  c4_ipb_x = c4_theta_2;
  c4_jpb_x = c4_ipb_x;
  c4_jpb_x = muDoubleScalarCos(c4_jpb_x);
  c4_kpb_x = c4_theta_3;
  c4_lpb_x = c4_kpb_x;
  c4_lpb_x = muDoubleScalarCos(c4_lpb_x);
  c4_fn_a = c4_jpb_x;
  c4_lo_b = c4_lpb_x;
  c4_qp_y = c4_fn_a * c4_lo_b;
  c4_mpb_x = c4_theta_2;
  c4_npb_x = c4_mpb_x;
  c4_npb_x = muDoubleScalarSin(c4_npb_x);
  c4_opb_x = c4_theta_3;
  c4_ppb_x = c4_opb_x;
  c4_ppb_x = muDoubleScalarSin(c4_ppb_x);
  c4_gn_a = c4_npb_x;
  c4_mo_b = c4_ppb_x;
  c4_rp_y = c4_gn_a * c4_mo_b;
  c4_hn_a = c4_pp_y;
  c4_no_b = c4_qp_y - c4_rp_y;
  c4_sp_y = c4_hn_a * c4_no_b;
  c4_fb_A = c4_sp_y;
  c4_qpb_x = c4_fb_A;
  c4_rpb_x = c4_qpb_x;
  c4_tp_y = c4_rpb_x / 1000.0;
  c4_spb_x = c4_theta_4;
  c4_tpb_x = c4_spb_x;
  c4_tpb_x = muDoubleScalarSin(c4_tpb_x);
  c4_oo_b = c4_tpb_x;
  c4_up_y = 93.0 * c4_oo_b;
  c4_upb_x = c4_theta_2;
  c4_vpb_x = c4_upb_x;
  c4_vpb_x = muDoubleScalarCos(c4_vpb_x);
  c4_wpb_x = c4_theta_3;
  c4_xpb_x = c4_wpb_x;
  c4_xpb_x = muDoubleScalarSin(c4_xpb_x);
  c4_in_a = c4_vpb_x;
  c4_po_b = c4_xpb_x;
  c4_vp_y = c4_in_a * c4_po_b;
  c4_ypb_x = c4_theta_3;
  c4_aqb_x = c4_ypb_x;
  c4_aqb_x = muDoubleScalarCos(c4_aqb_x);
  c4_bqb_x = c4_theta_2;
  c4_cqb_x = c4_bqb_x;
  c4_cqb_x = muDoubleScalarSin(c4_cqb_x);
  c4_jn_a = c4_aqb_x;
  c4_qo_b = c4_cqb_x;
  c4_wp_y = c4_jn_a * c4_qo_b;
  c4_kn_a = c4_up_y;
  c4_ro_b = c4_vp_y + c4_wp_y;
  c4_xp_y = c4_kn_a * c4_ro_b;
  c4_gb_A = c4_xp_y;
  c4_dqb_x = c4_gb_A;
  c4_eqb_x = c4_dqb_x;
  c4_yp_y = c4_eqb_x / 1000.0;
  c4_fqb_x = c4_theta_5;
  c4_gqb_x = c4_fqb_x;
  c4_gqb_x = muDoubleScalarCos(c4_gqb_x);
  c4_so_b = c4_gqb_x;
  c4_aq_y = 347.0 * c4_so_b;
  c4_hqb_x = c4_theta_6;
  c4_iqb_x = c4_hqb_x;
  c4_iqb_x = muDoubleScalarCos(c4_iqb_x);
  c4_ln_a = c4_aq_y;
  c4_to_b = c4_iqb_x;
  c4_bq_y = c4_ln_a * c4_to_b;
  c4_jqb_x = c4_theta_4;
  c4_kqb_x = c4_jqb_x;
  c4_kqb_x = muDoubleScalarCos(c4_kqb_x);
  c4_lqb_x = c4_theta_2;
  c4_mqb_x = c4_lqb_x;
  c4_mqb_x = muDoubleScalarCos(c4_mqb_x);
  c4_nqb_x = c4_theta_3;
  c4_oqb_x = c4_nqb_x;
  c4_oqb_x = muDoubleScalarSin(c4_oqb_x);
  c4_mn_a = c4_mqb_x;
  c4_uo_b = c4_oqb_x;
  c4_cq_y = c4_mn_a * c4_uo_b;
  c4_pqb_x = c4_theta_3;
  c4_qqb_x = c4_pqb_x;
  c4_qqb_x = muDoubleScalarCos(c4_qqb_x);
  c4_rqb_x = c4_theta_2;
  c4_sqb_x = c4_rqb_x;
  c4_sqb_x = muDoubleScalarSin(c4_sqb_x);
  c4_nn_a = c4_qqb_x;
  c4_vo_b = c4_sqb_x;
  c4_dq_y = c4_nn_a * c4_vo_b;
  c4_on_a = c4_kqb_x;
  c4_wo_b = c4_cq_y + c4_dq_y;
  c4_eq_y = c4_on_a * c4_wo_b;
  c4_tqb_x = c4_theta_4;
  c4_uqb_x = c4_tqb_x;
  c4_uqb_x = muDoubleScalarSin(c4_uqb_x);
  c4_vqb_x = c4_theta_2;
  c4_wqb_x = c4_vqb_x;
  c4_wqb_x = muDoubleScalarCos(c4_wqb_x);
  c4_xqb_x = c4_theta_3;
  c4_yqb_x = c4_xqb_x;
  c4_yqb_x = muDoubleScalarCos(c4_yqb_x);
  c4_pn_a = c4_wqb_x;
  c4_xo_b = c4_yqb_x;
  c4_fq_y = c4_pn_a * c4_xo_b;
  c4_arb_x = c4_theta_2;
  c4_brb_x = c4_arb_x;
  c4_brb_x = muDoubleScalarSin(c4_brb_x);
  c4_crb_x = c4_theta_3;
  c4_drb_x = c4_crb_x;
  c4_drb_x = muDoubleScalarSin(c4_drb_x);
  c4_qn_a = c4_brb_x;
  c4_yo_b = c4_drb_x;
  c4_gq_y = c4_qn_a * c4_yo_b;
  c4_rn_a = c4_uqb_x;
  c4_ap_b = c4_fq_y - c4_gq_y;
  c4_hq_y = c4_rn_a * c4_ap_b;
  c4_sn_a = c4_bq_y;
  c4_bp_b = c4_eq_y + c4_hq_y;
  c4_iq_y = c4_sn_a * c4_bp_b;
  c4_hb_A = c4_iq_y;
  c4_erb_x = c4_hb_A;
  c4_frb_x = c4_erb_x;
  c4_jq_y = c4_frb_x / 20000.0;
  c4_grb_x = c4_theta_5;
  c4_hrb_x = c4_grb_x;
  c4_hrb_x = muDoubleScalarCos(c4_hrb_x);
  c4_cp_b = c4_hrb_x;
  c4_kq_y = 121.0 * c4_cp_b;
  c4_irb_x = c4_theta_6;
  c4_jrb_x = c4_irb_x;
  c4_jrb_x = muDoubleScalarSin(c4_jrb_x);
  c4_tn_a = c4_kq_y;
  c4_dp_b = c4_jrb_x;
  c4_lq_y = c4_tn_a * c4_dp_b;
  c4_krb_x = c4_theta_4;
  c4_lrb_x = c4_krb_x;
  c4_lrb_x = muDoubleScalarCos(c4_lrb_x);
  c4_mrb_x = c4_theta_2;
  c4_nrb_x = c4_mrb_x;
  c4_nrb_x = muDoubleScalarCos(c4_nrb_x);
  c4_orb_x = c4_theta_3;
  c4_prb_x = c4_orb_x;
  c4_prb_x = muDoubleScalarSin(c4_prb_x);
  c4_un_a = c4_nrb_x;
  c4_ep_b = c4_prb_x;
  c4_mq_y = c4_un_a * c4_ep_b;
  c4_qrb_x = c4_theta_3;
  c4_rrb_x = c4_qrb_x;
  c4_rrb_x = muDoubleScalarCos(c4_rrb_x);
  c4_srb_x = c4_theta_2;
  c4_trb_x = c4_srb_x;
  c4_trb_x = muDoubleScalarSin(c4_trb_x);
  c4_vn_a = c4_rrb_x;
  c4_fp_b = c4_trb_x;
  c4_nq_y = c4_vn_a * c4_fp_b;
  c4_wn_a = c4_lrb_x;
  c4_gp_b = c4_mq_y + c4_nq_y;
  c4_oq_y = c4_wn_a * c4_gp_b;
  c4_urb_x = c4_theta_4;
  c4_vrb_x = c4_urb_x;
  c4_vrb_x = muDoubleScalarSin(c4_vrb_x);
  c4_wrb_x = c4_theta_2;
  c4_xrb_x = c4_wrb_x;
  c4_xrb_x = muDoubleScalarCos(c4_xrb_x);
  c4_yrb_x = c4_theta_3;
  c4_asb_x = c4_yrb_x;
  c4_asb_x = muDoubleScalarCos(c4_asb_x);
  c4_xn_a = c4_xrb_x;
  c4_hp_b = c4_asb_x;
  c4_pq_y = c4_xn_a * c4_hp_b;
  c4_bsb_x = c4_theta_2;
  c4_csb_x = c4_bsb_x;
  c4_csb_x = muDoubleScalarSin(c4_csb_x);
  c4_dsb_x = c4_theta_3;
  c4_esb_x = c4_dsb_x;
  c4_esb_x = muDoubleScalarSin(c4_esb_x);
  c4_yn_a = c4_csb_x;
  c4_ip_b = c4_esb_x;
  c4_qq_y = c4_yn_a * c4_ip_b;
  c4_ao_a = c4_vrb_x;
  c4_jp_b = c4_pq_y - c4_qq_y;
  c4_rq_y = c4_ao_a * c4_jp_b;
  c4_bo_a = c4_lq_y;
  c4_kp_b = c4_oq_y + c4_rq_y;
  c4_sq_y = c4_bo_a * c4_kp_b;
  c4_ib_A = c4_sq_y;
  c4_fsb_x = c4_ib_A;
  c4_gsb_x = c4_fsb_x;
  c4_tq_y = c4_gsb_x / 20000.0;
  c4_T[0] = c4_m_y - c4_x_y;
  c4_T[4] = c4_lb_y - c4_wb_y;
  c4_T[8] = c4_xb_y + c4_jc_y;
  c4_T[12] = ((((((((((c4_lc_y - c4_oc_y) + c4_rc_y) + c4_hd_y) + c4_od_y) -
                   c4_ee_y) - c4_le_y) - c4_ye_y) + c4_mf_y) - c4_ag_y) +
              c4_eg_y) - c4_ig_y;
  c4_T[1] = c4_vg_y - c4_hh_y;
  c4_T[5] = c4_uh_y - c4_gi_y;
  c4_T[9] = c4_ri_y - c4_si_y;
  c4_T[13] = ((((((((((c4_aj_y - c4_dj_y) - c4_gj_y) - c4_ij_y) - c4_xj_y) -
                   c4_fk_y) + c4_uk_y) - c4_il_y) + c4_vl_y) - c4_jm_y) +
              c4_nm_y) - c4_rm_y;
  c4_T[2] = c4_ym_y + c4_hn_y;
  c4_T[6] = c4_on_y - c4_wn_y;
  c4_T[10] = c4_eo_y;
  c4_T[14] = (((((((((c4_no_y - c4_qo_y) - c4_to_y) - c4_vo_y) - c4_fp_y) +
                  c4_op_y) - c4_tp_y) + c4_yp_y) + c4_jq_y) - c4_tq_y) + 0.0892;
  c4_i8 = 0;
  for (c4_i9 = 0; c4_i9 < 4; c4_i9++) {
    c4_T[c4_i8 + 3] = c4_dv2[c4_i9];
    c4_i8 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 107);
  c4_i10 = 0;
  c4_i11 = 0;
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
      c4_R[c4_i13 + c4_i10] = c4_T[c4_i13 + c4_i11];
    }

    c4_i10 += 3;
    c4_i11 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 108);
  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_d[c4_i14] = c4_T[c4_i14 + 12];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -108);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    (*c4_b_d)[c4_i15] = c4_d[c4_i15];
  }

  for (c4_i16 = 0; c4_i16 < 9; c4_i16++) {
    (*c4_b_R)[c4_i16] = c4_R[c4_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc4_JointSpaceControl_BestInertia
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  real_T c4_b_inData[9];
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i17 = 0;
  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
      c4_b_inData[c4_i19 + c4_i17] = (*(real_T (*)[9])c4_inData)[c4_i19 + c4_i17];
    }

    c4_i17 += 3;
  }

  c4_i20 = 0;
  for (c4_i21 = 0; c4_i21 < 3; c4_i21++) {
    for (c4_i22 = 0; c4_i22 < 3; c4_i22++) {
      c4_u[c4_i22 + c4_i20] = c4_b_inData[c4_i22 + c4_i20];
    }

    c4_i20 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, const mxArray *c4_R, const char_T *c4_identifier, real_T c4_y
  [9])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_R), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_R);
}

static void c4_b_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9])
{
  real_T c4_dv3[9];
  int32_T c4_i23;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i23 = 0; c4_i23 < 9; c4_i23++) {
    c4_y[c4_i23] = c4_dv3[c4_i23];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_R;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[9];
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_R = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_R), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_R);
  c4_i24 = 0;
  for (c4_i25 = 0; c4_i25 < 3; c4_i25++) {
    for (c4_i26 = 0; c4_i26 < 3; c4_i26++) {
      (*(real_T (*)[9])c4_outData)[c4_i26 + c4_i24] = c4_y[c4_i26 + c4_i24];
    }

    c4_i24 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i27;
  real_T c4_b_inData[3];
  int32_T c4_i28;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i27 = 0; c4_i27 < 3; c4_i27++) {
    c4_b_inData[c4_i27] = (*(real_T (*)[3])c4_inData)[c4_i27];
  }

  for (c4_i28 = 0; c4_i28 < 3; c4_i28++) {
    c4_u[c4_i28] = c4_b_inData[c4_i28];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_d, const char_T *c4_identifier, real_T c4_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d);
}

static void c4_d_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3])
{
  real_T c4_dv4[3];
  int32_T c4_i29;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i29 = 0; c4_i29 < 3; c4_i29++) {
    c4_y[c4_i29] = c4_dv4[c4_i29];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_d;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i30;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_d = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d);
  for (c4_i30 = 0; c4_i30 < 3; c4_i30++) {
    (*(real_T (*)[3])c4_outData)[c4_i30] = c4_y[c4_i30];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i31;
  real_T c4_b_inData[6];
  int32_T c4_i32;
  real_T c4_u[6];
  const mxArray *c4_y = NULL;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i31 = 0; c4_i31 < 6; c4_i31++) {
    c4_b_inData[c4_i31] = (*(real_T (*)[6])c4_inData)[c4_i31];
  }

  for (c4_i32 = 0; c4_i32 < 6; c4_i32++) {
    c4_u[c4_i32] = c4_b_inData[c4_i32];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  real_T c4_b_inData[16];
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  real_T c4_u[16];
  const mxArray *c4_y = NULL;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i33 = 0;
  for (c4_i34 = 0; c4_i34 < 4; c4_i34++) {
    for (c4_i35 = 0; c4_i35 < 4; c4_i35++) {
      c4_b_inData[c4_i35 + c4_i33] = (*(real_T (*)[16])c4_inData)[c4_i35 +
        c4_i33];
    }

    c4_i33 += 4;
  }

  c4_i36 = 0;
  for (c4_i37 = 0; c4_i37 < 4; c4_i37++) {
    for (c4_i38 = 0; c4_i38 < 4; c4_i38++) {
      c4_u[c4_i38 + c4_i36] = c4_b_inData[c4_i38 + c4_i36];
    }

    c4_i36 += 4;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[16])
{
  real_T c4_dv5[16];
  int32_T c4_i39;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv5, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c4_i39 = 0; c4_i39 < 16; c4_i39++) {
    c4_y[c4_i39] = c4_dv5[c4_i39];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_T;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[16];
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_T = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_T), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_T);
  c4_i40 = 0;
  for (c4_i41 = 0; c4_i41 < 4; c4_i41++) {
    for (c4_i42 = 0; c4_i42 < 4; c4_i42++) {
      (*(real_T (*)[16])c4_outData)[c4_i42 + c4_i40] = c4_y[c4_i42 + c4_i40];
    }

    c4_i40 += 4;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_JointSpaceControl_BestInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[9];
  c4_ResolvedFunctionInfo (*c4_b_info)[9];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i43;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[9])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "cos";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c4_b_info)[0].fileTimeLo = 1343851972U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c4_b_info)[1].name = "eml_scalar_cos";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c4_b_info)[1].fileTimeLo = 1286840322U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context = "";
  (*c4_b_info)[2].name = "sin";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[2].fileTimeLo = 1343851986U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[3].name = "eml_scalar_sin";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c4_b_info)[3].fileTimeLo = 1286840336U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context = "";
  (*c4_b_info)[4].name = "mtimes";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[4].fileTimeLo = 1289541292U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context = "";
  (*c4_b_info)[5].name = "mrdivide";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[5].fileTimeLo = 1357973148U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 1319751566U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  (*c4_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[6].name = "rdivide";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[6].fileTimeLo = 1346531988U;
  (*c4_b_info)[6].fileTimeHi = 0U;
  (*c4_b_info)[6].mFileTimeLo = 0U;
  (*c4_b_info)[6].mFileTimeHi = 0U;
  (*c4_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[7].name = "eml_scalexp_compatible";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c4_b_info)[7].fileTimeLo = 1286840396U;
  (*c4_b_info)[7].fileTimeHi = 0U;
  (*c4_b_info)[7].mFileTimeLo = 0U;
  (*c4_b_info)[7].mFileTimeHi = 0U;
  (*c4_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[8].name = "eml_div";
  (*c4_b_info)[8].dominantType = "double";
  (*c4_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[8].fileTimeLo = 1313369410U;
  (*c4_b_info)[8].fileTimeHi = 0U;
  (*c4_b_info)[8].mFileTimeLo = 0U;
  (*c4_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c4_i43 = 0; c4_i43 < 9; c4_i43++) {
    c4_r0 = &c4_info[c4_i43];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i43);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i43);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_g_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i44;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i44, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i44;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_h_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_JointSpaceControl_BestInertia, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_JointSpaceControl_BestInertia), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_JointSpaceControl_BestInertia);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
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

void sf_c4_JointSpaceControl_BestInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4280821069U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3816198594U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4103308611U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3294780714U);
}

mxArray *sf_c4_JointSpaceControl_BestInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RQnebgIV4GyPqB7OhB5O1C");
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_JointSpaceControl_BestInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_JointSpaceControl_BestInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"R\",},{M[1],M[6],T\"d\",},{M[8],M[0],T\"is_active_c4_JointSpaceControl_BestInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_JointSpaceControl_BestInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_BestInertiaMachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"d");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,24599);
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
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real_T (*c4_d)[3];
          real_T (*c4_q)[6];
          real_T (*c4_R)[9];
          c4_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c4_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_d);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_q);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_R);
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
  return "u4Sz1gJe5hvMNWHpwhuraH";
}

static void sf_opaque_initialize_c4_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_JointSpaceControl_BestInertiaInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
  initialize_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  enable_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  disable_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  sf_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_JointSpaceControl_BestInertia();/* state var info */
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

extern void sf_internal_set_sim_state_c4_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_JointSpaceControl_BestInertia();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c4_JointSpaceControl_BestInertia(S);
}

static void sf_opaque_set_sim_state_c4_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_JointSpaceControl_BestInertia(S, st);
}

static void sf_opaque_terminate_c4_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_BestInertia_optimization_info();
    }

    finalize_c4_JointSpaceControl_BestInertia
      ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_JointSpaceControl_BestInertia
    ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_JointSpaceControl_BestInertia(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_JointSpaceControl_BestInertia
      ((SFc4_JointSpaceControl_BestInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_BestInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2149714969U));
  ssSetChecksum1(S,(775924U));
  ssSetChecksum2(S,(2887172680U));
  ssSetChecksum3(S,(1227109145U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_JointSpaceControl_BestInertia(SimStruct *S)
{
  SFc4_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc4_JointSpaceControl_BestInertiaInstanceStruct *)utMalloc
    (sizeof(SFc4_JointSpaceControl_BestInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_JointSpaceControl_BestInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_JointSpaceControl_BestInertia;
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

void c4_JointSpaceControl_BestInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_JointSpaceControl_BestInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_JointSpaceControl_BestInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
