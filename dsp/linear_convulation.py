import numpy as np
import matplotlib.pyplot as plt


def sinusoid1(dataset):
    return 10*np.sin((2*np.pi/5)*dataset)


def sinusoid2(dataset):
    return 20*np.sin((2*np.pi/3)*dataset)


def convulation(signal1, signal2):
    len1 = len(signal1)
    len2 = len(signal2)
    conv_len = len1+len2-1
    signal1 = np.pad(signal1, (0, (conv_len-len1)), "constant")
    signal2 = np.pad(signal2, (0, (conv_len-len2)), "constant")

    convulated_signal = [0]*(len2+len1-1)

    for n in range(len1+len2-1):
        for k in range(len2+len1-1):
            if((n-k) >= 0):
                convulated_signal[n] += (signal1[k]*signal2[n-k])

    return (convulated_signal)


dataset = np.arange(-5, 5, 2)
signal1 = sinusoid1(dataset)
signal2 = sinusoid2(dataset)

len1 = len(signal1)
len2 = len(signal2)

total_len = len1+len2-1

dataset1 = np.arange(0, total_len, 1)

convulated_signal = convulation(signal1, signal2)

plt.plot(dataset1, convulated_signal)

print(convulated_signal)
plt.show()
