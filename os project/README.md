
Here is a **clear and exam-oriented summary** of the given **CPU Scheduling program in C++**:

---
## Scheduling Algorithms Implemented

### 1. **FCFS (First Come First Serve)**

* Processes are executed in the **order of arrival**.
* Waiting time of first process is **0**.
* WT of each process = WT of previous process + previous burst time.
* TAT = WT + Burst Time.
* Simple but may cause **convoy effect**.

---

### 2. **SJF (Shortest Job First – Non-Preemptive)**

* Processes are executed in **ascending order of burst time**.
* Burst times are **sorted** before scheduling.
* Minimizes average waiting time.
* Does **not consider arrival time or preemption**.

---

### 3. **Priority Scheduling (Non-Preemptive)**

* Each process is assigned a **priority number**.
* Process with **highest priority (lowest number)** executes first.
* Burst times are rearranged according to priority order.
* WT and TAT are calculated similar to FCFS.

---

### 4. **Round Robin Scheduling**

* Each process gets a **fixed time quantum**.
* Processes execute in cyclic order.
* Remaining burst time is tracked.
* Waiting time is calculated when the process finishes execution.
* Suitable for **time-sharing systems**.

---

## Program Flow

1. User inputs:

   * Number of processes
   * Burst times
2. User selects scheduling algorithm.
3. Additional inputs:

   * Priority values (for Priority scheduling)
   * Time Quantum (for Round Robin)
4. Selected algorithm runs and prints:

   * Process ID
   * Burst Time (BT)
   * Waiting Time (WT)
   * Turnaround Time (TAT)

---

## Key Features

* Menu-driven program
* Uses arrays for process data
* Demonstrates core CPU scheduling logic
* Useful for OS lab experiments and exams

---

## Limitations

* No arrival time considered
* SJF and Priority are **non-preemptive only**
* Process IDs change in SJF and Priority due to sorting
* No average WT or TAT calculation

---

## Conclusion

This program is a **basic CPU scheduling simulator** that helps understand and compare different scheduling algorithms by computing waiting and turnaround times.

---
