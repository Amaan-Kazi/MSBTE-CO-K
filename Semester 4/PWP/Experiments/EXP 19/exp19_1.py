import numpy as np

# Create two matrices
A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
B = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])

add_result = A + B
sub_result = A - B
mul_result = A * B
div_result = np.divide(A, B, out=np.zeros_like(A, dtype=float), where=B!=0)

# Print Results
print("Matrix A:\n", A)
print("\nMatrix B:\n", B)
print("\nAddition:\n", add_result)
print("\nSubtraction:\n", sub_result)
print("\nMultiplication (Element-wise):\n", mul_result)
print("\nDivision (Element-wise):\n", div_result)
