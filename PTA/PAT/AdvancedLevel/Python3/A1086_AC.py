import sys

_ = input()
preorder_nodes = []
inorder_nodes = []
stk = []
for instruction in sys.stdin:
    if instruction.startswith('Push'):
        node_i = int(instruction.split()[1])
        preorder_nodes.append(node_i)
        stk.append(node_i)
    else:
        inorder_nodes.append(stk.pop())

postorder_nodes = []


def pre_in_to_post(i, j, root_i):
    if i <= j:
        index = i
        while preorder_nodes[root_i] != inorder_nodes[index]:
            index += 1
        pre_in_to_post(i, index-1, root_i+1)
        pre_in_to_post(index+1, j, root_i+1 + index-i)
        postorder_nodes.append(inorder_nodes[index])


pre_in_to_post(0, len(inorder_nodes)-1, 0)

print(postorder_nodes[0], end='')
for node in postorder_nodes[1:]:
    print('', node, end='')

