**Note**
This just simple impelementation of Data Structures and Algorithms for educational perposes

## Trees
- Binary Trees 
- Binary Search trees
- AVL 
- Tire

Height = Edges from any Node to the last Leaf ⬇️ <br>
Depth = Edges from any Node up to the Root ⬆️ <br>

### Traversing on Tree 
- Inorder = LVR
- Postorder = LRV
- Preorder = VLR 
### Notes
- Most tasks follow one of these traversal strategies
- Find the minimum value of a tree
- Find the height of a tree
- Count how many leaf or non-leaf nodes
- In all of them you need to follow some style. Go preorder: VLR
-  Proper basecase handling
- Compute something based current->data
- Compute the left subtree recursively
- Compute the right subtree recursively
- Compute the overall of these 3 values
- For some tasks, we might easily compute inorder traversal and check
- Save the traversal in an array
- Do the operation if applicable 
- Tree sum, min, max, if a value exists, if the tree has duplicate values
- But the downside, we have to traverse the whole tree. E.g. not efficient for value searching
