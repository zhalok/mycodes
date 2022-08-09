# your code goes here
# radix 2
import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import time


def fft2(x):
    '''Compute the DFT of an input x of N = 2**k samples'''

    N = len(x)
    if N == 1:
        return x
    else:
        # Recursively compute the even and odd DFTs
        X_even = fft2(x[0::2])  # Start at 0 with steps of 2
        X_odd = fft2(x[1::2])  # Start at 1 with steps of 2

        # Allocate the output array
        X = np.zeros(N, dtype=np.complex)

        # Combine the even and odd parts
        for m in range(N//2):
            # Find the alias of frequency m in the smaller DFTs
            # m_alias = m % (N//2)
            # X[m] = X_even[m_alias] + \
            #     np.exp(-2j * np.pi * m / N) * X_odd[m_alias]
            X[m] = X_even[m] + np.exp(-2j * np.pi * m / N) * X_odd[m]
            X[m+(N//2)] = X_even[m] - np.exp(-2j * np.pi * m / N)*X_odd[m]
    return X


x = [1, 2, 4, 8, 16, 32, 64, 128]
_x = np.arange(0, len(x), 1)

fft_ = fft2(x)
fft__ = np.fft.fft(x)

plt.plot(_x, fft_)
plt.plot(_x, fft__)
plt.show()
