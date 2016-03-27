#define salloc3();	errbnds_n__ = (real *)malloc(nrhs*n_err_bnds__*sizeof(real));\
					errbnds_c__ = (real *)malloc(nrhs*n_err_bnds__*sizeof(real));\
					berr = (real *)malloc(nrhs*sizeof(real));

#define dalloc3();	errbnds_n__ = (doublereal *)malloc(nrhs*n_err_bnds__*sizeof(doublereal));\
					errbnds_c__ = (doublereal *)malloc(nrhs*n_err_bnds__*sizeof(doublereal));\
					berr = (doublereal *)malloc(nrhs*sizeof(doublereal));

#define free3();	free (errbnds_n__);\
					free (errbnds_c__);\
					free (berr);

