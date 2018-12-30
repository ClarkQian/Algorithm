class TreeNode:
    def __init__(self, key, val, left = None, right = None, parent = None):
        self.key = key
        self.payload = val
        self.leftChild = left
        self.rightChild = right
        self.parent = parent
        self.balanceFactor = 0

    def hasLeftChild(self):
        return self.leftChild


    def hasRightChild(self):
        return self.rightChild

    def isLeftChild(self):
        return self.parent and self.parent.leftChild == self

    def isRightChild(self):
        return self.parent and self.parent.rightChild == self

    def isRoot(self):
        return not self.parent

    def isLeaf(self):
        return not (self.rightChild or self.leftChild)

    def hasAnyChildren(self):
        return self.rightChild or self.leftChild

    def hasBothChildren(self):
        return self.rightChild and self.leftChild

    def replaceNodeData(self, key, value, lc, rc):
        self.key = key
        self.value = value
        self.leftChild = lc
        self.rightChild = rc
        if self.hasLeftChild():
            self.leftChild.parent = self
        if self.hasRightChild():
            self.rightChild.parent = self


    def findSuccessor(self):
        succ = self.rightChild
        while succ.hasLeftChild():
            succ = succ.leftChild
        return succ

    def findPredecessor(self):
        pred = self.leftChild
        while pred.hasRightChild():
            pred = pred .hasRightChild
        return pred




    #这个函数的效果是删除自身这个节点，用于辅助Hubbard Deletion。其实这就是下面的remove函数里的两种简单情况(leaf or has one child)，代码几乎相同。
    #is it necessary?
    def spliceOut(self):
        if self.isLeaf():#no child
            if self.isLeftChild():
                self.parent.leftChild = None
            else: #right child
                self.parent.rightChild = None

        elif self.hasAnyChildren():#have one child
            if self.hasLeftChild():
                if self.isLeftChild():
                    self.parent.leftChild = self.leftChild
                else:
                    self.parent.rightChild = self.leftChild
                self.leftChild.parent = self.parent
            else: # has only right child
                if self.isLeftChild():
                    self.parent.leftChild = self.leftChild
                else:
                    self.parent.rightChild = self.leftChild
                self.rightChild.parent = self.parent

    def findMin(self):
        current = self
        while current.hasLeftChild():
            current = current.leftChild
        return current

    #here is a useful using of iterator
    #combined with cursion
    def __iter__(self):
        if self:
            if self.hasLeftChild():
                for elem in self.leftChild:
                    yield elem
            yield self.key
            if self.hasRightChild():
                for elem in self.rightChild:
                    yield  elem
