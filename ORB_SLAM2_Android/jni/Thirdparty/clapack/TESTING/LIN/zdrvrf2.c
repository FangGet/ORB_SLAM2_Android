/* zdrvrf2.f -- translated by f2c (version 20061008).
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
static integer c__1 = 1;

/* Subroutine */ int zdrvrf2_(integer *nout, integer *nn, integer *nval, 
	doublecomplex *a, integer *lda, doublecomplex *arf, doublecomplex *ap, 
	 doublecomplex *asav)
{
    /* Initialized data */

    static integer iseedy[4] = { 1988,1989,1990,1991 };
    static char uplos[1*2] = "U" "L";
    static char forms[1*2] = "N" "C";

    /* Format strings */
    static char fmt_9999[] = "(1x,\002 *** Error(s) while testing the RFP co"
	    "nvertion\002,\002 routines ***\002)";
    static char fmt_9998[] = "(1x,\002     Error in RFP,convertion routines "
	    "N=\002,i5,\002 UPLO='\002,a1,\002', FORM ='\002,a1,\002'\002)";
    static char fmt_9997[] = "(1x,\002All tests for the RFP convertion routi"
	    "nes passed (\002,i5,\002 tests run)\002)";
    static char fmt_9996[] = "(1x,\002RFP convertion routines:\002,i5,\002 o"
	    "ut of \002,i5,\002 error message recorded\002)";

    /* System generated locals */
    integer a_dim1, a_offset, asav_dim1, asav_offset, i__1, i__2, i__3, i__4, 
	    i__5;
    doublecomplex z__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(void), 
	    do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__, j, n;
    logical ok1, ok2;
    integer iin, info;
    char uplo[1];
    integer nrun, iseed[4];
    char cform[1];
    integer iform;
    logical lower;
    integer iuplo, nerrs;
    extern /* Double Complex */ VOID zlarnd_(doublecomplex *, integer *, 
	    integer *);
    extern /* Subroutine */ int ztfttp_(char *, char *, integer *, 
	    doublecomplex *, doublecomplex *, integer *), 
	    ztpttf_(char *, char *, integer *, doublecomplex *, doublecomplex 
	    *, integer *), ztfttr_(char *, char *, integer *, 
	    doublecomplex *, doublecomplex *, integer *, integer *), ztrttf_(char *, char *, integer *, doublecomplex *, 
	    integer *, doublecomplex *, integer *), ztrttp_(
	    char *, integer *, doublecomplex *, integer *, doublecomplex *, 
	    integer *), ztpttr_(char *, integer *, doublecomplex *, 
	    doublecomplex *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_9996, 0 };




/*  -- LAPACK test routine (version 3.2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2008 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  ZDRVRF2 tests the LAPACK RFP convertion routines. */

/*  Arguments */
/*  ========= */

/*  NOUT          (input) INTEGER */
/*                The unit number for output. */

/*  NN            (input) INTEGER */
/*                The number of values of N contained in the vector NVAL. */

/*  NVAL          (input) INTEGER array, dimension (NN) */
/*                The values of the matrix dimension N. */

/*  A             (workspace) COMPLEX*16 array, dimension (LDA,NMAX) */

/*  LDA           (input) INTEGER */
/*                The leading dimension of the array A.  LDA >= max(1,NMAX). */

/*  ARF           (workspace) COMPLEX*16 array, dimension ((NMAX*(NMAX+1))/2). */

/*  AP            (workspace) COMPLEX*16 array, dimension ((NMAX*(NMAX+1))/2). */

/*  A2            (workspace) COMPLEX*16 array, dimension (LDA,NMAX) */

/*  ===================================================================== */
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
    asav_dim1 = *lda;
    asav_offset = 1 + asav_dim1;
    asav -= asav_offset;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --arf;
    --ap;

    /* Function Body */
/*     .. */
/*     .. Executable Statements .. */

/*     Initialize constants and the random number seed. */

    nrun = 0;
    nerrs = 0;
    info = 0;
    for (i__ = 1; i__ <= 4; ++i__) {
	iseed[i__ - 1] = iseedy[i__ - 1];
/* L10: */
    }

    i__1 = *nn;
    for (iin = 1; iin <= i__1; ++iin) {

	n = nval[iin];

/*        Do first for UPLO = 'U', then for UPLO = 'L' */

	for (iuplo = 1; iuplo <= 2; ++iuplo) {

	    *(unsigned char *)uplo = *(unsigned char *)&uplos[iuplo - 1];
	    lower = TRUE_;
	    if (iuplo == 1) {
		lower = FALSE_;
	    }

/*           Do first for CFORM = 'N', then for CFORM = 'C' */

	    for (iform = 1; iform <= 2; ++iform) {

		*(unsigned char *)cform = *(unsigned char *)&forms[iform - 1];

		++nrun;

		i__2 = n;
		for (j = 1; j <= i__2; ++j) {
		    i__3 = n;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			i__4 = i__ + j * a_dim1;
			zlarnd_(&z__1, &c__4, iseed);
			a[i__4].r = z__1.r, a[i__4].i = z__1.i;
		    }
		}

		s_copy(srnamc_1.srnamt, "ZTRTTF", (ftnlen)32, (ftnlen)6);
		ztrttf_(cform, uplo, &n, &a[a_offset], lda, &arf[1], &info);

		s_copy(srnamc_1.srnamt, "ZTFTTP", (ftnlen)32, (ftnlen)6);
		ztfttp_(cform, uplo, &n, &arf[1], &ap[1], &info);

		s_copy(srnamc_1.srnamt, "ZTPTTR", (ftnlen)32, (ftnlen)6);
		ztpttr_(uplo, &n, &ap[1], &asav[asav_offset], lda, &info);

		ok1 = TRUE_;
		if (lower) {
		    i__2 = n;
		    for (j = 1; j <= i__2; ++j) {
			i__3 = n;
			for (i__ = j; i__ <= i__3; ++i__) {
			    i__4 = i__ + j * a_dim1;
			    i__5 = i__ + j * asav_dim1;
			    if (a[i__4].r != asav[i__5].r || a[i__4].i != 
				    asav[i__5].i) {
				ok1 = FALSE_;
			    }
			}
		    }
		} else {
		    i__2 = n;
		    for (j = 1; j <= i__2; ++j) {
			i__3 = j;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    i__4 = i__ + j * a_dim1;
			    i__5 = i__ + j * asav_dim1;
			    if (a[i__4].r != asav[i__5].r || a[i__4].i != 
				    asav[i__5].i) {
				ok1 = FALSE_;
			    }
			}
		    }
		}

		++nrun;

		s_copy(srnamc_1.srnamt, "ZTRTTP", (ftnlen)32, (ftnlen)6);
		ztrttp_(uplo, &n, &a[a_offset], lda, &ap[1], &info)
			;

		s_copy(srnamc_1.srnamt, "ZTPTTF", (ftnlen)32, (ftnlen)6);
		ztpttf_(cform, uplo, &n, &ap[1], &arf[1], &info);

		s_copy(srnamc_1.srnamt, "ZTFTTR", (ftnlen)32, (ftnlen)6);
		ztfttr_(cform, uplo, &n, &arf[1], &asav[asav_offset], lda, &
			info);

		ok2 = TRUE_;
		if (lower) {
		    i__2 = n;
		    for (j = 1; j <= i__2; ++j) {
			i__3 = n;
			for (i__ = j; i__ <= i__3; ++i__) {
			    i__4 = i__ + j * a_dim1;
			    i__5 = i__ + j * asav_dim1;
			    if (a[i__4].r != asav[i__5].r || a[i__4].i != 
				    asav[i__5].i) {
				ok2 = FALSE_;
			    }
			}
		    }
		} else {
		    i__2 = n;
		    for (j = 1; j <= i__2; ++j) {
			i__3 = j;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    i__4 = i__ + j * a_dim1;
			    i__5 = i__ + j * asav_dim1;
			    if (a[i__4].r != asav[i__5].r || a[i__4].i != 
				    asav[i__5].i) {
				ok2 = FALSE_;
			    }
			}
		    }
		}

		if (! ok1 || ! ok2) {
		    if (nerrs == 0) {
			io___19.ciunit = *nout;
			s_wsle(&io___19);
			e_wsle();
			io___20.ciunit = *nout;
			s_wsfe(&io___20);
			e_wsfe();
		    }
		    io___21.ciunit = *nout;
		    s_wsfe(&io___21);
		    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
		    do_fio(&c__1, uplo, (ftnlen)1);
		    do_fio(&c__1, cform, (ftnlen)1);
		    e_wsfe();
		    ++nerrs;
		}

/* L100: */
	    }
/* L110: */
	}
/* L120: */
    }

/*     Print a summary of the results. */

    if (nerrs == 0) {
	io___22.ciunit = *nout;
	s_wsfe(&io___22);
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	io___23.ciunit = *nout;
	s_wsfe(&io___23);
	do_fio(&c__1, (char *)&nerrs, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nrun, (ftnlen)sizeof(integer));
	e_wsfe();
    }


    return 0;

/*     End of ZDRVRF2 */

} /* zdrvrf2_ */
