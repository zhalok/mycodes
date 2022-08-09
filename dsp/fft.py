import numpy as np
import math
import matplotlib.pyplot as plt


def fft(x):
    n = len(x)
    if len(x) == 1:
        return x

    w = np.exp(-1j*2*np.pi/n)
    even_list = []
    odd_list = []
    for i in range(math.floor(n/2)):
        even_list.append(x[i*2])
        odd_list.append(x[2*i+1])

    _even_list, _odd_list = fft(even_list), fft(odd_list)
    y = np.zeros(n, dtype=np.complex)
    for i in range(math.floor(n/2)):
        y[i] = _even_list[i] + np.power(w, i) * _odd_list[i]
        y[i+math.floor(n/2)] = _even_list[i] - np.power(w, i) * _odd_list[i]

    return y


signal = [1, 2, 4, 8, 16, 32, 64, 128]
fft_response = fft(signal)

plt.plot(signal, fft_response, linestyle="dashed")
plt.plot(signal, np.fft.fft(signal))
plt.show()
print(fft_response)
