from numpy.lib.function_base import append
import matplotlib.pyplot as plt
import numpy as np


def impulse_signal(shift, dataset):
    print(dataset)
    impulse = []

    for x in dataset:
        if(x == (-1*shift)):
            impulse.append(1)
        else:
            impulse.append(0)
    return impulse


dataset = np.arange(-10, 10, 1)
impulse = impulse_signal(0, dataset)

# print(impulse);
plt.stem(dataset, impulse)
