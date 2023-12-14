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


def plot_multiline(file: str):
    data = pd.read_csv(file, sep=',', header=None, names=['time', 'error1', 'error2', 'error3'])
    plt.figure(figsize=(12, 6))

    plt.plot(data['time'], data['error1'], label='TS with swap neighbour', marker='.', markersize=7)
    plt.plot(data['time'], data['error2'], label='TS with insert neighbour', marker='.', markersize=7)
    plt.plot(data['time'], data['error3'], label='TS with inverse neighbour', marker='.', markersize=7)

    plt.title('Comparison rbg358.xml file')
    plt.legend()
    plt.ylabel('Relative error [%]')
    plt.xlabel('Time [s]')

    # Set a subset of ticks for better readability
    # plt.xticks(rotation='vertical')
    plt.xticks([60, 120, 180, 240, 300, 360])

    # plt.yscale('log')
    fig = plt.gcf()
    plt.show()

    if not os.path.exists('img'):
        os.mkdir('img')

    fig.savefig(f'img/{file.removesuffix(".csv")}.png', bbox_inches='tight')


# plot_multiline("tabu_rbg358.csv")


path_as_str: str = "0-239-69-39-21-305-40-4-44-91-10-27-16-17-13-3-164-218-321-260-55-34-9-35-18-329-64-36-29-337-137-37-28-24-41-205-180-47-311-79-45-25-12-48-11-246-81-6-15-284-56-23-185-209-49-5-104-97-208-63-19-286-22-58-243-51-67-95-52-171-53-59-125-236-357-277-302-238-204-220-250-113-317-221-199-54-100-157-71-314-222-148-229-309-325-350-258-225-294-298-344-291-227-315-223-339-276-295-94-235-330-261-242-306-336-268-234-244-211-323-351-304-228-327-248-187-354-273-256-318-272-233-78-353-313-231-114-264-341-62-237-355-60-345-289-254-160-105-66-14-232-249-118-146-68-297-99-70-26-112-103-72-172-255-320-183-184-214-76-196-77-42-198-80-106-181-328-61-86-165-292-88-123-89-192-269-283-347-83-92-275-191-182-207-93-32-31-117-135-1-87-288-119-267-75-212-333-166-122-303-200-126-202-102-210-265-226-127-131-352-116-128-293-252-335-147-162-133-143-163-2-247-266-151-349-141-167-8-115-169-348-170-174-145-326-334-240-46-296-195-175-307-300-177-150-216-178-176-312-299-179-173-356-331-186-346-259-206-230-7-188-262-332-190-73-280-194-74-270-301-340-281-324-279-338-213-203-278-251-217-201-219-322-343-287-129-57-130-111-101-132-20-316-224-134-82-253-136-85-84-33-108-290-138-38-139-271-310-140-110-197-142-109-96-144-107-193-153-65-168-154-124-43-215-308-50-319-257-155-98-156-30-158-149-241-189-342-285-263-282-274-159-121-120-161-152-245-90-0"
splitted_string = path_as_str.split('-')
cleaned = [item for item in splitted_string if item.strip()]
file_path = "files/ts_rbg358.txt"


with open(file_path, 'w+', newline='') as file:
    file.write(str(len(cleaned)) + '\n')
    for city in cleaned:
        file.write(city + '\n')

