/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_BestInertia_sfun.h"
#include "c16_JointSpaceControl_BestInertia.h"
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
static const char * c16_debug_family_names[18] = { "theta1", "theta2", "theta3",
  "theta4", "theta5", "theta6", "theta_1", "theta_2", "theta_3", "theta_4",
  "theta_5", "theta_6", "T", "nargin", "nargout", "q", "d", "R" };

/* Function Declarations */
static void initialize_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initialize_params_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void enable_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void disable_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void set_sim_state_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_st);
static void finalize_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void sf_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c16_chartstep_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initSimStructsc16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void registerMessagesc16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_R, const char_T *c16_identifier, real_T c16_y[9]);
static void c16_b_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[9]);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_c_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_d, const char_T *c16_identifier, real_T c16_y[3]);
static void c16_d_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[3]);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_e_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_f_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[16]);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_g_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_h_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_b_is_active_c16_JointSpaceControl_BestInertia, const char_T
   *c16_identifier);
static uint8_T c16_i_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_JointSpaceControl_BestInertia = 0U;
}

static void initialize_params_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void enable_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[9];
  const mxArray *c16_b_y = NULL;
  int32_T c16_i1;
  real_T c16_b_u[3];
  const mxArray *c16_c_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  real_T (*c16_d)[3];
  real_T (*c16_R)[9];
  c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(3), FALSE);
  for (c16_i0 = 0; c16_i0 < 9; c16_i0++) {
    c16_u[c16_i0] = (*c16_R)[c16_i0];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  for (c16_i1 = 0; c16_i1 < 3; c16_i1++) {
    c16_b_u[c16_i1] = (*c16_d)[c16_i1];
  }

  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", c16_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_hoistedGlobal =
    chartInstance->c16_is_active_c16_JointSpaceControl_BestInertia;
  c16_c_u = c16_hoistedGlobal;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 2, c16_d_y);
  sf_mex_assign(&c16_st, c16_y, FALSE);
  return c16_st;
}

static void set_sim_state_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[9];
  int32_T c16_i2;
  real_T c16_dv1[3];
  int32_T c16_i3;
  real_T (*c16_R)[9];
  real_T (*c16_d)[3];
  c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)), "R",
                       c16_dv0);
  for (c16_i2 = 0; c16_i2 < 9; c16_i2++) {
    (*c16_R)[c16_i2] = c16_dv0[c16_i2];
  }

  c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
    "d", c16_dv1);
  for (c16_i3 = 0; c16_i3 < 3; c16_i3++) {
    (*c16_d)[c16_i3] = c16_dv1[c16_i3];
  }

  chartInstance->c16_is_active_c16_JointSpaceControl_BestInertia =
    c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 2)),
    "is_active_c16_JointSpaceControl_BestInertia");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_JointSpaceControl_BestInertia(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void sf_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c16_i4;
  int32_T c16_i5;
  int32_T c16_i6;
  real_T (*c16_R)[9];
  real_T (*c16_q)[6];
  real_T (*c16_d)[3];
  c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c16_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
  for (c16_i4 = 0; c16_i4 < 3; c16_i4++) {
    _SFD_DATA_RANGE_CHECK((*c16_d)[c16_i4], 0U);
  }

  for (c16_i5 = 0; c16_i5 < 6; c16_i5++) {
    _SFD_DATA_RANGE_CHECK((*c16_q)[c16_i5], 1U);
  }

  for (c16_i6 = 0; c16_i6 < 9; c16_i6++) {
    _SFD_DATA_RANGE_CHECK((*c16_R)[c16_i6], 2U);
  }

  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_JointSpaceControl_BestInertia(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_BestInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c16_chartstep_c16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c16_i7;
  real_T c16_q[6];
  uint32_T c16_debug_family_var_map[18];
  real_T c16_theta1;
  real_T c16_theta2;
  real_T c16_theta3;
  real_T c16_theta4;
  real_T c16_theta5;
  real_T c16_theta6;
  real_T c16_theta_1;
  real_T c16_theta_2;
  real_T c16_theta_3;
  real_T c16_theta_4;
  real_T c16_theta_5;
  real_T c16_theta_6;
  real_T c16_T[16];
  real_T c16_nargin = 1.0;
  real_T c16_nargout = 2.0;
  real_T c16_d[3];
  real_T c16_R[9];
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_c_x;
  real_T c16_d_x;
  real_T c16_e_x;
  real_T c16_f_x;
  real_T c16_a;
  real_T c16_b;
  real_T c16_y;
  real_T c16_g_x;
  real_T c16_h_x;
  real_T c16_i_x;
  real_T c16_j_x;
  real_T c16_k_x;
  real_T c16_l_x;
  real_T c16_m_x;
  real_T c16_n_x;
  real_T c16_b_a;
  real_T c16_b_b;
  real_T c16_b_y;
  real_T c16_o_x;
  real_T c16_p_x;
  real_T c16_c_a;
  real_T c16_c_b;
  real_T c16_c_y;
  real_T c16_q_x;
  real_T c16_r_x;
  real_T c16_s_x;
  real_T c16_t_x;
  real_T c16_d_a;
  real_T c16_d_b;
  real_T c16_d_y;
  real_T c16_u_x;
  real_T c16_v_x;
  real_T c16_e_a;
  real_T c16_e_b;
  real_T c16_e_y;
  real_T c16_f_a;
  real_T c16_f_b;
  real_T c16_f_y;
  real_T c16_w_x;
  real_T c16_x_x;
  real_T c16_y_x;
  real_T c16_ab_x;
  real_T c16_bb_x;
  real_T c16_cb_x;
  real_T c16_g_a;
  real_T c16_g_b;
  real_T c16_g_y;
  real_T c16_db_x;
  real_T c16_eb_x;
  real_T c16_h_a;
  real_T c16_h_b;
  real_T c16_h_y;
  real_T c16_fb_x;
  real_T c16_gb_x;
  real_T c16_hb_x;
  real_T c16_ib_x;
  real_T c16_i_a;
  real_T c16_i_b;
  real_T c16_i_y;
  real_T c16_jb_x;
  real_T c16_kb_x;
  real_T c16_j_a;
  real_T c16_j_b;
  real_T c16_j_y;
  real_T c16_k_a;
  real_T c16_k_b;
  real_T c16_k_y;
  real_T c16_l_a;
  real_T c16_l_b;
  real_T c16_l_y;
  real_T c16_m_a;
  real_T c16_m_b;
  real_T c16_m_y;
  real_T c16_lb_x;
  real_T c16_mb_x;
  real_T c16_nb_x;
  real_T c16_ob_x;
  real_T c16_pb_x;
  real_T c16_qb_x;
  real_T c16_rb_x;
  real_T c16_sb_x;
  real_T c16_n_a;
  real_T c16_n_b;
  real_T c16_n_y;
  real_T c16_tb_x;
  real_T c16_ub_x;
  real_T c16_o_a;
  real_T c16_o_b;
  real_T c16_o_y;
  real_T c16_vb_x;
  real_T c16_wb_x;
  real_T c16_xb_x;
  real_T c16_yb_x;
  real_T c16_p_a;
  real_T c16_p_b;
  real_T c16_p_y;
  real_T c16_ac_x;
  real_T c16_bc_x;
  real_T c16_q_a;
  real_T c16_q_b;
  real_T c16_q_y;
  real_T c16_r_a;
  real_T c16_r_b;
  real_T c16_r_y;
  real_T c16_cc_x;
  real_T c16_dc_x;
  real_T c16_ec_x;
  real_T c16_fc_x;
  real_T c16_gc_x;
  real_T c16_hc_x;
  real_T c16_s_a;
  real_T c16_s_b;
  real_T c16_s_y;
  real_T c16_ic_x;
  real_T c16_jc_x;
  real_T c16_t_a;
  real_T c16_t_b;
  real_T c16_t_y;
  real_T c16_kc_x;
  real_T c16_lc_x;
  real_T c16_mc_x;
  real_T c16_nc_x;
  real_T c16_u_a;
  real_T c16_u_b;
  real_T c16_u_y;
  real_T c16_oc_x;
  real_T c16_pc_x;
  real_T c16_v_a;
  real_T c16_v_b;
  real_T c16_v_y;
  real_T c16_w_a;
  real_T c16_w_b;
  real_T c16_w_y;
  real_T c16_x_a;
  real_T c16_x_b;
  real_T c16_x_y;
  real_T c16_qc_x;
  real_T c16_rc_x;
  real_T c16_sc_x;
  real_T c16_tc_x;
  real_T c16_uc_x;
  real_T c16_vc_x;
  real_T c16_y_a;
  real_T c16_y_b;
  real_T c16_y_y;
  real_T c16_wc_x;
  real_T c16_xc_x;
  real_T c16_yc_x;
  real_T c16_ad_x;
  real_T c16_bd_x;
  real_T c16_cd_x;
  real_T c16_dd_x;
  real_T c16_ed_x;
  real_T c16_ab_a;
  real_T c16_ab_b;
  real_T c16_ab_y;
  real_T c16_fd_x;
  real_T c16_gd_x;
  real_T c16_bb_a;
  real_T c16_bb_b;
  real_T c16_bb_y;
  real_T c16_hd_x;
  real_T c16_id_x;
  real_T c16_jd_x;
  real_T c16_kd_x;
  real_T c16_cb_a;
  real_T c16_cb_b;
  real_T c16_cb_y;
  real_T c16_ld_x;
  real_T c16_md_x;
  real_T c16_db_a;
  real_T c16_db_b;
  real_T c16_db_y;
  real_T c16_eb_a;
  real_T c16_eb_b;
  real_T c16_eb_y;
  real_T c16_nd_x;
  real_T c16_od_x;
  real_T c16_pd_x;
  real_T c16_qd_x;
  real_T c16_rd_x;
  real_T c16_sd_x;
  real_T c16_fb_a;
  real_T c16_fb_b;
  real_T c16_fb_y;
  real_T c16_td_x;
  real_T c16_ud_x;
  real_T c16_gb_a;
  real_T c16_gb_b;
  real_T c16_gb_y;
  real_T c16_vd_x;
  real_T c16_wd_x;
  real_T c16_xd_x;
  real_T c16_yd_x;
  real_T c16_hb_a;
  real_T c16_hb_b;
  real_T c16_hb_y;
  real_T c16_ae_x;
  real_T c16_be_x;
  real_T c16_ib_a;
  real_T c16_ib_b;
  real_T c16_ib_y;
  real_T c16_jb_a;
  real_T c16_jb_b;
  real_T c16_jb_y;
  real_T c16_kb_a;
  real_T c16_kb_b;
  real_T c16_kb_y;
  real_T c16_lb_a;
  real_T c16_lb_b;
  real_T c16_lb_y;
  real_T c16_ce_x;
  real_T c16_de_x;
  real_T c16_ee_x;
  real_T c16_fe_x;
  real_T c16_ge_x;
  real_T c16_he_x;
  real_T c16_ie_x;
  real_T c16_je_x;
  real_T c16_mb_a;
  real_T c16_mb_b;
  real_T c16_mb_y;
  real_T c16_ke_x;
  real_T c16_le_x;
  real_T c16_nb_a;
  real_T c16_nb_b;
  real_T c16_nb_y;
  real_T c16_me_x;
  real_T c16_ne_x;
  real_T c16_oe_x;
  real_T c16_pe_x;
  real_T c16_ob_a;
  real_T c16_ob_b;
  real_T c16_ob_y;
  real_T c16_qe_x;
  real_T c16_re_x;
  real_T c16_pb_a;
  real_T c16_pb_b;
  real_T c16_pb_y;
  real_T c16_qb_a;
  real_T c16_qb_b;
  real_T c16_qb_y;
  real_T c16_se_x;
  real_T c16_te_x;
  real_T c16_ue_x;
  real_T c16_ve_x;
  real_T c16_we_x;
  real_T c16_xe_x;
  real_T c16_rb_a;
  real_T c16_rb_b;
  real_T c16_rb_y;
  real_T c16_ye_x;
  real_T c16_af_x;
  real_T c16_sb_a;
  real_T c16_sb_b;
  real_T c16_sb_y;
  real_T c16_bf_x;
  real_T c16_cf_x;
  real_T c16_df_x;
  real_T c16_ef_x;
  real_T c16_tb_a;
  real_T c16_tb_b;
  real_T c16_tb_y;
  real_T c16_ff_x;
  real_T c16_gf_x;
  real_T c16_ub_a;
  real_T c16_ub_b;
  real_T c16_ub_y;
  real_T c16_vb_a;
  real_T c16_vb_b;
  real_T c16_vb_y;
  real_T c16_wb_a;
  real_T c16_wb_b;
  real_T c16_wb_y;
  real_T c16_hf_x;
  real_T c16_if_x;
  real_T c16_jf_x;
  real_T c16_kf_x;
  real_T c16_xb_a;
  real_T c16_xb_b;
  real_T c16_xb_y;
  real_T c16_lf_x;
  real_T c16_mf_x;
  real_T c16_nf_x;
  real_T c16_of_x;
  real_T c16_pf_x;
  real_T c16_qf_x;
  real_T c16_rf_x;
  real_T c16_sf_x;
  real_T c16_yb_a;
  real_T c16_yb_b;
  real_T c16_yb_y;
  real_T c16_tf_x;
  real_T c16_uf_x;
  real_T c16_ac_a;
  real_T c16_ac_b;
  real_T c16_ac_y;
  real_T c16_vf_x;
  real_T c16_wf_x;
  real_T c16_xf_x;
  real_T c16_yf_x;
  real_T c16_bc_a;
  real_T c16_bc_b;
  real_T c16_bc_y;
  real_T c16_ag_x;
  real_T c16_bg_x;
  real_T c16_cc_a;
  real_T c16_cc_b;
  real_T c16_cc_y;
  real_T c16_dc_a;
  real_T c16_dc_b;
  real_T c16_dc_y;
  real_T c16_cg_x;
  real_T c16_dg_x;
  real_T c16_eg_x;
  real_T c16_fg_x;
  real_T c16_gg_x;
  real_T c16_hg_x;
  real_T c16_ec_a;
  real_T c16_ec_b;
  real_T c16_ec_y;
  real_T c16_ig_x;
  real_T c16_jg_x;
  real_T c16_fc_a;
  real_T c16_fc_b;
  real_T c16_fc_y;
  real_T c16_kg_x;
  real_T c16_lg_x;
  real_T c16_mg_x;
  real_T c16_ng_x;
  real_T c16_gc_a;
  real_T c16_gc_b;
  real_T c16_gc_y;
  real_T c16_og_x;
  real_T c16_pg_x;
  real_T c16_hc_a;
  real_T c16_hc_b;
  real_T c16_hc_y;
  real_T c16_ic_a;
  real_T c16_ic_b;
  real_T c16_ic_y;
  real_T c16_jc_a;
  real_T c16_jc_b;
  real_T c16_jc_y;
  real_T c16_qg_x;
  real_T c16_rg_x;
  real_T c16_kc_b;
  real_T c16_kc_y;
  real_T c16_A;
  real_T c16_sg_x;
  real_T c16_tg_x;
  real_T c16_lc_y;
  real_T c16_ug_x;
  real_T c16_vg_x;
  real_T c16_lc_b;
  real_T c16_mc_y;
  real_T c16_wg_x;
  real_T c16_xg_x;
  real_T c16_kc_a;
  real_T c16_mc_b;
  real_T c16_nc_y;
  real_T c16_b_A;
  real_T c16_yg_x;
  real_T c16_ah_x;
  real_T c16_oc_y;
  real_T c16_bh_x;
  real_T c16_ch_x;
  real_T c16_nc_b;
  real_T c16_pc_y;
  real_T c16_dh_x;
  real_T c16_eh_x;
  real_T c16_lc_a;
  real_T c16_oc_b;
  real_T c16_qc_y;
  real_T c16_c_A;
  real_T c16_fh_x;
  real_T c16_gh_x;
  real_T c16_rc_y;
  real_T c16_hh_x;
  real_T c16_ih_x;
  real_T c16_pc_b;
  real_T c16_sc_y;
  real_T c16_jh_x;
  real_T c16_kh_x;
  real_T c16_lh_x;
  real_T c16_mh_x;
  real_T c16_mc_a;
  real_T c16_qc_b;
  real_T c16_tc_y;
  real_T c16_nh_x;
  real_T c16_oh_x;
  real_T c16_ph_x;
  real_T c16_qh_x;
  real_T c16_rh_x;
  real_T c16_sh_x;
  real_T c16_th_x;
  real_T c16_uh_x;
  real_T c16_nc_a;
  real_T c16_rc_b;
  real_T c16_uc_y;
  real_T c16_vh_x;
  real_T c16_wh_x;
  real_T c16_oc_a;
  real_T c16_sc_b;
  real_T c16_vc_y;
  real_T c16_xh_x;
  real_T c16_yh_x;
  real_T c16_ai_x;
  real_T c16_bi_x;
  real_T c16_pc_a;
  real_T c16_tc_b;
  real_T c16_wc_y;
  real_T c16_ci_x;
  real_T c16_di_x;
  real_T c16_qc_a;
  real_T c16_uc_b;
  real_T c16_xc_y;
  real_T c16_rc_a;
  real_T c16_vc_b;
  real_T c16_yc_y;
  real_T c16_ei_x;
  real_T c16_fi_x;
  real_T c16_gi_x;
  real_T c16_hi_x;
  real_T c16_ii_x;
  real_T c16_ji_x;
  real_T c16_sc_a;
  real_T c16_wc_b;
  real_T c16_ad_y;
  real_T c16_ki_x;
  real_T c16_li_x;
  real_T c16_tc_a;
  real_T c16_xc_b;
  real_T c16_bd_y;
  real_T c16_mi_x;
  real_T c16_ni_x;
  real_T c16_oi_x;
  real_T c16_pi_x;
  real_T c16_uc_a;
  real_T c16_yc_b;
  real_T c16_cd_y;
  real_T c16_qi_x;
  real_T c16_ri_x;
  real_T c16_vc_a;
  real_T c16_ad_b;
  real_T c16_dd_y;
  real_T c16_wc_a;
  real_T c16_bd_b;
  real_T c16_ed_y;
  real_T c16_xc_a;
  real_T c16_cd_b;
  real_T c16_fd_y;
  real_T c16_yc_a;
  real_T c16_dd_b;
  real_T c16_gd_y;
  real_T c16_d_A;
  real_T c16_si_x;
  real_T c16_ti_x;
  real_T c16_hd_y;
  real_T c16_ui_x;
  real_T c16_vi_x;
  real_T c16_ed_b;
  real_T c16_id_y;
  real_T c16_wi_x;
  real_T c16_xi_x;
  real_T c16_yi_x;
  real_T c16_aj_x;
  real_T c16_ad_a;
  real_T c16_fd_b;
  real_T c16_jd_y;
  real_T c16_bj_x;
  real_T c16_cj_x;
  real_T c16_bd_a;
  real_T c16_gd_b;
  real_T c16_kd_y;
  real_T c16_dj_x;
  real_T c16_ej_x;
  real_T c16_fj_x;
  real_T c16_gj_x;
  real_T c16_cd_a;
  real_T c16_hd_b;
  real_T c16_ld_y;
  real_T c16_hj_x;
  real_T c16_ij_x;
  real_T c16_dd_a;
  real_T c16_id_b;
  real_T c16_md_y;
  real_T c16_ed_a;
  real_T c16_jd_b;
  real_T c16_nd_y;
  real_T c16_e_A;
  real_T c16_jj_x;
  real_T c16_kj_x;
  real_T c16_od_y;
  real_T c16_lj_x;
  real_T c16_mj_x;
  real_T c16_kd_b;
  real_T c16_pd_y;
  real_T c16_nj_x;
  real_T c16_oj_x;
  real_T c16_pj_x;
  real_T c16_qj_x;
  real_T c16_fd_a;
  real_T c16_ld_b;
  real_T c16_qd_y;
  real_T c16_rj_x;
  real_T c16_sj_x;
  real_T c16_tj_x;
  real_T c16_uj_x;
  real_T c16_vj_x;
  real_T c16_wj_x;
  real_T c16_xj_x;
  real_T c16_yj_x;
  real_T c16_gd_a;
  real_T c16_md_b;
  real_T c16_rd_y;
  real_T c16_ak_x;
  real_T c16_bk_x;
  real_T c16_hd_a;
  real_T c16_nd_b;
  real_T c16_sd_y;
  real_T c16_ck_x;
  real_T c16_dk_x;
  real_T c16_ek_x;
  real_T c16_fk_x;
  real_T c16_id_a;
  real_T c16_od_b;
  real_T c16_td_y;
  real_T c16_gk_x;
  real_T c16_hk_x;
  real_T c16_jd_a;
  real_T c16_pd_b;
  real_T c16_ud_y;
  real_T c16_kd_a;
  real_T c16_qd_b;
  real_T c16_vd_y;
  real_T c16_ik_x;
  real_T c16_jk_x;
  real_T c16_kk_x;
  real_T c16_lk_x;
  real_T c16_mk_x;
  real_T c16_nk_x;
  real_T c16_ld_a;
  real_T c16_rd_b;
  real_T c16_wd_y;
  real_T c16_ok_x;
  real_T c16_pk_x;
  real_T c16_md_a;
  real_T c16_sd_b;
  real_T c16_xd_y;
  real_T c16_qk_x;
  real_T c16_rk_x;
  real_T c16_sk_x;
  real_T c16_tk_x;
  real_T c16_nd_a;
  real_T c16_td_b;
  real_T c16_yd_y;
  real_T c16_uk_x;
  real_T c16_vk_x;
  real_T c16_od_a;
  real_T c16_ud_b;
  real_T c16_ae_y;
  real_T c16_pd_a;
  real_T c16_vd_b;
  real_T c16_be_y;
  real_T c16_qd_a;
  real_T c16_wd_b;
  real_T c16_ce_y;
  real_T c16_rd_a;
  real_T c16_xd_b;
  real_T c16_de_y;
  real_T c16_f_A;
  real_T c16_wk_x;
  real_T c16_xk_x;
  real_T c16_ee_y;
  real_T c16_yk_x;
  real_T c16_al_x;
  real_T c16_yd_b;
  real_T c16_fe_y;
  real_T c16_bl_x;
  real_T c16_cl_x;
  real_T c16_dl_x;
  real_T c16_el_x;
  real_T c16_sd_a;
  real_T c16_ae_b;
  real_T c16_ge_y;
  real_T c16_fl_x;
  real_T c16_gl_x;
  real_T c16_td_a;
  real_T c16_be_b;
  real_T c16_he_y;
  real_T c16_hl_x;
  real_T c16_il_x;
  real_T c16_jl_x;
  real_T c16_kl_x;
  real_T c16_ud_a;
  real_T c16_ce_b;
  real_T c16_ie_y;
  real_T c16_ll_x;
  real_T c16_ml_x;
  real_T c16_vd_a;
  real_T c16_de_b;
  real_T c16_je_y;
  real_T c16_wd_a;
  real_T c16_ee_b;
  real_T c16_ke_y;
  real_T c16_g_A;
  real_T c16_nl_x;
  real_T c16_ol_x;
  real_T c16_le_y;
  real_T c16_pl_x;
  real_T c16_ql_x;
  real_T c16_fe_b;
  real_T c16_me_y;
  real_T c16_rl_x;
  real_T c16_sl_x;
  real_T c16_tl_x;
  real_T c16_ul_x;
  real_T c16_vl_x;
  real_T c16_wl_x;
  real_T c16_xd_a;
  real_T c16_ge_b;
  real_T c16_ne_y;
  real_T c16_xl_x;
  real_T c16_yl_x;
  real_T c16_yd_a;
  real_T c16_he_b;
  real_T c16_oe_y;
  real_T c16_am_x;
  real_T c16_bm_x;
  real_T c16_cm_x;
  real_T c16_dm_x;
  real_T c16_ae_a;
  real_T c16_ie_b;
  real_T c16_pe_y;
  real_T c16_em_x;
  real_T c16_fm_x;
  real_T c16_be_a;
  real_T c16_je_b;
  real_T c16_qe_y;
  real_T c16_ce_a;
  real_T c16_ke_b;
  real_T c16_re_y;
  real_T c16_gm_x;
  real_T c16_hm_x;
  real_T c16_im_x;
  real_T c16_jm_x;
  real_T c16_km_x;
  real_T c16_lm_x;
  real_T c16_de_a;
  real_T c16_le_b;
  real_T c16_se_y;
  real_T c16_mm_x;
  real_T c16_nm_x;
  real_T c16_ee_a;
  real_T c16_me_b;
  real_T c16_te_y;
  real_T c16_om_x;
  real_T c16_pm_x;
  real_T c16_qm_x;
  real_T c16_rm_x;
  real_T c16_fe_a;
  real_T c16_ne_b;
  real_T c16_ue_y;
  real_T c16_sm_x;
  real_T c16_tm_x;
  real_T c16_ge_a;
  real_T c16_oe_b;
  real_T c16_ve_y;
  real_T c16_he_a;
  real_T c16_pe_b;
  real_T c16_we_y;
  real_T c16_ie_a;
  real_T c16_qe_b;
  real_T c16_xe_y;
  real_T c16_h_A;
  real_T c16_um_x;
  real_T c16_vm_x;
  real_T c16_ye_y;
  real_T c16_wm_x;
  real_T c16_xm_x;
  real_T c16_re_b;
  real_T c16_af_y;
  real_T c16_ym_x;
  real_T c16_an_x;
  real_T c16_bn_x;
  real_T c16_cn_x;
  real_T c16_dn_x;
  real_T c16_en_x;
  real_T c16_je_a;
  real_T c16_se_b;
  real_T c16_bf_y;
  real_T c16_fn_x;
  real_T c16_gn_x;
  real_T c16_ke_a;
  real_T c16_te_b;
  real_T c16_cf_y;
  real_T c16_hn_x;
  real_T c16_in_x;
  real_T c16_jn_x;
  real_T c16_kn_x;
  real_T c16_le_a;
  real_T c16_ue_b;
  real_T c16_df_y;
  real_T c16_ln_x;
  real_T c16_mn_x;
  real_T c16_me_a;
  real_T c16_ve_b;
  real_T c16_ef_y;
  real_T c16_ne_a;
  real_T c16_we_b;
  real_T c16_ff_y;
  real_T c16_nn_x;
  real_T c16_on_x;
  real_T c16_pn_x;
  real_T c16_qn_x;
  real_T c16_rn_x;
  real_T c16_sn_x;
  real_T c16_oe_a;
  real_T c16_xe_b;
  real_T c16_gf_y;
  real_T c16_tn_x;
  real_T c16_un_x;
  real_T c16_pe_a;
  real_T c16_ye_b;
  real_T c16_hf_y;
  real_T c16_vn_x;
  real_T c16_wn_x;
  real_T c16_xn_x;
  real_T c16_yn_x;
  real_T c16_qe_a;
  real_T c16_af_b;
  real_T c16_if_y;
  real_T c16_ao_x;
  real_T c16_bo_x;
  real_T c16_re_a;
  real_T c16_bf_b;
  real_T c16_jf_y;
  real_T c16_se_a;
  real_T c16_cf_b;
  real_T c16_kf_y;
  real_T c16_te_a;
  real_T c16_df_b;
  real_T c16_lf_y;
  real_T c16_i_A;
  real_T c16_co_x;
  real_T c16_do_x;
  real_T c16_mf_y;
  real_T c16_eo_x;
  real_T c16_fo_x;
  real_T c16_ef_b;
  real_T c16_nf_y;
  real_T c16_go_x;
  real_T c16_ho_x;
  real_T c16_io_x;
  real_T c16_jo_x;
  real_T c16_ko_x;
  real_T c16_lo_x;
  real_T c16_ue_a;
  real_T c16_ff_b;
  real_T c16_of_y;
  real_T c16_mo_x;
  real_T c16_no_x;
  real_T c16_ve_a;
  real_T c16_gf_b;
  real_T c16_pf_y;
  real_T c16_oo_x;
  real_T c16_po_x;
  real_T c16_qo_x;
  real_T c16_ro_x;
  real_T c16_we_a;
  real_T c16_hf_b;
  real_T c16_qf_y;
  real_T c16_so_x;
  real_T c16_to_x;
  real_T c16_xe_a;
  real_T c16_if_b;
  real_T c16_rf_y;
  real_T c16_ye_a;
  real_T c16_jf_b;
  real_T c16_sf_y;
  real_T c16_uo_x;
  real_T c16_vo_x;
  real_T c16_wo_x;
  real_T c16_xo_x;
  real_T c16_yo_x;
  real_T c16_ap_x;
  real_T c16_af_a;
  real_T c16_kf_b;
  real_T c16_tf_y;
  real_T c16_bp_x;
  real_T c16_cp_x;
  real_T c16_bf_a;
  real_T c16_lf_b;
  real_T c16_uf_y;
  real_T c16_dp_x;
  real_T c16_ep_x;
  real_T c16_fp_x;
  real_T c16_gp_x;
  real_T c16_cf_a;
  real_T c16_mf_b;
  real_T c16_vf_y;
  real_T c16_hp_x;
  real_T c16_ip_x;
  real_T c16_df_a;
  real_T c16_nf_b;
  real_T c16_wf_y;
  real_T c16_ef_a;
  real_T c16_of_b;
  real_T c16_xf_y;
  real_T c16_ff_a;
  real_T c16_pf_b;
  real_T c16_yf_y;
  real_T c16_j_A;
  real_T c16_jp_x;
  real_T c16_kp_x;
  real_T c16_ag_y;
  real_T c16_lp_x;
  real_T c16_mp_x;
  real_T c16_qf_b;
  real_T c16_bg_y;
  real_T c16_np_x;
  real_T c16_op_x;
  real_T c16_gf_a;
  real_T c16_rf_b;
  real_T c16_cg_y;
  real_T c16_pp_x;
  real_T c16_qp_x;
  real_T c16_hf_a;
  real_T c16_sf_b;
  real_T c16_dg_y;
  real_T c16_k_A;
  real_T c16_rp_x;
  real_T c16_sp_x;
  real_T c16_eg_y;
  real_T c16_tp_x;
  real_T c16_up_x;
  real_T c16_tf_b;
  real_T c16_fg_y;
  real_T c16_vp_x;
  real_T c16_wp_x;
  real_T c16_if_a;
  real_T c16_uf_b;
  real_T c16_gg_y;
  real_T c16_xp_x;
  real_T c16_yp_x;
  real_T c16_jf_a;
  real_T c16_vf_b;
  real_T c16_hg_y;
  real_T c16_l_A;
  real_T c16_aq_x;
  real_T c16_bq_x;
  real_T c16_ig_y;
  real_T c16_cq_x;
  real_T c16_dq_x;
  real_T c16_eq_x;
  real_T c16_fq_x;
  real_T c16_gq_x;
  real_T c16_hq_x;
  real_T c16_kf_a;
  real_T c16_wf_b;
  real_T c16_jg_y;
  real_T c16_iq_x;
  real_T c16_jq_x;
  real_T c16_kq_x;
  real_T c16_lq_x;
  real_T c16_mq_x;
  real_T c16_nq_x;
  real_T c16_oq_x;
  real_T c16_pq_x;
  real_T c16_lf_a;
  real_T c16_xf_b;
  real_T c16_kg_y;
  real_T c16_qq_x;
  real_T c16_rq_x;
  real_T c16_mf_a;
  real_T c16_yf_b;
  real_T c16_lg_y;
  real_T c16_sq_x;
  real_T c16_tq_x;
  real_T c16_uq_x;
  real_T c16_vq_x;
  real_T c16_nf_a;
  real_T c16_ag_b;
  real_T c16_mg_y;
  real_T c16_wq_x;
  real_T c16_xq_x;
  real_T c16_of_a;
  real_T c16_bg_b;
  real_T c16_ng_y;
  real_T c16_pf_a;
  real_T c16_cg_b;
  real_T c16_og_y;
  real_T c16_yq_x;
  real_T c16_ar_x;
  real_T c16_br_x;
  real_T c16_cr_x;
  real_T c16_dr_x;
  real_T c16_er_x;
  real_T c16_qf_a;
  real_T c16_dg_b;
  real_T c16_pg_y;
  real_T c16_fr_x;
  real_T c16_gr_x;
  real_T c16_rf_a;
  real_T c16_eg_b;
  real_T c16_qg_y;
  real_T c16_hr_x;
  real_T c16_ir_x;
  real_T c16_jr_x;
  real_T c16_kr_x;
  real_T c16_sf_a;
  real_T c16_fg_b;
  real_T c16_rg_y;
  real_T c16_lr_x;
  real_T c16_mr_x;
  real_T c16_tf_a;
  real_T c16_gg_b;
  real_T c16_sg_y;
  real_T c16_uf_a;
  real_T c16_hg_b;
  real_T c16_tg_y;
  real_T c16_vf_a;
  real_T c16_ig_b;
  real_T c16_ug_y;
  real_T c16_wf_a;
  real_T c16_jg_b;
  real_T c16_vg_y;
  real_T c16_nr_x;
  real_T c16_or_x;
  real_T c16_pr_x;
  real_T c16_qr_x;
  real_T c16_rr_x;
  real_T c16_sr_x;
  real_T c16_tr_x;
  real_T c16_ur_x;
  real_T c16_xf_a;
  real_T c16_kg_b;
  real_T c16_wg_y;
  real_T c16_vr_x;
  real_T c16_wr_x;
  real_T c16_yf_a;
  real_T c16_lg_b;
  real_T c16_xg_y;
  real_T c16_xr_x;
  real_T c16_yr_x;
  real_T c16_as_x;
  real_T c16_bs_x;
  real_T c16_ag_a;
  real_T c16_mg_b;
  real_T c16_yg_y;
  real_T c16_cs_x;
  real_T c16_ds_x;
  real_T c16_bg_a;
  real_T c16_ng_b;
  real_T c16_ah_y;
  real_T c16_cg_a;
  real_T c16_og_b;
  real_T c16_bh_y;
  real_T c16_es_x;
  real_T c16_fs_x;
  real_T c16_gs_x;
  real_T c16_hs_x;
  real_T c16_is_x;
  real_T c16_js_x;
  real_T c16_dg_a;
  real_T c16_pg_b;
  real_T c16_ch_y;
  real_T c16_ks_x;
  real_T c16_ls_x;
  real_T c16_eg_a;
  real_T c16_qg_b;
  real_T c16_dh_y;
  real_T c16_ms_x;
  real_T c16_ns_x;
  real_T c16_os_x;
  real_T c16_ps_x;
  real_T c16_fg_a;
  real_T c16_rg_b;
  real_T c16_eh_y;
  real_T c16_qs_x;
  real_T c16_rs_x;
  real_T c16_gg_a;
  real_T c16_sg_b;
  real_T c16_fh_y;
  real_T c16_hg_a;
  real_T c16_tg_b;
  real_T c16_gh_y;
  real_T c16_ig_a;
  real_T c16_ug_b;
  real_T c16_hh_y;
  real_T c16_ss_x;
  real_T c16_ts_x;
  real_T c16_us_x;
  real_T c16_vs_x;
  real_T c16_ws_x;
  real_T c16_xs_x;
  real_T c16_jg_a;
  real_T c16_vg_b;
  real_T c16_ih_y;
  real_T c16_ys_x;
  real_T c16_at_x;
  real_T c16_bt_x;
  real_T c16_ct_x;
  real_T c16_dt_x;
  real_T c16_et_x;
  real_T c16_ft_x;
  real_T c16_gt_x;
  real_T c16_kg_a;
  real_T c16_wg_b;
  real_T c16_jh_y;
  real_T c16_ht_x;
  real_T c16_it_x;
  real_T c16_lg_a;
  real_T c16_xg_b;
  real_T c16_kh_y;
  real_T c16_jt_x;
  real_T c16_kt_x;
  real_T c16_lt_x;
  real_T c16_mt_x;
  real_T c16_mg_a;
  real_T c16_yg_b;
  real_T c16_lh_y;
  real_T c16_nt_x;
  real_T c16_ot_x;
  real_T c16_ng_a;
  real_T c16_ah_b;
  real_T c16_mh_y;
  real_T c16_og_a;
  real_T c16_bh_b;
  real_T c16_nh_y;
  real_T c16_pt_x;
  real_T c16_qt_x;
  real_T c16_rt_x;
  real_T c16_st_x;
  real_T c16_tt_x;
  real_T c16_ut_x;
  real_T c16_pg_a;
  real_T c16_ch_b;
  real_T c16_oh_y;
  real_T c16_vt_x;
  real_T c16_wt_x;
  real_T c16_qg_a;
  real_T c16_dh_b;
  real_T c16_ph_y;
  real_T c16_xt_x;
  real_T c16_yt_x;
  real_T c16_au_x;
  real_T c16_bu_x;
  real_T c16_rg_a;
  real_T c16_eh_b;
  real_T c16_qh_y;
  real_T c16_cu_x;
  real_T c16_du_x;
  real_T c16_sg_a;
  real_T c16_fh_b;
  real_T c16_rh_y;
  real_T c16_tg_a;
  real_T c16_gh_b;
  real_T c16_sh_y;
  real_T c16_ug_a;
  real_T c16_hh_b;
  real_T c16_th_y;
  real_T c16_vg_a;
  real_T c16_ih_b;
  real_T c16_uh_y;
  real_T c16_eu_x;
  real_T c16_fu_x;
  real_T c16_gu_x;
  real_T c16_hu_x;
  real_T c16_iu_x;
  real_T c16_ju_x;
  real_T c16_ku_x;
  real_T c16_lu_x;
  real_T c16_wg_a;
  real_T c16_jh_b;
  real_T c16_vh_y;
  real_T c16_mu_x;
  real_T c16_nu_x;
  real_T c16_xg_a;
  real_T c16_kh_b;
  real_T c16_wh_y;
  real_T c16_ou_x;
  real_T c16_pu_x;
  real_T c16_qu_x;
  real_T c16_ru_x;
  real_T c16_yg_a;
  real_T c16_lh_b;
  real_T c16_xh_y;
  real_T c16_su_x;
  real_T c16_tu_x;
  real_T c16_ah_a;
  real_T c16_mh_b;
  real_T c16_yh_y;
  real_T c16_bh_a;
  real_T c16_nh_b;
  real_T c16_ai_y;
  real_T c16_uu_x;
  real_T c16_vu_x;
  real_T c16_wu_x;
  real_T c16_xu_x;
  real_T c16_yu_x;
  real_T c16_av_x;
  real_T c16_ch_a;
  real_T c16_oh_b;
  real_T c16_bi_y;
  real_T c16_bv_x;
  real_T c16_cv_x;
  real_T c16_dh_a;
  real_T c16_ph_b;
  real_T c16_ci_y;
  real_T c16_dv_x;
  real_T c16_ev_x;
  real_T c16_fv_x;
  real_T c16_gv_x;
  real_T c16_eh_a;
  real_T c16_qh_b;
  real_T c16_di_y;
  real_T c16_hv_x;
  real_T c16_iv_x;
  real_T c16_fh_a;
  real_T c16_rh_b;
  real_T c16_ei_y;
  real_T c16_gh_a;
  real_T c16_sh_b;
  real_T c16_fi_y;
  real_T c16_hh_a;
  real_T c16_th_b;
  real_T c16_gi_y;
  real_T c16_jv_x;
  real_T c16_kv_x;
  real_T c16_lv_x;
  real_T c16_mv_x;
  real_T c16_nv_x;
  real_T c16_ov_x;
  real_T c16_pv_x;
  real_T c16_qv_x;
  real_T c16_ih_a;
  real_T c16_uh_b;
  real_T c16_hi_y;
  real_T c16_rv_x;
  real_T c16_sv_x;
  real_T c16_jh_a;
  real_T c16_vh_b;
  real_T c16_ii_y;
  real_T c16_tv_x;
  real_T c16_uv_x;
  real_T c16_vv_x;
  real_T c16_wv_x;
  real_T c16_kh_a;
  real_T c16_wh_b;
  real_T c16_ji_y;
  real_T c16_xv_x;
  real_T c16_yv_x;
  real_T c16_lh_a;
  real_T c16_xh_b;
  real_T c16_ki_y;
  real_T c16_mh_a;
  real_T c16_yh_b;
  real_T c16_li_y;
  real_T c16_aw_x;
  real_T c16_bw_x;
  real_T c16_cw_x;
  real_T c16_dw_x;
  real_T c16_ew_x;
  real_T c16_fw_x;
  real_T c16_nh_a;
  real_T c16_ai_b;
  real_T c16_mi_y;
  real_T c16_gw_x;
  real_T c16_hw_x;
  real_T c16_oh_a;
  real_T c16_bi_b;
  real_T c16_ni_y;
  real_T c16_iw_x;
  real_T c16_jw_x;
  real_T c16_kw_x;
  real_T c16_lw_x;
  real_T c16_ph_a;
  real_T c16_ci_b;
  real_T c16_oi_y;
  real_T c16_mw_x;
  real_T c16_nw_x;
  real_T c16_qh_a;
  real_T c16_di_b;
  real_T c16_pi_y;
  real_T c16_rh_a;
  real_T c16_ei_b;
  real_T c16_qi_y;
  real_T c16_sh_a;
  real_T c16_fi_b;
  real_T c16_ri_y;
  real_T c16_ow_x;
  real_T c16_pw_x;
  real_T c16_qw_x;
  real_T c16_rw_x;
  real_T c16_th_a;
  real_T c16_gi_b;
  real_T c16_si_y;
  real_T c16_sw_x;
  real_T c16_tw_x;
  real_T c16_hi_b;
  real_T c16_ti_y;
  real_T c16_uw_x;
  real_T c16_vw_x;
  real_T c16_ww_x;
  real_T c16_xw_x;
  real_T c16_uh_a;
  real_T c16_ii_b;
  real_T c16_ui_y;
  real_T c16_yw_x;
  real_T c16_ax_x;
  real_T c16_vh_a;
  real_T c16_ji_b;
  real_T c16_vi_y;
  real_T c16_bx_x;
  real_T c16_cx_x;
  real_T c16_dx_x;
  real_T c16_ex_x;
  real_T c16_wh_a;
  real_T c16_ki_b;
  real_T c16_wi_y;
  real_T c16_fx_x;
  real_T c16_gx_x;
  real_T c16_xh_a;
  real_T c16_li_b;
  real_T c16_xi_y;
  real_T c16_yh_a;
  real_T c16_mi_b;
  real_T c16_yi_y;
  real_T c16_m_A;
  real_T c16_hx_x;
  real_T c16_ix_x;
  real_T c16_aj_y;
  real_T c16_jx_x;
  real_T c16_kx_x;
  real_T c16_ni_b;
  real_T c16_bj_y;
  real_T c16_lx_x;
  real_T c16_mx_x;
  real_T c16_ai_a;
  real_T c16_oi_b;
  real_T c16_cj_y;
  real_T c16_n_A;
  real_T c16_nx_x;
  real_T c16_ox_x;
  real_T c16_dj_y;
  real_T c16_px_x;
  real_T c16_qx_x;
  real_T c16_pi_b;
  real_T c16_ej_y;
  real_T c16_rx_x;
  real_T c16_sx_x;
  real_T c16_bi_a;
  real_T c16_qi_b;
  real_T c16_fj_y;
  real_T c16_o_A;
  real_T c16_tx_x;
  real_T c16_ux_x;
  real_T c16_gj_y;
  real_T c16_vx_x;
  real_T c16_wx_x;
  real_T c16_ri_b;
  real_T c16_hj_y;
  real_T c16_p_A;
  real_T c16_xx_x;
  real_T c16_yx_x;
  real_T c16_ij_y;
  real_T c16_ay_x;
  real_T c16_by_x;
  real_T c16_si_b;
  real_T c16_jj_y;
  real_T c16_cy_x;
  real_T c16_dy_x;
  real_T c16_ey_x;
  real_T c16_fy_x;
  real_T c16_ci_a;
  real_T c16_ti_b;
  real_T c16_kj_y;
  real_T c16_gy_x;
  real_T c16_hy_x;
  real_T c16_iy_x;
  real_T c16_jy_x;
  real_T c16_ky_x;
  real_T c16_ly_x;
  real_T c16_my_x;
  real_T c16_ny_x;
  real_T c16_di_a;
  real_T c16_ui_b;
  real_T c16_lj_y;
  real_T c16_oy_x;
  real_T c16_py_x;
  real_T c16_ei_a;
  real_T c16_vi_b;
  real_T c16_mj_y;
  real_T c16_qy_x;
  real_T c16_ry_x;
  real_T c16_sy_x;
  real_T c16_ty_x;
  real_T c16_fi_a;
  real_T c16_wi_b;
  real_T c16_nj_y;
  real_T c16_uy_x;
  real_T c16_vy_x;
  real_T c16_gi_a;
  real_T c16_xi_b;
  real_T c16_oj_y;
  real_T c16_hi_a;
  real_T c16_yi_b;
  real_T c16_pj_y;
  real_T c16_wy_x;
  real_T c16_xy_x;
  real_T c16_yy_x;
  real_T c16_aab_x;
  real_T c16_bab_x;
  real_T c16_cab_x;
  real_T c16_ii_a;
  real_T c16_aj_b;
  real_T c16_qj_y;
  real_T c16_dab_x;
  real_T c16_eab_x;
  real_T c16_ji_a;
  real_T c16_bj_b;
  real_T c16_rj_y;
  real_T c16_fab_x;
  real_T c16_gab_x;
  real_T c16_hab_x;
  real_T c16_iab_x;
  real_T c16_ki_a;
  real_T c16_cj_b;
  real_T c16_sj_y;
  real_T c16_jab_x;
  real_T c16_kab_x;
  real_T c16_li_a;
  real_T c16_dj_b;
  real_T c16_tj_y;
  real_T c16_mi_a;
  real_T c16_ej_b;
  real_T c16_uj_y;
  real_T c16_ni_a;
  real_T c16_fj_b;
  real_T c16_vj_y;
  real_T c16_oi_a;
  real_T c16_gj_b;
  real_T c16_wj_y;
  real_T c16_q_A;
  real_T c16_lab_x;
  real_T c16_mab_x;
  real_T c16_xj_y;
  real_T c16_nab_x;
  real_T c16_oab_x;
  real_T c16_hj_b;
  real_T c16_yj_y;
  real_T c16_pab_x;
  real_T c16_qab_x;
  real_T c16_rab_x;
  real_T c16_sab_x;
  real_T c16_pi_a;
  real_T c16_ij_b;
  real_T c16_ak_y;
  real_T c16_tab_x;
  real_T c16_uab_x;
  real_T c16_qi_a;
  real_T c16_jj_b;
  real_T c16_bk_y;
  real_T c16_vab_x;
  real_T c16_wab_x;
  real_T c16_xab_x;
  real_T c16_yab_x;
  real_T c16_ri_a;
  real_T c16_kj_b;
  real_T c16_ck_y;
  real_T c16_abb_x;
  real_T c16_bbb_x;
  real_T c16_si_a;
  real_T c16_lj_b;
  real_T c16_dk_y;
  real_T c16_ti_a;
  real_T c16_mj_b;
  real_T c16_ek_y;
  real_T c16_r_A;
  real_T c16_cbb_x;
  real_T c16_dbb_x;
  real_T c16_fk_y;
  real_T c16_ebb_x;
  real_T c16_fbb_x;
  real_T c16_nj_b;
  real_T c16_gk_y;
  real_T c16_gbb_x;
  real_T c16_hbb_x;
  real_T c16_ibb_x;
  real_T c16_jbb_x;
  real_T c16_ui_a;
  real_T c16_oj_b;
  real_T c16_hk_y;
  real_T c16_kbb_x;
  real_T c16_lbb_x;
  real_T c16_mbb_x;
  real_T c16_nbb_x;
  real_T c16_obb_x;
  real_T c16_pbb_x;
  real_T c16_qbb_x;
  real_T c16_rbb_x;
  real_T c16_vi_a;
  real_T c16_pj_b;
  real_T c16_ik_y;
  real_T c16_sbb_x;
  real_T c16_tbb_x;
  real_T c16_wi_a;
  real_T c16_qj_b;
  real_T c16_jk_y;
  real_T c16_ubb_x;
  real_T c16_vbb_x;
  real_T c16_wbb_x;
  real_T c16_xbb_x;
  real_T c16_xi_a;
  real_T c16_rj_b;
  real_T c16_kk_y;
  real_T c16_ybb_x;
  real_T c16_acb_x;
  real_T c16_yi_a;
  real_T c16_sj_b;
  real_T c16_lk_y;
  real_T c16_aj_a;
  real_T c16_tj_b;
  real_T c16_mk_y;
  real_T c16_bcb_x;
  real_T c16_ccb_x;
  real_T c16_dcb_x;
  real_T c16_ecb_x;
  real_T c16_fcb_x;
  real_T c16_gcb_x;
  real_T c16_bj_a;
  real_T c16_uj_b;
  real_T c16_nk_y;
  real_T c16_hcb_x;
  real_T c16_icb_x;
  real_T c16_cj_a;
  real_T c16_vj_b;
  real_T c16_ok_y;
  real_T c16_jcb_x;
  real_T c16_kcb_x;
  real_T c16_lcb_x;
  real_T c16_mcb_x;
  real_T c16_dj_a;
  real_T c16_wj_b;
  real_T c16_pk_y;
  real_T c16_ncb_x;
  real_T c16_ocb_x;
  real_T c16_ej_a;
  real_T c16_xj_b;
  real_T c16_qk_y;
  real_T c16_fj_a;
  real_T c16_yj_b;
  real_T c16_rk_y;
  real_T c16_gj_a;
  real_T c16_ak_b;
  real_T c16_sk_y;
  real_T c16_hj_a;
  real_T c16_bk_b;
  real_T c16_tk_y;
  real_T c16_s_A;
  real_T c16_pcb_x;
  real_T c16_qcb_x;
  real_T c16_uk_y;
  real_T c16_rcb_x;
  real_T c16_scb_x;
  real_T c16_ck_b;
  real_T c16_vk_y;
  real_T c16_tcb_x;
  real_T c16_ucb_x;
  real_T c16_vcb_x;
  real_T c16_wcb_x;
  real_T c16_xcb_x;
  real_T c16_ycb_x;
  real_T c16_ij_a;
  real_T c16_dk_b;
  real_T c16_wk_y;
  real_T c16_adb_x;
  real_T c16_bdb_x;
  real_T c16_jj_a;
  real_T c16_ek_b;
  real_T c16_xk_y;
  real_T c16_cdb_x;
  real_T c16_ddb_x;
  real_T c16_edb_x;
  real_T c16_fdb_x;
  real_T c16_kj_a;
  real_T c16_fk_b;
  real_T c16_yk_y;
  real_T c16_gdb_x;
  real_T c16_hdb_x;
  real_T c16_lj_a;
  real_T c16_gk_b;
  real_T c16_al_y;
  real_T c16_mj_a;
  real_T c16_hk_b;
  real_T c16_bl_y;
  real_T c16_idb_x;
  real_T c16_jdb_x;
  real_T c16_kdb_x;
  real_T c16_ldb_x;
  real_T c16_mdb_x;
  real_T c16_ndb_x;
  real_T c16_nj_a;
  real_T c16_ik_b;
  real_T c16_cl_y;
  real_T c16_odb_x;
  real_T c16_pdb_x;
  real_T c16_oj_a;
  real_T c16_jk_b;
  real_T c16_dl_y;
  real_T c16_qdb_x;
  real_T c16_rdb_x;
  real_T c16_sdb_x;
  real_T c16_tdb_x;
  real_T c16_pj_a;
  real_T c16_kk_b;
  real_T c16_el_y;
  real_T c16_udb_x;
  real_T c16_vdb_x;
  real_T c16_qj_a;
  real_T c16_lk_b;
  real_T c16_fl_y;
  real_T c16_rj_a;
  real_T c16_mk_b;
  real_T c16_gl_y;
  real_T c16_sj_a;
  real_T c16_nk_b;
  real_T c16_hl_y;
  real_T c16_t_A;
  real_T c16_wdb_x;
  real_T c16_xdb_x;
  real_T c16_il_y;
  real_T c16_ydb_x;
  real_T c16_aeb_x;
  real_T c16_ok_b;
  real_T c16_jl_y;
  real_T c16_beb_x;
  real_T c16_ceb_x;
  real_T c16_deb_x;
  real_T c16_eeb_x;
  real_T c16_feb_x;
  real_T c16_geb_x;
  real_T c16_tj_a;
  real_T c16_pk_b;
  real_T c16_kl_y;
  real_T c16_heb_x;
  real_T c16_ieb_x;
  real_T c16_uj_a;
  real_T c16_qk_b;
  real_T c16_ll_y;
  real_T c16_jeb_x;
  real_T c16_keb_x;
  real_T c16_leb_x;
  real_T c16_meb_x;
  real_T c16_vj_a;
  real_T c16_rk_b;
  real_T c16_ml_y;
  real_T c16_neb_x;
  real_T c16_oeb_x;
  real_T c16_wj_a;
  real_T c16_sk_b;
  real_T c16_nl_y;
  real_T c16_xj_a;
  real_T c16_tk_b;
  real_T c16_ol_y;
  real_T c16_peb_x;
  real_T c16_qeb_x;
  real_T c16_reb_x;
  real_T c16_seb_x;
  real_T c16_teb_x;
  real_T c16_ueb_x;
  real_T c16_yj_a;
  real_T c16_uk_b;
  real_T c16_pl_y;
  real_T c16_veb_x;
  real_T c16_web_x;
  real_T c16_ak_a;
  real_T c16_vk_b;
  real_T c16_ql_y;
  real_T c16_xeb_x;
  real_T c16_yeb_x;
  real_T c16_afb_x;
  real_T c16_bfb_x;
  real_T c16_bk_a;
  real_T c16_wk_b;
  real_T c16_rl_y;
  real_T c16_cfb_x;
  real_T c16_dfb_x;
  real_T c16_ck_a;
  real_T c16_xk_b;
  real_T c16_sl_y;
  real_T c16_dk_a;
  real_T c16_yk_b;
  real_T c16_tl_y;
  real_T c16_ek_a;
  real_T c16_al_b;
  real_T c16_ul_y;
  real_T c16_u_A;
  real_T c16_efb_x;
  real_T c16_ffb_x;
  real_T c16_vl_y;
  real_T c16_gfb_x;
  real_T c16_hfb_x;
  real_T c16_bl_b;
  real_T c16_wl_y;
  real_T c16_ifb_x;
  real_T c16_jfb_x;
  real_T c16_kfb_x;
  real_T c16_lfb_x;
  real_T c16_mfb_x;
  real_T c16_nfb_x;
  real_T c16_fk_a;
  real_T c16_cl_b;
  real_T c16_xl_y;
  real_T c16_ofb_x;
  real_T c16_pfb_x;
  real_T c16_gk_a;
  real_T c16_dl_b;
  real_T c16_yl_y;
  real_T c16_qfb_x;
  real_T c16_rfb_x;
  real_T c16_sfb_x;
  real_T c16_tfb_x;
  real_T c16_hk_a;
  real_T c16_el_b;
  real_T c16_am_y;
  real_T c16_ufb_x;
  real_T c16_vfb_x;
  real_T c16_ik_a;
  real_T c16_fl_b;
  real_T c16_bm_y;
  real_T c16_jk_a;
  real_T c16_gl_b;
  real_T c16_cm_y;
  real_T c16_wfb_x;
  real_T c16_xfb_x;
  real_T c16_yfb_x;
  real_T c16_agb_x;
  real_T c16_bgb_x;
  real_T c16_cgb_x;
  real_T c16_kk_a;
  real_T c16_hl_b;
  real_T c16_dm_y;
  real_T c16_dgb_x;
  real_T c16_egb_x;
  real_T c16_lk_a;
  real_T c16_il_b;
  real_T c16_em_y;
  real_T c16_fgb_x;
  real_T c16_ggb_x;
  real_T c16_hgb_x;
  real_T c16_igb_x;
  real_T c16_mk_a;
  real_T c16_jl_b;
  real_T c16_fm_y;
  real_T c16_jgb_x;
  real_T c16_kgb_x;
  real_T c16_nk_a;
  real_T c16_kl_b;
  real_T c16_gm_y;
  real_T c16_ok_a;
  real_T c16_ll_b;
  real_T c16_hm_y;
  real_T c16_pk_a;
  real_T c16_ml_b;
  real_T c16_im_y;
  real_T c16_v_A;
  real_T c16_lgb_x;
  real_T c16_mgb_x;
  real_T c16_jm_y;
  real_T c16_ngb_x;
  real_T c16_ogb_x;
  real_T c16_nl_b;
  real_T c16_km_y;
  real_T c16_pgb_x;
  real_T c16_qgb_x;
  real_T c16_qk_a;
  real_T c16_ol_b;
  real_T c16_lm_y;
  real_T c16_rgb_x;
  real_T c16_sgb_x;
  real_T c16_rk_a;
  real_T c16_pl_b;
  real_T c16_mm_y;
  real_T c16_w_A;
  real_T c16_tgb_x;
  real_T c16_ugb_x;
  real_T c16_nm_y;
  real_T c16_vgb_x;
  real_T c16_wgb_x;
  real_T c16_ql_b;
  real_T c16_om_y;
  real_T c16_xgb_x;
  real_T c16_ygb_x;
  real_T c16_sk_a;
  real_T c16_rl_b;
  real_T c16_pm_y;
  real_T c16_ahb_x;
  real_T c16_bhb_x;
  real_T c16_tk_a;
  real_T c16_sl_b;
  real_T c16_qm_y;
  real_T c16_x_A;
  real_T c16_chb_x;
  real_T c16_dhb_x;
  real_T c16_rm_y;
  real_T c16_ehb_x;
  real_T c16_fhb_x;
  real_T c16_ghb_x;
  real_T c16_hhb_x;
  real_T c16_ihb_x;
  real_T c16_jhb_x;
  real_T c16_khb_x;
  real_T c16_lhb_x;
  real_T c16_uk_a;
  real_T c16_tl_b;
  real_T c16_sm_y;
  real_T c16_mhb_x;
  real_T c16_nhb_x;
  real_T c16_ohb_x;
  real_T c16_phb_x;
  real_T c16_vk_a;
  real_T c16_ul_b;
  real_T c16_tm_y;
  real_T c16_wk_a;
  real_T c16_vl_b;
  real_T c16_um_y;
  real_T c16_qhb_x;
  real_T c16_rhb_x;
  real_T c16_shb_x;
  real_T c16_thb_x;
  real_T c16_uhb_x;
  real_T c16_vhb_x;
  real_T c16_xk_a;
  real_T c16_wl_b;
  real_T c16_vm_y;
  real_T c16_whb_x;
  real_T c16_xhb_x;
  real_T c16_yhb_x;
  real_T c16_aib_x;
  real_T c16_yk_a;
  real_T c16_xl_b;
  real_T c16_wm_y;
  real_T c16_al_a;
  real_T c16_yl_b;
  real_T c16_xm_y;
  real_T c16_bl_a;
  real_T c16_am_b;
  real_T c16_ym_y;
  real_T c16_bib_x;
  real_T c16_cib_x;
  real_T c16_dib_x;
  real_T c16_eib_x;
  real_T c16_cl_a;
  real_T c16_bm_b;
  real_T c16_an_y;
  real_T c16_fib_x;
  real_T c16_gib_x;
  real_T c16_hib_x;
  real_T c16_iib_x;
  real_T c16_jib_x;
  real_T c16_kib_x;
  real_T c16_dl_a;
  real_T c16_cm_b;
  real_T c16_bn_y;
  real_T c16_lib_x;
  real_T c16_mib_x;
  real_T c16_nib_x;
  real_T c16_oib_x;
  real_T c16_el_a;
  real_T c16_dm_b;
  real_T c16_cn_y;
  real_T c16_fl_a;
  real_T c16_em_b;
  real_T c16_dn_y;
  real_T c16_pib_x;
  real_T c16_qib_x;
  real_T c16_rib_x;
  real_T c16_sib_x;
  real_T c16_tib_x;
  real_T c16_uib_x;
  real_T c16_gl_a;
  real_T c16_fm_b;
  real_T c16_en_y;
  real_T c16_vib_x;
  real_T c16_wib_x;
  real_T c16_xib_x;
  real_T c16_yib_x;
  real_T c16_hl_a;
  real_T c16_gm_b;
  real_T c16_fn_y;
  real_T c16_il_a;
  real_T c16_hm_b;
  real_T c16_gn_y;
  real_T c16_jl_a;
  real_T c16_im_b;
  real_T c16_hn_y;
  real_T c16_ajb_x;
  real_T c16_bjb_x;
  real_T c16_cjb_x;
  real_T c16_djb_x;
  real_T c16_ejb_x;
  real_T c16_fjb_x;
  real_T c16_gjb_x;
  real_T c16_hjb_x;
  real_T c16_kl_a;
  real_T c16_jm_b;
  real_T c16_in_y;
  real_T c16_ijb_x;
  real_T c16_jjb_x;
  real_T c16_kjb_x;
  real_T c16_ljb_x;
  real_T c16_ll_a;
  real_T c16_km_b;
  real_T c16_jn_y;
  real_T c16_ml_a;
  real_T c16_lm_b;
  real_T c16_kn_y;
  real_T c16_mjb_x;
  real_T c16_njb_x;
  real_T c16_ojb_x;
  real_T c16_pjb_x;
  real_T c16_qjb_x;
  real_T c16_rjb_x;
  real_T c16_nl_a;
  real_T c16_mm_b;
  real_T c16_ln_y;
  real_T c16_sjb_x;
  real_T c16_tjb_x;
  real_T c16_ujb_x;
  real_T c16_vjb_x;
  real_T c16_ol_a;
  real_T c16_nm_b;
  real_T c16_mn_y;
  real_T c16_pl_a;
  real_T c16_om_b;
  real_T c16_nn_y;
  real_T c16_ql_a;
  real_T c16_pm_b;
  real_T c16_on_y;
  real_T c16_wjb_x;
  real_T c16_xjb_x;
  real_T c16_yjb_x;
  real_T c16_akb_x;
  real_T c16_rl_a;
  real_T c16_qm_b;
  real_T c16_pn_y;
  real_T c16_bkb_x;
  real_T c16_ckb_x;
  real_T c16_dkb_x;
  real_T c16_ekb_x;
  real_T c16_fkb_x;
  real_T c16_gkb_x;
  real_T c16_sl_a;
  real_T c16_rm_b;
  real_T c16_qn_y;
  real_T c16_hkb_x;
  real_T c16_ikb_x;
  real_T c16_jkb_x;
  real_T c16_kkb_x;
  real_T c16_tl_a;
  real_T c16_sm_b;
  real_T c16_rn_y;
  real_T c16_ul_a;
  real_T c16_tm_b;
  real_T c16_sn_y;
  real_T c16_lkb_x;
  real_T c16_mkb_x;
  real_T c16_nkb_x;
  real_T c16_okb_x;
  real_T c16_pkb_x;
  real_T c16_qkb_x;
  real_T c16_vl_a;
  real_T c16_um_b;
  real_T c16_tn_y;
  real_T c16_rkb_x;
  real_T c16_skb_x;
  real_T c16_tkb_x;
  real_T c16_ukb_x;
  real_T c16_wl_a;
  real_T c16_vm_b;
  real_T c16_un_y;
  real_T c16_xl_a;
  real_T c16_wm_b;
  real_T c16_vn_y;
  real_T c16_yl_a;
  real_T c16_xm_b;
  real_T c16_wn_y;
  real_T c16_vkb_x;
  real_T c16_wkb_x;
  real_T c16_xkb_x;
  real_T c16_ykb_x;
  real_T c16_alb_x;
  real_T c16_blb_x;
  real_T c16_clb_x;
  real_T c16_dlb_x;
  real_T c16_am_a;
  real_T c16_ym_b;
  real_T c16_xn_y;
  real_T c16_elb_x;
  real_T c16_flb_x;
  real_T c16_glb_x;
  real_T c16_hlb_x;
  real_T c16_bm_a;
  real_T c16_an_b;
  real_T c16_yn_y;
  real_T c16_cm_a;
  real_T c16_bn_b;
  real_T c16_ao_y;
  real_T c16_ilb_x;
  real_T c16_jlb_x;
  real_T c16_klb_x;
  real_T c16_llb_x;
  real_T c16_mlb_x;
  real_T c16_nlb_x;
  real_T c16_dm_a;
  real_T c16_cn_b;
  real_T c16_bo_y;
  real_T c16_olb_x;
  real_T c16_plb_x;
  real_T c16_qlb_x;
  real_T c16_rlb_x;
  real_T c16_em_a;
  real_T c16_dn_b;
  real_T c16_co_y;
  real_T c16_fm_a;
  real_T c16_en_b;
  real_T c16_do_y;
  real_T c16_gm_a;
  real_T c16_fn_b;
  real_T c16_eo_y;
  real_T c16_slb_x;
  real_T c16_tlb_x;
  real_T c16_gn_b;
  real_T c16_fo_y;
  real_T c16_ulb_x;
  real_T c16_vlb_x;
  real_T c16_wlb_x;
  real_T c16_xlb_x;
  real_T c16_ylb_x;
  real_T c16_amb_x;
  real_T c16_hm_a;
  real_T c16_hn_b;
  real_T c16_go_y;
  real_T c16_bmb_x;
  real_T c16_cmb_x;
  real_T c16_dmb_x;
  real_T c16_emb_x;
  real_T c16_im_a;
  real_T c16_in_b;
  real_T c16_ho_y;
  real_T c16_jm_a;
  real_T c16_jn_b;
  real_T c16_io_y;
  real_T c16_fmb_x;
  real_T c16_gmb_x;
  real_T c16_hmb_x;
  real_T c16_imb_x;
  real_T c16_jmb_x;
  real_T c16_kmb_x;
  real_T c16_km_a;
  real_T c16_kn_b;
  real_T c16_jo_y;
  real_T c16_lmb_x;
  real_T c16_mmb_x;
  real_T c16_nmb_x;
  real_T c16_omb_x;
  real_T c16_lm_a;
  real_T c16_ln_b;
  real_T c16_ko_y;
  real_T c16_mm_a;
  real_T c16_mn_b;
  real_T c16_lo_y;
  real_T c16_nm_a;
  real_T c16_nn_b;
  real_T c16_mo_y;
  real_T c16_y_A;
  real_T c16_pmb_x;
  real_T c16_qmb_x;
  real_T c16_no_y;
  real_T c16_rmb_x;
  real_T c16_smb_x;
  real_T c16_on_b;
  real_T c16_oo_y;
  real_T c16_tmb_x;
  real_T c16_umb_x;
  real_T c16_om_a;
  real_T c16_pn_b;
  real_T c16_po_y;
  real_T c16_ab_A;
  real_T c16_vmb_x;
  real_T c16_wmb_x;
  real_T c16_qo_y;
  real_T c16_xmb_x;
  real_T c16_ymb_x;
  real_T c16_qn_b;
  real_T c16_ro_y;
  real_T c16_anb_x;
  real_T c16_bnb_x;
  real_T c16_pm_a;
  real_T c16_rn_b;
  real_T c16_so_y;
  real_T c16_bb_A;
  real_T c16_cnb_x;
  real_T c16_dnb_x;
  real_T c16_to_y;
  real_T c16_enb_x;
  real_T c16_fnb_x;
  real_T c16_sn_b;
  real_T c16_uo_y;
  real_T c16_cb_A;
  real_T c16_gnb_x;
  real_T c16_hnb_x;
  real_T c16_vo_y;
  real_T c16_inb_x;
  real_T c16_jnb_x;
  real_T c16_tn_b;
  real_T c16_wo_y;
  real_T c16_knb_x;
  real_T c16_lnb_x;
  real_T c16_mnb_x;
  real_T c16_nnb_x;
  real_T c16_onb_x;
  real_T c16_pnb_x;
  real_T c16_qm_a;
  real_T c16_un_b;
  real_T c16_xo_y;
  real_T c16_qnb_x;
  real_T c16_rnb_x;
  real_T c16_snb_x;
  real_T c16_tnb_x;
  real_T c16_rm_a;
  real_T c16_vn_b;
  real_T c16_yo_y;
  real_T c16_sm_a;
  real_T c16_wn_b;
  real_T c16_ap_y;
  real_T c16_unb_x;
  real_T c16_vnb_x;
  real_T c16_wnb_x;
  real_T c16_xnb_x;
  real_T c16_ynb_x;
  real_T c16_aob_x;
  real_T c16_tm_a;
  real_T c16_xn_b;
  real_T c16_bp_y;
  real_T c16_bob_x;
  real_T c16_cob_x;
  real_T c16_dob_x;
  real_T c16_eob_x;
  real_T c16_um_a;
  real_T c16_yn_b;
  real_T c16_cp_y;
  real_T c16_vm_a;
  real_T c16_ao_b;
  real_T c16_dp_y;
  real_T c16_wm_a;
  real_T c16_bo_b;
  real_T c16_ep_y;
  real_T c16_db_A;
  real_T c16_fob_x;
  real_T c16_gob_x;
  real_T c16_fp_y;
  real_T c16_hob_x;
  real_T c16_iob_x;
  real_T c16_co_b;
  real_T c16_gp_y;
  real_T c16_job_x;
  real_T c16_kob_x;
  real_T c16_lob_x;
  real_T c16_mob_x;
  real_T c16_nob_x;
  real_T c16_oob_x;
  real_T c16_xm_a;
  real_T c16_do_b;
  real_T c16_hp_y;
  real_T c16_pob_x;
  real_T c16_qob_x;
  real_T c16_rob_x;
  real_T c16_sob_x;
  real_T c16_ym_a;
  real_T c16_eo_b;
  real_T c16_ip_y;
  real_T c16_an_a;
  real_T c16_fo_b;
  real_T c16_jp_y;
  real_T c16_tob_x;
  real_T c16_uob_x;
  real_T c16_vob_x;
  real_T c16_wob_x;
  real_T c16_xob_x;
  real_T c16_yob_x;
  real_T c16_bn_a;
  real_T c16_go_b;
  real_T c16_kp_y;
  real_T c16_apb_x;
  real_T c16_bpb_x;
  real_T c16_cpb_x;
  real_T c16_dpb_x;
  real_T c16_cn_a;
  real_T c16_ho_b;
  real_T c16_lp_y;
  real_T c16_dn_a;
  real_T c16_io_b;
  real_T c16_mp_y;
  real_T c16_en_a;
  real_T c16_jo_b;
  real_T c16_np_y;
  real_T c16_eb_A;
  real_T c16_epb_x;
  real_T c16_fpb_x;
  real_T c16_op_y;
  real_T c16_gpb_x;
  real_T c16_hpb_x;
  real_T c16_ko_b;
  real_T c16_pp_y;
  real_T c16_ipb_x;
  real_T c16_jpb_x;
  real_T c16_kpb_x;
  real_T c16_lpb_x;
  real_T c16_fn_a;
  real_T c16_lo_b;
  real_T c16_qp_y;
  real_T c16_mpb_x;
  real_T c16_npb_x;
  real_T c16_opb_x;
  real_T c16_ppb_x;
  real_T c16_gn_a;
  real_T c16_mo_b;
  real_T c16_rp_y;
  real_T c16_hn_a;
  real_T c16_no_b;
  real_T c16_sp_y;
  real_T c16_fb_A;
  real_T c16_qpb_x;
  real_T c16_rpb_x;
  real_T c16_tp_y;
  real_T c16_spb_x;
  real_T c16_tpb_x;
  real_T c16_oo_b;
  real_T c16_up_y;
  real_T c16_upb_x;
  real_T c16_vpb_x;
  real_T c16_wpb_x;
  real_T c16_xpb_x;
  real_T c16_in_a;
  real_T c16_po_b;
  real_T c16_vp_y;
  real_T c16_ypb_x;
  real_T c16_aqb_x;
  real_T c16_bqb_x;
  real_T c16_cqb_x;
  real_T c16_jn_a;
  real_T c16_qo_b;
  real_T c16_wp_y;
  real_T c16_kn_a;
  real_T c16_ro_b;
  real_T c16_xp_y;
  real_T c16_gb_A;
  real_T c16_dqb_x;
  real_T c16_eqb_x;
  real_T c16_yp_y;
  real_T c16_fqb_x;
  real_T c16_gqb_x;
  real_T c16_so_b;
  real_T c16_aq_y;
  real_T c16_hqb_x;
  real_T c16_iqb_x;
  real_T c16_ln_a;
  real_T c16_to_b;
  real_T c16_bq_y;
  real_T c16_jqb_x;
  real_T c16_kqb_x;
  real_T c16_lqb_x;
  real_T c16_mqb_x;
  real_T c16_nqb_x;
  real_T c16_oqb_x;
  real_T c16_mn_a;
  real_T c16_uo_b;
  real_T c16_cq_y;
  real_T c16_pqb_x;
  real_T c16_qqb_x;
  real_T c16_rqb_x;
  real_T c16_sqb_x;
  real_T c16_nn_a;
  real_T c16_vo_b;
  real_T c16_dq_y;
  real_T c16_on_a;
  real_T c16_wo_b;
  real_T c16_eq_y;
  real_T c16_tqb_x;
  real_T c16_uqb_x;
  real_T c16_vqb_x;
  real_T c16_wqb_x;
  real_T c16_xqb_x;
  real_T c16_yqb_x;
  real_T c16_pn_a;
  real_T c16_xo_b;
  real_T c16_fq_y;
  real_T c16_arb_x;
  real_T c16_brb_x;
  real_T c16_crb_x;
  real_T c16_drb_x;
  real_T c16_qn_a;
  real_T c16_yo_b;
  real_T c16_gq_y;
  real_T c16_rn_a;
  real_T c16_ap_b;
  real_T c16_hq_y;
  real_T c16_sn_a;
  real_T c16_bp_b;
  real_T c16_iq_y;
  real_T c16_hb_A;
  real_T c16_erb_x;
  real_T c16_frb_x;
  real_T c16_jq_y;
  real_T c16_grb_x;
  real_T c16_hrb_x;
  real_T c16_cp_b;
  real_T c16_kq_y;
  real_T c16_irb_x;
  real_T c16_jrb_x;
  real_T c16_tn_a;
  real_T c16_dp_b;
  real_T c16_lq_y;
  real_T c16_krb_x;
  real_T c16_lrb_x;
  real_T c16_mrb_x;
  real_T c16_nrb_x;
  real_T c16_orb_x;
  real_T c16_prb_x;
  real_T c16_un_a;
  real_T c16_ep_b;
  real_T c16_mq_y;
  real_T c16_qrb_x;
  real_T c16_rrb_x;
  real_T c16_srb_x;
  real_T c16_trb_x;
  real_T c16_vn_a;
  real_T c16_fp_b;
  real_T c16_nq_y;
  real_T c16_wn_a;
  real_T c16_gp_b;
  real_T c16_oq_y;
  real_T c16_urb_x;
  real_T c16_vrb_x;
  real_T c16_wrb_x;
  real_T c16_xrb_x;
  real_T c16_yrb_x;
  real_T c16_asb_x;
  real_T c16_xn_a;
  real_T c16_hp_b;
  real_T c16_pq_y;
  real_T c16_bsb_x;
  real_T c16_csb_x;
  real_T c16_dsb_x;
  real_T c16_esb_x;
  real_T c16_yn_a;
  real_T c16_ip_b;
  real_T c16_qq_y;
  real_T c16_ao_a;
  real_T c16_jp_b;
  real_T c16_rq_y;
  real_T c16_bo_a;
  real_T c16_kp_b;
  real_T c16_sq_y;
  real_T c16_ib_A;
  real_T c16_fsb_x;
  real_T c16_gsb_x;
  real_T c16_tq_y;
  int32_T c16_i8;
  int32_T c16_i9;
  static real_T c16_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c16_i10;
  int32_T c16_i11;
  int32_T c16_i12;
  int32_T c16_i13;
  int32_T c16_i14;
  int32_T c16_i15;
  int32_T c16_i16;
  real_T (*c16_b_d)[3];
  real_T (*c16_b_R)[9];
  real_T (*c16_b_q)[6];
  c16_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c16_b_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
  for (c16_i7 = 0; c16_i7 < 6; c16_i7++) {
    c16_q[c16_i7] = (*c16_b_q)[c16_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta1, 0U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta2, 1U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta3, 2U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta4, 3U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta5, 4U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta6, 5U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta_1, 6U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta_2, 7U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta_3, 8U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta_4, 9U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta_5, 10U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta_6, 11U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_T, 12U, c16_e_sf_marshallOut,
    c16_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 13U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 14U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_q, 15U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_d, 16U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_R, 17U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_theta1 = c16_q[0];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 8);
  c16_theta2 = c16_q[1];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
  c16_theta3 = c16_q[2];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  c16_theta4 = c16_q[3];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  c16_theta5 = c16_q[4];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 12);
  c16_theta6 = c16_q[5];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 14);
  c16_theta_1 = c16_theta1;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 15);
  c16_theta_2 = c16_theta2;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 16);
  c16_theta_3 = c16_theta3;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 17);
  c16_theta_4 = c16_theta4;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 18);
  c16_theta_5 = c16_theta5;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 19);
  c16_theta_6 = c16_theta6;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 22);
  c16_x = c16_theta_6;
  c16_b_x = c16_x;
  c16_b_x = muDoubleScalarCos(c16_b_x);
  c16_c_x = c16_theta_1;
  c16_d_x = c16_c_x;
  c16_d_x = muDoubleScalarSin(c16_d_x);
  c16_e_x = c16_theta_5;
  c16_f_x = c16_e_x;
  c16_f_x = muDoubleScalarSin(c16_f_x);
  c16_a = c16_d_x;
  c16_b = c16_f_x;
  c16_y = c16_a * c16_b;
  c16_g_x = c16_theta_5;
  c16_h_x = c16_g_x;
  c16_h_x = muDoubleScalarCos(c16_h_x);
  c16_i_x = c16_theta_4;
  c16_j_x = c16_i_x;
  c16_j_x = muDoubleScalarCos(c16_j_x);
  c16_k_x = c16_theta_1;
  c16_l_x = c16_k_x;
  c16_l_x = muDoubleScalarCos(c16_l_x);
  c16_m_x = c16_theta_2;
  c16_n_x = c16_m_x;
  c16_n_x = muDoubleScalarSin(c16_n_x);
  c16_b_a = c16_l_x;
  c16_b_b = c16_n_x;
  c16_b_y = c16_b_a * c16_b_b;
  c16_o_x = c16_theta_3;
  c16_p_x = c16_o_x;
  c16_p_x = muDoubleScalarSin(c16_p_x);
  c16_c_a = c16_b_y;
  c16_c_b = c16_p_x;
  c16_c_y = c16_c_a * c16_c_b;
  c16_q_x = c16_theta_1;
  c16_r_x = c16_q_x;
  c16_r_x = muDoubleScalarCos(c16_r_x);
  c16_s_x = c16_theta_2;
  c16_t_x = c16_s_x;
  c16_t_x = muDoubleScalarCos(c16_t_x);
  c16_d_a = c16_r_x;
  c16_d_b = c16_t_x;
  c16_d_y = c16_d_a * c16_d_b;
  c16_u_x = c16_theta_3;
  c16_v_x = c16_u_x;
  c16_v_x = muDoubleScalarCos(c16_v_x);
  c16_e_a = c16_d_y;
  c16_e_b = c16_v_x;
  c16_e_y = c16_e_a * c16_e_b;
  c16_f_a = c16_j_x;
  c16_f_b = c16_c_y - c16_e_y;
  c16_f_y = c16_f_a * c16_f_b;
  c16_w_x = c16_theta_4;
  c16_x_x = c16_w_x;
  c16_x_x = muDoubleScalarSin(c16_x_x);
  c16_y_x = c16_theta_1;
  c16_ab_x = c16_y_x;
  c16_ab_x = muDoubleScalarCos(c16_ab_x);
  c16_bb_x = c16_theta_2;
  c16_cb_x = c16_bb_x;
  c16_cb_x = muDoubleScalarCos(c16_cb_x);
  c16_g_a = c16_ab_x;
  c16_g_b = c16_cb_x;
  c16_g_y = c16_g_a * c16_g_b;
  c16_db_x = c16_theta_3;
  c16_eb_x = c16_db_x;
  c16_eb_x = muDoubleScalarSin(c16_eb_x);
  c16_h_a = c16_g_y;
  c16_h_b = c16_eb_x;
  c16_h_y = c16_h_a * c16_h_b;
  c16_fb_x = c16_theta_1;
  c16_gb_x = c16_fb_x;
  c16_gb_x = muDoubleScalarCos(c16_gb_x);
  c16_hb_x = c16_theta_3;
  c16_ib_x = c16_hb_x;
  c16_ib_x = muDoubleScalarCos(c16_ib_x);
  c16_i_a = c16_gb_x;
  c16_i_b = c16_ib_x;
  c16_i_y = c16_i_a * c16_i_b;
  c16_jb_x = c16_theta_2;
  c16_kb_x = c16_jb_x;
  c16_kb_x = muDoubleScalarSin(c16_kb_x);
  c16_j_a = c16_i_y;
  c16_j_b = c16_kb_x;
  c16_j_y = c16_j_a * c16_j_b;
  c16_k_a = c16_x_x;
  c16_k_b = c16_h_y + c16_j_y;
  c16_k_y = c16_k_a * c16_k_b;
  c16_l_a = c16_h_x;
  c16_l_b = c16_f_y + c16_k_y;
  c16_l_y = c16_l_a * c16_l_b;
  c16_m_a = c16_b_x;
  c16_m_b = c16_y - c16_l_y;
  c16_m_y = c16_m_a * c16_m_b;
  c16_lb_x = c16_theta_6;
  c16_mb_x = c16_lb_x;
  c16_mb_x = muDoubleScalarSin(c16_mb_x);
  c16_nb_x = c16_theta_4;
  c16_ob_x = c16_nb_x;
  c16_ob_x = muDoubleScalarCos(c16_ob_x);
  c16_pb_x = c16_theta_1;
  c16_qb_x = c16_pb_x;
  c16_qb_x = muDoubleScalarCos(c16_qb_x);
  c16_rb_x = c16_theta_2;
  c16_sb_x = c16_rb_x;
  c16_sb_x = muDoubleScalarCos(c16_sb_x);
  c16_n_a = c16_qb_x;
  c16_n_b = c16_sb_x;
  c16_n_y = c16_n_a * c16_n_b;
  c16_tb_x = c16_theta_3;
  c16_ub_x = c16_tb_x;
  c16_ub_x = muDoubleScalarSin(c16_ub_x);
  c16_o_a = c16_n_y;
  c16_o_b = c16_ub_x;
  c16_o_y = c16_o_a * c16_o_b;
  c16_vb_x = c16_theta_1;
  c16_wb_x = c16_vb_x;
  c16_wb_x = muDoubleScalarCos(c16_wb_x);
  c16_xb_x = c16_theta_3;
  c16_yb_x = c16_xb_x;
  c16_yb_x = muDoubleScalarCos(c16_yb_x);
  c16_p_a = c16_wb_x;
  c16_p_b = c16_yb_x;
  c16_p_y = c16_p_a * c16_p_b;
  c16_ac_x = c16_theta_2;
  c16_bc_x = c16_ac_x;
  c16_bc_x = muDoubleScalarSin(c16_bc_x);
  c16_q_a = c16_p_y;
  c16_q_b = c16_bc_x;
  c16_q_y = c16_q_a * c16_q_b;
  c16_r_a = c16_ob_x;
  c16_r_b = c16_o_y + c16_q_y;
  c16_r_y = c16_r_a * c16_r_b;
  c16_cc_x = c16_theta_4;
  c16_dc_x = c16_cc_x;
  c16_dc_x = muDoubleScalarSin(c16_dc_x);
  c16_ec_x = c16_theta_1;
  c16_fc_x = c16_ec_x;
  c16_fc_x = muDoubleScalarCos(c16_fc_x);
  c16_gc_x = c16_theta_2;
  c16_hc_x = c16_gc_x;
  c16_hc_x = muDoubleScalarSin(c16_hc_x);
  c16_s_a = c16_fc_x;
  c16_s_b = c16_hc_x;
  c16_s_y = c16_s_a * c16_s_b;
  c16_ic_x = c16_theta_3;
  c16_jc_x = c16_ic_x;
  c16_jc_x = muDoubleScalarSin(c16_jc_x);
  c16_t_a = c16_s_y;
  c16_t_b = c16_jc_x;
  c16_t_y = c16_t_a * c16_t_b;
  c16_kc_x = c16_theta_1;
  c16_lc_x = c16_kc_x;
  c16_lc_x = muDoubleScalarCos(c16_lc_x);
  c16_mc_x = c16_theta_2;
  c16_nc_x = c16_mc_x;
  c16_nc_x = muDoubleScalarCos(c16_nc_x);
  c16_u_a = c16_lc_x;
  c16_u_b = c16_nc_x;
  c16_u_y = c16_u_a * c16_u_b;
  c16_oc_x = c16_theta_3;
  c16_pc_x = c16_oc_x;
  c16_pc_x = muDoubleScalarCos(c16_pc_x);
  c16_v_a = c16_u_y;
  c16_v_b = c16_pc_x;
  c16_v_y = c16_v_a * c16_v_b;
  c16_w_a = c16_dc_x;
  c16_w_b = c16_t_y - c16_v_y;
  c16_w_y = c16_w_a * c16_w_b;
  c16_x_a = c16_mb_x;
  c16_x_b = c16_r_y - c16_w_y;
  c16_x_y = c16_x_a * c16_x_b;
  c16_qc_x = c16_theta_6;
  c16_rc_x = c16_qc_x;
  c16_rc_x = muDoubleScalarSin(c16_rc_x);
  c16_sc_x = c16_theta_1;
  c16_tc_x = c16_sc_x;
  c16_tc_x = muDoubleScalarSin(c16_tc_x);
  c16_uc_x = c16_theta_5;
  c16_vc_x = c16_uc_x;
  c16_vc_x = muDoubleScalarSin(c16_vc_x);
  c16_y_a = c16_tc_x;
  c16_y_b = c16_vc_x;
  c16_y_y = c16_y_a * c16_y_b;
  c16_wc_x = c16_theta_5;
  c16_xc_x = c16_wc_x;
  c16_xc_x = muDoubleScalarCos(c16_xc_x);
  c16_yc_x = c16_theta_4;
  c16_ad_x = c16_yc_x;
  c16_ad_x = muDoubleScalarCos(c16_ad_x);
  c16_bd_x = c16_theta_1;
  c16_cd_x = c16_bd_x;
  c16_cd_x = muDoubleScalarCos(c16_cd_x);
  c16_dd_x = c16_theta_2;
  c16_ed_x = c16_dd_x;
  c16_ed_x = muDoubleScalarSin(c16_ed_x);
  c16_ab_a = c16_cd_x;
  c16_ab_b = c16_ed_x;
  c16_ab_y = c16_ab_a * c16_ab_b;
  c16_fd_x = c16_theta_3;
  c16_gd_x = c16_fd_x;
  c16_gd_x = muDoubleScalarSin(c16_gd_x);
  c16_bb_a = c16_ab_y;
  c16_bb_b = c16_gd_x;
  c16_bb_y = c16_bb_a * c16_bb_b;
  c16_hd_x = c16_theta_1;
  c16_id_x = c16_hd_x;
  c16_id_x = muDoubleScalarCos(c16_id_x);
  c16_jd_x = c16_theta_2;
  c16_kd_x = c16_jd_x;
  c16_kd_x = muDoubleScalarCos(c16_kd_x);
  c16_cb_a = c16_id_x;
  c16_cb_b = c16_kd_x;
  c16_cb_y = c16_cb_a * c16_cb_b;
  c16_ld_x = c16_theta_3;
  c16_md_x = c16_ld_x;
  c16_md_x = muDoubleScalarCos(c16_md_x);
  c16_db_a = c16_cb_y;
  c16_db_b = c16_md_x;
  c16_db_y = c16_db_a * c16_db_b;
  c16_eb_a = c16_ad_x;
  c16_eb_b = c16_bb_y - c16_db_y;
  c16_eb_y = c16_eb_a * c16_eb_b;
  c16_nd_x = c16_theta_4;
  c16_od_x = c16_nd_x;
  c16_od_x = muDoubleScalarSin(c16_od_x);
  c16_pd_x = c16_theta_1;
  c16_qd_x = c16_pd_x;
  c16_qd_x = muDoubleScalarCos(c16_qd_x);
  c16_rd_x = c16_theta_2;
  c16_sd_x = c16_rd_x;
  c16_sd_x = muDoubleScalarCos(c16_sd_x);
  c16_fb_a = c16_qd_x;
  c16_fb_b = c16_sd_x;
  c16_fb_y = c16_fb_a * c16_fb_b;
  c16_td_x = c16_theta_3;
  c16_ud_x = c16_td_x;
  c16_ud_x = muDoubleScalarSin(c16_ud_x);
  c16_gb_a = c16_fb_y;
  c16_gb_b = c16_ud_x;
  c16_gb_y = c16_gb_a * c16_gb_b;
  c16_vd_x = c16_theta_1;
  c16_wd_x = c16_vd_x;
  c16_wd_x = muDoubleScalarCos(c16_wd_x);
  c16_xd_x = c16_theta_3;
  c16_yd_x = c16_xd_x;
  c16_yd_x = muDoubleScalarCos(c16_yd_x);
  c16_hb_a = c16_wd_x;
  c16_hb_b = c16_yd_x;
  c16_hb_y = c16_hb_a * c16_hb_b;
  c16_ae_x = c16_theta_2;
  c16_be_x = c16_ae_x;
  c16_be_x = muDoubleScalarSin(c16_be_x);
  c16_ib_a = c16_hb_y;
  c16_ib_b = c16_be_x;
  c16_ib_y = c16_ib_a * c16_ib_b;
  c16_jb_a = c16_od_x;
  c16_jb_b = c16_gb_y + c16_ib_y;
  c16_jb_y = c16_jb_a * c16_jb_b;
  c16_kb_a = c16_xc_x;
  c16_kb_b = c16_eb_y + c16_jb_y;
  c16_kb_y = c16_kb_a * c16_kb_b;
  c16_lb_a = -c16_rc_x;
  c16_lb_b = c16_y_y - c16_kb_y;
  c16_lb_y = c16_lb_a * c16_lb_b;
  c16_ce_x = c16_theta_6;
  c16_de_x = c16_ce_x;
  c16_de_x = muDoubleScalarCos(c16_de_x);
  c16_ee_x = c16_theta_4;
  c16_fe_x = c16_ee_x;
  c16_fe_x = muDoubleScalarCos(c16_fe_x);
  c16_ge_x = c16_theta_1;
  c16_he_x = c16_ge_x;
  c16_he_x = muDoubleScalarCos(c16_he_x);
  c16_ie_x = c16_theta_2;
  c16_je_x = c16_ie_x;
  c16_je_x = muDoubleScalarCos(c16_je_x);
  c16_mb_a = c16_he_x;
  c16_mb_b = c16_je_x;
  c16_mb_y = c16_mb_a * c16_mb_b;
  c16_ke_x = c16_theta_3;
  c16_le_x = c16_ke_x;
  c16_le_x = muDoubleScalarSin(c16_le_x);
  c16_nb_a = c16_mb_y;
  c16_nb_b = c16_le_x;
  c16_nb_y = c16_nb_a * c16_nb_b;
  c16_me_x = c16_theta_1;
  c16_ne_x = c16_me_x;
  c16_ne_x = muDoubleScalarCos(c16_ne_x);
  c16_oe_x = c16_theta_3;
  c16_pe_x = c16_oe_x;
  c16_pe_x = muDoubleScalarCos(c16_pe_x);
  c16_ob_a = c16_ne_x;
  c16_ob_b = c16_pe_x;
  c16_ob_y = c16_ob_a * c16_ob_b;
  c16_qe_x = c16_theta_2;
  c16_re_x = c16_qe_x;
  c16_re_x = muDoubleScalarSin(c16_re_x);
  c16_pb_a = c16_ob_y;
  c16_pb_b = c16_re_x;
  c16_pb_y = c16_pb_a * c16_pb_b;
  c16_qb_a = c16_fe_x;
  c16_qb_b = c16_nb_y + c16_pb_y;
  c16_qb_y = c16_qb_a * c16_qb_b;
  c16_se_x = c16_theta_4;
  c16_te_x = c16_se_x;
  c16_te_x = muDoubleScalarSin(c16_te_x);
  c16_ue_x = c16_theta_1;
  c16_ve_x = c16_ue_x;
  c16_ve_x = muDoubleScalarCos(c16_ve_x);
  c16_we_x = c16_theta_2;
  c16_xe_x = c16_we_x;
  c16_xe_x = muDoubleScalarSin(c16_xe_x);
  c16_rb_a = c16_ve_x;
  c16_rb_b = c16_xe_x;
  c16_rb_y = c16_rb_a * c16_rb_b;
  c16_ye_x = c16_theta_3;
  c16_af_x = c16_ye_x;
  c16_af_x = muDoubleScalarSin(c16_af_x);
  c16_sb_a = c16_rb_y;
  c16_sb_b = c16_af_x;
  c16_sb_y = c16_sb_a * c16_sb_b;
  c16_bf_x = c16_theta_1;
  c16_cf_x = c16_bf_x;
  c16_cf_x = muDoubleScalarCos(c16_cf_x);
  c16_df_x = c16_theta_2;
  c16_ef_x = c16_df_x;
  c16_ef_x = muDoubleScalarCos(c16_ef_x);
  c16_tb_a = c16_cf_x;
  c16_tb_b = c16_ef_x;
  c16_tb_y = c16_tb_a * c16_tb_b;
  c16_ff_x = c16_theta_3;
  c16_gf_x = c16_ff_x;
  c16_gf_x = muDoubleScalarCos(c16_gf_x);
  c16_ub_a = c16_tb_y;
  c16_ub_b = c16_gf_x;
  c16_ub_y = c16_ub_a * c16_ub_b;
  c16_vb_a = c16_te_x;
  c16_vb_b = c16_sb_y - c16_ub_y;
  c16_vb_y = c16_vb_a * c16_vb_b;
  c16_wb_a = c16_de_x;
  c16_wb_b = c16_qb_y - c16_vb_y;
  c16_wb_y = c16_wb_a * c16_wb_b;
  c16_hf_x = c16_theta_5;
  c16_if_x = c16_hf_x;
  c16_if_x = muDoubleScalarCos(c16_if_x);
  c16_jf_x = c16_theta_1;
  c16_kf_x = c16_jf_x;
  c16_kf_x = muDoubleScalarSin(c16_kf_x);
  c16_xb_a = c16_if_x;
  c16_xb_b = c16_kf_x;
  c16_xb_y = c16_xb_a * c16_xb_b;
  c16_lf_x = c16_theta_5;
  c16_mf_x = c16_lf_x;
  c16_mf_x = muDoubleScalarSin(c16_mf_x);
  c16_nf_x = c16_theta_4;
  c16_of_x = c16_nf_x;
  c16_of_x = muDoubleScalarCos(c16_of_x);
  c16_pf_x = c16_theta_1;
  c16_qf_x = c16_pf_x;
  c16_qf_x = muDoubleScalarCos(c16_qf_x);
  c16_rf_x = c16_theta_2;
  c16_sf_x = c16_rf_x;
  c16_sf_x = muDoubleScalarSin(c16_sf_x);
  c16_yb_a = c16_qf_x;
  c16_yb_b = c16_sf_x;
  c16_yb_y = c16_yb_a * c16_yb_b;
  c16_tf_x = c16_theta_3;
  c16_uf_x = c16_tf_x;
  c16_uf_x = muDoubleScalarSin(c16_uf_x);
  c16_ac_a = c16_yb_y;
  c16_ac_b = c16_uf_x;
  c16_ac_y = c16_ac_a * c16_ac_b;
  c16_vf_x = c16_theta_1;
  c16_wf_x = c16_vf_x;
  c16_wf_x = muDoubleScalarCos(c16_wf_x);
  c16_xf_x = c16_theta_2;
  c16_yf_x = c16_xf_x;
  c16_yf_x = muDoubleScalarCos(c16_yf_x);
  c16_bc_a = c16_wf_x;
  c16_bc_b = c16_yf_x;
  c16_bc_y = c16_bc_a * c16_bc_b;
  c16_ag_x = c16_theta_3;
  c16_bg_x = c16_ag_x;
  c16_bg_x = muDoubleScalarCos(c16_bg_x);
  c16_cc_a = c16_bc_y;
  c16_cc_b = c16_bg_x;
  c16_cc_y = c16_cc_a * c16_cc_b;
  c16_dc_a = c16_of_x;
  c16_dc_b = c16_ac_y - c16_cc_y;
  c16_dc_y = c16_dc_a * c16_dc_b;
  c16_cg_x = c16_theta_4;
  c16_dg_x = c16_cg_x;
  c16_dg_x = muDoubleScalarSin(c16_dg_x);
  c16_eg_x = c16_theta_1;
  c16_fg_x = c16_eg_x;
  c16_fg_x = muDoubleScalarCos(c16_fg_x);
  c16_gg_x = c16_theta_2;
  c16_hg_x = c16_gg_x;
  c16_hg_x = muDoubleScalarCos(c16_hg_x);
  c16_ec_a = c16_fg_x;
  c16_ec_b = c16_hg_x;
  c16_ec_y = c16_ec_a * c16_ec_b;
  c16_ig_x = c16_theta_3;
  c16_jg_x = c16_ig_x;
  c16_jg_x = muDoubleScalarSin(c16_jg_x);
  c16_fc_a = c16_ec_y;
  c16_fc_b = c16_jg_x;
  c16_fc_y = c16_fc_a * c16_fc_b;
  c16_kg_x = c16_theta_1;
  c16_lg_x = c16_kg_x;
  c16_lg_x = muDoubleScalarCos(c16_lg_x);
  c16_mg_x = c16_theta_3;
  c16_ng_x = c16_mg_x;
  c16_ng_x = muDoubleScalarCos(c16_ng_x);
  c16_gc_a = c16_lg_x;
  c16_gc_b = c16_ng_x;
  c16_gc_y = c16_gc_a * c16_gc_b;
  c16_og_x = c16_theta_2;
  c16_pg_x = c16_og_x;
  c16_pg_x = muDoubleScalarSin(c16_pg_x);
  c16_hc_a = c16_gc_y;
  c16_hc_b = c16_pg_x;
  c16_hc_y = c16_hc_a * c16_hc_b;
  c16_ic_a = c16_dg_x;
  c16_ic_b = c16_fc_y + c16_hc_y;
  c16_ic_y = c16_ic_a * c16_ic_b;
  c16_jc_a = c16_mf_x;
  c16_jc_b = c16_dc_y + c16_ic_y;
  c16_jc_y = c16_jc_a * c16_jc_b;
  c16_qg_x = c16_theta_1;
  c16_rg_x = c16_qg_x;
  c16_rg_x = muDoubleScalarSin(c16_rg_x);
  c16_kc_b = c16_rg_x;
  c16_kc_y = 109.0 * c16_kc_b;
  c16_A = c16_kc_y;
  c16_sg_x = c16_A;
  c16_tg_x = c16_sg_x;
  c16_lc_y = c16_tg_x / 1000.0;
  c16_ug_x = c16_theta_1;
  c16_vg_x = c16_ug_x;
  c16_vg_x = muDoubleScalarCos(c16_vg_x);
  c16_lc_b = c16_vg_x;
  c16_mc_y = 17.0 * c16_lc_b;
  c16_wg_x = c16_theta_2;
  c16_xg_x = c16_wg_x;
  c16_xg_x = muDoubleScalarCos(c16_xg_x);
  c16_kc_a = c16_mc_y;
  c16_mc_b = c16_xg_x;
  c16_nc_y = c16_kc_a * c16_mc_b;
  c16_b_A = c16_nc_y;
  c16_yg_x = c16_b_A;
  c16_ah_x = c16_yg_x;
  c16_oc_y = c16_ah_x / 40.0;
  c16_bh_x = c16_theta_5;
  c16_ch_x = c16_bh_x;
  c16_ch_x = muDoubleScalarCos(c16_ch_x);
  c16_nc_b = c16_ch_x;
  c16_pc_y = 183.0 * c16_nc_b;
  c16_dh_x = c16_theta_1;
  c16_eh_x = c16_dh_x;
  c16_eh_x = muDoubleScalarSin(c16_eh_x);
  c16_lc_a = c16_pc_y;
  c16_oc_b = c16_eh_x;
  c16_qc_y = c16_lc_a * c16_oc_b;
  c16_c_A = c16_qc_y;
  c16_fh_x = c16_c_A;
  c16_gh_x = c16_fh_x;
  c16_rc_y = c16_gh_x / 2000.0;
  c16_hh_x = c16_theta_6;
  c16_ih_x = c16_hh_x;
  c16_ih_x = muDoubleScalarCos(c16_ih_x);
  c16_pc_b = c16_ih_x;
  c16_sc_y = 347.0 * c16_pc_b;
  c16_jh_x = c16_theta_1;
  c16_kh_x = c16_jh_x;
  c16_kh_x = muDoubleScalarSin(c16_kh_x);
  c16_lh_x = c16_theta_5;
  c16_mh_x = c16_lh_x;
  c16_mh_x = muDoubleScalarSin(c16_mh_x);
  c16_mc_a = c16_kh_x;
  c16_qc_b = c16_mh_x;
  c16_tc_y = c16_mc_a * c16_qc_b;
  c16_nh_x = c16_theta_5;
  c16_oh_x = c16_nh_x;
  c16_oh_x = muDoubleScalarCos(c16_oh_x);
  c16_ph_x = c16_theta_4;
  c16_qh_x = c16_ph_x;
  c16_qh_x = muDoubleScalarCos(c16_qh_x);
  c16_rh_x = c16_theta_1;
  c16_sh_x = c16_rh_x;
  c16_sh_x = muDoubleScalarCos(c16_sh_x);
  c16_th_x = c16_theta_2;
  c16_uh_x = c16_th_x;
  c16_uh_x = muDoubleScalarSin(c16_uh_x);
  c16_nc_a = c16_sh_x;
  c16_rc_b = c16_uh_x;
  c16_uc_y = c16_nc_a * c16_rc_b;
  c16_vh_x = c16_theta_3;
  c16_wh_x = c16_vh_x;
  c16_wh_x = muDoubleScalarSin(c16_wh_x);
  c16_oc_a = c16_uc_y;
  c16_sc_b = c16_wh_x;
  c16_vc_y = c16_oc_a * c16_sc_b;
  c16_xh_x = c16_theta_1;
  c16_yh_x = c16_xh_x;
  c16_yh_x = muDoubleScalarCos(c16_yh_x);
  c16_ai_x = c16_theta_2;
  c16_bi_x = c16_ai_x;
  c16_bi_x = muDoubleScalarCos(c16_bi_x);
  c16_pc_a = c16_yh_x;
  c16_tc_b = c16_bi_x;
  c16_wc_y = c16_pc_a * c16_tc_b;
  c16_ci_x = c16_theta_3;
  c16_di_x = c16_ci_x;
  c16_di_x = muDoubleScalarCos(c16_di_x);
  c16_qc_a = c16_wc_y;
  c16_uc_b = c16_di_x;
  c16_xc_y = c16_qc_a * c16_uc_b;
  c16_rc_a = c16_qh_x;
  c16_vc_b = c16_vc_y - c16_xc_y;
  c16_yc_y = c16_rc_a * c16_vc_b;
  c16_ei_x = c16_theta_4;
  c16_fi_x = c16_ei_x;
  c16_fi_x = muDoubleScalarSin(c16_fi_x);
  c16_gi_x = c16_theta_1;
  c16_hi_x = c16_gi_x;
  c16_hi_x = muDoubleScalarCos(c16_hi_x);
  c16_ii_x = c16_theta_2;
  c16_ji_x = c16_ii_x;
  c16_ji_x = muDoubleScalarCos(c16_ji_x);
  c16_sc_a = c16_hi_x;
  c16_wc_b = c16_ji_x;
  c16_ad_y = c16_sc_a * c16_wc_b;
  c16_ki_x = c16_theta_3;
  c16_li_x = c16_ki_x;
  c16_li_x = muDoubleScalarSin(c16_li_x);
  c16_tc_a = c16_ad_y;
  c16_xc_b = c16_li_x;
  c16_bd_y = c16_tc_a * c16_xc_b;
  c16_mi_x = c16_theta_1;
  c16_ni_x = c16_mi_x;
  c16_ni_x = muDoubleScalarCos(c16_ni_x);
  c16_oi_x = c16_theta_3;
  c16_pi_x = c16_oi_x;
  c16_pi_x = muDoubleScalarCos(c16_pi_x);
  c16_uc_a = c16_ni_x;
  c16_yc_b = c16_pi_x;
  c16_cd_y = c16_uc_a * c16_yc_b;
  c16_qi_x = c16_theta_2;
  c16_ri_x = c16_qi_x;
  c16_ri_x = muDoubleScalarSin(c16_ri_x);
  c16_vc_a = c16_cd_y;
  c16_ad_b = c16_ri_x;
  c16_dd_y = c16_vc_a * c16_ad_b;
  c16_wc_a = c16_fi_x;
  c16_bd_b = c16_bd_y + c16_dd_y;
  c16_ed_y = c16_wc_a * c16_bd_b;
  c16_xc_a = c16_oh_x;
  c16_cd_b = c16_yc_y + c16_ed_y;
  c16_fd_y = c16_xc_a * c16_cd_b;
  c16_yc_a = c16_sc_y;
  c16_dd_b = c16_tc_y - c16_fd_y;
  c16_gd_y = c16_yc_a * c16_dd_b;
  c16_d_A = c16_gd_y;
  c16_si_x = c16_d_A;
  c16_ti_x = c16_si_x;
  c16_hd_y = c16_ti_x / 20000.0;
  c16_ui_x = c16_theta_4;
  c16_vi_x = c16_ui_x;
  c16_vi_x = muDoubleScalarCos(c16_vi_x);
  c16_ed_b = c16_vi_x;
  c16_id_y = 93.0 * c16_ed_b;
  c16_wi_x = c16_theta_1;
  c16_xi_x = c16_wi_x;
  c16_xi_x = muDoubleScalarCos(c16_xi_x);
  c16_yi_x = c16_theta_2;
  c16_aj_x = c16_yi_x;
  c16_aj_x = muDoubleScalarCos(c16_aj_x);
  c16_ad_a = c16_xi_x;
  c16_fd_b = c16_aj_x;
  c16_jd_y = c16_ad_a * c16_fd_b;
  c16_bj_x = c16_theta_3;
  c16_cj_x = c16_bj_x;
  c16_cj_x = muDoubleScalarSin(c16_cj_x);
  c16_bd_a = c16_jd_y;
  c16_gd_b = c16_cj_x;
  c16_kd_y = c16_bd_a * c16_gd_b;
  c16_dj_x = c16_theta_1;
  c16_ej_x = c16_dj_x;
  c16_ej_x = muDoubleScalarCos(c16_ej_x);
  c16_fj_x = c16_theta_3;
  c16_gj_x = c16_fj_x;
  c16_gj_x = muDoubleScalarCos(c16_gj_x);
  c16_cd_a = c16_ej_x;
  c16_hd_b = c16_gj_x;
  c16_ld_y = c16_cd_a * c16_hd_b;
  c16_hj_x = c16_theta_2;
  c16_ij_x = c16_hj_x;
  c16_ij_x = muDoubleScalarSin(c16_ij_x);
  c16_dd_a = c16_ld_y;
  c16_id_b = c16_ij_x;
  c16_md_y = c16_dd_a * c16_id_b;
  c16_ed_a = c16_id_y;
  c16_jd_b = c16_kd_y + c16_md_y;
  c16_nd_y = c16_ed_a * c16_jd_b;
  c16_e_A = c16_nd_y;
  c16_jj_x = c16_e_A;
  c16_kj_x = c16_jj_x;
  c16_od_y = c16_kj_x / 1000.0;
  c16_lj_x = c16_theta_6;
  c16_mj_x = c16_lj_x;
  c16_mj_x = muDoubleScalarSin(c16_mj_x);
  c16_kd_b = c16_mj_x;
  c16_pd_y = 121.0 * c16_kd_b;
  c16_nj_x = c16_theta_1;
  c16_oj_x = c16_nj_x;
  c16_oj_x = muDoubleScalarSin(c16_oj_x);
  c16_pj_x = c16_theta_5;
  c16_qj_x = c16_pj_x;
  c16_qj_x = muDoubleScalarSin(c16_qj_x);
  c16_fd_a = c16_oj_x;
  c16_ld_b = c16_qj_x;
  c16_qd_y = c16_fd_a * c16_ld_b;
  c16_rj_x = c16_theta_5;
  c16_sj_x = c16_rj_x;
  c16_sj_x = muDoubleScalarCos(c16_sj_x);
  c16_tj_x = c16_theta_4;
  c16_uj_x = c16_tj_x;
  c16_uj_x = muDoubleScalarCos(c16_uj_x);
  c16_vj_x = c16_theta_1;
  c16_wj_x = c16_vj_x;
  c16_wj_x = muDoubleScalarCos(c16_wj_x);
  c16_xj_x = c16_theta_2;
  c16_yj_x = c16_xj_x;
  c16_yj_x = muDoubleScalarSin(c16_yj_x);
  c16_gd_a = c16_wj_x;
  c16_md_b = c16_yj_x;
  c16_rd_y = c16_gd_a * c16_md_b;
  c16_ak_x = c16_theta_3;
  c16_bk_x = c16_ak_x;
  c16_bk_x = muDoubleScalarSin(c16_bk_x);
  c16_hd_a = c16_rd_y;
  c16_nd_b = c16_bk_x;
  c16_sd_y = c16_hd_a * c16_nd_b;
  c16_ck_x = c16_theta_1;
  c16_dk_x = c16_ck_x;
  c16_dk_x = muDoubleScalarCos(c16_dk_x);
  c16_ek_x = c16_theta_2;
  c16_fk_x = c16_ek_x;
  c16_fk_x = muDoubleScalarCos(c16_fk_x);
  c16_id_a = c16_dk_x;
  c16_od_b = c16_fk_x;
  c16_td_y = c16_id_a * c16_od_b;
  c16_gk_x = c16_theta_3;
  c16_hk_x = c16_gk_x;
  c16_hk_x = muDoubleScalarCos(c16_hk_x);
  c16_jd_a = c16_td_y;
  c16_pd_b = c16_hk_x;
  c16_ud_y = c16_jd_a * c16_pd_b;
  c16_kd_a = c16_uj_x;
  c16_qd_b = c16_sd_y - c16_ud_y;
  c16_vd_y = c16_kd_a * c16_qd_b;
  c16_ik_x = c16_theta_4;
  c16_jk_x = c16_ik_x;
  c16_jk_x = muDoubleScalarSin(c16_jk_x);
  c16_kk_x = c16_theta_1;
  c16_lk_x = c16_kk_x;
  c16_lk_x = muDoubleScalarCos(c16_lk_x);
  c16_mk_x = c16_theta_2;
  c16_nk_x = c16_mk_x;
  c16_nk_x = muDoubleScalarCos(c16_nk_x);
  c16_ld_a = c16_lk_x;
  c16_rd_b = c16_nk_x;
  c16_wd_y = c16_ld_a * c16_rd_b;
  c16_ok_x = c16_theta_3;
  c16_pk_x = c16_ok_x;
  c16_pk_x = muDoubleScalarSin(c16_pk_x);
  c16_md_a = c16_wd_y;
  c16_sd_b = c16_pk_x;
  c16_xd_y = c16_md_a * c16_sd_b;
  c16_qk_x = c16_theta_1;
  c16_rk_x = c16_qk_x;
  c16_rk_x = muDoubleScalarCos(c16_rk_x);
  c16_sk_x = c16_theta_3;
  c16_tk_x = c16_sk_x;
  c16_tk_x = muDoubleScalarCos(c16_tk_x);
  c16_nd_a = c16_rk_x;
  c16_td_b = c16_tk_x;
  c16_yd_y = c16_nd_a * c16_td_b;
  c16_uk_x = c16_theta_2;
  c16_vk_x = c16_uk_x;
  c16_vk_x = muDoubleScalarSin(c16_vk_x);
  c16_od_a = c16_yd_y;
  c16_ud_b = c16_vk_x;
  c16_ae_y = c16_od_a * c16_ud_b;
  c16_pd_a = c16_jk_x;
  c16_vd_b = c16_xd_y + c16_ae_y;
  c16_be_y = c16_pd_a * c16_vd_b;
  c16_qd_a = c16_sj_x;
  c16_wd_b = c16_vd_y + c16_be_y;
  c16_ce_y = c16_qd_a * c16_wd_b;
  c16_rd_a = c16_pd_y;
  c16_xd_b = c16_qd_y - c16_ce_y;
  c16_de_y = c16_rd_a * c16_xd_b;
  c16_f_A = c16_de_y;
  c16_wk_x = c16_f_A;
  c16_xk_x = c16_wk_x;
  c16_ee_y = c16_xk_x / 20000.0;
  c16_yk_x = c16_theta_4;
  c16_al_x = c16_yk_x;
  c16_al_x = muDoubleScalarSin(c16_al_x);
  c16_yd_b = c16_al_x;
  c16_fe_y = 93.0 * c16_yd_b;
  c16_bl_x = c16_theta_1;
  c16_cl_x = c16_bl_x;
  c16_cl_x = muDoubleScalarCos(c16_cl_x);
  c16_dl_x = c16_theta_2;
  c16_el_x = c16_dl_x;
  c16_el_x = muDoubleScalarSin(c16_el_x);
  c16_sd_a = c16_cl_x;
  c16_ae_b = c16_el_x;
  c16_ge_y = c16_sd_a * c16_ae_b;
  c16_fl_x = c16_theta_3;
  c16_gl_x = c16_fl_x;
  c16_gl_x = muDoubleScalarSin(c16_gl_x);
  c16_td_a = c16_ge_y;
  c16_be_b = c16_gl_x;
  c16_he_y = c16_td_a * c16_be_b;
  c16_hl_x = c16_theta_1;
  c16_il_x = c16_hl_x;
  c16_il_x = muDoubleScalarCos(c16_il_x);
  c16_jl_x = c16_theta_2;
  c16_kl_x = c16_jl_x;
  c16_kl_x = muDoubleScalarCos(c16_kl_x);
  c16_ud_a = c16_il_x;
  c16_ce_b = c16_kl_x;
  c16_ie_y = c16_ud_a * c16_ce_b;
  c16_ll_x = c16_theta_3;
  c16_ml_x = c16_ll_x;
  c16_ml_x = muDoubleScalarCos(c16_ml_x);
  c16_vd_a = c16_ie_y;
  c16_de_b = c16_ml_x;
  c16_je_y = c16_vd_a * c16_de_b;
  c16_wd_a = c16_fe_y;
  c16_ee_b = c16_he_y - c16_je_y;
  c16_ke_y = c16_wd_a * c16_ee_b;
  c16_g_A = c16_ke_y;
  c16_nl_x = c16_g_A;
  c16_ol_x = c16_nl_x;
  c16_le_y = c16_ol_x / 1000.0;
  c16_pl_x = c16_theta_6;
  c16_ql_x = c16_pl_x;
  c16_ql_x = muDoubleScalarCos(c16_ql_x);
  c16_fe_b = c16_ql_x;
  c16_me_y = 121.0 * c16_fe_b;
  c16_rl_x = c16_theta_4;
  c16_sl_x = c16_rl_x;
  c16_sl_x = muDoubleScalarCos(c16_sl_x);
  c16_tl_x = c16_theta_1;
  c16_ul_x = c16_tl_x;
  c16_ul_x = muDoubleScalarCos(c16_ul_x);
  c16_vl_x = c16_theta_2;
  c16_wl_x = c16_vl_x;
  c16_wl_x = muDoubleScalarCos(c16_wl_x);
  c16_xd_a = c16_ul_x;
  c16_ge_b = c16_wl_x;
  c16_ne_y = c16_xd_a * c16_ge_b;
  c16_xl_x = c16_theta_3;
  c16_yl_x = c16_xl_x;
  c16_yl_x = muDoubleScalarSin(c16_yl_x);
  c16_yd_a = c16_ne_y;
  c16_he_b = c16_yl_x;
  c16_oe_y = c16_yd_a * c16_he_b;
  c16_am_x = c16_theta_1;
  c16_bm_x = c16_am_x;
  c16_bm_x = muDoubleScalarCos(c16_bm_x);
  c16_cm_x = c16_theta_3;
  c16_dm_x = c16_cm_x;
  c16_dm_x = muDoubleScalarCos(c16_dm_x);
  c16_ae_a = c16_bm_x;
  c16_ie_b = c16_dm_x;
  c16_pe_y = c16_ae_a * c16_ie_b;
  c16_em_x = c16_theta_2;
  c16_fm_x = c16_em_x;
  c16_fm_x = muDoubleScalarSin(c16_fm_x);
  c16_be_a = c16_pe_y;
  c16_je_b = c16_fm_x;
  c16_qe_y = c16_be_a * c16_je_b;
  c16_ce_a = c16_sl_x;
  c16_ke_b = c16_oe_y + c16_qe_y;
  c16_re_y = c16_ce_a * c16_ke_b;
  c16_gm_x = c16_theta_4;
  c16_hm_x = c16_gm_x;
  c16_hm_x = muDoubleScalarSin(c16_hm_x);
  c16_im_x = c16_theta_1;
  c16_jm_x = c16_im_x;
  c16_jm_x = muDoubleScalarCos(c16_jm_x);
  c16_km_x = c16_theta_2;
  c16_lm_x = c16_km_x;
  c16_lm_x = muDoubleScalarSin(c16_lm_x);
  c16_de_a = c16_jm_x;
  c16_le_b = c16_lm_x;
  c16_se_y = c16_de_a * c16_le_b;
  c16_mm_x = c16_theta_3;
  c16_nm_x = c16_mm_x;
  c16_nm_x = muDoubleScalarSin(c16_nm_x);
  c16_ee_a = c16_se_y;
  c16_me_b = c16_nm_x;
  c16_te_y = c16_ee_a * c16_me_b;
  c16_om_x = c16_theta_1;
  c16_pm_x = c16_om_x;
  c16_pm_x = muDoubleScalarCos(c16_pm_x);
  c16_qm_x = c16_theta_2;
  c16_rm_x = c16_qm_x;
  c16_rm_x = muDoubleScalarCos(c16_rm_x);
  c16_fe_a = c16_pm_x;
  c16_ne_b = c16_rm_x;
  c16_ue_y = c16_fe_a * c16_ne_b;
  c16_sm_x = c16_theta_3;
  c16_tm_x = c16_sm_x;
  c16_tm_x = muDoubleScalarCos(c16_tm_x);
  c16_ge_a = c16_ue_y;
  c16_oe_b = c16_tm_x;
  c16_ve_y = c16_ge_a * c16_oe_b;
  c16_he_a = c16_hm_x;
  c16_pe_b = c16_te_y - c16_ve_y;
  c16_we_y = c16_he_a * c16_pe_b;
  c16_ie_a = c16_me_y;
  c16_qe_b = c16_re_y - c16_we_y;
  c16_xe_y = c16_ie_a * c16_qe_b;
  c16_h_A = c16_xe_y;
  c16_um_x = c16_h_A;
  c16_vm_x = c16_um_x;
  c16_ye_y = c16_vm_x / 20000.0;
  c16_wm_x = c16_theta_5;
  c16_xm_x = c16_wm_x;
  c16_xm_x = muDoubleScalarSin(c16_xm_x);
  c16_re_b = c16_xm_x;
  c16_af_y = 183.0 * c16_re_b;
  c16_ym_x = c16_theta_4;
  c16_an_x = c16_ym_x;
  c16_an_x = muDoubleScalarCos(c16_an_x);
  c16_bn_x = c16_theta_1;
  c16_cn_x = c16_bn_x;
  c16_cn_x = muDoubleScalarCos(c16_cn_x);
  c16_dn_x = c16_theta_2;
  c16_en_x = c16_dn_x;
  c16_en_x = muDoubleScalarSin(c16_en_x);
  c16_je_a = c16_cn_x;
  c16_se_b = c16_en_x;
  c16_bf_y = c16_je_a * c16_se_b;
  c16_fn_x = c16_theta_3;
  c16_gn_x = c16_fn_x;
  c16_gn_x = muDoubleScalarSin(c16_gn_x);
  c16_ke_a = c16_bf_y;
  c16_te_b = c16_gn_x;
  c16_cf_y = c16_ke_a * c16_te_b;
  c16_hn_x = c16_theta_1;
  c16_in_x = c16_hn_x;
  c16_in_x = muDoubleScalarCos(c16_in_x);
  c16_jn_x = c16_theta_2;
  c16_kn_x = c16_jn_x;
  c16_kn_x = muDoubleScalarCos(c16_kn_x);
  c16_le_a = c16_in_x;
  c16_ue_b = c16_kn_x;
  c16_df_y = c16_le_a * c16_ue_b;
  c16_ln_x = c16_theta_3;
  c16_mn_x = c16_ln_x;
  c16_mn_x = muDoubleScalarCos(c16_mn_x);
  c16_me_a = c16_df_y;
  c16_ve_b = c16_mn_x;
  c16_ef_y = c16_me_a * c16_ve_b;
  c16_ne_a = c16_an_x;
  c16_we_b = c16_cf_y - c16_ef_y;
  c16_ff_y = c16_ne_a * c16_we_b;
  c16_nn_x = c16_theta_4;
  c16_on_x = c16_nn_x;
  c16_on_x = muDoubleScalarSin(c16_on_x);
  c16_pn_x = c16_theta_1;
  c16_qn_x = c16_pn_x;
  c16_qn_x = muDoubleScalarCos(c16_qn_x);
  c16_rn_x = c16_theta_2;
  c16_sn_x = c16_rn_x;
  c16_sn_x = muDoubleScalarCos(c16_sn_x);
  c16_oe_a = c16_qn_x;
  c16_xe_b = c16_sn_x;
  c16_gf_y = c16_oe_a * c16_xe_b;
  c16_tn_x = c16_theta_3;
  c16_un_x = c16_tn_x;
  c16_un_x = muDoubleScalarSin(c16_un_x);
  c16_pe_a = c16_gf_y;
  c16_ye_b = c16_un_x;
  c16_hf_y = c16_pe_a * c16_ye_b;
  c16_vn_x = c16_theta_1;
  c16_wn_x = c16_vn_x;
  c16_wn_x = muDoubleScalarCos(c16_wn_x);
  c16_xn_x = c16_theta_3;
  c16_yn_x = c16_xn_x;
  c16_yn_x = muDoubleScalarCos(c16_yn_x);
  c16_qe_a = c16_wn_x;
  c16_af_b = c16_yn_x;
  c16_if_y = c16_qe_a * c16_af_b;
  c16_ao_x = c16_theta_2;
  c16_bo_x = c16_ao_x;
  c16_bo_x = muDoubleScalarSin(c16_bo_x);
  c16_re_a = c16_if_y;
  c16_bf_b = c16_bo_x;
  c16_jf_y = c16_re_a * c16_bf_b;
  c16_se_a = c16_on_x;
  c16_cf_b = c16_hf_y + c16_jf_y;
  c16_kf_y = c16_se_a * c16_cf_b;
  c16_te_a = c16_af_y;
  c16_df_b = c16_ff_y + c16_kf_y;
  c16_lf_y = c16_te_a * c16_df_b;
  c16_i_A = c16_lf_y;
  c16_co_x = c16_i_A;
  c16_do_x = c16_co_x;
  c16_mf_y = c16_do_x / 2000.0;
  c16_eo_x = c16_theta_6;
  c16_fo_x = c16_eo_x;
  c16_fo_x = muDoubleScalarSin(c16_fo_x);
  c16_ef_b = c16_fo_x;
  c16_nf_y = 347.0 * c16_ef_b;
  c16_go_x = c16_theta_4;
  c16_ho_x = c16_go_x;
  c16_ho_x = muDoubleScalarCos(c16_ho_x);
  c16_io_x = c16_theta_1;
  c16_jo_x = c16_io_x;
  c16_jo_x = muDoubleScalarCos(c16_jo_x);
  c16_ko_x = c16_theta_2;
  c16_lo_x = c16_ko_x;
  c16_lo_x = muDoubleScalarCos(c16_lo_x);
  c16_ue_a = c16_jo_x;
  c16_ff_b = c16_lo_x;
  c16_of_y = c16_ue_a * c16_ff_b;
  c16_mo_x = c16_theta_3;
  c16_no_x = c16_mo_x;
  c16_no_x = muDoubleScalarSin(c16_no_x);
  c16_ve_a = c16_of_y;
  c16_gf_b = c16_no_x;
  c16_pf_y = c16_ve_a * c16_gf_b;
  c16_oo_x = c16_theta_1;
  c16_po_x = c16_oo_x;
  c16_po_x = muDoubleScalarCos(c16_po_x);
  c16_qo_x = c16_theta_3;
  c16_ro_x = c16_qo_x;
  c16_ro_x = muDoubleScalarCos(c16_ro_x);
  c16_we_a = c16_po_x;
  c16_hf_b = c16_ro_x;
  c16_qf_y = c16_we_a * c16_hf_b;
  c16_so_x = c16_theta_2;
  c16_to_x = c16_so_x;
  c16_to_x = muDoubleScalarSin(c16_to_x);
  c16_xe_a = c16_qf_y;
  c16_if_b = c16_to_x;
  c16_rf_y = c16_xe_a * c16_if_b;
  c16_ye_a = c16_ho_x;
  c16_jf_b = c16_pf_y + c16_rf_y;
  c16_sf_y = c16_ye_a * c16_jf_b;
  c16_uo_x = c16_theta_4;
  c16_vo_x = c16_uo_x;
  c16_vo_x = muDoubleScalarSin(c16_vo_x);
  c16_wo_x = c16_theta_1;
  c16_xo_x = c16_wo_x;
  c16_xo_x = muDoubleScalarCos(c16_xo_x);
  c16_yo_x = c16_theta_2;
  c16_ap_x = c16_yo_x;
  c16_ap_x = muDoubleScalarSin(c16_ap_x);
  c16_af_a = c16_xo_x;
  c16_kf_b = c16_ap_x;
  c16_tf_y = c16_af_a * c16_kf_b;
  c16_bp_x = c16_theta_3;
  c16_cp_x = c16_bp_x;
  c16_cp_x = muDoubleScalarSin(c16_cp_x);
  c16_bf_a = c16_tf_y;
  c16_lf_b = c16_cp_x;
  c16_uf_y = c16_bf_a * c16_lf_b;
  c16_dp_x = c16_theta_1;
  c16_ep_x = c16_dp_x;
  c16_ep_x = muDoubleScalarCos(c16_ep_x);
  c16_fp_x = c16_theta_2;
  c16_gp_x = c16_fp_x;
  c16_gp_x = muDoubleScalarCos(c16_gp_x);
  c16_cf_a = c16_ep_x;
  c16_mf_b = c16_gp_x;
  c16_vf_y = c16_cf_a * c16_mf_b;
  c16_hp_x = c16_theta_3;
  c16_ip_x = c16_hp_x;
  c16_ip_x = muDoubleScalarCos(c16_ip_x);
  c16_df_a = c16_vf_y;
  c16_nf_b = c16_ip_x;
  c16_wf_y = c16_df_a * c16_nf_b;
  c16_ef_a = c16_vo_x;
  c16_of_b = c16_uf_y - c16_wf_y;
  c16_xf_y = c16_ef_a * c16_of_b;
  c16_ff_a = c16_nf_y;
  c16_pf_b = c16_sf_y - c16_xf_y;
  c16_yf_y = c16_ff_a * c16_pf_b;
  c16_j_A = c16_yf_y;
  c16_jp_x = c16_j_A;
  c16_kp_x = c16_jp_x;
  c16_ag_y = c16_kp_x / 20000.0;
  c16_lp_x = c16_theta_1;
  c16_mp_x = c16_lp_x;
  c16_mp_x = muDoubleScalarCos(c16_mp_x);
  c16_qf_b = c16_mp_x;
  c16_bg_y = 39243.0 * c16_qf_b;
  c16_np_x = c16_theta_2;
  c16_op_x = c16_np_x;
  c16_op_x = muDoubleScalarSin(c16_op_x);
  c16_gf_a = c16_bg_y;
  c16_rf_b = c16_op_x;
  c16_cg_y = c16_gf_a * c16_rf_b;
  c16_pp_x = c16_theta_3;
  c16_qp_x = c16_pp_x;
  c16_qp_x = muDoubleScalarSin(c16_qp_x);
  c16_hf_a = c16_cg_y;
  c16_sf_b = c16_qp_x;
  c16_dg_y = c16_hf_a * c16_sf_b;
  c16_k_A = c16_dg_y;
  c16_rp_x = c16_k_A;
  c16_sp_x = c16_rp_x;
  c16_eg_y = c16_sp_x / 100000.0;
  c16_tp_x = c16_theta_1;
  c16_up_x = c16_tp_x;
  c16_up_x = muDoubleScalarCos(c16_up_x);
  c16_tf_b = c16_up_x;
  c16_fg_y = 39243.0 * c16_tf_b;
  c16_vp_x = c16_theta_2;
  c16_wp_x = c16_vp_x;
  c16_wp_x = muDoubleScalarCos(c16_wp_x);
  c16_if_a = c16_fg_y;
  c16_uf_b = c16_wp_x;
  c16_gg_y = c16_if_a * c16_uf_b;
  c16_xp_x = c16_theta_3;
  c16_yp_x = c16_xp_x;
  c16_yp_x = muDoubleScalarCos(c16_yp_x);
  c16_jf_a = c16_gg_y;
  c16_vf_b = c16_yp_x;
  c16_hg_y = c16_jf_a * c16_vf_b;
  c16_l_A = c16_hg_y;
  c16_aq_x = c16_l_A;
  c16_bq_x = c16_aq_x;
  c16_ig_y = c16_bq_x / 100000.0;
  c16_cq_x = c16_theta_6;
  c16_dq_x = c16_cq_x;
  c16_dq_x = muDoubleScalarCos(c16_dq_x);
  c16_eq_x = c16_theta_1;
  c16_fq_x = c16_eq_x;
  c16_fq_x = muDoubleScalarCos(c16_fq_x);
  c16_gq_x = c16_theta_5;
  c16_hq_x = c16_gq_x;
  c16_hq_x = muDoubleScalarSin(c16_hq_x);
  c16_kf_a = c16_fq_x;
  c16_wf_b = c16_hq_x;
  c16_jg_y = c16_kf_a * c16_wf_b;
  c16_iq_x = c16_theta_5;
  c16_jq_x = c16_iq_x;
  c16_jq_x = muDoubleScalarCos(c16_jq_x);
  c16_kq_x = c16_theta_4;
  c16_lq_x = c16_kq_x;
  c16_lq_x = muDoubleScalarCos(c16_lq_x);
  c16_mq_x = c16_theta_1;
  c16_nq_x = c16_mq_x;
  c16_nq_x = muDoubleScalarSin(c16_nq_x);
  c16_oq_x = c16_theta_2;
  c16_pq_x = c16_oq_x;
  c16_pq_x = muDoubleScalarSin(c16_pq_x);
  c16_lf_a = c16_nq_x;
  c16_xf_b = c16_pq_x;
  c16_kg_y = c16_lf_a * c16_xf_b;
  c16_qq_x = c16_theta_3;
  c16_rq_x = c16_qq_x;
  c16_rq_x = muDoubleScalarSin(c16_rq_x);
  c16_mf_a = c16_kg_y;
  c16_yf_b = c16_rq_x;
  c16_lg_y = c16_mf_a * c16_yf_b;
  c16_sq_x = c16_theta_2;
  c16_tq_x = c16_sq_x;
  c16_tq_x = muDoubleScalarCos(c16_tq_x);
  c16_uq_x = c16_theta_3;
  c16_vq_x = c16_uq_x;
  c16_vq_x = muDoubleScalarCos(c16_vq_x);
  c16_nf_a = c16_tq_x;
  c16_ag_b = c16_vq_x;
  c16_mg_y = c16_nf_a * c16_ag_b;
  c16_wq_x = c16_theta_1;
  c16_xq_x = c16_wq_x;
  c16_xq_x = muDoubleScalarSin(c16_xq_x);
  c16_of_a = c16_mg_y;
  c16_bg_b = c16_xq_x;
  c16_ng_y = c16_of_a * c16_bg_b;
  c16_pf_a = c16_lq_x;
  c16_cg_b = c16_lg_y - c16_ng_y;
  c16_og_y = c16_pf_a * c16_cg_b;
  c16_yq_x = c16_theta_4;
  c16_ar_x = c16_yq_x;
  c16_ar_x = muDoubleScalarSin(c16_ar_x);
  c16_br_x = c16_theta_2;
  c16_cr_x = c16_br_x;
  c16_cr_x = muDoubleScalarCos(c16_cr_x);
  c16_dr_x = c16_theta_1;
  c16_er_x = c16_dr_x;
  c16_er_x = muDoubleScalarSin(c16_er_x);
  c16_qf_a = c16_cr_x;
  c16_dg_b = c16_er_x;
  c16_pg_y = c16_qf_a * c16_dg_b;
  c16_fr_x = c16_theta_3;
  c16_gr_x = c16_fr_x;
  c16_gr_x = muDoubleScalarSin(c16_gr_x);
  c16_rf_a = c16_pg_y;
  c16_eg_b = c16_gr_x;
  c16_qg_y = c16_rf_a * c16_eg_b;
  c16_hr_x = c16_theta_3;
  c16_ir_x = c16_hr_x;
  c16_ir_x = muDoubleScalarCos(c16_ir_x);
  c16_jr_x = c16_theta_1;
  c16_kr_x = c16_jr_x;
  c16_kr_x = muDoubleScalarSin(c16_kr_x);
  c16_sf_a = c16_ir_x;
  c16_fg_b = c16_kr_x;
  c16_rg_y = c16_sf_a * c16_fg_b;
  c16_lr_x = c16_theta_2;
  c16_mr_x = c16_lr_x;
  c16_mr_x = muDoubleScalarSin(c16_mr_x);
  c16_tf_a = c16_rg_y;
  c16_gg_b = c16_mr_x;
  c16_sg_y = c16_tf_a * c16_gg_b;
  c16_uf_a = c16_ar_x;
  c16_hg_b = c16_qg_y + c16_sg_y;
  c16_tg_y = c16_uf_a * c16_hg_b;
  c16_vf_a = c16_jq_x;
  c16_ig_b = c16_og_y + c16_tg_y;
  c16_ug_y = c16_vf_a * c16_ig_b;
  c16_wf_a = -c16_dq_x;
  c16_jg_b = c16_jg_y + c16_ug_y;
  c16_vg_y = c16_wf_a * c16_jg_b;
  c16_nr_x = c16_theta_6;
  c16_or_x = c16_nr_x;
  c16_or_x = muDoubleScalarSin(c16_or_x);
  c16_pr_x = c16_theta_4;
  c16_qr_x = c16_pr_x;
  c16_qr_x = muDoubleScalarCos(c16_qr_x);
  c16_rr_x = c16_theta_2;
  c16_sr_x = c16_rr_x;
  c16_sr_x = muDoubleScalarCos(c16_sr_x);
  c16_tr_x = c16_theta_1;
  c16_ur_x = c16_tr_x;
  c16_ur_x = muDoubleScalarSin(c16_ur_x);
  c16_xf_a = c16_sr_x;
  c16_kg_b = c16_ur_x;
  c16_wg_y = c16_xf_a * c16_kg_b;
  c16_vr_x = c16_theta_3;
  c16_wr_x = c16_vr_x;
  c16_wr_x = muDoubleScalarSin(c16_wr_x);
  c16_yf_a = c16_wg_y;
  c16_lg_b = c16_wr_x;
  c16_xg_y = c16_yf_a * c16_lg_b;
  c16_xr_x = c16_theta_3;
  c16_yr_x = c16_xr_x;
  c16_yr_x = muDoubleScalarCos(c16_yr_x);
  c16_as_x = c16_theta_1;
  c16_bs_x = c16_as_x;
  c16_bs_x = muDoubleScalarSin(c16_bs_x);
  c16_ag_a = c16_yr_x;
  c16_mg_b = c16_bs_x;
  c16_yg_y = c16_ag_a * c16_mg_b;
  c16_cs_x = c16_theta_2;
  c16_ds_x = c16_cs_x;
  c16_ds_x = muDoubleScalarSin(c16_ds_x);
  c16_bg_a = c16_yg_y;
  c16_ng_b = c16_ds_x;
  c16_ah_y = c16_bg_a * c16_ng_b;
  c16_cg_a = c16_qr_x;
  c16_og_b = c16_xg_y + c16_ah_y;
  c16_bh_y = c16_cg_a * c16_og_b;
  c16_es_x = c16_theta_4;
  c16_fs_x = c16_es_x;
  c16_fs_x = muDoubleScalarSin(c16_fs_x);
  c16_gs_x = c16_theta_1;
  c16_hs_x = c16_gs_x;
  c16_hs_x = muDoubleScalarSin(c16_hs_x);
  c16_is_x = c16_theta_2;
  c16_js_x = c16_is_x;
  c16_js_x = muDoubleScalarSin(c16_js_x);
  c16_dg_a = c16_hs_x;
  c16_pg_b = c16_js_x;
  c16_ch_y = c16_dg_a * c16_pg_b;
  c16_ks_x = c16_theta_3;
  c16_ls_x = c16_ks_x;
  c16_ls_x = muDoubleScalarSin(c16_ls_x);
  c16_eg_a = c16_ch_y;
  c16_qg_b = c16_ls_x;
  c16_dh_y = c16_eg_a * c16_qg_b;
  c16_ms_x = c16_theta_2;
  c16_ns_x = c16_ms_x;
  c16_ns_x = muDoubleScalarCos(c16_ns_x);
  c16_os_x = c16_theta_3;
  c16_ps_x = c16_os_x;
  c16_ps_x = muDoubleScalarCos(c16_ps_x);
  c16_fg_a = c16_ns_x;
  c16_rg_b = c16_ps_x;
  c16_eh_y = c16_fg_a * c16_rg_b;
  c16_qs_x = c16_theta_1;
  c16_rs_x = c16_qs_x;
  c16_rs_x = muDoubleScalarSin(c16_rs_x);
  c16_gg_a = c16_eh_y;
  c16_sg_b = c16_rs_x;
  c16_fh_y = c16_gg_a * c16_sg_b;
  c16_hg_a = c16_fs_x;
  c16_tg_b = c16_dh_y - c16_fh_y;
  c16_gh_y = c16_hg_a * c16_tg_b;
  c16_ig_a = c16_or_x;
  c16_ug_b = c16_bh_y - c16_gh_y;
  c16_hh_y = c16_ig_a * c16_ug_b;
  c16_ss_x = c16_theta_6;
  c16_ts_x = c16_ss_x;
  c16_ts_x = muDoubleScalarSin(c16_ts_x);
  c16_us_x = c16_theta_1;
  c16_vs_x = c16_us_x;
  c16_vs_x = muDoubleScalarCos(c16_vs_x);
  c16_ws_x = c16_theta_5;
  c16_xs_x = c16_ws_x;
  c16_xs_x = muDoubleScalarSin(c16_xs_x);
  c16_jg_a = c16_vs_x;
  c16_vg_b = c16_xs_x;
  c16_ih_y = c16_jg_a * c16_vg_b;
  c16_ys_x = c16_theta_5;
  c16_at_x = c16_ys_x;
  c16_at_x = muDoubleScalarCos(c16_at_x);
  c16_bt_x = c16_theta_4;
  c16_ct_x = c16_bt_x;
  c16_ct_x = muDoubleScalarCos(c16_ct_x);
  c16_dt_x = c16_theta_1;
  c16_et_x = c16_dt_x;
  c16_et_x = muDoubleScalarSin(c16_et_x);
  c16_ft_x = c16_theta_2;
  c16_gt_x = c16_ft_x;
  c16_gt_x = muDoubleScalarSin(c16_gt_x);
  c16_kg_a = c16_et_x;
  c16_wg_b = c16_gt_x;
  c16_jh_y = c16_kg_a * c16_wg_b;
  c16_ht_x = c16_theta_3;
  c16_it_x = c16_ht_x;
  c16_it_x = muDoubleScalarSin(c16_it_x);
  c16_lg_a = c16_jh_y;
  c16_xg_b = c16_it_x;
  c16_kh_y = c16_lg_a * c16_xg_b;
  c16_jt_x = c16_theta_2;
  c16_kt_x = c16_jt_x;
  c16_kt_x = muDoubleScalarCos(c16_kt_x);
  c16_lt_x = c16_theta_3;
  c16_mt_x = c16_lt_x;
  c16_mt_x = muDoubleScalarCos(c16_mt_x);
  c16_mg_a = c16_kt_x;
  c16_yg_b = c16_mt_x;
  c16_lh_y = c16_mg_a * c16_yg_b;
  c16_nt_x = c16_theta_1;
  c16_ot_x = c16_nt_x;
  c16_ot_x = muDoubleScalarSin(c16_ot_x);
  c16_ng_a = c16_lh_y;
  c16_ah_b = c16_ot_x;
  c16_mh_y = c16_ng_a * c16_ah_b;
  c16_og_a = c16_ct_x;
  c16_bh_b = c16_kh_y - c16_mh_y;
  c16_nh_y = c16_og_a * c16_bh_b;
  c16_pt_x = c16_theta_4;
  c16_qt_x = c16_pt_x;
  c16_qt_x = muDoubleScalarSin(c16_qt_x);
  c16_rt_x = c16_theta_2;
  c16_st_x = c16_rt_x;
  c16_st_x = muDoubleScalarCos(c16_st_x);
  c16_tt_x = c16_theta_1;
  c16_ut_x = c16_tt_x;
  c16_ut_x = muDoubleScalarSin(c16_ut_x);
  c16_pg_a = c16_st_x;
  c16_ch_b = c16_ut_x;
  c16_oh_y = c16_pg_a * c16_ch_b;
  c16_vt_x = c16_theta_3;
  c16_wt_x = c16_vt_x;
  c16_wt_x = muDoubleScalarSin(c16_wt_x);
  c16_qg_a = c16_oh_y;
  c16_dh_b = c16_wt_x;
  c16_ph_y = c16_qg_a * c16_dh_b;
  c16_xt_x = c16_theta_3;
  c16_yt_x = c16_xt_x;
  c16_yt_x = muDoubleScalarCos(c16_yt_x);
  c16_au_x = c16_theta_1;
  c16_bu_x = c16_au_x;
  c16_bu_x = muDoubleScalarSin(c16_bu_x);
  c16_rg_a = c16_yt_x;
  c16_eh_b = c16_bu_x;
  c16_qh_y = c16_rg_a * c16_eh_b;
  c16_cu_x = c16_theta_2;
  c16_du_x = c16_cu_x;
  c16_du_x = muDoubleScalarSin(c16_du_x);
  c16_sg_a = c16_qh_y;
  c16_fh_b = c16_du_x;
  c16_rh_y = c16_sg_a * c16_fh_b;
  c16_tg_a = c16_qt_x;
  c16_gh_b = c16_ph_y + c16_rh_y;
  c16_sh_y = c16_tg_a * c16_gh_b;
  c16_ug_a = c16_at_x;
  c16_hh_b = c16_nh_y + c16_sh_y;
  c16_th_y = c16_ug_a * c16_hh_b;
  c16_vg_a = c16_ts_x;
  c16_ih_b = c16_ih_y + c16_th_y;
  c16_uh_y = c16_vg_a * c16_ih_b;
  c16_eu_x = c16_theta_6;
  c16_fu_x = c16_eu_x;
  c16_fu_x = muDoubleScalarCos(c16_fu_x);
  c16_gu_x = c16_theta_4;
  c16_hu_x = c16_gu_x;
  c16_hu_x = muDoubleScalarCos(c16_hu_x);
  c16_iu_x = c16_theta_2;
  c16_ju_x = c16_iu_x;
  c16_ju_x = muDoubleScalarCos(c16_ju_x);
  c16_ku_x = c16_theta_1;
  c16_lu_x = c16_ku_x;
  c16_lu_x = muDoubleScalarSin(c16_lu_x);
  c16_wg_a = c16_ju_x;
  c16_jh_b = c16_lu_x;
  c16_vh_y = c16_wg_a * c16_jh_b;
  c16_mu_x = c16_theta_3;
  c16_nu_x = c16_mu_x;
  c16_nu_x = muDoubleScalarSin(c16_nu_x);
  c16_xg_a = c16_vh_y;
  c16_kh_b = c16_nu_x;
  c16_wh_y = c16_xg_a * c16_kh_b;
  c16_ou_x = c16_theta_3;
  c16_pu_x = c16_ou_x;
  c16_pu_x = muDoubleScalarCos(c16_pu_x);
  c16_qu_x = c16_theta_1;
  c16_ru_x = c16_qu_x;
  c16_ru_x = muDoubleScalarSin(c16_ru_x);
  c16_yg_a = c16_pu_x;
  c16_lh_b = c16_ru_x;
  c16_xh_y = c16_yg_a * c16_lh_b;
  c16_su_x = c16_theta_2;
  c16_tu_x = c16_su_x;
  c16_tu_x = muDoubleScalarSin(c16_tu_x);
  c16_ah_a = c16_xh_y;
  c16_mh_b = c16_tu_x;
  c16_yh_y = c16_ah_a * c16_mh_b;
  c16_bh_a = c16_hu_x;
  c16_nh_b = c16_wh_y + c16_yh_y;
  c16_ai_y = c16_bh_a * c16_nh_b;
  c16_uu_x = c16_theta_4;
  c16_vu_x = c16_uu_x;
  c16_vu_x = muDoubleScalarSin(c16_vu_x);
  c16_wu_x = c16_theta_1;
  c16_xu_x = c16_wu_x;
  c16_xu_x = muDoubleScalarSin(c16_xu_x);
  c16_yu_x = c16_theta_2;
  c16_av_x = c16_yu_x;
  c16_av_x = muDoubleScalarSin(c16_av_x);
  c16_ch_a = c16_xu_x;
  c16_oh_b = c16_av_x;
  c16_bi_y = c16_ch_a * c16_oh_b;
  c16_bv_x = c16_theta_3;
  c16_cv_x = c16_bv_x;
  c16_cv_x = muDoubleScalarSin(c16_cv_x);
  c16_dh_a = c16_bi_y;
  c16_ph_b = c16_cv_x;
  c16_ci_y = c16_dh_a * c16_ph_b;
  c16_dv_x = c16_theta_2;
  c16_ev_x = c16_dv_x;
  c16_ev_x = muDoubleScalarCos(c16_ev_x);
  c16_fv_x = c16_theta_3;
  c16_gv_x = c16_fv_x;
  c16_gv_x = muDoubleScalarCos(c16_gv_x);
  c16_eh_a = c16_ev_x;
  c16_qh_b = c16_gv_x;
  c16_di_y = c16_eh_a * c16_qh_b;
  c16_hv_x = c16_theta_1;
  c16_iv_x = c16_hv_x;
  c16_iv_x = muDoubleScalarSin(c16_iv_x);
  c16_fh_a = c16_di_y;
  c16_rh_b = c16_iv_x;
  c16_ei_y = c16_fh_a * c16_rh_b;
  c16_gh_a = c16_vu_x;
  c16_sh_b = c16_ci_y - c16_ei_y;
  c16_fi_y = c16_gh_a * c16_sh_b;
  c16_hh_a = c16_fu_x;
  c16_th_b = c16_ai_y - c16_fi_y;
  c16_gi_y = c16_hh_a * c16_th_b;
  c16_jv_x = c16_theta_5;
  c16_kv_x = c16_jv_x;
  c16_kv_x = muDoubleScalarSin(c16_kv_x);
  c16_lv_x = c16_theta_4;
  c16_mv_x = c16_lv_x;
  c16_mv_x = muDoubleScalarCos(c16_mv_x);
  c16_nv_x = c16_theta_1;
  c16_ov_x = c16_nv_x;
  c16_ov_x = muDoubleScalarSin(c16_ov_x);
  c16_pv_x = c16_theta_2;
  c16_qv_x = c16_pv_x;
  c16_qv_x = muDoubleScalarSin(c16_qv_x);
  c16_ih_a = c16_ov_x;
  c16_uh_b = c16_qv_x;
  c16_hi_y = c16_ih_a * c16_uh_b;
  c16_rv_x = c16_theta_3;
  c16_sv_x = c16_rv_x;
  c16_sv_x = muDoubleScalarSin(c16_sv_x);
  c16_jh_a = c16_hi_y;
  c16_vh_b = c16_sv_x;
  c16_ii_y = c16_jh_a * c16_vh_b;
  c16_tv_x = c16_theta_2;
  c16_uv_x = c16_tv_x;
  c16_uv_x = muDoubleScalarCos(c16_uv_x);
  c16_vv_x = c16_theta_3;
  c16_wv_x = c16_vv_x;
  c16_wv_x = muDoubleScalarCos(c16_wv_x);
  c16_kh_a = c16_uv_x;
  c16_wh_b = c16_wv_x;
  c16_ji_y = c16_kh_a * c16_wh_b;
  c16_xv_x = c16_theta_1;
  c16_yv_x = c16_xv_x;
  c16_yv_x = muDoubleScalarSin(c16_yv_x);
  c16_lh_a = c16_ji_y;
  c16_xh_b = c16_yv_x;
  c16_ki_y = c16_lh_a * c16_xh_b;
  c16_mh_a = c16_mv_x;
  c16_yh_b = c16_ii_y - c16_ki_y;
  c16_li_y = c16_mh_a * c16_yh_b;
  c16_aw_x = c16_theta_4;
  c16_bw_x = c16_aw_x;
  c16_bw_x = muDoubleScalarSin(c16_bw_x);
  c16_cw_x = c16_theta_2;
  c16_dw_x = c16_cw_x;
  c16_dw_x = muDoubleScalarCos(c16_dw_x);
  c16_ew_x = c16_theta_1;
  c16_fw_x = c16_ew_x;
  c16_fw_x = muDoubleScalarSin(c16_fw_x);
  c16_nh_a = c16_dw_x;
  c16_ai_b = c16_fw_x;
  c16_mi_y = c16_nh_a * c16_ai_b;
  c16_gw_x = c16_theta_3;
  c16_hw_x = c16_gw_x;
  c16_hw_x = muDoubleScalarSin(c16_hw_x);
  c16_oh_a = c16_mi_y;
  c16_bi_b = c16_hw_x;
  c16_ni_y = c16_oh_a * c16_bi_b;
  c16_iw_x = c16_theta_3;
  c16_jw_x = c16_iw_x;
  c16_jw_x = muDoubleScalarCos(c16_jw_x);
  c16_kw_x = c16_theta_1;
  c16_lw_x = c16_kw_x;
  c16_lw_x = muDoubleScalarSin(c16_lw_x);
  c16_ph_a = c16_jw_x;
  c16_ci_b = c16_lw_x;
  c16_oi_y = c16_ph_a * c16_ci_b;
  c16_mw_x = c16_theta_2;
  c16_nw_x = c16_mw_x;
  c16_nw_x = muDoubleScalarSin(c16_nw_x);
  c16_qh_a = c16_oi_y;
  c16_di_b = c16_nw_x;
  c16_pi_y = c16_qh_a * c16_di_b;
  c16_rh_a = c16_bw_x;
  c16_ei_b = c16_ni_y + c16_pi_y;
  c16_qi_y = c16_rh_a * c16_ei_b;
  c16_sh_a = c16_kv_x;
  c16_fi_b = c16_li_y + c16_qi_y;
  c16_ri_y = c16_sh_a * c16_fi_b;
  c16_ow_x = c16_theta_1;
  c16_pw_x = c16_ow_x;
  c16_pw_x = muDoubleScalarCos(c16_pw_x);
  c16_qw_x = c16_theta_5;
  c16_rw_x = c16_qw_x;
  c16_rw_x = muDoubleScalarCos(c16_rw_x);
  c16_th_a = c16_pw_x;
  c16_gi_b = c16_rw_x;
  c16_si_y = c16_th_a * c16_gi_b;
  c16_sw_x = c16_theta_4;
  c16_tw_x = c16_sw_x;
  c16_tw_x = muDoubleScalarCos(c16_tw_x);
  c16_hi_b = c16_tw_x;
  c16_ti_y = 93.0 * c16_hi_b;
  c16_uw_x = c16_theta_2;
  c16_vw_x = c16_uw_x;
  c16_vw_x = muDoubleScalarCos(c16_vw_x);
  c16_ww_x = c16_theta_1;
  c16_xw_x = c16_ww_x;
  c16_xw_x = muDoubleScalarSin(c16_xw_x);
  c16_uh_a = c16_vw_x;
  c16_ii_b = c16_xw_x;
  c16_ui_y = c16_uh_a * c16_ii_b;
  c16_yw_x = c16_theta_3;
  c16_ax_x = c16_yw_x;
  c16_ax_x = muDoubleScalarSin(c16_ax_x);
  c16_vh_a = c16_ui_y;
  c16_ji_b = c16_ax_x;
  c16_vi_y = c16_vh_a * c16_ji_b;
  c16_bx_x = c16_theta_3;
  c16_cx_x = c16_bx_x;
  c16_cx_x = muDoubleScalarCos(c16_cx_x);
  c16_dx_x = c16_theta_1;
  c16_ex_x = c16_dx_x;
  c16_ex_x = muDoubleScalarSin(c16_ex_x);
  c16_wh_a = c16_cx_x;
  c16_ki_b = c16_ex_x;
  c16_wi_y = c16_wh_a * c16_ki_b;
  c16_fx_x = c16_theta_2;
  c16_gx_x = c16_fx_x;
  c16_gx_x = muDoubleScalarSin(c16_gx_x);
  c16_xh_a = c16_wi_y;
  c16_li_b = c16_gx_x;
  c16_xi_y = c16_xh_a * c16_li_b;
  c16_yh_a = c16_ti_y;
  c16_mi_b = c16_vi_y + c16_xi_y;
  c16_yi_y = c16_yh_a * c16_mi_b;
  c16_m_A = c16_yi_y;
  c16_hx_x = c16_m_A;
  c16_ix_x = c16_hx_x;
  c16_aj_y = c16_ix_x / 1000.0;
  c16_jx_x = c16_theta_1;
  c16_kx_x = c16_jx_x;
  c16_kx_x = muDoubleScalarCos(c16_kx_x);
  c16_ni_b = c16_kx_x;
  c16_bj_y = 183.0 * c16_ni_b;
  c16_lx_x = c16_theta_5;
  c16_mx_x = c16_lx_x;
  c16_mx_x = muDoubleScalarCos(c16_mx_x);
  c16_ai_a = c16_bj_y;
  c16_oi_b = c16_mx_x;
  c16_cj_y = c16_ai_a * c16_oi_b;
  c16_n_A = c16_cj_y;
  c16_nx_x = c16_n_A;
  c16_ox_x = c16_nx_x;
  c16_dj_y = c16_ox_x / 2000.0;
  c16_px_x = c16_theta_2;
  c16_qx_x = c16_px_x;
  c16_qx_x = muDoubleScalarCos(c16_qx_x);
  c16_pi_b = c16_qx_x;
  c16_ej_y = 17.0 * c16_pi_b;
  c16_rx_x = c16_theta_1;
  c16_sx_x = c16_rx_x;
  c16_sx_x = muDoubleScalarSin(c16_sx_x);
  c16_bi_a = c16_ej_y;
  c16_qi_b = c16_sx_x;
  c16_fj_y = c16_bi_a * c16_qi_b;
  c16_o_A = c16_fj_y;
  c16_tx_x = c16_o_A;
  c16_ux_x = c16_tx_x;
  c16_gj_y = c16_ux_x / 40.0;
  c16_vx_x = c16_theta_1;
  c16_wx_x = c16_vx_x;
  c16_wx_x = muDoubleScalarCos(c16_wx_x);
  c16_ri_b = c16_wx_x;
  c16_hj_y = 109.0 * c16_ri_b;
  c16_p_A = c16_hj_y;
  c16_xx_x = c16_p_A;
  c16_yx_x = c16_xx_x;
  c16_ij_y = c16_yx_x / 1000.0;
  c16_ay_x = c16_theta_6;
  c16_by_x = c16_ay_x;
  c16_by_x = muDoubleScalarCos(c16_by_x);
  c16_si_b = c16_by_x;
  c16_jj_y = 347.0 * c16_si_b;
  c16_cy_x = c16_theta_1;
  c16_dy_x = c16_cy_x;
  c16_dy_x = muDoubleScalarCos(c16_dy_x);
  c16_ey_x = c16_theta_5;
  c16_fy_x = c16_ey_x;
  c16_fy_x = muDoubleScalarSin(c16_fy_x);
  c16_ci_a = c16_dy_x;
  c16_ti_b = c16_fy_x;
  c16_kj_y = c16_ci_a * c16_ti_b;
  c16_gy_x = c16_theta_5;
  c16_hy_x = c16_gy_x;
  c16_hy_x = muDoubleScalarCos(c16_hy_x);
  c16_iy_x = c16_theta_4;
  c16_jy_x = c16_iy_x;
  c16_jy_x = muDoubleScalarCos(c16_jy_x);
  c16_ky_x = c16_theta_1;
  c16_ly_x = c16_ky_x;
  c16_ly_x = muDoubleScalarSin(c16_ly_x);
  c16_my_x = c16_theta_2;
  c16_ny_x = c16_my_x;
  c16_ny_x = muDoubleScalarSin(c16_ny_x);
  c16_di_a = c16_ly_x;
  c16_ui_b = c16_ny_x;
  c16_lj_y = c16_di_a * c16_ui_b;
  c16_oy_x = c16_theta_3;
  c16_py_x = c16_oy_x;
  c16_py_x = muDoubleScalarSin(c16_py_x);
  c16_ei_a = c16_lj_y;
  c16_vi_b = c16_py_x;
  c16_mj_y = c16_ei_a * c16_vi_b;
  c16_qy_x = c16_theta_2;
  c16_ry_x = c16_qy_x;
  c16_ry_x = muDoubleScalarCos(c16_ry_x);
  c16_sy_x = c16_theta_3;
  c16_ty_x = c16_sy_x;
  c16_ty_x = muDoubleScalarCos(c16_ty_x);
  c16_fi_a = c16_ry_x;
  c16_wi_b = c16_ty_x;
  c16_nj_y = c16_fi_a * c16_wi_b;
  c16_uy_x = c16_theta_1;
  c16_vy_x = c16_uy_x;
  c16_vy_x = muDoubleScalarSin(c16_vy_x);
  c16_gi_a = c16_nj_y;
  c16_xi_b = c16_vy_x;
  c16_oj_y = c16_gi_a * c16_xi_b;
  c16_hi_a = c16_jy_x;
  c16_yi_b = c16_mj_y - c16_oj_y;
  c16_pj_y = c16_hi_a * c16_yi_b;
  c16_wy_x = c16_theta_4;
  c16_xy_x = c16_wy_x;
  c16_xy_x = muDoubleScalarSin(c16_xy_x);
  c16_yy_x = c16_theta_2;
  c16_aab_x = c16_yy_x;
  c16_aab_x = muDoubleScalarCos(c16_aab_x);
  c16_bab_x = c16_theta_1;
  c16_cab_x = c16_bab_x;
  c16_cab_x = muDoubleScalarSin(c16_cab_x);
  c16_ii_a = c16_aab_x;
  c16_aj_b = c16_cab_x;
  c16_qj_y = c16_ii_a * c16_aj_b;
  c16_dab_x = c16_theta_3;
  c16_eab_x = c16_dab_x;
  c16_eab_x = muDoubleScalarSin(c16_eab_x);
  c16_ji_a = c16_qj_y;
  c16_bj_b = c16_eab_x;
  c16_rj_y = c16_ji_a * c16_bj_b;
  c16_fab_x = c16_theta_3;
  c16_gab_x = c16_fab_x;
  c16_gab_x = muDoubleScalarCos(c16_gab_x);
  c16_hab_x = c16_theta_1;
  c16_iab_x = c16_hab_x;
  c16_iab_x = muDoubleScalarSin(c16_iab_x);
  c16_ki_a = c16_gab_x;
  c16_cj_b = c16_iab_x;
  c16_sj_y = c16_ki_a * c16_cj_b;
  c16_jab_x = c16_theta_2;
  c16_kab_x = c16_jab_x;
  c16_kab_x = muDoubleScalarSin(c16_kab_x);
  c16_li_a = c16_sj_y;
  c16_dj_b = c16_kab_x;
  c16_tj_y = c16_li_a * c16_dj_b;
  c16_mi_a = c16_xy_x;
  c16_ej_b = c16_rj_y + c16_tj_y;
  c16_uj_y = c16_mi_a * c16_ej_b;
  c16_ni_a = c16_hy_x;
  c16_fj_b = c16_pj_y + c16_uj_y;
  c16_vj_y = c16_ni_a * c16_fj_b;
  c16_oi_a = c16_jj_y;
  c16_gj_b = c16_kj_y + c16_vj_y;
  c16_wj_y = c16_oi_a * c16_gj_b;
  c16_q_A = c16_wj_y;
  c16_lab_x = c16_q_A;
  c16_mab_x = c16_lab_x;
  c16_xj_y = c16_mab_x / 20000.0;
  c16_nab_x = c16_theta_4;
  c16_oab_x = c16_nab_x;
  c16_oab_x = muDoubleScalarSin(c16_oab_x);
  c16_hj_b = c16_oab_x;
  c16_yj_y = 93.0 * c16_hj_b;
  c16_pab_x = c16_theta_1;
  c16_qab_x = c16_pab_x;
  c16_qab_x = muDoubleScalarSin(c16_qab_x);
  c16_rab_x = c16_theta_2;
  c16_sab_x = c16_rab_x;
  c16_sab_x = muDoubleScalarSin(c16_sab_x);
  c16_pi_a = c16_qab_x;
  c16_ij_b = c16_sab_x;
  c16_ak_y = c16_pi_a * c16_ij_b;
  c16_tab_x = c16_theta_3;
  c16_uab_x = c16_tab_x;
  c16_uab_x = muDoubleScalarSin(c16_uab_x);
  c16_qi_a = c16_ak_y;
  c16_jj_b = c16_uab_x;
  c16_bk_y = c16_qi_a * c16_jj_b;
  c16_vab_x = c16_theta_2;
  c16_wab_x = c16_vab_x;
  c16_wab_x = muDoubleScalarCos(c16_wab_x);
  c16_xab_x = c16_theta_3;
  c16_yab_x = c16_xab_x;
  c16_yab_x = muDoubleScalarCos(c16_yab_x);
  c16_ri_a = c16_wab_x;
  c16_kj_b = c16_yab_x;
  c16_ck_y = c16_ri_a * c16_kj_b;
  c16_abb_x = c16_theta_1;
  c16_bbb_x = c16_abb_x;
  c16_bbb_x = muDoubleScalarSin(c16_bbb_x);
  c16_si_a = c16_ck_y;
  c16_lj_b = c16_bbb_x;
  c16_dk_y = c16_si_a * c16_lj_b;
  c16_ti_a = c16_yj_y;
  c16_mj_b = c16_bk_y - c16_dk_y;
  c16_ek_y = c16_ti_a * c16_mj_b;
  c16_r_A = c16_ek_y;
  c16_cbb_x = c16_r_A;
  c16_dbb_x = c16_cbb_x;
  c16_fk_y = c16_dbb_x / 1000.0;
  c16_ebb_x = c16_theta_6;
  c16_fbb_x = c16_ebb_x;
  c16_fbb_x = muDoubleScalarSin(c16_fbb_x);
  c16_nj_b = c16_fbb_x;
  c16_gk_y = 121.0 * c16_nj_b;
  c16_gbb_x = c16_theta_1;
  c16_hbb_x = c16_gbb_x;
  c16_hbb_x = muDoubleScalarCos(c16_hbb_x);
  c16_ibb_x = c16_theta_5;
  c16_jbb_x = c16_ibb_x;
  c16_jbb_x = muDoubleScalarSin(c16_jbb_x);
  c16_ui_a = c16_hbb_x;
  c16_oj_b = c16_jbb_x;
  c16_hk_y = c16_ui_a * c16_oj_b;
  c16_kbb_x = c16_theta_5;
  c16_lbb_x = c16_kbb_x;
  c16_lbb_x = muDoubleScalarCos(c16_lbb_x);
  c16_mbb_x = c16_theta_4;
  c16_nbb_x = c16_mbb_x;
  c16_nbb_x = muDoubleScalarCos(c16_nbb_x);
  c16_obb_x = c16_theta_1;
  c16_pbb_x = c16_obb_x;
  c16_pbb_x = muDoubleScalarSin(c16_pbb_x);
  c16_qbb_x = c16_theta_2;
  c16_rbb_x = c16_qbb_x;
  c16_rbb_x = muDoubleScalarSin(c16_rbb_x);
  c16_vi_a = c16_pbb_x;
  c16_pj_b = c16_rbb_x;
  c16_ik_y = c16_vi_a * c16_pj_b;
  c16_sbb_x = c16_theta_3;
  c16_tbb_x = c16_sbb_x;
  c16_tbb_x = muDoubleScalarSin(c16_tbb_x);
  c16_wi_a = c16_ik_y;
  c16_qj_b = c16_tbb_x;
  c16_jk_y = c16_wi_a * c16_qj_b;
  c16_ubb_x = c16_theta_2;
  c16_vbb_x = c16_ubb_x;
  c16_vbb_x = muDoubleScalarCos(c16_vbb_x);
  c16_wbb_x = c16_theta_3;
  c16_xbb_x = c16_wbb_x;
  c16_xbb_x = muDoubleScalarCos(c16_xbb_x);
  c16_xi_a = c16_vbb_x;
  c16_rj_b = c16_xbb_x;
  c16_kk_y = c16_xi_a * c16_rj_b;
  c16_ybb_x = c16_theta_1;
  c16_acb_x = c16_ybb_x;
  c16_acb_x = muDoubleScalarSin(c16_acb_x);
  c16_yi_a = c16_kk_y;
  c16_sj_b = c16_acb_x;
  c16_lk_y = c16_yi_a * c16_sj_b;
  c16_aj_a = c16_nbb_x;
  c16_tj_b = c16_jk_y - c16_lk_y;
  c16_mk_y = c16_aj_a * c16_tj_b;
  c16_bcb_x = c16_theta_4;
  c16_ccb_x = c16_bcb_x;
  c16_ccb_x = muDoubleScalarSin(c16_ccb_x);
  c16_dcb_x = c16_theta_2;
  c16_ecb_x = c16_dcb_x;
  c16_ecb_x = muDoubleScalarCos(c16_ecb_x);
  c16_fcb_x = c16_theta_1;
  c16_gcb_x = c16_fcb_x;
  c16_gcb_x = muDoubleScalarSin(c16_gcb_x);
  c16_bj_a = c16_ecb_x;
  c16_uj_b = c16_gcb_x;
  c16_nk_y = c16_bj_a * c16_uj_b;
  c16_hcb_x = c16_theta_3;
  c16_icb_x = c16_hcb_x;
  c16_icb_x = muDoubleScalarSin(c16_icb_x);
  c16_cj_a = c16_nk_y;
  c16_vj_b = c16_icb_x;
  c16_ok_y = c16_cj_a * c16_vj_b;
  c16_jcb_x = c16_theta_3;
  c16_kcb_x = c16_jcb_x;
  c16_kcb_x = muDoubleScalarCos(c16_kcb_x);
  c16_lcb_x = c16_theta_1;
  c16_mcb_x = c16_lcb_x;
  c16_mcb_x = muDoubleScalarSin(c16_mcb_x);
  c16_dj_a = c16_kcb_x;
  c16_wj_b = c16_mcb_x;
  c16_pk_y = c16_dj_a * c16_wj_b;
  c16_ncb_x = c16_theta_2;
  c16_ocb_x = c16_ncb_x;
  c16_ocb_x = muDoubleScalarSin(c16_ocb_x);
  c16_ej_a = c16_pk_y;
  c16_xj_b = c16_ocb_x;
  c16_qk_y = c16_ej_a * c16_xj_b;
  c16_fj_a = c16_ccb_x;
  c16_yj_b = c16_ok_y + c16_qk_y;
  c16_rk_y = c16_fj_a * c16_yj_b;
  c16_gj_a = c16_lbb_x;
  c16_ak_b = c16_mk_y + c16_rk_y;
  c16_sk_y = c16_gj_a * c16_ak_b;
  c16_hj_a = c16_gk_y;
  c16_bk_b = c16_hk_y + c16_sk_y;
  c16_tk_y = c16_hj_a * c16_bk_b;
  c16_s_A = c16_tk_y;
  c16_pcb_x = c16_s_A;
  c16_qcb_x = c16_pcb_x;
  c16_uk_y = c16_qcb_x / 20000.0;
  c16_rcb_x = c16_theta_6;
  c16_scb_x = c16_rcb_x;
  c16_scb_x = muDoubleScalarCos(c16_scb_x);
  c16_ck_b = c16_scb_x;
  c16_vk_y = 121.0 * c16_ck_b;
  c16_tcb_x = c16_theta_4;
  c16_ucb_x = c16_tcb_x;
  c16_ucb_x = muDoubleScalarCos(c16_ucb_x);
  c16_vcb_x = c16_theta_2;
  c16_wcb_x = c16_vcb_x;
  c16_wcb_x = muDoubleScalarCos(c16_wcb_x);
  c16_xcb_x = c16_theta_1;
  c16_ycb_x = c16_xcb_x;
  c16_ycb_x = muDoubleScalarSin(c16_ycb_x);
  c16_ij_a = c16_wcb_x;
  c16_dk_b = c16_ycb_x;
  c16_wk_y = c16_ij_a * c16_dk_b;
  c16_adb_x = c16_theta_3;
  c16_bdb_x = c16_adb_x;
  c16_bdb_x = muDoubleScalarSin(c16_bdb_x);
  c16_jj_a = c16_wk_y;
  c16_ek_b = c16_bdb_x;
  c16_xk_y = c16_jj_a * c16_ek_b;
  c16_cdb_x = c16_theta_3;
  c16_ddb_x = c16_cdb_x;
  c16_ddb_x = muDoubleScalarCos(c16_ddb_x);
  c16_edb_x = c16_theta_1;
  c16_fdb_x = c16_edb_x;
  c16_fdb_x = muDoubleScalarSin(c16_fdb_x);
  c16_kj_a = c16_ddb_x;
  c16_fk_b = c16_fdb_x;
  c16_yk_y = c16_kj_a * c16_fk_b;
  c16_gdb_x = c16_theta_2;
  c16_hdb_x = c16_gdb_x;
  c16_hdb_x = muDoubleScalarSin(c16_hdb_x);
  c16_lj_a = c16_yk_y;
  c16_gk_b = c16_hdb_x;
  c16_al_y = c16_lj_a * c16_gk_b;
  c16_mj_a = c16_ucb_x;
  c16_hk_b = c16_xk_y + c16_al_y;
  c16_bl_y = c16_mj_a * c16_hk_b;
  c16_idb_x = c16_theta_4;
  c16_jdb_x = c16_idb_x;
  c16_jdb_x = muDoubleScalarSin(c16_jdb_x);
  c16_kdb_x = c16_theta_1;
  c16_ldb_x = c16_kdb_x;
  c16_ldb_x = muDoubleScalarSin(c16_ldb_x);
  c16_mdb_x = c16_theta_2;
  c16_ndb_x = c16_mdb_x;
  c16_ndb_x = muDoubleScalarSin(c16_ndb_x);
  c16_nj_a = c16_ldb_x;
  c16_ik_b = c16_ndb_x;
  c16_cl_y = c16_nj_a * c16_ik_b;
  c16_odb_x = c16_theta_3;
  c16_pdb_x = c16_odb_x;
  c16_pdb_x = muDoubleScalarSin(c16_pdb_x);
  c16_oj_a = c16_cl_y;
  c16_jk_b = c16_pdb_x;
  c16_dl_y = c16_oj_a * c16_jk_b;
  c16_qdb_x = c16_theta_2;
  c16_rdb_x = c16_qdb_x;
  c16_rdb_x = muDoubleScalarCos(c16_rdb_x);
  c16_sdb_x = c16_theta_3;
  c16_tdb_x = c16_sdb_x;
  c16_tdb_x = muDoubleScalarCos(c16_tdb_x);
  c16_pj_a = c16_rdb_x;
  c16_kk_b = c16_tdb_x;
  c16_el_y = c16_pj_a * c16_kk_b;
  c16_udb_x = c16_theta_1;
  c16_vdb_x = c16_udb_x;
  c16_vdb_x = muDoubleScalarSin(c16_vdb_x);
  c16_qj_a = c16_el_y;
  c16_lk_b = c16_vdb_x;
  c16_fl_y = c16_qj_a * c16_lk_b;
  c16_rj_a = c16_jdb_x;
  c16_mk_b = c16_dl_y - c16_fl_y;
  c16_gl_y = c16_rj_a * c16_mk_b;
  c16_sj_a = c16_vk_y;
  c16_nk_b = c16_bl_y - c16_gl_y;
  c16_hl_y = c16_sj_a * c16_nk_b;
  c16_t_A = c16_hl_y;
  c16_wdb_x = c16_t_A;
  c16_xdb_x = c16_wdb_x;
  c16_il_y = c16_xdb_x / 20000.0;
  c16_ydb_x = c16_theta_5;
  c16_aeb_x = c16_ydb_x;
  c16_aeb_x = muDoubleScalarSin(c16_aeb_x);
  c16_ok_b = c16_aeb_x;
  c16_jl_y = 183.0 * c16_ok_b;
  c16_beb_x = c16_theta_4;
  c16_ceb_x = c16_beb_x;
  c16_ceb_x = muDoubleScalarCos(c16_ceb_x);
  c16_deb_x = c16_theta_1;
  c16_eeb_x = c16_deb_x;
  c16_eeb_x = muDoubleScalarSin(c16_eeb_x);
  c16_feb_x = c16_theta_2;
  c16_geb_x = c16_feb_x;
  c16_geb_x = muDoubleScalarSin(c16_geb_x);
  c16_tj_a = c16_eeb_x;
  c16_pk_b = c16_geb_x;
  c16_kl_y = c16_tj_a * c16_pk_b;
  c16_heb_x = c16_theta_3;
  c16_ieb_x = c16_heb_x;
  c16_ieb_x = muDoubleScalarSin(c16_ieb_x);
  c16_uj_a = c16_kl_y;
  c16_qk_b = c16_ieb_x;
  c16_ll_y = c16_uj_a * c16_qk_b;
  c16_jeb_x = c16_theta_2;
  c16_keb_x = c16_jeb_x;
  c16_keb_x = muDoubleScalarCos(c16_keb_x);
  c16_leb_x = c16_theta_3;
  c16_meb_x = c16_leb_x;
  c16_meb_x = muDoubleScalarCos(c16_meb_x);
  c16_vj_a = c16_keb_x;
  c16_rk_b = c16_meb_x;
  c16_ml_y = c16_vj_a * c16_rk_b;
  c16_neb_x = c16_theta_1;
  c16_oeb_x = c16_neb_x;
  c16_oeb_x = muDoubleScalarSin(c16_oeb_x);
  c16_wj_a = c16_ml_y;
  c16_sk_b = c16_oeb_x;
  c16_nl_y = c16_wj_a * c16_sk_b;
  c16_xj_a = c16_ceb_x;
  c16_tk_b = c16_ll_y - c16_nl_y;
  c16_ol_y = c16_xj_a * c16_tk_b;
  c16_peb_x = c16_theta_4;
  c16_qeb_x = c16_peb_x;
  c16_qeb_x = muDoubleScalarSin(c16_qeb_x);
  c16_reb_x = c16_theta_2;
  c16_seb_x = c16_reb_x;
  c16_seb_x = muDoubleScalarCos(c16_seb_x);
  c16_teb_x = c16_theta_1;
  c16_ueb_x = c16_teb_x;
  c16_ueb_x = muDoubleScalarSin(c16_ueb_x);
  c16_yj_a = c16_seb_x;
  c16_uk_b = c16_ueb_x;
  c16_pl_y = c16_yj_a * c16_uk_b;
  c16_veb_x = c16_theta_3;
  c16_web_x = c16_veb_x;
  c16_web_x = muDoubleScalarSin(c16_web_x);
  c16_ak_a = c16_pl_y;
  c16_vk_b = c16_web_x;
  c16_ql_y = c16_ak_a * c16_vk_b;
  c16_xeb_x = c16_theta_3;
  c16_yeb_x = c16_xeb_x;
  c16_yeb_x = muDoubleScalarCos(c16_yeb_x);
  c16_afb_x = c16_theta_1;
  c16_bfb_x = c16_afb_x;
  c16_bfb_x = muDoubleScalarSin(c16_bfb_x);
  c16_bk_a = c16_yeb_x;
  c16_wk_b = c16_bfb_x;
  c16_rl_y = c16_bk_a * c16_wk_b;
  c16_cfb_x = c16_theta_2;
  c16_dfb_x = c16_cfb_x;
  c16_dfb_x = muDoubleScalarSin(c16_dfb_x);
  c16_ck_a = c16_rl_y;
  c16_xk_b = c16_dfb_x;
  c16_sl_y = c16_ck_a * c16_xk_b;
  c16_dk_a = c16_qeb_x;
  c16_yk_b = c16_ql_y + c16_sl_y;
  c16_tl_y = c16_dk_a * c16_yk_b;
  c16_ek_a = c16_jl_y;
  c16_al_b = c16_ol_y + c16_tl_y;
  c16_ul_y = c16_ek_a * c16_al_b;
  c16_u_A = c16_ul_y;
  c16_efb_x = c16_u_A;
  c16_ffb_x = c16_efb_x;
  c16_vl_y = c16_ffb_x / 2000.0;
  c16_gfb_x = c16_theta_6;
  c16_hfb_x = c16_gfb_x;
  c16_hfb_x = muDoubleScalarSin(c16_hfb_x);
  c16_bl_b = c16_hfb_x;
  c16_wl_y = 347.0 * c16_bl_b;
  c16_ifb_x = c16_theta_4;
  c16_jfb_x = c16_ifb_x;
  c16_jfb_x = muDoubleScalarCos(c16_jfb_x);
  c16_kfb_x = c16_theta_2;
  c16_lfb_x = c16_kfb_x;
  c16_lfb_x = muDoubleScalarCos(c16_lfb_x);
  c16_mfb_x = c16_theta_1;
  c16_nfb_x = c16_mfb_x;
  c16_nfb_x = muDoubleScalarSin(c16_nfb_x);
  c16_fk_a = c16_lfb_x;
  c16_cl_b = c16_nfb_x;
  c16_xl_y = c16_fk_a * c16_cl_b;
  c16_ofb_x = c16_theta_3;
  c16_pfb_x = c16_ofb_x;
  c16_pfb_x = muDoubleScalarSin(c16_pfb_x);
  c16_gk_a = c16_xl_y;
  c16_dl_b = c16_pfb_x;
  c16_yl_y = c16_gk_a * c16_dl_b;
  c16_qfb_x = c16_theta_3;
  c16_rfb_x = c16_qfb_x;
  c16_rfb_x = muDoubleScalarCos(c16_rfb_x);
  c16_sfb_x = c16_theta_1;
  c16_tfb_x = c16_sfb_x;
  c16_tfb_x = muDoubleScalarSin(c16_tfb_x);
  c16_hk_a = c16_rfb_x;
  c16_el_b = c16_tfb_x;
  c16_am_y = c16_hk_a * c16_el_b;
  c16_ufb_x = c16_theta_2;
  c16_vfb_x = c16_ufb_x;
  c16_vfb_x = muDoubleScalarSin(c16_vfb_x);
  c16_ik_a = c16_am_y;
  c16_fl_b = c16_vfb_x;
  c16_bm_y = c16_ik_a * c16_fl_b;
  c16_jk_a = c16_jfb_x;
  c16_gl_b = c16_yl_y + c16_bm_y;
  c16_cm_y = c16_jk_a * c16_gl_b;
  c16_wfb_x = c16_theta_4;
  c16_xfb_x = c16_wfb_x;
  c16_xfb_x = muDoubleScalarSin(c16_xfb_x);
  c16_yfb_x = c16_theta_1;
  c16_agb_x = c16_yfb_x;
  c16_agb_x = muDoubleScalarSin(c16_agb_x);
  c16_bgb_x = c16_theta_2;
  c16_cgb_x = c16_bgb_x;
  c16_cgb_x = muDoubleScalarSin(c16_cgb_x);
  c16_kk_a = c16_agb_x;
  c16_hl_b = c16_cgb_x;
  c16_dm_y = c16_kk_a * c16_hl_b;
  c16_dgb_x = c16_theta_3;
  c16_egb_x = c16_dgb_x;
  c16_egb_x = muDoubleScalarSin(c16_egb_x);
  c16_lk_a = c16_dm_y;
  c16_il_b = c16_egb_x;
  c16_em_y = c16_lk_a * c16_il_b;
  c16_fgb_x = c16_theta_2;
  c16_ggb_x = c16_fgb_x;
  c16_ggb_x = muDoubleScalarCos(c16_ggb_x);
  c16_hgb_x = c16_theta_3;
  c16_igb_x = c16_hgb_x;
  c16_igb_x = muDoubleScalarCos(c16_igb_x);
  c16_mk_a = c16_ggb_x;
  c16_jl_b = c16_igb_x;
  c16_fm_y = c16_mk_a * c16_jl_b;
  c16_jgb_x = c16_theta_1;
  c16_kgb_x = c16_jgb_x;
  c16_kgb_x = muDoubleScalarSin(c16_kgb_x);
  c16_nk_a = c16_fm_y;
  c16_kl_b = c16_kgb_x;
  c16_gm_y = c16_nk_a * c16_kl_b;
  c16_ok_a = c16_xfb_x;
  c16_ll_b = c16_em_y - c16_gm_y;
  c16_hm_y = c16_ok_a * c16_ll_b;
  c16_pk_a = c16_wl_y;
  c16_ml_b = c16_cm_y - c16_hm_y;
  c16_im_y = c16_pk_a * c16_ml_b;
  c16_v_A = c16_im_y;
  c16_lgb_x = c16_v_A;
  c16_mgb_x = c16_lgb_x;
  c16_jm_y = c16_mgb_x / 20000.0;
  c16_ngb_x = c16_theta_1;
  c16_ogb_x = c16_ngb_x;
  c16_ogb_x = muDoubleScalarSin(c16_ogb_x);
  c16_nl_b = c16_ogb_x;
  c16_km_y = 39243.0 * c16_nl_b;
  c16_pgb_x = c16_theta_2;
  c16_qgb_x = c16_pgb_x;
  c16_qgb_x = muDoubleScalarSin(c16_qgb_x);
  c16_qk_a = c16_km_y;
  c16_ol_b = c16_qgb_x;
  c16_lm_y = c16_qk_a * c16_ol_b;
  c16_rgb_x = c16_theta_3;
  c16_sgb_x = c16_rgb_x;
  c16_sgb_x = muDoubleScalarSin(c16_sgb_x);
  c16_rk_a = c16_lm_y;
  c16_pl_b = c16_sgb_x;
  c16_mm_y = c16_rk_a * c16_pl_b;
  c16_w_A = c16_mm_y;
  c16_tgb_x = c16_w_A;
  c16_ugb_x = c16_tgb_x;
  c16_nm_y = c16_ugb_x / 100000.0;
  c16_vgb_x = c16_theta_2;
  c16_wgb_x = c16_vgb_x;
  c16_wgb_x = muDoubleScalarCos(c16_wgb_x);
  c16_ql_b = c16_wgb_x;
  c16_om_y = 39243.0 * c16_ql_b;
  c16_xgb_x = c16_theta_3;
  c16_ygb_x = c16_xgb_x;
  c16_ygb_x = muDoubleScalarCos(c16_ygb_x);
  c16_sk_a = c16_om_y;
  c16_rl_b = c16_ygb_x;
  c16_pm_y = c16_sk_a * c16_rl_b;
  c16_ahb_x = c16_theta_1;
  c16_bhb_x = c16_ahb_x;
  c16_bhb_x = muDoubleScalarSin(c16_bhb_x);
  c16_tk_a = c16_pm_y;
  c16_sl_b = c16_bhb_x;
  c16_qm_y = c16_tk_a * c16_sl_b;
  c16_x_A = c16_qm_y;
  c16_chb_x = c16_x_A;
  c16_dhb_x = c16_chb_x;
  c16_rm_y = c16_dhb_x / 100000.0;
  c16_ehb_x = c16_theta_6;
  c16_fhb_x = c16_ehb_x;
  c16_fhb_x = muDoubleScalarSin(c16_fhb_x);
  c16_ghb_x = c16_theta_4;
  c16_hhb_x = c16_ghb_x;
  c16_hhb_x = muDoubleScalarCos(c16_hhb_x);
  c16_ihb_x = c16_theta_2;
  c16_jhb_x = c16_ihb_x;
  c16_jhb_x = muDoubleScalarCos(c16_jhb_x);
  c16_khb_x = c16_theta_3;
  c16_lhb_x = c16_khb_x;
  c16_lhb_x = muDoubleScalarCos(c16_lhb_x);
  c16_uk_a = c16_jhb_x;
  c16_tl_b = c16_lhb_x;
  c16_sm_y = c16_uk_a * c16_tl_b;
  c16_mhb_x = c16_theta_2;
  c16_nhb_x = c16_mhb_x;
  c16_nhb_x = muDoubleScalarSin(c16_nhb_x);
  c16_ohb_x = c16_theta_3;
  c16_phb_x = c16_ohb_x;
  c16_phb_x = muDoubleScalarSin(c16_phb_x);
  c16_vk_a = c16_nhb_x;
  c16_ul_b = c16_phb_x;
  c16_tm_y = c16_vk_a * c16_ul_b;
  c16_wk_a = c16_hhb_x;
  c16_vl_b = c16_sm_y - c16_tm_y;
  c16_um_y = c16_wk_a * c16_vl_b;
  c16_qhb_x = c16_theta_4;
  c16_rhb_x = c16_qhb_x;
  c16_rhb_x = muDoubleScalarSin(c16_rhb_x);
  c16_shb_x = c16_theta_2;
  c16_thb_x = c16_shb_x;
  c16_thb_x = muDoubleScalarCos(c16_thb_x);
  c16_uhb_x = c16_theta_3;
  c16_vhb_x = c16_uhb_x;
  c16_vhb_x = muDoubleScalarSin(c16_vhb_x);
  c16_xk_a = c16_thb_x;
  c16_wl_b = c16_vhb_x;
  c16_vm_y = c16_xk_a * c16_wl_b;
  c16_whb_x = c16_theta_3;
  c16_xhb_x = c16_whb_x;
  c16_xhb_x = muDoubleScalarCos(c16_xhb_x);
  c16_yhb_x = c16_theta_2;
  c16_aib_x = c16_yhb_x;
  c16_aib_x = muDoubleScalarSin(c16_aib_x);
  c16_yk_a = c16_xhb_x;
  c16_xl_b = c16_aib_x;
  c16_wm_y = c16_yk_a * c16_xl_b;
  c16_al_a = c16_rhb_x;
  c16_yl_b = c16_vm_y + c16_wm_y;
  c16_xm_y = c16_al_a * c16_yl_b;
  c16_bl_a = c16_fhb_x;
  c16_am_b = c16_um_y - c16_xm_y;
  c16_ym_y = c16_bl_a * c16_am_b;
  c16_bib_x = c16_theta_5;
  c16_cib_x = c16_bib_x;
  c16_cib_x = muDoubleScalarCos(c16_cib_x);
  c16_dib_x = c16_theta_6;
  c16_eib_x = c16_dib_x;
  c16_eib_x = muDoubleScalarCos(c16_eib_x);
  c16_cl_a = c16_cib_x;
  c16_bm_b = c16_eib_x;
  c16_an_y = c16_cl_a * c16_bm_b;
  c16_fib_x = c16_theta_4;
  c16_gib_x = c16_fib_x;
  c16_gib_x = muDoubleScalarCos(c16_gib_x);
  c16_hib_x = c16_theta_2;
  c16_iib_x = c16_hib_x;
  c16_iib_x = muDoubleScalarCos(c16_iib_x);
  c16_jib_x = c16_theta_3;
  c16_kib_x = c16_jib_x;
  c16_kib_x = muDoubleScalarSin(c16_kib_x);
  c16_dl_a = c16_iib_x;
  c16_cm_b = c16_kib_x;
  c16_bn_y = c16_dl_a * c16_cm_b;
  c16_lib_x = c16_theta_3;
  c16_mib_x = c16_lib_x;
  c16_mib_x = muDoubleScalarCos(c16_mib_x);
  c16_nib_x = c16_theta_2;
  c16_oib_x = c16_nib_x;
  c16_oib_x = muDoubleScalarSin(c16_oib_x);
  c16_el_a = c16_mib_x;
  c16_dm_b = c16_oib_x;
  c16_cn_y = c16_el_a * c16_dm_b;
  c16_fl_a = c16_gib_x;
  c16_em_b = c16_bn_y + c16_cn_y;
  c16_dn_y = c16_fl_a * c16_em_b;
  c16_pib_x = c16_theta_4;
  c16_qib_x = c16_pib_x;
  c16_qib_x = muDoubleScalarSin(c16_qib_x);
  c16_rib_x = c16_theta_2;
  c16_sib_x = c16_rib_x;
  c16_sib_x = muDoubleScalarCos(c16_sib_x);
  c16_tib_x = c16_theta_3;
  c16_uib_x = c16_tib_x;
  c16_uib_x = muDoubleScalarCos(c16_uib_x);
  c16_gl_a = c16_sib_x;
  c16_fm_b = c16_uib_x;
  c16_en_y = c16_gl_a * c16_fm_b;
  c16_vib_x = c16_theta_2;
  c16_wib_x = c16_vib_x;
  c16_wib_x = muDoubleScalarSin(c16_wib_x);
  c16_xib_x = c16_theta_3;
  c16_yib_x = c16_xib_x;
  c16_yib_x = muDoubleScalarSin(c16_yib_x);
  c16_hl_a = c16_wib_x;
  c16_gm_b = c16_yib_x;
  c16_fn_y = c16_hl_a * c16_gm_b;
  c16_il_a = c16_qib_x;
  c16_hm_b = c16_en_y - c16_fn_y;
  c16_gn_y = c16_il_a * c16_hm_b;
  c16_jl_a = c16_an_y;
  c16_im_b = c16_dn_y + c16_gn_y;
  c16_hn_y = c16_jl_a * c16_im_b;
  c16_ajb_x = c16_theta_6;
  c16_bjb_x = c16_ajb_x;
  c16_bjb_x = muDoubleScalarCos(c16_bjb_x);
  c16_cjb_x = c16_theta_4;
  c16_djb_x = c16_cjb_x;
  c16_djb_x = muDoubleScalarCos(c16_djb_x);
  c16_ejb_x = c16_theta_2;
  c16_fjb_x = c16_ejb_x;
  c16_fjb_x = muDoubleScalarCos(c16_fjb_x);
  c16_gjb_x = c16_theta_3;
  c16_hjb_x = c16_gjb_x;
  c16_hjb_x = muDoubleScalarCos(c16_hjb_x);
  c16_kl_a = c16_fjb_x;
  c16_jm_b = c16_hjb_x;
  c16_in_y = c16_kl_a * c16_jm_b;
  c16_ijb_x = c16_theta_2;
  c16_jjb_x = c16_ijb_x;
  c16_jjb_x = muDoubleScalarSin(c16_jjb_x);
  c16_kjb_x = c16_theta_3;
  c16_ljb_x = c16_kjb_x;
  c16_ljb_x = muDoubleScalarSin(c16_ljb_x);
  c16_ll_a = c16_jjb_x;
  c16_km_b = c16_ljb_x;
  c16_jn_y = c16_ll_a * c16_km_b;
  c16_ml_a = c16_djb_x;
  c16_lm_b = c16_in_y - c16_jn_y;
  c16_kn_y = c16_ml_a * c16_lm_b;
  c16_mjb_x = c16_theta_4;
  c16_njb_x = c16_mjb_x;
  c16_njb_x = muDoubleScalarSin(c16_njb_x);
  c16_ojb_x = c16_theta_2;
  c16_pjb_x = c16_ojb_x;
  c16_pjb_x = muDoubleScalarCos(c16_pjb_x);
  c16_qjb_x = c16_theta_3;
  c16_rjb_x = c16_qjb_x;
  c16_rjb_x = muDoubleScalarSin(c16_rjb_x);
  c16_nl_a = c16_pjb_x;
  c16_mm_b = c16_rjb_x;
  c16_ln_y = c16_nl_a * c16_mm_b;
  c16_sjb_x = c16_theta_3;
  c16_tjb_x = c16_sjb_x;
  c16_tjb_x = muDoubleScalarCos(c16_tjb_x);
  c16_ujb_x = c16_theta_2;
  c16_vjb_x = c16_ujb_x;
  c16_vjb_x = muDoubleScalarSin(c16_vjb_x);
  c16_ol_a = c16_tjb_x;
  c16_nm_b = c16_vjb_x;
  c16_mn_y = c16_ol_a * c16_nm_b;
  c16_pl_a = c16_njb_x;
  c16_om_b = c16_ln_y + c16_mn_y;
  c16_nn_y = c16_pl_a * c16_om_b;
  c16_ql_a = c16_bjb_x;
  c16_pm_b = c16_kn_y - c16_nn_y;
  c16_on_y = c16_ql_a * c16_pm_b;
  c16_wjb_x = c16_theta_5;
  c16_xjb_x = c16_wjb_x;
  c16_xjb_x = muDoubleScalarCos(c16_xjb_x);
  c16_yjb_x = c16_theta_6;
  c16_akb_x = c16_yjb_x;
  c16_akb_x = muDoubleScalarSin(c16_akb_x);
  c16_rl_a = c16_xjb_x;
  c16_qm_b = c16_akb_x;
  c16_pn_y = c16_rl_a * c16_qm_b;
  c16_bkb_x = c16_theta_4;
  c16_ckb_x = c16_bkb_x;
  c16_ckb_x = muDoubleScalarCos(c16_ckb_x);
  c16_dkb_x = c16_theta_2;
  c16_ekb_x = c16_dkb_x;
  c16_ekb_x = muDoubleScalarCos(c16_ekb_x);
  c16_fkb_x = c16_theta_3;
  c16_gkb_x = c16_fkb_x;
  c16_gkb_x = muDoubleScalarSin(c16_gkb_x);
  c16_sl_a = c16_ekb_x;
  c16_rm_b = c16_gkb_x;
  c16_qn_y = c16_sl_a * c16_rm_b;
  c16_hkb_x = c16_theta_3;
  c16_ikb_x = c16_hkb_x;
  c16_ikb_x = muDoubleScalarCos(c16_ikb_x);
  c16_jkb_x = c16_theta_2;
  c16_kkb_x = c16_jkb_x;
  c16_kkb_x = muDoubleScalarSin(c16_kkb_x);
  c16_tl_a = c16_ikb_x;
  c16_sm_b = c16_kkb_x;
  c16_rn_y = c16_tl_a * c16_sm_b;
  c16_ul_a = c16_ckb_x;
  c16_tm_b = c16_qn_y + c16_rn_y;
  c16_sn_y = c16_ul_a * c16_tm_b;
  c16_lkb_x = c16_theta_4;
  c16_mkb_x = c16_lkb_x;
  c16_mkb_x = muDoubleScalarSin(c16_mkb_x);
  c16_nkb_x = c16_theta_2;
  c16_okb_x = c16_nkb_x;
  c16_okb_x = muDoubleScalarCos(c16_okb_x);
  c16_pkb_x = c16_theta_3;
  c16_qkb_x = c16_pkb_x;
  c16_qkb_x = muDoubleScalarCos(c16_qkb_x);
  c16_vl_a = c16_okb_x;
  c16_um_b = c16_qkb_x;
  c16_tn_y = c16_vl_a * c16_um_b;
  c16_rkb_x = c16_theta_2;
  c16_skb_x = c16_rkb_x;
  c16_skb_x = muDoubleScalarSin(c16_skb_x);
  c16_tkb_x = c16_theta_3;
  c16_ukb_x = c16_tkb_x;
  c16_ukb_x = muDoubleScalarSin(c16_ukb_x);
  c16_wl_a = c16_skb_x;
  c16_vm_b = c16_ukb_x;
  c16_un_y = c16_wl_a * c16_vm_b;
  c16_xl_a = c16_mkb_x;
  c16_wm_b = c16_tn_y - c16_un_y;
  c16_vn_y = c16_xl_a * c16_wm_b;
  c16_yl_a = c16_pn_y;
  c16_xm_b = c16_sn_y + c16_vn_y;
  c16_wn_y = c16_yl_a * c16_xm_b;
  c16_vkb_x = c16_theta_5;
  c16_wkb_x = c16_vkb_x;
  c16_wkb_x = muDoubleScalarSin(c16_wkb_x);
  c16_xkb_x = c16_theta_4;
  c16_ykb_x = c16_xkb_x;
  c16_ykb_x = muDoubleScalarCos(c16_ykb_x);
  c16_alb_x = c16_theta_2;
  c16_blb_x = c16_alb_x;
  c16_blb_x = muDoubleScalarCos(c16_blb_x);
  c16_clb_x = c16_theta_3;
  c16_dlb_x = c16_clb_x;
  c16_dlb_x = muDoubleScalarSin(c16_dlb_x);
  c16_am_a = c16_blb_x;
  c16_ym_b = c16_dlb_x;
  c16_xn_y = c16_am_a * c16_ym_b;
  c16_elb_x = c16_theta_3;
  c16_flb_x = c16_elb_x;
  c16_flb_x = muDoubleScalarCos(c16_flb_x);
  c16_glb_x = c16_theta_2;
  c16_hlb_x = c16_glb_x;
  c16_hlb_x = muDoubleScalarSin(c16_hlb_x);
  c16_bm_a = c16_flb_x;
  c16_an_b = c16_hlb_x;
  c16_yn_y = c16_bm_a * c16_an_b;
  c16_cm_a = c16_ykb_x;
  c16_bn_b = c16_xn_y + c16_yn_y;
  c16_ao_y = c16_cm_a * c16_bn_b;
  c16_ilb_x = c16_theta_4;
  c16_jlb_x = c16_ilb_x;
  c16_jlb_x = muDoubleScalarSin(c16_jlb_x);
  c16_klb_x = c16_theta_2;
  c16_llb_x = c16_klb_x;
  c16_llb_x = muDoubleScalarCos(c16_llb_x);
  c16_mlb_x = c16_theta_3;
  c16_nlb_x = c16_mlb_x;
  c16_nlb_x = muDoubleScalarCos(c16_nlb_x);
  c16_dm_a = c16_llb_x;
  c16_cn_b = c16_nlb_x;
  c16_bo_y = c16_dm_a * c16_cn_b;
  c16_olb_x = c16_theta_2;
  c16_plb_x = c16_olb_x;
  c16_plb_x = muDoubleScalarSin(c16_plb_x);
  c16_qlb_x = c16_theta_3;
  c16_rlb_x = c16_qlb_x;
  c16_rlb_x = muDoubleScalarSin(c16_rlb_x);
  c16_em_a = c16_plb_x;
  c16_dn_b = c16_rlb_x;
  c16_co_y = c16_em_a * c16_dn_b;
  c16_fm_a = c16_jlb_x;
  c16_en_b = c16_bo_y - c16_co_y;
  c16_do_y = c16_fm_a * c16_en_b;
  c16_gm_a = -c16_wkb_x;
  c16_fn_b = c16_ao_y + c16_do_y;
  c16_eo_y = c16_gm_a * c16_fn_b;
  c16_slb_x = c16_theta_6;
  c16_tlb_x = c16_slb_x;
  c16_tlb_x = muDoubleScalarCos(c16_tlb_x);
  c16_gn_b = c16_tlb_x;
  c16_fo_y = 121.0 * c16_gn_b;
  c16_ulb_x = c16_theta_4;
  c16_vlb_x = c16_ulb_x;
  c16_vlb_x = muDoubleScalarCos(c16_vlb_x);
  c16_wlb_x = c16_theta_2;
  c16_xlb_x = c16_wlb_x;
  c16_xlb_x = muDoubleScalarCos(c16_xlb_x);
  c16_ylb_x = c16_theta_3;
  c16_amb_x = c16_ylb_x;
  c16_amb_x = muDoubleScalarCos(c16_amb_x);
  c16_hm_a = c16_xlb_x;
  c16_hn_b = c16_amb_x;
  c16_go_y = c16_hm_a * c16_hn_b;
  c16_bmb_x = c16_theta_2;
  c16_cmb_x = c16_bmb_x;
  c16_cmb_x = muDoubleScalarSin(c16_cmb_x);
  c16_dmb_x = c16_theta_3;
  c16_emb_x = c16_dmb_x;
  c16_emb_x = muDoubleScalarSin(c16_emb_x);
  c16_im_a = c16_cmb_x;
  c16_in_b = c16_emb_x;
  c16_ho_y = c16_im_a * c16_in_b;
  c16_jm_a = c16_vlb_x;
  c16_jn_b = c16_go_y - c16_ho_y;
  c16_io_y = c16_jm_a * c16_jn_b;
  c16_fmb_x = c16_theta_4;
  c16_gmb_x = c16_fmb_x;
  c16_gmb_x = muDoubleScalarSin(c16_gmb_x);
  c16_hmb_x = c16_theta_2;
  c16_imb_x = c16_hmb_x;
  c16_imb_x = muDoubleScalarCos(c16_imb_x);
  c16_jmb_x = c16_theta_3;
  c16_kmb_x = c16_jmb_x;
  c16_kmb_x = muDoubleScalarSin(c16_kmb_x);
  c16_km_a = c16_imb_x;
  c16_kn_b = c16_kmb_x;
  c16_jo_y = c16_km_a * c16_kn_b;
  c16_lmb_x = c16_theta_3;
  c16_mmb_x = c16_lmb_x;
  c16_mmb_x = muDoubleScalarCos(c16_mmb_x);
  c16_nmb_x = c16_theta_2;
  c16_omb_x = c16_nmb_x;
  c16_omb_x = muDoubleScalarSin(c16_omb_x);
  c16_lm_a = c16_mmb_x;
  c16_ln_b = c16_omb_x;
  c16_ko_y = c16_lm_a * c16_ln_b;
  c16_mm_a = c16_gmb_x;
  c16_mn_b = c16_jo_y + c16_ko_y;
  c16_lo_y = c16_mm_a * c16_mn_b;
  c16_nm_a = c16_fo_y;
  c16_nn_b = c16_io_y - c16_lo_y;
  c16_mo_y = c16_nm_a * c16_nn_b;
  c16_y_A = c16_mo_y;
  c16_pmb_x = c16_y_A;
  c16_qmb_x = c16_pmb_x;
  c16_no_y = c16_qmb_x / 20000.0;
  c16_rmb_x = c16_theta_2;
  c16_smb_x = c16_rmb_x;
  c16_smb_x = muDoubleScalarCos(c16_smb_x);
  c16_on_b = c16_smb_x;
  c16_oo_y = 39243.0 * c16_on_b;
  c16_tmb_x = c16_theta_3;
  c16_umb_x = c16_tmb_x;
  c16_umb_x = muDoubleScalarSin(c16_umb_x);
  c16_om_a = c16_oo_y;
  c16_pn_b = c16_umb_x;
  c16_po_y = c16_om_a * c16_pn_b;
  c16_ab_A = c16_po_y;
  c16_vmb_x = c16_ab_A;
  c16_wmb_x = c16_vmb_x;
  c16_qo_y = c16_wmb_x / 100000.0;
  c16_xmb_x = c16_theta_3;
  c16_ymb_x = c16_xmb_x;
  c16_ymb_x = muDoubleScalarCos(c16_ymb_x);
  c16_qn_b = c16_ymb_x;
  c16_ro_y = 39243.0 * c16_qn_b;
  c16_anb_x = c16_theta_2;
  c16_bnb_x = c16_anb_x;
  c16_bnb_x = muDoubleScalarSin(c16_bnb_x);
  c16_pm_a = c16_ro_y;
  c16_rn_b = c16_bnb_x;
  c16_so_y = c16_pm_a * c16_rn_b;
  c16_bb_A = c16_so_y;
  c16_cnb_x = c16_bb_A;
  c16_dnb_x = c16_cnb_x;
  c16_to_y = c16_dnb_x / 100000.0;
  c16_enb_x = c16_theta_2;
  c16_fnb_x = c16_enb_x;
  c16_fnb_x = muDoubleScalarSin(c16_fnb_x);
  c16_sn_b = c16_fnb_x;
  c16_uo_y = 17.0 * c16_sn_b;
  c16_cb_A = c16_uo_y;
  c16_gnb_x = c16_cb_A;
  c16_hnb_x = c16_gnb_x;
  c16_vo_y = c16_hnb_x / 40.0;
  c16_inb_x = c16_theta_5;
  c16_jnb_x = c16_inb_x;
  c16_jnb_x = muDoubleScalarSin(c16_jnb_x);
  c16_tn_b = c16_jnb_x;
  c16_wo_y = 183.0 * c16_tn_b;
  c16_knb_x = c16_theta_4;
  c16_lnb_x = c16_knb_x;
  c16_lnb_x = muDoubleScalarCos(c16_lnb_x);
  c16_mnb_x = c16_theta_2;
  c16_nnb_x = c16_mnb_x;
  c16_nnb_x = muDoubleScalarCos(c16_nnb_x);
  c16_onb_x = c16_theta_3;
  c16_pnb_x = c16_onb_x;
  c16_pnb_x = muDoubleScalarSin(c16_pnb_x);
  c16_qm_a = c16_nnb_x;
  c16_un_b = c16_pnb_x;
  c16_xo_y = c16_qm_a * c16_un_b;
  c16_qnb_x = c16_theta_3;
  c16_rnb_x = c16_qnb_x;
  c16_rnb_x = muDoubleScalarCos(c16_rnb_x);
  c16_snb_x = c16_theta_2;
  c16_tnb_x = c16_snb_x;
  c16_tnb_x = muDoubleScalarSin(c16_tnb_x);
  c16_rm_a = c16_rnb_x;
  c16_vn_b = c16_tnb_x;
  c16_yo_y = c16_rm_a * c16_vn_b;
  c16_sm_a = c16_lnb_x;
  c16_wn_b = c16_xo_y + c16_yo_y;
  c16_ap_y = c16_sm_a * c16_wn_b;
  c16_unb_x = c16_theta_4;
  c16_vnb_x = c16_unb_x;
  c16_vnb_x = muDoubleScalarSin(c16_vnb_x);
  c16_wnb_x = c16_theta_2;
  c16_xnb_x = c16_wnb_x;
  c16_xnb_x = muDoubleScalarCos(c16_xnb_x);
  c16_ynb_x = c16_theta_3;
  c16_aob_x = c16_ynb_x;
  c16_aob_x = muDoubleScalarCos(c16_aob_x);
  c16_tm_a = c16_xnb_x;
  c16_xn_b = c16_aob_x;
  c16_bp_y = c16_tm_a * c16_xn_b;
  c16_bob_x = c16_theta_2;
  c16_cob_x = c16_bob_x;
  c16_cob_x = muDoubleScalarSin(c16_cob_x);
  c16_dob_x = c16_theta_3;
  c16_eob_x = c16_dob_x;
  c16_eob_x = muDoubleScalarSin(c16_eob_x);
  c16_um_a = c16_cob_x;
  c16_yn_b = c16_eob_x;
  c16_cp_y = c16_um_a * c16_yn_b;
  c16_vm_a = c16_vnb_x;
  c16_ao_b = c16_bp_y - c16_cp_y;
  c16_dp_y = c16_vm_a * c16_ao_b;
  c16_wm_a = c16_wo_y;
  c16_bo_b = c16_ap_y + c16_dp_y;
  c16_ep_y = c16_wm_a * c16_bo_b;
  c16_db_A = c16_ep_y;
  c16_fob_x = c16_db_A;
  c16_gob_x = c16_fob_x;
  c16_fp_y = c16_gob_x / 2000.0;
  c16_hob_x = c16_theta_6;
  c16_iob_x = c16_hob_x;
  c16_iob_x = muDoubleScalarSin(c16_iob_x);
  c16_co_b = c16_iob_x;
  c16_gp_y = 347.0 * c16_co_b;
  c16_job_x = c16_theta_4;
  c16_kob_x = c16_job_x;
  c16_kob_x = muDoubleScalarCos(c16_kob_x);
  c16_lob_x = c16_theta_2;
  c16_mob_x = c16_lob_x;
  c16_mob_x = muDoubleScalarCos(c16_mob_x);
  c16_nob_x = c16_theta_3;
  c16_oob_x = c16_nob_x;
  c16_oob_x = muDoubleScalarCos(c16_oob_x);
  c16_xm_a = c16_mob_x;
  c16_do_b = c16_oob_x;
  c16_hp_y = c16_xm_a * c16_do_b;
  c16_pob_x = c16_theta_2;
  c16_qob_x = c16_pob_x;
  c16_qob_x = muDoubleScalarSin(c16_qob_x);
  c16_rob_x = c16_theta_3;
  c16_sob_x = c16_rob_x;
  c16_sob_x = muDoubleScalarSin(c16_sob_x);
  c16_ym_a = c16_qob_x;
  c16_eo_b = c16_sob_x;
  c16_ip_y = c16_ym_a * c16_eo_b;
  c16_an_a = c16_kob_x;
  c16_fo_b = c16_hp_y - c16_ip_y;
  c16_jp_y = c16_an_a * c16_fo_b;
  c16_tob_x = c16_theta_4;
  c16_uob_x = c16_tob_x;
  c16_uob_x = muDoubleScalarSin(c16_uob_x);
  c16_vob_x = c16_theta_2;
  c16_wob_x = c16_vob_x;
  c16_wob_x = muDoubleScalarCos(c16_wob_x);
  c16_xob_x = c16_theta_3;
  c16_yob_x = c16_xob_x;
  c16_yob_x = muDoubleScalarSin(c16_yob_x);
  c16_bn_a = c16_wob_x;
  c16_go_b = c16_yob_x;
  c16_kp_y = c16_bn_a * c16_go_b;
  c16_apb_x = c16_theta_3;
  c16_bpb_x = c16_apb_x;
  c16_bpb_x = muDoubleScalarCos(c16_bpb_x);
  c16_cpb_x = c16_theta_2;
  c16_dpb_x = c16_cpb_x;
  c16_dpb_x = muDoubleScalarSin(c16_dpb_x);
  c16_cn_a = c16_bpb_x;
  c16_ho_b = c16_dpb_x;
  c16_lp_y = c16_cn_a * c16_ho_b;
  c16_dn_a = c16_uob_x;
  c16_io_b = c16_kp_y + c16_lp_y;
  c16_mp_y = c16_dn_a * c16_io_b;
  c16_en_a = c16_gp_y;
  c16_jo_b = c16_jp_y - c16_mp_y;
  c16_np_y = c16_en_a * c16_jo_b;
  c16_eb_A = c16_np_y;
  c16_epb_x = c16_eb_A;
  c16_fpb_x = c16_epb_x;
  c16_op_y = c16_fpb_x / 20000.0;
  c16_gpb_x = c16_theta_4;
  c16_hpb_x = c16_gpb_x;
  c16_hpb_x = muDoubleScalarCos(c16_hpb_x);
  c16_ko_b = c16_hpb_x;
  c16_pp_y = 93.0 * c16_ko_b;
  c16_ipb_x = c16_theta_2;
  c16_jpb_x = c16_ipb_x;
  c16_jpb_x = muDoubleScalarCos(c16_jpb_x);
  c16_kpb_x = c16_theta_3;
  c16_lpb_x = c16_kpb_x;
  c16_lpb_x = muDoubleScalarCos(c16_lpb_x);
  c16_fn_a = c16_jpb_x;
  c16_lo_b = c16_lpb_x;
  c16_qp_y = c16_fn_a * c16_lo_b;
  c16_mpb_x = c16_theta_2;
  c16_npb_x = c16_mpb_x;
  c16_npb_x = muDoubleScalarSin(c16_npb_x);
  c16_opb_x = c16_theta_3;
  c16_ppb_x = c16_opb_x;
  c16_ppb_x = muDoubleScalarSin(c16_ppb_x);
  c16_gn_a = c16_npb_x;
  c16_mo_b = c16_ppb_x;
  c16_rp_y = c16_gn_a * c16_mo_b;
  c16_hn_a = c16_pp_y;
  c16_no_b = c16_qp_y - c16_rp_y;
  c16_sp_y = c16_hn_a * c16_no_b;
  c16_fb_A = c16_sp_y;
  c16_qpb_x = c16_fb_A;
  c16_rpb_x = c16_qpb_x;
  c16_tp_y = c16_rpb_x / 1000.0;
  c16_spb_x = c16_theta_4;
  c16_tpb_x = c16_spb_x;
  c16_tpb_x = muDoubleScalarSin(c16_tpb_x);
  c16_oo_b = c16_tpb_x;
  c16_up_y = 93.0 * c16_oo_b;
  c16_upb_x = c16_theta_2;
  c16_vpb_x = c16_upb_x;
  c16_vpb_x = muDoubleScalarCos(c16_vpb_x);
  c16_wpb_x = c16_theta_3;
  c16_xpb_x = c16_wpb_x;
  c16_xpb_x = muDoubleScalarSin(c16_xpb_x);
  c16_in_a = c16_vpb_x;
  c16_po_b = c16_xpb_x;
  c16_vp_y = c16_in_a * c16_po_b;
  c16_ypb_x = c16_theta_3;
  c16_aqb_x = c16_ypb_x;
  c16_aqb_x = muDoubleScalarCos(c16_aqb_x);
  c16_bqb_x = c16_theta_2;
  c16_cqb_x = c16_bqb_x;
  c16_cqb_x = muDoubleScalarSin(c16_cqb_x);
  c16_jn_a = c16_aqb_x;
  c16_qo_b = c16_cqb_x;
  c16_wp_y = c16_jn_a * c16_qo_b;
  c16_kn_a = c16_up_y;
  c16_ro_b = c16_vp_y + c16_wp_y;
  c16_xp_y = c16_kn_a * c16_ro_b;
  c16_gb_A = c16_xp_y;
  c16_dqb_x = c16_gb_A;
  c16_eqb_x = c16_dqb_x;
  c16_yp_y = c16_eqb_x / 1000.0;
  c16_fqb_x = c16_theta_5;
  c16_gqb_x = c16_fqb_x;
  c16_gqb_x = muDoubleScalarCos(c16_gqb_x);
  c16_so_b = c16_gqb_x;
  c16_aq_y = 347.0 * c16_so_b;
  c16_hqb_x = c16_theta_6;
  c16_iqb_x = c16_hqb_x;
  c16_iqb_x = muDoubleScalarCos(c16_iqb_x);
  c16_ln_a = c16_aq_y;
  c16_to_b = c16_iqb_x;
  c16_bq_y = c16_ln_a * c16_to_b;
  c16_jqb_x = c16_theta_4;
  c16_kqb_x = c16_jqb_x;
  c16_kqb_x = muDoubleScalarCos(c16_kqb_x);
  c16_lqb_x = c16_theta_2;
  c16_mqb_x = c16_lqb_x;
  c16_mqb_x = muDoubleScalarCos(c16_mqb_x);
  c16_nqb_x = c16_theta_3;
  c16_oqb_x = c16_nqb_x;
  c16_oqb_x = muDoubleScalarSin(c16_oqb_x);
  c16_mn_a = c16_mqb_x;
  c16_uo_b = c16_oqb_x;
  c16_cq_y = c16_mn_a * c16_uo_b;
  c16_pqb_x = c16_theta_3;
  c16_qqb_x = c16_pqb_x;
  c16_qqb_x = muDoubleScalarCos(c16_qqb_x);
  c16_rqb_x = c16_theta_2;
  c16_sqb_x = c16_rqb_x;
  c16_sqb_x = muDoubleScalarSin(c16_sqb_x);
  c16_nn_a = c16_qqb_x;
  c16_vo_b = c16_sqb_x;
  c16_dq_y = c16_nn_a * c16_vo_b;
  c16_on_a = c16_kqb_x;
  c16_wo_b = c16_cq_y + c16_dq_y;
  c16_eq_y = c16_on_a * c16_wo_b;
  c16_tqb_x = c16_theta_4;
  c16_uqb_x = c16_tqb_x;
  c16_uqb_x = muDoubleScalarSin(c16_uqb_x);
  c16_vqb_x = c16_theta_2;
  c16_wqb_x = c16_vqb_x;
  c16_wqb_x = muDoubleScalarCos(c16_wqb_x);
  c16_xqb_x = c16_theta_3;
  c16_yqb_x = c16_xqb_x;
  c16_yqb_x = muDoubleScalarCos(c16_yqb_x);
  c16_pn_a = c16_wqb_x;
  c16_xo_b = c16_yqb_x;
  c16_fq_y = c16_pn_a * c16_xo_b;
  c16_arb_x = c16_theta_2;
  c16_brb_x = c16_arb_x;
  c16_brb_x = muDoubleScalarSin(c16_brb_x);
  c16_crb_x = c16_theta_3;
  c16_drb_x = c16_crb_x;
  c16_drb_x = muDoubleScalarSin(c16_drb_x);
  c16_qn_a = c16_brb_x;
  c16_yo_b = c16_drb_x;
  c16_gq_y = c16_qn_a * c16_yo_b;
  c16_rn_a = c16_uqb_x;
  c16_ap_b = c16_fq_y - c16_gq_y;
  c16_hq_y = c16_rn_a * c16_ap_b;
  c16_sn_a = c16_bq_y;
  c16_bp_b = c16_eq_y + c16_hq_y;
  c16_iq_y = c16_sn_a * c16_bp_b;
  c16_hb_A = c16_iq_y;
  c16_erb_x = c16_hb_A;
  c16_frb_x = c16_erb_x;
  c16_jq_y = c16_frb_x / 20000.0;
  c16_grb_x = c16_theta_5;
  c16_hrb_x = c16_grb_x;
  c16_hrb_x = muDoubleScalarCos(c16_hrb_x);
  c16_cp_b = c16_hrb_x;
  c16_kq_y = 121.0 * c16_cp_b;
  c16_irb_x = c16_theta_6;
  c16_jrb_x = c16_irb_x;
  c16_jrb_x = muDoubleScalarSin(c16_jrb_x);
  c16_tn_a = c16_kq_y;
  c16_dp_b = c16_jrb_x;
  c16_lq_y = c16_tn_a * c16_dp_b;
  c16_krb_x = c16_theta_4;
  c16_lrb_x = c16_krb_x;
  c16_lrb_x = muDoubleScalarCos(c16_lrb_x);
  c16_mrb_x = c16_theta_2;
  c16_nrb_x = c16_mrb_x;
  c16_nrb_x = muDoubleScalarCos(c16_nrb_x);
  c16_orb_x = c16_theta_3;
  c16_prb_x = c16_orb_x;
  c16_prb_x = muDoubleScalarSin(c16_prb_x);
  c16_un_a = c16_nrb_x;
  c16_ep_b = c16_prb_x;
  c16_mq_y = c16_un_a * c16_ep_b;
  c16_qrb_x = c16_theta_3;
  c16_rrb_x = c16_qrb_x;
  c16_rrb_x = muDoubleScalarCos(c16_rrb_x);
  c16_srb_x = c16_theta_2;
  c16_trb_x = c16_srb_x;
  c16_trb_x = muDoubleScalarSin(c16_trb_x);
  c16_vn_a = c16_rrb_x;
  c16_fp_b = c16_trb_x;
  c16_nq_y = c16_vn_a * c16_fp_b;
  c16_wn_a = c16_lrb_x;
  c16_gp_b = c16_mq_y + c16_nq_y;
  c16_oq_y = c16_wn_a * c16_gp_b;
  c16_urb_x = c16_theta_4;
  c16_vrb_x = c16_urb_x;
  c16_vrb_x = muDoubleScalarSin(c16_vrb_x);
  c16_wrb_x = c16_theta_2;
  c16_xrb_x = c16_wrb_x;
  c16_xrb_x = muDoubleScalarCos(c16_xrb_x);
  c16_yrb_x = c16_theta_3;
  c16_asb_x = c16_yrb_x;
  c16_asb_x = muDoubleScalarCos(c16_asb_x);
  c16_xn_a = c16_xrb_x;
  c16_hp_b = c16_asb_x;
  c16_pq_y = c16_xn_a * c16_hp_b;
  c16_bsb_x = c16_theta_2;
  c16_csb_x = c16_bsb_x;
  c16_csb_x = muDoubleScalarSin(c16_csb_x);
  c16_dsb_x = c16_theta_3;
  c16_esb_x = c16_dsb_x;
  c16_esb_x = muDoubleScalarSin(c16_esb_x);
  c16_yn_a = c16_csb_x;
  c16_ip_b = c16_esb_x;
  c16_qq_y = c16_yn_a * c16_ip_b;
  c16_ao_a = c16_vrb_x;
  c16_jp_b = c16_pq_y - c16_qq_y;
  c16_rq_y = c16_ao_a * c16_jp_b;
  c16_bo_a = c16_lq_y;
  c16_kp_b = c16_oq_y + c16_rq_y;
  c16_sq_y = c16_bo_a * c16_kp_b;
  c16_ib_A = c16_sq_y;
  c16_fsb_x = c16_ib_A;
  c16_gsb_x = c16_fsb_x;
  c16_tq_y = c16_gsb_x / 20000.0;
  c16_T[0] = c16_m_y - c16_x_y;
  c16_T[4] = c16_lb_y - c16_wb_y;
  c16_T[8] = c16_xb_y + c16_jc_y;
  c16_T[12] = ((((((((((c16_lc_y - c16_oc_y) + c16_rc_y) + c16_hd_y) + c16_od_y)
                    - c16_ee_y) - c16_le_y) - c16_ye_y) + c16_mf_y) - c16_ag_y)
               + c16_eg_y) - c16_ig_y;
  c16_T[1] = c16_vg_y - c16_hh_y;
  c16_T[5] = c16_uh_y - c16_gi_y;
  c16_T[9] = c16_ri_y - c16_si_y;
  c16_T[13] = ((((((((((c16_aj_y - c16_dj_y) - c16_gj_y) - c16_ij_y) - c16_xj_y)
                    - c16_fk_y) + c16_uk_y) - c16_il_y) + c16_vl_y) - c16_jm_y)
               + c16_nm_y) - c16_rm_y;
  c16_T[2] = c16_ym_y + c16_hn_y;
  c16_T[6] = c16_on_y - c16_wn_y;
  c16_T[10] = c16_eo_y;
  c16_T[14] = (((((((((c16_no_y - c16_qo_y) - c16_to_y) - c16_vo_y) - c16_fp_y)
                   + c16_op_y) - c16_tp_y) + c16_yp_y) + c16_jq_y) - c16_tq_y) +
    0.0892;
  c16_i8 = 0;
  for (c16_i9 = 0; c16_i9 < 4; c16_i9++) {
    c16_T[c16_i8 + 3] = c16_dv2[c16_i9];
    c16_i8 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 107);
  c16_i10 = 0;
  c16_i11 = 0;
  for (c16_i12 = 0; c16_i12 < 3; c16_i12++) {
    for (c16_i13 = 0; c16_i13 < 3; c16_i13++) {
      c16_R[c16_i13 + c16_i10] = c16_T[c16_i13 + c16_i11];
    }

    c16_i10 += 3;
    c16_i11 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 108);
  for (c16_i14 = 0; c16_i14 < 3; c16_i14++) {
    c16_d[c16_i14] = c16_T[c16_i14 + 12];
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -108);
  _SFD_SYMBOL_SCOPE_POP();
  for (c16_i15 = 0; c16_i15 < 3; c16_i15++) {
    (*c16_b_d)[c16_i15] = c16_d[c16_i15];
  }

  for (c16_i16 = 0; c16_i16 < 9; c16_i16++) {
    (*c16_b_R)[c16_i16] = c16_R[c16_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc16_JointSpaceControl_BestInertia
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i17;
  int32_T c16_i18;
  int32_T c16_i19;
  real_T c16_b_inData[9];
  int32_T c16_i20;
  int32_T c16_i21;
  int32_T c16_i22;
  real_T c16_u[9];
  const mxArray *c16_y = NULL;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i17 = 0;
  for (c16_i18 = 0; c16_i18 < 3; c16_i18++) {
    for (c16_i19 = 0; c16_i19 < 3; c16_i19++) {
      c16_b_inData[c16_i19 + c16_i17] = (*(real_T (*)[9])c16_inData)[c16_i19 +
        c16_i17];
    }

    c16_i17 += 3;
  }

  c16_i20 = 0;
  for (c16_i21 = 0; c16_i21 < 3; c16_i21++) {
    for (c16_i22 = 0; c16_i22 < 3; c16_i22++) {
      c16_u[c16_i22 + c16_i20] = c16_b_inData[c16_i22 + c16_i20];
    }

    c16_i20 += 3;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_R, const char_T *c16_identifier, real_T c16_y[9])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_R), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_R);
}

static void c16_b_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[9])
{
  real_T c16_dv3[9];
  int32_T c16_i23;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c16_i23 = 0; c16_i23 < 9; c16_i23++) {
    c16_y[c16_i23] = c16_dv3[c16_i23];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_R;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[9];
  int32_T c16_i24;
  int32_T c16_i25;
  int32_T c16_i26;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_R = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_R), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_R);
  c16_i24 = 0;
  for (c16_i25 = 0; c16_i25 < 3; c16_i25++) {
    for (c16_i26 = 0; c16_i26 < 3; c16_i26++) {
      (*(real_T (*)[9])c16_outData)[c16_i26 + c16_i24] = c16_y[c16_i26 + c16_i24];
    }

    c16_i24 += 3;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i27;
  real_T c16_b_inData[3];
  int32_T c16_i28;
  real_T c16_u[3];
  const mxArray *c16_y = NULL;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i27 = 0; c16_i27 < 3; c16_i27++) {
    c16_b_inData[c16_i27] = (*(real_T (*)[3])c16_inData)[c16_i27];
  }

  for (c16_i28 = 0; c16_i28 < 3; c16_i28++) {
    c16_u[c16_i28] = c16_b_inData[c16_i28];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_c_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_d, const char_T *c16_identifier, real_T c16_y[3])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_d), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_d);
}

static void c16_d_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[3])
{
  real_T c16_dv4[3];
  int32_T c16_i29;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c16_i29 = 0; c16_i29 < 3; c16_i29++) {
    c16_y[c16_i29] = c16_dv4[c16_i29];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_d;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[3];
  int32_T c16_i30;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_d = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_d), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_d);
  for (c16_i30 = 0; c16_i30 < 3; c16_i30++) {
    (*(real_T (*)[3])c16_outData)[c16_i30] = c16_y[c16_i30];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i31;
  real_T c16_b_inData[6];
  int32_T c16_i32;
  real_T c16_u[6];
  const mxArray *c16_y = NULL;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i31 = 0; c16_i31 < 6; c16_i31++) {
    c16_b_inData[c16_i31] = (*(real_T (*)[6])c16_inData)[c16_i31];
  }

  for (c16_i32 = 0; c16_i32 < 6; c16_i32++) {
    c16_u[c16_i32] = c16_b_inData[c16_i32];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static real_T c16_e_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i33;
  int32_T c16_i34;
  int32_T c16_i35;
  real_T c16_b_inData[16];
  int32_T c16_i36;
  int32_T c16_i37;
  int32_T c16_i38;
  real_T c16_u[16];
  const mxArray *c16_y = NULL;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i33 = 0;
  for (c16_i34 = 0; c16_i34 < 4; c16_i34++) {
    for (c16_i35 = 0; c16_i35 < 4; c16_i35++) {
      c16_b_inData[c16_i35 + c16_i33] = (*(real_T (*)[16])c16_inData)[c16_i35 +
        c16_i33];
    }

    c16_i33 += 4;
  }

  c16_i36 = 0;
  for (c16_i37 = 0; c16_i37 < 4; c16_i37++) {
    for (c16_i38 = 0; c16_i38 < 4; c16_i38++) {
      c16_u[c16_i38 + c16_i36] = c16_b_inData[c16_i38 + c16_i36];
    }

    c16_i36 += 4;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_f_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[16])
{
  real_T c16_dv5[16];
  int32_T c16_i39;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv5, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c16_i39 = 0; c16_i39 < 16; c16_i39++) {
    c16_y[c16_i39] = c16_dv5[c16_i39];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_T;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[16];
  int32_T c16_i40;
  int32_T c16_i41;
  int32_T c16_i42;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_T = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_T), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_T);
  c16_i40 = 0;
  for (c16_i41 = 0; c16_i41 < 4; c16_i41++) {
    for (c16_i42 = 0; c16_i42 < 4; c16_i42++) {
      (*(real_T (*)[16])c16_outData)[c16_i42 + c16_i40] = c16_y[c16_i42 +
        c16_i40];
    }

    c16_i40 += 4;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray
  *sf_c16_JointSpaceControl_BestInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo;
  c16_ResolvedFunctionInfo c16_info[9];
  c16_ResolvedFunctionInfo (*c16_b_info)[9];
  const mxArray *c16_m0 = NULL;
  int32_T c16_i43;
  c16_ResolvedFunctionInfo *c16_r0;
  c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  c16_b_info = (c16_ResolvedFunctionInfo (*)[9])c16_info;
  (*c16_b_info)[0].context = "";
  (*c16_b_info)[0].name = "cos";
  (*c16_b_info)[0].dominantType = "double";
  (*c16_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c16_b_info)[0].fileTimeLo = 1343851972U;
  (*c16_b_info)[0].fileTimeHi = 0U;
  (*c16_b_info)[0].mFileTimeLo = 0U;
  (*c16_b_info)[0].mFileTimeHi = 0U;
  (*c16_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c16_b_info)[1].name = "eml_scalar_cos";
  (*c16_b_info)[1].dominantType = "double";
  (*c16_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c16_b_info)[1].fileTimeLo = 1286840322U;
  (*c16_b_info)[1].fileTimeHi = 0U;
  (*c16_b_info)[1].mFileTimeLo = 0U;
  (*c16_b_info)[1].mFileTimeHi = 0U;
  (*c16_b_info)[2].context = "";
  (*c16_b_info)[2].name = "sin";
  (*c16_b_info)[2].dominantType = "double";
  (*c16_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c16_b_info)[2].fileTimeLo = 1343851986U;
  (*c16_b_info)[2].fileTimeHi = 0U;
  (*c16_b_info)[2].mFileTimeLo = 0U;
  (*c16_b_info)[2].mFileTimeHi = 0U;
  (*c16_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c16_b_info)[3].name = "eml_scalar_sin";
  (*c16_b_info)[3].dominantType = "double";
  (*c16_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c16_b_info)[3].fileTimeLo = 1286840336U;
  (*c16_b_info)[3].fileTimeHi = 0U;
  (*c16_b_info)[3].mFileTimeLo = 0U;
  (*c16_b_info)[3].mFileTimeHi = 0U;
  (*c16_b_info)[4].context = "";
  (*c16_b_info)[4].name = "mtimes";
  (*c16_b_info)[4].dominantType = "double";
  (*c16_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c16_b_info)[4].fileTimeLo = 1289541292U;
  (*c16_b_info)[4].fileTimeHi = 0U;
  (*c16_b_info)[4].mFileTimeLo = 0U;
  (*c16_b_info)[4].mFileTimeHi = 0U;
  (*c16_b_info)[5].context = "";
  (*c16_b_info)[5].name = "mrdivide";
  (*c16_b_info)[5].dominantType = "double";
  (*c16_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c16_b_info)[5].fileTimeLo = 1357973148U;
  (*c16_b_info)[5].fileTimeHi = 0U;
  (*c16_b_info)[5].mFileTimeLo = 1319751566U;
  (*c16_b_info)[5].mFileTimeHi = 0U;
  (*c16_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c16_b_info)[6].name = "rdivide";
  (*c16_b_info)[6].dominantType = "double";
  (*c16_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c16_b_info)[6].fileTimeLo = 1346531988U;
  (*c16_b_info)[6].fileTimeHi = 0U;
  (*c16_b_info)[6].mFileTimeLo = 0U;
  (*c16_b_info)[6].mFileTimeHi = 0U;
  (*c16_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c16_b_info)[7].name = "eml_scalexp_compatible";
  (*c16_b_info)[7].dominantType = "double";
  (*c16_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c16_b_info)[7].fileTimeLo = 1286840396U;
  (*c16_b_info)[7].fileTimeHi = 0U;
  (*c16_b_info)[7].mFileTimeLo = 0U;
  (*c16_b_info)[7].mFileTimeHi = 0U;
  (*c16_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c16_b_info)[8].name = "eml_div";
  (*c16_b_info)[8].dominantType = "double";
  (*c16_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c16_b_info)[8].fileTimeLo = 1313369410U;
  (*c16_b_info)[8].fileTimeHi = 0U;
  (*c16_b_info)[8].mFileTimeLo = 0U;
  (*c16_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c16_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c16_i43 = 0; c16_i43 < 9; c16_i43++) {
    c16_r0 = &c16_info[c16_i43];
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->context)), "context", "nameCaptureInfo",
                    c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->name)), "name", "nameCaptureInfo",
                    c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      c16_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->resolved)), "resolved",
                    "nameCaptureInfo", c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c16_i43);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c16_i43);
  }

  sf_mex_assign(&c16_nameCaptureInfo, c16_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static int32_T c16_g_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i44;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i44, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i44;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_h_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_b_is_active_c16_JointSpaceControl_BestInertia, const char_T
   *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_JointSpaceControl_BestInertia), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_JointSpaceControl_BestInertia);
  return c16_y;
}

static uint8_T c16_i_emlrt_marshallIn
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info
  (SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
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

void sf_c16_JointSpaceControl_BestInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4280821069U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3816198594U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4103308611U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3294780714U);
}

mxArray *sf_c16_JointSpaceControl_BestInertia_get_autoinheritance_info(void)
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

mxArray *sf_c16_JointSpaceControl_BestInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c16_JointSpaceControl_BestInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"R\",},{M[1],M[6],T\"d\",},{M[8],M[0],T\"is_active_c16_JointSpaceControl_BestInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_JointSpaceControl_BestInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_BestInertiaMachineNumber_,
           16,
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
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)
            c16_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)
            c16_sf_marshallIn);
        }

        {
          real_T (*c16_d)[3];
          real_T (*c16_q)[6];
          real_T (*c16_R)[9];
          c16_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c16_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c16_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c16_d);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_q);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_R);
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

static void sf_opaque_initialize_c16_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_JointSpaceControl_BestInertiaInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
  initialize_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  enable_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  disable_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  sf_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c16_JointSpaceControl_BestInertia(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_JointSpaceControl_BestInertia();/* state var info */
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

extern void sf_internal_set_sim_state_c16_JointSpaceControl_BestInertia
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_JointSpaceControl_BestInertia();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c16_JointSpaceControl_BestInertia(S);
}

static void sf_opaque_set_sim_state_c16_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c16_JointSpaceControl_BestInertia(S, st);
}

static void sf_opaque_terminate_c16_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_BestInertia_optimization_info();
    }

    finalize_c16_JointSpaceControl_BestInertia
      ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_JointSpaceControl_BestInertia
    ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_JointSpaceControl_BestInertia(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_JointSpaceControl_BestInertia
      ((SFc16_JointSpaceControl_BestInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_BestInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,16,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
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

static void mdlRTW_c16_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_JointSpaceControl_BestInertia(SimStruct *S)
{
  SFc16_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc16_JointSpaceControl_BestInertiaInstanceStruct *)utMalloc
    (sizeof(SFc16_JointSpaceControl_BestInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc16_JointSpaceControl_BestInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_JointSpaceControl_BestInertia;
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

void c16_JointSpaceControl_BestInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_JointSpaceControl_BestInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_JointSpaceControl_BestInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
