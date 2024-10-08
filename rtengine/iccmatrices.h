/*
 *  This file is part of RawTherapee.
 *
 *  Copyright (c) 2004-2010 Gabor Horvath <hgabor@rawtherapee.com>
 *
 *  RawTherapee is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RawTherapee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RawTherapee.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

// Bradford transform between illuminants
constexpr double d65_d50[3][3] =  {
    {0.9555766, -0.0230393,  0.0631636},
    { -0.0282895,  1.0099416,  0.0210077},
    {0.0122982, -0.0204830,  1.3299098}
};

constexpr double d50_d65[3][3] =  {
    { 1.0478112,  0.0228866, -0.0501270},
    {0.0295424,  0.9904844, -0.0170491},
    { -0.0092345,  0.0150436,  0.7521316}
};

//J.Desmis 04 2018
constexpr double d50_d60[3][3] =  {
    { 1.034368,  0.016908, -0.037658},
    {0.021752,  0.992183, -0.012785},
    { -0.006971,  0.011377,  0.812150}
};

constexpr double d60_d50[3][3] =  {
    { 0.96743198, -0.01699717, 0.044590689},
    {-0.02109893, 1.008067172, 0.014890785},
    {0.008598998, -0.01426777, 1.231474467}
};

// Color space conversion to/from XYZ; color spaces adapted to D65
constexpr double xyz_sRGBd65[3][3] = {
    {0.4124564,  0.3575761,  0.1804375},
    {0.2126729,  0.7151522,  0.0721750},   // WARNING: the summ of this line is > 1.0
    {0.0193339,  0.1191920,  0.9503041}
};

constexpr double sRGBd65_xyz[3][3] = {
    { 3.2404542, -1.5371385, -0.4985314},
    { -0.9692660,  1.8760108,  0.0415560},
    {0.0556434, -0.2040259,  1.0572252}
};

//%%%%%%%%%%%%%%%%%%%%%%%%
//    TEST using Gabor's matrices
/*constexpr double xyz_sRGB[3][3] = {
    {0.435859,   0.385336, 0.143023},
    {0.222385,   0.717021,  0.0605936 },
    {0.0139162,   0.0971389,  0.713817}};

constexpr double sRGB_xyz[3][3] = {
    {3.13593293538656,        -1.61878246026431,        -0.490913888760734},
    {-0.978702373022194,        1.91609508555177,        0.0334453372795315},
    {0.0720490013929888,       -0.22919049060526,       1.40593851447263}};*/
//%%%%%%%%%%%%%%%%%%%%%%%%


// Color space conversion to/from XYZ; color spaces adapted to D50 using Bradford transform
constexpr double xyz_sRGB[3][3] = {
    {0.4360747,  0.3850649, 0.1430804},
    {0.2225045,  0.7168786,  0.0606169},
    {0.0139322,  0.0971045,  0.7141733}
};

constexpr double xyz_ACESp0[3][3] = {
    {0.9908526, 0.0122334, -0.0388654},
    {0.3618807, 0.72255045  , -0.0843859},
    {-0.0027093, 0.0082323, 0.8196880}
};

constexpr double ACESp0_xyz[3][3] = {
    {1.01583320, -0.01772807, 0.04634052},
    {-0.50781231, 1.39131494  , 0.11915641},
    {0.00845768,  -0.01403193, 1.21893277}
};

constexpr double xyz_jdcmax[3][3] = {//prim red 0.734702 0.265302 gr 0.021908 0.930288 bl 0.120593 0.001583
    {0.8394088, 0.0163780, 0.1084133},
    {0.3031122, 0.6954651, 0.0014227},
    {-0.000048, 0.0357376, 0.7891671}
    
/*    
    {0.878152, -0.035991, 0.122039},//stdA
    {0.293869, 0.682893, 0.023238},
    {0.020725, 0.025411, 0.778763}
*/  
/*  
     {0.831816, 0.041363, 0.091021},//D80
    {0.307370, 0.714525, -0.021895},
    {-0.004335, 0.039442, 0.789793}
 */  
};

constexpr double xyz_jdcmaxstdA[3][3] = {//prim red 0.734702 0.265302 gr 0.021908 0.930288 bl 0.120593 0.001583
       
    {0.878152, -0.035991, 0.122039},//stdA
    {0.293869, 0.682893, 0.023238},
    {0.020725, 0.025411, 0.778763}  
};

constexpr double jdcmaxstdA_xyz[3][3] = {
    
     {1.1209647, 0.06568858, -0.177625},//stdA
    {-0.481904, 1.437746, 0.03261678},
    {-0.0141074,  -0.0486617, 1.28775}
      
};

constexpr double jdcmax_xyz[3][3] = {
    {1.1984508, -0.0197646, -0.1646037},
    {-0.5223824, 1.4466349, 0.0691553},
    {0.0236634,  -0.0655113, 1.2640260}
    
    /*
     {1.1209647, 0.06568858, -0.177625},//stdA
    {-0.481904, 1.437746, 0.03261678},
    {-0.0141074,  -0.0486617, 1.28775}
    */
    /*
     {1.2247276, -0.0630103, -0.142892},//D80
    {-0.525835, 1.424446, 0.100089},
    {0.032982,  -0.0714782, 1.260371}
    */
  
};


constexpr double xyz_ACESp1[3][3] = {
    {0.689697, 0.149944, 0.124559},
    {0.284448, 0.671758  , 0.043794},
    {-0.006043, 0.009998, 0.820945}
};

constexpr double ACESp1_xyz[3][3] = {
    {1.5932624, -0.352316, -0.222945},
    {-0.6759496, 1.639286  , 0.01511026},
    {0.0199602,  -0.0225577, 1.2162833}
};


constexpr double sRGB_xyz[3][3] = {
    {3.1338561, -1.6168667, -0.4906146},
    { -0.9787684,  1.9161415,  0.0334540},
    {0.0719453, -0.2289914,  1.4052427}
};

constexpr double xyz_adobe[3][3] =    {
    {0.6097559,  0.2052401,  0.1492240},
    {0.3111242,  0.6256560,  0.0632197},
    {0.0194811,  0.0608902,  0.7448387}
};

constexpr double adobe_xyz[3][3] =    {
    {1.9624274, -0.6105343, -0.3413404},
    { -0.9787684,  1.9161415,  0.0334540},
    {0.0286869, -0.1406752,  1.3487655}
};

constexpr double xyz_prophoto[3][3] = {
    {0.7976749,  0.1351917,  0.0313534},
    {0.2880402,  0.7118741,  0.0000857},
    {0.0000000,  0.0000000,  0.8252100}
};

constexpr double prophoto_xyz[3][3] = {
    {1.3459433, -0.2556075, -0.0511118},
    { -0.5445989,  1.5081673,  0.0205351},
    {0.0000000,  0.0000000,  1.2118128}
};
/*
constexpr double xyz_rec2020[3][3] = {
    {0.636958,  0.144617,  0.168881},
    {0.262700,  0.677998,  0.059302},
    {0.0000000,  0.028073, 1.060985}
};

constexpr double rec2020_xyz[3][3] = {
    {1.716651, -0.355671, -0.253366},
    { -0.666684,  1.616481,  0.015769},
    {0.017640, -0.042771, 0.942103}
};
*/
constexpr double xyz_rec2020[3][3] = {
    {0.6734241,  0.1656411,  0.1251286},
    {0.2790177,  0.6753402,  0.0456377},
    { -0.0019300,  0.0299784, 0.7973330}
};

constexpr double rec2020_xyz[3][3] = {
    {1.6473376, -0.3935675, -0.2359961},
    { -0.6826036,  1.6475887,  0.0128190},
    {0.0296524, -0.0628993, 1.2531279}
};

constexpr double xyz_widegamut[3][3] = {
    {0.7161046,  0.1009296,  0.1471858},
    {0.2581874,  0.7249378,  0.0168748},
    {0.0000000,  0.0517813,  0.7734287}
};

constexpr double widegamut_xyz[3][3] = {
    { 1.4628067, -0.1840623, -0.2743606},
    { -0.5217933,  1.4472381,  0.0677227},
    {0.0349342, -0.0968930,  1.2884099}
};

constexpr double xyz_bruce[3][3] = {
    {0.4941816,  0.3204834,  0.1495550},
    {0.2521531,  0.6844869,  0.0633600},
    {0.0157886,  0.0629304,  0.7464909}
};

constexpr double bruce_xyz[3][3] = {
    {2.6502856, -1.2014485, -0.4289936},
    { -0.9787684,  1.9161415,  0.0334540},
    {0.0264570, -0.1361227,  1.3458542}
};

constexpr double xyz_beta[3][3] = {
    {0.6712537,  0.1745834,  0.1183829},
    {0.3032726,  0.6637861,  0.0329413},
    {0.0000000,  0.0407010,  0.7845090}
};

constexpr double beta_xyz[3][3] = {
    {1.6832270, -0.4282363, -0.2360185},
    { -0.7710229,  1.7065571,  0.0446900},
    {0.0400013, -0.0885376,  1.2723640}
};

constexpr double xyz_best[3][3] = {
    {0.6326696,  0.2045558,  0.1269946},
    {0.2284569,  0.7373523,  0.0341908},
    {0.0000000,  0.0095142,  0.8156958}
};

constexpr double best_xyz[3][3] = {
    {1.7552599, -0.4836786, -0.2530000},
    { -0.5441336,  1.5068789,  0.0215528},
    {0.0063467, -0.0175761,  1.2256959}
};


/*
constexpr double sRGB_d50[3][3] = {
    {0.4360520246092,  0.2224915978656,    0.0139291219896},
    {0.38508159282,    0.716886060114,     0.09709700166},
    {0.1430874138552,  0.0606214863936,    0.714185469944}
};

constexpr double d50_sRGB[3][3] = {
    {3.13405134405167,-0.978762729953942,  0.0719425766617001},
    {-1.61702771153574,1.91614222810656,  -0.228971178679309},
    {-0.49065220876631,0.0334496273068589, 1.40521830559074}
};
*/

/*
// Gabor's matrices
constexpr double sRGB_d50[3][3] = {
    {0.435859,   0.222385,   0.0139162},
    {0.385336,   0.717021,   0.0971389},
    {0.143023,   0.0605936,  0.713817}
};

constexpr double d50_sRGB[3][3] = {
    {3.13593293538656,        -0.978702373022194,        0.0720490013929888},
    {-1.61878246026431,        1.91609508555177,        -0.22919049060526},
    {-0.490913888760734,       0.0334453372795315,       1.40593851447263}
};

constexpr double adobe_d50[3][3] = {
    {0.6097395054954,  0.3111142944042,    0.0194773131652},
    {0.2052518325737,  0.6256618480686,    0.0608872306106},
    {0.1492308013399,  0.0632241329247,    0.744846530711}
};
constexpr double d50_adobe[3][3] = {
    {1.9624959949628,  -0.978762712052774,  0.0286904764959749},
    {-0.610587687828765,1.91614073756734,  -0.140667763143042},
    {-0.34136021627766, 0.0334501217627688, 1.34875045144924}
};
constexpr double prophoto_d50[3][3] = {
    {0.797675, 0.288040,   0.000000},
    {0.135192, 0.711874,   0.000000},
    {0.0313534,0.000086,   0.825210}
};
constexpr double d50_prophoto[3][3] = {
    {1.34594335079331,    -0.544598514291158,  0},
    {-0.255608118122657,   1.50816768465213,   0},
    {-0.0511117387775285,  0.0205345459181255, 1.21181275069376}
};
constexpr double widegamut_d50[3][3] = {
    {0.716105,  0.258187,   0.000000},
    {0.100930,  0.724938,   0.0517813},
    {0.147186,  0.0168748,  0.773429}
};
constexpr double d50_widegamut[3][3] = {
    {1.46280597103052,  -0.521792197260068, 0.0349341417298585},
    {-0.184062984909417, 1.44723786022891, -0.0968930022172314},
    {-0.27436071519732,  0.0677226440980744,1.28840945122198}
};
constexpr double bruce_d50[3][3] = {
    {0.4941607255908,   0.2521412970174,    0.0157852934504},
    {0.3204990468435,   0.684494580042,     0.062927176507},
    {0.1495612990809,   0.0633643619597,    0.746498914581}
};
constexpr double d50_bruce[3][3] = {
    {2.65042308164152, -0.978762745761462,  0.0264609493245811},
    {-1.20155941925411, 1.9161402914007,   -0.136115844662896},
    {-0.42902228923717, 0.0334495071197919, 1.34583900936772}
};
constexpr double beta_d50[3][3] = {
    {0.671254,   0.303273,   0.000000},
    {0.174583,   0.663786,   0.040701},
    {0.118383,   0.0329413,  0.784509}
};
constexpr double d50_beta[3][3] = {
    {1.68322591962771,   -0.771023599950842, 0.0400013658754702},
    {-0.428235060337656,  1.70655704781303, -0.0885376438040078},
    {-0.236018598193503,  0.0446902191738489,1.27236406897742}
};
constexpr double best_d50[3][3] = {
    {0.632670,   0.228457,   0.000000},
    {0.204556,   0.737352,   0.00951424},
    {0.126995,   0.0341908,  0.815696}
};
constexpr double d50_best[3][3] = {
    {1.75525923340349,   -0.544133953997468, 0.00634675299435191},
    {-0.483679025800866,  1.50687975713407, -0.017576175021718},
    {-0.253000840399762,  0.0215532098817316,1.22569552576991}
};
 */
