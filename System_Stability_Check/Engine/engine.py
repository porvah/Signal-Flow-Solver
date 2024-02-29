class RoutheEngine (object):
    def __init__(self, coefficients_array):
        self.coefficients_array = coefficients_array
        self.degree = len(coefficients_array) - 1

    def check_stability(self):
        if(self.check_same_sign_coefficients(self.coefficients_array)):
            return False
        
    def check_same_sign_coefficients(self, coefficients_array):
        return all(x > 0 for x in coefficients_array) or all(x < 0 for x in coefficients_array)