import numpy as np
import matplotlib.pyplot as plt
import math


def fourier_transform(signal):
    _len = len(signal)

    fourier_signal = [0]*_len
    for i in range(_len):
        sum = 0
        for j in range(_len):
            sum += signal[j] * \
                np.exp(-1j*2*np.pi*i*j/_len)
        sum /= _len
        fourier_signal[i] = sum
    return fourier_signal


def sinusoid1(x):
    return 2*np.sin(x)


def sinusoid2(x):
    return 2*np.sin(2*x)


def sinusoid3(x):
    return 3 * np.sin(5*x)


dataset = np.arange(0, 200, 1)

signal1 = sinusoid1(dataset)
signal2 = sinusoid2(dataset)
signal3 = sinusoid3(dataset)

signal_combined = signal1+signal2+signal3
fourier_signal = fourier_transform(signal_combined)

plt.plot(dataset, signal_combined, "-")
plt.plot(dataset, fourier_signal, "-")
plt.show()
