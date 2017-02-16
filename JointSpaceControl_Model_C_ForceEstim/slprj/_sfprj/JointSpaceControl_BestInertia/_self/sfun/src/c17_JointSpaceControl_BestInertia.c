/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_BestInertia_sfun.h"
#include "c17_JointSpaceControl_BestInertia.h"
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
static const char * c17_debug_family_names[12] = { "theta1", "theta2", "theta3",
  "theta4", "theta5", "theta6", "T", "nargin", "nargout", "q", "d", "R" };

/* Function Declarations */
static void initialize_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initialize_params_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void enable_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void disable_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c17_update_debugger_state_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void set_sim_state_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_st);
static void finalize_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void sf_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c17_chartstep_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initSimStructsc17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void registerMessagesc17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_R, const char_T *c17_identifier, real_T c17_y[9]);
static void c17_b_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[9]);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_c_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_d, const char_T *c17_identifier, real_T c17_y[3]);
static void c17_d_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[3]);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_e_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_f_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[16]);
static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_f_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_g_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_h_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_b_is_active_c17_JointSpaceControl_BestInertia, const char_T
   *c17_identifier);
static uint8_T c17_i_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void init_dsm_address_info
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c17_is_active_c17_JointSpaceControl_BestInertia = 0U;
}

static void initialize_params_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void enable_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c17_update_debugger_state_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i0;
  real_T c17_u[9];
  const mxArray *c17_b_y = NULL;
  int32_T c17_i1;
  real_T c17_b_u[3];
  const mxArray *c17_c_y = NULL;
  uint8_T c17_hoistedGlobal;
  uint8_T c17_c_u;
  const mxArray *c17_d_y = NULL;
  real_T (*c17_d)[3];
  real_T (*c17_R)[9];
  c17_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c17_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellarray(3), FALSE);
  for (c17_i0 = 0; c17_i0 < 9; c17_i0++) {
    c17_u[c17_i0] = (*c17_R)[c17_i0];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  for (c17_i1 = 0; c17_i1 < 3; c17_i1++) {
    c17_b_u[c17_i1] = (*c17_d)[c17_i1];
  }

  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", c17_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  c17_hoistedGlobal =
    chartInstance->c17_is_active_c17_JointSpaceControl_BestInertia;
  c17_c_u = c17_hoistedGlobal;
  c17_d_y = NULL;
  sf_mex_assign(&c17_d_y, sf_mex_create("y", &c17_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 2, c17_d_y);
  sf_mex_assign(&c17_st, c17_y, FALSE);
  return c17_st;
}

static void set_sim_state_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv0[9];
  int32_T c17_i2;
  real_T c17_dv1[3];
  int32_T c17_i3;
  real_T (*c17_R)[9];
  real_T (*c17_d)[3];
  c17_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c17_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = TRUE;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)), "R",
                       c17_dv0);
  for (c17_i2 = 0; c17_i2 < 9; c17_i2++) {
    (*c17_R)[c17_i2] = c17_dv0[c17_i2];
  }

  c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
    "d", c17_dv1);
  for (c17_i3 = 0; c17_i3 < 3; c17_i3++) {
    (*c17_d)[c17_i3] = c17_dv1[c17_i3];
  }

  chartInstance->c17_is_active_c17_JointSpaceControl_BestInertia =
    c17_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 2)),
    "is_active_c17_JointSpaceControl_BestInertia");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_JointSpaceControl_BestInertia(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void sf_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c17_i4;
  int32_T c17_i5;
  int32_T c17_i6;
  real_T (*c17_R)[9];
  real_T (*c17_q)[6];
  real_T (*c17_d)[3];
  c17_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c17_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c17_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c17_sfEvent);
  for (c17_i4 = 0; c17_i4 < 3; c17_i4++) {
    _SFD_DATA_RANGE_CHECK((*c17_d)[c17_i4], 0U);
  }

  for (c17_i5 = 0; c17_i5 < 6; c17_i5++) {
    _SFD_DATA_RANGE_CHECK((*c17_q)[c17_i5], 1U);
  }

  for (c17_i6 = 0; c17_i6 < 9; c17_i6++) {
    _SFD_DATA_RANGE_CHECK((*c17_R)[c17_i6], 2U);
  }

  chartInstance->c17_sfEvent = CALL_EVENT;
  c17_chartstep_c17_JointSpaceControl_BestInertia(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_BestInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c17_chartstep_c17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c17_i7;
  real_T c17_q[6];
  uint32_T c17_debug_family_var_map[12];
  real_T c17_theta1;
  real_T c17_theta2;
  real_T c17_theta3;
  real_T c17_theta4;
  real_T c17_theta5;
  real_T c17_theta6;
  real_T c17_T[16];
  real_T c17_nargin = 1.0;
  real_T c17_nargout = 2.0;
  real_T c17_d[3];
  real_T c17_R[9];
  real_T c17_x;
  real_T c17_b_x;
  real_T c17_c_x;
  real_T c17_d_x;
  real_T c17_a;
  real_T c17_b;
  real_T c17_y;
  real_T c17_e_x;
  real_T c17_f_x;
  real_T c17_b_a;
  real_T c17_b_b;
  real_T c17_b_y;
  real_T c17_g_x;
  real_T c17_h_x;
  real_T c17_i_x;
  real_T c17_j_x;
  real_T c17_c_a;
  real_T c17_c_b;
  real_T c17_c_y;
  real_T c17_k_x;
  real_T c17_l_x;
  real_T c17_d_a;
  real_T c17_d_b;
  real_T c17_d_y;
  real_T c17_m_x;
  real_T c17_n_x;
  real_T c17_e_a;
  real_T c17_e_b;
  real_T c17_e_y;
  real_T c17_o_x;
  real_T c17_p_x;
  real_T c17_q_x;
  real_T c17_r_x;
  real_T c17_f_a;
  real_T c17_f_b;
  real_T c17_f_y;
  real_T c17_s_x;
  real_T c17_t_x;
  real_T c17_g_a;
  real_T c17_g_b;
  real_T c17_g_y;
  real_T c17_u_x;
  real_T c17_v_x;
  real_T c17_w_x;
  real_T c17_x_x;
  real_T c17_h_a;
  real_T c17_h_b;
  real_T c17_h_y;
  real_T c17_y_x;
  real_T c17_ab_x;
  real_T c17_i_a;
  real_T c17_i_b;
  real_T c17_i_y;
  real_T c17_bb_x;
  real_T c17_cb_x;
  real_T c17_j_a;
  real_T c17_j_b;
  real_T c17_j_y;
  real_T c17_db_x;
  real_T c17_eb_x;
  real_T c17_k_a;
  real_T c17_k_b;
  real_T c17_k_y;
  real_T c17_fb_x;
  real_T c17_gb_x;
  real_T c17_hb_x;
  real_T c17_ib_x;
  real_T c17_l_a;
  real_T c17_l_b;
  real_T c17_l_y;
  real_T c17_jb_x;
  real_T c17_kb_x;
  real_T c17_m_a;
  real_T c17_m_b;
  real_T c17_m_y;
  real_T c17_lb_x;
  real_T c17_mb_x;
  real_T c17_nb_x;
  real_T c17_ob_x;
  real_T c17_n_a;
  real_T c17_n_b;
  real_T c17_n_y;
  real_T c17_pb_x;
  real_T c17_qb_x;
  real_T c17_o_a;
  real_T c17_o_b;
  real_T c17_o_y;
  real_T c17_rb_x;
  real_T c17_sb_x;
  real_T c17_tb_x;
  real_T c17_ub_x;
  real_T c17_p_a;
  real_T c17_p_b;
  real_T c17_p_y;
  real_T c17_vb_x;
  real_T c17_wb_x;
  real_T c17_q_a;
  real_T c17_q_b;
  real_T c17_q_y;
  real_T c17_xb_x;
  real_T c17_yb_x;
  real_T c17_r_a;
  real_T c17_r_b;
  real_T c17_r_y;
  real_T c17_ac_x;
  real_T c17_bc_x;
  real_T c17_cc_x;
  real_T c17_dc_x;
  real_T c17_s_a;
  real_T c17_s_b;
  real_T c17_s_y;
  real_T c17_ec_x;
  real_T c17_fc_x;
  real_T c17_t_a;
  real_T c17_t_b;
  real_T c17_t_y;
  real_T c17_gc_x;
  real_T c17_hc_x;
  real_T c17_ic_x;
  real_T c17_jc_x;
  real_T c17_u_a;
  real_T c17_u_b;
  real_T c17_u_y;
  real_T c17_kc_x;
  real_T c17_lc_x;
  real_T c17_v_a;
  real_T c17_v_b;
  real_T c17_v_y;
  real_T c17_mc_x;
  real_T c17_nc_x;
  real_T c17_w_a;
  real_T c17_w_b;
  real_T c17_w_y;
  real_T c17_oc_x;
  real_T c17_pc_x;
  real_T c17_x_a;
  real_T c17_x_b;
  real_T c17_x_y;
  real_T c17_qc_x;
  real_T c17_rc_x;
  real_T c17_sc_x;
  real_T c17_tc_x;
  real_T c17_y_a;
  real_T c17_y_b;
  real_T c17_y_y;
  real_T c17_uc_x;
  real_T c17_vc_x;
  real_T c17_ab_a;
  real_T c17_ab_b;
  real_T c17_ab_y;
  real_T c17_wc_x;
  real_T c17_xc_x;
  real_T c17_yc_x;
  real_T c17_ad_x;
  real_T c17_bb_a;
  real_T c17_bb_b;
  real_T c17_bb_y;
  real_T c17_bd_x;
  real_T c17_cd_x;
  real_T c17_cb_a;
  real_T c17_cb_b;
  real_T c17_cb_y;
  real_T c17_dd_x;
  real_T c17_ed_x;
  real_T c17_db_a;
  real_T c17_db_b;
  real_T c17_db_y;
  real_T c17_fd_x;
  real_T c17_gd_x;
  real_T c17_hd_x;
  real_T c17_id_x;
  real_T c17_eb_a;
  real_T c17_eb_b;
  real_T c17_eb_y;
  real_T c17_jd_x;
  real_T c17_kd_x;
  real_T c17_fb_a;
  real_T c17_fb_b;
  real_T c17_fb_y;
  real_T c17_ld_x;
  real_T c17_md_x;
  real_T c17_nd_x;
  real_T c17_od_x;
  real_T c17_gb_a;
  real_T c17_gb_b;
  real_T c17_gb_y;
  real_T c17_pd_x;
  real_T c17_qd_x;
  real_T c17_hb_a;
  real_T c17_hb_b;
  real_T c17_hb_y;
  real_T c17_rd_x;
  real_T c17_sd_x;
  real_T c17_ib_a;
  real_T c17_ib_b;
  real_T c17_ib_y;
  real_T c17_td_x;
  real_T c17_ud_x;
  real_T c17_jb_a;
  real_T c17_jb_b;
  real_T c17_jb_y;
  real_T c17_vd_x;
  real_T c17_wd_x;
  real_T c17_xd_x;
  real_T c17_yd_x;
  real_T c17_kb_a;
  real_T c17_kb_b;
  real_T c17_kb_y;
  real_T c17_ae_x;
  real_T c17_be_x;
  real_T c17_lb_a;
  real_T c17_lb_b;
  real_T c17_lb_y;
  real_T c17_ce_x;
  real_T c17_de_x;
  real_T c17_ee_x;
  real_T c17_fe_x;
  real_T c17_mb_a;
  real_T c17_mb_b;
  real_T c17_mb_y;
  real_T c17_ge_x;
  real_T c17_he_x;
  real_T c17_nb_a;
  real_T c17_nb_b;
  real_T c17_nb_y;
  real_T c17_ie_x;
  real_T c17_je_x;
  real_T c17_ke_x;
  real_T c17_le_x;
  real_T c17_ob_a;
  real_T c17_ob_b;
  real_T c17_ob_y;
  real_T c17_me_x;
  real_T c17_ne_x;
  real_T c17_pb_a;
  real_T c17_pb_b;
  real_T c17_pb_y;
  real_T c17_oe_x;
  real_T c17_pe_x;
  real_T c17_qb_a;
  real_T c17_qb_b;
  real_T c17_qb_y;
  real_T c17_qe_x;
  real_T c17_re_x;
  real_T c17_se_x;
  real_T c17_te_x;
  real_T c17_rb_a;
  real_T c17_rb_b;
  real_T c17_rb_y;
  real_T c17_ue_x;
  real_T c17_ve_x;
  real_T c17_sb_a;
  real_T c17_sb_b;
  real_T c17_sb_y;
  real_T c17_we_x;
  real_T c17_xe_x;
  real_T c17_ye_x;
  real_T c17_af_x;
  real_T c17_tb_a;
  real_T c17_tb_b;
  real_T c17_tb_y;
  real_T c17_bf_x;
  real_T c17_cf_x;
  real_T c17_ub_a;
  real_T c17_ub_b;
  real_T c17_ub_y;
  real_T c17_df_x;
  real_T c17_ef_x;
  real_T c17_vb_a;
  real_T c17_vb_b;
  real_T c17_vb_y;
  real_T c17_ff_x;
  real_T c17_gf_x;
  real_T c17_wb_a;
  real_T c17_wb_b;
  real_T c17_wb_y;
  real_T c17_hf_x;
  real_T c17_if_x;
  real_T c17_jf_x;
  real_T c17_kf_x;
  real_T c17_xb_a;
  real_T c17_xb_b;
  real_T c17_xb_y;
  real_T c17_lf_x;
  real_T c17_mf_x;
  real_T c17_yb_a;
  real_T c17_yb_b;
  real_T c17_yb_y;
  real_T c17_nf_x;
  real_T c17_of_x;
  real_T c17_pf_x;
  real_T c17_qf_x;
  real_T c17_ac_a;
  real_T c17_ac_b;
  real_T c17_ac_y;
  real_T c17_rf_x;
  real_T c17_sf_x;
  real_T c17_bc_a;
  real_T c17_bc_b;
  real_T c17_bc_y;
  real_T c17_tf_x;
  real_T c17_uf_x;
  real_T c17_cc_a;
  real_T c17_cc_b;
  real_T c17_cc_y;
  real_T c17_vf_x;
  real_T c17_wf_x;
  real_T c17_xf_x;
  real_T c17_yf_x;
  real_T c17_dc_a;
  real_T c17_dc_b;
  real_T c17_dc_y;
  real_T c17_ag_x;
  real_T c17_bg_x;
  real_T c17_ec_a;
  real_T c17_ec_b;
  real_T c17_ec_y;
  real_T c17_cg_x;
  real_T c17_dg_x;
  real_T c17_eg_x;
  real_T c17_fg_x;
  real_T c17_fc_a;
  real_T c17_fc_b;
  real_T c17_fc_y;
  real_T c17_gg_x;
  real_T c17_hg_x;
  real_T c17_gc_a;
  real_T c17_gc_b;
  real_T c17_gc_y;
  real_T c17_ig_x;
  real_T c17_jg_x;
  real_T c17_hc_a;
  real_T c17_hc_b;
  real_T c17_hc_y;
  real_T c17_kg_x;
  real_T c17_lg_x;
  real_T c17_ic_a;
  real_T c17_ic_b;
  real_T c17_ic_y;
  real_T c17_mg_x;
  real_T c17_ng_x;
  real_T c17_og_x;
  real_T c17_pg_x;
  real_T c17_jc_a;
  real_T c17_jc_b;
  real_T c17_jc_y;
  real_T c17_qg_x;
  real_T c17_rg_x;
  real_T c17_sg_x;
  real_T c17_tg_x;
  real_T c17_kc_a;
  real_T c17_kc_b;
  real_T c17_kc_y;
  real_T c17_ug_x;
  real_T c17_vg_x;
  real_T c17_lc_a;
  real_T c17_lc_b;
  real_T c17_lc_y;
  real_T c17_wg_x;
  real_T c17_xg_x;
  real_T c17_yg_x;
  real_T c17_ah_x;
  real_T c17_mc_a;
  real_T c17_mc_b;
  real_T c17_mc_y;
  real_T c17_bh_x;
  real_T c17_ch_x;
  real_T c17_nc_a;
  real_T c17_nc_b;
  real_T c17_nc_y;
  real_T c17_dh_x;
  real_T c17_eh_x;
  real_T c17_oc_a;
  real_T c17_oc_b;
  real_T c17_oc_y;
  real_T c17_fh_x;
  real_T c17_gh_x;
  real_T c17_hh_x;
  real_T c17_ih_x;
  real_T c17_pc_a;
  real_T c17_pc_b;
  real_T c17_pc_y;
  real_T c17_jh_x;
  real_T c17_kh_x;
  real_T c17_qc_a;
  real_T c17_qc_b;
  real_T c17_qc_y;
  real_T c17_lh_x;
  real_T c17_mh_x;
  real_T c17_nh_x;
  real_T c17_oh_x;
  real_T c17_rc_a;
  real_T c17_rc_b;
  real_T c17_rc_y;
  real_T c17_ph_x;
  real_T c17_qh_x;
  real_T c17_sc_a;
  real_T c17_sc_b;
  real_T c17_sc_y;
  real_T c17_rh_x;
  real_T c17_sh_x;
  real_T c17_tc_a;
  real_T c17_tc_b;
  real_T c17_tc_y;
  real_T c17_uc_b;
  real_T c17_uc_y;
  real_T c17_th_x;
  real_T c17_uh_x;
  real_T c17_uc_a;
  real_T c17_vc_b;
  real_T c17_vc_y;
  real_T c17_vh_x;
  real_T c17_wh_x;
  real_T c17_wc_b;
  real_T c17_wc_y;
  real_T c17_xh_x;
  real_T c17_yh_x;
  real_T c17_vc_a;
  real_T c17_xc_b;
  real_T c17_xc_y;
  real_T c17_ai_x;
  real_T c17_bi_x;
  real_T c17_ci_x;
  real_T c17_di_x;
  real_T c17_wc_a;
  real_T c17_yc_b;
  real_T c17_yc_y;
  real_T c17_ei_x;
  real_T c17_fi_x;
  real_T c17_xc_a;
  real_T c17_ad_b;
  real_T c17_ad_y;
  real_T c17_gi_x;
  real_T c17_hi_x;
  real_T c17_ii_x;
  real_T c17_ji_x;
  real_T c17_yc_a;
  real_T c17_bd_b;
  real_T c17_bd_y;
  real_T c17_ki_x;
  real_T c17_li_x;
  real_T c17_ad_a;
  real_T c17_cd_b;
  real_T c17_cd_y;
  real_T c17_dd_b;
  real_T c17_dd_y;
  real_T c17_mi_x;
  real_T c17_ni_x;
  real_T c17_bd_a;
  real_T c17_ed_b;
  real_T c17_ed_y;
  real_T c17_oi_x;
  real_T c17_pi_x;
  real_T c17_qi_x;
  real_T c17_ri_x;
  real_T c17_cd_a;
  real_T c17_fd_b;
  real_T c17_fd_y;
  real_T c17_si_x;
  real_T c17_ti_x;
  real_T c17_dd_a;
  real_T c17_gd_b;
  real_T c17_gd_y;
  real_T c17_ui_x;
  real_T c17_vi_x;
  real_T c17_wi_x;
  real_T c17_xi_x;
  real_T c17_ed_a;
  real_T c17_hd_b;
  real_T c17_hd_y;
  real_T c17_yi_x;
  real_T c17_aj_x;
  real_T c17_fd_a;
  real_T c17_id_b;
  real_T c17_id_y;
  real_T c17_jd_b;
  real_T c17_jd_y;
  real_T c17_bj_x;
  real_T c17_cj_x;
  real_T c17_gd_a;
  real_T c17_kd_b;
  real_T c17_kd_y;
  real_T c17_dj_x;
  real_T c17_ej_x;
  real_T c17_ld_b;
  real_T c17_ld_y;
  real_T c17_fj_x;
  real_T c17_gj_x;
  real_T c17_md_b;
  real_T c17_md_y;
  real_T c17_hj_x;
  real_T c17_ij_x;
  real_T c17_hd_a;
  real_T c17_nd_b;
  real_T c17_nd_y;
  real_T c17_jj_x;
  real_T c17_kj_x;
  real_T c17_id_a;
  real_T c17_od_b;
  real_T c17_od_y;
  real_T c17_lj_x;
  real_T c17_mj_x;
  real_T c17_pd_b;
  real_T c17_pd_y;
  real_T c17_nj_x;
  real_T c17_oj_x;
  real_T c17_jd_a;
  real_T c17_qd_b;
  real_T c17_qd_y;
  real_T c17_pj_x;
  real_T c17_qj_x;
  real_T c17_kd_a;
  real_T c17_rd_b;
  real_T c17_rd_y;
  real_T c17_rj_x;
  real_T c17_sj_x;
  real_T c17_sd_b;
  real_T c17_sd_y;
  real_T c17_tj_x;
  real_T c17_uj_x;
  real_T c17_ld_a;
  real_T c17_td_b;
  real_T c17_td_y;
  real_T c17_vj_x;
  real_T c17_wj_x;
  real_T c17_xj_x;
  real_T c17_yj_x;
  real_T c17_md_a;
  real_T c17_ud_b;
  real_T c17_ud_y;
  real_T c17_ak_x;
  real_T c17_bk_x;
  real_T c17_nd_a;
  real_T c17_vd_b;
  real_T c17_vd_y;
  real_T c17_ck_x;
  real_T c17_dk_x;
  real_T c17_ek_x;
  real_T c17_fk_x;
  real_T c17_od_a;
  real_T c17_wd_b;
  real_T c17_wd_y;
  real_T c17_gk_x;
  real_T c17_hk_x;
  real_T c17_pd_a;
  real_T c17_xd_b;
  real_T c17_xd_y;
  real_T c17_ik_x;
  real_T c17_jk_x;
  real_T c17_qd_a;
  real_T c17_yd_b;
  real_T c17_yd_y;
  real_T c17_kk_x;
  real_T c17_lk_x;
  real_T c17_mk_x;
  real_T c17_nk_x;
  real_T c17_rd_a;
  real_T c17_ae_b;
  real_T c17_ae_y;
  real_T c17_ok_x;
  real_T c17_pk_x;
  real_T c17_sd_a;
  real_T c17_be_b;
  real_T c17_be_y;
  real_T c17_qk_x;
  real_T c17_rk_x;
  real_T c17_sk_x;
  real_T c17_tk_x;
  real_T c17_td_a;
  real_T c17_ce_b;
  real_T c17_ce_y;
  real_T c17_uk_x;
  real_T c17_vk_x;
  real_T c17_ud_a;
  real_T c17_de_b;
  real_T c17_de_y;
  real_T c17_wk_x;
  real_T c17_xk_x;
  real_T c17_vd_a;
  real_T c17_ee_b;
  real_T c17_ee_y;
  real_T c17_yk_x;
  real_T c17_al_x;
  real_T c17_wd_a;
  real_T c17_fe_b;
  real_T c17_fe_y;
  real_T c17_bl_x;
  real_T c17_cl_x;
  real_T c17_dl_x;
  real_T c17_el_x;
  real_T c17_xd_a;
  real_T c17_ge_b;
  real_T c17_ge_y;
  real_T c17_fl_x;
  real_T c17_gl_x;
  real_T c17_yd_a;
  real_T c17_he_b;
  real_T c17_he_y;
  real_T c17_hl_x;
  real_T c17_il_x;
  real_T c17_jl_x;
  real_T c17_kl_x;
  real_T c17_ae_a;
  real_T c17_ie_b;
  real_T c17_ie_y;
  real_T c17_ll_x;
  real_T c17_ml_x;
  real_T c17_be_a;
  real_T c17_je_b;
  real_T c17_je_y;
  real_T c17_nl_x;
  real_T c17_ol_x;
  real_T c17_pl_x;
  real_T c17_ql_x;
  real_T c17_ce_a;
  real_T c17_ke_b;
  real_T c17_ke_y;
  real_T c17_rl_x;
  real_T c17_sl_x;
  real_T c17_de_a;
  real_T c17_le_b;
  real_T c17_le_y;
  real_T c17_tl_x;
  real_T c17_ul_x;
  real_T c17_ee_a;
  real_T c17_me_b;
  real_T c17_me_y;
  real_T c17_vl_x;
  real_T c17_wl_x;
  real_T c17_xl_x;
  real_T c17_yl_x;
  real_T c17_fe_a;
  real_T c17_ne_b;
  real_T c17_ne_y;
  real_T c17_am_x;
  real_T c17_bm_x;
  real_T c17_ge_a;
  real_T c17_oe_b;
  real_T c17_oe_y;
  real_T c17_cm_x;
  real_T c17_dm_x;
  real_T c17_em_x;
  real_T c17_fm_x;
  real_T c17_he_a;
  real_T c17_pe_b;
  real_T c17_pe_y;
  real_T c17_gm_x;
  real_T c17_hm_x;
  real_T c17_ie_a;
  real_T c17_qe_b;
  real_T c17_qe_y;
  real_T c17_im_x;
  real_T c17_jm_x;
  real_T c17_je_a;
  real_T c17_re_b;
  real_T c17_re_y;
  real_T c17_km_x;
  real_T c17_lm_x;
  real_T c17_ke_a;
  real_T c17_se_b;
  real_T c17_se_y;
  real_T c17_mm_x;
  real_T c17_nm_x;
  real_T c17_om_x;
  real_T c17_pm_x;
  real_T c17_le_a;
  real_T c17_te_b;
  real_T c17_te_y;
  real_T c17_qm_x;
  real_T c17_rm_x;
  real_T c17_me_a;
  real_T c17_ue_b;
  real_T c17_ue_y;
  real_T c17_sm_x;
  real_T c17_tm_x;
  real_T c17_um_x;
  real_T c17_vm_x;
  real_T c17_ne_a;
  real_T c17_ve_b;
  real_T c17_ve_y;
  real_T c17_wm_x;
  real_T c17_xm_x;
  real_T c17_oe_a;
  real_T c17_we_b;
  real_T c17_we_y;
  real_T c17_ym_x;
  real_T c17_an_x;
  real_T c17_pe_a;
  real_T c17_xe_b;
  real_T c17_xe_y;
  real_T c17_bn_x;
  real_T c17_cn_x;
  real_T c17_dn_x;
  real_T c17_en_x;
  real_T c17_qe_a;
  real_T c17_ye_b;
  real_T c17_ye_y;
  real_T c17_fn_x;
  real_T c17_gn_x;
  real_T c17_re_a;
  real_T c17_af_b;
  real_T c17_af_y;
  real_T c17_hn_x;
  real_T c17_in_x;
  real_T c17_jn_x;
  real_T c17_kn_x;
  real_T c17_se_a;
  real_T c17_bf_b;
  real_T c17_bf_y;
  real_T c17_ln_x;
  real_T c17_mn_x;
  real_T c17_te_a;
  real_T c17_cf_b;
  real_T c17_cf_y;
  real_T c17_nn_x;
  real_T c17_on_x;
  real_T c17_ue_a;
  real_T c17_df_b;
  real_T c17_df_y;
  real_T c17_pn_x;
  real_T c17_qn_x;
  real_T c17_ve_a;
  real_T c17_ef_b;
  real_T c17_ef_y;
  real_T c17_rn_x;
  real_T c17_sn_x;
  real_T c17_tn_x;
  real_T c17_un_x;
  real_T c17_we_a;
  real_T c17_ff_b;
  real_T c17_ff_y;
  real_T c17_vn_x;
  real_T c17_wn_x;
  real_T c17_xe_a;
  real_T c17_gf_b;
  real_T c17_gf_y;
  real_T c17_xn_x;
  real_T c17_yn_x;
  real_T c17_ao_x;
  real_T c17_bo_x;
  real_T c17_ye_a;
  real_T c17_hf_b;
  real_T c17_hf_y;
  real_T c17_co_x;
  real_T c17_do_x;
  real_T c17_af_a;
  real_T c17_if_b;
  real_T c17_if_y;
  real_T c17_eo_x;
  real_T c17_fo_x;
  real_T c17_go_x;
  real_T c17_ho_x;
  real_T c17_bf_a;
  real_T c17_jf_b;
  real_T c17_jf_y;
  real_T c17_io_x;
  real_T c17_jo_x;
  real_T c17_cf_a;
  real_T c17_kf_b;
  real_T c17_kf_y;
  real_T c17_ko_x;
  real_T c17_lo_x;
  real_T c17_df_a;
  real_T c17_lf_b;
  real_T c17_lf_y;
  real_T c17_mo_x;
  real_T c17_no_x;
  real_T c17_oo_x;
  real_T c17_po_x;
  real_T c17_ef_a;
  real_T c17_mf_b;
  real_T c17_mf_y;
  real_T c17_qo_x;
  real_T c17_ro_x;
  real_T c17_ff_a;
  real_T c17_nf_b;
  real_T c17_nf_y;
  real_T c17_so_x;
  real_T c17_to_x;
  real_T c17_uo_x;
  real_T c17_vo_x;
  real_T c17_gf_a;
  real_T c17_of_b;
  real_T c17_of_y;
  real_T c17_wo_x;
  real_T c17_xo_x;
  real_T c17_hf_a;
  real_T c17_pf_b;
  real_T c17_pf_y;
  real_T c17_yo_x;
  real_T c17_ap_x;
  real_T c17_if_a;
  real_T c17_qf_b;
  real_T c17_qf_y;
  real_T c17_bp_x;
  real_T c17_cp_x;
  real_T c17_jf_a;
  real_T c17_rf_b;
  real_T c17_rf_y;
  real_T c17_dp_x;
  real_T c17_ep_x;
  real_T c17_fp_x;
  real_T c17_gp_x;
  real_T c17_kf_a;
  real_T c17_sf_b;
  real_T c17_sf_y;
  real_T c17_hp_x;
  real_T c17_ip_x;
  real_T c17_lf_a;
  real_T c17_tf_b;
  real_T c17_tf_y;
  real_T c17_jp_x;
  real_T c17_kp_x;
  real_T c17_lp_x;
  real_T c17_mp_x;
  real_T c17_mf_a;
  real_T c17_uf_b;
  real_T c17_uf_y;
  real_T c17_np_x;
  real_T c17_op_x;
  real_T c17_nf_a;
  real_T c17_vf_b;
  real_T c17_vf_y;
  real_T c17_pp_x;
  real_T c17_qp_x;
  real_T c17_of_a;
  real_T c17_wf_b;
  real_T c17_wf_y;
  real_T c17_rp_x;
  real_T c17_sp_x;
  real_T c17_tp_x;
  real_T c17_up_x;
  real_T c17_pf_a;
  real_T c17_xf_b;
  real_T c17_xf_y;
  real_T c17_vp_x;
  real_T c17_wp_x;
  real_T c17_qf_a;
  real_T c17_yf_b;
  real_T c17_yf_y;
  real_T c17_xp_x;
  real_T c17_yp_x;
  real_T c17_aq_x;
  real_T c17_bq_x;
  real_T c17_rf_a;
  real_T c17_ag_b;
  real_T c17_ag_y;
  real_T c17_cq_x;
  real_T c17_dq_x;
  real_T c17_sf_a;
  real_T c17_bg_b;
  real_T c17_bg_y;
  real_T c17_eq_x;
  real_T c17_fq_x;
  real_T c17_tf_a;
  real_T c17_cg_b;
  real_T c17_cg_y;
  real_T c17_gq_x;
  real_T c17_hq_x;
  real_T c17_uf_a;
  real_T c17_dg_b;
  real_T c17_dg_y;
  real_T c17_iq_x;
  real_T c17_jq_x;
  real_T c17_kq_x;
  real_T c17_lq_x;
  real_T c17_vf_a;
  real_T c17_eg_b;
  real_T c17_eg_y;
  real_T c17_mq_x;
  real_T c17_nq_x;
  real_T c17_oq_x;
  real_T c17_pq_x;
  real_T c17_wf_a;
  real_T c17_fg_b;
  real_T c17_fg_y;
  real_T c17_qq_x;
  real_T c17_rq_x;
  real_T c17_xf_a;
  real_T c17_gg_b;
  real_T c17_gg_y;
  real_T c17_sq_x;
  real_T c17_tq_x;
  real_T c17_uq_x;
  real_T c17_vq_x;
  real_T c17_yf_a;
  real_T c17_hg_b;
  real_T c17_hg_y;
  real_T c17_wq_x;
  real_T c17_xq_x;
  real_T c17_ag_a;
  real_T c17_ig_b;
  real_T c17_ig_y;
  real_T c17_yq_x;
  real_T c17_ar_x;
  real_T c17_bg_a;
  real_T c17_jg_b;
  real_T c17_jg_y;
  real_T c17_br_x;
  real_T c17_cr_x;
  real_T c17_dr_x;
  real_T c17_er_x;
  real_T c17_cg_a;
  real_T c17_kg_b;
  real_T c17_kg_y;
  real_T c17_fr_x;
  real_T c17_gr_x;
  real_T c17_dg_a;
  real_T c17_lg_b;
  real_T c17_lg_y;
  real_T c17_hr_x;
  real_T c17_ir_x;
  real_T c17_jr_x;
  real_T c17_kr_x;
  real_T c17_eg_a;
  real_T c17_mg_b;
  real_T c17_mg_y;
  real_T c17_lr_x;
  real_T c17_mr_x;
  real_T c17_fg_a;
  real_T c17_ng_b;
  real_T c17_ng_y;
  real_T c17_nr_x;
  real_T c17_or_x;
  real_T c17_gg_a;
  real_T c17_og_b;
  real_T c17_og_y;
  real_T c17_pg_b;
  real_T c17_pg_y;
  real_T c17_pr_x;
  real_T c17_qr_x;
  real_T c17_hg_a;
  real_T c17_qg_b;
  real_T c17_qg_y;
  real_T c17_rr_x;
  real_T c17_sr_x;
  real_T c17_rg_b;
  real_T c17_rg_y;
  real_T c17_tr_x;
  real_T c17_ur_x;
  real_T c17_ig_a;
  real_T c17_sg_b;
  real_T c17_sg_y;
  real_T c17_vr_x;
  real_T c17_wr_x;
  real_T c17_xr_x;
  real_T c17_yr_x;
  real_T c17_jg_a;
  real_T c17_tg_b;
  real_T c17_tg_y;
  real_T c17_as_x;
  real_T c17_bs_x;
  real_T c17_kg_a;
  real_T c17_ug_b;
  real_T c17_ug_y;
  real_T c17_cs_x;
  real_T c17_ds_x;
  real_T c17_es_x;
  real_T c17_fs_x;
  real_T c17_lg_a;
  real_T c17_vg_b;
  real_T c17_vg_y;
  real_T c17_gs_x;
  real_T c17_hs_x;
  real_T c17_mg_a;
  real_T c17_wg_b;
  real_T c17_wg_y;
  real_T c17_xg_b;
  real_T c17_xg_y;
  real_T c17_is_x;
  real_T c17_js_x;
  real_T c17_ng_a;
  real_T c17_yg_b;
  real_T c17_yg_y;
  real_T c17_ks_x;
  real_T c17_ls_x;
  real_T c17_ms_x;
  real_T c17_ns_x;
  real_T c17_og_a;
  real_T c17_ah_b;
  real_T c17_ah_y;
  real_T c17_os_x;
  real_T c17_ps_x;
  real_T c17_pg_a;
  real_T c17_bh_b;
  real_T c17_bh_y;
  real_T c17_qs_x;
  real_T c17_rs_x;
  real_T c17_ss_x;
  real_T c17_ts_x;
  real_T c17_qg_a;
  real_T c17_ch_b;
  real_T c17_ch_y;
  real_T c17_us_x;
  real_T c17_vs_x;
  real_T c17_rg_a;
  real_T c17_dh_b;
  real_T c17_dh_y;
  real_T c17_eh_b;
  real_T c17_eh_y;
  real_T c17_ws_x;
  real_T c17_xs_x;
  real_T c17_sg_a;
  real_T c17_fh_b;
  real_T c17_fh_y;
  real_T c17_ys_x;
  real_T c17_at_x;
  real_T c17_gh_b;
  real_T c17_gh_y;
  real_T c17_bt_x;
  real_T c17_ct_x;
  real_T c17_hh_b;
  real_T c17_hh_y;
  real_T c17_dt_x;
  real_T c17_et_x;
  real_T c17_tg_a;
  real_T c17_ih_b;
  real_T c17_ih_y;
  real_T c17_ft_x;
  real_T c17_gt_x;
  real_T c17_ug_a;
  real_T c17_jh_b;
  real_T c17_jh_y;
  real_T c17_ht_x;
  real_T c17_it_x;
  real_T c17_kh_b;
  real_T c17_kh_y;
  real_T c17_jt_x;
  real_T c17_kt_x;
  real_T c17_vg_a;
  real_T c17_lh_b;
  real_T c17_lh_y;
  real_T c17_lt_x;
  real_T c17_mt_x;
  real_T c17_wg_a;
  real_T c17_mh_b;
  real_T c17_mh_y;
  real_T c17_nt_x;
  real_T c17_ot_x;
  real_T c17_nh_b;
  real_T c17_nh_y;
  real_T c17_pt_x;
  real_T c17_qt_x;
  real_T c17_xg_a;
  real_T c17_oh_b;
  real_T c17_oh_y;
  real_T c17_rt_x;
  real_T c17_st_x;
  real_T c17_tt_x;
  real_T c17_ut_x;
  real_T c17_yg_a;
  real_T c17_ph_b;
  real_T c17_ph_y;
  real_T c17_vt_x;
  real_T c17_wt_x;
  real_T c17_xt_x;
  real_T c17_yt_x;
  real_T c17_ah_a;
  real_T c17_qh_b;
  real_T c17_qh_y;
  real_T c17_au_x;
  real_T c17_bu_x;
  real_T c17_bh_a;
  real_T c17_rh_b;
  real_T c17_rh_y;
  real_T c17_cu_x;
  real_T c17_du_x;
  real_T c17_eu_x;
  real_T c17_fu_x;
  real_T c17_ch_a;
  real_T c17_sh_b;
  real_T c17_sh_y;
  real_T c17_gu_x;
  real_T c17_hu_x;
  real_T c17_iu_x;
  real_T c17_ju_x;
  real_T c17_dh_a;
  real_T c17_th_b;
  real_T c17_th_y;
  real_T c17_ku_x;
  real_T c17_lu_x;
  real_T c17_eh_a;
  real_T c17_uh_b;
  real_T c17_uh_y;
  real_T c17_mu_x;
  real_T c17_nu_x;
  real_T c17_fh_a;
  real_T c17_vh_b;
  real_T c17_vh_y;
  real_T c17_ou_x;
  real_T c17_pu_x;
  real_T c17_gh_a;
  real_T c17_wh_b;
  real_T c17_wh_y;
  real_T c17_qu_x;
  real_T c17_ru_x;
  real_T c17_su_x;
  real_T c17_tu_x;
  real_T c17_hh_a;
  real_T c17_xh_b;
  real_T c17_xh_y;
  real_T c17_uu_x;
  real_T c17_vu_x;
  real_T c17_wu_x;
  real_T c17_xu_x;
  real_T c17_ih_a;
  real_T c17_yh_b;
  real_T c17_yh_y;
  real_T c17_yu_x;
  real_T c17_av_x;
  real_T c17_jh_a;
  real_T c17_ai_b;
  real_T c17_ai_y;
  real_T c17_bv_x;
  real_T c17_cv_x;
  real_T c17_dv_x;
  real_T c17_ev_x;
  real_T c17_kh_a;
  real_T c17_bi_b;
  real_T c17_bi_y;
  real_T c17_fv_x;
  real_T c17_gv_x;
  real_T c17_hv_x;
  real_T c17_iv_x;
  real_T c17_lh_a;
  real_T c17_ci_b;
  real_T c17_ci_y;
  real_T c17_jv_x;
  real_T c17_kv_x;
  real_T c17_mh_a;
  real_T c17_di_b;
  real_T c17_di_y;
  real_T c17_lv_x;
  real_T c17_mv_x;
  real_T c17_nh_a;
  real_T c17_ei_b;
  real_T c17_ei_y;
  real_T c17_nv_x;
  real_T c17_ov_x;
  real_T c17_pv_x;
  real_T c17_qv_x;
  real_T c17_oh_a;
  real_T c17_fi_b;
  real_T c17_fi_y;
  real_T c17_rv_x;
  real_T c17_sv_x;
  real_T c17_tv_x;
  real_T c17_uv_x;
  real_T c17_ph_a;
  real_T c17_gi_b;
  real_T c17_gi_y;
  real_T c17_vv_x;
  real_T c17_wv_x;
  real_T c17_qh_a;
  real_T c17_hi_b;
  real_T c17_hi_y;
  real_T c17_xv_x;
  real_T c17_yv_x;
  real_T c17_aw_x;
  real_T c17_bw_x;
  real_T c17_rh_a;
  real_T c17_ii_b;
  real_T c17_ii_y;
  real_T c17_cw_x;
  real_T c17_dw_x;
  real_T c17_ew_x;
  real_T c17_fw_x;
  real_T c17_sh_a;
  real_T c17_ji_b;
  real_T c17_ji_y;
  real_T c17_gw_x;
  real_T c17_hw_x;
  real_T c17_th_a;
  real_T c17_ki_b;
  real_T c17_ki_y;
  real_T c17_iw_x;
  real_T c17_jw_x;
  real_T c17_uh_a;
  real_T c17_li_b;
  real_T c17_li_y;
  real_T c17_kw_x;
  real_T c17_lw_x;
  real_T c17_vh_a;
  real_T c17_mi_b;
  real_T c17_mi_y;
  real_T c17_mw_x;
  real_T c17_nw_x;
  real_T c17_ow_x;
  real_T c17_pw_x;
  real_T c17_wh_a;
  real_T c17_ni_b;
  real_T c17_ni_y;
  real_T c17_qw_x;
  real_T c17_rw_x;
  real_T c17_sw_x;
  real_T c17_tw_x;
  real_T c17_xh_a;
  real_T c17_oi_b;
  real_T c17_oi_y;
  real_T c17_uw_x;
  real_T c17_vw_x;
  real_T c17_yh_a;
  real_T c17_pi_b;
  real_T c17_pi_y;
  real_T c17_ww_x;
  real_T c17_xw_x;
  real_T c17_yw_x;
  real_T c17_ax_x;
  real_T c17_ai_a;
  real_T c17_qi_b;
  real_T c17_qi_y;
  real_T c17_bx_x;
  real_T c17_cx_x;
  real_T c17_dx_x;
  real_T c17_ex_x;
  real_T c17_bi_a;
  real_T c17_ri_b;
  real_T c17_ri_y;
  real_T c17_fx_x;
  real_T c17_gx_x;
  real_T c17_ci_a;
  real_T c17_si_b;
  real_T c17_si_y;
  real_T c17_hx_x;
  real_T c17_ix_x;
  real_T c17_di_a;
  real_T c17_ti_b;
  real_T c17_ti_y;
  real_T c17_jx_x;
  real_T c17_kx_x;
  real_T c17_lx_x;
  real_T c17_mx_x;
  real_T c17_ei_a;
  real_T c17_ui_b;
  real_T c17_ui_y;
  real_T c17_nx_x;
  real_T c17_ox_x;
  real_T c17_px_x;
  real_T c17_qx_x;
  real_T c17_fi_a;
  real_T c17_vi_b;
  real_T c17_vi_y;
  real_T c17_rx_x;
  real_T c17_sx_x;
  real_T c17_gi_a;
  real_T c17_wi_b;
  real_T c17_wi_y;
  real_T c17_tx_x;
  real_T c17_ux_x;
  real_T c17_vx_x;
  real_T c17_wx_x;
  real_T c17_hi_a;
  real_T c17_xi_b;
  real_T c17_xi_y;
  real_T c17_xx_x;
  real_T c17_yx_x;
  real_T c17_ay_x;
  real_T c17_by_x;
  real_T c17_ii_a;
  real_T c17_yi_b;
  real_T c17_yi_y;
  real_T c17_cy_x;
  real_T c17_dy_x;
  real_T c17_ji_a;
  real_T c17_aj_b;
  real_T c17_aj_y;
  real_T c17_ey_x;
  real_T c17_fy_x;
  real_T c17_ki_a;
  real_T c17_bj_b;
  real_T c17_bj_y;
  real_T c17_gy_x;
  real_T c17_hy_x;
  real_T c17_iy_x;
  real_T c17_jy_x;
  real_T c17_li_a;
  real_T c17_cj_b;
  real_T c17_cj_y;
  real_T c17_ky_x;
  real_T c17_ly_x;
  real_T c17_my_x;
  real_T c17_ny_x;
  real_T c17_mi_a;
  real_T c17_dj_b;
  real_T c17_dj_y;
  real_T c17_oy_x;
  real_T c17_py_x;
  real_T c17_ni_a;
  real_T c17_ej_b;
  real_T c17_ej_y;
  real_T c17_qy_x;
  real_T c17_ry_x;
  real_T c17_sy_x;
  real_T c17_ty_x;
  real_T c17_oi_a;
  real_T c17_fj_b;
  real_T c17_fj_y;
  real_T c17_uy_x;
  real_T c17_vy_x;
  real_T c17_wy_x;
  real_T c17_xy_x;
  real_T c17_pi_a;
  real_T c17_gj_b;
  real_T c17_gj_y;
  real_T c17_yy_x;
  real_T c17_aab_x;
  real_T c17_qi_a;
  real_T c17_hj_b;
  real_T c17_hj_y;
  real_T c17_ij_b;
  real_T c17_ij_y;
  real_T c17_bab_x;
  real_T c17_cab_x;
  real_T c17_ri_a;
  real_T c17_jj_b;
  real_T c17_jj_y;
  real_T c17_dab_x;
  real_T c17_eab_x;
  real_T c17_fab_x;
  real_T c17_gab_x;
  real_T c17_si_a;
  real_T c17_kj_b;
  real_T c17_kj_y;
  real_T c17_hab_x;
  real_T c17_iab_x;
  real_T c17_jab_x;
  real_T c17_kab_x;
  real_T c17_ti_a;
  real_T c17_lj_b;
  real_T c17_lj_y;
  real_T c17_mj_b;
  real_T c17_mj_y;
  real_T c17_lab_x;
  real_T c17_mab_x;
  real_T c17_ui_a;
  real_T c17_nj_b;
  real_T c17_nj_y;
  real_T c17_nab_x;
  real_T c17_oab_x;
  real_T c17_pab_x;
  real_T c17_qab_x;
  real_T c17_vi_a;
  real_T c17_oj_b;
  real_T c17_oj_y;
  real_T c17_rab_x;
  real_T c17_sab_x;
  real_T c17_tab_x;
  real_T c17_uab_x;
  real_T c17_wi_a;
  real_T c17_pj_b;
  real_T c17_pj_y;
  real_T c17_qj_b;
  real_T c17_qj_y;
  real_T c17_vab_x;
  real_T c17_wab_x;
  real_T c17_xi_a;
  real_T c17_rj_b;
  real_T c17_rj_y;
  real_T c17_xab_x;
  real_T c17_yab_x;
  real_T c17_sj_b;
  real_T c17_sj_y;
  real_T c17_abb_x;
  real_T c17_bbb_x;
  real_T c17_yi_a;
  real_T c17_tj_b;
  real_T c17_tj_y;
  real_T c17_cbb_x;
  real_T c17_dbb_x;
  real_T c17_uj_b;
  real_T c17_uj_y;
  real_T c17_ebb_x;
  real_T c17_fbb_x;
  real_T c17_aj_a;
  real_T c17_vj_b;
  real_T c17_vj_y;
  real_T c17_gbb_x;
  real_T c17_hbb_x;
  real_T c17_wj_b;
  real_T c17_wj_y;
  int32_T c17_i8;
  int32_T c17_i9;
  static real_T c17_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c17_i10;
  int32_T c17_i11;
  int32_T c17_i12;
  int32_T c17_i13;
  int32_T c17_i14;
  int32_T c17_i15;
  int32_T c17_i16;
  real_T (*c17_b_d)[3];
  real_T (*c17_b_R)[9];
  real_T (*c17_b_q)[6];
  c17_b_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c17_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c17_b_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c17_sfEvent);
  for (c17_i7 = 0; c17_i7 < 6; c17_i7++) {
    c17_q[c17_i7] = (*c17_b_q)[c17_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta1, 0U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta2, 1U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta3, 2U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta4, 3U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta5, 4U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta6, 5U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_T, 6U, c17_e_sf_marshallOut,
    c17_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 7U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 8U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_q, 9U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_d, 10U, c17_b_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_R, 11U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 7);
  c17_theta1 = c17_q[0];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 8);
  c17_theta2 = c17_q[1];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 9);
  c17_theta3 = c17_q[2];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 10);
  c17_theta4 = c17_q[3];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 11);
  c17_theta5 = c17_q[4];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 12);
  c17_theta6 = c17_q[5];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 14);
  c17_x = c17_theta1;
  c17_b_x = c17_x;
  c17_b_x = muDoubleScalarCos(c17_b_x);
  c17_c_x = c17_theta2;
  c17_d_x = c17_c_x;
  c17_d_x = muDoubleScalarCos(c17_d_x);
  c17_a = c17_b_x;
  c17_b = c17_d_x;
  c17_y = c17_a * c17_b;
  c17_e_x = c17_theta3;
  c17_f_x = c17_e_x;
  c17_f_x = muDoubleScalarCos(c17_f_x);
  c17_b_a = c17_y;
  c17_b_b = c17_f_x;
  c17_b_y = c17_b_a * c17_b_b;
  c17_g_x = c17_theta1;
  c17_h_x = c17_g_x;
  c17_h_x = muDoubleScalarCos(c17_h_x);
  c17_i_x = c17_theta2;
  c17_j_x = c17_i_x;
  c17_j_x = muDoubleScalarSin(c17_j_x);
  c17_c_a = c17_h_x;
  c17_c_b = c17_j_x;
  c17_c_y = c17_c_a * c17_c_b;
  c17_k_x = c17_theta3;
  c17_l_x = c17_k_x;
  c17_l_x = muDoubleScalarSin(c17_l_x);
  c17_d_a = c17_c_y;
  c17_d_b = c17_l_x;
  c17_d_y = c17_d_a * c17_d_b;
  c17_m_x = c17_theta4;
  c17_n_x = c17_m_x;
  c17_n_x = muDoubleScalarCos(c17_n_x);
  c17_e_a = c17_b_y - c17_d_y;
  c17_e_b = c17_n_x;
  c17_e_y = c17_e_a * c17_e_b;
  c17_o_x = c17_theta1;
  c17_p_x = c17_o_x;
  c17_p_x = muDoubleScalarCos(c17_p_x);
  c17_q_x = c17_theta2;
  c17_r_x = c17_q_x;
  c17_r_x = muDoubleScalarCos(c17_r_x);
  c17_f_a = -c17_p_x;
  c17_f_b = c17_r_x;
  c17_f_y = c17_f_a * c17_f_b;
  c17_s_x = c17_theta3;
  c17_t_x = c17_s_x;
  c17_t_x = muDoubleScalarSin(c17_t_x);
  c17_g_a = c17_f_y;
  c17_g_b = c17_t_x;
  c17_g_y = c17_g_a * c17_g_b;
  c17_u_x = c17_theta1;
  c17_v_x = c17_u_x;
  c17_v_x = muDoubleScalarCos(c17_v_x);
  c17_w_x = c17_theta2;
  c17_x_x = c17_w_x;
  c17_x_x = muDoubleScalarSin(c17_x_x);
  c17_h_a = c17_v_x;
  c17_h_b = c17_x_x;
  c17_h_y = c17_h_a * c17_h_b;
  c17_y_x = c17_theta3;
  c17_ab_x = c17_y_x;
  c17_ab_x = muDoubleScalarCos(c17_ab_x);
  c17_i_a = c17_h_y;
  c17_i_b = c17_ab_x;
  c17_i_y = c17_i_a * c17_i_b;
  c17_bb_x = c17_theta4;
  c17_cb_x = c17_bb_x;
  c17_cb_x = muDoubleScalarSin(c17_cb_x);
  c17_j_a = c17_g_y - c17_i_y;
  c17_j_b = c17_cb_x;
  c17_j_y = c17_j_a * c17_j_b;
  c17_db_x = c17_theta5;
  c17_eb_x = c17_db_x;
  c17_eb_x = muDoubleScalarCos(c17_eb_x);
  c17_k_a = c17_e_y + c17_j_y;
  c17_k_b = c17_eb_x;
  c17_k_y = c17_k_a * c17_k_b;
  c17_fb_x = c17_theta1;
  c17_gb_x = c17_fb_x;
  c17_gb_x = muDoubleScalarSin(c17_gb_x);
  c17_hb_x = c17_theta5;
  c17_ib_x = c17_hb_x;
  c17_ib_x = muDoubleScalarSin(c17_ib_x);
  c17_l_a = c17_gb_x;
  c17_l_b = c17_ib_x;
  c17_l_y = c17_l_a * c17_l_b;
  c17_jb_x = c17_theta6;
  c17_kb_x = c17_jb_x;
  c17_kb_x = muDoubleScalarCos(c17_kb_x);
  c17_m_a = c17_k_y + c17_l_y;
  c17_m_b = c17_kb_x;
  c17_m_y = c17_m_a * c17_m_b;
  c17_lb_x = c17_theta1;
  c17_mb_x = c17_lb_x;
  c17_mb_x = muDoubleScalarCos(c17_mb_x);
  c17_nb_x = c17_theta2;
  c17_ob_x = c17_nb_x;
  c17_ob_x = muDoubleScalarCos(c17_ob_x);
  c17_n_a = c17_mb_x;
  c17_n_b = c17_ob_x;
  c17_n_y = c17_n_a * c17_n_b;
  c17_pb_x = c17_theta3;
  c17_qb_x = c17_pb_x;
  c17_qb_x = muDoubleScalarCos(c17_qb_x);
  c17_o_a = c17_n_y;
  c17_o_b = c17_qb_x;
  c17_o_y = c17_o_a * c17_o_b;
  c17_rb_x = c17_theta1;
  c17_sb_x = c17_rb_x;
  c17_sb_x = muDoubleScalarCos(c17_sb_x);
  c17_tb_x = c17_theta2;
  c17_ub_x = c17_tb_x;
  c17_ub_x = muDoubleScalarSin(c17_ub_x);
  c17_p_a = c17_sb_x;
  c17_p_b = c17_ub_x;
  c17_p_y = c17_p_a * c17_p_b;
  c17_vb_x = c17_theta3;
  c17_wb_x = c17_vb_x;
  c17_wb_x = muDoubleScalarSin(c17_wb_x);
  c17_q_a = c17_p_y;
  c17_q_b = c17_wb_x;
  c17_q_y = c17_q_a * c17_q_b;
  c17_xb_x = c17_theta4;
  c17_yb_x = c17_xb_x;
  c17_yb_x = muDoubleScalarSin(c17_yb_x);
  c17_r_a = -(c17_o_y - c17_q_y);
  c17_r_b = c17_yb_x;
  c17_r_y = c17_r_a * c17_r_b;
  c17_ac_x = c17_theta1;
  c17_bc_x = c17_ac_x;
  c17_bc_x = muDoubleScalarCos(c17_bc_x);
  c17_cc_x = c17_theta2;
  c17_dc_x = c17_cc_x;
  c17_dc_x = muDoubleScalarCos(c17_dc_x);
  c17_s_a = -c17_bc_x;
  c17_s_b = c17_dc_x;
  c17_s_y = c17_s_a * c17_s_b;
  c17_ec_x = c17_theta3;
  c17_fc_x = c17_ec_x;
  c17_fc_x = muDoubleScalarSin(c17_fc_x);
  c17_t_a = c17_s_y;
  c17_t_b = c17_fc_x;
  c17_t_y = c17_t_a * c17_t_b;
  c17_gc_x = c17_theta1;
  c17_hc_x = c17_gc_x;
  c17_hc_x = muDoubleScalarCos(c17_hc_x);
  c17_ic_x = c17_theta2;
  c17_jc_x = c17_ic_x;
  c17_jc_x = muDoubleScalarSin(c17_jc_x);
  c17_u_a = c17_hc_x;
  c17_u_b = c17_jc_x;
  c17_u_y = c17_u_a * c17_u_b;
  c17_kc_x = c17_theta3;
  c17_lc_x = c17_kc_x;
  c17_lc_x = muDoubleScalarCos(c17_lc_x);
  c17_v_a = c17_u_y;
  c17_v_b = c17_lc_x;
  c17_v_y = c17_v_a * c17_v_b;
  c17_mc_x = c17_theta4;
  c17_nc_x = c17_mc_x;
  c17_nc_x = muDoubleScalarCos(c17_nc_x);
  c17_w_a = c17_t_y - c17_v_y;
  c17_w_b = c17_nc_x;
  c17_w_y = c17_w_a * c17_w_b;
  c17_oc_x = c17_theta6;
  c17_pc_x = c17_oc_x;
  c17_pc_x = muDoubleScalarSin(c17_pc_x);
  c17_x_a = c17_r_y + c17_w_y;
  c17_x_b = c17_pc_x;
  c17_x_y = c17_x_a * c17_x_b;
  c17_qc_x = c17_theta1;
  c17_rc_x = c17_qc_x;
  c17_rc_x = muDoubleScalarCos(c17_rc_x);
  c17_sc_x = c17_theta2;
  c17_tc_x = c17_sc_x;
  c17_tc_x = muDoubleScalarCos(c17_tc_x);
  c17_y_a = c17_rc_x;
  c17_y_b = c17_tc_x;
  c17_y_y = c17_y_a * c17_y_b;
  c17_uc_x = c17_theta3;
  c17_vc_x = c17_uc_x;
  c17_vc_x = muDoubleScalarCos(c17_vc_x);
  c17_ab_a = c17_y_y;
  c17_ab_b = c17_vc_x;
  c17_ab_y = c17_ab_a * c17_ab_b;
  c17_wc_x = c17_theta1;
  c17_xc_x = c17_wc_x;
  c17_xc_x = muDoubleScalarCos(c17_xc_x);
  c17_yc_x = c17_theta2;
  c17_ad_x = c17_yc_x;
  c17_ad_x = muDoubleScalarSin(c17_ad_x);
  c17_bb_a = c17_xc_x;
  c17_bb_b = c17_ad_x;
  c17_bb_y = c17_bb_a * c17_bb_b;
  c17_bd_x = c17_theta3;
  c17_cd_x = c17_bd_x;
  c17_cd_x = muDoubleScalarSin(c17_cd_x);
  c17_cb_a = c17_bb_y;
  c17_cb_b = c17_cd_x;
  c17_cb_y = c17_cb_a * c17_cb_b;
  c17_dd_x = c17_theta4;
  c17_ed_x = c17_dd_x;
  c17_ed_x = muDoubleScalarCos(c17_ed_x);
  c17_db_a = c17_ab_y - c17_cb_y;
  c17_db_b = c17_ed_x;
  c17_db_y = c17_db_a * c17_db_b;
  c17_fd_x = c17_theta1;
  c17_gd_x = c17_fd_x;
  c17_gd_x = muDoubleScalarCos(c17_gd_x);
  c17_hd_x = c17_theta2;
  c17_id_x = c17_hd_x;
  c17_id_x = muDoubleScalarCos(c17_id_x);
  c17_eb_a = -c17_gd_x;
  c17_eb_b = c17_id_x;
  c17_eb_y = c17_eb_a * c17_eb_b;
  c17_jd_x = c17_theta3;
  c17_kd_x = c17_jd_x;
  c17_kd_x = muDoubleScalarSin(c17_kd_x);
  c17_fb_a = c17_eb_y;
  c17_fb_b = c17_kd_x;
  c17_fb_y = c17_fb_a * c17_fb_b;
  c17_ld_x = c17_theta1;
  c17_md_x = c17_ld_x;
  c17_md_x = muDoubleScalarCos(c17_md_x);
  c17_nd_x = c17_theta2;
  c17_od_x = c17_nd_x;
  c17_od_x = muDoubleScalarSin(c17_od_x);
  c17_gb_a = c17_md_x;
  c17_gb_b = c17_od_x;
  c17_gb_y = c17_gb_a * c17_gb_b;
  c17_pd_x = c17_theta3;
  c17_qd_x = c17_pd_x;
  c17_qd_x = muDoubleScalarCos(c17_qd_x);
  c17_hb_a = c17_gb_y;
  c17_hb_b = c17_qd_x;
  c17_hb_y = c17_hb_a * c17_hb_b;
  c17_rd_x = c17_theta4;
  c17_sd_x = c17_rd_x;
  c17_sd_x = muDoubleScalarSin(c17_sd_x);
  c17_ib_a = c17_fb_y - c17_hb_y;
  c17_ib_b = c17_sd_x;
  c17_ib_y = c17_ib_a * c17_ib_b;
  c17_td_x = c17_theta5;
  c17_ud_x = c17_td_x;
  c17_ud_x = muDoubleScalarCos(c17_ud_x);
  c17_jb_a = c17_db_y + c17_ib_y;
  c17_jb_b = c17_ud_x;
  c17_jb_y = c17_jb_a * c17_jb_b;
  c17_vd_x = c17_theta1;
  c17_wd_x = c17_vd_x;
  c17_wd_x = muDoubleScalarSin(c17_wd_x);
  c17_xd_x = c17_theta5;
  c17_yd_x = c17_xd_x;
  c17_yd_x = muDoubleScalarSin(c17_yd_x);
  c17_kb_a = c17_wd_x;
  c17_kb_b = c17_yd_x;
  c17_kb_y = c17_kb_a * c17_kb_b;
  c17_ae_x = c17_theta6;
  c17_be_x = c17_ae_x;
  c17_be_x = muDoubleScalarSin(c17_be_x);
  c17_lb_a = -(c17_jb_y + c17_kb_y);
  c17_lb_b = c17_be_x;
  c17_lb_y = c17_lb_a * c17_lb_b;
  c17_ce_x = c17_theta1;
  c17_de_x = c17_ce_x;
  c17_de_x = muDoubleScalarCos(c17_de_x);
  c17_ee_x = c17_theta2;
  c17_fe_x = c17_ee_x;
  c17_fe_x = muDoubleScalarCos(c17_fe_x);
  c17_mb_a = c17_de_x;
  c17_mb_b = c17_fe_x;
  c17_mb_y = c17_mb_a * c17_mb_b;
  c17_ge_x = c17_theta3;
  c17_he_x = c17_ge_x;
  c17_he_x = muDoubleScalarCos(c17_he_x);
  c17_nb_a = c17_mb_y;
  c17_nb_b = c17_he_x;
  c17_nb_y = c17_nb_a * c17_nb_b;
  c17_ie_x = c17_theta1;
  c17_je_x = c17_ie_x;
  c17_je_x = muDoubleScalarCos(c17_je_x);
  c17_ke_x = c17_theta2;
  c17_le_x = c17_ke_x;
  c17_le_x = muDoubleScalarSin(c17_le_x);
  c17_ob_a = c17_je_x;
  c17_ob_b = c17_le_x;
  c17_ob_y = c17_ob_a * c17_ob_b;
  c17_me_x = c17_theta3;
  c17_ne_x = c17_me_x;
  c17_ne_x = muDoubleScalarSin(c17_ne_x);
  c17_pb_a = c17_ob_y;
  c17_pb_b = c17_ne_x;
  c17_pb_y = c17_pb_a * c17_pb_b;
  c17_oe_x = c17_theta4;
  c17_pe_x = c17_oe_x;
  c17_pe_x = muDoubleScalarSin(c17_pe_x);
  c17_qb_a = -(c17_nb_y - c17_pb_y);
  c17_qb_b = c17_pe_x;
  c17_qb_y = c17_qb_a * c17_qb_b;
  c17_qe_x = c17_theta1;
  c17_re_x = c17_qe_x;
  c17_re_x = muDoubleScalarCos(c17_re_x);
  c17_se_x = c17_theta2;
  c17_te_x = c17_se_x;
  c17_te_x = muDoubleScalarCos(c17_te_x);
  c17_rb_a = -c17_re_x;
  c17_rb_b = c17_te_x;
  c17_rb_y = c17_rb_a * c17_rb_b;
  c17_ue_x = c17_theta3;
  c17_ve_x = c17_ue_x;
  c17_ve_x = muDoubleScalarSin(c17_ve_x);
  c17_sb_a = c17_rb_y;
  c17_sb_b = c17_ve_x;
  c17_sb_y = c17_sb_a * c17_sb_b;
  c17_we_x = c17_theta1;
  c17_xe_x = c17_we_x;
  c17_xe_x = muDoubleScalarCos(c17_xe_x);
  c17_ye_x = c17_theta2;
  c17_af_x = c17_ye_x;
  c17_af_x = muDoubleScalarSin(c17_af_x);
  c17_tb_a = c17_xe_x;
  c17_tb_b = c17_af_x;
  c17_tb_y = c17_tb_a * c17_tb_b;
  c17_bf_x = c17_theta3;
  c17_cf_x = c17_bf_x;
  c17_cf_x = muDoubleScalarCos(c17_cf_x);
  c17_ub_a = c17_tb_y;
  c17_ub_b = c17_cf_x;
  c17_ub_y = c17_ub_a * c17_ub_b;
  c17_df_x = c17_theta4;
  c17_ef_x = c17_df_x;
  c17_ef_x = muDoubleScalarCos(c17_ef_x);
  c17_vb_a = c17_sb_y - c17_ub_y;
  c17_vb_b = c17_ef_x;
  c17_vb_y = c17_vb_a * c17_vb_b;
  c17_ff_x = c17_theta6;
  c17_gf_x = c17_ff_x;
  c17_gf_x = muDoubleScalarCos(c17_gf_x);
  c17_wb_a = c17_qb_y + c17_vb_y;
  c17_wb_b = c17_gf_x;
  c17_wb_y = c17_wb_a * c17_wb_b;
  c17_hf_x = c17_theta1;
  c17_if_x = c17_hf_x;
  c17_if_x = muDoubleScalarCos(c17_if_x);
  c17_jf_x = c17_theta2;
  c17_kf_x = c17_jf_x;
  c17_kf_x = muDoubleScalarCos(c17_kf_x);
  c17_xb_a = c17_if_x;
  c17_xb_b = c17_kf_x;
  c17_xb_y = c17_xb_a * c17_xb_b;
  c17_lf_x = c17_theta3;
  c17_mf_x = c17_lf_x;
  c17_mf_x = muDoubleScalarCos(c17_mf_x);
  c17_yb_a = c17_xb_y;
  c17_yb_b = c17_mf_x;
  c17_yb_y = c17_yb_a * c17_yb_b;
  c17_nf_x = c17_theta1;
  c17_of_x = c17_nf_x;
  c17_of_x = muDoubleScalarCos(c17_of_x);
  c17_pf_x = c17_theta2;
  c17_qf_x = c17_pf_x;
  c17_qf_x = muDoubleScalarSin(c17_qf_x);
  c17_ac_a = c17_of_x;
  c17_ac_b = c17_qf_x;
  c17_ac_y = c17_ac_a * c17_ac_b;
  c17_rf_x = c17_theta3;
  c17_sf_x = c17_rf_x;
  c17_sf_x = muDoubleScalarSin(c17_sf_x);
  c17_bc_a = c17_ac_y;
  c17_bc_b = c17_sf_x;
  c17_bc_y = c17_bc_a * c17_bc_b;
  c17_tf_x = c17_theta4;
  c17_uf_x = c17_tf_x;
  c17_uf_x = muDoubleScalarCos(c17_uf_x);
  c17_cc_a = c17_yb_y - c17_bc_y;
  c17_cc_b = c17_uf_x;
  c17_cc_y = c17_cc_a * c17_cc_b;
  c17_vf_x = c17_theta1;
  c17_wf_x = c17_vf_x;
  c17_wf_x = muDoubleScalarCos(c17_wf_x);
  c17_xf_x = c17_theta2;
  c17_yf_x = c17_xf_x;
  c17_yf_x = muDoubleScalarCos(c17_yf_x);
  c17_dc_a = -c17_wf_x;
  c17_dc_b = c17_yf_x;
  c17_dc_y = c17_dc_a * c17_dc_b;
  c17_ag_x = c17_theta3;
  c17_bg_x = c17_ag_x;
  c17_bg_x = muDoubleScalarSin(c17_bg_x);
  c17_ec_a = c17_dc_y;
  c17_ec_b = c17_bg_x;
  c17_ec_y = c17_ec_a * c17_ec_b;
  c17_cg_x = c17_theta1;
  c17_dg_x = c17_cg_x;
  c17_dg_x = muDoubleScalarCos(c17_dg_x);
  c17_eg_x = c17_theta2;
  c17_fg_x = c17_eg_x;
  c17_fg_x = muDoubleScalarSin(c17_fg_x);
  c17_fc_a = c17_dg_x;
  c17_fc_b = c17_fg_x;
  c17_fc_y = c17_fc_a * c17_fc_b;
  c17_gg_x = c17_theta3;
  c17_hg_x = c17_gg_x;
  c17_hg_x = muDoubleScalarCos(c17_hg_x);
  c17_gc_a = c17_fc_y;
  c17_gc_b = c17_hg_x;
  c17_gc_y = c17_gc_a * c17_gc_b;
  c17_ig_x = c17_theta4;
  c17_jg_x = c17_ig_x;
  c17_jg_x = muDoubleScalarSin(c17_jg_x);
  c17_hc_a = c17_ec_y - c17_gc_y;
  c17_hc_b = c17_jg_x;
  c17_hc_y = c17_hc_a * c17_hc_b;
  c17_kg_x = c17_theta5;
  c17_lg_x = c17_kg_x;
  c17_lg_x = muDoubleScalarSin(c17_lg_x);
  c17_ic_a = -(c17_cc_y + c17_hc_y);
  c17_ic_b = c17_lg_x;
  c17_ic_y = c17_ic_a * c17_ic_b;
  c17_mg_x = c17_theta1;
  c17_ng_x = c17_mg_x;
  c17_ng_x = muDoubleScalarSin(c17_ng_x);
  c17_og_x = c17_theta5;
  c17_pg_x = c17_og_x;
  c17_pg_x = muDoubleScalarCos(c17_pg_x);
  c17_jc_a = c17_ng_x;
  c17_jc_b = c17_pg_x;
  c17_jc_y = c17_jc_a * c17_jc_b;
  c17_qg_x = c17_theta1;
  c17_rg_x = c17_qg_x;
  c17_rg_x = muDoubleScalarCos(c17_rg_x);
  c17_sg_x = c17_theta2;
  c17_tg_x = c17_sg_x;
  c17_tg_x = muDoubleScalarCos(c17_tg_x);
  c17_kc_a = c17_rg_x;
  c17_kc_b = c17_tg_x;
  c17_kc_y = c17_kc_a * c17_kc_b;
  c17_ug_x = c17_theta3;
  c17_vg_x = c17_ug_x;
  c17_vg_x = muDoubleScalarCos(c17_vg_x);
  c17_lc_a = c17_kc_y;
  c17_lc_b = c17_vg_x;
  c17_lc_y = c17_lc_a * c17_lc_b;
  c17_wg_x = c17_theta1;
  c17_xg_x = c17_wg_x;
  c17_xg_x = muDoubleScalarCos(c17_xg_x);
  c17_yg_x = c17_theta2;
  c17_ah_x = c17_yg_x;
  c17_ah_x = muDoubleScalarSin(c17_ah_x);
  c17_mc_a = c17_xg_x;
  c17_mc_b = c17_ah_x;
  c17_mc_y = c17_mc_a * c17_mc_b;
  c17_bh_x = c17_theta3;
  c17_ch_x = c17_bh_x;
  c17_ch_x = muDoubleScalarSin(c17_ch_x);
  c17_nc_a = c17_mc_y;
  c17_nc_b = c17_ch_x;
  c17_nc_y = c17_nc_a * c17_nc_b;
  c17_dh_x = c17_theta4;
  c17_eh_x = c17_dh_x;
  c17_eh_x = muDoubleScalarCos(c17_eh_x);
  c17_oc_a = c17_lc_y - c17_nc_y;
  c17_oc_b = c17_eh_x;
  c17_oc_y = c17_oc_a * c17_oc_b;
  c17_fh_x = c17_theta1;
  c17_gh_x = c17_fh_x;
  c17_gh_x = muDoubleScalarCos(c17_gh_x);
  c17_hh_x = c17_theta2;
  c17_ih_x = c17_hh_x;
  c17_ih_x = muDoubleScalarCos(c17_ih_x);
  c17_pc_a = -c17_gh_x;
  c17_pc_b = c17_ih_x;
  c17_pc_y = c17_pc_a * c17_pc_b;
  c17_jh_x = c17_theta3;
  c17_kh_x = c17_jh_x;
  c17_kh_x = muDoubleScalarSin(c17_kh_x);
  c17_qc_a = c17_pc_y;
  c17_qc_b = c17_kh_x;
  c17_qc_y = c17_qc_a * c17_qc_b;
  c17_lh_x = c17_theta1;
  c17_mh_x = c17_lh_x;
  c17_mh_x = muDoubleScalarCos(c17_mh_x);
  c17_nh_x = c17_theta2;
  c17_oh_x = c17_nh_x;
  c17_oh_x = muDoubleScalarSin(c17_oh_x);
  c17_rc_a = c17_mh_x;
  c17_rc_b = c17_oh_x;
  c17_rc_y = c17_rc_a * c17_rc_b;
  c17_ph_x = c17_theta3;
  c17_qh_x = c17_ph_x;
  c17_qh_x = muDoubleScalarCos(c17_qh_x);
  c17_sc_a = c17_rc_y;
  c17_sc_b = c17_qh_x;
  c17_sc_y = c17_sc_a * c17_sc_b;
  c17_rh_x = c17_theta4;
  c17_sh_x = c17_rh_x;
  c17_sh_x = muDoubleScalarSin(c17_sh_x);
  c17_tc_a = c17_qc_y - c17_sc_y;
  c17_tc_b = c17_sh_x;
  c17_tc_y = c17_tc_a * c17_tc_b;
  c17_uc_b = c17_oc_y + c17_tc_y;
  c17_uc_y = -0.082 * c17_uc_b;
  c17_th_x = c17_theta5;
  c17_uh_x = c17_th_x;
  c17_uh_x = muDoubleScalarSin(c17_uh_x);
  c17_uc_a = c17_uc_y;
  c17_vc_b = c17_uh_x;
  c17_vc_y = c17_uc_a * c17_vc_b;
  c17_vh_x = c17_theta1;
  c17_wh_x = c17_vh_x;
  c17_wh_x = muDoubleScalarSin(c17_wh_x);
  c17_wc_b = c17_wh_x;
  c17_wc_y = 0.082 * c17_wc_b;
  c17_xh_x = c17_theta5;
  c17_yh_x = c17_xh_x;
  c17_yh_x = muDoubleScalarCos(c17_yh_x);
  c17_vc_a = c17_wc_y;
  c17_xc_b = c17_yh_x;
  c17_xc_y = c17_vc_a * c17_xc_b;
  c17_ai_x = c17_theta1;
  c17_bi_x = c17_ai_x;
  c17_bi_x = muDoubleScalarCos(c17_bi_x);
  c17_ci_x = c17_theta2;
  c17_di_x = c17_ci_x;
  c17_di_x = muDoubleScalarCos(c17_di_x);
  c17_wc_a = c17_bi_x;
  c17_yc_b = c17_di_x;
  c17_yc_y = c17_wc_a * c17_yc_b;
  c17_ei_x = c17_theta3;
  c17_fi_x = c17_ei_x;
  c17_fi_x = muDoubleScalarCos(c17_fi_x);
  c17_xc_a = c17_yc_y;
  c17_ad_b = c17_fi_x;
  c17_ad_y = c17_xc_a * c17_ad_b;
  c17_gi_x = c17_theta1;
  c17_hi_x = c17_gi_x;
  c17_hi_x = muDoubleScalarCos(c17_hi_x);
  c17_ii_x = c17_theta2;
  c17_ji_x = c17_ii_x;
  c17_ji_x = muDoubleScalarSin(c17_ji_x);
  c17_yc_a = c17_hi_x;
  c17_bd_b = c17_ji_x;
  c17_bd_y = c17_yc_a * c17_bd_b;
  c17_ki_x = c17_theta3;
  c17_li_x = c17_ki_x;
  c17_li_x = muDoubleScalarSin(c17_li_x);
  c17_ad_a = c17_bd_y;
  c17_cd_b = c17_li_x;
  c17_cd_y = c17_ad_a * c17_cd_b;
  c17_dd_b = c17_ad_y - c17_cd_y;
  c17_dd_y = 0.093 * c17_dd_b;
  c17_mi_x = c17_theta4;
  c17_ni_x = c17_mi_x;
  c17_ni_x = muDoubleScalarSin(c17_ni_x);
  c17_bd_a = c17_dd_y;
  c17_ed_b = c17_ni_x;
  c17_ed_y = c17_bd_a * c17_ed_b;
  c17_oi_x = c17_theta1;
  c17_pi_x = c17_oi_x;
  c17_pi_x = muDoubleScalarCos(c17_pi_x);
  c17_qi_x = c17_theta2;
  c17_ri_x = c17_qi_x;
  c17_ri_x = muDoubleScalarCos(c17_ri_x);
  c17_cd_a = -c17_pi_x;
  c17_fd_b = c17_ri_x;
  c17_fd_y = c17_cd_a * c17_fd_b;
  c17_si_x = c17_theta3;
  c17_ti_x = c17_si_x;
  c17_ti_x = muDoubleScalarSin(c17_ti_x);
  c17_dd_a = c17_fd_y;
  c17_gd_b = c17_ti_x;
  c17_gd_y = c17_dd_a * c17_gd_b;
  c17_ui_x = c17_theta1;
  c17_vi_x = c17_ui_x;
  c17_vi_x = muDoubleScalarCos(c17_vi_x);
  c17_wi_x = c17_theta2;
  c17_xi_x = c17_wi_x;
  c17_xi_x = muDoubleScalarSin(c17_xi_x);
  c17_ed_a = c17_vi_x;
  c17_hd_b = c17_xi_x;
  c17_hd_y = c17_ed_a * c17_hd_b;
  c17_yi_x = c17_theta3;
  c17_aj_x = c17_yi_x;
  c17_aj_x = muDoubleScalarCos(c17_aj_x);
  c17_fd_a = c17_hd_y;
  c17_id_b = c17_aj_x;
  c17_id_y = c17_fd_a * c17_id_b;
  c17_jd_b = c17_gd_y - c17_id_y;
  c17_jd_y = 0.093 * c17_jd_b;
  c17_bj_x = c17_theta4;
  c17_cj_x = c17_bj_x;
  c17_cj_x = muDoubleScalarCos(c17_cj_x);
  c17_gd_a = c17_jd_y;
  c17_kd_b = c17_cj_x;
  c17_kd_y = c17_gd_a * c17_kd_b;
  c17_dj_x = c17_theta1;
  c17_ej_x = c17_dj_x;
  c17_ej_x = muDoubleScalarSin(c17_ej_x);
  c17_ld_b = c17_ej_x;
  c17_ld_y = 0.109 * c17_ld_b;
  c17_fj_x = c17_theta1;
  c17_gj_x = c17_fj_x;
  c17_gj_x = muDoubleScalarCos(c17_gj_x);
  c17_md_b = c17_gj_x;
  c17_md_y = 0.39243 * c17_md_b;
  c17_hj_x = c17_theta2;
  c17_ij_x = c17_hj_x;
  c17_ij_x = muDoubleScalarCos(c17_ij_x);
  c17_hd_a = c17_md_y;
  c17_nd_b = c17_ij_x;
  c17_nd_y = c17_hd_a * c17_nd_b;
  c17_jj_x = c17_theta3;
  c17_kj_x = c17_jj_x;
  c17_kj_x = muDoubleScalarCos(c17_kj_x);
  c17_id_a = c17_nd_y;
  c17_od_b = c17_kj_x;
  c17_od_y = c17_id_a * c17_od_b;
  c17_lj_x = c17_theta1;
  c17_mj_x = c17_lj_x;
  c17_mj_x = muDoubleScalarCos(c17_mj_x);
  c17_pd_b = c17_mj_x;
  c17_pd_y = 0.39243 * c17_pd_b;
  c17_nj_x = c17_theta2;
  c17_oj_x = c17_nj_x;
  c17_oj_x = muDoubleScalarSin(c17_oj_x);
  c17_jd_a = c17_pd_y;
  c17_qd_b = c17_oj_x;
  c17_qd_y = c17_jd_a * c17_qd_b;
  c17_pj_x = c17_theta3;
  c17_qj_x = c17_pj_x;
  c17_qj_x = muDoubleScalarSin(c17_qj_x);
  c17_kd_a = c17_qd_y;
  c17_rd_b = c17_qj_x;
  c17_rd_y = c17_kd_a * c17_rd_b;
  c17_rj_x = c17_theta1;
  c17_sj_x = c17_rj_x;
  c17_sj_x = muDoubleScalarCos(c17_sj_x);
  c17_sd_b = c17_sj_x;
  c17_sd_y = 0.425 * c17_sd_b;
  c17_tj_x = c17_theta2;
  c17_uj_x = c17_tj_x;
  c17_uj_x = muDoubleScalarCos(c17_uj_x);
  c17_ld_a = c17_sd_y;
  c17_td_b = c17_uj_x;
  c17_td_y = c17_ld_a * c17_td_b;
  c17_vj_x = c17_theta1;
  c17_wj_x = c17_vj_x;
  c17_wj_x = muDoubleScalarSin(c17_wj_x);
  c17_xj_x = c17_theta2;
  c17_yj_x = c17_xj_x;
  c17_yj_x = muDoubleScalarCos(c17_yj_x);
  c17_md_a = c17_wj_x;
  c17_ud_b = c17_yj_x;
  c17_ud_y = c17_md_a * c17_ud_b;
  c17_ak_x = c17_theta3;
  c17_bk_x = c17_ak_x;
  c17_bk_x = muDoubleScalarCos(c17_bk_x);
  c17_nd_a = c17_ud_y;
  c17_vd_b = c17_bk_x;
  c17_vd_y = c17_nd_a * c17_vd_b;
  c17_ck_x = c17_theta1;
  c17_dk_x = c17_ck_x;
  c17_dk_x = muDoubleScalarSin(c17_dk_x);
  c17_ek_x = c17_theta2;
  c17_fk_x = c17_ek_x;
  c17_fk_x = muDoubleScalarSin(c17_fk_x);
  c17_od_a = c17_dk_x;
  c17_wd_b = c17_fk_x;
  c17_wd_y = c17_od_a * c17_wd_b;
  c17_gk_x = c17_theta3;
  c17_hk_x = c17_gk_x;
  c17_hk_x = muDoubleScalarSin(c17_hk_x);
  c17_pd_a = c17_wd_y;
  c17_xd_b = c17_hk_x;
  c17_xd_y = c17_pd_a * c17_xd_b;
  c17_ik_x = c17_theta4;
  c17_jk_x = c17_ik_x;
  c17_jk_x = muDoubleScalarCos(c17_jk_x);
  c17_qd_a = c17_vd_y - c17_xd_y;
  c17_yd_b = c17_jk_x;
  c17_yd_y = c17_qd_a * c17_yd_b;
  c17_kk_x = c17_theta1;
  c17_lk_x = c17_kk_x;
  c17_lk_x = muDoubleScalarSin(c17_lk_x);
  c17_mk_x = c17_theta2;
  c17_nk_x = c17_mk_x;
  c17_nk_x = muDoubleScalarCos(c17_nk_x);
  c17_rd_a = -c17_lk_x;
  c17_ae_b = c17_nk_x;
  c17_ae_y = c17_rd_a * c17_ae_b;
  c17_ok_x = c17_theta3;
  c17_pk_x = c17_ok_x;
  c17_pk_x = muDoubleScalarSin(c17_pk_x);
  c17_sd_a = c17_ae_y;
  c17_be_b = c17_pk_x;
  c17_be_y = c17_sd_a * c17_be_b;
  c17_qk_x = c17_theta1;
  c17_rk_x = c17_qk_x;
  c17_rk_x = muDoubleScalarSin(c17_rk_x);
  c17_sk_x = c17_theta2;
  c17_tk_x = c17_sk_x;
  c17_tk_x = muDoubleScalarSin(c17_tk_x);
  c17_td_a = c17_rk_x;
  c17_ce_b = c17_tk_x;
  c17_ce_y = c17_td_a * c17_ce_b;
  c17_uk_x = c17_theta3;
  c17_vk_x = c17_uk_x;
  c17_vk_x = muDoubleScalarCos(c17_vk_x);
  c17_ud_a = c17_ce_y;
  c17_de_b = c17_vk_x;
  c17_de_y = c17_ud_a * c17_de_b;
  c17_wk_x = c17_theta4;
  c17_xk_x = c17_wk_x;
  c17_xk_x = muDoubleScalarSin(c17_xk_x);
  c17_vd_a = c17_be_y - c17_de_y;
  c17_ee_b = c17_xk_x;
  c17_ee_y = c17_vd_a * c17_ee_b;
  c17_yk_x = c17_theta5;
  c17_al_x = c17_yk_x;
  c17_al_x = muDoubleScalarCos(c17_al_x);
  c17_wd_a = c17_yd_y + c17_ee_y;
  c17_fe_b = c17_al_x;
  c17_fe_y = c17_wd_a * c17_fe_b;
  c17_bl_x = c17_theta1;
  c17_cl_x = c17_bl_x;
  c17_cl_x = muDoubleScalarCos(c17_cl_x);
  c17_dl_x = c17_theta5;
  c17_el_x = c17_dl_x;
  c17_el_x = muDoubleScalarSin(c17_el_x);
  c17_xd_a = c17_cl_x;
  c17_ge_b = c17_el_x;
  c17_ge_y = c17_xd_a * c17_ge_b;
  c17_fl_x = c17_theta6;
  c17_gl_x = c17_fl_x;
  c17_gl_x = muDoubleScalarCos(c17_gl_x);
  c17_yd_a = c17_fe_y - c17_ge_y;
  c17_he_b = c17_gl_x;
  c17_he_y = c17_yd_a * c17_he_b;
  c17_hl_x = c17_theta1;
  c17_il_x = c17_hl_x;
  c17_il_x = muDoubleScalarSin(c17_il_x);
  c17_jl_x = c17_theta2;
  c17_kl_x = c17_jl_x;
  c17_kl_x = muDoubleScalarCos(c17_kl_x);
  c17_ae_a = c17_il_x;
  c17_ie_b = c17_kl_x;
  c17_ie_y = c17_ae_a * c17_ie_b;
  c17_ll_x = c17_theta3;
  c17_ml_x = c17_ll_x;
  c17_ml_x = muDoubleScalarCos(c17_ml_x);
  c17_be_a = c17_ie_y;
  c17_je_b = c17_ml_x;
  c17_je_y = c17_be_a * c17_je_b;
  c17_nl_x = c17_theta1;
  c17_ol_x = c17_nl_x;
  c17_ol_x = muDoubleScalarSin(c17_ol_x);
  c17_pl_x = c17_theta2;
  c17_ql_x = c17_pl_x;
  c17_ql_x = muDoubleScalarSin(c17_ql_x);
  c17_ce_a = c17_ol_x;
  c17_ke_b = c17_ql_x;
  c17_ke_y = c17_ce_a * c17_ke_b;
  c17_rl_x = c17_theta3;
  c17_sl_x = c17_rl_x;
  c17_sl_x = muDoubleScalarSin(c17_sl_x);
  c17_de_a = c17_ke_y;
  c17_le_b = c17_sl_x;
  c17_le_y = c17_de_a * c17_le_b;
  c17_tl_x = c17_theta4;
  c17_ul_x = c17_tl_x;
  c17_ul_x = muDoubleScalarSin(c17_ul_x);
  c17_ee_a = -(c17_je_y - c17_le_y);
  c17_me_b = c17_ul_x;
  c17_me_y = c17_ee_a * c17_me_b;
  c17_vl_x = c17_theta1;
  c17_wl_x = c17_vl_x;
  c17_wl_x = muDoubleScalarSin(c17_wl_x);
  c17_xl_x = c17_theta2;
  c17_yl_x = c17_xl_x;
  c17_yl_x = muDoubleScalarCos(c17_yl_x);
  c17_fe_a = -c17_wl_x;
  c17_ne_b = c17_yl_x;
  c17_ne_y = c17_fe_a * c17_ne_b;
  c17_am_x = c17_theta3;
  c17_bm_x = c17_am_x;
  c17_bm_x = muDoubleScalarSin(c17_bm_x);
  c17_ge_a = c17_ne_y;
  c17_oe_b = c17_bm_x;
  c17_oe_y = c17_ge_a * c17_oe_b;
  c17_cm_x = c17_theta1;
  c17_dm_x = c17_cm_x;
  c17_dm_x = muDoubleScalarSin(c17_dm_x);
  c17_em_x = c17_theta2;
  c17_fm_x = c17_em_x;
  c17_fm_x = muDoubleScalarSin(c17_fm_x);
  c17_he_a = c17_dm_x;
  c17_pe_b = c17_fm_x;
  c17_pe_y = c17_he_a * c17_pe_b;
  c17_gm_x = c17_theta3;
  c17_hm_x = c17_gm_x;
  c17_hm_x = muDoubleScalarCos(c17_hm_x);
  c17_ie_a = c17_pe_y;
  c17_qe_b = c17_hm_x;
  c17_qe_y = c17_ie_a * c17_qe_b;
  c17_im_x = c17_theta4;
  c17_jm_x = c17_im_x;
  c17_jm_x = muDoubleScalarCos(c17_jm_x);
  c17_je_a = c17_oe_y - c17_qe_y;
  c17_re_b = c17_jm_x;
  c17_re_y = c17_je_a * c17_re_b;
  c17_km_x = c17_theta6;
  c17_lm_x = c17_km_x;
  c17_lm_x = muDoubleScalarSin(c17_lm_x);
  c17_ke_a = c17_me_y + c17_re_y;
  c17_se_b = c17_lm_x;
  c17_se_y = c17_ke_a * c17_se_b;
  c17_mm_x = c17_theta1;
  c17_nm_x = c17_mm_x;
  c17_nm_x = muDoubleScalarSin(c17_nm_x);
  c17_om_x = c17_theta2;
  c17_pm_x = c17_om_x;
  c17_pm_x = muDoubleScalarCos(c17_pm_x);
  c17_le_a = c17_nm_x;
  c17_te_b = c17_pm_x;
  c17_te_y = c17_le_a * c17_te_b;
  c17_qm_x = c17_theta3;
  c17_rm_x = c17_qm_x;
  c17_rm_x = muDoubleScalarCos(c17_rm_x);
  c17_me_a = c17_te_y;
  c17_ue_b = c17_rm_x;
  c17_ue_y = c17_me_a * c17_ue_b;
  c17_sm_x = c17_theta1;
  c17_tm_x = c17_sm_x;
  c17_tm_x = muDoubleScalarSin(c17_tm_x);
  c17_um_x = c17_theta2;
  c17_vm_x = c17_um_x;
  c17_vm_x = muDoubleScalarSin(c17_vm_x);
  c17_ne_a = c17_tm_x;
  c17_ve_b = c17_vm_x;
  c17_ve_y = c17_ne_a * c17_ve_b;
  c17_wm_x = c17_theta3;
  c17_xm_x = c17_wm_x;
  c17_xm_x = muDoubleScalarSin(c17_xm_x);
  c17_oe_a = c17_ve_y;
  c17_we_b = c17_xm_x;
  c17_we_y = c17_oe_a * c17_we_b;
  c17_ym_x = c17_theta4;
  c17_an_x = c17_ym_x;
  c17_an_x = muDoubleScalarCos(c17_an_x);
  c17_pe_a = c17_ue_y - c17_we_y;
  c17_xe_b = c17_an_x;
  c17_xe_y = c17_pe_a * c17_xe_b;
  c17_bn_x = c17_theta1;
  c17_cn_x = c17_bn_x;
  c17_cn_x = muDoubleScalarSin(c17_cn_x);
  c17_dn_x = c17_theta2;
  c17_en_x = c17_dn_x;
  c17_en_x = muDoubleScalarCos(c17_en_x);
  c17_qe_a = -c17_cn_x;
  c17_ye_b = c17_en_x;
  c17_ye_y = c17_qe_a * c17_ye_b;
  c17_fn_x = c17_theta3;
  c17_gn_x = c17_fn_x;
  c17_gn_x = muDoubleScalarSin(c17_gn_x);
  c17_re_a = c17_ye_y;
  c17_af_b = c17_gn_x;
  c17_af_y = c17_re_a * c17_af_b;
  c17_hn_x = c17_theta1;
  c17_in_x = c17_hn_x;
  c17_in_x = muDoubleScalarSin(c17_in_x);
  c17_jn_x = c17_theta2;
  c17_kn_x = c17_jn_x;
  c17_kn_x = muDoubleScalarSin(c17_kn_x);
  c17_se_a = c17_in_x;
  c17_bf_b = c17_kn_x;
  c17_bf_y = c17_se_a * c17_bf_b;
  c17_ln_x = c17_theta3;
  c17_mn_x = c17_ln_x;
  c17_mn_x = muDoubleScalarCos(c17_mn_x);
  c17_te_a = c17_bf_y;
  c17_cf_b = c17_mn_x;
  c17_cf_y = c17_te_a * c17_cf_b;
  c17_nn_x = c17_theta4;
  c17_on_x = c17_nn_x;
  c17_on_x = muDoubleScalarSin(c17_on_x);
  c17_ue_a = c17_af_y - c17_cf_y;
  c17_df_b = c17_on_x;
  c17_df_y = c17_ue_a * c17_df_b;
  c17_pn_x = c17_theta5;
  c17_qn_x = c17_pn_x;
  c17_qn_x = muDoubleScalarCos(c17_qn_x);
  c17_ve_a = c17_xe_y + c17_df_y;
  c17_ef_b = c17_qn_x;
  c17_ef_y = c17_ve_a * c17_ef_b;
  c17_rn_x = c17_theta1;
  c17_sn_x = c17_rn_x;
  c17_sn_x = muDoubleScalarCos(c17_sn_x);
  c17_tn_x = c17_theta5;
  c17_un_x = c17_tn_x;
  c17_un_x = muDoubleScalarSin(c17_un_x);
  c17_we_a = c17_sn_x;
  c17_ff_b = c17_un_x;
  c17_ff_y = c17_we_a * c17_ff_b;
  c17_vn_x = c17_theta6;
  c17_wn_x = c17_vn_x;
  c17_wn_x = muDoubleScalarSin(c17_wn_x);
  c17_xe_a = -(c17_ef_y - c17_ff_y);
  c17_gf_b = c17_wn_x;
  c17_gf_y = c17_xe_a * c17_gf_b;
  c17_xn_x = c17_theta1;
  c17_yn_x = c17_xn_x;
  c17_yn_x = muDoubleScalarSin(c17_yn_x);
  c17_ao_x = c17_theta2;
  c17_bo_x = c17_ao_x;
  c17_bo_x = muDoubleScalarCos(c17_bo_x);
  c17_ye_a = c17_yn_x;
  c17_hf_b = c17_bo_x;
  c17_hf_y = c17_ye_a * c17_hf_b;
  c17_co_x = c17_theta3;
  c17_do_x = c17_co_x;
  c17_do_x = muDoubleScalarCos(c17_do_x);
  c17_af_a = c17_hf_y;
  c17_if_b = c17_do_x;
  c17_if_y = c17_af_a * c17_if_b;
  c17_eo_x = c17_theta1;
  c17_fo_x = c17_eo_x;
  c17_fo_x = muDoubleScalarSin(c17_fo_x);
  c17_go_x = c17_theta2;
  c17_ho_x = c17_go_x;
  c17_ho_x = muDoubleScalarSin(c17_ho_x);
  c17_bf_a = c17_fo_x;
  c17_jf_b = c17_ho_x;
  c17_jf_y = c17_bf_a * c17_jf_b;
  c17_io_x = c17_theta3;
  c17_jo_x = c17_io_x;
  c17_jo_x = muDoubleScalarSin(c17_jo_x);
  c17_cf_a = c17_jf_y;
  c17_kf_b = c17_jo_x;
  c17_kf_y = c17_cf_a * c17_kf_b;
  c17_ko_x = c17_theta4;
  c17_lo_x = c17_ko_x;
  c17_lo_x = muDoubleScalarSin(c17_lo_x);
  c17_df_a = -(c17_if_y - c17_kf_y);
  c17_lf_b = c17_lo_x;
  c17_lf_y = c17_df_a * c17_lf_b;
  c17_mo_x = c17_theta1;
  c17_no_x = c17_mo_x;
  c17_no_x = muDoubleScalarSin(c17_no_x);
  c17_oo_x = c17_theta2;
  c17_po_x = c17_oo_x;
  c17_po_x = muDoubleScalarCos(c17_po_x);
  c17_ef_a = -c17_no_x;
  c17_mf_b = c17_po_x;
  c17_mf_y = c17_ef_a * c17_mf_b;
  c17_qo_x = c17_theta3;
  c17_ro_x = c17_qo_x;
  c17_ro_x = muDoubleScalarSin(c17_ro_x);
  c17_ff_a = c17_mf_y;
  c17_nf_b = c17_ro_x;
  c17_nf_y = c17_ff_a * c17_nf_b;
  c17_so_x = c17_theta1;
  c17_to_x = c17_so_x;
  c17_to_x = muDoubleScalarSin(c17_to_x);
  c17_uo_x = c17_theta2;
  c17_vo_x = c17_uo_x;
  c17_vo_x = muDoubleScalarSin(c17_vo_x);
  c17_gf_a = c17_to_x;
  c17_of_b = c17_vo_x;
  c17_of_y = c17_gf_a * c17_of_b;
  c17_wo_x = c17_theta3;
  c17_xo_x = c17_wo_x;
  c17_xo_x = muDoubleScalarCos(c17_xo_x);
  c17_hf_a = c17_of_y;
  c17_pf_b = c17_xo_x;
  c17_pf_y = c17_hf_a * c17_pf_b;
  c17_yo_x = c17_theta4;
  c17_ap_x = c17_yo_x;
  c17_ap_x = muDoubleScalarCos(c17_ap_x);
  c17_if_a = c17_nf_y - c17_pf_y;
  c17_qf_b = c17_ap_x;
  c17_qf_y = c17_if_a * c17_qf_b;
  c17_bp_x = c17_theta6;
  c17_cp_x = c17_bp_x;
  c17_cp_x = muDoubleScalarCos(c17_cp_x);
  c17_jf_a = c17_lf_y + c17_qf_y;
  c17_rf_b = c17_cp_x;
  c17_rf_y = c17_jf_a * c17_rf_b;
  c17_dp_x = c17_theta1;
  c17_ep_x = c17_dp_x;
  c17_ep_x = muDoubleScalarSin(c17_ep_x);
  c17_fp_x = c17_theta2;
  c17_gp_x = c17_fp_x;
  c17_gp_x = muDoubleScalarCos(c17_gp_x);
  c17_kf_a = c17_ep_x;
  c17_sf_b = c17_gp_x;
  c17_sf_y = c17_kf_a * c17_sf_b;
  c17_hp_x = c17_theta3;
  c17_ip_x = c17_hp_x;
  c17_ip_x = muDoubleScalarCos(c17_ip_x);
  c17_lf_a = c17_sf_y;
  c17_tf_b = c17_ip_x;
  c17_tf_y = c17_lf_a * c17_tf_b;
  c17_jp_x = c17_theta1;
  c17_kp_x = c17_jp_x;
  c17_kp_x = muDoubleScalarSin(c17_kp_x);
  c17_lp_x = c17_theta2;
  c17_mp_x = c17_lp_x;
  c17_mp_x = muDoubleScalarSin(c17_mp_x);
  c17_mf_a = c17_kp_x;
  c17_uf_b = c17_mp_x;
  c17_uf_y = c17_mf_a * c17_uf_b;
  c17_np_x = c17_theta3;
  c17_op_x = c17_np_x;
  c17_op_x = muDoubleScalarSin(c17_op_x);
  c17_nf_a = c17_uf_y;
  c17_vf_b = c17_op_x;
  c17_vf_y = c17_nf_a * c17_vf_b;
  c17_pp_x = c17_theta4;
  c17_qp_x = c17_pp_x;
  c17_qp_x = muDoubleScalarCos(c17_qp_x);
  c17_of_a = c17_tf_y - c17_vf_y;
  c17_wf_b = c17_qp_x;
  c17_wf_y = c17_of_a * c17_wf_b;
  c17_rp_x = c17_theta1;
  c17_sp_x = c17_rp_x;
  c17_sp_x = muDoubleScalarSin(c17_sp_x);
  c17_tp_x = c17_theta2;
  c17_up_x = c17_tp_x;
  c17_up_x = muDoubleScalarCos(c17_up_x);
  c17_pf_a = -c17_sp_x;
  c17_xf_b = c17_up_x;
  c17_xf_y = c17_pf_a * c17_xf_b;
  c17_vp_x = c17_theta3;
  c17_wp_x = c17_vp_x;
  c17_wp_x = muDoubleScalarSin(c17_wp_x);
  c17_qf_a = c17_xf_y;
  c17_yf_b = c17_wp_x;
  c17_yf_y = c17_qf_a * c17_yf_b;
  c17_xp_x = c17_theta1;
  c17_yp_x = c17_xp_x;
  c17_yp_x = muDoubleScalarSin(c17_yp_x);
  c17_aq_x = c17_theta2;
  c17_bq_x = c17_aq_x;
  c17_bq_x = muDoubleScalarSin(c17_bq_x);
  c17_rf_a = c17_yp_x;
  c17_ag_b = c17_bq_x;
  c17_ag_y = c17_rf_a * c17_ag_b;
  c17_cq_x = c17_theta3;
  c17_dq_x = c17_cq_x;
  c17_dq_x = muDoubleScalarCos(c17_dq_x);
  c17_sf_a = c17_ag_y;
  c17_bg_b = c17_dq_x;
  c17_bg_y = c17_sf_a * c17_bg_b;
  c17_eq_x = c17_theta4;
  c17_fq_x = c17_eq_x;
  c17_fq_x = muDoubleScalarSin(c17_fq_x);
  c17_tf_a = c17_yf_y - c17_bg_y;
  c17_cg_b = c17_fq_x;
  c17_cg_y = c17_tf_a * c17_cg_b;
  c17_gq_x = c17_theta5;
  c17_hq_x = c17_gq_x;
  c17_hq_x = muDoubleScalarSin(c17_hq_x);
  c17_uf_a = -(c17_wf_y + c17_cg_y);
  c17_dg_b = c17_hq_x;
  c17_dg_y = c17_uf_a * c17_dg_b;
  c17_iq_x = c17_theta1;
  c17_jq_x = c17_iq_x;
  c17_jq_x = muDoubleScalarCos(c17_jq_x);
  c17_kq_x = c17_theta5;
  c17_lq_x = c17_kq_x;
  c17_lq_x = muDoubleScalarCos(c17_lq_x);
  c17_vf_a = c17_jq_x;
  c17_eg_b = c17_lq_x;
  c17_eg_y = c17_vf_a * c17_eg_b;
  c17_mq_x = c17_theta1;
  c17_nq_x = c17_mq_x;
  c17_nq_x = muDoubleScalarSin(c17_nq_x);
  c17_oq_x = c17_theta2;
  c17_pq_x = c17_oq_x;
  c17_pq_x = muDoubleScalarCos(c17_pq_x);
  c17_wf_a = c17_nq_x;
  c17_fg_b = c17_pq_x;
  c17_fg_y = c17_wf_a * c17_fg_b;
  c17_qq_x = c17_theta3;
  c17_rq_x = c17_qq_x;
  c17_rq_x = muDoubleScalarCos(c17_rq_x);
  c17_xf_a = c17_fg_y;
  c17_gg_b = c17_rq_x;
  c17_gg_y = c17_xf_a * c17_gg_b;
  c17_sq_x = c17_theta1;
  c17_tq_x = c17_sq_x;
  c17_tq_x = muDoubleScalarSin(c17_tq_x);
  c17_uq_x = c17_theta2;
  c17_vq_x = c17_uq_x;
  c17_vq_x = muDoubleScalarSin(c17_vq_x);
  c17_yf_a = c17_tq_x;
  c17_hg_b = c17_vq_x;
  c17_hg_y = c17_yf_a * c17_hg_b;
  c17_wq_x = c17_theta3;
  c17_xq_x = c17_wq_x;
  c17_xq_x = muDoubleScalarSin(c17_xq_x);
  c17_ag_a = c17_hg_y;
  c17_ig_b = c17_xq_x;
  c17_ig_y = c17_ag_a * c17_ig_b;
  c17_yq_x = c17_theta4;
  c17_ar_x = c17_yq_x;
  c17_ar_x = muDoubleScalarCos(c17_ar_x);
  c17_bg_a = c17_gg_y - c17_ig_y;
  c17_jg_b = c17_ar_x;
  c17_jg_y = c17_bg_a * c17_jg_b;
  c17_br_x = c17_theta1;
  c17_cr_x = c17_br_x;
  c17_cr_x = muDoubleScalarSin(c17_cr_x);
  c17_dr_x = c17_theta2;
  c17_er_x = c17_dr_x;
  c17_er_x = muDoubleScalarCos(c17_er_x);
  c17_cg_a = -c17_cr_x;
  c17_kg_b = c17_er_x;
  c17_kg_y = c17_cg_a * c17_kg_b;
  c17_fr_x = c17_theta3;
  c17_gr_x = c17_fr_x;
  c17_gr_x = muDoubleScalarSin(c17_gr_x);
  c17_dg_a = c17_kg_y;
  c17_lg_b = c17_gr_x;
  c17_lg_y = c17_dg_a * c17_lg_b;
  c17_hr_x = c17_theta1;
  c17_ir_x = c17_hr_x;
  c17_ir_x = muDoubleScalarSin(c17_ir_x);
  c17_jr_x = c17_theta2;
  c17_kr_x = c17_jr_x;
  c17_kr_x = muDoubleScalarSin(c17_kr_x);
  c17_eg_a = c17_ir_x;
  c17_mg_b = c17_kr_x;
  c17_mg_y = c17_eg_a * c17_mg_b;
  c17_lr_x = c17_theta3;
  c17_mr_x = c17_lr_x;
  c17_mr_x = muDoubleScalarCos(c17_mr_x);
  c17_fg_a = c17_mg_y;
  c17_ng_b = c17_mr_x;
  c17_ng_y = c17_fg_a * c17_ng_b;
  c17_nr_x = c17_theta4;
  c17_or_x = c17_nr_x;
  c17_or_x = muDoubleScalarSin(c17_or_x);
  c17_gg_a = c17_lg_y - c17_ng_y;
  c17_og_b = c17_or_x;
  c17_og_y = c17_gg_a * c17_og_b;
  c17_pg_b = c17_jg_y + c17_og_y;
  c17_pg_y = -0.082 * c17_pg_b;
  c17_pr_x = c17_theta5;
  c17_qr_x = c17_pr_x;
  c17_qr_x = muDoubleScalarSin(c17_qr_x);
  c17_hg_a = c17_pg_y;
  c17_qg_b = c17_qr_x;
  c17_qg_y = c17_hg_a * c17_qg_b;
  c17_rr_x = c17_theta1;
  c17_sr_x = c17_rr_x;
  c17_sr_x = muDoubleScalarCos(c17_sr_x);
  c17_rg_b = c17_sr_x;
  c17_rg_y = 0.082 * c17_rg_b;
  c17_tr_x = c17_theta5;
  c17_ur_x = c17_tr_x;
  c17_ur_x = muDoubleScalarCos(c17_ur_x);
  c17_ig_a = c17_rg_y;
  c17_sg_b = c17_ur_x;
  c17_sg_y = c17_ig_a * c17_sg_b;
  c17_vr_x = c17_theta1;
  c17_wr_x = c17_vr_x;
  c17_wr_x = muDoubleScalarSin(c17_wr_x);
  c17_xr_x = c17_theta2;
  c17_yr_x = c17_xr_x;
  c17_yr_x = muDoubleScalarCos(c17_yr_x);
  c17_jg_a = c17_wr_x;
  c17_tg_b = c17_yr_x;
  c17_tg_y = c17_jg_a * c17_tg_b;
  c17_as_x = c17_theta3;
  c17_bs_x = c17_as_x;
  c17_bs_x = muDoubleScalarCos(c17_bs_x);
  c17_kg_a = c17_tg_y;
  c17_ug_b = c17_bs_x;
  c17_ug_y = c17_kg_a * c17_ug_b;
  c17_cs_x = c17_theta1;
  c17_ds_x = c17_cs_x;
  c17_ds_x = muDoubleScalarSin(c17_ds_x);
  c17_es_x = c17_theta2;
  c17_fs_x = c17_es_x;
  c17_fs_x = muDoubleScalarSin(c17_fs_x);
  c17_lg_a = c17_ds_x;
  c17_vg_b = c17_fs_x;
  c17_vg_y = c17_lg_a * c17_vg_b;
  c17_gs_x = c17_theta3;
  c17_hs_x = c17_gs_x;
  c17_hs_x = muDoubleScalarSin(c17_hs_x);
  c17_mg_a = c17_vg_y;
  c17_wg_b = c17_hs_x;
  c17_wg_y = c17_mg_a * c17_wg_b;
  c17_xg_b = c17_ug_y - c17_wg_y;
  c17_xg_y = 0.093 * c17_xg_b;
  c17_is_x = c17_theta4;
  c17_js_x = c17_is_x;
  c17_js_x = muDoubleScalarSin(c17_js_x);
  c17_ng_a = c17_xg_y;
  c17_yg_b = c17_js_x;
  c17_yg_y = c17_ng_a * c17_yg_b;
  c17_ks_x = c17_theta1;
  c17_ls_x = c17_ks_x;
  c17_ls_x = muDoubleScalarSin(c17_ls_x);
  c17_ms_x = c17_theta2;
  c17_ns_x = c17_ms_x;
  c17_ns_x = muDoubleScalarCos(c17_ns_x);
  c17_og_a = -c17_ls_x;
  c17_ah_b = c17_ns_x;
  c17_ah_y = c17_og_a * c17_ah_b;
  c17_os_x = c17_theta3;
  c17_ps_x = c17_os_x;
  c17_ps_x = muDoubleScalarSin(c17_ps_x);
  c17_pg_a = c17_ah_y;
  c17_bh_b = c17_ps_x;
  c17_bh_y = c17_pg_a * c17_bh_b;
  c17_qs_x = c17_theta1;
  c17_rs_x = c17_qs_x;
  c17_rs_x = muDoubleScalarSin(c17_rs_x);
  c17_ss_x = c17_theta2;
  c17_ts_x = c17_ss_x;
  c17_ts_x = muDoubleScalarSin(c17_ts_x);
  c17_qg_a = c17_rs_x;
  c17_ch_b = c17_ts_x;
  c17_ch_y = c17_qg_a * c17_ch_b;
  c17_us_x = c17_theta3;
  c17_vs_x = c17_us_x;
  c17_vs_x = muDoubleScalarCos(c17_vs_x);
  c17_rg_a = c17_ch_y;
  c17_dh_b = c17_vs_x;
  c17_dh_y = c17_rg_a * c17_dh_b;
  c17_eh_b = c17_bh_y - c17_dh_y;
  c17_eh_y = 0.093 * c17_eh_b;
  c17_ws_x = c17_theta4;
  c17_xs_x = c17_ws_x;
  c17_xs_x = muDoubleScalarCos(c17_xs_x);
  c17_sg_a = c17_eh_y;
  c17_fh_b = c17_xs_x;
  c17_fh_y = c17_sg_a * c17_fh_b;
  c17_ys_x = c17_theta1;
  c17_at_x = c17_ys_x;
  c17_at_x = muDoubleScalarCos(c17_at_x);
  c17_gh_b = c17_at_x;
  c17_gh_y = 0.109 * c17_gh_b;
  c17_bt_x = c17_theta1;
  c17_ct_x = c17_bt_x;
  c17_ct_x = muDoubleScalarSin(c17_ct_x);
  c17_hh_b = c17_ct_x;
  c17_hh_y = 0.39243 * c17_hh_b;
  c17_dt_x = c17_theta2;
  c17_et_x = c17_dt_x;
  c17_et_x = muDoubleScalarCos(c17_et_x);
  c17_tg_a = c17_hh_y;
  c17_ih_b = c17_et_x;
  c17_ih_y = c17_tg_a * c17_ih_b;
  c17_ft_x = c17_theta3;
  c17_gt_x = c17_ft_x;
  c17_gt_x = muDoubleScalarCos(c17_gt_x);
  c17_ug_a = c17_ih_y;
  c17_jh_b = c17_gt_x;
  c17_jh_y = c17_ug_a * c17_jh_b;
  c17_ht_x = c17_theta1;
  c17_it_x = c17_ht_x;
  c17_it_x = muDoubleScalarSin(c17_it_x);
  c17_kh_b = c17_it_x;
  c17_kh_y = 0.39243 * c17_kh_b;
  c17_jt_x = c17_theta2;
  c17_kt_x = c17_jt_x;
  c17_kt_x = muDoubleScalarSin(c17_kt_x);
  c17_vg_a = c17_kh_y;
  c17_lh_b = c17_kt_x;
  c17_lh_y = c17_vg_a * c17_lh_b;
  c17_lt_x = c17_theta3;
  c17_mt_x = c17_lt_x;
  c17_mt_x = muDoubleScalarSin(c17_mt_x);
  c17_wg_a = c17_lh_y;
  c17_mh_b = c17_mt_x;
  c17_mh_y = c17_wg_a * c17_mh_b;
  c17_nt_x = c17_theta1;
  c17_ot_x = c17_nt_x;
  c17_ot_x = muDoubleScalarSin(c17_ot_x);
  c17_nh_b = c17_ot_x;
  c17_nh_y = 0.425 * c17_nh_b;
  c17_pt_x = c17_theta2;
  c17_qt_x = c17_pt_x;
  c17_qt_x = muDoubleScalarCos(c17_qt_x);
  c17_xg_a = c17_nh_y;
  c17_oh_b = c17_qt_x;
  c17_oh_y = c17_xg_a * c17_oh_b;
  c17_rt_x = c17_theta2;
  c17_st_x = c17_rt_x;
  c17_st_x = muDoubleScalarSin(c17_st_x);
  c17_tt_x = c17_theta3;
  c17_ut_x = c17_tt_x;
  c17_ut_x = muDoubleScalarCos(c17_ut_x);
  c17_yg_a = c17_st_x;
  c17_ph_b = c17_ut_x;
  c17_ph_y = c17_yg_a * c17_ph_b;
  c17_vt_x = c17_theta2;
  c17_wt_x = c17_vt_x;
  c17_wt_x = muDoubleScalarCos(c17_wt_x);
  c17_xt_x = c17_theta3;
  c17_yt_x = c17_xt_x;
  c17_yt_x = muDoubleScalarSin(c17_yt_x);
  c17_ah_a = c17_wt_x;
  c17_qh_b = c17_yt_x;
  c17_qh_y = c17_ah_a * c17_qh_b;
  c17_au_x = c17_theta4;
  c17_bu_x = c17_au_x;
  c17_bu_x = muDoubleScalarCos(c17_bu_x);
  c17_bh_a = c17_ph_y + c17_qh_y;
  c17_rh_b = c17_bu_x;
  c17_rh_y = c17_bh_a * c17_rh_b;
  c17_cu_x = c17_theta2;
  c17_du_x = c17_cu_x;
  c17_du_x = muDoubleScalarSin(c17_du_x);
  c17_eu_x = c17_theta3;
  c17_fu_x = c17_eu_x;
  c17_fu_x = muDoubleScalarSin(c17_fu_x);
  c17_ch_a = -c17_du_x;
  c17_sh_b = c17_fu_x;
  c17_sh_y = c17_ch_a * c17_sh_b;
  c17_gu_x = c17_theta2;
  c17_hu_x = c17_gu_x;
  c17_hu_x = muDoubleScalarCos(c17_hu_x);
  c17_iu_x = c17_theta3;
  c17_ju_x = c17_iu_x;
  c17_ju_x = muDoubleScalarCos(c17_ju_x);
  c17_dh_a = c17_hu_x;
  c17_th_b = c17_ju_x;
  c17_th_y = c17_dh_a * c17_th_b;
  c17_ku_x = c17_theta4;
  c17_lu_x = c17_ku_x;
  c17_lu_x = muDoubleScalarSin(c17_lu_x);
  c17_eh_a = c17_sh_y + c17_th_y;
  c17_uh_b = c17_lu_x;
  c17_uh_y = c17_eh_a * c17_uh_b;
  c17_mu_x = c17_theta5;
  c17_nu_x = c17_mu_x;
  c17_nu_x = muDoubleScalarCos(c17_nu_x);
  c17_fh_a = c17_rh_y + c17_uh_y;
  c17_vh_b = c17_nu_x;
  c17_vh_y = c17_fh_a * c17_vh_b;
  c17_ou_x = c17_theta6;
  c17_pu_x = c17_ou_x;
  c17_pu_x = muDoubleScalarCos(c17_pu_x);
  c17_gh_a = c17_vh_y;
  c17_wh_b = c17_pu_x;
  c17_wh_y = c17_gh_a * c17_wh_b;
  c17_qu_x = c17_theta2;
  c17_ru_x = c17_qu_x;
  c17_ru_x = muDoubleScalarSin(c17_ru_x);
  c17_su_x = c17_theta3;
  c17_tu_x = c17_su_x;
  c17_tu_x = muDoubleScalarCos(c17_tu_x);
  c17_hh_a = c17_ru_x;
  c17_xh_b = c17_tu_x;
  c17_xh_y = c17_hh_a * c17_xh_b;
  c17_uu_x = c17_theta2;
  c17_vu_x = c17_uu_x;
  c17_vu_x = muDoubleScalarCos(c17_vu_x);
  c17_wu_x = c17_theta3;
  c17_xu_x = c17_wu_x;
  c17_xu_x = muDoubleScalarSin(c17_xu_x);
  c17_ih_a = c17_vu_x;
  c17_yh_b = c17_xu_x;
  c17_yh_y = c17_ih_a * c17_yh_b;
  c17_yu_x = c17_theta4;
  c17_av_x = c17_yu_x;
  c17_av_x = muDoubleScalarSin(c17_av_x);
  c17_jh_a = -(c17_xh_y + c17_yh_y);
  c17_ai_b = c17_av_x;
  c17_ai_y = c17_jh_a * c17_ai_b;
  c17_bv_x = c17_theta2;
  c17_cv_x = c17_bv_x;
  c17_cv_x = muDoubleScalarSin(c17_cv_x);
  c17_dv_x = c17_theta3;
  c17_ev_x = c17_dv_x;
  c17_ev_x = muDoubleScalarSin(c17_ev_x);
  c17_kh_a = -c17_cv_x;
  c17_bi_b = c17_ev_x;
  c17_bi_y = c17_kh_a * c17_bi_b;
  c17_fv_x = c17_theta2;
  c17_gv_x = c17_fv_x;
  c17_gv_x = muDoubleScalarCos(c17_gv_x);
  c17_hv_x = c17_theta3;
  c17_iv_x = c17_hv_x;
  c17_iv_x = muDoubleScalarCos(c17_iv_x);
  c17_lh_a = c17_gv_x;
  c17_ci_b = c17_iv_x;
  c17_ci_y = c17_lh_a * c17_ci_b;
  c17_jv_x = c17_theta4;
  c17_kv_x = c17_jv_x;
  c17_kv_x = muDoubleScalarCos(c17_kv_x);
  c17_mh_a = c17_bi_y + c17_ci_y;
  c17_di_b = c17_kv_x;
  c17_di_y = c17_mh_a * c17_di_b;
  c17_lv_x = c17_theta6;
  c17_mv_x = c17_lv_x;
  c17_mv_x = muDoubleScalarSin(c17_mv_x);
  c17_nh_a = c17_ai_y + c17_di_y;
  c17_ei_b = c17_mv_x;
  c17_ei_y = c17_nh_a * c17_ei_b;
  c17_nv_x = c17_theta2;
  c17_ov_x = c17_nv_x;
  c17_ov_x = muDoubleScalarSin(c17_ov_x);
  c17_pv_x = c17_theta3;
  c17_qv_x = c17_pv_x;
  c17_qv_x = muDoubleScalarCos(c17_qv_x);
  c17_oh_a = c17_ov_x;
  c17_fi_b = c17_qv_x;
  c17_fi_y = c17_oh_a * c17_fi_b;
  c17_rv_x = c17_theta2;
  c17_sv_x = c17_rv_x;
  c17_sv_x = muDoubleScalarCos(c17_sv_x);
  c17_tv_x = c17_theta3;
  c17_uv_x = c17_tv_x;
  c17_uv_x = muDoubleScalarSin(c17_uv_x);
  c17_ph_a = c17_sv_x;
  c17_gi_b = c17_uv_x;
  c17_gi_y = c17_ph_a * c17_gi_b;
  c17_vv_x = c17_theta4;
  c17_wv_x = c17_vv_x;
  c17_wv_x = muDoubleScalarCos(c17_wv_x);
  c17_qh_a = c17_fi_y + c17_gi_y;
  c17_hi_b = c17_wv_x;
  c17_hi_y = c17_qh_a * c17_hi_b;
  c17_xv_x = c17_theta2;
  c17_yv_x = c17_xv_x;
  c17_yv_x = muDoubleScalarSin(c17_yv_x);
  c17_aw_x = c17_theta3;
  c17_bw_x = c17_aw_x;
  c17_bw_x = muDoubleScalarSin(c17_bw_x);
  c17_rh_a = -c17_yv_x;
  c17_ii_b = c17_bw_x;
  c17_ii_y = c17_rh_a * c17_ii_b;
  c17_cw_x = c17_theta2;
  c17_dw_x = c17_cw_x;
  c17_dw_x = muDoubleScalarCos(c17_dw_x);
  c17_ew_x = c17_theta3;
  c17_fw_x = c17_ew_x;
  c17_fw_x = muDoubleScalarCos(c17_fw_x);
  c17_sh_a = c17_dw_x;
  c17_ji_b = c17_fw_x;
  c17_ji_y = c17_sh_a * c17_ji_b;
  c17_gw_x = c17_theta4;
  c17_hw_x = c17_gw_x;
  c17_hw_x = muDoubleScalarSin(c17_hw_x);
  c17_th_a = c17_ii_y + c17_ji_y;
  c17_ki_b = c17_hw_x;
  c17_ki_y = c17_th_a * c17_ki_b;
  c17_iw_x = c17_theta5;
  c17_jw_x = c17_iw_x;
  c17_jw_x = muDoubleScalarCos(c17_jw_x);
  c17_uh_a = -(c17_hi_y + c17_ki_y);
  c17_li_b = c17_jw_x;
  c17_li_y = c17_uh_a * c17_li_b;
  c17_kw_x = c17_theta6;
  c17_lw_x = c17_kw_x;
  c17_lw_x = muDoubleScalarSin(c17_lw_x);
  c17_vh_a = c17_li_y;
  c17_mi_b = c17_lw_x;
  c17_mi_y = c17_vh_a * c17_mi_b;
  c17_mw_x = c17_theta2;
  c17_nw_x = c17_mw_x;
  c17_nw_x = muDoubleScalarSin(c17_nw_x);
  c17_ow_x = c17_theta3;
  c17_pw_x = c17_ow_x;
  c17_pw_x = muDoubleScalarCos(c17_pw_x);
  c17_wh_a = c17_nw_x;
  c17_ni_b = c17_pw_x;
  c17_ni_y = c17_wh_a * c17_ni_b;
  c17_qw_x = c17_theta2;
  c17_rw_x = c17_qw_x;
  c17_rw_x = muDoubleScalarCos(c17_rw_x);
  c17_sw_x = c17_theta3;
  c17_tw_x = c17_sw_x;
  c17_tw_x = muDoubleScalarSin(c17_tw_x);
  c17_xh_a = c17_rw_x;
  c17_oi_b = c17_tw_x;
  c17_oi_y = c17_xh_a * c17_oi_b;
  c17_uw_x = c17_theta4;
  c17_vw_x = c17_uw_x;
  c17_vw_x = muDoubleScalarSin(c17_vw_x);
  c17_yh_a = -(c17_ni_y + c17_oi_y);
  c17_pi_b = c17_vw_x;
  c17_pi_y = c17_yh_a * c17_pi_b;
  c17_ww_x = c17_theta2;
  c17_xw_x = c17_ww_x;
  c17_xw_x = muDoubleScalarSin(c17_xw_x);
  c17_yw_x = c17_theta3;
  c17_ax_x = c17_yw_x;
  c17_ax_x = muDoubleScalarSin(c17_ax_x);
  c17_ai_a = -c17_xw_x;
  c17_qi_b = c17_ax_x;
  c17_qi_y = c17_ai_a * c17_qi_b;
  c17_bx_x = c17_theta2;
  c17_cx_x = c17_bx_x;
  c17_cx_x = muDoubleScalarCos(c17_cx_x);
  c17_dx_x = c17_theta3;
  c17_ex_x = c17_dx_x;
  c17_ex_x = muDoubleScalarCos(c17_ex_x);
  c17_bi_a = c17_cx_x;
  c17_ri_b = c17_ex_x;
  c17_ri_y = c17_bi_a * c17_ri_b;
  c17_fx_x = c17_theta4;
  c17_gx_x = c17_fx_x;
  c17_gx_x = muDoubleScalarCos(c17_gx_x);
  c17_ci_a = c17_qi_y + c17_ri_y;
  c17_si_b = c17_gx_x;
  c17_si_y = c17_ci_a * c17_si_b;
  c17_hx_x = c17_theta6;
  c17_ix_x = c17_hx_x;
  c17_ix_x = muDoubleScalarCos(c17_ix_x);
  c17_di_a = c17_pi_y + c17_si_y;
  c17_ti_b = c17_ix_x;
  c17_ti_y = c17_di_a * c17_ti_b;
  c17_jx_x = c17_theta2;
  c17_kx_x = c17_jx_x;
  c17_kx_x = muDoubleScalarSin(c17_kx_x);
  c17_lx_x = c17_theta3;
  c17_mx_x = c17_lx_x;
  c17_mx_x = muDoubleScalarCos(c17_mx_x);
  c17_ei_a = c17_kx_x;
  c17_ui_b = c17_mx_x;
  c17_ui_y = c17_ei_a * c17_ui_b;
  c17_nx_x = c17_theta2;
  c17_ox_x = c17_nx_x;
  c17_ox_x = muDoubleScalarCos(c17_ox_x);
  c17_px_x = c17_theta3;
  c17_qx_x = c17_px_x;
  c17_qx_x = muDoubleScalarSin(c17_qx_x);
  c17_fi_a = c17_ox_x;
  c17_vi_b = c17_qx_x;
  c17_vi_y = c17_fi_a * c17_vi_b;
  c17_rx_x = c17_theta4;
  c17_sx_x = c17_rx_x;
  c17_sx_x = muDoubleScalarCos(c17_sx_x);
  c17_gi_a = c17_ui_y + c17_vi_y;
  c17_wi_b = c17_sx_x;
  c17_wi_y = c17_gi_a * c17_wi_b;
  c17_tx_x = c17_theta2;
  c17_ux_x = c17_tx_x;
  c17_ux_x = muDoubleScalarSin(c17_ux_x);
  c17_vx_x = c17_theta3;
  c17_wx_x = c17_vx_x;
  c17_wx_x = muDoubleScalarSin(c17_wx_x);
  c17_hi_a = -c17_ux_x;
  c17_xi_b = c17_wx_x;
  c17_xi_y = c17_hi_a * c17_xi_b;
  c17_xx_x = c17_theta2;
  c17_yx_x = c17_xx_x;
  c17_yx_x = muDoubleScalarCos(c17_yx_x);
  c17_ay_x = c17_theta3;
  c17_by_x = c17_ay_x;
  c17_by_x = muDoubleScalarCos(c17_by_x);
  c17_ii_a = c17_yx_x;
  c17_yi_b = c17_by_x;
  c17_yi_y = c17_ii_a * c17_yi_b;
  c17_cy_x = c17_theta4;
  c17_dy_x = c17_cy_x;
  c17_dy_x = muDoubleScalarSin(c17_dy_x);
  c17_ji_a = c17_xi_y + c17_yi_y;
  c17_aj_b = c17_dy_x;
  c17_aj_y = c17_ji_a * c17_aj_b;
  c17_ey_x = c17_theta5;
  c17_fy_x = c17_ey_x;
  c17_fy_x = muDoubleScalarSin(c17_fy_x);
  c17_ki_a = -(c17_wi_y + c17_aj_y);
  c17_bj_b = c17_fy_x;
  c17_bj_y = c17_ki_a * c17_bj_b;
  c17_gy_x = c17_theta2;
  c17_hy_x = c17_gy_x;
  c17_hy_x = muDoubleScalarSin(c17_hy_x);
  c17_iy_x = c17_theta3;
  c17_jy_x = c17_iy_x;
  c17_jy_x = muDoubleScalarCos(c17_jy_x);
  c17_li_a = c17_hy_x;
  c17_cj_b = c17_jy_x;
  c17_cj_y = c17_li_a * c17_cj_b;
  c17_ky_x = c17_theta2;
  c17_ly_x = c17_ky_x;
  c17_ly_x = muDoubleScalarCos(c17_ly_x);
  c17_my_x = c17_theta3;
  c17_ny_x = c17_my_x;
  c17_ny_x = muDoubleScalarSin(c17_ny_x);
  c17_mi_a = c17_ly_x;
  c17_dj_b = c17_ny_x;
  c17_dj_y = c17_mi_a * c17_dj_b;
  c17_oy_x = c17_theta4;
  c17_py_x = c17_oy_x;
  c17_py_x = muDoubleScalarCos(c17_py_x);
  c17_ni_a = c17_cj_y + c17_dj_y;
  c17_ej_b = c17_py_x;
  c17_ej_y = c17_ni_a * c17_ej_b;
  c17_qy_x = c17_theta2;
  c17_ry_x = c17_qy_x;
  c17_ry_x = muDoubleScalarSin(c17_ry_x);
  c17_sy_x = c17_theta3;
  c17_ty_x = c17_sy_x;
  c17_ty_x = muDoubleScalarSin(c17_ty_x);
  c17_oi_a = -c17_ry_x;
  c17_fj_b = c17_ty_x;
  c17_fj_y = c17_oi_a * c17_fj_b;
  c17_uy_x = c17_theta2;
  c17_vy_x = c17_uy_x;
  c17_vy_x = muDoubleScalarCos(c17_vy_x);
  c17_wy_x = c17_theta3;
  c17_xy_x = c17_wy_x;
  c17_xy_x = muDoubleScalarCos(c17_xy_x);
  c17_pi_a = c17_vy_x;
  c17_gj_b = c17_xy_x;
  c17_gj_y = c17_pi_a * c17_gj_b;
  c17_yy_x = c17_theta4;
  c17_aab_x = c17_yy_x;
  c17_aab_x = muDoubleScalarSin(c17_aab_x);
  c17_qi_a = c17_fj_y + c17_gj_y;
  c17_hj_b = c17_aab_x;
  c17_hj_y = c17_qi_a * c17_hj_b;
  c17_ij_b = c17_ej_y + c17_hj_y;
  c17_ij_y = 0.082 * c17_ij_b;
  c17_bab_x = c17_theta5;
  c17_cab_x = c17_bab_x;
  c17_cab_x = muDoubleScalarSin(c17_cab_x);
  c17_ri_a = c17_ij_y;
  c17_jj_b = c17_cab_x;
  c17_jj_y = c17_ri_a * c17_jj_b;
  c17_dab_x = c17_theta2;
  c17_eab_x = c17_dab_x;
  c17_eab_x = muDoubleScalarSin(c17_eab_x);
  c17_fab_x = c17_theta3;
  c17_gab_x = c17_fab_x;
  c17_gab_x = muDoubleScalarCos(c17_gab_x);
  c17_si_a = c17_eab_x;
  c17_kj_b = c17_gab_x;
  c17_kj_y = c17_si_a * c17_kj_b;
  c17_hab_x = c17_theta2;
  c17_iab_x = c17_hab_x;
  c17_iab_x = muDoubleScalarCos(c17_iab_x);
  c17_jab_x = c17_theta3;
  c17_kab_x = c17_jab_x;
  c17_kab_x = muDoubleScalarSin(c17_kab_x);
  c17_ti_a = c17_iab_x;
  c17_lj_b = c17_kab_x;
  c17_lj_y = c17_ti_a * c17_lj_b;
  c17_mj_b = c17_kj_y + c17_lj_y;
  c17_mj_y = 0.093 * c17_mj_b;
  c17_lab_x = c17_theta4;
  c17_mab_x = c17_lab_x;
  c17_mab_x = muDoubleScalarSin(c17_mab_x);
  c17_ui_a = c17_mj_y;
  c17_nj_b = c17_mab_x;
  c17_nj_y = c17_ui_a * c17_nj_b;
  c17_nab_x = c17_theta2;
  c17_oab_x = c17_nab_x;
  c17_oab_x = muDoubleScalarSin(c17_oab_x);
  c17_pab_x = c17_theta3;
  c17_qab_x = c17_pab_x;
  c17_qab_x = muDoubleScalarSin(c17_qab_x);
  c17_vi_a = -c17_oab_x;
  c17_oj_b = c17_qab_x;
  c17_oj_y = c17_vi_a * c17_oj_b;
  c17_rab_x = c17_theta2;
  c17_sab_x = c17_rab_x;
  c17_sab_x = muDoubleScalarCos(c17_sab_x);
  c17_tab_x = c17_theta3;
  c17_uab_x = c17_tab_x;
  c17_uab_x = muDoubleScalarCos(c17_uab_x);
  c17_wi_a = c17_sab_x;
  c17_pj_b = c17_uab_x;
  c17_pj_y = c17_wi_a * c17_pj_b;
  c17_qj_b = c17_oj_y + c17_pj_y;
  c17_qj_y = 0.093 * c17_qj_b;
  c17_vab_x = c17_theta4;
  c17_wab_x = c17_vab_x;
  c17_wab_x = muDoubleScalarCos(c17_wab_x);
  c17_xi_a = c17_qj_y;
  c17_rj_b = c17_wab_x;
  c17_rj_y = c17_xi_a * c17_rj_b;
  c17_xab_x = c17_theta2;
  c17_yab_x = c17_xab_x;
  c17_yab_x = muDoubleScalarSin(c17_yab_x);
  c17_sj_b = c17_yab_x;
  c17_sj_y = 0.39243 * c17_sj_b;
  c17_abb_x = c17_theta3;
  c17_bbb_x = c17_abb_x;
  c17_bbb_x = muDoubleScalarCos(c17_bbb_x);
  c17_yi_a = c17_sj_y;
  c17_tj_b = c17_bbb_x;
  c17_tj_y = c17_yi_a * c17_tj_b;
  c17_cbb_x = c17_theta2;
  c17_dbb_x = c17_cbb_x;
  c17_dbb_x = muDoubleScalarCos(c17_dbb_x);
  c17_uj_b = c17_dbb_x;
  c17_uj_y = 0.39243 * c17_uj_b;
  c17_ebb_x = c17_theta3;
  c17_fbb_x = c17_ebb_x;
  c17_fbb_x = muDoubleScalarSin(c17_fbb_x);
  c17_aj_a = c17_uj_y;
  c17_vj_b = c17_fbb_x;
  c17_vj_y = c17_aj_a * c17_vj_b;
  c17_gbb_x = c17_theta2;
  c17_hbb_x = c17_gbb_x;
  c17_hbb_x = muDoubleScalarSin(c17_hbb_x);
  c17_wj_b = c17_hbb_x;
  c17_wj_y = 0.425 * c17_wj_b;
  c17_T[0] = c17_m_y + c17_x_y;
  c17_T[4] = c17_lb_y + c17_wb_y;
  c17_T[8] = c17_ic_y + c17_jc_y;
  c17_T[12] = ((((((c17_vc_y + c17_xc_y) + c17_ed_y) - c17_kd_y) + c17_ld_y) -
                c17_od_y) + c17_rd_y) - c17_td_y;
  c17_T[1] = c17_he_y + c17_se_y;
  c17_T[5] = c17_gf_y + c17_rf_y;
  c17_T[9] = c17_dg_y - c17_eg_y;
  c17_T[13] = ((((((c17_qg_y - c17_sg_y) + c17_yg_y) - c17_fh_y) - c17_gh_y) -
                c17_jh_y) + c17_mh_y) - c17_oh_y;
  c17_T[2] = c17_wh_y + c17_ei_y;
  c17_T[6] = c17_mi_y + c17_ti_y;
  c17_T[10] = c17_bj_y;
  c17_T[14] = (((((0.0892 - c17_jj_y) + c17_nj_y) - c17_rj_y) - c17_tj_y) -
               c17_vj_y) - c17_wj_y;
  c17_i8 = 0;
  for (c17_i9 = 0; c17_i9 < 4; c17_i9++) {
    c17_T[c17_i8 + 3] = c17_dv2[c17_i9];
    c17_i8 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 86);
  c17_i10 = 0;
  c17_i11 = 0;
  for (c17_i12 = 0; c17_i12 < 3; c17_i12++) {
    for (c17_i13 = 0; c17_i13 < 3; c17_i13++) {
      c17_R[c17_i13 + c17_i10] = c17_T[c17_i13 + c17_i11];
    }

    c17_i10 += 3;
    c17_i11 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 87);
  for (c17_i14 = 0; c17_i14 < 3; c17_i14++) {
    c17_d[c17_i14] = c17_T[c17_i14 + 12];
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -87);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i15 = 0; c17_i15 < 3; c17_i15++) {
    (*c17_b_d)[c17_i15] = c17_d[c17_i15];
  }

  for (c17_i16 = 0; c17_i16 < 9; c17_i16++) {
    (*c17_b_R)[c17_i16] = c17_R[c17_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c17_sfEvent);
}

static void initSimStructsc17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc17_JointSpaceControl_BestInertia
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber)
{
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i17;
  int32_T c17_i18;
  int32_T c17_i19;
  real_T c17_b_inData[9];
  int32_T c17_i20;
  int32_T c17_i21;
  int32_T c17_i22;
  real_T c17_u[9];
  const mxArray *c17_y = NULL;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_i17 = 0;
  for (c17_i18 = 0; c17_i18 < 3; c17_i18++) {
    for (c17_i19 = 0; c17_i19 < 3; c17_i19++) {
      c17_b_inData[c17_i19 + c17_i17] = (*(real_T (*)[9])c17_inData)[c17_i19 +
        c17_i17];
    }

    c17_i17 += 3;
  }

  c17_i20 = 0;
  for (c17_i21 = 0; c17_i21 < 3; c17_i21++) {
    for (c17_i22 = 0; c17_i22 < 3; c17_i22++) {
      c17_u[c17_i22 + c17_i20] = c17_b_inData[c17_i22 + c17_i20];
    }

    c17_i20 += 3;
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static void c17_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_R, const char_T *c17_identifier, real_T c17_y[9])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_R), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_R);
}

static void c17_b_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[9])
{
  real_T c17_dv3[9];
  int32_T c17_i23;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c17_i23 = 0; c17_i23 < 9; c17_i23++) {
    c17_y[c17_i23] = c17_dv3[c17_i23];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_R;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[9];
  int32_T c17_i24;
  int32_T c17_i25;
  int32_T c17_i26;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_R = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_R), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_R);
  c17_i24 = 0;
  for (c17_i25 = 0; c17_i25 < 3; c17_i25++) {
    for (c17_i26 = 0; c17_i26 < 3; c17_i26++) {
      (*(real_T (*)[9])c17_outData)[c17_i26 + c17_i24] = c17_y[c17_i26 + c17_i24];
    }

    c17_i24 += 3;
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i27;
  real_T c17_b_inData[3];
  int32_T c17_i28;
  real_T c17_u[3];
  const mxArray *c17_y = NULL;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i27 = 0; c17_i27 < 3; c17_i27++) {
    c17_b_inData[c17_i27] = (*(real_T (*)[3])c17_inData)[c17_i27];
  }

  for (c17_i28 = 0; c17_i28 < 3; c17_i28++) {
    c17_u[c17_i28] = c17_b_inData[c17_i28];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static void c17_c_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_d, const char_T *c17_identifier, real_T c17_y[3])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_d), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_d);
}

static void c17_d_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[3])
{
  real_T c17_dv4[3];
  int32_T c17_i29;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c17_i29 = 0; c17_i29 < 3; c17_i29++) {
    c17_y[c17_i29] = c17_dv4[c17_i29];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_d;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[3];
  int32_T c17_i30;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_d = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_d), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_d);
  for (c17_i30 = 0; c17_i30 < 3; c17_i30++) {
    (*(real_T (*)[3])c17_outData)[c17_i30] = c17_y[c17_i30];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i31;
  real_T c17_b_inData[6];
  int32_T c17_i32;
  real_T c17_u[6];
  const mxArray *c17_y = NULL;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i31 = 0; c17_i31 < 6; c17_i31++) {
    c17_b_inData[c17_i31] = (*(real_T (*)[6])c17_inData)[c17_i31];
  }

  for (c17_i32 = 0; c17_i32 < 6; c17_i32++) {
    c17_u[c17_i32] = c17_b_inData[c17_i32];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static real_T c17_e_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_nargout;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_nargout = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i33;
  int32_T c17_i34;
  int32_T c17_i35;
  real_T c17_b_inData[16];
  int32_T c17_i36;
  int32_T c17_i37;
  int32_T c17_i38;
  real_T c17_u[16];
  const mxArray *c17_y = NULL;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_i33 = 0;
  for (c17_i34 = 0; c17_i34 < 4; c17_i34++) {
    for (c17_i35 = 0; c17_i35 < 4; c17_i35++) {
      c17_b_inData[c17_i35 + c17_i33] = (*(real_T (*)[16])c17_inData)[c17_i35 +
        c17_i33];
    }

    c17_i33 += 4;
  }

  c17_i36 = 0;
  for (c17_i37 = 0; c17_i37 < 4; c17_i37++) {
    for (c17_i38 = 0; c17_i38 < 4; c17_i38++) {
      c17_u[c17_i38 + c17_i36] = c17_b_inData[c17_i38 + c17_i36];
    }

    c17_i36 += 4;
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static void c17_f_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[16])
{
  real_T c17_dv5[16];
  int32_T c17_i39;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv5, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c17_i39 = 0; c17_i39 < 16; c17_i39++) {
    c17_y[c17_i39] = c17_dv5[c17_i39];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_T;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[16];
  int32_T c17_i40;
  int32_T c17_i41;
  int32_T c17_i42;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_T = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_T), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_T);
  c17_i40 = 0;
  for (c17_i41 = 0; c17_i41 < 4; c17_i41++) {
    for (c17_i42 = 0; c17_i42 < 4; c17_i42++) {
      (*(real_T (*)[16])c17_outData)[c17_i42 + c17_i40] = c17_y[c17_i42 +
        c17_i40];
    }

    c17_i40 += 4;
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray
  *sf_c17_JointSpaceControl_BestInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo;
  c17_ResolvedFunctionInfo c17_info[5];
  c17_ResolvedFunctionInfo (*c17_b_info)[5];
  const mxArray *c17_m0 = NULL;
  int32_T c17_i43;
  c17_ResolvedFunctionInfo *c17_r0;
  c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  c17_b_info = (c17_ResolvedFunctionInfo (*)[5])c17_info;
  (*c17_b_info)[0].context = "";
  (*c17_b_info)[0].name = "cos";
  (*c17_b_info)[0].dominantType = "double";
  (*c17_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c17_b_info)[0].fileTimeLo = 1343851972U;
  (*c17_b_info)[0].fileTimeHi = 0U;
  (*c17_b_info)[0].mFileTimeLo = 0U;
  (*c17_b_info)[0].mFileTimeHi = 0U;
  (*c17_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c17_b_info)[1].name = "eml_scalar_cos";
  (*c17_b_info)[1].dominantType = "double";
  (*c17_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c17_b_info)[1].fileTimeLo = 1286840322U;
  (*c17_b_info)[1].fileTimeHi = 0U;
  (*c17_b_info)[1].mFileTimeLo = 0U;
  (*c17_b_info)[1].mFileTimeHi = 0U;
  (*c17_b_info)[2].context = "";
  (*c17_b_info)[2].name = "mtimes";
  (*c17_b_info)[2].dominantType = "double";
  (*c17_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c17_b_info)[2].fileTimeLo = 1289541292U;
  (*c17_b_info)[2].fileTimeHi = 0U;
  (*c17_b_info)[2].mFileTimeLo = 0U;
  (*c17_b_info)[2].mFileTimeHi = 0U;
  (*c17_b_info)[3].context = "";
  (*c17_b_info)[3].name = "sin";
  (*c17_b_info)[3].dominantType = "double";
  (*c17_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c17_b_info)[3].fileTimeLo = 1343851986U;
  (*c17_b_info)[3].fileTimeHi = 0U;
  (*c17_b_info)[3].mFileTimeLo = 0U;
  (*c17_b_info)[3].mFileTimeHi = 0U;
  (*c17_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c17_b_info)[4].name = "eml_scalar_sin";
  (*c17_b_info)[4].dominantType = "double";
  (*c17_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c17_b_info)[4].fileTimeLo = 1286840336U;
  (*c17_b_info)[4].fileTimeHi = 0U;
  (*c17_b_info)[4].mFileTimeLo = 0U;
  (*c17_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c17_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c17_i43 = 0; c17_i43 < 5; c17_i43++) {
    c17_r0 = &c17_info[c17_i43];
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", c17_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c17_r0->context)), "context", "nameCaptureInfo",
                    c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", c17_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c17_r0->name)), "name", "nameCaptureInfo",
                    c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo",
      c17_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c17_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", c17_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c17_r0->resolved)), "resolved",
                    "nameCaptureInfo", c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo",
      &c17_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c17_i43);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo",
      &c17_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c17_i43);
  }

  sf_mex_assign(&c17_nameCaptureInfo, c17_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static const mxArray *c17_f_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static int32_T c17_g_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i44;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i44, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i44;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_h_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_b_is_active_c17_JointSpaceControl_BestInertia, const char_T
   *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_JointSpaceControl_BestInertia), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_JointSpaceControl_BestInertia);
  return c17_y;
}

static uint8_T c17_i_emlrt_marshallIn
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void init_dsm_address_info
  (SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
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

void sf_c17_JointSpaceControl_BestInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2713865532U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1845748807U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1189893988U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1764218471U);
}

mxArray *sf_c17_JointSpaceControl_BestInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kC1ryQMhi3q1FGMxB1H0uE");
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

mxArray *sf_c17_JointSpaceControl_BestInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c17_JointSpaceControl_BestInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"R\",},{M[1],M[6],T\"d\",},{M[8],M[0],T\"is_active_c17_JointSpaceControl_BestInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_JointSpaceControl_BestInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_BestInertiaMachineNumber_,
           17,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,5918);
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
            1.0,0,0,(MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)
            c17_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)
            c17_sf_marshallIn);
        }

        {
          real_T (*c17_d)[3];
          real_T (*c17_q)[6];
          real_T (*c17_R)[9];
          c17_R = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c17_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c17_d = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c17_d);
          _SFD_SET_DATA_VALUE_PTR(1U, *c17_q);
          _SFD_SET_DATA_VALUE_PTR(2U, *c17_R);
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
  return "j79fC60vD7Fp8sl30RH0p";
}

static void sf_opaque_initialize_c17_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_JointSpaceControl_BestInertiaInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
  initialize_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c17_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  enable_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  disable_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  sf_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c17_JointSpaceControl_BestInertia(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_JointSpaceControl_BestInertia();/* state var info */
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

extern void sf_internal_set_sim_state_c17_JointSpaceControl_BestInertia
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_JointSpaceControl_BestInertia();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c17_JointSpaceControl_BestInertia(S);
}

static void sf_opaque_set_sim_state_c17_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c17_JointSpaceControl_BestInertia(S, st);
}

static void sf_opaque_terminate_c17_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_BestInertia_optimization_info();
    }

    finalize_c17_JointSpaceControl_BestInertia
      ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_JointSpaceControl_BestInertia
    ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_JointSpaceControl_BestInertia(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c17_JointSpaceControl_BestInertia
      ((SFc17_JointSpaceControl_BestInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_BestInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,17,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3029681485U));
  ssSetChecksum1(S,(3821623203U));
  ssSetChecksum2(S,(2101335840U));
  ssSetChecksum3(S,(1390234292U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_JointSpaceControl_BestInertia(SimStruct *S)
{
  SFc17_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc17_JointSpaceControl_BestInertiaInstanceStruct *)utMalloc
    (sizeof(SFc17_JointSpaceControl_BestInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc17_JointSpaceControl_BestInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_JointSpaceControl_BestInertia;
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

void c17_JointSpaceControl_BestInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_JointSpaceControl_BestInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_JointSpaceControl_BestInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
