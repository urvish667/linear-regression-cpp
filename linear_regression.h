#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class LinearRegression {
  private:
    double coef_, intercept, x_mean, y_mean;

    double average(const vector<double> &L) {
        // calculating mean
        return accumulate( L.begin(), L.end(), 0.0 ) / (double) L.size();
    }

    double calculate_coef(const vector<double> &X, const vector<double> &y, double x_mean, double y_mean) {
        double numerator = inner_product(X.begin(), X.end(), y.begin(), 0.0, std::plus<>(), 
                                        [=](double xi, double yi) { return (xi - x_mean) * (yi - y_mean); });
        double denominator = inner_product(X.begin(), X.end(), X.begin(), 0.0, std::plus<>(), 
                                        [=](double xi, double xi2) { return (xi - x_mean) * (xi - x_mean); });

        return numerator / denominator;
    }


    double calculate_intercept(double coef_, double x_mean, double y_mean) {
        return y_mean - (coef_ * x_mean);
    }

  public:
    LinearRegression() {}

    void fit(const vector<double> &X, const vector<double> &y) {
        x_mean = average(X); y_mean = average(y);

        coef_ = calculate_coef(X, y, x_mean, y_mean);
        intercept = calculate_intercept(coef_, x_mean, y_mean);
    }

    vector<double> predict(vector<double> &X) {
        int length = X.size(); vector<double> predictions;

        for(int i = 0; i < length; i++) {
            predictions.push_back((coef_ * X[i]) + intercept);
        }

        return predictions;
    }

    void get_coef() {
        cout << "Coef_: " << coef_ << endl;
    }

    void get_intercept() {
        cout << "Intercept: " << intercept << endl;
    }

    double mean_squared_error(vector<double> &y_pred, vector<double> &y, bool squared=false) {
        double mse = (inner_product(y.begin(), y.end(), y_pred.begin(), 0.0, std::plus<>(), 
                                        [=](double yi, double yhati) { return  (yi - yhati) * (yi - yhati); })) / (double) y_pred.size(); 

        double rmse = sqrt(mse);

        if(squared) return rmse;
        else return mse;
    }

    double mean_absolute_error(vector<double> &y_pred, vector<double> &y) {
        return (inner_product(y.begin(), y.end(), y_pred.begin(), 0.0, std::plus<>(), 
                                        [=](double yi, double yhati) { return  abs(yi - yhati); })) / (double) y_pred.size();
    }

    double r_square(vector<double> &y_pred, vector<double> &y) {
        double TSS = 0.0;
        for (int i = 0; i < y.size(); i++) {
            TSS += (y[i] - y_mean) * (y[i] - y_mean);
        }
        TSS /= y.size();

        double RSS = 0.0;
        for (int i = 0; i < y.size(); i++) {
            RSS += (y[i] - y_pred[i]) * (y[i] - y_pred[i]);
        }
        RSS /= y_pred.size();

        double r_squared = 1 - (RSS / TSS);

        return r_squared;
    }
};