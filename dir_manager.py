import os, zipfile

lab_num = input()
task_count = int(input())
os.mkdir(lab_num)

for i in range(1, task_count+1):
    os.makedirs(f"{lab_num}/{i}")
    os.makedirs(f"{lab_num}/{i}/tests")
    with open(f"{lab_num}/{i}/answer.c", "w") as f:
        f.write("")
    with open(f"{lab_num}/{i}/answer.cpp", "w") as f:
        f.write("")
    with zipfile.ZipFile(f"{lab_num}{i}.zip", 'r') as zip_file:
        zip_file.extractall(f"{lab_num}/{i}/tests")

