# Best First Search Algorithm

The water jug problem for 2 jugs has been solved using Best First Search Algorithm.

The search space is expanded using a Best First Search approach as shown below:

<img align="center" alt="Coding" width="400" height="300" src="https://github.com/adi666-png/System-Software-Labs/blob/main/assets/BestFirstSearch.gif">

The heuristic function used here has two parts:

(a) Cost of generation of nodes g(x): Calculated using the distance from the root null node 

(b) Cost function h(x): Here, the function used was min(|x-target|,|y-target|), where x,y are the capacities of the two buckets and target is the desired final value required

The search space is expanded in that direction which minimizes g(x)+h(x) until a suitable solution is found. 

A reverse trace to the beginning to performed to find the most optimal path to the solution.
