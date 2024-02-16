import math
import random

def hillClimbing(maxIt, g):
    x=random.randrange(256)
    print("x start:",x)
    t=1
    while(t<maxIt and evaluate(x)!=g):
        #print("t:",t)
        xEval=perturb(x)
        if evaluate(xEval)>evaluate(x):
            #print("go up from",x,"to",xEval)
            x=xEval
        t+=1
    if t<maxIt:
        print("Reached top!:",evaluate(x))
    else:
        print("Final stop:",evaluate(x))
    return x

def evaluate(x):
    return math.sin(math.pi*x/256)

def perturb(x):
    if x==0:
        x+=1
    elif x==255:
        x-=1
    else:
        if random.randrange(2)==0:
            x+=1
        else:
            x-=1
    return x

#Iterative Hill Climbing
def IHC(nStart, maxIt, g):
    best=random.randrange(256)
    t1=1
    while t1<nStart and best!=g:
        x=hillClimbing(maxIt, g)
        t1+=1
        if x>best:
            best=x
    print("Best:",best)
    return best

IHC(25, 257, 1)
#hillClimbing(257, 1)