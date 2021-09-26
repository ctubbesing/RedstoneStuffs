def getInputNumber():
    a = 1
    a = input('enter number:')
    print('length: ' + str(len(a)))
    print(int(a))
    print(type(int(a)))

def forTesting():
    for char in 'testStr':
        print(char)

def replaceTesting():
    testStr = 'bushu314'
    print(testStr.replace('u', '', 1))

def main():
    print('Start.')
    # getInputNumber()
    # forTesting()
    replaceTesting()

main()

