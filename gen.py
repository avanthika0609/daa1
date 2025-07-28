import random
import string

def random_name(length=6):
    return ''.join(random.choices(string.ascii_letters, k=length))

def random_department():
    return random.choice(['HR', 'IT', 'Finance', 'Marketing', 'Sales', 'Admin'])

def generate_employees(n):
    employees = []
    for i in range(1, n + 1):
        name = random_name()
        dept = random_department()
        salary = round(random.uniform(30000, 100000), 2)
        employees.append((i, name, dept, salary))
    return employees

def write_file(filename, employees):
    with open(filename, 'w') as f:
        for emp in employees:
            f.write(f"{emp[0]} {emp[1]} {emp[2]} {emp[3]}\n")

def generate_files(sizes):
    for size in sizes:
        ascending = generate_employees(size)
        descending = list(reversed(ascending))
        random.shuffle(ascending)
        write_file(f"ascending_employees_{size}.txt", sorted(ascending))
        write_file(f"descending_employees_{size}.txt", descending)
        write_file(f"random_employees_{size}.txt", ascending)

generate_files([5000, 10000, 20000])
