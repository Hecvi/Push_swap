import random
import subprocess
import matplotlib.pyplot as plt
import seaborn as sns
from itertools import permutations


def generate_random_integers(left, right, cnt):
    lst = random.sample(range(left, right + 1), cnt)
    return lst

def get_str(permut):
    res = " ".join(map(str, permut))
    return res

def checker_run(input_, arg):
    process = subprocess.Popen(["./checker", arg],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE)
    process.stdin.write(input_)
    res = process.communicate()[0]
    process.stdin.close()
    return res.decode().strip()

def full_check(length):
    lst = generate_random_integers(1, length, length)
    inputs = [get_str(p) for p in permutations(lst)]
    outputs = [subprocess.check_output(['./push_swap', i]) for i in inputs]
    pswap = [len(item.decode().split('\n')) - 1 if item else 0 for item in outputs]
    checker = [checker_run(output, input_) for input_, output in zip(inputs, outputs)]
    return (list(zip(inputs, pswap, checker)))

def run_check(i):
    if i < 15:
        return full_check(i)
    res = []
    for _ in range(100):
        lst = generate_random_integers(1, 10000, i)
        input_ = " ".join(map(str, lst))
        #print(input_) #печать входных чисел
        output = subprocess.check_output(['./push_swap', input_])
        pswap = len(output.decode().split('\n')) - 1 if output else 0
        checker = checker_run(output, input_)
        res.append([input_, pswap, checker])
    return res

def mean(it):
    lst = list(it)
    return sum(lst) / len(lst)

def save_plot(data, filename):
    sns_plot = sns.distplot(data, hist=True, kde=True, 
                            bins=10, color = 'darkblue', 
                            hist_kws={'edgecolor':'black'},
                            kde_kws={'linewidth': 4}).get_figure()
    sns_plot.savefig(filename)
    plt.clf()

if __name__ == "__main__":
    for i in [500]:
        print(f"Running test for {i} numbers...")
        results = sorted(run_check(i), key=lambda x: x[1])
        if all(map(lambda x: x[-1] == "OK", results)):
            print("Test passed!")
            print(f"Minimum ops: {results[0][1]}")
            print(f"Maximum ops: {results[-1][1]}")
            print(f"Lowest 5% ops: {results[int(len(results) * 0.05)][1]}")
            print(f"Highgest 5% ops: {results[int(len(results) * 0.95)][1]}")
            print(f"Average ops: {mean(map(lambda x: x[1], results))}")
            print(f"Median ops: {results[len(results) >> 1][1]}")
            save_plot([x[1] for x in results], f"results_{i}.png")
            print(f"Plot saved as results_{i}.png")
        else:
            print("Test failed!")
