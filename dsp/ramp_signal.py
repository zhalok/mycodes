def ramp_signal(dataset):
    response = []
    for data in dataset:
        response.append(data)
    return response


dataset = np.arange(-10, 10, 1)
plt.stem(dataset, ramp_signal(dataset))
