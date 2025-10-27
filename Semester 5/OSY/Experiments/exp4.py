"""
Experiment 4
Write a C/Python program to calculate
average waiting time and Turnaround Time of n processes
with First Come First Serve (FCFS) CPU scheduling algorithm.
"""


n = int(input("Number Of Processes: "))

# Initialize lists of length n with value 0
arrival_time    = [0] * n
burst_time      = [0] * n
waiting_time    = [0] * n
completion_time = [0] * n
turnaround_time = [0] * n


print("\nEnter Burst Time for each process")

for i in range(n):
  burst_time[i] = int(input(f"P{i+1}: "))
  arrival_time[i] = 0


# First process always has waiting time 0
waiting_time[0] = 0

for i in range(1, n):
  waiting_time[i] = waiting_time[i-1] + burst_time[i-1]


for i in range(n):
  completion_time[i] = waiting_time[i] + burst_time[i]
  turnaround_time[i] = completion_time[i] - arrival_time[i]


print("\nPID\tAT\tBT\tWT\tCT\tTAT")
for i in range(n):
  print(f"P{i+1}\t{arrival_time[i]}\t{burst_time[i]}\t{waiting_time[i]}\t{completion_time[i]}\t{turnaround_time[i]}")

print(f"\nAverage Waiting Time: {sum(waiting_time) / n}")
print(f"Average Turnaround Time: {sum(turnaround_time) / n}")
