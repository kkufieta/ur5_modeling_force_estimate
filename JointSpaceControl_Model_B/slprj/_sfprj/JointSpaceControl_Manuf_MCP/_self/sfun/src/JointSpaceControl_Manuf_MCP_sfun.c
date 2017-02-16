/* Include files */

#include "JointSpaceControl_Manuf_MCP_sfun.h"
#include "JointSpaceControl_Manuf_MCP_sfun_debug_macros.h"
#include "c1_JointSpaceControl_Manuf_MCP.h"
#include "c2_JointSpaceControl_Manuf_MCP.h"
#include "c3_JointSpaceControl_Manuf_MCP.h"
#include "c5_JointSpaceControl_Manuf_MCP.h"
#include "c6_JointSpaceControl_Manuf_MCP.h"
#include "c7_JointSpaceControl_Manuf_MCP.h"
#include "c8_JointSpaceControl_Manuf_MCP.h"
#include "c9_JointSpaceControl_Manuf_MCP.h"
#include "c10_JointSpaceControl_Manuf_MCP.h"
#include "c11_JointSpaceControl_Manuf_MCP.h"
#include "c12_JointSpaceControl_Manuf_MCP.h"
#include "c13_JointSpaceControl_Manuf_MCP.h"
#include "c14_JointSpaceControl_Manuf_MCP.h"
#include "c15_JointSpaceControl_Manuf_MCP.h"
#include "c16_JointSpaceControl_Manuf_MCP.h"
#include "c17_JointSpaceControl_Manuf_MCP.h"
#include "c18_JointSpaceControl_Manuf_MCP.h"
#include "c19_JointSpaceControl_Manuf_MCP.h"
#include "c20_JointSpaceControl_Manuf_MCP.h"
#include "c21_JointSpaceControl_Manuf_MCP.h"
#include "c22_JointSpaceControl_Manuf_MCP.h"
#include "c24_JointSpaceControl_Manuf_MCP.h"
#include "c25_JointSpaceControl_Manuf_MCP.h"
#include "c27_JointSpaceControl_Manuf_MCP.h"
#include "c28_JointSpaceControl_Manuf_MCP.h"
#include "c30_JointSpaceControl_Manuf_MCP.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _JointSpaceControl_Manuf_MCPMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void JointSpaceControl_Manuf_MCP_initializer(void)
{
}

void JointSpaceControl_Manuf_MCP_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_JointSpaceControl_Manuf_MCP_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_JointSpaceControl_Manuf_MCP_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_JointSpaceControl_Manuf_MCP_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3845504622U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1631754381U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3115013211U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(214692192U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1999125056U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(451769129U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(362004876U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1463547800U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c1_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c2_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c3_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c5_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c6_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c7_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c8_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c9_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c10_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c11_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c12_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c13_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c14_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c15_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c16_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c17_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c18_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c19_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c20_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c21_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c22_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c24_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c25_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c27_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c28_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray
            *plhs[]);
          sf_c30_JointSpaceControl_Manuf_MCP_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1764838350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3410240878U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(118138738U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(243351119U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4256953912U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(261842897U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1339404092U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4215688004U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_JointSpaceControl_Manuf_MCP_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "9d4ZBc1LjgGHCVcokFIrLG") == 0) {
          extern mxArray
            *sf_c1_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c1_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "AHIBPiDULbfGazNp2VjmfF") == 0) {
          extern mxArray
            *sf_c2_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c2_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "9d4ZBc1LjgGHCVcokFIrLG") == 0) {
          extern mxArray
            *sf_c3_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c3_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "1p0p4Eb7X58iHa19kcFWWE") == 0) {
          extern mxArray
            *sf_c5_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c5_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "nzAnFn5m1B8plInJg8y7xC") == 0) {
          extern mxArray
            *sf_c6_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c6_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "bagdr5spW2ABH4M8s3D8UB") == 0) {
          extern mxArray
            *sf_c7_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c7_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "Akowil4FuPzP8AFYvcXM4B") == 0) {
          extern mxArray
            *sf_c8_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c8_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "I2i2uFpperEyStY4qjbKVF") == 0) {
          extern mxArray
            *sf_c9_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c9_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "3sn27IkPdn8XWlMAdcPMaD") == 0) {
          extern mxArray
            *sf_c10_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c10_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "DMiDiAmli2npoFnVYr3ZYH") == 0) {
          extern mxArray
            *sf_c11_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c11_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "SZNpsAPyb4G8fJR5xjsCaF") == 0) {
          extern mxArray
            *sf_c12_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c12_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "SYLpeyXWgod32o3TIjWQxB") == 0) {
          extern mxArray
            *sf_c13_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c13_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "bagdr5spW2ABH4M8s3D8UB") == 0) {
          extern mxArray
            *sf_c14_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c14_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "Akowil4FuPzP8AFYvcXM4B") == 0) {
          extern mxArray
            *sf_c15_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c15_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "0EP6jHS9H2hTCDoERnimoD") == 0) {
          extern mxArray
            *sf_c16_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c16_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "kC1ryQMhi3q1FGMxB1H0uE") == 0) {
          extern mxArray
            *sf_c17_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c17_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "CBbrtpYuqffcJZVXnlTmjE") == 0) {
          extern mxArray
            *sf_c18_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c18_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "TSq2RiLJOVIv6G1AmBmhLG") == 0) {
          extern mxArray
            *sf_c19_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c19_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "bgVAyx9NEPHIIbUYFQBI2E") == 0) {
          extern mxArray
            *sf_c20_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c20_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "EP25PSj0Mu2BF7JxkWiFCB") == 0) {
          extern mxArray
            *sf_c21_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c21_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "6J92kSNwndO5cn6LgrzZiH") == 0) {
          extern mxArray
            *sf_c22_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c22_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "hKtZp1Z0Rrhoc60mpWq7F") == 0) {
          extern mxArray
            *sf_c24_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c24_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "1iXtMBqI8BvdUyOMOjf4VG") == 0) {
          extern mxArray
            *sf_c25_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c25_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "FzpNWEma43w4vneqZNb3fG") == 0) {
          extern mxArray
            *sf_c27_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c27_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "PSQRYTN2t68uVgNIyv7CFD") == 0) {
          extern mxArray
            *sf_c28_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c28_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "G9hHwYvxuOTpiK8FomGQsB") == 0) {
          extern mxArray
            *sf_c30_JointSpaceControl_Manuf_MCP_get_autoinheritance_info(void);
          plhs[0] = sf_c30_JointSpaceControl_Manuf_MCP_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray
          *sf_c25_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray
          *sf_c28_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_JointSpaceControl_Manuf_MCP_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "IfrWb0axKr4o0zSLL0Ok9G") == 0) {
          extern mxArray
            *sf_c1_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c1_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "bP9o76gL5mFY7TkgzYkN3") == 0) {
          extern mxArray
            *sf_c2_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c2_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "IfrWb0axKr4o0zSLL0Ok9G") == 0) {
          extern mxArray
            *sf_c3_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c3_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "ABlhaC34JPN3XLi7nEwKB") == 0) {
          extern mxArray
            *sf_c5_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c5_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "353FCkjHQR42BbsOnvmFGC") == 0) {
          extern mxArray
            *sf_c6_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c6_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "43TV8S3l57mtzilx1QDIfC") == 0) {
          extern mxArray
            *sf_c7_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c7_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "Y4Jezfv6fKTJGiVFQdyn5B") == 0) {
          extern mxArray
            *sf_c8_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c8_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "8Q6SSJtq4GzM10QwY833oF") == 0) {
          extern mxArray
            *sf_c9_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c9_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "FeGaVtpE6N0uwshQ5lBq0D") == 0) {
          extern mxArray
            *sf_c10_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c10_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "3KKRZbKbTLfmFTYtQA79zE") == 0) {
          extern mxArray
            *sf_c11_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c11_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "WFrh96vwkk2at13NfnQXDD") == 0) {
          extern mxArray
            *sf_c12_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c12_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "8wKXiQwyuNX7yh9V7xPY3") == 0) {
          extern mxArray
            *sf_c13_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c13_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "43TV8S3l57mtzilx1QDIfC") == 0) {
          extern mxArray
            *sf_c14_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c14_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "Y4Jezfv6fKTJGiVFQdyn5B") == 0) {
          extern mxArray
            *sf_c15_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c15_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "LfkX3YEP8LvfyyR1lkXmCF") == 0) {
          extern mxArray
            *sf_c16_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c16_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "j79fC60vD7Fp8sl30RH0p") == 0) {
          extern mxArray
            *sf_c17_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c17_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "VFn9SBrwufpJ57VFiLH7c") == 0) {
          extern mxArray
            *sf_c18_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c18_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "hcCObZhD7XcY6vcquDis2D") == 0) {
          extern mxArray
            *sf_c19_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c19_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "PlJbDfzTYDOt0dcGSMTCrF") == 0) {
          extern mxArray
            *sf_c20_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c20_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "0vOWprsEaZVE9kKbXu9tCG") == 0) {
          extern mxArray
            *sf_c21_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c21_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "iiQfQmGrrx4DFynkmkjH3G") == 0) {
          extern mxArray
            *sf_c22_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c22_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "rGFyCAdki1Nkil2dnaYBZ") == 0) {
          extern mxArray
            *sf_c24_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c24_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "SilIb6Cx2GyA59NBQhDvfH") == 0) {
          extern mxArray
            *sf_c25_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c25_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "ygNilml2GMqpHSJIUqLbAD") == 0) {
          extern mxArray
            *sf_c27_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c27_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "0anGOUp7atEuWIRYZkXU3C") == 0) {
          extern mxArray
            *sf_c28_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c28_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "zNoUsell6FGeSvXzicMyvC") == 0) {
          extern mxArray
            *sf_c30_JointSpaceControl_Manuf_MCP_third_party_uses_info(void);
          plhs[0] = sf_c30_JointSpaceControl_Manuf_MCP_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void JointSpaceControl_Manuf_MCP_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _JointSpaceControl_Manuf_MCPMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"JointSpaceControl_Manuf_MCP","sfun",0,26,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _JointSpaceControl_Manuf_MCPMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _JointSpaceControl_Manuf_MCPMachineNumber_,0);
}

void JointSpaceControl_Manuf_MCP_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_JointSpaceControl_Manuf_MCP_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "JointSpaceControl_Manuf_MCP", "JointSpaceControl_Manuf_MCP");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_JointSpaceControl_Manuf_MCP_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
