

import numpy


class Checker:
    def validate(self, coefficients_array, output):
        return (self.num_of_positive_poles(coefficients_array) == 0) == output
    
    def num_of_positive_poles(self, coefficients_array):
        sol = numpy.roots(coefficients_array)
        sol = [x for x in sol if abs(x.real) > 1e-8 and x.real > 0]
        return len(sol)
