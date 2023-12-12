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


def run_exe_and_save_output_for_chart():
    for parameter in data:
        csv_file_path = f'chart/{parameter[0]}_{parameter[2]}.csv'
        command = [exe_path, parameter[0], parameter[1], parameter[2]]
        result = subprocess.run(command, capture_output=True, text=True)
        print(result)
        output = result.stdout.strip()
        row = f"{output},{parameter[1]}\n"
        with open(csv_file_path, 'a+', newline='') as file:
            file.write(row)


exe_path = R'cmake-build-release/meta-heuristic-algorithms.exe'

# data = [
#     ('ftv55.xml', '60', 'Swap'),
#     ('ftv55.xml', '120', 'Swap'),
#     ('ftv55.xml', '180', 'Swap'),
#     ('ftv55.xml', '240', 'Swap'),
#     ('ftv55.xml', '300', 'Swap'),
#     ('ftv55.xml', '360', 'Swap'),
#     ('ftv55.xml', '60', 'Insert'),
#     ('ftv55.xml', '120', 'Insert'),
#     ('ftv55.xml', '180', 'Insert'),
#     ('ftv55.xml', '240', 'Insert'),
#     ('ftv55.xml', '300', 'Insert'),
#     ('ftv55.xml', '360', 'Insert'),
#     ('ftv55.xml', '60', 'Invert'),
#     ('ftv55.xml', '120', 'Invert'),
#     ('ftv55.xml', '180', 'Invert'),
#     ('ftv55.xml', '240', 'Invert'),
#     ('ftv55.xml', '300', 'Invert'),
#     ('ftv55.xml', '360', 'Invert'),
#     ('ftv170.xml', '60', 'Swap'),
#     ('ftv170.xml', '120', 'Swap'),
#     ('ftv170.xml', '180', 'Swap'),
#     ('ftv170.xml', '240', 'Swap'),
#     ('ftv170.xml', '300', 'Swap'),
#     ('ftv170.xml', '360', 'Swap'),
#     ('ftv170.xml', '60', 'Insert'),
#     ('ftv170.xml', '120', 'Insert'),
#     ('ftv170.xml', '180', 'Insert'),
#     ('ftv170.xml', '240', 'Insert'),
#     ('ftv170.xml', '300', 'Insert'),
#     ('ftv170.xml', '360', 'Insert'),
#     ('ftv170.xml', '60', 'Invert'),
#     ('ftv170.xml', '120', 'Invert'),
#     ('ftv170.xml', '180', 'Invert'),
#     ('ftv170.xml', '240', 'Invert'),
#     ('ftv170.xml', '300', 'Invert'),
#     ('ftv170.xml', '360', 'Invert'),
#     ('rbg358.xml', '60', 'Swap'),
#     ('rbg358.xml', '120', 'Swap'),
#     ('rbg358.xml', '180', 'Swap'),
#     ('rbg358.xml', '240', 'Swap'),
#     ('rbg358.xml', '300', 'Swap'),
#     ('rbg358.xml', '360', 'Swap'),
#     ('rbg358.xml', '60', 'Insert'),
#     ('rbg358.xml', '120', 'Insert'),
#     ('rbg358.xml', '180', 'Insert'),
#     ('rbg358.xml', '240', 'Insert'),
#     ('rbg358.xml', '300', 'Insert'),
#     ('rbg358.xml', '360', 'Insert'),
#     ('rbg358.xml', '60', 'Invert'),
#     ('rbg358.xml', '120', 'Invert'),
#     ('rbg358.xml', '180', 'Invert'),
#     ('rbg358.xml', '240', 'Invert'),
#     ('rbg358.xml', '300', 'Invert'),
#     ('rbg358.xml', '360', 'Invert'),
# ]

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
    ('ftv55.xml', '60', '0.6'),
    ('ftv55.xml', '120', '0.6'),
    ('ftv55.xml', '180', '0.6'),
    ('ftv55.xml', '240', '0.6'),
    ('ftv55.xml', '300', '0.6'),
    ('ftv55.xml', '360', '0.6'),
    ('ftv170.xml',  '60', '0.6'),
    ('ftv170.xml',  '120', '0.6'),
    ('ftv170.xml',  '180', '0.6'),
    ('ftv170.xml',  '240', '0.6'),
    ('ftv170.xml',  '300', '0.6'),
    ('ftv170.xml',  '360', '0.6'),
    # ('rbg358.xml', '60', '0.8'),
    # ('rbg358.xml', '120', '0.8'),
    # ('rbg358.xml', '180', '0.8'),
    # ('rbg358.xml', '240', '0.8'),
    # ('rbg358.xml', '300', '0.8'),
    # ('rbg358.xml', '360', '0.8'),
]

run_exe_and_save_output_for_chart()
