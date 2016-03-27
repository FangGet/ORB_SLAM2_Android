/* sget06.f -- translated by f2c (version 20061008).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"
#include "blaswrap.h"

doublereal sget06_(real *rcond, real *rcondc)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real rat, eps;
    extern doublereal slamch_(char *);


/*  -- LAPACK test routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SGET06 computes a test ratio to compare two values for RCOND. */

/*  Arguments */
/*  ========== */

/*  RCOND   (input) REAL */
/*          The estimate of the reciprocal of the condition number of A, */
/*          as computed by SGECON. */

/*  RCONDC  (input) REAL */
/*          The reciprocal of the condition number of A, computed as */
/*          ( 1/norm(A) ) / norm(inv(A)). */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

    eps = slamch_("Epsilon");
    if (*rcond > 0.f) {
	if (*rcondc > 0.f) {
	    rat = dmax(*rcond,*rcondc) / dmin(*rcond,*rcondc) - (1.f - eps);
	} else {
	    rat = *rcond / eps;
	}
    } else {
	if (*rcondc > 0.f) {
	    rat = *rcondc / eps;
	} else {
	    rat = 0.f;
	}
    }
    ret_val = rat;
    return ret_val;

/*     End of SGET06 */

} /* sget06_ */
