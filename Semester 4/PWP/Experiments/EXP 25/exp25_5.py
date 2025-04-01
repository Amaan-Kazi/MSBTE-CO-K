import pandas as pd

data_list = [
  [1, 'Alice', 20],
  [2, 'Seth',  30],
  [3, 'Mark',  25]
]

diff_list = pd.DataFrame(data_list, columns=["ID", "Name", "Age"])
print(diff_list)
