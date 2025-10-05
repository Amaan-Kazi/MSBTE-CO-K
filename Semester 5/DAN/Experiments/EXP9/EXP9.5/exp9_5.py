import numpy as np
import matplotlib.pyplot as plt

companies = ['Company A', 'Company B', 'Company C', 'Company D', 'Company E']
market_share = [25, 20, 30, 15, 10] 

plt.pie(market_share, labels=companies)
plt.title("Market Share")

plt.savefig("plot.png")
plt.savefig("plot.pdf")
plt.savefig("plot.svg")

plt.show()
