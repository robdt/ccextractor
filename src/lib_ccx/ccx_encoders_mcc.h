#ifndef _CCEXTRACTOR_CCX_ENCODERS_MCC_H
#define _CCEXTRACTOR_CCX_ENCODERS_MCC_H

#include "ccx_common_platform.h"
#include "ccx_common_common.h"
#include "ccx_encoders_common.h"

/*----------------------------------------------------------------------------*/
/*--                               Constants                                --*/
/*----------------------------------------------------------------------------*/

// --- MCC Encode Related Constants

#define ANC_DID_CLOSED_CAPTIONING        0x61
#define ANC_SDID_CEA_708                 0x01
#define CDP_IDENTIFIER_VALUE_HIGH        0x96
#define CDP_IDENTIFIER_VALUE_LOW         0x69
#define CC_DATA_ID                       0x72
#define CDP_FOOTER_ID                    0x74

#define CDP_FRAME_RATE_FORBIDDEN         0x00
#define CDP_FRAME_RATE_23_976            0x01
#define CDP_FRAME_RATE_24                0x02
#define CDP_FRAME_RATE_25                0x03
#define CDP_FRAME_RATE_29_97             0x04
#define CDP_FRAME_RATE_30                0x05
#define CDP_FRAME_RATE_50                0x06
#define CDP_FRAME_RATE_59_94             0x07
#define CDP_FRAME_RATE_60                0x08

// --- Caption Decode Related Constants

#define CEA608E_LINE21_FIELD_1_CC        0x00
#define CEA608E_LINE21_FIELD_2_CC        0x01
#define DTVCCC_CHANNEL_PACKET_DATA       0x02
#define DTVCCC_CHANNEL_PACKET_START      0x03

#define CC_CONSTR_CC_VALID_FLAG_MASK     0x04
#define CC_CONSTR_CC_VALID_FLAG_SET      0x04
#define CC_CONSTR_CC_TYPE_MASK           0x03

#define LINE_21_PARITY_MASK              0x7F

#define GLOBAL_CTRL_CODE_CC1             0x14
#define GLOBAL_CTRL_CODE_CC2             0x1C
#define GLOBAL_CTRL_CODE_CC3             0x15
#define GLOBAL_CTRL_CODE_CC4             0x1D
#define GLOBAL_CTRL_CMD_MASK             0x2F

#define CMD_MIDROW_BG_CHAN_1_3           0x10
#define CMD_MIDROW_FG_CHAN_1_3           0x11
#define CMD_MIDROW_BG_CHAN_2_4           0x18
#define CMD_MIDROW_FG_CHAN_2_4           0x19
#define MIDROW_CODE_MASK                 0x2F

#define CMD_TAB_HI_CC_1_3                0x17
#define CMD_TAB_HI_CC_2_4                0x1F
#define TAB_CMD_MASK                     0x23

#define PAC_CC1_MASK                     0x1F

#define SPCL_NA_CHAR_SET_CH_1_3          0x11
#define SPCL_NA_CHAR_SET_CH_2_4          0x19
#define SPCL_NA_CHAR_SET_MASK            0x3F

#define EXT_W_EURO_CHAR_SET_CH_1_3_SF    0x12
#define EXT_W_EURO_CHAR_SET_CH_1_3_FG    0x13
#define EXT_W_EURO_CHAR_SET_CH_2_4_SF    0x1A
#define EXT_W_EURO_CHAR_SET_CH_2_4_FG    0x1B
#define EXT_W_EURO_CHAR_SET_MASK         0x3F

#define NULL_BASIC_CHAR                  0x00
#define FIRST_BASIC_CHAR                 0x20
#define LAST_BASIC_CHAR                  0x7F

#define DTVCC_MAX_PACKET_LENGTH           128
#define PACKET_LENGTH_MASK               0x3F

#define SERVICE_NUMBER_MASK              0xE0
#define SERVICE_NUMBER_SHIFT                5
#define SERVICE_BLOCK_SIZE_MASK          0x1F

#define EXTENDED_SRV_NUM_PATTERN         0x07
#define EXTENDED_SRV_NUM_MASK            0x3F

#define LENGTH_UNKNOWN                     -1

#define DTVCC_C0_EXT1                    0x10

#define DTVCC_MIN_G0_CODE                0x20
#define DTVCC_MAX_G0_CODE                0x7F

#define DTVCC_MIN_C0_CODE                0x00
#define DTVCC_MAX_C0_CODE                0x1F

#define DTVCC_C1_CW0                     0x80
#define DTVCC_C1_CW1                     0x81
#define DTVCC_C1_CW2                     0x82
#define DTVCC_C1_CW3                     0x83
#define DTVCC_C1_CW4                     0x84
#define DTVCC_C1_CW5                     0x85
#define DTVCC_C1_CW6                     0x86
#define DTVCC_C1_CW7                     0x87
#define DTVCC_C1_CLW                     0x88
#define DTVCC_C1_DSW                     0x89
#define DTVCC_C1_HDW                     0x8A
#define DTVCC_C1_TGW                     0x8B
#define DTVCC_C1_DLW                     0x8C
#define DTVCC_C1_DLY                     0x8D
#define DTVCC_C1_DLC                     0x8E
#define DTVCC_C1_RST                     0x8F
#define DTVCC_C1_SPA                     0x90
#define DTVCC_C1_SPC                     0x91
#define DTVCC_C1_SPL                     0x92
#define DTVCC_C1_RSV93                   0x93
#define DTVCC_C1_RSV94                   0x94
#define DTVCC_C1_RSV95                   0x95
#define DTVCC_C1_RSV96                   0x96
#define DTVCC_C1_SWA                     0x97
#define DTVCC_C1_DF0                     0x98
#define DTVCC_C1_DF1                     0x99
#define DTVCC_C1_DF2                     0x9A
#define DTVCC_C1_DF3                     0x9B
#define DTVCC_C1_DF4                     0x9C
#define DTVCC_C1_DF5                     0x9D
#define DTVCC_C1_DF6                     0x9E
#define DTVCC_C1_DF7                     0x9F

#define DTVCC_MIN_C1_CODE                0x80
#define DTVCC_MAX_C1_CODE                0x9F

/*----------------------------------------------------------------------------*/
/*--                                Types                                   --*/
/*----------------------------------------------------------------------------*/

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef long long int64;

/*----------------------------------------------------------------------------*/
/*--                              Structures                                --*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*--                                Macros                                  --*/
/*----------------------------------------------------------------------------*/

#define LOG(...) debug_log(__FILE__, __LINE__, __VA_ARGS__)
#define ASSERT(x) if(!(x)) debug_log(__FILE__, __LINE__, "ASSERT FAILED!")

/*----------------------------------------------------------------------------*/
/*--                          Exposed Variables                             --*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*--                          Exposed Functions                             --*/
/*----------------------------------------------------------------------------*/

boolean mcc_encode_cc_data(struct encoder_ctx *ctx, struct lib_cc_decode *dec_ctx, unsigned char *cc_data, int cc_count);

#endif // _CCEXTRACTOR_CCX_ENCODERS_MCC_H
