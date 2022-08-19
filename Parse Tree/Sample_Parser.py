s = "the a rat the cat"
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
0,S,NP,VP
1,NP,ART,N
2,ART,a,an,the
3,N,cat,rat
4,VP,V,NP1
5,V,chases,ate
6,NP1,ART1,N1
7,ART1,a,an,the
8,N1,cat,rat

queue
current_expansion
last_expansion
expanded_nodes
l
counter
flag
len(l)
"""




file1 = open(r"C:\Users\adity\OneDrive\Desktop\eps\GrammarFile.txt")
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
      if l[counter]==queue[0]:
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
