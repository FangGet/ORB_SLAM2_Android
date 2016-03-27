/* zdrvrf3.f -- translated by f2c (version 20061008).
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

static integer c__4 = 4;
static integer c__5 = 5;
static integer c__1 = 1;

/* Subroutine */ int zdrvrf3_(integer *nout, integer *nn, integer *nval, 
	doublereal *thresh, doublecomplex *a, integer *lda, doublecomplex *
	arf, doublecomplex *b1, doublecomplex *b2, doublereal *
	d_work_zlange__, doublecomplex *z_work_zgeqrf__, doublecomplex *tau)
{
    /* Initialized data */

    static integer iseedy[4] = { 1988,1989,1990,1991 };
    static char uplos[1*2] = "U" "L";
    static char forms[1*2] = "N" "C";
    static char sides[1*2] = "L" "R";
    static char transs[1*2] = "N" "C";
    static char diags[1*2] = "N" "U";

    /* Format strings */
    static char fmt_9999[] = "(1x,\002 *** Error(s) or Failure(s) while test"
	    "ing ZTFSM               ***\002)";
    static char fmt_9997[] = "(1x,\002     Failure in \002,a5,\002, CFORM="
	    "'\002,a1,\002',\002,\002 SIDE='\002,a1,\002',\002,\002 UPLO='"
	    "\002,a1,\002',\002,\002 TRANS='\002,a1,\002',\002,\002 DIAG='"
	    "\002,a1,\002',\002,\002 M=\002,i3,\002, N =\002,i3,\002, test"
	    "=\002,g12.5)";
    static char fmt_9996[] = "(1x,\002All tests for \002,a5,\002 auxiliary r"
	    "outine passed the \002,\002threshold (\002,i5,\002 tests run)"
	    "\002)";
    static char fmt_9995[] = "(1x,a6,\002 auxiliary routine:\002,i5,\002 out"
	    " of \002,i5,\002 tests failed to pass the threshold\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b1_dim1, b1_offset, b2_dim1, b2_offset, i__1, 
	    i__2, i__3, i__4, i__5, i__6, i__7;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(void), 
	    do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__, j, m, n, na, iim, iin;
    doublereal eps;
    char diag[1], side[1];
    integer info;
    char uplo[1];
    integer nrun, idiag;
    doublecomplex alpha;
    integer nfail, iseed[4], iside;
    char cform[1];
    integer iform;
    char trans[1];
    integer iuplo;
    extern /* Subroutine */ int ztfsm_(char *, char *, char *, char *, char *, 
	     integer *, integer *, doublecomplex *, doublecomplex *, 
	    doublecomplex *, integer *), ztrsm_(char *, char *, char *, char *, integer *, 
	    integer *, doublecomplex *, doublecomplex *, integer *, 
	    doublecomplex *, integer *);
    extern doublereal dlamch_(char *);
    integer ialpha;
    extern doublereal zlange_(char *, integer *, integer *, doublecomplex *, 
	    integer *, doublereal *);
    extern /* Subroutine */ int zgelqf_(integer *, integer *, doublecomplex *, 
	     integer *, doublecomplex *, doublecomplex *, integer *, integer *
);
    extern /* Double Complex */ VOID zlarnd_(doublecomplex *, integer *, 
	    integer *);
    extern /* Subroutine */ int zgeqrf_(integer *, integer *, doublecomplex *, 
	     integer *, doublecomplex *, doublecomplex *, integer *, integer *
);
    integer itrans;
    doublereal result[1];
    extern /* Subroutine */ int ztrttf_(char *, char *, integer *, 
	    doublecomplex *, integer *, doublecomplex *, integer *);

    /* Fortran I/O blocks */
    static cilist io___32 = { 0, 0, 0, 0, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_9996, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_9995, 0 };



/*  -- LAPACK test routine (version 3.2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  ZDRVRF3 tests the LAPACK RFP routines: */
/*      ZTFSM */

/*  Arguments */
/*  ========= */

/*  NOUT          (input) INTEGER */
/*                The unit number for output. */

/*  NN            (input) INTEGER */
/*                The number of values of N contained in the vector NVAL. */

/*  NVAL          (input) INTEGER array, dimension (NN) */
/*                The values of the matrix dimension N. */

/*  THRESH        (input) DOUBLE PRECISION */
/*                The threshold value for the test ratios.  A result is */
/*                included in the output file if RESULT >= THRESH.  To have */
/*                every test ratio printed, use THRESH = 0. */

/*  A             (workspace) COMPLEX*16 array, dimension (LDA,NMAX) */

/*  LDA           (input) INTEGER */
/*                The leading dimension of the array A.  LDA >= max(1,NMAX). */

/*  ARF           (workspace) COMPLEX*16 array, dimension ((NMAX*(NMAX+1))/2). */

/*  B1            (workspace) COMPLEX*16 array, dimension (LDA,NMAX) */

/*  B2            (workspace) COMPLEX*16 array, dimension (LDA,NMAX) */

/*  D_WORK_ZLANGE (workspace) DOUBLE PRECISION array, dimension (NMAX) */

/*  Z_WORK_ZGEQRF (workspace) COMPLEX*16 array, dimension (NMAX) */

/*  TAU           (workspace) COMPLEX*16 array, dimension (NMAX) */

/*  ===================================================================== */
/*     .. */
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
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Scalars in Common .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Data statements .. */
    /* Parameter adjustments */
    --nval;
    b2_dim1 = *lda;
    b2_offset = 1 + b2_dim1;
    b2 -= b2_offset;
    b1_dim1 = *lda;
    b1_offset = 1 + b1_dim1;
    b1 -= b1_offset;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --arf;
    --d_work_zlange__;
    --z_work_zgeqrf__;
    --tau;

    /* Function Body */
/*     .. */
/*     .. Executable Statements .. */

/*     Initialize constants and the random number seed. */

    nrun = 0;
    nfail = 0;
    info = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
	iseed[i__ - 1] = iseedy[i__ - 1];
/* L10: */
    }
    eps = dlamch_("Precision");

    i__1 = *nn;
    for (iim = 1; iim <= i__1; ++iim) {

	m = nval[iim];

	i__2 = *nn;
	for (iin = 1; iin <= i__2; ++iin) {

	    n = nval[iin];

	    for (iform = 1; iform <= 2; ++iform) {

		*(unsigned char *)cform = *(unsigned char *)&forms[iform - 1];

		for (iuplo = 1; iuplo <= 2; ++iuplo) {

		    *(unsigned char *)uplo = *(unsigned char *)&uplos[iuplo - 
			    1];

		    for (iside = 1; iside <= 2; ++iside) {

			*(unsigned char *)side = *(unsigned char *)&sides[
				iside - 1];

			for (itrans = 1; itrans <= 2; ++itrans) {

			    *(unsigned char *)trans = *(unsigned char *)&
				    transs[itrans - 1];

			    for (idiag = 1; idiag <= 2; ++idiag) {

				*(unsigned char *)diag = *(unsigned char *)&
					diags[idiag - 1];

				for (ialpha = 1; ialpha <= 3; ++ialpha) {

				    if (ialpha == 1) {
					alpha.r = 0., alpha.i = 0.;
				    } else if (ialpha == 1) {
					alpha.r = 1., alpha.i = 0.;
				    } else {
					zlarnd_(&z__1, &c__4, iseed);
					alpha.r = z__1.r, alpha.i = z__1.i;
				    }

/*                             All the parameters are set: */
/*                                CFORM, SIDE, UPLO, TRANS, DIAG, M, N, */
/*                                and ALPHA */
/*                             READY TO TEST! */

				    ++nrun;

				    if (iside == 1) {

/*                                The case ISIDE.EQ.1 is when SIDE.EQ.'L' */
/*                                -> A is M-by-M ( B is M-by-N ) */

					na = m;

				    } else {

/*                                The case ISIDE.EQ.2 is when SIDE.EQ.'R' */
/*                                -> A is N-by-N ( B is M-by-N ) */

					na = n;

				    }

/*                             Generate A our NA--by--NA triangular */
/*                             matrix. */
/*                             Our test is based on forward error so we */
/*                             do want A to be well conditionned! To get */
/*                             a well-conditionned triangular matrix, we */
/*                             take the R factor of the QR/LQ factorization */
/*                             of a random matrix. */

				    i__3 = na;
				    for (j = 1; j <= i__3; ++j) {
					i__4 = na;
					for (i__ = 1; i__ <= i__4; ++i__) {
					    i__5 = i__ + j * a_dim1;
					    zlarnd_(&z__1, &c__4, iseed);
					    a[i__5].r = z__1.r, a[i__5].i = 
						    z__1.i;
					}
				    }

				    if (iuplo == 1) {

/*                                The case IUPLO.EQ.1 is when SIDE.EQ.'U' */
/*                                -> QR factorization. */

					s_copy(srnamc_1.srnamt, "ZGEQRF", (
						ftnlen)32, (ftnlen)6);
					zgeqrf_(&na, &na, &a[a_offset], lda, &
						tau[1], &z_work_zgeqrf__[1], 
						lda, &info);
				    } else {

/*                                The case IUPLO.EQ.2 is when SIDE.EQ.'L' */
/*                                -> QL factorization. */

					s_copy(srnamc_1.srnamt, "ZGELQF", (
						ftnlen)32, (ftnlen)6);
					zgelqf_(&na, &na, &a[a_offset], lda, &
						tau[1], &z_work_zgeqrf__[1], 
						lda, &info);
				    }

/*                             After the QR factorization, the diagonal */
/*                             of A is made of real numbers, we multiply */
/*                             by a random complex number of absolute */
/*                             value 1.0E+00. */

				    i__3 = na;
				    for (j = 1; j <= i__3; ++j) {
					i__4 = j + j * a_dim1;
					i__5 = j + j * a_dim1;
					zlarnd_(&z__2, &c__5, iseed);
					z__1.r = a[i__5].r * z__2.r - a[i__5]
						.i * z__2.i, z__1.i = a[i__5]
						.r * z__2.i + a[i__5].i * 
						z__2.r;
					a[i__4].r = z__1.r, a[i__4].i = 
						z__1.i;
				    }

/*                             Store a copy of A in RFP format (in ARF). */

				    s_copy(srnamc_1.srnamt, "ZTRTTF", (ftnlen)
					    32, (ftnlen)6);
				    ztrttf_(cform, uplo, &na, &a[a_offset], 
					    lda, &arf[1], &info);

/*                             Generate B1 our M--by--N right-hand side */
/*                             and store a copy in B2. */

				    i__3 = n;
				    for (j = 1; j <= i__3; ++j) {
					i__4 = m;
					for (i__ = 1; i__ <= i__4; ++i__) {
					    i__5 = i__ + j * b1_dim1;
					    zlarnd_(&z__1, &c__4, iseed);
					    b1[i__5].r = z__1.r, b1[i__5].i = 
						    z__1.i;
					    i__5 = i__ + j * b2_dim1;
					    i__6 = i__ + j * b1_dim1;
					    b2[i__5].r = b1[i__6].r, b2[i__5]
						    .i = b1[i__6].i;
					}
				    }

/*                             Solve op( A ) X = B or X op( A ) = B */
/*                             with ZTRSM */

				    s_copy(srnamc_1.srnamt, "ZTRSM", (ftnlen)
					    32, (ftnlen)5);
				    ztrsm_(side, uplo, trans, diag, &m, &n, &
					    alpha, &a[a_offset], lda, &b1[
					    b1_offset], lda);

/*                             Solve op( A ) X = B or X op( A ) = B */
/*                             with ZTFSM */

				    s_copy(srnamc_1.srnamt, "ZTFSM", (ftnlen)
					    32, (ftnlen)5);
				    ztfsm_(cform, side, uplo, trans, diag, &m, 
					     &n, &alpha, &arf[1], &b2[
					    b2_offset], lda);

/*                             Check that the result agrees. */

				    i__3 = n;
				    for (j = 1; j <= i__3; ++j) {
					i__4 = m;
					for (i__ = 1; i__ <= i__4; ++i__) {
					    i__5 = i__ + j * b1_dim1;
					    i__6 = i__ + j * b2_dim1;
					    i__7 = i__ + j * b1_dim1;
					    z__1.r = b2[i__6].r - b1[i__7].r, 
						    z__1.i = b2[i__6].i - b1[
						    i__7].i;
					    b1[i__5].r = z__1.r, b1[i__5].i = 
						    z__1.i;
					}
				    }

				    result[0] = zlange_("I", &m, &n, &b1[
					    b1_offset], lda, &d_work_zlange__[
					    1]);

/* Computing MAX */
				    i__3 = max(m,n);
				    result[0] = result[0] / sqrt(eps) / max(
					    i__3,1);

				    if (result[0] >= *thresh) {
					if (nfail == 0) {
					    io___32.ciunit = *nout;
					    s_wsle(&io___32);
					    e_wsle();
					    io___33.ciunit = *nout;
					    s_wsfe(&io___33);
					    e_wsfe();
					}
					io___34.ciunit = *nout;
					s_wsfe(&io___34);
					do_fio(&c__1, "ZTFSM", (ftnlen)5);
					do_fio(&c__1, cform, (ftnlen)1);
					do_fio(&c__1, side, (ftnlen)1);
					do_fio(&c__1, uplo, (ftnlen)1);
					do_fio(&c__1, trans, (ftnlen)1);
					do_fio(&c__1, diag, (ftnlen)1);
					do_fio(&c__1, (char *)&m, (ftnlen)
						sizeof(integer));
					do_fio(&c__1, (char *)&n, (ftnlen)
						sizeof(integer));
					do_fio(&c__1, (char *)&result[0], (
						ftnlen)sizeof(doublereal));
					e_wsfe();
					++nfail;
				    }

/* L100: */
				}
/* L110: */
			    }
/* L120: */
			}
/* L130: */
		    }
/* L140: */
		}
/* L150: */
	    }
/* L160: */
	}
/* L170: */
    }

/*     Print a summary of the results. */

    if (nfail == 0) {
	io___35.ciunit = *nout;
	s_wsfe(&io___35);
	do_fio(&c__1, "ZTFSM", (ftnlen)5);
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	io___36.ciunit = *nout;
	s_wsfe(&io___36);
	do_fio(&c__1, "ZTFSM", (ftnlen)5);
	do_fio(&c__1, (char *)&nfail, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    }


    return 0;

/*     End of ZDRVRF3 */

} /* zdrvrf3_ */
