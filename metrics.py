import numpy as np
import pandas as pd
import os

filename = "/media/pirgus/files/mestrado/edaa/trab_01/codes/output_o100000.txt"
with open(filename, 'r') as file:
    lines = file.readlines()

EOI_index = 10
EOWC_index = 21

lines_insertion = lines[:EOI_index]
lines_worstcase = lines[EOI_index+1:EOWC_index]
lines_randomcase = lines[EOWC_index+1:]

with open('insertion_data.txt', 'w') as file:
    file.writelines(lines_insertion)

with open('worstcase_data.txt', 'w') as file:
    file.writelines(lines_worstcase)

with open('randomcase_data.txt', 'w') as file:
    file.writelines(lines_randomcase)

insertion_df = pd.read_csv('insertion_data.txt', sep = ' ', header=None, names=['time'])
worstcase_df = pd.read_csv('worstcase_data.txt', sep = ';', header=None, names=['time', 'ncomp'])
randomcase_df = pd.read_csv('randomcase_data.txt', sep = ';', header=None, names=['time', 'ncomp'])

print("insertion metrics")
print(insertion_df['time'].mean())
print(insertion_df['time'].std())
print('----------------------------\n')

print("worst case metrics - time")
print(worstcase_df['time'].mean())
print(worstcase_df['time'].std())
print("worst case metrics - comparisons")
print(worstcase_df['ncomp'].mean())
print(worstcase_df['ncomp'].std())
print('----------------------------\n')

print("random case metrics - time")
print(randomcase_df['time'].mean())
print(randomcase_df['time'].std())
print("random case metrics - comparisons")
print(randomcase_df['ncomp'].mean())
print(randomcase_df['ncomp'].std())

os.remove('insertion_data.txt')
os.remove('worstcase_data.txt')
os.remove('randomcase_data.txt')

