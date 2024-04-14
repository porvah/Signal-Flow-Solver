
import os
import sys

import numpy



paths = ['./System_Stability_Check']
for path in paths:
    abs_path = os.path.abspath(path)
    print(f"Original path: {path}, Absolute path: {abs_path}")
    if abs_path not in sys.path:
        sys.path.append(abs_path)

from Engine.engine import RoutheEngine
from InputGenerator import InputGenerator
from Checker import Checker

if __name__ == '__main__':
    num_tests = 100000
    failed_tests = []
    inputGen = InputGenerator(10, -1, 10)
    for i in range(1, num_tests + 1):
        try:
                input = inputGen.generate_coefficients()
                output, table = RoutheEngine(input).check_stability()

                # print("Expected output: ", Checker().num_of_positive_poles(input) == 0)
                # print("Actual output: ", output)
                # print("Good" if output == (Checker().num_of_positive_poles(input) == 0) else "Bad")
                if not Checker().validate(input, output):
                    failed_tests.append(input)
        except Exception as e:
             print(f"Test {i} failed with exception: {e}")
             print(f"Test input: {input}")       
             failed_tests.append(input) 

        

    print("No of failed tests: ", len(failed_tests))

    for i in failed_tests:
        print(i)
        print(numpy.roots(i))
        print("Expected output: ", Checker().num_of_positive_poles(i) == 0)

    print("Tests passed: ", num_tests - len(failed_tests), "/", num_tests)

