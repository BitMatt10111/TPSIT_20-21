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
    def printTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()
    def findByKey(self,key):
        if self is None or self.data == key:
            return self.data
        else:
            return "non esiste questa chiave"
        if key < self.data:
            return self.left.FindByKey(key)
        if key > self.data:
            return self.right.FindByKey(key)
    def inorderTraversal(self,root):
        res=[]
        if root:
            res=self.inorderTraversal(root.left)
            res.append(root.data)
            res=res + self.inorderTraversal(root.right)
        return res
    def preorderTraversal(self,root):
        res=[]
        if root:
            res.append(root.data)
            res=res + self.preorderTraversal(root.left)
            res=res + self.preorderTraversal(root.right)
        return res
    def postorderTraversal(self,root):
        res=[]
        if root:
            res=self.postorderTraversal(root.left)
            res=res + self.postorderTraversal(root.right)
            res.append(root.data)
        return res
    def sumKeys(self,root):
        som = 0
        r = self.inorderTraversal(root)
        for i in r:
            som += i
        return som
    def pariKeys(self,root):
        lista = self.inorderTraversal(root)
        listaP = []
        for k in lista:
            if k % 2 == 0:
                listaP.append(k)
        return listaP

#inserimento
rootKey=int(input())
root = Node(rootKey)
while True:
    ris=input("Inserire ancora? y/n: ")
    if ris=='y':
        value=int(input())
        root.insert(value)
    else:
        break
print(f"Somma delle chiavi: {root.sumKeys(root)}")
print(f"Chiavi pari: {root.pariKeys(root)}")