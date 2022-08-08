import numpy as np
import matplotlib.pyplot as plt


def unit_impulse(x):
    signal = []
    for i in x:
        if(i < 0):
            signal.append(0)
        else:
            signal.append(1)

    return signal


x = np.arange(-10, 10, .1)
y = unit_impulse(x)
plt.plot(x, y)
plt.show()
