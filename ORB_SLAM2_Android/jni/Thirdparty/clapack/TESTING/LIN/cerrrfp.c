/* cerrrfp.f -- translated by f2c (version 20061008).
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

/* Subroutine */ int cerrrfp_(integer *nunit)
{
    /* Format strings */
    static char fmt_9999[] = "(1x,\002COMPLEX RFP routines passed the tests "
	    "of the \002,\002error exits\002)";
    static char fmt_9998[] = "(\002 *** RFP routines failed the tests of the"
	    " error \002,\002exits ***\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    complex a[1]	/* was [1][1] */, b[1]	/* was [1][1] */, beta;
    integer info;
    complex alpha;
    extern /* Subroutine */ int chfrk_(char *, char *, char *, integer *, 
	    integer *, complex *, complex *, integer *, complex *, complex *), ctfsm_(char *, char *, char *, char *, 
	    char *, integer *, integer *, complex *, complex *, complex *, 
	    integer *), chkxer_(char *
, integer *, integer *, logical *, logical *), cpftrf_(
	    char *, char *, integer *, complex *, integer *), 
	    cpftri_(char *, char *, integer *, complex *, integer *), ctftri_(char *, char *, char *, integer *, complex *, 
	    integer *), cpftrs_(char *, char *, 
	    integer *, integer *, complex *, complex *, integer *, integer *), ctfttp_(char *, char *, integer *, complex *, 
	    complex *, integer *), ctpttf_(char *, char *, 
	    integer *, complex *, complex *, integer *), 
	    ctfttr_(char *, char *, integer *, complex *, complex *, integer *
, integer *), ctrttf_(char *, char *, integer *, 
	    complex *, integer *, complex *, integer *), 
	    ctpttr_(char *, integer *, complex *, complex *, integer *, 
	    integer *), ctrttp_(char *, integer *, complex *, integer 
	    *, complex *, integer *);

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

/*  CERRRFP tests the error exits for the COMPLEX driver routines */
/*  for solving linear systems of equations. */

/*  CDRVRFP tests the COMPLEX LAPACK RFP routines: */
/*      CTFSM, CTFTRI, CHFRK, CTFTTP, CTFTTR, CPFTRF, CPFTRS, CTPTTF, */
/*      CTPTTR, CTRTTF, and CTRTTP */

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
    a[0].r = 1.f, a[0].i = 1.f;
    b[0].r = 1.f, b[0].i = 1.f;
    alpha.r = 1.f, alpha.i = 1.f;
    beta.r = 1.f, beta.i = 1.f;

    s_copy(srnamc_1.srnamt, "CPFTRF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    cpftrf_("/", "U", &c__0, a, &info);
    chkxer_("CPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    cpftrf_("N", "/", &c__0, a, &info);
    chkxer_("CPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    cpftrf_("N", "U", &c_n1, a, &info);
    chkxer_("CPFTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CPFTRS", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    cpftrs_("/", "U", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("CPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    cpftrs_("N", "/", &c__0, &c__0, a, b, &c__1, &info);
    chkxer_("CPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    cpftrs_("N", "U", &c_n1, &c__0, a, b, &c__1, &info);
    chkxer_("CPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    cpftrs_("N", "U", &c__0, &c_n1, a, b, &c__1, &info);
    chkxer_("CPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    cpftrs_("N", "U", &c__0, &c__0, a, b, &c__0, &info);
    chkxer_("CPFTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CPFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    cpftri_("/", "U", &c__0, a, &info);
    chkxer_("CPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    cpftri_("N", "/", &c__0, a, &info);
    chkxer_("CPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    cpftri_("N", "U", &c_n1, a, &info);
    chkxer_("CPFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTFSM ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctfsm_("/", "L", "U", "C", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctfsm_("N", "/", "U", "C", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ctfsm_("N", "L", "/", "C", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ctfsm_("N", "L", "U", "/", "U", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ctfsm_("N", "L", "U", "C", "/", &c__0, &c__0, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    ctfsm_("N", "L", "U", "C", "U", &c_n1, &c__0, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 7;
    ctfsm_("N", "L", "U", "C", "U", &c__0, &c_n1, &alpha, a, b, &c__1);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 11;
    ctfsm_("N", "L", "U", "C", "U", &c__0, &c__0, &alpha, a, b, &c__0);
    chkxer_("CTFSM ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTFTRI", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctftri_("/", "L", "N", &c__0, a, &info);
    chkxer_("CTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctftri_("N", "/", "N", &c__0, a, &info);
    chkxer_("CTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ctftri_("N", "L", "/", &c__0, a, &info);
    chkxer_("CTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ctftri_("N", "L", "N", &c_n1, a, &info);
    chkxer_("CTFTRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTFTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctfttr_("/", "U", &c__0, a, b, &c__1, &info);
    chkxer_("CTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctfttr_("N", "/", &c__0, a, b, &c__1, &info);
    chkxer_("CTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ctfttr_("N", "U", &c_n1, a, b, &c__1, &info);
    chkxer_("CTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 6;
    ctfttr_("N", "U", &c__0, a, b, &c__0, &info);
    chkxer_("CTFTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTRTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctrttf_("/", "U", &c__0, a, &c__1, b, &info);
    chkxer_("CTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctrttf_("N", "/", &c__0, a, &c__1, b, &info);
    chkxer_("CTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ctrttf_("N", "U", &c_n1, a, &c__1, b, &info);
    chkxer_("CTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ctrttf_("N", "U", &c__0, a, &c__0, b, &info);
    chkxer_("CTRTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTFTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctfttp_("/", "U", &c__0, a, b, &info);
    chkxer_("CTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctfttp_("N", "/", &c__0, a, b, &info);
    chkxer_("CTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ctfttp_("N", "U", &c_n1, a, b, &info);
    chkxer_("CTFTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTPTTF", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctpttf_("/", "U", &c__0, a, b, &info);
    chkxer_("CTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctpttf_("N", "/", &c__0, a, b, &info);
    chkxer_("CTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    ctpttf_("N", "U", &c_n1, a, b, &info);
    chkxer_("CTPTTF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTRTTP", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctrttp_("/", &c__0, a, &c__1, b, &info);
    chkxer_("CTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctrttp_("U", &c_n1, a, &c__1, b, &info);
    chkxer_("CTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    ctrttp_("U", &c__0, a, &c__0, b, &info);
    chkxer_("CTRTTP", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CTPTTR", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    ctpttr_("/", &c__0, a, b, &c__1, &info);
    chkxer_("CTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    ctpttr_("U", &c_n1, a, b, &c__1, &info);
    chkxer_("CTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    ctpttr_("U", &c__0, a, b, &c__0, &info);
    chkxer_("CTPTTR", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);

    s_copy(srnamc_1.srnamt, "CHFRK ", (ftnlen)32, (ftnlen)6);
    infoc_1.infot = 1;
    chfrk_("/", "U", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("CHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 2;
    chfrk_("N", "/", "N", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("CHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 3;
    chfrk_("N", "U", "/", &c__0, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("CHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 4;
    chfrk_("N", "U", "N", &c_n1, &c__0, &alpha, a, &c__1, &beta, b);
    chkxer_("CHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 5;
    chfrk_("N", "U", "N", &c__0, &c_n1, &alpha, a, &c__1, &beta, b);
    chkxer_("CHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
	    infoc_1.ok);
    infoc_1.infot = 8;
    chfrk_("N", "U", "N", &c__0, &c__0, &alpha, a, &c__0, &beta, b);
    chkxer_("CHFRK ", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
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

/*     End of CERRRFP */

} /* cerrrfp_ */
