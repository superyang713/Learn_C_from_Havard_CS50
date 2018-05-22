# Test the swap function to see if python behaves the same as C.


def main():
    a = 3
    b = 4
    # a, b = swap(a, b)
    swap(a, b)
    print('a = {}, b = {}'.format(a, b))


def swap(x, y):
    temp = x
    x = y
    y = temp
    # return x, y


if __name__ == '__main__':
    main()
