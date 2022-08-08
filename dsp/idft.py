import numpy as np
import matplotlib.pyplot as plt
import scipy as sc


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


def idft(signal):
    _len = len(signal)
    _idft = [0]*_len
    for n in range(_len):
        for k in range(_len):
            _idft[n] += singal[k]*np.exp(1j*2*np.pi*k*n/_len)
        _idft[n] /= _len
    return _idft


inputs = np.arange(0, 100, 1)
signal = sinusoid(inputs)
_dft = dft((signal))
_idft = idft(_dft)

plt.plot(inputs, _dft)
plt.plot(inputs, _idft)

lib_dft = sc.fft.fft(signal)
lib_idft = sc.fft.ifft(lib_dft)

plt.plot(inputs, lib_dft)
plt.plot(inputs, lib_idft)

plt.show()
