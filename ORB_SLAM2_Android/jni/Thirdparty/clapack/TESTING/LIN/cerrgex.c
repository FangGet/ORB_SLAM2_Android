/* cerrgex.f -- translated by f2c (version 20061008).
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
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;

/* Subroutine */ int cerrge_(char *path, integer *nunit)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;
    complex q__1;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    complex a[16]	/* was [4][4] */, b[4];
    integer i__, j;
    real r__[4];
    complex w[8], x[4];
    char c2[2];
    real r1[4], r2[4];
    complex af[16]	/* was [4][4] */;
    char eq[1];
    real cs[4];
    integer ip[4];
    real rs[4];
    complex err_bnds_c__[12]	/* was [4][3] */;
    integer n_err_bnds__;
    complex err_bnds_n__[12]	/* was [4][3] */;
    real berr;
    integer info;
    real anrm, ccond, rcond;
    extern /* Subroutine */ int cgbtf2_(integer *, integer *, integer *, 
	    integer *, complex *, integer *, integer *, integer *), cgetf2_(
	    integer *, integer *, complex *, integer *, integer *, integer *),
	     cgbcon_(char *, integer *, integer *, integer *, complex *, 
	    integer *, integer *, real *, real *, complex *, real *, integer *
), cgecon_(char *, integer *, complex *, integer *, real *
, real *, complex *, real *, integer *), alaesm_(char *, 
	    logical *, integer *), cgbequ_(integer *, integer *, 
	    integer *, integer *, complex *, integer *, real *, real *, real *
, real *, real *, integer *), cgbrfs_(char *, integer *, integer *
, integer *, integer *, complex *, integer *, complex *, integer *
, integer *, complex *, integer *, complex *, integer *, real *, 
	    real *, complex *, real *, integer *), cgbtrf_(integer *, 
	    integer *, integer *, integer *, complex *, integer *, integer *, 
	    integer *), cgeequ_(integer *, integer *, complex *, integer *, 
	    real *, real *, real *, real *, real *, integer *), cgerfs_(char *
, integer *, integer *, complex *, integer *, complex *, integer *
, integer *, complex *, integer *, complex *, integer *, real *, 
	    real *, complex *, real *, integer *), cgetrf_(integer *, 
	    integer *, complex *, integer *, integer *, integer *), cgetri_(
	    integer *, complex *, integer *, integer *, complex *, integer *, 
	    integer *);
    extern logical lsamen_(integer *, char *, char *);
    complex params[1];
    extern /* Subroutine */ int cgbtrs_(char *, integer *, integer *, integer 
	    *, integer *, complex *, integer *, integer *, complex *, integer 
	    *, integer *), chkxer_(char *, integer *, integer *, 
	    logical *, logical *), cgetrs_(char *, integer *, integer 
	    *, complex *, integer *, integer *, complex *, integer *, integer 
	    *), cgbequb_(integer *, integer *, integer *, integer *, 
	    complex *, integer *, real *, real *, real *, real *, real *, 
	    integer *), cgeequb_(integer *, integer *, complex *, integer *, 
	    real *, real *, real *, real *, real *, integer *), cgbrfsx_(char 
	    *, char *, integer *, integer *, integer *, integer *, complex *, 
	    integer *, complex *, integer *, integer *, real *, real *, 
	    complex *, integer *, complex *, integer *, real *, real *, 
	    integer *, complex *, complex *, integer *, complex *, complex *, 
	    real *, integer *);
    integer nparams;
    extern /* Subroutine */ int cgerfsx_(char *, char *, integer *, integer *, 
	     complex *, integer *, complex *, integer *, integer *, real *, 
	    real *, complex *, integer *, complex *, integer *, real *, real *
, integer *, complex *, complex *, integer *, complex *, complex *
, real *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 0, 0, 0, 0 };



/*  -- LAPACK test routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  CERRGE tests the error exits for the COMPLEX routines */
/*  for general matrices. */

/*  Note that this file is used only when the XBLAS are available, */
/*  otherwise cerrge.f defines this subroutine. */

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
/*     .. LOCAL ARRAYS .. */
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
	    i__1 = i__ + (j << 2) - 5;
	    r__1 = 1.f / (real) (i__ + j);
	    r__2 = -1.f / (real) (i__ + j);
	    q__1.r = r__1, q__1.i = r__2;
	    a[i__1].r = q__1.r, a[i__1].i = q__1.i;
	    i__1 = i__ + (j << 2) - 5;
	    r__1 = 1.f / (real) (i__ + j);
	    r__2 = -1.f / (real) (i__ + j);
	    q__1.r = r__1, q__1.i = r__2;
	    af[i__1].r = q__1.r, af[i__1].i = q__1.i;
/* L10: */
	}
	i__1 = j - 1;
	b[i__1].r = 0.f, b[i__1].i = 0.f;
	r1[j - 1] = 0.f;
	r2[j - 1] = 0.f;
	i__1 = j - 1;
	w[i__1].r = 0.f, w[i__1].i = 0.f;
	i__1 = j - 1;
	x[i__1].r = 0.f, x[i__1].i = 0.f;
	cs[j - 1] = 0.f;
	rs[j - 1] = 0.f;
	ip[j - 1] = j;
/* L20: */
    }
    infoc_1.ok = TRUE_;

/*     Test error exits of the routines that use the LU decomposition */
/*     of a general matrix. */

    if (lsamen_(&c__2, c2, "GE")) {

/*        CGETRF */

	s_copy(srnamc_1.srnamt, "CGETRF", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgetrf_(&c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("CGETRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgetrf_(&c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("CGETRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgetrf_(&c__2, &c__1, a, &c__1, ip, &info);
	chkxer_("CGETRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGETF2 */

	s_copy(srnamc_1.srnamt, "CGETF2", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgetf2_(&c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("CGETF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgetf2_(&c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("CGETF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgetf2_(&c__2, &c__1, a, &c__1, ip, &info);
	chkxer_("CGETF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGETRI */

	s_copy(srnamc_1.srnamt, "CGETRI", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgetri_(&c_n1, a, &c__1, ip, w, &c__1, &info);
	chkxer_("CGETRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgetri_(&c__2, a, &c__1, ip, w, &c__2, &info);
	chkxer_("CGETRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgetri_(&c__2, a, &c__2, ip, w, &c__1, &info);
	chkxer_("CGETRI", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGETRS */

	s_copy(srnamc_1.srnamt, "CGETRS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgetrs_("/", &c__0, &c__0, a, &c__1, ip, b, &c__1, &info);
	chkxer_("CGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgetrs_("N", &c_n1, &c__0, a, &c__1, ip, b, &c__1, &info);
	chkxer_("CGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgetrs_("N", &c__0, &c_n1, a, &c__1, ip, b, &c__1, &info);
	chkxer_("CGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	cgetrs_("N", &c__2, &c__1, a, &c__1, ip, b, &c__2, &info);
	chkxer_("CGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 8;
	cgetrs_("N", &c__2, &c__1, a, &c__2, ip, b, &c__1, &info);
	chkxer_("CGETRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGERFS */

	s_copy(srnamc_1.srnamt, "CGERFS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgerfs_("/", &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &c__1, x, &
		c__1, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgerfs_("N", &c_n1, &c__0, a, &c__1, af, &c__1, ip, b, &c__1, x, &
		c__1, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgerfs_("N", &c__0, &c_n1, a, &c__1, af, &c__1, ip, b, &c__1, x, &
		c__1, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	cgerfs_("N", &c__2, &c__1, a, &c__1, af, &c__2, ip, b, &c__2, x, &
		c__2, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 7;
	cgerfs_("N", &c__2, &c__1, a, &c__2, af, &c__1, ip, b, &c__2, x, &
		c__2, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 10;
	cgerfs_("N", &c__2, &c__1, a, &c__2, af, &c__2, ip, b, &c__1, x, &
		c__2, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 12;
	cgerfs_("N", &c__2, &c__1, a, &c__2, af, &c__2, ip, b, &c__2, x, &
		c__1, r1, r2, w, r__, &info);
	chkxer_("CGERFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGERFSX */

	n_err_bnds__ = 3;
	nparams = 0;
	s_copy(srnamc_1.srnamt, "CGERFSX", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	cgerfsx_("/", eq, &c__0, &c__0, a, &c__1, af, &c__1, ip, rs, cs, b, &
		c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	*(unsigned char *)eq = '/';
	cgerfsx_("N", eq, &c__2, &c__1, a, &c__1, af, &c__2, ip, rs, cs, b, &
		c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	*(unsigned char *)eq = 'R';
	cgerfsx_("N", eq, &c_n1, &c__0, a, &c__1, af, &c__1, ip, rs, cs, b, &
		c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgerfsx_("N", eq, &c__0, &c_n1, a, &c__1, af, &c__1, ip, rs, cs, b, &
		c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgerfsx_("N", eq, &c__2, &c__1, a, &c__1, af, &c__2, ip, rs, cs, b, &
		c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 8;
	cgerfsx_("N", eq, &c__2, &c__1, a, &c__2, af, &c__1, ip, rs, cs, b, &
		c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 13;
	*(unsigned char *)eq = 'C';
	cgerfsx_("N", eq, &c__2, &c__1, a, &c__2, af, &c__2, ip, rs, cs, b, &
		c__1, x, &c__2, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 15;
	cgerfsx_("N", eq, &c__2, &c__1, a, &c__2, af, &c__2, ip, rs, cs, b, &
		c__2, x, &c__1, &rcond, &berr, &n_err_bnds__, err_bnds_n__, 
		err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGERFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGECON */

	s_copy(srnamc_1.srnamt, "CGECON", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgecon_("/", &c__0, a, &c__1, &anrm, &rcond, w, r__, &info)
		;
	chkxer_("CGECON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgecon_("1", &c_n1, a, &c__1, &anrm, &rcond, w, r__, &info)
		;
	chkxer_("CGECON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgecon_("1", &c__2, a, &c__1, &anrm, &rcond, w, r__, &info)
		;
	chkxer_("CGECON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGEEQU */

	s_copy(srnamc_1.srnamt, "CGEEQU", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgeequ_(&c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info);
	chkxer_("CGEEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgeequ_(&c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info);
	chkxer_("CGEEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgeequ_(&c__2, &c__2, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info);
	chkxer_("CGEEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGEEQUB */

	s_copy(srnamc_1.srnamt, "CGEEQUB", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	cgeequb_(&c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info)
		;
	chkxer_("CGEEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgeequb_(&c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info)
		;
	chkxer_("CGEEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgeequb_(&c__2, &c__2, a, &c__1, r1, r2, &rcond, &ccond, &anrm, &info)
		;
	chkxer_("CGEEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*     Test error exits of the routines that use the LU decomposition */
/*     of a general band matrix. */

    } else if (lsamen_(&c__2, c2, "GB")) {

/*        CGBTRF */

	s_copy(srnamc_1.srnamt, "CGBTRF", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgbtrf_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("CGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbtrf_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("CGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbtrf_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("CGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbtrf_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("CGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgbtrf_(&c__2, &c__2, &c__1, &c__1, a, &c__3, ip, &info);
	chkxer_("CGBTRF", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBTF2 */

	s_copy(srnamc_1.srnamt, "CGBTF2", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgbtf2_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("CGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbtf2_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, ip, &info);
	chkxer_("CGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbtf2_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, ip, &info);
	chkxer_("CGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbtf2_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, ip, &info);
	chkxer_("CGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgbtf2_(&c__2, &c__2, &c__1, &c__1, a, &c__3, ip, &info);
	chkxer_("CGBTF2", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBTRS */

	s_copy(srnamc_1.srnamt, "CGBTRS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgbtrs_("/", &c__0, &c__0, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbtrs_("N", &c_n1, &c__0, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbtrs_("N", &c__1, &c_n1, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbtrs_("N", &c__1, &c__0, &c_n1, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	cgbtrs_("N", &c__1, &c__0, &c__0, &c_n1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 7;
	cgbtrs_("N", &c__2, &c__1, &c__1, &c__1, a, &c__3, ip, b, &c__2, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 10;
	cgbtrs_("N", &c__2, &c__0, &c__0, &c__1, a, &c__1, ip, b, &c__1, &
		info);
	chkxer_("CGBTRS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBRFS */

	s_copy(srnamc_1.srnamt, "CGBRFS", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgbrfs_("/", &c__0, &c__0, &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbrfs_("N", &c_n1, &c__0, &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbrfs_("N", &c__1, &c_n1, &c__0, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbrfs_("N", &c__1, &c__0, &c_n1, &c__0, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	cgbrfs_("N", &c__1, &c__0, &c__0, &c_n1, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__1, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 7;
	cgbrfs_("N", &c__2, &c__1, &c__1, &c__1, a, &c__2, af, &c__4, ip, b, &
		c__2, x, &c__2, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 9;
	cgbrfs_("N", &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__3, ip, b, &
		c__2, x, &c__2, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 12;
	cgbrfs_("N", &c__2, &c__0, &c__0, &c__1, a, &c__1, af, &c__1, ip, b, &
		c__1, x, &c__2, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 14;
	cgbrfs_("N", &c__2, &c__0, &c__0, &c__1, a, &c__1, af, &c__1, ip, b, &
		c__2, x, &c__1, r1, r2, w, r__, &info);
	chkxer_("CGBRFS", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBRFSX */

	n_err_bnds__ = 3;
	nparams = 0;
	s_copy(srnamc_1.srnamt, "CGBRFSX", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	cgbrfsx_("/", eq, &c__0, &c__0, &c__0, &c__0, a, &c__1, af, &c__1, ip, 
		 rs, cs, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	*(unsigned char *)eq = '/';
	cgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__1, af, &c__2, ip, 
		 rs, cs, b, &c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	*(unsigned char *)eq = 'R';
	cgbrfsx_("N", eq, &c_n1, &c__1, &c__1, &c__0, a, &c__1, af, &c__1, ip, 
		 rs, cs, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	*(unsigned char *)eq = 'R';
	cgbrfsx_("N", eq, &c__2, &c_n1, &c__1, &c__1, a, &c__3, af, &c__4, ip, 
		 rs, cs, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 5;
	*(unsigned char *)eq = 'R';
	cgbrfsx_("N", eq, &c__2, &c__1, &c_n1, &c__1, a, &c__3, af, &c__4, ip, 
		 rs, cs, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgbrfsx_("N", eq, &c__0, &c__0, &c__0, &c_n1, a, &c__1, af, &c__1, ip, 
		 rs, cs, b, &c__1, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 8;
	cgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__1, af, &c__2, ip, 
		 rs, cs, b, &c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 10;
	cgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__3, ip, 
		 rs, cs, b, &c__2, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 13;
	*(unsigned char *)eq = 'C';
	cgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__5, ip, 
		 rs, cs, b, &c__1, x, &c__2, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 15;
	cgbrfsx_("N", eq, &c__2, &c__1, &c__1, &c__1, a, &c__3, af, &c__5, ip, 
		 rs, cs, b, &c__2, x, &c__1, &rcond, &berr, &n_err_bnds__, 
		err_bnds_n__, err_bnds_c__, &nparams, params, w, r__, &info);
	chkxer_("CGBRFSX", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBCON */

	s_copy(srnamc_1.srnamt, "CGBCON", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgbcon_("/", &c__0, &c__0, &c__0, a, &c__1, ip, &anrm, &rcond, w, r__, 
		 &info);
	chkxer_("CGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbcon_("1", &c_n1, &c__0, &c__0, a, &c__1, ip, &anrm, &rcond, w, r__, 
		 &info);
	chkxer_("CGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbcon_("1", &c__1, &c_n1, &c__0, a, &c__1, ip, &anrm, &rcond, w, r__, 
		 &info);
	chkxer_("CGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbcon_("1", &c__1, &c__0, &c_n1, a, &c__1, ip, &anrm, &rcond, w, r__, 
		 &info);
	chkxer_("CGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgbcon_("1", &c__2, &c__1, &c__1, a, &c__3, ip, &anrm, &rcond, w, r__, 
		 &info);
	chkxer_("CGBCON", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBEQU */

	s_copy(srnamc_1.srnamt, "CGBEQU", (ftnlen)32, (ftnlen)6);
	infoc_1.infot = 1;
	cgbequ_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("CGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbequ_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("CGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbequ_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("CGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbequ_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("CGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgbequ_(&c__2, &c__2, &c__1, &c__1, a, &c__2, r1, r2, &rcond, &ccond, 
		&anrm, &info);
	chkxer_("CGBEQU", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);

/*        CGBEQUB */

	s_copy(srnamc_1.srnamt, "CGBEQUB", (ftnlen)32, (ftnlen)7);
	infoc_1.infot = 1;
	cgbequb_(&c_n1, &c__0, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("CGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 2;
	cgbequb_(&c__0, &c_n1, &c__0, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("CGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 3;
	cgbequb_(&c__1, &c__1, &c_n1, &c__0, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("CGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 4;
	cgbequb_(&c__1, &c__1, &c__0, &c_n1, a, &c__1, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("CGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
	infoc_1.infot = 6;
	cgbequb_(&c__2, &c__2, &c__1, &c__1, a, &c__2, r1, r2, &rcond, &ccond, 
		 &anrm, &info);
	chkxer_("CGBEQUB", &infoc_1.infot, &infoc_1.nout, &infoc_1.lerr, &
		infoc_1.ok);
    }

/*     Print a summary line. */

    alaesm_(path, &infoc_1.ok, &infoc_1.nout);

    return 0;

/*     End of CERRGE */

} /* cerrge_ */
