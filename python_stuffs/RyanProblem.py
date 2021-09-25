def validateNumber(num):
    # string must be a 9-digit number with all unique digits
    missingDigit = ''
    for i in range(0, 10):
        if missingDigit == '':
            if str(i) not in num:
                missingDigit = str(i)
            
