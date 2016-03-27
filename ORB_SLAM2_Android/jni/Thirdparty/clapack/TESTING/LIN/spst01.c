/* spst01.f -- translated by f2c (version 20061008).
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

static integer c__1 = 1;
static real c_b18 = 1.f;

/* Subroutine */ int spst01_(char *uplo, integer *n, real *a, integer *lda, 
	real *afac, integer *ldafac, real *perm, integer *ldperm, integer *
	piv, real *rwork, real *resid, integer *rank)
{
    /* System generated locals */
    integer a_dim1, a_offset, afac_dim1, afac_offset, perm_dim1, perm_offset, 
	    i__1, i__2;

    /* Local variables */
    integer i__, j, k;
    real t, eps;
    extern doublereal sdot_(integer *, real *, integer *, real *, integer *);
    extern /* Subroutine */ int ssyr_(char *, integer *, real *, real *, 
	    integer *, real *, integer *);
    extern logical lsame_(char *, char *);
    extern /* Subroutine */ int sscal_(integer *, real *, real *, integer *);
    real anorm;
    extern /* Subroutine */ int strmv_(char *, char *, char *, integer *, 
	    real *, integer *, real *, integer *);
    extern doublereal slamch_(char *), slansy_(char *, char *, 
	    integer *, real *, integer *, real *);


/*  -- LAPACK test routine (version 3.1) -- */
/*     Craig Lucas, University of Manchester / NAG Ltd. */
/*     October, 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SPST01 reconstructs a symmetric positive semidefinite matrix A */
/*  from its L or U factors and the permutation matrix P and computes */
/*  the residual */
/*     norm( P*L*L'*P' - A ) / ( N * norm(A) * EPS ) or */
/*     norm( P*U'*U*P' - A ) / ( N * norm(A) * EPS ), */
/*  where EPS is the machine epsilon. */

/*  Arguments */
/*  ========== */

/*  UPLO    (input) CHARACTER*1 */
/*          Specifies whether the upper or lower triangular part of the */
/*          symmetric matrix A is stored: */
/*          = 'U':  Upper triangular */
/*          = 'L':  Lower triangular */

/*  N       (input) INTEGER */
/*          The number of rows and columns of the matrix A.  N >= 0. */

/*  A       (input) REAL array, dimension (LDA,N) */
/*          The original symmetric matrix A. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= max(1,N) */

/*  AFAC    (input) REAL array, dimension (LDAFAC,N) */
/*          The factor L or U from the L*L' or U'*U */
/*          factorization of A. */

/*  LDAFAC  (input) INTEGER */
/*          The leading dimension of the array AFAC.  LDAFAC >= max(1,N). */

/*  PERM    (output) REAL array, dimension (LDPERM,N) */
/*          Overwritten with the reconstructed matrix, and then with the */
/*          difference P*L*L'*P' - A (or P*U'*U*P' - A) */

/*  LDPERM  (input) INTEGER */
/*          The leading dimension of the array PERM. */
/*          LDAPERM >= max(1,N). */

/*  PIV     (input) INTEGER array, dimension (N) */
/*          PIV is such that the nonzero entries are */
/*          P( PIV( K ), K ) = 1. */

/*  RWORK   (workspace) REAL array, dimension (N) */

/*  RESID   (output) REAL */
/*          If UPLO = 'L', norm(L*L' - A) / ( N * norm(A) * EPS ) */
/*          If UPLO = 'U', norm(U'*U - A) / ( N * norm(A) * EPS ) */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Quick exit if N = 0. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    afac_dim1 = *ldafac;
    afac_offset = 1 + afac_dim1;
    afac -= afac_offset;
    perm_dim1 = *ldperm;
    perm_offset = 1 + perm_dim1;
    perm -= perm_offset;
    --piv;
    --rwork;

    /* Function Body */
    if (*n <= 0) {
	*resid = 0.f;
	return 0;
    }

/*     Exit with RESID = 1/EPS if ANORM = 0. */

    eps = slamch_("Epsilon");
    anorm = slansy_("1", uplo, n, &a[a_offset], lda, &rwork[1]);
    if (anorm <= 0.f) {
	*resid = 1.f / eps;
	return 0;
    }

/*     Compute the product U'*U, overwriting U. */

    if (lsame_(uplo, "U")) {

	if (*rank < *n) {
	    i__1 = *n;
	    for (j = *rank + 1; j <= i__1; ++j) {
		i__2 = j;
		for (i__ = *rank + 1; i__ <= i__2; ++i__) {
		    afac[i__ + j * afac_dim1] = 0.f;
/* L100: */
		}
/* L110: */
	    }
	}

	for (k = *n; k >= 1; --k) {

/*           Compute the (K,K) element of the result. */

	    t = sdot_(&k, &afac[k * afac_dim1 + 1], &c__1, &afac[k * 
		    afac_dim1 + 1], &c__1);
	    afac[k + k * afac_dim1] = t;

/*           Compute the rest of column K. */

	    i__1 = k - 1;
	    strmv_("Upper", "Transpose", "Non-unit", &i__1, &afac[afac_offset]
, ldafac, &afac[k * afac_dim1 + 1], &c__1);

/* L120: */
	}

/*     Compute the product L*L', overwriting L. */

    } else {

	if (*rank < *n) {
	    i__1 = *n;
	    for (j = *rank + 1; j <= i__1; ++j) {
		i__2 = *n;
		for (i__ = j; i__ <= i__2; ++i__) {
		    afac[i__ + j * afac_dim1] = 0.f;
/* L130: */
		}
/* L140: */
	    }
	}

	for (k = *n; k >= 1; --k) {
/*           Add a multiple of column K of the factor L to each of */
/*           columns K+1 through N. */

	    if (k + 1 <= *n) {
		i__1 = *n - k;
		ssyr_("Lower", &i__1, &c_b18, &afac[k + 1 + k * afac_dim1], &
			c__1, &afac[k + 1 + (k + 1) * afac_dim1], ldafac);
	    }

/*           Scale column K by the diagonal element. */

	    t = afac[k + k * afac_dim1];
	    i__1 = *n - k + 1;
	    sscal_(&i__1, &t, &afac[k + k * afac_dim1], &c__1);
/* L150: */
	}

    }

/*        Form P*L*L'*P' or P*U'*U*P' */

    if (lsame_(uplo, "U")) {

	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		if (piv[i__] <= piv[j]) {
		    if (i__ <= j) {
			perm[piv[i__] + piv[j] * perm_dim1] = afac[i__ + j * 
				afac_dim1];
		    } else {
			perm[piv[i__] + piv[j] * perm_dim1] = afac[j + i__ * 
				afac_dim1];
		    }
		}
/* L160: */
	    }
/* L170: */
	}


    } else {

	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		if (piv[i__] >= piv[j]) {
		    if (i__ >= j) {
			perm[piv[i__] + piv[j] * perm_dim1] = afac[i__ + j * 
				afac_dim1];
		    } else {
			perm[piv[i__] + piv[j] * perm_dim1] = afac[j + i__ * 
				afac_dim1];
		    }
		}
/* L180: */
	    }
/* L190: */
	}

    }

/*     Compute the difference  P*L*L'*P' - A (or P*U'*U*P' - A). */

    if (lsame_(uplo, "U")) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = j;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		perm[i__ + j * perm_dim1] -= a[i__ + j * a_dim1];
/* L200: */
	    }
/* L210: */
	}
    } else {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = j; i__ <= i__2; ++i__) {
		perm[i__ + j * perm_dim1] -= a[i__ + j * a_dim1];
/* L220: */
	    }
/* L230: */
	}
    }

/*     Compute norm( P*L*L'P - A ) / ( N * norm(A) * EPS ), or */
/*     ( P*U'*U*P' - A )/ ( N * norm(A) * EPS ). */

    *resid = slansy_("1", uplo, n, &perm[perm_offset], ldafac, &rwork[1]);

    *resid = *resid / (real) (*n) / anorm / eps;

    return 0;

/*     End of SPST01 */

} /* spst01_ */
