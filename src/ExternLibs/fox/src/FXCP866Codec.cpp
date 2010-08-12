#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXHash.h"
#include "FXStream.h"
#include "FXTextCodec.h"
#include "FXCP866Codec.h"

namespace FX {

FXIMPLEMENT(FXCP866Codec,FXTextCodec,NULL,0)


//// Created by codec tool on 03/25/2005 from: CP866.TXT ////
static const unsigned short forward_data[256]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055,
   1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071,
   1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
   9617, 9618, 9619, 9474, 9508, 9569, 9570, 9558, 9557, 9571, 9553, 9559, 9565, 9564, 9563, 9488,
   9492, 9524, 9516, 9500, 9472, 9532, 9566, 9567, 9562, 9556, 9577, 9574, 9568, 9552, 9580, 9575,
   9576, 9572, 9573, 9561, 9560, 9554, 9555, 9579, 9578, 9496, 9484, 9608, 9604, 9612, 9616, 9600,
   1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103,
   1025, 1105, 1028, 1108, 1031, 1111, 1038, 1118, 176,  8729, 183,  8730, 8470, 164,  9632, 160,
  };


static const unsigned char reverse_plane[17]={
  0, 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
  };

static const unsigned char reverse_pages[74]={
  0,  64, 70, 70, 70, 70, 70, 70, 117,165,70, 70, 70, 70, 70, 70,
  70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
  70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
  70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
  70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
  };

static const unsigned short reverse_block[229]={
  0,   16,  32,  48,  64,  80,  96,  112, 128, 128, 144, 160, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  175, 191, 207, 223, 239, 255, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 270, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 277, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 293, 309, 322, 335, 128, 351, 367, 128, 383, 399, 415,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128,
  };

static const unsigned char reverse_data[431]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   255,  26,   26,   26,   253,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   248,  26,   26,   26,   26,   26,   26,   250,  26,   26,   26,   26,   26,   26,   26,   26,
   240,  26,   26,   242,  26,   26,   244,  26,   26,   26,   26,   26,   26,   246,  26,   128,
   129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,  144,
   145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,
   161,  162,  163,  164,  165,  166,  167,  168,  169,  170,  171,  172,  173,  174,  175,  224,
   225,  226,  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  26,
   241,  26,   26,   243,  26,   26,   245,  26,   26,   26,   26,   26,   26,   247,  26,   26,
   26,   26,   26,   26,   252,  26,   26,   26,   26,   26,   26,   26,   26,   26,   249,  251,
   26,   26,   26,   26,   26,   196,  26,   179,  26,   26,   26,   26,   26,   26,   26,   26,
   26,   218,  26,   26,   26,   191,  26,   26,   26,   192,  26,   26,   26,   217,  26,   26,
   26,   195,  26,   26,   26,   26,   180,  26,   26,   26,   26,   26,   26,   26,   194,  26,
   26,   26,   26,   193,  26,   26,   26,   26,   26,   26,   26,   197,  26,   26,   26,   205,
   186,  213,  214,  201,  184,  183,  187,  212,  211,  200,  190,  189,  188,  198,  199,  204,
   181,  182,  185,  209,  210,  203,  207,  208,  202,  216,  215,  206,  26,   26,   26,   223,
   26,   26,   26,   220,  26,   26,   26,   219,  26,   26,   26,   221,  26,   26,   26,   222,
   176,  177,  178,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   254,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
  };


FXint FXCP866Codec::mb2wc(FXwchar& wc,const FXchar* src,FXint nsrc) const {
  if(nsrc<1) return -1;
  wc=forward_data[(FXuchar)src[0]];
  return 1;
  }


FXint FXCP866Codec::wc2mb(FXchar* dst,FXint ndst,FXwchar wc) const {
  if(ndst<1) return -1;
  dst[0]=reverse_data[reverse_block[reverse_pages[reverse_plane[wc>>16]+((wc>>10)&63)]+((wc>>4)&63)]+(wc&15)];
  return 1;
  }

FXint FXCP866Codec::mibEnum() const {
  return 2086;
  }


const FXchar* FXCP866Codec::name() const {
  return "IBM866";
  }


const FXchar* FXCP866Codec::mimeName() const {
  return "IBM866";
  }


const FXchar* const* FXCP866Codec::aliases() const {
  static const FXchar *const list[]={"microsoft-cp866","IBM866","cp866","866","csIBM866",NULL};
  return list;
  }

}

