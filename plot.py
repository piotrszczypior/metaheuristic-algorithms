import sys
import os
import pandas as pd
import matplotlib.pyplot as plt
import csv

plt.style.use('seaborn-v0_8-whitegrid')
def plot(file: str, directory=''):
    file_path = (file if directory == '' else f'{directory}/{file}')

    df = pd.read_csv(file_path, header=None, names=['time', 'error'], delimiter=',')
    label = file.replace('_', ' ')
    # bars1 = ax.bar(df['num_elements'], y_values_bar1, width=0.4, color='#3d85c6', alpha=0.7, label='Bar 1 (Percentage)')


    # label = f'{labels[0]} algorithm, {labels[1]} graph implementation, density: {labels[2].removesuffix(".csv")}'
    plt.plot(df['time'], df['error'], marker='.', markersize=7, markerfacecolor='#000000',
             markeredgecolor='#000000', label=f'SA with a = 0.6')
    plt.title(f'SA for ftv55.xml file')
    # plt.ylim([0, 25.0])
    # plt.xlim([60, 400])
    plt.legend()
    plt.xticks([60, 120, 180, 240, 300, 360])
    plt.ylabel('Relative error [%]')
    plt.xlabel('Time [s]')
    fig = plt.gcf()
    plt.show()
    if not os.path.exists('img'):
        os.mkdir('img')
    fig.savefig(f'img/{file.removesuffix(".csv")}.png', )



plot("plot.csv")
