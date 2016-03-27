/* serrrfp.f -- translated by f2c (version 20061008).
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

/* Subroutine */ int serrrfp_(integer *nunit)
{
    /* Format strings */
    static char fmt_9999[] = "(1x,\002REAL RFP routines passed the tests of"
	    " \002,\002the error exits\002)";
    static char fmt_9998[] = "(\002 *** RFP routines failed the tests of the"
	    " error \002,\002exits ***\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    real a[1]	/* was [1][1] */, b[1]	/* was [1][1] */, beta;
    integer info;
    real alpha;
    extern /* Subroutine */ int ssfrk_(char *, char *, char *, integer *, 
	    integer *, real *, real *, integer *, real *, real *), stfsm_(char *, char *, char *, char *, char *, 
	    integer *, integer *, real *, real *, real *, integer *), chkxer_(char *, integer *, 
	    integer *, logical *, logical *), spftrf_(char *, char *, 
	    integer *, real *, integer *), spftri_(char *, 
	    char *, integer *, real *, integer *), stftri_(
	    char *, char *, char *, integer *, real *, integer *), spftrs_(char *, char *, integer *, integer *, 
	    real *, real *, integer *, integer *), stfttp_(
	    char *, char *, integer *, real *, real *, integer *), stpttf_(char *, char *, integer *, real *, real *, 
	    integer *), stfttr_(char *, char *, integer *, 
	    real *, real *, integer *, integer *), strttf_(
	    char *, char *, integer *, real *, integer *, real *, integer *), stpttr_(char *, integer *, real *, real *, 
	    integer *, integer *), strttp_(char *, integer *, real *, 
	    integer *, real *, integer *);

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

/*  SERRRFP tests the error exits for the REAL driver routines */
/*  for solving linear systems of equations. */

/*  SDRVRFP tests the REAL LAPACK RFP routines: */
/*      STFSM, STFTRI, SSFRK, STFTTP, STFTTR, SPFTRF, SPFTRS, STPTTF, */
/*      STPTTR, STRTTF, and STRTTP */

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
    a[0] = 1.f;
    b[0] = 1.f;
    alpha = 1.f;
    beta = 1.f;

    s_copy(srnamc_1.srnamt, "SPFTRF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    spftrf_("/", "U", &c__0, a, &info);
    chkxer_("SPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    spftrf_("N", "/", &c__0, a, &info);
    chkxer_("SPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    spftrf_("N", "U", &c_n1, a, &info);
    chkxer_("SPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "SPFTRS", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    spftrs_("/", "U", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("SPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    spftrs_("N", "/", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("SPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    spftrs_("N", "U", &c_n1, &c__0, a, b, &c__1, &info);
    chkxer_("SPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    spftrs_("N", "U", &c__0, &c_n1, a, b, &c__1, &info);
    chkxer_("SPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    spftrs_("N", "U", &c__0, &c__0, a, b, &c__0, &info);
    chkxer_("SPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "SPFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    spftri_("/", "U", &c__0, a, &info);
    chkxer_("SPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    spftri_("N", "/", &c__0, a, &info);
    chkxer_("SPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    spftri_("N", "U", &c_n1, a, &info);
    chkxer_("SPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STFSM ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    stfsm_("/", "L", "U", "T", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    stfsm_("N", "/", "U", "T", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    stfsm_("N", "L", "/", "T", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    stfsm_("N", "L", "U", "/", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    stfsm_("N", "L", "U", "T", "/", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    stfsm_("N", "L", "U", "T", "U", &c_n1, &c__0, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    stfsm_("N", "L", "U", "T", "U", &c__0, &c_n1, &alpha, a, b, &c__1);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 11;
    stfsm_("N", "L", "U", "T", "U", &c__0, &c__0, &alpha, a, b, &c__0);
    chkxer_("STFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    stftri_("/", "L", "N", &c__0, a, &info);
    chkxer_("STFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    stftri_("N", "/", "N", &c__0, a, &info);
    chkxer_("STFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    stftri_("N", "L", "/", &c__0, a, &info);
    chkxer_("STFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    stftri_("N", "L", "N", &c_n1, a, &info);
    chkxer_("STFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STFTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    stfttr_("/", "U", &c__0, a, b, &c__1, &info);
    chkxer_("STFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    stfttr_("N", "/", &c__0, a, b, &c__1, &info);
    chkxer_("STFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    stfttr_("N", "U", &c_n1, a, b, &c__1, &info);
    chkxer_("STFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    stfttr_("N", "U", &c__0, a, b, &c__0, &info);
    chkxer_("STFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STRTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    strttf_("/", "U", &c__0, a, &c__1, b, &info);
    chkxer_("STRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    strttf_("N", "/", &c__0, a, &c__1, b, &info);
    chkxer_("STRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    strttf_("N", "U", &c_n1, a, &c__1, b, &info);
    chkxer_("STRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    strttf_("N", "U", &c__0, a, &c__0, b, &info);
    chkxer_("STRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STFTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    stfttp_("/", "U", &c__0, a, b, &info);
    chkxer_("STFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    stfttp_("N", "/", &c__0, a, b, &info);
    chkxer_("STFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    stfttp_("N", "U", &c_n1, a, b, &info);
    chkxer_("STFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STPTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    stpttf_("/", "U", &c__0, a, b, &info);
    chkxer_("STPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    stpttf_("N", "/", &c__0, a, b, &info);
    chkxer_("STPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    stpttf_("N", "U", &c_n1, a, b, &info);
    chkxer_("STPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STRTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    strttp_("/", &c__0, a, &c__1, b, &info);
    chkxer_("STRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    strttp_("U", &c_n1, a, &c__1, b, &info);
    chkxer_("STRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    strttp_("U", &c__0, a, &c__0, b, &info);
    chkxer_("STRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "STPTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    stpttr_("/", &c__0, a, b, &c__1, &info);
    chkxer_("STPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    stpttr_("U", &c_n1, a, b, &c__1, &info);
    chkxer_("STPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    stpttr_("U", &c__0, a, b, &c__0, &info);
    chkxer_("STPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "SSFRK ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ssfrk_("/", "U", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("SSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ssfrk_("N", "/", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("SSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ssfrk_("N", "U", "/", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("SSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ssfrk_("N", "U", "N", &c_n1, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("SSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ssfrk_("N", "U", "N", &c__0, &c_n1, &alpha, a, &c__1, &beta, b);
    chkxer_("SSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 8;
    ssfrk_("N", "U", "N", &c__0, &c__0, &alpha, a, &c__0, &beta, b);
    chkxer_("SSFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
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

/*     End of SERRRFP */

} /* serrrfp_ */
