import numpy as np
import matplotlib.pyplot as plt

data = np.random.rand(10, 10)

plt.imshow(data)
plt.title("Heatmap")

plt.savefig("plot.png")
plt.savefig("plot.pdf")
plt.savefig("plot.svg")

plt.show()
