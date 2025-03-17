# def sum_num(*args):
#     print(sum(args))

# sum_num(1, 2, 3, 4, 5)
# sum_num(10, 12)

def display_info(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

display_info(name="Student", department="Computer Engineering")
display_info(name="Student 2", department="Civil Engineering")