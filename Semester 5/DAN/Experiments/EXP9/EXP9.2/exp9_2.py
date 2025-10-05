import numpy as np
import matplotlib.pyplot as plt

months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun"]
sales = [120, 150, 100, 170, 200, 180]

plt.bar(months, sales)
plt.title("Monthly Sales")
plt.xlabel("Month")
plt.ylabel("Sales")
plt.grid(True)
plt.tight_layout()

plt.savefig("plot.png")
plt.savefig("plot.pdf")
plt.savefig("plot.svg")

plt.show()
