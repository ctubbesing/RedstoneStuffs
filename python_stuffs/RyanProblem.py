def isValidNumber(num):
    # string must be a 9-digit number with all unique digits
    if len(num) != 9:
        return False
    
    checklist = '0123456789'
    for n in num:
        checklist = checklist.replace(n, '')
    
    # print(checklist)

    if (len(checklist) != 1):
        return False

    return True

def bruteForce(num):
    if num == '987654321':
        print('No larger value exists.')
    
    if isValidNumber(num):
        currentVal = int(num) + 1
        while not isValidNumber(str(currentVal).zfill(9)):
            currentVal += 1
        print(str(currentVal).zfill(9))
    else:
        print('Invalid input.')

def main():
    print('Start.')

    userInput = input('Enter a number: ')
    while userInput != 'q':
        bruteForce(userInput)
        userInput = input('\nEnter a number: ')
    
    print('Done.')

main()
