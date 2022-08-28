# If-else Parse-Tree

A recursive if-else parser was implemented using a list in Python which enforces the rules present in the If_Grammar.txt .

The rules present in the file are expanded in a Depth First Search Traversal (Preorder) kind of traversal as shown below:

<img align="center" alt="Coding" width="400" height="300" src="https://github.com/adi666-png/System-Software-Labs/blob/main/assets/traversal.gif">

Nodes names are arbitrarily named in the above illustration and in our case are the tokens present in GrammarFile.txt .

The main difference from Day 1's parser is that this uses a recursive approach and hence can supports as many if-else ladders as desired. 
