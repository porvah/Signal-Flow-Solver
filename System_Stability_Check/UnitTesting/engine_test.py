
import unittest
import sys
import os
# Add the parent directory (project_root) to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from Engine.engine import RoutheEngine as Engine



class TestEngine(unittest.TestCase):
    def test_constructor_1(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.coefficients_array, coefficients_array)
        self.assertEqual(engine.degree, 3)

    def test_constructor_2(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.coefficients_array, coefficients_array)
        self.assertEqual(engine.degree, 4)

    def test_constructor_3(self):
        coefficients_array = [1]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.coefficients_array, coefficients_array)
        self.assertEqual(engine.degree, 0)

    def test_constructor_4(self):
        coefficients_array = [0, 0, 0, 0]
        try:
            engine = Engine(coefficients_array)
        except ValueError as e:
            self.assertEqual(str(e), "Degree of the polynomial should be greater than or equal to 0")

    def test_constructor_5(self):
        coefficients_array = [0, 0, 2, 1]
        engine = Engine(coefficients_array)
        self.assertEqual(engine.coefficients_array, [2, 1])

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


    def test_get_next_element_1(self):
        table = [[1, 31, 0], [10, 1030, 0]]
        engine = Engine([1])
        res = engine.get_next_element(table, 2, 0)
        self.assertEqual(res, -72)

        res = engine.get_next_element(table, 2, 1)
        self.assertEqual(res, 0)

        table = [[1, 31, 0], [1, 103, 0], [-72, 0, 0]]

        res = engine.get_next_element(table, 3, 0)
        self.assertEqual(res, 103)

        res = engine.get_next_element(table, 3, 1)
        self.assertEqual(res, 0)



    def test_get_next_element_2(self):
        coefficients_array = [1]
        engine = Engine(coefficients_array)
        table = [[1, 3, 5, 0], [2, 4, 0, 0]]
        res = engine.get_next_element(table, 2, 0)
        self.assertEqual(res, 1)

        res = engine.get_next_element(table, 2, 1)
        self.assertEqual(res, 5)

        table = [[1, 3, 5, 0], [2, 4, 0, 0], [1, 5, 0]]
        res = engine.get_next_element(table, 3, 0)
        self.assertEqual(res, -6)

        res = engine.get_next_element(table, 3, 1)  
        self.assertEqual(res, 0)

        table = [[1, 3, 5, 0], [2, 4, 0, 0], [1, 5, 0, 0], [-6, 0, 0, 0]]
        res = engine.get_next_element(table, 4, 0)
        self.assertEqual(res, 5)


    def test_get_next_row_1(self):
        coefficients_array = [1]
        engine = Engine(coefficients_array)
        table = [[1, 3, 5, 0], [2, 4, 0, 0]]
        res = engine.get_next_row(table, 2)
        self.assertEqual(res, [1, 5, 0, 0])

    def test_get_next_row_2(self):
        coefficients_array = [1]
        engine = Engine(coefficients_array)
        table = [[1, 3, 5, 0], [2, 4, 0, 0], [1, 5, 0, 0]]
        res = engine.get_next_row(table, 3)
        self.assertEqual(res, [-6, 0, 0, 0])

    def test_get_next_row_3(self):
        coefficients_array = [1, 10, 31, 1030]
        engine = Engine(coefficients_array)
        table = [[1, 31, 0], [10, 1030, 0]]
        table[1] = [i / 10 for i in table[1]]
        res = engine.get_next_row(table, 2)
        self.assertEqual(res, [-72, 0, 0])

        table += [res]
        res = engine.get_next_row(table, 3)
        self.assertEqual(res, [103, 0, 0])

    def test_get_routhe_table_1(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        res = engine.get_routhe_table()
        self.assertEqual(res, [[1, 3, 5, 0], [2, 4, 0], [1, 5, 0], [-6, 0, 0], [5, 0, 0]])

    def test_get_routhe_table_2(self):
        coefficients_array = [1, 10, 31, 1030]
        engine = Engine(coefficients_array)
        res = engine.get_routhe_table()
        self.assertEqual(res, [[1, 31, 0], [10, 1030, 0], [-72, 0, 0], [1030, 0, 0]]) # without dividing the second row by 10 as in reference


    def test_get_number_of_sign_changes_1(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        table = [[1, 3, 5, 0], [2, 4, 0], [1, 5, 0], [-6, 0, 0], [5, 0, 0]]
        res = engine.get_number_of_sign_changes(table)
        self.assertEqual(res, 2)

    def test_get_number_of_sign_changes_2(self):
        coefficients_array = [1, 10, 31, 1030]
        engine = Engine(coefficients_array)
        table = [[1, 31, 0], [10, 1030, 0], [-72, 0, 0], [1030, 0, 0]]
        res = engine.get_number_of_sign_changes(table)
        self.assertEqual(res, 2)

    def test_check_stability_1(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        res = engine.check_stability()
        self.assertFalse(res)


    def test_check_stability_2(self):
        coefficients_array = [1, 10, 31, 1030]
        engine = Engine(coefficients_array)
        res = engine.check_stability()
        self.assertFalse(res)

    def test_check_stability_3(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        res = engine.check_stability()
        self.assertTrue(res)        

    
    def test_check_stability_4(self):
        coefficients_array = [1, 0, 3, 2, 5]
        engine = Engine(coefficients_array)
        res = engine.check_stability()
        self.assertFalse(res)

    def test_check_stability_5(self):
        coefficients_array = [1, 1, 3, 1, 0]
        engine = Engine(coefficients_array)
        res = engine.check_stability()
        self.assertTrue(res)

    def test_get_poles_1(self):
        coefficients_array = [1, 2, 3, 4, 5]
        engine = Engine(coefficients_array)
        try:
            engine.get_poles()
        except AssertionError as e:
            self.assertFalse(True)
        res = engine.get_poles()
        self.assertTrue(all(x.real > 0 for x in res))
        
        
        


if __name__ == '__main__':
    unittest.main()
