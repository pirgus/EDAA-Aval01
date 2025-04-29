import pandas as pd
import os

type = "o"
qtt = "100000"
filename = "soutput_" + type + qtt + ".txt"
with open(filename, 'r') as file:
    lines = file.readlines()

EOI_index = 10
EOSWC_index = 21
EOSRC_index = 1022
EOOWC_index = 1033
EOORC_index = 2034
EOBWC_index = 2045

lines_insertion = lines[:EOI_index]
lines_seqWC = lines[EOI_index+1:EOSWC_index]
lines_seqRC = lines[EOSWC_index+1:EOSRC_index]

with open('insertion_data.txt', 'w') as file:
    file.writelines(lines_insertion)

with open('seqWC_data.txt', 'w') as file:
    file.writelines(lines_seqWC)

with open('seqRC_data.txt', 'w') as file:
    file.writelines(lines_seqRC)

insertion_df = pd.read_csv('insertion_data.txt', sep = ' ', header=None, names=['time'])
seqWC_df = pd.read_csv('seqWC_data.txt', sep = ';', header=None, names=['time', 'ncomp'])
seqRC_df = pd.read_csv('seqRC_data.txt', sep = ';', header=None, names=['time', 'ncomp'])

print("Insertion")
print(insertion_df['time'].mean())
print(insertion_df['time'].std())
print('---------------------------------------------\n')


print("Sequential Worst Case - Time")
print(seqWC_df['time'].mean())
print(seqWC_df['time'].std())
print("Sequential Worst Case - Comparisons")
print(seqWC_df['ncomp'].mean())
print(seqWC_df['ncomp'].std())
print('---------------------------------------------\n')

print("Sequential Random Case - Time")
print(seqRC_df['time'].mean())
print(seqRC_df['time'].std())
print("Sequential Random Case - Comparisons")
print(seqRC_df['ncomp'].mean())
print(seqRC_df['ncomp'].std())
print('---------------------------------------------\n')


os.remove('insertion_data.txt')
os.remove('seqWC_data.txt')
os.remove('seqRC_data.txt')

if(type == "o"):
    lines_optWC = lines[EOSRC_index+1:EOOWC_index]
    lines_optRC = lines[EOOWC_index+1:EOORC_index]
    lines_binWC = lines[EOORC_index+1:EOBWC_index]
    lines_binRC = lines[EOBWC_index+1:]

    with open('optWC_data.txt', 'w') as file:
        file.writelines(lines_optWC)
    
    with open('optRC_data.txt', 'w') as file:
        file.writelines(lines_optRC)
    
    with open('binWC_data.txt', 'w') as file:
        file.writelines(lines_binWC)

    with open('binRC_data.txt', 'w') as file:
        file.writelines(lines_binRC)

    optWC_df = pd.read_csv('optWC_data.txt', sep = ';', header=None, names=['time', 'ncomp'])
    optRC_df = pd.read_csv('optRC_data.txt', sep = ';', header=None, names=['time', 'ncomp'])

    binWC_df = pd.read_csv('binWC_data.txt', sep = ';', header=None, names=['time', 'ncomp'])
    binRC_df = pd.read_csv('binRC_data.txt', sep = ';', header=None, names=['time', 'ncomp'])

    print("Optimized Worst Case - Time")
    print(optWC_df['time'].mean())
    print(optWC_df['time'].std())
    print("Optimized Worst Case - Comparisons")
    print(optWC_df['ncomp'].mean())
    print(optWC_df['ncomp'].std())
    print('---------------------------------------------\n')

    print("Optimized Random Case - Time")
    print(optRC_df['time'].mean())
    print(optRC_df['time'].std())
    print("Optimized Random Case - Comparisons")
    print(optRC_df['ncomp'].mean())
    print(optRC_df['ncomp'].std())
    print('---------------------------------------------\n')

    print("Binary Worst Case - Time")
    print(binWC_df['time'].mean())
    print(binWC_df['time'].std())
    print("Binary Worst Case - Comparisons")
    print(binWC_df['ncomp'].mean())
    print(binWC_df['ncomp'].std())
    print('---------------------------------------------\n')


    print("Binary Random Case - Time")
    print(binRC_df['time'].mean())
    print(binRC_df['time'].std())
    print("Binary Random Case - Comparisons")
    print(binRC_df['ncomp'].mean())
    print(binRC_df['ncomp'].std())

    os.remove('optWC_data.txt')
    os.remove('optRC_data.txt')
    os.remove('binWC_data.txt')
    os.remove('binRC_data.txt')



