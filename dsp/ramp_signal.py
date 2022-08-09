import numpy as np
import matplotlib.pyplot as plt


def ramp_signal(dataset):
    response = []
    for data in dataset:
        if(data >= 0):
            response.append(data)
        else:
            response.append(0)
    return response


dataset = np.arange(-10, 10, 1)
plt.stem(dataset, ramp_signal(dataset))
plt.show()
