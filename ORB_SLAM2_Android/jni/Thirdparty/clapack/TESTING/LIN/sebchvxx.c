/* sebchvxx.f -- translated by f2c (version 20061008).
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

static integer c__6 = 6;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__7 = 7;
static integer c__8 = 8;

/* Subroutine */ int sebchvxx_(real *thresh, char *path)
{
    /* Format strings */
    static char fmt_8000[] = "(\002 S\002,a2,\002SVXX: N =\002,i2,\002, INFO"
	    " = \002,i3,\002, ORCOND = \002,g12.5,\002, real RCOND = \002,g12"
	    ".5)";
    static char fmt_9996[] = "(3x,i2,\002: Normwise guaranteed forward erro"
	    "r\002,/5x,\002Guaranteed case: if norm ( abs( Xc - Xt )\002,\002"
	    " / norm ( Xt ) .LE. ERRBND( *, nwise_i, bnd_i ), then\002,/5x"
	    ",\002ERRBND( *, nwise_i, bnd_i ) .LE. MAX(SQRT(N), 10) * EPS\002)"
	    ;
    static char fmt_9995[] = "(3x,i2,\002: Componentwise guaranteed forward "
	    "error\002)";
    static char fmt_9994[] = "(3x,i2,\002: Backwards error\002)";
    static char fmt_9993[] = "(3x,i2,\002: Reciprocal condition number\002)";
    static char fmt_9992[] = "(3x,i2,\002: Reciprocal normwise condition num"
	    "ber\002)";
    static char fmt_9991[] = "(3x,i2,\002: Raw normwise error estimate\002)";
    static char fmt_9990[] = "(3x,i2,\002: Reciprocal componentwise conditio"
	    "n number\002)";
    static char fmt_9989[] = "(3x,i2,\002: Raw componentwise error estimat"
	    "e\002)";
    static char fmt_9999[] = "(\002 S\002,a2,\002SVXX: N =\002,i2,\002, RHS "
	    "= \002,i2,\002, NWISE GUAR. = \002,a,\002, CWISE GUAR. = \002,a"
	    ",\002 test(\002,i1,\002) =\002,g12.5)";
    static char fmt_9998[] = "(\002 S\002,a2,\002SVXX: \002,i6,\002 out of"
	    " \002,i6,\002 tests failed to pass the threshold\002)";
    static char fmt_9997[] = "(\002 S\002,a2,\002SVXX passed the tests of er"
	    "ror bounds\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    real r__1, r__2, r__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsle(cilist *), e_wsle(void);

    /* Local variables */
    extern /* Subroutine */ int sposvxx_(char *, char *, integer *, integer *, 
	     real *, integer *, real *, integer *, char *, real *, real *, 
	    integer *, real *, integer *, real *, real *, real *, integer *, 
	    real *, real *, integer *, real *, real *, integer *, integer *), ssysvxx_(char *, char *, integer *, 
	    integer *, real *, integer *, real *, integer *, integer *, char *
, real *, real *, integer *, real *, integer *, real *, real *, 
	    real *, integer *, real *, real *, integer *, real *, real *, 
	    integer *, integer *);
    real errbnd_c__[18], errbnd_n__[18], a[36]	/* was [6][6] */, b[36]	/* 
	    was [6][6] */, c__[6];
    integer i__, j, k;
    real m;
    integer n;
    real r__[6], s[6], x[36]	/* was [6][6] */, cwise_bnd__;
    char c2[2];
    real nwise_bnd__, cwise_err__, nwise_err__, errthresh, ab[66]	/* 
	    was [11][6] */, af[36]	/* was [6][6] */;
    integer kl, ku;
    real condthresh, afb[96]	/* was [16][6] */;
    integer lda;
    real eps, cwise_rcond__, nwise_rcond__;
    integer n_aux_tests__, ldab;
    real diff[36]	/* was [6][6] */;
    char fact[1];
    real berr[6];
    integer info, ipiv[6], nrhs;
    real rinv[6];
    char uplo[1];
    real work[30], sumr;
    integer ldafb;
    real ccond;
    integer nfail;
    char cguar[3];
    real ncond;
    char equed[1];
    real rcond, acopy[36]	/* was [6][6] */;
    char nguar[3], trans[1];
    integer iwork[6];
    real rnorm, normt, sumri;
    logical printed_guide__;
    extern doublereal slamch_(char *);
    real abcopy[66]	/* was [11][6] */;
    extern logical lsamen_(integer *, char *, char *);
    real params[2], orcond;
    extern /* Subroutine */ int slacpy_(char *, integer *, integer *, real *, 
	    integer *, real *, integer *);
    real rinorm, tstrat[6], rpvgrw;
    extern /* Subroutine */ int slahilb_(integer *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *, real *, integer *
);
    real invhilb[36]	/* was [6][6] */, normdif;
    extern /* Subroutine */ int sgbsvxx_(char *, char *, integer *, integer *, 
	     integer *, integer *, real *, integer *, real *, integer *, 
	    integer *, char *, real *, real *, real *, integer *, real *, 
	    integer *, real *, real *, real *, integer *, real *, real *, 
	    integer *, real *, real *, integer *, integer *), sgesvxx_(char *, char *, integer *, integer *, real *, 
	    integer *, real *, integer *, integer *, char *, real *, real *, 
	    real *, integer *, real *, integer *, real *, real *, real *, 
	    integer *, real *, real *, integer *, real *, real *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___42 = { 0, 6, 0, fmt_8000, 0 };
    static cilist io___66 = { 0, 6, 0, 0, 0 };
    static cilist io___67 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___68 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_9994, 0 };
    static cilist io___70 = { 0, 6, 0, fmt_9993, 0 };
    static cilist io___71 = { 0, 6, 0, fmt_9992, 0 };
    static cilist io___72 = { 0, 6, 0, fmt_9991, 0 };
    static cilist io___73 = { 0, 6, 0, fmt_9990, 0 };
    static cilist io___74 = { 0, 6, 0, fmt_9989, 0 };
    static cilist io___75 = { 0, 6, 0, 0, 0 };
    static cilist io___76 = { 0, 6, 0, fmt_9999, 0 };
    static cilist io___77 = { 0, 6, 0, 0, 0 };
    static cilist io___78 = { 0, 6, 0, fmt_9998, 0 };
    static cilist io___79 = { 0, 6, 0, fmt_9997, 0 };


/*     .. Scalar Arguments .. */

/*  Purpose */
/*  ====== */

/*  SEBCHVXX will run S**SVXX on a series of Hilbert matrices and then */
/*  compare the error bounds returned by SGESVXX to see if the returned */
/*  answer indeed falls within those bounds. */

/*  Eight test ratios will be computed.  The tests will pass if they are .LT. */
/*  THRESH.  There are two cases that are determined by 1 / (SQRT( N ) * EPS). */
/*  If that value is .LE. to the component wise reciprocal condition number, */
/*  it uses the guaranteed case, other wise it uses the unguaranteed case. */

/*  Test ratios: */
/*     Let Xc be X_computed and Xt be X_truth. */
/*     The norm used is the infinity norm. */
/*     Let A be the guaranteed case and B be the unguaranteed case. */

/*       1. Normwise guaranteed forward error bound. */
/*       A: norm ( abs( Xc - Xt ) / norm ( Xt ) .LE. ERRBND( *, nwise_i, bnd_i ) and */
/*          ERRBND( *, nwise_i, bnd_i ) .LE. MAX(SQRT(N),10) * EPS. */
/*          If these conditions are met, the test ratio is set to be */
/*          ERRBND( *, nwise_i, bnd_i ) / MAX(SQRT(N), 10).  Otherwise it is 1/EPS. */
/*       B: For this case, SGESVXX should just return 1.  If it is less than */
/*          one, treat it the same as in 1A.  Otherwise it fails. (Set test */
/*          ratio to ERRBND( *, nwise_i, bnd_i ) * THRESH?) */

/*       2. Componentwise guaranteed forward error bound. */
/*       A: norm ( abs( Xc(j) - Xt(j) ) ) / norm (Xt(j)) .LE. ERRBND( *, cwise_i, bnd_i ) */
/*          for all j .AND. ERRBND( *, cwise_i, bnd_i ) .LE. MAX(SQRT(N), 10) * EPS. */
/*          If these conditions are met, the test ratio is set to be */
/*          ERRBND( *, cwise_i, bnd_i ) / MAX(SQRT(N), 10).  Otherwise it is 1/EPS. */
/*       B: Same as normwise test ratio. */

/*       3. Backwards error. */
/*       A: The test ratio is set to BERR/EPS. */
/*       B: Same test ratio. */

/*       4. Reciprocal condition number. */
/*       A: A condition number is computed with Xt and compared with the one */
/*          returned from SGESVXX.  Let RCONDc be the RCOND returned by SGESVXX */
/*          and RCONDt be the RCOND from the truth value.  Test ratio is set to */
/*          MAX(RCONDc/RCONDt, RCONDt/RCONDc). */
/*       B: Test ratio is set to 1 / (EPS * RCONDc). */

/*       5. Reciprocal normwise condition number. */
/*       A: The test ratio is set to */
/*          MAX(ERRBND( *, nwise_i, cond_i ) / NCOND, NCOND / ERRBND( *, nwise_i, cond_i )). */
/*       B: Test ratio is set to 1 / (EPS * ERRBND( *, nwise_i, cond_i )). */

/*       7. Reciprocal componentwise condition number. */
/*       A: Test ratio is set to */
/*          MAX(ERRBND( *, cwise_i, cond_i ) / CCOND, CCOND / ERRBND( *, cwise_i, cond_i )). */
/*       B: Test ratio is set to 1 / (EPS * ERRBND( *, cwise_i, cond_i )). */

/*     .. Parameters .. */
/*     NMAX is determined by the largest number in the inverse of the Hilbert */
/*     matrix.  Precision is exhausted when the largest entry in it is greater */
/*     than 2 to the power of the number of bits in the fraction of the data */
/*     type used plus one, which is 24 for single precision. */
/*     NMAX should be 6 for single and 11 for double. */
/*     .. Local Scalars .. */
/*     .. Local Arrays .. */
/*     .. External Functions .. */
/*     .. External Subroutines .. */
/*     .. Intrinsic Functions .. */
/*     .. Parameters .. */
/*     Create the loop to test out the Hilbert matrices */
    *(unsigned char *)fact = 'E';
    *(unsigned char *)uplo = 'U';
    *(unsigned char *)trans = 'N';
    *(unsigned char *)equed = 'N';
    eps = slamch_("Epsilon");
    nfail = 0;
    n_aux_tests__ = 0;
    lda = 6;
    ldab = 11;
    ldafb = 16;
    s_copy(c2, path + 1, (ftnlen)2, (ftnlen)2);
/*     Main loop to test the different Hilbert Matrices. */
    printed_guide__ = FALSE_;
    for (n = 1; n <= 6; ++n) {
	params[0] = -1.f;
	params[1] = -1.f;
	kl = n - 1;
	ku = n - 1;
	nrhs = n;
/* Computing MAX */
	r__1 = sqrt((real) n);
	m = dmax(r__1,10.f);
/*        Generate the Hilbert matrix, its inverse, and the */
/*        right hand side, all scaled by the LCM(1,..,2N-1). */
	slahilb_(&n, &n, a, &lda, invhilb, &lda, b, &lda, work, &info);
/*        Copy A into ACOPY. */
	slacpy_("ALL", &n, &n, a, &c__6, acopy, &c__6);
/*        Store A in band format for GB tests */
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = kl + ku + 1;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		ab[i__ + j * 11 - 12] = 0.f;
	    }
	}
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
/* Computing MAX */
	    i__2 = 1, i__3 = j - ku;
/* Computing MIN */
	    i__5 = n, i__6 = j + kl;
	    i__4 = min(i__5,i__6);
	    for (i__ = max(i__2,i__3); i__ <= i__4; ++i__) {
		ab[ku + 1 + i__ - j + j * 11 - 12] = a[i__ + j * 6 - 7];
	    }
	}
/*        Copy AB into ABCOPY. */
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    i__4 = kl + ku + 1;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		abcopy[i__ + j * 11 - 12] = 0.f;
	    }
	}
	i__1 = kl + ku + 1;
	slacpy_("ALL", &i__1, &n, ab, &ldab, abcopy, &ldab);
/*        Call S**SVXX with default PARAMS and N_ERR_BND = 3. */
	if (lsamen_(&c__2, c2, "SY")) {
	    ssysvxx_(fact, uplo, &n, &nrhs, acopy, &lda, af, &lda, ipiv, 
		    equed, s, b, &lda, x, &lda, &orcond, &rpvgrw, berr, &c__3, 
		     errbnd_n__, errbnd_c__, &c__2, params, work, iwork, &
		    info);
	} else if (lsamen_(&c__2, c2, "PO")) {
	    sposvxx_(fact, uplo, &n, &nrhs, acopy, &lda, af, &lda, equed, s, 
		    b, &lda, x, &lda, &orcond, &rpvgrw, berr, &c__3, 
		    errbnd_n__, errbnd_c__, &c__2, params, work, iwork, &info);
	} else if (lsamen_(&c__2, c2, "GB")) {
	    sgbsvxx_(fact, trans, &n, &kl, &ku, &nrhs, abcopy, &ldab, afb, &
		    ldafb, ipiv, equed, r__, c__, b, &lda, x, &lda, &orcond, &
		    rpvgrw, berr, &c__3, errbnd_n__, errbnd_c__, &c__2, 
		    params, work, iwork, &info);
	} else {
	    sgesvxx_(fact, trans, &n, &nrhs, acopy, &lda, af, &lda, ipiv, 
		    equed, r__, c__, b, &lda, x, &lda, &orcond, &rpvgrw, berr, 
		     &c__3, errbnd_n__, errbnd_c__, &c__2, params, work, 
		    iwork, &info);
	}
	++n_aux_tests__;
	if (orcond < eps) {
/*        Either factorization failed or the matrix is flagged, and 1 <= */
/*        INFO <= N+1. We don't decide based on rcond anymore. */
/*            IF (INFO .EQ. 0 .OR. INFO .GT. N+1) THEN */
/*               NFAIL = NFAIL + 1 */
/*               WRITE (*, FMT=8000) N, INFO, ORCOND, RCOND */
/*            END IF */
	} else {
/*        Either everything succeeded (INFO == 0) or some solution failed */
/*        to converge (INFO > N+1). */
	    if (info > 0 && info <= n + 1) {
		++nfail;
		s_wsfe(&io___42);
		do_fio(&c__1, c2, (ftnlen)2);
		do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&info, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&orcond, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&rcond, (ftnlen)sizeof(real));
		e_wsfe();
	    }
	}
/*        Calculating the difference between S**SVXX's X and the true X. */
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__4 = nrhs;
	    for (j = 1; j <= i__4; ++j) {
		diff[i__ + j * 6 - 7] = x[i__ + j * 6 - 7] - invhilb[i__ + j *
			 6 - 7];
	    }
	}
/*        Calculating the RCOND */
	rnorm = 0.f;
	rinorm = 0.f;
	if (lsamen_(&c__2, c2, "PO") || lsamen_(&c__2, 
		c2, "SY")) {
	    i__1 = n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		sumr = 0.f;
		sumri = 0.f;
		i__4 = n;
		for (j = 1; j <= i__4; ++j) {
		    sumr += (r__1 = s[i__ - 1] * a[i__ + j * 6 - 7] * s[j - 1]
			    , dabs(r__1));
		    sumri += (r__1 = invhilb[i__ + j * 6 - 7] / s[j - 1] / s[
			    i__ - 1], dabs(r__1));
		}
		rnorm = dmax(rnorm,sumr);
		rinorm = dmax(rinorm,sumri);
	    }
	} else if (lsamen_(&c__2, c2, "GE") || lsamen_(&
		c__2, c2, "GB")) {
	    i__1 = n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		sumr = 0.f;
		sumri = 0.f;
		i__4 = n;
		for (j = 1; j <= i__4; ++j) {
		    sumr += (r__1 = r__[i__ - 1] * a[i__ + j * 6 - 7] * c__[j 
			    - 1], dabs(r__1));
		    sumri += (r__1 = invhilb[i__ + j * 6 - 7] / r__[j - 1] / 
			    c__[i__ - 1], dabs(r__1));
		}
		rnorm = dmax(rnorm,sumr);
		rinorm = dmax(rinorm,sumri);
	    }
	}
	rnorm /= a[0];
	rcond = 1.f / (rnorm * rinorm);
/*        Calculating the R for normwise rcond. */
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    rinv[i__ - 1] = 0.f;
	}
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		rinv[i__ - 1] += (r__1 = a[i__ + j * 6 - 7], dabs(r__1));
	    }
	}
/*        Calculating the Normwise rcond. */
	rinorm = 0.f;
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    sumri = 0.f;
	    i__4 = n;
	    for (j = 1; j <= i__4; ++j) {
		sumri += (r__1 = invhilb[i__ + j * 6 - 7] * rinv[j - 1], dabs(
			r__1));
	    }
	    rinorm = dmax(rinorm,sumri);
	}
/*        invhilb is the inverse *unscaled* Hilbert matrix, so scale its norm */
/*        by 1/A(1,1) to make the scaling match A (the scaled Hilbert matrix) */
	ncond = a[0] / rinorm;
	condthresh = m * eps;
	errthresh = m * eps;
	i__1 = nrhs;
	for (k = 1; k <= i__1; ++k) {
	    normt = 0.f;
	    normdif = 0.f;
	    cwise_err__ = 0.f;
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
/* Computing MAX */
		r__2 = (r__1 = invhilb[i__ + k * 6 - 7], dabs(r__1));
		normt = dmax(r__2,normt);
/* Computing MAX */
		r__2 = (r__1 = x[i__ + k * 6 - 7] - invhilb[i__ + k * 6 - 7], 
			dabs(r__1));
		normdif = dmax(r__2,normdif);
		if (invhilb[i__ + k * 6 - 7] != 0.f) {
/* Computing MAX */
		    r__3 = (r__1 = x[i__ + k * 6 - 7] - invhilb[i__ + k * 6 - 
			    7], dabs(r__1)) / (r__2 = invhilb[i__ + k * 6 - 7]
			    , dabs(r__2));
		    cwise_err__ = dmax(r__3,cwise_err__);
		} else if (x[i__ + k * 6 - 7] != 0.f) {
		    cwise_err__ = slamch_("OVERFLOW");
		}
	    }
	    if (normt != 0.f) {
		nwise_err__ = normdif / normt;
	    } else if (normdif != 0.f) {
		nwise_err__ = slamch_("OVERFLOW");
	    } else {
		nwise_err__ = 0.f;
	    }
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		rinv[i__ - 1] = 0.f;
	    }
	    i__4 = n;
	    for (j = 1; j <= i__4; ++j) {
		i__2 = n;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    rinv[i__ - 1] += (r__1 = a[i__ + j * 6 - 7] * invhilb[j + 
			    k * 6 - 7], dabs(r__1));
		}
	    }
	    rinorm = 0.f;
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		sumri = 0.f;
		i__2 = n;
		for (j = 1; j <= i__2; ++j) {
		    sumri += (r__1 = invhilb[i__ + j * 6 - 7] * rinv[j - 1] / 
			    invhilb[i__ + k * 6 - 7], dabs(r__1));
		}
		rinorm = dmax(rinorm,sumri);
	    }
/*        invhilb is the inverse *unscaled* Hilbert matrix, so scale its norm */
/*        by 1/A(1,1) to make the scaling match A (the scaled Hilbert matrix) */
	    ccond = a[0] / rinorm;
/*        Forward error bound tests */
	    nwise_bnd__ = errbnd_n__[k + nrhs - 1];
	    cwise_bnd__ = errbnd_c__[k + nrhs - 1];
	    nwise_rcond__ = errbnd_n__[k + (nrhs << 1) - 1];
	    cwise_rcond__ = errbnd_c__[k + (nrhs << 1) - 1];
/*            write (*,*) 'nwise : ', n, k, ncond, nwise_rcond, */
/*     $           condthresh, ncond.ge.condthresh */
/*            write (*,*) 'nwise2: ', k, nwise_bnd, nwise_err, errthresh */
	    if (ncond >= condthresh) {
		s_copy(nguar, "YES", (ftnlen)3, (ftnlen)3);
		if (nwise_bnd__ > errthresh) {
		    tstrat[0] = 1 / (eps * 2.f);
		} else {
		    if (nwise_bnd__ != 0.f) {
			tstrat[0] = nwise_err__ / nwise_bnd__;
		    } else if (nwise_err__ != 0.f) {
			tstrat[0] = 1 / (eps * 16.f);
		    } else {
			tstrat[0] = 0.f;
		    }
		    if (tstrat[0] > 1.f) {
			tstrat[0] = 1 / (eps * 4.f);
		    }
		}
	    } else {
		s_copy(nguar, "NO", (ftnlen)3, (ftnlen)2);
		if (nwise_bnd__ < 1.f) {
		    tstrat[0] = 1 / (eps * 8.f);
		} else {
		    tstrat[0] = 1.f;
		}
	    }
/*            write (*,*) 'cwise : ', n, k, ccond, cwise_rcond, */
/*     $           condthresh, ccond.ge.condthresh */
/*            write (*,*) 'cwise2: ', k, cwise_bnd, cwise_err, errthresh */
	    if (ccond >= condthresh) {
		s_copy(cguar, "YES", (ftnlen)3, (ftnlen)3);
		if (cwise_bnd__ > errthresh) {
		    tstrat[1] = 1 / (eps * 2.f);
		} else {
		    if (cwise_bnd__ != 0.f) {
			tstrat[1] = cwise_err__ / cwise_bnd__;
		    } else if (cwise_err__ != 0.f) {
			tstrat[1] = 1 / (eps * 16.f);
		    } else {
			tstrat[1] = 0.f;
		    }
		    if (tstrat[1] > 1.f) {
			tstrat[1] = 1 / (eps * 4.f);
		    }
		}
	    } else {
		s_copy(cguar, "NO", (ftnlen)3, (ftnlen)2);
		if (cwise_bnd__ < 1.f) {
		    tstrat[1] = 1 / (eps * 8.f);
		} else {
		    tstrat[1] = 1.f;
		}
	    }
/*     Backwards error test */
	    tstrat[2] = berr[k - 1] / eps;
/*     Condition number tests */
	    tstrat[3] = rcond / orcond;
	    if (rcond >= condthresh && tstrat[3] < 1.f) {
		tstrat[3] = 1.f / tstrat[3];
	    }
	    tstrat[4] = ncond / nwise_rcond__;
	    if (ncond >= condthresh && tstrat[4] < 1.f) {
		tstrat[4] = 1.f / tstrat[4];
	    }
	    tstrat[5] = ccond / nwise_rcond__;
	    if (ccond >= condthresh && tstrat[5] < 1.f) {
		tstrat[5] = 1.f / tstrat[5];
	    }
	    for (i__ = 1; i__ <= 6; ++i__) {
		if (tstrat[i__ - 1] > *thresh) {
		    if (! printed_guide__) {
			s_wsle(&io___66);
			e_wsle();
			s_wsfe(&io___67);
			do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___68);
			do_fio(&c__1, (char *)&c__2, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___69);
			do_fio(&c__1, (char *)&c__3, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___70);
			do_fio(&c__1, (char *)&c__4, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___71);
			do_fio(&c__1, (char *)&c__5, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___72);
			do_fio(&c__1, (char *)&c__6, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___73);
			do_fio(&c__1, (char *)&c__7, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___74);
			do_fio(&c__1, (char *)&c__8, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsle(&io___75);
			e_wsle();
			printed_guide__ = TRUE_;
		    }
		    s_wsfe(&io___76);
		    do_fio(&c__1, c2, (ftnlen)2);
		    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
		    do_fio(&c__1, nguar, (ftnlen)3);
		    do_fio(&c__1, cguar, (ftnlen)3);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&tstrat[i__ - 1], (ftnlen)sizeof(
			    real));
		    e_wsfe();
		    ++nfail;
		}
	    }
	}
/* $$$         WRITE(*,*) */
/* $$$         WRITE(*,*) 'Normwise Error Bounds' */
/* $$$         WRITE(*,*) 'Guaranteed error bound: ',ERRBND(NRHS,nwise_i,bnd_i) */
/* $$$         WRITE(*,*) 'Reciprocal condition number: ',ERRBND(NRHS,nwise_i,cond_i) */
/* $$$         WRITE(*,*) 'Raw error estimate: ',ERRBND(NRHS,nwise_i,rawbnd_i) */
/* $$$         WRITE(*,*) */
/* $$$         WRITE(*,*) 'Componentwise Error Bounds' */
/* $$$         WRITE(*,*) 'Guaranteed error bound: ',ERRBND(NRHS,cwise_i,bnd_i) */
/* $$$         WRITE(*,*) 'Reciprocal condition number: ',ERRBND(NRHS,cwise_i,cond_i) */
/* $$$         WRITE(*,*) 'Raw error estimate: ',ERRBND(NRHS,cwise_i,rawbnd_i) */
/* $$$         print *, 'Info: ', info */
/* $$$         WRITE(*,*) */
/*         WRITE(*,*) 'TSTRAT: ',TSTRAT */
    }
    s_wsle(&io___77);
    e_wsle();
    if (nfail > 0) {
	s_wsfe(&io___78);
	do_fio(&c__1, c2, (ftnlen)2);
	do_fio(&c__1, (char *)&nfail, (ftnlen)sizeof(integer));
	i__1 = n * 6 + n_aux_tests__;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	s_wsfe(&io___79);
	do_fio(&c__1, c2, (ftnlen)2);
	e_wsfe();
    }
/*     Test ratios. */
    return 0;
} /* sebchvxx_ */
