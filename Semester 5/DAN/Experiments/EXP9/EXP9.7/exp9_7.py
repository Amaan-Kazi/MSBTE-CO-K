import numpy as np
import matplotlib.pyplot as plt

data1 = np.random.randn(50)  # 50 values from normal distribution
data2 = np.random.randn(50) + 1  # shifted
data3 = np.random.randn(50) - 1
data4 = np.random.randn(50) * 2  # scaled
data5 = np.random.randn(50) * 0.5 + 0.5

datasets = [data1, data2, data3, data4, data5]

plt.boxplot(datasets, label=["Dataset 1", "Dataset 2", "Dataset 3", "Dataset 4", "Dataset 5"])
plt.title("Dataset Distributions")
plt.ylabel("Values")

plt.savefig("plot.png")
plt.savefig("plot.pdf")
plt.savefig("plot.svg")

plt.show()
