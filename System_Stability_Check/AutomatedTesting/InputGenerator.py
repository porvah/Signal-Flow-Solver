import random


class InputGenerator:
    def __init__(self, max_len, lower_bound_val, upper_bound_val):
        self.max_len = max_len
        self.lower_bound_val = lower_bound_val
        self.upper_bound_val = upper_bound_val
        
    def generate_coefficients(self):
        length = random.randint(1, self.max_len)
        ret =  [random.randint(self.lower_bound_val, self.upper_bound_val) for _ in range(length)]
        if(all(x == 0 for x in ret)):
            return self.generate_coefficients()
        return ret

    