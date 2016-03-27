SCATGEN = slatm1.c slaran.c slarnd.c

SMATGEN = slatms.c slatme.c slatmr.c slatmt.c \
   slagge.c slagsy.c slakf2.c slarge.c slaror.c slarot.c slatm2.c \
   slatm3.c slatm5.c slatm6.c slatm7.c slahilb.c

CMATGEN = clatms.c clatme.c clatmr.c clatmt.c \
   clagge.c claghe.c clagsy.c clakf2.c clarge.c claror.c clarot.c \
   clatm1.c clarnd.c clatm2.c clatm3.c clatm5.c clatm6.c clahilb.c

DZATGEN = dlatm1.c dlaran.c dlarnd.c

DMATGEN = dlatms.c dlatme.c dlatmr.c dlatmt.c \
   dlagge.c dlagsy.c dlakf2.c dlarge.c dlaror.c dlarot.c dlatm2.c \
   dlatm3.c dlatm5.c dlatm6.c dlatm7.c dlahilb.c

ZMATGEN = zlatms.c zlatme.c zlatmr.c zlatmt.c \
   zlagge.c zlaghe.c zlagsy.c zlakf2.c zlarge.c zlaror.c zlarot.c \
   zlatm1.c zlarnd.c zlatm2.c zlatm3.c zlatm5.c zlatm6.c zlahilb.c

ALLOBJ = $(SMATGEN) $(CMATGEN) $(SCATGEN) $(DMATGEN) $(ZMATGEN)	\
	$(DZATGEN)
