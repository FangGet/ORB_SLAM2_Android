/* ddrvrf1.f -- translated by f2c (version 20061008).
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

static integer c__2 = 2;
static integer c__1 = 1;

/* Subroutine */ int ddrvrf1_(integer *nout, integer *nn, integer *nval, 
	doublereal *thresh, doublereal *a, integer *lda, doublereal *arf, 
	doublereal *work)
{
    /* Initialized data */

    static integer iseedy[4] = { 1988,1989,1990,1991 };
    static char uplos[1*2] = "U" "L";
    static char forms[1*2] = "N" "T";
    static char norms[1*4] = "M" "1" "I" "F";

    /* Format strings */
    static char fmt_9999[] = "(1x,\002 *** Error(s) or Failure(s) while test"
	    "ing DLANSF              ***\002)";
    static char fmt_9998[] = "(1x,\002     Error in \002,a6,\002 with UPLO="
	    "'\002,a1,\002', FORM='\002,a1,\002', N=\002,i5)";
    static char fmt_9997[] = "(1x,\002     Failure in \002,a6,\002 N=\002,"
	    "i5,\002 TYPE=\002,i5,\002 UPLO='\002,a1,\002', FORM ='\002,a1"
	    ",\002', NORM='\002,a1,\002', test=\002,g12.5)";
    static char fmt_9996[] = "(1x,\002All tests for \002,a6,\002 auxiliary r"
	    "outine passed the \002,\002threshold (\002,i5,\002 tests run)"
	    "\002)";
    static char fmt_9995[] = "(1x,a6,\002 auxiliary routine:\002,i5,\002 out"
	    " of \002,i5,\002 tests failed to pass the threshold\002)";
    static char fmt_9994[] = "(26x,i5,\002 error message recorded (\002,a6"
	    ",\002)\002)";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(void), 
	    do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__, j, n, iin, iit;
    doublereal eps;
    integer info;
    char norm[1], uplo[1];
    integer nrun, nfail;
    doublereal large;
    integer iseed[4];
    char cform[1];
    doublereal small;
    integer iform;
    doublereal norma;
    integer inorm, iuplo, nerrs;
    extern doublereal dlamch_(char *), dlarnd_(integer *, integer *), 
	    dlansf_(char *, char *, char *, integer *, doublereal *, 
	    doublereal *), dlansy_(char *, char *, 
	    integer *, doublereal *, integer *, doublereal *);
    extern /* Subroutine */ int dtrttf_(char *, char *, integer *, doublereal 
	    *, integer *, doublereal *, integer *);
    doublereal result[1], normarf;

    /* Fortran I/O blocks */
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___30 = { 0, 0, 0, 0, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_9996, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_9994, 0 };



/*  -- LAPACK test routine (version 3.2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DDRVRF1 tests the LAPACK RFP routines: */
/*      DLANSF */

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

/*  A             (workspace) DOUBLE PRECISION array, dimension (LDA,NMAX) */

/*  LDA           (input) INTEGER */
/*                The leading dimension of the array A.  LDA >= max(1,NMAX). */

/*  ARF           (workspace) DOUBLE PRECISION array, dimension ((NMAX*(NMAX+1))/2). */

/*  WORK          (workspace) DOUBLE PRECISION array, dimension ( NMAX ) */

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
/*     .. Scalars in Common .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Data statements .. */
    /* Parameter adjustments */
    --nval;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --arf;
    --work;

    /* Function Body */
/*     .. */
/*     .. Executable Statements .. */

/*     Initialize constants and the random number seed. */

    nrun = 0;
    nfail = 0;
    nerrs = 0;
    info = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
	iseed[i__ - 1] = iseedy[i__ - 1];
/* L10: */
    }

    eps = dlamch_("Precision");
    small = dlamch_("Safe minimum");
    large = 1. / small;
    small = small * *lda * *lda;
    large = large / *lda / *lda;

    i__1 = *nn;
    for (iin = 1; iin <= i__1; ++iin) {

	n = nval[iin];

	for (iit = 1; iit <= 3; ++iit) {

/*           IIT = 1 : random matrix */
/*           IIT = 2 : random matrix scaled near underflow */
/*           IIT = 3 : random matrix scaled near overflow */

	    i__2 = n;
	    for (j = 1; j <= i__2; ++j) {
		i__3 = n;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    a[i__ + j * a_dim1] = dlarnd_(&c__2, iseed);
		}
	    }

	    if (iit == 2) {
		i__2 = n;
		for (j = 1; j <= i__2; ++j) {
		    i__3 = n;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			a[i__ + j * a_dim1] *= large;
		    }
		}
	    }

	    if (iit == 3) {
		i__2 = n;
		for (j = 1; j <= i__2; ++j) {
		    i__3 = n;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			a[i__ + j * a_dim1] *= small;
		    }
		}
	    }

/*           Do first for UPLO = 'U', then for UPLO = 'L' */

	    for (iuplo = 1; iuplo <= 2; ++iuplo) {

		*(unsigned char *)uplo = *(unsigned char *)&uplos[iuplo - 1];

/*              Do first for CFORM = 'N', then for CFORM = 'C' */

		for (iform = 1; iform <= 2; ++iform) {

		    *(unsigned char *)cform = *(unsigned char *)&forms[iform 
			    - 1];

		    s_copy(srnamc_1.srnamt, "DTRTTF", (ftnlen)32, (ftnlen)6);
		    dtrttf_(cform, uplo, &n, &a[a_offset], lda, &arf[1], &
			    info);

/*                 Check error code from DTRTTF */

		    if (info != 0) {
			if (nfail == 0 && nerrs == 0) {
			    io___22.ciunit = *nout;
			    s_wsle(&io___22);
			    e_wsle();
			    io___23.ciunit = *nout;
			    s_wsfe(&io___23);
			    e_wsfe();
			}
			io___24.ciunit = *nout;
			s_wsfe(&io___24);
			do_fio(&c__1, srnamc_1.srnamt, (ftnlen)32);
			do_fio(&c__1, uplo, (ftnlen)1);
			do_fio(&c__1, cform, (ftnlen)1);
			do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
			e_wsfe();
			++nerrs;
			goto L100;
		    }

		    for (inorm = 1; inorm <= 4; ++inorm) {

/*                    Check all four norms: 'M', '1', 'I', 'F' */

			*(unsigned char *)norm = *(unsigned char *)&norms[
				inorm - 1];
			normarf = dlansf_(norm, cform, uplo, &n, &arf[1], &
				work[1]);
			norma = dlansy_(norm, uplo, &n, &a[a_offset], lda, &
				work[1]);

			result[0] = (norma - normarf) / norma / eps;
			++nrun;

			if (result[0] >= *thresh) {
			    if (nfail == 0 && nerrs == 0) {
				io___30.ciunit = *nout;
				s_wsle(&io___30);
				e_wsle();
				io___31.ciunit = *nout;
				s_wsfe(&io___31);
				e_wsfe();
			    }
			    io___32.ciunit = *nout;
			    s_wsfe(&io___32);
			    do_fio(&c__1, "DLANSF", (ftnlen)6);
			    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer))
				    ;
			    do_fio(&c__1, (char *)&iit, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, uplo, (ftnlen)1);
			    do_fio(&c__1, cform, (ftnlen)1);
			    do_fio(&c__1, norm, (ftnlen)1);
			    do_fio(&c__1, (char *)&result[0], (ftnlen)sizeof(
				    doublereal));
			    e_wsfe();
			    ++nfail;
			}
/* L90: */
		    }
L100:
		    ;
		}
/* L110: */
	    }
/* L120: */
	}
/* L130: */
    }

/*     Print a summary of the results. */

    if (nfail == 0) {
	io___33.ciunit = *nout;
	s_wsfe(&io___33);
	do_fio(&c__1, "DLANSF", (ftnlen)6);
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	io___34.ciunit = *nout;
	s_wsfe(&io___34);
	do_fio(&c__1, "DLANSF", (ftnlen)6);
	do_fio(&c__1, (char *)&nfail, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (nerrs != 0) {
	io___35.ciunit = *nout;
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&nerrs, (ftnlen)sizeof(integer));
	do_fio(&c__1, "DLANSF", (ftnlen)6);
	e_wsfe();
    }


    return 0;

/*     End of DDRVRF1 */

} /* ddrvrf1_ */
