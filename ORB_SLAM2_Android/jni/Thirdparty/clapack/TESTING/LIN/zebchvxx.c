/* zebchvxx.f -- translated by f2c (version 20061008).
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

static integer c__10 = 10;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__8 = 8;

/* Subroutine */ int zebchvxx_(doublereal *thresh, char *path)
{
    /* Format strings */
    static char fmt_8000[] = "(\002 Z\002,a2,\002SVXX: N =\002,i2,\002, INFO"
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
    static char fmt_9999[] = "(\002 Z\002,a2,\002SVXX: N =\002,i2,\002, RHS "
	    "= \002,i2,\002, NWISE GUAR. = \002,a,\002, CWISE GUAR. = \002,a"
	    ",\002 test(\002,i1,\002) =\002,g12.5)";
    static char fmt_9998[] = "(\002 Z\002,a2,\002SVXX: \002,i6,\002 out of"
	    " \002,i6,\002 tests failed to pass the threshold\002)";
    static char fmt_9997[] = "(\002 Z\002,a2,\002SVXX passed the tests of er"
	    "ror bounds\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    doublereal d__1, d__2, d__3, d__4, d__5;
    doublecomplex z__1, z__2, z__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double d_imag(doublecomplex *);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);
    integer s_wsle(cilist *), e_wsle(void);

    /* Local variables */
    extern /* Subroutine */ int zposvxx_(char *, char *, integer *, integer *, 
	     doublecomplex *, integer *, doublecomplex *, integer *, char *, 
	    doublereal *, doublecomplex *, integer *, doublecomplex *, 
	    integer *, doublereal *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, 
	    doublecomplex *, doublereal *, integer *);
    doublereal errbnd_c__[30];
    extern /* Subroutine */ int zsysvxx_(char *, char *, integer *, integer *, 
	     doublecomplex *, integer *, doublecomplex *, integer *, integer *
, char *, doublereal *, doublecomplex *, integer *, doublecomplex 
	    *, integer *, doublereal *, doublereal *, doublereal *, integer *, 
	     doublereal *, doublereal *, integer *, doublereal *, 
	    doublecomplex *, doublereal *, integer *);
    doublereal errbnd_n__[30];
    doublecomplex a[100]	/* was [10][10] */, b[100]	/* was [10][
	    10] */;
    doublereal c__[10];
    integer i__, j, k;
    doublereal m;
    integer n;
    doublereal r__[10], s[10];
    doublecomplex x[100]	/* was [10][10] */;
    doublereal cwise_bnd__;
    char c2[2];
    doublereal nwise_bnd__, cwise_err__, nwise_err__, errthresh;
    doublecomplex ab[190]	/* was [19][10] */, af[100]	/* was [10][
	    10] */;
    integer kl, ku;
    doublereal condthresh;
    doublecomplex afb[280]	/* was [28][10] */;
    integer lda;
    doublereal eps, cwise_rcond__, nwise_rcond__;
    integer n_aux_tests__, ldab;
    doublereal diff[100]	/* was [10][10] */;
    char fact[1];
    doublereal berr[10];
    integer info, ipiv[10], nrhs;
    doublereal rinv[10];
    char uplo[1];
    doublecomplex work[150];
    doublereal sumr;
    integer ldafb;
    doublereal ccond;
    integer nfail;
    char cguar[3];
    doublereal ncond;
    char equed[1];
    doublereal rcond;
    doublecomplex acopy[100]	/* was [10][10] */;
    char nguar[3], trans[1];
    doublereal rnorm, normt, sumri, rwork[30];
    logical printed_guide__;
    extern doublereal dlamch_(char *);
    doublecomplex abcopy[190]	/* was [19][10] */;
    extern logical lsamen_(integer *, char *, char *);
    doublereal params[2], orcond;
    extern /* Subroutine */ int zlacpy_(char *, integer *, integer *, 
	    doublecomplex *, integer *, doublecomplex *, integer *);
    doublereal rinorm, tstrat[6], rpvgrw;
    extern /* Subroutine */ int zlahilb_(integer *, integer *, doublecomplex *
, integer *, doublecomplex *, integer *, doublecomplex *, integer 
	    *, doublecomplex *, integer *, char *);
    doublecomplex invhilb[100]	/* was [10][10] */;
    doublereal normdif;
    extern /* Subroutine */ int zgbsvxx_(char *, char *, integer *, integer *, 
	     integer *, integer *, doublecomplex *, integer *, doublecomplex *
, integer *, integer *, char *, doublereal *, doublereal *, 
	    doublecomplex *, integer *, doublecomplex *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *, 
	     doublereal *, integer *, doublereal *, doublecomplex *, 
	    doublereal *, integer *), zgesvxx_(char *, 
	     char *, integer *, integer *, doublecomplex *, integer *, 
	    doublecomplex *, integer *, integer *, char *, doublereal *, 
	    doublereal *, doublecomplex *, integer *, doublecomplex *, 
	    integer *, doublereal *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, 
	    doublecomplex *, doublereal *, integer *),
	     zhesvxx_(char *, char *, integer *, integer *, doublecomplex *, 
	    integer *, doublecomplex *, integer *, integer *, char *, 
	    doublereal *, doublecomplex *, integer *, doublecomplex *, 
	    integer *, doublereal *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, 
	    doublecomplex *, doublereal *, integer *);

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

/*  ZEBCHVXX will run Z**SVXX on a series of Hilbert matrices and then */
/*  compare the error bounds returned by Z**SVXX to see if the returned */
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
/*       B: For this case, CGESVXX should just return 1.  If it is less than */
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
/*          returned from CGESVXX.  Let RCONDc be the RCOND returned by CGESVXX */
/*          and RCONDt be the RCOND from the truth value.  Test ratio is set to */
/*          MAX(RCONDc/RCONDt, RCONDt/RCONDc). */
/*       B: Test ratio is set to 1 / (EPS * RCONDc). */

/*       5. Reciprocal normwise condition number. */
/*       A: The test ratio is set to */
/*          MAX(ERRBND( *, nwise_i, cond_i ) / NCOND, NCOND / ERRBND( *, nwise_i, cond_i )). */
/*       B: Test ratio is set to 1 / (EPS * ERRBND( *, nwise_i, cond_i )). */

/*       6. Reciprocal componentwise condition number. */
/*       A: Test ratio is set to */
/*          MAX(ERRBND( *, cwise_i, cond_i ) / CCOND, CCOND / ERRBND( *, cwise_i, cond_i )). */
/*       B: Test ratio is set to 1 / (EPS * ERRBND( *, cwise_i, cond_i )). */

/*     .. Parameters .. */
/*     NMAX is determined by the largest number in the inverse of the hilbert */
/*     matrix.  Precision is exhausted when the largest entry in it is greater */
/*     than 2 to the power of the number of bits in the fraction of the data */
/*     type used plus one, which is 24 for single precision. */
/*     NMAX should be 6 for single and 11 for double. */
/*     .. Local Scalars .. */
/*     .. Local Arrays .. */
/*     .. External Functions .. */
/*     .. External Subroutines .. */
/*     .. Intrinsic Functions .. */
/*     .. Statement Functions .. */
/*     .. Statement Function Definitions .. */
/*     .. Parameters .. */
/*  Create the loop to test out the Hilbert matrices */
    *(unsigned char *)fact = 'E';
    *(unsigned char *)uplo = 'U';
    *(unsigned char *)trans = 'N';
    *(unsigned char *)equed = 'N';
    eps = dlamch_("Epsilon");
    nfail = 0;
    n_aux_tests__ = 0;
    lda = 10;
    ldab = 19;
    ldafb = 28;
    s_copy(c2, path + 1, (ftnlen)2, (ftnlen)2);
/*     Main loop to test the different Hilbert Matrices. */
    printed_guide__ = FALSE_;
    for (n = 1; n <= 10; ++n) {
	params[0] = -1.;
	params[1] = -1.;
	kl = n - 1;
	ku = n - 1;
	nrhs = n;
/* Computing MAX */
	d__1 = sqrt((doublereal) n);
	m = max(d__1,10.);
/*        Generate the Hilbert matrix, its inverse, and the */
/*        right hand side, all scaled by the LCM(1,..,2N-1). */
	zlahilb_(&n, &n, a, &lda, invhilb, &lda, b, &lda, work, &info, path);
/*        Copy A into ACOPY. */
	zlacpy_("ALL", &n, &n, a, &c__10, acopy, &c__10);
/*        Store A in band format for GB tests */
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = kl + ku + 1;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__3 = i__ + j * 19 - 20;
		ab[i__3].r = 0., ab[i__3].i = 0.;
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
		i__2 = ku + 1 + i__ - j + j * 19 - 20;
		i__3 = i__ + j * 10 - 11;
		ab[i__2].r = a[i__3].r, ab[i__2].i = a[i__3].i;
	    }
	}
/*        Copy AB into ABCOPY. */
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    i__4 = kl + ku + 1;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__2 = i__ + j * 19 - 20;
		abcopy[i__2].r = 0., abcopy[i__2].i = 0.;
	    }
	}
	i__1 = kl + ku + 1;
	zlacpy_("ALL", &i__1, &n, ab, &ldab, abcopy, &ldab);
/*        Call Z**SVXX with default PARAMS and N_ERR_BND = 3. */
	if (lsamen_(&c__2, c2, "SY")) {
	    zsysvxx_(fact, uplo, &n, &nrhs, acopy, &lda, af, &lda, ipiv, 
		    equed, s, b, &lda, x, &lda, &orcond, &rpvgrw, berr, &c__3, 
		     errbnd_n__, errbnd_c__, &c__2, params, work, rwork, &
		    info);
	} else if (lsamen_(&c__2, c2, "PO")) {
	    zposvxx_(fact, uplo, &n, &nrhs, acopy, &lda, af, &lda, equed, s, 
		    b, &lda, x, &lda, &orcond, &rpvgrw, berr, &c__3, 
		    errbnd_n__, errbnd_c__, &c__2, params, work, rwork, &info);
	} else if (lsamen_(&c__2, c2, "HE")) {
	    zhesvxx_(fact, uplo, &n, &nrhs, acopy, &lda, af, &lda, ipiv, 
		    equed, s, b, &lda, x, &lda, &orcond, &rpvgrw, berr, &c__3, 
		     errbnd_n__, errbnd_c__, &c__2, params, work, rwork, &
		    info);
	} else if (lsamen_(&c__2, c2, "GB")) {
	    zgbsvxx_(fact, trans, &n, &kl, &ku, &nrhs, abcopy, &ldab, afb, &
		    ldafb, ipiv, equed, r__, c__, b, &lda, x, &lda, &orcond, &
		    rpvgrw, berr, &c__3, errbnd_n__, errbnd_c__, &c__2, 
		    params, work, rwork, &info);
	} else {
	    zgesvxx_(fact, trans, &n, &nrhs, acopy, &lda, af, &lda, ipiv, 
		    equed, r__, c__, b, &lda, x, &lda, &orcond, &rpvgrw, berr, 
		     &c__3, errbnd_n__, errbnd_c__, &c__2, params, work, 
		    rwork, &info);
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
		do_fio(&c__1, (char *)&orcond, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&rcond, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	}
/*        Calculating the difference between Z**SVXX's X and the true X. */
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__4 = nrhs;
	    for (j = 1; j <= i__4; ++j) {
		i__2 = i__ + j * 10 - 11;
		i__3 = i__ + j * 10 - 11;
		i__5 = i__ + j * 10 - 11;
		z__1.r = x[i__3].r - invhilb[i__5].r, z__1.i = x[i__3].i - 
			invhilb[i__5].i;
		diff[i__2] = z__1.r;
	    }
	}
/*        Calculating the RCOND */
	rnorm = 0.;
	rinorm = 0.;
	if (lsamen_(&c__2, c2, "PO") || lsamen_(&c__2, 
		c2, "SY") || lsamen_(&c__2, c2, "HE")) {
	    i__1 = n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		sumr = 0.;
		sumri = 0.;
		i__4 = n;
		for (j = 1; j <= i__4; ++j) {
		    i__2 = i__ + j * 10 - 11;
		    sumr += s[i__ - 1] * ((d__1 = a[i__2].r, abs(d__1)) + (
			    d__2 = d_imag(&a[i__ + j * 10 - 11]), abs(d__2))) 
			    * s[j - 1];
		    i__2 = i__ + j * 10 - 11;
		    sumri += ((d__1 = invhilb[i__2].r, abs(d__1)) + (d__2 = 
			    d_imag(&invhilb[i__ + j * 10 - 11]), abs(d__2))) /
			     (s[j - 1] * s[i__ - 1]);
		}
		rnorm = max(rnorm,sumr);
		rinorm = max(rinorm,sumri);
	    }
	} else if (lsamen_(&c__2, c2, "GE") || lsamen_(&
		c__2, c2, "GB")) {
	    i__1 = n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		sumr = 0.;
		sumri = 0.;
		i__4 = n;
		for (j = 1; j <= i__4; ++j) {
		    i__2 = i__ + j * 10 - 11;
		    sumr += r__[i__ - 1] * ((d__1 = a[i__2].r, abs(d__1)) + (
			    d__2 = d_imag(&a[i__ + j * 10 - 11]), abs(d__2))) 
			    * c__[j - 1];
		    i__2 = i__ + j * 10 - 11;
		    sumri += ((d__1 = invhilb[i__2].r, abs(d__1)) + (d__2 = 
			    d_imag(&invhilb[i__ + j * 10 - 11]), abs(d__2))) /
			     (r__[j - 1] * c__[i__ - 1]);
		}
		rnorm = max(rnorm,sumr);
		rinorm = max(rinorm,sumri);
	    }
	}
	rnorm /= (d__1 = a[0].r, abs(d__1)) + (d__2 = d_imag(a), abs(d__2));
	rcond = 1. / (rnorm * rinorm);
/*        Calculating the R for normwise rcond. */
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    rinv[i__ - 1] = 0.;
	}
	i__1 = n;
	for (j = 1; j <= i__1; ++j) {
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__2 = i__ + j * 10 - 11;
		rinv[i__ - 1] += (d__1 = a[i__2].r, abs(d__1)) + (d__2 = 
			d_imag(&a[i__ + j * 10 - 11]), abs(d__2));
	    }
	}
/*        Calculating the Normwise rcond. */
	rinorm = 0.;
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    sumri = 0.;
	    i__4 = n;
	    for (j = 1; j <= i__4; ++j) {
		i__2 = i__ + j * 10 - 11;
		i__3 = j - 1;
		z__2.r = rinv[i__3] * invhilb[i__2].r, z__2.i = rinv[i__3] * 
			invhilb[i__2].i;
		z__1.r = z__2.r, z__1.i = z__2.i;
		sumri += (d__1 = z__1.r, abs(d__1)) + (d__2 = d_imag(&z__1), 
			abs(d__2));
	    }
	    rinorm = max(rinorm,sumri);
	}
/*        invhilb is the inverse *unscaled* Hilbert matrix, so scale its norm */
/*        by 1/A(1,1) to make the scaling match A (the scaled Hilbert matrix) */
	ncond = ((d__1 = a[0].r, abs(d__1)) + (d__2 = d_imag(a), abs(d__2))) /
		 rinorm;
	condthresh = m * eps;
	errthresh = m * eps;
	i__1 = nrhs;
	for (k = 1; k <= i__1; ++k) {
	    normt = 0.;
	    normdif = 0.;
	    cwise_err__ = 0.;
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
/* Computing MAX */
		i__2 = i__ + k * 10 - 11;
		d__3 = (d__1 = invhilb[i__2].r, abs(d__1)) + (d__2 = d_imag(&
			invhilb[i__ + k * 10 - 11]), abs(d__2));
		normt = max(d__3,normt);
		i__2 = i__ + k * 10 - 11;
		i__3 = i__ + k * 10 - 11;
		z__2.r = x[i__2].r - invhilb[i__3].r, z__2.i = x[i__2].i - 
			invhilb[i__3].i;
		z__1.r = z__2.r, z__1.i = z__2.i;
/* Computing MAX */
		d__3 = (d__1 = z__1.r, abs(d__1)) + (d__2 = d_imag(&z__1), 
			abs(d__2));
		normdif = max(d__3,normdif);
		i__2 = i__ + k * 10 - 11;
		if (invhilb[i__2].r != 0. || invhilb[i__2].i != 0.) {
		    i__2 = i__ + k * 10 - 11;
		    i__3 = i__ + k * 10 - 11;
		    z__2.r = x[i__2].r - invhilb[i__3].r, z__2.i = x[i__2].i 
			    - invhilb[i__3].i;
		    z__1.r = z__2.r, z__1.i = z__2.i;
/* Computing MAX */
		    i__5 = i__ + k * 10 - 11;
		    d__5 = ((d__1 = z__1.r, abs(d__1)) + (d__2 = d_imag(&z__1)
			    , abs(d__2))) / ((d__3 = invhilb[i__5].r, abs(
			    d__3)) + (d__4 = d_imag(&invhilb[i__ + k * 10 - 
			    11]), abs(d__4)));
		    cwise_err__ = max(d__5,cwise_err__);
		} else /* if(complicated condition) */ {
		    i__2 = i__ + k * 10 - 11;
		    if (x[i__2].r != 0. || x[i__2].i != 0.) {
			cwise_err__ = dlamch_("OVERFLOW");
		    }
		}
	    }
	    if (normt != 0.) {
		nwise_err__ = normdif / normt;
	    } else if (normdif != 0.) {
		nwise_err__ = dlamch_("OVERFLOW");
	    } else {
		nwise_err__ = 0.;
	    }
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		rinv[i__ - 1] = 0.;
	    }
	    i__4 = n;
	    for (j = 1; j <= i__4; ++j) {
		i__2 = n;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    i__3 = i__ + j * 10 - 11;
		    i__5 = j + k * 10 - 11;
		    z__2.r = a[i__3].r * invhilb[i__5].r - a[i__3].i * 
			    invhilb[i__5].i, z__2.i = a[i__3].r * invhilb[
			    i__5].i + a[i__3].i * invhilb[i__5].r;
		    z__1.r = z__2.r, z__1.i = z__2.i;
		    rinv[i__ - 1] += (d__1 = z__1.r, abs(d__1)) + (d__2 = 
			    d_imag(&z__1), abs(d__2));
		}
	    }
	    rinorm = 0.;
	    i__4 = n;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		sumri = 0.;
		i__2 = n;
		for (j = 1; j <= i__2; ++j) {
		    i__3 = i__ + j * 10 - 11;
		    i__5 = j - 1;
		    z__3.r = rinv[i__5] * invhilb[i__3].r, z__3.i = rinv[i__5]
			     * invhilb[i__3].i;
		    z_div(&z__2, &z__3, &invhilb[i__ + k * 10 - 11]);
		    z__1.r = z__2.r, z__1.i = z__2.i;
		    sumri += (d__1 = z__1.r, abs(d__1)) + (d__2 = d_imag(&
			    z__1), abs(d__2));
		}
		rinorm = max(rinorm,sumri);
	    }
/*        invhilb is the inverse *unscaled* Hilbert matrix, so scale its norm */
/*        by 1/A(1,1) to make the scaling match A (the scaled Hilbert matrix) */
	    ccond = ((d__1 = a[0].r, abs(d__1)) + (d__2 = d_imag(a), abs(d__2)
		    )) / rinorm;
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
		    tstrat[0] = 1 / (eps * 2.);
		} else {
		    if (nwise_bnd__ != 0.) {
			tstrat[0] = nwise_err__ / nwise_bnd__;
		    } else if (nwise_err__ != 0.) {
			tstrat[0] = 1 / (eps * 16.f);
		    } else {
			tstrat[0] = 0.;
		    }
		    if (tstrat[0] > 1.) {
			tstrat[0] = 1 / (eps * 4.);
		    }
		}
	    } else {
		s_copy(nguar, "NO", (ftnlen)3, (ftnlen)2);
		if (nwise_bnd__ < 1.) {
		    tstrat[0] = 1 / (eps * 8.);
		} else {
		    tstrat[0] = 1.;
		}
	    }
/*            write (*,*) 'cwise : ', n, k, ccond, cwise_rcond, */
/*     $           condthresh, ccond.ge.condthresh */
/*            write (*,*) 'cwise2: ', k, cwise_bnd, cwise_err, errthresh */
	    if (ccond >= condthresh) {
		s_copy(cguar, "YES", (ftnlen)3, (ftnlen)3);
		if (cwise_bnd__ > errthresh) {
		    tstrat[1] = 1 / (eps * 2.);
		} else {
		    if (cwise_bnd__ != 0.) {
			tstrat[1] = cwise_err__ / cwise_bnd__;
		    } else if (cwise_err__ != 0.) {
			tstrat[1] = 1 / (eps * 16.);
		    } else {
			tstrat[1] = 0.;
		    }
		    if (tstrat[1] > 1.) {
			tstrat[1] = 1 / (eps * 4.);
		    }
		}
	    } else {
		s_copy(cguar, "NO", (ftnlen)3, (ftnlen)2);
		if (cwise_bnd__ < 1.) {
		    tstrat[1] = 1 / (eps * 8.);
		} else {
		    tstrat[1] = 1.;
		}
	    }
/*     Backwards error test */
	    tstrat[2] = berr[k - 1] / eps;
/*     Condition number tests */
	    tstrat[3] = rcond / orcond;
	    if (rcond >= condthresh && tstrat[3] < 1.) {
		tstrat[3] = 1. / tstrat[3];
	    }
	    tstrat[4] = ncond / nwise_rcond__;
	    if (ncond >= condthresh && tstrat[4] < 1.) {
		tstrat[4] = 1. / tstrat[4];
	    }
	    tstrat[5] = ccond / nwise_rcond__;
	    if (ccond >= condthresh && tstrat[5] < 1.) {
		tstrat[5] = 1. / tstrat[5];
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
			    doublereal));
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
} /* zebchvxx_ */
