import numpy as np
import matplotlib.pyplot as plt


def maze(shape=(64,64), complexity=.95, density = 1):
    # Only odd shapes
    shape = ((shape[0]//2)*2+1, (shape[1]//2)*2+1)
    # Adjust complexity and density relative to maze size
    complexity = int(complexity*(5*(shape[0]+shape[1])))
    density    = int(density*(shape[0]//2*shape[1]//2))
    # Build actual maze
    Z = np.zeros(shape, dtype=float)
    # Fill borders
    Z[0,:] = Z[-1,:] = 1
    Z[:,0] = Z[:,-1] = 1
    # Make isles
    for i in xrange(density):
        x = shape[1]*(.5-min(max(np.random.normal(0,.5),-.5),.5))
        y = shape[0]*(.5-min(max(np.random.normal(0,.5),-.5),.5))
        x, y = (x//2)*2, (y//2)*2
        #x, y = rnd(0,shape[1]//2)*2, rnd(0,shape[0]//2)*2
        Z[y,x] = 1
        for j in xrange(complexity):
            neighbours = []
            if x > 1:           neighbours.append( (y,x-2) )
            if x < shape[1]-2:  neighbours.append( (y,x+2) )
            if y > 1:           neighbours.append( (y-2,x) )
            if y < shape[0]-2:  neighbours.append( (y+2,x) )
            if len(neighbours):
                y_,x_ = neighbours[np.random.random_integers(0,len(neighbours)-1)]
                if Z[y_,x_] == 0:
                    Z[y_,x_] = 1
                    Z[y_+(y-y_)//2, x_+(x-x_)//2] = 1
                    x, y = x_, y_
    Z[ 0, 1] = 0 # Entrance
    Z[-2,-1] = 0 # Exit
    return Z

n = 51
Z = 1-maze((n,2*n))
Z[-2,-1] = 1
np.save("maze.npy",Z)

# Display Value
plt.figure(figsize=(2*9,9))
plt.subplot(111,frameon=False)
plt.imshow(Z, interpolation='nearest', cmap=plt.cm.hot, vmin=0, vmax=1)
plt.xticks([]), plt.yticks([])

plt.show()
