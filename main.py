import subprocess
import csv


class Algorithm:
    def __init__(self, name, arg1, arg2):
        self.name = name
        self.arg1 = arg1
        self.arg2 = arg2


def run_exe_and_save_output():
    for parameter in data:
        command = [exe_path, parameter[1], parameter[2]]
        result = subprocess.run(command, capture_output=True, text=True)
        print(result)
        output = result.stdout.strip()
        row = f"{parameter[1]},{parameter[2]},{output}\n"
        with open(csv_file_path, 'a+', newline='') as file:
            file.write(row)


exe_path = R'C:\Users\Zosia\Desktop\metaheuristic-algorithms\cmake-build-debug\meta-heuristic-algorithms.exe'

data = [
    ("SimulatedAnnealing", "0.99", "100"),
    ("SimulatedAnnealing", "0.99", "90"),
    ("SimulatedAnnealing", "0.99", "80"),
    ("SimulatedAnnealing", "0.99", "70"),
    ("SimulatedAnnealing", "0.99", "60"),
    ("SimulatedAnnealing", "0.99", "50"),
    ("SimulatedAnnealing", "0.99", "40"),
    ("SimulatedAnnealing", "0.99", "30"),
    ("SimulatedAnnealing", "0.99", "20"),
    ("SimulatedAnnealing", "0.99", "10"),
    ("SimulatedAnnealing", "0.89", "100"),
    ("SimulatedAnnealing", "0.89", "90"),
    ("SimulatedAnnealing", "0.89", "80"),
    ("SimulatedAnnealing", "0.89", "70"),
    ("SimulatedAnnealing", "0.89", "60"),
    ("SimulatedAnnealing", "0.89", "50"),
    ("SimulatedAnnealing", "0.89", "40"),
    ("SimulatedAnnealing", "0.89", "30"),
    ("SimulatedAnnealing", "0.89", "20"),
    ("SimulatedAnnealing", "0.89", "10"),
    ("SimulatedAnnealing", "0.79", "100"),
    ("SimulatedAnnealing", "0.79", "90"),
    ("SimulatedAnnealing", "0.79", "80"),
    ("SimulatedAnnealing", "0.79", "70"),
    ("SimulatedAnnealing", "0.79", "60"),
    ("SimulatedAnnealing", "0.79", "50"),
    ("SimulatedAnnealing", "0.79", "40"),
    ("SimulatedAnnealing", "0.79", "30"),
    ("SimulatedAnnealing", "0.79", "20"),
    ("SimulatedAnnealing", "0.79", "10"),
    ("SimulatedAnnealing", "0.69", "100"),
    ("SimulatedAnnealing", "0.69", "90"),
    ("SimulatedAnnealing", "0.69", "80"),
    ("SimulatedAnnealing", "0.69", "70"),
    ("SimulatedAnnealing", "0.69", "60"),
    ("SimulatedAnnealing", "0.69", "50"),
    ("SimulatedAnnealing", "0.69", "40"),
    ("SimulatedAnnealing", "0.69", "30"),
    ("SimulatedAnnealing", "0.69", "20"),
    ("SimulatedAnnealing", "0.69", "10"),
    ("SimulatedAnnealing", "0.59", "100"),
    ("SimulatedAnnealing", "0.59", "90"),
    ("SimulatedAnnealing", "0.59", "80"),
    ("SimulatedAnnealing", "0.59", "70"),
    ("SimulatedAnnealing", "0.59", "60"),
    ("SimulatedAnnealing", "0.59", "50"),
    ("SimulatedAnnealing", "0.59", "40"),
    ("SimulatedAnnealing", "0.59", "30"),
    ("SimulatedAnnealing", "0.59", "20"),
    ("SimulatedAnnealing", "0.59", "10"),
    ("SimulatedAnnealing", "0.49", "100"),
    ("SimulatedAnnealing", "0.49", "90"),
    ("SimulatedAnnealing", "0.49", "80"),
    ("SimulatedAnnealing", "0.49", "70"),
    ("SimulatedAnnealing", "0.49", "60"),
    ("SimulatedAnnealing", "0.49", "50"),
    ("SimulatedAnnealing", "0.49", "40"),
    ("SimulatedAnnealing", "0.49", "30"),
    ("SimulatedAnnealing", "0.49", "20"),
    ("SimulatedAnnealing", "0.49", "10"),
    ("SimulatedAnnealing", "0.39", "100"),
    ("SimulatedAnnealing", "0.39", "90"),
    ("SimulatedAnnealing", "0.39", "80"),
    ("SimulatedAnnealing", "0.39", "70"),
    ("SimulatedAnnealing", "0.39", "60"),
    ("SimulatedAnnealing", "0.39", "50"),
    ("SimulatedAnnealing", "0.39", "40"),
    ("SimulatedAnnealing", "0.39", "30"),
    ("SimulatedAnnealing", "0.39", "20"),
    ("SimulatedAnnealing", "0.39", "10"),
    ("SimulatedAnnealing", "0.29", "100"),
    ("SimulatedAnnealing", "0.29", "90"),
    ("SimulatedAnnealing", "0.29", "80"),
    ("SimulatedAnnealing", "0.29", "70"),
    ("SimulatedAnnealing", "0.29", "60"),
    ("SimulatedAnnealing", "0.29", "50"),
    ("SimulatedAnnealing", "0.29", "40"),
    ("SimulatedAnnealing", "0.29", "30"),
    ("SimulatedAnnealing", "0.29", "20"),
    ("SimulatedAnnealing", "0.29", "10"),
    ("SimulatedAnnealing", "0.19", "100"),
    ("SimulatedAnnealing", "0.19", "90"),
    ("SimulatedAnnealing", "0.19", "80"),
    ("SimulatedAnnealing", "0.19", "70"),
    ("SimulatedAnnealing", "0.19", "60"),
    ("SimulatedAnnealing", "0.19", "50"),
    ("SimulatedAnnealing", "0.19", "40"),
    ("SimulatedAnnealing", "0.19", "30"),
    ("SimulatedAnnealing", "0.19", "20"),
    ("SimulatedAnnealing", "0.19", "10"),
]

csv_file_path = 'SA_rbg358.csv'

run_exe_and_save_output()
