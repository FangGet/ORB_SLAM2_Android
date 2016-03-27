/* dgennd.f -- translated by f2c (version 20061008).
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

logical dgennd_(integer *m, integer *n, doublereal *a, integer *lda)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1;
    logical ret_val;

    /* Local variables */
    integer i__, k;


/*  -- LAPACK test routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     February 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*     DGENND tests that its argument has a non-negative diagonal. */

/*  Arguments */
/*  ========= */

/*  M       (input) INTEGER */
/*          The number of rows in A. */

/*  N       (input) INTEGER */
/*          The number of columns in A. */

/*  A       (input) DOUBLE PRECISION array, dimension (LDA, N) */
/*          The matrix. */

/*  LDA     (input) INTEGER */
/*          Leading dimension of A. */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Intrinsics .. */
/*     .. */
/*     .. Executable Statements .. */
    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    k = min(*m,*n);
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (a[i__ + i__ * a_dim1] < 0.) {
	    ret_val = FALSE_;
	    return ret_val;
	}
    }
    ret_val = TRUE_;
    return ret_val;
} /* dgennd_ */
