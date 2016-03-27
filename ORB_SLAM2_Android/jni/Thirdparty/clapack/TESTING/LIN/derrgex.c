/* derrgex.f -- translated by f2c (version 20061008).
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

static integer c__2 = 2;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__12 = 12;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;

/* Subroutine */ int derrge_(char *path, integer *nunit)
{
    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal a[16]	/* was [4][4] */, b[4], c__[4];
    integer i__, j;
    doublereal r__[4], w[12], x[4];
    char c2[2];
    doublereal r1[4], r2[4], af[16]	/* was [4][4] */;
    char eq[1];
    integer ip[4], iw[4];
    doublereal err_bnds_c__[12]	/* was [4][3] */;
    integer n_err_bnds__;
    doublereal err_bnds_n__[12]	/* was [4][3] */, berr;
    integer info;
    doublereal anrm, ccond, rcond;
    extern /* Subroutine */ int dgbtf2_(integer *, integer *, integer *, 
	    integer *, doublereal *, integer *, integer *, integer *), 
	    dgetf2_(integer *, integer *, doublereal *, integer *, integer *, 
	    integer *), dgbcon_(char *, integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), dgecon_(char *, 
	    integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), alaesm_(char *, 
	    logical *, integer *), dgbequ_(integer *, integer *, 
	    integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    , dgbrfs_(char *, integer *, integer *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *), 
	    dgbtrf_(integer *, integer *, integer *, integer *, doublereal *, 
	    integer *, integer *, integer *), dgeequ_(integer *, integer *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *, 
	     doublereal *, doublereal *, integer *), dgerfs_(char *, integer *
, integer *, doublereal *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *), dgetrf_(integer *, integer *, doublereal *, integer *, 
	    integer *, integer *), dgetri_(integer *, doublereal *, integer *, 
	     integer *, doublereal *, integer *, integer *);
    extern logical lsamen_(integer *, char *, char *);
    doublereal params[1];
    extern /* Subroutine */ int chkxer_(char *, integer *, integer *, logical 
	    *, logical *), dgbtrs_(char *, integer *, integer *, 
	    integer *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *), dgetrs_(char *, 
	    integer *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *), dgbequb_(integer *, 
	    integer *, integer *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), dgeequb_(integer *, integer *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *, 
	     doublereal *, doublereal *, integer *), dgbrfsx_(char *, char *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, doublereal *, integer *, integer *, doublereal *, doublereal *, 
	     doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, integer *);
    integer nparams;
    extern /* Subroutine */ int dgerfsx_(char *, char *, integer *, integer *, 
	     doublereal *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *, 
	     integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 0, 0, 0, 0 };



/*  -- LAPACK test routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DERRGE tests the error exits for the DOUBLE PRECISION routines */
/*  for general matrices. */

/*  Note that this file is used only when the XBLAS are available, */
/*  otherwise derrge.f defines this subroutine. */

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
/*     .. External Functions .. */
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
    s_copy(c2, path + 1, (ftnlen)2, (ftnlen)2);

/*     Set the variables to innocuous values. */

    for (j = 1; j <= 4; ++j) {
	for (i__ = 1; i__ <= 4; ++i__) {
	    a[i__ + (j << 2) - 5] = 1. / (doublereal) (i__ + j);
	    af[i__ + (j << 2) - 5] = 1. / (doublereal) (i__ + j);
/* L10: */
	}
	b[j - 1] = 0.;
	r1[j - 1] = 0.;
	r2[j - 1] = 0.;
	w[j - 1] = 0.;
	x[j - 1] = 0.;
	c__[j - 1] = 0.;
	r__[j - 1] = 0.;
	ip[j - 1] = j;
	iw[j - 1] = j;
/* L20: */
    }
    infoc_1.ok = TRUE_;

    if (lsamen_(&c__2, c2, "GE")) {

/*        Test error exits of the routines that use the LU decomposition */
/*        of a general matrix. */

/*        DGETRF */

	s_copy(srnamc_1.srnamt, "DGETRF", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgetrf_(&c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("DGETRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgetrf_(&c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("DGETRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgetrf_(&c__2, &c__1, a, &c__1, ip, &info);
	chkxer_("DGETRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGETF2 */

	s_copy(srnamc_1.srnamt, "DGETF2", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgetf2_(&c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("DGETF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgetf2_(&c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("DGETF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgetf2_(&c__2, &c__1, a, &c__1, ip, &info);
	chkxer_("DGETF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGETRI */

	s_copy(srnamc_1.srnamt, "DGETRI", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgetri_(&c_n1, a, &c__1, ip, w, &c__12, &info);
	chkxer_("DGETRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgetri_(&c__2, a, &c__1, ip, w, &c__12, &info);
	chkxer_("DGETRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGETRS */

	s_copy(srnamc_1.srnamt, "DGETRS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgetrs_("/", &c__0, &c__0, a, &c__1, ip, b, &c__1, &info);
	chkxer_("DGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgetrs_("N", &c_n1, &c__0, a, &c__1, ip, b, &c__1, &info);
	chkxer_("DGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgetrs_("N", &c__0, &c_n1, a, &c__1, ip, b, &c__1, &info);
	chkxer_("DGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	dgetrs_("N", &c__2, &c__1, a, &c__1, ip, b, &c__2, &info);
	chkxer_("DGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 8;
	dgetrs_("N", &c__2, &c__1, a, &c__2, ip, b, &c__1, &info);
	chkxer_("DGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGERFS */

	s_copy(srnamc_1.srnamt, "DGERFS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgerfs_("/", &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &c__1, x, &
		c__1, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgerfs_("N", &c_n1, &c__0, a, &c__1, af, &c__1, ip, b, &c__1, x, &
		c__1, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgerfs_("N", &c__0, &c_n1, a, &c__1, af, &c__1, ip, b, &c__1, x, &
		c__1, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	dgerfs_("N", &c__2, &c__1, a, &c__1, af, &c__2, ip, b, &c__2, x, &
		c__2, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 7;
	dgerfs_("N", &c__2, &c__1, a, &c__2, af, &c__1, ip, b, &c__2, x, &
		c__2, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 10;
	dgerfs_("N", &c__2, &c__1, a, &c__2, af, &c__2, ip, b, &c__1, x, &
		c__2, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 12;
	dgerfs_("N", &c__2, &c__1, a, &c__2, af, &c__2, ip, b, &c__2, x, &
		c__1, r1, r2, w, iw, &info);
	chkxer_("DGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGERFSX */

	n_err_bnds__ = 3;
	nparams = 0;
	s_copy(srnamc_1.srnamt, "DGERFSX", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	dgerfsx_("/", eq, &c__0, &c__0, a, &c__1, af, &c__1, ip, r__, c__, b, 
		&c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	*(unsigned char *)eq = '/';
	dgerfsx_("N", eq, &c__2, &c__1, a, &c__1, af, &c__2, ip, r__, c__, b, 
		&c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	*(unsigned char *)eq = 'R';
	dgerfsx_("N", eq, &c_n1, &c__0, a, &c__1, af, &c__1, ip, r__, c__, b, 
		&c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgerfsx_("N", eq, &c__0, &c_n1, a, &c__1, af, &c__1, ip, r__, c__, b, 
		&c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgerfsx_("N", eq, &c__2, &c__1, a, &c__1, af, &c__2, ip, r__, c__, b, 
		&c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 8;
	dgerfsx_("N", eq, &c__2, &c__1, a, &c__2, af, &c__1, ip, r__, c__, b, 
		&c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 13;
	*(unsigned char *)eq = 'C';
	dgerfsx_("N", eq, &c__2, &c__1, a, &c__2, af, &c__2, ip, r__, c__, b, 
		&c__1, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 15;
	dgerfsx_("N", eq, &c__2, &c__1, a, &c__2, af, &c__2, ip, r__, c__, b, 
		&c__2, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGECON */

	s_copy(srnamc_1.srnamt, "DGECON", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgecon_("/", &c__0, a, &c__1, &anrm, &rcond, w, iw, &info);
	chkxer_("DGECON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgecon_("1", &c_n1, a, &c__1, &anrm, &rcond, w, iw, &info);
	chkxer_("DGECON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgecon_("1", &c__2, a, &c__1, &anrm, &rcond, w, iw, &info);
	chkxer_("DGECON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGEEQU */

	s_copy(srnamc_1.srnamt, "DGEEQU", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgeequ_(&c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info);
	chkxer_("DGEEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgeequ_(&c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info);
	chkxer_("DGEEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgeequ_(&c__2, &c__2, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info);
	chkxer_("DGEEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGEEQUB */

	s_copy(srnamc_1.srnamt, "DGEEQUB", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	dgeequb_(&c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info)
		;
	chkxer_("DGEEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgeequb_(&c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info)
		;
	chkxer_("DGEEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgeequb_(&c__2, &c__2, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info)
		;
	chkxer_("DGEEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

    } else if (lsamen_(&c__2, c2, "GB")) {

/*        Test error exits of the routines that use the LU decomposition */
/*        of a general band matrix. */

/*        DGBTRF */

	s_copy(srnamc_1.srnamt, "DGBTRF", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgbtrf_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("DGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbtrf_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("DGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbtrf_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("DGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbtrf_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("DGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgbtrf_(&c__2, &c__2, &c__1, &c__1, a, &c__3, ip, &info);
	chkxer_("DGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBTF2 */

	s_copy(srnamc_1.srnamt, "DGBTF2", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgbtf2_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("DGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbtf2_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("DGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbtf2_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("DGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbtf2_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("DGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgbtf2_(&c__2, &c__2, &c__1, &c__1, a, &c__3, ip, &info);
	chkxer_("DGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBTRS */

	s_copy(srnamc_1.srnamt, "DGBTRS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgbtrs_("/", &c__0, &c__0, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbtrs_("N", &c_n1, &c__0, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbtrs_("N", &c__1, &c_n1, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbtrs_("N", &c__1, &c__0, &c_n1, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	dgbtrs_("N", &c__1, &c__0, &c__0, &c_n1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 7;
	dgbtrs_("N", &c__2, &c__1, &c__1, &c__1, a, &c__3, ip, b, &c__2, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 10;
	dgbtrs_("N", &c__2, &c__0, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("DGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBRFS */

	s_copy(srnamc_1.srnamt, "DGBRFS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgbrfs_("/", &c__0, &c__0, &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbrfs_("N", &c_n1, &c__0, &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbrfs_("N", &c__1, &c_n1, &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbrfs_("N", &c__1, &c__0, &c_n1, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	dgbrfs_("N", &c__1, &c__0, &c__0, &c_n1, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 7;
	dgbrfs_("N", &c__2, &c__1, &c__1, &c__1, a, &c__2, af, &c__4, ip, b, &
		c__2, x, &c__2, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 9;
	dgbrfs_("N", &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__3, ip, b, &
		c__2, x, &c__2, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 12;
	dgbrfs_("N", &c__2, &c__0, &c__0, &c__1, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__2, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 14;
	dgbrfs_("N", &c__2, &c__0, &c__0, &c__1, a, &c__1, af, &c__1, ip, b, &
		c__2, x, &c__1, r1, r2, w, iw, &info);
	chkxer_("DGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBRFSX */

	n_err_bnds__ = 3;
	nparams = 0;
	s_copy(srnamc_1.srnamt, "DGBRFSX", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	dgbrfsx_("/", eq, &c__0, &c__0, &c__0, &c__0, a, &c__1, af, &c__1, ip, 
		 r__, c__, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	*(unsigned char *)eq = '/';
	dgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__1, af, &c__2, ip, 
		 r__, c__, b, &c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	*(unsigned char *)eq = 'R';
	dgbrfsx_("N", eq, &c_n1, &c__1, &c__1, &c__0, a, &c__1, af, &c__1, ip, 
		 r__, c__, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	*(unsigned char *)eq = 'R';
	dgbrfsx_("N", eq, &c__2, &c_n1, &c__1, &c__1, a, &c__3, af, &c__4, ip, 
		 r__, c__, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	*(unsigned char *)eq = 'R';
	dgbrfsx_("N", eq, &c__2, &c__1, &c_n1, &c__1, a, &c__3, af, &c__4, ip, 
		 r__, c__, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgbrfsx_("N", eq, &c__0, &c__0, &c__0, &c_n1, a, &c__1, af, &c__1, ip, 
		 r__, c__, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 8;
	dgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__1, af, &c__2, ip, 
		 r__, c__, b, &c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 10;
	dgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__3, ip, 
		 r__, c__, b, &c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 13;
	*(unsigned char *)eq = 'C';
	dgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__5, ip, 
		 r__, c__, b, &c__1, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 15;
	dgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__5, ip, 
		 r__, c__, b, &c__2, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, iw, &info);
	chkxer_("DGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBCON */

	s_copy(srnamc_1.srnamt, "DGBCON", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgbcon_("/", &c__0, &c__0, &c__0, a, &c__1, ip, &anrm, &rcond, w, iw, 
		&info);
	chkxer_("DGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbcon_("1", &c_n1, &c__0, &c__0, a, &c__1, ip, &anrm, &rcond, w, iw, 
		&info);
	chkxer_("DGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbcon_("1", &c__1, &c_n1, &c__0, a, &c__1, ip, &anrm, &rcond, w, iw, 
		&info);
	chkxer_("DGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbcon_("1", &c__1, &c__0, &c_n1, a, &c__1, ip, &anrm, &rcond, w, iw, 
		&info);
	chkxer_("DGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgbcon_("1", &c__2, &c__1, &c__1, a, &c__3, ip, &anrm, &rcond, w, iw, 
		&info);
	chkxer_("DGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBEQU */

	s_copy(srnamc_1.srnamt, "DGBEQU", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	dgbequ_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("DGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbequ_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("DGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbequ_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("DGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbequ_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("DGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgbequ_(&c__2, &c__2, &c__1, &c__1, a, &c__2, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("DGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        DGBEQUB */

	s_copy(srnamc_1.srnamt, "DGBEQUB", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	dgbequb_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("DGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	dgbequb_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("DGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	dgbequb_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("DGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	dgbequb_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("DGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	dgbequb_(&c__2, &c__2, &c__1, &c__1, a, &c__2, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("DGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
    }

/*     Print a summary line. */

    alaesm_(path, &infoc_1.ok, &infoc_1.nout);

    return 0;

/*     End of DERRGE */

} /* derrge_ */
