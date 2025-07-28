import random

def generate_input_file(filename, n):
    with open(filename, 'w') as f:
        for _ in range(n):
            f.write(f"{random.randint(1, 1000)}\n")  
sizes = {
    "pages_1000.txt": 1000,
    "pages_5000.txt": 5000,
    "pages_10000.txt": 10000,
    "pages_50000.txt": 50000
}

for filename, count in sizes.items():
    generate_input_file(filename, count)
    print(f"Generated {filename} with {count} page counts.")
