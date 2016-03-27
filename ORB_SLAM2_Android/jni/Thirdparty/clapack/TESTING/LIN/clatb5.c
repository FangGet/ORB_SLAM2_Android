/* clatb5.f -- translated by f2c (version 20061008).
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

/* Subroutine */ int clatb5_(char *path, integer *imat, integer *n, char *
	type__, integer *kl, integer *ku, real *anorm, integer *mode, real *
	cndnum, char *dist)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char c2[2];
    static real eps, badc1, badc2, large, small;
    extern /* Subroutine */ int slabad_(real *, real *);
    extern doublereal slamch_(char *);


/*  -- LAPACK test routine (version 3.1) -- */
/*     Craig Lucas, University of Manchester / NAG Ltd. */
/*     October, 2008 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  CLATB5 sets parameters for the matrix generator based on the type */
/*  of matrix to be generated. */

/*  Arguments */
/*  ========= */

/*  PATH    (input) CHARACTER*3 */
/*          The LAPACK path name. */

/*  IMAT    (input) INTEGER */
/*          An integer key describing which matrix to generate for this */
/*          path. */

/*  N       (input) INTEGER */
/*          The number of rows and columns in the matrix to be generated. */

/*  TYPE    (output) CHARACTER*1 */
/*          The type of the matrix to be generated: */
/*          = 'S':  symmetric matrix */
/*          = 'P':  symmetric positive (semi)definite matrix */
/*          = 'N':  nonsymmetric matrix */

/*  KL      (output) INTEGER */
/*          The lower band width of the matrix to be generated. */

/*  KU      (output) INTEGER */
/*          The upper band width of the matrix to be generated. */

/*  ANORM   (output) REAL */
/*          The desired norm of the matrix to be generated.  The diagonal */
/*          matrix of singular values or eigenvalues is scaled by this */
/*          value. */

/*  MODE    (output) INTEGER */
/*          A key indicating how to choose the vector of eigenvalues. */

/*  CNDNUM  (output) REAL */
/*          The desired condition number. */

/*  DIST    (output) CHARACTER*1 */
/*          The type of distribution to be used by the random number */
/*          generator. */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Save statement .. */
/*     .. */
/*     .. Data statements .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Set some constants for use in the subroutine. */

    if (first) {
	first = FALSE_;
	eps = slamch_("Precision");
	badc2 = .1f / eps;
	badc1 = sqrt(badc2);
	small = slamch_("Safe minimum");
	large = 1.f / small;

/*        If it looks like we're on a Cray, take the square root of */
/*        SMALL and LARGE to avoid overflow and underflow problems. */

	slabad_(&small, &large);
	small = small / eps * .25f;
	large = 1.f / small;
    }

    s_copy(c2, path + 1, (ftnlen)2, (ftnlen)2);

/*     Set some parameters */

    *(unsigned char *)dist = 'S';
    *mode = 3;

/*     Set TYPE, the type of matrix to be generated. */

    *(unsigned char *)type__ = *(unsigned char *)c2;

/*     Set the lower and upper bandwidths. */

    if (*imat == 1) {
	*kl = 0;
    } else {
/* Computing MAX */
	i__1 = *n - 1;
	*kl = max(i__1,0);
    }
    *ku = *kl;

/*     Set the condition number and norm.etc */

    if (*imat == 3) {
	*cndnum = 1e4f;
	*mode = 2;
    } else if (*imat == 4) {
	*cndnum = 1e4f;
	*mode = 1;
    } else if (*imat == 5) {
	*cndnum = 1e4f;
	*mode = 3;
    } else if (*imat == 6) {
	*cndnum = badc1;
    } else if (*imat == 7) {
	*cndnum = badc2;
    } else {
	*cndnum = 2.f;
    }

    if (*imat == 8) {
	*anorm = small;
    } else if (*imat == 9) {
	*anorm = large;
    } else {
	*anorm = 1.f;
    }

    if (*n <= 1) {
	*cndnum = 1.f;
    }

    return 0;

/*     End of SLATB5 */

} /* clatb5_ */
