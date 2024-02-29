
import unittest
import sys
import os
# Add the parent directory (project_root) to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from Engine.engine import RoutheEngine as Engine



class TestEngine(unittest.TestCase):
    def test_constructor(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.coefficients_array, coefficients_array)
        self.assertEqual(engine.degree, 3)

    def test_same_sign_coefficients_1(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        self.assertTrue(engine.check_same_sign_coefficients(coefficients_array))

    def test_same_sign_coefficients_2(self):
        coefficients_array = [-1, -2, -3, -4]
        engine = Engine(coefficients_array)
        self.assertTrue(engine.check_same_sign_coefficients(coefficients_array))

    def test_same_sign_coefficients_3(self):
        coefficients_array = [1, -2, 3, -4]
        engine = Engine(coefficients_array)
        self.assertFalse(engine.check_same_sign_coefficients(coefficients_array))

    def test_get_first_row_1(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.get_first_row(), [1, 3, 0])
    
    def test_get_first_row_2(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.get_first_row(), [1, 3, 5, 0])
    
    def test_get_second_row_1(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.get_second_row(), [2, 4, 0])
    
    def test_get_second_row_2(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.get_second_row(), [2, 4, 0])
    
if __name__ == '__main__':
    unittest.main()
