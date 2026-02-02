class QuickFindUF:

    def __init__(self, N):
        self.id = list(range(N))

    def connected(self, p, q):
        return self.id[p] == self.id[q]
    
    def union(self, p, q):
        pid = self.id[p]
        qid = self.id[q]
        for i in range(len(self.id)):
            if self.id[i] == pid:
                self.id[i] = qid
