import numpy as np
import matplotlib.pyplot as plt


def sinusoid1(dataset):
    return 10*np.sin((2*np.pi/5)*dataset)


def sinusoid2(dataset):
    return 20*np.sin((2*np.pi/3)*dataset)


def cross_correlation(signal1, signal2):
    len1 = len(signal1)
    len2 = len(signal2)
    N = len1+len2-1
    signal1 = np.pad(signal1, (0, N-len1), 'constant')
    signal2 = np.pad(signal2, (0, N-len2), 'constant')
    cross_correlation_signal = [0]*N
    for l in range(N):
        for n in range(N):
            if(n >= l):
                cross_correlation_signal[l] += signal1[n]*signal2[n-l]
    return cross_correlation_signal


dataset = np.arange(0, 10, 1)

signal1 = sinusoid1(dataset)
signal2 = sinusoid2(dataset)


cross_correlation_signal = cross_correlation(signal1, signal1)
print(cross_correlation_signal)
