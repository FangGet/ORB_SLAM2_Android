/* slaord.f -- translated by f2c (version 20061008).
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

/* Subroutine */ int slaord_(char *job, integer *n, real *x, integer *incx)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer i__, ix, inc;
    real temp;
    extern logical lsame_(char *, char *);
    integer ixnext;


/*  -- LAPACK auxiliary routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SLAORD sorts the elements of a vector x in increasing or decreasing */
/*  order. */

/*  Arguments */
/*  ========= */

/*  JOB     (input) CHARACTER */
/*          = 'I':  Sort in increasing order */
/*          = 'D':  Sort in decreasing order */

/*  N       (input) INTEGER */
/*          The length of the vector X. */

/*  X       (input/output) REAL array, dimension */
/*                         (1+(N-1)*INCX) */
/*          On entry, the vector of length n to be sorted. */
/*          On exit, the vector x is sorted in the prescribed order. */

/*  INCX    (input) INTEGER */
/*          The spacing between successive elements of X.  INCX >= 0. */

/*  ===================================================================== */

/*     .. Local Scalars .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

    /* Parameter adjustments */
    --x;

    /* Function Body */
    inc = abs(*incx);
    if (lsame_(job, "I")) {

/*        Sort in increasing order */

	i__1 = *n;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    ix = (i__ - 1) * inc + 1;
L10:
	    if (ix == 1) {
		goto L20;
	    }
	    ixnext = ix - inc;
	    if (x[ix] > x[ixnext]) {
		goto L20;
	    } else {
		temp = x[ix];
		x[ix] = x[ixnext];
		x[ixnext] = temp;
	    }
	    ix = ixnext;
	    goto L10;
L20:
	    ;
	}

    } else if (lsame_(job, "D")) {

/*        Sort in decreasing order */

	i__1 = *n;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    ix = (i__ - 1) * inc + 1;
L30:
	    if (ix == 1) {
		goto L40;
	    }
	    ixnext = ix - inc;
	    if (x[ix] < x[ixnext]) {
		goto L40;
	    } else {
		temp = x[ix];
		x[ix] = x[ixnext];
		x[ixnext] = temp;
	    }
	    ix = ixnext;
	    goto L30;
L40:
	    ;
	}
    }
    return 0;

/*     End of SLAORD */

} /* slaord_ */
