# Linear Regression Example

This is a simple example of linear regression implemented in C++. It includes functionality for fitting a linear regression model, making predictions, and calculating various evaluation metrics like Mean Squared Error (MSE), Root Mean Squared Error (RMSE), Mean Absolute Error (MAE), and R-squared (\(R^2\)).

## Usage

### Prerequisites

Before running the code, ensure you have a C++ compiler installed on your system.

### Code Files

This example consists of two main files:

1. `linear_regression.h`: The header file containing the `LinearRegression` class definition and function prototypes.

2. `main.cpp`: The main program file that demonstrates how to use the `LinearRegression` class with sample data.

### Compiling and Running the Code

1. Compile the code using your C++ compiler. For example, you can use g++:

    ```bash
    g++ main.cpp -o linear_regression
    ```

2. Execute the compiled binary:

    ```bash
    ./linear_regression
    ```

This will fit a linear regression model to the provided data, make predictions, and display the model coefficients, evaluation metrics, and predictions.

## Code Structure

- `LinearRegression` class (defined in `linear_regression.h`): Contains methods for fitting the model, making predictions, and calculating evaluation metrics.
- `fit`: Fits the linear regression model to the data.
- `predict`: Makes predictions using the fitted model.
- `get_coef`: Displays the model coefficients.
- `mean_squared_error`, `mean_absolute_error`, `r_square`: Calculate evaluation metrics.

## Evaluation Metrics

- Mean Squared Error (MSE): A measure of the average squared difference between predicted and actual values.
- Root Mean Squared Error (RMSE): The square root of MSE, providing a measure in the same units as the target variable.
- Mean Absolute Error (MAE): A measure of the average absolute difference between predicted and actual values.
- R-squared (\(R^2\)): A measure of how well the model fits the data, ranging from 0 (poor fit) to 1 (perfect fit).

## Sample Data

The code uses the following sample data for demonstration:

- Independent variable (hours): [2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
- Dependent variable (marks): [56, 67, 73, 76, 82, 88, 93, 98, 105, 112]

## License

This code is provided under the MIT License. Feel free to use and modify it for your own purposes.

Happy coding!
