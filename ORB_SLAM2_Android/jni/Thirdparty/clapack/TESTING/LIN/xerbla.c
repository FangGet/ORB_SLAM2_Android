/* xerbla.f -- translated by f2c (version 20061008).
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
#include "string.h"

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

static integer c__1 = 1;

/* Subroutine */ int xerbla_(char *srname, integer *info)
{
    /* Format strings */
    static char fmt_9999[] = "(\002 *** XERBLA was called from \002,a,\002 w"
	    "ith INFO = \002,i6,\002 instead of \002,i2,\002 ***\002)";
    static char fmt_9997[] = "(\002 *** On entry to \002,a,\002 parameter nu"
	    "mber \002,i6,\002 had an illegal value ***\002)";
    static char fmt_9998[] = "(\002 *** XERBLA was called with SRNAME = \002"
	    ",a,\002 instead of \002,a6,\002 ***\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), i_len_trim(char *, ftnlen), do_fio(integer *, 
	    char *, ftnlen), e_wsfe(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___2 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___3 = { 0, 0, 0, fmt_9998, 0 };

	int srname_len;

	srname_len = strlen (srname);


/*  -- LAPACK auxiliary routine (version 3.1) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
/*     November 2006 */

/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  This is a special version of XERBLA to be used only as part of */
/*  the test program for testing error exits from the LAPACK routines. */
/*  Error messages are printed if INFO.NE.INFOT or if SRNAME.NE.SRMANT, */
/*  where INFOT and SRNAMT are values stored in COMMON. */

/*  Arguments */
/*  ========= */

/*  SRNAME  (input) CHARACTER*(*) */
/*          The name of the subroutine calling XERBLA.  This name should */
/*          match the COMMON variable SRNAMT. */

/*  INFO    (input) INTEGER */
/*          The error return code from the calling subroutine.  INFO */
/*          should equal the COMMON variable INFOT. */

/*  Further Details */
/*  ======= ======= */

/*  The following variables are passed via the common blocks INFOC and */
/*  SRNAMC: */

/*  INFOT   INTEGER      Expected integer return code */
/*  NOUT    INTEGER      Unit number for printing error messages */
/*  OK      LOGICAL      Set to .TRUE. if INFO = INFOT and */
/*                       SRNAME = SRNAMT, otherwise set to .FALSE. */
/*  LERR    LOGICAL      Set to .TRUE., indicating that XERBLA was called */
/*  SRNAMT  CHARACTER*(*) Expected name of calling subroutine */


/*     .. Scalars in Common .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Common blocks .. */
/*     .. */
/*     .. Executable Statements .. */

    infoc_1.lerr = TRUE_;
    if (*info != infoc_1.infot) {
	if (infoc_1.infot != 0) {
	    io___1.ciunit = infoc_1.nout;
	    s_wsfe(&io___1);
	    do_fio(&c__1, srnamc_1.srnamt, i_len_trim(srnamc_1.srnamt, (
		    ftnlen)32));
	    do_fio(&c__1, (char *)&(*info), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&infoc_1.infot, (ftnlen)sizeof(integer));
	    e_wsfe();
	} else {
	    io___2.ciunit = infoc_1.nout;
	    s_wsfe(&io___2);
	    do_fio(&c__1, srname, i_len_trim(srname, srname_len));
	    do_fio(&c__1, (char *)&(*info), (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	infoc_1.ok = FALSE_;
    }
    if (s_cmp(srname, srnamc_1.srnamt, srname_len, (ftnlen)32) != 0) {
	io___3.ciunit = infoc_1.nout;
	s_wsfe(&io___3);
	do_fio(&c__1, srname, i_len_trim(srname, srname_len));
	do_fio(&c__1, srnamc_1.srnamt, i_len_trim(srnamc_1.srnamt, (ftnlen)32)
		);
	e_wsfe();
	infoc_1.ok = FALSE_;
    }
    return 0;


/*     End of XERBLA */

} /* xerbla_ */
