#백준 3613, Java vs C++

string = input()

if string[0] == '_' or string[0].isupper() or string[-1] == '_':
    print("Error!")
    exit()

if string.islower():
    new = ''
    underbar = False
    for c in string:
        if c == '_' and underbar:
            print("Error!")
            exit()
        if c == '_':
            underbar = True
        elif underbar:
            new += c.upper()
            underbar = False
        else:
            new += c
    print(new)

else:
    new = ''
    for c in string:
        if c == '_':
            print("Error!")
            exit()
        if c.isupper():
            new += '_' + c.lower()
        else:
            new += c
    print(new)


