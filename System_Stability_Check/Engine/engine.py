class RoutheEngine (object):
    def __init__(self, coefficients_array):
        self.coefficients_array = coefficients_array
        self.degree = len(coefficients_array) - 1

    def check_stability(self):
        if(not self.check_same_sign_coefficients(self.coefficients_array)):
            return False
    
        
        
    def check_same_sign_coefficients(self, coefficients_array):
        return all(x > 0 for x in coefficients_array) or all(x < 0 for x in coefficients_array)
    
    def get_routhe_table(self):
        table = []
        table.append(self.get_first_row())
        table.append(self.get_second_row())
        
        for i in range(2, self.degree + 1):
            table.append(self.get_next_row(table, i))
        return table
        
    

    def get_next_row(self, table, row_index):
        previous_row = table[row_index - 1]
        next_row = []
        for i in range(len(previous_row) - 1):
            next_row.append(self.get_next_element(table, row_index, i))
        next_row.append(0)
        return next_row
    
    def get_first_row(self):
        return [ele for i, ele in enumerate(self.coefficients_array) if i % 2 == 0] + [0]
    
    def get_second_row(self):
        return [ele for i, ele in enumerate(self.coefficients_array) if i % 2 != 0] + [0]
    
    def get_next_element(self, table, i, j):
        up_left, down_left = table[i-2][0], table[i-1][0]
        up_right, down_right = table[i-2][j+1], table[i-1][j+1]
        return  -1 * (up_left * down_right - up_right * down_left) / down_left
    
    