/* slctes.f -- translated by f2c (version 20061008).
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

/* Table of constant values */

static real c_b2 = 1.f;

logical slctes_(real *zr, real *zi, real *d__)
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
    double r_sign(real *, real *);


/*  -- LAPACK test routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SLCTES returns .TRUE. if the eigenvalue (ZR/D) + sqrt(-1)*(ZI/D) */
/*  is to be selected (specifically, in this subroutine, if the real */
/*  part of the eigenvalue is negative), and otherwise it returns */
/*  .FALSE.. */

/*  It is used by the test routine SDRGES to test whether the driver */
/*  routine SGGES succesfully sorts eigenvalues. */

/*  Arguments */
/*  ========= */

/*  ZR      (input) REAL */
/*          The numerator of the real part of a complex eigenvalue */
/*          (ZR/D) + i*(ZI/D). */

/*  ZI      (input) REAL */
/*          The numerator of the imaginary part of a complex eigenvalue */
/*          (ZR/D) + i*(ZI). */

/*  D       (input) REAL */
/*          The denominator part of a complex eigenvalue */
/*          (ZR/D) + i*(ZI/D). */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

    if (*d__ == 0.f) {
	ret_val = *zr < 0.f;
    } else {
	ret_val = r_sign(&c_b2, zr) != r_sign(&c_b2, d__);
    }

    return ret_val;

/*     End of SLCTES */

} /* slctes_ */
