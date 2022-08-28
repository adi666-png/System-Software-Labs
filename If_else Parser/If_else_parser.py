s = "if x > 2 y = 3 else if x < 2 y = 1 else y = 0"
l = s.split(" ")

class Node:
   def __init__(self, dataval=None):
      self.dataval = dataval
      self.nextval = None

for i in range(len(l)):
  if i==0:
    e0 = Node(l[0])
  else:
    exec(f"e{i}=Node(l[i])")



for i in range(len(l)-1):
  exec(f"e{i}.nextval = e{i+1}")



for i in range(len(l)-1):
  if i==0:
    exec(f"print(e{i}.dataval)")
    exec(f"print(e{i}.nextval.dataval)")
  else:
    exec(f"print(e{i}.nextval.dataval)")
    



#Parse grammar
"""
0,S,S0,S1,S2,S3,S4
1,S0,if
2,S1,cond
3,S2,action
4,S3,else
5,S4,action1
6,cond,var,bool-op,var1
7,action,assignment,print
8,assignment,var2,assign,var3
9,action1,assignment1,print
10,var,x,y,z
11,var1,x,y,z,0,1,2,3,4,5,6,7,8,9
12,var2,x,y,z
13,var3,x,y,z,0,1,2,3,4,5,6,7,8,9
14,bool-op,>,<,==
15,assign,=
16,assign1,=
17,assignment1,var4,assign2,var5
18,var4,x,y,z,0,1,2,3,4,5,6,7,8,9
19,var5,x,y,z,0,1,2,3,4,5,6,7,8,9
20,assign2,=

queue
current_expansion
last_expansion
expanded_nodes
l
counter
flag
len(l)
"""




file1 = open(r"C:\Users\adity\OneDrive\Desktop\eps\If_Grammar.txt")
Lines = file1.readlines()
count = 0

for line in Lines:
    line = line.strip()
    line = line.split(",")
    Lines[count] = line
    count = count+1



flag = 1
counter = 0
if len(l)==1:
  print("Sentence is trivially grammatically correct.")
else:
  queue = []
  queue.append(Lines[0][1])
  expanded_nodes = []
  current_expansion = queue[0]
  last_expansion = queue[0]  
  while queue and counter<len(l):
          
      if current_expansion=='S4' and last_expansion=='S3' and l[counter]=='if':
          expanded_nodes = ['S','S0']
          last_expansion = 'S0'
          current_expansion = 'S1'
          counter = counter+1
          queue = ['S1','S2','S3','S4','S']
          continue 

      elif l[counter]==queue[0]:
        while queue[0]!= last_expansion:
          queue.pop(0)
        queue.pop(0)
        current_expansion = queue[0]
        counter = counter+1


      elif l[counter]!=queue[0] and counter==0:
        if current_expansion in expanded_nodes:
          while current_expansion in expanded_nodes:
            queue.pop(0)
            current_expansion = queue[0]
            if not len(queue):
              print("Sentence is gramatically correct.")
              break
        else:  
          for i in range(len(Lines)):
            if Lines[i][1]==current_expansion:
              flag= 0  
              expanded_nodes.append(queue[0])
              last_expansion = queue[0]
              queue.reverse()
              for j in range(len(Lines[i])-1,1,-1):
                queue.append(Lines[i][j])
              queue.reverse()
              break
          if flag:  
            queue.pop(0)
          flag=1
          current_expansion =  queue[0]   
      elif l[counter]!=queue[0] and counter!=0:
        if current_expansion == last_expansion:
            print("Sentence is gramatically incorrect due to the word: {}".format(l[counter]))
            break
        if current_expansion in expanded_nodes:
          while current_expansion in expanded_nodes:
            queue.pop(0)
            if len(queue):
              current_expansion = queue[0]
            if not len(queue) and counter<len(l):
                print("Sentence is gramatically incorrect due to end of parse tree rules.")
                break
        else:  
          for i in range(len(Lines)):
            if Lines[i][1]==current_expansion:
              flag=0  
              expanded_nodes.append(queue[0])
              last_expansion = queue[0]
              queue.reverse()
              for j in range(len(Lines[i])-1,1,-1):
                queue.append(Lines[i][j])
              queue.reverse()
              break
          if flag:  
            queue.pop(0)
          flag=1
          current_expansion =  queue[0]
      else:
        print("Something's wrong with the code!")
        exit()  
if counter==len(l):
  print("Sentence is grammatically correct.") 
