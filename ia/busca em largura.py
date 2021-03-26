def create_array(*args, **kwargs):
    if(kwargs.get("i") == None):
        kwargs["i"] = 0
    if(kwargs.get("val") == None):
        kwargs["val"] = 0
    x = args[kwargs["i"]]
    if len(args) == kwargs["i"]+1:
        return [kwargs["val"] for y in range(x)]
    kwargs["i"] += 1
    return [create_array(*args,**kwargs) for y in range(x)]

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
        return self.l[-1]
n, e = input().split(' ')
n = int(n)
e = int(e)
adj = create_array(n, 0)
# print(adj)
visited = create_array(n, val = False)
for i in range(e):
    a ,b = input().split(' ')
    a = int(a)
    b = int(b)
    a -= 1
    b -= 1
    adj[a].append(b)
# print(adj)
x, y = input().split(' ')
x = int(x)
y = int(y)
x -= 1
y -= 1
fila = Fila()
fila.push(x)
visited[x] = True
while not fila.empty():
    v = fila.front()
    fila.pop()
    if v == y:
        print(v+1, end = "")
        break
    else:
        print(v+1, end = '-')
    for i in range(len(adj[v])):
        if not visited[adj[v][i]]:
            fila.push(adj[v][i])
            visited[adj[v][i]] = True
# print()