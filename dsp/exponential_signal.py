import numpy as np
import matplotlib.pyplot as plt
import math


def exponential_signal(dataset):
    responses = []
    for data in dataset:
        responses.append(math.exp(data))
    return responses


dataset = np.arange(-1, 1, .1)
plt.stem(dataset, exponential_signal(dataset))
# plt.plot(dataset,exponential_signal(dataset))
plt.show()
