/* dpst01.f -- translated by f2c (version 20061008).
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
static doublereal c_b18 = 1.;

/* Subroutine */ int dpst01_(char *uplo, integer *n, doublereal *a, integer *
	lda, doublereal *afac, integer *ldafac, doublereal *perm, integer *
	ldperm, integer *piv, doublereal *rwork, doublereal *resid, integer *
	rank)
{
    /* System generated locals */
    integer a_dim1, a_offset, afac_dim1, afac_offset, perm_dim1, perm_offset, 
	    i__1, i__2;

    /* Local variables */
    integer i__, j, k;
    doublereal t, eps;
    extern doublereal ddot_(integer *, doublereal *, integer *, doublereal *, 
	    integer *);
    extern /* Subroutine */ int dsyr_(char *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *), dscal_(
	    integer *, doublereal *, doublereal *, integer *);
    extern logical lsame_(char *, char *);
    doublereal anorm;
    extern /* Subroutine */ int dtrmv_(char *, char *, char *, integer *, 
	    doublereal *, integer *, doublereal *, integer *);
    extern doublereal dlamch_(char *), dlansy_(char *, char *, 
	    integer *, doublereal *, integer *, doublereal *);


/*  -- LAPACK test routine (version 3.1) -- */
/*     Craig Lucas, University of Manchester / NAG Ltd. */
/*     October, 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DPST01 reconstructs a symmetric positive semidefinite matrix A */
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

/*  A       (input) DOUBLE PRECISION array, dimension (LDA,N) */
/*          The original symmetric matrix A. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= max(1,N) */

/*  AFAC    (input) DOUBLE PRECISION array, dimension (LDAFAC,N) */
/*          The factor L or U from the L*L' or U'*U */
/*          factorization of A. */

/*  LDAFAC  (input) INTEGER */
/*          The leading dimension of the array AFAC.  LDAFAC >= max(1,N). */

/*  PERM    (output) DOUBLE PRECISION array, dimension (LDPERM,N) */
/*          Overwritten with the reconstructed matrix, and then with the */
/*          difference P*L*L'*P' - A (or P*U'*U*P' - A) */

/*  LDPERM  (input) INTEGER */
/*          The leading dimension of the array PERM. */
/*          LDAPERM >= max(1,N). */

/*  PIV     (input) INTEGER array, dimension (N) */
/*          PIV is such that the nonzero entries are */
/*          P( PIV( K ), K ) = 1. */

/*  RWORK   (workspace) DOUBLE PRECISION array, dimension (N) */

/*  RESID   (output) DOUBLE PRECISION */
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
	*resid = 0.;
	return 0;
    }

/*     Exit with RESID = 1/EPS if ANORM = 0. */

    eps = dlamch_("Epsilon");
    anorm = dlansy_("1", uplo, n, &a[a_offset], lda, &rwork[1]);
    if (anorm <= 0.) {
	*resid = 1. / eps;
	return 0;
    }

/*     Compute the product U'*U, overwriting U. */

    if (lsame_(uplo, "U")) {

	if (*rank < *n) {
	    i__1 = *n;
	    for (j = *rank + 1; j <= i__1; ++j) {
		i__2 = j;
		for (i__ = *rank + 1; i__ <= i__2; ++i__) {
		    afac[i__ + j * afac_dim1] = 0.;
/* L100: */
		}
/* L110: */
	    }
	}

	for (k = *n; k >= 1; --k) {

/*           Compute the (K,K) element of the result. */

	    t = ddot_(&k, &afac[k * afac_dim1 + 1], &c__1, &afac[k * 
		    afac_dim1 + 1], &c__1);
	    afac[k + k * afac_dim1] = t;

/*           Compute the rest of column K. */

	    i__1 = k - 1;
	    dtrmv_("Upper", "Transpose", "Non-unit", &i__1, &afac[afac_offset]
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
		    afac[i__ + j * afac_dim1] = 0.;
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
		dsyr_("Lower", &i__1, &c_b18, &afac[k + 1 + k * afac_dim1], &
			c__1, &afac[k + 1 + (k + 1) * afac_dim1], ldafac);
	    }

/*           Scale column K by the diagonal element. */

	    t = afac[k + k * afac_dim1];
	    i__1 = *n - k + 1;
	    dscal_(&i__1, &t, &afac[k + k * afac_dim1], &c__1);
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

    *resid = dlansy_("1", uplo, n, &perm[perm_offset], ldafac, &rwork[1]);

    *resid = *resid / (doublereal) (*n) / anorm / eps;

    return 0;

/*     End of DPST01 */

} /* dpst01_ */
