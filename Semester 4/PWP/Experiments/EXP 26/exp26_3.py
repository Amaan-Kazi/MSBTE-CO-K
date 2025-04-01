import pandas as pd

data_frame = pd.DataFrame({
  "Name": ["Alice", "Bob"],
  "Age":  [25, 30]
})

data_frame.to_csv("sample.csv")
data_frame_read = pd.read_csv("sample.csv")
print(data_frame_read)
