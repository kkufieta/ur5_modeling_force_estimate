#include "__cf_JointSpaceControl.h"
#include <math.h>
#include "JointSpaceControl.h"
#include "JointSpaceControl_private.h"
#include "JointSpaceControl_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 11 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 2 ;
const char_T * gbl_raccel_Version = "8.4 (R2013a) 13-Feb-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} const char * gblSlvrJacPatternFileName =
"slprj//raccel//JointSpaceControl//JointSpaceControl_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static void kug0xcztmu ( const real_T x [ 9 ] , real_T y [ 9 ] )
; void nfvr5phzhh ( const real_T ozbvfd5n0v [ 6 ] , const real_T jtm353sqni [
6 ] , ltocdbcp2k * localB ) { localB -> c3phy4uy3g [ 0 ] = ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 1 ] )
* 0.41364213499999991 + muDoubleScalarCos ( ozbvfd5n0v [ 4 ] ) * 0.0029173632
) + muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 4 ] ) * -
1.6263032587282567E-19 ) + muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 1 ] - 2.0 *
ozbvfd5n0v [ 4 ] ) * - 1.6263032587282567E-19 ) + muDoubleScalarCos ( 2.0 *
ozbvfd5n0v [ 3 ] ) * - 4.3368086899420177E-19 ) + muDoubleScalarCos ( 2.0 *
ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 3 ] ) * 4.3368086899420177E-19 ) +
muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) *
4.3368086899420177E-19 ) + muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ]
) * - 0.00013221207530500002 ) + muDoubleScalarCos ( ( ( - 2.0 * ozbvfd5n0v [
4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v
[ 1 ] ) * - 0.00013221207530500002 ) + muDoubleScalarCos ( 2.0 * ozbvfd5n0v [
4 ] ) * 0.00026442415060999971 ) + muDoubleScalarCos ( ( 2.0 * ozbvfd5n0v [ 3
] + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * -
4.6295616399996166E-6 ) + muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 4 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) *
8.1315162936412833E-20 ) + muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 3 ] + -
ozbvfd5n0v [ 4 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) *
8.1315162936412833E-20 ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * - 0.007778078 ) +
muDoubleScalarSin ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * - 0.007778078 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * 0.0028437600000000003 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * 0.0028437600000000003 ) + muDoubleScalarSin ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * - 0.0028437600000000003 ) +
0.57863617116011989 ) + muDoubleScalarCos ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 4 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarCos ( ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 4 ] ) * 2.7105054312137611E-20 ) + muDoubleScalarCos ( 2.0 *
ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 4 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarCos ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 4 ] ) * - 2.7105054312137611E-20 ) + muDoubleScalarCos ( 2.0 *
ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 1 ] ) * 0.022579986776000004 ) +
muDoubleScalarCos ( ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) -
ozbvfd5n0v [ 4 ] ) * 2.7105054312137611E-20 ) + muDoubleScalarCos ( 2.0 *
ozbvfd5n0v [ 3 ] - ozbvfd5n0v [ 4 ] ) * 2.7105054312137611E-20 ; localB ->
c3phy4uy3g [ 6 ] = ( ( ( ( ( ( ( muDoubleScalarCos ( ( ( ozbvfd5n0v [ 1 ] -
2.0 * ozbvfd5n0v [ 4 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) *
3.2526065174565133E-19 + muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * -
0.00026442415060999971 ) + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.0007293408
) + muDoubleScalarSin ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarSin ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 1 ] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.0007293408 )
+ muDoubleScalarSin ( ozbvfd5n0v [ 1 ] ) * 0.267177491 ) + muDoubleScalarCos
( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) *
0.00202230028 ; localB -> c3phy4uy3g [ 12 ] = ( ( ( muDoubleScalarCos ( ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * - 0.0007293408 + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2
] ) + ozbvfd5n0v [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.0007293408 )
+ muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00026442415061000003 ; localB
-> c3phy4uy3g [ 18 ] = ( ( ( muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.0007293408
+ muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) *
0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.0007293408 )
+ muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00026442415061000003 ; localB
-> c3phy4uy3g [ 24 ] = ( ( ( muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00201419266993 +
muDoubleScalarSin ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.0007293408
) + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.0007293408 ) +
muDoubleScalarSin ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) * -
0.0028437600000000003 ; localB -> c3phy4uy3g [ 30 ] = muDoubleScalarCos ( ( (
- ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * - 6.08795974E-5 + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 6.08795974E-5 ; localB ->
c3phy4uy3g [ 1 ] = ( ( ( ( ( muDoubleScalarCos ( ( ( - ( 2.0 * ozbvfd5n0v [ 4
] ) + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) *
0.00026442415061000003 + ( muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.00202230028 + muDoubleScalarSin (
ozbvfd5n0v [ 1 ] ) * 0.267177491 ) ) + muDoubleScalarSin ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 1 ] ) * 0.0028437600000000003 ) + muDoubleScalarSin ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00026442415061000003 ) +
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.0007293408 ) + muDoubleScalarCos ( ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * - 0.0007293408 ; localB -> c3phy4uy3g [ 7 ] = ( ( ( muDoubleScalarSin ( (
- ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * -
0.0056875200000000006 + muDoubleScalarSin ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2
] ) * - 0.015556156000000002 ) + 0.88551842438821993 ) + muDoubleScalarCos (
2.0 * ozbvfd5n0v [ 4 ] ) * - 0.00052884830122000006 ) + muDoubleScalarSin ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) *
0.0056875200000000006 ; localB -> c3phy4uy3g [ 13 ] = ( ( ( muDoubleScalarSin
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * -
0.0028437600000000003 + muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] ) * -
0.00052884830122000006 ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * 0.0028437600000000003 ) +
0.049670834388219995 ) + muDoubleScalarSin ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [
2 ] ) * - 0.007778077999999999 ; localB -> c3phy4uy3g [ 19 ] = ( ( (
muDoubleScalarSin ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * 0.0028437600000000003 + muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] ) *
- 0.00052884830122000006 ) + muDoubleScalarSin ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) * - 0.007778077999999999 ) + muDoubleScalarSin ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * -
0.0028437600000000003 ) + 0.0029100855382200004 ; localB -> c3phy4uy3g [ 25 ]
= muDoubleScalarSin ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) * 0.0028437600000000003 + muDoubleScalarSin ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * 0.0028437600000000003 ; localB ->
c3phy4uy3g [ 31 ] = 0.0001217591948 * muDoubleScalarCos ( ozbvfd5n0v [ 4 ] )
; localB -> c3phy4uy3g [ 2 ] = ( ( ( muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * -
0.0007293408 + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) +
ozbvfd5n0v [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.0007293408 )
+ muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00026442415061000003 ; localB
-> c3phy4uy3g [ 8 ] = ( ( ( muDoubleScalarSin ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * - 0.0028437600000000003 +
muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] ) * - 0.00052884830122000006 ) +
muDoubleScalarSin ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * -
0.0077780780000000008 ) + 0.049670834388219995 ) + muDoubleScalarSin ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) *
0.0028437600000000003 ; localB -> c3phy4uy3g [ 14 ] = muDoubleScalarCos ( 2.0
* ozbvfd5n0v [ 4 ] ) * - 0.00052884830122000006 + 0.049670834388219995 ;
localB -> c3phy4uy3g [ 20 ] = muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] ) *
- 0.00052884830122000006 + 0.0029100855382200004 ; localB -> c3phy4uy3g [ 26
] = 0.0 ; localB -> c3phy4uy3g [ 32 ] = 0.0001217591948 * muDoubleScalarCos (
ozbvfd5n0v [ 4 ] ) ; localB -> c3phy4uy3g [ 3 ] = ( ( ( muDoubleScalarCos ( (
( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * - 0.0007293408 + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0
* ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 0.0007293408 )
+ muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00026442415061000003 ; localB
-> c3phy4uy3g [ 9 ] = ( ( ( muDoubleScalarSin ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * - 0.0028437600000000003 +
muDoubleScalarSin ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] )
* - 0.00052884830122000006 ) + muDoubleScalarSin ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) * - 0.0077780780000000008 ) + 0.0029100855382200004 ;
localB -> c3phy4uy3g [ 15 ] = muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] ) *
- 0.00052884830122000006 + 0.00291008553822 ; localB -> c3phy4uy3g [ 21 ] =
muDoubleScalarCos ( 2.0 * ozbvfd5n0v [ 4 ] ) * - 0.00052884830122000006 +
0.0029100855382200004 ; localB -> c3phy4uy3g [ 27 ] = 0.0 ; localB ->
c3phy4uy3g [ 33 ] = 0.0001217591948 * muDoubleScalarCos ( ozbvfd5n0v [ 4 ] )
; localB -> c3phy4uy3g [ 4 ] = ( ( ( muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * -
0.0007293408 + muDoubleScalarSin ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarSin ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [
1 ] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.00201419266994 ) +
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * - 0.0007293408 ; localB -> c3phy4uy3g [ 10 ] =
muDoubleScalarSin ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * 0.0028437600000000003 + muDoubleScalarSin ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * 0.0028437600000000003 ; localB ->
c3phy4uy3g [ 16 ] = 0.0 ; localB -> c3phy4uy3g [ 22 ] = 0.0 ; localB ->
c3phy4uy3g [ 28 ] = 0.00201419266993 ; localB -> c3phy4uy3g [ 34 ] = 0.0 ;
localB -> c3phy4uy3g [ 5 ] = muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * -
6.08795974E-5 + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] )
+ ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 6.08795974E-5 ; localB ->
c3phy4uy3g [ 11 ] = 0.0001217591948 * muDoubleScalarCos ( ozbvfd5n0v [ 4 ] )
; localB -> c3phy4uy3g [ 17 ] = 0.0001217591948 * muDoubleScalarCos (
ozbvfd5n0v [ 4 ] ) ; localB -> c3phy4uy3g [ 23 ] = 0.0001217591948 *
muDoubleScalarCos ( ozbvfd5n0v [ 4 ] ) ; localB -> c3phy4uy3g [ 29 ] = 0.0 ;
localB -> c3phy4uy3g [ 35 ] = 0.0001217591948 ; localB -> dvbqjjkdy0 [ 0 ] =
0.0 ; localB -> dvbqjjkdy0 [ 1 ] = ( ( muDoubleScalarSin ( ( ( - ozbvfd5n0v [
4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 *
0.0066912000000000004 + muDoubleScalarCos ( ozbvfd5n0v [ 1 ] ) * 9.81 * -
2.37167 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * - 0.0066912000000000004 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * 9.81 * 0.01830136 ; localB -> dvbqjjkdy0 [ 2 ] = ( muDoubleScalarSin (
( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
1 ] ) * 9.81 * - 0.0066912000000000004 + muDoubleScalarSin ( ( ozbvfd5n0v [ 3
] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * 0.01830136 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * 0.0066912000000000004 ; localB ->
dvbqjjkdy0 [ 3 ] = ( muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [
3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * -
0.0066912000000000004 + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * 0.01830136 ) + muDoubleScalarSin ( ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * 9.81 * 0.0066912000000000004 ; localB -> dvbqjjkdy0 [ 4 ] =
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * - 0.0066912000000000004 +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * 9.81 * - 0.0066912000000000004 ; localB ->
dvbqjjkdy0 [ 5 ] = 0.0 ; localB -> eqanm5grr0 [ 0 ] = ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( muDoubleScalarSin ( ( ( ( 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [
3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [ 4 ] ) * (
5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] ) + muDoubleScalarSin ( ( ( ( -
2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( 2.5E-15 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] +
2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ]
) - ozbvfd5n0v [ 4 ] ) * ( 2.5E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) )
- 2.5E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 4 ] ) ) - muDoubleScalarSin ( ( ( ( - 2.0 *
ozbvfd5n0v [ 5 ] + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0
* ozbvfd5n0v [ 1 ] ) + ozbvfd5n0v [ 4 ] ) * ( 2.5E-15 * jtm353sqni [ 0 ] *
jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0 *
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( 5.0E-15 * jtm353sqni [ 0 ]
* jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] +
2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ]
) * ( 5.0E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) + muDoubleScalarCos (
( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 *
ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * - 0.0056875200000000006 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * - 4.3368086899420177E-19 ) +
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * 4.9999988958188135E-14 ) + jtm353sqni
[ 0 ] * jtm353sqni [ 1 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 1 ] ) * -
0.82728427000054983 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + 2.0
* ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) *
( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * 0.00026442415071 ) + jtm353sqni [ 0
] * jtm353sqni [ 1 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2 ] ) *
4.9999934748079511E-13 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0
* ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) * 9.2591233300000353E-6 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 1 ] ) * 4.9999934748079511E-14 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 1
] - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * -
4.99996908025907E-14 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 *
ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * -
0.045159973551500004 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) * 4.9999988958188135E-14 ) + muDoubleScalarSin ( ( 2.0 *
ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * - 4.9999988958188135E-14 ) +
muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * 4.3368086899420177E-19 ) +
muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) * 0.00026442415071 ) + jtm353sqni [ 0 ] * jtm353sqni [ 1 ]
* muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
1.7347234759768071E-18 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) * - 0.015556156 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * -
4.9999880537970887E-14 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 1 ] - 2.0 *
ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) *
4.9999988958188135E-14 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0
* ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 2 ] ) * - 4.9999988958188135E-14 ) + muDoubleScalarSin ( ( 2.0 *
ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * 1.3552527156068805E-20 ) +
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * - 1.3552527156068805E-20 ) +
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 3 ] - 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * - 1.3552527156068805E-20 ) +
muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 3 ] ) - 2.0
* ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0
* ozbvfd5n0v [ 2 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 2 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 2 ] - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 2 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2
] + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0
* ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 2 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 3 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 2 ] ) * - 5.4210108624275222E-20 ) + jtm353sqni [ 0 ] * jtm353sqni [ 2 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 3 ] ) * 5.4210108624275222E-20 ) +
jtm353sqni [ 0 ] * jtm353sqni [ 2 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
1 ] ) * 5.0001669471555488E-14 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2 ]
+ 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * -
0.045159973552 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0 *
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 2 ] ) * 9.2591233299999811E-6 ) + muDoubleScalarCos ( (
ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * - 0.007778077999999999 ) +
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] )
* - 0.0028437600000000003 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4
] + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [
1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * 0.00026442415070999996 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 2 ] ) * 0.00026442415065999997 ) + muDoubleScalarCos ( ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v
[ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] )
* - 0.0028437600000000003 ) - muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
6.08795974E-5 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) - muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 5 ] * jtm353sqni [ 4 ] ) ) -
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 5 ] * jtm353sqni
[ 4 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) * 0.00026442415078499997 ) +
muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) - 2.0
* ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) * -
1.2499999950052465E-13 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ]
) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) * 0.00026442415070999996 ) +
muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 2 ] ) - 2.0
* ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2 ] - 2.0 *
ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0
* ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 3 ] ) * 9.2591235799999259E-6 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 3 ] ) * - 1.9999995583275254E-13 ) + jtm353sqni [ 0 ] * jtm353sqni [ 3 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 1 ] ) * 1.9999995583275254E-13 ) +
muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] )
* - 0.007778077999999999 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 2 ] +
2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 3 ] ) * 4.9999988958188135E-14 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 1 ] + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 3 ] ) * - 4.9999988958188135E-14 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
1 ] - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) *
1.2499999950052465E-13 ) + muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 1 ] + 2.0
* ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 3 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 3 ] - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 3 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( 2.0 *
ozbvfd5n0v [ 4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0
* ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) *
0.00026442415066 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) * - 0.00026442415066 ) +
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4 ] )
* 0.0028437600000000003 ) + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) * 0.0028437600000000003 ) + jtm353sqni
[ 0 ] * jtm353sqni [ 4 ] * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) * -
0.0029173632 ) + jtm353sqni [ 0 ] * jtm353sqni [ 2 ] * muDoubleScalarCos (
ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * - 0.007778077999999999 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * - 0.0028437600000000003 ) +
jtm353sqni [ 0 ] * jtm353sqni [ 3 ] * muDoubleScalarCos ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) * - 0.007778077999999999 ) + muDoubleScalarCos ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0
] * jtm353sqni [ 3 ] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0
] * jtm353sqni [ 3 ] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0
] * jtm353sqni [ 4 ] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0
] * jtm353sqni [ 4 ] ) * 0.0028437600000000003 ) + muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 4 ] ) * jtm353sqni [ 0 ] * jtm353sqni [ 1 ] * -
2.9815559743351372E-19 ) + jtm353sqni [ 0 ] * jtm353sqni [ 4 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * - 0.00052884830132 ) - 5.0E-15
* jtm353sqni [ 0 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v
[ 5 ] ) ) + jtm353sqni [ 0 ] * jtm353sqni [ 2 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 4 ] ) * 4.9999988958188135E-14 ) + jtm353sqni [ 0 ] * jtm353sqni
[ 3 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * 7.5000010542336515E-14
) + 2.5E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( - 2.0
* ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 4 ] ) ) + muDoubleScalarSin ( ( ( 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) * 0.00052884830131999993 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] +
ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) * - 0.00404460056 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) * -
0.0014586816 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ]
) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni
[ 2 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] -
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [
3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
1 ] * jtm353sqni [ 2 ] ) * - 0.00052884830131999993 ) + muDoubleScalarSin ( (
( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 3 ] ) * 0.0014586816 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 3 ] ) * -
0.0014586816 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
1 ] * jtm353sqni [ 3 ] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( 2.0
* ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 3 ] ) * 0.00052884830132 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 3 ] ) * - 0.00404460056 ) +
muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 4
] ) * 0.000528848301245 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
1 ] * jtm353sqni [ 4 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( jtm353sqni [ 1 ] * jtm353sqni [ 4 ] ) * 0.0014586816 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 4
] ) * 0.000528848301245 ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 4
] ) * 0.00201419267009 ) - muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 5.0E-15 *
jtm353sqni [ 1 ] * jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( ( ozbvfd5n0v
[ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
6.08795974E-5 * jtm353sqni [ 1 ] * jtm353sqni [ 5 ] ) ) + muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 1 ] * jtm353sqni [ 5 ] ) ) -
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 5.0E-15 * jtm353sqni [ 1 ] *
jtm353sqni [ 5 ] ) ) - 1.0E-14 * jtm353sqni [ 1 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] )
+ ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 *
jtm353sqni [ 2 ] * jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( ozbvfd5n0v
[ 1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) *
( jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) *
- 2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - 2.0 *
ozbvfd5n0v [ 4 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [
2 ] * jtm353sqni [ 3 ] ) * - 5.4210108624275222E-20 ) + muDoubleScalarSin ( (
( ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) + 2.0 *
ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] -
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) -
ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3
] ) * 5.4210108624275222E-20 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4
] + ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * (
jtm353sqni [ 2 ] * jtm353sqni [ 4 ] ) * 6.2500026855316637E-14 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - 2.0 * ozbvfd5n0v [ 4 ] ) -
ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4
] ) * 6.2500026855316637E-14 ) + muDoubleScalarSin ( ( - ozbvfd5n0v [ 2 ] -
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4
] ) * 1.2500005371063327E-13 ) + muDoubleScalarSin ( ( ( ( 2.0 * ozbvfd5n0v [
5 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) - 2.0 *
ozbvfd5n0v [ 4 ] ) * ( 2.5E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4 ] ) *
0.0020141926702150004 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
2 ] * jtm353sqni [ 4 ] ) * 0.00052884830130750006 ) + muDoubleScalarSin ( ( (
- 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) +
ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4 ] ) *
0.00052884830130750006 ) - muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) + ozbvfd5n0v [
4 ] ) * ( 5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3
] ) * 0.00052884830131999993 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [
4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) * - 0.00052884830131999993 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) * - 0.00404460056 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 *
jtm353sqni [ 2 ] * jtm353sqni [ 5 ] ) ) + 5.0E-15 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ]
) + ozbvfd5n0v [ 1 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 *
jtm353sqni [ 2 ] * jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( ozbvfd5n0v
[ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) * 0.0014586816 ) + muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) * - 0.0014586816 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4 ] ) *
0.0014586816 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ]
) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni
[ 4 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
3 ] * jtm353sqni [ 4 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] - 2.0 * ozbvfd5n0v [ 4 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v
[ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4 ] ) * 7.5000010542336515E-14 )
+ muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
1 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4 ] ) * 0.00201419266994 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4
] ) * 0.00052884830132 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [
3 ] * jtm353sqni [ 4 ] ) * 7.5000010542336515E-14 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4 ] ) * 0.0014586816 ) +
muDoubleScalarSin ( ( - ozbvfd5n0v [ 2 ] - ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
1 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4 ] ) * - 1.5000002108467303E-13 )
+ muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4
] ) * 0.00052884830132 ) - muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) + 2.0 *
ozbvfd5n0v [ 4 ] ) * ( 2.5E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) -
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 * jtm353sqni [ 3 ] *
jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 *
jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( ( ( 2.0 *
ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( 2.5E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5
] ) ) + 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( (
ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) ) +
muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) + ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 *
jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( 2.5E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) - muDoubleScalarSin (
( ( ( 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) +
ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 * jtm353sqni [ 3 ] *
jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.5E-15 *
jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) + muDoubleScalarSin ( ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( 6.08795974E-5 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) -
ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3
] ) * 2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] +
ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 3 ] * jtm353sqni [ 3 ] ) * - 1.3552527156068805E-20 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3 ] ) *
- 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
3 ] * jtm353sqni [ 3 ] ) * 0.00026442415065999997 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] - 2.0 * ozbvfd5n0v [ 4 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v
[ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3 ] ) * - 2.7105054312137611E-20
) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) -
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 3 ] *
jtm353sqni [ 3 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v
[ 4 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3 ] ) * 1.3552527156068805E-20 )
+ muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3
] ) * - 0.00026442415065999997 ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3
] ) * - 0.00202230028 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
3 ] * jtm353sqni [ 3 ] ) * 0.0007293408 ) + muDoubleScalarSin ( ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3 ] ) * - 0.0007293408 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 4 ] * jtm353sqni [ 4 ] ) * -
0.0007293408 ) + jtm353sqni [ 4 ] * jtm353sqni [ 4 ] * muDoubleScalarCos (
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 4 ] * jtm353sqni [ 4 ] ) *
0.0007293408 ) + jtm353sqni [ 4 ] * jtm353sqni [ 4 ] * muDoubleScalarCos ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
2 ] * jtm353sqni [ 2 ] ) * - 0.00026442415065999997 ) + muDoubleScalarSin ( (
( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) +
ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) *
0.00026442415065999997 ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2
] ) * - 0.00202230028 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] +
ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) * 1.3552527156068805E-20 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) *
0.0007293408 ) + muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3
] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 2 ] *
jtm353sqni [ 2 ] ) * - 0.0007293408 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [
1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) * - 1.3552527156068805E-20 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) *
- 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [
1 ] * jtm353sqni [ 1 ] ) * 2.7105054312137611E-20 ) + muDoubleScalarSin ( ( (
- 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) +
ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * -
0.00026442415065999997 ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1
] ) * - 0.00202230028 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - 2.0 *
ozbvfd5n0v [ 4 ] ) - ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [
1 ] * jtm353sqni [ 1 ] ) * 3.2526065174565133E-19 ) + jtm353sqni [ 1 ] *
jtm353sqni [ 1 ] * muDoubleScalarCos ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ]
) * 0.0028437600000000003 ) + jtm353sqni [ 1 ] * jtm353sqni [ 1 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
1 ] * jtm353sqni [ 1 ] ) * 0.00026442415065999964 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v
[ 4 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * - 1.3552527156068805E-20
) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) +
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 1 ] *
jtm353sqni [ 1 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v
[ 4 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * 1.3552527156068805E-20 )
+ muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] )
* 1.3552527156068805E-20 ) + jtm353sqni [ 1 ] * jtm353sqni [ 1 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 1 ] ) * 0.267177491 ) + muDoubleScalarSin (
( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * 0.0007293408 ) +
muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * -
0.0007293408 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ]
) - ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * - 3.3881317890172014E-20 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] - ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 3 ] ) - 2.0 * ozbvfd5n0v
[ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 3.3881317890172014E-20
) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] - 2.0 * ozbvfd5n0v [ 4 ] ) -
ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * 2.439454888092385E-19 ) + muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] -
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 3.3881317890172014E-20 ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) - ozbvfd5n0v [
3 ] ) - 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
3.3881317890172014E-20 ) + muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 2 ] +
2.0 * ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 4 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 5.4210108624275222E-20 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) -
ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * - 2.7105054312137611E-20 ) + jtm353sqni [ 0 ] * jtm353sqni [ 0 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 1 ] ) * 2.7755575615628914E-17 ) +
muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 1 ] - 2.0 * ozbvfd5n0v [ 4 ] ) +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * 9.4867690092481638E-20 ) + muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 1
] + 2.0 * ozbvfd5n0v [ 4 ] ) + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 1 ] + 3.0 * ozbvfd5n0v [ 2 ] ) +
3.0 * ozbvfd5n0v [ 3 ] ) - ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * 2.7105054312137611E-20 ) + muDoubleScalarCos ( ( ( 3.0 *
ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 4 ] ) + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 *
ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
5.4210108624275222E-20 ) + muDoubleScalarCos ( ( ( 3.0 * ozbvfd5n0v [ 1 ] -
ozbvfd5n0v [ 4 ] ) + 2.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 5.4210108624275222E-20 ) +
muDoubleScalarCos ( ( ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 4 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * 5.4210108624275222E-20 ) + muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 1
] + 3.0 * ozbvfd5n0v [ 2 ] ) + 3.0 * ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 4 ] )
* ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) + 3.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * - 3.3881317890172014E-21 ) + muDoubleScalarSin ( ( (
ozbvfd5n0v [ 1 ] + ozbvfd5n0v [ 2 ] ) + 3.0 * ozbvfd5n0v [ 3 ] ) + 2.0 *
ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
3.3881317890172014E-21 ) + muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 1 ] +
3.0 * ozbvfd5n0v [ 2 ] ) + 3.0 * ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ]
) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 1.0164395367051604E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 2 ] + ozbvfd5n0v [ 1 ] ) + 3.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * 3.3881317890172014E-21 ) + muDoubleScalarSin ( ( ( 3.0 *
ozbvfd5n0v [ 1 ] + 3.0 * ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 3 ] ) + 2.0 *
ozbvfd5n0v [ 4 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
6.7762635780344027E-21 ) + muDoubleScalarSin ( ( ( 3.0 * ozbvfd5n0v [ 2 ] +
ozbvfd5n0v [ 1 ] ) + ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 4 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 6.7762635780344027E-21 ) +
muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * 1.4907779871675686E-19 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4
] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 2.1684043449710089E-19 ) +
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] * muDoubleScalarCos ( - ozbvfd5n0v [ 4 ]
+ ozbvfd5n0v [ 1 ] ) * 2.1684043449710089E-19 ) + jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] * muDoubleScalarCos ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] )
* 2.1684043449710089E-19 ; localB -> eqanm5grr0 [ 1 ] = ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0 *
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * - 4.6295615399999775E-6 + muDoubleScalarCos ( ( ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v
[ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
- 0.0028437600000000003 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * 2.1684043449710089E-19 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * - 2.1684043449710089E-19 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * 0.007778078 ) + jtm353sqni [ 0 ] * jtm353sqni [ 0 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
8.6736173798840355E-19 ) + jtm353sqni [ 1 ] * jtm353sqni [ 1 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
1.7347234759768071E-18 ) + 2.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 1 ] *
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) ) - 2.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 2 ] * muDoubleScalarSin ( (
ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( 1.0E-13 * jtm353sqni [ 0 ] ) * jtm353sqni [ 3 ] ) + jtm353sqni [ 0 ]
* jtm353sqni [ 0 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 1 ] ) *
0.41364213499999991 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 4 ] * jtm353sqni [ 4 ] ) * -
0.0028437600000000003 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 4 ] * jtm353sqni [ 4 ] ) *
0.0028437600000000003 ) + jtm353sqni [ 2 ] * jtm353sqni [ 2 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * -
0.007778077999999999 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 2
] ) * - 0.0028437600000000003 ) + jtm353sqni [ 3 ] * jtm353sqni [ 3 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * -
0.007778077999999999 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 3
] ) * - 0.0028437600000000003 ) + jtm353sqni [ 0 ] * jtm353sqni [ 4 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) *
0.0056875200000000006 ) + jtm353sqni [ 0 ] * jtm353sqni [ 4 ] *
muDoubleScalarCos ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) * -
0.0056875200000000006 ) + jtm353sqni [ 1 ] * jtm353sqni [ 2 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * -
0.015556155999999998 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 2
] ) * - 0.0056875200000000006 ) + jtm353sqni [ 1 ] * jtm353sqni [ 3 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * -
0.015556155999999998 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 3 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 3
] ) * - 0.0056875200000000006 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 4
] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 4
] ) * 0.0056875200000000006 ) + jtm353sqni [ 2 ] * jtm353sqni [ 3 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) * -
0.015556155999999998 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 3
] ) * - 0.0056875200000000006 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4
] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 2 ] * jtm353sqni [ 4
] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4
] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 3 ] * jtm353sqni [ 4
] ) * 0.0056875200000000006 ) + muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2 ] +
2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
0.02257998678 ) - 0.0001217591948 * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) *
jtm353sqni [ 5 ] * jtm353sqni [ 4 ] ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3
] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni
[ 4 ] ) * - 0.00201419266984 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4
] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) * 0.00052884830132 ) +
muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4
] ) * 0.00052884830132 ) + muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [
4 ] ) * ( 5.0E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) -
muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) + ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 *
jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) - 1.0E-14 * jtm353sqni [ 1 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) +
jtm353sqni [ 1 ] * jtm353sqni [ 4 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) * 0.00105769660249 ) + jtm353sqni [ 2 ] * jtm353sqni [ 4 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * 0.0010576966027400002 ) +
5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( - 2.0 *
ozbvfd5n0v [ 5 ] + 2.0 * ozbvfd5n0v [ 4 ] ) ) + 5.0E-15 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 5 ] ) ) + 5.0E-15 *
jtm353sqni [ 2 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) ) + jtm353sqni [ 3 ] * jtm353sqni [ 4 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 4 ] ) * 0.00105769660279 ) - 5.0E-15 * jtm353sqni [ 3 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( - 2.0 * ozbvfd5n0v [ 5 ] + 2.0 *
ozbvfd5n0v [ 4 ] ) ) - 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 5 ] ) ) + 5.0E-15 * jtm353sqni [ 3 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.0E-13 * jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 2.0E-13 *
jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( 5.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) ) - muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni
[ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.00013221207533 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * - 0.00013221207533 ; localB -> eqanm5grr0 [ 2 ] = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
muDoubleScalarSin ( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0
* ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * -
4.629561539999991E-6 + muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 0.0014218800000000001 ) +
muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
- 0.0014218800000000001 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * 0.0014218800000000001 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0
] ) * - 0.0014218800000000001 ) + muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1
] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1
] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * 0.0038890390000000004 ) + jtm353sqni [ 0 ] * jtm353sqni
[ 0 ] * muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
0.0038890390000000004 ) + jtm353sqni [ 1 ] * jtm353sqni [ 1 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
0.0077780780000000008 ) - muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 3.0E-13 * jtm353sqni [ 0 ] ) * jtm353sqni [
3 ] ) + jtm353sqni [ 0 ] * jtm353sqni [ 0 ] * 0.02257998678 *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 2 ] + 2.0 * ozbvfd5n0v [ 1 ] ) ) -
0.0001217591948 * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) * jtm353sqni [ 5 ] *
jtm353sqni [ 4 ] ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2
] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) * -
0.0020141926698400005 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [
0 ] * jtm353sqni [ 4 ] ) * 0.00052884830132 ) + muDoubleScalarSin ( ( ( - 2.0
* ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) * 0.00052884830132000015 ) +
muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) - ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 *
jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) - muDoubleScalarSin ( ( ( ( - 2.0 *
ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) + ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) )
- 1.0E-14 * jtm353sqni [ 1 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 4 ] ) ) + jtm353sqni [ 1 ] * jtm353sqni [ 4 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * 0.00105769660249 ) +
jtm353sqni [ 2 ] * jtm353sqni [ 4 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) * 0.00105769660249 ) + 5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( - 2.0 * ozbvfd5n0v [ 5 ] + 2.0 * ozbvfd5n0v [ 4 ] ) ) +
5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 5 ] ) ) + 5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) + jtm353sqni [ 3 ] *
jtm353sqni [ 4 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) *
0.0010576966027400002 ) - 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( - 2.0 * ozbvfd5n0v [ 5 ] + 2.0 * ozbvfd5n0v [ 4 ] ) ) -
5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 5 ] ) ) + 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) - muDoubleScalarSin ( ( ( -
2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 5.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 1.0E-13 * jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 1.0E-13 *
jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( 2.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) ) - muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni
[ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.00013221207533 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * - 0.00013221207533 ; localB -> eqanm5grr0 [ 3 ] = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarSin
( ( 2.0 * ozbvfd5n0v [ 3 ] + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 4.629561539999991E-6 +
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] )
* 0.0014218800000000001 ) + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 0.0014218800000000001 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + 2.0 *
ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) *
0.0038890390000000004 ) + jtm353sqni [ 0 ] * jtm353sqni [ 0 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
0.0038890390000000004 ) + jtm353sqni [ 1 ] * jtm353sqni [ 1 ] *
muDoubleScalarCos ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) *
0.0077780780000000008 ) - muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v
[ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 3.0E-13 * jtm353sqni [ 0 ] ) * jtm353sqni [
3 ] ) - 0.0001217591948 * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) * jtm353sqni
[ 5 ] * jtm353sqni [ 4 ] ) + muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4
] ) * - 0.0020141926698400005 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [
4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 4 ] ) * 0.00052884830132 ) +
muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 4
] ) * 0.00052884830132000015 ) + muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v
[ 5 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) -
ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) -
muDoubleScalarSin ( ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) + ozbvfd5n0v [ 4 ] ) * ( 5.0E-15 *
jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) - 1.0E-14 * jtm353sqni [ 1 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) +
jtm353sqni [ 1 ] * jtm353sqni [ 4 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) * 0.00105769660249 ) + jtm353sqni [ 2 ] * jtm353sqni [ 4 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * 0.00105769660249 ) + 5.0E-15 *
jtm353sqni [ 2 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( - 2.0 * ozbvfd5n0v
[ 5 ] + 2.0 * ozbvfd5n0v [ 4 ] ) ) + 5.0E-15 * jtm353sqni [ 2 ] * jtm353sqni
[ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 5 ] ) ) + 5.0E-15 * jtm353sqni
[ 2 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) +
jtm353sqni [ 3 ] * jtm353sqni [ 4 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) * 0.0010576966027400002 ) - 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5
] * muDoubleScalarSin ( - 2.0 * ozbvfd5n0v [ 5 ] + 2.0 * ozbvfd5n0v [ 4 ] ) )
- 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] * muDoubleScalarSin ( 2.0 *
ozbvfd5n0v [ 5 ] ) ) + 5.0E-15 * jtm353sqni [ 3 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) ) - muDoubleScalarSin ( ( ( -
2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 5.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 1.0E-13 * jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 1.0E-13 *
jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 *
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ]
) * ( 2.0E-13 * jtm353sqni [ 0 ] * jtm353sqni [ 3 ] ) ) - muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni
[ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.00013221207533 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + 2.0 * ozbvfd5n0v [ 3 ] ) +
2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] *
jtm353sqni [ 0 ] ) * - 0.00013221207533 ; localB -> eqanm5grr0 [ 4 ] = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
muDoubleScalarCos ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v
[ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] )
* - 0.0014218800000000001 + muDoubleScalarCos ( ( ( ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2
] ) * ( jtm353sqni [ 1 ] * jtm353sqni [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * 0.00201419266994 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * 0.00201419266994 ) +
muDoubleScalarSin ( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1
] ) * jtm353sqni [ 0 ] * jtm353sqni [ 3 ] * 0.00201419266994 ) + jtm353sqni [
0 ] * jtm353sqni [ 0 ] * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) *
0.0014586816 ) + jtm353sqni [ 0 ] * jtm353sqni [ 1 ] * muDoubleScalarCos ( -
ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 1 ] ) * 0.0056875200000000006 ) + jtm353sqni
[ 0 ] * jtm353sqni [ 1 ] * muDoubleScalarCos ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 1 ] ) * - 0.0056875200000000006 ) + jtm353sqni [ 2 ] * jtm353sqni [ 2 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * - 0.00052884830132 ) +
jtm353sqni [ 3 ] * jtm353sqni [ 3 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4
] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) * - 0.00052884830131999993 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 1
] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni
[ 0 ] * jtm353sqni [ 2 ] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( (
2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) * - 0.00052884830132 ) +
muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni [ 0 ] * jtm353sqni [ 3
] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ]
+ ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( jtm353sqni
[ 0 ] * jtm353sqni [ 3 ] ) * - 0.00052884830131999993 ) + muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] ) ) +
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni
[ 5 ] ) ) + 1.0E-14 * jtm353sqni [ 0 ] * jtm353sqni [ 5 ] * muDoubleScalarSin
( ( ozbvfd5n0v [ 3 ] + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) ) -
muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 1.0E-14 * jtm353sqni [ 0 ] *
jtm353sqni [ 5 ] ) ) + jtm353sqni [ 1 ] * jtm353sqni [ 2 ] *
muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * - 0.00105769660264 ) +
jtm353sqni [ 1 ] * jtm353sqni [ 3 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [
4 ] ) * - 0.00105769660264 ) + 0.0001217591948 * jtm353sqni [ 1 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) ) + jtm353sqni [ 2
] * jtm353sqni [ 3 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * -
0.00105769660264 ) + 0.0001217591948 * jtm353sqni [ 2 ] * jtm353sqni [ 5 ] *
muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) ) + 1.0E-14 * jtm353sqni [ 2 ] *
jtm353sqni [ 5 ] * muDoubleScalarSin ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v
[ 4 ] ) ) + 0.0001217591948 * jtm353sqni [ 5 ] * jtm353sqni [ 3 ] *
muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) ) - 1.0E-14 * jtm353sqni [ 5 ] *
jtm353sqni [ 3 ] * muDoubleScalarSin ( - 2.0 * ozbvfd5n0v [ 5 ] + ozbvfd5n0v
[ 4 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * 0.00013221207533 ) + jtm353sqni [ 0 ]
* jtm353sqni [ 0 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) *
0.00026442415066 ) + muDoubleScalarSin ( ( ( 2.0 * ozbvfd5n0v [ 4 ] + 2.0 *
ozbvfd5n0v [ 3 ] ) + 2.0 * ozbvfd5n0v [ 2 ] ) + 2.0 * ozbvfd5n0v [ 1 ] ) * (
jtm353sqni [ 0 ] * jtm353sqni [ 0 ] ) * - 0.00013221207533 ) + jtm353sqni [ 1
] * jtm353sqni [ 1 ] * muDoubleScalarSin ( 2.0 * ozbvfd5n0v [ 4 ] ) * -
0.00052884830131999993 ; localB -> eqanm5grr0 [ 5 ] = ( ( ( ( ( ( ( ( (
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( - 6.08795974E-5 * jtm353sqni [ 0 ] *
jtm353sqni [ 1 ] ) + muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v
[ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 *
jtm353sqni [ 0 ] * jtm353sqni [ 1 ] ) ) - muDoubleScalarSin ( ( ( ozbvfd5n0v
[ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) ) + muDoubleScalarSin (
( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v
[ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni [ 2 ] ) ) -
muDoubleScalarSin ( ( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [
2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ] * jtm353sqni
[ 3 ] ) ) + muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) +
ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 0 ]
* jtm353sqni [ 3 ] ) ) - muDoubleScalarSin ( ( ( - ozbvfd5n0v [ 4 ] +
ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [ 1 ] ) * (
6.08795974E-5 * jtm353sqni [ 4 ] * jtm353sqni [ 0 ] ) ) - muDoubleScalarSin (
( ( ozbvfd5n0v [ 4 ] + ozbvfd5n0v [ 3 ] ) + ozbvfd5n0v [ 2 ] ) + ozbvfd5n0v [
1 ] ) * ( 6.08795974E-5 * jtm353sqni [ 4 ] * jtm353sqni [ 0 ] ) ) -
0.0001217591948 * jtm353sqni [ 4 ] * muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) *
jtm353sqni [ 3 ] ) - 0.0001217591948 * jtm353sqni [ 4 ] * muDoubleScalarSin (
ozbvfd5n0v [ 4 ] ) * jtm353sqni [ 1 ] ) - 0.0001217591948 * jtm353sqni [ 4 ]
* muDoubleScalarSin ( ozbvfd5n0v [ 4 ] ) * jtm353sqni [ 2 ] ; } void
mnevwrhe2n ( const real_T fjgd5watko [ 6 ] , const real_T p5w5wmvmzg [ 36 ] ,
const real_T gaz1hcynja [ 6 ] , const real_T e2phh1jph4 [ 6 ] , okdv3yvldy *
localB ) { int32_T i ; int32_T i_0 ; real_T tmp ; for ( i = 0 ; i < 6 ; i ++
) { tmp = 0.0 ; for ( i_0 = 0 ; i_0 < 6 ; i_0 ++ ) { tmp += p5w5wmvmzg [ 6 *
i_0 + i ] * fjgd5watko [ i_0 ] ; } localB -> p505mfvaxs [ i ] = ( tmp +
e2phh1jph4 [ i ] ) + gaz1hcynja [ i ] ; } } static void kug0xcztmu ( const
real_T x [ 9 ] , real_T y [ 9 ] ) { real_T b_x [ 9 ] ; int32_T p ; int32_T
p_0 ; int32_T p_1 ; real_T absx ; real_T absx_0 ; real_T absx_1 ; int32_T
itmp ; memcpy ( & b_x [ 0 ] , & x [ 0 ] , 9U * sizeof ( real_T ) ) ; p = 0 ;
p_0 = 3 ; p_1 = 6 ; absx = muDoubleScalarAbs ( x [ 0 ] ) ; absx_0 =
muDoubleScalarAbs ( x [ 1 ] ) ; absx_1 = muDoubleScalarAbs ( x [ 2 ] ) ; if (
( absx_0 > absx ) && ( absx_0 > absx_1 ) ) { p = 3 ; p_0 = 0 ; b_x [ 0 ] = x
[ 1 ] ; b_x [ 1 ] = x [ 0 ] ; b_x [ 3 ] = x [ 4 ] ; b_x [ 4 ] = x [ 3 ] ; b_x
[ 6 ] = x [ 7 ] ; b_x [ 7 ] = x [ 6 ] ; } else { if ( absx_1 > absx ) { p = 6
; p_1 = 0 ; b_x [ 0 ] = x [ 2 ] ; b_x [ 2 ] = x [ 0 ] ; b_x [ 3 ] = x [ 5 ] ;
b_x [ 5 ] = x [ 3 ] ; b_x [ 6 ] = x [ 8 ] ; b_x [ 8 ] = x [ 6 ] ; } } absx =
b_x [ 1 ] / b_x [ 0 ] ; b_x [ 1 ] /= b_x [ 0 ] ; absx_0 = b_x [ 2 ] / b_x [ 0
] ; b_x [ 2 ] /= b_x [ 0 ] ; b_x [ 4 ] -= absx * b_x [ 3 ] ; b_x [ 5 ] -=
absx_0 * b_x [ 3 ] ; b_x [ 7 ] -= absx * b_x [ 6 ] ; b_x [ 8 ] -= absx_0 *
b_x [ 6 ] ; if ( muDoubleScalarAbs ( b_x [ 5 ] ) > muDoubleScalarAbs ( b_x [
4 ] ) ) { itmp = p_0 ; p_0 = p_1 ; p_1 = itmp ; b_x [ 1 ] = absx_0 ; b_x [ 2
] = absx ; absx = b_x [ 4 ] ; b_x [ 4 ] = b_x [ 5 ] ; b_x [ 5 ] = absx ; absx
= b_x [ 7 ] ; b_x [ 7 ] = b_x [ 8 ] ; b_x [ 8 ] = absx ; } absx = b_x [ 5 ] /
b_x [ 4 ] ; b_x [ 5 ] /= b_x [ 4 ] ; b_x [ 8 ] -= absx * b_x [ 7 ] ; absx = (
b_x [ 5 ] * b_x [ 1 ] - b_x [ 2 ] ) / b_x [ 8 ] ; absx_0 = - ( b_x [ 7 ] *
absx + b_x [ 1 ] ) / b_x [ 4 ] ; y [ p ] = ( ( 1.0 - b_x [ 3 ] * absx_0 ) -
b_x [ 6 ] * absx ) / b_x [ 0 ] ; y [ p + 1 ] = absx_0 ; y [ p + 2 ] = absx ;
absx = - b_x [ 5 ] / b_x [ 8 ] ; absx_0 = ( 1.0 - b_x [ 7 ] * absx ) / b_x [
4 ] ; y [ p_0 ] = - ( b_x [ 3 ] * absx_0 + b_x [ 6 ] * absx ) / b_x [ 0 ] ; y
[ p_0 + 1 ] = absx_0 ; y [ p_0 + 2 ] = absx ; absx = 1.0 / b_x [ 8 ] ; absx_0
= - b_x [ 7 ] * absx / b_x [ 4 ] ; y [ p_1 ] = - ( b_x [ 3 ] * absx_0 + b_x [
6 ] * absx ) / b_x [ 0 ] ; y [ p_1 + 1 ] = absx_0 ; y [ p_1 + 2 ] = absx ; }
void MdlInitialize ( void ) { { int_T i1 ; real_T * xc = & rtX . oh2bsf3aw5 [
0 ] ; const real_T * p_Integrator3_IC = rtP . Integrator3_IC ; for ( i1 = 0 ;
i1 < 6 ; i1 ++ ) { xc [ i1 ] = p_Integrator3_IC [ i1 ] ; } } { int_T i1 ;
real_T * xc = & rtX . eym24ufl0b [ 0 ] ; const real_T * p_Integrator2_IC =
rtP . Integrator2_IC ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { xc [ i1 ] =
p_Integrator2_IC [ i1 ] ; } } rtDW . hifeqprlqm . TimeStampA = rtInf ; rtDW .
hifeqprlqm . TimeStampB = rtInf ; rtDW . bqyz2wxpe2 . TimeStampA = rtInf ;
rtDW . bqyz2wxpe2 . TimeStampB = rtInf ; } void MdlStart ( void ) { {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "qdd_target" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace2_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace2_Time0 ; rtDW
. njjuawiwjd . TimePtr = fromwksInfo -> time ; rtDW . njjuawiwjd . DataPtr =
fromwksInfo -> data ; rtDW . njjuawiwjd . RSimInfoPtr = fromwksInfo ; } rtDW
. htkw22hmrn . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "q_target" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace5_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace5_Time0 ; rtDW
. jpryus4wqu . TimePtr = fromwksInfo -> time ; rtDW . jpryus4wqu . DataPtr =
fromwksInfo -> data ; rtDW . jpryus4wqu . RSimInfoPtr = fromwksInfo ; } rtDW
. de2p54zry4 . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "qd_target" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace3_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace3_Time0 ; rtDW
. fanbrdsnik . TimePtr = fromwksInfo -> time ; rtDW . fanbrdsnik . DataPtr =
fromwksInfo -> data ; rtDW . fanbrdsnik . RSimInfoPtr = fromwksInfo ; } rtDW
. i4j2tjognw . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tool_vector" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace5_Data0_b3yhoghqxp ; fromwksInfo ->
nDataPoints = 1312 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace5_Time0_lq40dglfbc ; rtDW . oyg0xcbkq2 . TimePtr = fromwksInfo
-> time ; rtDW . oyg0xcbkq2 . DataPtr = fromwksInfo -> data ; rtDW .
oyg0xcbkq2 . RSimInfoPtr = fromwksInfo ; } rtDW . abooqdppeu . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "q_actual" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace1_Time0 ; rtDW
. meb1ohukzh . TimePtr = fromwksInfo -> time ; rtDW . meb1ohukzh . DataPtr =
fromwksInfo -> data ; rtDW . meb1ohukzh . RSimInfoPtr = fromwksInfo ; } rtDW
. bl25evyz1e . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tcp_speed" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace2_Data0_cs3a2ku0bw ; fromwksInfo ->
nDataPoints = 1312 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace2_Time0_pjbseop3la ; rtDW . kgedcln4ib . TimePtr = fromwksInfo
-> time ; rtDW . kgedcln4ib . DataPtr = fromwksInfo -> data ; rtDW .
kgedcln4ib . RSimInfoPtr = fromwksInfo ; } rtDW . ofgbpzna2m . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "qd_actual" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace3_Data0_kk2jdg25gp ; fromwksInfo ->
nDataPoints = 1312 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace3_Time0_at4l0orznp ; rtDW . di0rqa2hxr . TimePtr = fromwksInfo
-> time ; rtDW . di0rqa2hxr . DataPtr = fromwksInfo -> data ; rtDW .
di0rqa2hxr . RSimInfoPtr = fromwksInfo ; } rtDW . nuog3ppeov . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tool_acc" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace4_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace4_Time0 ; rtDW
. ftfrxtmkht . TimePtr = fromwksInfo -> time ; rtDW . ftfrxtmkht . DataPtr =
fromwksInfo -> data ; rtDW . ftfrxtmkht . RSimInfoPtr = fromwksInfo ; } rtDW
. mis12p4hji . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "m_target" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace6_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace6_Time0 ; rtDW
. gz4yk0vbeq . TimePtr = fromwksInfo -> time ; rtDW . gz4yk0vbeq . DataPtr =
fromwksInfo -> data ; rtDW . gz4yk0vbeq . RSimInfoPtr = fromwksInfo ; } rtDW
. pnfgom0ma5 . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "i_actual" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace7_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace7_Time0 ; rtDW
. afqqfcyfky . TimePtr = fromwksInfo -> time ; rtDW . afqqfcyfky . DataPtr =
fromwksInfo -> data ; rtDW . afqqfcyfky . RSimInfoPtr = fromwksInfo ; } rtDW
. jehbknbywz . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "i_target" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 6 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace8_Data0 ; fromwksInfo -> nDataPoints
= 1312 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace8_Time0 ; rtDW
. j3lsycmps3 . TimePtr = fromwksInfo -> time ; rtDW . j3lsycmps3 . DataPtr =
fromwksInfo -> data ; rtDW . j3lsycmps3 . RSimInfoPtr = fromwksInfo ; } rtDW
. mohuhbx5xb . PrevIndex = 0 ; } MdlInitialize ( ) ; } void MdlOutputs (
int_T tid ) { real_T bqz4pmo125 [ 36 ] ; real_T gjq5s2adi0 [ 6 ] ; real_T
np5zqfnlzb [ 6 ] ; real_T theta ; real_T scale ; real_T s ; real_T x ; real_T
phi ; int8_T I [ 9 ] ; int8_T p [ 6 ] ; real_T A [ 36 ] ; int8_T ipiv [ 6 ] ;
real_T y [ 36 ] ; real_T B_0 [ 6 ] ; int32_T j ; int32_T c ; int32_T ix ;
int32_T b_ix ; int32_T iy ; int32_T jA ; int32_T ijA ; int32_T c_c ; real_T t
; real_T kxystv1yji [ 12 ] ; real_T fh0cjr3tor ; real_T ns20wur0va ; real_T
kpxobg4d0b [ 16 ] ; int32_T i ; real_T tmp [ 9 ] ; real_T tmp_0 [ 9 ] ;
real_T tmp_1 [ 6 ] ; real_T tmp_2 [ 6 ] ; real_T tmp_3 [ 16 ] ; real_T I_0 [
36 ] ; real_T tmp_4 [ 6 ] ; real_T y_0 [ 6 ] ; real_T tmp_5 [ 9 ] ; real_T
tmp_6 [ 36 ] ; real_T tmp_7 [ 36 ] ; real_T ok14zp1th0_idx ; real_T
ok14zp1th0_idx_0 ; real_T gzcw1jgbdt_idx ; real_T gzcw1jgbdt_idx_0 ; real_T
gzcw1jgbdt_idx_1 ; real_T gzcw1jgbdt_idx_2 ; real_T gzcw1jgbdt_idx_3 ; real_T
gzcw1jgbdt_idx_4 ; real_T gzcw1jgbdt_idx_5 ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { scale = 2.2250738585072014E-308 ; s = muDoubleScalarAbs ( rtP .
Constant_Value [ 0 ] ) ; if ( s > 2.2250738585072014E-308 ) { theta = 1.0 ;
scale = s ; } else { t = s / 2.2250738585072014E-308 ; theta = t * t ; } s =
muDoubleScalarAbs ( rtP . Constant_Value [ 1 ] ) ; if ( s > scale ) { t =
scale / s ; theta = theta * t * t + 1.0 ; scale = s ; } else { t = s / scale
; theta += t * t ; } s = muDoubleScalarAbs ( rtP . Constant_Value [ 2 ] ) ;
if ( s > scale ) { t = scale / s ; theta = theta * t * t + 1.0 ; scale = s ;
} else { t = s / scale ; theta += t * t ; } theta = scale *
muDoubleScalarSqrt ( theta ) ; t = rtP . Constant_Value [ 0 ] / theta ;
ok14zp1th0_idx = rtP . Constant_Value [ 1 ] / theta ; ok14zp1th0_idx_0 = rtP
. Constant_Value [ 2 ] / theta ; x = muDoubleScalarCos ( theta ) ; s =
muDoubleScalarSin ( theta ) ; scale = muDoubleScalarCos ( theta ) ;
gzcw1jgbdt_idx = t * t * ( 1.0 - x ) + scale ; gzcw1jgbdt_idx_0 = t *
ok14zp1th0_idx * ( 1.0 - x ) - ok14zp1th0_idx_0 * s ; gzcw1jgbdt_idx_1 = t *
ok14zp1th0_idx_0 * ( 1.0 - x ) + ok14zp1th0_idx * s ; gzcw1jgbdt_idx_2 = t *
ok14zp1th0_idx * ( 1.0 - x ) + ok14zp1th0_idx_0 * s ; gzcw1jgbdt_idx_3 =
ok14zp1th0_idx * ok14zp1th0_idx * ( 1.0 - x ) + scale ; gzcw1jgbdt_idx_4 =
ok14zp1th0_idx * ok14zp1th0_idx_0 * ( 1.0 - x ) - t * s ; gzcw1jgbdt_idx_5 =
t * ok14zp1th0_idx_0 * ( 1.0 - x ) - ok14zp1th0_idx * s ; ok14zp1th0_idx =
ok14zp1th0_idx * ok14zp1th0_idx_0 * ( 1.0 - x ) + t * s ; t =
ok14zp1th0_idx_0 * ok14zp1th0_idx_0 * ( 1.0 - x ) + scale ; theta = 1.0 /
muDoubleScalarCos ( ( ( ( gzcw1jgbdt_idx + gzcw1jgbdt_idx_3 ) + t ) - 1.0 ) /
2.0 ) ; scale = 1.0 / ( 2.0 * muDoubleScalarSin ( theta ) ) ; rtB .
k0j4ewnvel [ 0 ] = ( ok14zp1th0_idx - gzcw1jgbdt_idx_4 ) * scale ; rtB .
k0j4ewnvel [ 1 ] = ( gzcw1jgbdt_idx_1 - gzcw1jgbdt_idx_5 ) * scale ; rtB .
k0j4ewnvel [ 2 ] = ( gzcw1jgbdt_idx_2 - gzcw1jgbdt_idx_0 ) * scale ; rtB .
kf4tsa5k52 = theta ; theta = muDoubleScalarAcos ( ( ( ( gzcw1jgbdt_idx +
gzcw1jgbdt_idx_3 ) + t ) - 1.0 ) / 2.0 ) ; scale = 1.0 / ( 2.0 *
muDoubleScalarSin ( theta ) ) ; rtB . mju1w13ukz [ 0 ] = ( ok14zp1th0_idx -
gzcw1jgbdt_idx_4 ) * scale ; rtB . mju1w13ukz [ 1 ] = ( gzcw1jgbdt_idx_1 -
gzcw1jgbdt_idx_5 ) * scale ; rtB . mju1w13ukz [ 2 ] = ( gzcw1jgbdt_idx_2 -
gzcw1jgbdt_idx_0 ) * scale ; rtB . l4pjsja05o = theta ; } { real_T *
pDataValues = ( real_T * ) rtDW . njjuawiwjd . DataPtr ; real_T * pTimeValues
= ( real_T * ) rtDW . njjuawiwjd . TimePtr ; int_T currTimeIndex = rtDW .
htkw22hmrn . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >=
pTimeValues [ 1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . blnxm0qljw [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ;
pDataValues += 1312 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . njjuawiwjd . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . htkw22hmrn . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T elIdx ; for (
elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . blnxm0qljw [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; } } } else { {
int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . blnxm0qljw
[ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ; pDataValues +=
numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 =
1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { d1 = pDataValues [
TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( & rtB . blnxm0qljw [ 0 ]
) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } } } } { real_T * pDataValues = ( real_T * ) rtDW .
jpryus4wqu . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . jpryus4wqu
. TimePtr ; int_T currTimeIndex = rtDW . de2p54zry4 . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 1311 ] ) { { int_T elIdx
; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . ji3bwqz25y [ 0 ] ) [
elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
jpryus4wqu . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . de2p54zry4 .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB .
ji3bwqz25y [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues +=
numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . ji3bwqz25y [ 0 ] ) [ elIdx ] = pDataValues [
currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 = (
t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ]
; ( & rtB . ji3bwqz25y [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2
, f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues =
( real_T * ) rtDW . fanbrdsnik . DataPtr ; real_T * pTimeValues = ( real_T *
) rtDW . fanbrdsnik . TimePtr ; int_T currTimeIndex = rtDW . i4j2tjognw .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [
1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB
. gfvbxq25vn [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ;
} } } else { int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo
* ) rtDW . fanbrdsnik . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints
; lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex =
0 ; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint
- 1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
i4j2tjognw . PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx
) { ( & rtB . gfvbxq25vn [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ;
pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 6 ; ++ elIdx ) { ( & rtB . gfvbxq25vn [ 0 ] ) [ elIdx ] = pDataValues
[ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 =
( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ;
int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6
; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ( & rtB . gfvbxq25vn [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate (
d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } } if (
ssIsMajorTimeStep ( rtS ) ) { { int_T i1 ; real_T * xc = & rtX . oh2bsf3aw5 [
0 ] ; const real_T * p_Integrator3_UpperSat = rtP . Integrator3_UpperSat ;
const real_T * p_Integrator3_LowerSat = rtP . Integrator3_LowerSat ; for ( i1
= 0 ; i1 < 6 ; i1 ++ ) { if ( xc [ i1 ] >= p_Integrator3_UpperSat [ i1 ] ) {
xc [ i1 ] = p_Integrator3_UpperSat [ i1 ] ; } else if ( xc [ i1 ] <=
p_Integrator3_LowerSat [ i1 ] ) { xc [ i1 ] = p_Integrator3_LowerSat [ i1 ] ;
} } } } { int_T i1 ; real_T * y0 = rtB . d1pmn0ij1l ; real_T * xc = & rtX .
oh2bsf3aw5 [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { y0 [ i1 ] = xc [ i1 ] ;
} } if ( ssIsMajorTimeStep ( rtS ) ) { { int_T i1 ; real_T * xc = & rtX .
eym24ufl0b [ 0 ] ; const real_T * p_Integrator2_UpperSat = rtP .
Integrator2_UpperSat ; const real_T * p_Integrator2_LowerSat = rtP .
Integrator2_LowerSat ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( xc [ i1 ] >=
p_Integrator2_UpperSat [ i1 ] ) { xc [ i1 ] = p_Integrator2_UpperSat [ i1 ] ;
} else if ( xc [ i1 ] <= p_Integrator2_LowerSat [ i1 ] ) { xc [ i1 ] =
p_Integrator2_LowerSat [ i1 ] ; } } } } { int_T i1 ; real_T * y0 = rtB .
mzfhfa0zkn ; real_T * xc = & rtX . eym24ufl0b [ 0 ] ; for ( i1 = 0 ; i1 < 6 ;
i1 ++ ) { y0 [ i1 ] = xc [ i1 ] ; } } for ( i = 0 ; i < 6 ; i ++ ) {
kxystv1yji [ i ] = rtB . ji3bwqz25y [ i ] - rtB . d1pmn0ij1l [ i ] ; } for (
i = 0 ; i < 6 ; i ++ ) { kxystv1yji [ i + 6 ] = rtB . gfvbxq25vn [ i ] - rtB
. mzfhfa0zkn [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { tmp_1 [ i ] = 0.0 ; for
( iy = 0 ; iy < 6 ; iy ++ ) { tmp_1 [ i ] += rtP . Gain_Gain [ 6 * iy + i ] *
kxystv1yji [ iy ] ; } tmp_2 [ i ] = 0.0 ; for ( iy = 0 ; iy < 6 ; iy ++ ) {
tmp_2 [ i ] += rtP . Gain1_Gain [ 6 * iy + i ] * kxystv1yji [ 6 + iy ] ; }
rtB . hmdtjrw30e [ i ] = ( tmp_1 [ i ] + tmp_2 [ i ] ) + rtB . blnxm0qljw [ i
] ; } tmp_3 [ 0 ] = ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) + ( - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) + ( -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) ; tmp_3 [ 4 ] = - ( ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) + muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) + ( - ( muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_3 [ 8 ] = - ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) +
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) ; tmp_3 [ 12 ] = ( ( ( ( ( ( ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * -
0.082 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) + 0.082 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * 0.093 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) )
- ( - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * 0.093 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) + 0.109 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 0 ] ) ) - 0.39243 * muDoubleScalarCos ( rtB . d1pmn0ij1l [
0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) ) + 0.39243 * muDoubleScalarCos ( rtB . d1pmn0ij1l [
0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) ) - 0.425 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0
] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) ; tmp_3 [ 1 ] = ( ( (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) + ( - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_3 [
5 ] = - ( ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) + ( - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) + ( -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) ; tmp_3 [ 9 ] = - ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l
[ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; tmp_3 [ 13 ] = ( ( ( ( ( ( ( (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * - 0.082 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
- 0.082 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) ) + ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * 0.093 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) )
- ( - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * 0.093 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) - 0.109 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 0 ] ) ) - 0.39243 * muDoubleScalarSin ( rtB . d1pmn0ij1l [
0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) ) + 0.39243 * muDoubleScalarSin ( rtB . d1pmn0ij1l [
0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) ) - 0.425 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0
] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) ; tmp_3 [ 2 ] = ( (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) + ( - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) ; tmp_3 [ 6 ] = - ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l
[ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) + ( - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_3 [ 10 ] = - ( (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) ; tmp_3 [ 14 ] = ( ( ( ( ( 0.0892 - ( ( muDoubleScalarSin
( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * 0.082 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) )
+ ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * 0.093 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) - ( - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] )
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * 0.093 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) - 0.39243 * muDoubleScalarSin
( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) -
0.39243 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) ) - 0.425 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1
] ) ; tmp_3 [ 3 ] = 0.0 ; tmp_3 [ 7 ] = 0.0 ; tmp_3 [ 11 ] = 0.0 ; tmp_3 [ 15
] = 1.0 ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . lriz3d1h1w [ 3 * i ] = tmp_3 [
i << 2 ] ; rtB . lriz3d1h1w [ 1 + 3 * i ] = tmp_3 [ ( i << 2 ) + 1 ] ; rtB .
lriz3d1h1w [ 2 + 3 * i ] = tmp_3 [ ( i << 2 ) + 2 ] ; } if ( ( rtB .
lriz3d1h1w [ 6 ] != 0.0 ) || ( rtB . lriz3d1h1w [ 7 ] != 0.0 ) ) { fh0cjr3tor
= muDoubleScalarAtan2 ( muDoubleScalarSqrt ( rtB . lriz3d1h1w [ 6 ] * rtB .
lriz3d1h1w [ 6 ] + rtB . lriz3d1h1w [ 7 ] * rtB . lriz3d1h1w [ 7 ] ) , rtB .
lriz3d1h1w [ 8 ] ) ; phi = muDoubleScalarAtan2 ( rtB . lriz3d1h1w [ 7 ] , rtB
. lriz3d1h1w [ 6 ] ) ; ns20wur0va = muDoubleScalarAtan2 ( rtB . lriz3d1h1w [
5 ] , - rtB . lriz3d1h1w [ 2 ] ) ; } else { if ( ( rtB . lriz3d1h1w [ 6 ] ==
0.0 ) && ( rtB . lriz3d1h1w [ 7 ] == 0.0 ) ) { if ( rtB . lriz3d1h1w [ 8 ] ==
1.0 ) { fh0cjr3tor = 0.0 ; phi = 0.0 ; ns20wur0va = muDoubleScalarAtan2 ( rtB
. lriz3d1h1w [ 0 ] , rtB . lriz3d1h1w [ 1 ] ) ; } else { if ( rtB .
lriz3d1h1w [ 8 ] == - 1.0 ) { fh0cjr3tor = 3.1415926535897931 ; phi = 0.0 ;
ns20wur0va = - muDoubleScalarAtan2 ( - rtB . lriz3d1h1w [ 0 ] , - rtB .
lriz3d1h1w [ 3 ] ) ; } } } } for ( i = 0 ; i < 9 ; i ++ ) { I [ i ] = 0 ; } I
[ 0 ] = 1 ; I [ 4 ] = 1 ; I [ 8 ] = 1 ; tmp [ 0 ] = muDoubleScalarCos (
ns20wur0va ) * muDoubleScalarSin ( fh0cjr3tor ) ; tmp [ 3 ] = -
muDoubleScalarSin ( ns20wur0va ) ; tmp [ 6 ] = 0.0 ; tmp [ 1 ] =
muDoubleScalarSin ( ns20wur0va ) * muDoubleScalarSin ( fh0cjr3tor ) ; tmp [ 4
] = muDoubleScalarCos ( ns20wur0va ) ; tmp [ 7 ] = 0.0 ; tmp [ 2 ] =
muDoubleScalarCos ( fh0cjr3tor ) ; tmp [ 5 ] = 0.0 ; tmp [ 8 ] = 1.0 ;
kug0xcztmu ( tmp , tmp_0 ) ; for ( i = 0 ; i < 3 ; i ++ ) { I_0 [ 6 * i ] = I
[ 3 * i ] ; I_0 [ 1 + 6 * i ] = I [ 3 * i + 1 ] ; I_0 [ 2 + 6 * i ] = I [ 3 *
i + 2 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { I_0 [ 6 * ( i + 3 ) ] = 0.0 ; I_0
[ 1 + 6 * ( i + 3 ) ] = 0.0 ; I_0 [ 2 + 6 * ( i + 3 ) ] = 0.0 ; } for ( i = 0
; i < 3 ; i ++ ) { I_0 [ 3 + 6 * i ] = 0.0 ; I_0 [ 4 + 6 * i ] = 0.0 ; I_0 [
5 + 6 * i ] = 0.0 ; } for ( i = 0 ; i < 3 ; i ++ ) { I_0 [ 3 + 6 * ( i + 3 )
] = tmp_0 [ 3 * i ] ; I_0 [ 4 + 6 * ( i + 3 ) ] = tmp_0 [ 3 * i + 1 ] ; I_0 [
5 + 6 * ( i + 3 ) ] = tmp_0 [ 3 * i + 2 ] ; } y [ 0 ] = ( ( ( ( ( ( 41.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) / 500.0 + 109.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0
] ) / 1000.0 ) + 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 40.0 ) - ( muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - ( ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) - 39243.0 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 100000.0 ; y [ 6 ] = ( ( ( ( 17.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
40.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; y [ 12 ] = ( ( ( (
( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; y [ 18 ] = ( ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; y [ 24 ] = ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - 41.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 500.0 ; y
[ 30 ] = 0.0 ; y [ 1 ] = ( ( ( ( ( ( 109.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 1000.0 - 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0
] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 ) + 41.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] )
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) - 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
; y [ 7 ] = ( ( ( ( 17.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 - ( muDoubleScalarSin (
rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 100000.0 ; y [ 13 ] = ( ( ( ( ( muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 100000.0 ; y [ 19 ] = ( ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; y [ 25 ] = ( (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 + 41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 500.0 ; y [ 31 ] = 0.0 ; y [ 2
] = 0.0 ; y [ 8 ] = ( ( ( ( 39243.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [
1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 - 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) - 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l
[ 1 ] ) / 40.0 ) - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; y [ 14 ] = ( ( ( 39243.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l
[ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 - 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [
1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; y [ 20 ] = ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 - ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l
[ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; y [ 26 ] = -
( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB
. d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) ) ) / 500.0 ; y [ 32 ] = 0.0 ; y [ 3 ] = 0.0 ; y [ 9
] = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; y [ 15 ] =
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; y [ 21 ] = muDoubleScalarSin (
rtB . d1pmn0ij1l [ 0 ] ) ; y [ 27 ] = ( muDoubleScalarCos ( rtB . d1pmn0ij1l
[ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ; y [ 33 ] = ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ; y [ 4 ] = 0.0 ; y [ 10 ] = - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) ; y [ 16 ] = - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ]
) ; y [ 22 ] = - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ; y [ 28 ] = (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ; y [ 34 ] = ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0
] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB
. d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; y [ 5 ] = 1.0 ; y [ 11 ] = 0.0
; y [ 17 ] = 0.0 ; y [ 23 ] = 0.0 ; y [ 29 ] = ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) ; y [ 35 ] = ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1
] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ; for ( i = 0 ; i < 6 ; i ++ ) {
for ( iy = 0 ; iy < 6 ; iy ++ ) { rtB . lysn5dtfor [ i + 6 * iy ] = 0.0 ; for
( ix = 0 ; ix < 6 ; ix ++ ) { rtB . lysn5dtfor [ i + 6 * iy ] += I_0 [ 6 * ix
+ i ] * y [ 6 * iy + ix ] ; } } } { real_T t = ssGetTaskTime ( rtS , 0 ) ;
real_T timeStampA = rtDW . hifeqprlqm . TimeStampA ; real_T timeStampB = rtDW
. hifeqprlqm . TimeStampB ; real_T * lastU = & rtDW . hifeqprlqm .
LastUAtTimeA [ 0 ] ; if ( timeStampA >= t && timeStampB >= t ) { { int_T i1 ;
real_T * y0 = bqz4pmo125 ; for ( i1 = 0 ; i1 < 36 ; i1 ++ ) { y0 [ i1 ] = 0.0
; } } } else { real_T deltaT ; real_T lastTime = timeStampA ; if ( timeStampA
< timeStampB ) { if ( timeStampB < t ) { lastTime = timeStampB ; lastU = &
rtDW . hifeqprlqm . LastUAtTimeB [ 0 ] ; } } else if ( timeStampA >= t ) {
lastTime = timeStampB ; lastU = & rtDW . hifeqprlqm . LastUAtTimeB [ 0 ] ; }
deltaT = t - lastTime ; { int_T i1 ; const real_T * u0 = rtB . lysn5dtfor ;
real_T * y0 = bqz4pmo125 ; for ( i1 = 0 ; i1 < 36 ; i1 ++ ) { y0 [ i1 ] = (
u0 [ i1 ] - * lastU ++ ) / deltaT ; } } } } { real_T t = ssGetTaskTime ( rtS
, 0 ) ; real_T timeStampA = rtDW . bqyz2wxpe2 . TimeStampA ; real_T
timeStampB = rtDW . bqyz2wxpe2 . TimeStampB ; real_T * lastU = & rtDW .
bqyz2wxpe2 . LastUAtTimeA [ 0 ] ; if ( timeStampA >= t && timeStampB >= t ) {
{ int_T i1 ; real_T * y0 = gjq5s2adi0 ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { y0
[ i1 ] = 0.0 ; } } } else { real_T deltaT ; real_T lastTime = timeStampA ; if
( timeStampA < timeStampB ) { if ( timeStampB < t ) { lastTime = timeStampB ;
lastU = & rtDW . bqyz2wxpe2 . LastUAtTimeB [ 0 ] ; } } else if ( timeStampA
>= t ) { lastTime = timeStampB ; lastU = & rtDW . bqyz2wxpe2 . LastUAtTimeB [
0 ] ; } deltaT = t - lastTime ; { int_T i1 ; const real_T * u0 = rtB .
mzfhfa0zkn ; real_T * y0 = gjq5s2adi0 ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { y0
[ i1 ] = ( u0 [ i1 ] - * lastU ++ ) / deltaT ; } } } } for ( i = 0 ; i < 36 ;
i ++ ) { I_0 [ i ] = 0.0 ; A [ i ] = rtB . lysn5dtfor [ i ] ; } for ( i = 0 ;
i < 6 ; i ++ ) { ipiv [ i ] = ( int8_T ) ( 1 + i ) ; } for ( i = 0 ; i < 5 ;
i ++ ) { c = i * 7 ; c_c = 0 ; ix = c ; scale = muDoubleScalarAbs ( A [ c ] )
; for ( jA = 2 ; jA <= 6 - i ; jA ++ ) { ix ++ ; s = muDoubleScalarAbs ( A [
ix ] ) ; if ( s > scale ) { c_c = jA - 1 ; scale = s ; } } if ( A [ c + c_c ]
!= 0.0 ) { if ( c_c != 0 ) { ipiv [ i ] = ( int8_T ) ( ( i + c_c ) + 1 ) ;
b_ix = i ; iy = i + c_c ; for ( ix = 0 ; ix < 6 ; ix ++ ) { scale = A [ b_ix
] ; A [ b_ix ] = A [ iy ] ; A [ iy ] = scale ; b_ix += 6 ; iy += 6 ; } } ix =
( c - i ) + 6 ; for ( iy = c + 1 ; iy + 1 <= ix ; iy ++ ) { A [ iy ] /= A [ c
] ; } } jA = c ; ix = c + 6 ; for ( c_c = 1 ; c_c <= 5 - i ; c_c ++ ) { scale
= A [ ix ] ; if ( A [ ix ] != 0.0 ) { iy = c + 1 ; b_ix = ( jA - i ) + 12 ;
for ( ijA = 7 + jA ; ijA + 1 <= b_ix ; ijA ++ ) { A [ ijA ] += A [ iy ] * -
scale ; iy ++ ; } } ix += 6 ; jA += 6 ; } } for ( i = 0 ; i < 6 ; i ++ ) { p
[ i ] = ( int8_T ) ( 1 + i ) ; } for ( iy = 0 ; iy < 5 ; iy ++ ) { if ( ipiv
[ iy ] > 1 + iy ) { ix = p [ ipiv [ iy ] - 1 ] ; p [ ipiv [ iy ] - 1 ] = p [
iy ] ; p [ iy ] = ( int8_T ) ix ; } } for ( iy = 0 ; iy < 6 ; iy ++ ) { I_0 [
iy + 6 * ( p [ iy ] - 1 ) ] = 1.0 ; for ( j = iy ; j + 1 < 7 ; j ++ ) { if (
I_0 [ ( p [ iy ] - 1 ) * 6 + j ] != 0.0 ) { for ( ix = j + 1 ; ix + 1 < 7 ;
ix ++ ) { I_0 [ ix + 6 * ( p [ iy ] - 1 ) ] -= I_0 [ ( p [ iy ] - 1 ) * 6 + j
] * A [ 6 * j + ix ] ; } } } } for ( ix = 0 ; ix < 6 ; ix ++ ) { c_c = 6 * ix
; for ( iy = 5 ; iy >= 0 ; iy += - 1 ) { jA = 6 * iy ; if ( I_0 [ iy + c_c ]
!= 0.0 ) { I_0 [ iy + c_c ] /= A [ iy + jA ] ; for ( b_ix = 0 ; b_ix + 1 <=
iy ; b_ix ++ ) { I_0 [ b_ix + c_c ] -= I_0 [ iy + c_c ] * A [ b_ix + jA ] ; }
} } } for ( i = 0 ; i < 36 ; i ++ ) { y [ i ] = 0.0 ; A [ i ] = rtB .
lysn5dtfor [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { ipiv [ i ] = ( int8_T ) (
1 + i ) ; } for ( i = 0 ; i < 5 ; i ++ ) { c = i * 7 ; c_c = 0 ; ix = c ;
scale = muDoubleScalarAbs ( A [ c ] ) ; for ( jA = 2 ; jA <= 6 - i ; jA ++ )
{ ix ++ ; s = muDoubleScalarAbs ( A [ ix ] ) ; if ( s > scale ) { c_c = jA -
1 ; scale = s ; } } if ( A [ c + c_c ] != 0.0 ) { if ( c_c != 0 ) { ipiv [ i
] = ( int8_T ) ( ( i + c_c ) + 1 ) ; b_ix = i ; iy = i + c_c ; for ( ix = 0 ;
ix < 6 ; ix ++ ) { scale = A [ b_ix ] ; A [ b_ix ] = A [ iy ] ; A [ iy ] =
scale ; b_ix += 6 ; iy += 6 ; } } ix = ( c - i ) + 6 ; for ( iy = c + 1 ; iy
+ 1 <= ix ; iy ++ ) { A [ iy ] /= A [ c ] ; } } jA = c ; ix = c + 6 ; for (
c_c = 1 ; c_c <= 5 - i ; c_c ++ ) { scale = A [ ix ] ; if ( A [ ix ] != 0.0 )
{ iy = c + 1 ; b_ix = ( jA - i ) + 12 ; for ( ijA = 7 + jA ; ijA + 1 <= b_ix
; ijA ++ ) { A [ ijA ] += A [ iy ] * - scale ; iy ++ ; } } ix += 6 ; jA += 6
; } } for ( i = 0 ; i < 6 ; i ++ ) { p [ i ] = ( int8_T ) ( 1 + i ) ; } for (
iy = 0 ; iy < 5 ; iy ++ ) { if ( ipiv [ iy ] > 1 + iy ) { ix = p [ ipiv [ iy
] - 1 ] ; p [ ipiv [ iy ] - 1 ] = p [ iy ] ; p [ iy ] = ( int8_T ) ix ; } }
for ( iy = 0 ; iy < 6 ; iy ++ ) { y [ iy + 6 * ( p [ iy ] - 1 ) ] = 1.0 ; for
( j = iy ; j + 1 < 7 ; j ++ ) { if ( y [ ( p [ iy ] - 1 ) * 6 + j ] != 0.0 )
{ for ( ix = j + 1 ; ix + 1 < 7 ; ix ++ ) { y [ ix + 6 * ( p [ iy ] - 1 ) ]
-= y [ ( p [ iy ] - 1 ) * 6 + j ] * A [ 6 * j + ix ] ; } } } } for ( ix = 0 ;
ix < 6 ; ix ++ ) { c_c = 6 * ix ; for ( iy = 5 ; iy >= 0 ; iy += - 1 ) { jA =
6 * iy ; if ( y [ iy + c_c ] != 0.0 ) { y [ iy + c_c ] /= A [ iy + jA ] ; for
( b_ix = 0 ; b_ix + 1 <= iy ; b_ix ++ ) { y [ b_ix + c_c ] -= y [ iy + c_c ]
* A [ b_ix + jA ] ; } } } } for ( i = 0 ; i < 6 ; i ++ ) { tmp_1 [ i ] = 0.0
; for ( iy = 0 ; iy < 6 ; iy ++ ) { tmp_1 [ i ] += rtB . lysn5dtfor [ 6 * iy
+ i ] * gjq5s2adi0 [ iy ] ; } tmp_2 [ i ] = 0.0 ; for ( iy = 0 ; iy < 6 ; iy
++ ) { tmp_2 [ i ] += bqz4pmo125 [ 6 * iy + i ] * rtB . mzfhfa0zkn [ iy ] ; }
tmp_4 [ i ] = 0.0 ; for ( iy = 0 ; iy < 6 ; iy ++ ) { tmp_4 [ i ] += rtB .
lysn5dtfor [ 6 * iy + i ] * rtB . mzfhfa0zkn [ iy ] ; } } for ( i = 0 ; i < 6
; i ++ ) { y_0 [ i ] = 0.0 ; for ( iy = 0 ; iy < 6 ; iy ++ ) { y_0 [ i ] +=
I_0 [ 6 * iy + i ] * tmp_4 [ iy ] ; } } for ( i = 0 ; i < 6 ; i ++ ) { t =
0.0 ; for ( iy = 0 ; iy < 6 ; iy ++ ) { t += bqz4pmo125 [ 6 * iy + i ] * y_0
[ iy ] ; } tmp_4 [ i ] = ( tmp_1 [ i ] + tmp_2 [ i ] ) - t ; } for ( i = 0 ;
i < 6 ; i ++ ) { np5zqfnlzb [ i ] = 0.0 ; for ( iy = 0 ; iy < 6 ; iy ++ ) {
np5zqfnlzb [ i ] += y [ 6 * iy + i ] * tmp_4 [ iy ] ; } } nfvr5phzhh ( rtB .
mzfhfa0zkn , rtB . d1pmn0ij1l , & rtB . mvghmhsjz4 ) ; mnevwrhe2n (
np5zqfnlzb , rtB . mvghmhsjz4 . c3phy4uy3g , rtB . mvghmhsjz4 . dvbqjjkdy0 ,
rtB . mvghmhsjz4 . eqanm5grr0 , & rtB . lddm5yrsqq ) ; nfvr5phzhh ( rtB .
d1pmn0ij1l , rtB . mzfhfa0zkn , & rtB . okpo04efs2 ) ; mnevwrhe2n ( rtB .
hmdtjrw30e , rtB . okpo04efs2 . c3phy4uy3g , rtB . okpo04efs2 . dvbqjjkdy0 ,
rtB . okpo04efs2 . eqanm5grr0 , & rtB . nghlo5plg0 ) ; rtB . oshetbdj3o [ 0 ]
= ( ( ( ( ( ( 41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) / 500.0 + 109.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) / 1000.0 ) + 17.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 40.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] )
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) - 39243.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 100000.0
; rtB . oshetbdj3o [ 6 ] = ( ( ( ( 17.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; rtB . oshetbdj3o [
12 ] = ( ( ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [
0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; rtB . oshetbdj3o [
18 ] = ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos
( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; rtB . oshetbdj3o [ 24 ] = ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - 41.0 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) / 500.0 ; rtB . oshetbdj3o [ 30 ] = 0.0 ; rtB . oshetbdj3o
[ 1 ] = ( ( ( ( ( ( 109.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
1000.0 - 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 ) + 41.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] )
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) - 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
; rtB . oshetbdj3o [ 7 ] = ( ( ( ( 17.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; rtB . oshetbdj3o [
13 ] = ( ( ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [
1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; rtB . oshetbdj3o [
19 ] = ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin
( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; rtB . oshetbdj3o [ 25 ] = ( ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 + 41.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) / 500.0 ; rtB . oshetbdj3o [ 31 ] = 0.0 ; rtB . oshetbdj3o
[ 2 ] = 0.0 ; rtB . oshetbdj3o [ 8 ] = ( ( ( ( 39243.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) /
100000.0 - 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) - 17.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 ) - ( ( muDoubleScalarCos
( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; rtB . oshetbdj3o [ 14 ] = ( ( ( 39243.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 - 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l
[ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * (
93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; rtB . oshetbdj3o [ 20 ] = ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 - ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; rtB . oshetbdj3o
[ 26 ] = - ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) ) / 500.0 ; rtB .
oshetbdj3o [ 32 ] = 0.0 ; rtB . oshetbdj3o [ 3 ] = 0.0 ; rtB . oshetbdj3o [ 9
] = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; rtB . oshetbdj3o [ 15 ] =
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; rtB . oshetbdj3o [ 21 ] =
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; rtB . oshetbdj3o [ 27 ] = (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ; rtB . oshetbdj3o [ 33 ] = ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; rtB .
oshetbdj3o [ 4 ] = 0.0 ; rtB . oshetbdj3o [ 10 ] = - muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 0 ] ) ; rtB . oshetbdj3o [ 16 ] = - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) ; rtB . oshetbdj3o [ 22 ] = - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) ; rtB . oshetbdj3o [ 28 ] = ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ; rtB .
oshetbdj3o [ 34 ] = ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; rtB . oshetbdj3o [ 5 ] = 1.0 ;
rtB . oshetbdj3o [ 11 ] = 0.0 ; rtB . oshetbdj3o [ 17 ] = 0.0 ; rtB .
oshetbdj3o [ 23 ] = 0.0 ; rtB . oshetbdj3o [ 29 ] = ( muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) ; rtB . oshetbdj3o [ 35 ] = ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ; for (
i = 0 ; i < 3 ; i ++ ) { for ( iy = 0 ; iy < 6 ; iy ++ ) { rtB . kbgoclq5ff [
iy + 6 * i ] = rtB . oshetbdj3o [ 6 * i + iy ] ; } } for ( i = 0 ; i < 3 ; i
++ ) { for ( iy = 0 ; iy < 6 ; iy ++ ) { rtB . iq3tvc1jiy [ iy + 6 * i ] =
rtB . oshetbdj3o [ ( 3 + i ) * 6 + iy ] ; } } tmp_5 [ 0 ] = muDoubleScalarCos
( phi ) * muDoubleScalarCos ( fh0cjr3tor ) * muDoubleScalarCos ( ns20wur0va )
- muDoubleScalarSin ( phi ) * muDoubleScalarSin ( ns20wur0va ) ; tmp_5 [ 3 ]
= - muDoubleScalarCos ( phi ) * muDoubleScalarCos ( fh0cjr3tor ) *
muDoubleScalarSin ( ns20wur0va ) - muDoubleScalarSin ( phi ) *
muDoubleScalarCos ( ns20wur0va ) ; tmp_5 [ 6 ] = muDoubleScalarCos ( phi ) *
muDoubleScalarSin ( fh0cjr3tor ) ; tmp_5 [ 1 ] = muDoubleScalarSin ( phi ) *
muDoubleScalarCos ( fh0cjr3tor ) * muDoubleScalarCos ( ns20wur0va ) +
muDoubleScalarCos ( phi ) * muDoubleScalarSin ( ns20wur0va ) ; tmp_5 [ 4 ] =
- muDoubleScalarSin ( phi ) * muDoubleScalarCos ( fh0cjr3tor ) *
muDoubleScalarSin ( ns20wur0va ) + muDoubleScalarCos ( phi ) *
muDoubleScalarCos ( ns20wur0va ) ; tmp_5 [ 7 ] = muDoubleScalarSin ( phi ) *
muDoubleScalarSin ( fh0cjr3tor ) ; tmp_5 [ 2 ] = - muDoubleScalarSin (
fh0cjr3tor ) * muDoubleScalarCos ( ns20wur0va ) ; tmp_5 [ 5 ] =
muDoubleScalarSin ( fh0cjr3tor ) * muDoubleScalarSin ( ns20wur0va ) ; tmp_5 [
8 ] = muDoubleScalarCos ( fh0cjr3tor ) ; for ( i = 0 ; i < 3 ; i ++ ) { rtB .
ctrvb4cmxr [ 3 * i ] = rtB . lriz3d1h1w [ 3 * i ] - tmp_5 [ 3 * i ] ; rtB .
ctrvb4cmxr [ 1 + 3 * i ] = rtB . lriz3d1h1w [ 3 * i + 1 ] - tmp_5 [ 3 * i + 1
] ; rtB . ctrvb4cmxr [ 2 + 3 * i ] = rtB . lriz3d1h1w [ 3 * i + 2 ] - tmp_5 [
3 * i + 2 ] ; } x = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] / 2.0 ) ;
scale = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] / 2.0 ) ; t =
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] / 2.0 ) ; s = muDoubleScalarSin (
rtB . d1pmn0ij1l [ 5 ] / 2.0 ) ; theta = muDoubleScalarSin ( rtB . d1pmn0ij1l
[ 4 ] / 2.0 ) ; fh0cjr3tor = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] / 2.0
) ; phi = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] / 2.0 ) ; ns20wur0va =
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] / 2.0 + rtB . d1pmn0ij1l [ 2 ] /
2.0 ) + rtB . d1pmn0ij1l [ 3 ] / 2.0 ) ; ok14zp1th0_idx = muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] / 2.0 ) ; kpxobg4d0b [ 0 ] = ( ( ( ( ( (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) - ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 8.1129638414606682E+31 ) + (
( 4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 ) * ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 ) - ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) + ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) + ( ( ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) + ( ( ( muDoubleScalarSin ( rtB
. d1pmn0ij1l [ 0 ] ) - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) ) / 8.1129638414606682E+31 ) + ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 8.1129638414606682E+31 ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) - ( ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) ; kpxobg4d0b [ 4 ] = ( ( ( ( ( ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) ) / 8.1129638414606682E+31 ) + ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 8.1129638414606682E+31 ) * (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) /
8.1129638414606682E+31 - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 ) - ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) ) + ( ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) + ( ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) -
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) - ( ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) - ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 ) + ( ( 4.967757600021511E+15 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) / 8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) - ( ( ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) - 4.967757600021511E+15 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ;
kpxobg4d0b [ 8 ] = ( ( ( ( ( ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] -
rtB . d1pmn0ij1l [ 4 ] ) / 2.0 - muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [
0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l
[ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * 6.5820182292848256E+63 /
2.6328072917139297E+64 ) - muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 0 ] -
rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 4 ] ) * 6.5820182292848234E+63 /
2.6328072917139297E+64 ) + muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 0 ] +
rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ]
) - rtB . d1pmn0ij1l [ 4 ] ) * 6.5820182292848242E+63 /
2.6328072917139297E+64 ) + muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 0 ] -
rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ]
) - rtB . d1pmn0ij1l [ 4 ] ) * 6.5820182292848242E+63 /
2.6328072917139297E+64 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 0 ] +
rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ]
) * 4.0303237782115947E+47 / 1.3164036458569648E+64 ) + muDoubleScalarSin (
rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 4 ] ) / 2.0 ) - muDoubleScalarSin
( ( ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [
2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) * 4.0303237782115947E+47 /
1.3164036458569648E+64 ) + 2.4678615572571482E+31 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 6.5820182292848242E+63 ; kpxobg4d0b [ 12 ] = ( ( ( ( ( (
( ( ( ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 4 ]
) * 41.0 / 1000.0 - muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 0 ] + rtB .
d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 4 ] ) * 2.1589019792054224E+63 / 1.0531229166855719E+65 )
- muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) *
1.3792038530483136E+33 / 6.4903710731685345E+33 ) - muDoubleScalarCos ( ( rtB
. d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] ) *
1.273508160121764E+35 / 6.4903710731685345E+35 ) - muDoubleScalarSin ( ( ( (
rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] )
- rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) *
2.6986274740067774E+65 / 1.3164036458569648E+67 ) + muDoubleScalarSin ( ( ( (
rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
1.0794509896027111E+64 / 5.2656145834278593E+65 ) + muDoubleScalarSin ( ( ( (
rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] )
- rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
1.0794509896027111E+64 / 5.2656145834278593E+65 ) + muDoubleScalarSin ( ( (
rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 3 ] ) * 1.2242553906469775E+64 / 2.6328072917139297E+65
) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) *
2.7584077060966275E+32 / 1.2980742146337069E+33 ) + muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 4 ] ) * 41.0 / 1000.0 ) -
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) -
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) * 3.0606384766174432E+65
/ 6.5820182292848242E+66 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 0 ] -
rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * 3.18377040030441E+36 /
1.6225927682921336E+37 ) + 3.5871999349602292E+65 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 3.2910091146424121E+66 ; kpxobg4d0b [ 1 ] = ( ( ( ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ) + ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) - ( (
( 4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) * -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) - ( ( ( ( ( ( ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ) + ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 ) * ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 - 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 ) + ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) + ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) + ( ( ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ; kpxobg4d0b [ 5 ] = ( ( ( ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ) + ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) - ( (
( 4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) - ( ( ( ( ( ( ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ) + ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * (
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) /
8.1129638414606682E+31 ) * ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 - 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) / 8.1129638414606682E+31 ) + ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) + ( ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) + ( ( ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + ( 4.967757600021511E+15 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) /
8.1129638414606682E+31 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 8.1129638414606682E+31 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 8.1129638414606682E+31 ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) ; kpxobg4d0b [ 9 ] = ( ( ( ( ( (
( muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] )
- rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4
] ) * 6.5820182292848234E+63 / 2.6328072917139297E+64 - muDoubleScalarCos (
rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 4 ] ) / 2.0 ) - muDoubleScalarCos
( ( ( ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l
[ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
6.5820182292848242E+63 / 2.6328072917139297E+64 ) - muDoubleScalarCos ( ( ( (
rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] )
- rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
6.5820182292848242E+63 / 2.6328072917139297E+64 ) - muDoubleScalarCos ( ( (
rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 3 ] ) * 4.0303237782115947E+47 / 1.3164036458569648E+64
) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 4 ] ) /
2.0 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1
] ) - rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) *
4.0303237782115947E+47 / 1.3164036458569648E+64 ) - 2.4678615572571482E+31 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) / 6.5820182292848242E+63 ) +
muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ]
) * 6.5820182292848256E+63 / 2.6328072917139297E+64 ; kpxobg4d0b [ 13 ] = ( (
( ( ( ( ( ( ( ( ( muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 0 ] - rtB .
d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 4 ] ) * 2.6986274740067774E+65 / 1.3164036458569648E+67 -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) *
1.3792038530483136E+33 / 6.4903710731685345E+33 ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 4 ] ) * 41.0 / 1000.0 ) -
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * 1.273508160121764E+35 / 6.4903710731685345E+35 ) -
muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) * 1.0794509896027111E+64 / 5.2656145834278593E+65 ) - muDoubleScalarCos ( (
( ( rtB . d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2
] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
1.0794509896027111E+64 / 5.2656145834278593E+65 ) - muDoubleScalarCos ( ( (
rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 3 ] ) * 1.2242553906469775E+64 / 2.6328072917139297E+65
) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 4 ] ) *
41.0 / 1000.0 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 0 ] - rtB .
d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) *
3.0606384766174432E+65 / 6.5820182292848242E+66 ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) * 2.7584077060966275E+32 /
1.2980742146337069E+33 ) - 3.5871999349602292E+65 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) / 3.2910091146424121E+66 ) - muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 0 ] - rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 2 ] ) *
3.18377040030441E+36 / 1.6225927682921336E+37 ) + muDoubleScalarCos ( ( ( (
rtB . d1pmn0ij1l [ 0 ] + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) *
2.1589019792054224E+63 / 1.0531229166855719E+65 ; kpxobg4d0b [ 2 ] = ( ( (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) * 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+31 ) + (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) * 2.4678615572571482E+31 / 6.5820182292848242E+63 +
3.749399456654644E-33 ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) -
3.749399456654644E-33 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) + ( (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) * 4.967757600021511E+15 / 8.1129638414606682E+31 +
6.123233995736766E-17 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) ; kpxobg4d0b [ 6 ] = ( ( (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) * 4.967757600021511E+15 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+31 ) + (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) * 2.4678615572571482E+31 / 6.5820182292848242E+63 +
3.749399456654644E-33 ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) -
3.749399456654644E-33 ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) - ( (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) * 4.967757600021511E+15 / 8.1129638414606682E+31 +
6.123233995736766E-17 ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ; kpxobg4d0b [ 10 ] = ( ( phi *
phi * 4.967757600021511E+15 * ( ns20wur0va * ns20wur0va ) /
2.028240960365167E+31 - ok14zp1th0_idx * ok14zp1th0_idx *
4.967757600021511E+15 / 2.028240960365167E+31 ) - muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) + 6.123233995736766E-17 ;
kpxobg4d0b [ 14 ] = ( ( ( ( ( muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) * 2.0367806160088195E+17
/ 4.0564819207303341E+34 + 5.0210518765041478E-18 ) * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 4 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 2 ] ) * 39243.0 / 100000.0 ) - 17.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 40.0 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) * 3.7725281862792107E+33
/ 4.0564819207303341E+34 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) * 41.0 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 500.0 ) + 0.089200000000000015
; kpxobg4d0b [ 3 ] = 0.0 ; kpxobg4d0b [ 7 ] = 0.0 ; kpxobg4d0b [ 11 ] = 0.0 ;
kpxobg4d0b [ 15 ] = 1.0 ; for ( i = 0 ; i < 3 ; i ++ ) { I_0 [ 6 * i ] =
kpxobg4d0b [ i << 2 ] ; I_0 [ 1 + 6 * i ] = kpxobg4d0b [ ( i << 2 ) + 1 ] ;
I_0 [ 2 + 6 * i ] = kpxobg4d0b [ ( i << 2 ) + 2 ] ; } for ( i = 0 ; i < 3 ; i
++ ) { I_0 [ 6 * ( i + 3 ) ] = 0.0 ; I_0 [ 1 + 6 * ( i + 3 ) ] = 0.0 ; I_0 [
2 + 6 * ( i + 3 ) ] = 0.0 ; } for ( i = 0 ; i < 3 ; i ++ ) { I_0 [ 3 + 6 * i
] = 0.0 ; I_0 [ 4 + 6 * i ] = 0.0 ; I_0 [ 5 + 6 * i ] = 0.0 ; } for ( i = 0 ;
i < 3 ; i ++ ) { I_0 [ 3 + 6 * ( i + 3 ) ] = kpxobg4d0b [ i << 2 ] ; I_0 [ 4
+ 6 * ( i + 3 ) ] = kpxobg4d0b [ ( i << 2 ) + 1 ] ; I_0 [ 5 + 6 * ( i + 3 ) ]
= kpxobg4d0b [ ( i << 2 ) + 2 ] ; } tmp_6 [ 0 ] = ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ]
- rtB . d1pmn0ij1l [ 5 ] ) * 3.5967658190210794E+79 / 1.067993517960455E+98 +
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 5 ] ) *
8.445187920036568E+16 / 6.4903710731685345E+33 ) + muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] - rtB . d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20 /
1.6225927682921336E+37 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20 /
1.6225927682921336E+37 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 2.7584077060966275E+32 /
2.5961484292674138E+33 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 2 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 /
6.4903710731685345E+33 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 2.0530600877940982E+81 /
3.4175792574734561E+98 ) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ]
) * 1.273508160121764E+35 / 1.2980742146337069E+36 ) - muDoubleScalarSin ( (
( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 5 ] ) * 1.1117276167883337E+80 /
1.7087896287367281E+97 ) + muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 5 ] ) * 5.1987556764765279E+128 /
1.7329185588255093E+130 ) + muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 1 ]
+ rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4
] ) + rtB . d1pmn0ij1l [ 5 ] ) * 2.1228252345612486E+129 /
8.6645927941275464E+130 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20
/ 1.6225927682921336E+37 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 1.3792038530483136E+33
/ 1.2980742146337069E+34 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 1.3792038530483136E+33
/ 1.2980742146337069E+34 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 2 ] +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 /
6.4903710731685345E+33 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 5.1326502194852446E+82 /
8.54394814368364E+99 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] - rtB .
d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 1.2831625548713111E+84 /
2.13598703592091E+101 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 191.0 / 2000.0 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) *
1.273508160121764E+35 / 1.2980742146337069E+36 ) - muDoubleScalarSin ( ( (
rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] )
+ rtB . d1pmn0ij1l [ 5 ] ) * 1.1117276167883338E+80 / 1.7087896287367281E+97
) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 5 ] ) *
2.8610637196758589E+81 / 5.3399675898022752E+98 ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 /
6.4903710731685345E+33 ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20 / 1.6225927682921336E+37 ) -
muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ]
) * 1.4296578110310452E+129 / 8.6645927941275464E+130 ) -
1.0118232384754309E+33 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
3.2910091146424121E+66 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] - rtB
. d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 2.7584077060966275E+32 /
2.5961484292674138E+33 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] - rtB
. d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 5.1326502194852446E+82 /
8.54394814368364E+99 ) - muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 5 ] ) *
27.0 / 2000.0 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) *
3.18377040030441E+36 / 3.2451855365842673E+37 ) - muDoubleScalarSin ( ( ( rtB
. d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 4 ] ) +
rtB . d1pmn0ij1l [ 5 ] ) * 3.18377040030441E+36 / 3.2451855365842673E+37 ) -
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 1.1117276167883337E+80
/ 1.7087896287367281E+97 ) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 2 ] +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 5.5586380839416679E+80 / 8.54394814368364E+97 ) + muDoubleScalarCos ( ( (
( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) *
6.1518608838305592E+129 / 8.6645927941275464E+130 ; tmp_6 [ 6 ] = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( 3.7725281862792107E+33 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
4.0564819207303341E+34 - 2.0367806160088195E+17 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 ) - 39243.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
100000.0 ) - 2.6986274740067779E+65 * muDoubleScalarSin ( rtB . d1pmn0ij1l [
4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 3.2910091146424121E+66
) + 17.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
40.0 ) + 1.9494971149764415E+20 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ]
) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 8.1129638414606682E+36 ) - 17.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 40.0 ) - 9.684629109144227E+35
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
6.5820182292848242E+68 ) - 1.9494971149764415E+20 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+36 ) -
39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) /
100000.0 ) - 4.1953646473371523E+32 * muDoubleScalarCos ( rtB . d1pmn0ij1l [
2 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
2.6328072917139297E+65 ) - 8.445187920036568E+16 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) / 3.2451855365842673E+33 ) - 17.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) / 40.0 ) - 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3
] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 40.0 )
+ 8.445187920036568E+16 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
3.2451855365842673E+33 ) + 8.445187920036568E+16 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 3.2451855365842673E+33 ) + 4.1953646473371523E+32 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 2.6328072917139297E+65 ) +
8.445187920036568E+16 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) /
3.2451855365842673E+33 ; tmp_6 [ 12 ] = ( ( ( ( ( ( 3.7725281862792107E+33 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 - 2.0367806160088195E+17 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 ) -
39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 5 ] ) / 100000.0 ) - 2.6986274740067779E+65 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 3.2910091146424121E+66 ) + 1.9494971149764415E+20 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
8.1129638414606682E+36 ) - 9.684629109144227E+35 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 6.5820182292848242E+68 ) -
1.9494971149764415E+20 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+36 ) - 39243.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) / 100000.0 ; tmp_6 [ 18 ] = (
3.7725281862792107E+33 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 -
2.0367806160088195E+17 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
4.0564819207303341E+34 ) - 2.6986274740067779E+65 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
3.2910091146424121E+66 ; tmp_6 [ 24 ] = - ( 41.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) ) / 500.0 ; tmp_6 [ 30 ] = 0.0 ; tmp_6 [ 1 ] = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] - rtB . d1pmn0ij1l [ 5 ] ) * 3.5967658190210794E+79 /
1.067993517960455E+98 - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] - rtB .
d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20 / 1.6225927682921336E+37 ) -
muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 6.1518608838305592E+129 / 8.6645927941275464E+130 ) - muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 /
6.4903710731685345E+33 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20 /
1.6225927682921336E+37 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 2.7584077060966275E+32 /
2.5961484292674138E+33 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 2 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 /
6.4903710731685345E+33 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 2.0530600877940982E+81 /
3.4175792574734561E+98 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ]
) * 1.273508160121764E+35 / 1.2980742146337069E+36 ) + muDoubleScalarCos ( (
( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 5 ] ) * 1.1117276167883337E+80 /
1.7087896287367281E+97 ) + muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 5 ] ) * 5.1987556764765279E+128 /
1.7329185588255093E+130 ) - muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 1 ]
+ rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4
] ) + rtB . d1pmn0ij1l [ 5 ] ) * 2.1228252345612486E+129 /
8.6645927941275464E+130 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 1.9494971149764415E+20
/ 1.6225927682921336E+37 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 1.3792038530483136E+33
/ 1.2980742146337069E+34 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 1.3792038530483136E+33
/ 1.2980742146337069E+34 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 2 ] +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 /
6.4903710731685345E+33 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 5.1326502194852446E+82 /
8.54394814368364E+99 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] - rtB .
d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 1.2831625548713111E+84 /
2.13598703592091E+101 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 1.273508160121764E+35 / 1.2980742146337069E+36 ) - muDoubleScalarCos ( (
( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ]
) + rtB . d1pmn0ij1l [ 5 ] ) * 1.1117276167883338E+80 /
1.7087896287367281E+97 ) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 191.0 / 2000.0 ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 5 ] ) * 8.445187920036568E+16 / 6.4903710731685345E+33 ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 5 ] ) *
1.9494971149764415E+20 / 1.6225927682921336E+37 ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 5 ] ) * 2.8610637196758589E+81 /
5.3399675898022752E+98 ) - muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 5 ] ) * 1.4296578110310452E+129 /
8.6645927941275464E+130 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 2.7584077060966275E+32
/ 2.5961484292674138E+33 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] -
rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 5.1326502194852446E+82
/ 8.54394814368364E+99 ) + 1.0118232384754309E+33 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 3.2910091146424121E+66 ) - muDoubleScalarCos ( ( ( rtB .
d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 4 ] ) - rtB
. d1pmn0ij1l [ 5 ] ) * 3.18377040030441E+36 / 3.2451855365842673E+37 ) -
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) -
rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) * 3.18377040030441E+36 /
3.2451855365842673E+37 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 2 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ]
) * 1.1117276167883337E+80 / 1.7087896287367281E+97 ) - muDoubleScalarCos ( (
( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) + rtB . d1pmn0ij1l [ 5 ] ) * 5.5586380839416679E+80 / 8.54394814368364E+97
) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 5 ] ) * 27.0 / 2000.0 ; tmp_6
[ 7 ] = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( 2.0367806160088195E+17 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 -
39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 5 ] ) / 100000.0 ) - 3.7725281862792107E+33 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 ) - 2.6986274740067779E+65 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) / 3.2910091146424121E+66 ) - 17.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 40.0 ) - 9.684629109144227E+35
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
6.5820182292848242E+68 ) + 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ]
) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) / 40.0 ) + 1.9494971149764415E+20 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 8.1129638414606682E+36 ) +
39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
100000.0 ) + 1.9494971149764415E+20 * muDoubleScalarCos ( rtB . d1pmn0ij1l [
5 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+36 ) - 4.1953646473371523E+32
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 2.6328072917139297E+65 ) +
8.445187920036568E+16 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
3.2451855365842673E+33 ) + 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ]
) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 40.0 ) +
8.445187920036568E+16 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) /
3.2451855365842673E+33 ) + 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ]
) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 40.0 ) +
8.445187920036568E+16 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) /
3.2451855365842673E+33 ) + 4.1953646473371523E+32 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) / 2.6328072917139297E+65 ) - 8.445187920036568E+16 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 3.2451855365842673E+33 ; tmp_6
[ 13 ] = ( ( ( ( ( ( 2.0367806160088195E+17 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 - 39243.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
100000.0 ) - 3.7725281862792107E+33 * muDoubleScalarCos ( rtB . d1pmn0ij1l [
4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34
) - 2.6986274740067779E+65 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 3.2910091146424121E+66 ) -
9.684629109144227E+35 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 5 ] ) / 6.5820182292848242E+68 ) + 1.9494971149764415E+20 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
8.1129638414606682E+36 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4
] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB
. d1pmn0ij1l [ 5 ] ) / 100000.0 ) + 1.9494971149764415E+20 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) /
8.1129638414606682E+36 ; tmp_6 [ 19 ] = ( 2.0367806160088195E+17 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 -
3.7725281862792107E+33 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+34 ) -
2.6986274740067779E+65 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 3.2910091146424121E+66 ; tmp_6
[ 25 ] = 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 500.0 ; tmp_6
[ 31 ] = 0.0 ; tmp_6 [ 2 ] = ( ( ( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 4 ] ) * 17.0 / 80.0 +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] - rtB . d1pmn0ij1l [ 4 ] ) *
1.581619960283576E+52 / 1.3164036458569648E+69 ) + muDoubleScalarCos ( ( rtB
. d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 4 ] ) *
39243.0 / 200000.0 ) - muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 2 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * 1.3703100845919423E+48 /
1.0531229166855719E+65 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) * 5.414855784023447E+17 /
8.1129638414606682E+34 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * 39243.0 / 200000.0 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) - rtB
. d1pmn0ij1l [ 4 ] ) * 6.85155042295971E+48 / 5.2656145834278593E+65 ) -
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * 1.3295676823155345E+66
/ 1.3164036458569648E+67 ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] + rtB
. d1pmn0ij1l [ 2 ] ) * 9.684629109144227E+35 / 6.5820182292848242E+68 ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 4 ] ) * 17.0
/ 80.0 ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3
] ) * 4.1953646473371523E+32 / 2.6328072917139297E+65 ) - muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 4 ] ) * 6.3264798411343046E+50 /
5.2656145834278593E+67 ) + 4.1953646473371523E+32 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) / 2.6328072917139297E+65 ) + 9.684629109144227E+35 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) / 6.5820182292848242E+68 ) -
4.6200145680200051E+17 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) /
8.1129638414606682E+34 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) * 1.0531229166855718E+65 / 1.3164036458569648E+67 ; tmp_6 [ 8 ] = ( ( ( ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] - rtB . d1pmn0ij1l [ 4 ] ) *
3.18377040030441E+36 / 1.6225927682921336E+37 - muDoubleScalarCos ( ( rtB .
d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) *
2.7584077060966275E+32 / 1.2980742146337069E+33 ) + muDoubleScalarCos ( ( rtB
. d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
1.3792038530483136E+33 / 6.4903710731685345E+33 ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 3 ] ) * 8.445187920036568E+16 /
3.2451855365842673E+33 ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 4 ] ) * 1.273508160121764E+35 / 6.4903710731685345E+35 ) +
1.9494971149764415E+20 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) /
8.1129638414606682E+36 ) - 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ]
) / 1000.0 ; tmp_6 [ 14 ] = ( ( 1.9494971149764415E+20 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) / 8.1129638414606682E+36 - 93.0 * muDoubleScalarSin
( rtB . d1pmn0ij1l [ 4 ] ) / 1000.0 ) - 1.9494971149764415E+20 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+36 ) + 39243.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) /
100000.0 ; tmp_6 [ 20 ] = - ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4
] ) ) / 1000.0 ; tmp_6 [ 26 ] = 0.0 ; tmp_6 [ 32 ] = 0.0 ; tmp_6 [ 3 ] = ( (
( ( ( ( ( muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l
[ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) + rtB .
d1pmn0ij1l [ 5 ] ) * 6.5820182292848256E+63 / 2.6328072917139297E+64 +
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] - rtB . d1pmn0ij1l [ 5 ] ) *
4.0303237782115947E+47 / 1.3164036458569648E+64 ) + muDoubleScalarSin ( ( ( (
rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] )
+ rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) *
6.5820182292848242E+63 / 2.6328072917139297E+64 ) + muDoubleScalarSin ( ( ( (
rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] )
- rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ] ) *
6.5820182292848234E+63 / 2.6328072917139297E+64 ) + muDoubleScalarSin ( ( (
rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] )
+ rtB . d1pmn0ij1l [ 5 ] ) / 2.0 ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 5 ] ) * 4.0303237782115947E+47 /
1.3164036458569648E+64 ) + muDoubleScalarSin ( ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 5 ] ) * 6.5820182292848242E+63 /
2.6328072917139297E+64 ) - 2.4678615572571482E+31 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) / 6.5820182292848242E+63 ) - muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - rtB
. d1pmn0ij1l [ 5 ] ) / 2.0 ; tmp_6 [ 9 ] = ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) - x * x * 4.967757600021511E+15 * muDoubleScalarSin ( rtB
. d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+31 ) - scale * scale * 2.0 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ; tmp_6 [ 15 ] = (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) - t * t * 4.967757600021511E+15
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) / 4.0564819207303341E+31 ) - s
* s * 2.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ; tmp_6 [ 21 ] = (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) - theta * theta *
4.967757600021511E+15 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) /
4.0564819207303341E+31 ) - fh0cjr3tor * fh0cjr3tor * 2.0 * muDoubleScalarSin
( rtB . d1pmn0ij1l [ 4 ] ) ; tmp_6 [ 27 ] = - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 5 ] ) ; tmp_6 [ 33 ] = 0.0 ; tmp_6 [ 4 ] = ( ( ( ( ( ( (
muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 6.5820182292848234E+63 / 2.6328072917139297E+64 - muDoubleScalarCos ( ( (
( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) *
6.5820182292848242E+63 / 2.6328072917139297E+64 ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] - rtB . d1pmn0ij1l [ 5 ] ) * 4.0303237782115947E+47 /
1.3164036458569648E+64 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 5 ]
) / 2.0 ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 5
] ) * 4.0303237782115947E+47 / 1.3164036458569648E+64 ) - muDoubleScalarCos (
( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [
3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 5 ] ) *
6.5820182292848242E+63 / 2.6328072917139297E+64 ) - 2.4678615572571482E+31 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 6.5820182292848242E+63 ) +
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 5 ] ) / 2.0 ) +
muDoubleScalarCos ( ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 5 ]
) * 6.5820182292848256E+63 / 2.6328072917139297E+64 ; tmp_6 [ 10 ] = (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 8.1129638414606682E+31 -
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
8.1129638414606682E+31 ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_6 [ 16 ] = (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 8.1129638414606682E+31 -
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
8.1129638414606682E+31 ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_6 [ 22 ] = (
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) / 8.1129638414606682E+31 -
4.967757600021511E+15 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) /
8.1129638414606682E+31 ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_6 [ 28 ] = -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 5 ] ) ; tmp_6 [ 34 ] = 0.0 ; tmp_6 [ 5
] = ( ( ( muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) *
8.1129638414606682E+31 / 1.6225927682921336E+32 - muDoubleScalarCos ( ( rtB .
d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) *
4.967757600021511E+15 / 8.1129638414606682E+31 ) + 4.967757600021511E+15 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) / 8.1129638414606682E+31 ) -
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * 8.1129638414606673E+31
/ 1.6225927682921336E+32 ) + 2.2958450216584675E-49 ; tmp_6 [ 11 ] =
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) + 3.749399456654644E-33 ; tmp_6
[ 17 ] = muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) + 3.749399456654644E-33
; tmp_6 [ 23 ] = muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) +
3.749399456654644E-33 ; tmp_6 [ 29 ] = 6.123233995736766E-17 ; tmp_6 [ 35 ] =
1.0 ; for ( i = 0 ; i < 6 ; i ++ ) { for ( iy = 0 ; iy < 6 ; iy ++ ) { rtB .
ewrxhcp51e [ i + 6 * iy ] = 0.0 ; for ( ix = 0 ; ix < 6 ; ix ++ ) { rtB .
ewrxhcp51e [ i + 6 * iy ] += I_0 [ 6 * ix + i ] * tmp_6 [ 6 * iy + ix ] ; } }
} for ( i = 0 ; i < 36 ; i ++ ) { rtB . lqmj5akbao [ i ] = rtB . oshetbdj3o [
i ] - rtB . ewrxhcp51e [ i ] ; } tmp_7 [ 0 ] = ( ( ( ( ( ( 41.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] ) / 500.0 + 109.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0
] ) / 1000.0 ) + 17.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) / 40.0 ) - ( muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - ( ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) - 39243.0 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) / 100000.0 ; tmp_7 [ 6 ] = ( ( ( ( 17.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 40.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0
; tmp_7 [ 12 ] = ( ( ( ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [
0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) / 100000.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 100000.0 ; tmp_7 [ 18 ] = ( (
( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; tmp_7 [ 24 ] = ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] )
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - 41.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 500.0 ;
tmp_7 [ 30 ] = 0.0 ; tmp_7 [ 1 ] = ( ( ( ( ( ( 109.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 0 ] ) / 1000.0 - 17.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 ) +
41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) * muDoubleScalarSin ( rtB
. d1pmn0ij1l [ 0 ] ) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ]
) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ) + ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + 39243.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) - 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
; tmp_7 [ 7 ] = ( ( ( ( 17.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) / 40.0 - ( muDoubleScalarSin (
rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 100000.0 ; tmp_7 [ 13 ] = ( ( ( ( ( muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + 39243.0 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
) + 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) / 100000.0 ; tmp_7 [ 19 ] = ( ( ( muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) - (
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; tmp_7 [ 25 ] = (
( muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 + 41.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) / 500.0 ; tmp_7 [ 31 ] = 0.0 ;
tmp_7 [ 2 ] = 0.0 ; tmp_7 [ 8 ] = ( ( ( ( 39243.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
- 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos
( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) - 17.0 * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) / 40.0 ) - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ]
) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 ; tmp_7 [ 14 ] = ( ( ( 39243.0 * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0
- 39243.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos
( rtB . d1pmn0ij1l [ 2 ] ) / 100000.0 ) - ( ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) -
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] )
) / 500.0 ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * ( 93.0
* muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; tmp_7 [ 20 ] = ( ( muDoubleScalarCos (
rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * ( 93.0 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] )
) / 1000.0 - ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * (
41.0 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) / 500.0 ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) * ( 93.0 * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] ) ) / 1000.0 ; tmp_7 [ 26 ] = - ( ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * ( 41.0 * muDoubleScalarCos (
rtB . d1pmn0ij1l [ 4 ] ) ) ) / 500.0 ; tmp_7 [ 32 ] = 0.0 ; tmp_7 [ 3 ] = 0.0
; tmp_7 [ 9 ] = muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 15 ] =
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 21 ] =
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 27 ] = (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ; tmp_7 [ 33 ] = ( ( muDoubleScalarCos ( rtB . d1pmn0ij1l
[ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 4 ] = 0.0 ; tmp_7 [ 10
] = - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 16 ] = -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 22 ] = -
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) ; tmp_7 [ 28 ] = (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) ; tmp_7 [ 34 ] = ( ( muDoubleScalarSin ( rtB . d1pmn0ij1l
[ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin (
rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) ) * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) + (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) +
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 0 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) - muDoubleScalarCos ( rtB . d1pmn0ij1l [ 0 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; tmp_7 [ 5 ] = 1.0 ; tmp_7 [ 11
] = 0.0 ; tmp_7 [ 17 ] = 0.0 ; tmp_7 [ 23 ] = 0.0 ; tmp_7 [ 29 ] = (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 3 ] ) - ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] ) ; tmp_7 [ 35 ] = ( (
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 2 ] ) + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) ) * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] ) + ( muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 2 ] ) - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 1 ] ) * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 2 ] ) ) *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] ) ) * - muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . agea4cv0wk [ i ] =
0.0 ; for ( iy = 0 ; iy < 6 ; iy ++ ) { rtB . agea4cv0wk [ i ] += tmp_7 [ 6 *
iy + i ] * rtB . mzfhfa0zkn [ iy ] ; } } theta = muDoubleScalarAcos ( ( ( (
rtB . lriz3d1h1w [ 0 ] + rtB . lriz3d1h1w [ 4 ] ) + rtB . lriz3d1h1w [ 8 ] )
- 1.0 ) / 2.0 ) ; scale = 1.0 / ( 2.0 * muDoubleScalarSin ( theta ) ) ; rtB .
ank5kdwdcq [ 0 ] = ( rtB . lriz3d1h1w [ 5 ] - rtB . lriz3d1h1w [ 7 ] ) *
scale ; rtB . ank5kdwdcq [ 1 ] = ( rtB . lriz3d1h1w [ 6 ] - rtB . lriz3d1h1w
[ 2 ] ) * scale ; rtB . ank5kdwdcq [ 2 ] = ( rtB . lriz3d1h1w [ 1 ] - rtB .
lriz3d1h1w [ 3 ] ) * scale ; rtB . mytz3m1ztc = theta ; if (
ssIsMajorTimeStep ( rtS ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtDW .
h0luuex5q2 [ i ] = rtB . nghlo5plg0 . p505mfvaxs [ i ] >= rtP .
torque_limits1_UpperSat [ i ] ? 1 : rtB . nghlo5plg0 . p505mfvaxs [ i ] > rtP
. torque_limits1_LowerSat [ i ] ? 0 : - 1 ; } } B_0 [ 0 ] = ( rtDW .
h0luuex5q2 [ 0 ] == 1 ? rtP . torque_limits1_UpperSat [ 0 ] : rtDW .
h0luuex5q2 [ 0 ] == - 1 ? rtP . torque_limits1_LowerSat [ 0 ] : rtB .
nghlo5plg0 . p505mfvaxs [ 0 ] ) - ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
muDoubleScalarSin ( ( ( ( 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l
[ 4 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] ) +
muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * ( 2.5E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [
5 ] ) ) - muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 *
rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * ( 2.5E-15 * rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - 2.5E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB .
d1pmn0ij1l [ 4 ] ) ) - muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5
] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 *
rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * ( 2.5E-15 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( 2.0 *
rtB . d1pmn0ij1l [ 3 ] + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [
5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 * rtB
. d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [
5 ] ) ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * 0.0056875200000000006 ) +
muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * - 0.0056875200000000006 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) *
- 4.3368086899420177E-19 ) + muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ]
+ 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 1 ] ) * 4.9999988958188135E-14 ) + rtB . mzfhfa0zkn [ 0 ] * rtB
. mzfhfa0zkn [ 1 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * -
0.82728427000054983 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ]
+ 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) *
0.00026442415071 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 2 ] ) * 4.9999934748079511E-13 )
+ muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] + 2.0 * rtB . d1pmn0ij1l
[ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 1 ] ) * 9.2591233300000353E-6 ) + muDoubleScalarSin ( 2.0 * rtB
. d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 1 ] ) * 4.9999934748079511E-14 ) + muDoubleScalarSin (
2.0 * rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * - 4.99996908025907E-14 ) +
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 1
] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * -
0.045159973551500004 ) + muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ] +
2.0 * rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * 4.9999988958188135E-14 ) +
muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [
3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 1 ] ) * - 4.9999988958188135E-14 ) + muDoubleScalarCos ( ( - rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * (
rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * 4.3368086899420177E-19 )
+ muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB .
d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) *
0.00026442415071 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) *
1.7347234759768071E-18 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 1 ] ) * - 0.015556156 ) + muDoubleScalarSin ( 2.0 *
rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) * ( rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * - 4.9999880537970887E-14 ) +
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4
] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) *
4.9999988958188135E-14 ) + muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ]
+ 2.0 * rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * - 4.9999988958188135E-14 ) +
muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l [
3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 2 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * rtB
. d1pmn0ij1l [ 3 ] + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 2 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 3 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * - 1.3552527156068805E-20 ) +
muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l [
3 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 2 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( 2.0 *
rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) - 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 2 ] -
2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn
[ 2 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * rtB .
d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ]
* rtB . mzfhfa0zkn [ 2 ] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( (
2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ] +
2.0 * rtB . d1pmn0ij1l [ 3 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn
[ 2 ] ) * - 5.4210108624275222E-20 ) + rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 2 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 3 ] ) *
5.4210108624275222E-20 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * 5.0001669471555488E-14 )
+ muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [
1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
0.045159973552 ) + muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] + 2.0 *
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * 9.2591233299999811E-6 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + 2.0
* rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2
] ) * - 0.007778077999999999 ) + muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
0.0028437600000000003 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [
4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 *
rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ]
) * 0.00026442415070999996 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l
[ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0
* rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2
] ) * 0.00026442415065999997 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
0.0028437600000000003 ) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) -
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 5 ] * rtB . mzfhfa0zkn [ 4 ] ) ) - muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 5 ] * rtB .
mzfhfa0zkn [ 4 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ]
+ 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) *
0.00026442415078499997 ) + muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ]
+ 2.0 * rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 1.2499999950052465E-13 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l
[ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * 0.00026442415070999996 )
+ muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l
[ 2 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 3 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 *
rtB . d1pmn0ij1l [ 2 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * 1.3552527156068805E-20 ) +
muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] + 2.0 * rtB . d1pmn0ij1l [
2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 3 ] ) * 9.2591235799999259E-6 ) + muDoubleScalarSin ( 2.0 * rtB
. d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 3 ] ) * - 1.9999995583275254E-13 ) + rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 3 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [
1 ] ) * 1.9999995583275254E-13 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 0.007778077999999999 ) + muDoubleScalarSin
( ( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB
. d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) *
4.9999988958188135E-14 ) + muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ] +
2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn
[ 3 ] ) * - 4.9999988958188135E-14 ) + muDoubleScalarSin ( 2.0 * rtB .
d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ]
* rtB . mzfhfa0zkn [ 3 ] ) * 1.2499999950052465E-13 ) + muDoubleScalarSin ( (
2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 3 ] -
2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn
[ 3 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [
2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 4 ] ) * 0.00026442415066 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB
. d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 4 ] ) * - 0.00026442415066 ) + muDoubleScalarCos ( ( ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0
* rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4
] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) *
0.0028437600000000003 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * - 0.0029173632 ) + rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * - 0.007778077999999999 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 2 ] ) * - 0.0028437600000000003 ) + rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 3 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) * - 0.007778077999999999 ) + muDoubleScalarCos ( (
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * 0.0028437600000000003
) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] )
+ rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3
] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ]
) * 0.0028437600000000003 ) + muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4
] ) * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] * -
2.9815559743351372E-19 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830132 ) -
5.0E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 5 ] ) ) + rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 2 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) *
4.9999988958188135E-14 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * 7.5000010542336515E-14 )
+ 2.5E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] *
muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 4 ] )
) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) * 0.00052884830131999993 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) -
rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) *
- 0.00404460056 ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) * - 0.0014586816 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1
] * rtB . mzfhfa0zkn [ 2 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - 2.0
* rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2
] ) * - 2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [
1 ] + rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l
[ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
0.00052884830131999993 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 3 ] ) * 0.0014586816 ) +
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1
] * rtB . mzfhfa0zkn [ 3 ] ) * - 0.0014586816 ) + muDoubleScalarSin ( ( ( -
2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB .
mzfhfa0zkn [ 3 ] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( 2.0 * rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 3 ]
) * 0.00052884830132 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 3 ] ) * - 0.00404460056 ) + muDoubleScalarSin ( ( ( - 2.0
* rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [
4 ] ) * 0.000528848301245 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1
] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0014586816 ) +
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1
] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 4
] ) * 0.000528848301245 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1
] * rtB . mzfhfa0zkn [ 4 ] ) * 0.00201419267009 ) - muDoubleScalarSin ( ( ( -
2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 1 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
6.08795974E-5 * rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 5 ] ) ) +
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 1 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) - 1.0E-14 * rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [
5 ] * muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( 2.5E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn
[ 5 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
2.5E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] ) ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) -
rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn
[ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 5.4210108624275222E-20 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) -
rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ]
) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn
[ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * 5.4210108624275222E-20 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ]
) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn
[ 2 ] * rtB . mzfhfa0zkn [ 4 ] ) * 6.2500026855316637E-14 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn
[ 2 ] * rtB . mzfhfa0zkn [ 4 ] ) * 6.2500026855316637E-14 ) +
muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 2 ] - rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 4 ]
) * 1.2500005371063327E-13 ) + muDoubleScalarSin ( ( ( ( 2.0 * rtB .
d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( 2.5E-15 * rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * ( 2.5E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] *
rtB . mzfhfa0zkn [ 4 ] ) * 0.0020141926702150004 ) + muDoubleScalarSin ( ( (
2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 4 ] ) * 0.00052884830130750006 ) + muDoubleScalarSin ( ( ( - 2.0
* rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [
4 ] ) * 0.00052884830130750006 ) - muDoubleScalarSin ( ( ( ( - 2.0 * rtB .
d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3
] ) * 0.00052884830131999993 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) *
- 0.00052884830131999993 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 3 ] ) * - 0.00404460056 ) + muDoubleScalarSin ( ( ( -
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
6.08795974E-5 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + 5.0E-15
* rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( ( rtB
. d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) ) +
muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 2.5E-15 * rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) *
0.0014586816 ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 0.0014586816 ) +
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 4 ] ) *
0.0014586816 ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0014586816 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn
[ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) * 7.5000010542336515E-14 ) +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) *
0.00201419266994 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.00052884830132 )
+ muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1
] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) * ( rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) * 7.5000010542336515E-14 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 3
] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0014586816 ) + muDoubleScalarSin ( ( - rtB .
d1pmn0ij1l [ 2 ] - rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) * - 1.5000002108467303E-13
) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l
[ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.00052884830132 ) -
muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * ( 2.5E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [
5 ] ) ) - muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
2.5E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) -
muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 2.5E-15 * rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( ( ( 2.0
* rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( 2.5E-15 *
rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + 5.0E-15 * rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) ) +
muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) + rtB .
d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [
5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
2.5E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) -
muDoubleScalarSin ( ( ( ( 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l
[ 4 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 2.5E-15 * rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( - rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 3 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ]
) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [
1 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) *
0.00026442415065999997 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
2.0 * rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l
[ 2 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l
[ 1 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
0.00026442415065999997 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 3 ] *
rtB . mzfhfa0zkn [ 3 ] ) * - 0.00202230028 ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) *
0.0007293408 ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) * - 0.0007293408 ) +
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 4
] * rtB . mzfhfa0zkn [ 4 ] ) * - 0.0007293408 ) + rtB . mzfhfa0zkn [ 4 ] *
rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 1 ] ) * - 0.0028437600000000003 ) + muDoubleScalarSin ( ( ( rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 4 ] * rtB . mzfhfa0zkn [ 4 ]
) * 0.0007293408 ) + rtB . mzfhfa0zkn [ 4 ] * rtB . mzfhfa0zkn [ 4 ] *
muDoubleScalarCos ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * -
0.0028437600000000003 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l
[ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
0.00026442415065999997 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [
1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2 ] ) *
0.00026442415065999997 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] *
rtB . mzfhfa0zkn [ 2 ] ) * - 0.00202230028 ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - 2.0
* rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2
] ) * 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [
1 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2 ] ) * 0.0007293408 )
+ muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] )
+ rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [
2 ] * rtB . mzfhfa0zkn [ 2 ] ) * - 0.0007293408 ) + muDoubleScalarSin ( ( (
rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] )
+ 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 2 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB
. d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) -
2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn
[ 2 ] ) * - 1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB
. d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l
[ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) * -
0.00026442415065999997 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 1 ] ) * - 0.00202230028 ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 3 ] )
- rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1
] ) * 3.2526065174565133E-19 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [
1 ] * muDoubleScalarCos ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] )
* 0.0028437600000000003 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [
1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) *
0.00026442415065999964 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) * -
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) *
1.3552527156068805E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) *
1.3552527156068805E-20 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * 0.267177491 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1
] * rtB . mzfhfa0zkn [ 1 ] ) * 0.0007293408 ) + muDoubleScalarSin ( ( ( - rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ]
) * - 0.0007293408 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB .
d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ]
) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * -
3.3881317890172014E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * -
3.3881317890172014E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
2.0 * rtB . d1pmn0ij1l [ 4 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l
[ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
2.439454888092385E-19 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] -
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
3.3881317890172014E-20 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] +
rtB . d1pmn0ij1l [ 2 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
3.3881317890172014E-20 ) + muDoubleScalarCos ( ( ( 2.0 * rtB . d1pmn0ij1l [ 2
] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) + rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
5.4210108624275222E-20 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [
2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * -
2.7105054312137611E-20 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * 2.7755575615628914E-17 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 9.4867690092481638E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l
[ 4 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + 3.0 * rtB . d1pmn0ij1l
[ 2 ] ) + 3.0 * rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 2.7105054312137611E-20 ) +
muDoubleScalarCos ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 4 ]
) + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 5.4210108624275222E-20 ) +
muDoubleScalarCos ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] - rtB . d1pmn0ij1l [ 4 ]
) + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 5.4210108624275222E-20 ) +
muDoubleScalarCos ( ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l
[ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 5.4210108624275222E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + 3.0 * rtB . d1pmn0ij1l
[ 2 ] ) + 3.0 * rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 2.7105054312137611E-20 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ]
) + 3.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 3.3881317890172014E-21 ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 1 ] + rtB . d1pmn0ij1l [ 2 ] ) +
3.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 3.3881317890172014E-21 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + 3.0 * rtB . d1pmn0ij1l
[ 2 ] ) + 3.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * (
rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 1.0164395367051604E-20 )
+ muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 1
] ) + 3.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB
. mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 3.3881317890172014E-21 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 1 ] + 3.0 * rtB . d1pmn0ij1l
[ 2 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 6.7762635780344027E-21 ) +
muDoubleScalarSin ( ( ( 3.0 * rtB . d1pmn0ij1l [ 2 ] + rtB . d1pmn0ij1l [ 1 ]
) + rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 6.7762635780344027E-21 ) +
muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 1.4907779871675686E-19 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 2.1684043449710089E-19 ) + rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] * muDoubleScalarCos ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * 2.1684043449710089E-19 ) + rtB
. mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * 2.1684043449710089E-19 ) ; B_0
[ 1 ] = ( ( rtDW . h0luuex5q2 [ 1 ] == 1 ? rtP . torque_limits1_UpperSat [ 1
] : rtDW . h0luuex5q2 [ 1 ] == - 1 ? rtP . torque_limits1_LowerSat [ 1 ] :
rtB . nghlo5plg0 . p505mfvaxs [ 1 ] ) - ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] + 2.0 * rtB .
d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * - 4.6295615399999775E-6 + muDoubleScalarCos (
( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 0 ] ) * 0.0028437600000000003 ) + muDoubleScalarCos ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0
* rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0
] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 2.1684043449710089E-19 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
- 2.1684043449710089E-19 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 0.007778078 ) + rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * 8.6736173798840355E-19 ) + rtB
. mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] * muDoubleScalarCos ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * 1.7347234759768071E-18 ) +
2.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] * muDoubleScalarSin
( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1
] ) ) - 2.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] *
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 1.0E-13 * rtB . mzfhfa0zkn
[ 0 ] ) * rtB . mzfhfa0zkn [ 3 ] ) + rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 0 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 1 ] ) *
0.41364213499999991 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 4 ] *
rtB . mzfhfa0zkn [ 4 ] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( (
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* ( rtB . mzfhfa0zkn [ 4 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0028437600000000003
) + rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2 ] * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * - 0.007778077999999999 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 2 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 2 ] ) * - 0.0028437600000000003 ) + rtB . mzfhfa0zkn [
3 ] * rtB . mzfhfa0zkn [ 3 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) * - 0.007778077999999999 ) + muDoubleScalarCos ( (
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] ) * 0.0028437600000000003
) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] )
+ rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3
] ) * - 0.0028437600000000003 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [
4 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) *
0.0056875200000000006 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] *
muDoubleScalarCos ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * -
0.0056875200000000006 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * -
0.015556155999999998 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 2 ] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( -
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 2 ] ) * -
0.0056875200000000006 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 3 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * -
0.015556155999999998 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 3 ] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( -
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
0.0056875200000000006 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 4 ] ) * 0.0056875200000000006 ) + muDoubleScalarCos ( ( -
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0056875200000000006
) + rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] * muDoubleScalarCos ( rtB
. d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * - 0.015556155999999998 ) +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 3 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 3 ] ) * - 0.0056875200000000006 ) + muDoubleScalarCos
( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2
] ) * ( rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 4 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0056875200000000006 ) + muDoubleScalarCos (
( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) * ( rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] ) *
0.0056875200000000006 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 3
] * rtB . mzfhfa0zkn [ 4 ] ) * 0.0056875200000000006 ) + muDoubleScalarSin (
2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 0.02257998678 ) -
0.0001217591948 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * rtB .
mzfhfa0zkn [ 5 ] * rtB . mzfhfa0zkn [ 4 ] ) + muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) * - 0.00201419266984 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.00052884830132 ) + muDoubleScalarSin ( (
( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] *
rtB . mzfhfa0zkn [ 4 ] ) * 0.00052884830132 ) + muDoubleScalarSin ( ( ( ( -
2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB
. mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( ( ( -
2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB
. mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - 1.0E-14 * rtB . mzfhfa0zkn
[ 1 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [
4 ] ) ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * 0.00105769660249 ) + rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ]
) * 0.0010576966027400002 ) + 5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 *
rtB . d1pmn0ij1l [ 4 ] ) ) + 5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 5 ] ) ) +
5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) ) + rtB . mzfhfa0zkn [ 3 ] * rtB .
mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) *
0.00105769660279 ) - 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5
] * muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) ) - 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [
5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 5 ] ) ) + 5.0E-15 * rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * ( 2.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) ) -
muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 2.0E-13 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) ) - muDoubleScalarSin ( ( ( - 2.0
* rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * ( 5.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 3 ] ) ) - muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) *
( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0
* rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.00013221207533 ) + muDoubleScalarSin ( ( (
2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.00013221207533 ) ) - ( ( (
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 *
0.0066912000000000004 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 1 ] ) * 9.81 *
- 2.37167 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) *
9.81 * - 0.0066912000000000004 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3
] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 * 0.01830136 )
; B_0 [ 2 ] = ( ( rtDW . h0luuex5q2 [ 2 ] == 1 ? rtP .
torque_limits1_UpperSat [ 2 ] : rtDW . h0luuex5q2 [ 2 ] == - 1 ? rtP .
torque_limits1_LowerSat [ 2 ] : rtB . nghlo5plg0 . p505mfvaxs [ 2 ] ) - ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] + 2.0 * rtB . d1pmn0ij1l [
2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 0 ] ) * - 4.629561539999991E-6 + muDoubleScalarCos ( ( ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0
* rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0
] ) * 0.0014218800000000001 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * -
0.0014218800000000001 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * 0.0014218800000000001 ) + muDoubleScalarCos (
( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * -
0.0014218800000000001 ) + muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1
] * rtB . mzfhfa0zkn [ 1 ] ) * 0.0028437600000000003 ) + muDoubleScalarCos (
( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) * -
0.0028437600000000003 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 0.0038890390000000004 ) + rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 0 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) * 0.0038890390000000004 ) + rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 1 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) * 0.0077780780000000008 ) - muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
3.0E-13 * rtB . mzfhfa0zkn [ 0 ] ) * rtB . mzfhfa0zkn [ 3 ] ) + rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] * 0.02257998678 * muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) ) -
0.0001217591948 * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * rtB .
mzfhfa0zkn [ 5 ] * rtB . mzfhfa0zkn [ 4 ] ) + muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) * - 0.0020141926698400005 )
+ muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.00052884830132 ) +
muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ] ) * 0.00052884830132000015 ) +
muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) - rtB .
d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [
5 ] ) ) - muDoubleScalarSin ( ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) +
rtB . d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) - 1.0E-14 * rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [
5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) ) + rtB . mzfhfa0zkn
[ 1 ] * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [
4 ] ) * 0.00105769660249 ) + rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 4 ]
* muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * 0.00105769660249 ) +
5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin
( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) ) + 5.0E-15
* rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 *
rtB . d1pmn0ij1l [ 5 ] ) ) + 5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) ) + rtB
. mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * 0.0010576966027400002 ) - 5.0E-15 * rtB . mzfhfa0zkn [ 3
] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5
] + 2.0 * rtB . d1pmn0ij1l [ 4 ] ) ) - 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB
. mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 5 ] ) ) +
5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 * rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( 5.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn
[ 1 ] ) ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
1.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 1.0E-13 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) ) - muDoubleScalarSin ( ( ( - 2.0
* rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * ( 2.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 3 ] ) ) - muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) *
( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0
* rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.00013221207533 ) + muDoubleScalarSin ( ( (
2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.00013221207533 ) ) - ( ( muDoubleScalarSin
( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 * - 0.0066912000000000004 +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 9.81 * 0.01830136 ) + muDoubleScalarSin ( ( ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 9.81 * 0.0066912000000000004 ) ; B_0 [ 3 ] = ( ( rtDW
. h0luuex5q2 [ 3 ] == 1 ? rtP . torque_limits1_UpperSat [ 3 ] : rtDW .
h0luuex5q2 [ 3 ] == - 1 ? rtP . torque_limits1_LowerSat [ 3 ] : rtB .
nghlo5plg0 . p505mfvaxs [ 3 ] ) - ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarSin ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] +
2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 4.629561539999991E-6 +
muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * 0.0014218800000000001 ) +
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ]
) * 0.0014218800000000001 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0
] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.0014218800000000001 ) + muDoubleScalarCos
( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] *
rtB . mzfhfa0zkn [ 1 ] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( (
rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [
1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
0.0038890390000000004 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) *
0.0038890390000000004 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) *
0.0077780780000000008 ) - muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 3.0E-13 * rtB .
mzfhfa0zkn [ 0 ] ) * rtB . mzfhfa0zkn [ 3 ] ) - 0.0001217591948 *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * rtB . mzfhfa0zkn [ 5 ] * rtB .
mzfhfa0zkn [ 4 ] ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] *
rtB . mzfhfa0zkn [ 4 ] ) * - 0.0020141926698400005 ) + muDoubleScalarSin ( (
( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l
[ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 4 ] ) * 0.00052884830132 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 4 ]
) * 0.00052884830132000015 ) + muDoubleScalarSin ( ( ( ( - 2.0 * rtB .
d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - muDoubleScalarSin ( ( ( ( -
2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [
2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) + rtB . d1pmn0ij1l [ 4 ] ) * ( 5.0E-15 * rtB
. mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) - 1.0E-14 * rtB . mzfhfa0zkn
[ 1 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [
4 ] ) ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin
( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * 0.00105769660249 ) + rtB . mzfhfa0zkn [ 2
] * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ]
) * 0.00105769660249 ) + 5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn
[ 5 ] * muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) ) + 5.0E-15 * rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [
5 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 5 ] ) ) + 5.0E-15 * rtB .
mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) ) + rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 4 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * 0.0010576966027400002 )
- 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] *
muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + 2.0 * rtB . d1pmn0ij1l [
4 ] ) ) - 5.0E-15 * rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 5 ] ) ) + 5.0E-15 * rtB .
mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1
] ) * ( 5.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 1.0E-13 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) ) + muDoubleScalarSin ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * ( 1.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 3 ] ) ) - muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1
] ) * ( 2.0E-13 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) ) -
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 5 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ]
+ 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
- 0.00013221207533 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] +
2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * -
0.00013221207533 ) ) - ( ( muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * 9.81 * - 0.0066912000000000004 + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [
3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 * 0.01830136
) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 *
0.0066912000000000004 ) ; B_0 [ 4 ] = ( ( rtDW . h0luuex5q2 [ 4 ] == 1 ? rtP
. torque_limits1_UpperSat [ 4 ] : rtDW . h0luuex5q2 [ 4 ] == - 1 ? rtP .
torque_limits1_LowerSat [ 4 ] : rtB . nghlo5plg0 . p505mfvaxs [ 4 ] ) - ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.0014218800000000001 +
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ]
) * - 0.0014218800000000001 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.0014218800000000001 ) +
muDoubleScalarCos ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ]
) * - 0.0028437600000000003 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * ( rtB . mzfhfa0zkn [
1 ] * rtB . mzfhfa0zkn [ 1 ] ) * - 0.0028437600000000003 ) +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) *
0.00201419266994 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] *
rtB . mzfhfa0zkn [ 2 ] ) * 0.00201419266994 ) + muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * rtB
. mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] * 0.00201419266994 ) + rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * 0.0014586816 ) + rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 1 ] * muDoubleScalarCos ( - rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 1 ] ) * 0.0056875200000000006 ) + rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 1 ] * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 1 ] ) * - 0.0056875200000000006 ) + rtB . mzfhfa0zkn [ 2 ] * rtB
. mzfhfa0zkn [ 2 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * -
0.00052884830132 ) + rtB . mzfhfa0zkn [ 3 ] * rtB . mzfhfa0zkn [ 3 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830132 ) +
muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * - 0.00052884830131999993 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) * - 0.00052884830132 ) + muDoubleScalarSin (
( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] *
rtB . mzfhfa0zkn [ 2 ] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( 2.0
* rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [
2 ] ) * - 0.00052884830132 ) + muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l
[ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
0.00052884830132 ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) * -
0.00052884830131999993 ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + 1.0E-14 * rtB . mzfhfa0zkn [
0 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) ) - muDoubleScalarSin ( (
( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 1.0E-14 * rtB . mzfhfa0zkn
[ 0 ] * rtB . mzfhfa0zkn [ 5 ] ) ) + rtB . mzfhfa0zkn [ 1 ] * rtB .
mzfhfa0zkn [ 2 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * -
0.00105769660264 ) + rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 3 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00105769660264 ) +
0.0001217591948 * rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 5 ] *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) + rtB . mzfhfa0zkn [ 2 ] * rtB
. mzfhfa0zkn [ 3 ] * muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * -
0.00105769660264 ) + 0.0001217591948 * rtB . mzfhfa0zkn [ 2 ] * rtB .
mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) ) + 1.0E-14 *
rtB . mzfhfa0zkn [ 2 ] * rtB . mzfhfa0zkn [ 5 ] * muDoubleScalarSin ( - 2.0 *
rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [ 4 ] ) ) + 0.0001217591948 * rtB .
mzfhfa0zkn [ 5 ] * rtB . mzfhfa0zkn [ 3 ] * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) ) - 1.0E-14 * rtB . mzfhfa0zkn [ 5 ] * rtB . mzfhfa0zkn [
3 ] * muDoubleScalarSin ( - 2.0 * rtB . d1pmn0ij1l [ 5 ] + rtB . d1pmn0ij1l [
4 ] ) ) + muDoubleScalarSin ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB
. d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * ( rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) *
0.00013221207533 ) + rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] *
muDoubleScalarSin ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * 0.00026442415066 ) +
muDoubleScalarSin ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l
[ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * (
rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 0 ] ) * - 0.00013221207533 ) +
rtB . mzfhfa0zkn [ 1 ] * rtB . mzfhfa0zkn [ 1 ] * muDoubleScalarSin ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830131999993 ) ) - ( muDoubleScalarSin
( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l
[ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 * - 0.0066912000000000004 +
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 9.81 * -
0.0066912000000000004 ) ; B_0 [ 5 ] = ( rtDW . h0luuex5q2 [ 5 ] == 1 ? rtP .
torque_limits1_UpperSat [ 5 ] : rtDW . h0luuex5q2 [ 5 ] == - 1 ? rtP .
torque_limits1_LowerSat [ 5 ] : rtB . nghlo5plg0 . p505mfvaxs [ 5 ] ) - ( ( (
( ( ( ( ( ( ( muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * (
- 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) +
muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 1 ] ) ) - muDoubleScalarSin ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 2 ] ) ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) *
( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 2 ] ) ) -
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 0 ] * rtB . mzfhfa0zkn [ 3 ] ) ) + muDoubleScalarSin ( ( ( - rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB . mzfhfa0zkn [ 0 ] * rtB .
mzfhfa0zkn [ 3 ] ) ) - muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) *
( 6.08795974E-5 * rtB . mzfhfa0zkn [ 4 ] * rtB . mzfhfa0zkn [ 0 ] ) ) -
muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * ( 6.08795974E-5 * rtB .
mzfhfa0zkn [ 4 ] * rtB . mzfhfa0zkn [ 0 ] ) ) - 0.0001217591948 * rtB .
mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * rtB .
mzfhfa0zkn [ 3 ] ) - 0.0001217591948 * rtB . mzfhfa0zkn [ 4 ] *
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] ) * rtB . mzfhfa0zkn [ 1 ] ) -
0.0001217591948 * rtB . mzfhfa0zkn [ 4 ] * muDoubleScalarSin ( rtB .
d1pmn0ij1l [ 4 ] ) * rtB . mzfhfa0zkn [ 2 ] ) ; A [ 0 ] = ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 1
] ) * 0.41364213499999991 + muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) *
0.0029173632 ) + muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB
. d1pmn0ij1l [ 4 ] ) * - 1.6263032587282567E-19 ) + muDoubleScalarCos ( 2.0 *
rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * -
1.6263032587282567E-19 ) + muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 3 ] )
* - 4.3368086899420177E-19 ) + muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 1
] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) * 4.3368086899420177E-19 ) +
muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 3
] ) * 4.3368086899420177E-19 ) + muDoubleScalarCos ( ( ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [
2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * - 0.00013221207530500002 ) +
muDoubleScalarCos ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + 2.0 * rtB .
d1pmn0ij1l [ 3 ] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 1 ] ) * - 0.00013221207530500002 ) + muDoubleScalarCos ( 2.0 * rtB .
d1pmn0ij1l [ 4 ] ) * 0.00026442415060999971 ) + muDoubleScalarCos ( ( 2.0 *
rtB . d1pmn0ij1l [ 3 ] + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * - 4.6295616399996166E-6 ) + muDoubleScalarCos ( ( ( 2.0
* rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 4 ] ) + 2.0 * rtB . d1pmn0ij1l
[ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * 8.1315162936412833E-20 ) +
muDoubleScalarCos ( ( ( 2.0 * rtB . d1pmn0ij1l [ 3 ] + - rtB . d1pmn0ij1l [ 4
] ) + 2.0 * rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) *
8.1315162936412833E-20 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 3 ] + rtB
. d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) * - 0.007778078 ) +
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * -
0.007778078 ) + muDoubleScalarSin ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB . d1pmn0ij1l [ 1 ]
) * 0.0028437600000000003 ) + muDoubleScalarSin ( ( ( - rtB . d1pmn0ij1l [ 4
] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + 2.0 * rtB .
d1pmn0ij1l [ 1 ] ) * - 0.0028437600000000003 ) + muDoubleScalarSin ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) *
0.0028437600000000003 ) + muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * - 0.0028437600000000003
) + 0.57863617116011989 ) + muDoubleScalarCos ( ( 2.0 * rtB . d1pmn0ij1l [ 1
] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) * -
2.7105054312137611E-20 ) + muDoubleScalarCos ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ]
+ 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 4 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 4 ] ) * 2.7105054312137611E-20 ) + muDoubleScalarCos ( (
2.0 * rtB . d1pmn0ij1l [ 1 ] + 2.0 * rtB . d1pmn0ij1l [ 3 ] ) + rtB .
d1pmn0ij1l [ 4 ] ) * - 2.7105054312137611E-20 ) + muDoubleScalarCos ( 2.0 *
rtB . d1pmn0ij1l [ 2 ] + 2.0 * rtB . d1pmn0ij1l [ 1 ] ) *
0.022579986776000004 ) + muDoubleScalarCos ( ( 2.0 * rtB . d1pmn0ij1l [ 2 ] +
2.0 * rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 4 ] ) *
2.7105054312137611E-20 ) + muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 3 ] -
rtB . d1pmn0ij1l [ 4 ] ) * 2.7105054312137611E-20 ; A [ 6 ] = ( ( ( ( ( ( (
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 1 ] - 2.0 * rtB . d1pmn0ij1l [ 4 ]
) - rtB . d1pmn0ij1l [ 3 ] ) - rtB . d1pmn0ij1l [ 2 ] ) *
3.2526065174565133E-19 + muDoubleScalarCos ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1
] ) * - 0.00026442415060999971 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l
[ 1 ] ) * - 0.0007293408 ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 1 ] ) * 0.0028437600000000003 ) + muDoubleScalarSin ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ( - 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3
] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) *
0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * 0.0007293408 ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 1 ] ) *
0.267177491 ) + muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 0.00202230028 ; A [ 12 ] = (
( ( muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] )
+ rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408 +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 * rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( (
- rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * 0.0007293408 ) + muDoubleScalarCos ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * - 0.00026442415061000003 ; A [ 18 ] = ( ( (
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408 +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 * rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( (
- rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * 0.0007293408 ) + muDoubleScalarCos ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * - 0.00026442415061000003 ; A [ 24 ] = ( ( (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * - 0.00201419266993 + muDoubleScalarSin ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408 ) +
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408 ) +
muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * -
0.0028437600000000003 ; A [ 30 ] = muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l
[ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB .
d1pmn0ij1l [ 1 ] ) * - 6.08795974E-5 + muDoubleScalarCos ( ( ( rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 6.08795974E-5 ; A [ 1 ] = ( ( ( ( ( muDoubleScalarCos
( ( ( - ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) + rtB . d1pmn0ij1l [ 3 ] ) + rtB .
d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 0.00026442415061000003 + (
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 0.00202230028 + muDoubleScalarSin ( rtB . d1pmn0ij1l [
1 ] ) * 0.267177491 ) ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 1 ] ) * 0.0028437600000000003 ) + muDoubleScalarSin ( - rtB .
d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) * 0.0028437600000000003 ) +
muDoubleScalarCos ( ( ( 2.0 * rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ]
) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * -
0.00026442415061000003 ) + muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ]
) * 0.0007293408 ) + muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * -
0.0007293408 ; A [ 7 ] = ( ( ( muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ]
+ rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * -
0.0056875200000000006 + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] + rtB .
d1pmn0ij1l [ 2 ] ) * - 0.015556156000000002 ) + 0.88551842438821993 ) +
muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830122000006
) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * 0.0056875200000000006 ; A [ 13 ] = ( ( (
muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * - 0.0028437600000000003 + muDoubleScalarCos ( 2.0
* rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830122000006 ) + muDoubleScalarSin (
( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) * 0.0028437600000000003 ) + 0.049670834388219995 ) + muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * - 0.007778077999999999 ;
A [ 19 ] = ( ( ( muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * 0.0028437600000000003 +
muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830122000006
) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * -
0.007778077999999999 ) + muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * - 0.0028437600000000003 ) +
0.0029100855382200004 ; A [ 25 ] = muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [
4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) *
0.0028437600000000003 + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * 0.0028437600000000003 ; A [
31 ] = 0.0001217591948 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; A [ 2
] = ( ( ( muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [
3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408
+ muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * 0.00026442415061000003 ) + muDoubleScalarCos ( (
( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2
] ) + rtB . d1pmn0ij1l [ 1 ] ) * 0.0007293408 ) + muDoubleScalarCos ( ( ( 2.0
* rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.00026442415061000003 ; A [ 8 ] = ( ( (
muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * - 0.0028437600000000003 + muDoubleScalarCos ( 2.0
* rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830122000006 ) + muDoubleScalarSin (
rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) * - 0.0077780780000000008 )
+ 0.049670834388219995 ) + muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 4 ] + rtB
. d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * 0.0028437600000000003 ; A [
14 ] = muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * -
0.00052884830122000006 + 0.049670834388219995 ; A [ 20 ] = muDoubleScalarCos
( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830122000006 +
0.0029100855382200004 ; A [ 26 ] = 0.0 ; A [ 32 ] = 0.0001217591948 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; A [ 3 ] = ( ( (
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408 +
muDoubleScalarCos ( ( rtB . d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB
. d1pmn0ij1l [ 1 ] ) * 0.00202230028 ) + muDoubleScalarCos ( ( ( - 2.0 * rtB
. d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) +
rtB . d1pmn0ij1l [ 1 ] ) * 0.00026442415061000003 ) + muDoubleScalarCos ( ( (
- rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ]
) + rtB . d1pmn0ij1l [ 1 ] ) * 0.0007293408 ) + muDoubleScalarCos ( ( ( 2.0 *
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
+ rtB . d1pmn0ij1l [ 1 ] ) * - 0.00026442415061000003 ; A [ 9 ] = ( ( (
muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) * - 0.0028437600000000003 + muDoubleScalarSin ( (
rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] )
* 0.0028437600000000003 ) + muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 4 ]
) * - 0.00052884830122000006 ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 3 ] +
rtB . d1pmn0ij1l [ 2 ] ) * - 0.0077780780000000008 ) + 0.0029100855382200004
; A [ 15 ] = muDoubleScalarCos ( 2.0 * rtB . d1pmn0ij1l [ 4 ] ) * -
0.00052884830122000006 + 0.00291008553822 ; A [ 21 ] = muDoubleScalarCos (
2.0 * rtB . d1pmn0ij1l [ 4 ] ) * - 0.00052884830122000006 +
0.0029100855382200004 ; A [ 27 ] = 0.0 ; A [ 33 ] = 0.0001217591948 *
muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; A [ 4 ] = ( ( (
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 0.0007293408 +
muDoubleScalarSin ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 1 ] ) *
0.0028437600000000003 ) + muDoubleScalarSin ( rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 1 ] ) * - 0.0028437600000000003 ) + muDoubleScalarCos ( ( rtB .
d1pmn0ij1l [ 3 ] + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * -
0.00201419266994 ) + muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB .
d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * -
0.0007293408 ; A [ 10 ] = muDoubleScalarSin ( ( - rtB . d1pmn0ij1l [ 4 ] +
rtB . d1pmn0ij1l [ 3 ] ) + rtB . d1pmn0ij1l [ 2 ] ) * 0.0028437600000000003 +
muDoubleScalarSin ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) + rtB
. d1pmn0ij1l [ 2 ] ) * 0.0028437600000000003 ; A [ 16 ] = 0.0 ; A [ 22 ] =
0.0 ; A [ 28 ] = 0.00201419266993 ; A [ 34 ] = 0.0 ; A [ 5 ] =
muDoubleScalarCos ( ( ( - rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * - 6.08795974E-5 +
muDoubleScalarCos ( ( ( rtB . d1pmn0ij1l [ 4 ] + rtB . d1pmn0ij1l [ 3 ] ) +
rtB . d1pmn0ij1l [ 2 ] ) + rtB . d1pmn0ij1l [ 1 ] ) * 6.08795974E-5 ; A [ 11
] = 0.0001217591948 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; A [ 17 ]
= 0.0001217591948 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; A [ 23 ] =
0.0001217591948 * muDoubleScalarCos ( rtB . d1pmn0ij1l [ 4 ] ) ; A [ 29 ] =
0.0 ; A [ 35 ] = 0.0001217591948 ; for ( i = 0 ; i < 6 ; i ++ ) { ipiv [ i ]
= ( int8_T ) ( 1 + i ) ; } for ( j = 0 ; j < 5 ; j ++ ) { c = j * 7 ; c_c = 0
; ix = c ; scale = muDoubleScalarAbs ( A [ c ] ) ; for ( iy = 2 ; iy <= 6 - j
; iy ++ ) { ix ++ ; s = muDoubleScalarAbs ( A [ ix ] ) ; if ( s > scale ) {
c_c = iy - 1 ; scale = s ; } } if ( A [ c + c_c ] != 0.0 ) { if ( c_c != 0 )
{ ipiv [ j ] = ( int8_T ) ( ( j + c_c ) + 1 ) ; b_ix = j ; iy = j + c_c ; for
( jA = 0 ; jA < 6 ; jA ++ ) { scale = A [ b_ix ] ; A [ b_ix ] = A [ iy ] ; A
[ iy ] = scale ; b_ix += 6 ; iy += 6 ; } } ix = ( c - j ) + 6 ; for ( iy = c
+ 1 ; iy + 1 <= ix ; iy ++ ) { A [ iy ] /= A [ c ] ; } } jA = c ; ix = c + 6
; for ( i = 1 ; i <= 5 - j ; i ++ ) { scale = A [ ix ] ; if ( A [ ix ] != 0.0
) { iy = c + 1 ; b_ix = ( jA - j ) + 12 ; for ( ijA = 7 + jA ; ijA + 1 <=
b_ix ; ijA ++ ) { A [ ijA ] += A [ iy ] * - scale ; iy ++ ; } } ix += 6 ; jA
+= 6 ; } } for ( ix = 0 ; ix < 6 ; ix ++ ) { if ( ix + 1 != ipiv [ ix ] ) {
scale = B_0 [ ix ] ; B_0 [ ix ] = B_0 [ ipiv [ ix ] - 1 ] ; B_0 [ ipiv [ ix ]
- 1 ] = scale ; } } for ( ix = 0 ; ix < 6 ; ix ++ ) { c_c = 6 * ix ; if ( B_0
[ ix ] != 0.0 ) { for ( b_ix = ix + 2 ; b_ix < 7 ; b_ix ++ ) { B_0 [ b_ix - 1
] -= A [ ( b_ix + c_c ) - 1 ] * B_0 [ ix ] ; } } } for ( iy = 5 ; iy >= 0 ;
iy += - 1 ) { jA = 6 * iy ; if ( B_0 [ iy ] != 0.0 ) { B_0 [ iy ] /= A [ iy +
jA ] ; for ( ix = 0 ; ix + 1 <= iy ; ix ++ ) { B_0 [ ix ] -= A [ ix + jA ] *
B_0 [ iy ] ; } } } for ( i = 0 ; i < 6 ; i ++ ) { rtB . ibtz24ephg [ i ] =
B_0 [ i ] ; } if ( ssIsMajorTimeStep ( rtS ) ) { for ( i = 0 ; i < 6 ; i ++ )
{ rtDW . itd1vtaubg [ i ] = rtB . ibtz24ephg [ i ] >= rtP .
acc_limits1_UpperSat [ i ] ? 1 : rtB . ibtz24ephg [ i ] > rtP .
acc_limits1_LowerSat [ i ] ? 0 : - 1 ; } } for ( i = 0 ; i < 6 ; i ++ ) { rtB
. hlydmluflh [ i ] = rtDW . itd1vtaubg [ i ] == 1 ? rtP .
acc_limits1_UpperSat [ i ] : rtDW . itd1vtaubg [ i ] == - 1 ? rtP .
acc_limits1_LowerSat [ i ] : rtB . ibtz24ephg [ i ] ; } { real_T *
pDataValues = ( real_T * ) rtDW . oyg0xcbkq2 . DataPtr ; real_T * pTimeValues
= ( real_T * ) rtDW . oyg0xcbkq2 . TimePtr ; int_T currTimeIndex = rtDW .
abooqdppeu . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >=
pTimeValues [ 1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . ki1c4j2kes [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ;
pDataValues += 1312 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . oyg0xcbkq2 . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . abooqdppeu . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T elIdx ; for (
elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . ki1c4j2kes [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; } } } else { {
int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . ki1c4j2kes
[ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ; pDataValues +=
numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 =
1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { d1 = pDataValues [
TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( & rtB . ki1c4j2kes [ 0 ]
) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } } } } scale = 2.2250738585072014E-308 ; s =
muDoubleScalarAbs ( rtB . ki1c4j2kes [ 3 ] ) ; if ( s >
2.2250738585072014E-308 ) { theta = 1.0 ; scale = s ; } else { t = s /
2.2250738585072014E-308 ; theta = t * t ; } s = muDoubleScalarAbs ( rtB .
ki1c4j2kes [ 4 ] ) ; if ( s > scale ) { t = scale / s ; theta = theta * t * t
+ 1.0 ; scale = s ; } else { t = s / scale ; theta += t * t ; } s =
muDoubleScalarAbs ( rtB . ki1c4j2kes [ 5 ] ) ; if ( s > scale ) { t = scale /
s ; theta = theta * t * t + 1.0 ; scale = s ; } else { t = s / scale ; theta
+= t * t ; } theta = scale * muDoubleScalarSqrt ( theta ) ; rtB . at3pokyun0
[ 0 ] = rtB . ki1c4j2kes [ 3 ] / theta ; rtB . at3pokyun0 [ 1 ] = rtB .
ki1c4j2kes [ 4 ] / theta ; rtB . at3pokyun0 [ 2 ] = rtB . ki1c4j2kes [ 5 ] /
theta ; rtB . eziy2ljh0e = theta ; x = muDoubleScalarCos ( rtB . eziy2ljh0e )
; s = muDoubleScalarSin ( rtB . eziy2ljh0e ) ; scale = muDoubleScalarCos (
rtB . eziy2ljh0e ) ; rtB . loh4vtrrkc [ 0 ] = rtB . at3pokyun0 [ 0 ] * rtB .
at3pokyun0 [ 0 ] * ( 1.0 - x ) + scale ; rtB . loh4vtrrkc [ 3 ] = rtB .
at3pokyun0 [ 0 ] * rtB . at3pokyun0 [ 1 ] * ( 1.0 - x ) - rtB . at3pokyun0 [
2 ] * s ; rtB . loh4vtrrkc [ 6 ] = rtB . at3pokyun0 [ 0 ] * rtB . at3pokyun0
[ 2 ] * ( 1.0 - x ) + rtB . at3pokyun0 [ 1 ] * s ; rtB . loh4vtrrkc [ 1 ] =
rtB . at3pokyun0 [ 0 ] * rtB . at3pokyun0 [ 1 ] * ( 1.0 - x ) + rtB .
at3pokyun0 [ 2 ] * s ; rtB . loh4vtrrkc [ 4 ] = rtB . at3pokyun0 [ 1 ] * rtB
. at3pokyun0 [ 1 ] * ( 1.0 - x ) + scale ; rtB . loh4vtrrkc [ 7 ] = rtB .
at3pokyun0 [ 1 ] * rtB . at3pokyun0 [ 2 ] * ( 1.0 - x ) - rtB . at3pokyun0 [
0 ] * s ; rtB . loh4vtrrkc [ 2 ] = rtB . at3pokyun0 [ 0 ] * rtB . at3pokyun0
[ 2 ] * ( 1.0 - x ) - rtB . at3pokyun0 [ 1 ] * s ; rtB . loh4vtrrkc [ 5 ] =
rtB . at3pokyun0 [ 1 ] * rtB . at3pokyun0 [ 2 ] * ( 1.0 - x ) + rtB .
at3pokyun0 [ 0 ] * s ; rtB . loh4vtrrkc [ 8 ] = rtB . at3pokyun0 [ 2 ] * rtB
. at3pokyun0 [ 2 ] * ( 1.0 - x ) + scale ; { real_T * pDataValues = ( real_T
* ) rtDW . meb1ohukzh . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
meb1ohukzh . TimePtr ; int_T currTimeIndex = rtDW . bl25evyz1e . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 1311 ] ) { {
int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . ibhm4qsbtk
[ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ; } } } else {
int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
meb1ohukzh . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . bl25evyz1e .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB .
ibhm4qsbtk [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues +=
numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . ibhm4qsbtk [ 0 ] ) [ elIdx ] = pDataValues [
currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 = (
t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ]
; ( & rtB . ibhm4qsbtk [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2
, f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues =
( real_T * ) rtDW . kgedcln4ib . DataPtr ; real_T * pTimeValues = ( real_T *
) rtDW . kgedcln4ib . TimePtr ; int_T currTimeIndex = rtDW . ofgbpzna2m .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [
1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB
. ew2txbl40n [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ;
} } } else { int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo
* ) rtDW . kgedcln4ib . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints
; lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex =
0 ; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint
- 1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
ofgbpzna2m . PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx
) { ( & rtB . ew2txbl40n [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ;
pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 6 ; ++ elIdx ) { ( & rtB . ew2txbl40n [ 0 ] ) [ elIdx ] = pDataValues
[ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 =
( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ;
int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6
; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ( & rtB . ew2txbl40n [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate (
d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T *
pDataValues = ( real_T * ) rtDW . di0rqa2hxr . DataPtr ; real_T * pTimeValues
= ( real_T * ) rtDW . di0rqa2hxr . TimePtr ; int_T currTimeIndex = rtDW .
nuog3ppeov . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >=
pTimeValues [ 1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . ll04tin3ej [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ;
pDataValues += 1312 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . di0rqa2hxr . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . nuog3ppeov . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T elIdx ; for (
elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . ll04tin3ej [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; } } } else { {
int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . ll04tin3ej
[ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ; pDataValues +=
numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 =
1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { d1 = pDataValues [
TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( & rtB . ll04tin3ej [ 0 ]
) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } } } } { real_T * pDataValues = ( real_T * ) rtDW .
ftfrxtmkht . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . ftfrxtmkht
. TimePtr ; int_T currTimeIndex = rtDW . mis12p4hji . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 1311 ] ) { { int_T elIdx
; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & rtB . on2ccbefn1 [ 0 ] ) [
elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
ftfrxtmkht . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . mis12p4hji .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & rtB .
on2ccbefn1 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues +=
numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & rtB . on2ccbefn1 [ 0 ] ) [ elIdx ] = pDataValues [
currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 = (
t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ]
; ( & rtB . on2ccbefn1 [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2
, f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues =
( real_T * ) rtDW . gz4yk0vbeq . DataPtr ; real_T * pTimeValues = ( real_T *
) rtDW . gz4yk0vbeq . TimePtr ; int_T currTimeIndex = rtDW . pnfgom0ma5 .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [
1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB
. fumx0wqu0p [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ;
} } } else { int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo
* ) rtDW . gz4yk0vbeq . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints
; lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex =
0 ; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint
- 1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
pnfgom0ma5 . PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx
) { ( & rtB . fumx0wqu0p [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ;
pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 6 ; ++ elIdx ) { ( & rtB . fumx0wqu0p [ 0 ] ) [ elIdx ] = pDataValues
[ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 =
( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ;
int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6
; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ( & rtB . fumx0wqu0p [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate (
d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T *
pDataValues = ( real_T * ) rtDW . afqqfcyfky . DataPtr ; real_T * pTimeValues
= ( real_T * ) rtDW . afqqfcyfky . TimePtr ; int_T currTimeIndex = rtDW .
jehbknbywz . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >=
pTimeValues [ 1311 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . oxqjrfhajt [ 0 ] ) [ elIdx ] = pDataValues [ 1311 ] ;
pDataValues += 1312 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . afqqfcyfky . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . jehbknbywz . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T elIdx ; for (
elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . oxqjrfhajt [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; } } } else { {
int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . oxqjrfhajt
[ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ; pDataValues +=
numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 =
1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { d1 = pDataValues [
TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( & rtB . oxqjrfhajt [ 0 ]
) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } } } } { real_T * pDataValues = ( real_T * ) rtDW .
j3lsycmps3 . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . j3lsycmps3
. TimePtr ; int_T currTimeIndex = rtDW . mohuhbx5xb . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 1311 ] ) { { int_T elIdx
; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB . en2yguwqwb [ 0 ] ) [
elIdx ] = pDataValues [ 1311 ] ; pDataValues += 1312 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
j3lsycmps3 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . mohuhbx5xb .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++ elIdx ) { ( & rtB .
en2yguwqwb [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues +=
numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { ( & rtB . en2yguwqwb [ 0 ] ) [ elIdx ] = pDataValues [
currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else { real_T f1 = (
t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 6 ; ++
elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ]
; ( & rtB . en2yguwqwb [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2
, f1 , f2 ) ; pDataValues += numPoints ; } } } } } } UNUSED_PARAMETER ( tid )
; } void MdlUpdate ( int_T tid ) { { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; { int_T i1 ; const real_T * u0 = rtB . mzfhfa0zkn ; int_T
* mode = & rtDW . mh2ebmwctw [ 0 ] ; real_T * xc = & rtX . oh2bsf3aw5 [ 0 ] ;
const real_T * p_Integrator3_UpperSat = rtP . Integrator3_UpperSat ; const
real_T * p_Integrator3_LowerSat = rtP . Integrator3_LowerSat ; for ( i1 = 0 ;
i1 < 6 ; i1 ++ ) { if ( xc [ i1 ] == p_Integrator3_UpperSat [ i1 ] ) { switch
( mode [ i1 ] ) { case INTG_UPPER_SAT : if ( u0 [ i1 ] < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; mode [ i1 ] = INTG_LEAVING_UPPER_SAT ; }
break ; case INTG_LEAVING_UPPER_SAT : if ( u0 [ i1 ] >= 0.0 ) { mode [ i1 ] =
INTG_UPPER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ; default :
ssSetSolverNeedsReset ( rtS ) ; if ( u0 [ i1 ] < 0.0 ) { mode [ i1 ] =
INTG_LEAVING_UPPER_SAT ; } else { mode [ i1 ] = INTG_UPPER_SAT ; } break ; }
} else if ( xc [ i1 ] == p_Integrator3_LowerSat [ i1 ] ) { switch ( mode [ i1
] ) { case INTG_LOWER_SAT : if ( u0 [ i1 ] > 0.0 ) { ssSetSolverNeedsReset (
rtS ) ; mode [ i1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( u0 [ i1 ] <= 0.0 ) { mode [ i1 ] =
INTG_LOWER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ; default :
ssSetSolverNeedsReset ( rtS ) ; if ( u0 [ i1 ] > 0.0 ) { mode [ i1 ] =
INTG_LEAVING_LOWER_SAT ; } else { mode [ i1 ] = INTG_LOWER_SAT ; } break ; }
} else { mode [ i1 ] = INTG_NORMAL ; } } } } { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; { int_T i1 ; const real_T * u0 = rtB . hlydmluflh ; int_T
* mode = & rtDW . om4jx250hy [ 0 ] ; real_T * xc = & rtX . eym24ufl0b [ 0 ] ;
const real_T * p_Integrator2_UpperSat = rtP . Integrator2_UpperSat ; const
real_T * p_Integrator2_LowerSat = rtP . Integrator2_LowerSat ; for ( i1 = 0 ;
i1 < 6 ; i1 ++ ) { if ( xc [ i1 ] == p_Integrator2_UpperSat [ i1 ] ) { switch
( mode [ i1 ] ) { case INTG_UPPER_SAT : if ( u0 [ i1 ] < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; mode [ i1 ] = INTG_LEAVING_UPPER_SAT ; }
break ; case INTG_LEAVING_UPPER_SAT : if ( u0 [ i1 ] >= 0.0 ) { mode [ i1 ] =
INTG_UPPER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ; default :
ssSetSolverNeedsReset ( rtS ) ; if ( u0 [ i1 ] < 0.0 ) { mode [ i1 ] =
INTG_LEAVING_UPPER_SAT ; } else { mode [ i1 ] = INTG_UPPER_SAT ; } break ; }
} else if ( xc [ i1 ] == p_Integrator2_LowerSat [ i1 ] ) { switch ( mode [ i1
] ) { case INTG_LOWER_SAT : if ( u0 [ i1 ] > 0.0 ) { ssSetSolverNeedsReset (
rtS ) ; mode [ i1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( u0 [ i1 ] <= 0.0 ) { mode [ i1 ] =
INTG_LOWER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ; default :
ssSetSolverNeedsReset ( rtS ) ; if ( u0 [ i1 ] > 0.0 ) { mode [ i1 ] =
INTG_LEAVING_LOWER_SAT ; } else { mode [ i1 ] = INTG_LOWER_SAT ; } break ; }
} else { mode [ i1 ] = INTG_NORMAL ; } } } } { real_T timeStampA = rtDW .
hifeqprlqm . TimeStampA ; real_T timeStampB = rtDW . hifeqprlqm . TimeStampB
; real_T * lastTime = & rtDW . hifeqprlqm . TimeStampA ; real_T * lastU = &
rtDW . hifeqprlqm . LastUAtTimeA [ 0 ] ; if ( timeStampA != rtInf ) { if (
timeStampB == rtInf ) { lastTime = & rtDW . hifeqprlqm . TimeStampB ; lastU =
& rtDW . hifeqprlqm . LastUAtTimeB [ 0 ] ; } else if ( timeStampA >=
timeStampB ) { lastTime = & rtDW . hifeqprlqm . TimeStampB ; lastU = & rtDW .
hifeqprlqm . LastUAtTimeB [ 0 ] ; } } * lastTime = ssGetTaskTime ( rtS , 0 )
; { int_T i1 ; const real_T * u0 = rtB . lysn5dtfor ; for ( i1 = 0 ; i1 < 36
; i1 ++ ) { * lastU ++ = u0 [ i1 ] ; } } } { real_T timeStampA = rtDW .
bqyz2wxpe2 . TimeStampA ; real_T timeStampB = rtDW . bqyz2wxpe2 . TimeStampB
; real_T * lastTime = & rtDW . bqyz2wxpe2 . TimeStampA ; real_T * lastU = &
rtDW . bqyz2wxpe2 . LastUAtTimeA [ 0 ] ; if ( timeStampA != rtInf ) { if (
timeStampB == rtInf ) { lastTime = & rtDW . bqyz2wxpe2 . TimeStampB ; lastU =
& rtDW . bqyz2wxpe2 . LastUAtTimeB [ 0 ] ; } else if ( timeStampA >=
timeStampB ) { lastTime = & rtDW . bqyz2wxpe2 . TimeStampB ; lastU = & rtDW .
bqyz2wxpe2 . LastUAtTimeB [ 0 ] ; } } * lastTime = ssGetTaskTime ( rtS , 0 )
; { int_T i1 ; const real_T * u0 = rtB . mzfhfa0zkn ; for ( i1 = 0 ; i1 < 6 ;
i1 ++ ) { * lastU ++ = u0 [ i1 ] ; } } } UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; { int_T i1 ;
const real_T * u0 = rtB . mzfhfa0zkn ; int_T * mode = & rtDW . mh2ebmwctw [ 0
] ; real_T * xdot = & ( ( XDot * ) ssGetdX ( rtS ) ) -> oh2bsf3aw5 [ 0 ] ;
boolean_T * xdis = & ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
oh2bsf3aw5 [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( ( mode [ i1 ] !=
INTG_UPPER_SAT ) && ( mode [ i1 ] != INTG_LOWER_SAT ) ) { xdot [ i1 ] = u0 [
i1 ] ; xdis [ i1 ] = FALSE ; } else { xdot [ i1 ] = 0.0 ; if ( ( mode [ i1 ]
== INTG_UPPER_SAT ) || ( mode [ i1 ] == INTG_LOWER_SAT ) ) { xdis [ i1 ] =
TRUE ; } } } } } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; { int_T i1 ;
const real_T * u0 = rtB . hlydmluflh ; int_T * mode = & rtDW . om4jx250hy [ 0
] ; real_T * xdot = & ( ( XDot * ) ssGetdX ( rtS ) ) -> eym24ufl0b [ 0 ] ;
boolean_T * xdis = & ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
eym24ufl0b [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( ( mode [ i1 ] !=
INTG_UPPER_SAT ) && ( mode [ i1 ] != INTG_LOWER_SAT ) ) { xdot [ i1 ] = u0 [
i1 ] ; xdis [ i1 ] = FALSE ; } else { xdot [ i1 ] = 0.0 ; if ( ( mode [ i1 ]
== INTG_UPPER_SAT ) || ( mode [ i1 ] == INTG_LOWER_SAT ) ) { xdis [ i1 ] =
TRUE ; } } } } } } void MdlProjection ( void ) { } void MdlZeroCrossings (
void ) { int32_T i ; ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; { int_T i1 ; real_T * zcsv0 = & ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> barjk4hla1 [ 0 ] ; real_T * zcsv1 = &
( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> ccd1n420az [ 0 ] ; real_T
* xc = & rtX . oh2bsf3aw5 [ 0 ] ; const real_T * p_Integrator3_UpperSat = rtP
. Integrator3_UpperSat ; const real_T * p_Integrator3_LowerSat = rtP .
Integrator3_LowerSat ; int_T * mode = & rtDW . mh2ebmwctw [ 0 ] ; for ( i1 =
0 ; i1 < 6 ; i1 ++ ) { if ( mode [ i1 ] == INTG_LEAVING_UPPER_SAT && xc [ i1
] >= p_Integrator3_UpperSat [ i1 ] ) { zcsv0 [ i1 ] = 0.0 ; } else { zcsv0 [
i1 ] = xc [ i1 ] - p_Integrator3_UpperSat [ i1 ] ; } if ( mode [ i1 ] ==
INTG_LEAVING_LOWER_SAT && xc [ i1 ] <= p_Integrator3_LowerSat [ i1 ] ) {
zcsv1 [ i1 ] = 0.0 ; } else { zcsv1 [ i1 ] = xc [ i1 ] -
p_Integrator3_LowerSat [ i1 ] ; } } } { { int_T i1 ; const real_T * u0 = rtB
. mzfhfa0zkn ; real_T * zcsv2 = & ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS
) ) -> gkokqkqsys [ 0 ] ; int_T * mode = & rtDW . mh2ebmwctw [ 0 ] ; for ( i1
= 0 ; i1 < 6 ; i1 ++ ) { if ( ( mode [ i1 ] == INTG_UPPER_SAT ) || ( mode [
i1 ] == INTG_LOWER_SAT ) ) { zcsv2 [ i1 ] = u0 [ i1 ] ; } else { zcsv2 [ i1 ]
= 0.0 ; } } } } } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; { int_T i1 ;
real_T * zcsv0 = & ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ->
ebnnvryhem [ 0 ] ; real_T * zcsv1 = & ( ( ZCV * ) ssGetSolverZcSignalVector (
rtS ) ) -> ftli25xlsi [ 0 ] ; real_T * xc = & rtX . eym24ufl0b [ 0 ] ; const
real_T * p_Integrator2_UpperSat = rtP . Integrator2_UpperSat ; const real_T *
p_Integrator2_LowerSat = rtP . Integrator2_LowerSat ; int_T * mode = & rtDW .
om4jx250hy [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( mode [ i1 ] ==
INTG_LEAVING_UPPER_SAT && xc [ i1 ] >= p_Integrator2_UpperSat [ i1 ] ) {
zcsv0 [ i1 ] = 0.0 ; } else { zcsv0 [ i1 ] = xc [ i1 ] -
p_Integrator2_UpperSat [ i1 ] ; } if ( mode [ i1 ] == INTG_LEAVING_LOWER_SAT
&& xc [ i1 ] <= p_Integrator2_LowerSat [ i1 ] ) { zcsv1 [ i1 ] = 0.0 ; } else
{ zcsv1 [ i1 ] = xc [ i1 ] - p_Integrator2_LowerSat [ i1 ] ; } } } { { int_T
i1 ; const real_T * u0 = rtB . hlydmluflh ; real_T * zcsv2 = & ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> azcjmsbiwi [ 0 ] ; int_T * mode = &
rtDW . om4jx250hy [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( ( mode [ i1
] == INTG_UPPER_SAT ) || ( mode [ i1 ] == INTG_LOWER_SAT ) ) { zcsv2 [ i1 ] =
u0 [ i1 ] ; } else { zcsv2 [ i1 ] = 0.0 ; } } } } } for ( i = 0 ; i < 6 ; i
++ ) { _rtZCSV -> orbk4xiljm [ i ] = rtB . nghlo5plg0 . p505mfvaxs [ i ] -
rtP . torque_limits1_UpperSat [ i ] ; _rtZCSV -> dzeixerbua [ i ] = rtB .
nghlo5plg0 . p505mfvaxs [ i ] - rtP . torque_limits1_LowerSat [ i ] ; _rtZCSV
-> ideoc3ef2t [ i ] = rtB . ibtz24ephg [ i ] - rtP . acc_limits1_UpperSat [ i
] ; _rtZCSV -> e5por3dzyk [ i ] = rtB . ibtz24ephg [ i ] - rtP .
acc_limits1_LowerSat [ i ] ; } } void MdlTerminate ( void ) { rt_FREE ( rtDW
. njjuawiwjd . RSimInfoPtr ) ; rt_FREE ( rtDW . jpryus4wqu . RSimInfoPtr ) ;
rt_FREE ( rtDW . fanbrdsnik . RSimInfoPtr ) ; rt_FREE ( rtDW . oyg0xcbkq2 .
RSimInfoPtr ) ; rt_FREE ( rtDW . meb1ohukzh . RSimInfoPtr ) ; rt_FREE ( rtDW
. kgedcln4ib . RSimInfoPtr ) ; rt_FREE ( rtDW . di0rqa2hxr . RSimInfoPtr ) ;
rt_FREE ( rtDW . ftfrxtmkht . RSimInfoPtr ) ; rt_FREE ( rtDW . gz4yk0vbeq .
RSimInfoPtr ) ; rt_FREE ( rtDW . afqqfcyfky . RSimInfoPtr ) ; rt_FREE ( rtDW
. j3lsycmps3 . RSimInfoPtr ) ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 12 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ;
ssSetNumBlocks ( rtS , 87 ) ; ssSetNumBlockIO ( rtS , 42 ) ;
ssSetNumBlockParams ( rtS , 97223 ) ; } void MdlInitializeSampleTimes ( void
) { ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
1879348162U ) ; ssSetChecksumVal ( rtS , 1 , 1180972568U ) ; ssSetChecksumVal
( rtS , 2 , 621690654U ) ; ssSetChecksumVal ( rtS , 3 , 3739316111U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = (
real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * )
x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . B = &
rtBTransTable ; dtInfo . P = & rtPTransTable ; } ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"JointSpaceControl" ) ; ssSetPath ( rtS , "JointSpaceControl" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 30.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { {
static int_T rt_LoggedStateWidths [ ] = { 6 , 6 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 6 , 6 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"JointSpaceControl/Robot UR5\nM, C, g/Integrator3" ,
"JointSpaceControl/Robot UR5\nM, C, g/Integrator2" } ; static const char_T *
rt_LoggedStateNames [ ] = { "position" , "velocity" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . oh2bsf3aw5 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . eym24ufl0b [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetSigLog ( ssGetRTWLogInfo ( rtS
) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 12
] ; static real_T absTol [ 12 ] = { 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 ,
1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 } ;
static uint8_T absTolControl [ 12 ] = { 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U
, 2U , 2U , 2U , 2U } ; static uint8_T zcAttributes [ 60 ] = { (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP )
, ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; ssSetSolverRelTol (
rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.008 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver (
rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 60 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 60 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1879348162U ) ; ssSetChecksumVal ( rtS , 1 ,
1180972568U ) ; ssSetChecksumVal ( rtS , 2 , 621690654U ) ; ssSetChecksumVal
( rtS , 3 , 3739316111U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 24 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
