import numpy as np
import matplotlib.pyplot as plt

# Load maze (see maze.py)
Z = np.load("maze.npy")
target = Z.shape[1]-1,Z.shape[0]-2

# Value iteration
gamma = 0.99
P = np.zeros(Z.shape)
P[-2,-1] = 1
for i in range(250):
    P_ = P.copy()
    for y in xrange(1,Z.shape[0]-1):
         for x in xrange(1,Z.shape[1]-1):
             a = max(P[y,x-1], P[y,x+1])
             b = max(P[y+1,x], P[y-1,x])
             c = gamma*max(a,b)
             P_[y,x] = Z[y,x]*max(c,P[y,x])
    P = P_

# Display Value
plt.figure(figsize=(2*9,9))
plt.subplot(111,frameon=False)
plt.imshow(P, interpolation='nearest', cmap=plt.cm.hot, vmin=0, vmax=1)
plt.xticks([]), plt.yticks([])

# Path finding by descending gradient
y,x = 0, 1
X,Y = [],[]
dirs = [(0,-1), (0,+1), (-1,0), (+1,0)]
for i in range(1000):
    Y.append(y), X.append(x)
    neighbours = -np.ones(4)
    if x > 0:            neighbours[0] = P[y,x-1]
    if x < P.shape[1]-1: neighbours[1] = P[y,x+1]
    if y > 0:            neighbours[2] = P[y-1,x]
    if y < P.shape[0]-1: neighbours[3] = P[y+1,x]
    a = np.argmax(neighbours)
    x,y  = x + dirs[a][1], y + dirs[a][0]
    if (x,y) == target:
        break

plt.scatter(X, Y, s=20, lw=.5, color='k', marker='o',
            alpha=1.0, edgecolors='k', facecolors='w')
plt.axis( [-0.5,P.shape[1]-0.5, -0.5, P.shape[0]-0.5] )
# plt.title('Maze path finding using value iteration', fontsize=20)

plt.savefig("path-finding.png",dpi=50)

plt.show()
