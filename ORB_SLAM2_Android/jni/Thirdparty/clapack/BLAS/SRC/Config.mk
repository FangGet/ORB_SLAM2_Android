SBLAS1 = isamax.c sasum.c saxpy.c scopy.c sdot.c snrm2.c \
	srot.c srotg.c sscal.c sswap.c sdsdot.c srotmg.c srotm.c

CBLAS1 = scabs1.c scasum.c scnrm2.c icamax.c caxpy.c ccopy.c \
	cdotc.c cdotu.c csscal.c crotg.c cscal.c cswap.c csrot.c

DBLAS1 = idamax.c dasum.c daxpy.c dcopy.c ddot.c dnrm2.c \
	drot.c drotg.c dscal.c dsdot.c dswap.c drotmg.c drotm.c

ZBLAS1 = dcabs1.c dzasum.c dznrm2.c izamax.c zaxpy.c zcopy.c \
	zdotc.c zdotu.c zdscal.c zrotg.c zscal.c zswap.c zdrot.c

CB1AUX = isamax.c sasum.c saxpy.c scopy.c snrm2.c sscal.c

ZB1AUX = idamax.c dasum.c daxpy.c dcopy.c dnrm2.c dscal.c

ALLBLAS  = lsame.c #xerbla.c xerbla_array.c

SBLAS2 = sgemv.c sgbmv.c ssymv.c ssbmv.c sspmv.c \
	strmv.c stbmv.c stpmv.c strsv.c stbsv.c stpsv.c \
	sger.c ssyr.c sspr.c ssyr2.c sspr2.c

CBLAS2 = cgemv.c cgbmv.c chemv.c chbmv.c chpmv.c \
	ctrmv.c ctbmv.c ctpmv.c ctrsv.c ctbsv.c ctpsv.c \
	cgerc.c cgeru.c cher.c chpr.c cher2.c chpr2.c

DBLAS2 = dgemv.c dgbmv.c dsymv.c dsbmv.c dspmv.c \
	dtrmv.c dtbmv.c dtpmv.c dtrsv.c dtbsv.c dtpsv.c \
	dger.c dsyr.c dspr.c dsyr2.c dspr2.c

ZBLAS2 = zgemv.c zgbmv.c zhemv.c zhbmv.c zhpmv.c \
	ztrmv.c ztbmv.c ztpmv.c ztrsv.c ztbsv.c ztpsv.c \
	zgerc.c zgeru.c zher.c zhpr.c zher2.c zhpr2.c

SBLAS3 = sgemm.c ssymm.c ssyrk.c ssyr2k.c strmm.c strsm.c 

CBLAS3 = cgemm.c csymm.c csyrk.c csyr2k.c ctrmm.c ctrsm.c \
	chemm.c cherk.c cher2k.c

DBLAS3 = dgemm.c dsymm.c dsyrk.c dsyr2k.c dtrmm.c dtrsm.c

ZBLAS3 = zgemm.c zsymm.c zsyrk.c zsyr2k.c ztrmm.c ztrsm.c \
	zhemm.c zherk.c zher2k.c

ALLOBJ=$(SBLAS1) $(SBLAS2) $(SBLAS3) $(DBLAS1) $(DBLAS2) $(DBLAS3)	\
	$(CBLAS1) $(CBLAS2) $(CBLAS3) $(ZBLAS1) \
	$(ZBLAS2) $(ZBLAS3) $(ALLBLAS)
