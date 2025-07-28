import matplotlib.pyplot as plt

sizes = [5000, 10000, 20000]

ascending_times = {
    "Selection Sort": [42, 94, 369],
    "Insertion Sort": [0, 0, 0],
    "Merge Sort": [3, 6, 14],
    "Quick Sort": [0, 0, 0]  # Replace with real data
}

descending_times = {
    "Selection Sort": [26, 102, 406],
    "Insertion Sort": [66, 265, 1067],
    "Merge Sort": [3, 7, 16],
    "Quick Sort": [0, 0, 0]  # Replace with real data
}

random_times = {
    "Selection Sort": [24, 95, 391],
    "Insertion Sort": [32, 131, 529],
    "Merge Sort": [3, 7, 18],
    "Quick Sort": [0, 0, 0]  # Replace with real data
}

def plot_case(times, title, filename):
    plt.figure()
    for algo, t in times.items():
        plt.plot(sizes, t, marker='o', label=algo)

    plt.title(title)
    plt.xlabel("Number of Employees")
    plt.ylabel("Time Taken (ms)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(filename)
    plt.close()

# Save each plot as a PNG
plot_case(ascending_times, "Best Case: Ascending Employee IDs", "ascending_plot.png")
plot_case(descending_times, "Worst Case: Descending Employee IDs", "descending_plot.png")
plot_case(random_times, "Average Case: Random Employee IDs", "random_plot.png")
