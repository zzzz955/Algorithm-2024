import time

if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        a, b = map(int, input().split())
        print(f'#{i} {int(a/b)} {a%b}')

    time.sleep(0.1)
