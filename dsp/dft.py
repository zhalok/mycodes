import numpy as np
import matplotlib.pyplot as plt


def sinusoid(x):
    return 2*np.sin(3*x)


def sinusoid1(x):
    return 3*np.sin(4*x)


def dft(signal):
    _len = len(signal)
    _dft = [0]*_len
    for k in range(_len):
        for n in range(_len):
            _dft[k] += singal[n]*np.exp(-1j*2*np.pi*k*n/_len)
    return _dft


inputs = np.arange(0, 100, 1)
signal = sinusoid(inputs)
_dft = dft((signal))
plt.plot(inputs, _dft)
plt.show()
