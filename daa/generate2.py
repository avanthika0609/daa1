import random

def generate_input_file(filename, n):
    with open(filename, 'w') as f:
        for _ in range(n):
            height = random.randint(100, 200)  # Simulating student height in cm
            f.write(f"{height}\n")

# File sizes to generate
sizes = {
    "heights_1000.txt": 1000,
    "heights_5000.txt": 5000,
    "heights_10000.txt": 10000,
    "heights_50000.txt": 50000
}

for filename, count in sizes.items():
    generate_input_file(filename, count)
    print(f"Generated {filename} with {count} heights.")
