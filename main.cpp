#include <iostream>
#include <vector>
#include "linear_regression.h"

using namespace std;

int main() {
    vector<double> hours = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    vector<double> marks = {56, 67, 73, 76, 82, 88, 93, 98, 105, 112};

    LinearRegression model;
    model.fit(hours, marks);

    vector<double> predictions = model.predict(hours);

    model.get_coef();
    model.get_intercept();

    cout << "Mean Squared Error (MSE): " << model.mean_squared_error(predictions, marks) << endl;
    cout << "Root Mean Squared Error (RMSE): " << model.mean_squared_error(predictions, marks, true) << endl;
    cout << "Mean Absolute Error (MAE): " << model.mean_absolute_error(predictions, marks) << endl;
    cout << "R-square (R^2): " << model.r_square(predictions, marks) << endl;
    return 0;
}