/* cchkrfp.f -- translated by f2c (version 20061008).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__12 = 12;
static integer c__0 = 0;
static integer c__50 = 50;
static integer c__16 = 16;
static integer c__9 = 9;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__6 = 6;

/* Main program */ int MAIN__(void)
{
    /* Format strings */
    static char fmt_9994[] = "(/\002 Tests of the COMPLEX LAPACK RFP routine"
	    "s \002,/\002 LAPACK VERSION \002,i1,\002.\002,i1,\002.\002,i1,/"
	    "/\002 The following parameter values will be used:\002)";
    static char fmt_9996[] = "(\002 !! Invalid input value: \002,a4,\002="
	    "\002,i6,\002; must be >=\002,i6)";
    static char fmt_9995[] = "(\002 !! Invalid input value: \002,a4,\002="
	    "\002,i6,\002; must be <=\002,i6)";
    static char fmt_9993[] = "(4x,a4,\002:  \002,10i6,/11x,10i6)";
    static char fmt_9992[] = "(/\002 Routines pass computational tests if te"
	    "st ratio is \002,\002less than\002,f8.2,/)";
    static char fmt_9999[] = "(/\002 Execution not attempted due to input er"
	    "rors\002)";
    static char fmt_9991[] = "(\002 Relative machine \002,a,\002 is taken to"
	    " be\002,d16.6)";
    static char fmt_9998[] = "(/\002 End of tests\002)";
    static char fmt_9997[] = "(\002 Total time used = \002,f12.2,\002 seco"
	    "nds\002,/)";

    /* System generated locals */
    integer i__1;
    real r__1;
    cllist cl__1;

    /* Builtin functions */
    integer s_rsle(cilist *), e_rsle(void), s_wsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_wsfe(void), do_lio(integer *, integer *, 
	    char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), e_wsle(void), f_clos(cllist *);

    /* Local variables */
    complex workafac[2500]	/* was [50][50] */, workasav[2500]	/* 
	    was [50][50] */, workbsav[800]	/* was [50][16] */, workainv[
	    2500]	/* was [50][50] */, workxact[800]	/* was [50][
	    16] */;
    integer i__;
    real s1, s2;
    integer nn, vers_patch__, vers_major__, vers_minor__;
    complex workarfinv[1275];
    real eps;
    integer nns, nnt, nval[12];
    complex c_work_cpot01__[50], c_work_cpot02__[800]	/* was [50][16] */, 
	    c_work_cpot03__[2500]	/* was [50][50] */;
    real s_work_cpot02__[50], s_work_cpot03__[50];
    logical fatal;
    integer nsval[12], ntval[9];
    complex worka[2500]	/* was [50][50] */, workb[800]	/* was [50][16] */, 
	    workx[800]	/* was [50][16] */;
    real s_work_clanhe__[50];
    complex c_work_clatms__[150];
    real s_work_clatms__[50];
    extern doublereal slamch_(char *), second_(void);
    extern /* Subroutine */ int ilaver_(integer *, integer *, integer *);
    real thresh;
    complex workap[1275];
    logical tsterr;
    extern /* Subroutine */ int cdrvrf1_(integer *, integer *, integer *, 
	    real *, complex *, integer *, complex *, real *), cdrvrf2_(
	    integer *, integer *, integer *, complex *, integer *, complex *, 
	    complex *, complex *), cdrvrf3_(integer *, integer *, integer *, 
	    real *, complex *, integer *, complex *, complex *, complex *, 
	    real *, complex *, complex *), cdrvrf4_(integer *, integer *, 
	    integer *, real *, complex *, complex *, integer *, complex *, 
	    complex *, integer *, real *), cerrrfp_(integer *), cdrvrfp_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, complex *, complex *, complex *, complex *, 
	    complex *, complex *, complex *, complex *, complex *, complex *, 
	    complex *, complex *, complex *, complex *, real *, real *, real *
, real *);
    complex workarf[1275];

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 5, 0, 0, 0 };
    static cilist io___7 = { 0, 6, 0, fmt_9994, 0 };
    static cilist io___8 = { 0, 5, 0, 0, 0 };
    static cilist io___10 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___11 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___12 = { 0, 5, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_9993, 0 };
    static cilist io___18 = { 0, 5, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___21 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___22 = { 0, 5, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___25 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_9993, 0 };
    static cilist io___27 = { 0, 5, 0, 0, 0 };
    static cilist io___29 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___30 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___31 = { 0, 5, 0, 0, 0 };
    static cilist io___33 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___34 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___35 = { 0, 6, 0, fmt_9993, 0 };
    static cilist io___36 = { 0, 5, 0, 0, 0 };
    static cilist io___38 = { 0, 6, 0, fmt_9992, 0 };
    static cilist io___39 = { 0, 5, 0, 0, 0 };
    static cilist io___41 = { 0, 6, 0, fmt_9999, 0 };
    static cilist io___42 = { 0, 6, 0, fmt_9999, 0 };
    static cilist io___44 = { 0, 6, 0, fmt_9991, 0 };
    static cilist io___45 = { 0, 6, 0, fmt_9991, 0 };
    static cilist io___46 = { 0, 6, 0, fmt_9991, 0 };
    static cilist io___47 = { 0, 6, 0, 0, 0 };
    static cilist io___68 = { 0, 6, 0, fmt_9998, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_9997, 0 };



/*  -- LAPACK test routine (version 3.2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2008 */

/*  Purpose */
/*  ======= */

/*  CCHKRFP is the main test program for the COMPLEX linear equation */
/*  routines with RFP storage format */


/*  Internal Parameters */
/*  =================== */

/*  MAXIN   INTEGER */
/*          The number of different values that can be used for each of */
/*          M, N, or NB */

/*  MAXRHS  INTEGER */
/*          The maximum number of right hand sides */

/*  NTYPES  INTEGER */

/*  NMAX    INTEGER */
/*          The maximum allowable value for N. */

/*  NIN     INTEGER */
/*          The unit number for input */

/*  NOUT    INTEGER */
/*          The unit number for output */

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
/*     .. Executable Statements .. */

    s1 = second_();
    fatal = FALSE_;

/*     Read a dummy line. */

    s_rsle(&io___3);
    e_rsle();

/*     Report LAPACK version tag (e.g. LAPACK-3.2.0) */

    ilaver_(&vers_major__, &vers_minor__, &vers_patch__);
    s_wsfe(&io___7);
    do_fio(&c__1, (char *)&vers_major__, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&vers_minor__, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&vers_patch__, (ftnlen)sizeof(integer));
    e_wsfe();

/*     Read the values of N */

    s_rsle(&io___8);
    do_lio(&c__3, &c__1, (char *)&nn, (ftnlen)sizeof(integer));
    e_rsle();
    if (nn < 1) {
	s_wsfe(&io___10);
	do_fio(&c__1, " NN ", (ftnlen)4);
	do_fio(&c__1, (char *)&nn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(integer));
	e_wsfe();
	nn = 0;
	fatal = TRUE_;
    } else if (nn > 12) {
	s_wsfe(&io___11);
	do_fio(&c__1, " NN ", (ftnlen)4);
	do_fio(&c__1, (char *)&nn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__12, (ftnlen)sizeof(integer));
	e_wsfe();
	nn = 0;
	fatal = TRUE_;
    }
    s_rsle(&io___12);
    i__1 = nn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_lio(&c__3, &c__1, (char *)&nval[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_rsle();
    i__1 = nn;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (nval[i__ - 1] < 0) {
	    s_wsfe(&io___15);
	    do_fio(&c__1, " M  ", (ftnlen)4);
	    do_fio(&c__1, (char *)&nval[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__0, (ftnlen)sizeof(integer));
	    e_wsfe();
	    fatal = TRUE_;
	} else if (nval[i__ - 1] > 50) {
	    s_wsfe(&io___16);
	    do_fio(&c__1, " M  ", (ftnlen)4);
	    do_fio(&c__1, (char *)&nval[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__50, (ftnlen)sizeof(integer));
	    e_wsfe();
	    fatal = TRUE_;
	}
/* L10: */
    }
    if (nn > 0) {
	s_wsfe(&io___17);
	do_fio(&c__1, "N   ", (ftnlen)4);
	i__1 = nn;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&nval[i__ - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
    }

/*     Read the values of NRHS */

    s_rsle(&io___18);
    do_lio(&c__3, &c__1, (char *)&nns, (ftnlen)sizeof(integer));
    e_rsle();
    if (nns < 1) {
	s_wsfe(&io___20);
	do_fio(&c__1, " NNS", (ftnlen)4);
	do_fio(&c__1, (char *)&nns, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(integer));
	e_wsfe();
	nns = 0;
	fatal = TRUE_;
    } else if (nns > 12) {
	s_wsfe(&io___21);
	do_fio(&c__1, " NNS", (ftnlen)4);
	do_fio(&c__1, (char *)&nns, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__12, (ftnlen)sizeof(integer));
	e_wsfe();
	nns = 0;
	fatal = TRUE_;
    }
    s_rsle(&io___22);
    i__1 = nns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_lio(&c__3, &c__1, (char *)&nsval[i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    e_rsle();
    i__1 = nns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (nsval[i__ - 1] < 0) {
	    s_wsfe(&io___24);
	    do_fio(&c__1, "NRHS", (ftnlen)4);
	    do_fio(&c__1, (char *)&nsval[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__0, (ftnlen)sizeof(integer));
	    e_wsfe();
	    fatal = TRUE_;
	} else if (nsval[i__ - 1] > 16) {
	    s_wsfe(&io___25);
	    do_fio(&c__1, "NRHS", (ftnlen)4);
	    do_fio(&c__1, (char *)&nsval[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__16, (ftnlen)sizeof(integer));
	    e_wsfe();
	    fatal = TRUE_;
	}
/* L30: */
    }
    if (nns > 0) {
	s_wsfe(&io___26);
	do_fio(&c__1, "NRHS", (ftnlen)4);
	i__1 = nns;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&nsval[i__ - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
    }

/*     Read the matrix types */

    s_rsle(&io___27);
    do_lio(&c__3, &c__1, (char *)&nnt, (ftnlen)sizeof(integer));
    e_rsle();
    if (nnt < 1) {
	s_wsfe(&io___29);
	do_fio(&c__1, " NMA", (ftnlen)4);
	do_fio(&c__1, (char *)&nnt, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(integer));
	e_wsfe();
	nnt = 0;
	fatal = TRUE_;
    } else if (nnt > 9) {
	s_wsfe(&io___30);
	do_fio(&c__1, " NMA", (ftnlen)4);
	do_fio(&c__1, (char *)&nnt, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__9, (ftnlen)sizeof(integer));
	e_wsfe();
	nnt = 0;
	fatal = TRUE_;
    }
    s_rsle(&io___31);
    i__1 = nnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_lio(&c__3, &c__1, (char *)&ntval[i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    e_rsle();
    i__1 = nnt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ntval[i__ - 1] < 0) {
	    s_wsfe(&io___33);
	    do_fio(&c__1, "TYPE", (ftnlen)4);
	    do_fio(&c__1, (char *)&ntval[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__0, (ftnlen)sizeof(integer));
	    e_wsfe();
	    fatal = TRUE_;
	} else if (ntval[i__ - 1] > 9) {
	    s_wsfe(&io___34);
	    do_fio(&c__1, "TYPE", (ftnlen)4);
	    do_fio(&c__1, (char *)&ntval[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__9, (ftnlen)sizeof(integer));
	    e_wsfe();
	    fatal = TRUE_;
	}
/* L320: */
    }
    if (nnt > 0) {
	s_wsfe(&io___35);
	do_fio(&c__1, "TYPE", (ftnlen)4);
	i__1 = nnt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&ntval[i__ - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
    }

/*     Read the threshold value for the test ratios. */

    s_rsle(&io___36);
    do_lio(&c__4, &c__1, (char *)&thresh, (ftnlen)sizeof(real));
    e_rsle();
    s_wsfe(&io___38);
    do_fio(&c__1, (char *)&thresh, (ftnlen)sizeof(real));
    e_wsfe();

/*     Read the flag that indicates whether to test the error exits. */

    s_rsle(&io___39);
    do_lio(&c__8, &c__1, (char *)&tsterr, (ftnlen)sizeof(logical));
    e_rsle();

    if (fatal) {
	s_wsfe(&io___41);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    if (fatal) {
	s_wsfe(&io___42);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     Calculate and print the machine dependent constants. */

    eps = slamch_("Underflow threshold");
    s_wsfe(&io___44);
    do_fio(&c__1, "underflow", (ftnlen)9);
    do_fio(&c__1, (char *)&eps, (ftnlen)sizeof(real));
    e_wsfe();
    eps = slamch_("Overflow threshold");
    s_wsfe(&io___45);
    do_fio(&c__1, "overflow ", (ftnlen)9);
    do_fio(&c__1, (char *)&eps, (ftnlen)sizeof(real));
    e_wsfe();
    eps = slamch_("Epsilon");
    s_wsfe(&io___46);
    do_fio(&c__1, "precision", (ftnlen)9);
    do_fio(&c__1, (char *)&eps, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsle(&io___47);
    e_wsle();

/*     Test the error exit of: */

    if (tsterr) {
	cerrrfp_(&c__6);
    }

/*    Test the routines: cpftrf, cpftri, cpftrs (as in CDRVPO). */
/*    This also tests the routines: ctfsm, ctftri, ctfttr, ctrttf. */

    cdrvrfp_(&c__6, &nn, nval, &nns, nsval, &nnt, ntval, &thresh, worka, 
	    workasav, workafac, workainv, workb, workbsav, workxact, workx, 
	    workarf, workarfinv, c_work_clatms__, c_work_cpot01__, 
	    c_work_cpot02__, c_work_cpot03__, s_work_clatms__, 
	    s_work_clanhe__, s_work_cpot02__, s_work_cpot03__);

/*    Test the routine: clanhf */

    cdrvrf1_(&c__6, &nn, nval, &thresh, worka, &c__50, workarf, 
	    s_work_clanhe__);

/*    Test the convertion routines: */
/*       chfttp, ctpthf, ctfttr, ctrttf, ctrttp and ctpttr. */

    cdrvrf2_(&c__6, &nn, nval, worka, &c__50, workarf, workap, workasav);

/*    Test the routine: ctfsm */

    cdrvrf3_(&c__6, &nn, nval, &thresh, worka, &c__50, workarf, workainv, 
	    workafac, s_work_clanhe__, c_work_cpot03__, c_work_cpot01__);


/*    Test the routine: chfrk */

    cdrvrf4_(&c__6, &nn, nval, &thresh, worka, workafac, &c__50, workarf, 
	    workainv, &c__50, s_work_clanhe__);

    cl__1.cerr = 0;
    cl__1.cunit = 5;
    cl__1.csta = 0;
    f_clos(&cl__1);
    s2 = second_();
    s_wsfe(&io___68);
    e_wsfe();
    s_wsfe(&io___69);
    r__1 = s2 - s1;
    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
    e_wsfe();


/*     End of CCHKRFP */

    return 0;
} /* MAIN__ */

/* Main program alias */ int cchkrfp_ () { MAIN__ (); return 0; }
