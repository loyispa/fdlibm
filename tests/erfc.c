#include "testconfig.h"
#define TEST_FUNC_F_F __MATH_PRECNAME(erfc)
#include "testdriver.h"



static test_f_f_data const erfc_data[] = {
	{ __LINE__, ZERO_P, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, ZERO_M, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, INF_P, ZERO_P, 0 },
	{ __LINE__, INF_M, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },

	{ __LINE__, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(0.859683795198666182606970553478376602L, 0x3ffe, 0xdc143cb9L, 0x4788ed18L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(0.288844366346484868401062165408589223L, 0x3ffd, 0x93e368a6L, 0x2f1a093bL), 0 },
	{ __LINE__, HEXCONSTE(1.25L, 0x3fff, 0xa0000000L, 0x00000000L), HEXCONSTE(0.0770998717435417698634765188027188596L, 0x3ffb, 0x9de6899dL, 0x507fdfcfL), FLAG_INEXACT|FLAG_FAIL_ARANYM }, /* too inexact when using double */
	{ __LINE__, HEXCONSTE(2.0L, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(0.00467773498104726583793074363274707139L, 0x3ff7, 0x9947af61L, 0xa873346cL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.93115949630737304688e+00, 0x4000, 0xfb981e00L, 0x00000000L), HEXCONSTE(2.705500297238986897105236321218861842255e-8L, 0x3fe5, 0xe86694a9L, 0xc24115c3L), FLAG_FAIL_ARANYM }, /* too inexact when using double */
	{ __LINE__, HEXCONSTE(4.125L, 0x4001, 0x84000000L, 0x00000000L), HEXCONSTE(0.542340079956506600531223408575531062e-8L, 0x3fe3, 0xba58bce8L, 0xf5d404f9L), FLAG_FAIL_ARANYM }, /* too inexact when using double */
	{ __LINE__, HEXCONSTE(7.99414110183715820312e+00, 0x4001, 0xffd00100L, 0x00000000L), HEXCONSTE(1.233585992097580296336099501489175967033e-29L, 0x3f9e, 0xfa33725bL, 0xea2f7d7bL), FLAG_INEXACT|FLAG_FAIL_ARANYM }, /* too inexact when using double */
	{ __LINE__, HEXCONSTE(7.99998664855957031250e+00, 0x4001, 0xffffe400L, 0x00000000L), HEXCONSTE(1.122671365033056305522366683719541099329e-29L, 0x3f9e, 0xe3b46e15L, 0xad97825dL), FLAG_FAIL_ARANYM }, /* too inexact when using double */
#ifdef TEST_LDOUBLE
	/* The result can only be represented in long double.  */
# if LDBL_MIN_10_EXP < -319
	{ __LINE__, HEXCONSTE(27.0L, 0x4003, 0xd8000000L, 0x00000000L), HEXCONSTE(0.523704892378925568501606768284954709e-318L, 0x3bdd, 0xcf07866fL, 0xc1d3afd1L), 0 },
# endif
# if LDBL_MANT_DIG >= 106
	{ __LINE__, HEXCONSTE(7.99995958116319444073e+00, 0x4001, 0xffffab3cL, 0x4d5e6f78L), HEXCONSTE(1.123161416304655390092138725253789378459e-29L, 0x3f9e, 0xe3cddffbL, 0xbe84faf8L), 0 },
# endif
#endif
};

int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(erfc_data, ARRAY_SIZE(erfc_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}