/* derrps.f -- translated by f2c (version 20061008).
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
    integer infot, nout;
    logical ok, lerr;
} infoc_;

#define infoc_1 infoc_

struct {
    char srnamt[32];
} srnamc_;

#define srnamc_1 srnamc_

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static doublereal c_b9 = -1.;
static integer c_n1 = -1;
static integer c__2 = 2;

/* Subroutine */ int derrps_(char *path, integer *nunit)
{
    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal a[16]	/* was [4][4] */;
    integer i__, j, piv[4], info;
    doublereal work[8];
    extern /* Subroutine */ int dpstf2_(char *, integer *, doublereal *, 
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    integer *), alaesm_(char *, logical *, integer *),
	     chkxer_(char *, integer *, integer *, logical *, logical *), dpstrf_(char *, integer *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 0, 0, 0, 0 };



/*  -- LAPACK test routine (version 3.1) -- */
/*     Craig Lucas, University of Manchester / NAG Ltd. */
/*     October, 2008 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DERRPS tests the error exits for the DOUBLE PRECISION routines */
/*  for DPSTRF. */

/*  Arguments */
/*  ========= */

/*  PATH    (input) CHARACTER*3 */
/*          The LAPACK path name for the routines to be tested. */

/*  NUNIT   (input) INTEGER */
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
/*     .. Executable Statements .. */

    infoc_1.nout = *nunit;
    io___1.ciunit = infoc_1.nout;
    s_wsle(&io___1);
    e_wsle();

/*     Set the variables to innocuous values. */

    for (j = 1; j <= 4; ++j) {
	for (i__ = 1; i__ <= 4; ++i__) {
	    a[i__ + (j << 2) - 5] = 1. / (doublereal) (i__ + j);

/* L100: */
	}
	piv[j - 1] = j;
	work[j - 1] = 0.;
	work[j + 3] = 0.;

/* L110: */
    }
    infoc_1.ok = TRUE_;


/*        Test error exits of the routines that use the Cholesky */
/*        decomposition of a symmetric positive semidefinite matrix. */

/*        DPSTRF */

    s_copy(srnamc_1.srnamt, "DPSTRF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dpstrf_("/", &c__0, a, &c__1, piv, &c__1, &c_b9, work, &info);
    chkxer_("DPSTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dpstrf_("U", &c_n1, a, &c__1, piv, &c__1, &c_b9, work, &info);
    chkxer_("DPSTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dpstrf_("U", &c__2, a, &c__1, piv, &c__1, &c_b9, work, &info);
    chkxer_("DPSTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

/*        DPSTF2 */

    s_copy(srnamc_1.srnamt, "DPSTF2", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dpstf2_("/", &c__0, a, &c__1, piv, &c__1, &c_b9, work, &info);
    chkxer_("DPSTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dpstf2_("U", &c_n1, a, &c__1, piv, &c__1, &c_b9, work, &info);
    chkxer_("DPSTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dpstf2_("U", &c__2, a, &c__1, piv, &c__1, &c_b9, work, &info);
    chkxer_("DPSTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);


/*     Print a summary line. */

    alaesm_(path, &infoc_1.ok, &infoc_1.nout);

    return 0;

/*     End of DERRPS */

} /* derrps_ */
