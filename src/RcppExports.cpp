// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// httpClient
void httpClient(const std::string& host, const std::string& path);
RcppExport SEXP _RcppAsioExample_httpClient(SEXP hostSEXP, SEXP pathSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type host(hostSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type path(pathSEXP);
    httpClient(host, path);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppAsioExample_httpClient", (DL_FUNC) &_RcppAsioExample_httpClient, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppAsioExample(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}