import pprint
import numpy as np


class matrix2vector:
    def __init__(self, n, m, p):
        self.depth = n
        self.width = m
        self.height = p
        self.size1d = n * m * p
        self.matrix3d = np.empty(
            (self.depth, self.width, self.height), dtype=object)
        self.vector1d = np.empty(self.size1d, dtype=object)

    def show_vector(self):
        pprint.pprint(self.matrix3d)
        pprint.pprint(self.vector1d)

    def get_1d_index(self, i, j, k):
        return ((i * self.width * self.height) + (j * self.height) + k)

    def set_element_value(self, i, j, k, value):
        self.matrix3d[i][j][k] = value
        index = self.get_1d_index(i, j, k)
        self.vector1d[index] = value

    def get_element(self, i, j, k):
        index = self.get_1d_index(i, j, k)
        return self.vector1d[index]

    def fill_matrix(self, number):
        self.matrix3d.fill(number)
        self.vector1d.fill(number)
