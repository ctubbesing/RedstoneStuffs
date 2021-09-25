def getInputNumber():
    a = 1
    a = input('enter number:')
    print('length: ' + str(len(a)))
    print(int(a))
    print(type(int(a)))

def main():
    print('in main')
    getInputNumber()

main()

