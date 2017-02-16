#include "__cf_JointSpaceControl.h"
#ifndef RTW_HEADER_JointSpaceControl_h_
#define RTW_HEADER_JointSpaceControl_h_
#ifndef JointSpaceControl_COMMON_INCLUDES_
#define JointSpaceControl_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "JointSpaceControl_types.h"
#define MODEL_NAME JointSpaceControl
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (42) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (12)   
#elif NCSTATES != 12
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (NULL)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
typedef struct { real_T c3phy4uy3g [ 36 ] ; real_T dvbqjjkdy0 [ 6 ] ; real_T
eqanm5grr0 [ 6 ] ; } ltocdbcp2k ; typedef struct { real_T p505mfvaxs [ 6 ] ;
} okdv3yvldy ; typedef struct { real_T blnxm0qljw [ 6 ] ; real_T ji3bwqz25y [
6 ] ; real_T gfvbxq25vn [ 6 ] ; real_T d1pmn0ij1l [ 6 ] ; real_T mzfhfa0zkn [
6 ] ; real_T hmdtjrw30e [ 6 ] ; real_T ctrvb4cmxr [ 9 ] ; real_T lqmj5akbao [
36 ] ; real_T hlydmluflh [ 6 ] ; real_T ki1c4j2kes [ 6 ] ; real_T ibhm4qsbtk
[ 6 ] ; real_T ew2txbl40n [ 6 ] ; real_T ll04tin3ej [ 6 ] ; real_T on2ccbefn1
[ 3 ] ; real_T fumx0wqu0p [ 6 ] ; real_T oxqjrfhajt [ 6 ] ; real_T en2yguwqwb
[ 6 ] ; real_T loh4vtrrkc [ 9 ] ; real_T at3pokyun0 [ 3 ] ; real_T eziy2ljh0e
; real_T ibtz24ephg [ 6 ] ; real_T ank5kdwdcq [ 3 ] ; real_T mytz3m1ztc ;
real_T agea4cv0wk [ 6 ] ; real_T lriz3d1h1w [ 9 ] ; real_T lysn5dtfor [ 36 ]
; real_T ewrxhcp51e [ 36 ] ; real_T oshetbdj3o [ 36 ] ; real_T kbgoclq5ff [
18 ] ; real_T iq3tvc1jiy [ 18 ] ; real_T mju1w13ukz [ 3 ] ; real_T l4pjsja05o
; real_T k0j4ewnvel [ 3 ] ; real_T kf4tsa5k52 ; okdv3yvldy lddm5yrsqq ;
ltocdbcp2k mvghmhsjz4 ; okdv3yvldy nghlo5plg0 ; ltocdbcp2k okpo04efs2 ; } B ;
typedef struct { struct { real_T TimeStampA ; real_T LastUAtTimeA [ 36 ] ;
real_T TimeStampB ; real_T LastUAtTimeB [ 36 ] ; } hifeqprlqm ; struct {
real_T TimeStampA ; real_T LastUAtTimeA [ 6 ] ; real_T TimeStampB ; real_T
LastUAtTimeB [ 6 ] ; } bqyz2wxpe2 ; struct { void * LoggedData ; } k132invbs3
; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
njjuawiwjd ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} jpryus4wqu ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr
; } fanbrdsnik ; struct { void * LoggedData ; } aofqajehkm ; struct { void *
LoggedData ; } c3ap40vzp1 ; struct { void * LoggedData ; } czgludmajx ;
struct { void * LoggedData ; } fozyij0lt1 ; struct { void * LoggedData ; }
jhry0z5oig ; struct { void * LoggedData ; } cuuu1ut1bt ; struct { void *
LoggedData ; } mwkifxrisj ; struct { void * LoggedData ; } hmiwsxfdg0 ;
struct { void * LoggedData ; } epwhptnepu ; struct { void * LoggedData ; }
epnjkmarbk ; struct { void * LoggedData ; } cu0zg5v3uj ; struct { void *
LoggedData ; } lxfu1qrpbu ; struct { void * LoggedData ; } oxwae315aw ;
struct { void * LoggedData ; } nc244ysu3p ; struct { void * TimePtr ; void *
DataPtr ; void * RSimInfoPtr ; } oyg0xcbkq2 ; struct { void * TimePtr ; void
* DataPtr ; void * RSimInfoPtr ; } meb1ohukzh ; struct { void * TimePtr ;
void * DataPtr ; void * RSimInfoPtr ; } kgedcln4ib ; struct { void * TimePtr
; void * DataPtr ; void * RSimInfoPtr ; } di0rqa2hxr ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } ftfrxtmkht ; struct { void
* TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } gz4yk0vbeq ; struct {
void * LoggedData ; } exrbmkyn4h ; struct { void * TimePtr ; void * DataPtr ;
void * RSimInfoPtr ; } afqqfcyfky ; struct { void * LoggedData ; } dz1x5atckv
; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
j3lsycmps3 ; struct { void * LoggedData ; } ik52nvxufc ; struct { int_T
PrevIndex ; } htkw22hmrn ; struct { int_T PrevIndex ; } de2p54zry4 ; struct {
int_T PrevIndex ; } i4j2tjognw ; struct { int_T PrevIndex ; } abooqdppeu ;
struct { int_T PrevIndex ; } bl25evyz1e ; struct { int_T PrevIndex ; }
ofgbpzna2m ; struct { int_T PrevIndex ; } nuog3ppeov ; struct { int_T
PrevIndex ; } mis12p4hji ; struct { int_T PrevIndex ; } pnfgom0ma5 ; struct {
int_T PrevIndex ; } jehbknbywz ; struct { int_T PrevIndex ; } mohuhbx5xb ;
int_T mh2ebmwctw [ 6 ] ; int_T om4jx250hy [ 6 ] ; int_T h0luuex5q2 [ 6 ] ;
int_T itd1vtaubg [ 6 ] ; } DW ; typedef struct { real_T oh2bsf3aw5 [ 6 ] ;
real_T eym24ufl0b [ 6 ] ; } X ; typedef struct { real_T oh2bsf3aw5 [ 6 ] ;
real_T eym24ufl0b [ 6 ] ; } XDot ; typedef struct { boolean_T oh2bsf3aw5 [ 6
] ; boolean_T eym24ufl0b [ 6 ] ; } XDis ; typedef struct { real_T oh2bsf3aw5
[ 6 ] ; real_T eym24ufl0b [ 6 ] ; } CStateAbsTol ; typedef struct { real_T
barjk4hla1 [ 6 ] ; real_T ccd1n420az [ 6 ] ; real_T gkokqkqsys [ 6 ] ; real_T
ebnnvryhem [ 6 ] ; real_T ftli25xlsi [ 6 ] ; real_T azcjmsbiwi [ 6 ] ; real_T
orbk4xiljm [ 6 ] ; real_T dzeixerbua [ 6 ] ; real_T ideoc3ef2t [ 6 ] ; real_T
e5por3dzyk [ 6 ] ; } ZCV ; typedef struct { ZCSigState morkufsqul [ 6 ] ;
ZCSigState jdiio4fjqt [ 6 ] ; ZCSigState hd20akwh4k [ 6 ] ; ZCSigState
irsoq1be2b [ 6 ] ; ZCSigState bztnc41mmj [ 6 ] ; ZCSigState g4fo5brgow [ 6 ]
; ZCSigState doyyd5me1y [ 6 ] ; ZCSigState lsenyptmpx [ 6 ] ; ZCSigState
h3jioa21z4 [ 6 ] ; ZCSigState pv3tf0fbll [ 6 ] ; } PrevZCX ; struct P_ {
real_T Constant_Value [ 3 ] ; real_T FromWorkspace2_Time0 [ 1312 ] ; real_T
FromWorkspace2_Data0 [ 7872 ] ; real_T FromWorkspace5_Time0 [ 1312 ] ; real_T
FromWorkspace5_Data0 [ 7872 ] ; real_T FromWorkspace3_Time0 [ 1312 ] ; real_T
FromWorkspace3_Data0 [ 7872 ] ; real_T Integrator3_IC [ 6 ] ; real_T
Integrator3_UpperSat [ 6 ] ; real_T Integrator3_LowerSat [ 6 ] ; real_T
Integrator2_IC [ 6 ] ; real_T Integrator2_UpperSat [ 6 ] ; real_T
Integrator2_LowerSat [ 6 ] ; real_T Gain_Gain [ 36 ] ; real_T Gain1_Gain [ 36
] ; real_T torque_limits1_UpperSat [ 6 ] ; real_T torque_limits1_LowerSat [ 6
] ; real_T acc_limits1_UpperSat [ 6 ] ; real_T acc_limits1_LowerSat [ 6 ] ;
real_T FromWorkspace5_Time0_lq40dglfbc [ 1312 ] ; real_T
FromWorkspace5_Data0_b3yhoghqxp [ 7872 ] ; real_T FromWorkspace1_Time0 [ 1312
] ; real_T FromWorkspace1_Data0 [ 7872 ] ; real_T
FromWorkspace2_Time0_pjbseop3la [ 1312 ] ; real_T
FromWorkspace2_Data0_cs3a2ku0bw [ 7872 ] ; real_T
FromWorkspace3_Time0_at4l0orznp [ 1312 ] ; real_T
FromWorkspace3_Data0_kk2jdg25gp [ 7872 ] ; real_T FromWorkspace4_Time0 [ 1312
] ; real_T FromWorkspace4_Data0 [ 3936 ] ; real_T FromWorkspace6_Time0 [ 1312
] ; real_T FromWorkspace6_Data0 [ 7872 ] ; real_T FromWorkspace7_Time0 [ 1312
] ; real_T FromWorkspace7_Data0 [ 7872 ] ; real_T FromWorkspace8_Time0 [ 1312
] ; real_T FromWorkspace8_Data0 [ 7872 ] ; } ; extern P rtP ; extern const
char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern PrevZCX rtPrevZCX ; extern SimStruct * const rtS ; extern const
int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const int_T
gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern const
char * gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern
const int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ;
#endif
