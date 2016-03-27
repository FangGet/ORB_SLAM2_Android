/* zlahilb.f -- translated by f2c (version 20061008).
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

static integer c__2 = 2;
static doublecomplex c_b6 = {0.,0.};

/* Subroutine */ int zlahilb_(integer *n, integer *nrhs, doublecomplex *a, 
	integer *lda, doublecomplex *x, integer *ldx, doublecomplex *b, 
	integer *ldb, doublereal *work, integer *info, char *path)
{
    /* Initialized data */

    static doublecomplex d1[8] = { {-1.,0.},{0.,1.},{-1.,-1.},{0.,-1.},{1.,0.}
	    ,{-1.,1.},{1.,1.},{1.,-1.} };
    static doublecomplex d2[8] = { {-1.,0.},{0.,-1.},{-1.,1.},{0.,1.},{1.,0.},
	    {-1.,-1.},{1.,-1.},{1.,1.} };
    static doublecomplex invd1[8] = { {-1.,0.},{0.,-1.},{-.5,.5},{0.,1.},{1.,
	    0.},{-.5,-.5},{.5,-.5},{.5,.5} };
    static doublecomplex invd2[8] = { {-1.,0.},{0.,1.},{-.5,-.5},{0.,-1.},{1.,
	    0.},{-.5,.5},{.5,.5},{.5,-.5} };

    /* System generated locals */
    integer a_dim1, a_offset, x_dim1, x_offset, b_dim1, b_offset, i__1, i__2, 
	    i__3, i__4, i__5;
    doublereal d__1;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer i__, j, m, r__;
    char c2[2];
    integer ti, tm;
    doublecomplex tmp;
    extern /* Subroutine */ int xerbla_(char *, integer *);
    extern logical lsamen_(integer *, char *, char *);
    extern /* Subroutine */ int zlaset_(char *, integer *, integer *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, integer *);


/*  -- LAPACK auxiliary test routine (version 3.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd., */
/*     Courant Institute, Argonne National Lab, and Rice University */
/*     28 August, 2006 */

/*     David Vu <dtv@cs.berkeley.edu> */
/*     Yozo Hida <yozo@cs.berkeley.edu> */
/*     Jason Riedy <ejr@cs.berkeley.edu> */
/*     D. Halligan <dhalligan@berkeley.edu> */

/*     .. Scalar Arguments .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  ZLAHILB generates an N by N scaled Hilbert matrix in A along with */
/*  NRHS right-hand sides in B and solutions in X such that A*X=B. */

/*  The Hilbert matrix is scaled by M = LCM(1, 2, ..., 2*N-1) so that all */
/*  entries are integers.  The right-hand sides are the first NRHS */
/*  columns of M * the identity matrix, and the solutions are the */
/*  first NRHS columns of the inverse Hilbert matrix. */

/*  The condition number of the Hilbert matrix grows exponentially with */
/*  its size, roughly as O(e ** (3.5*N)).  Additionally, the inverse */
/*  Hilbert matrices beyond a relatively small dimension cannot be */
/*  generated exactly without extra precision.  Precision is exhausted */
/*  when the largest entry in the inverse Hilbert matrix is greater than */
/*  2 to the power of the number of bits in the fraction of the data type */
/*  used plus one, which is 24 for single precision. */

/*  In single, the generated solution is exact for N <= 6 and has */
/*  small componentwise error for 7 <= N <= 11. */

/*  Arguments */
/*  ========= */

/*  N       (input) INTEGER */
/*          The dimension of the matrix A. */

/*  NRHS    (input) NRHS */
/*          The requested number of right-hand sides. */

/*  A       (output) COMPLEX array, dimension (LDA, N) */
/*          The generated scaled Hilbert matrix. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= N. */

/*  X       (output) COMPLEX array, dimension (LDX, NRHS) */
/*          The generated exact solutions.  Currently, the first NRHS */
/*          columns of the inverse Hilbert matrix. */

/*  LDX     (input) INTEGER */
/*          The leading dimension of the array X.  LDX >= N. */

/*  B       (output) REAL array, dimension (LDB, NRHS) */
/*          The generated right-hand sides.  Currently, the first NRHS */
/*          columns of LCM(1, 2, ..., 2*N-1) * the identity matrix. */

/*  LDB     (input) INTEGER */
/*          The leading dimension of the array B.  LDB >= N. */

/*  WORK    (workspace) REAL array, dimension (N) */


/*  INFO    (output) INTEGER */
/*          = 0: successful exit */
/*          = 1: N is too large; the data is still generated but may not */
/*               be not exact. */
/*          < 0: if INFO = -i, the i-th argument had an illegal value */

/*  ===================================================================== */
/*     .. Local Scalars .. */
/*     .. Parameters .. */
/*     NMAX_EXACT   the largest dimension where the generated data is */
/*                  exact. */
/*     NMAX_APPROX  the largest dimension where the generated data has */
/*                  a small componentwise relative error. */
/*     ??? complex uses how many bits ??? */
/*     d's are generated from random permuation of those eight elements. */
    /* Parameter adjustments */
    --work;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    x_dim1 = *ldx;
    x_offset = 1 + x_dim1;
    x -= x_offset;
    b_dim1 = *ldb;
    b_offset = 1 + b_dim1;
    b -= b_offset;

    /* Function Body */
/*     .. */
/*     .. External Functions */
/*     .. */
/*     .. Executable Statements .. */
    s_copy(c2, path + 1, (ftnlen)2, (ftnlen)2);

/*     Test the input arguments */

    *info = 0;
    if (*n < 0 || *n > 11) {
	*info = -1;
    } else if (*nrhs < 0) {
	*info = -2;
    } else if (*lda < *n) {
	*info = -4;
    } else if (*ldx < *n) {
	*info = -6;
    } else if (*ldb < *n) {
	*info = -8;
    }
    if (*info < 0) {
	i__1 = -(*info);
	xerbla_("ZLAHILB", &i__1);
	return 0;
    }
    if (*n > 6) {
	*info = 1;
    }
/*     Compute M = the LCM of the integers [1, 2*N-1].  The largest */
/*     reasonable N is small enough that integers suffice (up to N = 11). */
    m = 1;
    i__1 = (*n << 1) - 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	tm = m;
	ti = i__;
	r__ = tm % ti;
	while(r__ != 0) {
	    tm = ti;
	    ti = r__;
	    r__ = tm % ti;
	}
	m = m / ti * i__;
    }
/*     Generate the scaled Hilbert matrix in A */
/*     If we are testing SY routines, take D1_i = D2_i, else, D1_i = D2_i* */
    if (lsamen_(&c__2, c2, "SY")) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__3 = i__ + j * a_dim1;
		i__4 = j % 8;
		d__1 = (doublereal) m / (i__ + j - 1);
		z__2.r = d__1 * d1[i__4].r, z__2.i = d__1 * d1[i__4].i;
		i__5 = i__ % 8;
		z__1.r = z__2.r * d1[i__5].r - z__2.i * d1[i__5].i, z__1.i = 
			z__2.r * d1[i__5].i + z__2.i * d1[i__5].r;
		a[i__3].r = z__1.r, a[i__3].i = z__1.i;
	    }
	}
    } else {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__3 = i__ + j * a_dim1;
		i__4 = j % 8;
		d__1 = (doublereal) m / (i__ + j - 1);
		z__2.r = d__1 * d1[i__4].r, z__2.i = d__1 * d1[i__4].i;
		i__5 = i__ % 8;
		z__1.r = z__2.r * d2[i__5].r - z__2.i * d2[i__5].i, z__1.i = 
			z__2.r * d2[i__5].i + z__2.i * d2[i__5].r;
		a[i__3].r = z__1.r, a[i__3].i = z__1.i;
	    }
	}
    }
/*     Generate matrix B as simply the first NRHS columns of M * the */
/*     identity. */
    d__1 = (doublereal) m;
    tmp.r = d__1, tmp.i = 0.;
    zlaset_("Full", n, nrhs, &c_b6, &tmp, &b[b_offset], ldb);
/*     Generate the true solutions in X.  Because B = the first NRHS */
/*     columns of M*I, the true solutions are just the first NRHS columns */
/*     of the inverse Hilbert matrix. */
    work[1] = (doublereal) (*n);
    i__1 = *n;
    for (j = 2; j <= i__1; ++j) {
	work[j] = work[j - 1] / (j - 1) * (j - 1 - *n) / (j - 1) * (*n + j - 
		1);
    }
/*     If we are testing SY routines, take D1_i = D2_i, else, D1_i = D2_i* */
    if (lsamen_(&c__2, c2, "SY")) {
	i__1 = *nrhs;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__3 = i__ + j * x_dim1;
		i__4 = j % 8;
		d__1 = work[i__] * work[j] / (i__ + j - 1);
		z__2.r = d__1 * invd1[i__4].r, z__2.i = d__1 * invd1[i__4].i;
		i__5 = i__ % 8;
		z__1.r = z__2.r * invd1[i__5].r - z__2.i * invd1[i__5].i, 
			z__1.i = z__2.r * invd1[i__5].i + z__2.i * invd1[i__5]
			.r;
		x[i__3].r = z__1.r, x[i__3].i = z__1.i;
	    }
	}
    } else {
	i__1 = *nrhs;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__3 = i__ + j * x_dim1;
		i__4 = j % 8;
		d__1 = work[i__] * work[j] / (i__ + j - 1);
		z__2.r = d__1 * invd2[i__4].r, z__2.i = d__1 * invd2[i__4].i;
		i__5 = i__ % 8;
		z__1.r = z__2.r * invd1[i__5].r - z__2.i * invd1[i__5].i, 
			z__1.i = z__2.r * invd1[i__5].i + z__2.i * invd1[i__5]
			.r;
		x[i__3].r = z__1.r, x[i__3].i = z__1.i;
	    }
	}
    }
    return 0;
} /* zlahilb_ */
