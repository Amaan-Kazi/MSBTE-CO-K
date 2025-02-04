bits = eval(input("Bits: "))

# 1 byte = 8 bits
# for converting bytes to megabytes

b = bits / 8
kb = bits / (1024 * 8)
mb = bits / (1024 * 1024 * 8)
gb = bits / (1024 * 1024 * 1024 * 8)
tb = bits / (1024 * 1024 * 1024 * 1024 * 8)

print("Megabytes: ", mb)
print("Gigabytes: ", gb)
print("Terabytes: ", tb)
