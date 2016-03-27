/* dget06.f -- translated by f2c (version 20061008).
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

doublereal dget06_(doublereal *rcond, doublereal *rcondc)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    doublereal rat, eps;
    extern doublereal dlamch_(char *);


/*  -- LAPACK test routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DGET06 computes a test ratio to compare two values for RCOND. */

/*  Arguments */
/*  ========== */

/*  RCOND   (input) DOUBLE PRECISION */
/*          The estimate of the reciprocal of the condition number of A, */
/*          as computed by DGECON. */

/*  RCONDC  (input) DOUBLE PRECISION */
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

    eps = dlamch_("Epsilon");
    if (*rcond > 0.) {
	if (*rcondc > 0.) {
	    rat = max(*rcond,*rcondc) / min(*rcond,*rcondc) - (1. - eps);
	} else {
	    rat = *rcond / eps;
	}
    } else {
	if (*rcondc > 0.) {
	    rat = *rcondc / eps;
	} else {
	    rat = 0.;
	}
    }
    ret_val = rat;
    return ret_val;

/*     End of DGET06 */

} /* dget06_ */
