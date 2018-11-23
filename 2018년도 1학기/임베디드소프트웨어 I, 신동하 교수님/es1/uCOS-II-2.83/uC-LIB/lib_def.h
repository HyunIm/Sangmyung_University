/*
*********************************************************************************************************
*                                               uC/LIB
*                                       CUSTOM LIBRARY MODULES
*
*                          (c) Copyright 2004-2006; Micrium, Inc.; Weston, FL
*
*                   All rights reserved.  Protected by international copyright laws.
*                   Knowledge of the source code may not be used to write a similar
*                   product.  This file may only be used in accordance with a license
*                   and should not be redistributed in any way.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                          STANDARD DEFINES
*
* Filename      : lib_def.h
* Version       : V1.21
* Programmer(s) : ITJ
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  LIB_DEF_MODULE_PRESENT
#define  LIB_DEF_MODULE_PRESENT


/*$PAGE*/
/*
*********************************************************************************************************
*                                          STANDARD DEFINES
*********************************************************************************************************
*/


#define  DEF_DISABLED                                      0
#define  DEF_ENABLED                                       1

#define  DEF_FALSE                                         0
#define  DEF_TRUE                                          1

#define  DEF_NO                                            0
#define  DEF_YES                                           1

#define  DEF_OFF                                           0
#define  DEF_ON                                            1

#define  DEF_ACTIVE                                        0
#define  DEF_INACTIVE                                      1

#define  DEF_FAIL                                          0
#define  DEF_OK                                            1


                                                                /* -------------------- BIT DEFINES ------------------- */
#define  DEF_BIT_NONE                                   0x00

#define  DEF_BIT_00                                     0x01
#define  DEF_BIT_01                                     0x02
#define  DEF_BIT_02                                     0x04
#define  DEF_BIT_03                                     0x08
#define  DEF_BIT_04                                     0x10
#define  DEF_BIT_05                                     0x20
#define  DEF_BIT_06                                     0x40
#define  DEF_BIT_07                                     0x80

#define  DEF_BIT_08                                   0x0100
#define  DEF_BIT_09                                   0x0200
#define  DEF_BIT_10                                   0x0400
#define  DEF_BIT_11                                   0x0800
#define  DEF_BIT_12                                   0x1000
#define  DEF_BIT_13                                   0x2000
#define  DEF_BIT_14                                   0x4000
#define  DEF_BIT_15                                   0x8000

#define  DEF_BIT_16                               0x00010000
#define  DEF_BIT_17                               0x00020000
#define  DEF_BIT_18                               0x00040000
#define  DEF_BIT_19                               0x00080000
#define  DEF_BIT_20                               0x00100000
#define  DEF_BIT_21                               0x00200000
#define  DEF_BIT_22                               0x00400000
#define  DEF_BIT_23                               0x00800000

#define  DEF_BIT_24                               0x01000000
#define  DEF_BIT_25                               0x02000000
#define  DEF_BIT_26                               0x04000000
#define  DEF_BIT_27                               0x08000000
#define  DEF_BIT_28                               0x10000000
#define  DEF_BIT_29                               0x20000000
#define  DEF_BIT_30                               0x40000000
#define  DEF_BIT_31                               0x80000000

                                                                /* ------------------- OCTET DEFINES ------------------ */
#define  DEF_OCTET_NBR_BITS                                8
#define  DEF_OCTET_MASK                                 0xFF

#define  DEF_NIBBLE_NBR_BITS                               4
#define  DEF_NIBBLE_MASK                                0x0F


/*$PAGE*/
                                                                /* ------------------ INTEGER DEFINES ----------------- */
#define  DEF_INT_08_NBR_BITS                               8
#define  DEF_INT_08_MASK                                0xFF
                                                            
#define  DEF_INT_08U_MIN_VAL                               0u
#define  DEF_INT_08U_MAX_VAL                             255u

#define  DEF_INT_08S_MIN_VAL                            -128
#define  DEF_INT_08S_MAX_VAL                             127

#define  DEF_INT_08S_MIN_VAL_ONES_CPL                   -127
#define  DEF_INT_08S_MAX_VAL_ONES_CPL                    127


#define  DEF_INT_16_NBR_BITS                              16
#define  DEF_INT_16_MASK                              0xFFFF
                                                            
#define  DEF_INT_16U_MIN_VAL                               0u
#define  DEF_INT_16U_MAX_VAL                           65535u

#define  DEF_INT_16S_MIN_VAL                          -32768
#define  DEF_INT_16S_MAX_VAL                           32767

#define  DEF_INT_16S_MIN_VAL_ONES_CPL                 -32767
#define  DEF_INT_16S_MAX_VAL_ONES_CPL                  32767


#define  DEF_INT_32_NBR_BITS                              32
#define  DEF_INT_32_MASK                          0xFFFFFFFF
                                                            
#define  DEF_INT_32U_MIN_VAL                               0u
#define  DEF_INT_32U_MAX_VAL                      4294967295u 

#define  DEF_INT_32S_MIN_VAL                     -2147483648
#define  DEF_INT_32S_MAX_VAL                      2147483647

#define  DEF_INT_32S_MIN_VAL_ONES_CPL            -2147483647
#define  DEF_INT_32S_MAX_VAL_ONES_CPL             2147483647


#define  DEF_INT_64_NBR_BITS                              64
#define  DEF_INT_64_MASK                  0xFFFFFFFFFFFFFFFF
                                                            
#define  DEF_INT_64U_MIN_VAL                               0u
#define  DEF_INT_64U_MAX_VAL            18446744073709551615u 

#define  DEF_INT_64S_MIN_VAL            -9223372036854775808
#define  DEF_INT_64S_MAX_VAL             9223372036854775807

#define  DEF_INT_64S_MIN_VAL_ONES_CPL   -9223372036854775807
#define  DEF_INT_64S_MAX_VAL_ONES_CPL    9223372036854775807



                                                                /* ------------------- TIME DEFINES ------------------- */
#define  DEF_TIME_NBR_HR_PER_DAY                          24uL

#define  DEF_TIME_NBR_MIN_PER_HR                          60uL
#define  DEF_TIME_NBR_MIN_PER_DAY                       (DEF_TIME_NBR_MIN_PER_HR  * DEF_TIME_NBR_HR_PER_DAY)

#define  DEF_TIME_NBR_SEC_PER_MIN                         60uL
#define  DEF_TIME_NBR_SEC_PER_HR                        (DEF_TIME_NBR_SEC_PER_MIN * DEF_TIME_NBR_MIN_PER_HR)
#define  DEF_TIME_NBR_SEC_PER_DAY                       (DEF_TIME_NBR_SEC_PER_HR  * DEF_TIME_NBR_HR_PER_DAY)

#define  DEF_TIME_NBR_mS_PER_SEC                        1000uL
#define  DEF_TIME_NBR_uS_PER_SEC                     1000000uL
#define  DEF_TIME_NBR_nS_PER_SEC                  1000000000uL


/*$PAGE*/
/*
*********************************************************************************************************
*                                             BIT MACRO'S
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              DEF_BIT()
*
* Description : Create bit mask with single, specified bit set.
*
* Argument(s) : bit         Bit number of bit to set.
*
* Return(s)   : Bit mask with single, specified bit set.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT(bit)       (1 << (bit))


/*$PAGE*/
/*
*********************************************************************************************************
*                                           DEF_BIT_MASK()
*
* Description : Shift a bit mask.
*
* Argument(s) : bit_mask    Bit mask to shift.
*
*               bit_shift   Number of bit positions to left-shift bit mask.
*
* Return(s)   : Shifted bit mask.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_MASK(bit_mask, bit_shift)              ((bit_mask)       << (bit_shift))


/*
*********************************************************************************************************
*                                           DEF_BIT_FIELD()
*
* Description : Create & shift a contiguous bit field.
*
* Argument(s) : bit_field   Number of contiguous bits to set in the bit field.
*
*               bit_shift   Number of bit positions to left-shift bit field.
*
* Return(s)   : Shifted bit field.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_FIELD(bit_field, bit_shift)    ((DEF_BIT(bit_field) - 1) << (bit_shift))


/*$PAGE*/
/*
*********************************************************************************************************
*                                            DEF_BIT_SET()
*
* Description : Set specified bit(s) in a value.
*
* Argument(s) : val         Value to modify by setting specified bit(s).
*
*               mask        Mask of bits to set.
*
* Return(s)   : Modified value with specified bit(s) set.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_SET(val, mask)                 {(val) |=  (mask);}


/*
*********************************************************************************************************
*                                            DEF_BIT_CLR()
*
* Description : Clear specified bit(s) in a value.
*
* Argument(s) : val         Value to modify by clearing specified bit(s).
*
*               mask        Mask of bits to clear.
*
* Return(s)   : Modified value with specified bit(s) clear.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_CLR(val, mask)                 {(val) &= ~(mask);}


/*$PAGE*/
/*
*********************************************************************************************************
*                                          DEF_BIT_IS_SET()
*
* Description : Determine if specified bit(s) in a value are set.
*
* Argument(s) : val         Value to check for specified bit(s) set.
*
*               mask        Mask of bits to check if set.
*
* Return(s)   : DEF_YES, if ALL specified bit(s) are     set in value.
*     
*               DEF_NO,	 if ALL specified bit(s) are NOT set in value.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_IS_SET(val, mask)              ((((val) & (mask)) == (mask)) ? (DEF_YES) : (DEF_NO ))


/*
*********************************************************************************************************
*                                          DEF_BIT_IS_CLR()
*
* Description : Determine if specified bit(s) in a value are clear.
*
* Argument(s) : val         Value to check for specified bit(s) clear.
*
*               mask        Mask of bits to check if clear.
*
* Return(s)   : DEF_YES, if ALL specified bit(s) are     clear in value.
*     
*               DEF_NO,	 if ALL specified bit(s) are NOT clear in value.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_IS_CLR(val, mask)               (((val) & (mask))            ? (DEF_NO ) : (DEF_YES))


/*$PAGE*/
/*
*********************************************************************************************************
*                                        DEF_BIT_IS_SET_ANY()
*
* Description : Determine if any specified bit(s) in a value are set.
*
* Argument(s) : val         Value to check for specified bit(s) set.
*
*               mask        Mask of bits to check if set.
*
* Return(s)   : DEF_YES, if ANY specified bit(s) are     set in value.
*     
*               DEF_NO,	 if ALL specified bit(s) are NOT set in value.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_IS_SET_ANY(val, mask)           (((val) & (mask))            ? (DEF_YES) : (DEF_NO ))


/*
*********************************************************************************************************
*                                        DEF_BIT_IS_CLR_ANY()
*
* Description : Determine if any specified bit(s) in a value are clear.
*
* Argument(s) : val         Value to check for specified bit(s) clear.
*
*               mask        Mask of bits to check if clear.
*
* Return(s)   : DEF_YES, if ANY specified bit(s) are     clear in value.
*     
*               DEF_NO,	 if ALL specified bit(s) are NOT clear in value.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_BIT_IS_CLR_ANY(val, mask)          ((((val) & (mask)) != (mask)) ? (DEF_YES) : (DEF_NO ))


/*$PAGE*/
/*
*********************************************************************************************************
*                                            MATH MACRO'S
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              DEF_MIN()
*
* Description : Determine the minimum of two values.
*
* Argument(s) : a           First  value.
*
*               b           Second value.
*
* Return(s)   : Minimum of the two values.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_MIN(a, b)      (((a) < (b)) ? (a) : (b))


/*
*********************************************************************************************************
*                                              DEF_MAX()
*
* Description : Determine the maximum of two values.
*
* Argument(s) : a           First  value.
*
*               b           Second value.
*
* Return(s)   : Maximum of the two values.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_MAX(a, b)      (((a) > (b)) ? (a) : (b))


/*$PAGE*/
/*
*********************************************************************************************************
*                                              DEF_ABS()
*
* Description : Determine the absolute value of a value.
*
* Argument(s) : a           Value to calculate absolute value.
*
* Return(s)   : Absolute value of the value.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#define  DEF_ABS(a)         (((a) < 0) ? (-(a)) : (a))


/*$PAGE*/
/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of lib def module inclusion.                     */

