import subprocess
import csv


class Algorithm:
    def __init__(self, name, arg1, arg2):
        self.name = name
        self.arg1 = arg1
        self.arg2 = arg2


def run_exe_and_save_output():
    for parameter in data:
        csv_file_path = f'csv/{parameter[0]}_{parameter[1]}_{parameter[2]}.csv'
        for i in range(1, 10):
            command = [exe_path, parameter[0], parameter[1], parameter[2]]
            result = subprocess.run(command, capture_output=True, text=True)
            print(result)
            output = result.stdout.strip()
            row = f"{i},{output}\n"
            with open(csv_file_path, 'a+', newline='') as file:
                file.write(row)


exe_path = R'cmake-build-release/meta-heuristic-algorithms.exe'

# data = [
    # (R'ftv55.atsp', '120', 'swap'),
    # ('ftv55.xml', '120', 'Insert'),
    # ('ftv55.xml', '120', 'Invert'),
    # ('ftv170.xml', '240', 'swap'),
    # ('ftv170.xml', '240', 'Insert'),
    # ('ftv170.xml', '240', 'Invert'),
    # ('rbg358.xml', '360', 'Swap'),
    # ('rbg358.xml', '360', 'Insert'),
    # ('rbg358.xml', '360', 'Invert'),
# ]

data = [
    # ('ftv55.xml', '120', '0.4'),
    # ('ftv55.xml', '120', '0.6'),
    # ('ftv55.xml', '120', '0.8'),
    ('ftv170.xml', '240', '0.4'),
    ('ftv170.xml', '240', '0.6'),
    ('ftv170.xml', '240', '0.8'),
    ('rbg358.xml', '360', '0.4'),
    ('rbg358.xml', '360', '0.6'),
    ('rbg358.xml', '360', '0.8'),
]
run_exe_and_save_output()
