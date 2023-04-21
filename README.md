# ShortestJobFirstPreemptionAlgo

This Algorithm is basically a CPU Scheduling Preemption Algorithm
Brute Force Technique to Solve this Problem
This code working fine in Windows as well as Linux


Steps 
Step 1: Given Process Name, Arrival Time, Burst Time and Declare the Complete Time, Turn Around Time, Wating Time Array.
Step 2: Calculate the Max no of iteration for the program Sum all the BT and terminate the loop with variable name “sp”.
Step 3: Create the temporary PID, AT, BT array to check the AT for each iteration with the help of “sp” variable.
Step 4: After that those process which are in the ready state then calculate the minimum BT from the temporary BT and decrement by 1 in every iteration.
Step 5: At every iteration we check that which process BT appears to be zero according to which we update the CT with “sp” variable.
Step 6: After Completing all the iteration we get all Processes BT will be 0.
Step 7: After that Calculate the TAT(Turn Around Time) = CT(Completion Time) – AT(Arrival Time) and WT(Wating Time) = TAT(Turn Around Time) – BT(Burst Time).
Step 8: Display the Data with sequence of PID AT BT CT TAT WT
Step 9: End of Algorithm.




  By Tushar Chand Thakur
