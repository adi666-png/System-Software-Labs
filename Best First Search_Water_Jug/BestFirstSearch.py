class Node:
   def __init__(self,firstval,secondval,identifier,prevval):
      self.firstval = firstval
      self.secondval = secondval
      self.identifier = identifier
      self.prevval = prevval
      self.gcost = 0
      self.hcost = 0
    
   def update_cost(self,round,target):
      self.gcost = round
      self.hcost = min(abs(self.firstval - target),abs(self.secondval - target))


i = 2
first_jug_capacity = 4
second_jug_capacity = 3
target = 2
round = 2                 

e0 = Node(first_jug_capacity,0,0,None)
e0.update_cost(1,target)
e1 = Node(0,second_jug_capacity,1,None)
e1.update_cost(1,target)

flag = 1
not_expanded = [e0,e1]
last_check = 2

while flag:
    to_be_expanded = []
    to_be_deleted = []
    cost = []
    for j in not_expanded:
        cost.append(j.gcost+j.hcost)
    mincost = min(cost)

    for j in not_expanded:
        if j.gcost+j.hcost==mincost:
            to_be_expanded.append(j)
            to_be_deleted.append(j)

    for j in to_be_deleted:
        not_expanded.remove(j)
    
    for j in to_be_expanded:
        #global i
        if j.firstval!=first_jug_capacity:
            exec(f"e{i}=Node(first_jug_capacity,j.secondval,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
        if j.secondval!=second_jug_capacity:
            exec(f"e{i}=Node(j.firstval,second_jug_capacity,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
        if j.firstval!=0 and j.secondval!=0:
            exec(f"e{i}=Node(0,j.secondval,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1        
        if j.secondval!=0 and j.firstval!=0:
            exec(f"e{i}=Node(j.firstval,0,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
        if j.firstval+j.secondval<first_jug_capacity and j.secondval!=0:
            exec(f"e{i}=Node(j.firstval+j.secondval,0,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
        if j.firstval+j.secondval<second_jug_capacity and j.firstval!=0:
            exec(f"e{i}=Node(0,j.firstval+j.secondval,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
        if j.firstval+j.secondval>first_jug_capacity:
            exec(f"e{i}=Node(first_jug_capacity,j.secondval-(first_jug_capacity-j.firstval),i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
        if j.firstval+j.secondval>second_jug_capacity:
            exec(f"e{i}=Node(j.firstval-(second_jug_capacity-j.secondval),second_jug_capacity,i,e{j.identifier})")
            exec(f"e{i}.update_cost(round,target)")
            i = i+1
    
     
    for j in range(last_check,i,1):
        exec(f"not_expanded.append(e{j})")     
    
    for j in not_expanded:
        if j.firstval==target or j.secondval==target:
            flag = 0
            final_result = []
            while j.prevval !=None:
                final_result.append(j)
                j = j.prevval
            final_result.reverse()
            print((0,0))
            for j in final_result:
                print((j.firstval,j.secondval))
            break    
    round = round+1
    last_check = i          


