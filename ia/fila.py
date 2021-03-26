class Fila:
    def __init__(self):
        self.l = []
        self.r = []
    def push(self, x):
        self.r.append(x)
    def size(self):
        return len(self.l) + len(self.r)
    def pop(self):
        if len(self.l) == 0:
            while len(self.r) > 0:
                self.l.append(self.r.pop())
        self.l.pop()
    def empty(self):
        return len(self.r) == 0 and len(self.l) == 0
    def front(self):
        if len(self.l) == 0:
            while len(self.r) > 0:
                self.l.append(self.r.pop())
        return self.l[len(self.l) - 1]