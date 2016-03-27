/* derrrfp.f -- translated by f2c (version 20061008).
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
static integer c_n1 = -1;
static integer c__1 = 1;

/* Subroutine */ int derrrfp_(integer *nunit)
{
    /* Format strings */
    static char fmt_9999[] = "(1x,\002DOUBLE PRECISION RFP routines passed t"
	    "he tests of \002,\002the error exits\002)";
    static char fmt_9998[] = "(\002 *** RFP routines failed the tests of the"
	    " error \002,\002exits ***\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    doublereal a[1]	/* was [1][1] */, b[1]	/* was [1][1] */, beta;
    integer info;
    doublereal alpha;
    extern /* Subroutine */ int dsfrk_(char *, char *, char *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *), dtfsm_(char *, char *, 
	    char *, char *, char *, integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *), chkxer_(char *, integer *, integer *, logical *, 
	    logical *), dpftrf_(char *, char *, integer *, doublereal 
	    *, integer *), dpftri_(char *, char *, integer *, 
	    doublereal *, integer *), dtftri_(char *, char *, 
	    char *, integer *, doublereal *, integer *), dpftrs_(char *, char *, integer *, integer *, doublereal 
	    *, doublereal *, integer *, integer *), dtfttp_(
	    char *, char *, integer *, doublereal *, doublereal *, integer *), dtpttf_(char *, char *, integer *, doublereal *, 
	    doublereal *, integer *), dtfttr_(char *, char *, 
	    integer *, doublereal *, doublereal *, integer *, integer *), dtrttf_(char *, char *, integer *, doublereal *, 
	    integer *, doublereal *, integer *), dtpttr_(char 
	    *, integer *, doublereal *, doublereal *, integer *, integer *), dtrttp_(char *, integer *, doublereal *, integer *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_9998, 0 };



/*  -- LAPACK test routine (version 3.2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2008 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DERRRFP tests the error exits for the DOUBLE PRECISION driver routines */
/*  for solving linear systems of equations. */

/*  DDRVRFP tests the DOUBLE PRECISION LAPACK RFP routines: */
/*      DTFSM, DTFTRI, DSFRK, DTFTTP, DTFTTR, DPFTRF, DPFTRS, DTPTTF, */
/*      DTPTTR, DTRTTF, and DTRTTP */

/*  Arguments */
/*  ========= */

/*  NUNIT   (input) INTEGER */
/*          The unit number for output. */

/*  ===================================================================== */

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
/*     .. Executable Statements .. */

    infoc_1.nout = *nunit;
    infoc_1.ok = TRUE_;
    a[0] = 1.;
    b[0] = 1.;
    alpha = 1.;
    beta = 1.;

    s_copy(srnamc_1.srnamt, "DPFTRF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dpftrf_("/", "U", &c__0, a, &info);
    chkxer_("DPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dpftrf_("N", "/", &c__0, a, &info);
    chkxer_("DPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dpftrf_("N", "U", &c_n1, a, &info);
    chkxer_("DPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DPFTRS", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dpftrs_("/", "U", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("DPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dpftrs_("N", "/", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("DPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dpftrs_("N", "U", &c_n1, &c__0, a, b, &c__1, &info);
    chkxer_("DPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dpftrs_("N", "U", &c__0, &c_n1, a, b, &c__1, &info);
    chkxer_("DPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    dpftrs_("N", "U", &c__0, &c__0, a, b, &c__0, &info);
    chkxer_("DPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DPFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dpftri_("/", "U", &c__0, a, &info);
    chkxer_("DPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dpftri_("N", "/", &c__0, a, &info);
    chkxer_("DPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dpftri_("N", "U", &c_n1, a, &info);
    chkxer_("DPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTFSM ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtfsm_("/", "L", "U", "T", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtfsm_("N", "/", "U", "T", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dtfsm_("N", "L", "/", "T", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dtfsm_("N", "L", "U", "/", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    dtfsm_("N", "L", "U", "T", "/", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    dtfsm_("N", "L", "U", "T", "U", &c_n1, &c__0, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    dtfsm_("N", "L", "U", "T", "U", &c__0, &c_n1, &alpha, a, b, &c__1);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 11;
    dtfsm_("N", "L", "U", "T", "U", &c__0, &c__0, &alpha, a, b, &c__0);
    chkxer_("DTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtftri_("/", "L", "N", &c__0, a, &info);
    chkxer_("DTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtftri_("N", "/", "N", &c__0, a, &info);
    chkxer_("DTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dtftri_("N", "L", "/", &c__0, a, &info);
    chkxer_("DTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dtftri_("N", "L", "N", &c_n1, a, &info);
    chkxer_("DTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTFTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtfttr_("/", "U", &c__0, a, b, &c__1, &info);
    chkxer_("DTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtfttr_("N", "/", &c__0, a, b, &c__1, &info);
    chkxer_("DTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dtfttr_("N", "U", &c_n1, a, b, &c__1, &info);
    chkxer_("DTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    dtfttr_("N", "U", &c__0, a, b, &c__0, &info);
    chkxer_("DTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTRTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtrttf_("/", "U", &c__0, a, &c__1, b, &info);
    chkxer_("DTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtrttf_("N", "/", &c__0, a, &c__1, b, &info);
    chkxer_("DTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dtrttf_("N", "U", &c_n1, a, &c__1, b, &info);
    chkxer_("DTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    dtrttf_("N", "U", &c__0, a, &c__0, b, &info);
    chkxer_("DTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTFTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtfttp_("/", "U", &c__0, a, b, &info);
    chkxer_("DTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtfttp_("N", "/", &c__0, a, b, &info);
    chkxer_("DTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dtfttp_("N", "U", &c_n1, a, b, &info);
    chkxer_("DTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTPTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtpttf_("/", "U", &c__0, a, b, &info);
    chkxer_("DTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtpttf_("N", "/", &c__0, a, b, &info);
    chkxer_("DTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dtpttf_("N", "U", &c_n1, a, b, &info);
    chkxer_("DTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTRTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtrttp_("/", &c__0, a, &c__1, b, &info);
    chkxer_("DTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtrttp_("U", &c_n1, a, &c__1, b, &info);
    chkxer_("DTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dtrttp_("U", &c__0, a, &c__0, b, &info);
    chkxer_("DTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DTPTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dtpttr_("/", &c__0, a, b, &c__1, &info);
    chkxer_("DTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dtpttr_("U", &c_n1, a, b, &c__1, &info);
    chkxer_("DTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    dtpttr_("U", &c__0, a, b, &c__0, &info);
    chkxer_("DTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "DSFRK ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    dsfrk_("/", "U", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("DSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    dsfrk_("N", "/", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("DSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    dsfrk_("N", "U", "/", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("DSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    dsfrk_("N", "U", "N", &c_n1, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("DSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    dsfrk_("N", "U", "N", &c__0, &c_n1, &alpha, a, &c__1, &beta, b);
    chkxer_("DSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 8;
    dsfrk_("N", "U", "N", &c__0, &c__0, &alpha, a, &c__0, &beta, b);
    chkxer_("DSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

/*     Print a summary line. */

    if (infoc_1.ok) {
	io___6.ciunit = infoc_1.nout;
	s_wsfe(&io___6);
	e_wsfe();
    } else {
	io___7.ciunit = infoc_1.nout;
	s_wsfe(&io___7);
	e_wsfe();
    }

    return 0;

/*     End of DERRRFP */

} /* derrrfp_ */
