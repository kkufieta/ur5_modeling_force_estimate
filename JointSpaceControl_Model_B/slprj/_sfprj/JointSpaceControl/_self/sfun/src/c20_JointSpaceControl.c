/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_sfun.h"
#include "c20_JointSpaceControl.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c20_debug_family_names[5] = { "nargin", "nargout", "J_a",
  "dq", "dX" };

/* Function Declarations */
static void initialize_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static void initialize_params_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static void enable_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct
  *chartInstance);
static void disable_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct *
  chartInstance);
static void c20_update_debugger_state_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static void set_sim_state_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c20_st);
static void finalize_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct
  *chartInstance);
static void sf_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct
  *chartInstance);
static void c20_chartstep_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static void initSimStructsc20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static void registerMessagesc20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_dX, const char_T *c20_identifier, real_T
  c20_y[6]);
static void c20_b_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[6]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_c_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_eml_scalar_eg(SFc20_JointSpaceControlInstanceStruct
  *chartInstance);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_d_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_e_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_JointSpaceControl, const
  char_T *c20_identifier);
static uint8_T c20_f_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void init_dsm_address_info(SFc20_JointSpaceControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_JointSpaceControl = 0U;
}

static void initialize_params_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void enable_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  real_T c20_u[6];
  const mxArray *c20_b_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T (*c20_dX)[6];
  c20_dX = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2), FALSE);
  for (c20_i0 = 0; c20_i0 < 6; c20_i0++) {
    c20_u[c20_i0] = (*c20_dX)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_hoistedGlobal = chartInstance->c20_is_active_c20_JointSpaceControl;
  c20_b_u = c20_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y, FALSE);
  return c20_st;
}

static void set_sim_state_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv0[6];
  int32_T c20_i1;
  real_T (*c20_dX)[6];
  c20_dX = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)), "dX",
                       c20_dv0);
  for (c20_i1 = 0; c20_i1 < 6; c20_i1++) {
    (*c20_dX)[c20_i1] = c20_dv0[c20_i1];
  }

  chartInstance->c20_is_active_c20_JointSpaceControl = c20_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_JointSpaceControl");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_JointSpaceControl(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct
  *chartInstance)
{
}

static void sf_c20_JointSpaceControl(SFc20_JointSpaceControlInstanceStruct
  *chartInstance)
{
  int32_T c20_i2;
  int32_T c20_i3;
  int32_T c20_i4;
  real_T (*c20_dX)[6];
  real_T (*c20_dq)[6];
  real_T (*c20_J_a)[36];
  c20_dX = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_dq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c20_J_a = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
  for (c20_i2 = 0; c20_i2 < 36; c20_i2++) {
    _SFD_DATA_RANGE_CHECK((*c20_J_a)[c20_i2], 0U);
  }

  for (c20_i3 = 0; c20_i3 < 6; c20_i3++) {
    _SFD_DATA_RANGE_CHECK((*c20_dq)[c20_i3], 1U);
  }

  for (c20_i4 = 0; c20_i4 < 6; c20_i4++) {
    _SFD_DATA_RANGE_CHECK((*c20_dX)[c20_i4], 2U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  c20_chartstep_c20_JointSpaceControl(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_JointSpaceControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c20_chartstep_c20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
  int32_T c20_i5;
  real_T c20_J_a[36];
  int32_T c20_i6;
  real_T c20_dq[6];
  uint32_T c20_debug_family_var_map[5];
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  real_T c20_dX[6];
  int32_T c20_i7;
  real_T c20_a[36];
  int32_T c20_i8;
  real_T c20_b[6];
  int32_T c20_i9;
  int32_T c20_i10;
  int32_T c20_i11;
  real_T c20_C[6];
  int32_T c20_i12;
  int32_T c20_i13;
  int32_T c20_i14;
  int32_T c20_i15;
  int32_T c20_i16;
  int32_T c20_i17;
  int32_T c20_i18;
  real_T (*c20_b_dX)[6];
  real_T (*c20_b_dq)[6];
  real_T (*c20_b_J_a)[36];
  c20_b_dX = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_b_dq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_J_a = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
  for (c20_i5 = 0; c20_i5 < 36; c20_i5++) {
    c20_J_a[c20_i5] = (*c20_b_J_a)[c20_i5];
  }

  for (c20_i6 = 0; c20_i6 < 6; c20_i6++) {
    c20_dq[c20_i6] = (*c20_b_dq)[c20_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_c_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_c_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_J_a, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_dq, 3U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_dX, 4U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i7 = 0; c20_i7 < 36; c20_i7++) {
    c20_a[c20_i7] = c20_J_a[c20_i7];
  }

  for (c20_i8 = 0; c20_i8 < 6; c20_i8++) {
    c20_b[c20_i8] = c20_dq[c20_i8];
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i9 = 0; c20_i9 < 6; c20_i9++) {
    c20_dX[c20_i9] = 0.0;
  }

  for (c20_i10 = 0; c20_i10 < 6; c20_i10++) {
    c20_dX[c20_i10] = 0.0;
  }

  for (c20_i11 = 0; c20_i11 < 6; c20_i11++) {
    c20_C[c20_i11] = c20_dX[c20_i11];
  }

  for (c20_i12 = 0; c20_i12 < 6; c20_i12++) {
    c20_dX[c20_i12] = c20_C[c20_i12];
  }

  for (c20_i13 = 0; c20_i13 < 6; c20_i13++) {
    c20_C[c20_i13] = c20_dX[c20_i13];
  }

  for (c20_i14 = 0; c20_i14 < 6; c20_i14++) {
    c20_dX[c20_i14] = c20_C[c20_i14];
  }

  for (c20_i15 = 0; c20_i15 < 6; c20_i15++) {
    c20_dX[c20_i15] = 0.0;
    c20_i16 = 0;
    for (c20_i17 = 0; c20_i17 < 6; c20_i17++) {
      c20_dX[c20_i15] += c20_a[c20_i16 + c20_i15] * c20_b[c20_i17];
      c20_i16 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i18 = 0; c20_i18 < 6; c20_i18++) {
    (*c20_b_dX)[c20_i18] = c20_dX[c20_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
}

static void initSimStructsc20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void registerMessagesc20_JointSpaceControl
  (SFc20_JointSpaceControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i19;
  real_T c20_b_inData[6];
  int32_T c20_i20;
  real_T c20_u[6];
  const mxArray *c20_y = NULL;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i19 = 0; c20_i19 < 6; c20_i19++) {
    c20_b_inData[c20_i19] = (*(real_T (*)[6])c20_inData)[c20_i19];
  }

  for (c20_i20 = 0; c20_i20 < 6; c20_i20++) {
    c20_u[c20_i20] = c20_b_inData[c20_i20];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_dX, const char_T *c20_identifier, real_T
  c20_y[6])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_dX), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_dX);
}

static void c20_b_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[6])
{
  real_T c20_dv1[6];
  int32_T c20_i21;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c20_i21 = 0; c20_i21 < 6; c20_i21++) {
    c20_y[c20_i21] = c20_dv1[c20_i21];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_dX;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[6];
  int32_T c20_i22;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_dX = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_dX), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_dX);
  for (c20_i22 = 0; c20_i22 < 6; c20_i22++) {
    (*(real_T (*)[6])c20_outData)[c20_i22] = c20_y[c20_i22];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i23;
  int32_T c20_i24;
  int32_T c20_i25;
  real_T c20_b_inData[36];
  int32_T c20_i26;
  int32_T c20_i27;
  int32_T c20_i28;
  real_T c20_u[36];
  const mxArray *c20_y = NULL;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i23 = 0;
  for (c20_i24 = 0; c20_i24 < 6; c20_i24++) {
    for (c20_i25 = 0; c20_i25 < 6; c20_i25++) {
      c20_b_inData[c20_i25 + c20_i23] = (*(real_T (*)[36])c20_inData)[c20_i25 +
        c20_i23];
    }

    c20_i23 += 6;
  }

  c20_i26 = 0;
  for (c20_i27 = 0; c20_i27 < 6; c20_i27++) {
    for (c20_i28 = 0; c20_i28 < 6; c20_i28++) {
      c20_u[c20_i28 + c20_i26] = c20_b_inData[c20_i28 + c20_i26];
    }

    c20_i26 += 6;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static real_T c20_c_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_JointSpaceControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo;
  c20_ResolvedFunctionInfo c20_info[9];
  c20_ResolvedFunctionInfo (*c20_b_info)[9];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i29;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  c20_b_info = (c20_ResolvedFunctionInfo (*)[9])c20_info;
  (*c20_b_info)[0].context = "";
  (*c20_b_info)[0].name = "mtimes";
  (*c20_b_info)[0].dominantType = "double";
  (*c20_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c20_b_info)[0].fileTimeLo = 1289541292U;
  (*c20_b_info)[0].fileTimeHi = 0U;
  (*c20_b_info)[0].mFileTimeLo = 0U;
  (*c20_b_info)[0].mFileTimeHi = 0U;
  (*c20_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c20_b_info)[1].name = "eml_index_class";
  (*c20_b_info)[1].dominantType = "";
  (*c20_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c20_b_info)[1].fileTimeLo = 1323192178U;
  (*c20_b_info)[1].fileTimeHi = 0U;
  (*c20_b_info)[1].mFileTimeLo = 0U;
  (*c20_b_info)[1].mFileTimeHi = 0U;
  (*c20_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c20_b_info)[2].name = "eml_scalar_eg";
  (*c20_b_info)[2].dominantType = "double";
  (*c20_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c20_b_info)[2].fileTimeLo = 1286840396U;
  (*c20_b_info)[2].fileTimeHi = 0U;
  (*c20_b_info)[2].mFileTimeLo = 0U;
  (*c20_b_info)[2].mFileTimeHi = 0U;
  (*c20_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c20_b_info)[3].name = "eml_xgemm";
  (*c20_b_info)[3].dominantType = "char";
  (*c20_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c20_b_info)[3].fileTimeLo = 1299098372U;
  (*c20_b_info)[3].fileTimeHi = 0U;
  (*c20_b_info)[3].mFileTimeLo = 0U;
  (*c20_b_info)[3].mFileTimeHi = 0U;
  (*c20_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c20_b_info)[4].name = "eml_blas_inline";
  (*c20_b_info)[4].dominantType = "";
  (*c20_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c20_b_info)[4].fileTimeLo = 1299098368U;
  (*c20_b_info)[4].fileTimeHi = 0U;
  (*c20_b_info)[4].mFileTimeLo = 0U;
  (*c20_b_info)[4].mFileTimeHi = 0U;
  (*c20_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c20_b_info)[5].name = "mtimes";
  (*c20_b_info)[5].dominantType = "double";
  (*c20_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c20_b_info)[5].fileTimeLo = 1289541292U;
  (*c20_b_info)[5].fileTimeHi = 0U;
  (*c20_b_info)[5].mFileTimeLo = 0U;
  (*c20_b_info)[5].mFileTimeHi = 0U;
  (*c20_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c20_b_info)[6].name = "eml_index_class";
  (*c20_b_info)[6].dominantType = "";
  (*c20_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c20_b_info)[6].fileTimeLo = 1323192178U;
  (*c20_b_info)[6].fileTimeHi = 0U;
  (*c20_b_info)[6].mFileTimeLo = 0U;
  (*c20_b_info)[6].mFileTimeHi = 0U;
  (*c20_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c20_b_info)[7].name = "eml_scalar_eg";
  (*c20_b_info)[7].dominantType = "double";
  (*c20_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c20_b_info)[7].fileTimeLo = 1286840396U;
  (*c20_b_info)[7].fileTimeHi = 0U;
  (*c20_b_info)[7].mFileTimeLo = 0U;
  (*c20_b_info)[7].mFileTimeHi = 0U;
  (*c20_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c20_b_info)[8].name = "eml_refblas_xgemm";
  (*c20_b_info)[8].dominantType = "char";
  (*c20_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c20_b_info)[8].fileTimeLo = 1299098374U;
  (*c20_b_info)[8].fileTimeHi = 0U;
  (*c20_b_info)[8].mFileTimeLo = 0U;
  (*c20_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c20_i29 = 0; c20_i29 < 9; c20_i29++) {
    c20_r0 = &c20_info[c20_i29];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->context)), "context", "nameCaptureInfo",
                    c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->name)), "name", "nameCaptureInfo",
                    c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->resolved)), "resolved",
                    "nameCaptureInfo", c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      &c20_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c20_i29);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      &c20_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c20_i29);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_eml_scalar_eg(SFc20_JointSpaceControlInstanceStruct
  *chartInstance)
{
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static int32_T c20_d_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i30;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i30, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i30;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_JointSpaceControl, const
  char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_JointSpaceControl), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_JointSpaceControl);
  return c20_y;
}

static uint8_T c20_f_emlrt_marshallIn(SFc20_JointSpaceControlInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void init_dsm_address_info(SFc20_JointSpaceControlInstanceStruct
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

void sf_c20_JointSpaceControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3935153248U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3110133399U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3531889774U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3361229433U);
}

mxArray *sf_c20_JointSpaceControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bgVAyx9NEPHIIbUYFQBI2E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c20_JointSpaceControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c20_JointSpaceControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[12],T\"dX\",},{M[8],M[0],T\"is_active_c20_JointSpaceControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_JointSpaceControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_JointSpaceControlInstanceStruct *chartInstance;
    chartInstance = (SFc20_JointSpaceControlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControlMachineNumber_,
           20,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"J_a");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(2,2,0,1,"dX");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,193);
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
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          real_T (*c20_J_a)[36];
          real_T (*c20_dq)[6];
          real_T (*c20_dX)[6];
          c20_dX = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c20_dq = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c20_J_a = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_J_a);
          _SFD_SET_DATA_VALUE_PTR(1U, *c20_dq);
          _SFD_SET_DATA_VALUE_PTR(2U, *c20_dX);
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
  return "PlJbDfzTYDOt0dcGSMTCrF";
}

static void sf_opaque_initialize_c20_JointSpaceControl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
  initialize_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_JointSpaceControl(void *chartInstanceVar)
{
  enable_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_JointSpaceControl(void *chartInstanceVar)
{
  disable_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_JointSpaceControl(void *chartInstanceVar)
{
  sf_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_JointSpaceControl(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_JointSpaceControl
    ((SFc20_JointSpaceControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_JointSpaceControl();/* state var info */
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

extern void sf_internal_set_sim_state_c20_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_JointSpaceControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_JointSpaceControl(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_JointSpaceControl(S);
}

static void sf_opaque_set_sim_state_c20_JointSpaceControl(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c20_JointSpaceControl(S, st);
}

static void sf_opaque_terminate_c20_JointSpaceControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_JointSpaceControlInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_optimization_info();
    }

    finalize_c20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_JointSpaceControl((SFc20_JointSpaceControlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_JointSpaceControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_JointSpaceControl
      ((SFc20_JointSpaceControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,20,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3504392491U));
  ssSetChecksum1(S,(2365346673U));
  ssSetChecksum2(S,(1052796057U));
  ssSetChecksum3(S,(2521795167U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_JointSpaceControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_JointSpaceControl(SimStruct *S)
{
  SFc20_JointSpaceControlInstanceStruct *chartInstance;
  chartInstance = (SFc20_JointSpaceControlInstanceStruct *)utMalloc(sizeof
    (SFc20_JointSpaceControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_JointSpaceControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_JointSpaceControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_JointSpaceControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_JointSpaceControl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_JointSpaceControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_JointSpaceControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_JointSpaceControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_JointSpaceControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_JointSpaceControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_JointSpaceControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_JointSpaceControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_JointSpaceControl;
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

void c20_JointSpaceControl_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_JointSpaceControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_JointSpaceControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_JointSpaceControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
