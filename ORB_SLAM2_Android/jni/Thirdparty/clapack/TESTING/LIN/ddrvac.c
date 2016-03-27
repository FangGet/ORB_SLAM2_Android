/* ddrvac.f -- translated by f2c (version 20061008).
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

/* Common Block Declarations */

struct {
    integer infot, nunit;
    logical ok, lerr;
} infoc_;

#define infoc_1 infoc_

struct {
    char srnamt[32];
} srnamc_;

#define srnamc_1 srnamc_

/* Table of constant values */

static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__1 = 1;

/* Subroutine */ int ddrvac_(logical *dotype, integer *nm, integer *mval, 
	integer *nns, integer *nsval, doublereal *thresh, integer *nmax, 
	doublereal *a, doublereal *afac, doublereal *b, doublereal *x, 
	doublereal *work, doublereal *rwork, real *swork, integer *nout)
{
    /* Initialized data */

    static integer iseedy[4] = { 1988,1989,1990,1991 };
    static char uplos[1*2] = "U" "L";

    /* Format strings */
    static char fmt_9988[] = "(\002 *** \002,a6,\002 returned with INFO ="
	    "\002,i5,\002 instead of \002,i5,/\002 ==> N =\002,i5,\002, type"
	    " \002,i2)";
    static char fmt_9975[] = "(\002 *** Error code from \002,a6,\002=\002,"
	    "i5,\002 for M=\002,i5,\002, type \002,i2)";
    static char fmt_8999[] = "(/1x,a3,\002:  positive definite dense matri"
	    "ces\002)";
    static char fmt_8979[] = "(4x,\0021. Diagonal\002,24x,\0027. Last n/2 co"
	    "lumns zero\002,/4x,\0022. Upper triangular\002,16x,\0028. Random"
	    ", CNDNUM = sqrt(0.1/EPS)\002,/4x,\0023. Lower triangular\002,16x,"
	    "\0029. Random, CNDNUM = 0.1/EPS\002,/4x,\0024. Random, CNDNUM = 2"
	    "\002,13x,\00210. Scaled near underflow\002,/4x,\0025. First colu"
	    "mn zero\002,14x,\00211. Scaled near overflow\002,/4x,\0026. Last"
	    " column zero\002)";
    static char fmt_8960[] = "(3x,i2,\002: norm_1( B - A * X )  / \002,\002("
	    " norm_1(A) * norm_1(X) * EPS * SQRT(N) ) > 1 if ITERREF\002,/4x"
	    ",\002or norm_1( B - A * X )  / \002,\002( norm_1(A) * norm_1(X) "
	    "* EPS ) > THRES if DPOTRF\002)";
    static char fmt_9998[] = "(\002 UPLO='\002,a1,\002', N =\002,i5,\002, NR"
	    "HS=\002,i3,\002, type \002,i2,\002, test(\002,i2,\002) =\002,g12"
	    ".5)";
    static char fmt_9996[] = "(1x,a6,\002: \002,i6,\002 out of \002,i6,\002 "
	    "tests failed to pass the threshold\002)";
    static char fmt_9995[] = "(/1x,\002All tests for \002,a6,\002 routines p"
	    "assed the threshold (\002,i6,\002 tests run)\002)";
    static char fmt_9994[] = "(6x,i6,\002 error messages recorded\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    cilist ci__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);

    /* Local variables */
    integer i__, n, im, kl, ku, lda, ioff, mode, kase, imat, info;
    char path[3], dist[1];
    integer irhs, iter, nrhs;
    char uplo[1], type__[1];
    integer nrun;
    extern /* Subroutine */ int alahd_(integer *, char *);
    integer nfail, iseed[4], nimat;
    doublereal anorm;
    extern /* Subroutine */ int dpot06_(char *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *);
    integer iuplo, izero, nerrs;
    logical zerot;
    char xtype[1];
    extern /* Subroutine */ int dlatb4_(char *, integer *, integer *, integer 
	    *, char *, integer *, integer *, doublereal *, integer *, 
	    doublereal *, char *), alaerh_(char *, 
	    char *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), dlacpy_(char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *), dlarhs_(char *, char *, char *, char *, integer *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, doublereal *, integer *, doublereal *, integer *, integer *, 
	    integer *);
    doublereal cndnum;
    extern /* Subroutine */ int dlatms_(integer *, integer *, char *, integer 
	    *, char *, doublereal *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, char *, doublereal *, integer *, doublereal 
	    *, integer *);
    doublereal result[1];
    extern /* Subroutine */ int dsposv_(char *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, real *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___32 = { 0, 0, 0, fmt_9988, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_9975, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_8999, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_8979, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_8960, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_9996, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_9994, 0 };



/*  -- LAPACK test routine (version 3.1.2) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     April 2007 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DDRVAC tests DSPOSV. */

/*  Arguments */
/*  ========= */

/*  DOTYPE  (input) LOGICAL array, dimension (NTYPES) */
/*          The matrix types to be used for testing.  Matrices of type j */
/*          (for 1 <= j <= NTYPES) are used for testing if DOTYPE(j) = */
/*          .TRUE.; if DOTYPE(j) = .FALSE., then type j is not used. */

/*  NM      (input) INTEGER */
/*          The number of values of N contained in the vector MVAL. */

/*  MVAL    (input) INTEGER array, dimension (NM) */
/*          The values of the matrix dimension N. */

/*  NNS    (input) INTEGER */
/*          The number of values of NRHS contained in the vector NSVAL. */

/*  NSVAL   (input) INTEGER array, dimension (NNS) */
/*          The values of the number of right hand sides NRHS. */

/*  THRESH  (input) DOUBLE PRECISION */
/*          The threshold value for the test ratios.  A result is */
/*          included in the output file if RESULT >= THRESH.  To have */
/*          every test ratio printed, use THRESH = 0. */

/*  NMAX    (input) INTEGER */
/*          The maximum value permitted for N, used in dimensioning the */
/*          work arrays. */

/*  A       (workspace) DOUBLE PRECISION array, dimension (NMAX*NMAX) */

/*  AFAC    (workspace) DOUBLE PRECISION array, dimension (NMAX*NMAX) */

/*  B       (workspace) DOUBLE PRECISION array, dimension (NMAX*NSMAX) */

/*  X       (workspace) DOUBLE PRECISION array, dimension (NMAX*NSMAX) */

/*  WORK    (workspace) DOUBLE PRECISION array, dimension */
/*                      (NMAX*max(3,NSMAX)) */

/*  RWORK   (workspace) DOUBLE PRECISION array, dimension */
/*                      (max(2*NMAX,2*NSMAX+NWORK)) */

/*  SWORK   (workspace) REAL array, dimension */
/*                      (NMAX*(NSMAX+NMAX)) */

/*  NOUT    (input) INTEGER */
/*          The unit number for output. */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Local Arrays .. */
/*     .. */
/*     .. Local Variables .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Scalars in Common .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Data statements .. */
    /* Parameter adjustments */
    --swork;
    --rwork;
    --work;
    --x;
    --b;
    --afac;
    --a;
    --nsval;
    --mval;
    --dotype;

    /* Function Body */
/*     .. */
/*     .. Executable Statements .. */

/*     Initialize constants and the random number seed. */

    kase = 0;
    s_copy(path, "Double precision", (ftnlen)1, (ftnlen)16);
    s_copy(path + 1, "PO", (ftnlen)2, (ftnlen)2);
    nrun = 0;
    nfail = 0;
    nerrs = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
	iseed[i__ - 1] = iseedy[i__ - 1];
/* L10: */
    }

    infoc_1.infot = 0;

/*     Do for each value of N in MVAL */

    i__1 = *nm;
    for (im = 1; im <= i__1; ++im) {
	n = mval[im];
	lda = max(n,1);
	nimat = 9;
	if (n <= 0) {
	    nimat = 1;
	}

	i__2 = nimat;
	for (imat = 1; imat <= i__2; ++imat) {

/*           Do the tests only if DOTYPE( IMAT ) is true. */

	    if (! dotype[imat]) {
		goto L110;
	    }

/*           Skip types 3, 4, or 5 if the matrix size is too small. */

	    zerot = imat >= 3 && imat <= 5;
	    if (zerot && n < imat - 2) {
		goto L110;
	    }

/*           Do first for UPLO = 'U', then for UPLO = 'L' */

	    for (iuplo = 1; iuplo <= 2; ++iuplo) {
		*(unsigned char *)uplo = *(unsigned char *)&uplos[iuplo - 1];

/*              Set up parameters with DLATB4 and generate a test matrix */
/*              with DLATMS. */

		dlatb4_(path, &imat, &n, &n, type__, &kl, &ku, &anorm, &mode, 
			&cndnum, dist);

		s_copy(srnamc_1.srnamt, "DLATMS", (ftnlen)32, (ftnlen)6);
		dlatms_(&n, &n, dist, iseed, type__, &rwork[1], &mode, &
			cndnum, &anorm, &kl, &ku, uplo, &a[1], &lda, &work[1], 
			 &info);

/*              Check error code from DLATMS. */

		if (info != 0) {
		    alaerh_(path, "DLATMS", &info, &c__0, uplo, &n, &n, &c_n1, 
			     &c_n1, &c_n1, &imat, &nfail, &nerrs, nout);
		    goto L100;
		}

/*              For types 3-5, zero one row and column of the matrix to */
/*              test that INFO is returned correctly. */

		if (zerot) {
		    if (imat == 3) {
			izero = 1;
		    } else if (imat == 4) {
			izero = n;
		    } else {
			izero = n / 2 + 1;
		    }
		    ioff = (izero - 1) * lda;

/*                 Set row and column IZERO of A to 0. */

		    if (iuplo == 1) {
			i__3 = izero - 1;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    a[ioff + i__] = 0.;
/* L20: */
			}
			ioff += izero;
			i__3 = n;
			for (i__ = izero; i__ <= i__3; ++i__) {
			    a[ioff] = 0.;
			    ioff += lda;
/* L30: */
			}
		    } else {
			ioff = izero;
			i__3 = izero - 1;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    a[ioff] = 0.;
			    ioff += lda;
/* L40: */
			}
			ioff -= izero;
			i__3 = n;
			for (i__ = izero; i__ <= i__3; ++i__) {
			    a[ioff + i__] = 0.;
/* L50: */
			}
		    }
		} else {
		    izero = 0;
		}

		i__3 = *nns;
		for (irhs = 1; irhs <= i__3; ++irhs) {
		    nrhs = nsval[irhs];
		    *(unsigned char *)xtype = 'N';

/*                 Form an exact solution and set the right hand side. */

		    s_copy(srnamc_1.srnamt, "DLARHS", (ftnlen)32, (ftnlen)6);
		    dlarhs_(path, xtype, uplo, " ", &n, &n, &kl, &ku, &nrhs, &
			    a[1], &lda, &x[1], &lda, &b[1], &lda, iseed, &
			    info);

/*                 Compute the L*L' or U'*U factorization of the */
/*                 matrix and solve the system. */

		    s_copy(srnamc_1.srnamt, "DSPOSV ", (ftnlen)32, (ftnlen)7);
		    ++kase;

		    dlacpy_("All", &n, &n, &a[1], &lda, &afac[1], &lda);

		    dsposv_(uplo, &n, &nrhs, &afac[1], &lda, &b[1], &lda, &x[
			    1], &lda, &work[1], &swork[1], &iter, &info);
		    if (iter < 0) {
			dlacpy_("All", &n, &n, &a[1], &lda, &afac[1], &lda);
		    }

/*                 Check error code from DSPOSV . */

		    if (info != izero) {

			if (nfail == 0 && nerrs == 0) {
			    alahd_(nout, path);
			}
			++nerrs;

			if (info != izero && izero != 0) {
			    io___32.ciunit = *nout;
			    s_wsfe(&io___32);
			    do_fio(&c__1, "DSPOSV", (ftnlen)6);
			    do_fio(&c__1, (char *)&info, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&izero, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer))
				    ;
			    do_fio(&c__1, (char *)&imat, (ftnlen)sizeof(
				    integer));
			    e_wsfe();
			} else {
			    io___33.ciunit = *nout;
			    s_wsfe(&io___33);
			    do_fio(&c__1, "DSPOSV", (ftnlen)6);
			    do_fio(&c__1, (char *)&info, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer))
				    ;
			    do_fio(&c__1, (char *)&imat, (ftnlen)sizeof(
				    integer));
			    e_wsfe();
			}
		    }

/*                 Skip the remaining test if the matrix is singular. */

		    if (info != 0) {
			goto L110;
		    }

/*                 Check the quality of the solution */

		    dlacpy_("All", &n, &nrhs, &b[1], &lda, &work[1], &lda);

		    dpot06_(uplo, &n, &nrhs, &a[1], &lda, &x[1], &lda, &work[
			    1], &lda, &rwork[1], result);

/*                 Check if the test passes the tesing. */
/*                 Print information about the tests that did not */
/*                 pass the testing. */

/*                 If iterative refinement has been used and claimed to */
/*                 be successful (ITER>0), we want */
/*                 NORM1(B - A*X)/(NORM1(A)*NORM1(X)*EPS*SRQT(N)) < 1 */

/*                 If double precision has been used (ITER<0), we want */
/*                 NORM1(B - A*X)/(NORM1(A)*NORM1(X)*EPS) < THRES */
/*                 (Cf. the linear solver testing routines) */

		    if (*thresh <= 0.f || iter >= 0 && n > 0 && result[0] >= 
			    sqrt((doublereal) n) || iter < 0 && result[0] >= *
			    thresh) {

			if (nfail == 0 && nerrs == 0) {
			    io___35.ciunit = *nout;
			    s_wsfe(&io___35);
			    do_fio(&c__1, "DPO", (ftnlen)3);
			    e_wsfe();
			    ci__1.cierr = 0;
			    ci__1.ciunit = *nout;
			    ci__1.cifmt = "( ' Matrix types:' )";
			    s_wsfe(&ci__1);
			    e_wsfe();
			    io___36.ciunit = *nout;
			    s_wsfe(&io___36);
			    e_wsfe();
			    ci__1.cierr = 0;
			    ci__1.ciunit = *nout;
			    ci__1.cifmt = "( ' Test ratios:' )";
			    s_wsfe(&ci__1);
			    e_wsfe();
			    io___37.ciunit = *nout;
			    s_wsfe(&io___37);
			    do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(
				    integer));
			    e_wsfe();
			    ci__1.cierr = 0;
			    ci__1.ciunit = *nout;
			    ci__1.cifmt = "( ' Messages:' )";
			    s_wsfe(&ci__1);
			    e_wsfe();
			}

			io___38.ciunit = *nout;
			s_wsfe(&io___38);
			do_fio(&c__1, uplo, (ftnlen)1);
			do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&nrhs, (ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&imat, (ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&result[0], (ftnlen)sizeof(
				doublereal));
			e_wsfe();

			++nfail;

		    }

		    ++nrun;

/* L60: */
		}
L100:
		;
	    }
L110:
	    ;
	}
/* L120: */
    }

/* L130: */

/*     Print a summary of the results. */

    if (nfail > 0) {
	io___39.ciunit = *nout;
	s_wsfe(&io___39);
	do_fio(&c__1, "DSPOSV", (ftnlen)6);
	do_fio(&c__1, (char *)&nfail, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	io___40.ciunit = *nout;
	s_wsfe(&io___40);
	do_fio(&c__1, "DSPOSV", (ftnlen)6);
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (nerrs > 0) {
	io___41.ciunit = *nout;
	s_wsfe(&io___41);
	do_fio(&c__1, (char *)&nerrs, (ftnlen)sizeof(integer));
	e_wsfe();
    }


/*     SUBNAM, INFO, INFOE, N, IMAT */


/*     SUBNAM, INFO, N, IMAT */

    return 0;

/*     End of DDRVAC */

} /* ddrvac_ */
