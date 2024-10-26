class QuickUnionUF:
    def __init__(self, N):
        self.id = list(range(N))

    def root(self, i):
        while i != self.id[i]:
            i = self.id[i]
        return i
    
    def connected(self, p, q):
        return self.id[p] == self.id[q]
    
    def union(self, p, q):
        i = self.root(p)
        j = self.root(q)
        id[i] = j