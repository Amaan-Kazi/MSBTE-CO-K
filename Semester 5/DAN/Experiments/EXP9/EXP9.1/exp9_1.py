import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 400)
y = x**2

plt.plot(x, y, linewidth=2)
plt.title("Plot of y = x^2")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.tight_layout()

plt.savefig("plot.png")
plt.savefig("plot.pdf")
plt.savefig("plot.svg")

plt.show()
