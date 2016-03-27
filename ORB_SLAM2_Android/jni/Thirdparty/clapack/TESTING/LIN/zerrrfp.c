/* zerrrfp.f -- translated by f2c (version 20061008).
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

/* Subroutine */ int zerrrfp_(integer *nunit)
{
    /* Format strings */
    static char fmt_9999[] = "(1x,\002COMPLEX*16 RFP routines passed the tes"
	    "ts of the \002,\002error exits\002)";
    static char fmt_9998[] = "(\002 *** RFP routines failed the tests of the"
	    " error \002,\002exits ***\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    doublecomplex a[1]	/* was [1][1] */, b[1]	/* was [1][1] */, beta;
    integer info;
    doublecomplex alpha;
    extern /* Subroutine */ int zhfrk_(char *, char *, char *, integer *, 
	    integer *, doublecomplex *, doublecomplex *, integer *, 
	    doublecomplex *, doublecomplex *), ztfsm_(
	    char *, char *, char *, char *, char *, integer *, integer *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, integer *), chkxer_(char *, integer *
, integer *, logical *, logical *), zpftrf_(char *, char *
, integer *, doublecomplex *, integer *), zpftri_(
	    char *, char *, integer *, doublecomplex *, integer *), ztftri_(char *, char *, char *, integer *, doublecomplex 
	    *, integer *), zpftrs_(char *, char *, 
	    integer *, integer *, doublecomplex *, doublecomplex *, integer *, 
	     integer *), ztfttp_(char *, char *, integer *, 
	    doublecomplex *, doublecomplex *, integer *), 
	    ztpttf_(char *, char *, integer *, doublecomplex *, doublecomplex 
	    *, integer *), ztfttr_(char *, char *, integer *, 
	    doublecomplex *, doublecomplex *, integer *, integer *), ztrttf_(char *, char *, integer *, doublecomplex *, 
	    integer *, doublecomplex *, integer *), ztpttr_(
	    char *, integer *, doublecomplex *, doublecomplex *, integer *, 
	    integer *), ztrttp_(char *, integer *, doublecomplex *, 
	    integer *, doublecomplex *, integer *);

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

/*  ZERRRFP tests the error exits for the COMPLEX*16 driver routines */
/*  for solving linear systems of equations. */

/*  ZDRVRFP tests the COMPLEX*16 LAPACK RFP routines: */
/*      ZTFSM, ZTFTRI, ZHFRK, ZTFTTP, ZTFTTR, ZPFTRF, ZPFTRS, ZTPTTF, */
/*      ZTPTTR, ZTRTTF, and ZTRTTP */

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
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Executable Statements .. */

    infoc_1.nout = *nunit;
    infoc_1.ok = TRUE_;
    a[0].r = 1., a[0].i = 1.;
    b[0].r = 1., b[0].i = 1.;
    alpha.r = 1., alpha.i = 1.;
    beta.r = 1., beta.i = 1.;

    s_copy(srnamc_1.srnamt, "ZPFTRF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    zpftrf_("/", "U", &c__0, a, &info);
    chkxer_("ZPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    zpftrf_("N", "/", &c__0, a, &info);
    chkxer_("ZPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    zpftrf_("N", "U", &c_n1, a, &info);
    chkxer_("ZPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZPFTRS", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    zpftrs_("/", "U", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("ZPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    zpftrs_("N", "/", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("ZPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    zpftrs_("N", "U", &c_n1, &c__0, a, b, &c__1, &info);
    chkxer_("ZPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    zpftrs_("N", "U", &c__0, &c_n1, a, b, &c__1, &info);
    chkxer_("ZPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    zpftrs_("N", "U", &c__0, &c__0, a, b, &c__0, &info);
    chkxer_("ZPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZPFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    zpftri_("/", "U", &c__0, a, &info);
    chkxer_("ZPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    zpftri_("N", "/", &c__0, a, &info);
    chkxer_("ZPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    zpftri_("N", "U", &c_n1, a, &info);
    chkxer_("ZPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTFSM ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztfsm_("/", "L", "U", "C", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztfsm_("N", "/", "U", "C", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ztfsm_("N", "L", "/", "C", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ztfsm_("N", "L", "U", "/", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ztfsm_("N", "L", "U", "C", "/", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    ztfsm_("N", "L", "U", "C", "U", &c_n1, &c__0, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    ztfsm_("N", "L", "U", "C", "U", &c__0, &c_n1, &alpha, a, b, &c__1);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 11;
    ztfsm_("N", "L", "U", "C", "U", &c__0, &c__0, &alpha, a, b, &c__0);
    chkxer_("ZTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztftri_("/", "L", "N", &c__0, a, &info);
    chkxer_("ZTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztftri_("N", "/", "N", &c__0, a, &info);
    chkxer_("ZTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ztftri_("N", "L", "/", &c__0, a, &info);
    chkxer_("ZTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ztftri_("N", "L", "N", &c_n1, a, &info);
    chkxer_("ZTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTFTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztfttr_("/", "U", &c__0, a, b, &c__1, &info);
    chkxer_("ZTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztfttr_("N", "/", &c__0, a, b, &c__1, &info);
    chkxer_("ZTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ztfttr_("N", "U", &c_n1, a, b, &c__1, &info);
    chkxer_("ZTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    ztfttr_("N", "U", &c__0, a, b, &c__0, &info);
    chkxer_("ZTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTRTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztrttf_("/", "U", &c__0, a, &c__1, b, &info);
    chkxer_("ZTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztrttf_("N", "/", &c__0, a, &c__1, b, &info);
    chkxer_("ZTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ztrttf_("N", "U", &c_n1, a, &c__1, b, &info);
    chkxer_("ZTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ztrttf_("N", "U", &c__0, a, &c__0, b, &info);
    chkxer_("ZTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTFTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztfttp_("/", "U", &c__0, a, b, &info);
    chkxer_("ZTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztfttp_("N", "/", &c__0, a, b, &info);
    chkxer_("ZTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ztfttp_("N", "U", &c_n1, a, b, &info);
    chkxer_("ZTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTPTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztpttf_("/", "U", &c__0, a, b, &info);
    chkxer_("ZTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztpttf_("N", "/", &c__0, a, b, &info);
    chkxer_("ZTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ztpttf_("N", "U", &c_n1, a, b, &info);
    chkxer_("ZTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTRTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztrttp_("/", &c__0, a, &c__1, b, &info);
    chkxer_("ZTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztrttp_("U", &c_n1, a, &c__1, b, &info);
    chkxer_("ZTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ztrttp_("U", &c__0, a, &c__0, b, &info);
    chkxer_("ZTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZTPTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ztpttr_("/", &c__0, a, b, &c__1, &info);
    chkxer_("ZTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ztpttr_("U", &c_n1, a, b, &c__1, &info);
    chkxer_("ZTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ztpttr_("U", &c__0, a, b, &c__0, &info);
    chkxer_("ZTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "ZHFRK ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    zhfrk_("/", "U", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("ZHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    zhfrk_("N", "/", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("ZHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    zhfrk_("N", "U", "/", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("ZHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    zhfrk_("N", "U", "N", &c_n1, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("ZHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    zhfrk_("N", "U", "N", &c__0, &c_n1, &alpha, a, &c__1, &beta, b);
    chkxer_("ZHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 8;
    zhfrk_("N", "U", "N", &c__0, &c__0, &alpha, a, &c__0, &beta, b);
    chkxer_("ZHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
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

/*     End of ZERRRFP */

} /* zerrrfp_ */
