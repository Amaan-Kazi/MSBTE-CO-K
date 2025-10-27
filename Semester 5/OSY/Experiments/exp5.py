"""
Experiment 5
Write a C/Python program to calculate
average waiting time and Turnaround Time of n processes
with Shortest Job First (SJF) CPU scheduling algorithm.
"""


n = int(input("Number Of Processes: "))

# Initialize lists of length n with value 0
process_id      = [0] * n
arrival_time    = [0] * n
burst_time      = [0] * n
waiting_time    = [0] * n
completion_time = [0] * n
turnaround_time = [0] * n


print("\nEnter Burst Time for each process")

for i in range(n):
  burst_time[i] = int(input(f"P{i+1}: "))
  process_id[i] = i + 1
  arrival_time[i] = 0


# SJF is same as FCFS, except the processes just need to be sorted in ascending order based on burst time
for i in range(n):
  for j in range(n - 1):
    if burst_time[j] > burst_time[j + 1]:
      # Swap Burst Times
      temp = burst_time[j]
      burst_time[j] = burst_time[j + 1]
      burst_time[j + 1] = temp

      # Swap Process IDs
      temp = process_id[j]
      process_id[j] = process_id[j + 1]
      process_id[j + 1] = temp


# First process always has waiting time 0
waiting_time[0] = 0

for i in range(1, n):
  waiting_time[i] = waiting_time[i-1] + burst_time[i-1]


for i in range(n):
  completion_time[i] = waiting_time[i] + burst_time[i]
  turnaround_time[i] = completion_time[i] - arrival_time[i]


print("\nPID\tAT\tBT\tWT\tCT\tTAT")
for i in range(n):
  print(f"P{process_id[i]}\t{arrival_time[i]}\t{burst_time[i]}\t{waiting_time[i]}\t{completion_time[i]}\t{turnaround_time[i]}")

print(f"\nAverage Waiting Time: {sum(waiting_time) / n}")
print(f"Average Turnaround Time: {sum(turnaround_time) / n}")
