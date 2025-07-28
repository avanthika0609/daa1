import random

def generate_input_file(filename, n):
    with open(filename, 'w') as f:
        for _ in range(n):
            f.write(f"{random.randint(1, 1000)}\n")

sizes = {
    "input_1000.txt": 1000,
    "input_5000.txt": 5000,
    "input_10000.txt": 10000,
    "input_50000.txt": 50000
}

for filename, n in sizes.items():
    generate_input_file(filename, n)
    print(f"Generated {filename} with {n} book sizes.")
