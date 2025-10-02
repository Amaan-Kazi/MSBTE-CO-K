import numpy as np

str1 = np.array(["Hello", "Testing"])
str2 = np.array([" World", " Numpy"])

result = np.char.add(str1, str2)
print(result)
