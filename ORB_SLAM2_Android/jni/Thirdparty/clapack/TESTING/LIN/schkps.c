/* schkps.f -- translated by f2c (version 20061008).
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

static integer c__2 = 2;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__1 = 1;

/* Subroutine */ int schkps_(logical *dotype, integer *nn, integer *nval, 
	integer *nnb, integer *nbval, integer *nrank, integer *rankval, real *
	thresh, logical *tsterr, integer *nmax, real *a, real *afac, real *
	perm, integer *piv, real *work, real *rwork, integer *nout)
{
    /* Initialized data */

    static integer iseedy[4] = { 1988,1989,1990,1991 };
    static char uplos[1*2] = "U" "L";

    /* Format strings */
    static char fmt_9999[] = "(\002 UPLO = '\002,a1,\002', N =\002,i5,\002, "
	    "RANK =\002,i3,\002, Diff =\002,i5,\002, NB =\002,i4,\002, type"
	    " \002,i2,\002, Ratio =\002,g12.5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    real r__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_sceiling(real *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);

    /* Local variables */
    integer rankdiff, comprank, i__, n, nb, in, kl, ku, lda, inb;
    real tol;
    integer mode, imat, info, rank;
    char path[3], dist[1], uplo[1], type__[1];
    integer nrun;
    extern /* Subroutine */ int alahd_(integer *, char *);
    integer nfail, iseed[4], irank, nimat;
    real anorm;
    integer iuplo, izero, nerrs;
    extern /* Subroutine */ int spst01_(char *, integer *, real *, integer *, 
	    real *, integer *, real *, integer *, integer *, real *, real *, 
	    integer *), slatb5_(char *, integer *, integer *, char *, 
	    integer *, integer *, real *, integer *, real *, char *), alaerh_(char *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), alasum_(char *, integer *, integer *, integer *, integer 
	    *);
    real cndnum;
    extern /* Subroutine */ int slacpy_(char *, integer *, integer *, real *, 
	    integer *, real *, integer *), xlaenv_(integer *, integer 
	    *), slatmt_(integer *, integer *, char *, integer *, char *, real 
	    *, integer *, real *, real *, integer *, integer *, integer *, 
	    char *, real *, integer *, real *, integer *);
    real result;
    extern /* Subroutine */ int serrps_(char *, integer *), spstrf_(
	    char *, integer *, real *, integer *, integer *, integer *, real *
, real *, integer *);

    /* Fortran I/O blocks */
    static cilist io___33 = { 0, 0, 0, fmt_9999, 0 };



/*  -- LAPACK test routine (version 3.1) -- */
/*     Craig Lucas, University of Manchester / NAG Ltd. */
/*     October, 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SCHKPS tests SPSTRF. */

/*  Arguments */
/*  ========= */

/*  DOTYPE  (input) LOGICAL array, dimension (NTYPES) */
/*          The matrix types to be used for testing.  Matrices of type j */
/*          (for 1 <= j <= NTYPES) are used for testing if DOTYPE(j) = */
/*          .TRUE.; if DOTYPE(j) = .FALSE., then type j is not used. */

/*  NN      (input) INTEGER */
/*          The number of values of N contained in the vector NVAL. */

/*  NVAL    (input) INTEGER array, dimension (NN) */
/*          The values of the matrix dimension N. */

/*  NNB     (input) INTEGER */
/*          The number of values of NB contained in the vector NBVAL. */

/*  NBVAL   (input) INTEGER array, dimension (NBVAL) */
/*          The values of the block size NB. */

/*  NRANK   (input) INTEGER */
/*          The number of values of RANK contained in the vector RANKVAL. */

/*  RANKVAL (input) INTEGER array, dimension (NBVAL) */
/*          The values of the block size NB. */

/*  THRESH  (input) REAL */
/*          The threshold value for the test ratios.  A result is */
/*          included in the output file if RESULT >= THRESH.  To have */
/*          every test ratio printed, use THRESH = 0. */

/*  TSTERR  (input) LOGICAL */
/*          Flag that indicates whether error exits are to be tested. */

/*  NMAX    (input) INTEGER */
/*          The maximum value permitted for N, used in dimensioning the */
/*          work arrays. */

/*  A       (workspace) REAL array, dimension (NMAX*NMAX) */

/*  AFAC    (workspace) REAL array, dimension (NMAX*NMAX) */

/*  PERM    (workspace) REAL array, dimension (NMAX*NMAX) */

/*  PIV     (workspace) INTEGER array, dimension (NMAX) */

/*  WORK    (workspace) REAL array, dimension (NMAX*3) */

/*  RWORK   (workspace) REAL array, dimension (NMAX) */

/*  NOUT    (input) INTEGER */
/*          The unit number for output. */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Local Arrays .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Scalars in Common .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Data statements .. */
    /* Parameter adjustments */
    --rwork;
    --work;
    --piv;
    --perm;
    --afac;
    --a;
    --rankval;
    --nbval;
    --nval;
    --dotype;

    /* Function Body */
/*     .. */
/*     .. Executable Statements .. */

/*     Initialize constants and the random number seed. */

    s_copy(path, "Single Precision", (ftnlen)1, (ftnlen)16);
    s_copy(path + 1, "PS", (ftnlen)2, (ftnlen)2);
    nrun = 0;
    nfail = 0;
    nerrs = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
	iseed[i__ - 1] = iseedy[i__ - 1];
/* L100: */
    }

/*     Test the error exits */

    if (*tsterr) {
	serrps_(path, nout);
    }
    infoc_1.infot = 0;
    xlaenv_(&c__2, &c__2);

/*     Do for each value of N in NVAL */

    i__1 = *nn;
    for (in = 1; in <= i__1; ++in) {
	n = nval[in];
	lda = max(n,1);
	nimat = 9;
	if (n <= 0) {
	    nimat = 1;
	}

	izero = 0;
	i__2 = nimat;
	for (imat = 1; imat <= i__2; ++imat) {

/*           Do the tests only if DOTYPE( IMAT ) is true. */

	    if (! dotype[imat]) {
		goto L140;
	    }

/*              Do for each value of RANK in RANKVAL */

	    i__3 = *nrank;
	    for (irank = 1; irank <= i__3; ++irank) {

/*              Only repeat test 3 to 5 for different ranks */
/*              Other tests use full rank */

		if ((imat < 3 || imat > 5) && irank > 1) {
		    goto L130;
		}

		r__1 = n * (real) rankval[irank] / 100.f;
		rank = i_sceiling(&r__1);


/*           Do first for UPLO = 'U', then for UPLO = 'L' */

		for (iuplo = 1; iuplo <= 2; ++iuplo) {
		    *(unsigned char *)uplo = *(unsigned char *)&uplos[iuplo - 
			    1];

/*              Set up parameters with SLATB5 and generate a test matrix */
/*              with SLATMT. */

		    slatb5_(path, &imat, &n, type__, &kl, &ku, &anorm, &mode, 
			    &cndnum, dist);

		    s_copy(srnamc_1.srnamt, "SLATMT", (ftnlen)32, (ftnlen)6);
		    slatmt_(&n, &n, dist, iseed, type__, &rwork[1], &mode, &
			    cndnum, &anorm, &rank, &kl, &ku, uplo, &a[1], &
			    lda, &work[1], &info);

/*              Check error code from SLATMT. */

		    if (info != 0) {
			alaerh_(path, "SLATMT", &info, &c__0, uplo, &n, &n, &
				c_n1, &c_n1, &c_n1, &imat, &nfail, &nerrs, 
				nout);
			goto L120;
		    }

/*              Do for each value of NB in NBVAL */

		    i__4 = *nnb;
		    for (inb = 1; inb <= i__4; ++inb) {
			nb = nbval[inb];
			xlaenv_(&c__1, &nb);

/*                 Compute the pivoted L*L' or U'*U factorization */
/*                 of the matrix. */

			slacpy_(uplo, &n, &n, &a[1], &lda, &afac[1], &lda);
			s_copy(srnamc_1.srnamt, "SPSTRF", (ftnlen)32, (ftnlen)
				6);

/*                 Use default tolerance */

			tol = -1.f;
			spstrf_(uplo, &n, &afac[1], &lda, &piv[1], &comprank, 
				&tol, &work[1], &info);

/*                 Check error code from SPSTRF. */

			if (info < izero || info != izero && rank == n || 
				info <= izero && rank < n) {
			    alaerh_(path, "SPSTRF", &info, &izero, uplo, &n, &
				    n, &c_n1, &c_n1, &nb, &imat, &nfail, &
				    nerrs, nout);
			    goto L110;
			}

/*                 Skip the test if INFO is not 0. */

			if (info != 0) {
			    goto L110;
			}

/*                 Reconstruct matrix from factors and compute residual. */

/*                 PERM holds permuted L*L^T or U^T*U */

			spst01_(uplo, &n, &a[1], &lda, &afac[1], &lda, &perm[
				1], &lda, &piv[1], &rwork[1], &result, &
				comprank);

/*                 Print information about the tests that did not pass */
/*                 the threshold or where computed rank was not RANK. */

			if (n == 0) {
			    comprank = 0;
			}
			rankdiff = rank - comprank;
			if (result >= *thresh) {
			    if (nfail == 0 && nerrs == 0) {
				alahd_(nout, path);
			    }
			    io___33.ciunit = *nout;
			    s_wsfe(&io___33);
			    do_fio(&c__1, uplo, (ftnlen)1);
			    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer))
				    ;
			    do_fio(&c__1, (char *)&rank, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&rankdiff, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&nb, (ftnlen)sizeof(integer)
				    );
			    do_fio(&c__1, (char *)&imat, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&result, (ftnlen)sizeof(
				    real));
			    e_wsfe();
			    ++nfail;
			}
			++nrun;
L110:
			;
		    }

L120:
		    ;
		}
L130:
		;
	    }
L140:
	    ;
	}
/* L150: */
    }

/*     Print a summary of the results. */

    alasum_(path, nout, &nfail, &nrun, &nerrs);

    return 0;

/*     End of SCHKPS */

} /* schkps_ */
