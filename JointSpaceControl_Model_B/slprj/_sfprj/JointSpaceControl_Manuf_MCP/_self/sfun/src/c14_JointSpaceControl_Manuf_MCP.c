/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_Manuf_MCP_sfun.h"
#include "c14_JointSpaceControl_Manuf_MCP.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_Manuf_MCP_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c14_debug_family_names[5] = { "nargin", "nargout", "RxRyRz",
  "k", "theta" };

/* Function Declarations */
static void initialize_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void initialize_params_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void enable_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void disable_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void set_sim_state_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_st);
static void finalize_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void sf_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void initSimStructsc14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void registerMessagesc14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_theta, const char_T *c14_identifier);
static real_T c14_b_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_c_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_k, const char_T *c14_identifier, real_T c14_y[3]);
static void c14_d_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3]);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(c14_ResolvedFunctionInfo c14_info[24]);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_e_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_f_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_b_is_active_c14_JointSpaceControl_Manuf_MCP, const char_T
   *c14_identifier);
static uint8_T c14_g_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_JointSpaceControl_Manuf_MCP = 0U;
}

static void initialize_params_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void enable_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  int32_T c14_i0;
  real_T c14_u[3];
  const mxArray *c14_b_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  real_T *c14_theta;
  real_T (*c14_k)[3];
  c14_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(3), FALSE);
  for (c14_i0 = 0; c14_i0 < 3; c14_i0++) {
    c14_u[c14_i0] = (*c14_k)[c14_i0];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_hoistedGlobal = *c14_theta;
  c14_b_u = c14_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_b_hoistedGlobal =
    chartInstance->c14_is_active_c14_JointSpaceControl_Manuf_MCP;
  c14_c_u = c14_b_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  sf_mex_assign(&c14_st, c14_y, FALSE);
  return c14_st;
}

static void set_sim_state_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv0[3];
  int32_T c14_i1;
  real_T *c14_theta;
  real_T (*c14_k)[3];
  c14_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)),
    "k", c14_dv0);
  for (c14_i1 = 0; c14_i1 < 3; c14_i1++) {
    (*c14_k)[c14_i1] = c14_dv0[c14_i1];
  }

  *c14_theta = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 1)), "theta");
  chartInstance->c14_is_active_c14_JointSpaceControl_Manuf_MCP =
    c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
    "is_active_c14_JointSpaceControl_Manuf_MCP");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_JointSpaceControl_Manuf_MCP(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void sf_c14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
  int32_T c14_i2;
  int32_T c14_i3;
  int32_T c14_i4;
  real_T c14_RxRyRz[3];
  uint32_T c14_debug_family_var_map[5];
  real_T c14_nargin = 1.0;
  real_T c14_nargout = 2.0;
  real_T c14_k[3];
  real_T c14_theta;
  int32_T c14_i5;
  real_T c14_x[3];
  real_T c14_scale;
  int32_T c14_b_k;
  int32_T c14_c_k;
  real_T c14_b_x;
  real_T c14_c_x;
  real_T c14_absxk;
  real_T c14_t;
  int32_T c14_i6;
  real_T c14_B;
  real_T c14_y;
  real_T c14_b_y;
  int32_T c14_i7;
  int32_T c14_i8;
  real_T *c14_b_theta;
  real_T (*c14_d_k)[3];
  real_T (*c14_b_RxRyRz)[3];
  c14_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_d_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_RxRyRz = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
  for (c14_i2 = 0; c14_i2 < 3; c14_i2++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_RxRyRz)[c14_i2], 0U);
  }

  for (c14_i3 = 0; c14_i3 < 3; c14_i3++) {
    _SFD_DATA_RANGE_CHECK((*c14_d_k)[c14_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c14_b_theta, 2U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
  for (c14_i4 = 0; c14_i4 < 3; c14_i4++) {
    c14_RxRyRz[c14_i4] = (*c14_b_RxRyRz)[c14_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 0U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_RxRyRz, 2U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_k, 3U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_theta, 4U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  for (c14_i5 = 0; c14_i5 < 3; c14_i5++) {
    c14_x[c14_i5] = c14_RxRyRz[c14_i5];
  }

  c14_theta = 0.0;
  c14_scale = 2.2250738585072014E-308;
  for (c14_b_k = 1; c14_b_k < 4; c14_b_k++) {
    c14_c_k = c14_b_k;
    c14_b_x = c14_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c14_c_k), 1, 3, 1, 0) - 1];
    c14_c_x = c14_b_x;
    c14_absxk = muDoubleScalarAbs(c14_c_x);
    if (c14_absxk > c14_scale) {
      c14_t = c14_scale / c14_absxk;
      c14_theta = 1.0 + c14_theta * c14_t * c14_t;
      c14_scale = c14_absxk;
    } else {
      c14_t = c14_absxk / c14_scale;
      c14_theta += c14_t * c14_t;
    }
  }

  c14_theta = c14_scale * muDoubleScalarSqrt(c14_theta);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 5);
  for (c14_i6 = 0; c14_i6 < 3; c14_i6++) {
    c14_x[c14_i6] = c14_RxRyRz[c14_i6];
  }

  c14_B = c14_theta;
  c14_y = c14_B;
  c14_b_y = c14_y;
  for (c14_i7 = 0; c14_i7 < 3; c14_i7++) {
    c14_k[c14_i7] = c14_x[c14_i7] / c14_b_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c14_i8 = 0; c14_i8 < 3; c14_i8++) {
    (*c14_d_k)[c14_i8] = c14_k[c14_i8];
  }

  *c14_b_theta = c14_theta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControl_Manuf_MCPMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void registerMessagesc14_JointSpaceControl_Manuf_MCP
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_theta, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_theta),
    &c14_thisId);
  sf_mex_destroy(&c14_theta);
  return c14_y;
}

static real_T c14_b_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_theta;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c14_theta = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_theta),
    &c14_thisId);
  sf_mex_destroy(&c14_theta);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i9;
  real_T c14_b_inData[3];
  int32_T c14_i10;
  real_T c14_u[3];
  const mxArray *c14_y = NULL;
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i9 = 0; c14_i9 < 3; c14_i9++) {
    c14_b_inData[c14_i9] = (*(real_T (*)[3])c14_inData)[c14_i9];
  }

  for (c14_i10 = 0; c14_i10 < 3; c14_i10++) {
    c14_u[c14_i10] = c14_b_inData[c14_i10];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_c_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_k, const char_T *c14_identifier, real_T c14_y[3])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_k), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_k);
}

static void c14_d_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3])
{
  real_T c14_dv1[3];
  int32_T c14_i11;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c14_i11 = 0; c14_i11 < 3; c14_i11++) {
    c14_y[c14_i11] = c14_dv1[c14_i11];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_k;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[3];
  int32_T c14_i12;
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c14_k = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_k), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_k);
  for (c14_i12 = 0; c14_i12 < 3; c14_i12++) {
    (*(real_T (*)[3])c14_outData)[c14_i12] = c14_y[c14_i12];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray
  *sf_c14_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo;
  c14_ResolvedFunctionInfo c14_info[24];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i13;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  c14_info_helper(c14_info);
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24), FALSE);
  for (c14_i13 = 0; c14_i13 < 24; c14_i13++) {
    c14_r0 = &c14_info[c14_i13];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context", "nameCaptureInfo",
                    c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name", "nameCaptureInfo",
                    c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)), "resolved",
                    "nameCaptureInfo", c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c14_i13);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c14_i13);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(c14_ResolvedFunctionInfo c14_info[24])
{
  c14_info[0].context = "";
  c14_info[0].name = "norm";
  c14_info[0].dominantType = "double";
  c14_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c14_info[0].fileTimeLo = 1336543694U;
  c14_info[0].fileTimeHi = 0U;
  c14_info[0].mFileTimeLo = 0U;
  c14_info[0].mFileTimeHi = 0U;
  c14_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c14_info[1].name = "eml_index_class";
  c14_info[1].dominantType = "";
  c14_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[1].fileTimeLo = 1323192178U;
  c14_info[1].fileTimeHi = 0U;
  c14_info[1].mFileTimeLo = 0U;
  c14_info[1].mFileTimeHi = 0U;
  c14_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c14_info[2].name = "eml_xnrm2";
  c14_info[2].dominantType = "double";
  c14_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c14_info[2].fileTimeLo = 1299098376U;
  c14_info[2].fileTimeHi = 0U;
  c14_info[2].mFileTimeLo = 0U;
  c14_info[2].mFileTimeHi = 0U;
  c14_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c14_info[3].name = "eml_blas_inline";
  c14_info[3].dominantType = "";
  c14_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c14_info[3].fileTimeLo = 1299098368U;
  c14_info[3].fileTimeHi = 0U;
  c14_info[3].mFileTimeLo = 0U;
  c14_info[3].mFileTimeHi = 0U;
  c14_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c14_info[4].name = "eml_index_class";
  c14_info[4].dominantType = "";
  c14_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[4].fileTimeLo = 1323192178U;
  c14_info[4].fileTimeHi = 0U;
  c14_info[4].mFileTimeLo = 0U;
  c14_info[4].mFileTimeHi = 0U;
  c14_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c14_info[5].name = "eml_refblas_xnrm2";
  c14_info[5].dominantType = "double";
  c14_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[5].fileTimeLo = 1299098384U;
  c14_info[5].fileTimeHi = 0U;
  c14_info[5].mFileTimeLo = 0U;
  c14_info[5].mFileTimeHi = 0U;
  c14_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[6].name = "realmin";
  c14_info[6].dominantType = "char";
  c14_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c14_info[6].fileTimeLo = 1307672842U;
  c14_info[6].fileTimeHi = 0U;
  c14_info[6].mFileTimeLo = 0U;
  c14_info[6].mFileTimeHi = 0U;
  c14_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c14_info[7].name = "eml_realmin";
  c14_info[7].dominantType = "char";
  c14_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c14_info[7].fileTimeLo = 1307672844U;
  c14_info[7].fileTimeHi = 0U;
  c14_info[7].mFileTimeLo = 0U;
  c14_info[7].mFileTimeHi = 0U;
  c14_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c14_info[8].name = "eml_float_model";
  c14_info[8].dominantType = "char";
  c14_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c14_info[8].fileTimeLo = 1326749596U;
  c14_info[8].fileTimeHi = 0U;
  c14_info[8].mFileTimeLo = 0U;
  c14_info[8].mFileTimeHi = 0U;
  c14_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[9].name = "eml_index_class";
  c14_info[9].dominantType = "";
  c14_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[9].fileTimeLo = 1323192178U;
  c14_info[9].fileTimeHi = 0U;
  c14_info[9].mFileTimeLo = 0U;
  c14_info[9].mFileTimeHi = 0U;
  c14_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[10].name = "eml_index_minus";
  c14_info[10].dominantType = "double";
  c14_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c14_info[10].fileTimeLo = 1286840378U;
  c14_info[10].fileTimeHi = 0U;
  c14_info[10].mFileTimeLo = 0U;
  c14_info[10].mFileTimeHi = 0U;
  c14_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c14_info[11].name = "eml_index_class";
  c14_info[11].dominantType = "";
  c14_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[11].fileTimeLo = 1323192178U;
  c14_info[11].fileTimeHi = 0U;
  c14_info[11].mFileTimeLo = 0U;
  c14_info[11].mFileTimeHi = 0U;
  c14_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[12].name = "eml_index_times";
  c14_info[12].dominantType = "coder.internal.indexInt";
  c14_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c14_info[12].fileTimeLo = 1286840380U;
  c14_info[12].fileTimeHi = 0U;
  c14_info[12].mFileTimeLo = 0U;
  c14_info[12].mFileTimeHi = 0U;
  c14_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c14_info[13].name = "eml_index_class";
  c14_info[13].dominantType = "";
  c14_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[13].fileTimeLo = 1323192178U;
  c14_info[13].fileTimeHi = 0U;
  c14_info[13].mFileTimeLo = 0U;
  c14_info[13].mFileTimeHi = 0U;
  c14_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[14].name = "eml_index_plus";
  c14_info[14].dominantType = "coder.internal.indexInt";
  c14_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c14_info[14].fileTimeLo = 1286840378U;
  c14_info[14].fileTimeHi = 0U;
  c14_info[14].mFileTimeLo = 0U;
  c14_info[14].mFileTimeHi = 0U;
  c14_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c14_info[15].name = "eml_index_class";
  c14_info[15].dominantType = "";
  c14_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[15].fileTimeLo = 1323192178U;
  c14_info[15].fileTimeHi = 0U;
  c14_info[15].mFileTimeLo = 0U;
  c14_info[15].mFileTimeHi = 0U;
  c14_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[16].name = "eml_int_forloop_overflow_check";
  c14_info[16].dominantType = "";
  c14_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c14_info[16].fileTimeLo = 1346531940U;
  c14_info[16].fileTimeHi = 0U;
  c14_info[16].mFileTimeLo = 0U;
  c14_info[16].mFileTimeHi = 0U;
  c14_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c14_info[17].name = "intmax";
  c14_info[17].dominantType = "char";
  c14_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c14_info[17].fileTimeLo = 1311276916U;
  c14_info[17].fileTimeHi = 0U;
  c14_info[17].mFileTimeLo = 0U;
  c14_info[17].mFileTimeHi = 0U;
  c14_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c14_info[18].name = "abs";
  c14_info[18].dominantType = "double";
  c14_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[18].fileTimeLo = 1343851966U;
  c14_info[18].fileTimeHi = 0U;
  c14_info[18].mFileTimeLo = 0U;
  c14_info[18].mFileTimeHi = 0U;
  c14_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[19].name = "eml_scalar_abs";
  c14_info[19].dominantType = "double";
  c14_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c14_info[19].fileTimeLo = 1286840312U;
  c14_info[19].fileTimeHi = 0U;
  c14_info[19].mFileTimeLo = 0U;
  c14_info[19].mFileTimeHi = 0U;
  c14_info[20].context = "";
  c14_info[20].name = "mrdivide";
  c14_info[20].dominantType = "double";
  c14_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[20].fileTimeLo = 1357973148U;
  c14_info[20].fileTimeHi = 0U;
  c14_info[20].mFileTimeLo = 1319751566U;
  c14_info[20].mFileTimeHi = 0U;
  c14_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[21].name = "rdivide";
  c14_info[21].dominantType = "double";
  c14_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[21].fileTimeLo = 1346531988U;
  c14_info[21].fileTimeHi = 0U;
  c14_info[21].mFileTimeLo = 0U;
  c14_info[21].mFileTimeHi = 0U;
  c14_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[22].name = "eml_scalexp_compatible";
  c14_info[22].dominantType = "double";
  c14_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c14_info[22].fileTimeLo = 1286840396U;
  c14_info[22].fileTimeHi = 0U;
  c14_info[22].mFileTimeLo = 0U;
  c14_info[22].mFileTimeHi = 0U;
  c14_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[23].name = "eml_div";
  c14_info[23].dominantType = "double";
  c14_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c14_info[23].fileTimeLo = 1313369410U;
  c14_info[23].fileTimeHi = 0U;
  c14_info[23].mFileTimeLo = 0U;
  c14_info[23].mFileTimeHi = 0U;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static int32_T c14_e_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i14;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i14, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i14;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
    chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_f_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_b_is_active_c14_JointSpaceControl_Manuf_MCP, const char_T
   *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_JointSpaceControl_Manuf_MCP), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_JointSpaceControl_Manuf_MCP);
  return c14_y;
}

static uint8_T c14_g_emlrt_marshallIn
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance, const mxArray
   *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info
  (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance)
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

void sf_c14_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3195823605U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3785734470U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3551135659U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1139983783U);
}

mxArray *sf_c14_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bagdr5spW2ABH4M8s3D8UB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_JointSpaceControl_Manuf_MCP_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c14_JointSpaceControl_Manuf_MCP(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"k\",},{M[1],M[6],T\"theta\",},{M[8],M[0],T\"is_active_c14_JointSpaceControl_Manuf_MCP\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_JointSpaceControl_Manuf_MCP_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
    chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_Manuf_MCPMachineNumber_,
           14,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"RxRyRz");
          _SFD_SET_DATA_PROPS(1,2,0,1,"k");
          _SFD_SET_DATA_PROPS(2,2,0,1,"theta");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,185);
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
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
            c14_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);

        {
          real_T *c14_theta;
          real_T (*c14_RxRyRz)[3];
          real_T (*c14_k)[3];
          c14_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c14_k = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c14_RxRyRz = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_RxRyRz);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_k);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_theta);
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
  return "43TV8S3l57mtzilx1QDIfC";
}

static void sf_opaque_initialize_c14_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
  initialize_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  enable_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  disable_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  sf_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_JointSpaceControl_Manuf_MCP
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_JointSpaceControl_Manuf_MCP();/* state var info */
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

extern void sf_internal_set_sim_state_c14_JointSpaceControl_Manuf_MCP(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_JointSpaceControl_Manuf_MCP();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_JointSpaceControl_Manuf_MCP
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c14_JointSpaceControl_Manuf_MCP(S);
}

static void sf_opaque_set_sim_state_c14_JointSpaceControl_Manuf_MCP(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c14_JointSpaceControl_Manuf_MCP(S, st);
}

static void sf_opaque_terminate_c14_JointSpaceControl_Manuf_MCP(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_Manuf_MCP_optimization_info();
    }

    finalize_c14_JointSpaceControl_Manuf_MCP
      ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_JointSpaceControl_Manuf_MCP
    ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_JointSpaceControl_Manuf_MCP
      ((SFc14_JointSpaceControl_Manuf_MCPInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_Manuf_MCP_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,14,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1632372756U));
  ssSetChecksum1(S,(389795285U));
  ssSetChecksum2(S,(2755948812U));
  ssSetChecksum3(S,(1621388412U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_JointSpaceControl_Manuf_MCP(SimStruct *S)
{
  SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *chartInstance;
  chartInstance = (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct *)utMalloc
    (sizeof(SFc14_JointSpaceControl_Manuf_MCPInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc14_JointSpaceControl_Manuf_MCPInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_JointSpaceControl_Manuf_MCP;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_JointSpaceControl_Manuf_MCP;
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

void c14_JointSpaceControl_Manuf_MCP_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_JointSpaceControl_Manuf_MCP(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_JointSpaceControl_Manuf_MCP(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_JointSpaceControl_Manuf_MCP(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_JointSpaceControl_Manuf_MCP_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
