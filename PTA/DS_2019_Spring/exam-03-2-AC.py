from collections import namedtuple, deque

NULL = -1

Node = namedtuple('Node', ['data', 'li', 'ri'])

n = int(input())

nodes = []
used_nodes = [False for _ in range(n)]
for i, _ in enumerate(range(n)):
    l, r = map(int, input().replace('-', str(NULL)).split())
    nodes.append(Node(i, l, r))
    if l != -1:
        used_nodes[l] = True
    if r != -1:
        used_nodes[r] = True

root = NULL
for i, used in enumerate(used_nodes):
    if not used:
        root = i
        break

result = []
q = deque([nodes[root]])
while len(q) != 0:
    node = q.popleft()
    if node.li == node.ri and node.li == NULL:
        result.append(node.data)
    if node.li != NULL:
        q.append(nodes[node.li])
    if node.ri != NULL:
        q.append(nodes[node.ri])

print(result[0], end='')
for node in result[1:]:
    print('', node, end='')
