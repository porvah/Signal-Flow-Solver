import numpy


class RoutheEngine (object):
    def __init__(self, coefficients_array):
        self.coefficients_array = coefficients_array
        self.simplify_coeffecient()
        self.degree = len(coefficients_array) - 1
        if self.degree < 0:
            raise ValueError("Degree of the polynomial should be greater than or equal to 0")

    def check_stability(self):
        array = self.coefficients_array[:]
        if(not self.check_same_sign_coefficients(array)):
            return False
        table = self.get_routhe_table(array)
        return self.get_number_of_sign_changes(table) == 0
    
    def simplify_coeffecient(self):
        i = 0
        while i < len(self.coefficients_array):
            if self.coefficients_array[i] == 0:
                i += 1
            else:
                break
        self.coefficients_array = self.coefficients_array[i:]
    
    def get_number_of_sign_changes(self, table):
        return len([i for i in range(len(table) - 1) if table[i][0] * table[i + 1][0] < 0])
        
    def check_same_sign_coefficients(self, coefficients_array):
        arr = coefficients_array[:]
        while arr and arr[-1] == 0:
            arr.pop()
        return all(x > 0 for x in arr) or all(x < 0 for x in arr)
    
    def get_routhe_table(self, coefficients_array, reversed = False):
        table = []
        table.append(self.get_first_row(coefficients_array))
        table.append(self.get_second_row(coefficients_array))
        for i in range(2, self.degree + 1):
            if table[i - 1][0] == 0:
                if not reversed:
                    print("computing reverse")
                    return self.get_routhe_table(coefficients_array[::-1], True)
                else:
                    raise ValueError("Cannot compute the routhe table")
            
                
            table.append(self.get_next_row(table, i))
        return table
        
    

    def get_next_row(self, table, row_index):
        previous_row = table[row_index - 1]
        next_row = []
        for i in range(len(previous_row) - 1):
            next_row.append(self.get_next_element(table, row_index, i))
        next_row.append(0)
        return next_row
    
    def get_first_row(self, coefficients_array):
        return [ele for i, ele in enumerate(coefficients_array) if i % 2 == 0] + [0]
    
    def get_second_row(self, coefficients_array):
        return [ele for i, ele in enumerate(coefficients_array) if i % 2 != 0] + [0]
    
    def get_next_element(self, table, i, j):
        up_left, down_left = table[i-2][0], table[i-1][0]
        up_right, down_right = table[i-2][j+1], table[i-1][j+1]
        return  -1 * (up_left * down_right - up_right * down_left) / down_left
    
    def get_poles(self):
        sol = numpy.roots(self.coefficients_array)
        sol = [x for x in sol if x.real > 0]
        assert len(sol) == self.get_number_of_sign_changes(self.get_routhe_table()), f'Number of poles should be equal to the number of sign changes in the routhe table. Expected {self.get_number_of_sign_changes(self.get_routhe_table())}  computed from {self.get_routhe_table()}but got {len(sol)} '
        return sol