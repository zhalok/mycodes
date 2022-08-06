import numpy as np
import matplotlib.pyplot as plt

dataset = np.arange(-10, 10, .1)
response = np.sin(dataset)
plt.stem(dataset, response)
