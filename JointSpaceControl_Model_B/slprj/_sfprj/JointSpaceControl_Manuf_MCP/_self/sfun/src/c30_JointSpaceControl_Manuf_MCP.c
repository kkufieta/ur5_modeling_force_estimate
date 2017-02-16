/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_Manuf_MCP_sfun.h"
#include "c30_JointSpaceControl_Manuf_MCP.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_Manuf_MCP_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c30_debug_family_names[10] = { "nargin", "nargout", "a_q",
  "M", "G", "CDq", "tau", "tau_M", "tau_CDq", "tau_G" };

/* Function Declarations */
static void initialize_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void initialize_params_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void enable_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void disable_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void c30_update_debugger_state_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void set_sim_state_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_st);
static void finalize_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void sf_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void c30_chartstep_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void initSimStructsc30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void registerMessagesc30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_emlrt_marshallIn(SFc30_JointSpaceControl_Manuf_MCPInstanceStruct
  *chartInstance, const mxArray *c30_tau_G, const char_T *c30_identifier, real_T
  c30_y[6]);
static void c30_b_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[6]);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_c_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static void c30_eml_scalar_eg(SFc30_JointSpaceControl_Manuf_MCPInstanceStruct
  *chartInstance);
static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_d_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_e_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_b_is_active_c30_JointSpaceControl_Manuf_MCP, const char_T
   *c30_identifier);
static uint8_T c30_f_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void init_dsm_address_info
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c30_is_active_c30_JointSpaceControl_Manuf_MCP = 0U;
}

static void initialize_params_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void enable_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c30_update_debugger_state_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  int32_T c30_i0;
  real_T c30_u[6];
  const mxArray *c30_b_y = NULL;
  int32_T c30_i1;
  real_T c30_b_u[6];
  const mxArray *c30_c_y = NULL;
  int32_T c30_i2;
  real_T c30_c_u[6];
  const mxArray *c30_d_y = NULL;
  int32_T c30_i3;
  real_T c30_d_u[6];
  const mxArray *c30_e_y = NULL;
  uint8_T c30_hoistedGlobal;
  uint8_T c30_e_u;
  const mxArray *c30_f_y = NULL;
  real_T (*c30_tau_M)[6];
  real_T (*c30_tau_G)[6];
  real_T (*c30_tau_CDq)[6];
  real_T (*c30_tau)[6];
  c30_tau_G = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c30_tau_CDq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c30_tau_M = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c30_tau = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellarray(5), FALSE);
  for (c30_i0 = 0; c30_i0 < 6; c30_i0++) {
    c30_u[c30_i0] = (*c30_tau)[c30_i0];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  for (c30_i1 = 0; c30_i1 < 6; c30_i1++) {
    c30_b_u[c30_i1] = (*c30_tau_CDq)[c30_i1];
  }

  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", c30_b_u, 0, 0U, 1U, 0U, 1, 6),
                FALSE);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  for (c30_i2 = 0; c30_i2 < 6; c30_i2++) {
    c30_c_u[c30_i2] = (*c30_tau_G)[c30_i2];
  }

  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_create("y", c30_c_u, 0, 0U, 1U, 0U, 1, 6),
                FALSE);
  sf_mex_setcell(c30_y, 2, c30_d_y);
  for (c30_i3 = 0; c30_i3 < 6; c30_i3++) {
    c30_d_u[c30_i3] = (*c30_tau_M)[c30_i3];
  }

  c30_e_y = NULL;
  sf_mex_assign(&c30_e_y, sf_mex_create("y", c30_d_u, 0, 0U, 1U, 0U, 1, 6),
                FALSE);
  sf_mex_setcell(c30_y, 3, c30_e_y);
  c30_hoistedGlobal =
    chartInstance->c30_is_active_c30_JointSpaceControl_Manuf_MCP;
  c30_e_u = c30_hoistedGlobal;
  c30_f_y = NULL;
  sf_mex_assign(&c30_f_y, sf_mex_create("y", &c30_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c30_y, 4, c30_f_y);
  sf_mex_assign(&c30_st, c30_y, FALSE);
  return c30_st;
}

static void set_sim_state_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_st)
{
  const mxArray *c30_u;
  real_T c30_dv0[6];
  int32_T c30_i4;
  real_T c30_dv1[6];
  int32_T c30_i5;
  real_T c30_dv2[6];
  int32_T c30_i6;
  real_T c30_dv3[6];
  int32_T c30_i7;
  real_T (*c30_tau)[6];
  real_T (*c30_tau_CDq)[6];
  real_T (*c30_tau_G)[6];
  real_T (*c30_tau_M)[6];
  c30_tau_G = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c30_tau_CDq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c30_tau_M = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c30_tau = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c30_doneDoubleBufferReInit = TRUE;
  c30_u = sf_mex_dup(c30_st);
  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 0)),
                       "tau", c30_dv0);
  for (c30_i4 = 0; c30_i4 < 6; c30_i4++) {
    (*c30_tau)[c30_i4] = c30_dv0[c30_i4];
  }

  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 1)),
                       "tau_CDq", c30_dv1);
  for (c30_i5 = 0; c30_i5 < 6; c30_i5++) {
    (*c30_tau_CDq)[c30_i5] = c30_dv1[c30_i5];
  }

  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 2)),
                       "tau_G", c30_dv2);
  for (c30_i6 = 0; c30_i6 < 6; c30_i6++) {
    (*c30_tau_G)[c30_i6] = c30_dv2[c30_i6];
  }

  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 3)),
                       "tau_M", c30_dv3);
  for (c30_i7 = 0; c30_i7 < 6; c30_i7++) {
    (*c30_tau_M)[c30_i7] = c30_dv3[c30_i7];
  }

  chartInstance->c30_is_active_c30_JointSpaceControl_Manuf_MCP =
    c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 4)),
    "is_active_c30_JointSpaceControl_Manuf_MCP");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_JointSpaceControl_Manuf_MCP(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void sf_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  int32_T c30_i8;
  int32_T c30_i9;
  int32_T c30_i10;
  int32_T c30_i11;
  int32_T c30_i12;
  int32_T c30_i13;
  int32_T c30_i14;
  int32_T c30_i15;
  real_T (*c30_tau_G)[6];
  real_T (*c30_tau_CDq)[6];
  real_T (*c30_tau_M)[6];
  real_T (*c30_tau)[6];
  real_T (*c30_CDq)[6];
  real_T (*c30_G)[6];
  real_T (*c30_M)[36];
  real_T (*c30_a_q)[6];
  c30_tau_G = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c30_tau_CDq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c30_tau_M = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c30_tau = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_CDq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c30_G = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c30_M = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 1);
  c30_a_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, chartInstance->c30_sfEvent);
  for (c30_i8 = 0; c30_i8 < 6; c30_i8++) {
    _SFD_DATA_RANGE_CHECK((*c30_a_q)[c30_i8], 0U);
  }

  for (c30_i9 = 0; c30_i9 < 36; c30_i9++) {
    _SFD_DATA_RANGE_CHECK((*c30_M)[c30_i9], 1U);
  }

  for (c30_i10 = 0; c30_i10 < 6; c30_i10++) {
    _SFD_DATA_RANGE_CHECK((*c30_G)[c30_i10], 2U);
  }

  for (c30_i11 = 0; c30_i11 < 6; c30_i11++) {
    _SFD_DATA_RANGE_CHECK((*c30_CDq)[c30_i11], 3U);
  }

  for (c30_i12 = 0; c30_i12 < 6; c30_i12++) {
    _SFD_DATA_RANGE_CHECK((*c30_tau)[c30_i12], 4U);
  }

  for (c30_i13 = 0; c30_i13 < 6; c30_i13++) {
    _SFD_DATA_RANGE_CHECK((*c30_tau_M)[c30_i13], 5U);
  }

  for (c30_i14 = 0; c30_i14 < 6; c30_i14++) {
    _SFD_DATA_RANGE_CHECK((*c30_tau_CDq)[c30_i14], 6U);
  }

  for (c30_i15 = 0; c30_i15 < 6; c30_i15++) {
    _SFD_DATA_RANGE_CHECK((*c30_tau_G)[c30_i15], 7U);
  }

  chartInstance->c30_sfEvent = CALL_EVENT;
  c30_chartstep_c30_JointSpaceControl_Manuf_MCP(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControl_Manuf_MCPMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c30_chartstep_c30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  int32_T c30_i16;
  real_T c30_a_q[6];
  int32_T c30_i17;
  real_T c30_M[36];
  int32_T c30_i18;
  real_T c30_G[6];
  int32_T c30_i19;
  real_T c30_CDq[6];
  uint32_T c30_debug_family_var_map[10];
  real_T c30_nargin = 4.0;
  real_T c30_nargout = 4.0;
  real_T c30_tau[6];
  real_T c30_tau_M[6];
  real_T c30_tau_CDq[6];
  real_T c30_tau_G[6];
  int32_T c30_i20;
  real_T c30_a[36];
  int32_T c30_i21;
  real_T c30_b[6];
  int32_T c30_i22;
  real_T c30_y[6];
  int32_T c30_i23;
  int32_T c30_i24;
  int32_T c30_i25;
  int32_T c30_i26;
  int32_T c30_i27;
  int32_T c30_i28;
  int32_T c30_i29;
  int32_T c30_i30;
  int32_T c30_i31;
  int32_T c30_i32;
  int32_T c30_i33;
  int32_T c30_i34;
  int32_T c30_i35;
  int32_T c30_i36;
  int32_T c30_i37;
  int32_T c30_i38;
  int32_T c30_i39;
  int32_T c30_i40;
  int32_T c30_i41;
  int32_T c30_i42;
  real_T (*c30_b_tau)[6];
  real_T (*c30_b_tau_M)[6];
  real_T (*c30_b_tau_CDq)[6];
  real_T (*c30_b_tau_G)[6];
  real_T (*c30_b_CDq)[6];
  real_T (*c30_b_G)[6];
  real_T (*c30_b_M)[36];
  real_T (*c30_b_a_q)[6];
  c30_b_tau_G = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c30_b_tau_CDq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c30_b_tau_M = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c30_b_tau = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_b_CDq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c30_b_G = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c30_b_M = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 1);
  c30_b_a_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c30_sfEvent);
  for (c30_i16 = 0; c30_i16 < 6; c30_i16++) {
    c30_a_q[c30_i16] = (*c30_b_a_q)[c30_i16];
  }

  for (c30_i17 = 0; c30_i17 < 36; c30_i17++) {
    c30_M[c30_i17] = (*c30_b_M)[c30_i17];
  }

  for (c30_i18 = 0; c30_i18 < 6; c30_i18++) {
    c30_G[c30_i18] = (*c30_b_G)[c30_i18];
  }

  for (c30_i19 = 0; c30_i19 < 6; c30_i19++) {
    c30_CDq[c30_i19] = (*c30_b_CDq)[c30_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 0U, c30_c_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 1U, c30_c_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_a_q, 2U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_M, 3U, c30_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_G, 4U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_CDq, 5U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_tau, 6U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_tau_M, 7U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_tau_CDq, 8U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_tau_G, 9U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 5);
  for (c30_i20 = 0; c30_i20 < 36; c30_i20++) {
    c30_a[c30_i20] = c30_M[c30_i20];
  }

  for (c30_i21 = 0; c30_i21 < 6; c30_i21++) {
    c30_b[c30_i21] = c30_a_q[c30_i21];
  }

  c30_eml_scalar_eg(chartInstance);
  c30_eml_scalar_eg(chartInstance);
  for (c30_i22 = 0; c30_i22 < 6; c30_i22++) {
    c30_y[c30_i22] = 0.0;
    c30_i23 = 0;
    for (c30_i24 = 0; c30_i24 < 6; c30_i24++) {
      c30_y[c30_i22] += c30_a[c30_i23 + c30_i22] * c30_b[c30_i24];
      c30_i23 += 6;
    }
  }

  for (c30_i25 = 0; c30_i25 < 6; c30_i25++) {
    c30_tau[c30_i25] = (c30_y[c30_i25] + c30_CDq[c30_i25]) + c30_G[c30_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 6);
  for (c30_i26 = 0; c30_i26 < 36; c30_i26++) {
    c30_a[c30_i26] = c30_M[c30_i26];
  }

  for (c30_i27 = 0; c30_i27 < 6; c30_i27++) {
    c30_b[c30_i27] = c30_a_q[c30_i27];
  }

  c30_eml_scalar_eg(chartInstance);
  c30_eml_scalar_eg(chartInstance);
  for (c30_i28 = 0; c30_i28 < 6; c30_i28++) {
    c30_tau_M[c30_i28] = 0.0;
  }

  for (c30_i29 = 0; c30_i29 < 6; c30_i29++) {
    c30_tau_M[c30_i29] = 0.0;
  }

  for (c30_i30 = 0; c30_i30 < 6; c30_i30++) {
    c30_y[c30_i30] = c30_tau_M[c30_i30];
  }

  for (c30_i31 = 0; c30_i31 < 6; c30_i31++) {
    c30_tau_M[c30_i31] = c30_y[c30_i31];
  }

  for (c30_i32 = 0; c30_i32 < 6; c30_i32++) {
    c30_y[c30_i32] = c30_tau_M[c30_i32];
  }

  for (c30_i33 = 0; c30_i33 < 6; c30_i33++) {
    c30_tau_M[c30_i33] = c30_y[c30_i33];
  }

  for (c30_i34 = 0; c30_i34 < 6; c30_i34++) {
    c30_tau_M[c30_i34] = 0.0;
    c30_i35 = 0;
    for (c30_i36 = 0; c30_i36 < 6; c30_i36++) {
      c30_tau_M[c30_i34] += c30_a[c30_i35 + c30_i34] * c30_b[c30_i36];
      c30_i35 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 7);
  for (c30_i37 = 0; c30_i37 < 6; c30_i37++) {
    c30_tau_CDq[c30_i37] = c30_CDq[c30_i37];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 8);
  for (c30_i38 = 0; c30_i38 < 6; c30_i38++) {
    c30_tau_G[c30_i38] = c30_G[c30_i38];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c30_i39 = 0; c30_i39 < 6; c30_i39++) {
    (*c30_b_tau)[c30_i39] = c30_tau[c30_i39];
  }

  for (c30_i40 = 0; c30_i40 < 6; c30_i40++) {
    (*c30_b_tau_M)[c30_i40] = c30_tau_M[c30_i40];
  }

  for (c30_i41 = 0; c30_i41 < 6; c30_i41++) {
    (*c30_b_tau_CDq)[c30_i41] = c30_tau_CDq[c30_i41];
  }

  for (c30_i42 = 0; c30_i42 < 6; c30_i42++) {
    (*c30_b_tau_G)[c30_i42] = c30_tau_G[c30_i42];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c30_sfEvent);
}

static void initSimStructsc30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void registerMessagesc30_JointSpaceControl_Manuf_MCP
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber)
{
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i43;
  real_T c30_b_inData[6];
  int32_T c30_i44;
  real_T c30_u[6];
  const mxArray *c30_y = NULL;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  for (c30_i43 = 0; c30_i43 < 6; c30_i43++) {
    c30_b_inData[c30_i43] = (*(real_T (*)[6])c30_inData)[c30_i43];
  }

  for (c30_i44 = 0; c30_i44 < 6; c30_i44++) {
    c30_u[c30_i44] = c30_b_inData[c30_i44];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static void c30_emlrt_marshallIn(SFc30_JointSpaceControl_Manuf_MCPInstanceStruct
  *chartInstance, const mxArray *c30_tau_G, const char_T *c30_identifier, real_T
  c30_y[6])
{
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_tau_G), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_tau_G);
}

static void c30_b_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId, real_T c30_y[6])
{
  real_T c30_dv4[6];
  int32_T c30_i45;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c30_i45 = 0; c30_i45 < 6; c30_i45++) {
    c30_y[c30_i45] = c30_dv4[c30_i45];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_tau_G;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y[6];
  int32_T c30_i46;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_tau_G = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_tau_G), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_tau_G);
  for (c30_i46 = 0; c30_i46 < 6; c30_i46++) {
    (*(real_T (*)[6])c30_outData)[c30_i46] = c30_y[c30_i46];
  }

  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i47;
  int32_T c30_i48;
  int32_T c30_i49;
  real_T c30_b_inData[36];
  int32_T c30_i50;
  int32_T c30_i51;
  int32_T c30_i52;
  real_T c30_u[36];
  const mxArray *c30_y = NULL;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_i47 = 0;
  for (c30_i48 = 0; c30_i48 < 6; c30_i48++) {
    for (c30_i49 = 0; c30_i49 < 6; c30_i49++) {
      c30_b_inData[c30_i49 + c30_i47] = (*(real_T (*)[36])c30_inData)[c30_i49 +
        c30_i47];
    }

    c30_i47 += 6;
  }

  c30_i50 = 0;
  for (c30_i51 = 0; c30_i51 < 6; c30_i51++) {
    for (c30_i52 = 0; c30_i52 < 6; c30_i52++) {
      c30_u[c30_i52 + c30_i50] = c30_b_inData[c30_i52 + c30_i50];
    }

    c30_i50 += 6;
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static real_T c30_c_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d0, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_nargout;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_nargout = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_nargout),
    &c30_thisId);
  sf_mex_destroy(&c30_nargout);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray
  *sf_c30_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo;
  c30_ResolvedFunctionInfo c30_info[9];
  c30_ResolvedFunctionInfo (*c30_b_info)[9];
  const mxArray *c30_m0 = NULL;
  int32_T c30_i53;
  c30_ResolvedFunctionInfo *c30_r0;
  c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  c30_b_info = (c30_ResolvedFunctionInfo (*)[9])c30_info;
  (*c30_b_info)[0].context = "";
  (*c30_b_info)[0].name = "mtimes";
  (*c30_b_info)[0].dominantType = "double";
  (*c30_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c30_b_info)[0].fileTimeLo = 1289541292U;
  (*c30_b_info)[0].fileTimeHi = 0U;
  (*c30_b_info)[0].mFileTimeLo = 0U;
  (*c30_b_info)[0].mFileTimeHi = 0U;
  (*c30_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c30_b_info)[1].name = "eml_index_class";
  (*c30_b_info)[1].dominantType = "";
  (*c30_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c30_b_info)[1].fileTimeLo = 1323192178U;
  (*c30_b_info)[1].fileTimeHi = 0U;
  (*c30_b_info)[1].mFileTimeLo = 0U;
  (*c30_b_info)[1].mFileTimeHi = 0U;
  (*c30_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c30_b_info)[2].name = "eml_scalar_eg";
  (*c30_b_info)[2].dominantType = "double";
  (*c30_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c30_b_info)[2].fileTimeLo = 1286840396U;
  (*c30_b_info)[2].fileTimeHi = 0U;
  (*c30_b_info)[2].mFileTimeLo = 0U;
  (*c30_b_info)[2].mFileTimeHi = 0U;
  (*c30_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c30_b_info)[3].name = "eml_xgemm";
  (*c30_b_info)[3].dominantType = "char";
  (*c30_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c30_b_info)[3].fileTimeLo = 1299098372U;
  (*c30_b_info)[3].fileTimeHi = 0U;
  (*c30_b_info)[3].mFileTimeLo = 0U;
  (*c30_b_info)[3].mFileTimeHi = 0U;
  (*c30_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c30_b_info)[4].name = "eml_blas_inline";
  (*c30_b_info)[4].dominantType = "";
  (*c30_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c30_b_info)[4].fileTimeLo = 1299098368U;
  (*c30_b_info)[4].fileTimeHi = 0U;
  (*c30_b_info)[4].mFileTimeLo = 0U;
  (*c30_b_info)[4].mFileTimeHi = 0U;
  (*c30_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c30_b_info)[5].name = "mtimes";
  (*c30_b_info)[5].dominantType = "double";
  (*c30_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c30_b_info)[5].fileTimeLo = 1289541292U;
  (*c30_b_info)[5].fileTimeHi = 0U;
  (*c30_b_info)[5].mFileTimeLo = 0U;
  (*c30_b_info)[5].mFileTimeHi = 0U;
  (*c30_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c30_b_info)[6].name = "eml_index_class";
  (*c30_b_info)[6].dominantType = "";
  (*c30_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c30_b_info)[6].fileTimeLo = 1323192178U;
  (*c30_b_info)[6].fileTimeHi = 0U;
  (*c30_b_info)[6].mFileTimeLo = 0U;
  (*c30_b_info)[6].mFileTimeHi = 0U;
  (*c30_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c30_b_info)[7].name = "eml_scalar_eg";
  (*c30_b_info)[7].dominantType = "double";
  (*c30_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c30_b_info)[7].fileTimeLo = 1286840396U;
  (*c30_b_info)[7].fileTimeHi = 0U;
  (*c30_b_info)[7].mFileTimeLo = 0U;
  (*c30_b_info)[7].mFileTimeHi = 0U;
  (*c30_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c30_b_info)[8].name = "eml_refblas_xgemm";
  (*c30_b_info)[8].dominantType = "char";
  (*c30_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c30_b_info)[8].fileTimeLo = 1299098374U;
  (*c30_b_info)[8].fileTimeHi = 0U;
  (*c30_b_info)[8].mFileTimeLo = 0U;
  (*c30_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c30_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c30_i53 = 0; c30_i53 < 9; c30_i53++) {
    c30_r0 = &c30_info[c30_i53];
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", c30_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c30_r0->context)), "context", "nameCaptureInfo",
                    c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", c30_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c30_r0->name)), "name", "nameCaptureInfo",
                    c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo",
      c30_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c30_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", c30_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c30_r0->resolved)), "resolved",
                    "nameCaptureInfo", c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo",
      &c30_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c30_i53);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo",
      &c30_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c30_i53);
  }

  sf_mex_assign(&c30_nameCaptureInfo, c30_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c30_nameCaptureInfo);
  return c30_nameCaptureInfo;
}

static void c30_eml_scalar_eg(SFc30_JointSpaceControl_Manuf_MCPInstanceStruct
  *chartInstance)
{
}

static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static int32_T c30_d_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i54;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i54, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i54;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_e_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_b_is_active_c30_JointSpaceControl_Manuf_MCP, const char_T
   *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_JointSpaceControl_Manuf_MCP), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_JointSpaceControl_Manuf_MCP);
  return c30_y;
}

static uint8_T c30_f_emlrt_marshallIn
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void init_dsm_address_info
  (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
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

void sf_c30_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3869655841U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2795069178U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3573809263U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1615475156U);
}

mxArray *sf_c30_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("G9hHwYvxuOTpiK8FomGQsB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[1] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c30_JointSpaceControl_Manuf_MCP_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c30_JointSpaceControl_Manuf_MCP(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[8],T\"tau\",},{M[1],M[10],T\"tau_CDq\",},{M[1],M[11],T\"tau_G\",},{M[1],M[9],T\"tau_M\",},{M[8],M[0],T\"is_active_c30_JointSpaceControl_Manuf_MCP\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_JointSpaceControl_Manuf_MCP_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
    chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_Manuf_MCPMachineNumber_,
           30,
           1,
           1,
           8,
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
            (_JointSpaceControl_Manuf_MCPMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_Manuf_MCPMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_Manuf_MCPMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"a_q");
          _SFD_SET_DATA_PROPS(1,1,1,0,"M");
          _SFD_SET_DATA_PROPS(2,1,1,0,"G");
          _SFD_SET_DATA_PROPS(3,1,1,0,"CDq");
          _SFD_SET_DATA_PROPS(4,2,0,1,"tau");
          _SFD_SET_DATA_PROPS(5,2,0,1,"tau_M");
          _SFD_SET_DATA_PROPS(6,2,0,1,"tau_CDq");
          _SFD_SET_DATA_PROPS(7,2,0,1,"tau_G");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,259);
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
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        {
          real_T (*c30_a_q)[6];
          real_T (*c30_M)[36];
          real_T (*c30_G)[6];
          real_T (*c30_CDq)[6];
          real_T (*c30_tau)[6];
          real_T (*c30_tau_M)[6];
          real_T (*c30_tau_CDq)[6];
          real_T (*c30_tau_G)[6];
          c30_tau_G = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
          c30_tau_CDq = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
          c30_tau_M = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
          c30_tau = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c30_CDq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
          c30_G = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c30_M = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 1);
          c30_a_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c30_a_q);
          _SFD_SET_DATA_VALUE_PTR(1U, *c30_M);
          _SFD_SET_DATA_VALUE_PTR(2U, *c30_G);
          _SFD_SET_DATA_VALUE_PTR(3U, *c30_CDq);
          _SFD_SET_DATA_VALUE_PTR(4U, *c30_tau);
          _SFD_SET_DATA_VALUE_PTR(5U, *c30_tau_M);
          _SFD_SET_DATA_VALUE_PTR(6U, *c30_tau_CDq);
          _SFD_SET_DATA_VALUE_PTR(7U, *c30_tau_G);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_Manuf_MCPMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "zNoUsell6FGeSvXzicMyvC";
}

static void sf_opaque_initialize_c30_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
  initialize_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c30_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  enable_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c30_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  disable_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c30_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  sf_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c30_JointSpaceControl_Manuf_MCP
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_JointSpaceControl_Manuf_MCP();/* state var info */
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

extern void sf_internal_set_sim_state_c30_JointSpaceControl_Manuf_MCP(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_JointSpaceControl_Manuf_MCP();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c30_JointSpaceControl_Manuf_MCP
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c30_JointSpaceControl_Manuf_MCP(S);
}

static void sf_opaque_set_sim_state_c30_JointSpaceControl_Manuf_MCP(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c30_JointSpaceControl_Manuf_MCP(S, st);
}

static void sf_opaque_terminate_c30_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_Manuf_MCP_optimization_info();
    }

    finalize_c30_JointSpaceControl_Manuf_MCP
      ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc30_JointSpaceControl_Manuf_MCP
    ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c30_JointSpaceControl_Manuf_MCP
      ((SFc30_JointSpaceControl_Manuf_MCPInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_Manuf_MCP_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,30,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,30);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,30,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,30,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4019121072U));
  ssSetChecksum1(S,(3195726420U));
  ssSetChecksum2(S,(2596656957U));
  ssSetChecksum3(S,(1325959716U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c30_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct *)utMalloc
    (sizeof(SFc30_JointSpaceControl_Manuf_MCPInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc30_JointSpaceControl_Manuf_MCPInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_JointSpaceControl_Manuf_MCP;
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

void c30_JointSpaceControl_Manuf_MCP_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_JointSpaceControl_Manuf_MCP(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_JointSpaceControl_Manuf_MCP(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_JointSpaceControl_Manuf_MCP(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_JointSpaceControl_Manuf_MCP_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
