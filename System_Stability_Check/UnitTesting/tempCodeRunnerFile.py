


    def test_get_next_element_2(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        table = [[1, 2, 3, 4], [1, 3, 0], [2, 4, 0]]
        self.assertEqual(engine.get_next_element(table, 3, 1), -1.0)

    def test_get_next_element_3(self):
        coefficients_array = [1, 2, 3, 4]
        engine = Engine(coefficients_array)
        table = [[1, 2, 3, 4], [1, 3, 0], [2, 4, 0]]
        self.assertEqual(engine.get_next_element(table, 4, 0), -2.0)
    