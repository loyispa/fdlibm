#include "testconfig.h"
#ifdef HAVE_SINCOS
#define TEST_FUNC_F_FF __MATH_PRECNAME(sincos)
#include "testdriver.h"



static test_f_ff_data const fsincos_data[] = {
	{ __LINE__, ZERO_P, ZERO_P, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, ZERO_M, ZERO_M, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), FLAG_IGNORE_ZEROSIGN },
	{ __LINE__, INF_P, QNAN_P, QNAN_P, 0 },
	{ __LINE__, INF_M, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_P, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, QNAN_P, 0 },

	{ __LINE__, HEXCONSTE(1.57079637050628662109e+00, 0x3fff, 0xc90fdb00L, 0x00000000L), HEXCONSTE(9.99999999999999044655e-01, 0x3ffe, 0xffffffffL, 0xffffbb29L), HEXCONSTE(-4.37113900018624143888e-08, 0xbfe6, 0xbbbd2e7bL, 0x96766267L), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(1.57079625129699707031e+00, 0x3fff, 0xc90fda00L, 0x00000000L), HEXCONSTE(9.99999999999997150012e-01, 0x3ffe, 0xffffffffL, 0xffff32a3L), HEXCONSTE(7.54978995489187499690e-08, 0x3fe7, 0xa22168c2L, 0x34c49b08L), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(1.57079632679489678004e+00, 0x3fff, 0xc90fdaa2L, 0x2168c800L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.60812264967663649219e-16, 0xbfca, 0xb9676733L, 0xae8fe47cL), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(1.57079632679489655800e+00, 0x3fff, 0xc90fdaa2L, 0x2168c000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(6.12323399573676588601e-17, 0x3fc9, 0x8d313198L, 0xa2e03707L), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(1.57079632679489661926e+00, 0x3fff, 0xc90fdaa2L, 0x2168c235L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(-2.50827880633416601173e-20, 0xbfbe, 0x80000000L, 0x00000000L), FLAG_FAIL_X87 }, /* bfbd:ece675d1:fc8f8cbb */
	{ __LINE__, HEXCONSTE(1.57079632679489661915e+00, 0x3fff, 0xc90fdaa2L, 0x2168c234L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(6.1232339957367660358688e-17, 0x3fc9, 0x8d313198L, 0xa2e03800L), FLAG_INEXACT4 }, /* 3fbf:c4c6628b:80dc1cd1 */
	{ __LINE__, HEXCONSTE(5.23598790168762207031e-01, 0x3ffe, 0x860a9200L, 0x00000000L), HEXCONSTE(5.00000012618391339030e-01, 0x3ffe, 0x80000036L, 0x32116885L), HEXCONSTE(8.66025396499206887837e-01, 0x3ffe, 0xddb3d723L, 0x7832e30fL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(5.23598730564117431641e-01, 0x3ffe, 0x860a9100L, 0x00000000L), HEXCONSTE(4.99999960999254326060e-01, 0x3ffd, 0xfffffeb0L, 0xfc740a1aL), HEXCONSTE(8.66025426301528489324e-01, 0x3ffe, 0xddb3d7a3L, 0x7832aa68L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.23598775598298926681e-01, 0x3ffe, 0x860a91c1L, 0x6b9b3000L), HEXCONSTE(5.00000000000000046404e-01, 0x3ffe, 0x80000000L, 0x00000358L), HEXCONSTE(8.66025403784438619953e-01, 0x3ffe, 0xddb3d742L, 0xc26551afL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.23598775598298815659e-01, 0x3ffe, 0x860a91c1L, 0x6b9b2800L), HEXCONSTE(4.99999999999999950262e-01, 0x3ffd, 0xffffffffL, 0xfffff8d5L), HEXCONSTE(8.66025403784438675464e-01, 0x3ffe, 0xddb3d742L, 0xc26555afL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.23598775598298873122e-01, 0x3ffe, 0x860a91c1L, 0x6b9b2c24L), HEXCONSTE(5.00000000000000000054e-01, 0x3ffe, 0x80000000L, 0x00000001L), HEXCONSTE(8.66025403784438646733e-01, 0x3ffe, 0xddb3d742L, 0xc265539dL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.23598775598298873067e-01, 0x3ffe, 0x860a91c1L, 0x6b9b2c23L), HEXCONSTE(5.00000000000000000000e-01, 0x3ffe, 0x80000000L, 0x00000000L), HEXCONSTE(8.66025403784438646787e-01, 0x3ffe, 0xddb3d742L, 0xc265539eL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(1.04719758033752441406e+00, 0x3fff, 0x860a9200L, 0x00000000L), HEXCONSTE(8.66025418354901612989e-01, 0x3ffe, 0xddb3d781L, 0x56ca0cfbL), HEXCONSTE(4.99999974763217003483e-01, 0x3ffd, 0xffffff27L, 0x37ba3007L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(1.04719746112823486328e+00, 0x3fff, 0x860a9100L, 0x00000000L), HEXCONSTE(8.66025358750253692599e-01, 0x3ffe, 0xddb3d681L, 0x56c92a5cL), HEXCONSTE(5.00000078001488305771e-01, 0x3ffe, 0x8000014fL, 0x038b1ab1L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.04719755119659785336e+00, 0x3fff, 0x860a91c1L, 0x6b9b3000L), HEXCONSTE(8.66025403784438700346e-01, 0x3ffe, 0xddb3d742L, 0xc265577aL), HEXCONSTE(4.99999999999999907165e-01, 0x3ffd, 0xffffffffL, 0xfffff29fL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.04719755119659763132e+00, 0x3fff, 0x860a91c1L, 0x6b9b2800L), HEXCONSTE(8.66025403784438589324e-01, 0x3ffe, 0xddb3d742L, 0xc2654f7aL), HEXCONSTE(5.00000000000000099476e-01, 0x3ffe, 0x80000000L, 0x0000072bL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.04719755119659774624e+00, 0x3fff, 0x860a91c1L, 0x6b9b2c24L), HEXCONSTE(8.66025403784438646787e-01, 0x3ffe, 0xddb3d742L, 0xc265539eL), HEXCONSTE(4.99999999999999999919e-01, 0x3ffe, 0x80000000L, 0x00000033L), FLAG_INEXACT3 }, /* 3ffd:ffffffff:fffffffd */
	{ __LINE__, HEXCONSTE(1.04719755119659774613e+00, 0x3fff, 0x860a91c1L, 0x6b9b2c23L), HEXCONSTE(8.66025403784438646733e-01, 0x3ffe, 0xddb3d742L, 0xc265539dL), HEXCONSTE(5.00000000000000000000e-01, 0x3ffe, 0x80000000L, 0x00000000L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(3.14159274101257324219e+00, 0x4000, 0xc90fdb00L, 0x00000000L), HEXCONSTE(-8.74227800037247452581e-08, 0xbfe7, 0xbbbd2e7bL, 0x967fbcb0L), HEXCONSTE(-9.99999999999996178621e-01, 0xbffe, 0xffffffffL, 0xfffeeca4L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bfe7:bbbd2e7b:96762feb */
	{ __LINE__, HEXCONSTE(3.14159250259399414062e+00, 0x4000, 0xc90fda00L, 0x00000000L), HEXCONSTE(1.50995799097837069610e-07, 0x3fe8, 0xa22168c2L, 0x34c418f9L), HEXCONSTE(-9.99999999999988600156e-01, 0xbffe, 0xffffffffL, 0xfffcca8eL), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(3.14159265358979356009e+00, 0x4000, 0xc90fdaa2L, 0x2168c800L), HEXCONSTE(-3.21624529935327298437e-16, 0xbfcb, 0xb9680000L, 0x00000000L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4 }, /* bfcb:b9676733:ae8fe47c */
	{ __LINE__, HEXCONSTE(3.14159265358979311600e+00, 0x4000, 0xc90fdaa2L, 0x2168c000L), HEXCONSTE(1.22464679914735317720e-16, 0x3fca, 0x8d300000L, 0x00000000L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4 }, /* 3fca:8d313198:a2e03707 */
	{ __LINE__, HEXCONSTE(3.14159265358979323851e+00, 0x4000, 0xc90fdaa2L, 0x2168c235L), HEXCONSTE(-5.01655761266833202345e-20, 0xbfbf, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4|FLAG_FAIL_X87 }, /* bfbe:ece675d1:fc8f8cbb */
	{ __LINE__, HEXCONSTE(3.14159265358979323830e+00, 0x4000, 0xc90fdaa2L, 0x2168c234L), HEXCONSTE(1.2246467991473532071738e-16, 0x3fca, 0x8d313198L, 0xa2e03800L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4 }, /* 3fc0:c4c6628b:80dc1cd1 */
	{ __LINE__, HEXCONSTE(-3.14159274101257324219e+00, 0xc000, 0xc90fdb00L, 0x00000000L), HEXCONSTE(8.74227800037247452581e-08, 0x3fe7, 0xbbbd2e7bL, 0x96762febL), HEXCONSTE(-9.99999999999996178621e-01, 0xbffe, 0xffffffffL, 0xfffeeca4L), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(-3.14159250259399414062e+00, 0xc000, 0xc90fda00L, 0x00000000L), HEXCONSTE(-1.50995799097837069610e-07, 0xbfe8, 0xa22168c2L, 0x34c418f9L), HEXCONSTE(-9.99999999999988600156e-01, 0xbffe, 0xffffffffL, 0xfffcca8eL), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(-3.14159265358979356009e+00, 0xc000, 0xc90fdaa2L, 0x2168c800L), HEXCONSTE(3.21624529935327298437e-16, 0x3fcb, 0xb9680000L, 0x00000000L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4 }, /* 3fcb:b9676733:ae8fe47c */
	{ __LINE__, HEXCONSTE(-3.14159265358979311600e+00, 0xc000, 0xc90fdaa2L, 0x2168c000L), HEXCONSTE(-1.22464679914735317720e-16, 0xbfca, 0x8d300000L, 0x00000000L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4 }, /* bfca:8d313198:a2e03707 */
	{ __LINE__, HEXCONSTE(-3.14159265358979323851e+00, 0xc000, 0xc90fdaa2L, 0x2168c235L), HEXCONSTE(5.01655761266833202345e-20, 0x3fbf, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4|FLAG_FAIL_X87 }, /* 3fbe:ece675d1:fc8f8cbb */
	{ __LINE__, HEXCONSTE(-3.14159265358979323830e+00, 0xc000, 0xc90fdaa2L, 0x2168c234L), HEXCONSTE(-1.2246467991473532071738e-16, 0xbfca, 0x8d313198L, 0xa2e03800L), HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), FLAG_INEXACT4 }, /* bfc0:c4c6628b:80dc1cd1 */
	{ __LINE__, HEXCONSTE(7.50000000000000000000e-01, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(6.81638760023334166756e-01, 0x3ffe, 0xae7fe0b5L, 0xfc786b2eL), HEXCONSTE(7.31688868873820886325e-01, 0x3ffe, 0xbb4ff632L, 0xa908f73fL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(3.68934881474191032320e+19, 0x4040, 0x80000000L, 0x00000000L), HEXCONSTE(-4.71838762123546738049e-02, 0x3ff3, 0x9b17d865L, 0xe6dd4a05L), HEXCONSTE(9.98886220660580136132e-01, 0x3ffe, 0xffffff44L, 0x143b3309L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffa:c143e153:b0701e80, 3ffe:ffb701e2:2987fbe7 */
	{ __LINE__, HEXCONSTE(-3.68934881474191032320e+19, 0xc040, 0x80000000L, 0x00000000L), HEXCONSTE(4.71838762123546738049e-02, 0xbff3, 0x9b17d865L, 0xe6dd4a05L), HEXCONSTE(9.98886220660580136132e-01, 0x3ffe, 0xffffff44L, 0x143b3309L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffa:c143e153:b0701e80, 3ffe:ffb701e2:2987fbe7 */
	{ __LINE__, HEXCONSTE(8.01901280879974365234e-01, 0x3ffe, 0xcd496700L, 0x00000000L), HEXCONSTE(7.18679428673139419556e-01, 0x3ffe, 0xb7fb6002L, 0x75877a60L), HEXCONSTE(6.95341555497763925725e-01, 0x3ffe, 0xb201e778L, 0x69a46ae2L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(8.01901221275329589844e-01, 0x3ffe, 0xcd496600L, 0x00000000L), HEXCONSTE(7.18679387227551729931e-01, 0x3ffe, 0xb7fb5f50L, 0x739fa5f9L), HEXCONSTE(6.95341598334394744017e-01, 0x3ffe, 0xb201e830L, 0x65041457L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(8.01901271840588458772e-01, 0x3ffe, 0xcd4966d9L, 0x2d171000L), HEXCONSTE(7.18679422387678733231e-01, 0x3ffe, 0xb7fb5fe7L, 0x769793e6L), HEXCONSTE(6.95341561994184596124e-01, 0x3ffe, 0xb201e794L, 0x50884640L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(8.01901271840588347750e-01, 0x3ffe, 0xcd4966d9L, 0x2d170800L), HEXCONSTE(7.18679422387678656036e-01, 0x3ffe, 0xb7fb5fe7L, 0x76978e56L), HEXCONSTE(6.95341561994184675921e-01, 0x3ffe, 0xb201e794L, 0x50884c00L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(8.01901271840588350027e-01, 0x3ffe, 0xcd4966d9L, 0x2d17082aL), HEXCONSTE(7.18679422387678657662e-01, 0x3ffe, 0xb7fb5fe7L, 0x76978e74L), HEXCONSTE(6.95341561994184674295e-01, 0x3ffe, 0xb201e794L, 0x50884be2L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(8.01901271840588349973e-01, 0x3ffe, 0xcd4966d9L, 0x2d170829L), HEXCONSTE(7.18679422387678657608e-01, 0x3ffe, 0xb7fb5fe7L, 0x76978e73L), HEXCONSTE(6.95341561994184674349e-01, 0x3ffe, 0xb201e794L, 0x50884be3L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.00000009040962152038e+22, 0x4048, 0x87867900L, 0x00000000L), HEXCONSTE(-3.00169493130367990501e-01, 0x3ff6, 0xbe835a6eL, 0x2c556b4eL), HEXCONSTE(9.53885881745745288040e-01, 0x3ffe, 0xffffb91cL, 0x575ebf69L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffd:99afd0d8:80ef7e1c, 3ffe:f431dd7a:36cf37de */
	{ __LINE__, HEXCONSTE(9.99999977819630836122e+21, 0x4048, 0x87867800L, 0x00000000L), HEXCONSTE(-7.34081535296101525979e-01, 0xbffd, 0xfcdcce9aL, 0x988c4f93L), HEXCONSTE(6.79061337095050972191e-01, 0x3ffe, 0xde99d0e1, 0xcd8755dbL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:bbecc47a:b1b8c708, 3ffe:add6f6ba:cd20654c */
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+22, 0x4048, 0x87867832L, 0x6eac9000L), HEXCONSTE(-8.52200849767188801768e-01, 0xbffe, 0xa755cb95L, 0x96c75048L), HEXCONSTE(5.23214785395138945478e-01, 0x3ffe, 0xc1bd48bdL, 0x5cb29cccL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:da29d5bb:5f9cb87d, 3ffe:85f16778:0e479c9a */
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-5.21876523333658540562e-01, 0x3ffe, 0xf3e8111bL, 0x794ca429L), HEXCONSTE(8.53021039830304158072e-01, 0xbffd, 0x9b81d0beL, 0xfeb2a614L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:8599b328:44aba907, 3ffe:da5f963c:defe6d53 */
	{ __LINE__, HEXCONSTE(8.98846567431157953865e+307, 0x43fe, 0x80000000L, 0x00000000L), HEXCONSTE(5.63127779850884013443e-01, 0xbffe, 0xec660098L, 0xb6d15fecL), HEXCONSTE(-8.26369834614147994497e-01, 0x3ffd, 0xc47ca4cbL, 0x9b2c544eL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:90292465:edbaff2d, bffe:d38cf936:1195f50b */
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-5.21876523333658540562e-01, 0x3ffe, 0xf3e8111bL, 0x794ca429L), HEXCONSTE(8.53021039830304158072e-01, 0xbffd, 0x9b81d0beL, 0xfeb2a614L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:8599b328:44aba907, 3ffe:da5f963c:defe6d53 */
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(4.96195478918406179070e-03, 0xbffe, 0xcbafef50L, 0x1d8a7cb4L), HEXCONSTE(-9.99987689426559937453e-01, 0xbffe, 0x9b1294d0L, 0x9cf3e650L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ff7:a297e4c5:9a74b5b1, bffe:ffff3176:7d5ba9e0 */
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(5.94865747678615882543e+4931, 0x7ffe, 0x80000000L, 0x00000000L), HEXCONSTE(3.89362998589420812698e-01, 0xbffe, 0xfab8efb2L, 0x149f3907L), HEXCONSTE(9.21084390992190620712e-01, 0xbffc, 0xceda821fL, 0x1ee0da71L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffd:c75a9642:6d98d104, 3ffe:ebcc2fc8:2ae39ec0 */
#endif
	{ __LINE__, HEXCONSTE(1.32922799578491587290e+36, 0x4077, 0x80000000L, 0x00000000L), HEXCONSTE(3.77820109360752022661e-01, 0xbffe, 0xebcdeef4L, 0xbae324c6L), HEXCONSTE(-9.25879022854837867307e-01, 0xbffd, 0xc752525eL, 0xef6da9eaL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffd:c171a32a:f37e5b6c, bffe:ed06685b:36c66c4d */
	{ __LINE__, HEXCONSTE(1.70141183460469231732e+38, 0x407e, 0x80000000L, 0x00000000L), HEXCONSTE(6.23385512955870240359e-01, 0xbffe, 0xcb5f91faL, 0xbda011daL), HEXCONSTE(7.81914638714960072267e-01, 0x3ffe, 0x9b7beb35L, 0x84744aa2L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:9f963166:f215eb89, 3ffe:c82b8ec9:8b5e62fd */
	{ __LINE__, HEXCONSTE(3.40282285791300048857e+38, 0x407e, 0xfffffc00L, 0x00000000L), HEXCONSTE(4.85786063130487339716e-02, 0x3ffd, 0xe31da09cL, 0xa53611daL), HEXCONSTE(9.98819362551949040704e-01, 0x3ffe, 0xe56f778fL, 0x34e98637L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffa:c6fa5c56:65984d89, 3ffe:ffb2a030:c5ae20be */
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-5.21876523333658540562e-01, 0x3ffe, 0xf3e8111bL, 0x794ca429L), HEXCONSTE(8.53021039830304158072e-01, 0xbffd, 0x9b81d0beL, 0xfeb2a614L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:8599b328:44aba907, 3ffe:da5f963c:defe6d53 */
	{ __LINE__, HEXCONSTE(1.12589990684262400000e+15, 0x4031, 0x80000000L, 0x00000000L), HEXCONSTE(4.96396515208940840872e-01, 0x3ffd, 0xfe27d956L, 0x1866fd77L), HEXCONSTE(8.68095904660550604312e-01, 0x3ffe, 0xde3b7c6d, 0xf5ef66a2L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffd:fe27af1d:576ed715, 3ffe:de3b8880:4f00552d */
	{ __LINE__, HEXCONSTE(2.68435456000000000000e+08, 0x401b, 0x80000000L, 0x00000000L), HEXCONSTE(-9.86198211836975655704e-01, 0xbffe, 0xfc777c6bL, 0x36b76baeL), HEXCONSTE(-1.65568979490578758871e-01, 0xbffc, 0xa98aea20L, 0x921738b3L), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(-3.40282346638528859812e+38, 0xc07e, 0xffffff00L, 0x00000000L), HEXCONSTE(5.21876523333658540562e-01, 0xbffe, 0xf3e8111bL, 0x794ca429L), HEXCONSTE(8.53021039830304158072e-01, 0xbffd, 0x9b81d0beL, 0xfeb2a614L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:8599b328:44aba907, 3ffe:da5f963c:defe6d53 */
	{ __LINE__, HEXCONSTE(-3.64229140925048708372e+307, 0xc3fc, 0xcf78c83dL, 0xafa1f800L), HEXCONSTE(-9.92195624918954397636e-01, 0x3ffd, 0xb9899a90L, 0x322e15a0L), HEXCONSTE(-1.24690985607162313507e-01, 0x3ffe, 0xee999947L, 0x53db5fcdL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:fe008850:42dd770d, bffb:ff5dfcca:4f66099b */
	{ __LINE__, HEXCONSTE(7.59194657019045731761e+34, 0x4072, 0xe9f1e600L, 0x00000000L), HEXCONSTE(7.79108221354363387633e-01, 0x3ffe, 0xb022a84fL, 0x76653b3cL), HEXCONSTE(-6.26889447524872842987e-01, 0xbffe, 0xb9c66259L, 0x794192baL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:c773a2ea:c3000ddf, bffe:a07bd3ab:53ab9711 */
	{ __LINE__, HEXCONSTE(7.59194607501444160346e+34, 0x4072, 0xe9f1e500L, 0x00000000L), HEXCONSTE(4.66512683316143507688e-01, 0x3ffe, 0xea5cd76fL, 0x02f8721eL), HEXCONSTE(8.84514508815526213101e-01, 0xbffd, 0xce02d6f2L, 0x4e16e8acL), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffd:eedac01c:062a4370, 3ffe:e26f8af8:333f9271 */
	{ __LINE__, HEXCONSTE(7.59194643911056501837e+34, 0x4072, 0xe9f1e5bcL, 0x3bb88000L), HEXCONSTE(9.92187350026198468548e-01, 0xbffe, 0xc17ebb77L, 0xe04d1035L), HEXCONSTE(1.24756813232744614799e-01, 0xbffe, 0xa79e1c50L, 0xa3e666e2L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:fdfffd7b:de0fb4ec, 3ffb:ff808006:4d739b18 */
	{ __LINE__, HEXCONSTE(1.31933767361251141222e+21, 0x4045, 0x8f0afa00L, 0x00000000L), HEXCONSTE(-1.24929881576082082729e-01, 0xbffe, 0xf7d9ca6bL, 0x4cf46ea2L), HEXCONSTE(-9.92165573223232789748e-01, 0x3ffd, 0x8028022fL, 0xef29e109L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffb:ffdb3cdd:4ca5bb0c, bffe:fdfe9021:35fc1c18 */
	{ __LINE__, HEXCONSTE(6.15815448760986328125e+00, 0x4001, 0xc50f9a00L, 0x00000000L), HEXCONSTE(-1.24705312431196324671e-01, 0xbffb, 0xff657fb4L, 0x3c508673L), HEXCONSTE(9.92193824336473942447e-01, 0x3ffe, 0xfe006a1aL, 0xd17db69bL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.15815401077270507812e+00, 0x4001, 0xc50f9900L, 0x00000000L), HEXCONSTE(-1.24705785546065730596e-01, 0xbffb, 0xff65bf34L, 0x56b74e20L), HEXCONSTE(9.92193764872234350576e-01, 0x3ffe, 0xfe00691bL, 0x6bde4252L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.15815403791391346999e+00, 0x4001, 0xc50f990eL, 0x92426000L), HEXCONSTE(-1.24705758616727947154e-01, 0xbffb, 0xff65bb97L, 0x0dc18073L), HEXCONSTE(9.92193768256899698266e-01, 0x3ffe, 0xfe006929L, 0xf558dbe6L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.15815403791391258181e+00, 0x4001, 0xc50f990eL, 0x92425800L), HEXCONSTE(-1.24705758616728828401e-01, 0xbffb, 0xff65bb97L, 0x0dc37c74L), HEXCONSTE(9.92193768256899587515e-01, 0x3ffe, 0xfe006929L, 0xf558d3ebL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.15815403791391312478e+00, 0x4001, 0xc50f990eL, 0x92425ce4L), HEXCONSTE(-1.24705758616728289667e-01, 0xbffb, 0xff65bb97L, 0x0dc245e5L), HEXCONSTE(9.92193768256899655223e-01, 0x3ffe, 0xfe006929L, 0xf558d8ccL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-1.01128077507019042969e+00, 0xbfff, 0x8171a600L, 0x00000000L), HEXCONSTE(-8.47512343819588481741e-01, 0xbffe, 0xd8f691a7L, 0xa9542600L), HEXCONSTE(5.30775684327595814770e-01, 0x3ffe, 0x87e0ea4dL, 0xb2f48867L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(2.55009582519531250000e+02, 0x4006, 0xff027400L, 0x00000000L), HEXCONSTE(-5.14631300183308550763e-01, 0xbffe, 0x83bee07bL, 0xc9076425L), HEXCONSTE(-8.57411584288221151643e-01, 0xbffe, 0xdb7f5359L, 0xbabdb66cL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(3.01631975173950195312e+00, 0x4000, 0xc10b6200L, 0x00000000L), HEXCONSTE(1.24945501318506756680e-01, 0x3ffb, 0xffe36d4fL, 0x8fff6c4bL), HEXCONSTE(-9.92163606317157264374e-01, 0xbffe, 0xfdfe6f21L, 0x69e24f27L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-5.21876523333658540562e-01, 0x3ffe, 0xf3e8111bL, 0x794ca429L), HEXCONSTE(8.53021039830304158072e-01, 0xbffd, 0x9b81d0beL, 0xfeb2a614L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:8599b328:44aba907, 3ffe:da5f963c:defe6d53 */
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(4.96195478918406179070e-03, 0xbffe, 0xcbafef50L, 0x1d8a7cb4L), HEXCONSTE(-9.99987689426559937453e-01, 0xbffe, 0x9b1294d0L, 0x9cf3e650L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ff7:a297e4c5:9a74b5b1, bffe:ffff3176:7d5ba9e0 */
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(1.18973149535723176502e+4932, 0x7ffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(9.92151099123526495965e-01, 0xbffb, 0xd5533512L, 0x6b40ccd2L), HEXCONSTE(-1.25044778011631903473e-01, 0x3ffe, 0xfe9b80a4L, 0x0c3bfcf5L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:fdfd9d4b:6d0e5f7c, bffc:800bbd00:61d4f543 */
	{ __LINE__, HEXCONSTE(-1.18973149535723176502e+4932, 0xfffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(-9.92151099123526495965e-01, 0x3ffb, 0xd5533512L, 0x6b40ccd2L), HEXCONSTE(-1.25044778011631903473e-01, 0x3ffe, 0xfe9b80a4L, 0x0c3bfcf5L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bffe:fdfd9d4b:6d0e5f7c, bffc:800bbd00:61d4f543 */
#endif
	{ __LINE__, HEXCONSTE(-3.40282346638528859812e+38, 0xc07e, 0xffffff00L, 0x00000000L), HEXCONSTE(5.21876523333658540562e-01, 0xbffe, 0xf3e8111bL, 0x794ca429L), HEXCONSTE(8.53021039830304158072e-01, 0xbffd, 0x9b81d0beL, 0xfeb2a614L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* 3ffe:8599b328:44aba907, 3ffe:da5f963c:defe6d53 */
	{ __LINE__, HEXCONSTE(-1.79769313486231570815e+308, 0xc3fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(-4.96195478918406179070e-03, 0x3ffe, 0xcbafef50L, 0x1d8a7cb4L), HEXCONSTE(-9.99987689426559937453e-01, 0xbffe, 0x9b1294d0L, 0x9cf3e650L), FLAG_INEXACT3|FLAG_FAIL_X87 }, /* bff7:a297e4c5:9a74b5b1, bffe:ffff3176:7d5ba9e0 */
	{ __LINE__, HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.22507385850720138309e-308, 0x3c01, 0x80000000L, 0x00000000L), HEXCONSTE(2.22507385850720138309e-308, 0x3c01, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#if defined(TEST_LDOUBLE) && __LDBL_MIN_EXP__ <= (-16381)
	{ __LINE__, HEXCONSTE(3.36210314311209350626e-4932, 0x0001, 0x80000000L, 0x00000000L), HEXCONSTE(3.36210314311209350626e-4932, 0x0001, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#endif
#if defined(TEST_LDOUBLE) && __LDBL_MIN_EXP__ <= (-16382)
	{ __LINE__, HEXCONSTE(1.68105157155604675313e-4932, 0x0000, 0x40000000L, 0x00000000L), HEXCONSTE(1.68105157155604675313e-4932, 0x0000, 0x40000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#endif
	{ __LINE__, HEXCONSTE(2.00416836000897277800e-292, 0x3c36, 0x80000000L, 0x00000000L), HEXCONSTE(2.00416836000897277800e-292, 0x3c36, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.22507385850720138309e-308, 0xbc01, 0x80000000L, 0x00000000L), HEXCONSTE(-2.22507385850720138309e-308, 0xbc01, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#if defined(TEST_LDOUBLE) && __LDBL_MIN_EXP__ <= (-16381)
	{ __LINE__, HEXCONSTE(-3.36210314311209350626e-4932, 0x8001, 0x80000000L, 0x00000000L), HEXCONSTE(-3.36210314311209350626e-4932, 0x8001, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#endif
#if defined(TEST_LDOUBLE) && __LDBL_MIN_EXP__ <= (-16382)
	{ __LINE__, HEXCONSTE(-1.68105157155604675313e-4932, 0x8000, 0x40000000L, 0x00000000L), HEXCONSTE(-1.68105157155604675313e-4932, 0x8000, 0x40000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#endif
	{ __LINE__, HEXCONSTE(-2.00416836000897277800e-292, 0xbc36, 0x80000000L, 0x00000000L), HEXCONSTE(-2.00416836000897277800e-292, 0xbc36, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(3.64519953188247460253e-4951L, 0x0000, 0x00000000L, 0x00000001L), HEXCONSTE(3.64519953188247460253e-4951, 0x0000, 0x00000000L, 0x00000001L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.82259976594123730126e-4951L, 0x0000, 0x00000000L, 0x00000001L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000001L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), FLAG_SUBNORM },
	{ __LINE__, HEXCONSTE(1.82259976594123730126e-4951L, 0x8000, 0x00000000L, 0x00000001L), HEXCONSTE(-0.0, 0x8000, 0x00000000L, 0x00000001L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), FLAG_SUBNORM },
#endif
	{ __LINE__, HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.94065645841246544177e-324, 0xbbcd, 0x80000000L, 0x00000000L), HEXCONSTE(-4.94065645841246544177e-324, 0xbbcd, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(-3.64519953188247460253e-4951, 0x8000, 0x00000000L, 0x00000001L), HEXCONSTE(-3.64519953188247460253e-4951, 0x8000, 0x00000000L, 0x00000001L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), 0 },
#endif
	{ __LINE__, HEXCONSTE(1.51742398738861083984e+00, 0x3fff, 0xc23af300L, 0x00000000L), HEXCONSTE(9.98576034767698972555e-01, 0x3ffe, 0xffa2add3L, 0xe58948d1L), HEXCONSTE(5.33470035486460361106e-02, 0x3ffa, 0xda826339L, 0x4be6d0e6L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.51742386817932128906e+00, 0x3fff, 0xc23af200L, 0x00000000L), HEXCONSTE(9.98576028408233484540e-01, 0x3ffe, 0xffa2adb8L, 0x953ae262L), HEXCONSTE(5.33471225881853241497e-02, 0x3ffa, 0xda82832dL, 0xa19f9892L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.51742396872239759809e+00, 0x3fff, 0xc23af2d7L, 0xea240800L), HEXCONSTE(9.98576033771912254552e-01, 0x3ffe, 0xffa2adcfL, 0x9ea83dbeL), HEXCONSTE(5.33470221882792298984e-02, 0x3ffa, 0xda82683aL, 0x33cbec00L), FLAG_INEXACT2 },
};



int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_ff(fsincos_data, ARRAY_SIZE(fsincos_data), __FILE__);

#if defined(__mc68000__) && (defined(__HAVE_68881__))
	{
		ld_union fp0;
		ld_union fp1;
		int this_fail;
		int i;
		static ld_union const pi_2 = HEXCONST_PI_2;
		
		/* test that we get the sin in the result when using the same register */
		numtests++;
		if (testonly == 0 || testonly == numtests)
		{
			for (i = 0; i < jit_loops; i++)
			{
				__asm__ __volatile__(
					"\tfmove.x %[x],%[fp0]\n"
					"\tfsincos.x %[fp0],%[r1],%[r1]\n"
				: [fp0]"=&f"(fp0.x), [r1]"=&f"(fp1.x)
				: [x]"m"(pi_2)
				: "cc", "memory");
				EXPECT_FP(fp1, 0x3fff, 0x80000000L, 0x00000000L);
				if (this_fail) break;
			}
		}
	}
#endif
		
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}

#else

int main(void)
{
	return 77;
}

#endif
