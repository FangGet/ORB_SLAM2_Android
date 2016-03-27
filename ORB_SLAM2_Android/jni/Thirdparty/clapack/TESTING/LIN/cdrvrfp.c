/* cdrvrfp.f -- translated by f2c (version 20061008).
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
    char srnamt[32];
} srnamc_;

#define srnamc_1 srnamc_

/* Table of constant values */

static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__1 = 1;

/* Subroutine */ int cdrvrfp_(integer *nout, integer *nn, integer *nval, 
	integer *nns, integer *nsval, integer *nnt, integer *ntval, real *
	thresh, complex *a, complex *asav, complex *afac, complex *ainv, 
	complex *b, complex *bsav, complex *xact, complex *x, complex *arf, 
	complex *arfinv, complex *c_work_clatms__, complex *c_work_cpot01__, 
	complex *c_work_cpot02__, complex *c_work_cpot03__, real *
	s_work_clatms__, real *s_work_clanhe__, real *s_work_cpot02__, real *
	s_work_cpot03__)
{
    /* Initialized data */

    static integer iseedy[4] = { 1988,1989,1990,1991 };
    static char uplos[1*2] = "U" "L";
    static char forms[1*2] = "N" "C";

    /* Format strings */
    static char fmt_9999[] = "(1x,a6,\002, UPLO='\002,a1,\002', N =\002,i5"
	    ",\002, type \002,i1,\002, test(\002,i1,\002)=\002,g12.5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    integer i__, k, n, kl, ku, nt, lda, ldb, iin, iis, iit, ioff, mode, info, 
	    imat;
    char dist[1];
    integer nrhs;
    char uplo[1];
    integer nrun;
    extern /* Subroutine */ int cget04_(integer *, integer *, complex *, 
	    integer *, complex *, integer *, real *, real *);
    integer nfail, iseed[4];
    char cform[1];
    extern /* Subroutine */ int cpot01_(char *, integer *, complex *, integer 
	    *, complex *, integer *, complex *, real *), cpot02_(char 
	    *, integer *, integer *, complex *, integer *, complex *, integer 
	    *, complex *, integer *, real *, real *), cpot03_(char *, 
	    integer *, complex *, integer *, complex *, integer *, complex *, 
	    integer *, real *, real *, real *);
    integer iform;
    real anorm;
    char ctype[1];
    integer iuplo, nerrs, izero;
    logical zerot;
    extern /* Subroutine */ int clatb4_(char *, integer *, integer *, integer 
	    *, char *, integer *, integer *, real *, integer *, real *, char *
), aladhd_(integer *, char *);
    extern doublereal clanhe_(char *, char *, integer *, complex *, integer *, 
	     real *);
    extern /* Subroutine */ int alaerh_(char *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), claipd_(integer *, complex *, integer *, integer *);
    real rcondc;
    extern /* Subroutine */ int clacpy_(char *, integer *, integer *, complex 
	    *, integer *, complex *, integer *), clarhs_(char *, char 
	    *, char *, char *, integer *, integer *, integer *, integer *, 
	    integer *, complex *, integer *, complex *, integer *, complex *, 
	    integer *, integer *, integer *), 
	    alasvm_(char *, integer *, integer *, integer *, integer *);
    real cndnum;
    extern /* Subroutine */ int clatms_(integer *, integer *, char *, integer 
	    *, char *, real *, integer *, real *, real *, integer *, integer *
, char *, complex *, integer *, complex *, integer *), cpftri_(char *, char *, integer *, complex *, 
	    integer *);
    real ainvnm;
    extern /* Subroutine */ int cpftrf_(char *, char *, integer *, complex *, 
	    integer *), cpotrf_(char *, integer *, complex *, 
	    integer *, integer *), cpotri_(char *, integer *, complex 
	    *, integer *, integer *), cpftrs_(char *, char *, integer 
	    *, integer *, complex *, complex *, integer *, integer *), ctfttr_(char *, char *, integer *, complex *, complex *, 
	    integer *, integer *), ctrttf_(char *, char *, 
	    integer *, complex *, integer *, complex *, integer *);
    real result[4];

    /* Fortran I/O blocks */
    static cilist io___37 = { 0, 0, 0, fmt_9999, 0 };



/*  -- LAPACK test routine (version 3.2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  CDRVRFP tests the LAPACK RFP routines: */
/*      CPFTRF, CPFTRS, and CPFTRI. */

/*  This testing routine follow the same tests as CDRVPO (test for the full */
/*  format Symmetric Positive Definite solver). */

/*  The tests are performed in Full Format, convertion back and forth from */
/*  full format to RFP format are performed using the routines CTRTTF and */
/*  CTFTTR. */

/*  First, a specific matrix A of size N is created. There is nine types of */
/*  different matrixes possible. */
/*   1. Diagonal                        6. Random, CNDNUM = sqrt(0.1/EPS) */
/*   2. Random, CNDNUM = 2              7. Random, CNDNUM = 0.1/EPS */
/*  *3. First row and column zero       8. Scaled near underflow */
/*  *4. Last row and column zero        9. Scaled near overflow */
/*  *5. Middle row and column zero */
/*  (* - tests error exits from CPFTRF, no test ratios are computed) */
/*  A solution XACT of size N-by-NRHS is created and the associated right */
/*  hand side B as well. Then CPFTRF is called to compute L (or U), the */
/*  Cholesky factor of A. Then L (or U) is used to solve the linear system */
/*  of equations AX = B. This gives X. Then L (or U) is used to compute the */
/*  inverse of A, AINV. The following four tests are then performed: */
/*  (1) norm( L*L' - A ) / ( N * norm(A) * EPS ) or */
/*      norm( U'*U - A ) / ( N * norm(A) * EPS ), */
/*  (2) norm(B - A*X) / ( norm(A) * norm(X) * EPS ), */
/*  (3) norm( I - A*AINV ) / ( N * norm(A) * norm(AINV) * EPS ), */
/*  (4) ( norm(X-XACT) * RCOND ) / ( norm(XACT) * EPS ), */
/*  where EPS is the machine precision, RCOND the condition number of A, and */
/*  norm( . ) the 1-norm for (1,2,3) and the inf-norm for (4). */
/*  Errors occur when INFO parameter is not as expected. Failures occur when */
/*  a test ratios is greater than THRES. */

/*  Arguments */
/*  ========= */

/*  NOUT          (input) INTEGER */
/*                The unit number for output. */

/*  NN            (input) INTEGER */
/*                The number of values of N contained in the vector NVAL. */

/*  NVAL          (input) INTEGER array, dimension (NN) */
/*                The values of the matrix dimension N. */

/*  NNS           (input) INTEGER */
/*                The number of values of NRHS contained in the vector NSVAL. */

/*  NSVAL         (input) INTEGER array, dimension (NNS) */
/*                The values of the number of right-hand sides NRHS. */

/*  NNT           (input) INTEGER */
/*                The number of values of MATRIX TYPE contained in the vector NTVAL. */

/*  NTVAL         (input) INTEGER array, dimension (NNT) */
/*                The values of matrix type (between 0 and 9 for PO/PP/PF matrices). */

/*  THRESH        (input) REAL */
/*                The threshold value for the test ratios.  A result is */
/*                included in the output file if RESULT >= THRESH.  To have */
/*                every test ratio printed, use THRESH = 0. */

/*  A             (workspace) COMPLEX array, dimension (NMAX*NMAX) */

/*  ASAV          (workspace) COMPLEX array, dimension (NMAX*NMAX) */

/*  AFAC          (workspace) COMPLEX array, dimension (NMAX*NMAX) */

/*  AINV          (workspace) COMPLEX array, dimension (NMAX*NMAX) */

/*  B             (workspace) COMPLEX array, dimension (NMAX*MAXRHS) */

/*  BSAV          (workspace) COMPLEX array, dimension (NMAX*MAXRHS) */

/*  XACT          (workspace) COMPLEX array, dimension (NMAX*MAXRHS) */

/*  X             (workspace) COMPLEX array, dimension (NMAX*MAXRHS) */

/*  ARF           (workspace) COMPLEX array, dimension ((NMAX*(NMAX+1))/2) */

/*  ARFINV        (workspace) COMPLEX array, dimension ((NMAX*(NMAX+1))/2) */

/*  C_WORK_CLATMS (workspace) COMPLEX array, dimension ( 3*NMAX ) */

/*  C_WORK_CPOT01 (workspace) COMPLEX array, dimension ( NMAX ) */

/*  C_WORK_CPOT02 (workspace) COMPLEX array, dimension ( NMAX*MAXRHS ) */

/*  C_WORK_CPOT03 (workspace) COMPLEX array, dimension ( NMAX*NMAX ) */

/*  S_WORK_CLATMS (workspace) REAL array, dimension ( NMAX ) */

/*  S_WORK_CLANHE (workspace) REAL array, dimension ( NMAX ) */

/*  S_WORK_CPOT02 (workspace) REAL array, dimension ( NMAX ) */

/*  S_WORK_CPOT03 (workspace) REAL array, dimension ( NMAX ) */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Local Arrays .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Scalars in Common .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Data statements .. */
    /* Parameter adjustments */
    --nval;
    --nsval;
    --ntval;
    --a;
    --asav;
    --afac;
    --ainv;
    --b;
    --bsav;
    --xact;
    --x;
    --arf;
    --arfinv;
    --c_work_clatms__;
    --c_work_cpot01__;
    --c_work_cpot02__;
    --c_work_cpot03__;
    --s_work_clatms__;
    --s_work_clanhe__;
    --s_work_cpot02__;
    --s_work_cpot03__;

    /* Function Body */
/*     .. */
/*     .. Executable Statements .. */

/*     Initialize constants and the random number seed. */

    nrun = 0;
    nfail = 0;
    nerrs = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
	iseed[i__ - 1] = iseedy[i__ - 1];
/* L10: */
    }

    i__1 = *nn;
    for (iin = 1; iin <= i__1; ++iin) {

	n = nval[iin];
	lda = max(n,1);
	ldb = max(n,1);

	i__2 = *nns;
	for (iis = 1; iis <= i__2; ++iis) {

	    nrhs = nsval[iis];

	    i__3 = *nnt;
	    for (iit = 1; iit <= i__3; ++iit) {

		imat = ntval[iit];

/*              If N.EQ.0, only consider the first type */

		if (n == 0 && iit > 1) {
		    goto L120;
		}

/*              Skip types 3, 4, or 5 if the matrix size is too small. */

		if (imat == 4 && n <= 1) {
		    goto L120;
		}
		if (imat == 5 && n <= 2) {
		    goto L120;
		}

/*              Do first for UPLO = 'U', then for UPLO = 'L' */

		for (iuplo = 1; iuplo <= 2; ++iuplo) {
		    *(unsigned char *)uplo = *(unsigned char *)&uplos[iuplo - 
			    1];

/*                 Do first for CFORM = 'N', then for CFORM = 'C' */

		    for (iform = 1; iform <= 2; ++iform) {
			*(unsigned char *)cform = *(unsigned char *)&forms[
				iform - 1];

/*                    Set up parameters with CLATB4 and generate a test */
/*                    matrix with CLATMS. */

			clatb4_("CPO", &imat, &n, &n, ctype, &kl, &ku, &anorm, 
				 &mode, &cndnum, dist);

			s_copy(srnamc_1.srnamt, "CLATMS", (ftnlen)32, (ftnlen)
				6);
			clatms_(&n, &n, dist, iseed, ctype, &s_work_clatms__[
				1], &mode, &cndnum, &anorm, &kl, &ku, uplo, &
				a[1], &lda, &c_work_clatms__[1], &info);

/*                    Check error code from CLATMS. */

			if (info != 0) {
			    alaerh_("CPF", "CLATMS", &info, &c__0, uplo, &n, &
				    n, &c_n1, &c_n1, &c_n1, &iit, &nfail, &
				    nerrs, nout);
			    goto L100;
			}

/*                    For types 3-5, zero one row and column of the matrix to */
/*                    test that INFO is returned correctly. */

			zerot = imat >= 3 && imat <= 5;
			if (zerot) {
			    if (iit == 3) {
				izero = 1;
			    } else if (iit == 4) {
				izero = n;
			    } else {
				izero = n / 2 + 1;
			    }
			    ioff = (izero - 1) * lda;

/*                       Set row and column IZERO of A to 0. */

			    if (iuplo == 1) {
				i__4 = izero - 1;
				for (i__ = 1; i__ <= i__4; ++i__) {
				    i__5 = ioff + i__;
				    a[i__5].r = 0.f, a[i__5].i = 0.f;
/* L20: */
				}
				ioff += izero;
				i__4 = n;
				for (i__ = izero; i__ <= i__4; ++i__) {
				    i__5 = ioff;
				    a[i__5].r = 0.f, a[i__5].i = 0.f;
				    ioff += lda;
/* L30: */
				}
			    } else {
				ioff = izero;
				i__4 = izero - 1;
				for (i__ = 1; i__ <= i__4; ++i__) {
				    i__5 = ioff;
				    a[i__5].r = 0.f, a[i__5].i = 0.f;
				    ioff += lda;
/* L40: */
				}
				ioff -= izero;
				i__4 = n;
				for (i__ = izero; i__ <= i__4; ++i__) {
				    i__5 = ioff + i__;
				    a[i__5].r = 0.f, a[i__5].i = 0.f;
/* L50: */
				}
			    }
			} else {
			    izero = 0;
			}

/*                    Set the imaginary part of the diagonals. */

			i__4 = lda + 1;
			claipd_(&n, &a[1], &i__4, &c__0);

/*                    Save a copy of the matrix A in ASAV. */

			clacpy_(uplo, &n, &n, &a[1], &lda, &asav[1], &lda);

/*                    Compute the condition number of A (RCONDC). */

			if (zerot) {
			    rcondc = 0.f;
			} else {

/*                       Compute the 1-norm of A. */

			    anorm = clanhe_("1", uplo, &n, &a[1], &lda, &
				    s_work_clanhe__[1]);

/*                       Factor the matrix A. */

			    cpotrf_(uplo, &n, &a[1], &lda, &info);

/*                       Form the inverse of A. */

			    cpotri_(uplo, &n, &a[1], &lda, &info);

/*                       Compute the 1-norm condition number of A. */

			    ainvnm = clanhe_("1", uplo, &n, &a[1], &lda, &
				    s_work_clanhe__[1]);
			    rcondc = 1.f / anorm / ainvnm;

/*                       Restore the matrix A. */

			    clacpy_(uplo, &n, &n, &asav[1], &lda, &a[1], &lda);

			}

/*                    Form an exact solution and set the right hand side. */

			s_copy(srnamc_1.srnamt, "CLARHS", (ftnlen)32, (ftnlen)
				6);
			clarhs_("CPO", "N", uplo, " ", &n, &n, &kl, &ku, &
				nrhs, &a[1], &lda, &xact[1], &lda, &b[1], &
				lda, iseed, &info);
			clacpy_("Full", &n, &nrhs, &b[1], &lda, &bsav[1], &
				lda);

/*                    Compute the L*L' or U'*U factorization of the */
/*                    matrix and solve the system. */

			clacpy_(uplo, &n, &n, &a[1], &lda, &afac[1], &lda);
			clacpy_("Full", &n, &nrhs, &b[1], &ldb, &x[1], &ldb);

			s_copy(srnamc_1.srnamt, "CTRTTF", (ftnlen)32, (ftnlen)
				6);
			ctrttf_(cform, uplo, &n, &afac[1], &lda, &arf[1], &
				info);
			s_copy(srnamc_1.srnamt, "CPFTRF", (ftnlen)32, (ftnlen)
				6);
			cpftrf_(cform, uplo, &n, &arf[1], &info);

/*                    Check error code from CPFTRF. */

			if (info != izero) {

/*                       LANGOU: there is a small hick here: IZERO should */
/*                       always be INFO however if INFO is ZERO, ALAERH does not */
/*                       complain. */

			    alaerh_("CPF", "CPFSV ", &info, &izero, uplo, &n, 
				    &n, &c_n1, &c_n1, &nrhs, &iit, &nfail, &
				    nerrs, nout);
			    goto L100;
			}

/*                     Skip the tests if INFO is not 0. */

			if (info != 0) {
			    goto L100;
			}

			s_copy(srnamc_1.srnamt, "CPFTRS", (ftnlen)32, (ftnlen)
				6);
			cpftrs_(cform, uplo, &n, &nrhs, &arf[1], &x[1], &ldb, 
				&info);

			s_copy(srnamc_1.srnamt, "CTFTTR", (ftnlen)32, (ftnlen)
				6);
			ctfttr_(cform, uplo, &n, &arf[1], &afac[1], &lda, &
				info);

/*                    Reconstruct matrix from factors and compute */
/*                    residual. */

			clacpy_(uplo, &n, &n, &afac[1], &lda, &asav[1], &lda);
			cpot01_(uplo, &n, &a[1], &lda, &afac[1], &lda, &
				c_work_cpot01__[1], result);
			clacpy_(uplo, &n, &n, &asav[1], &lda, &afac[1], &lda);

/*                    Form the inverse and compute the residual. */

			if (n % 2 == 0) {
			    i__4 = n + 1;
			    i__5 = n / 2;
			    i__6 = n + 1;
			    i__7 = n + 1;
			    clacpy_("A", &i__4, &i__5, &arf[1], &i__6, &
				    arfinv[1], &i__7);
			} else {
			    i__4 = (n + 1) / 2;
			    clacpy_("A", &n, &i__4, &arf[1], &n, &arfinv[1], &
				    n);
			}

			s_copy(srnamc_1.srnamt, "CPFTRI", (ftnlen)32, (ftnlen)
				6);
			cpftri_(cform, uplo, &n, &arfinv[1], &info);

			s_copy(srnamc_1.srnamt, "CTFTTR", (ftnlen)32, (ftnlen)
				6);
			ctfttr_(cform, uplo, &n, &arfinv[1], &ainv[1], &lda, &
				info);

/*                    Check error code from CPFTRI. */

			if (info != 0) {
			    alaerh_("CPO", "CPFTRI", &info, &c__0, uplo, &n, &
				    n, &c_n1, &c_n1, &c_n1, &imat, &nfail, &
				    nerrs, nout);
			}

			cpot03_(uplo, &n, &a[1], &lda, &ainv[1], &lda, &
				c_work_cpot03__[1], &lda, &s_work_cpot03__[1], 
				 &rcondc, &result[1]);

/*                    Compute residual of the computed solution. */

			clacpy_("Full", &n, &nrhs, &b[1], &lda, &
				c_work_cpot02__[1], &lda);
			cpot02_(uplo, &n, &nrhs, &a[1], &lda, &x[1], &lda, &
				c_work_cpot02__[1], &lda, &s_work_cpot02__[1], 
				 &result[2]);

/*                    Check solution from generated exact solution. */

			cget04_(&n, &nrhs, &x[1], &lda, &xact[1], &lda, &
				rcondc, &result[3]);
			nt = 4;

/*                    Print information about the tests that did not */
/*                    pass the threshold. */

			i__4 = nt;
			for (k = 1; k <= i__4; ++k) {
			    if (result[k - 1] >= *thresh) {
				if (nfail == 0 && nerrs == 0) {
				    aladhd_(nout, "CPF");
				}
				io___37.ciunit = *nout;
				s_wsfe(&io___37);
				do_fio(&c__1, "CPFSV ", (ftnlen)6);
				do_fio(&c__1, uplo, (ftnlen)1);
				do_fio(&c__1, (char *)&n, (ftnlen)sizeof(
					integer));
				do_fio(&c__1, (char *)&iit, (ftnlen)sizeof(
					integer));
				do_fio(&c__1, (char *)&k, (ftnlen)sizeof(
					integer));
				do_fio(&c__1, (char *)&result[k - 1], (ftnlen)
					sizeof(real));
				e_wsfe();
				++nfail;
			    }
/* L60: */
			}
			nrun += nt;
L100:
			;
		    }
/* L110: */
		}
L120:
		;
	    }
/* L980: */
	}
/* L130: */
    }

/*     Print a summary of the results. */

    alasvm_("CPF", nout, &nfail, &nrun, &nerrs);


    return 0;

/*     End of CDRVRFP */

} /* cdrvrfp_ */
