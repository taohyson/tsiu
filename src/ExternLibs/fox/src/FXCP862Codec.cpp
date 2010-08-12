#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXHash.h"
#include "FXStream.h"
#include "FXTextCodec.h"
#include "FXCP862Codec.h"

namespace FX {

FXIMPLEMENT(FXCP862Codec,FXTextCodec,NULL,0)


//// Created by codec tool on 03/25/2005 from: CP862.TXT ////
static const unsigned short forward_data[256]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503,
   1504, 1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512, 1513, 1514, 162,  163,  165,  8359, 402,
   225,  237,  243,  250,  241,  209,  170,  186,  191,  8976, 172,  189,  188,  161,  171,  187,
   9617, 9618, 9619, 9474, 9508, 9569, 9570, 9558, 9557, 9571, 9553, 9559, 9565, 9564, 9563, 9488,
   9492, 9524, 9516, 9500, 9472, 9532, 9566, 9567, 9562, 9556, 9577, 9574, 9568, 9552, 9580, 9575,
   9576, 9572, 9573, 9561, 9560, 9554, 9555, 9579, 9578, 9496, 9484, 9608, 9604, 9612, 9616, 9600,
   945,  223,  915,  960,  931,  963,  181,  964,  934,  920,  937,  948,  8734, 966,  949,  8745,
   8801, 177,  8805, 8804, 8992, 8993, 247,  8776, 176,  8729, 183,  8730, 8319, 178,  9632, 160,
  };


static const unsigned char reverse_plane[17]={
  0, 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
  };

static const unsigned char reverse_pages[74]={
  0,  61, 92, 92, 92, 92, 92, 92, 149,200,92, 92, 92, 92, 92, 92,
  92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92,
  92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92,
  92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92,
  92, 92, 92, 92, 92, 92, 92, 92, 92, 92,
  };

static const unsigned short reverse_block[264]={
  0,   16,  32,  48,  64,  80,  96,  112, 128, 128, 144, 160, 128, 176, 192, 207,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 221, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 234, 247, 262, 278, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 294, 310, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 321, 128, 128, 337,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 345, 360, 128, 370, 128, 385, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 401, 417, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 433, 449, 462, 475, 128, 491, 507, 128,
  523, 539, 555, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128,
  };

static const unsigned char reverse_data[571]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   255,  173,  155,  156,  26,   157,  26,   26,   26,   26,   166,  174,  170,  26,   26,   26,
   248,  241,  253,  26,   26,   230,  26,   250,  26,   26,   167,  175,  172,  171,  26,   168,
   26,   165,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   225,
   26,   160,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   161,  26,   26,
   164,  26,   162,  26,   26,   26,   246,  26,   26,   163,  26,   26,   26,   26,   26,   159,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   226,  26,   26,
   26,   26,   233,  26,   26,   26,   26,   26,   26,   26,   228,  26,   26,   232,  26,   26,
   234,  26,   26,   26,   26,   26,   26,   224,  26,   26,   235,  238,  26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   227,  26,   26,   229,  231,  26,   237,  26,   26,   26,
   26,   26,   26,   26,   26,   26,   128,  129,  130,  131,  132,  133,  134,  135,  136,  137,
   138,  139,  140,  141,  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,
   154,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   252,  26,   26,   26,   26,   26,   26,   26,   158,  26,   26,   26,   26,   26,   26,   26,
   26,   26,   249,  251,  26,   26,   26,   236,  26,   26,   26,   26,   26,   26,   26,   26,
   26,   239,  26,   26,   26,   26,   26,   26,   26,   26,   247,  26,   26,   26,   26,   26,
   26,   26,   240,  26,   26,   243,  242,  26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   169,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   244,  245,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   196,  26,   179,  26,   26,   26,   26,   26,   26,   26,   26,   26,   218,  26,   26,
   26,   191,  26,   26,   26,   192,  26,   26,   26,   217,  26,   26,   26,   195,  26,   26,
   26,   26,   180,  26,   26,   26,   26,   26,   26,   26,   194,  26,   26,   26,   26,   193,
   26,   26,   26,   26,   26,   26,   26,   197,  26,   26,   26,   205,  186,  213,  214,  201,
   184,  183,  187,  212,  211,  200,  190,  189,  188,  198,  199,  204,  181,  182,  185,  209,
   210,  203,  207,  208,  202,  216,  215,  206,  26,   26,   26,   223,  26,   26,   26,   220,
   26,   26,   26,   219,  26,   26,   26,   221,  26,   26,   26,   222,  176,  177,  178,  26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   254,  26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
  };


FXint FXCP862Codec::mb2wc(FXwchar& wc,const FXchar* src,FXint nsrc) const {
  if(nsrc<1) return -1;
  wc=forward_data[(FXuchar)src[0]];
  return 1;
  }


FXint FXCP862Codec::wc2mb(FXchar* dst,FXint ndst,FXwchar wc) const {
  if(ndst<1) return -1;
  dst[0]=reverse_data[reverse_block[reverse_pages[reverse_plane[wc>>16]+((wc>>10)&63)]+((wc>>4)&63)]+(wc&15)];
  return 1;
  }

FXint FXCP862Codec::mibEnum() const {
  return 2013;
  }


const FXchar* FXCP862Codec::name() const {
  return "IBM862";
  }


const FXchar* FXCP862Codec::mimeName() const {
  return "IBM862";
  }


const FXchar* const* FXCP862Codec::aliases() const {
  static const FXchar *const list[]={"microsoft-cp862","IBM862","cp862","862","csPC862LatinHebrew",NULL};
  return list;
  }

}

