import numpy as np
import matplotlib.pyplot as plt

data = np.random.randn(10000)

plt.hist(data, bins=50, histtype='bar')
plt.title("Histogram")
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.grid(True)
plt.tight_layout()

plt.savefig("plot.png")
plt.savefig("plot.pdf")
plt.savefig("plot.svg")

plt.show()
