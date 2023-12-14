import sympy as sp

class MathFunction:
    def __init__(self, expression, variables="x"):
        self.expression = sp.sympify(expression)
        self.variables = sp.symbols(variables) if isinstance(variables, str) else variables

    def evaluate(self, **kwargs):
        if not isinstance(self.variables, (tuple, list)):
            self.variables = [self.variables]

        if not set(kwargs.keys()).issubset(self.variables):
            raise ValueError("Invalid variable(s) provided.")

        assignment = {var: kwargs[var] for var in self.variables}
        result = self.expression.evalf(subs=assignment)

        return result

def find_derivative(math_function, variable=None, order=1):
    if isinstance(math_function, MathFunction):
        if variable is None:
            variable = math_function.variables[0]
        expr = math_function.expression
    else:
        if variable is None:
            raise ValueError("If providing a function expression, the variable must be specified.")
        expr = sp.sympify(math_function)

    x = sp.symbols(variable)
    derivative = sp.diff(expr, x, order)

    return derivative
