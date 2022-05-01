import pprint

matrix = [[[0, 1, 0], [0, 5, 0], [0, 0, 0]],
          [[0, 2, 0], [0, 0, 0], [0, 0, 0]],
          [[0, 0, 0], [0, 0, 0], [0, 0, 0]]]

vector = []

for i_index in range(len(matrix)):

    for j_index in range(len(matrix[i_index])):

        for k_index in range(len(matrix[i_index][j_index])):

            vector.append(matrix[i_index][j_index][k_index])


pprint.pprint(matrix)
pprint.pprint(vector)
