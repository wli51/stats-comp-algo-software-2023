#include <Rcpp.h>
#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using namespace Rcpp;

using Eigen::Map;
using Eigen::VectorXd;
using Eigen::MatrixXd;

// [[Rcpp::export]]
VectorXd rcpp_qr(Map<MatrixXd> A, Map<VectorXd> b) {
  if (A.rows() != b.size()) {
    Rcpp::stop("Incompatible matrix-vector dimensions.");
  }
  Eigen::HouseholderQR<Eigen::MatrixXd> qr(A);
  return qr.solve(b);
}
