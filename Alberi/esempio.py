'''

class Node:
    def __init__(self,data):
        self.left=Node
        self.right=Node
        self.data=data
    def insert(self,data): #confronta il valore del nodo da aggiungere con il nodo corrente
        if self.data:
            if data<self.data:
                if self.left is None:
                    self.left=Node(data)
                else:
                    self.left.insert(data)
            elif data>self.data:
                if self.right is None:
                    self.right=Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data=data
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()
root=Node(12)
root.insert(6)
root.insert(14)
root.insert(3)

root.PrintTree()

'''

class Node:
    def __init__(self,data):  #__init__ prende solo il data, il self solo nella definizione
        self.left = None
        self.right = None
        self.data = data 

    def insert(self,data):
    # conftonta il nodo da aggiungere con il nodo da aggiungere
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
             self.data = data
    #stampa albero
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()
    def FindByKey(self,data):
        if not self.data:
            return None
        else:
            if data<self.data:
                return self.left.FindByKey(data)
            elif data>self.data:
                return self.right.FindByKey(data)
            else:
                return self

#inserimento
root = Node(12)
root.insert(6)
root.insert(14)
root.insert(3)

root.PrintTree()
print(root.FindByKey(3).data)