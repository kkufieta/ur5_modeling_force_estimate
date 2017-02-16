#include "__cf_JointSpaceControl.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . blnxm0qljw
[ 0 ] ) , 0 , 0 , 322 } , { ( char_T * ) ( & rtB . lddm5yrsqq . p505mfvaxs [
0 ] ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtB . mvghmhsjz4 . c3phy4uy3g [ 0 ]
) , 0 , 0 , 48 } , { ( char_T * ) ( & rtB . nghlo5plg0 . p505mfvaxs [ 0 ] ) ,
0 , 0 , 6 } , { ( char_T * ) ( & rtB . okpo04efs2 . c3phy4uy3g [ 0 ] ) , 0 ,
0 , 48 } , { ( char_T * ) ( & rtDW . hifeqprlqm . TimeStampA ) , 0 , 0 , 2 }
, { ( char_T * ) ( & rtDW . k132invbs3 . LoggedData ) , 11 , 0 , 29 } , { (
char_T * ) ( & rtDW . htkw22hmrn . PrevIndex ) , 10 , 0 , 35 } } ; static
DataTypeTransitionTable rtBTransTable = { 8U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
Constant_Value [ 0 ] ) , 0 , 0 , 97223 } } ; static DataTypeTransitionTable
rtPTransTable = { 1U , rtPTransitions } ;
